unsigned int llvm_fshl_i32(unsigned int var0, unsigned int var1,
                           unsigned int var2);
void llvm_lifetime_end_p0i8(unsigned long var0, unsigned char *var1);
void llvm_lifetime_start_p0i8(unsigned long var0, unsigned char *var1);
unsigned int llvm_smin_i32(unsigned int var0, unsigned int var1);
void local_memcpy(unsigned int *var0, unsigned char *var1, unsigned int var2);
void local_memset(unsigned int *var0, unsigned int var1, unsigned int var2,
                  unsigned int var3);
int main();
unsigned int printf(unsigned char *var0, ...);
void sha_final();
void sha_init();
void sha_stream();
void sha_transform();
void sha_update(unsigned char *var0, unsigned int var1);

// global variable definitions
unsigned char indata[2][8192];
unsigned int in_i[2];
unsigned int sha_info_digest[5];
unsigned int sha_info_count_lo = 0;
unsigned int sha_info_count_hi = 0;
unsigned int sha_info_data[16];
unsigned int outData[5];
unsigned char _str[4];

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
    var3 = (((int)var2) / ((int)4));
    var4_phi = var3;
    var5_phi = var0;
    var6_phi = var1;
    do {
      var4_phi = var7;
      var5_phi = var9;
      var6_phi = var8;
      var7 = (((int)var4_phi) + ((int)-1));
      var8 = (&(*(((unsigned char *)(var6_phi)) + 4)));
      (*var5_phi) =
          ((((((int)((unsigned int)(*(((unsigned char *)(var6_phi)) + 1))))
              << ((int)((unsigned int)((int)8)))) |
             ((unsigned int)(*var6_phi))) |
            (((int)((unsigned int)(*(((unsigned char *)(var6_phi)) + 2))))
             << ((int)((unsigned int)((int)16))))) |
           (((unsigned int)(*(((unsigned char *)(var6_phi)) + 3)))
            << ((unsigned int)24)));
      var9 = (&(*(((unsigned int *)(var5_phi)) + 1)));
    } while (var4_phi > 1);
    return;
  } else {
    return;
  }
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
    var4 = (&(*(((unsigned int *)(var0)) +
                ((((int)var3) > ((int)0))
                     ? (((long)((unsigned long)(var3 + -1))) + ((long)1))
                     : 0))));
    var5 = (((int)var2) / ((int)4));
    var6_phi = var5;
    var7_phi = var4;
    do {
      var6_phi = var8;
      var7_phi = var9;
      var8 = (((int)var6_phi) + ((int)-1));
      var9 = (&(*(((unsigned int *)(var7_phi)) + 1)));
      (*var7_phi) = var1;
    } while (var6_phi > 1);
    return;
  } else {
    return;
  }
}

