#pragma once
#ifndef BABYBEAR_POSEIDON2_H
  #define BABYBEAR_POSEIDON2_H

  #include <string>

namespace poseidon2_constants_babybear {

  /**
   * This inner namespace contains constants for running Poseidon2.
   * The number in the name corresponds to the arity of hash function
   */

  int full_rounds_2 = 12;
  int half_full_rounds_2 = 6;
  int partial_rounds_2 = 24;
  int alpha_2 = 7;

  static const std::string rounds_constants_2[] = {
    "0x76a8932a", "0xbb32543",  "0x54a11a80", "0x29f09389", "0x4b8a8ec1", "0x3fa2f7a2", "0x2be3fd0c", "0x6ab70c3d",
    "0xcd8e8f1",  "0x3a34c8f0", "0x3c11bf77", "0x27eb37f3", "0x6dcafcd",  "0x19fd4b2a", "0x1ccd65c3", "0x3733a0c2",
    "0x18b43754", "0x2ed74076", "0x368f93a6", "0xe8024cd",  "0x3b8f289a", "0x4f5afa7b", "0x64c82b68", "0x76245680",
    "0x1ab4ac2f", "0x3ca5f68e", "0x14bd49b1", "0x52d03b15", "0x8cd74b3",  "0x1edb152a", "0x3037497a", "0x498a68ec",
    "0x6b11f228", "0x21214194", "0x640be0ba", "0x4bd18241", "0x20094634", "0x126e22d8", "0x42d213d1", "0x667db627",
    "0x29345ea8", "0x4e79edfa", "0x22abc20",  "0x36a8e6ca", "0x5f11d45",  "0x311d4622", "0x346d7598", "0x61b18ef3"};

  static const std::string mds_matrix_2[] = {"0x2", "0x1", "0x1", "0x2"};

  static const std::string partial_matrix_diagonal_2[] = {"0x2", "0x3"};

  int full_rounds_3 = 12;
  int half_full_rounds_3 = 6;
  int partial_rounds_3 = 17;
  int alpha_3 = 7;

  static const std::string rounds_constants_3[] = {
    "0x460c6c97", "0x763f1345", "0x354fb969", "0x650244d",  "0x742c7bad", "0x420ae4e6", "0x24b1922f", "0x54b38487",
    "0x67d8a525", "0xe3721d8",  "0x4bb8f261", "0x67830d12", "0x70129a6c", "0x11ba69e0", "0x463bf841", "0x32d4a62f",
    "0x67278981", "0x13955c1f", "0x26609020", "0x38f57776", "0x4684140d", "0x937fa72",  "0x39c9ed0",  "0xa8c4f4e",
    "0x4353324d", "0x70ac28",   "0x1bb3e99b", "0x4ebe72d0", "0x265dc2d3", "0x17749f7",  "0x69265d86", "0xe8c9842",
    "0x4c0cd782", "0x64374361", "0x158e5174", "0xb5c6575",  "0x87a66c2",  "0x67afa498", "0x1b7f0922", "0x25b48cdd",
    "0x1919afc",  "0x523aff57", "0x3c000cf8", "0x21007c9a", "0x3df614a1", "0x6f9ca329", "0x17fe10cf", "0x1858c1a1",
    "0x6779c6fe", "0xa4ca12c",  "0x36180c4d", "0x54d17e59", "0x23bcabd8"};

  static const std::string mds_matrix_3[] = {"0x2", "0x1", "0x1", "0x1", "0x2", "0x1", "0x1", "0x1", "0x2"};

  static const std::string partial_matrix_diagonal_3[] = {"0x2", "0x2", "0x3"};

  int full_rounds_4 = 8;
  int half_full_rounds_4 = 4;
  int partial_rounds_4 = 21;
  int alpha_4 = 7;

