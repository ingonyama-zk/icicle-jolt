# Remark: This script contains functionality for GF(2^n), but currently works only over GF(p)! A few small adaptations are needed for GF(2^n).
from sage.rings.polynomial.polynomial_gf2x import GF2X_BuildIrred_list
from math import *
import itertools

###########################################################################
# ICICLE:  change curve here: ICICLE supported curves/fie;ds
# p = 2147483647 #Mersene
# p = 18446744069414584321 # GoldiLocks
# p = 2013265921 # BabyBear
# p = 52435875175126190479447740508185965837690552500527637822603658699938581184513 # BLS12-381
# p = 8444461749428370424248824938781546531375899335154063827935233455917409239041 #BLS12-377
# p = 21888242871839275222246405745257275088548364400416034343698204186575808495617 # BN254/BN256
# p = 21888242871839275222246405745257275088696311157297823662689037894645226208583 #Grumpkin
# p = 3618502788666131213697322783095070105623107215331596699973092056135872020481 #stark252

## ICICLE unsupported
# p = 28948022309329048855892746252171976963363056481941560715954676764349967630337 # Pasta (Pallas)
# p = 28948022309329048855892746252171976963363056481941647379679742748393362948097 # Pasta (Vesta)

# n = len(p.bits()) # bit
# paper stuff, ignore
# t = 12 # GoldiLocks (t = 12 for sponge, t = 8 for compression)
# t = 16 # BabyBear (t = 24 for sponge, t = 16 for compression)
# t = 3 # BN254/BN256, BLS12-381, Pallas, Vesta (t = 3 for sponge, t = 2 for compression)

# change t here: For ICICLE: t=3,4 for large fields and small fields for now.

# ICICLE - CHANGE state size HERE: : t=2,3,4,8,12,16,20,24 are covered in paper. (Mersene, goldilocks,babybear all sizes)
# large fields 255 bits recommended t =2,3,4,8
# t = 3

if len(sys.argv) < 4:
    print(f'len(sys.argv) = {len(sys.argv)}')
    print("Usage: sage <script> <field_name> <hash_width (t)> <modulus_hex>")
    exit(1)

FIELD_NAME = sys.argv[1]
t = Integer(int(sys.argv[2]))
p = Integer(int(sys.argv[3], 16))
n = len((p).bits()) # bit
FIELD = 1
SBOX = 0
FIELD_SIZE = n
NUM_CELLS = t

def get_alpha(p):
    for alpha in range(3, p):
        if gcd(alpha, p-1) == 1:
            break
    return alpha

alpha = get_alpha(p)

def get_sbox_cost(R_F, R_P, N, t):
    return int(t * R_F + R_P)

def get_size_cost(R_F, R_P, N, t):
    n = ceil(float(N) / t)
    return int((N * R_F) + (n * R_P))

def poseidon_calc_final_numbers_fixed(p, t, alpha, M, security_margin):
    # [Min. S-boxes] Find best possible for t and N
    n = ceil(log(p, 2))
    N = int(n * t)
    cost_function = get_sbox_cost
    ret_list = []
    (R_F, R_P) = find_FD_round_numbers(p, t, alpha, M, cost_function, security_margin)
    min_sbox_cost = cost_function(R_F, R_P, N, t)
    ret_list.append(R_F)
    ret_list.append(R_P)
    ret_list.append(min_sbox_cost)

    # [Min. Size] Find best possible for t and N
    # Minimum number of S-boxes for fixed n results in minimum size also (round numbers are the same)!
    min_size_cost = get_size_cost(R_F, R_P, N, t)
    ret_list.append(min_size_cost)

    return ret_list # [R_F, R_P, min_sbox_cost, min_size_cost]

def find_FD_round_numbers(p, t, alpha, M, cost_function, security_margin):
    n = ceil(log(p, 2))
    N = int(n * t)

    sat_inequiv = sat_inequiv_alpha

    R_P = 0
    R_F = 0
    min_cost = float("inf")
    max_cost_rf = 0
    # Brute-force approach
    for R_P_t in range(1, 500):
        for R_F_t in range(4, 100):
            if R_F_t % 2 == 0:
                if (sat_inequiv(p, t, R_F_t, R_P_t, alpha, M) == True):
                    if security_margin == True:
                        R_F_t += 2
                        R_P_t = int(ceil(float(R_P_t) * 1.075))
                    cost = cost_function(R_F_t, R_P_t, N, t)
                    if (cost < min_cost) or ((cost == min_cost) and (R_F_t < max_cost_rf)):
                        R_P = ceil(R_P_t)
                        R_F = ceil(R_F_t)
                        min_cost = cost
                        max_cost_rf = R_F
    return (int(R_F), int(R_P))