int main() {
  unsigned long var0_phi;
  unsigned int var1_phi;
  unsigned int var4_phi;
  int var2;
  long var3;
block0:
  sha_stream();
  var0_phi = 0;
  var1_phi = 0;
  do {
    var0_phi = var3;
    var1_phi = var2;
    var2 =
        (((int)var1_phi) + ((int)((unsigned int)((sha_info_digest[var0_phi]) !=
                                                 (outData[var0_phi])))));
    var3 = (((long)var0_phi) + ((long)1));
  } while (var3 == 5);
  printf(&(_str[0]), var4_phi);
  return var4_phi;
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
  var2 = (((var0) >> (3)) & 63);
  var3 = ((unsigned long)var2);
  (sha_info_data[var3]) = 128;
  if (var2 > 55) {
    var4 = (var2 ^ 63);
    var5 = ((var4) >> (2));
    if (var4 > 3) {
      var6 = ((unsigned char *)(&(sha_info_data[((long)var3) + ((long)1)])));
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
    var7 = (((int)(((int)55) - ((int)var2))) / ((int)4));
    if (var2 < 52) {
      var8 = ((unsigned char *)(&(sha_info_data[((long)var3) + ((long)1)])));
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
  (sha_info_data[14]) = var1;
  (sha_info_data[15]) = var0;
  sha_transform();
  return;
}

void sha_init() {
block0:
  (sha_info_digest[0]) = 1732584193;
  (sha_info_digest[1]) = -271733879;
  (sha_info_digest[2]) = -1732584194;
  (sha_info_digest[3]) = 271733878;
  (sha_info_digest[4]) = -1009589776;
  sha_info_count_lo = 0;
  sha_info_count_hi = 0;
  return;
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
  (sha_info_digest[0]) = 1732584193;
  (sha_info_digest[1]) = -271733879;
  (sha_info_digest[2]) = -1732584194;
  (sha_info_digest[3]) = 271733878;
  (sha_info_digest[4]) = -1009589776;
  sha_info_count_lo = 0;
  sha_info_count_hi = 0;
  var0_phi = 0;
  do {
    var0_phi = var1;
    sha_update(&((indata[var0_phi])[0]), in_i[var0_phi]);
    var1 = (((long)var0_phi) + ((long)1));
  } while (var0_phi == 0);
  var2 = sha_info_count_lo;
  var3 = sha_info_count_hi;
  var4 = (((var2) >> (3)) & 63);
  var5 = ((unsigned long)var4);
  (sha_info_data[var5]) = 128;
  if (var4 > 55) {
    var6 = (var4 ^ 63);
    var7 = ((var6) >> (2));
    if (var6 > 3) {
      var8 = ((unsigned char *)(&(sha_info_data[((long)var5) + ((long)1)])));
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
    var9 = (((int)(((int)55) - ((int)var4))) / ((int)4));
    if (var4 < 52) {
      var10 = ((unsigned char *)(&(sha_info_data[((long)var5) + ((long)1)])));
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
  (sha_info_data[14]) = var3;
  (sha_info_data[15]) = var2;
  sha_transform();
  return;
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
  var1 = ((unsigned char *)(&var0));
  memcpy(var1, (unsigned char *)(&sha_info_data), 64);
  var2_phi = 16;
  do {
    var2_phi = var3;
    (var0[var2_phi]) = ((((var0[((long)var2_phi) + ((long)-8)]) ^
                          (var0[((long)var2_phi) + ((long)-3)])) ^
                         (var0[((long)var2_phi) + ((long)-14)])) ^
                        (var0[((long)var2_phi) + ((long)-16)]));
    var3 = (((long)var2_phi) + ((long)1));
  } while (var3 == 80);
  var4 = (sha_info_digest[0]);
  var5 = (sha_info_digest[1]);
  var6 = (sha_info_digest[2]);
  var7 = (sha_info_digest[3]);
  var8 = (sha_info_digest[4]);
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
    var15 = (((((llvm_fshl_i32(var14_phi, var14_phi, 5) + 1518500249) +
                (var12_phi & var13_phi)) +
               (var11_phi & (var13_phi ^ -1))) +
              var10_phi) +
             (var0[var9_phi]));
    var16 = llvm_fshl_i32(var13_phi, var13_phi, 30);
    var17 = (((long)var9_phi) + ((long)1));
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
    var29 = ((((llvm_fshl_i32(var28_phi, var28_phi, 5) + 1859775393) +
               ((var26_phi ^ var27_phi) ^ var25_phi)) +
              var24_phi) +
             (var0[var23_phi]));
    var30 = llvm_fshl_i32(var27_phi, var27_phi, 30);
    var31 = (((long)var23_phi) + ((long)1));
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
        ((((llvm_fshl_i32(var42_phi, var42_phi, 5) + -1894007588) + var38_phi) +
          (((var39_phi | var40_phi) & var41_phi) | (var39_phi & var40_phi))) +
         (var0[var37_phi]));
    var44 = llvm_fshl_i32(var41_phi, var41_phi, 30);
    var45 = (((long)var37_phi) + ((long)1));
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
    var57 = ((((llvm_fshl_i32(var56_phi, var56_phi, 5) + -899497514) +
               ((var54_phi ^ var55_phi) ^ var53_phi)) +
              var52_phi) +
             (var0[var51_phi]));
    var58 = llvm_fshl_i32(var55_phi, var55_phi, 30);
    var59 = (((long)var51_phi) + ((long)1));
  } while (var59 == 80);
  (sha_info_digest[0]) = (var63_phi + var4);
  (sha_info_digest[1]) = (var62_phi + var5);
  (sha_info_digest[2]) = (var64_phi + var6);
  (sha_info_digest[3]) = (var61_phi + var7);
  (sha_info_digest[4]) = (var60_phi + var8);
  return;
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
  var3 = (var1 << ((unsigned int)3));
  if (var3 > (var2 ^ -1)) {
    sha_info_count_hi = (sha_info_count_hi + 1);
    goto block2;
  } else {
    goto block2;
  }
block2:
  sha_info_count_lo = (var2 + var3);
  sha_info_count_hi = (sha_info_count_hi + ((var1) >> (29)));
  if (((int)var1) > ((int)63)) {
    var4_phi = var1;
    var5_phi = var0;
    do {
      var4_phi = var13;
      var5_phi = var12;
      var6_phi = 16;
      var7_phi = (&(sha_info_data[0]));
      var8_phi = var5_phi;
      do {
        var6_phi = var9;
        var7_phi = var11;
        var8_phi = var10;
        var9 = (((int)var6_phi) + ((int)-1));
        var10 = (&(*(((unsigned char *)(var8_phi)) + 4)));
        (*var7_phi) =
            ((((((int)((unsigned int)(*(((unsigned char *)(var8_phi)) + 1))))
                << ((int)((unsigned int)((int)8)))) |
               ((unsigned int)(*var8_phi))) |
              (((int)((unsigned int)(*(((unsigned char *)(var8_phi)) + 2))))
               << ((int)((unsigned int)((int)16))))) |
             (((unsigned int)(*(((unsigned char *)(var8_phi)) + 3)))
              << ((unsigned int)24)));
        var11 = (&(*(((unsigned int *)(var7_phi)) + 1)));
      } while (var6_phi > 1);
      goto block6;
    block6:
      sha_transform();
      var12 = (&(*(((unsigned char *)(var5_phi)) + 64)));
      var13 = (((int)var4_phi) + ((int)-64));
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
    var18 = (((int)var17_phi) / ((int)4));
    var19_phi = var18;
    var20_phi = (&(sha_info_data[0]));
    var21_phi = var16_phi;
    do {
      var19_phi = var22;
      var20_phi = var24;
      var21_phi = var23;
      var22 = (((int)var19_phi) + ((int)-1));
      var23 = (&(*(((unsigned char *)(var21_phi)) + 4)));
      (*var20_phi) =
          ((((((int)((unsigned int)(*(((unsigned char *)(var21_phi)) + 1))))
              << ((int)((unsigned int)((int)8)))) |
             ((unsigned int)(*var21_phi))) |
            (((int)((unsigned int)(*(((unsigned char *)(var21_phi)) + 2))))
             << ((int)((unsigned int)((int)16))))) |
           (((unsigned int)(*(((unsigned char *)(var21_phi)) + 3)))
            << ((unsigned int)24)));
      var24 = (&(*(((unsigned int *)(var20_phi)) + 1)));
    } while (var19_phi > 1);
    return;
  } else {
    return;
  }
}
