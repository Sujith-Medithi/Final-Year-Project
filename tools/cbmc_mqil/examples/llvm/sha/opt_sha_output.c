unsigned int llvm_fshl_i32(unsigned int var0, unsigned int var1,
                           unsigned int var2);
void llvm_lifetime_end_p0i8(unsigned long var0, unsigned char *var1);
void llvm_lifetime_start_p0i8(unsigned long var0, unsigned char *var1);
unsigned int llvm_smin_i32(unsigned int var0, unsigned int var1);
void local_memcpy(unsigned int *var0, unsigned char *var1, unsigned int var2);
void local_memset(unsigned int *var0, unsigned int var1, unsigned int var2,
                  unsigned int var3);
unsigned int printf(unsigned char *var0, ...);
void sha_final();
void sha_init();
void sha_stream();
void sha_transform();
void sha_update(unsigned char *var0, unsigned int var1);
unsigned char indata_1[2][8192];
unsigned char indata_2[2][8192];
unsigned char indata[2][8192];
unsigned int in_i_1[2];
unsigned int in_i_2[2];
unsigned int in_i[2];
unsigned int sha_info_digest_1[5];
unsigned int sha_info_digest_2[5];
unsigned int sha_info_digest[5];
unsigned int sha_info_count_lo_1 = 0;
unsigned int sha_info_count_lo_2 = 0;
unsigned int sha_info_count_lo = 0;
unsigned int sha_info_count_hi_1 = 0;
unsigned int sha_info_count_hi_2 = 0;
unsigned int sha_info_count_hi = 0;
unsigned int sha_info_data_1[16];
unsigned int sha_info_data_2[16];
unsigned int sha_info_data[16];
unsigned int outData_1[5];
unsigned int outData_2[5];
unsigned int outData[5];
unsigned char _str_1[4];
unsigned char _str_2[4];
unsigned char _str[4];
unsigned int nd_sha_info_digest();
void local_memcpy_2(unsigned int *var0_1, unsigned char *var1_1,
                    unsigned int var2_1, unsigned int *var0_2,
                    unsigned char *var1_2, unsigned int var2_2) {
  unsigned int var4_phi_1;
  unsigned int var4_phi_2;
  unsigned int *var5_phi_1;
  unsigned int *var5_phi_2;
  unsigned char *var6_phi_1;
  unsigned char *var6_phi_2;
  int var3_1;
  int var3_2;
  int var7_1;
  int var7_2;
  unsigned char *var8_1;
  unsigned char *var8_2;
  unsigned int *var9_1;
  unsigned int *var9_2;
block0_1:
  if (((int)var2_1) > ((int)3)) {
    var3_1 = ((int)var2_1) / ((int)4);
    var4_phi_1 = var3_1;
    var5_phi_1 = var0_1;
    var6_phi_1 = var1_1;
    do {
      var4_phi_1 = var7_1;
      var5_phi_1 = var9_1;
      var6_phi_1 = var8_1;
      var7_1 = ((int)var4_phi_1) + ((int)(-1));
      var8_1 = &(*(((unsigned char *)var6_phi_1) + 4));
      *var5_phi_1 =
          (((((int)((unsigned int)(*(((unsigned char *)var6_phi_1) + 1))))
             << ((int)((unsigned int)((int)8)))) |
            ((unsigned int)(*var6_phi_1))) |
           (((int)((unsigned int)(*(((unsigned char *)var6_phi_1) + 2))))
            << ((int)((unsigned int)((int)16))))) |
          (((unsigned int)(*(((unsigned char *)var6_phi_1) + 3)))
           << ((unsigned int)24));
      var9_1 = &(*(((unsigned int *)var5_phi_1) + 1));
    } while (var4_phi_1 > 1);
    return;
  } else {
    return;
  }

block0_2:
  if (((int)var2_2) > ((int)3)) {
    var3_2 = ((int)var2_2) / ((int)4);
    var4_phi_2 = var3_2;
    var5_phi_2 = var0_2;
    var6_phi_2 = var1_2;
    do {
      var4_phi_2 = var7_2;
      var5_phi_2 = var9_2;
      var6_phi_2 = var8_2;
      var7_2 = ((int)var4_phi_2) + ((int)(-1));
      var8_2 = &(*(((unsigned char *)var6_phi_2) + 4));
      *var5_phi_2 =
          (((((int)((unsigned int)(*(((unsigned char *)var6_phi_2) + 1))))
             << ((int)((unsigned int)((int)8)))) |
            ((unsigned int)(*var6_phi_2))) |
           (((int)((unsigned int)(*(((unsigned char *)var6_phi_2) + 2))))
            << ((int)((unsigned int)((int)16))))) |
          (((unsigned int)(*(((unsigned char *)var6_phi_2) + 3)))
           << ((unsigned int)24));
      var9_2 = &(*(((unsigned int *)var5_phi_2) + 1));
    } while (var4_phi_2 > 1);
    return;
  } else {
    return;
  }

  assert(var4_phi_1 == var4_phi_2);
  assert((*var5_phi_1) == (*var5_phi_2));
  assert((*var6_phi_1) == (*var6_phi_2));
  assert(var3_1 == var3_2);
  assert(var7_1 == var7_2);
  assert((*var8_1) == (*var8_2));
  assert((*var9_1) == (*var9_2));
}

void local_memcpy(unsigned int *var0, unsigned char *var1, unsigned int var2) {
  unsigned int var4_phi;
  unsigned int *var5_phi;
  unsigned char *var6_phi;
  int var3;
  int var7;
  unsigned char *var8;
  unsigned int *var9;
block0:
  if (((int)var2) > ((int)3)) {
    var3 = ((int)var2) / ((int)4);
    var4_phi = var3;
    var5_phi = var0;
    var6_phi = var1;
    do {
      var4_phi = var7;
      var5_phi = var9;
      var6_phi = var8;
      var7 = ((int)var4_phi) + ((int)(-1));
      var8 = &(*(((unsigned char *)var6_phi) + 4));
      *var5_phi = (((((int)((unsigned int)(*(((unsigned char *)var6_phi) + 1))))
                     << ((int)((unsigned int)((int)8)))) |
                    ((unsigned int)(*var6_phi))) |
                   (((int)((unsigned int)(*(((unsigned char *)var6_phi) + 2))))
                    << ((int)((unsigned int)((int)16))))) |
                  (((unsigned int)(*(((unsigned char *)var6_phi) + 3)))
                   << ((unsigned int)24));
      var9 = &(*(((unsigned int *)var5_phi) + 1));
    } while (var4_phi > 1);
    return;
  } else {
    return;
  }
}

void local_memset_2(unsigned int *var0_1, unsigned int var1_1,
                    unsigned int var2_1, unsigned int var3_1,
                    unsigned int *var0_2, unsigned int var1_2,
                    unsigned int var2_2, unsigned int var3_2) {
  unsigned int var6_phi_1;
  unsigned int var6_phi_2;
  unsigned int *var7_phi_1;
  unsigned int *var7_phi_2;
  unsigned int *var4_1;
  unsigned int *var4_2;
  int var5_1;
  int var5_2;
  int var8_1;
  int var8_2;
  unsigned int *var9_1;
  unsigned int *var9_2;
block0_1:
  if (((int)var2_1) > ((int)3)) {
    var4_1 = &(*(((unsigned int *)var0_1) +
                 ((((int)var3_1) > ((int)0))
                      ? (((long)((unsigned long)(var3_1 + (-1)))) + ((long)1))
                      : (0))));
    var5_1 = ((int)var2_1) / ((int)4);
    var6_phi_1 = var5_1;
    var7_phi_1 = var4_1;
    do {
      var6_phi_1 = var8_1;
      var7_phi_1 = var9_1;
      var8_1 = ((int)var6_phi_1) + ((int)(-1));
      var9_1 = &(*(((unsigned int *)var7_phi_1) + 1));
      *var7_phi_1 = var1_1;
    } while (var6_phi_1 > 1);
    return;
  } else {
    return;
  }

block0_2:
  if (((int)var2_2) > ((int)3)) {
    var4_2 = &(*(((unsigned int *)var0_2) +
                 ((((int)var3_2) > ((int)0))
                      ? (((long)((unsigned long)(var3_2 + (-1)))) + ((long)1))
                      : (0))));
    var5_2 = ((int)var2_2) / ((int)4);
    var6_phi_2 = var5_2;
    var7_phi_2 = var4_2;
    do {
      var6_phi_2 = var8_2;
      var7_phi_2 = var9_2;
      var8_2 = ((int)var6_phi_2) + ((int)(-1));
      var9_2 = &(*(((unsigned int *)var7_phi_2) + 1));
      *var7_phi_2 = var1_2;
    } while (var6_phi_2 > 1);
    return;
  } else {
    return;
  }

  assert(var6_phi_1 == var6_phi_2);
  assert((*var7_phi_1) == (*var7_phi_2));
  assert((*var4_1) == (*var4_2));
  assert(var5_1 == var5_2);
  assert(var8_1 == var8_2);
  assert((*var9_1) == (*var9_2));
}