def sat_inequiv_alpha(p, t, R_F, R_P, alpha, M):
    N = int(FIELD_SIZE * NUM_CELLS)
    
    if alpha > 0:
        R_F_1 = 6 if M <= ((floor(log(p, 2) - ((alpha-1)/2.0))) * (t + 1)) else 10 # Statistical
        R_F_2 = 1 + ceil(log(2, alpha) * min(M, FIELD_SIZE)) + ceil(log(t, alpha)) - R_P # Interpolation
        R_F_3 = (log(2, alpha) * min(M, log(p, 2))) - R_P # Groebner 1
        R_F_4 = t - 1 + log(2, alpha) * min(M / float(t + 1), log(p, 2) / float(2)) - R_P # Groebner 2
        R_F_5 = (t - 2 + (M / float(2 * log(alpha, 2))) - R_P) / float(t - 1) # Groebner 3
        R_F_max = max(ceil(R_F_1), ceil(R_F_2), ceil(R_F_3), ceil(R_F_4), ceil(R_F_5))
        
        # Addition due to https://eprint.iacr.org/2023/537.pdf
        r_temp = floor(t / 3.0)
        over = (R_F - 1) * t + R_P + r_temp + r_temp * (R_F / 2.0) + R_P + alpha
        under = r_temp * (R_F / 2.0) + R_P + alpha
        binom_log = log(binomial(over, under), 2)
        if binom_log == inf:
            binom_log = M + 1
        cost_gb4 = ceil(2 * binom_log) # Paper uses 2.3727, we are more conservative here

        return ((R_F >= R_F_max) and (cost_gb4 >= M))
    else:
        print("Invalid value for alpha!")
        exit(1)

print(p, t, alpha, 128, True)
R_F_FIXED, R_P_FIXED, _, _ = poseidon_calc_final_numbers_fixed(p, t, alpha, 128, True)
print("++++++ R_F = {0}, R_P = {1} +++".format(R_F_FIXED, R_P_FIXED))
print(f"RESULT: {R_F_FIXED} {R_P_FIXED} {alpha}")     # Alpha needed in the parent python script in order to know what file to concatenate.
FILE_cpp = open(f"{FIELD_NAME}_poseidon2_{t}_{alpha}.h", 'w')   # Alpha is needed to communicate with a parent python script.
FILE_cpp.write(f'int full_rounds_{t} =         {R_F_FIXED};\n')
FILE_cpp.write(f'int half_full_rounds_{t} =    {R_F_FIXED/2};\n')
FILE_cpp.write(f'int partial_rounds_{t} =      {R_P_FIXED};\n')
FILE_cpp.write(f'int alpha_{t} =               {alpha};\n\n')

INIT_SEQUENCE = []

PRIME_NUMBER = p

F = GF(PRIME_NUMBER)

def grain_sr_generator():
    bit_sequence = INIT_SEQUENCE
    for _ in range(0, 160):
        new_bit = bit_sequence[62] ^^ bit_sequence[51] ^^ bit_sequence[38] ^^ bit_sequence[23] ^^ bit_sequence[13] ^^ bit_sequence[0]
        bit_sequence.pop(0)
        bit_sequence.append(new_bit)

    while True:
        new_bit = bit_sequence[62] ^^ bit_sequence[51] ^^ bit_sequence[38] ^^ bit_sequence[23] ^^ bit_sequence[13] ^^ bit_sequence[0]
        bit_sequence.pop(0)
        bit_sequence.append(new_bit)
        while new_bit == 0:
            new_bit = bit_sequence[62] ^^ bit_sequence[51] ^^ bit_sequence[38] ^^ bit_sequence[23] ^^ bit_sequence[13] ^^ bit_sequence[0]
            bit_sequence.pop(0)
            bit_sequence.append(new_bit)
            new_bit = bit_sequence[62] ^^ bit_sequence[51] ^^ bit_sequence[38] ^^ bit_sequence[23] ^^ bit_sequence[13] ^^ bit_sequence[0]
            bit_sequence.pop(0)
            bit_sequence.append(new_bit)
        new_bit = bit_sequence[62] ^^ bit_sequence[51] ^^ bit_sequence[38] ^^ bit_sequence[23] ^^ bit_sequence[13] ^^ bit_sequence[0]
        bit_sequence.pop(0)
        bit_sequence.append(new_bit)
        yield new_bit
grain_gen = grain_sr_generator()

def grain_random_bits(num_bits):
    random_bits = [next(grain_gen) for i in range(0, num_bits)]
    # random_bits.reverse() ## Remove comment to start from least significant bit
    random_int = int("".join(str(i) for i in random_bits), 2)
    return random_int