  static const std::string rounds_constants_4[] = {
    "0x1b149b6a", "0x550ada3b", "0x22880f72", "0x162976de", "0x1459035b", "0x5b23b851", "0xecb6c50",  "0x5e25906e",
    "0x2e627964", "0x13edaf43", "0xf39a91a",  "0x4d1036b2", "0x7151a71",  "0x688d32c",  "0x640c2308", "0x4a823ac0",
    "0x664a061a", "0x735f9276", "0x1d33aa59", "0x444266ad", "0x65a98dc1", "0x210f7e1c", "0x5c429eb",  "0x12c9f1d5",
    "0x56e16908", "0x2cc4000f", "0x4cc1175d", "0x4696830c", "0x7276ab5e", "0x429e580",  "0x1eaddf35", "0x3d04814b",
    "0xce9d10c",  "0xc1bd2b2",  "0x5c0afe62", "0x41d3d05c", "0x4ea8fba8", "0x36415973", "0x1f6c2a2b", "0xfc447c9",
    "0xe06ec31",  "0x759e0d3b", "0x53928b9d", "0x1f031a41", "0x84357dc",  "0x18a44a08", "0x4e979922", "0x591b777e",
    "0x1698aa28", "0x6c89ede2", "0x49941eeb", "0x23d71466", "0x4ca1ef20"};

  static const std::string mds_matrix_4[] = {"0x5", "0x7", "0x1", "0x3", "0x4", "0x6", "0x1", "0x1",
                                             "0x1", "0x3", "0x5", "0x7", "0x1", "0x1", "0x4", "0x6"};

  static const std::string partial_matrix_diagonal_4[] = {"0x35bf6f48", "0x698266a0", "0x41f852b3", "0x375cdab9"};

  int full_rounds_8 = 8;
  int half_full_rounds_8 = 4;
  int partial_rounds_8 = 12;
  int alpha_8 = 7;

  static const std::string rounds_constants_8[] = {
    "0x11978cde", "0x531baacd", "0x62fc3e61", "0x6c5443d7", "0x213f7bea", "0x441daf50", "0x5b73b0ca", "0x37ac458a",
    "0x578d452a", "0x1105d869", "0x5f972521", "0x638ac688", "0x22bb206c", "0x3d2bb74b", "0x8b3659e",  "0x5c994035",
    "0xbf823b5",  "0xf126f71",  "0x4b3f0e22", "0x3274c979", "0x2a7e2fde", "0x4c5efc43", "0x51c10a78", "0x1b63549b",
    "0x3f6b4823", "0x4e3d9da4", "0x669fe91c", "0x51f27231", "0x47eb6c6c", "0x2cbe68db", "0x3a09b20d", "0x19cd3c02",
    "0x3d69b95e", "0x47e08f02", "0x73d51f24", "0x18689a99", "0x2d7d8b9d", "0x2a19c971", "0xafebd15",  "0x69b8a7ff",
    "0x1bb20d3b", "0x24fa2759", "0x7334f71d", "0x9e230b1",  "0x794f50d",  "0x74d2212",  "0x1a6c8f20", "0x1babe8f5",
    "0x16d15c2e", "0x49fbb5fc", "0x1ecdf383", "0x63dc7bc",  "0x545d4a85", "0x6a49504c", "0x3843670c", "0x586e0569",
    "0x2aa801dd", "0x38b4af42", "0x5937ccae", "0x2d7d72a6", "0x511a5bd1", "0xdc9f554",  "0x2c3e286e", "0x302b45be",
    "0x6ee05fcc", "0x27638646", "0x2b6fc4a2", "0x4c10b913", "0x420471d2", "0x29b908d2", "0x33f97fd5", "0x6834fc5",
    "0x70bee4ed", "0x4fe57541", "0x620e9e99", "0x6355ade6"};

  static const std::string mds_matrix_8[] = {
    "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3", "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1",
    "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7", "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6", "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2",
    "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe", "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc"};

  static const std::string partial_matrix_diagonal_8[] = {"0x17a3691c", "0x84987a",   "0x1f7b62e4", "0x5967b11",
                                                          "0x427c865b", "0x3f3341af", "0x52490f5c", "0x468846c6"};

  int full_rounds_12 = 8;
  int half_full_rounds_12 = 4;
  int partial_rounds_12 = 10;
  int alpha_12 = 7;

