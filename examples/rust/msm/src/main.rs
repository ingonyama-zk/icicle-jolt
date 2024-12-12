use icicle_runtime::{
    memory::{DeviceVec, HostSlice},
    stream::IcicleStream,
};

use icicle_bn254::curve::{CurveCfg, G1Projective, G2CurveCfg, G2Projective, ScalarCfg};

use clap::Parser;
use icicle_core::{curve::Curve, msm, traits::GenerateRandom};

#[derive(Parser, Debug)]
struct Args {
    /// Lower bound (inclusive) of MSM sizes to run for
    #[arg(short, long, default_value_t = 10)]
    lower_bound_log_size: u8,

    /// Upper bound of MSM sizes to run for
    #[arg(short, long, default_value_t = 10)]
    upper_bound_log_size: u8,

    /// Device type (e.g., "CPU", "CUDA")
    #[arg(short, long, default_value = "CPU")]
    device_type: String,
}

// Load backend and set device
fn try_load_and_set_backend_device(args: &Args) {
    if args.device_type != "CPU" {
        icicle_runtime::runtime::load_backend_from_env_or_default().unwrap();
    }
    println!("Setting device {}", args.device_type);
    let device = icicle_runtime::Device::new(&args.device_type, 0 /* =device_id*/);
    icicle_runtime::set_device(&device).unwrap();
}

fn main() {
    let args = Args::parse();
    println!("{:?}", args);

    try_load_and_set_backend_device(&args);

    let lower_bound = args.lower_bound_log_size;
    let upper_bound = args.upper_bound_log_size;
    println!("Running Icicle Examples: Rust MSM");
    let upper_size = 1 << upper_bound;

    println!("Generating random inputs on host for bn254...");
    let upper_points = CurveCfg::generate_random_affine_points(upper_size);
    let g2_upper_points = G2CurveCfg::generate_random_affine_points(upper_size);
    let upper_scalars = ScalarCfg::generate_random(upper_size);

    for i in lower_bound..=upper_bound {
        let log_size = i;
        let size = 1 << log_size;
        println!(
            "---------------------- MSM size 2^{} = {} ------------------------",
            log_size, size
        );

        // Setting Bn254 points and scalars
        let points = HostSlice::from_slice(&upper_points[..size]);
        let g2_points = HostSlice::from_slice(&g2_upper_points[..size]);
        let scalars = HostSlice::from_slice(&upper_scalars[..size]);

        println!("Configuring bn254 MSM...");
        let mut msm_results = DeviceVec::<G1Projective>::device_malloc(1).unwrap();
        let mut g2_msm_results = DeviceVec::<G2Projective>::device_malloc(1).unwrap();
        let mut stream = IcicleStream::create().unwrap();
        let mut g2_stream = IcicleStream::create().unwrap();
        let mut cfg = msm::MSMConfig::default();
        let mut g2_cfg = msm::MSMConfig::default();
        cfg.stream_handle = *stream;
        cfg.is_async = true;
        g2_cfg.stream_handle = *g2_stream;
        g2_cfg.is_async = true;

        println!("Executing bn254 MSM on device...");
        msm::msm(scalars, points, &cfg, &mut msm_results[..]).unwrap();
        msm::msm(scalars, g2_points, &g2_cfg, &mut g2_msm_results[..]).unwrap();

        println!("Moving results to host...");
        let mut msm_host_result = vec![G1Projective::zero(); 1];
        let mut g2_msm_host_result = vec![G2Projective::zero(); 1];

        stream
            .synchronize()
            .unwrap();
        msm_results
            .copy_to_host(HostSlice::from_mut_slice(&mut msm_host_result[..]))
            .unwrap();
        println!("bn254 result: {:#?}", msm_host_result);

        g2_stream
            .synchronize()
            .unwrap();
        g2_msm_results
            .copy_to_host(HostSlice::from_mut_slice(&mut g2_msm_host_result[..]))
            .unwrap();
        println!("G2 bn254 result: {:#?}", g2_msm_host_result);

        println!("Cleaning up bn254...");
        stream
            .destroy()
            .unwrap();
        g2_stream
            .destroy()
            .unwrap();

        println!("");
    }
}