def init_generator(field, sbox, n, t, R_F, R_P):
    # Generate initial sequence based on parameters
    bit_list_field = [_ for _ in (bin(FIELD)[2:].zfill(2))]
    bit_list_sbox = [_ for _ in (bin(SBOX)[2:].zfill(4))]
    bit_list_n = [_ for _ in (bin(FIELD_SIZE)[2:].zfill(12))]
    bit_list_t = [_ for _ in (bin(NUM_CELLS)[2:].zfill(12))]
    bit_list_R_F = [_ for _ in (bin(R_F)[2:].zfill(10))]
    bit_list_R_P = [_ for _ in (bin(R_P)[2:].zfill(10))]
    bit_list_1 = [1] * 30
    global INIT_SEQUENCE
    INIT_SEQUENCE = bit_list_field + bit_list_sbox + bit_list_n + bit_list_t + bit_list_R_F + bit_list_R_P + bit_list_1
    INIT_SEQUENCE = [int(_) for _ in INIT_SEQUENCE]

def generate_constants(field, n, t, R_F, R_P, prime_number):
    rounds_constants = []
    # num_constants = (R_F + R_P) * t # Poseidon
    num_constants = (R_F * t) + R_P # Poseidon2

    if field == 0:
        for i in range(0, num_constants):
            random_int = grain_random_bits(n)
            rounds_constants.append(random_int)
    elif field == 1:
        for i in range(0, num_constants):
            random_int = grain_random_bits(n)
            while random_int >= prime_number:
                # print("[Info] Round constant is not in prime field! Taking next one.")
                random_int = grain_random_bits(n)
            rounds_constants.append(random_int)
            # Add (t-1) zeroes for Poseidon2 if partial round
            if i >= ((R_F/2) * t) and i < (((R_F/2) * t) + R_P):
                rounds_constants.extend([0] * (t-1))
    return rounds_constants

def print_rounds_constants(rounds_constants, n, field):
    print("Number of round constants:", len(rounds_constants))

    if field == 0:
        print("Round constants for GF(2^n):")
    elif field == 1:
        print("Round constants for GF(p):")
    hex_length = int(ceil(float(n) / 4)) + 2 # +2 for "0x"
    print(["{0:#0{1}x}".format(entry, hex_length) for entry in rounds_constants])

def create_mds_p(n, t):
    M = matrix(F, t, t)

    # Sample random distinct indices and assign to xs and ys
    while True:
        flag = True
        rand_list = [F(grain_random_bits(n)) for _ in range(0, 2*t)]
        while len(rand_list) != len(set(rand_list)): # Check for duplicates
            rand_list = [F(grain_random_bits(n)) for _ in range(0, 2*t)]
        xs = rand_list[:t]
        ys = rand_list[t:]
        # xs = [F(ele) for ele in range(0, t)]
        # ys = [F(ele) for ele in range(t, 2*t)]
        for i in range(0, t):
            for j in range(0, t):
                if (flag == False) or ((xs[i] + ys[j]) == 0):
                    flag = False
                else:
                    entry = (xs[i] + ys[j])^(-1)
                    M[i, j] = entry
        if flag == False:
            continue
        return M

def generate_vectorspace(round_num, M, M_round, NUM_CELLS):
    t = NUM_CELLS
    s = 1
    V = VectorSpace(F, t)
    if round_num == 0:
        return V
    elif round_num == 1:
        return V.subspace(V.basis()[s:])
    else:
        mat_temp = matrix(F)
        for i in range(0, round_num-1):
            add_rows = []
            for j in range(0, s):
                add_rows.append(M_round[i].rows()[j][s:])
            mat_temp = matrix(mat_temp.rows() + add_rows)
        r_k = mat_temp.right_kernel()
        extended_basis_vectors = []
        for vec in r_k.basis():
            extended_basis_vectors.append(vector([0]*s + list(vec)))
        S = V.subspace(extended_basis_vectors)

        return S

def subspace_times_matrix(subspace, M, NUM_CELLS):
    t = NUM_CELLS
    V = VectorSpace(F, t)
    subspace_basis = subspace.basis()
    new_basis = []
    for vec in subspace_basis:
        new_basis.append(M * vec)
    new_subspace = V.subspace(new_basis)
    return new_subspace