  static const std::string rounds_constants_12[] = {
    "0x44d3bb88", "0x774148c9", "0x1562425e", "0x5070628b", "0x68799490", "0x46f432e",  "0xf2e4358",  "0x53c99049",
    "0x751c6051", "0x5b9ebc5a", "0x58893f0",  "0xdd5dd7d",  "0x4c2b4eac", "0x5a528be0", "0x675fbcc3", "0x740c9d60",
    "0x4bc6dec2", "0x23c5a8e4", "0x3189bd8c", "0x11ce185c", "0x68b9bb90", "0x670e9d8f", "0x703eadbc", "0x7102faf0",
    "0x576838aa", "0x1b6c76c6", "0x51f500b4", "0x15d639b6", "0x5c0245c9", "0x6f8df3bb", "0x4d0cc32b", "0x47b3c08b",
    "0x19292b3c", "0x96230be",  "0x173c9b43", "0x253558fa", "0x72787bae", "0x47ca9db3", "0x44234b4b", "0x4f47de93",
    "0x7309f557", "0xe7113f8",  "0x5ccfa802", "0x45f84e30", "0x518a065f", "0x2f6df559", "0x69815d68", "0x273fe8a1",
    "0x43317763", "0x74e4c89e", "0x42162b7e", "0x2ea3f9a5", "0x2bb30c04", "0x24744474", "0x69e8a40b", "0x50951c70",
    "0x47ff91bf", "0x5d7f98c6", "0x2bceacc0", "0x32a22f3b", "0x6e4b4664", "0x45d5907c", "0x2aa63f10", "0x48edb36d",
    "0x4ce8a0f9", "0x190673fe", "0x74878323", "0xc953e5b",  "0x6c251bb8", "0x6a1b0031", "0x66c83144", "0x29e57c9a",
    "0x70c4d4bc", "0x4aef5f94", "0x358a7014", "0x78d8eae",  "0x416be810", "0x77dacb86", "0x36958cc3", "0x3d125dbd",
    "0x6ce43bf2", "0x16e0b7e0", "0x50de3232", "0x3466fea8", "0x1dabba6d", "0x5cefe2b6", "0xfcb3de4",  "0x16d0a86a",
    "0x2bb9da47", "0x1aab3a29", "0x2e0ada0b", "0x3c3ee3b6", "0x3a678be3", "0x19fee590", "0x84ff04",   "0x35ae6b25",
    "0x761eaf7d", "0xed3fca7",  "0x156b59c4", "0x55e273f5", "0x2f1907f5", "0x3430dd1d", "0x101600c6", "0x66b38947",
    "0x212250e0", "0x62befa2c"};