void local_memset(unsigned int *var0, unsigned int var1, unsigned int var2,
                  unsigned int var3) {
  unsigned int var6_phi;
  unsigned int *var7_phi;
  unsigned int *var4;
  int var5;
  int var8;
  unsigned int *var9;
block0:
  if (((int)var2) > ((int)3)) {
    var4 = &(*(((unsigned int *)var0) +
               ((((int)var3) > ((int)0))
                    ? (((long)((unsigned long)(var3 + (-1)))) + ((long)1))
                    : (0))));
    var5 = ((int)var2) / ((int)4);
    var6_phi = var5;
    var7_phi = var4;
    do {
      var6_phi = var8;
      var7_phi = var9;
      var8 = ((int)var6_phi) + ((int)(-1));
      var9 = &(*(((unsigned int *)var7_phi) + 1));
      *var7_phi = var1;
    } while (var6_phi > 1);
    return;
  } else {
    return;
  }
}

void main() {
  for (int i_0 = 0; i_0 < 5; i_0++) {
    sha_info_digest_1[i_0] = nd_sha_info_digest();
  }

  for (int i_0 = 0; i_0 < 5; i_0++) {
    sha_info_digest_2[i_0] = nd_sha_info_digest();
  }

  unsigned long var0_phi_1;
  unsigned long var0_phi_2;
  unsigned int var1_phi_1;
  unsigned int var1_phi_2;
  unsigned int var4_phi_1;
  unsigned int var4_phi_2;
  int var2_1;
  int var2_2;
  long var3_1;
  long var3_2;
block0_1:
  sha_stream();

block0_2:
  sha_stream();

  sha_stream_2();
  var0_phi_1 = 0;
  var0_phi_2 = 0;
  var1_phi_1 = 0;
  var1_phi_2 = 0;
  do {
    var0_phi_1 = var3_1;
    var0_phi_2 = var3_2;
    var1_phi_1 = var2_1;
    var1_phi_2 = var2_2;
    var2_1 = ((int)var1_phi_1) +
             ((int)((unsigned int)(sha_info_digest_1[var0_phi_1] !=
                                   outData_1[var0_phi_1])));
    var2_2 = ((int)var1_phi_2) +
             ((int)((unsigned int)(sha_info_digest_2[var0_phi_2] !=
                                   outData_2[var0_phi_2])));
    var3_1 = ((long)var0_phi_1) + ((long)1);
    var3_2 = ((long)var0_phi_2) + ((long)1);
  } while ((var3_1 == 5) && (var3_2 == 5));
  printf(&_str_1[0], var4_phi_1);
  printf(&_str_2[0], var4_phi_2);
  printf_2(&_str_1[0], var4_phi_1, &_str_2[0], var4_phi_2);
  for (int i_0 = 0; i_0 < 16; i_0++) {
    __CPROVER_assume(sha_info_data_1[i_0] == sha_info_data_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 5; i_0++) {
    __CPROVER_assume(sha_info_digest_1[i_0] != sha_info_digest_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 5; i_0++) {
    assert(outData_1[i_0] == outData_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++) {
    assert(_str_1[i_0] == _str_2[i_0]);
  }

  assert(var0_phi_1 == var0_phi_2);
  assert(var1_phi_1 == var1_phi_2);
  assert(var4_phi_1 == var4_phi_2);
  assert(var2_1 == var2_2);
  assert(var3_1 == var3_2);
}

void sha_final_2() {
  unsigned int var0_1;
  unsigned int var0_2;
  unsigned int var1_1;
  unsigned int var1_2;
  unsigned int var2_1;
  unsigned int var2_2;
  unsigned long var3_1;
  unsigned long var3_2;
  unsigned int var4_1;
  unsigned int var4_2;
  unsigned int var5_1;
  unsigned int var5_2;
  unsigned char *var6_1;
  unsigned char *var6_2;
  int var7_1;
  int var7_2;
  unsigned char *var8_1;
  unsigned char *var8_2;
block0_1:
  var0_1 = sha_info_count_lo_1;

block0_2:
  var0_2 = sha_info_count_lo_2;

  var1_1 = sha_info_count_hi_1;
  var1_2 = sha_info_count_hi_2;
  var2_1 = (var0_1 >> 3) & 63;
  var2_2 = (var0_2 >> 3) & 63;
  var3_1 = (unsigned long)var2_1;
  var3_2 = (unsigned long)var2_2;
  sha_info_data_1[var3_1] = 128;
  sha_info_data_2[var3_2] = 128;
  if (var2_1 > 55) {
    var4_1 = var2_1 ^ 63;
    var5_1 = var4_1 >> 2;
    if (var4_1 > 3) {
      var6_1 = (unsigned char *)(&sha_info_data_1[((long)var3_1) + ((long)1)]);
      memset(var6_1, 0,
             ((long)(((long)((unsigned long)(((int)var5_1) -
                                             ((int)llvm_smin_i32(var5_1, 1)))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block3_1;
    } else {
      goto block3_1;
    }
  } else {
    var7_1 = ((int)(((int)55) - ((int)var2_1))) / ((int)4);
    if (var2_1 < 52) {
      var8_1 = (unsigned char *)(&sha_info_data_1[((long)var3_1) + ((long)1)]);
      memset(var8_1, 0,
             ((long)(((long)((unsigned long)(((unsigned int)var7_1) -
                                             llvm_smin_i32(var7_1, 1))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block6_1;
    } else {
      goto block6_1;
    }
  }
  if (var2_2 > 55) {
    var4_2 = var2_2 ^ 63;
    var5_2 = var4_2 >> 2;
    if (var4_2 > 3) {
      var6_2 = (unsigned char *)(&sha_info_data_2[((long)var3_2) + ((long)1)]);
      memset(var6_2, 0,
             ((long)(((long)((unsigned long)(((int)var5_2) -
                                             ((int)llvm_smin_i32(var5_2, 1)))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block3_2;
    } else {
      goto block3_2;
    }
  } else {
    var7_2 = ((int)(((int)55) - ((int)var2_2))) / ((int)4);
    if (var2_2 < 52) {
      var8_2 = (unsigned char *)(&sha_info_data_2[((long)var3_2) + ((long)1)]);
      memset(var8_2, 0,
             ((long)(((long)((unsigned long)(((unsigned int)var7_2) -
                                             llvm_smin_i32(var7_2, 1))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block6_2;
    } else {
      goto block6_2;
    }
  }
  memset_2(var6_1, 0,
           ((long)(((long)((unsigned long)(((int)var5_1) -
                                           ((int)llvm_smin_i32(var5_1, 1)))))
                   << ((long)((unsigned long)((long)2))))) +
               ((long)4),
           var6_2, 0,
           ((long)(((long)((unsigned long)(((int)var5_2) -
                                           ((int)llvm_smin_i32(var5_2, 1)))))
                   << ((long)((unsigned long)((long)2))))) +
               ((long)4));
block3_1:
  sha_transform();

block3_2:
  sha_transform();

  sha_transform_2();
  memset((unsigned char *)(&sha_info_data_1), 0, 56);
  memset((unsigned char *)(&sha_info_data_2), 0, 56);
  memset_2((unsigned char *)(&sha_info_data_1), 0, 56,
           (unsigned char *)(&sha_info_data_2), 0, 56);
  goto block6_1;
  goto block6_2;
block6_1:
  sha_info_data_1[14] = var1_1;

block6_2:
  sha_info_data_2[14] = var1_2;

  sha_info_data_1[15] = var0_1;
  sha_info_data_2[15] = var0_2;
  sha_transform();
  sha_transform();
  sha_transform_2();
  assert(sha_info_count_lo_1 == sha_info_count_lo_2);
  assert(sha_info_count_hi_1 == sha_info_count_hi_2);
  assert(var0_1 == var0_2);
  assert(var1_1 == var1_2);
  assert(var2_1 == var2_2);
  assert(var3_1 == var3_2);
  assert(var4_1 == var4_2);
  assert(var5_1 == var5_2);
  assert((*var6_1) == (*var6_2));
  assert(var7_1 == var7_2);
  assert((*var8_1) == (*var8_2));
}

void sha_final() {
  unsigned int var0;
  unsigned int var1;
  unsigned int var2;
  unsigned long var3;
  unsigned int var4;
  unsigned int var5;
  unsigned char *var6;
  int var7;
  unsigned char *var8;
block0:
  var0 = sha_info_count_lo;

  var1 = sha_info_count_hi;
  var2 = (var0 >> 3) & 63;
  var3 = (unsigned long)var2;
  sha_info_data[var3] = 128;
  if (var2 > 55) {
    var4 = var2 ^ 63;
    var5 = var4 >> 2;
    if (var4 > 3) {
      var6 = (unsigned char *)(&sha_info_data[((long)var3) + ((long)1)]);
      memset(var6, 0,
             ((long)(((long)((unsigned long)(((int)var5) -
                                             ((int)llvm_smin_i32(var5, 1)))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block3;
    } else {
      goto block3;
    }
  } else {
    var7 = ((int)(((int)55) - ((int)var2))) / ((int)4);
    if (var2 < 52) {
      var8 = (unsigned char *)(&sha_info_data[((long)var3) + ((long)1)]);
      memset(var8, 0,
             ((long)(((long)((unsigned long)(((unsigned int)var7) -
                                             llvm_smin_i32(var7, 1))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block6;
    } else {
      goto block6;
    }
  }
block3:
  sha_transform();

  memset((unsigned char *)(&sha_info_data), 0, 56);
  goto block6;
block6:
  sha_info_data[14] = var1;

  sha_info_data[15] = var0;
  sha_transform();
  return;
}

void sha_init_2() {
block0_1:
  sha_info_digest_1[0] = 1732584193;

block0_2:
  sha_info_digest_2[0] = 1732584193;

  sha_info_digest_1[1] = -271733879;
  sha_info_digest_2[1] = -271733879;
  sha_info_digest_1[2] = -1732584194;
  sha_info_digest_2[2] = -1732584194;
  sha_info_digest_1[3] = 271733878;
  sha_info_digest_2[3] = 271733878;
  sha_info_digest_1[4] = -1009589776;
  sha_info_digest_2[4] = -1009589776;
  sha_info_count_lo_1 = 0;
  sha_info_count_lo_2 = 0;
  sha_info_count_hi_1 = 0;
  sha_info_count_hi_2 = 0;
  assert(sha_info_count_lo_1 == sha_info_count_lo_2);
  assert(sha_info_count_hi_1 == sha_info_count_hi_2);
}

void sha_init() {
block0:
  sha_info_digest[0] = 1732584193;

  sha_info_digest[1] = -271733879;
  sha_info_digest[2] = -1732584194;
  sha_info_digest[3] = 271733878;
  sha_info_digest[4] = -1009589776;
  sha_info_count_lo = 0;
  sha_info_count_hi = 0;
  return;
}

void sha_stream_2() {
  unsigned long var0_phi_1;
  unsigned long var0_phi_2;
  long var1_1;
  long var1_2;
  unsigned int var2_1;
  unsigned int var2_2;
  unsigned int var3_1;
  unsigned int var3_2;
  unsigned int var4_1;
  unsigned int var4_2;
  unsigned long var5_1;
  unsigned long var5_2;
  unsigned int var6_1;
  unsigned int var6_2;
  unsigned int var7_1;
  unsigned int var7_2;
  unsigned char *var8_1;
  unsigned char *var8_2;
  int var9_1;
  int var9_2;
  unsigned char *var10_1;
  unsigned char *var10_2;
block0_1:
  sha_info_digest_1[0] = 1732584193;

block0_2:
  sha_info_digest_2[0] = 1732584193;

  sha_info_digest_1[1] = -271733879;
  sha_info_digest_2[1] = -271733879;
  sha_info_digest_1[2] = -1732584194;
  sha_info_digest_2[2] = -1732584194;
  sha_info_digest_1[3] = 271733878;
  sha_info_digest_2[3] = 271733878;
  sha_info_digest_1[4] = -1009589776;
  sha_info_digest_2[4] = -1009589776;
  sha_info_count_lo_1 = 0;
  sha_info_count_lo_2 = 0;
  sha_info_count_hi_1 = 0;
  sha_info_count_hi_2 = 0;
  var0_phi_1 = 0;
  var0_phi_2 = 0;
  do {
    var0_phi_1 = var1_1;
    var0_phi_2 = var1_2;
    sha_update(&indata_1[var0_phi_1][0], in_i_1[var0_phi_1]);
    sha_update(&indata_2[var0_phi_2][0], in_i_2[var0_phi_2]);
    sha_update_2(&indata_1[var0_phi_1][0], in_i_1[var0_phi_1],
                 &indata_2[var0_phi_2][0], in_i_2[var0_phi_2]);
    var1_1 = ((long)var0_phi_1) + ((long)1);
    var1_2 = ((long)var0_phi_2) + ((long)1);
  } while ((var0_phi_1 == 0) && (var0_phi_2 == 0));
  var2_1 = sha_info_count_lo_1;
  var2_2 = sha_info_count_lo_2;
  var3_1 = sha_info_count_hi_1;
  var3_2 = sha_info_count_hi_2;
  var4_1 = (var2_1 >> 3) & 63;
  var4_2 = (var2_2 >> 3) & 63;
  var5_1 = (unsigned long)var4_1;
  var5_2 = (unsigned long)var4_2;
  sha_info_data_1[var5_1] = 128;
  sha_info_data_2[var5_2] = 128;
  if (var4_1 > 55) {
    var6_1 = var4_1 ^ 63;
    var7_1 = var6_1 >> 2;
    if (var6_1 > 3) {
      var8_1 = (unsigned char *)(&sha_info_data_1[((long)var5_1) + ((long)1)]);
      memset(var8_1, 0,
             ((long)(((long)((unsigned long)(((int)var7_1) -
                                             ((int)llvm_smin_i32(var7_1, 1)))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block5_1;
    } else {
      goto block5_1;
    }
  } else {
    var9_1 = ((int)(((int)55) - ((int)var4_1))) / ((int)4);
    if (var4_1 < 52) {
      var10_1 = (unsigned char *)(&sha_info_data_1[((long)var5_1) + ((long)1)]);
      memset(var10_1, 0,
             ((long)(((long)((unsigned long)(((unsigned int)var9_1) -
                                             llvm_smin_i32(var9_1, 1))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block8_1;
    } else {
      goto block8_1;
    }
  }
  if (var4_2 > 55) {
    var6_2 = var4_2 ^ 63;
    var7_2 = var6_2 >> 2;
    if (var6_2 > 3) {
      var8_2 = (unsigned char *)(&sha_info_data_2[((long)var5_2) + ((long)1)]);
      memset(var8_2, 0,
             ((long)(((long)((unsigned long)(((int)var7_2) -
                                             ((int)llvm_smin_i32(var7_2, 1)))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block5_2;
    } else {
      goto block5_2;
    }
  } else {
    var9_2 = ((int)(((int)55) - ((int)var4_2))) / ((int)4);
    if (var4_2 < 52) {
      var10_2 = (unsigned char *)(&sha_info_data_2[((long)var5_2) + ((long)1)]);
      memset(var10_2, 0,
             ((long)(((long)((unsigned long)(((unsigned int)var9_2) -
                                             llvm_smin_i32(var9_2, 1))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block8_2;
    } else {
      goto block8_2;
    }
  }
  memset_2(var8_1, 0,
           ((long)(((long)((unsigned long)(((int)var7_1) -
                                           ((int)llvm_smin_i32(var7_1, 1)))))
                   << ((long)((unsigned long)((long)2))))) +
               ((long)4),
           var8_2, 0,
           ((long)(((long)((unsigned long)(((int)var7_2) -
                                           ((int)llvm_smin_i32(var7_2, 1)))))
                   << ((long)((unsigned long)((long)2))))) +
               ((long)4));
block5_1:
  sha_transform();

block5_2:
  sha_transform();

  sha_transform_2();
  memset((unsigned char *)(&sha_info_data_1), 0, 56);
  memset((unsigned char *)(&sha_info_data_2), 0, 56);
  memset_2((unsigned char *)(&sha_info_data_1), 0, 56,
           (unsigned char *)(&sha_info_data_2), 0, 56);
  goto block8_1;
  goto block8_2;
block8_1:
  sha_info_data_1[14] = var3_1;

block8_2:
  sha_info_data_2[14] = var3_2;

  sha_info_data_1[15] = var2_1;
  sha_info_data_2[15] = var2_2;
  sha_transform();
  sha_transform();
  sha_transform_2();
  for (int i_0 = 0; i_0 < 2; i_0++) {
    for (int i_1 = 0; i_1 < 8192; i_1++) {
      assert(indata_1[i_0][i_1] == indata_2[i_0][i_1]);
    }
  }

  for (int i_0 = 0; i_0 < 2; i_0++) {
    assert(in_i_1[i_0] == in_i_2[i_0]);
  }

  assert(sha_info_count_lo_1 == sha_info_count_lo_2);
  assert(sha_info_count_hi_1 == sha_info_count_hi_2);
  assert(var0_phi_1 == var0_phi_2);
  assert(var1_1 == var1_2);
  assert(var2_1 == var2_2);
  assert(var3_1 == var3_2);
  assert(var4_1 == var4_2);
  assert(var5_1 == var5_2);
  assert(var6_1 == var6_2);
  assert(var7_1 == var7_2);
  assert((*var8_1) == (*var8_2));
  assert(var9_1 == var9_2);
  assert((*var10_1) == (*var10_2));
}

void sha_stream() {
  unsigned long var0_phi;
  long var1;
  unsigned int var2;
  unsigned int var3;
  unsigned int var4;
  unsigned long var5;
  unsigned int var6;
  unsigned int var7;
  unsigned char *var8;
  int var9;
  unsigned char *var10;
block0:
  sha_info_digest[0] = 1732584193;

  sha_info_digest[1] = -271733879;
  sha_info_digest[2] = -1732584194;
  sha_info_digest[3] = 271733878;
  sha_info_digest[4] = -1009589776;
  sha_info_count_lo = 0;
  sha_info_count_hi = 0;
  var0_phi = 0;
  do {
    var0_phi = var1;
    sha_update(&indata[var0_phi][0], in_i[var0_phi]);
    var1 = ((long)var0_phi) + ((long)1);
  } while (var0_phi == 0);
  var2 = sha_info_count_lo;
  var3 = sha_info_count_hi;
  var4 = (var2 >> 3) & 63;
  var5 = (unsigned long)var4;
  sha_info_data[var5] = 128;
  if (var4 > 55) {
    var6 = var4 ^ 63;
    var7 = var6 >> 2;
    if (var6 > 3) {
      var8 = (unsigned char *)(&sha_info_data[((long)var5) + ((long)1)]);
      memset(var8, 0,
             ((long)(((long)((unsigned long)(((int)var7) -
                                             ((int)llvm_smin_i32(var7, 1)))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block5;
    } else {
      goto block5;
    }
  } else {
    var9 = ((int)(((int)55) - ((int)var4))) / ((int)4);
    if (var4 < 52) {
      var10 = (unsigned char *)(&sha_info_data[((long)var5) + ((long)1)]);
      memset(var10, 0,
             ((long)(((long)((unsigned long)(((unsigned int)var9) -
                                             llvm_smin_i32(var9, 1))))
                     << ((long)((unsigned long)((long)2))))) +
                 ((long)4));
      goto block8;
    } else {
      goto block8;
    }
  }
block5:
  sha_transform();

  memset((unsigned char *)(&sha_info_data), 0, 56);
  goto block8;
block8:
  sha_info_data[14] = var3;

  sha_info_data[15] = var2;
  sha_transform();
  return;
}

void sha_transform_2() {
  unsigned int var0_1[80];
  unsigned int var0_2[80];
  unsigned char *var1_1;
  unsigned char *var1_2;
  unsigned long var2_phi_1;
  unsigned long var2_phi_2;
  unsigned long var9_phi_1;
  unsigned long var9_phi_2;
  unsigned int var10_phi_1;
  unsigned int var10_phi_2;
  unsigned int var11_phi_1;
  unsigned int var11_phi_2;
  unsigned int var12_phi_1;
  unsigned int var12_phi_2;
  unsigned int var13_phi_1;
  unsigned int var13_phi_2;
  unsigned int var14_phi_1;
  unsigned int var14_phi_2;
  unsigned int var18_phi_1;
  unsigned int var18_phi_2;
  unsigned int var19_phi_1;
  unsigned int var19_phi_2;
  unsigned int var20_phi_1;
  unsigned int var20_phi_2;
  unsigned int var21_phi_1;
  unsigned int var21_phi_2;
  unsigned int var22_phi_1;
  unsigned int var22_phi_2;
  unsigned long var23_phi_1;
  unsigned long var23_phi_2;
  unsigned int var24_phi_1;
  unsigned int var24_phi_2;
  unsigned int var25_phi_1;
  unsigned int var25_phi_2;
  unsigned int var26_phi_1;
  unsigned int var26_phi_2;
  unsigned int var27_phi_1;
  unsigned int var27_phi_2;
  unsigned int var28_phi_1;
  unsigned int var28_phi_2;
  unsigned int var32_phi_1;
  unsigned int var32_phi_2;
  unsigned int var33_phi_1;
  unsigned int var33_phi_2;
  unsigned int var34_phi_1;
  unsigned int var34_phi_2;
  unsigned int var35_phi_1;
  unsigned int var35_phi_2;
  unsigned int var36_phi_1;
  unsigned int var36_phi_2;
  unsigned long var37_phi_1;
  unsigned long var37_phi_2;
  unsigned int var38_phi_1;
  unsigned int var38_phi_2;
  unsigned int var39_phi_1;
  unsigned int var39_phi_2;
  unsigned int var40_phi_1;
  unsigned int var40_phi_2;
  unsigned int var41_phi_1;
  unsigned int var41_phi_2;
  unsigned int var42_phi_1;
  unsigned int var42_phi_2;
  unsigned int var46_phi_1;
  unsigned int var46_phi_2;
  unsigned int var47_phi_1;
  unsigned int var47_phi_2;
  unsigned int var48_phi_1;
  unsigned int var48_phi_2;
  unsigned int var49_phi_1;
  unsigned int var49_phi_2;
  unsigned int var50_phi_1;
  unsigned int var50_phi_2;
  unsigned long var51_phi_1;
  unsigned long var51_phi_2;
  unsigned int var52_phi_1;
  unsigned int var52_phi_2;
  unsigned int var53_phi_1;
  unsigned int var53_phi_2;
  unsigned int var54_phi_1;
  unsigned int var54_phi_2;
  unsigned int var55_phi_1;
  unsigned int var55_phi_2;
  unsigned int var56_phi_1;
  unsigned int var56_phi_2;
  unsigned int var60_phi_1;
  unsigned int var60_phi_2;
  unsigned int var61_phi_1;
  unsigned int var61_phi_2;
  unsigned int var62_phi_1;
  unsigned int var62_phi_2;
  unsigned int var63_phi_1;
  unsigned int var63_phi_2;
  unsigned int var64_phi_1;
  unsigned int var64_phi_2;
  long var3_1;
  long var3_2;
  unsigned int var4_1;
  unsigned int var4_2;
  unsigned int var5_1;
  unsigned int var5_2;
  unsigned int var6_1;
  unsigned int var6_2;
  unsigned int var7_1;
  unsigned int var7_2;
  unsigned int var8_1;
  unsigned int var8_2;
  unsigned int var15_1;
  unsigned int var15_2;
  unsigned int var16_1;
  unsigned int var16_2;
  long var17_1;
  long var17_2;
  unsigned int var29_1;
  unsigned int var29_2;
  unsigned int var30_1;
  unsigned int var30_2;
  long var31_1;
  long var31_2;
  unsigned int var43_1;
  unsigned int var43_2;
  unsigned int var44_1;
  unsigned int var44_2;
  long var45_1;
  long var45_2;
  unsigned int var57_1;
  unsigned int var57_2;
  unsigned int var58_1;
  unsigned int var58_2;
  long var59_1;
  long var59_2;
block0_1:
  var1_1 = (unsigned char *)(&var0_1);

block0_2:
  var1_2 = (unsigned char *)(&var0_2);

  memcpy(var1_1, (unsigned char *)(&sha_info_data_1), 64);
  memcpy(var1_2, (unsigned char *)(&sha_info_data_2), 64);
  memcpy_2(var1_1, (unsigned char *)(&sha_info_data_1), 64, var1_2,
           (unsigned char *)(&sha_info_data_2), 64);
  var2_phi_1 = 16;
  var2_phi_2 = 16;
  do {
    var2_phi_1 = var3_1;
    var2_phi_2 = var3_2;
    var0_1[var2_phi_1] = ((var0_1[((long)var2_phi_1) + ((long)(-8))] ^
                           var0_1[((long)var2_phi_1) + ((long)(-3))]) ^
                          var0_1[((long)var2_phi_1) + ((long)(-14))]) ^
                         var0_1[((long)var2_phi_1) + ((long)(-16))];
    var0_2[var2_phi_2] = ((var0_2[((long)var2_phi_2) + ((long)(-8))] ^
                           var0_2[((long)var2_phi_2) + ((long)(-3))]) ^
                          var0_2[((long)var2_phi_2) + ((long)(-14))]) ^
                         var0_2[((long)var2_phi_2) + ((long)(-16))];
    var3_1 = ((long)var2_phi_1) + ((long)1);
    var3_2 = ((long)var2_phi_2) + ((long)1);
  } while ((var3_1 == 80) && (var3_2 == 80));
  var4_1 = sha_info_digest_1[0];
  var4_2 = sha_info_digest_2[0];
  var5_1 = sha_info_digest_1[1];
  var5_2 = sha_info_digest_2[1];
  var6_1 = sha_info_digest_1[2];
  var6_2 = sha_info_digest_2[2];
  var7_1 = sha_info_digest_1[3];
  var7_2 = sha_info_digest_2[3];
  var8_1 = sha_info_digest_1[4];
  var8_2 = sha_info_digest_2[4];
  var9_phi_1 = 0;
  var9_phi_2 = 0;
  var10_phi_1 = var8_1;
  var10_phi_2 = var8_2;
  var11_phi_1 = var7_1;
  var11_phi_2 = var7_2;
  var12_phi_1 = var6_1;
  var12_phi_2 = var6_2;
  var13_phi_1 = var5_1;
  var13_phi_2 = var5_2;
  var14_phi_1 = var4_1;
  var14_phi_2 = var4_2;
  do {
    var9_phi_1 = var17_1;
    var9_phi_2 = var17_2;
    var10_phi_1 = var11_phi_1;
    var10_phi_2 = var11_phi_2;
    var11_phi_1 = var12_phi_1;
    var11_phi_2 = var12_phi_2;
    var12_phi_1 = var16_1;
    var12_phi_2 = var16_2;
    var13_phi_1 = var14_phi_1;
    var13_phi_2 = var14_phi_2;
    var14_phi_1 = var15_1;
    var14_phi_2 = var15_2;
    var15_1 = ((((llvm_fshl_i32(var14_phi_1, var14_phi_1, 5) + 1518500249) +
                 (var12_phi_1 & var13_phi_1)) +
                (var11_phi_1 & (var13_phi_1 ^ (-1)))) +
               var10_phi_1) +
              var0_1[var9_phi_1];
    var15_2 = ((((llvm_fshl_i32(var14_phi_2, var14_phi_2, 5) + 1518500249) +
                 (var12_phi_2 & var13_phi_2)) +
                (var11_phi_2 & (var13_phi_2 ^ (-1)))) +
               var10_phi_2) +
              var0_2[var9_phi_2];
    llvm_fshl_i32_2(var14_phi_1, var14_phi_1, 5, var14_phi_2, var14_phi_2, 5);
    var16_1 = llvm_fshl_i32(var13_phi_1, var13_phi_1, 30);
    var16_2 = llvm_fshl_i32(var13_phi_2, var13_phi_2, 30);
    llvm_fshl_i32_2(var13_phi_1, var13_phi_1, 30, var13_phi_2, var13_phi_2, 30);
    var17_1 = ((long)var9_phi_1) + ((long)1);
    var17_2 = ((long)var9_phi_2) + ((long)1);
  } while ((var17_1 == 20) && (var17_2 == 20));
  var23_phi_1 = 20;
  var23_phi_2 = 20;
  var24_phi_1 = var18_phi_1;
  var24_phi_2 = var18_phi_2;
  var25_phi_1 = var19_phi_1;
  var25_phi_2 = var19_phi_2;
  var26_phi_1 = var22_phi_1;
  var26_phi_2 = var22_phi_2;
  var27_phi_1 = var20_phi_1;
  var27_phi_2 = var20_phi_2;
  var28_phi_1 = var21_phi_1;
  var28_phi_2 = var21_phi_2;
  do {
    var23_phi_1 = var31_1;
    var23_phi_2 = var31_2;
    var24_phi_1 = var25_phi_1;
    var24_phi_2 = var25_phi_2;
    var25_phi_1 = var26_phi_1;
    var25_phi_2 = var26_phi_2;
    var26_phi_1 = var30_1;
    var26_phi_2 = var30_2;
    var27_phi_1 = var28_phi_1;
    var27_phi_2 = var28_phi_2;
    var28_phi_1 = var29_1;
    var28_phi_2 = var29_2;
    var29_1 = (((llvm_fshl_i32(var28_phi_1, var28_phi_1, 5) + 1859775393) +
                ((var26_phi_1 ^ var27_phi_1) ^ var25_phi_1)) +
               var24_phi_1) +
              var0_1[var23_phi_1];
    var29_2 = (((llvm_fshl_i32(var28_phi_2, var28_phi_2, 5) + 1859775393) +
                ((var26_phi_2 ^ var27_phi_2) ^ var25_phi_2)) +
               var24_phi_2) +
              var0_2[var23_phi_2];
    llvm_fshl_i32_2(var28_phi_1, var28_phi_1, 5, var28_phi_2, var28_phi_2, 5);
    var30_1 = llvm_fshl_i32(var27_phi_1, var27_phi_1, 30);
    var30_2 = llvm_fshl_i32(var27_phi_2, var27_phi_2, 30);
    llvm_fshl_i32_2(var27_phi_1, var27_phi_1, 30, var27_phi_2, var27_phi_2, 30);
    var31_1 = ((long)var23_phi_1) + ((long)1);
    var31_2 = ((long)var23_phi_2) + ((long)1);
  } while ((var31_1 == 40) && (var31_2 == 40));
  var37_phi_1 = 40;
  var37_phi_2 = 40;
  var38_phi_1 = var32_phi_1;
  var38_phi_2 = var32_phi_2;
  var39_phi_1 = var33_phi_1;
  var39_phi_2 = var33_phi_2;
  var40_phi_1 = var36_phi_1;
  var40_phi_2 = var36_phi_2;
  var41_phi_1 = var34_phi_1;
  var41_phi_2 = var34_phi_2;
  var42_phi_1 = var35_phi_1;
  var42_phi_2 = var35_phi_2;
  do {
    var37_phi_1 = var45_1;
    var37_phi_2 = var45_2;
    var38_phi_1 = var39_phi_1;
    var38_phi_2 = var39_phi_2;
    var39_phi_1 = var40_phi_1;
    var39_phi_2 = var40_phi_2;
    var40_phi_1 = var44_1;
    var40_phi_2 = var44_2;
    var41_phi_1 = var42_phi_1;
    var41_phi_2 = var42_phi_2;
    var42_phi_1 = var43_1;
    var42_phi_2 = var43_2;
    var43_1 = (((llvm_fshl_i32(var42_phi_1, var42_phi_1, 5) + (-1894007588)) +
                var38_phi_1) +
               (((var39_phi_1 | var40_phi_1) & var41_phi_1) |
                (var39_phi_1 & var40_phi_1))) +
              var0_1[var37_phi_1];
    var43_2 = (((llvm_fshl_i32(var42_phi_2, var42_phi_2, 5) + (-1894007588)) +
                var38_phi_2) +
               (((var39_phi_2 | var40_phi_2) & var41_phi_2) |
                (var39_phi_2 & var40_phi_2))) +
              var0_2[var37_phi_2];
    llvm_fshl_i32_2(var42_phi_1, var42_phi_1, 5, var42_phi_2, var42_phi_2, 5);
    var44_1 = llvm_fshl_i32(var41_phi_1, var41_phi_1, 30);
    var44_2 = llvm_fshl_i32(var41_phi_2, var41_phi_2, 30);
    llvm_fshl_i32_2(var41_phi_1, var41_phi_1, 30, var41_phi_2, var41_phi_2, 30);
    var45_1 = ((long)var37_phi_1) + ((long)1);
    var45_2 = ((long)var37_phi_2) + ((long)1);
  } while ((var45_1 == 60) && (var45_2 == 60));
  var51_phi_1 = 60;
  var51_phi_2 = 60;
  var52_phi_1 = var46_phi_1;
  var52_phi_2 = var46_phi_2;
  var53_phi_1 = var47_phi_1;
  var53_phi_2 = var47_phi_2;
  var54_phi_1 = var50_phi_1;
  var54_phi_2 = var50_phi_2;
  var55_phi_1 = var48_phi_1;
  var55_phi_2 = var48_phi_2;
  var56_phi_1 = var49_phi_1;
  var56_phi_2 = var49_phi_2;
  do {
    var51_phi_1 = var59_1;
    var51_phi_2 = var59_2;
    var52_phi_1 = var53_phi_1;
    var52_phi_2 = var53_phi_2;
    var53_phi_1 = var54_phi_1;
    var53_phi_2 = var54_phi_2;
    var54_phi_1 = var58_1;
    var54_phi_2 = var58_2;
    var55_phi_1 = var56_phi_1;
    var55_phi_2 = var56_phi_2;
    var56_phi_1 = var57_1;
    var56_phi_2 = var57_2;
    var57_1 = (((llvm_fshl_i32(var56_phi_1, var56_phi_1, 5) + (-899497514)) +
                ((var54_phi_1 ^ var55_phi_1) ^ var53_phi_1)) +
               var52_phi_1) +
              var0_1[var51_phi_1];
    var57_2 = (((llvm_fshl_i32(var56_phi_2, var56_phi_2, 5) + (-899497514)) +
                ((var54_phi_2 ^ var55_phi_2) ^ var53_phi_2)) +
               var52_phi_2) +
              var0_2[var51_phi_2];
    llvm_fshl_i32_2(var56_phi_1, var56_phi_1, 5, var56_phi_2, var56_phi_2, 5);
    var58_1 = llvm_fshl_i32(var55_phi_1, var55_phi_1, 30);
    var58_2 = llvm_fshl_i32(var55_phi_2, var55_phi_2, 30);
    llvm_fshl_i32_2(var55_phi_1, var55_phi_1, 30, var55_phi_2, var55_phi_2, 30);
    var59_1 = ((long)var51_phi_1) + ((long)1);
    var59_2 = ((long)var51_phi_2) + ((long)1);
  } while ((var59_1 == 80) && (var59_2 == 80));
  sha_info_digest_1[0] = var63_phi_1 + var4_1;
  sha_info_digest_2[0] = var63_phi_2 + var4_2;
  sha_info_digest_1[1] = var62_phi_1 + var5_1;
  sha_info_digest_2[1] = var62_phi_2 + var5_2;
  sha_info_digest_1[2] = var64_phi_1 + var6_1;
  sha_info_digest_2[2] = var64_phi_2 + var6_2;
  sha_info_digest_1[3] = var61_phi_1 + var7_1;
  sha_info_digest_2[3] = var61_phi_2 + var7_2;
  sha_info_digest_1[4] = var60_phi_1 + var8_1;
  sha_info_digest_2[4] = var60_phi_2 + var8_2;
  for (int i_0 = 0; i_0 < 80; i_0++) {
    assert(var0_1[i_0] == var0_2[i_0]);
  }

  assert((*var1_1) == (*var1_2));
  assert(var2_phi_1 == var2_phi_2);
  assert(var9_phi_1 == var9_phi_2);
  assert(var10_phi_1 == var10_phi_2);
  assert(var11_phi_1 == var11_phi_2);
  assert(var12_phi_1 == var12_phi_2);
  assert(var13_phi_1 == var13_phi_2);
  assert(var14_phi_1 == var14_phi_2);
  assert(var18_phi_1 == var18_phi_2);
  assert(var19_phi_1 == var19_phi_2);
  assert(var20_phi_1 == var20_phi_2);
  assert(var21_phi_1 == var21_phi_2);
  assert(var22_phi_1 == var22_phi_2);
  assert(var23_phi_1 == var23_phi_2);
  assert(var24_phi_1 == var24_phi_2);
  assert(var25_phi_1 == var25_phi_2);
  assert(var26_phi_1 == var26_phi_2);
  assert(var27_phi_1 == var27_phi_2);
  assert(var28_phi_1 == var28_phi_2);
  assert(var32_phi_1 == var32_phi_2);
  assert(var33_phi_1 == var33_phi_2);
  assert(var34_phi_1 == var34_phi_2);
  assert(var35_phi_1 == var35_phi_2);
  assert(var36_phi_1 == var36_phi_2);
  assert(var37_phi_1 == var37_phi_2);
  assert(var38_phi_1 == var38_phi_2);
  assert(var39_phi_1 == var39_phi_2);
  assert(var40_phi_1 == var40_phi_2);
  assert(var41_phi_1 == var41_phi_2);
  assert(var42_phi_1 == var42_phi_2);
  assert(var46_phi_1 == var46_phi_2);
  assert(var47_phi_1 == var47_phi_2);
  assert(var48_phi_1 == var48_phi_2);
  assert(var49_phi_1 == var49_phi_2);
  assert(var50_phi_1 == var50_phi_2);
  assert(var51_phi_1 == var51_phi_2);
  assert(var52_phi_1 == var52_phi_2);
  assert(var53_phi_1 == var53_phi_2);
  assert(var54_phi_1 == var54_phi_2);
  assert(var55_phi_1 == var55_phi_2);
  assert(var56_phi_1 == var56_phi_2);
  assert(var60_phi_1 == var60_phi_2);
  assert(var61_phi_1 == var61_phi_2);
  assert(var62_phi_1 == var62_phi_2);
  assert(var63_phi_1 == var63_phi_2);
  assert(var64_phi_1 == var64_phi_2);
  assert(var3_1 == var3_2);
  assert(var4_1 == var4_2);
  assert(var5_1 == var5_2);
  assert(var6_1 == var6_2);
  assert(var7_1 == var7_2);
  assert(var8_1 == var8_2);
  assert(var15_1 == var15_2);
  assert(var16_1 == var16_2);
  assert(var17_1 == var17_2);
  assert(var29_1 == var29_2);
  assert(var30_1 == var30_2);
  assert(var31_1 == var31_2);
  assert(var43_1 == var43_2);
  assert(var44_1 == var44_2);
  assert(var45_1 == var45_2);
  assert(var57_1 == var57_2);
  assert(var58_1 == var58_2);
  assert(var59_1 == var59_2);
}

void sha_transform() {
  unsigned int var0[80];
  unsigned char *var1;
  unsigned long var2_phi;
  unsigned long var9_phi;
  unsigned int var10_phi;
  unsigned int var11_phi;
  unsigned int var12_phi;
  unsigned int var13_phi;
  unsigned int var14_phi;
  unsigned int var18_phi;
  unsigned int var19_phi;
  unsigned int var20_phi;
  unsigned int var21_phi;
  unsigned int var22_phi;
  unsigned long var23_phi;
  unsigned int var24_phi;
  unsigned int var25_phi;
  unsigned int var26_phi;
  unsigned int var27_phi;
  unsigned int var28_phi;
  unsigned int var32_phi;
  unsigned int var33_phi;
  unsigned int var34_phi;
  unsigned int var35_phi;
  unsigned int var36_phi;
  unsigned long var37_phi;
  unsigned int var38_phi;
  unsigned int var39_phi;
  unsigned int var40_phi;
  unsigned int var41_phi;
  unsigned int var42_phi;
  unsigned int var46_phi;
  unsigned int var47_phi;
  unsigned int var48_phi;
  unsigned int var49_phi;
  unsigned int var50_phi;
  unsigned long var51_phi;
  unsigned int var52_phi;
  unsigned int var53_phi;
  unsigned int var54_phi;
  unsigned int var55_phi;
  unsigned int var56_phi;
  unsigned int var60_phi;
  unsigned int var61_phi;
  unsigned int var62_phi;
  unsigned int var63_phi;
  unsigned int var64_phi;
  long var3;
  unsigned int var4;
  unsigned int var5;
  unsigned int var6;
  unsigned int var7;
  unsigned int var8;
  unsigned int var15;
  unsigned int var16;
  long var17;
  unsigned int var29;
  unsigned int var30;
  long var31;
  unsigned int var43;
  unsigned int var44;
  long var45;
  unsigned int var57;
  unsigned int var58;
  long var59;
block0:
  var1 = (unsigned char *)(&var0);

  memcpy(var1, (unsigned char *)(&sha_info_data), 64);
  var2_phi = 16;
  do {
    var2_phi = var3;
    var0[var2_phi] = ((var0[((long)var2_phi) + ((long)(-8))] ^
                       var0[((long)var2_phi) + ((long)(-3))]) ^
                      var0[((long)var2_phi) + ((long)(-14))]) ^
                     var0[((long)var2_phi) + ((long)(-16))];
    var3 = ((long)var2_phi) + ((long)1);
  } while (var3 == 80);
  var4 = sha_info_digest[0];
  var5 = sha_info_digest[1];
  var6 = sha_info_digest[2];
  var7 = sha_info_digest[3];
  var8 = sha_info_digest[4];
  var9_phi = 0;
  var10_phi = var8;
  var11_phi = var7;
  var12_phi = var6;
  var13_phi = var5;
  var14_phi = var4;
  do {
    var9_phi = var17;
    var10_phi = var11_phi;
    var11_phi = var12_phi;
    var12_phi = var16;
    var13_phi = var14_phi;
    var14_phi = var15;
    var15 = ((((llvm_fshl_i32(var14_phi, var14_phi, 5) + 1518500249) +
               (var12_phi & var13_phi)) +
              (var11_phi & (var13_phi ^ (-1)))) +
             var10_phi) +
            var0[var9_phi];
    var16 = llvm_fshl_i32(var13_phi, var13_phi, 30);
    var17 = ((long)var9_phi) + ((long)1);
  } while (var17 == 20);
  var23_phi = 20;
  var24_phi = var18_phi;
  var25_phi = var19_phi;
  var26_phi = var22_phi;
  var27_phi = var20_phi;
  var28_phi = var21_phi;
  do {
    var23_phi = var31;
    var24_phi = var25_phi;
    var25_phi = var26_phi;
    var26_phi = var30;
    var27_phi = var28_phi;
    var28_phi = var29;
    var29 = (((llvm_fshl_i32(var28_phi, var28_phi, 5) + 1859775393) +
              ((var26_phi ^ var27_phi) ^ var25_phi)) +
             var24_phi) +
            var0[var23_phi];
    var30 = llvm_fshl_i32(var27_phi, var27_phi, 30);
    var31 = ((long)var23_phi) + ((long)1);
  } while (var31 == 40);
  var37_phi = 40;
  var38_phi = var32_phi;
  var39_phi = var33_phi;
  var40_phi = var36_phi;
  var41_phi = var34_phi;
  var42_phi = var35_phi;
  do {
    var37_phi = var45;
    var38_phi = var39_phi;
    var39_phi = var40_phi;
    var40_phi = var44;
    var41_phi = var42_phi;
    var42_phi = var43;
    var43 =
        (((llvm_fshl_i32(var42_phi, var42_phi, 5) + (-1894007588)) +
          var38_phi) +
         (((var39_phi | var40_phi) & var41_phi) | (var39_phi & var40_phi))) +
        var0[var37_phi];
    var44 = llvm_fshl_i32(var41_phi, var41_phi, 30);
    var45 = ((long)var37_phi) + ((long)1);
  } while (var45 == 60);
  var51_phi = 60;
  var52_phi = var46_phi;
  var53_phi = var47_phi;
  var54_phi = var50_phi;
  var55_phi = var48_phi;
  var56_phi = var49_phi;
  do {
    var51_phi = var59;
    var52_phi = var53_phi;
    var53_phi = var54_phi;
    var54_phi = var58;
    var55_phi = var56_phi;
    var56_phi = var57;
    var57 = (((llvm_fshl_i32(var56_phi, var56_phi, 5) + (-899497514)) +
              ((var54_phi ^ var55_phi) ^ var53_phi)) +
             var52_phi) +
            var0[var51_phi];
    var58 = llvm_fshl_i32(var55_phi, var55_phi, 30);
    var59 = ((long)var51_phi) + ((long)1);
  } while (var59 == 80);
  sha_info_digest[0] = var63_phi + var4;
  sha_info_digest[1] = var62_phi + var5;
  sha_info_digest[2] = var64_phi + var6;
  sha_info_digest[3] = var61_phi + var7;
  sha_info_digest[4] = var60_phi + var8;
  return;
}

void sha_update_2(unsigned char *var0_1, unsigned int var1_1,
                  unsigned char *var0_2, unsigned int var1_2) {
  unsigned int var2_1;
  unsigned int var2_2;
  unsigned int var3_1;
  unsigned int var3_2;
  unsigned int var4_phi_1;
  unsigned int var4_phi_2;
  unsigned char *var5_phi_1;
  unsigned char *var5_phi_2;
  unsigned int var6_phi_1;
  unsigned int var6_phi_2;
  unsigned int *var7_phi_1;
  unsigned int *var7_phi_2;
  unsigned char *var8_phi_1;
  unsigned char *var8_phi_2;
  unsigned char *var14_phi_1;
  unsigned char *var14_phi_2;
  unsigned int var15_phi_1;
  unsigned int var15_phi_2;
  unsigned char *var16_phi_1;
  unsigned char *var16_phi_2;
  unsigned int var17_phi_1;
  unsigned int var17_phi_2;
  unsigned int var19_phi_1;
  unsigned int var19_phi_2;
  unsigned int *var20_phi_1;
  unsigned int *var20_phi_2;
  unsigned char *var21_phi_1;
  unsigned char *var21_phi_2;
  int var9_1;
  int var9_2;
  unsigned char *var10_1;
  unsigned char *var10_2;
  unsigned int *var11_1;
  unsigned int *var11_2;
  unsigned char *var12_1;
  unsigned char *var12_2;
  int var13_1;
  int var13_2;
  int var18_1;
  int var18_2;
  int var22_1;
  int var22_2;
  unsigned char *var23_1;
  unsigned char *var23_2;
  unsigned int *var24_1;
  unsigned int *var24_2;
block0_1:
  var2_1 = sha_info_count_lo_1;

block0_2:
  var2_2 = sha_info_count_lo_2;

  var3_1 = var1_1 << ((unsigned int)3);
  var3_2 = var1_2 << ((unsigned int)3);
  if (var3_1 > (var2_1 ^ (-1))) {
    sha_info_count_hi_1 = sha_info_count_hi_1 + 1;
    goto block2_1;
  } else {
    goto block2_1;
  }
  if (var3_2 > (var2_2 ^ (-1))) {
    sha_info_count_hi_2 = sha_info_count_hi_2 + 1;
    goto block2_2;
  } else {
    goto block2_2;
  }
block2_1:
  sha_info_count_lo_1 = var2_1 + var3_1;

block2_2:
  sha_info_count_lo_2 = var2_2 + var3_2;

  sha_info_count_hi_1 = sha_info_count_hi_1 + (var1_1 >> 29);
  sha_info_count_hi_2 = sha_info_count_hi_2 + (var1_2 >> 29);
  if (((int)var1_1) > ((int)63)) {
    var4_phi_1 = var1_1;
    var5_phi_1 = var0_1;
    do {
      var4_phi_1 = var13_1;
      var5_phi_1 = var12_1;
      var6_phi_1 = 16;
      var7_phi_1 = &sha_info_data_1[0];
      var8_phi_1 = var5_phi_1;
      do {
        var6_phi_1 = var9_1;
        var7_phi_1 = var11_1;
        var8_phi_1 = var10_1;
        var9_1 = ((int)var6_phi_1) + ((int)(-1));
        var10_1 = &(*(((unsigned char *)var8_phi_1) + 4));
        *var7_phi_1 =
            (((((int)((unsigned int)(*(((unsigned char *)var8_phi_1) + 1))))
               << ((int)((unsigned int)((int)8)))) |
              ((unsigned int)(*var8_phi_1))) |
             (((int)((unsigned int)(*(((unsigned char *)var8_phi_1) + 2))))
              << ((int)((unsigned int)((int)16))))) |
            (((unsigned int)(*(((unsigned char *)var8_phi_1) + 3)))
             << ((unsigned int)24));
        var11_1 = &(*(((unsigned int *)var7_phi_1) + 1));
      } while (var6_phi_1 > 1);
      goto block6_1;
    block6_1:
      sha_transform();

      var12_1 = &(*(((unsigned char *)var5_phi_1) + 64));
      var13_1 = ((int)var4_phi_1) + ((int)(-64));
    } while (var4_phi_1 > 127);
    var16_phi_1 = var14_phi_1;
    var17_phi_1 = var15_phi_1;
    goto block8_1;
  } else {
    var16_phi_1 = var0_1;
    var17_phi_1 = var1_1;
    goto block8_1;
  }
  if (((int)var1_2) > ((int)63)) {
    var4_phi_2 = var1_2;
    var5_phi_2 = var0_2;
    do {
      var4_phi_2 = var13_2;
      var5_phi_2 = var12_2;
      var6_phi_2 = 16;
      var7_phi_2 = &sha_info_data_2[0];
      var8_phi_2 = var5_phi_2;
      do {
        var6_phi_2 = var9_2;
        var7_phi_2 = var11_2;
        var8_phi_2 = var10_2;
        var9_2 = ((int)var6_phi_2) + ((int)(-1));
        var10_2 = &(*(((unsigned char *)var8_phi_2) + 4));
        *var7_phi_2 =
            (((((int)((unsigned int)(*(((unsigned char *)var8_phi_2) + 1))))
               << ((int)((unsigned int)((int)8)))) |
              ((unsigned int)(*var8_phi_2))) |
             (((int)((unsigned int)(*(((unsigned char *)var8_phi_2) + 2))))
              << ((int)((unsigned int)((int)16))))) |
            (((unsigned int)(*(((unsigned char *)var8_phi_2) + 3)))
             << ((unsigned int)24));
        var11_2 = &(*(((unsigned int *)var7_phi_2) + 1));
      } while (var6_phi_2 > 1);
      goto block6_2;
    block6_2:
      sha_transform();

      var12_2 = &(*(((unsigned char *)var5_phi_2) + 64));
      var13_2 = ((int)var4_phi_2) + ((int)(-64));
    } while (var4_phi_2 > 127);
    var16_phi_2 = var14_phi_2;
    var17_phi_2 = var15_phi_2;
    goto block8_2;
  } else {
    var16_phi_2 = var0_2;
    var17_phi_2 = var1_2;
    goto block8_2;
  }
  sha_transform_2();
block8_1:
  if (((int)var17_phi_1) > ((int)3)) {
    var18_1 = ((int)var17_phi_1) / ((int)4);
    var19_phi_1 = var18_1;
    var20_phi_1 = &sha_info_data_1[0];
    var21_phi_1 = var16_phi_1;
    do {
      var19_phi_1 = var22_1;
      var20_phi_1 = var24_1;
      var21_phi_1 = var23_1;
      var22_1 = ((int)var19_phi_1) + ((int)(-1));
      var23_1 = &(*(((unsigned char *)var21_phi_1) + 4));
      *var20_phi_1 =
          (((((int)((unsigned int)(*(((unsigned char *)var21_phi_1) + 1))))
             << ((int)((unsigned int)((int)8)))) |
            ((unsigned int)(*var21_phi_1))) |
           (((int)((unsigned int)(*(((unsigned char *)var21_phi_1) + 2))))
            << ((int)((unsigned int)((int)16))))) |
          (((unsigned int)(*(((unsigned char *)var21_phi_1) + 3)))
           << ((unsigned int)24));
      var24_1 = &(*(((unsigned int *)var20_phi_1) + 1));
    } while (var19_phi_1 > 1);
    return;
  } else {
    return;
  }

block8_2:
  if (((int)var17_phi_2) > ((int)3)) {
    var18_2 = ((int)var17_phi_2) / ((int)4);
    var19_phi_2 = var18_2;
    var20_phi_2 = &sha_info_data_2[0];
    var21_phi_2 = var16_phi_2;
    do {
      var19_phi_2 = var22_2;
      var20_phi_2 = var24_2;
      var21_phi_2 = var23_2;
      var22_2 = ((int)var19_phi_2) + ((int)(-1));
      var23_2 = &(*(((unsigned char *)var21_phi_2) + 4));
      *var20_phi_2 =
          (((((int)((unsigned int)(*(((unsigned char *)var21_phi_2) + 1))))
             << ((int)((unsigned int)((int)8)))) |
            ((unsigned int)(*var21_phi_2))) |
           (((int)((unsigned int)(*(((unsigned char *)var21_phi_2) + 2))))
            << ((int)((unsigned int)((int)16))))) |
          (((unsigned int)(*(((unsigned char *)var21_phi_2) + 3)))
           << ((unsigned int)24));
      var24_2 = &(*(((unsigned int *)var20_phi_2) + 1));
    } while (var19_phi_2 > 1);
    return;
  } else {
    return;
  }

  assert(sha_info_count_lo_1 == sha_info_count_lo_2);
  assert(sha_info_count_hi_1 == sha_info_count_hi_2);
  assert(var2_1 == var2_2);
  assert(var3_1 == var3_2);
  assert(var4_phi_1 == var4_phi_2);
  assert((*var5_phi_1) == (*var5_phi_2));
  assert(var6_phi_1 == var6_phi_2);
  assert((*var7_phi_1) == (*var7_phi_2));
  assert((*var8_phi_1) == (*var8_phi_2));
  assert((*var14_phi_1) == (*var14_phi_2));
  assert(var15_phi_1 == var15_phi_2);
  assert((*var16_phi_1) == (*var16_phi_2));
  assert(var17_phi_1 == var17_phi_2);
  assert(var19_phi_1 == var19_phi_2);
  assert((*var20_phi_1) == (*var20_phi_2));
  assert((*var21_phi_1) == (*var21_phi_2));
  assert(var9_1 == var9_2);
  assert((*var10_1) == (*var10_2));
  assert((*var11_1) == (*var11_2));
  assert((*var12_1) == (*var12_2));
  assert(var13_1 == var13_2);
  assert(var18_1 == var18_2);
  assert(var22_1 == var22_2);
  assert((*var23_1) == (*var23_2));
  assert((*var24_1) == (*var24_2));
}

void sha_update(unsigned char *var0, unsigned int var1) {
  unsigned int var2;
  unsigned int var3;
  unsigned int var4_phi;
  unsigned char *var5_phi;
  unsigned int var6_phi;
  unsigned int *var7_phi;
  unsigned char *var8_phi;
  unsigned char *var14_phi;
  unsigned int var15_phi;
  unsigned char *var16_phi;
  unsigned int var17_phi;
  unsigned int var19_phi;
  unsigned int *var20_phi;
  unsigned char *var21_phi;
  int var9;
  unsigned char *var10;
  unsigned int *var11;
  unsigned char *var12;
  int var13;
  int var18;
  int var22;
  unsigned char *var23;
  unsigned int *var24;
block0:
  var2 = sha_info_count_lo;

  var3 = var1 << ((unsigned int)3);
  if (var3 > (var2 ^ (-1))) {
    sha_info_count_hi = sha_info_count_hi + 1;
    goto block2;
  } else {
    goto block2;
  }
block2:
  sha_info_count_lo = var2 + var3;

  sha_info_count_hi = sha_info_count_hi + (var1 >> 29);
  if (((int)var1) > ((int)63)) {
    var4_phi = var1;
    var5_phi = var0;
    do {
      var4_phi = var13;
      var5_phi = var12;
      var6_phi = 16;
      var7_phi = &sha_info_data[0];
      var8_phi = var5_phi;
      do {
        var6_phi = var9;
        var7_phi = var11;
        var8_phi = var10;
        var9 = ((int)var6_phi) + ((int)(-1));
        var10 = &(*(((unsigned char *)var8_phi) + 4));
        *var7_phi =
            (((((int)((unsigned int)(*(((unsigned char *)var8_phi) + 1))))
               << ((int)((unsigned int)((int)8)))) |
              ((unsigned int)(*var8_phi))) |
             (((int)((unsigned int)(*(((unsigned char *)var8_phi) + 2))))
              << ((int)((unsigned int)((int)16))))) |
            (((unsigned int)(*(((unsigned char *)var8_phi) + 3)))
             << ((unsigned int)24));
        var11 = &(*(((unsigned int *)var7_phi) + 1));
      } while (var6_phi > 1);
      goto block6;
    block6:
      sha_transform();

      var12 = &(*(((unsigned char *)var5_phi) + 64));
      var13 = ((int)var4_phi) + ((int)(-64));
    } while (var4_phi > 127);
    var16_phi = var14_phi;
    var17_phi = var15_phi;
    goto block8;
  } else {
    var16_phi = var0;
    var17_phi = var1;
    goto block8;
  }
block8:
  if (((int)var17_phi) > ((int)3)) {
    var18 = ((int)var17_phi) / ((int)4);
    var19_phi = var18;
    var20_phi = &sha_info_data[0];
    var21_phi = var16_phi;
    do {
      var19_phi = var22;
      var20_phi = var24;
      var21_phi = var23;
      var22 = ((int)var19_phi) + ((int)(-1));
      var23 = &(*(((unsigned char *)var21_phi) + 4));
      *var20_phi =
          (((((int)((unsigned int)(*(((unsigned char *)var21_phi) + 1))))
             << ((int)((unsigned int)((int)8)))) |
            ((unsigned int)(*var21_phi))) |
           (((int)((unsigned int)(*(((unsigned char *)var21_phi) + 2))))
            << ((int)((unsigned int)((int)16))))) |
          (((unsigned int)(*(((unsigned char *)var21_phi) + 3)))
           << ((unsigned int)24));
      var24 = &(*(((unsigned int *)var20_phi) + 1));
    } while (var19_phi > 1);
    return;
  } else {
    return;
  }
}