# Returns True if the matrix is considered secure, False otherwise
def algorithm_1(M, NUM_CELLS):
    t = NUM_CELLS
    s = 1
    r = floor((t - s) / float(s))

    # Generate round matrices
    M_round = []
    for j in range(0, t+1):
        M_round.append(M^(j+1))

    for i in range(1, r+1):
        mat_test = M^i
        entry = mat_test[0, 0]
        mat_target = matrix.circulant(vector([entry] + ([F(0)] * (t-1))))

        if (mat_test - mat_target) == matrix.circulant(vector([F(0)] * (t))):
            return [False, 1]

        S = generate_vectorspace(i, M, M_round, t)
        V = VectorSpace(F, t)

        basis_vectors= []
        for eigenspace in mat_test.eigenspaces_right(format='galois'):
            if (eigenspace[0] not in F):
                continue
            vector_subspace = eigenspace[1]
            intersection = S.intersection(vector_subspace)
            basis_vectors += intersection.basis()
        IS = V.subspace(basis_vectors)

        if IS.dimension() >= 1 and IS != V:
            return [False, 2]
        for j in range(1, i+1):
            S_mat_mul = subspace_times_matrix(S, M^j, t)
            if S == S_mat_mul:
                print("S.basis():\n", S.basis())
                return [False, 3]

    return [True, 0]

# Returns True if the matrix is considered secure, False otherwise
def algorithm_2(M, NUM_CELLS):
    t = NUM_CELLS
    s = 1

    V = VectorSpace(F, t)
    trail = [None, None]
    test_next = False
    I = range(0, s)
    I_powerset = list(sage.misc.misc.powerset(I))[1:]
    for I_s in I_powerset:
        test_next = False
        new_basis = []
        for l in I_s:
            new_basis.append(V.basis()[l])
        IS = V.subspace(new_basis)
        for i in range(s, t):
            new_basis.append(V.basis()[i])
        full_iota_space = V.subspace(new_basis)
        for l in I_s:
            v = V.basis()[l]
            while True:
                delta = IS.dimension()
                v = M * v
                IS = V.subspace(IS.basis() + [v])
                if IS.dimension() == t or IS.intersection(full_iota_space) != IS:
                    test_next = True
                    break
                if IS.dimension() <= delta:
                    break
            if test_next == True:
                break
        if test_next == True:
            continue
        return [False, [IS, I_s]]

    return [True, None]

# Returns True if the matrix is considered secure, False otherwise
def algorithm_3(M, NUM_CELLS):
    t = NUM_CELLS
    s = 1

    V = VectorSpace(F, t)

    l = 4*t
    for r in range(2, l+1):
        next_r = False
        res_alg_2 = algorithm_2(M^r, t)
        if res_alg_2[0] == False:
            return [False, None]

        # if res_alg_2[1] == None:
        #     continue
        # IS = res_alg_2[1][0]
        # I_s = res_alg_2[1][1]
        # for j in range(1, r):
        #     IS = subspace_times_matrix(IS, M, t)
        #     I_j = []
        #     for i in range(0, s):
        #         new_basis = []
        #         for k in range(0, t):
        #             if k != i:
        #                 new_basis.append(V.basis()[k])
        #         iota_space = V.subspace(new_basis)
        #         if IS.intersection(iota_space) != iota_space:
        #             single_iota_space = V.subspace([V.basis()[i]])
        #             if IS.intersection(single_iota_space) == single_iota_space:
        #                 I_j.append(i)
        #             else:
        #                 next_r = True
        #                 break
        #     if next_r == True:
        #         break
        # if next_r == True:
        #     continue
        # return [False, [IS, I_j, r]]

    return [True, None]

def check_minpoly_condition(M, NUM_CELLS):
    max_period = 2*NUM_CELLS
    all_fulfilled = True
    M_temp = M
    for i in range(1, max_period + 1):
        if not ((M_temp.minimal_polynomial().degree() == NUM_CELLS) and (M_temp.minimal_polynomial().is_irreducible() == True)):
            all_fulfilled = False
            break
        M_temp = M * M_temp
    return all_fulfilled

def generate_matrix(FIELD, FIELD_SIZE, NUM_CELLS):
    if FIELD == 0:
        print("Matrix generation not implemented for GF(2^n).")
        exit(1)
    elif FIELD == 1:
        mds_matrix = create_mds_p(FIELD_SIZE, NUM_CELLS)
        result_1 = algorithm_1(mds_matrix, NUM_CELLS)
        result_2 = algorithm_2(mds_matrix, NUM_CELLS)
        result_3 = algorithm_3(mds_matrix, NUM_CELLS)
        while result_1[0] == False or result_2[0] == False or result_3[0] == False:
            mds_matrix = create_mds_p(FIELD_SIZE, NUM_CELLS)
            result_1 = algorithm_1(mds_matrix, NUM_CELLS)
            result_2 = algorithm_2(mds_matrix, NUM_CELLS)
            result_3 = algorithm_3(mds_matrix, NUM_CELLS)
        return mds_matrix