  static const std::string mds_matrix_12[] = {
    "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x8", "0xc", "0x2", "0x2",
    "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7",
    "0x1", "0x3", "0x5", "0x7", "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3", "0x4", "0x6", "0x1", "0x1",
    "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1", "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6", "0x4", "0x6", "0x1", "0x1",
    "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7",
    "0x2", "0x6", "0xa", "0xe", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc"};

  static const std::string partial_matrix_diagonal_12[] = {"0x5ce6d180", "0x392b0108", "0xcbd124d",  "0x6f099b7",
                                                           "0x6cb3ebb5", "0x363069b2", "0x4de47c38", "0x6af5a0c",
                                                           "0x52a0045f", "0x3e9f380e", "0xdf8c11f",  "0x63a32986"};

  int full_rounds_16 = 8;
  int half_full_rounds_16 = 4;
  int partial_rounds_16 = 13;
  int alpha_16 = 7;

  static const std::string rounds_constants_16[] = {
    "0x69cbb6af", "0x46ad93f9", "0x60a00f4e", "0x6b1297cd", "0x23189afe", "0x732e7bef", "0x72c246de", "0x2c941900",
    "0x557eede",  "0x1580496f", "0x3a3ea77b", "0x54f3f271", "0xf49b029",  "0x47872fe1", "0x221e2e36", "0x1ab7202e",
    "0x487779a6", "0x3851c9d8", "0x38dc17c0", "0x209f8849", "0x268dcee8", "0x350c48da", "0x5b9ad32e", "0x523272b",
    "0x3f89055b", "0x1e894b2",  "0x13ddedde", "0x1b2ef334", "0x7507d8b4", "0x6ceeb94e", "0x52eb6ba2", "0x50642905",
    "0x5453f3f",  "0x6349efc",  "0x6922787c", "0x4bfff9c",  "0x768c714a", "0x3e9ff21a", "0x15737c9c", "0x2229c807",
    "0xd47f88c",  "0x97e0ecc",  "0x27eadba0", "0x2d7d29e4", "0x3502aaa0", "0xf475fd7",  "0x29fbda49", "0x18afffd",
    "0x315b618",  "0x6d4497d1", "0x1b171d9e", "0x52861abd", "0x2e5d0501", "0x3ec8646c", "0x6e5f250a", "0x148ae8e6",
    "0x17f5fa4a", "0x3e66d284", "0x51aa3b",   "0x483f7913", "0x2cfe5f15", "0x23427ca",  "0x2cc78315", "0x1e36ea47",
    "0x5a8053c0", "0x693be639", "0x3858867d", "0x19334f6b", "0x128f0fd8", "0x4e2b1ccb", "0x61210ce0", "0x3c318939",
    "0xb5b2f22",  "0x2edb11d5", "0x213effdf", "0xcac4606",  "0x241af16d", "0x7290a80d", "0x6f7e5329", "0x598ec8a8",
    "0x76a859a0", "0x6559e868", "0x657b83af", "0x13271d3f", "0x1f876063", "0xaeeae37",  "0x706e9ca6", "0x46400cee",
    "0x72a05c26", "0x2c589c9e", "0x20bd37a7", "0x6a2d3d10", "0x20523767", "0x5b8fe9c4", "0x2aa501d6", "0x1e01ac3e",
    "0x1448bc54", "0x5ce5ad1c", "0x4918a14d", "0x2c46a83f", "0x4fcf6876", "0x61d8d5c8", "0x6ddf4ff9", "0x11fda4d3",
    "0x2933a8f",  "0x170eaf81", "0x5a9c314f", "0x49a12590", "0x35ec52a1", "0x58eb1611", "0x5e481e65", "0x367125c9",
    "0xeba33ba",  "0x1fc28ded", "0x66399ad",  "0xcbec0ea",  "0x75fd1af0", "0x50f5bf4e", "0x643d5f41", "0x6f4fe718",
    "0x5b3cbbde", "0x1e3afb3e", "0x296fb027", "0x45e1547b", "0x4a8db2ab", "0x59986d19", "0x30bcdfa3", "0x1db63932",
    "0x1d7c2824", "0x53b33681", "0x673b747",  "0x38a98a3",  "0x2c5bce60", "0x351979cd", "0x5008fb73", "0x547bca78",
    "0x711af481", "0x3f93bf64", "0x644d987b", "0x3c8bcd87", "0x608758b8"};

  static const std::string mds_matrix_16[] = {
    "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3",
    "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7",
    "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3",
    "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7",
    "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3",
    "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7",
    "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6",
    "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe",
    "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc"};

  static const std::string partial_matrix_diagonal_16[] = {
    "0xa632d95",  "0x6db657b8", "0x56fbdc9f", "0x52b3d8b",  "0x33745202", "0x5c03108d", "0xbeba37c",  "0x258c2e8c",
    "0x12029f3a", "0x694909cf", "0x6d231725", "0x21c3b223", "0x3c0904a6", "0x1d6acdb",  "0x27705c84", "0x5231c803"};

  int full_rounds_20 = 8;
  int half_full_rounds_20 = 4;
  int partial_rounds_20 = 18;
  int alpha_20 = 7;

  static const std::string rounds_constants_20[] = {
    "0x30cd4497", "0x67cf7d92", "0x113ca786", "0x28f511f7", "0x4c850311", "0x3dc07be8", "0xc8214b9",  "0x18090d97",
    "0x684f35fb", "0x11eeba68", "0x567d0ca7", "0x6d3fbebc", "0x47028460", "0x9a8d433",  "0x46bc5d5c", "0x110805b2",
    "0x50dddc82", "0x1ee4fa",   "0x55ed4719", "0x4708bdce", "0x1a530b2b", "0x6d372400", "0x32101d42", "0x2b0d7d0",
    "0x3064f512", "0x670f3c64", "0x35735e31", "0x5a2b6144", "0x210d6ba6", "0x1274e66a", "0x212e3e09", "0x57e62ff0",
    "0x6b631874", "0x6b577a1b", "0xd17fdaa",  "0x24ebe81b", "0x34f6c9fe", "0x591d5a55", "0x5f45a942", "0x5e454f3f",
    "0x23b75633", "0x55076170", "0x3caa9482", "0x6a2cbf00", "0x7224801b", "0x74bb2d64", "0x2e6d0990", "0x23eab921",
    "0x663603a8", "0x3e8e97f",  "0x4db5d3d",  "0x64c1e827", "0x37c478fe", "0x35efc805", "0x555aaef9", "0x6563ad0c",
    "0x14c9aeac", "0x16d6e172", "0x424fcbe9", "0x30380855", "0x74d4e5bf", "0x1275ba83", "0x56f32a2d", "0x3cf97f89",
    "0x440c5711", "0x48687e8a", "0x496600f8", "0xb0e429f",  "0x154b1e26", "0x379bb8ce", "0x277683e5", "0x4403e094",
    "0x12033240", "0x3bd006d7", "0x4ee6ee1b", "0x62c6764c", "0x7230552f", "0x4f341de7", "0x3c8f8c49", "0x6fc6bee2",
    "0xa3ef74d",  "0x23710107", "0x24650c82", "0x12baebd4", "0x46c2f3ce", "0x57816fd9", "0x443fe51c", "0x2a7805ab",
    "0x3f508ef1", "0x150b836c", "0x1c014ffa", "0x1c0786be", "0x10645190", "0x607b9c0a", "0x48961505", "0x6f20b7bb",
    "0x5b5aea23", "0x1fe5355c", "0x27ef98aa", "0x43e120b",  "0x647d5ccd", "0x455c81b2", "0x6ac27d3f", "0x279f6126",
    "0x76a15758", "0x58c1b0a6", "0x4af83901", "0x45641d4f", "0x1dfe8c33", "0x3720c88",  "0x3482d40d", "0x770d8960",
    "0x6108b730", "0x63fc084",  "0x96e2a34",  "0x130514a0", "0x42bc3eff", "0x43775848", "0x702960e4", "0x6cf19c79",
    "0x4c3030dd", "0x6dd27932", "0x64350de9", "0x480e8311", "0x6a22632c", "0x2814bcf6", "0x117197e3", "0x4844d419",
    "0x76e181a6", "0x6155d7b4", "0x42dbed26", "0x62e9c27b", "0x105b4f11", "0x51d45858", "0x33fa0298", "0x26a08228",
    "0x5f14581f", "0x3bd89737", "0x2325968f", "0x418512ba", "0x2f47442f", "0xe680af5",  "0xc424cba",  "0x6d3885ae",
    "0xa9c8cbe",  "0x2485f2a9", "0x1f99357f", "0xf58d531",  "0x32d6f6b1", "0x2c26876d", "0x2de3d38e", "0x5a7b6cc9",
    "0x1caec7f0", "0x4aa1f575", "0x77af0ccd", "0x19d3be5c", "0xaa619d8",  "0x4cfea78",  "0xdb3ab76",  "0x2ddffaa3",
    "0x52246767", "0x50d7f018", "0x318ceb9f", "0x2e69a506", "0x4bd9d1fa", "0x2a0b579a", "0x561238c2", "0x2877bb9a",
    "0x6ed2c79",  "0x229998ba", "0x737f0185", "0x609aad31", "0x2cee3551", "0x4434bd17", "0x1da8546f", "0x3532fbe6",
    "0x2637b96d", "0x2b04084"};

  static const std::string mds_matrix_20[] = {
    "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3",
    "0x5", "0x7", "0x1", "0x3", "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x2", "0x2", "0x8", "0xc",
    "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3",
    "0x5", "0x7", "0x1", "0x3", "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1",
    "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x1", "0x4", "0x6",
    "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3",
    "0x5", "0x7", "0x1", "0x3", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2",
    "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7",
    "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x1", "0x4", "0x6",
    "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7",
    "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7", "0x1", "0x1", "0x4", "0x6",
    "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3",
    "0xa", "0xe", "0x2", "0x6", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe", "0x1", "0x1", "0x4", "0x6",
    "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc"};

  static const std::string partial_matrix_diagonal_20[] = {
    "0x60531da4", "0x332932dc", "0x61f05e58", "0x614050f9", "0x4323c6de", "0x10b33548", "0x5e5ce1d9",
    "0x19a24086", "0x3c697e94", "0x365de6ba", "0x71f95069", "0x350c9229", "0x3883d126", "0x51502e2f",
    "0x1a4a8175", "0x1e081b3",  "0x54c1086b", "0x1253bc2b", "0x50599b35", "0x25b97c4"};

  int full_rounds_24 = 8;
  int half_full_rounds_24 = 4;
  int partial_rounds_24 = 21;
  int alpha_24 = 7;

  static const std::string rounds_constants_24[] = {
    "0xfa20c37",  "0x795bb97",  "0x12c60b9c", "0xeabd88e",  "0x96485ca",  "0x7093527",  "0x1b1d4e50", "0x30a01ace",
    "0x3bd86f5a", "0x69af7c28", "0x3f94775f", "0x731560e8", "0x465a0ecd", "0x574ef807", "0x62fd4870", "0x52ccfe44",
    "0x14772b14", "0x4dedf371", "0x260acd7c", "0x1f51dc58", "0x75125532", "0x686a4d7b", "0x54bac179", "0x31947706",
    "0x29799d3b", "0x6e01ae90", "0x203a7a64", "0x4f7e25be", "0x72503f77", "0x45bd3b69", "0x769bd6b4", "0x5a867f08",
    "0x4fdba082", "0x251c4318", "0x28f06201", "0x6788c43a", "0x4c6d6a99", "0x357784a8", "0x2abaf051", "0x770f7de6",
    "0x1794b784", "0x4796c57a", "0x724b7a10", "0x449989a7", "0x64935cf1", "0x59e14aac", "0xe620bb8",  "0x3af5a33b",
    "0x4465cc0e", "0x19df68f",  "0x4af8d068", "0x8784f82",  "0xcefdeae",  "0x6337a467", "0x32fa7a16", "0x486f62d6",
    "0x386a7480", "0x20f17c4a", "0x54e50da8", "0x2012cf03", "0x5fe52950", "0x9afb6cd",  "0x2523044e", "0x5c54d0ef",
    "0x71c01f3c", "0x60b2c4fb", "0x4050b379", "0x5e6a70a5", "0x418543f5", "0x71debe56", "0x1aad2994", "0x3368a483",
    "0x7a86f3a",  "0x5ea43ff1", "0x2443780e", "0x4ce444f7", "0x146f9882", "0x3132b089", "0x197ea856", "0x667030c3",
    "0x2317d5dc", "0xc2c48a7",  "0x56b2df66", "0x67bd81e9", "0x4fcdfb19", "0x4baaef32", "0x328d30a",  "0x6235760d",
    "0x12432912", "0xa49e258",  "0x30e1b70",  "0x48caeb03", "0x49e4d9e9", "0x1051b5c6", "0x6a36dbbe", "0x4cff27a5",
    "0x1da78ec2", "0x730b0924", "0x3eb56cf3", "0x5bd93073", "0x37204c97", "0x51642d89", "0x66e943e8", "0x1a3e72de",
    "0x70beb1e9", "0x30ff3b3f", "0x4240d1c4", "0x12647b8d", "0x65d86965", "0x49ef4d7c", "0x47785697", "0x46b3969f",
    "0x5c7b7a0e", "0x7078fc60", "0x4f22d482", "0x482a9aee", "0x6beb839d", "0x32959ad",  "0x2b18af6a", "0x55d3dc8c",
    "0x43bd26c8", "0xc41595f",  "0x7048d2e2", "0xdb8983",   "0x2af563d7", "0x6e84758f", "0x611d64e1", "0x1f9977e2",
    "0x64163a0a", "0x5c5fc27b", "0x2e22561",  "0x3a2d75db", "0x1ba7b71a", "0x34343f64", "0x7406b35d", "0x19df8299",
    "0x6ff4480a", "0x514a81c8", "0x57ab52ce", "0x6ad69f52", "0x3e0c0e0d", "0x48126114", "0x2a9d62cc", "0x17441f23",
    "0x485762bb", "0x2f218674", "0x6fdc64a",  "0x861b7f2",  "0x3b36eee6", "0x70a11040", "0x4b31737",  "0x3722a872",
    "0x2a351c63", "0x623560dc", "0x62584ab2", "0x382c7c04", "0x3bf9edc7", "0xe38fe51",  "0x376f3b10", "0x5381e178",
    "0x3afc61c7", "0x5c1bcb4d", "0x6643ce1f", "0x2d0af1c1", "0x8f583cc",  "0x5d6ff60f", "0x6324c1e5", "0x74412fb7",
    "0x70c0192e", "0xb72f141",  "0x4067a111", "0x57388c4f", "0x351009ec", "0x974c159",  "0x539a58b3", "0x38c0cff",
    "0x476c0392", "0x3f7bc15f", "0x4491dd2c", "0x4d1fef55", "0x4936ae3",  "0x58214dd4", "0x683c6aad", "0x1b42f16b",
    "0x6dc79135", "0x2d4e71ec", "0x3e2946ea", "0x59dce8db", "0x6cee892a", "0x47f07350", "0x7106ce93", "0x3bd4a7a9",
    "0x2bfe636a", "0x430011e9", "0x1cd66a",   "0x307faf5b", "0xd9ef3fe",  "0x6d40043a", "0x2e8f470c", "0x1b6865e8",
    "0xc0e6c01",  "0x4d41981f", "0x423b9d3d", "0x410408cc", "0x263f0884", "0x5311bbd0", "0x4dae58d8", "0x30401cea",
    "0x9afa575",  "0x4b3d5b42", "0x63ac0b37", "0x5fe5bb14", "0x5244e9d4"};

  static const std::string mds_matrix_24[] = {
    "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1",
    "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6",
    "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2",
    "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc",
    "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3",
    "0xa", "0xe", "0x2", "0x6", "0x5", "0x7", "0x1", "0x3", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2", "0x4", "0x6", "0x1", "0x1",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7",
    "0x2", "0x6", "0xa", "0xe", "0x1", "0x3", "0x5", "0x7", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc", "0x1", "0x1", "0x4", "0x6",
    "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3",
    "0x5", "0x7", "0x1", "0x3", "0xa", "0xe", "0x2", "0x6", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1",
    "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x8", "0xc", "0x2", "0x2",
    "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7", "0x1", "0x3", "0x5", "0x7",
    "0x1", "0x3", "0x5", "0x7", "0x2", "0x6", "0xa", "0xe", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6",
    "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x1", "0x1", "0x4", "0x6", "0x2", "0x2", "0x8", "0xc"};

  static const std::string partial_matrix_diagonal_24[] = {
    "0x409133f1", "0x1667a8a2", "0x6a6c7b7",  "0x6f53160f", "0x273b11d2", "0x3176c5e",  "0x72f9bbfa", "0x73ceba92",
    "0x5cdef81e", "0x1393286",  "0x46daee07", "0x65d7ba7",  "0x52d72d70", "0x5dd05e1",  "0x3bab4b64", "0x6ada3843",
    "0x2fc5fbed", "0x770d61b1", "0x5715aaea", "0x3ef0e91",  "0x75b6c771", "0x242adf60", "0xd0ca4d",   "0x36c0e389"};

} // namespace poseidon2_constants_babybear
#endif