def generate_matrix_full(NUM_CELLS):
    M = None
    if t == 2:
        M = matrix.circulant(vector([F(2), F(1)]))
    elif t == 3:
        M = matrix.circulant(vector([F(2), F(1), F(1)]))
    elif t == 4:
        M = matrix(F, [[F(5), F(7), F(1), F(3)], [F(4), F(6), F(1), F(1)], [F(1), F(3), F(5), F(7)], [F(1), F(1), F(4), F(6)]])
    elif (t % 4) == 0:
        M = matrix(F, t, t)
        # M_small = matrix.circulant(vector([F(3), F(2), F(1), F(1)]))
        M_small = matrix(F, [[F(5), F(7), F(1), F(3)], [F(4), F(6), F(1), F(1)], [F(1), F(3), F(5), F(7)], [F(1), F(1), F(4), F(6)]])
        small_num = t // 4
        for i in range(0, small_num):
            for j in range(0, small_num):
                if i == j:
                    M[i*4:(i+1)*4,j*4:(j+1)*4] = 2* M_small
                else:
                    M[i*4:(i+1)*4,j*4:(j+1)*4] = M_small
    else:
        print("Error: No matrix for these parameters.")
        exit()
    return M

def generate_matrix_partial(FIELD, FIELD_SIZE, NUM_CELLS): ## TODO: Prioritize small entries
    entry_max_bit_size = FIELD_SIZE
    if FIELD == 0:
        print("Matrix generation not implemented for GF(2^n).")
        exit(1)
    elif FIELD == 1:
        M = None
        if t == 2:
            M = matrix(F, [[F(2), F(1)], [F(1), F(3)]])
        elif t == 3:
            M = matrix(F, [[F(2), F(1), F(1)], [F(1), F(2), F(1)], [F(1), F(1), F(3)]])
        else:
            M_circulant = matrix.circulant(vector([F(0)] + [F(1) for _ in range(0, NUM_CELLS - 1)]))
            M_diagonal = matrix.diagonal([F(grain_random_bits(entry_max_bit_size)) for _ in range(0, NUM_CELLS)])
            M = M_circulant + M_diagonal
            # while algorithm_1(M, NUM_CELLS)[0] == False or algorithm_2(M, NUM_CELLS)[0] == False or algorithm_3(M, NUM_CELLS)[0] == False:
            while check_minpoly_condition(M, NUM_CELLS) == False:
                M_diagonal = matrix.diagonal([F(grain_random_bits(entry_max_bit_size)) for _ in range(0, NUM_CELLS)])
                M = M_circulant + M_diagonal
        
        if(algorithm_1(M, NUM_CELLS)[0] == False or algorithm_2(M, NUM_CELLS)[0] == False or algorithm_3(M, NUM_CELLS)[0] == False):
            print("Error: Generated partial matrix is not secure w.r.t. subspace trails.")
            exit()
        return M

def generate_matrix_partial_small_entries(FIELD, FIELD_SIZE, NUM_CELLS):
    if FIELD == 0:
        print("Matrix generation not implemented for GF(2^n).")
        exit(1)
    elif FIELD == 1:
        M_circulant = matrix.circulant(vector([F(0)] + [F(1) for _ in range(0, NUM_CELLS - 1)]))
        combinations = list(itertools.product(range(2, 6), repeat=NUM_CELLS))
        for entry in combinations:
            M = M_circulant + matrix.diagonal(vector(F, list(entry)))
            print(M)
            # if M.is_invertible() == False or algorithm_1(M, NUM_CELLS)[0] == False or algorithm_2(M, NUM_CELLS)[0] == False or algorithm_3(M, NUM_CELLS)[0] == False:
            if M.is_invertible() == False or check_minpoly_condition(M, NUM_CELLS) == False:
                continue
            return M

# def matrix_partial_m_1(matrix_partial, NUM_CELLS):
#     M_circulant = matrix.identity(F, NUM_CELLS)
#     return matrix_partial * M_circulant

def print_linear_layer(M, n, t):
    print("n:", n)
    print("t:", t)
    print("N:", (n * t))
    print("Result Algorithm 1:\n", algorithm_1(M, NUM_CELLS))
    print("Result Algorithm 2:\n", algorithm_2(M, NUM_CELLS))
    print("Result Algorithm 3:\n", algorithm_3(M, NUM_CELLS))
    hex_length = int(ceil(float(n) / 4)) + 2 # +2 for "0x"
    print("Prime number:", "0x" + hex(PRIME_NUMBER))
    matrix_string = "["
    for i in range(0, t):
        matrix_string += str(["{0:#0{1}x}".format(int(entry), hex_length) for entry in M[i]])
        if i < (t-1):
            matrix_string += ","
    matrix_string += "]"
    print("MDS matrix:\n", matrix_string)

def calc_equivalent_matrices(MDS_matrix_field):
    # Following idea: Split M into M' * M'', where M'' is "cheap" and M' can move before the partial nonlinear layer
    # The "previous" matrix layer is then M * M'. Due to the construction of M', the M[0,0] and v values will be the same for the new M' (and I also, obviously)
    # Thus: Compute the matrices, store the w_hat and v_hat values

    MDS_matrix_field_transpose = MDS_matrix_field.transpose()

    w_hat_collection = []
    v_collection = []
    v = MDS_matrix_field_transpose[[0], list(range(1,t))]

    M_mul = MDS_matrix_field_transpose
    M_i = matrix(F, t, t)
    for i in range(R_P_FIXED - 1, -1, -1):
        M_hat = M_mul[list(range(1,t)), list(range(1,t))]
        w = M_mul[list(range(1,t)), [0]]
        v = M_mul[[0], list(range(1,t))]
        v_collection.append(v.list())
        w_hat = M_hat.inverse() * w
        w_hat_collection.append(w_hat.list())

        # Generate new M_i, and multiplication M * M_i for "previous" round
        M_i = matrix.identity(t)
        M_i[list(range(1,t)), list(range(1,t))] = M_hat
        M_mul = MDS_matrix_field_transpose * M_i

    return M_i, v_collection, w_hat_collection, MDS_matrix_field_transpose[0, 0]

def calc_equivalent_constants(constants, MDS_matrix_field):
    constants_temp = [constants[index:index+t] for index in range(0, len(constants), t)]

    MDS_matrix_field_transpose = MDS_matrix_field.transpose()

    # Start moving round constants up
    # Calculate c_i' = M^(-1) * c_(i+1)
    # Split c_i': Add c_i'[0] AFTER the S-box, add the rest to c_i
    # I.e.: Store c_i'[0] for each of the partial rounds, and make c_i = c_i + c_i' (where now c_i'[0] = 0)
    num_rounds = R_F_FIXED + R_P_FIXED
    R_f = R_F_FIXED / 2
    for i in range(num_rounds - 2 - R_f, R_f - 1, -1):
        inv_cip1 = list(vector(constants_temp[i+1]) * MDS_matrix_field_transpose.inverse())
        constants_temp[i] = list(vector(constants_temp[i]) + vector([0] + inv_cip1[1:]))
        constants_temp[i+1] = [inv_cip1[0]] + [0] * (t-1)

    return constants_temp

def poseidon(input_words, matrix, rounds_constants):

    R_f = int(R_F_FIXED / 2)

    rounds_constants_counter = 0

    state_words = list(input_words)

    # First full rounds
    for r in range(0, R_f):
        # Round constants, nonlinear layer, matrix multiplication
        for i in range(0, t):
            state_words[i] = state_words[i] + rounds_constants[rounds_constants_counter]
            rounds_constants_counter += 1
        for i in range(0, t):
            state_words[i] = (state_words[i])^alpha
        state_words = list(matrix * vector(state_words))

    # Middle partial rounds
    for r in range(0, R_P_FIXED):
        # Round constants, nonlinear layer, matrix multiplication
        for i in range(0, t):
            state_words[i] = state_words[i] + rounds_constants[rounds_constants_counter]
            rounds_constants_counter += 1
        state_words[0] = (state_words[0])^alpha
        state_words = list(matrix * vector(state_words))

    # Last full rounds
    for r in range(0, R_f):
        # Round constants, nonlinear layer, matrix multiplication
        for i in range(0, t):
            state_words[i] = state_words[i] + rounds_constants[rounds_constants_counter]
            rounds_constants_counter += 1
        for i in range(0, t):
            state_words[i] = (state_words[i])^alpha
        state_words = list(matrix * vector(state_words))

    return state_words

def print_state(f, message, state):
  f.write(f'{message}\n')
  for i in range(t):
    # f.write(f' "{hex(state[i])}"')
    f.write(f' "0x{int(state[i]):064x}"')
    if i == t-1:
      f.write(f']\n')
    else:
      f.write(f', ')
def print_matrix(f, message, matrix):
  f.write(f'{message}\n')
  for row in range(matrix.nrows()):
    for col in range(matrix.ncols()):
      # f.write(f' "{hex(matrix[row,col])}"')
      f.write(f' "0x{int(matrix[row,col]):064x}"')
      if row != (matrix.nrows()) - 1 or col != (matrix.nrows()) - 1:
        f.write(f',')
    f.write(f'\n')
def poseidon2(f, input_words, matrix_full, matrix_partial, rounds_constants):

    R_f = int(R_F_FIXED / 2)

    rounds_constants_counter = 0

    state_words = list(input_words)

    print("Begin Poseidon2\n")
    f.write("Begin Poseidon2\n")
    # First matrix mul
    print("\n Field Modulus: = ",p)
    f.write("\n Field Modulus: = {p}")
    print("\n Full Rounds: R_F = ",R_F_FIXED)
    f.write("\n Full Rounds: R_F = {R_F_FIXED}")
    print("\n Partial Rounds: R_P= ",R_P_FIXED)
    f.write("\n Partial Rounds: R_P= {R_P_FIXED}")
    print("\n Alpha = ",alpha) 
    f.write("\n Alpha = {alpha}") 
    print("\n Full Matrix = {{")
    print(matrix_full)
    print_matrix(f, "\n Full matrix: ", matrix_full)
    print("\n Partial Matrix = {{")
    print(matrix_partial)
    print_matrix(f, "\n Partial matrix: ", matrix_partial)
    # Pre-full round.
    print_state(f, 'Input to pre-full rounds state', state_words)
    state_words = list(matrix_full * vector(state_words))
    print_state(f, 'Output of pre-full rounds state', state_words)

    # First full rounds
    print("\n First full rounds\n")
    print("Round constants:")
    for r in range(0, R_f):
        # Round constants, nonlinear layer, matrix multiplication
        print("Upper full round number: ",r)
        print(rounds_constants[rounds_constants_counter:rounds_constants_counter+t])
        f.write(f'Upper full round {r}\n')
        print_state(f, f'Round constants: ', rounds_constants[rounds_constants_counter:rounds_constants_counter+t])
        for i in range(0, t):
            state_words[i] = state_words[i] + rounds_constants[rounds_constants_counter]
            rounds_constants_counter += 1
        print_state(f, f'U.F.R. {r}: Output of add round constants', state_words)
        f.write(f'alpha = {alpha}\n')
        for i in range(0, t):
            state_words[i] = (state_words[i])^alpha
        print_state(f, f'U.F.R. {r}: S-box result', state_words)
        state_words = list(matrix_full * vector(state_words))
        print_state(f, f'U.F.R. {r}: Full matrix result', state_words)
    print_state(f, f'F.R. {r}: Upper full rounds result', state_words)
    f.write(f'\n\n\n')

    # Middle partial rounds
    print("\n Middle partial rounds\n")
    print("Round constants:")
    for r in range(0, R_P_FIXED):
        # Round constants, nonlinear layer, matrix multiplication
        f.write(f'Partial round {r}\n')
        print("Middle partial round number: ",r)
        print(rounds_constants[rounds_constants_counter:rounds_constants_counter+t])          
        print_state(f, f'Round constants: ', rounds_constants[rounds_constants_counter:rounds_constants_counter+t])
        for i in range(0, t):
            state_words[i] = state_words[i] + rounds_constants[rounds_constants_counter]         
            rounds_constants_counter += 1
        print_state(f, f'P.R. {r}: Output of add round constants', state_words)
        state_words[0] = (state_words[0])^alpha
        print_state(f, f'P.R. {r}: S-box result', state_words)
        state_words = list(matrix_partial * vector(state_words))
        print_state(f, f'P.R. {r}: Partial matrix result', state_words)
    print_state(f, f'Partial rounds result', state_words)
    f.write(f'\n\n\n')

    # Last full rounds
    print("\n Last full rounds\n")
    print("Round constants:")
    for r in range(0, R_f):
        print("Bottom full round number: ",r)
        # Round constants, nonlinear layer, matrix multiplication
        print("Last full round number: ",r)
        f.write(f'Bottom full round {r}\n')
        print(rounds_constants[rounds_constants_counter:rounds_constants_counter+t])
        for i in range(0, t):
            state_words[i] = state_words[i] + rounds_constants[rounds_constants_counter]
            rounds_constants_counter += 1
        print_state(f, f'B.F.R. {r}: Output of add round constants', state_words)
        for i in range(0, t):
            state_words[i] = (state_words[i])^alpha
        print_state(f, f'B.F.R. {r}: S-box result', state_words)
        state_words = list(matrix_full * vector(state_words))
        print_state(f, f'B.F.R. {r}: Full matrix result', state_words)
    print_state(f, f'Bottom full rounds result', state_words)

    print("End Poseidon2\n")
    return state_words

# Init
init_generator(FIELD, SBOX, FIELD_SIZE, NUM_CELLS, R_F_FIXED, R_P_FIXED)

# Round constants
rounds_constants = generate_constants(FIELD, FIELD_SIZE, NUM_CELLS, R_F_FIXED, R_P_FIXED, PRIME_NUMBER)
# print_rounds_constants(rounds_constants, FIELD_SIZE, FIELD)
print(f'type(rounds_constants) = {type(rounds_constants)}')
print(f'len(rounds_constants) = {len(rounds_constants)}')
print(f'rounds_constants = {rounds_constants}')
FILE_cpp.write(f'static const std::string rounds_constants_{t}[] = {{\n')
R_F_FIXED_HALF = R_F_FIXED / 2
for rc_idx in range(R_F_FIXED_HALF * t):
  FILE_cpp.write(f'  "{hex(rounds_constants[rc_idx])}",\n')
for rc_idx in range(R_F_FIXED_HALF * t, R_F_FIXED_HALF * t + R_P_FIXED * t):
  if rc_idx % t == 0:
    FILE_cpp.write(f'  "{hex(rounds_constants[rc_idx])}",\n')
for rc_idx in range(R_F_FIXED_HALF * t + R_P_FIXED * t, R_F_FIXED * t + R_P_FIXED * t):
  FILE_cpp.write(f'  "{hex(rounds_constants[rc_idx])}"')
  if rc_idx != R_F_FIXED * t + R_P_FIXED * t - 1:
    FILE_cpp.write(f',')
  FILE_cpp.write(f'\n')
FILE_cpp.write(f'}};\n\n')

# Matrix
# MDS = generate_matrix(FIELD, FIELD_SIZE, NUM_CELLS)
MATRIX_FULL = generate_matrix_full(NUM_CELLS)
MATRIX_PARTIAL = generate_matrix_partial(FIELD, FIELD_SIZE, NUM_CELLS)
# MATRIX_PARTIAL_DIAGONAL_M_1 = [matrix_partial_m_1(MATRIX_PARTIAL, NUM_CELLS)[i,i] for i in range(0, NUM_CELLS)]
MATRIX_PARTIAL_DIAGONAL = [MATRIX_PARTIAL[i,i] for i in range(0, NUM_CELLS)]
# Print MATRIX_FULL
FILE_cpp.write(f'static const std::string mds_matrix_{t}[] = {{\n')
for row in range(MATRIX_FULL.nrows()):
  for col in range(MATRIX_FULL.ncols()):
    print(f"M[{row},{col}] = {MATRIX_FULL[row,col]}")
    FILE_cpp.write(f' "{hex(MATRIX_FULL[row,col])}"')
    if row != (MATRIX_FULL.nrows()) - 1 or col != (MATRIX_FULL.nrows()) - 1:
      FILE_cpp.write(f',')
  FILE_cpp.write(f'\n')
FILE_cpp.write(f'}};\n\n')
# Print MATRIX_PARTIAL_DIAGONAL
FILE_cpp.write(f'static const std::string partial_matrix_diagonal_{t}[] = {{\n')
print(f'type(MATRIX_PARTIAL_DIAGONAL) = {type(MATRIX_PARTIAL_DIAGONAL)}')
print(f'MATRIX_PARTIAL_DIAGONAL = {MATRIX_PARTIAL_DIAGONAL}')
for i in range(len(MATRIX_PARTIAL_DIAGONAL)):
  print(f"M_P[{i},{i}] = {MATRIX_PARTIAL_DIAGONAL[i]}")
  FILE_cpp.write(f' "{hex(MATRIX_PARTIAL_DIAGONAL[i])}"')
  if i != len(MATRIX_PARTIAL_DIAGONAL) - 1:
    FILE_cpp.write(f',')
FILE_cpp.write(f'\n')
FILE_cpp.write(f'}};\n\n')

def to_hex(value):
    l = len(hex(p - 1))
    if l % 2 == 1:
        l = l + 1
    value = hex(int(value))[2:]
    value = "0x" + value.zfill(l - 2)
    print("from_hex(\"{}\"),".format(value))

FILE_run_dump = open(f"run_dump.txt", 'w')   # Alpha is needed to communicate with a parent python script.
state_in  = vector([F(i) for i in range(t)])
# state_out = poseidon(state_in, MDS, rounds_constants)
state_out = poseidon2(FILE_run_dump, state_in, MATRIX_FULL, MATRIX_PARTIAL, rounds_constants)

FILE_cpp.close()
FILE_run_dump.close()

print("\n\n Test Vectors\n")
print("Input state\n ",state_in)
print("Output state\n ",state_out)
