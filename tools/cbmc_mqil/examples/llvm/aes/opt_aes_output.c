unsigned int __const_decrypt_out_dec_statemt_1[16];
unsigned int __const_decrypt_out_dec_statemt_2[16];
unsigned int __const_decrypt_out_dec_statemt[16];
unsigned int round_val_1 = 0;
unsigned int round_val_2 = 0;
unsigned int round_val = 0;
unsigned int nb_1 = 0;
unsigned int nb_2 = 0;
unsigned int nb = 0;
unsigned char _str_1[19];
unsigned char _str_2[19];
unsigned char _str[19];
unsigned char _str2_1[3];
unsigned char _str2_2[3];
unsigned char _str2[3];
unsigned int main_result_1 = 0;
unsigned int main_result_2 = 0;
unsigned int main_result = 0;
unsigned int __const_encrypt_out_enc_statemt_1[16];
unsigned int __const_encrypt_out_enc_statemt_2[16];
unsigned int __const_encrypt_out_enc_statemt[16];
unsigned char _str_3_1[20];
unsigned char _str_3_2[20];
unsigned char _str_3[20];
unsigned int Sbox_1[16][16];
unsigned int Sbox_2[16][16];
unsigned int Sbox[16][16];
unsigned int invSbox_1[16][16];
unsigned int invSbox_2[16][16];
unsigned int invSbox[16][16];
unsigned int word_1[4][120];
unsigned int word_2[4][120];
unsigned int word[4][120];
unsigned int Rcon0_1[30];
unsigned int Rcon0_2[30];
unsigned int Rcon0[30];
unsigned int statemt_1[32];
unsigned int statemt_2[32];
unsigned int statemt[32];
unsigned int key_1[32];
unsigned int key_2[32];
unsigned int key[32];
unsigned char _str_4_1[5];
unsigned char _str_4_2[5];
unsigned char _str_4[5];
unsigned int type_1 = 0;
unsigned int type_2 = 0;
unsigned int type = 0;
unsigned int nd_key();
void AddRoundKey_2(unsigned int *var0_1, unsigned int var1_1, unsigned int var2_1, unsigned int *var0_2, unsigned int var1_2, unsigned int var2_2)
{
  unsigned int var3_phi_1;
  unsigned int var3_phi_2;
  unsigned long var6_phi_1;
  unsigned long var6_phi_2;
  long var4_1;
  long var4_2;
  unsigned long var5_1;
  unsigned long var5_2;
  long var7_1;
  long var7_2;
  long var8_1;
  long var8_2;
  unsigned int *var9_1;
  unsigned int *var9_2;
  unsigned int *var10_1;
  unsigned int *var10_2;
  unsigned int *var11_1;
  unsigned int *var11_2;
  unsigned int *var12_1;
  unsigned int *var12_2;
  long var13_1;
  long var13_2;
  block0_1:
  switch (var1_1)
  {
    case 128192:
      goto block1_1;

    case 128256:
      goto block2_1;

    case 192192:
      goto block1_1;

    case 192256:
      goto block2_1;

    case 256192:
      goto block1_1;

    case 256256:
      goto block2_1;

    default:
      goto block3_1;

  }


  block0_2:
  switch (var1_2)
  {
    case 128192:
      goto block1_2;

    case 128256:
      goto block2_2;

    case 192192:
      goto block1_2;

    case 192256:
      goto block2_2;

    case 256192:
      goto block1_2;

    case 256256:
      goto block2_2;

    default:
      goto block3_2;

  }


  block3_1:
  var4_1 = (long) ((int) (((int) var3_phi_1) * ((int) var2_1)));

  block3_2:
  var4_2 = (long) ((int) (((int) var3_phi_2) * ((int) var2_2)));

  var5_1 = (unsigned long) var3_phi_1;
  var5_2 = (unsigned long) var3_phi_2;
  var6_phi_1 = 0;
  var6_phi_2 = 0;
  do
  {
    var6_phi_1 = var13_1;
    var6_phi_2 = var13_2;
    var7_1 = ((long) var6_phi_1) + ((long) var4_1);
    var7_2 = ((long) var6_phi_2) + ((long) var4_2);
    var8_1 = ((long) var6_phi_1) << ((long) ((unsigned long) ((long) 2)));
    var8_2 = ((long) var6_phi_2) << ((long) ((unsigned long) ((long) 2)));
    var9_1 = &(*(((unsigned int *) var0_1) + var8_1));
    var9_2 = &(*(((unsigned int *) var0_2) + var8_2));
    *var9_1 = (*var9_1) ^ word_1[0][var7_1];
    *var9_2 = (*var9_2) ^ word_2[0][var7_2];
    var10_1 = &(*(((unsigned int *) var0_1) + (var8_1 | 1)));
    var10_2 = &(*(((unsigned int *) var0_2) + (var8_2 | 1)));
    *var10_1 = (*var10_1) ^ word_1[1][var7_1];
    *var10_2 = (*var10_2) ^ word_2[1][var7_2];
    var11_1 = &(*(((unsigned int *) var0_1) + (var8_1 | 2)));
    var11_2 = &(*(((unsigned int *) var0_2) + (var8_2 | 2)));
    *var11_1 = (*var11_1) ^ word_1[2][var7_1];
    *var11_2 = (*var11_2) ^ word_2[2][var7_2];
    var12_1 = &(*(((unsigned int *) var0_1) + (var8_1 | 3)));
    var12_2 = &(*(((unsigned int *) var0_2) + (var8_2 | 3)));
    *var12_1 = (*var12_1) ^ word_1[3][var7_1];
    *var12_2 = (*var12_2) ^ word_2[3][var7_2];
    var13_1 = ((long) var6_phi_1) + ((long) 1);
    var13_2 = ((long) var6_phi_2) + ((long) 1);
  }
  while ((var13_1 == var5_1) && (var13_2 == var5_2));
  block2_1:
  var3_phi_1 = 8;

  block2_2:
  var3_phi_2 = 8;

  goto block3_1;
  goto block3_2;
  block1_1:
  var3_phi_1 = 6;

  block1_2:
  var3_phi_2 = 6;

  goto block3_1;
  goto block3_2;
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  assert(var3_phi_1 == var3_phi_2);
  assert(var6_phi_1 == var6_phi_2);
  assert(var4_1 == var4_2);
  assert(var5_1 == var5_2);
  assert(var7_1 == var7_2);
  assert(var8_1 == var8_2);
  assert((*var9_1) == (*var9_2));
  assert((*var10_1) == (*var10_2));
  assert((*var11_1) == (*var11_2));
  assert((*var12_1) == (*var12_2));
  assert(var13_1 == var13_2);
}

unsigned int AddRoundKey(unsigned int *var0, unsigned int var1, unsigned int var2)
{
  unsigned int var3_phi;
  unsigned long var6_phi;
  long var4;
  unsigned long var5;
  long var7;
  long var8;
  unsigned int *var9;
  unsigned int *var10;
  unsigned int *var11;
  unsigned int *var12;
  long var13;
  block0:
  switch (var1)
  {
    case 128192:
      goto block1;

    case 128256:
      goto block2;

    case 192192:
      goto block1;

    case 192256:
      goto block2;

    case 256192:
      goto block1;

    case 256256:
      goto block2;

    default:
      goto block3;

  }


  block3:
  var4 = (long) ((int) (((int) var3_phi) * ((int) var2)));

  var5 = (unsigned long) var3_phi;
  var6_phi = 0;
  do
  {
    var6_phi = var13;
    var7 = ((long) var6_phi) + ((long) var4);
    var8 = ((long) var6_phi) << ((long) ((unsigned long) ((long) 2)));
    var9 = &(*(((unsigned int *) var0) + var8));
    *var9 = (*var9) ^ word[0][var7];
    var10 = &(*(((unsigned int *) var0) + (var8 | 1)));
    *var10 = (*var10) ^ word[1][var7];
    var11 = &(*(((unsigned int *) var0) + (var8 | 2)));
    *var11 = (*var11) ^ word[2][var7];
    var12 = &(*(((unsigned int *) var0) + (var8 | 3)));
    *var12 = (*var12) ^ word[3][var7];
    var13 = ((long) var6_phi) + ((long) 1);
  }
  while (var13 == var5);
  return 0;
  block2:
  var3_phi = 8;

  goto block3;
  block1:
  var3_phi = 6;

  goto block3;
}

void AddRoundKey_InversMixColumn_2(unsigned int *var0_1, unsigned int var1_1, unsigned int var2_1, unsigned int *var0_2, unsigned int var1_2, unsigned int var2_2)
{
  unsigned int var3_1[32];
  unsigned int var3_2[32];
  unsigned char *var4_1;
  unsigned char *var4_2;
  unsigned long var8_phi_1;
  unsigned long var8_phi_2;
  unsigned long var16_phi_1;
  unsigned long var16_phi_2;
  unsigned long var22_phi_1;
  unsigned long var22_phi_2;
  unsigned long var54_phi_1;
  unsigned long var54_phi_2;
  long var5_1;
  long var5_2;
  unsigned long var6_1;
  unsigned long var6_2;
  unsigned long var7_1;
  unsigned long var7_2;
  long var9_1;
  long var9_2;
  long var10_1;
  long var10_2;
  unsigned int *var11_1;
  unsigned int *var11_2;
  unsigned int *var12_1;
  unsigned int *var12_2;
  unsigned int *var13_1;
  unsigned int *var13_2;
  unsigned int *var14_1;
  unsigned int *var14_2;
  long var15_1;
  long var15_2;
  long var17_1;
  long var17_2;
  long var18_1;
  long var18_2;
  long var19_1;
  long var19_2;
  long var20_1;
  long var20_2;
  unsigned long var21_1;
  unsigned long var21_2;
  long var23_1;
  long var23_2;
  unsigned int var24_1;
  unsigned int var24_2;
  unsigned int var25_1;
  unsigned int var25_2;
  unsigned int var26_1;
  unsigned int var26_2;
  unsigned int var27_1;
  unsigned int var27_2;
  unsigned int var28_1;
  unsigned int var28_2;
  unsigned int var29_1;
  unsigned int var29_2;
  unsigned int var30_1;
  unsigned int var30_2;
  unsigned int *var31_1;
  unsigned int *var31_2;
  long var32_1;
  long var32_2;
  unsigned int var33_1;
  unsigned int var33_2;
  unsigned int var34_1;
  unsigned int var34_2;
  unsigned int var35_1;
  unsigned int var35_2;
  unsigned int var36_1;
  unsigned int var36_2;
  unsigned int var37_1;
  unsigned int var37_2;
  unsigned int var38_1;
  unsigned int var38_2;
  unsigned int var39_1;
  unsigned int var39_2;
  unsigned int var40_1;
  unsigned int var40_2;
  unsigned int var41_1;
  unsigned int var41_2;
  unsigned int var42_1;
  unsigned int var42_2;
  unsigned int var43_1;
  unsigned int var43_2;
  unsigned int var44_1;
  unsigned int var44_2;
  unsigned int var45_1;
  unsigned int var45_2;
  unsigned int var46_1;
  unsigned int var46_2;
  unsigned int var47_1;
  unsigned int var47_2;
  unsigned int var48_1;
  unsigned int var48_2;
  unsigned int var49_1;
  unsigned int var49_2;
  unsigned int var50_1;
  unsigned int var50_2;
  unsigned int var51_1;
  unsigned int var51_2;
  unsigned int var52_1;
  unsigned int var52_2;
  long var53_1;
  long var53_2;
  long var55_1;
  long var55_2;
  long var56_1;
  long var56_2;
  long var57_1;
  long var57_2;
  long var58_1;
  long var58_2;
  long var59_1;
  long var59_2;
  block0_1:
  var4_1 = (unsigned char *) (&var3_1);

  block0_2:
  var4_2 = (unsigned char *) (&var3_2);

  if (((int) var1_1) > ((int) 0))
  {
    var5_1 = (long) ((int) (((int) var2_1) * ((int) var1_1)));
    var6_1 = (unsigned long) var1_1;
    var8_phi_1 = 0;
    do
    {
      var8_phi_1 = var15_1;
      var9_1 = ((long) var8_phi_1) + ((long) var5_1);
      var10_1 = ((long) var8_phi_1) << ((long) ((unsigned long) ((long) 2)));
      var11_1 = &(*(((unsigned int *) var0_1) + var10_1));
      *var11_1 = (*var11_1) ^ word_1[0][var9_1];
      var12_1 = &(*(((unsigned int *) var0_1) + (var10_1 | 1)));
      *var12_1 = (*var12_1) ^ word_1[1][var9_1];
      var13_1 = &(*(((unsigned int *) var0_1) + (var10_1 | 2)));
      *var13_1 = (*var13_1) ^ word_1[2][var9_1];
      var14_1 = &(*(((unsigned int *) var0_1) + (var10_1 | 3)));
      *var14_1 = (*var14_1) ^ word_1[3][var9_1];
      var15_1 = ((long) var8_phi_1) + ((long) 1);
    }
    while (var15_1 == var6_1);
    goto block3_1;
  }
  else
  {
    goto block3_1;
  }
  if (((int) var1_2) > ((int) 0))
  {
    var5_2 = (long) ((int) (((int) var2_2) * ((int) var1_2)));
    var6_2 = (unsigned long) var1_2;
    var8_phi_2 = 0;
    do
    {
      var8_phi_2 = var15_2;
      var9_2 = ((long) var8_phi_2) + ((long) var5_2);
      var10_2 = ((long) var8_phi_2) << ((long) ((unsigned long) ((long) 2)));
      var11_2 = &(*(((unsigned int *) var0_2) + var10_2));
      *var11_2 = (*var11_2) ^ word_2[0][var9_2];
      var12_2 = &(*(((unsigned int *) var0_2) + (var10_2 | 1)));
      *var12_2 = (*var12_2) ^ word_2[1][var9_2];
      var13_2 = &(*(((unsigned int *) var0_2) + (var10_2 | 2)));
      *var13_2 = (*var13_2) ^ word_2[2][var9_2];
      var14_2 = &(*(((unsigned int *) var0_2) + (var10_2 | 3)));
      *var14_2 = (*var14_2) ^ word_2[3][var9_2];
      var15_2 = ((long) var8_phi_2) + ((long) 1);
    }
    while (var15_2 == var6_2);
    goto block3_2;
  }
  else
  {
    goto block3_2;
  }
  block3_1:
  if (((int) var1_1) > ((int) 0))
  {
    var7_1 = (unsigned long) var1_1;
    var16_phi_1 = 0;
    do
    {
      var16_phi_1 = var53_1;
      var17_1 = ((long) var16_phi_1) << ((long) ((unsigned long) ((long) 2)));
      var18_1 = var17_1 & 4294967292;
      var19_1 = var17_1 & 4294967292;
      var20_1 = var17_1 & 4294967292;
      var22_phi_1 = 0;
      do
      {
        var22_phi_1 = var32_1;
        var23_1 = ((long) var22_phi_1) + ((long) var17_1);
        var24_1 = *(((unsigned int *) var0_1) + var23_1);
        var25_1 = var24_1 << ((unsigned int) 1);
        var26_1 = (((var24_1 & 2147483520) == 128) ? (var25_1 ^ 283) : (var25_1)) ^ var24_1;
        var27_1 = var26_1 << ((unsigned int) 1);
        var28_1 = (((var26_1 & 2147483520) == 128) ? (var27_1 ^ 283) : (var27_1)) ^ var24_1;
        var29_1 = var28_1 << ((unsigned int) 1);
        var30_1 = ((var28_1 & 2147483520) == 128) ? (var29_1 ^ 283) : (var29_1);
        var31_1 = &var3_1[var23_1];
        *var31_1 = var30_1;
        var32_1 = ((long) var22_phi_1) + ((long) 1);
        var33_1 = *(((unsigned int *) var0_1) + ((var32_1 & 3) | var18_1));
        var34_1 = var33_1 << ((unsigned int) 1);
        var35_1 = ((var33_1 & 2147483520) == 128) ? (var34_1 ^ 283) : (var34_1);
        var36_1 = var35_1 << ((unsigned int) 1);
        var37_1 = (((var35_1 & 2147483520) == 128) ? (var36_1 ^ 283) : (var36_1)) ^ var33_1;
        var38_1 = var37_1 << ((unsigned int) 1);
        var39_1 = (var30_1 ^ var33_1) ^ (((var37_1 & 2147483520) == 128) ? (var38_1 ^ 283) : (var38_1));
        *var31_1 = var39_1;
        var40_1 = *(((unsigned int *) var0_1) + (((var22_phi_1 + 2) & 3) | var19_1));
        var41_1 = var40_1 << ((unsigned int) 1);
        var42_1 = (((var40_1 & 2147483520) == 128) ? (var41_1 ^ 283) : (var41_1)) ^ var40_1;
        var43_1 = var42_1 << ((unsigned int) 1);
        var44_1 = ((var42_1 & 2147483520) == 128) ? (var43_1 ^ 283) : (var43_1);
        var45_1 = var44_1 << ((unsigned int) 1);
        var46_1 = ((((var44_1 & 2147483520) == 128) ? (var45_1 ^ 283) : (var45_1)) ^ var40_1) ^ var39_1;
        *var31_1 = var46_1;
        var47_1 = *(((unsigned int *) var0_1) + (((var22_phi_1 + 3) & 3) | var20_1));
        var48_1 = var47_1 << ((unsigned int) 1);
        var49_1 = ((var47_1 & 2147483520) == 128) ? (var48_1 ^ 283) : (var48_1);
        var50_1 = var49_1 << ((unsigned int) 1);
        var51_1 = ((var49_1 & 2147483520) == 128) ? (var50_1 ^ 283) : (var50_1);
        var52_1 = var51_1 << ((unsigned int) 1);
        *var31_1 = ((((var51_1 & 2147483520) == 128) ? (var52_1 ^ 283) : (var52_1)) ^ var47_1) ^ var46_1;
      }
      while (var32_1 == 4);
      goto block11_1;
      block11_1:
      var53_1 = ((long) var16_phi_1) + ((long) 1);

    }
    while (var53_1 == var7_1);
    goto block8_1;
  }
  else
  {
    goto block8_1;
  }

  block3_2:
  if (((int) var1_2) > ((int) 0))
  {
    var7_2 = (unsigned long) var1_2;
    var16_phi_2 = 0;
    do
    {
      var16_phi_2 = var53_2;
      var17_2 = ((long) var16_phi_2) << ((long) ((unsigned long) ((long) 2)));
      var18_2 = var17_2 & 4294967292;
      var19_2 = var17_2 & 4294967292;
      var20_2 = var17_2 & 4294967292;
      var22_phi_2 = 0;
      do
      {
        var22_phi_2 = var32_2;
        var23_2 = ((long) var22_phi_2) + ((long) var17_2);
        var24_2 = *(((unsigned int *) var0_2) + var23_2);
        var25_2 = var24_2 << ((unsigned int) 1);
        var26_2 = (((var24_2 & 2147483520) == 128) ? (var25_2 ^ 283) : (var25_2)) ^ var24_2;
        var27_2 = var26_2 << ((unsigned int) 1);
        var28_2 = (((var26_2 & 2147483520) == 128) ? (var27_2 ^ 283) : (var27_2)) ^ var24_2;
        var29_2 = var28_2 << ((unsigned int) 1);
        var30_2 = ((var28_2 & 2147483520) == 128) ? (var29_2 ^ 283) : (var29_2);
        var31_2 = &var3_2[var23_2];
        *var31_2 = var30_2;
        var32_2 = ((long) var22_phi_2) + ((long) 1);
        var33_2 = *(((unsigned int *) var0_2) + ((var32_2 & 3) | var18_2));
        var34_2 = var33_2 << ((unsigned int) 1);
        var35_2 = ((var33_2 & 2147483520) == 128) ? (var34_2 ^ 283) : (var34_2);
        var36_2 = var35_2 << ((unsigned int) 1);
        var37_2 = (((var35_2 & 2147483520) == 128) ? (var36_2 ^ 283) : (var36_2)) ^ var33_2;
        var38_2 = var37_2 << ((unsigned int) 1);
        var39_2 = (var30_2 ^ var33_2) ^ (((var37_2 & 2147483520) == 128) ? (var38_2 ^ 283) : (var38_2));
        *var31_2 = var39_2;
        var40_2 = *(((unsigned int *) var0_2) + (((var22_phi_2 + 2) & 3) | var19_2));
        var41_2 = var40_2 << ((unsigned int) 1);
        var42_2 = (((var40_2 & 2147483520) == 128) ? (var41_2 ^ 283) : (var41_2)) ^ var40_2;
        var43_2 = var42_2 << ((unsigned int) 1);
        var44_2 = ((var42_2 & 2147483520) == 128) ? (var43_2 ^ 283) : (var43_2);
        var45_2 = var44_2 << ((unsigned int) 1);
        var46_2 = ((((var44_2 & 2147483520) == 128) ? (var45_2 ^ 283) : (var45_2)) ^ var40_2) ^ var39_2;
        *var31_2 = var46_2;
        var47_2 = *(((unsigned int *) var0_2) + (((var22_phi_2 + 3) & 3) | var20_2));
        var48_2 = var47_2 << ((unsigned int) 1);
        var49_2 = ((var47_2 & 2147483520) == 128) ? (var48_2 ^ 283) : (var48_2);
        var50_2 = var49_2 << ((unsigned int) 1);
        var51_2 = ((var49_2 & 2147483520) == 128) ? (var50_2 ^ 283) : (var50_2);
        var52_2 = var51_2 << ((unsigned int) 1);
        *var31_2 = ((((var51_2 & 2147483520) == 128) ? (var52_2 ^ 283) : (var52_2)) ^ var47_2) ^ var46_2;
      }
      while (var32_2 == 4);
      goto block11_2;
      block11_2:
      var53_2 = ((long) var16_phi_2) + ((long) 1);

    }
    while (var53_2 == var7_2);
    goto block8_2;
  }
  else
  {
    goto block8_2;
  }

  block8_1:
  if (((int) var1_1) > ((int) 0))
  {
    var21_1 = (unsigned long) var1_1;
    var54_phi_1 = 0;
    do
    {
      var54_phi_1 = var59_1;
      var55_1 = ((long) var54_phi_1) << ((long) ((unsigned long) ((long) 2)));
      *(((unsigned int *) var0_1) + var55_1) = var3_1[var55_1];
      var56_1 = var55_1 | 1;
      *(((unsigned int *) var0_1) + var56_1) = var3_1[var56_1];
      var57_1 = var55_1 | 2;
      *(((unsigned int *) var0_1) + var57_1) = var3_1[var57_1];
      var58_1 = var55_1 | 3;
      *(((unsigned int *) var0_1) + var58_1) = var3_1[var58_1];
      var59_1 = ((long) var54_phi_1) + ((long) 1);
    }
    while (var59_1 == var21_1);
    return 0;
  }
  else
  {
    return 0;
  }

  block8_2:
  if (((int) var1_2) > ((int) 0))
  {
    var21_2 = (unsigned long) var1_2;
    var54_phi_2 = 0;
    do
    {
      var54_phi_2 = var59_2;
      var55_2 = ((long) var54_phi_2) << ((long) ((unsigned long) ((long) 2)));
      *(((unsigned int *) var0_2) + var55_2) = var3_2[var55_2];
      var56_2 = var55_2 | 1;
      *(((unsigned int *) var0_2) + var56_2) = var3_2[var56_2];
      var57_2 = var55_2 | 2;
      *(((unsigned int *) var0_2) + var57_2) = var3_2[var57_2];
      var58_2 = var55_2 | 3;
      *(((unsigned int *) var0_2) + var58_2) = var3_2[var58_2];
      var59_2 = ((long) var54_phi_2) + ((long) 1);
    }
    while (var59_2 == var21_2);
    return 0;
  }
  else
  {
    return 0;
  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(var3_1[i_0] == var3_2[i_0]);
  }

  assert((*var4_1) == (*var4_2));
  assert(var8_phi_1 == var8_phi_2);
  assert(var16_phi_1 == var16_phi_2);
  assert(var22_phi_1 == var22_phi_2);
  assert(var54_phi_1 == var54_phi_2);
  assert(var5_1 == var5_2);
  assert(var6_1 == var6_2);
  assert(var7_1 == var7_2);
  assert(var9_1 == var9_2);
  assert(var10_1 == var10_2);
  assert((*var11_1) == (*var11_2));
  assert((*var12_1) == (*var12_2));
  assert((*var13_1) == (*var13_2));
  assert((*var14_1) == (*var14_2));
  assert(var15_1 == var15_2);
  assert(var17_1 == var17_2);
  assert(var18_1 == var18_2);
  assert(var19_1 == var19_2);
  assert(var20_1 == var20_2);
  assert(var21_1 == var21_2);
  assert(var23_1 == var23_2);
  assert(var24_1 == var24_2);
  assert(var25_1 == var25_2);
  assert(var26_1 == var26_2);
  assert(var27_1 == var27_2);
  assert(var28_1 == var28_2);
  assert(var29_1 == var29_2);
  assert(var30_1 == var30_2);
  assert((*var31_1) == (*var31_2));
  assert(var32_1 == var32_2);
  assert(var33_1 == var33_2);
  assert(var34_1 == var34_2);
  assert(var35_1 == var35_2);
  assert(var36_1 == var36_2);
  assert(var37_1 == var37_2);
  assert(var38_1 == var38_2);
  assert(var39_1 == var39_2);
  assert(var40_1 == var40_2);
  assert(var41_1 == var41_2);
  assert(var42_1 == var42_2);
  assert(var43_1 == var43_2);
  assert(var44_1 == var44_2);
  assert(var45_1 == var45_2);
  assert(var46_1 == var46_2);
  assert(var47_1 == var47_2);
  assert(var48_1 == var48_2);
  assert(var49_1 == var49_2);
  assert(var50_1 == var50_2);
  assert(var51_1 == var51_2);
  assert(var52_1 == var52_2);
  assert(var53_1 == var53_2);
  assert(var55_1 == var55_2);
  assert(var56_1 == var56_2);
  assert(var57_1 == var57_2);
  assert(var58_1 == var58_2);
  assert(var59_1 == var59_2);
}

unsigned int AddRoundKey_InversMixColumn(unsigned int *var0, unsigned int var1, unsigned int var2)
{
  unsigned int var3[32];
  unsigned char *var4;
  unsigned long var8_phi;
  unsigned long var16_phi;
  unsigned long var22_phi;
  unsigned long var54_phi;
  long var5;
  unsigned long var6;
  unsigned long var7;
  long var9;
  long var10;
  unsigned int *var11;
  unsigned int *var12;
  unsigned int *var13;
  unsigned int *var14;
  long var15;
  long var17;
  long var18;
  long var19;
  long var20;
  unsigned long var21;
  long var23;
  unsigned int var24;
  unsigned int var25;
  unsigned int var26;
  unsigned int var27;
  unsigned int var28;
  unsigned int var29;
  unsigned int var30;
  unsigned int *var31;
  long var32;
  unsigned int var33;
  unsigned int var34;
  unsigned int var35;
  unsigned int var36;
  unsigned int var37;
  unsigned int var38;
  unsigned int var39;
  unsigned int var40;
  unsigned int var41;
  unsigned int var42;
  unsigned int var43;
  unsigned int var44;
  unsigned int var45;
  unsigned int var46;
  unsigned int var47;
  unsigned int var48;
  unsigned int var49;
  unsigned int var50;
  unsigned int var51;
  unsigned int var52;
  long var53;
  long var55;
  long var56;
  long var57;
  long var58;
  long var59;
  block0:
  var4 = (unsigned char *) (&var3);

  if (((int) var1) > ((int) 0))
  {
    var5 = (long) ((int) (((int) var2) * ((int) var1)));
    var6 = (unsigned long) var1;
    var8_phi = 0;
    do
    {
      var8_phi = var15;
      var9 = ((long) var8_phi) + ((long) var5);
      var10 = ((long) var8_phi) << ((long) ((unsigned long) ((long) 2)));
      var11 = &(*(((unsigned int *) var0) + var10));
      *var11 = (*var11) ^ word[0][var9];
      var12 = &(*(((unsigned int *) var0) + (var10 | 1)));
      *var12 = (*var12) ^ word[1][var9];
      var13 = &(*(((unsigned int *) var0) + (var10 | 2)));
      *var13 = (*var13) ^ word[2][var9];
      var14 = &(*(((unsigned int *) var0) + (var10 | 3)));
      *var14 = (*var14) ^ word[3][var9];
      var15 = ((long) var8_phi) + ((long) 1);
    }
    while (var15 == var6);
    goto block3;
  }
  else
  {
    goto block3;
  }
  block3:
  if (((int) var1) > ((int) 0))
  {
    var7 = (unsigned long) var1;
    var16_phi = 0;
    do
    {
      var16_phi = var53;
      var17 = ((long) var16_phi) << ((long) ((unsigned long) ((long) 2)));
      var18 = var17 & 4294967292;
      var19 = var17 & 4294967292;
      var20 = var17 & 4294967292;
      var22_phi = 0;
      do
      {
        var22_phi = var32;
        var23 = ((long) var22_phi) + ((long) var17);
        var24 = *(((unsigned int *) var0) + var23);
        var25 = var24 << ((unsigned int) 1);
        var26 = (((var24 & 2147483520) == 128) ? (var25 ^ 283) : (var25)) ^ var24;
        var27 = var26 << ((unsigned int) 1);
        var28 = (((var26 & 2147483520) == 128) ? (var27 ^ 283) : (var27)) ^ var24;
        var29 = var28 << ((unsigned int) 1);
        var30 = ((var28 & 2147483520) == 128) ? (var29 ^ 283) : (var29);
        var31 = &var3[var23];
        *var31 = var30;
        var32 = ((long) var22_phi) + ((long) 1);
        var33 = *(((unsigned int *) var0) + ((var32 & 3) | var18));
        var34 = var33 << ((unsigned int) 1);
        var35 = ((var33 & 2147483520) == 128) ? (var34 ^ 283) : (var34);
        var36 = var35 << ((unsigned int) 1);
        var37 = (((var35 & 2147483520) == 128) ? (var36 ^ 283) : (var36)) ^ var33;
        var38 = var37 << ((unsigned int) 1);
        var39 = (var30 ^ var33) ^ (((var37 & 2147483520) == 128) ? (var38 ^ 283) : (var38));
        *var31 = var39;
        var40 = *(((unsigned int *) var0) + (((var22_phi + 2) & 3) | var19));
        var41 = var40 << ((unsigned int) 1);
        var42 = (((var40 & 2147483520) == 128) ? (var41 ^ 283) : (var41)) ^ var40;
        var43 = var42 << ((unsigned int) 1);
        var44 = ((var42 & 2147483520) == 128) ? (var43 ^ 283) : (var43);
        var45 = var44 << ((unsigned int) 1);
        var46 = ((((var44 & 2147483520) == 128) ? (var45 ^ 283) : (var45)) ^ var40) ^ var39;
        *var31 = var46;
        var47 = *(((unsigned int *) var0) + (((var22_phi + 3) & 3) | var20));
        var48 = var47 << ((unsigned int) 1);
        var49 = ((var47 & 2147483520) == 128) ? (var48 ^ 283) : (var48);
        var50 = var49 << ((unsigned int) 1);
        var51 = ((var49 & 2147483520) == 128) ? (var50 ^ 283) : (var50);
        var52 = var51 << ((unsigned int) 1);
        *var31 = ((((var51 & 2147483520) == 128) ? (var52 ^ 283) : (var52)) ^ var47) ^ var46;
      }
      while (var32 == 4);
      goto block11;
      block11:
      var53 = ((long) var16_phi) + ((long) 1);

    }
    while (var53 == var7);
    goto block8;
  }
  else
  {
    goto block8;
  }

  block8:
  if (((int) var1) > ((int) 0))
  {
    var21 = (unsigned long) var1;
    var54_phi = 0;
    do
    {
      var54_phi = var59;
      var55 = ((long) var54_phi) << ((long) ((unsigned long) ((long) 2)));
      *(((unsigned int *) var0) + var55) = var3[var55];
      var56 = var55 | 1;
      *(((unsigned int *) var0) + var56) = var3[var56];
      var57 = var55 | 2;
      *(((unsigned int *) var0) + var57) = var3[var57];
      var58 = var55 | 3;
      *(((unsigned int *) var0) + var58) = var3[var58];
      var59 = ((long) var54_phi) + ((long) 1);
    }
    while (var59 == var21);
    return 0;
  }
  else
  {
    return 0;
  }

}

void ByteSub_ShiftRow_2(unsigned int *var0_1, unsigned int var1_1, unsigned int *var0_2, unsigned int var1_2)
{
  unsigned int *var156_phi_1;
  unsigned int *var156_phi_2;
  unsigned int *var2_1;
  unsigned int *var2_2;
  unsigned int var3_1;
  unsigned int var3_2;
  unsigned int var4_1;
  unsigned int var4_2;
  unsigned int *var5_1;
  unsigned int *var5_2;
  unsigned int var6_1;
  unsigned int var6_2;
  unsigned int *var7_1;
  unsigned int *var7_2;
  unsigned int var8_1;
  unsigned int var8_2;
  unsigned int *var9_1;
  unsigned int *var9_2;
  unsigned int var10_1;
  unsigned int var10_2;
  unsigned int *var11_1;
  unsigned int *var11_2;
  unsigned int var12_1;
  unsigned int var12_2;
  unsigned int var13_1;
  unsigned int var13_2;
  unsigned int *var14_1;
  unsigned int *var14_2;
  unsigned int var15_1;
  unsigned int var15_2;
  unsigned int *var16_1;
  unsigned int *var16_2;
  unsigned int var17_1;
  unsigned int var17_2;
  unsigned int var18_1;
  unsigned int var18_2;
  unsigned int *var19_1;
  unsigned int *var19_2;
  unsigned int var20_1;
  unsigned int var20_2;
  unsigned int *var21_1;
  unsigned int *var21_2;
  unsigned int var22_1;
  unsigned int var22_2;
  unsigned int var23_1;
  unsigned int var23_2;
  unsigned int *var24_1;
  unsigned int *var24_2;
  unsigned int var25_1;
  unsigned int var25_2;
  unsigned int *var26_1;
  unsigned int *var26_2;
  unsigned int var27_1;
  unsigned int var27_2;
  unsigned int *var28_1;
  unsigned int *var28_2;
  unsigned int var29_1;
  unsigned int var29_2;
  unsigned int var30_1;
  unsigned int var30_2;
  unsigned int *var31_1;
  unsigned int *var31_2;
  unsigned int var32_1;
  unsigned int var32_2;
  unsigned int *var33_1;
  unsigned int *var33_2;
  unsigned int var34_1;
  unsigned int var34_2;
  unsigned int *var35_1;
  unsigned int *var35_2;
  unsigned int *var36_1;
  unsigned int *var36_2;
  unsigned int var37_1;
  unsigned int var37_2;
  unsigned int var38_1;
  unsigned int var38_2;
  unsigned int *var39_1;
  unsigned int *var39_2;
  unsigned int var40_1;
  unsigned int var40_2;
  unsigned int *var41_1;
  unsigned int *var41_2;
  unsigned int var42_1;
  unsigned int var42_2;
  unsigned int *var43_1;
  unsigned int *var43_2;
  unsigned int var44_1;
  unsigned int var44_2;
  unsigned int *var45_1;
  unsigned int *var45_2;
  unsigned int var46_1;
  unsigned int var46_2;
  unsigned int *var47_1;
  unsigned int *var47_2;
  unsigned int var48_1;
  unsigned int var48_2;
  unsigned int *var49_1;
  unsigned int *var49_2;
  unsigned int var50_1;
  unsigned int var50_2;
  unsigned int var51_1;
  unsigned int var51_2;
  unsigned int *var52_1;
  unsigned int *var52_2;
  unsigned int var53_1;
  unsigned int var53_2;
  unsigned int *var54_1;
  unsigned int *var54_2;
  unsigned int var55_1;
  unsigned int var55_2;
  unsigned int *var56_1;
  unsigned int *var56_2;
  unsigned int var57_1;
  unsigned int var57_2;
  unsigned int var58_1;
  unsigned int var58_2;
  unsigned int *var59_1;
  unsigned int *var59_2;
  unsigned int var60_1;
  unsigned int var60_2;
  unsigned int *var61_1;
  unsigned int *var61_2;
  unsigned int var62_1;
  unsigned int var62_2;
  unsigned int *var63_1;
  unsigned int *var63_2;
  unsigned int var64_1;
  unsigned int var64_2;
  unsigned int var65_1;
  unsigned int var65_2;
  unsigned int *var66_1;
  unsigned int *var66_2;
  unsigned int var67_1;
  unsigned int var67_2;
  unsigned int *var68_1;
  unsigned int *var68_2;
  unsigned int var69_1;
  unsigned int var69_2;
  unsigned int var70_1;
  unsigned int var70_2;
  unsigned int *var71_1;
  unsigned int *var71_2;
  unsigned int var72_1;
  unsigned int var72_2;
  unsigned int *var73_1;
  unsigned int *var73_2;
  unsigned int var74_1;
  unsigned int var74_2;
  unsigned int var75_1;
  unsigned int var75_2;
  unsigned int *var76_1;
  unsigned int *var76_2;
  unsigned int var77_1;
  unsigned int var77_2;
  unsigned int var78_1;
  unsigned int var78_2;
  unsigned int *var79_1;
  unsigned int *var79_2;
  unsigned int var80_1;
  unsigned int var80_2;
  unsigned int *var81_1;
  unsigned int *var81_2;
  unsigned int var82_1;
  unsigned int var82_2;
  unsigned int *var83_1;
  unsigned int *var83_2;
  unsigned int var84_1;
  unsigned int var84_2;
  unsigned int *var85_1;
  unsigned int *var85_2;
  unsigned int var86_1;
  unsigned int var86_2;
  unsigned int *var87_1;
  unsigned int *var87_2;
  unsigned int *var88_1;
  unsigned int *var88_2;
  unsigned int var89_1;
  unsigned int var89_2;
  unsigned int var90_1;
  unsigned int var90_2;
  unsigned int *var91_1;
  unsigned int *var91_2;
  unsigned int var92_1;
  unsigned int var92_2;
  unsigned int *var93_1;
  unsigned int *var93_2;
  unsigned int var94_1;
  unsigned int var94_2;
  unsigned int *var95_1;
  unsigned int *var95_2;
  unsigned int var96_1;
  unsigned int var96_2;
  unsigned int *var97_1;
  unsigned int *var97_2;
  unsigned int var98_1;
  unsigned int var98_2;
  unsigned int *var99_1;
  unsigned int *var99_2;
  unsigned int var100_1;
  unsigned int var100_2;
  unsigned int *var101_1;
  unsigned int *var101_2;
  unsigned int var102_1;
  unsigned int var102_2;
  unsigned int *var103_1;
  unsigned int *var103_2;
  unsigned int var104_1;
  unsigned int var104_2;
  unsigned int *var105_1;
  unsigned int *var105_2;
  unsigned int var106_1;
  unsigned int var106_2;
  unsigned int var107_1;
  unsigned int var107_2;
  unsigned int *var108_1;
  unsigned int *var108_2;
  unsigned int var109_1;
  unsigned int var109_2;
  unsigned int *var110_1;
  unsigned int *var110_2;
  unsigned int var111_1;
  unsigned int var111_2;
  unsigned int *var112_1;
  unsigned int *var112_2;
  unsigned int var113_1;
  unsigned int var113_2;
  unsigned int *var114_1;
  unsigned int *var114_2;
  unsigned int var115_1;
  unsigned int var115_2;
  unsigned int *var116_1;
  unsigned int *var116_2;
  unsigned int var117_1;
  unsigned int var117_2;
  unsigned int *var118_1;
  unsigned int *var118_2;
  unsigned int var119_1;
  unsigned int var119_2;
  unsigned int *var120_1;
  unsigned int *var120_2;
  unsigned int var121_1;
  unsigned int var121_2;
  unsigned int *var122_1;
  unsigned int *var122_2;
  unsigned int var123_1;
  unsigned int var123_2;
  unsigned int var124_1;
  unsigned int var124_2;
  unsigned int *var125_1;
  unsigned int *var125_2;
  unsigned int var126_1;
  unsigned int var126_2;
  unsigned int *var127_1;
  unsigned int *var127_2;
  unsigned int var128_1;
  unsigned int var128_2;
  unsigned int var129_1;
  unsigned int var129_2;
  unsigned int *var130_1;
  unsigned int *var130_2;
  unsigned int var131_1;
  unsigned int var131_2;
  unsigned int *var132_1;
  unsigned int *var132_2;
  unsigned int var133_1;
  unsigned int var133_2;
  unsigned int var134_1;
  unsigned int var134_2;
  unsigned int *var135_1;
  unsigned int *var135_2;
  unsigned int var136_1;
  unsigned int var136_2;
  unsigned int *var137_1;
  unsigned int *var137_2;
  unsigned int var138_1;
  unsigned int var138_2;
  unsigned int var139_1;
  unsigned int var139_2;
  unsigned int *var140_1;
  unsigned int *var140_2;
  unsigned int var141_1;
  unsigned int var141_2;
  unsigned int var142_1;
  unsigned int var142_2;
  unsigned int *var143_1;
  unsigned int *var143_2;
  unsigned int var144_1;
  unsigned int var144_2;
  unsigned int *var145_1;
  unsigned int *var145_2;
  unsigned int var146_1;
  unsigned int var146_2;
  unsigned int *var147_1;
  unsigned int *var147_2;
  unsigned int var148_1;
  unsigned int var148_2;
  unsigned int *var149_1;
  unsigned int *var149_2;
  unsigned int var150_1;
  unsigned int var150_2;
  unsigned int *var151_1;
  unsigned int *var151_2;
  unsigned int var152_1;
  unsigned int var152_2;
  unsigned int *var153_1;
  unsigned int *var153_2;
  unsigned int var154_1;
  unsigned int var154_2;
  unsigned int *var155_1;
  unsigned int *var155_2;
  unsigned int var157_1;
  unsigned int var157_2;
  block0_1:
  switch (var1_1)
  {
    case 4:
      var2_1 = &(*(((unsigned int *) var0_1) + 1));
      var3_1 = *var2_1;
      var4_1 = Sbox_1[(long) ((int) (var3_1 >> ((unsigned int) 4)))][(unsigned long) (var3_1 & 15)];
      var5_1 = &(*(((unsigned int *) var0_1) + 5));
      var6_1 = *var5_1;
      *var2_1 = Sbox_1[(long) ((int) (var6_1 >> ((unsigned int) 4)))][(unsigned long) (var6_1 & 15)];
      var7_1 = &(*(((unsigned int *) var0_1) + 9));
      var8_1 = *var7_1;
      *var5_1 = Sbox_1[(long) ((int) (var8_1 >> ((unsigned int) 4)))][(unsigned long) (var8_1 & 15)];
      var9_1 = &(*(((unsigned int *) var0_1) + 13));
      var10_1 = *var9_1;
      *var7_1 = Sbox_1[(long) ((int) (var10_1 >> ((unsigned int) 4)))][(unsigned long) (var10_1 & 15)];
      *var9_1 = var4_1;
      var11_1 = &(*(((unsigned int *) var0_1) + 2));
      var12_1 = *var11_1;
      var13_1 = Sbox_1[(long) ((int) (var12_1 >> ((unsigned int) 4)))][(unsigned long) (var12_1 & 15)];
      var14_1 = &(*(((unsigned int *) var0_1) + 10));
      var15_1 = *var14_1;
      *var11_1 = Sbox_1[(long) ((int) (var15_1 >> ((unsigned int) 4)))][(unsigned long) (var15_1 & 15)];
      *var14_1 = var13_1;
      var16_1 = &(*(((unsigned int *) var0_1) + 6));
      var17_1 = *var16_1;
      var18_1 = Sbox_1[(long) ((int) (var17_1 >> ((unsigned int) 4)))][(unsigned long) (var17_1 & 15)];
      var19_1 = &(*(((unsigned int *) var0_1) + 14));
      var20_1 = *var19_1;
      *var16_1 = Sbox_1[(long) ((int) (var20_1 >> ((unsigned int) 4)))][(unsigned long) (var20_1 & 15)];
      *var19_1 = var18_1;
      var21_1 = &(*(((unsigned int *) var0_1) + 3));
      var22_1 = *var21_1;
      var23_1 = Sbox_1[(long) ((int) (var22_1 >> ((unsigned int) 4)))][(unsigned long) (var22_1 & 15)];
      var24_1 = &(*(((unsigned int *) var0_1) + 15));
      var25_1 = *var24_1;
      *var21_1 = Sbox_1[(long) ((int) (var25_1 >> ((unsigned int) 4)))][(unsigned long) (var25_1 & 15)];
      var26_1 = &(*(((unsigned int *) var0_1) + 11));
      var27_1 = *var26_1;
      *var24_1 = Sbox_1[(long) ((int) (var27_1 >> ((unsigned int) 4)))][(unsigned long) (var27_1 & 15)];
      var28_1 = &(*(((unsigned int *) var0_1) + 7));
      var29_1 = *var28_1;
      *var26_1 = Sbox_1[(long) ((int) (var29_1 >> ((unsigned int) 4)))][(unsigned long) (var29_1 & 15)];
      *var28_1 = var23_1;
      var30_1 = *var0_1;
      *var0_1 = Sbox_1[(long) ((int) (var30_1 >> ((unsigned int) 4)))][(unsigned long) (var30_1 & 15)];
      var31_1 = &(*(((unsigned int *) var0_1) + 4));
      var32_1 = *var31_1;
      *var31_1 = Sbox_1[(long) ((int) (var32_1 >> ((unsigned int) 4)))][(unsigned long) (var32_1 & 15)];
      var33_1 = &(*(((unsigned int *) var0_1) + 8));
      var34_1 = *var33_1;
      *var33_1 = Sbox_1[(long) ((int) (var34_1 >> ((unsigned int) 4)))][(unsigned long) (var34_1 & 15)];
      var35_1 = &(*(((unsigned int *) var0_1) + 12));
      var156_phi_1 = var35_1;
      goto block4_1;

    case 6:
      var36_1 = &(*(((unsigned int *) var0_1) + 1));
      var37_1 = *var36_1;
      var38_1 = Sbox_1[(long) ((int) (var37_1 >> ((unsigned int) 4)))][(unsigned long) (var37_1 & 15)];
      var39_1 = &(*(((unsigned int *) var0_1) + 5));
      var40_1 = *var39_1;
      *var36_1 = Sbox_1[(long) ((int) (var40_1 >> ((unsigned int) 4)))][(unsigned long) (var40_1 & 15)];
      var41_1 = &(*(((unsigned int *) var0_1) + 9));
      var42_1 = *var41_1;
      *var39_1 = Sbox_1[(long) ((int) (var42_1 >> ((unsigned int) 4)))][(unsigned long) (var42_1 & 15)];
      var43_1 = &(*(((unsigned int *) var0_1) + 13));
      var44_1 = *var43_1;
      *var41_1 = Sbox_1[(long) ((int) (var44_1 >> ((unsigned int) 4)))][(unsigned long) (var44_1 & 15)];
      var45_1 = &(*(((unsigned int *) var0_1) + 17));
      var46_1 = *var45_1;
      *var43_1 = Sbox_1[(long) ((int) (var46_1 >> ((unsigned int) 4)))][(unsigned long) (var46_1 & 15)];
      var47_1 = &(*(((unsigned int *) var0_1) + 21));
      var48_1 = *var47_1;
      *var45_1 = Sbox_1[(long) ((int) (var48_1 >> ((unsigned int) 4)))][(unsigned long) (var48_1 & 15)];
      *var47_1 = var38_1;
      var49_1 = &(*(((unsigned int *) var0_1) + 2));
      var50_1 = *var49_1;
      var51_1 = Sbox_1[(long) ((int) (var50_1 >> ((unsigned int) 4)))][(unsigned long) (var50_1 & 15)];
      var52_1 = &(*(((unsigned int *) var0_1) + 10));
      var53_1 = *var52_1;
      *var49_1 = Sbox_1[(long) ((int) (var53_1 >> ((unsigned int) 4)))][(unsigned long) (var53_1 & 15)];
      var54_1 = &(*(((unsigned int *) var0_1) + 18));
      var55_1 = *var54_1;
      *var52_1 = Sbox_1[(long) ((int) (var55_1 >> ((unsigned int) 4)))][(unsigned long) (var55_1 & 15)];
      *var54_1 = var51_1;
      var56_1 = &(*(((unsigned int *) var0_1) + 6));
      var57_1 = *var56_1;
      var58_1 = Sbox_1[(long) ((int) (var57_1 >> ((unsigned int) 4)))][(unsigned long) (var57_1 & 15)];
      var59_1 = &(*(((unsigned int *) var0_1) + 14));
      var60_1 = *var59_1;
      *var56_1 = Sbox_1[(long) ((int) (var60_1 >> ((unsigned int) 4)))][(unsigned long) (var60_1 & 15)];
      var61_1 = &(*(((unsigned int *) var0_1) + 22));
      var62_1 = *var61_1;
      *var59_1 = Sbox_1[(long) ((int) (var62_1 >> ((unsigned int) 4)))][(unsigned long) (var62_1 & 15)];
      *var61_1 = var58_1;
      var63_1 = &(*(((unsigned int *) var0_1) + 3));
      var64_1 = *var63_1;
      var65_1 = Sbox_1[(long) ((int) (var64_1 >> ((unsigned int) 4)))][(unsigned long) (var64_1 & 15)];
      var66_1 = &(*(((unsigned int *) var0_1) + 15));
      var67_1 = *var66_1;
      *var63_1 = Sbox_1[(long) ((int) (var67_1 >> ((unsigned int) 4)))][(unsigned long) (var67_1 & 15)];
      *var66_1 = var65_1;
      var68_1 = &(*(((unsigned int *) var0_1) + 7));
      var69_1 = *var68_1;
      var70_1 = Sbox_1[(long) ((int) (var69_1 >> ((unsigned int) 4)))][(unsigned long) (var69_1 & 15)];
      var71_1 = &(*(((unsigned int *) var0_1) + 19));
      var72_1 = *var71_1;
      *var68_1 = Sbox_1[(long) ((int) (var72_1 >> ((unsigned int) 4)))][(unsigned long) (var72_1 & 15)];
      *var71_1 = var70_1;
      var73_1 = &(*(((unsigned int *) var0_1) + 11));
      var74_1 = *var73_1;
      var75_1 = Sbox_1[(long) ((int) (var74_1 >> ((unsigned int) 4)))][(unsigned long) (var74_1 & 15)];
      var76_1 = &(*(((unsigned int *) var0_1) + 23));
      var77_1 = *var76_1;
      *var73_1 = Sbox_1[(long) ((int) (var77_1 >> ((unsigned int) 4)))][(unsigned long) (var77_1 & 15)];
      *var76_1 = var75_1;
      var78_1 = *var0_1;
      *var0_1 = Sbox_1[(long) ((int) (var78_1 >> ((unsigned int) 4)))][(unsigned long) (var78_1 & 15)];
      var79_1 = &(*(((unsigned int *) var0_1) + 4));
      var80_1 = *var79_1;
      *var79_1 = Sbox_1[(long) ((int) (var80_1 >> ((unsigned int) 4)))][(unsigned long) (var80_1 & 15)];
      var81_1 = &(*(((unsigned int *) var0_1) + 8));
      var82_1 = *var81_1;
      *var81_1 = Sbox_1[(long) ((int) (var82_1 >> ((unsigned int) 4)))][(unsigned long) (var82_1 & 15)];
      var83_1 = &(*(((unsigned int *) var0_1) + 12));
      var84_1 = *var83_1;
      *var83_1 = Sbox_1[(long) ((int) (var84_1 >> ((unsigned int) 4)))][(unsigned long) (var84_1 & 15)];
      var85_1 = &(*(((unsigned int *) var0_1) + 16));
      var86_1 = *var85_1;
      *var85_1 = Sbox_1[(long) ((int) (var86_1 >> ((unsigned int) 4)))][(unsigned long) (var86_1 & 15)];
      var87_1 = &(*(((unsigned int *) var0_1) + 20));
      var156_phi_1 = var87_1;
      goto block4_1;

    case 8:
      var88_1 = &(*(((unsigned int *) var0_1) + 1));
      var89_1 = *var88_1;
      var90_1 = Sbox_1[(long) ((int) (var89_1 >> ((unsigned int) 4)))][(unsigned long) (var89_1 & 15)];
      var91_1 = &(*(((unsigned int *) var0_1) + 5));
      var92_1 = *var91_1;
      *var88_1 = Sbox_1[(long) ((int) (var92_1 >> ((unsigned int) 4)))][(unsigned long) (var92_1 & 15)];
      var93_1 = &(*(((unsigned int *) var0_1) + 9));
      var94_1 = *var93_1;
      *var91_1 = Sbox_1[(long) ((int) (var94_1 >> ((unsigned int) 4)))][(unsigned long) (var94_1 & 15)];
      var95_1 = &(*(((unsigned int *) var0_1) + 13));
      var96_1 = *var95_1;
      *var93_1 = Sbox_1[(long) ((int) (var96_1 >> ((unsigned int) 4)))][(unsigned long) (var96_1 & 15)];
      var97_1 = &(*(((unsigned int *) var0_1) + 17));
      var98_1 = *var97_1;
      *var95_1 = Sbox_1[(long) ((int) (var98_1 >> ((unsigned int) 4)))][(unsigned long) (var98_1 & 15)];
      var99_1 = &(*(((unsigned int *) var0_1) + 21));
      var100_1 = *var99_1;
      *var97_1 = Sbox_1[(long) ((int) (var100_1 >> ((unsigned int) 4)))][(unsigned long) (var100_1 & 15)];
      var101_1 = &(*(((unsigned int *) var0_1) + 25));
      var102_1 = *var101_1;
      *var99_1 = Sbox_1[(long) ((int) (var102_1 >> ((unsigned int) 4)))][(unsigned long) (var102_1 & 15)];
      var103_1 = &(*(((unsigned int *) var0_1) + 29));
      var104_1 = *var103_1;
      *var101_1 = Sbox_1[(long) ((int) (var104_1 >> ((unsigned int) 4)))][(unsigned long) (var104_1 & 15)];
      *var103_1 = var90_1;
      var105_1 = &(*(((unsigned int *) var0_1) + 2));
      var106_1 = *var105_1;
      var107_1 = Sbox_1[(long) ((int) (var106_1 >> ((unsigned int) 4)))][(unsigned long) (var106_1 & 15)];
      var108_1 = &(*(((unsigned int *) var0_1) + 14));
      var109_1 = *var108_1;
      *var105_1 = Sbox_1[(long) ((int) (var109_1 >> ((unsigned int) 4)))][(unsigned long) (var109_1 & 15)];
      var110_1 = &(*(((unsigned int *) var0_1) + 26));
      var111_1 = *var110_1;
      *var108_1 = Sbox_1[(long) ((int) (var111_1 >> ((unsigned int) 4)))][(unsigned long) (var111_1 & 15)];
      var112_1 = &(*(((unsigned int *) var0_1) + 6));
      var113_1 = *var112_1;
      *var110_1 = Sbox_1[(long) ((int) (var113_1 >> ((unsigned int) 4)))][(unsigned long) (var113_1 & 15)];
      var114_1 = &(*(((unsigned int *) var0_1) + 18));
      var115_1 = *var114_1;
      *var112_1 = Sbox_1[(long) ((int) (var115_1 >> ((unsigned int) 4)))][(unsigned long) (var115_1 & 15)];
      var116_1 = &(*(((unsigned int *) var0_1) + 30));
      var117_1 = *var116_1;
      *var114_1 = Sbox_1[(long) ((int) (var117_1 >> ((unsigned int) 4)))][(unsigned long) (var117_1 & 15)];
      var118_1 = &(*(((unsigned int *) var0_1) + 10));
      var119_1 = *var118_1;
      *var116_1 = Sbox_1[(long) ((int) (var119_1 >> ((unsigned int) 4)))][(unsigned long) (var119_1 & 15)];
      var120_1 = &(*(((unsigned int *) var0_1) + 22));
      var121_1 = *var120_1;
      *var118_1 = Sbox_1[(long) ((int) (var121_1 >> ((unsigned int) 4)))][(unsigned long) (var121_1 & 15)];
      *var120_1 = var107_1;
      var122_1 = &(*(((unsigned int *) var0_1) + 3));
      var123_1 = *var122_1;
      var124_1 = Sbox_1[(long) ((int) (var123_1 >> ((unsigned int) 4)))][(unsigned long) (var123_1 & 15)];
      var125_1 = &(*(((unsigned int *) var0_1) + 19));
      var126_1 = *var125_1;
      *var122_1 = Sbox_1[(long) ((int) (var126_1 >> ((unsigned int) 4)))][(unsigned long) (var126_1 & 15)];
      *var125_1 = var124_1;
      var127_1 = &(*(((unsigned int *) var0_1) + 7));
      var128_1 = *var127_1;
      var129_1 = Sbox_1[(long) ((int) (var128_1 >> ((unsigned int) 4)))][(unsigned long) (var128_1 & 15)];
      var130_1 = &(*(((unsigned int *) var0_1) + 23));
      var131_1 = *var130_1;
      *var127_1 = Sbox_1[(long) ((int) (var131_1 >> ((unsigned int) 4)))][(unsigned long) (var131_1 & 15)];
      *var130_1 = var129_1;
      var132_1 = &(*(((unsigned int *) var0_1) + 11));
      var133_1 = *var132_1;
      var134_1 = Sbox_1[(long) ((int) (var133_1 >> ((unsigned int) 4)))][(unsigned long) (var133_1 & 15)];
      var135_1 = &(*(((unsigned int *) var0_1) + 27));
      var136_1 = *var135_1;
      *var132_1 = Sbox_1[(long) ((int) (var136_1 >> ((unsigned int) 4)))][(unsigned long) (var136_1 & 15)];
      *var135_1 = var134_1;
      var137_1 = &(*(((unsigned int *) var0_1) + 15));
      var138_1 = *var137_1;
      var139_1 = Sbox_1[(long) ((int) (var138_1 >> ((unsigned int) 4)))][(unsigned long) (var138_1 & 15)];
      var140_1 = &(*(((unsigned int *) var0_1) + 31));
      var141_1 = *var140_1;
      *var137_1 = Sbox_1[(long) ((int) (var141_1 >> ((unsigned int) 4)))][(unsigned long) (var141_1 & 15)];
      *var140_1 = var139_1;
      var142_1 = *var0_1;
      *var0_1 = Sbox_1[(long) ((int) (var142_1 >> ((unsigned int) 4)))][(unsigned long) (var142_1 & 15)];
      var143_1 = &(*(((unsigned int *) var0_1) + 4));
      var144_1 = *var143_1;
      *var143_1 = Sbox_1[(long) ((int) (var144_1 >> ((unsigned int) 4)))][(unsigned long) (var144_1 & 15)];
      var145_1 = &(*(((unsigned int *) var0_1) + 8));
      var146_1 = *var145_1;
      *var145_1 = Sbox_1[(long) ((int) (var146_1 >> ((unsigned int) 4)))][(unsigned long) (var146_1 & 15)];
      var147_1 = &(*(((unsigned int *) var0_1) + 12));
      var148_1 = *var147_1;
      *var147_1 = Sbox_1[(long) ((int) (var148_1 >> ((unsigned int) 4)))][(unsigned long) (var148_1 & 15)];
      var149_1 = &(*(((unsigned int *) var0_1) + 16));
      var150_1 = *var149_1;
      *var149_1 = Sbox_1[(long) ((int) (var150_1 >> ((unsigned int) 4)))][(unsigned long) (var150_1 & 15)];
      var151_1 = &(*(((unsigned int *) var0_1) + 20));
      var152_1 = *var151_1;
      *var151_1 = Sbox_1[(long) ((int) (var152_1 >> ((unsigned int) 4)))][(unsigned long) (var152_1 & 15)];
      var153_1 = &(*(((unsigned int *) var0_1) + 24));
      var154_1 = *var153_1;
      *var153_1 = Sbox_1[(long) ((int) (var154_1 >> ((unsigned int) 4)))][(unsigned long) (var154_1 & 15)];
      var155_1 = &(*(((unsigned int *) var0_1) + 28));
      var156_phi_1 = var155_1;
      goto block4_1;

    default:
      return;

  }


  block0_2:
  switch (var1_2)
  {
    case 4:
      var2_2 = &(*(((unsigned int *) var0_2) + 1));
      var3_2 = *var2_2;
      var4_2 = Sbox_2[(long) ((int) (var3_2 >> ((unsigned int) 4)))][(unsigned long) (var3_2 & 15)];
      var5_2 = &(*(((unsigned int *) var0_2) + 5));
      var6_2 = *var5_2;
      *var2_2 = Sbox_2[(long) ((int) (var6_2 >> ((unsigned int) 4)))][(unsigned long) (var6_2 & 15)];
      var7_2 = &(*(((unsigned int *) var0_2) + 9));
      var8_2 = *var7_2;
      *var5_2 = Sbox_2[(long) ((int) (var8_2 >> ((unsigned int) 4)))][(unsigned long) (var8_2 & 15)];
      var9_2 = &(*(((unsigned int *) var0_2) + 13));
      var10_2 = *var9_2;
      *var7_2 = Sbox_2[(long) ((int) (var10_2 >> ((unsigned int) 4)))][(unsigned long) (var10_2 & 15)];
      *var9_2 = var4_2;
      var11_2 = &(*(((unsigned int *) var0_2) + 2));
      var12_2 = *var11_2;
      var13_2 = Sbox_2[(long) ((int) (var12_2 >> ((unsigned int) 4)))][(unsigned long) (var12_2 & 15)];
      var14_2 = &(*(((unsigned int *) var0_2) + 10));
      var15_2 = *var14_2;
      *var11_2 = Sbox_2[(long) ((int) (var15_2 >> ((unsigned int) 4)))][(unsigned long) (var15_2 & 15)];
      *var14_2 = var13_2;
      var16_2 = &(*(((unsigned int *) var0_2) + 6));
      var17_2 = *var16_2;
      var18_2 = Sbox_2[(long) ((int) (var17_2 >> ((unsigned int) 4)))][(unsigned long) (var17_2 & 15)];
      var19_2 = &(*(((unsigned int *) var0_2) + 14));
      var20_2 = *var19_2;
      *var16_2 = Sbox_2[(long) ((int) (var20_2 >> ((unsigned int) 4)))][(unsigned long) (var20_2 & 15)];
      *var19_2 = var18_2;
      var21_2 = &(*(((unsigned int *) var0_2) + 3));
      var22_2 = *var21_2;
      var23_2 = Sbox_2[(long) ((int) (var22_2 >> ((unsigned int) 4)))][(unsigned long) (var22_2 & 15)];
      var24_2 = &(*(((unsigned int *) var0_2) + 15));
      var25_2 = *var24_2;
      *var21_2 = Sbox_2[(long) ((int) (var25_2 >> ((unsigned int) 4)))][(unsigned long) (var25_2 & 15)];
      var26_2 = &(*(((unsigned int *) var0_2) + 11));
      var27_2 = *var26_2;
      *var24_2 = Sbox_2[(long) ((int) (var27_2 >> ((unsigned int) 4)))][(unsigned long) (var27_2 & 15)];
      var28_2 = &(*(((unsigned int *) var0_2) + 7));
      var29_2 = *var28_2;
      *var26_2 = Sbox_2[(long) ((int) (var29_2 >> ((unsigned int) 4)))][(unsigned long) (var29_2 & 15)];
      *var28_2 = var23_2;
      var30_2 = *var0_2;
      *var0_2 = Sbox_2[(long) ((int) (var30_2 >> ((unsigned int) 4)))][(unsigned long) (var30_2 & 15)];
      var31_2 = &(*(((unsigned int *) var0_2) + 4));
      var32_2 = *var31_2;
      *var31_2 = Sbox_2[(long) ((int) (var32_2 >> ((unsigned int) 4)))][(unsigned long) (var32_2 & 15)];
      var33_2 = &(*(((unsigned int *) var0_2) + 8));
      var34_2 = *var33_2;
      *var33_2 = Sbox_2[(long) ((int) (var34_2 >> ((unsigned int) 4)))][(unsigned long) (var34_2 & 15)];
      var35_2 = &(*(((unsigned int *) var0_2) + 12));
      var156_phi_2 = var35_2;
      goto block4_2;

    case 6:
      var36_2 = &(*(((unsigned int *) var0_2) + 1));
      var37_2 = *var36_2;
      var38_2 = Sbox_2[(long) ((int) (var37_2 >> ((unsigned int) 4)))][(unsigned long) (var37_2 & 15)];
      var39_2 = &(*(((unsigned int *) var0_2) + 5));
      var40_2 = *var39_2;
      *var36_2 = Sbox_2[(long) ((int) (var40_2 >> ((unsigned int) 4)))][(unsigned long) (var40_2 & 15)];
      var41_2 = &(*(((unsigned int *) var0_2) + 9));
      var42_2 = *var41_2;
      *var39_2 = Sbox_2[(long) ((int) (var42_2 >> ((unsigned int) 4)))][(unsigned long) (var42_2 & 15)];
      var43_2 = &(*(((unsigned int *) var0_2) + 13));
      var44_2 = *var43_2;
      *var41_2 = Sbox_2[(long) ((int) (var44_2 >> ((unsigned int) 4)))][(unsigned long) (var44_2 & 15)];
      var45_2 = &(*(((unsigned int *) var0_2) + 17));
      var46_2 = *var45_2;
      *var43_2 = Sbox_2[(long) ((int) (var46_2 >> ((unsigned int) 4)))][(unsigned long) (var46_2 & 15)];
      var47_2 = &(*(((unsigned int *) var0_2) + 21));
      var48_2 = *var47_2;
      *var45_2 = Sbox_2[(long) ((int) (var48_2 >> ((unsigned int) 4)))][(unsigned long) (var48_2 & 15)];
      *var47_2 = var38_2;
      var49_2 = &(*(((unsigned int *) var0_2) + 2));
      var50_2 = *var49_2;
      var51_2 = Sbox_2[(long) ((int) (var50_2 >> ((unsigned int) 4)))][(unsigned long) (var50_2 & 15)];
      var52_2 = &(*(((unsigned int *) var0_2) + 10));
      var53_2 = *var52_2;
      *var49_2 = Sbox_2[(long) ((int) (var53_2 >> ((unsigned int) 4)))][(unsigned long) (var53_2 & 15)];
      var54_2 = &(*(((unsigned int *) var0_2) + 18));
      var55_2 = *var54_2;
      *var52_2 = Sbox_2[(long) ((int) (var55_2 >> ((unsigned int) 4)))][(unsigned long) (var55_2 & 15)];
      *var54_2 = var51_2;
      var56_2 = &(*(((unsigned int *) var0_2) + 6));
      var57_2 = *var56_2;
      var58_2 = Sbox_2[(long) ((int) (var57_2 >> ((unsigned int) 4)))][(unsigned long) (var57_2 & 15)];
      var59_2 = &(*(((unsigned int *) var0_2) + 14));
      var60_2 = *var59_2;
      *var56_2 = Sbox_2[(long) ((int) (var60_2 >> ((unsigned int) 4)))][(unsigned long) (var60_2 & 15)];
      var61_2 = &(*(((unsigned int *) var0_2) + 22));
      var62_2 = *var61_2;
      *var59_2 = Sbox_2[(long) ((int) (var62_2 >> ((unsigned int) 4)))][(unsigned long) (var62_2 & 15)];
      *var61_2 = var58_2;
      var63_2 = &(*(((unsigned int *) var0_2) + 3));
      var64_2 = *var63_2;
      var65_2 = Sbox_2[(long) ((int) (var64_2 >> ((unsigned int) 4)))][(unsigned long) (var64_2 & 15)];
      var66_2 = &(*(((unsigned int *) var0_2) + 15));
      var67_2 = *var66_2;
      *var63_2 = Sbox_2[(long) ((int) (var67_2 >> ((unsigned int) 4)))][(unsigned long) (var67_2 & 15)];
      *var66_2 = var65_2;
      var68_2 = &(*(((unsigned int *) var0_2) + 7));
      var69_2 = *var68_2;
      var70_2 = Sbox_2[(long) ((int) (var69_2 >> ((unsigned int) 4)))][(unsigned long) (var69_2 & 15)];
      var71_2 = &(*(((unsigned int *) var0_2) + 19));
      var72_2 = *var71_2;
      *var68_2 = Sbox_2[(long) ((int) (var72_2 >> ((unsigned int) 4)))][(unsigned long) (var72_2 & 15)];
      *var71_2 = var70_2;
      var73_2 = &(*(((unsigned int *) var0_2) + 11));
      var74_2 = *var73_2;
      var75_2 = Sbox_2[(long) ((int) (var74_2 >> ((unsigned int) 4)))][(unsigned long) (var74_2 & 15)];
      var76_2 = &(*(((unsigned int *) var0_2) + 23));
      var77_2 = *var76_2;
      *var73_2 = Sbox_2[(long) ((int) (var77_2 >> ((unsigned int) 4)))][(unsigned long) (var77_2 & 15)];
      *var76_2 = var75_2;
      var78_2 = *var0_2;
      *var0_2 = Sbox_2[(long) ((int) (var78_2 >> ((unsigned int) 4)))][(unsigned long) (var78_2 & 15)];
      var79_2 = &(*(((unsigned int *) var0_2) + 4));
      var80_2 = *var79_2;
      *var79_2 = Sbox_2[(long) ((int) (var80_2 >> ((unsigned int) 4)))][(unsigned long) (var80_2 & 15)];
      var81_2 = &(*(((unsigned int *) var0_2) + 8));
      var82_2 = *var81_2;
      *var81_2 = Sbox_2[(long) ((int) (var82_2 >> ((unsigned int) 4)))][(unsigned long) (var82_2 & 15)];
      var83_2 = &(*(((unsigned int *) var0_2) + 12));
      var84_2 = *var83_2;
      *var83_2 = Sbox_2[(long) ((int) (var84_2 >> ((unsigned int) 4)))][(unsigned long) (var84_2 & 15)];
      var85_2 = &(*(((unsigned int *) var0_2) + 16));
      var86_2 = *var85_2;
      *var85_2 = Sbox_2[(long) ((int) (var86_2 >> ((unsigned int) 4)))][(unsigned long) (var86_2 & 15)];
      var87_2 = &(*(((unsigned int *) var0_2) + 20));
      var156_phi_2 = var87_2;
      goto block4_2;

    case 8:
      var88_2 = &(*(((unsigned int *) var0_2) + 1));
      var89_2 = *var88_2;
      var90_2 = Sbox_2[(long) ((int) (var89_2 >> ((unsigned int) 4)))][(unsigned long) (var89_2 & 15)];
      var91_2 = &(*(((unsigned int *) var0_2) + 5));
      var92_2 = *var91_2;
      *var88_2 = Sbox_2[(long) ((int) (var92_2 >> ((unsigned int) 4)))][(unsigned long) (var92_2 & 15)];
      var93_2 = &(*(((unsigned int *) var0_2) + 9));
      var94_2 = *var93_2;
      *var91_2 = Sbox_2[(long) ((int) (var94_2 >> ((unsigned int) 4)))][(unsigned long) (var94_2 & 15)];
      var95_2 = &(*(((unsigned int *) var0_2) + 13));
      var96_2 = *var95_2;
      *var93_2 = Sbox_2[(long) ((int) (var96_2 >> ((unsigned int) 4)))][(unsigned long) (var96_2 & 15)];
      var97_2 = &(*(((unsigned int *) var0_2) + 17));
      var98_2 = *var97_2;
      *var95_2 = Sbox_2[(long) ((int) (var98_2 >> ((unsigned int) 4)))][(unsigned long) (var98_2 & 15)];
      var99_2 = &(*(((unsigned int *) var0_2) + 21));
      var100_2 = *var99_2;
      *var97_2 = Sbox_2[(long) ((int) (var100_2 >> ((unsigned int) 4)))][(unsigned long) (var100_2 & 15)];
      var101_2 = &(*(((unsigned int *) var0_2) + 25));
      var102_2 = *var101_2;
      *var99_2 = Sbox_2[(long) ((int) (var102_2 >> ((unsigned int) 4)))][(unsigned long) (var102_2 & 15)];
      var103_2 = &(*(((unsigned int *) var0_2) + 29));
      var104_2 = *var103_2;
      *var101_2 = Sbox_2[(long) ((int) (var104_2 >> ((unsigned int) 4)))][(unsigned long) (var104_2 & 15)];
      *var103_2 = var90_2;
      var105_2 = &(*(((unsigned int *) var0_2) + 2));
      var106_2 = *var105_2;
      var107_2 = Sbox_2[(long) ((int) (var106_2 >> ((unsigned int) 4)))][(unsigned long) (var106_2 & 15)];
      var108_2 = &(*(((unsigned int *) var0_2) + 14));
      var109_2 = *var108_2;
      *var105_2 = Sbox_2[(long) ((int) (var109_2 >> ((unsigned int) 4)))][(unsigned long) (var109_2 & 15)];
      var110_2 = &(*(((unsigned int *) var0_2) + 26));
      var111_2 = *var110_2;
      *var108_2 = Sbox_2[(long) ((int) (var111_2 >> ((unsigned int) 4)))][(unsigned long) (var111_2 & 15)];
      var112_2 = &(*(((unsigned int *) var0_2) + 6));
      var113_2 = *var112_2;
      *var110_2 = Sbox_2[(long) ((int) (var113_2 >> ((unsigned int) 4)))][(unsigned long) (var113_2 & 15)];
      var114_2 = &(*(((unsigned int *) var0_2) + 18));
      var115_2 = *var114_2;
      *var112_2 = Sbox_2[(long) ((int) (var115_2 >> ((unsigned int) 4)))][(unsigned long) (var115_2 & 15)];
      var116_2 = &(*(((unsigned int *) var0_2) + 30));
      var117_2 = *var116_2;
      *var114_2 = Sbox_2[(long) ((int) (var117_2 >> ((unsigned int) 4)))][(unsigned long) (var117_2 & 15)];
      var118_2 = &(*(((unsigned int *) var0_2) + 10));
      var119_2 = *var118_2;
      *var116_2 = Sbox_2[(long) ((int) (var119_2 >> ((unsigned int) 4)))][(unsigned long) (var119_2 & 15)];
      var120_2 = &(*(((unsigned int *) var0_2) + 22));
      var121_2 = *var120_2;
      *var118_2 = Sbox_2[(long) ((int) (var121_2 >> ((unsigned int) 4)))][(unsigned long) (var121_2 & 15)];
      *var120_2 = var107_2;
      var122_2 = &(*(((unsigned int *) var0_2) + 3));
      var123_2 = *var122_2;
      var124_2 = Sbox_2[(long) ((int) (var123_2 >> ((unsigned int) 4)))][(unsigned long) (var123_2 & 15)];
      var125_2 = &(*(((unsigned int *) var0_2) + 19));
      var126_2 = *var125_2;
      *var122_2 = Sbox_2[(long) ((int) (var126_2 >> ((unsigned int) 4)))][(unsigned long) (var126_2 & 15)];
      *var125_2 = var124_2;
      var127_2 = &(*(((unsigned int *) var0_2) + 7));
      var128_2 = *var127_2;
      var129_2 = Sbox_2[(long) ((int) (var128_2 >> ((unsigned int) 4)))][(unsigned long) (var128_2 & 15)];
      var130_2 = &(*(((unsigned int *) var0_2) + 23));
      var131_2 = *var130_2;
      *var127_2 = Sbox_2[(long) ((int) (var131_2 >> ((unsigned int) 4)))][(unsigned long) (var131_2 & 15)];
      *var130_2 = var129_2;
      var132_2 = &(*(((unsigned int *) var0_2) + 11));
      var133_2 = *var132_2;
      var134_2 = Sbox_2[(long) ((int) (var133_2 >> ((unsigned int) 4)))][(unsigned long) (var133_2 & 15)];
      var135_2 = &(*(((unsigned int *) var0_2) + 27));
      var136_2 = *var135_2;
      *var132_2 = Sbox_2[(long) ((int) (var136_2 >> ((unsigned int) 4)))][(unsigned long) (var136_2 & 15)];
      *var135_2 = var134_2;
      var137_2 = &(*(((unsigned int *) var0_2) + 15));
      var138_2 = *var137_2;
      var139_2 = Sbox_2[(long) ((int) (var138_2 >> ((unsigned int) 4)))][(unsigned long) (var138_2 & 15)];
      var140_2 = &(*(((unsigned int *) var0_2) + 31));
      var141_2 = *var140_2;
      *var137_2 = Sbox_2[(long) ((int) (var141_2 >> ((unsigned int) 4)))][(unsigned long) (var141_2 & 15)];
      *var140_2 = var139_2;
      var142_2 = *var0_2;
      *var0_2 = Sbox_2[(long) ((int) (var142_2 >> ((unsigned int) 4)))][(unsigned long) (var142_2 & 15)];
      var143_2 = &(*(((unsigned int *) var0_2) + 4));
      var144_2 = *var143_2;
      *var143_2 = Sbox_2[(long) ((int) (var144_2 >> ((unsigned int) 4)))][(unsigned long) (var144_2 & 15)];
      var145_2 = &(*(((unsigned int *) var0_2) + 8));
      var146_2 = *var145_2;
      *var145_2 = Sbox_2[(long) ((int) (var146_2 >> ((unsigned int) 4)))][(unsigned long) (var146_2 & 15)];
      var147_2 = &(*(((unsigned int *) var0_2) + 12));
      var148_2 = *var147_2;
      *var147_2 = Sbox_2[(long) ((int) (var148_2 >> ((unsigned int) 4)))][(unsigned long) (var148_2 & 15)];
      var149_2 = &(*(((unsigned int *) var0_2) + 16));
      var150_2 = *var149_2;
      *var149_2 = Sbox_2[(long) ((int) (var150_2 >> ((unsigned int) 4)))][(unsigned long) (var150_2 & 15)];
      var151_2 = &(*(((unsigned int *) var0_2) + 20));
      var152_2 = *var151_2;
      *var151_2 = Sbox_2[(long) ((int) (var152_2 >> ((unsigned int) 4)))][(unsigned long) (var152_2 & 15)];
      var153_2 = &(*(((unsigned int *) var0_2) + 24));
      var154_2 = *var153_2;
      *var153_2 = Sbox_2[(long) ((int) (var154_2 >> ((unsigned int) 4)))][(unsigned long) (var154_2 & 15)];
      var155_2 = &(*(((unsigned int *) var0_2) + 28));
      var156_phi_2 = var155_2;
      goto block4_2;

    default:
      return;

  }


  block4_1:
  var157_1 = *var156_phi_1;

  block4_2:
  var157_2 = *var156_phi_2;

  *var156_phi_1 = Sbox_1[(long) ((int) (var157_1 >> ((unsigned int) 4)))][(unsigned long) (var157_1 & 15)];
  *var156_phi_2 = Sbox_2[(long) ((int) (var157_2 >> ((unsigned int) 4)))][(unsigned long) (var157_2 & 15)];
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    for (int i_1 = 0; i_1 < 16; i_1++)
    {
      assert(Sbox_1[i_0][i_1] == Sbox_2[i_0][i_1]);
    }

  }

  assert((*var156_phi_1) == (*var156_phi_2));
  assert((*var2_1) == (*var2_2));
  assert(var3_1 == var3_2);
  assert(var4_1 == var4_2);
  assert((*var5_1) == (*var5_2));
  assert(var6_1 == var6_2);
  assert((*var7_1) == (*var7_2));
  assert(var8_1 == var8_2);
  assert((*var9_1) == (*var9_2));
  assert(var10_1 == var10_2);
  assert((*var11_1) == (*var11_2));
  assert(var12_1 == var12_2);
  assert(var13_1 == var13_2);
  assert((*var14_1) == (*var14_2));
  assert(var15_1 == var15_2);
  assert((*var16_1) == (*var16_2));
  assert(var17_1 == var17_2);
  assert(var18_1 == var18_2);
  assert((*var19_1) == (*var19_2));
  assert(var20_1 == var20_2);
  assert((*var21_1) == (*var21_2));
  assert(var22_1 == var22_2);
  assert(var23_1 == var23_2);
  assert((*var24_1) == (*var24_2));
  assert(var25_1 == var25_2);
  assert((*var26_1) == (*var26_2));
  assert(var27_1 == var27_2);
  assert((*var28_1) == (*var28_2));
  assert(var29_1 == var29_2);
  assert(var30_1 == var30_2);
  assert((*var31_1) == (*var31_2));
  assert(var32_1 == var32_2);
  assert((*var33_1) == (*var33_2));
  assert(var34_1 == var34_2);
  assert((*var35_1) == (*var35_2));
  assert((*var36_1) == (*var36_2));
  assert(var37_1 == var37_2);
  assert(var38_1 == var38_2);
  assert((*var39_1) == (*var39_2));
  assert(var40_1 == var40_2);
  assert((*var41_1) == (*var41_2));
  assert(var42_1 == var42_2);
  assert((*var43_1) == (*var43_2));
  assert(var44_1 == var44_2);
  assert((*var45_1) == (*var45_2));
  assert(var46_1 == var46_2);
  assert((*var47_1) == (*var47_2));
  assert(var48_1 == var48_2);
  assert((*var49_1) == (*var49_2));
  assert(var50_1 == var50_2);
  assert(var51_1 == var51_2);
  assert((*var52_1) == (*var52_2));
  assert(var53_1 == var53_2);
  assert((*var54_1) == (*var54_2));
  assert(var55_1 == var55_2);
  assert((*var56_1) == (*var56_2));
  assert(var57_1 == var57_2);
  assert(var58_1 == var58_2);
  assert((*var59_1) == (*var59_2));
  assert(var60_1 == var60_2);
  assert((*var61_1) == (*var61_2));
  assert(var62_1 == var62_2);
  assert((*var63_1) == (*var63_2));
  assert(var64_1 == var64_2);
  assert(var65_1 == var65_2);
  assert((*var66_1) == (*var66_2));
  assert(var67_1 == var67_2);
  assert((*var68_1) == (*var68_2));
  assert(var69_1 == var69_2);
  assert(var70_1 == var70_2);
  assert((*var71_1) == (*var71_2));
  assert(var72_1 == var72_2);
  assert((*var73_1) == (*var73_2));
  assert(var74_1 == var74_2);
  assert(var75_1 == var75_2);
  assert((*var76_1) == (*var76_2));
  assert(var77_1 == var77_2);
  assert(var78_1 == var78_2);
  assert((*var79_1) == (*var79_2));
  assert(var80_1 == var80_2);
  assert((*var81_1) == (*var81_2));
  assert(var82_1 == var82_2);
  assert((*var83_1) == (*var83_2));
  assert(var84_1 == var84_2);
  assert((*var85_1) == (*var85_2));
  assert(var86_1 == var86_2);
  assert((*var87_1) == (*var87_2));
  assert((*var88_1) == (*var88_2));
  assert(var89_1 == var89_2);
  assert(var90_1 == var90_2);
  assert((*var91_1) == (*var91_2));
  assert(var92_1 == var92_2);
  assert((*var93_1) == (*var93_2));
  assert(var94_1 == var94_2);
  assert((*var95_1) == (*var95_2));
  assert(var96_1 == var96_2);
  assert((*var97_1) == (*var97_2));
  assert(var98_1 == var98_2);
  assert((*var99_1) == (*var99_2));
  assert(var100_1 == var100_2);
  assert((*var101_1) == (*var101_2));
  assert(var102_1 == var102_2);
  assert((*var103_1) == (*var103_2));
  assert(var104_1 == var104_2);
  assert((*var105_1) == (*var105_2));
  assert(var106_1 == var106_2);
  assert(var107_1 == var107_2);
  assert((*var108_1) == (*var108_2));
  assert(var109_1 == var109_2);
  assert((*var110_1) == (*var110_2));
  assert(var111_1 == var111_2);
  assert((*var112_1) == (*var112_2));
  assert(var113_1 == var113_2);
  assert((*var114_1) == (*var114_2));
  assert(var115_1 == var115_2);
  assert((*var116_1) == (*var116_2));
  assert(var117_1 == var117_2);
  assert((*var118_1) == (*var118_2));
  assert(var119_1 == var119_2);
  assert((*var120_1) == (*var120_2));
  assert(var121_1 == var121_2);
  assert((*var122_1) == (*var122_2));
  assert(var123_1 == var123_2);
  assert(var124_1 == var124_2);
  assert((*var125_1) == (*var125_2));
  assert(var126_1 == var126_2);
  assert((*var127_1) == (*var127_2));
  assert(var128_1 == var128_2);
  assert(var129_1 == var129_2);
  assert((*var130_1) == (*var130_2));
  assert(var131_1 == var131_2);
  assert((*var132_1) == (*var132_2));
  assert(var133_1 == var133_2);
  assert(var134_1 == var134_2);
  assert((*var135_1) == (*var135_2));
  assert(var136_1 == var136_2);
  assert((*var137_1) == (*var137_2));
  assert(var138_1 == var138_2);
  assert(var139_1 == var139_2);
  assert((*var140_1) == (*var140_2));
  assert(var141_1 == var141_2);
  assert(var142_1 == var142_2);
  assert((*var143_1) == (*var143_2));
  assert(var144_1 == var144_2);
  assert((*var145_1) == (*var145_2));
  assert(var146_1 == var146_2);
  assert((*var147_1) == (*var147_2));
  assert(var148_1 == var148_2);
  assert((*var149_1) == (*var149_2));
  assert(var150_1 == var150_2);
  assert((*var151_1) == (*var151_2));
  assert(var152_1 == var152_2);
  assert((*var153_1) == (*var153_2));
  assert(var154_1 == var154_2);
  assert((*var155_1) == (*var155_2));
  assert(var157_1 == var157_2);
}

void ByteSub_ShiftRow(unsigned int *var0, unsigned int var1)
{
  unsigned int *var156_phi;
  unsigned int *var2;
  unsigned int var3;
  unsigned int var4;
  unsigned int *var5;
  unsigned int var6;
  unsigned int *var7;
  unsigned int var8;
  unsigned int *var9;
  unsigned int var10;
  unsigned int *var11;
  unsigned int var12;
  unsigned int var13;
  unsigned int *var14;
  unsigned int var15;
  unsigned int *var16;
  unsigned int var17;
  unsigned int var18;
  unsigned int *var19;
  unsigned int var20;
  unsigned int *var21;
  unsigned int var22;
  unsigned int var23;
  unsigned int *var24;
  unsigned int var25;
  unsigned int *var26;
  unsigned int var27;
  unsigned int *var28;
  unsigned int var29;
  unsigned int var30;
  unsigned int *var31;
  unsigned int var32;
  unsigned int *var33;
  unsigned int var34;
  unsigned int *var35;
  unsigned int *var36;
  unsigned int var37;
  unsigned int var38;
  unsigned int *var39;
  unsigned int var40;
  unsigned int *var41;
  unsigned int var42;
  unsigned int *var43;
  unsigned int var44;
  unsigned int *var45;
  unsigned int var46;
  unsigned int *var47;
  unsigned int var48;
  unsigned int *var49;
  unsigned int var50;
  unsigned int var51;
  unsigned int *var52;
  unsigned int var53;
  unsigned int *var54;
  unsigned int var55;
  unsigned int *var56;
  unsigned int var57;
  unsigned int var58;
  unsigned int *var59;
  unsigned int var60;
  unsigned int *var61;
  unsigned int var62;
  unsigned int *var63;
  unsigned int var64;
  unsigned int var65;
  unsigned int *var66;
  unsigned int var67;
  unsigned int *var68;
  unsigned int var69;
  unsigned int var70;
  unsigned int *var71;
  unsigned int var72;
  unsigned int *var73;
  unsigned int var74;
  unsigned int var75;
  unsigned int *var76;
  unsigned int var77;
  unsigned int var78;
  unsigned int *var79;
  unsigned int var80;
  unsigned int *var81;
  unsigned int var82;
  unsigned int *var83;
  unsigned int var84;
  unsigned int *var85;
  unsigned int var86;
  unsigned int *var87;
  unsigned int *var88;
  unsigned int var89;
  unsigned int var90;
  unsigned int *var91;
  unsigned int var92;
  unsigned int *var93;
  unsigned int var94;
  unsigned int *var95;
  unsigned int var96;
  unsigned int *var97;
  unsigned int var98;
  unsigned int *var99;
  unsigned int var100;
  unsigned int *var101;
  unsigned int var102;
  unsigned int *var103;
  unsigned int var104;
  unsigned int *var105;
  unsigned int var106;
  unsigned int var107;
  unsigned int *var108;
  unsigned int var109;
  unsigned int *var110;
  unsigned int var111;
  unsigned int *var112;
  unsigned int var113;
  unsigned int *var114;
  unsigned int var115;
  unsigned int *var116;
  unsigned int var117;
  unsigned int *var118;
  unsigned int var119;
  unsigned int *var120;
  unsigned int var121;
  unsigned int *var122;
  unsigned int var123;
  unsigned int var124;
  unsigned int *var125;
  unsigned int var126;
  unsigned int *var127;
  unsigned int var128;
  unsigned int var129;
  unsigned int *var130;
  unsigned int var131;
  unsigned int *var132;
  unsigned int var133;
  unsigned int var134;
  unsigned int *var135;
  unsigned int var136;
  unsigned int *var137;
  unsigned int var138;
  unsigned int var139;
  unsigned int *var140;
  unsigned int var141;
  unsigned int var142;
  unsigned int *var143;
  unsigned int var144;
  unsigned int *var145;
  unsigned int var146;
  unsigned int *var147;
  unsigned int var148;
  unsigned int *var149;
  unsigned int var150;
  unsigned int *var151;
  unsigned int var152;
  unsigned int *var153;
  unsigned int var154;
  unsigned int *var155;
  unsigned int var157;
  block0:
  switch (var1)
  {
    case 4:
      var2 = &(*(((unsigned int *) var0) + 1));
      var3 = *var2;
      var4 = Sbox[(long) ((int) (var3 >> ((unsigned int) 4)))][(unsigned long) (var3 & 15)];
      var5 = &(*(((unsigned int *) var0) + 5));
      var6 = *var5;
      *var2 = Sbox[(long) ((int) (var6 >> ((unsigned int) 4)))][(unsigned long) (var6 & 15)];
      var7 = &(*(((unsigned int *) var0) + 9));
      var8 = *var7;
      *var5 = Sbox[(long) ((int) (var8 >> ((unsigned int) 4)))][(unsigned long) (var8 & 15)];
      var9 = &(*(((unsigned int *) var0) + 13));
      var10 = *var9;
      *var7 = Sbox[(long) ((int) (var10 >> ((unsigned int) 4)))][(unsigned long) (var10 & 15)];
      *var9 = var4;
      var11 = &(*(((unsigned int *) var0) + 2));
      var12 = *var11;
      var13 = Sbox[(long) ((int) (var12 >> ((unsigned int) 4)))][(unsigned long) (var12 & 15)];
      var14 = &(*(((unsigned int *) var0) + 10));
      var15 = *var14;
      *var11 = Sbox[(long) ((int) (var15 >> ((unsigned int) 4)))][(unsigned long) (var15 & 15)];
      *var14 = var13;
      var16 = &(*(((unsigned int *) var0) + 6));
      var17 = *var16;
      var18 = Sbox[(long) ((int) (var17 >> ((unsigned int) 4)))][(unsigned long) (var17 & 15)];
      var19 = &(*(((unsigned int *) var0) + 14));
      var20 = *var19;
      *var16 = Sbox[(long) ((int) (var20 >> ((unsigned int) 4)))][(unsigned long) (var20 & 15)];
      *var19 = var18;
      var21 = &(*(((unsigned int *) var0) + 3));
      var22 = *var21;
      var23 = Sbox[(long) ((int) (var22 >> ((unsigned int) 4)))][(unsigned long) (var22 & 15)];
      var24 = &(*(((unsigned int *) var0) + 15));
      var25 = *var24;
      *var21 = Sbox[(long) ((int) (var25 >> ((unsigned int) 4)))][(unsigned long) (var25 & 15)];
      var26 = &(*(((unsigned int *) var0) + 11));
      var27 = *var26;
      *var24 = Sbox[(long) ((int) (var27 >> ((unsigned int) 4)))][(unsigned long) (var27 & 15)];
      var28 = &(*(((unsigned int *) var0) + 7));
      var29 = *var28;
      *var26 = Sbox[(long) ((int) (var29 >> ((unsigned int) 4)))][(unsigned long) (var29 & 15)];
      *var28 = var23;
      var30 = *var0;
      *var0 = Sbox[(long) ((int) (var30 >> ((unsigned int) 4)))][(unsigned long) (var30 & 15)];
      var31 = &(*(((unsigned int *) var0) + 4));
      var32 = *var31;
      *var31 = Sbox[(long) ((int) (var32 >> ((unsigned int) 4)))][(unsigned long) (var32 & 15)];
      var33 = &(*(((unsigned int *) var0) + 8));
      var34 = *var33;
      *var33 = Sbox[(long) ((int) (var34 >> ((unsigned int) 4)))][(unsigned long) (var34 & 15)];
      var35 = &(*(((unsigned int *) var0) + 12));
      var156_phi = var35;
      goto block4;

    case 6:
      var36 = &(*(((unsigned int *) var0) + 1));
      var37 = *var36;
      var38 = Sbox[(long) ((int) (var37 >> ((unsigned int) 4)))][(unsigned long) (var37 & 15)];
      var39 = &(*(((unsigned int *) var0) + 5));
      var40 = *var39;
      *var36 = Sbox[(long) ((int) (var40 >> ((unsigned int) 4)))][(unsigned long) (var40 & 15)];
      var41 = &(*(((unsigned int *) var0) + 9));
      var42 = *var41;
      *var39 = Sbox[(long) ((int) (var42 >> ((unsigned int) 4)))][(unsigned long) (var42 & 15)];
      var43 = &(*(((unsigned int *) var0) + 13));
      var44 = *var43;
      *var41 = Sbox[(long) ((int) (var44 >> ((unsigned int) 4)))][(unsigned long) (var44 & 15)];
      var45 = &(*(((unsigned int *) var0) + 17));
      var46 = *var45;
      *var43 = Sbox[(long) ((int) (var46 >> ((unsigned int) 4)))][(unsigned long) (var46 & 15)];
      var47 = &(*(((unsigned int *) var0) + 21));
      var48 = *var47;
      *var45 = Sbox[(long) ((int) (var48 >> ((unsigned int) 4)))][(unsigned long) (var48 & 15)];
      *var47 = var38;
      var49 = &(*(((unsigned int *) var0) + 2));
      var50 = *var49;
      var51 = Sbox[(long) ((int) (var50 >> ((unsigned int) 4)))][(unsigned long) (var50 & 15)];
      var52 = &(*(((unsigned int *) var0) + 10));
      var53 = *var52;
      *var49 = Sbox[(long) ((int) (var53 >> ((unsigned int) 4)))][(unsigned long) (var53 & 15)];
      var54 = &(*(((unsigned int *) var0) + 18));
      var55 = *var54;
      *var52 = Sbox[(long) ((int) (var55 >> ((unsigned int) 4)))][(unsigned long) (var55 & 15)];
      *var54 = var51;
      var56 = &(*(((unsigned int *) var0) + 6));
      var57 = *var56;
      var58 = Sbox[(long) ((int) (var57 >> ((unsigned int) 4)))][(unsigned long) (var57 & 15)];
      var59 = &(*(((unsigned int *) var0) + 14));
      var60 = *var59;
      *var56 = Sbox[(long) ((int) (var60 >> ((unsigned int) 4)))][(unsigned long) (var60 & 15)];
      var61 = &(*(((unsigned int *) var0) + 22));
      var62 = *var61;
      *var59 = Sbox[(long) ((int) (var62 >> ((unsigned int) 4)))][(unsigned long) (var62 & 15)];
      *var61 = var58;
      var63 = &(*(((unsigned int *) var0) + 3));
      var64 = *var63;
      var65 = Sbox[(long) ((int) (var64 >> ((unsigned int) 4)))][(unsigned long) (var64 & 15)];
      var66 = &(*(((unsigned int *) var0) + 15));
      var67 = *var66;
      *var63 = Sbox[(long) ((int) (var67 >> ((unsigned int) 4)))][(unsigned long) (var67 & 15)];
      *var66 = var65;
      var68 = &(*(((unsigned int *) var0) + 7));
      var69 = *var68;
      var70 = Sbox[(long) ((int) (var69 >> ((unsigned int) 4)))][(unsigned long) (var69 & 15)];
      var71 = &(*(((unsigned int *) var0) + 19));
      var72 = *var71;
      *var68 = Sbox[(long) ((int) (var72 >> ((unsigned int) 4)))][(unsigned long) (var72 & 15)];
      *var71 = var70;
      var73 = &(*(((unsigned int *) var0) + 11));
      var74 = *var73;
      var75 = Sbox[(long) ((int) (var74 >> ((unsigned int) 4)))][(unsigned long) (var74 & 15)];
      var76 = &(*(((unsigned int *) var0) + 23));
      var77 = *var76;
      *var73 = Sbox[(long) ((int) (var77 >> ((unsigned int) 4)))][(unsigned long) (var77 & 15)];
      *var76 = var75;
      var78 = *var0;
      *var0 = Sbox[(long) ((int) (var78 >> ((unsigned int) 4)))][(unsigned long) (var78 & 15)];
      var79 = &(*(((unsigned int *) var0) + 4));
      var80 = *var79;
      *var79 = Sbox[(long) ((int) (var80 >> ((unsigned int) 4)))][(unsigned long) (var80 & 15)];
      var81 = &(*(((unsigned int *) var0) + 8));
      var82 = *var81;
      *var81 = Sbox[(long) ((int) (var82 >> ((unsigned int) 4)))][(unsigned long) (var82 & 15)];
      var83 = &(*(((unsigned int *) var0) + 12));
      var84 = *var83;
      *var83 = Sbox[(long) ((int) (var84 >> ((unsigned int) 4)))][(unsigned long) (var84 & 15)];
      var85 = &(*(((unsigned int *) var0) + 16));
      var86 = *var85;
      *var85 = Sbox[(long) ((int) (var86 >> ((unsigned int) 4)))][(unsigned long) (var86 & 15)];
      var87 = &(*(((unsigned int *) var0) + 20));
      var156_phi = var87;
      goto block4;

    case 8:
      var88 = &(*(((unsigned int *) var0) + 1));
      var89 = *var88;
      var90 = Sbox[(long) ((int) (var89 >> ((unsigned int) 4)))][(unsigned long) (var89 & 15)];
      var91 = &(*(((unsigned int *) var0) + 5));
      var92 = *var91;
      *var88 = Sbox[(long) ((int) (var92 >> ((unsigned int) 4)))][(unsigned long) (var92 & 15)];
      var93 = &(*(((unsigned int *) var0) + 9));
      var94 = *var93;
      *var91 = Sbox[(long) ((int) (var94 >> ((unsigned int) 4)))][(unsigned long) (var94 & 15)];
      var95 = &(*(((unsigned int *) var0) + 13));
      var96 = *var95;
      *var93 = Sbox[(long) ((int) (var96 >> ((unsigned int) 4)))][(unsigned long) (var96 & 15)];
      var97 = &(*(((unsigned int *) var0) + 17));
      var98 = *var97;
      *var95 = Sbox[(long) ((int) (var98 >> ((unsigned int) 4)))][(unsigned long) (var98 & 15)];
      var99 = &(*(((unsigned int *) var0) + 21));
      var100 = *var99;
      *var97 = Sbox[(long) ((int) (var100 >> ((unsigned int) 4)))][(unsigned long) (var100 & 15)];
      var101 = &(*(((unsigned int *) var0) + 25));
      var102 = *var101;
      *var99 = Sbox[(long) ((int) (var102 >> ((unsigned int) 4)))][(unsigned long) (var102 & 15)];
      var103 = &(*(((unsigned int *) var0) + 29));
      var104 = *var103;
      *var101 = Sbox[(long) ((int) (var104 >> ((unsigned int) 4)))][(unsigned long) (var104 & 15)];
      *var103 = var90;
      var105 = &(*(((unsigned int *) var0) + 2));
      var106 = *var105;
      var107 = Sbox[(long) ((int) (var106 >> ((unsigned int) 4)))][(unsigned long) (var106 & 15)];
      var108 = &(*(((unsigned int *) var0) + 14));
      var109 = *var108;
      *var105 = Sbox[(long) ((int) (var109 >> ((unsigned int) 4)))][(unsigned long) (var109 & 15)];
      var110 = &(*(((unsigned int *) var0) + 26));
      var111 = *var110;
      *var108 = Sbox[(long) ((int) (var111 >> ((unsigned int) 4)))][(unsigned long) (var111 & 15)];
      var112 = &(*(((unsigned int *) var0) + 6));
      var113 = *var112;
      *var110 = Sbox[(long) ((int) (var113 >> ((unsigned int) 4)))][(unsigned long) (var113 & 15)];
      var114 = &(*(((unsigned int *) var0) + 18));
      var115 = *var114;
      *var112 = Sbox[(long) ((int) (var115 >> ((unsigned int) 4)))][(unsigned long) (var115 & 15)];
      var116 = &(*(((unsigned int *) var0) + 30));
      var117 = *var116;
      *var114 = Sbox[(long) ((int) (var117 >> ((unsigned int) 4)))][(unsigned long) (var117 & 15)];
      var118 = &(*(((unsigned int *) var0) + 10));
      var119 = *var118;
      *var116 = Sbox[(long) ((int) (var119 >> ((unsigned int) 4)))][(unsigned long) (var119 & 15)];
      var120 = &(*(((unsigned int *) var0) + 22));
      var121 = *var120;
      *var118 = Sbox[(long) ((int) (var121 >> ((unsigned int) 4)))][(unsigned long) (var121 & 15)];
      *var120 = var107;
      var122 = &(*(((unsigned int *) var0) + 3));
      var123 = *var122;
      var124 = Sbox[(long) ((int) (var123 >> ((unsigned int) 4)))][(unsigned long) (var123 & 15)];
      var125 = &(*(((unsigned int *) var0) + 19));
      var126 = *var125;
      *var122 = Sbox[(long) ((int) (var126 >> ((unsigned int) 4)))][(unsigned long) (var126 & 15)];
      *var125 = var124;
      var127 = &(*(((unsigned int *) var0) + 7));
      var128 = *var127;
      var129 = Sbox[(long) ((int) (var128 >> ((unsigned int) 4)))][(unsigned long) (var128 & 15)];
      var130 = &(*(((unsigned int *) var0) + 23));
      var131 = *var130;
      *var127 = Sbox[(long) ((int) (var131 >> ((unsigned int) 4)))][(unsigned long) (var131 & 15)];
      *var130 = var129;
      var132 = &(*(((unsigned int *) var0) + 11));
      var133 = *var132;
      var134 = Sbox[(long) ((int) (var133 >> ((unsigned int) 4)))][(unsigned long) (var133 & 15)];
      var135 = &(*(((unsigned int *) var0) + 27));
      var136 = *var135;
      *var132 = Sbox[(long) ((int) (var136 >> ((unsigned int) 4)))][(unsigned long) (var136 & 15)];
      *var135 = var134;
      var137 = &(*(((unsigned int *) var0) + 15));
      var138 = *var137;
      var139 = Sbox[(long) ((int) (var138 >> ((unsigned int) 4)))][(unsigned long) (var138 & 15)];
      var140 = &(*(((unsigned int *) var0) + 31));
      var141 = *var140;
      *var137 = Sbox[(long) ((int) (var141 >> ((unsigned int) 4)))][(unsigned long) (var141 & 15)];
      *var140 = var139;
      var142 = *var0;
      *var0 = Sbox[(long) ((int) (var142 >> ((unsigned int) 4)))][(unsigned long) (var142 & 15)];
      var143 = &(*(((unsigned int *) var0) + 4));
      var144 = *var143;
      *var143 = Sbox[(long) ((int) (var144 >> ((unsigned int) 4)))][(unsigned long) (var144 & 15)];
      var145 = &(*(((unsigned int *) var0) + 8));
      var146 = *var145;
      *var145 = Sbox[(long) ((int) (var146 >> ((unsigned int) 4)))][(unsigned long) (var146 & 15)];
      var147 = &(*(((unsigned int *) var0) + 12));
      var148 = *var147;
      *var147 = Sbox[(long) ((int) (var148 >> ((unsigned int) 4)))][(unsigned long) (var148 & 15)];
      var149 = &(*(((unsigned int *) var0) + 16));
      var150 = *var149;
      *var149 = Sbox[(long) ((int) (var150 >> ((unsigned int) 4)))][(unsigned long) (var150 & 15)];
      var151 = &(*(((unsigned int *) var0) + 20));
      var152 = *var151;
      *var151 = Sbox[(long) ((int) (var152 >> ((unsigned int) 4)))][(unsigned long) (var152 & 15)];
      var153 = &(*(((unsigned int *) var0) + 24));
      var154 = *var153;
      *var153 = Sbox[(long) ((int) (var154 >> ((unsigned int) 4)))][(unsigned long) (var154 & 15)];
      var155 = &(*(((unsigned int *) var0) + 28));
      var156_phi = var155;
      goto block4;

    default:
      return;

  }


  block4:
  var157 = *var156_phi;

  *var156_phi = Sbox[(long) ((int) (var157 >> ((unsigned int) 4)))][(unsigned long) (var157 & 15)];
  return;
}

void InversShiftRow_ByteSub_2(unsigned int *var0_1, unsigned int var1_1, unsigned int *var0_2, unsigned int var1_2)
{
  unsigned int *var156_phi_1;
  unsigned int *var156_phi_2;
  unsigned int *var2_1;
  unsigned int *var2_2;
  unsigned int var3_1;
  unsigned int var3_2;
  unsigned int var4_1;
  unsigned int var4_2;
  unsigned int *var5_1;
  unsigned int *var5_2;
  unsigned int var6_1;
  unsigned int var6_2;
  unsigned int *var7_1;
  unsigned int *var7_2;
  unsigned int var8_1;
  unsigned int var8_2;
  unsigned int *var9_1;
  unsigned int *var9_2;
  unsigned int var10_1;
  unsigned int var10_2;
  unsigned int *var11_1;
  unsigned int *var11_2;
  unsigned int var12_1;
  unsigned int var12_2;
  unsigned int var13_1;
  unsigned int var13_2;
  unsigned int *var14_1;
  unsigned int *var14_2;
  unsigned int var15_1;
  unsigned int var15_2;
  unsigned int *var16_1;
  unsigned int *var16_2;
  unsigned int var17_1;
  unsigned int var17_2;
  unsigned int var18_1;
  unsigned int var18_2;
  unsigned int *var19_1;
  unsigned int *var19_2;
  unsigned int var20_1;
  unsigned int var20_2;
  unsigned int *var21_1;
  unsigned int *var21_2;
  unsigned int var22_1;
  unsigned int var22_2;
  unsigned int var23_1;
  unsigned int var23_2;
  unsigned int *var24_1;
  unsigned int *var24_2;
  unsigned int var25_1;
  unsigned int var25_2;
  unsigned int *var26_1;
  unsigned int *var26_2;
  unsigned int var27_1;
  unsigned int var27_2;
  unsigned int *var28_1;
  unsigned int *var28_2;
  unsigned int var29_1;
  unsigned int var29_2;
  unsigned int var30_1;
  unsigned int var30_2;
  unsigned int *var31_1;
  unsigned int *var31_2;
  unsigned int var32_1;
  unsigned int var32_2;
  unsigned int *var33_1;
  unsigned int *var33_2;
  unsigned int var34_1;
  unsigned int var34_2;
  unsigned int *var35_1;
  unsigned int *var35_2;
  unsigned int *var36_1;
  unsigned int *var36_2;
  unsigned int var37_1;
  unsigned int var37_2;
  unsigned int var38_1;
  unsigned int var38_2;
  unsigned int *var39_1;
  unsigned int *var39_2;
  unsigned int var40_1;
  unsigned int var40_2;
  unsigned int *var41_1;
  unsigned int *var41_2;
  unsigned int var42_1;
  unsigned int var42_2;
  unsigned int *var43_1;
  unsigned int *var43_2;
  unsigned int var44_1;
  unsigned int var44_2;
  unsigned int *var45_1;
  unsigned int *var45_2;
  unsigned int var46_1;
  unsigned int var46_2;
  unsigned int *var47_1;
  unsigned int *var47_2;
  unsigned int var48_1;
  unsigned int var48_2;
  unsigned int *var49_1;
  unsigned int *var49_2;
  unsigned int var50_1;
  unsigned int var50_2;
  unsigned int var51_1;
  unsigned int var51_2;
  unsigned int *var52_1;
  unsigned int *var52_2;
  unsigned int var53_1;
  unsigned int var53_2;
  unsigned int *var54_1;
  unsigned int *var54_2;
  unsigned int var55_1;
  unsigned int var55_2;
  unsigned int *var56_1;
  unsigned int *var56_2;
  unsigned int var57_1;
  unsigned int var57_2;
  unsigned int var58_1;
  unsigned int var58_2;
  unsigned int *var59_1;
  unsigned int *var59_2;
  unsigned int var60_1;
  unsigned int var60_2;
  unsigned int *var61_1;
  unsigned int *var61_2;
  unsigned int var62_1;
  unsigned int var62_2;
  unsigned int *var63_1;
  unsigned int *var63_2;
  unsigned int var64_1;
  unsigned int var64_2;
  unsigned int var65_1;
  unsigned int var65_2;
  unsigned int *var66_1;
  unsigned int *var66_2;
  unsigned int var67_1;
  unsigned int var67_2;
  unsigned int *var68_1;
  unsigned int *var68_2;
  unsigned int var69_1;
  unsigned int var69_2;
  unsigned int var70_1;
  unsigned int var70_2;
  unsigned int *var71_1;
  unsigned int *var71_2;
  unsigned int var72_1;
  unsigned int var72_2;
  unsigned int *var73_1;
  unsigned int *var73_2;
  unsigned int var74_1;
  unsigned int var74_2;
  unsigned int var75_1;
  unsigned int var75_2;
  unsigned int *var76_1;
  unsigned int *var76_2;
  unsigned int var77_1;
  unsigned int var77_2;
  unsigned int var78_1;
  unsigned int var78_2;
  unsigned int *var79_1;
  unsigned int *var79_2;
  unsigned int var80_1;
  unsigned int var80_2;
  unsigned int *var81_1;
  unsigned int *var81_2;
  unsigned int var82_1;
  unsigned int var82_2;
  unsigned int *var83_1;
  unsigned int *var83_2;
  unsigned int var84_1;
  unsigned int var84_2;
  unsigned int *var85_1;
  unsigned int *var85_2;
  unsigned int var86_1;
  unsigned int var86_2;
  unsigned int *var87_1;
  unsigned int *var87_2;
  unsigned int *var88_1;
  unsigned int *var88_2;
  unsigned int var89_1;
  unsigned int var89_2;
  unsigned int var90_1;
  unsigned int var90_2;
  unsigned int *var91_1;
  unsigned int *var91_2;
  unsigned int var92_1;
  unsigned int var92_2;
  unsigned int *var93_1;
  unsigned int *var93_2;
  unsigned int var94_1;
  unsigned int var94_2;
  unsigned int *var95_1;
  unsigned int *var95_2;
  unsigned int var96_1;
  unsigned int var96_2;
  unsigned int *var97_1;
  unsigned int *var97_2;
  unsigned int var98_1;
  unsigned int var98_2;
  unsigned int *var99_1;
  unsigned int *var99_2;
  unsigned int var100_1;
  unsigned int var100_2;
  unsigned int *var101_1;
  unsigned int *var101_2;
  unsigned int var102_1;
  unsigned int var102_2;
  unsigned int *var103_1;
  unsigned int *var103_2;
  unsigned int var104_1;
  unsigned int var104_2;
  unsigned int *var105_1;
  unsigned int *var105_2;
  unsigned int var106_1;
  unsigned int var106_2;
  unsigned int var107_1;
  unsigned int var107_2;
  unsigned int *var108_1;
  unsigned int *var108_2;
  unsigned int var109_1;
  unsigned int var109_2;
  unsigned int *var110_1;
  unsigned int *var110_2;
  unsigned int var111_1;
  unsigned int var111_2;
  unsigned int *var112_1;
  unsigned int *var112_2;
  unsigned int var113_1;
  unsigned int var113_2;
  unsigned int *var114_1;
  unsigned int *var114_2;
  unsigned int var115_1;
  unsigned int var115_2;
  unsigned int *var116_1;
  unsigned int *var116_2;
  unsigned int var117_1;
  unsigned int var117_2;
  unsigned int *var118_1;
  unsigned int *var118_2;
  unsigned int var119_1;
  unsigned int var119_2;
  unsigned int *var120_1;
  unsigned int *var120_2;
  unsigned int var121_1;
  unsigned int var121_2;
  unsigned int *var122_1;
  unsigned int *var122_2;
  unsigned int var123_1;
  unsigned int var123_2;
  unsigned int var124_1;
  unsigned int var124_2;
  unsigned int *var125_1;
  unsigned int *var125_2;
  unsigned int var126_1;
  unsigned int var126_2;
  unsigned int *var127_1;
  unsigned int *var127_2;
  unsigned int var128_1;
  unsigned int var128_2;
  unsigned int var129_1;
  unsigned int var129_2;
  unsigned int *var130_1;
  unsigned int *var130_2;
  unsigned int var131_1;
  unsigned int var131_2;
  unsigned int *var132_1;
  unsigned int *var132_2;
  unsigned int var133_1;
  unsigned int var133_2;
  unsigned int var134_1;
  unsigned int var134_2;
  unsigned int *var135_1;
  unsigned int *var135_2;
  unsigned int var136_1;
  unsigned int var136_2;
  unsigned int *var137_1;
  unsigned int *var137_2;
  unsigned int var138_1;
  unsigned int var138_2;
  unsigned int var139_1;
  unsigned int var139_2;
  unsigned int *var140_1;
  unsigned int *var140_2;
  unsigned int var141_1;
  unsigned int var141_2;
  unsigned int var142_1;
  unsigned int var142_2;
  unsigned int *var143_1;
  unsigned int *var143_2;
  unsigned int var144_1;
  unsigned int var144_2;
  unsigned int *var145_1;
  unsigned int *var145_2;
  unsigned int var146_1;
  unsigned int var146_2;
  unsigned int *var147_1;
  unsigned int *var147_2;
  unsigned int var148_1;
  unsigned int var148_2;
  unsigned int *var149_1;
  unsigned int *var149_2;
  unsigned int var150_1;
  unsigned int var150_2;
  unsigned int *var151_1;
  unsigned int *var151_2;
  unsigned int var152_1;
  unsigned int var152_2;
  unsigned int *var153_1;
  unsigned int *var153_2;
  unsigned int var154_1;
  unsigned int var154_2;
  unsigned int *var155_1;
  unsigned int *var155_2;
  unsigned int var157_1;
  unsigned int var157_2;
  block0_1:
  switch (var1_1)
  {
    case 4:
      var2_1 = &(*(((unsigned int *) var0_1) + 13));
      var3_1 = *var2_1;
      var4_1 = invSbox_1[(long) ((int) (var3_1 >> ((unsigned int) 4)))][(unsigned long) (var3_1 & 15)];
      var5_1 = &(*(((unsigned int *) var0_1) + 9));
      var6_1 = *var5_1;
      *var2_1 = invSbox_1[(long) ((int) (var6_1 >> ((unsigned int) 4)))][(unsigned long) (var6_1 & 15)];
      var7_1 = &(*(((unsigned int *) var0_1) + 5));
      var8_1 = *var7_1;
      *var5_1 = invSbox_1[(long) ((int) (var8_1 >> ((unsigned int) 4)))][(unsigned long) (var8_1 & 15)];
      var9_1 = &(*(((unsigned int *) var0_1) + 1));
      var10_1 = *var9_1;
      *var7_1 = invSbox_1[(long) ((int) (var10_1 >> ((unsigned int) 4)))][(unsigned long) (var10_1 & 15)];
      *var9_1 = var4_1;
      var11_1 = &(*(((unsigned int *) var0_1) + 14));
      var12_1 = *var11_1;
      var13_1 = invSbox_1[(long) ((int) (var12_1 >> ((unsigned int) 4)))][(unsigned long) (var12_1 & 15)];
      var14_1 = &(*(((unsigned int *) var0_1) + 6));
      var15_1 = *var14_1;
      *var11_1 = invSbox_1[(long) ((int) (var15_1 >> ((unsigned int) 4)))][(unsigned long) (var15_1 & 15)];
      *var14_1 = var13_1;
      var16_1 = &(*(((unsigned int *) var0_1) + 2));
      var17_1 = *var16_1;
      var18_1 = invSbox_1[(long) ((int) (var17_1 >> ((unsigned int) 4)))][(unsigned long) (var17_1 & 15)];
      var19_1 = &(*(((unsigned int *) var0_1) + 10));
      var20_1 = *var19_1;
      *var16_1 = invSbox_1[(long) ((int) (var20_1 >> ((unsigned int) 4)))][(unsigned long) (var20_1 & 15)];
      *var19_1 = var18_1;
      var21_1 = &(*(((unsigned int *) var0_1) + 15));
      var22_1 = *var21_1;
      var23_1 = invSbox_1[(long) ((int) (var22_1 >> ((unsigned int) 4)))][(unsigned long) (var22_1 & 15)];
      var24_1 = &(*(((unsigned int *) var0_1) + 3));
      var25_1 = *var24_1;
      *var21_1 = invSbox_1[(long) ((int) (var25_1 >> ((unsigned int) 4)))][(unsigned long) (var25_1 & 15)];
      var26_1 = &(*(((unsigned int *) var0_1) + 7));
      var27_1 = *var26_1;
      *var24_1 = invSbox_1[(long) ((int) (var27_1 >> ((unsigned int) 4)))][(unsigned long) (var27_1 & 15)];
      var28_1 = &(*(((unsigned int *) var0_1) + 11));
      var29_1 = *var28_1;
      *var26_1 = invSbox_1[(long) ((int) (var29_1 >> ((unsigned int) 4)))][(unsigned long) (var29_1 & 15)];
      *var28_1 = var23_1;
      var30_1 = *var0_1;
      *var0_1 = invSbox_1[(long) ((int) (var30_1 >> ((unsigned int) 4)))][(unsigned long) (var30_1 & 15)];
      var31_1 = &(*(((unsigned int *) var0_1) + 4));
      var32_1 = *var31_1;
      *var31_1 = invSbox_1[(long) ((int) (var32_1 >> ((unsigned int) 4)))][(unsigned long) (var32_1 & 15)];
      var33_1 = &(*(((unsigned int *) var0_1) + 8));
      var34_1 = *var33_1;
      *var33_1 = invSbox_1[(long) ((int) (var34_1 >> ((unsigned int) 4)))][(unsigned long) (var34_1 & 15)];
      var35_1 = &(*(((unsigned int *) var0_1) + 12));
      var156_phi_1 = var35_1;
      goto block4_1;

    case 6:
      var36_1 = &(*(((unsigned int *) var0_1) + 21));
      var37_1 = *var36_1;
      var38_1 = invSbox_1[(long) ((int) (var37_1 >> ((unsigned int) 4)))][(unsigned long) (var37_1 & 15)];
      var39_1 = &(*(((unsigned int *) var0_1) + 17));
      var40_1 = *var39_1;
      *var36_1 = invSbox_1[(long) ((int) (var40_1 >> ((unsigned int) 4)))][(unsigned long) (var40_1 & 15)];
      var41_1 = &(*(((unsigned int *) var0_1) + 13));
      var42_1 = *var41_1;
      *var39_1 = invSbox_1[(long) ((int) (var42_1 >> ((unsigned int) 4)))][(unsigned long) (var42_1 & 15)];
      var43_1 = &(*(((unsigned int *) var0_1) + 9));
      var44_1 = *var43_1;
      *var41_1 = invSbox_1[(long) ((int) (var44_1 >> ((unsigned int) 4)))][(unsigned long) (var44_1 & 15)];
      var45_1 = &(*(((unsigned int *) var0_1) + 5));
      var46_1 = *var45_1;
      *var43_1 = invSbox_1[(long) ((int) (var46_1 >> ((unsigned int) 4)))][(unsigned long) (var46_1 & 15)];
      var47_1 = &(*(((unsigned int *) var0_1) + 1));
      var48_1 = *var47_1;
      *var45_1 = invSbox_1[(long) ((int) (var48_1 >> ((unsigned int) 4)))][(unsigned long) (var48_1 & 15)];
      *var47_1 = var38_1;
      var49_1 = &(*(((unsigned int *) var0_1) + 22));
      var50_1 = *var49_1;
      var51_1 = invSbox_1[(long) ((int) (var50_1 >> ((unsigned int) 4)))][(unsigned long) (var50_1 & 15)];
      var52_1 = &(*(((unsigned int *) var0_1) + 14));
      var53_1 = *var52_1;
      *var49_1 = invSbox_1[(long) ((int) (var53_1 >> ((unsigned int) 4)))][(unsigned long) (var53_1 & 15)];
      var54_1 = &(*(((unsigned int *) var0_1) + 6));
      var55_1 = *var54_1;
      *var52_1 = invSbox_1[(long) ((int) (var55_1 >> ((unsigned int) 4)))][(unsigned long) (var55_1 & 15)];
      *var54_1 = var51_1;
      var56_1 = &(*(((unsigned int *) var0_1) + 18));
      var57_1 = *var56_1;
      var58_1 = invSbox_1[(long) ((int) (var57_1 >> ((unsigned int) 4)))][(unsigned long) (var57_1 & 15)];
      var59_1 = &(*(((unsigned int *) var0_1) + 10));
      var60_1 = *var59_1;
      *var56_1 = invSbox_1[(long) ((int) (var60_1 >> ((unsigned int) 4)))][(unsigned long) (var60_1 & 15)];
      var61_1 = &(*(((unsigned int *) var0_1) + 2));
      var62_1 = *var61_1;
      *var59_1 = invSbox_1[(long) ((int) (var62_1 >> ((unsigned int) 4)))][(unsigned long) (var62_1 & 15)];
      *var61_1 = var58_1;
      var63_1 = &(*(((unsigned int *) var0_1) + 15));
      var64_1 = *var63_1;
      var65_1 = invSbox_1[(long) ((int) (var64_1 >> ((unsigned int) 4)))][(unsigned long) (var64_1 & 15)];
      var66_1 = &(*(((unsigned int *) var0_1) + 3));
      var67_1 = *var66_1;
      *var63_1 = invSbox_1[(long) ((int) (var67_1 >> ((unsigned int) 4)))][(unsigned long) (var67_1 & 15)];
      *var66_1 = var65_1;
      var68_1 = &(*(((unsigned int *) var0_1) + 19));
      var69_1 = *var68_1;
      var70_1 = invSbox_1[(long) ((int) (var69_1 >> ((unsigned int) 4)))][(unsigned long) (var69_1 & 15)];
      var71_1 = &(*(((unsigned int *) var0_1) + 7));
      var72_1 = *var71_1;
      *var68_1 = invSbox_1[(long) ((int) (var72_1 >> ((unsigned int) 4)))][(unsigned long) (var72_1 & 15)];
      *var71_1 = var70_1;
      var73_1 = &(*(((unsigned int *) var0_1) + 23));
      var74_1 = *var73_1;
      var75_1 = invSbox_1[(long) ((int) (var74_1 >> ((unsigned int) 4)))][(unsigned long) (var74_1 & 15)];
      var76_1 = &(*(((unsigned int *) var0_1) + 11));
      var77_1 = *var76_1;
      *var73_1 = invSbox_1[(long) ((int) (var77_1 >> ((unsigned int) 4)))][(unsigned long) (var77_1 & 15)];
      *var76_1 = var75_1;
      var78_1 = *var0_1;
      *var0_1 = invSbox_1[(long) ((int) (var78_1 >> ((unsigned int) 4)))][(unsigned long) (var78_1 & 15)];
      var79_1 = &(*(((unsigned int *) var0_1) + 4));
      var80_1 = *var79_1;
      *var79_1 = invSbox_1[(long) ((int) (var80_1 >> ((unsigned int) 4)))][(unsigned long) (var80_1 & 15)];
      var81_1 = &(*(((unsigned int *) var0_1) + 8));
      var82_1 = *var81_1;
      *var81_1 = invSbox_1[(long) ((int) (var82_1 >> ((unsigned int) 4)))][(unsigned long) (var82_1 & 15)];
      var83_1 = &(*(((unsigned int *) var0_1) + 12));
      var84_1 = *var83_1;
      *var83_1 = invSbox_1[(long) ((int) (var84_1 >> ((unsigned int) 4)))][(unsigned long) (var84_1 & 15)];
      var85_1 = &(*(((unsigned int *) var0_1) + 16));
      var86_1 = *var85_1;
      *var85_1 = invSbox_1[(long) ((int) (var86_1 >> ((unsigned int) 4)))][(unsigned long) (var86_1 & 15)];
      var87_1 = &(*(((unsigned int *) var0_1) + 20));
      var156_phi_1 = var87_1;
      goto block4_1;

    case 8:
      var88_1 = &(*(((unsigned int *) var0_1) + 29));
      var89_1 = *var88_1;
      var90_1 = invSbox_1[(long) ((int) (var89_1 >> ((unsigned int) 4)))][(unsigned long) (var89_1 & 15)];
      var91_1 = &(*(((unsigned int *) var0_1) + 25));
      var92_1 = *var91_1;
      *var88_1 = invSbox_1[(long) ((int) (var92_1 >> ((unsigned int) 4)))][(unsigned long) (var92_1 & 15)];
      var93_1 = &(*(((unsigned int *) var0_1) + 21));
      var94_1 = *var93_1;
      *var91_1 = invSbox_1[(long) ((int) (var94_1 >> ((unsigned int) 4)))][(unsigned long) (var94_1 & 15)];
      var95_1 = &(*(((unsigned int *) var0_1) + 17));
      var96_1 = *var95_1;
      *var93_1 = invSbox_1[(long) ((int) (var96_1 >> ((unsigned int) 4)))][(unsigned long) (var96_1 & 15)];
      var97_1 = &(*(((unsigned int *) var0_1) + 13));
      var98_1 = *var97_1;
      *var95_1 = invSbox_1[(long) ((int) (var98_1 >> ((unsigned int) 4)))][(unsigned long) (var98_1 & 15)];
      var99_1 = &(*(((unsigned int *) var0_1) + 9));
      var100_1 = *var99_1;
      *var97_1 = invSbox_1[(long) ((int) (var100_1 >> ((unsigned int) 4)))][(unsigned long) (var100_1 & 15)];
      var101_1 = &(*(((unsigned int *) var0_1) + 5));
      var102_1 = *var101_1;
      *var99_1 = invSbox_1[(long) ((int) (var102_1 >> ((unsigned int) 4)))][(unsigned long) (var102_1 & 15)];
      var103_1 = &(*(((unsigned int *) var0_1) + 1));
      var104_1 = *var103_1;
      *var101_1 = invSbox_1[(long) ((int) (var104_1 >> ((unsigned int) 4)))][(unsigned long) (var104_1 & 15)];
      *var103_1 = var90_1;
      var105_1 = &(*(((unsigned int *) var0_1) + 30));
      var106_1 = *var105_1;
      var107_1 = invSbox_1[(long) ((int) (var106_1 >> ((unsigned int) 4)))][(unsigned long) (var106_1 & 15)];
      var108_1 = &(*(((unsigned int *) var0_1) + 18));
      var109_1 = *var108_1;
      *var105_1 = invSbox_1[(long) ((int) (var109_1 >> ((unsigned int) 4)))][(unsigned long) (var109_1 & 15)];
      var110_1 = &(*(((unsigned int *) var0_1) + 6));
      var111_1 = *var110_1;
      *var108_1 = invSbox_1[(long) ((int) (var111_1 >> ((unsigned int) 4)))][(unsigned long) (var111_1 & 15)];
      var112_1 = &(*(((unsigned int *) var0_1) + 26));
      var113_1 = *var112_1;
      *var110_1 = invSbox_1[(long) ((int) (var113_1 >> ((unsigned int) 4)))][(unsigned long) (var113_1 & 15)];
      var114_1 = &(*(((unsigned int *) var0_1) + 14));
      var115_1 = *var114_1;
      *var112_1 = invSbox_1[(long) ((int) (var115_1 >> ((unsigned int) 4)))][(unsigned long) (var115_1 & 15)];
      var116_1 = &(*(((unsigned int *) var0_1) + 2));
      var117_1 = *var116_1;
      *var114_1 = invSbox_1[(long) ((int) (var117_1 >> ((unsigned int) 4)))][(unsigned long) (var117_1 & 15)];
      var118_1 = &(*(((unsigned int *) var0_1) + 22));
      var119_1 = *var118_1;
      *var116_1 = invSbox_1[(long) ((int) (var119_1 >> ((unsigned int) 4)))][(unsigned long) (var119_1 & 15)];
      var120_1 = &(*(((unsigned int *) var0_1) + 10));
      var121_1 = *var120_1;
      *var118_1 = invSbox_1[(long) ((int) (var121_1 >> ((unsigned int) 4)))][(unsigned long) (var121_1 & 15)];
      *var120_1 = var107_1;
      var122_1 = &(*(((unsigned int *) var0_1) + 31));
      var123_1 = *var122_1;
      var124_1 = invSbox_1[(long) ((int) (var123_1 >> ((unsigned int) 4)))][(unsigned long) (var123_1 & 15)];
      var125_1 = &(*(((unsigned int *) var0_1) + 15));
      var126_1 = *var125_1;
      *var122_1 = invSbox_1[(long) ((int) (var126_1 >> ((unsigned int) 4)))][(unsigned long) (var126_1 & 15)];
      *var125_1 = var124_1;
      var127_1 = &(*(((unsigned int *) var0_1) + 27));
      var128_1 = *var127_1;
      var129_1 = invSbox_1[(long) ((int) (var128_1 >> ((unsigned int) 4)))][(unsigned long) (var128_1 & 15)];
      var130_1 = &(*(((unsigned int *) var0_1) + 11));
      var131_1 = *var130_1;
      *var127_1 = invSbox_1[(long) ((int) (var131_1 >> ((unsigned int) 4)))][(unsigned long) (var131_1 & 15)];
      *var130_1 = var129_1;
      var132_1 = &(*(((unsigned int *) var0_1) + 23));
      var133_1 = *var132_1;
      var134_1 = invSbox_1[(long) ((int) (var133_1 >> ((unsigned int) 4)))][(unsigned long) (var133_1 & 15)];
      var135_1 = &(*(((unsigned int *) var0_1) + 7));
      var136_1 = *var135_1;
      *var132_1 = invSbox_1[(long) ((int) (var136_1 >> ((unsigned int) 4)))][(unsigned long) (var136_1 & 15)];
      *var135_1 = var134_1;
      var137_1 = &(*(((unsigned int *) var0_1) + 19));
      var138_1 = *var137_1;
      var139_1 = invSbox_1[(long) ((int) (var138_1 >> ((unsigned int) 4)))][(unsigned long) (var138_1 & 15)];
      var140_1 = &(*(((unsigned int *) var0_1) + 3));
      var141_1 = *var140_1;
      *var137_1 = invSbox_1[(long) ((int) (var141_1 >> ((unsigned int) 4)))][(unsigned long) (var141_1 & 15)];
      *var140_1 = var139_1;
      var142_1 = *var0_1;
      *var0_1 = invSbox_1[(long) ((int) (var142_1 >> ((unsigned int) 4)))][(unsigned long) (var142_1 & 15)];
      var143_1 = &(*(((unsigned int *) var0_1) + 4));
      var144_1 = *var143_1;
      *var143_1 = invSbox_1[(long) ((int) (var144_1 >> ((unsigned int) 4)))][(unsigned long) (var144_1 & 15)];
      var145_1 = &(*(((unsigned int *) var0_1) + 8));
      var146_1 = *var145_1;
      *var145_1 = invSbox_1[(long) ((int) (var146_1 >> ((unsigned int) 4)))][(unsigned long) (var146_1 & 15)];
      var147_1 = &(*(((unsigned int *) var0_1) + 12));
      var148_1 = *var147_1;
      *var147_1 = invSbox_1[(long) ((int) (var148_1 >> ((unsigned int) 4)))][(unsigned long) (var148_1 & 15)];
      var149_1 = &(*(((unsigned int *) var0_1) + 16));
      var150_1 = *var149_1;
      *var149_1 = invSbox_1[(long) ((int) (var150_1 >> ((unsigned int) 4)))][(unsigned long) (var150_1 & 15)];
      var151_1 = &(*(((unsigned int *) var0_1) + 20));
      var152_1 = *var151_1;
      *var151_1 = invSbox_1[(long) ((int) (var152_1 >> ((unsigned int) 4)))][(unsigned long) (var152_1 & 15)];
      var153_1 = &(*(((unsigned int *) var0_1) + 24));
      var154_1 = *var153_1;
      *var153_1 = invSbox_1[(long) ((int) (var154_1 >> ((unsigned int) 4)))][(unsigned long) (var154_1 & 15)];
      var155_1 = &(*(((unsigned int *) var0_1) + 28));
      var156_phi_1 = var155_1;
      goto block4_1;

    default:
      return;

  }


  block0_2:
  switch (var1_2)
  {
    case 4:
      var2_2 = &(*(((unsigned int *) var0_2) + 13));
      var3_2 = *var2_2;
      var4_2 = invSbox_2[(long) ((int) (var3_2 >> ((unsigned int) 4)))][(unsigned long) (var3_2 & 15)];
      var5_2 = &(*(((unsigned int *) var0_2) + 9));
      var6_2 = *var5_2;
      *var2_2 = invSbox_2[(long) ((int) (var6_2 >> ((unsigned int) 4)))][(unsigned long) (var6_2 & 15)];
      var7_2 = &(*(((unsigned int *) var0_2) + 5));
      var8_2 = *var7_2;
      *var5_2 = invSbox_2[(long) ((int) (var8_2 >> ((unsigned int) 4)))][(unsigned long) (var8_2 & 15)];
      var9_2 = &(*(((unsigned int *) var0_2) + 1));
      var10_2 = *var9_2;
      *var7_2 = invSbox_2[(long) ((int) (var10_2 >> ((unsigned int) 4)))][(unsigned long) (var10_2 & 15)];
      *var9_2 = var4_2;
      var11_2 = &(*(((unsigned int *) var0_2) + 14));
      var12_2 = *var11_2;
      var13_2 = invSbox_2[(long) ((int) (var12_2 >> ((unsigned int) 4)))][(unsigned long) (var12_2 & 15)];
      var14_2 = &(*(((unsigned int *) var0_2) + 6));
      var15_2 = *var14_2;
      *var11_2 = invSbox_2[(long) ((int) (var15_2 >> ((unsigned int) 4)))][(unsigned long) (var15_2 & 15)];
      *var14_2 = var13_2;
      var16_2 = &(*(((unsigned int *) var0_2) + 2));
      var17_2 = *var16_2;
      var18_2 = invSbox_2[(long) ((int) (var17_2 >> ((unsigned int) 4)))][(unsigned long) (var17_2 & 15)];
      var19_2 = &(*(((unsigned int *) var0_2) + 10));
      var20_2 = *var19_2;
      *var16_2 = invSbox_2[(long) ((int) (var20_2 >> ((unsigned int) 4)))][(unsigned long) (var20_2 & 15)];
      *var19_2 = var18_2;
      var21_2 = &(*(((unsigned int *) var0_2) + 15));
      var22_2 = *var21_2;
      var23_2 = invSbox_2[(long) ((int) (var22_2 >> ((unsigned int) 4)))][(unsigned long) (var22_2 & 15)];
      var24_2 = &(*(((unsigned int *) var0_2) + 3));
      var25_2 = *var24_2;
      *var21_2 = invSbox_2[(long) ((int) (var25_2 >> ((unsigned int) 4)))][(unsigned long) (var25_2 & 15)];
      var26_2 = &(*(((unsigned int *) var0_2) + 7));
      var27_2 = *var26_2;
      *var24_2 = invSbox_2[(long) ((int) (var27_2 >> ((unsigned int) 4)))][(unsigned long) (var27_2 & 15)];
      var28_2 = &(*(((unsigned int *) var0_2) + 11));
      var29_2 = *var28_2;
      *var26_2 = invSbox_2[(long) ((int) (var29_2 >> ((unsigned int) 4)))][(unsigned long) (var29_2 & 15)];
      *var28_2 = var23_2;
      var30_2 = *var0_2;
      *var0_2 = invSbox_2[(long) ((int) (var30_2 >> ((unsigned int) 4)))][(unsigned long) (var30_2 & 15)];
      var31_2 = &(*(((unsigned int *) var0_2) + 4));
      var32_2 = *var31_2;
      *var31_2 = invSbox_2[(long) ((int) (var32_2 >> ((unsigned int) 4)))][(unsigned long) (var32_2 & 15)];
      var33_2 = &(*(((unsigned int *) var0_2) + 8));
      var34_2 = *var33_2;
      *var33_2 = invSbox_2[(long) ((int) (var34_2 >> ((unsigned int) 4)))][(unsigned long) (var34_2 & 15)];
      var35_2 = &(*(((unsigned int *) var0_2) + 12));
      var156_phi_2 = var35_2;
      goto block4_2;

    case 6:
      var36_2 = &(*(((unsigned int *) var0_2) + 21));
      var37_2 = *var36_2;
      var38_2 = invSbox_2[(long) ((int) (var37_2 >> ((unsigned int) 4)))][(unsigned long) (var37_2 & 15)];
      var39_2 = &(*(((unsigned int *) var0_2) + 17));
      var40_2 = *var39_2;
      *var36_2 = invSbox_2[(long) ((int) (var40_2 >> ((unsigned int) 4)))][(unsigned long) (var40_2 & 15)];
      var41_2 = &(*(((unsigned int *) var0_2) + 13));
      var42_2 = *var41_2;
      *var39_2 = invSbox_2[(long) ((int) (var42_2 >> ((unsigned int) 4)))][(unsigned long) (var42_2 & 15)];
      var43_2 = &(*(((unsigned int *) var0_2) + 9));
      var44_2 = *var43_2;
      *var41_2 = invSbox_2[(long) ((int) (var44_2 >> ((unsigned int) 4)))][(unsigned long) (var44_2 & 15)];
      var45_2 = &(*(((unsigned int *) var0_2) + 5));
      var46_2 = *var45_2;
      *var43_2 = invSbox_2[(long) ((int) (var46_2 >> ((unsigned int) 4)))][(unsigned long) (var46_2 & 15)];
      var47_2 = &(*(((unsigned int *) var0_2) + 1));
      var48_2 = *var47_2;
      *var45_2 = invSbox_2[(long) ((int) (var48_2 >> ((unsigned int) 4)))][(unsigned long) (var48_2 & 15)];
      *var47_2 = var38_2;
      var49_2 = &(*(((unsigned int *) var0_2) + 22));
      var50_2 = *var49_2;
      var51_2 = invSbox_2[(long) ((int) (var50_2 >> ((unsigned int) 4)))][(unsigned long) (var50_2 & 15)];
      var52_2 = &(*(((unsigned int *) var0_2) + 14));
      var53_2 = *var52_2;
      *var49_2 = invSbox_2[(long) ((int) (var53_2 >> ((unsigned int) 4)))][(unsigned long) (var53_2 & 15)];
      var54_2 = &(*(((unsigned int *) var0_2) + 6));
      var55_2 = *var54_2;
      *var52_2 = invSbox_2[(long) ((int) (var55_2 >> ((unsigned int) 4)))][(unsigned long) (var55_2 & 15)];
      *var54_2 = var51_2;
      var56_2 = &(*(((unsigned int *) var0_2) + 18));
      var57_2 = *var56_2;
      var58_2 = invSbox_2[(long) ((int) (var57_2 >> ((unsigned int) 4)))][(unsigned long) (var57_2 & 15)];
      var59_2 = &(*(((unsigned int *) var0_2) + 10));
      var60_2 = *var59_2;
      *var56_2 = invSbox_2[(long) ((int) (var60_2 >> ((unsigned int) 4)))][(unsigned long) (var60_2 & 15)];
      var61_2 = &(*(((unsigned int *) var0_2) + 2));
      var62_2 = *var61_2;
      *var59_2 = invSbox_2[(long) ((int) (var62_2 >> ((unsigned int) 4)))][(unsigned long) (var62_2 & 15)];
      *var61_2 = var58_2;
      var63_2 = &(*(((unsigned int *) var0_2) + 15));
      var64_2 = *var63_2;
      var65_2 = invSbox_2[(long) ((int) (var64_2 >> ((unsigned int) 4)))][(unsigned long) (var64_2 & 15)];
      var66_2 = &(*(((unsigned int *) var0_2) + 3));
      var67_2 = *var66_2;
      *var63_2 = invSbox_2[(long) ((int) (var67_2 >> ((unsigned int) 4)))][(unsigned long) (var67_2 & 15)];
      *var66_2 = var65_2;
      var68_2 = &(*(((unsigned int *) var0_2) + 19));
      var69_2 = *var68_2;
      var70_2 = invSbox_2[(long) ((int) (var69_2 >> ((unsigned int) 4)))][(unsigned long) (var69_2 & 15)];
      var71_2 = &(*(((unsigned int *) var0_2) + 7));
      var72_2 = *var71_2;
      *var68_2 = invSbox_2[(long) ((int) (var72_2 >> ((unsigned int) 4)))][(unsigned long) (var72_2 & 15)];
      *var71_2 = var70_2;
      var73_2 = &(*(((unsigned int *) var0_2) + 23));
      var74_2 = *var73_2;
      var75_2 = invSbox_2[(long) ((int) (var74_2 >> ((unsigned int) 4)))][(unsigned long) (var74_2 & 15)];
      var76_2 = &(*(((unsigned int *) var0_2) + 11));
      var77_2 = *var76_2;
      *var73_2 = invSbox_2[(long) ((int) (var77_2 >> ((unsigned int) 4)))][(unsigned long) (var77_2 & 15)];
      *var76_2 = var75_2;
      var78_2 = *var0_2;
      *var0_2 = invSbox_2[(long) ((int) (var78_2 >> ((unsigned int) 4)))][(unsigned long) (var78_2 & 15)];
      var79_2 = &(*(((unsigned int *) var0_2) + 4));
      var80_2 = *var79_2;
      *var79_2 = invSbox_2[(long) ((int) (var80_2 >> ((unsigned int) 4)))][(unsigned long) (var80_2 & 15)];
      var81_2 = &(*(((unsigned int *) var0_2) + 8));
      var82_2 = *var81_2;
      *var81_2 = invSbox_2[(long) ((int) (var82_2 >> ((unsigned int) 4)))][(unsigned long) (var82_2 & 15)];
      var83_2 = &(*(((unsigned int *) var0_2) + 12));
      var84_2 = *var83_2;
      *var83_2 = invSbox_2[(long) ((int) (var84_2 >> ((unsigned int) 4)))][(unsigned long) (var84_2 & 15)];
      var85_2 = &(*(((unsigned int *) var0_2) + 16));
      var86_2 = *var85_2;
      *var85_2 = invSbox_2[(long) ((int) (var86_2 >> ((unsigned int) 4)))][(unsigned long) (var86_2 & 15)];
      var87_2 = &(*(((unsigned int *) var0_2) + 20));
      var156_phi_2 = var87_2;
      goto block4_2;

    case 8:
      var88_2 = &(*(((unsigned int *) var0_2) + 29));
      var89_2 = *var88_2;
      var90_2 = invSbox_2[(long) ((int) (var89_2 >> ((unsigned int) 4)))][(unsigned long) (var89_2 & 15)];
      var91_2 = &(*(((unsigned int *) var0_2) + 25));
      var92_2 = *var91_2;
      *var88_2 = invSbox_2[(long) ((int) (var92_2 >> ((unsigned int) 4)))][(unsigned long) (var92_2 & 15)];
      var93_2 = &(*(((unsigned int *) var0_2) + 21));
      var94_2 = *var93_2;
      *var91_2 = invSbox_2[(long) ((int) (var94_2 >> ((unsigned int) 4)))][(unsigned long) (var94_2 & 15)];
      var95_2 = &(*(((unsigned int *) var0_2) + 17));
      var96_2 = *var95_2;
      *var93_2 = invSbox_2[(long) ((int) (var96_2 >> ((unsigned int) 4)))][(unsigned long) (var96_2 & 15)];
      var97_2 = &(*(((unsigned int *) var0_2) + 13));
      var98_2 = *var97_2;
      *var95_2 = invSbox_2[(long) ((int) (var98_2 >> ((unsigned int) 4)))][(unsigned long) (var98_2 & 15)];
      var99_2 = &(*(((unsigned int *) var0_2) + 9));
      var100_2 = *var99_2;
      *var97_2 = invSbox_2[(long) ((int) (var100_2 >> ((unsigned int) 4)))][(unsigned long) (var100_2 & 15)];
      var101_2 = &(*(((unsigned int *) var0_2) + 5));
      var102_2 = *var101_2;
      *var99_2 = invSbox_2[(long) ((int) (var102_2 >> ((unsigned int) 4)))][(unsigned long) (var102_2 & 15)];
      var103_2 = &(*(((unsigned int *) var0_2) + 1));
      var104_2 = *var103_2;
      *var101_2 = invSbox_2[(long) ((int) (var104_2 >> ((unsigned int) 4)))][(unsigned long) (var104_2 & 15)];
      *var103_2 = var90_2;
      var105_2 = &(*(((unsigned int *) var0_2) + 30));
      var106_2 = *var105_2;
      var107_2 = invSbox_2[(long) ((int) (var106_2 >> ((unsigned int) 4)))][(unsigned long) (var106_2 & 15)];
      var108_2 = &(*(((unsigned int *) var0_2) + 18));
      var109_2 = *var108_2;
      *var105_2 = invSbox_2[(long) ((int) (var109_2 >> ((unsigned int) 4)))][(unsigned long) (var109_2 & 15)];
      var110_2 = &(*(((unsigned int *) var0_2) + 6));
      var111_2 = *var110_2;
      *var108_2 = invSbox_2[(long) ((int) (var111_2 >> ((unsigned int) 4)))][(unsigned long) (var111_2 & 15)];
      var112_2 = &(*(((unsigned int *) var0_2) + 26));
      var113_2 = *var112_2;
      *var110_2 = invSbox_2[(long) ((int) (var113_2 >> ((unsigned int) 4)))][(unsigned long) (var113_2 & 15)];
      var114_2 = &(*(((unsigned int *) var0_2) + 14));
      var115_2 = *var114_2;
      *var112_2 = invSbox_2[(long) ((int) (var115_2 >> ((unsigned int) 4)))][(unsigned long) (var115_2 & 15)];
      var116_2 = &(*(((unsigned int *) var0_2) + 2));
      var117_2 = *var116_2;
      *var114_2 = invSbox_2[(long) ((int) (var117_2 >> ((unsigned int) 4)))][(unsigned long) (var117_2 & 15)];
      var118_2 = &(*(((unsigned int *) var0_2) + 22));
      var119_2 = *var118_2;
      *var116_2 = invSbox_2[(long) ((int) (var119_2 >> ((unsigned int) 4)))][(unsigned long) (var119_2 & 15)];
      var120_2 = &(*(((unsigned int *) var0_2) + 10));
      var121_2 = *var120_2;
      *var118_2 = invSbox_2[(long) ((int) (var121_2 >> ((unsigned int) 4)))][(unsigned long) (var121_2 & 15)];
      *var120_2 = var107_2;
      var122_2 = &(*(((unsigned int *) var0_2) + 31));
      var123_2 = *var122_2;
      var124_2 = invSbox_2[(long) ((int) (var123_2 >> ((unsigned int) 4)))][(unsigned long) (var123_2 & 15)];
      var125_2 = &(*(((unsigned int *) var0_2) + 15));
      var126_2 = *var125_2;
      *var122_2 = invSbox_2[(long) ((int) (var126_2 >> ((unsigned int) 4)))][(unsigned long) (var126_2 & 15)];
      *var125_2 = var124_2;
      var127_2 = &(*(((unsigned int *) var0_2) + 27));
      var128_2 = *var127_2;
      var129_2 = invSbox_2[(long) ((int) (var128_2 >> ((unsigned int) 4)))][(unsigned long) (var128_2 & 15)];
      var130_2 = &(*(((unsigned int *) var0_2) + 11));
      var131_2 = *var130_2;
      *var127_2 = invSbox_2[(long) ((int) (var131_2 >> ((unsigned int) 4)))][(unsigned long) (var131_2 & 15)];
      *var130_2 = var129_2;
      var132_2 = &(*(((unsigned int *) var0_2) + 23));
      var133_2 = *var132_2;
      var134_2 = invSbox_2[(long) ((int) (var133_2 >> ((unsigned int) 4)))][(unsigned long) (var133_2 & 15)];
      var135_2 = &(*(((unsigned int *) var0_2) + 7));
      var136_2 = *var135_2;
      *var132_2 = invSbox_2[(long) ((int) (var136_2 >> ((unsigned int) 4)))][(unsigned long) (var136_2 & 15)];
      *var135_2 = var134_2;
      var137_2 = &(*(((unsigned int *) var0_2) + 19));
      var138_2 = *var137_2;
      var139_2 = invSbox_2[(long) ((int) (var138_2 >> ((unsigned int) 4)))][(unsigned long) (var138_2 & 15)];
      var140_2 = &(*(((unsigned int *) var0_2) + 3));
      var141_2 = *var140_2;
      *var137_2 = invSbox_2[(long) ((int) (var141_2 >> ((unsigned int) 4)))][(unsigned long) (var141_2 & 15)];
      *var140_2 = var139_2;
      var142_2 = *var0_2;
      *var0_2 = invSbox_2[(long) ((int) (var142_2 >> ((unsigned int) 4)))][(unsigned long) (var142_2 & 15)];
      var143_2 = &(*(((unsigned int *) var0_2) + 4));
      var144_2 = *var143_2;
      *var143_2 = invSbox_2[(long) ((int) (var144_2 >> ((unsigned int) 4)))][(unsigned long) (var144_2 & 15)];
      var145_2 = &(*(((unsigned int *) var0_2) + 8));
      var146_2 = *var145_2;
      *var145_2 = invSbox_2[(long) ((int) (var146_2 >> ((unsigned int) 4)))][(unsigned long) (var146_2 & 15)];
      var147_2 = &(*(((unsigned int *) var0_2) + 12));
      var148_2 = *var147_2;
      *var147_2 = invSbox_2[(long) ((int) (var148_2 >> ((unsigned int) 4)))][(unsigned long) (var148_2 & 15)];
      var149_2 = &(*(((unsigned int *) var0_2) + 16));
      var150_2 = *var149_2;
      *var149_2 = invSbox_2[(long) ((int) (var150_2 >> ((unsigned int) 4)))][(unsigned long) (var150_2 & 15)];
      var151_2 = &(*(((unsigned int *) var0_2) + 20));
      var152_2 = *var151_2;
      *var151_2 = invSbox_2[(long) ((int) (var152_2 >> ((unsigned int) 4)))][(unsigned long) (var152_2 & 15)];
      var153_2 = &(*(((unsigned int *) var0_2) + 24));
      var154_2 = *var153_2;
      *var153_2 = invSbox_2[(long) ((int) (var154_2 >> ((unsigned int) 4)))][(unsigned long) (var154_2 & 15)];
      var155_2 = &(*(((unsigned int *) var0_2) + 28));
      var156_phi_2 = var155_2;
      goto block4_2;

    default:
      return;

  }


  block4_1:
  var157_1 = *var156_phi_1;

  block4_2:
  var157_2 = *var156_phi_2;

  *var156_phi_1 = invSbox_1[(long) ((int) (var157_1 >> ((unsigned int) 4)))][(unsigned long) (var157_1 & 15)];
  *var156_phi_2 = invSbox_2[(long) ((int) (var157_2 >> ((unsigned int) 4)))][(unsigned long) (var157_2 & 15)];
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    for (int i_1 = 0; i_1 < 16; i_1++)
    {
      assert(invSbox_1[i_0][i_1] == invSbox_2[i_0][i_1]);
    }

  }

  assert((*var156_phi_1) == (*var156_phi_2));
  assert((*var2_1) == (*var2_2));
  assert(var3_1 == var3_2);
  assert(var4_1 == var4_2);
  assert((*var5_1) == (*var5_2));
  assert(var6_1 == var6_2);
  assert((*var7_1) == (*var7_2));
  assert(var8_1 == var8_2);
  assert((*var9_1) == (*var9_2));
  assert(var10_1 == var10_2);
  assert((*var11_1) == (*var11_2));
  assert(var12_1 == var12_2);
  assert(var13_1 == var13_2);
  assert((*var14_1) == (*var14_2));
  assert(var15_1 == var15_2);
  assert((*var16_1) == (*var16_2));
  assert(var17_1 == var17_2);
  assert(var18_1 == var18_2);
  assert((*var19_1) == (*var19_2));
  assert(var20_1 == var20_2);
  assert((*var21_1) == (*var21_2));
  assert(var22_1 == var22_2);
  assert(var23_1 == var23_2);
  assert((*var24_1) == (*var24_2));
  assert(var25_1 == var25_2);
  assert((*var26_1) == (*var26_2));
  assert(var27_1 == var27_2);
  assert((*var28_1) == (*var28_2));
  assert(var29_1 == var29_2);
  assert(var30_1 == var30_2);
  assert((*var31_1) == (*var31_2));
  assert(var32_1 == var32_2);
  assert((*var33_1) == (*var33_2));
  assert(var34_1 == var34_2);
  assert((*var35_1) == (*var35_2));
  assert((*var36_1) == (*var36_2));
  assert(var37_1 == var37_2);
  assert(var38_1 == var38_2);
  assert((*var39_1) == (*var39_2));
  assert(var40_1 == var40_2);
  assert((*var41_1) == (*var41_2));
  assert(var42_1 == var42_2);
  assert((*var43_1) == (*var43_2));
  assert(var44_1 == var44_2);
  assert((*var45_1) == (*var45_2));
  assert(var46_1 == var46_2);
  assert((*var47_1) == (*var47_2));
  assert(var48_1 == var48_2);
  assert((*var49_1) == (*var49_2));
  assert(var50_1 == var50_2);
  assert(var51_1 == var51_2);
  assert((*var52_1) == (*var52_2));
  assert(var53_1 == var53_2);
  assert((*var54_1) == (*var54_2));
  assert(var55_1 == var55_2);
  assert((*var56_1) == (*var56_2));
  assert(var57_1 == var57_2);
  assert(var58_1 == var58_2);
  assert((*var59_1) == (*var59_2));
  assert(var60_1 == var60_2);
  assert((*var61_1) == (*var61_2));
  assert(var62_1 == var62_2);
  assert((*var63_1) == (*var63_2));
  assert(var64_1 == var64_2);
  assert(var65_1 == var65_2);
  assert((*var66_1) == (*var66_2));
  assert(var67_1 == var67_2);
  assert((*var68_1) == (*var68_2));
  assert(var69_1 == var69_2);
  assert(var70_1 == var70_2);
  assert((*var71_1) == (*var71_2));
  assert(var72_1 == var72_2);
  assert((*var73_1) == (*var73_2));
  assert(var74_1 == var74_2);
  assert(var75_1 == var75_2);
  assert((*var76_1) == (*var76_2));
  assert(var77_1 == var77_2);
  assert(var78_1 == var78_2);
  assert((*var79_1) == (*var79_2));
  assert(var80_1 == var80_2);
  assert((*var81_1) == (*var81_2));
  assert(var82_1 == var82_2);
  assert((*var83_1) == (*var83_2));
  assert(var84_1 == var84_2);
  assert((*var85_1) == (*var85_2));
  assert(var86_1 == var86_2);
  assert((*var87_1) == (*var87_2));
  assert((*var88_1) == (*var88_2));
  assert(var89_1 == var89_2);
  assert(var90_1 == var90_2);
  assert((*var91_1) == (*var91_2));
  assert(var92_1 == var92_2);
  assert((*var93_1) == (*var93_2));
  assert(var94_1 == var94_2);
  assert((*var95_1) == (*var95_2));
  assert(var96_1 == var96_2);
  assert((*var97_1) == (*var97_2));
  assert(var98_1 == var98_2);
  assert((*var99_1) == (*var99_2));
  assert(var100_1 == var100_2);
  assert((*var101_1) == (*var101_2));
  assert(var102_1 == var102_2);
  assert((*var103_1) == (*var103_2));
  assert(var104_1 == var104_2);
  assert((*var105_1) == (*var105_2));
  assert(var106_1 == var106_2);
  assert(var107_1 == var107_2);
  assert((*var108_1) == (*var108_2));
  assert(var109_1 == var109_2);
  assert((*var110_1) == (*var110_2));
  assert(var111_1 == var111_2);
  assert((*var112_1) == (*var112_2));
  assert(var113_1 == var113_2);
  assert((*var114_1) == (*var114_2));
  assert(var115_1 == var115_2);
  assert((*var116_1) == (*var116_2));
  assert(var117_1 == var117_2);
  assert((*var118_1) == (*var118_2));
  assert(var119_1 == var119_2);
  assert((*var120_1) == (*var120_2));
  assert(var121_1 == var121_2);
  assert((*var122_1) == (*var122_2));
  assert(var123_1 == var123_2);
  assert(var124_1 == var124_2);
  assert((*var125_1) == (*var125_2));
  assert(var126_1 == var126_2);
  assert((*var127_1) == (*var127_2));
  assert(var128_1 == var128_2);
  assert(var129_1 == var129_2);
  assert((*var130_1) == (*var130_2));
  assert(var131_1 == var131_2);
  assert((*var132_1) == (*var132_2));
  assert(var133_1 == var133_2);
  assert(var134_1 == var134_2);
  assert((*var135_1) == (*var135_2));
  assert(var136_1 == var136_2);
  assert((*var137_1) == (*var137_2));
  assert(var138_1 == var138_2);
  assert(var139_1 == var139_2);
  assert((*var140_1) == (*var140_2));
  assert(var141_1 == var141_2);
  assert(var142_1 == var142_2);
  assert((*var143_1) == (*var143_2));
  assert(var144_1 == var144_2);
  assert((*var145_1) == (*var145_2));
  assert(var146_1 == var146_2);
  assert((*var147_1) == (*var147_2));
  assert(var148_1 == var148_2);
  assert((*var149_1) == (*var149_2));
  assert(var150_1 == var150_2);
  assert((*var151_1) == (*var151_2));
  assert(var152_1 == var152_2);
  assert((*var153_1) == (*var153_2));
  assert(var154_1 == var154_2);
  assert((*var155_1) == (*var155_2));
  assert(var157_1 == var157_2);
}

void InversShiftRow_ByteSub(unsigned int *var0, unsigned int var1)
{
  unsigned int *var156_phi;
  unsigned int *var2;
  unsigned int var3;
  unsigned int var4;
  unsigned int *var5;
  unsigned int var6;
  unsigned int *var7;
  unsigned int var8;
  unsigned int *var9;
  unsigned int var10;
  unsigned int *var11;
  unsigned int var12;
  unsigned int var13;
  unsigned int *var14;
  unsigned int var15;
  unsigned int *var16;
  unsigned int var17;
  unsigned int var18;
  unsigned int *var19;
  unsigned int var20;
  unsigned int *var21;
  unsigned int var22;
  unsigned int var23;
  unsigned int *var24;
  unsigned int var25;
  unsigned int *var26;
  unsigned int var27;
  unsigned int *var28;
  unsigned int var29;
  unsigned int var30;
  unsigned int *var31;
  unsigned int var32;
  unsigned int *var33;
  unsigned int var34;
  unsigned int *var35;
  unsigned int *var36;
  unsigned int var37;
  unsigned int var38;
  unsigned int *var39;
  unsigned int var40;
  unsigned int *var41;
  unsigned int var42;
  unsigned int *var43;
  unsigned int var44;
  unsigned int *var45;
  unsigned int var46;
  unsigned int *var47;
  unsigned int var48;
  unsigned int *var49;
  unsigned int var50;
  unsigned int var51;
  unsigned int *var52;
  unsigned int var53;
  unsigned int *var54;
  unsigned int var55;
  unsigned int *var56;
  unsigned int var57;
  unsigned int var58;
  unsigned int *var59;
  unsigned int var60;
  unsigned int *var61;
  unsigned int var62;
  unsigned int *var63;
  unsigned int var64;
  unsigned int var65;
  unsigned int *var66;
  unsigned int var67;
  unsigned int *var68;
  unsigned int var69;
  unsigned int var70;
  unsigned int *var71;
  unsigned int var72;
  unsigned int *var73;
  unsigned int var74;
  unsigned int var75;
  unsigned int *var76;
  unsigned int var77;
  unsigned int var78;
  unsigned int *var79;
  unsigned int var80;
  unsigned int *var81;
  unsigned int var82;
  unsigned int *var83;
  unsigned int var84;
  unsigned int *var85;
  unsigned int var86;
  unsigned int *var87;
  unsigned int *var88;
  unsigned int var89;
  unsigned int var90;
  unsigned int *var91;
  unsigned int var92;
  unsigned int *var93;
  unsigned int var94;
  unsigned int *var95;
  unsigned int var96;
  unsigned int *var97;
  unsigned int var98;
  unsigned int *var99;
  unsigned int var100;
  unsigned int *var101;
  unsigned int var102;
  unsigned int *var103;
  unsigned int var104;
  unsigned int *var105;
  unsigned int var106;
  unsigned int var107;
  unsigned int *var108;
  unsigned int var109;
  unsigned int *var110;
  unsigned int var111;
  unsigned int *var112;
  unsigned int var113;
  unsigned int *var114;
  unsigned int var115;
  unsigned int *var116;
  unsigned int var117;
  unsigned int *var118;
  unsigned int var119;
  unsigned int *var120;
  unsigned int var121;
  unsigned int *var122;
  unsigned int var123;
  unsigned int var124;
  unsigned int *var125;
  unsigned int var126;
  unsigned int *var127;
  unsigned int var128;
  unsigned int var129;
  unsigned int *var130;
  unsigned int var131;
  unsigned int *var132;
  unsigned int var133;
  unsigned int var134;
  unsigned int *var135;
  unsigned int var136;
  unsigned int *var137;
  unsigned int var138;
  unsigned int var139;
  unsigned int *var140;
  unsigned int var141;
  unsigned int var142;
  unsigned int *var143;
  unsigned int var144;
  unsigned int *var145;
  unsigned int var146;
  unsigned int *var147;
  unsigned int var148;
  unsigned int *var149;
  unsigned int var150;
  unsigned int *var151;
  unsigned int var152;
  unsigned int *var153;
  unsigned int var154;
  unsigned int *var155;
  unsigned int var157;
  block0:
  switch (var1)
  {
    case 4:
      var2 = &(*(((unsigned int *) var0) + 13));
      var3 = *var2;
      var4 = invSbox[(long) ((int) (var3 >> ((unsigned int) 4)))][(unsigned long) (var3 & 15)];
      var5 = &(*(((unsigned int *) var0) + 9));
      var6 = *var5;
      *var2 = invSbox[(long) ((int) (var6 >> ((unsigned int) 4)))][(unsigned long) (var6 & 15)];
      var7 = &(*(((unsigned int *) var0) + 5));
      var8 = *var7;
      *var5 = invSbox[(long) ((int) (var8 >> ((unsigned int) 4)))][(unsigned long) (var8 & 15)];
      var9 = &(*(((unsigned int *) var0) + 1));
      var10 = *var9;
      *var7 = invSbox[(long) ((int) (var10 >> ((unsigned int) 4)))][(unsigned long) (var10 & 15)];
      *var9 = var4;
      var11 = &(*(((unsigned int *) var0) + 14));
      var12 = *var11;
      var13 = invSbox[(long) ((int) (var12 >> ((unsigned int) 4)))][(unsigned long) (var12 & 15)];
      var14 = &(*(((unsigned int *) var0) + 6));
      var15 = *var14;
      *var11 = invSbox[(long) ((int) (var15 >> ((unsigned int) 4)))][(unsigned long) (var15 & 15)];
      *var14 = var13;
      var16 = &(*(((unsigned int *) var0) + 2));
      var17 = *var16;
      var18 = invSbox[(long) ((int) (var17 >> ((unsigned int) 4)))][(unsigned long) (var17 & 15)];
      var19 = &(*(((unsigned int *) var0) + 10));
      var20 = *var19;
      *var16 = invSbox[(long) ((int) (var20 >> ((unsigned int) 4)))][(unsigned long) (var20 & 15)];
      *var19 = var18;
      var21 = &(*(((unsigned int *) var0) + 15));
      var22 = *var21;
      var23 = invSbox[(long) ((int) (var22 >> ((unsigned int) 4)))][(unsigned long) (var22 & 15)];
      var24 = &(*(((unsigned int *) var0) + 3));
      var25 = *var24;
      *var21 = invSbox[(long) ((int) (var25 >> ((unsigned int) 4)))][(unsigned long) (var25 & 15)];
      var26 = &(*(((unsigned int *) var0) + 7));
      var27 = *var26;
      *var24 = invSbox[(long) ((int) (var27 >> ((unsigned int) 4)))][(unsigned long) (var27 & 15)];
      var28 = &(*(((unsigned int *) var0) + 11));
      var29 = *var28;
      *var26 = invSbox[(long) ((int) (var29 >> ((unsigned int) 4)))][(unsigned long) (var29 & 15)];
      *var28 = var23;
      var30 = *var0;
      *var0 = invSbox[(long) ((int) (var30 >> ((unsigned int) 4)))][(unsigned long) (var30 & 15)];
      var31 = &(*(((unsigned int *) var0) + 4));
      var32 = *var31;
      *var31 = invSbox[(long) ((int) (var32 >> ((unsigned int) 4)))][(unsigned long) (var32 & 15)];
      var33 = &(*(((unsigned int *) var0) + 8));
      var34 = *var33;
      *var33 = invSbox[(long) ((int) (var34 >> ((unsigned int) 4)))][(unsigned long) (var34 & 15)];
      var35 = &(*(((unsigned int *) var0) + 12));
      var156_phi = var35;
      goto block4;

    case 6:
      var36 = &(*(((unsigned int *) var0) + 21));
      var37 = *var36;
      var38 = invSbox[(long) ((int) (var37 >> ((unsigned int) 4)))][(unsigned long) (var37 & 15)];
      var39 = &(*(((unsigned int *) var0) + 17));
      var40 = *var39;
      *var36 = invSbox[(long) ((int) (var40 >> ((unsigned int) 4)))][(unsigned long) (var40 & 15)];
      var41 = &(*(((unsigned int *) var0) + 13));
      var42 = *var41;
      *var39 = invSbox[(long) ((int) (var42 >> ((unsigned int) 4)))][(unsigned long) (var42 & 15)];
      var43 = &(*(((unsigned int *) var0) + 9));
      var44 = *var43;
      *var41 = invSbox[(long) ((int) (var44 >> ((unsigned int) 4)))][(unsigned long) (var44 & 15)];
      var45 = &(*(((unsigned int *) var0) + 5));
      var46 = *var45;
      *var43 = invSbox[(long) ((int) (var46 >> ((unsigned int) 4)))][(unsigned long) (var46 & 15)];
      var47 = &(*(((unsigned int *) var0) + 1));
      var48 = *var47;
      *var45 = invSbox[(long) ((int) (var48 >> ((unsigned int) 4)))][(unsigned long) (var48 & 15)];
      *var47 = var38;
      var49 = &(*(((unsigned int *) var0) + 22));
      var50 = *var49;
      var51 = invSbox[(long) ((int) (var50 >> ((unsigned int) 4)))][(unsigned long) (var50 & 15)];
      var52 = &(*(((unsigned int *) var0) + 14));
      var53 = *var52;
      *var49 = invSbox[(long) ((int) (var53 >> ((unsigned int) 4)))][(unsigned long) (var53 & 15)];
      var54 = &(*(((unsigned int *) var0) + 6));
      var55 = *var54;
      *var52 = invSbox[(long) ((int) (var55 >> ((unsigned int) 4)))][(unsigned long) (var55 & 15)];
      *var54 = var51;
      var56 = &(*(((unsigned int *) var0) + 18));
      var57 = *var56;
      var58 = invSbox[(long) ((int) (var57 >> ((unsigned int) 4)))][(unsigned long) (var57 & 15)];
      var59 = &(*(((unsigned int *) var0) + 10));
      var60 = *var59;
      *var56 = invSbox[(long) ((int) (var60 >> ((unsigned int) 4)))][(unsigned long) (var60 & 15)];
      var61 = &(*(((unsigned int *) var0) + 2));
      var62 = *var61;
      *var59 = invSbox[(long) ((int) (var62 >> ((unsigned int) 4)))][(unsigned long) (var62 & 15)];
      *var61 = var58;
      var63 = &(*(((unsigned int *) var0) + 15));
      var64 = *var63;
      var65 = invSbox[(long) ((int) (var64 >> ((unsigned int) 4)))][(unsigned long) (var64 & 15)];
      var66 = &(*(((unsigned int *) var0) + 3));
      var67 = *var66;
      *var63 = invSbox[(long) ((int) (var67 >> ((unsigned int) 4)))][(unsigned long) (var67 & 15)];
      *var66 = var65;
      var68 = &(*(((unsigned int *) var0) + 19));
      var69 = *var68;
      var70 = invSbox[(long) ((int) (var69 >> ((unsigned int) 4)))][(unsigned long) (var69 & 15)];
      var71 = &(*(((unsigned int *) var0) + 7));
      var72 = *var71;
      *var68 = invSbox[(long) ((int) (var72 >> ((unsigned int) 4)))][(unsigned long) (var72 & 15)];
      *var71 = var70;
      var73 = &(*(((unsigned int *) var0) + 23));
      var74 = *var73;
      var75 = invSbox[(long) ((int) (var74 >> ((unsigned int) 4)))][(unsigned long) (var74 & 15)];
      var76 = &(*(((unsigned int *) var0) + 11));
      var77 = *var76;
      *var73 = invSbox[(long) ((int) (var77 >> ((unsigned int) 4)))][(unsigned long) (var77 & 15)];
      *var76 = var75;
      var78 = *var0;
      *var0 = invSbox[(long) ((int) (var78 >> ((unsigned int) 4)))][(unsigned long) (var78 & 15)];
      var79 = &(*(((unsigned int *) var0) + 4));
      var80 = *var79;
      *var79 = invSbox[(long) ((int) (var80 >> ((unsigned int) 4)))][(unsigned long) (var80 & 15)];
      var81 = &(*(((unsigned int *) var0) + 8));
      var82 = *var81;
      *var81 = invSbox[(long) ((int) (var82 >> ((unsigned int) 4)))][(unsigned long) (var82 & 15)];
      var83 = &(*(((unsigned int *) var0) + 12));
      var84 = *var83;
      *var83 = invSbox[(long) ((int) (var84 >> ((unsigned int) 4)))][(unsigned long) (var84 & 15)];
      var85 = &(*(((unsigned int *) var0) + 16));
      var86 = *var85;
      *var85 = invSbox[(long) ((int) (var86 >> ((unsigned int) 4)))][(unsigned long) (var86 & 15)];
      var87 = &(*(((unsigned int *) var0) + 20));
      var156_phi = var87;
      goto block4;

    case 8:
      var88 = &(*(((unsigned int *) var0) + 29));
      var89 = *var88;
      var90 = invSbox[(long) ((int) (var89 >> ((unsigned int) 4)))][(unsigned long) (var89 & 15)];
      var91 = &(*(((unsigned int *) var0) + 25));
      var92 = *var91;
      *var88 = invSbox[(long) ((int) (var92 >> ((unsigned int) 4)))][(unsigned long) (var92 & 15)];
      var93 = &(*(((unsigned int *) var0) + 21));
      var94 = *var93;
      *var91 = invSbox[(long) ((int) (var94 >> ((unsigned int) 4)))][(unsigned long) (var94 & 15)];
      var95 = &(*(((unsigned int *) var0) + 17));
      var96 = *var95;
      *var93 = invSbox[(long) ((int) (var96 >> ((unsigned int) 4)))][(unsigned long) (var96 & 15)];
      var97 = &(*(((unsigned int *) var0) + 13));
      var98 = *var97;
      *var95 = invSbox[(long) ((int) (var98 >> ((unsigned int) 4)))][(unsigned long) (var98 & 15)];
      var99 = &(*(((unsigned int *) var0) + 9));
      var100 = *var99;
      *var97 = invSbox[(long) ((int) (var100 >> ((unsigned int) 4)))][(unsigned long) (var100 & 15)];
      var101 = &(*(((unsigned int *) var0) + 5));
      var102 = *var101;
      *var99 = invSbox[(long) ((int) (var102 >> ((unsigned int) 4)))][(unsigned long) (var102 & 15)];
      var103 = &(*(((unsigned int *) var0) + 1));
      var104 = *var103;
      *var101 = invSbox[(long) ((int) (var104 >> ((unsigned int) 4)))][(unsigned long) (var104 & 15)];
      *var103 = var90;
      var105 = &(*(((unsigned int *) var0) + 30));
      var106 = *var105;
      var107 = invSbox[(long) ((int) (var106 >> ((unsigned int) 4)))][(unsigned long) (var106 & 15)];
      var108 = &(*(((unsigned int *) var0) + 18));
      var109 = *var108;
      *var105 = invSbox[(long) ((int) (var109 >> ((unsigned int) 4)))][(unsigned long) (var109 & 15)];
      var110 = &(*(((unsigned int *) var0) + 6));
      var111 = *var110;
      *var108 = invSbox[(long) ((int) (var111 >> ((unsigned int) 4)))][(unsigned long) (var111 & 15)];
      var112 = &(*(((unsigned int *) var0) + 26));
      var113 = *var112;
      *var110 = invSbox[(long) ((int) (var113 >> ((unsigned int) 4)))][(unsigned long) (var113 & 15)];
      var114 = &(*(((unsigned int *) var0) + 14));
      var115 = *var114;
      *var112 = invSbox[(long) ((int) (var115 >> ((unsigned int) 4)))][(unsigned long) (var115 & 15)];
      var116 = &(*(((unsigned int *) var0) + 2));
      var117 = *var116;
      *var114 = invSbox[(long) ((int) (var117 >> ((unsigned int) 4)))][(unsigned long) (var117 & 15)];
      var118 = &(*(((unsigned int *) var0) + 22));
      var119 = *var118;
      *var116 = invSbox[(long) ((int) (var119 >> ((unsigned int) 4)))][(unsigned long) (var119 & 15)];
      var120 = &(*(((unsigned int *) var0) + 10));
      var121 = *var120;
      *var118 = invSbox[(long) ((int) (var121 >> ((unsigned int) 4)))][(unsigned long) (var121 & 15)];
      *var120 = var107;
      var122 = &(*(((unsigned int *) var0) + 31));
      var123 = *var122;
      var124 = invSbox[(long) ((int) (var123 >> ((unsigned int) 4)))][(unsigned long) (var123 & 15)];
      var125 = &(*(((unsigned int *) var0) + 15));
      var126 = *var125;
      *var122 = invSbox[(long) ((int) (var126 >> ((unsigned int) 4)))][(unsigned long) (var126 & 15)];
      *var125 = var124;
      var127 = &(*(((unsigned int *) var0) + 27));
      var128 = *var127;
      var129 = invSbox[(long) ((int) (var128 >> ((unsigned int) 4)))][(unsigned long) (var128 & 15)];
      var130 = &(*(((unsigned int *) var0) + 11));
      var131 = *var130;
      *var127 = invSbox[(long) ((int) (var131 >> ((unsigned int) 4)))][(unsigned long) (var131 & 15)];
      *var130 = var129;
      var132 = &(*(((unsigned int *) var0) + 23));
      var133 = *var132;
      var134 = invSbox[(long) ((int) (var133 >> ((unsigned int) 4)))][(unsigned long) (var133 & 15)];
      var135 = &(*(((unsigned int *) var0) + 7));
      var136 = *var135;
      *var132 = invSbox[(long) ((int) (var136 >> ((unsigned int) 4)))][(unsigned long) (var136 & 15)];
      *var135 = var134;
      var137 = &(*(((unsigned int *) var0) + 19));
      var138 = *var137;
      var139 = invSbox[(long) ((int) (var138 >> ((unsigned int) 4)))][(unsigned long) (var138 & 15)];
      var140 = &(*(((unsigned int *) var0) + 3));
      var141 = *var140;
      *var137 = invSbox[(long) ((int) (var141 >> ((unsigned int) 4)))][(unsigned long) (var141 & 15)];
      *var140 = var139;
      var142 = *var0;
      *var0 = invSbox[(long) ((int) (var142 >> ((unsigned int) 4)))][(unsigned long) (var142 & 15)];
      var143 = &(*(((unsigned int *) var0) + 4));
      var144 = *var143;
      *var143 = invSbox[(long) ((int) (var144 >> ((unsigned int) 4)))][(unsigned long) (var144 & 15)];
      var145 = &(*(((unsigned int *) var0) + 8));
      var146 = *var145;
      *var145 = invSbox[(long) ((int) (var146 >> ((unsigned int) 4)))][(unsigned long) (var146 & 15)];
      var147 = &(*(((unsigned int *) var0) + 12));
      var148 = *var147;
      *var147 = invSbox[(long) ((int) (var148 >> ((unsigned int) 4)))][(unsigned long) (var148 & 15)];
      var149 = &(*(((unsigned int *) var0) + 16));
      var150 = *var149;
      *var149 = invSbox[(long) ((int) (var150 >> ((unsigned int) 4)))][(unsigned long) (var150 & 15)];
      var151 = &(*(((unsigned int *) var0) + 20));
      var152 = *var151;
      *var151 = invSbox[(long) ((int) (var152 >> ((unsigned int) 4)))][(unsigned long) (var152 & 15)];
      var153 = &(*(((unsigned int *) var0) + 24));
      var154 = *var153;
      *var153 = invSbox[(long) ((int) (var154 >> ((unsigned int) 4)))][(unsigned long) (var154 & 15)];
      var155 = &(*(((unsigned int *) var0) + 28));
      var156_phi = var155;
      goto block4;

    default:
      return;

  }


  block4:
  var157 = *var156_phi;

  *var156_phi = invSbox[(long) ((int) (var157 >> ((unsigned int) 4)))][(unsigned long) (var157 & 15)];
  return;
}

void KeySchedule_2(unsigned int var0_1, unsigned int *var1_1, unsigned int var0_2, unsigned int *var1_2)
{
  unsigned int var2_1[4];
  unsigned int var2_2[4];
  unsigned char *var3_1;
  unsigned char *var3_2;
  unsigned int var4_phi_1;
  unsigned int var4_phi_2;
  unsigned int var5_phi_1;
  unsigned int var5_phi_2;
  unsigned long var6_phi_1;
  unsigned long var6_phi_2;
  unsigned long var7_phi_1;
  unsigned long var7_phi_2;
  unsigned long var9_phi_1;
  unsigned long var9_phi_2;
  unsigned long var21_phi_1;
  unsigned long var21_phi_2;
  unsigned long var24_phi_1;
  unsigned long var24_phi_2;
  unsigned int *var33_phi_1;
  unsigned int *var33_phi_2;
  unsigned int *var34_phi_1;
  unsigned int *var34_phi_2;
  unsigned long var35_phi_1;
  unsigned long var35_phi_2;
  unsigned long var40_phi_1;
  unsigned long var40_phi_2;
  unsigned int var43_phi_1;
  unsigned int var43_phi_2;
  unsigned long var8_1;
  unsigned long var8_2;
  long var10_1;
  long var10_2;
  long var11_1;
  long var11_2;
  unsigned int *var12_1;
  unsigned int *var12_2;
  unsigned int *var13_1;
  unsigned int *var13_2;
  unsigned int *var14_1;
  unsigned int *var14_2;
  unsigned int *var15_1;
  unsigned int *var15_2;
  unsigned int *var16_1;
  unsigned int *var16_2;
  unsigned int *var17_1;
  unsigned int *var17_2;
  unsigned int *var18_1;
  unsigned int *var18_2;
  unsigned int *var19_1;
  unsigned int *var19_2;
  unsigned long var20_1;
  unsigned long var20_2;
  long var22_1;
  long var22_2;
  long var23_1;
  long var23_2;
  unsigned int var25_1;
  unsigned int var25_2;
  long var26_1;
  long var26_2;
  unsigned int var27_1;
  unsigned int var27_2;
  unsigned int var28_1;
  unsigned int var28_2;
  unsigned int var29_1;
  unsigned int var29_2;
  unsigned int var30_1;
  unsigned int var30_2;
  unsigned int *var31_1;
  unsigned int *var31_2;
  unsigned int *var32_1;
  unsigned int *var32_2;
  unsigned int *var36_1;
  unsigned int *var36_2;
  unsigned int var37_1;
  unsigned int var37_2;
  long var38_1;
  long var38_2;
  long var39_1;
  long var39_2;
  long var41_1;
  long var41_2;
  long var42_1;
  long var42_2;
  block0_1:
  var3_1 = (unsigned char *) (&var2_1);

  block0_2:
  var3_2 = (unsigned char *) (&var2_2);

  switch (var0_1)
  {
    case 128128:
      goto block9_1;

    case 128192:
      var4_phi_1 = 0;
      var5_phi_1 = 4;
      var6_phi_1 = 6;
      var7_phi_1 = 13;
      goto block9_1;

    case 128256:
      var4_phi_1 = 0;
      var5_phi_1 = 4;
      var6_phi_1 = 8;
      var7_phi_1 = 15;
      goto block9_1;

    case 192128:
      var4_phi_1 = 0;
      var5_phi_1 = 6;
      var6_phi_1 = 4;
      var7_phi_1 = 13;
      goto block9_1;

    case 192192:
      var4_phi_1 = 0;
      var5_phi_1 = 6;
      var6_phi_1 = 6;
      var7_phi_1 = 13;
      goto block9_1;

    case 192256:
      var4_phi_1 = 0;
      var5_phi_1 = 6;
      var6_phi_1 = 8;
      var7_phi_1 = 15;
      goto block9_1;

    case 256128:
      var4_phi_1 = 1;
      var5_phi_1 = 8;
      var6_phi_1 = 4;
      var7_phi_1 = 15;
      goto block9_1;

    case 256192:
      var4_phi_1 = 1;
      var5_phi_1 = 8;
      var6_phi_1 = 6;
      var7_phi_1 = 15;
      goto block9_1;

    case 256256:
      var4_phi_1 = 1;
      var5_phi_1 = 8;
      var6_phi_1 = 8;
      var7_phi_1 = 15;
      goto block9_1;

    default:
      return var43_phi_1;

  }

  switch (var0_2)
  {
    case 128128:
      goto block9_2;

    case 128192:
      var4_phi_2 = 0;
      var5_phi_2 = 4;
      var6_phi_2 = 6;
      var7_phi_2 = 13;
      goto block9_2;

    case 128256:
      var4_phi_2 = 0;
      var5_phi_2 = 4;
      var6_phi_2 = 8;
      var7_phi_2 = 15;
      goto block9_2;

    case 192128:
      var4_phi_2 = 0;
      var5_phi_2 = 6;
      var6_phi_2 = 4;
      var7_phi_2 = 13;
      goto block9_2;

    case 192192:
      var4_phi_2 = 0;
      var5_phi_2 = 6;
      var6_phi_2 = 6;
      var7_phi_2 = 13;
      goto block9_2;

    case 192256:
      var4_phi_2 = 0;
      var5_phi_2 = 6;
      var6_phi_2 = 8;
      var7_phi_2 = 15;
      goto block9_2;

    case 256128:
      var4_phi_2 = 1;
      var5_phi_2 = 8;
      var6_phi_2 = 4;
      var7_phi_2 = 15;
      goto block9_2;

    case 256192:
      var4_phi_2 = 1;
      var5_phi_2 = 8;
      var6_phi_2 = 6;
      var7_phi_2 = 15;
      goto block9_2;

    case 256256:
      var4_phi_2 = 1;
      var5_phi_2 = 8;
      var6_phi_2 = 8;
      var7_phi_2 = 15;
      goto block9_2;

    default:
      return var43_phi_2;

  }

  block9_1:
  var8_1 = (unsigned long) var5_phi_1;

  block9_2:
  var8_2 = (unsigned long) var5_phi_2;

  var9_phi_1 = 0;
  var9_phi_2 = 0;
  do
  {
    var9_phi_1 = var23_1;
    var9_phi_2 = var23_2;
    var10_1 = ((long) var9_phi_1) << ((long) ((unsigned long) ((long) 2)));
    var10_2 = ((long) var9_phi_2) << ((long) ((unsigned long) ((long) 2)));
    var21_phi_1 = 0;
    var21_phi_2 = 0;
    do
    {
      var21_phi_1 = var22_1;
      var21_phi_2 = var22_2;
      word_1[var21_phi_1][var9_phi_1] = *(((unsigned int *) var1_1) + (((long) var21_phi_1) + ((long) var10_1)));
      word_2[var21_phi_2][var9_phi_2] = *(((unsigned int *) var1_2) + (((long) var21_phi_2) + ((long) var10_2)));
      var22_1 = ((long) var21_phi_1) + ((long) 1);
      var22_2 = ((long) var21_phi_2) + ((long) 1);
    }
    while ((var22_1 == 4) && (var22_2 == 4));
    goto block13_1;
    goto block13_2;
    block13_1:
    var23_1 = ((long) var9_phi_1) + ((long) 1);

    block13_2:
    var23_2 = ((long) var9_phi_2) + ((long) 1);

  }
  while ((var23_1 == var8_1) && (var23_2 == var8_2));
  var11_1 = ((long) var7_phi_1) * ((long) var6_phi_1);
  var11_2 = ((long) var7_phi_2) * ((long) var6_phi_2);
  var12_1 = &var2_1[0];
  var12_2 = &var2_2[0];
  var13_1 = &var2_1[1];
  var13_2 = &var2_2[1];
  var14_1 = &var2_1[2];
  var14_2 = &var2_2[2];
  var15_1 = &var2_1[3];
  var15_2 = &var2_2[3];
  var16_1 = &var2_1[0];
  var16_2 = &var2_2[0];
  var17_1 = &var2_1[1];
  var17_2 = &var2_2[1];
  var18_1 = &var2_1[2];
  var18_2 = &var2_2[2];
  var19_1 = &var2_1[3];
  var19_2 = &var2_2[3];
  var20_1 = (unsigned long) var5_phi_1;
  var20_2 = (unsigned long) var5_phi_2;
  var24_phi_1 = var8_1;
  var24_phi_2 = var8_2;
  do
  {
    var24_phi_1 = var42_1;
    var24_phi_2 = var42_2;
    var25_1 = ((unsigned int) var24_phi_1) % var5_phi_1;
    var25_2 = ((unsigned int) var24_phi_2) % var5_phi_2;
    var26_1 = ((long) var24_phi_1) + ((long) (-1));
    var26_2 = ((long) var24_phi_2) + ((long) (-1));
    if (var25_1 == 0)
    {
      var27_1 = word_1[1][var26_1];
      *var16_1 = Rcon0_1[(long) ((int) (((int) (((unsigned int) var24_phi_1) / var5_phi_1)) + ((int) (-1))))] ^ Sbox_1[(long) ((int) (((int) var27_1) / ((int) 16)))][(long) ((int) (((int) var27_1) % ((int) 16)))];
      var28_1 = word_1[2][var26_1];
      *var17_1 = Sbox_1[(long) ((int) (((int) var28_1) / ((int) 16)))][(long) ((int) (((int) var28_1) % ((int) 16)))];
      var29_1 = word_1[3][var26_1];
      *var18_1 = Sbox_1[(long) ((int) (((int) var29_1) / ((int) 16)))][(long) ((int) (((int) var29_1) % ((int) 16)))];
      var30_1 = word_1[0][var26_1];
      var31_1 = &Sbox_1[(long) ((int) (((int) var30_1) / ((int) 16)))][(long) ((int) (((int) var30_1) % ((int) 16)))];
      var33_phi_1 = var31_1;
      var34_phi_1 = var19_1;
      goto block17_1;
    }
    else
    {
      *var12_1 = word_1[0][var26_1];
      *var13_1 = word_1[1][var26_1];
      *var14_1 = word_1[2][var26_1];
      var32_1 = &word_1[3][var26_1];
      var33_phi_1 = var32_1;
      var34_phi_1 = var15_1;
      goto block17_1;
    }
    if (var25_2 == 0)
    {
      var27_2 = word_2[1][var26_2];
      *var16_2 = Rcon0_2[(long) ((int) (((int) (((unsigned int) var24_phi_2) / var5_phi_2)) + ((int) (-1))))] ^ Sbox_2[(long) ((int) (((int) var27_2) / ((int) 16)))][(long) ((int) (((int) var27_2) % ((int) 16)))];
      var28_2 = word_2[2][var26_2];
      *var17_2 = Sbox_2[(long) ((int) (((int) var28_2) / ((int) 16)))][(long) ((int) (((int) var28_2) % ((int) 16)))];
      var29_2 = word_2[3][var26_2];
      *var18_2 = Sbox_2[(long) ((int) (((int) var29_2) / ((int) 16)))][(long) ((int) (((int) var29_2) % ((int) 16)))];
      var30_2 = word_2[0][var26_2];
      var31_2 = &Sbox_2[(long) ((int) (((int) var30_2) / ((int) 16)))][(long) ((int) (((int) var30_2) % ((int) 16)))];
      var33_phi_2 = var31_2;
      var34_phi_2 = var19_2;
      goto block17_2;
    }
    else
    {
      *var12_2 = word_2[0][var26_2];
      *var13_2 = word_2[1][var26_2];
      *var14_2 = word_2[2][var26_2];
      var32_2 = &word_2[3][var26_2];
      var33_phi_2 = var32_2;
      var34_phi_2 = var15_2;
      goto block17_2;
    }
    block23_1:
    var42_1 = ((long) var24_phi_1) + ((long) 1);

    block23_2:
    var42_2 = ((long) var24_phi_2) + ((long) 1);

  }
  while ((var42_1 == var11_1) && (var42_2 == var11_2));
  var43_phi_1 = 0;
  var43_phi_2 = 0;
  block17_1:
  *var34_phi_1 = *var33_phi_1;

  block17_2:
  *var34_phi_2 = *var33_phi_2;

  if ((var4_phi_1) ? (var25_1 == 4) : (0))
  {
    var35_phi_1 = 0;
    do
    {
      var35_phi_1 = var38_1;
      var36_1 = &var2_1[var35_phi_1];
      var37_1 = *var36_1;
      *var36_1 = Sbox_1[(long) ((int) (((int) var37_1) / ((int) 16)))][(long) ((int) (((int) var37_1) % ((int) 16)))];
      var38_1 = ((long) var35_phi_1) + ((long) 1);
    }
    while (var38_1 == 4);
    goto block21_1;
  }
  else
  {
    goto block21_1;
  }
  if ((var4_phi_2) ? (var25_2 == 4) : (0))
  {
    var35_phi_2 = 0;
    do
    {
      var35_phi_2 = var38_2;
      var36_2 = &var2_2[var35_phi_2];
      var37_2 = *var36_2;
      *var36_2 = Sbox_2[(long) ((int) (((int) var37_2) / ((int) 16)))][(long) ((int) (((int) var37_2) % ((int) 16)))];
      var38_2 = ((long) var35_phi_2) + ((long) 1);
    }
    while (var38_2 == 4);
    goto block21_2;
  }
  else
  {
    goto block21_2;
  }
  block21_1:
  var39_1 = ((long) var24_phi_1) - ((long) var20_1);

  block21_2:
  var39_2 = ((long) var24_phi_2) - ((long) var20_2);

  var40_phi_1 = 0;
  var40_phi_2 = 0;
  do
  {
    var40_phi_1 = var41_1;
    var40_phi_2 = var41_2;
    word_1[var40_phi_1][var24_phi_1] = var2_1[var40_phi_1] ^ word_1[var40_phi_1][var39_1];
    word_2[var40_phi_2][var24_phi_2] = var2_2[var40_phi_2] ^ word_2[var40_phi_2][var39_2];
    var41_1 = ((long) var40_phi_1) + ((long) 1);
    var41_2 = ((long) var40_phi_2) + ((long) 1);
  }
  while ((var41_1 == 4) && (var41_2 == 4));
  goto block23_1;
  goto block23_2;
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    for (int i_1 = 0; i_1 < 16; i_1++)
    {
      assert(Sbox_1[i_0][i_1] == Sbox_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < 30; i_0++)
  {
    assert(Rcon0_1[i_0] == Rcon0_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(var2_1[i_0] == var2_2[i_0]);
  }

  assert((*var3_1) == (*var3_2));
  assert(var4_phi_1 == var4_phi_2);
  assert(var5_phi_1 == var5_phi_2);
  assert(var6_phi_1 == var6_phi_2);
  assert(var7_phi_1 == var7_phi_2);
  assert(var9_phi_1 == var9_phi_2);
  assert(var21_phi_1 == var21_phi_2);
  assert(var24_phi_1 == var24_phi_2);
  assert((*var33_phi_1) == (*var33_phi_2));
  assert((*var34_phi_1) == (*var34_phi_2));
  assert(var35_phi_1 == var35_phi_2);
  assert(var40_phi_1 == var40_phi_2);
  assert(var43_phi_1 == var43_phi_2);
  assert(var8_1 == var8_2);
  assert(var10_1 == var10_2);
  assert(var11_1 == var11_2);
  assert((*var12_1) == (*var12_2));
  assert((*var13_1) == (*var13_2));
  assert((*var14_1) == (*var14_2));
  assert((*var15_1) == (*var15_2));
  assert((*var16_1) == (*var16_2));
  assert((*var17_1) == (*var17_2));
  assert((*var18_1) == (*var18_2));
  assert((*var19_1) == (*var19_2));
  assert(var20_1 == var20_2);
  assert(var22_1 == var22_2);
  assert(var23_1 == var23_2);
  assert(var25_1 == var25_2);
  assert(var26_1 == var26_2);
  assert(var27_1 == var27_2);
  assert(var28_1 == var28_2);
  assert(var29_1 == var29_2);
  assert(var30_1 == var30_2);
  assert((*var31_1) == (*var31_2));
  assert((*var32_1) == (*var32_2));
  assert((*var36_1) == (*var36_2));
  assert(var37_1 == var37_2);
  assert(var38_1 == var38_2);
  assert(var39_1 == var39_2);
  assert(var41_1 == var41_2);
  assert(var42_1 == var42_2);
}

unsigned int KeySchedule(unsigned int var0, unsigned int *var1)
{
  unsigned int var2[4];
  unsigned char *var3;
  unsigned int var4_phi;
  unsigned int var5_phi;
  unsigned long var6_phi;
  unsigned long var7_phi;
  unsigned long var9_phi;
  unsigned long var21_phi;
  unsigned long var24_phi;
  unsigned int *var33_phi;
  unsigned int *var34_phi;
  unsigned long var35_phi;
  unsigned long var40_phi;
  unsigned int var43_phi;
  unsigned long var8;
  long var10;
  long var11;
  unsigned int *var12;
  unsigned int *var13;
  unsigned int *var14;
  unsigned int *var15;
  unsigned int *var16;
  unsigned int *var17;
  unsigned int *var18;
  unsigned int *var19;
  unsigned long var20;
  long var22;
  long var23;
  unsigned int var25;
  long var26;
  unsigned int var27;
  unsigned int var28;
  unsigned int var29;
  unsigned int var30;
  unsigned int *var31;
  unsigned int *var32;
  unsigned int *var36;
  unsigned int var37;
  long var38;
  long var39;
  long var41;
  long var42;
  block0:
  var3 = (unsigned char *) (&var2);

  switch (var0)
  {
    case 128128:
      goto block9;

    case 128192:
      var4_phi = 0;
      var5_phi = 4;
      var6_phi = 6;
      var7_phi = 13;
      goto block9;

    case 128256:
      var4_phi = 0;
      var5_phi = 4;
      var6_phi = 8;
      var7_phi = 15;
      goto block9;

    case 192128:
      var4_phi = 0;
      var5_phi = 6;
      var6_phi = 4;
      var7_phi = 13;
      goto block9;

    case 192192:
      var4_phi = 0;
      var5_phi = 6;
      var6_phi = 6;
      var7_phi = 13;
      goto block9;

    case 192256:
      var4_phi = 0;
      var5_phi = 6;
      var6_phi = 8;
      var7_phi = 15;
      goto block9;

    case 256128:
      var4_phi = 1;
      var5_phi = 8;
      var6_phi = 4;
      var7_phi = 15;
      goto block9;

    case 256192:
      var4_phi = 1;
      var5_phi = 8;
      var6_phi = 6;
      var7_phi = 15;
      goto block9;

    case 256256:
      var4_phi = 1;
      var5_phi = 8;
      var6_phi = 8;
      var7_phi = 15;
      goto block9;

    default:
      return var43_phi;

  }

  block9:
  var8 = (unsigned long) var5_phi;

  var9_phi = 0;
  do
  {
    var9_phi = var23;
    var10 = ((long) var9_phi) << ((long) ((unsigned long) ((long) 2)));
    var21_phi = 0;
    do
    {
      var21_phi = var22;
      word[var21_phi][var9_phi] = *(((unsigned int *) var1) + (((long) var21_phi) + ((long) var10)));
      var22 = ((long) var21_phi) + ((long) 1);
    }
    while (var22 == 4);
    goto block13;
    block13:
    var23 = ((long) var9_phi) + ((long) 1);

  }
  while (var23 == var8);
  var11 = ((long) var7_phi) * ((long) var6_phi);
  var12 = &var2[0];
  var13 = &var2[1];
  var14 = &var2[2];
  var15 = &var2[3];
  var16 = &var2[0];
  var17 = &var2[1];
  var18 = &var2[2];
  var19 = &var2[3];
  var20 = (unsigned long) var5_phi;
  var24_phi = var8;
  do
  {
    var24_phi = var42;
    var25 = ((unsigned int) var24_phi) % var5_phi;
    var26 = ((long) var24_phi) + ((long) (-1));
    if (var25 == 0)
    {
      var27 = word[1][var26];
      *var16 = Rcon0[(long) ((int) (((int) (((unsigned int) var24_phi) / var5_phi)) + ((int) (-1))))] ^ Sbox[(long) ((int) (((int) var27) / ((int) 16)))][(long) ((int) (((int) var27) % ((int) 16)))];
      var28 = word[2][var26];
      *var17 = Sbox[(long) ((int) (((int) var28) / ((int) 16)))][(long) ((int) (((int) var28) % ((int) 16)))];
      var29 = word[3][var26];
      *var18 = Sbox[(long) ((int) (((int) var29) / ((int) 16)))][(long) ((int) (((int) var29) % ((int) 16)))];
      var30 = word[0][var26];
      var31 = &Sbox[(long) ((int) (((int) var30) / ((int) 16)))][(long) ((int) (((int) var30) % ((int) 16)))];
      var33_phi = var31;
      var34_phi = var19;
      goto block17;
    }
    else
    {
      *var12 = word[0][var26];
      *var13 = word[1][var26];
      *var14 = word[2][var26];
      var32 = &word[3][var26];
      var33_phi = var32;
      var34_phi = var15;
      goto block17;
    }
    block23:
    var42 = ((long) var24_phi) + ((long) 1);

  }
  while (var42 == var11);
  var43_phi = 0;
  return var43_phi;
  block17:
  *var34_phi = *var33_phi;

  if ((var4_phi) ? (var25 == 4) : (0))
  {
    var35_phi = 0;
    do
    {
      var35_phi = var38;
      var36 = &var2[var35_phi];
      var37 = *var36;
      *var36 = Sbox[(long) ((int) (((int) var37) / ((int) 16)))][(long) ((int) (((int) var37) % ((int) 16)))];
      var38 = ((long) var35_phi) + ((long) 1);
    }
    while (var38 == 4);
    goto block21;
  }
  else
  {
    goto block21;
  }
  block21:
  var39 = ((long) var24_phi) - ((long) var20);

  var40_phi = 0;
  do
  {
    var40_phi = var41;
    word[var40_phi][var24_phi] = var2[var40_phi] ^ word[var40_phi][var39];
    var41 = ((long) var40_phi) + ((long) 1);
  }
  while (var41 == 4);
  goto block23;
}

void MixColumn_AddRoundKey_2(unsigned int *var0_1, unsigned int var1_1, unsigned int var2_1, unsigned int *var0_2, unsigned int var1_2, unsigned int var2_2)
{
  unsigned int var3_1[32];
  unsigned int var3_2[32];
  unsigned char *var4_1;
  unsigned char *var4_2;
  unsigned long var8_phi_1;
  unsigned long var8_phi_2;
  unsigned long var39_phi_1;
  unsigned long var39_phi_2;
  long var5_1;
  long var5_2;
  unsigned long var6_1;
  unsigned long var6_2;
  unsigned long var7_1;
  unsigned long var7_2;
  long var9_1;
  long var9_2;
  unsigned int var10_1;
  unsigned int var10_2;
  unsigned int var11_1;
  unsigned int var11_2;
  unsigned int *var12_1;
  unsigned int *var12_2;
  unsigned int var13_1;
  unsigned int var13_2;
  long var14_1;
  long var14_2;
  unsigned int var15_1;
  unsigned int var15_2;
  unsigned int var16_1;
  unsigned int var16_2;
  unsigned int var17_1;
  unsigned int var17_2;
  unsigned int var18_1;
  unsigned int var18_2;
  long var19_1;
  long var19_2;
  unsigned int var20_1;
  unsigned int var20_2;
  long var21_1;
  long var21_2;
  unsigned int var22_1;
  unsigned int var22_2;
  long var23_1;
  long var23_2;
  unsigned int *var24_1;
  unsigned int *var24_2;
  unsigned int var25_1;
  unsigned int var25_2;
  unsigned int var26_1;
  unsigned int var26_2;
  unsigned int var27_1;
  unsigned int var27_2;
  unsigned int var28_1;
  unsigned int var28_2;
  unsigned int *var29_1;
  unsigned int *var29_2;
  unsigned int var30_1;
  unsigned int var30_2;
  unsigned int var31_1;
  unsigned int var31_2;
  unsigned int var32_1;
  unsigned int var32_2;
  unsigned int var33_1;
  unsigned int var33_2;
  unsigned int *var34_1;
  unsigned int *var34_2;
  unsigned int var35_1;
  unsigned int var35_2;
  unsigned int var36_1;
  unsigned int var36_2;
  unsigned int var37_1;
  unsigned int var37_2;
  long var38_1;
  long var38_2;
  long var40_1;
  long var40_2;
  long var41_1;
  long var41_2;
  long var42_1;
  long var42_2;
  long var43_1;
  long var43_2;
  long var44_1;
  long var44_2;
  block0_1:
  var4_1 = (unsigned char *) (&var3_1);

  block0_2:
  var4_2 = (unsigned char *) (&var3_2);

  if (((int) var1_1) > ((int) 0))
  {
    var5_1 = (long) ((int) (((int) var2_1) * ((int) var1_1)));
    var6_1 = (unsigned long) var1_1;
    var8_phi_1 = 0;
    do
    {
      var8_phi_1 = var38_1;
      var9_1 = ((long) var8_phi_1) << ((long) ((unsigned long) ((long) 2)));
      var10_1 = *(((unsigned int *) var0_1) + var9_1);
      var11_1 = var10_1 << ((unsigned int) 1);
      var12_1 = &var3_1[var9_1];
      var13_1 = ((var10_1 & 2147483520) == 128) ? (var11_1 ^ 283) : (var11_1);
      *var12_1 = var13_1;
      var14_1 = var9_1 | 1;
      var15_1 = *(((unsigned int *) var0_1) + var14_1);
      var16_1 = var15_1 << ((unsigned int) 1);
      var17_1 = var16_1 ^ var15_1;
      var18_1 = ((var17_1 & (-256)) == 256) ? ((var17_1 ^ var13_1) ^ 283) : (var17_1 ^ var13_1);
      *var12_1 = var18_1;
      var19_1 = var9_1 | 2;
      var20_1 = *(((unsigned int *) var0_1) + var19_1);
      var21_1 = var9_1 | 3;
      var22_1 = *(((unsigned int *) var0_1) + var21_1);
      var23_1 = ((long) var8_phi_1) + ((long) var5_1);
      *var12_1 = ((var22_1 ^ var20_1) ^ word_1[0][var23_1]) ^ var18_1;
      var24_1 = &var3_1[var14_1];
      var25_1 = ((var15_1 & 2147483520) == 128) ? (var16_1 ^ 283) : (var16_1);
      *var24_1 = var25_1;
      var26_1 = var20_1 << ((unsigned int) 1);
      var27_1 = var26_1 ^ var20_1;
      var28_1 = ((var27_1 & (-256)) == 256) ? ((var27_1 ^ var25_1) ^ 283) : (var27_1 ^ var25_1);
      *var24_1 = var28_1;
      *var24_1 = ((var22_1 ^ var10_1) ^ var28_1) ^ word_1[1][var23_1];
      var29_1 = &var3_1[var19_1];
      var30_1 = ((var20_1 & 2147483520) == 128) ? (var26_1 ^ 283) : (var26_1);
      *var29_1 = var30_1;
      var31_1 = var22_1 << ((unsigned int) 1);
      var32_1 = var31_1 ^ var22_1;
      var33_1 = ((var32_1 & (-256)) == 256) ? ((var32_1 ^ var30_1) ^ 283) : (var30_1 ^ var32_1);
      *var29_1 = var33_1;
      *var29_1 = ((var15_1 ^ var10_1) ^ var33_1) ^ word_1[2][var23_1];
      var34_1 = &var3_1[var21_1];
      var35_1 = ((var22_1 & 2147483520) == 128) ? (var31_1 ^ 283) : (var31_1);
      *var34_1 = var35_1;
      var36_1 = var11_1 ^ var10_1;
      var37_1 = ((var36_1 & (-256)) == 256) ? ((var35_1 ^ var36_1) ^ 283) : (var35_1 ^ var36_1);
      *var34_1 = var37_1;
      *var34_1 = ((var20_1 ^ var15_1) ^ var37_1) ^ word_1[3][var23_1];
      var38_1 = ((long) var8_phi_1) + ((long) 1);
    }
    while (var38_1 == var6_1);
    goto block3_1;
  }
  else
  {
    goto block3_1;
  }
  if (((int) var1_2) > ((int) 0))
  {
    var5_2 = (long) ((int) (((int) var2_2) * ((int) var1_2)));
    var6_2 = (unsigned long) var1_2;
    var8_phi_2 = 0;
    do
    {
      var8_phi_2 = var38_2;
      var9_2 = ((long) var8_phi_2) << ((long) ((unsigned long) ((long) 2)));
      var10_2 = *(((unsigned int *) var0_2) + var9_2);
      var11_2 = var10_2 << ((unsigned int) 1);
      var12_2 = &var3_2[var9_2];
      var13_2 = ((var10_2 & 2147483520) == 128) ? (var11_2 ^ 283) : (var11_2);
      *var12_2 = var13_2;
      var14_2 = var9_2 | 1;
      var15_2 = *(((unsigned int *) var0_2) + var14_2);
      var16_2 = var15_2 << ((unsigned int) 1);
      var17_2 = var16_2 ^ var15_2;
      var18_2 = ((var17_2 & (-256)) == 256) ? ((var17_2 ^ var13_2) ^ 283) : (var17_2 ^ var13_2);
      *var12_2 = var18_2;
      var19_2 = var9_2 | 2;
      var20_2 = *(((unsigned int *) var0_2) + var19_2);
      var21_2 = var9_2 | 3;
      var22_2 = *(((unsigned int *) var0_2) + var21_2);
      var23_2 = ((long) var8_phi_2) + ((long) var5_2);
      *var12_2 = ((var22_2 ^ var20_2) ^ word_2[0][var23_2]) ^ var18_2;
      var24_2 = &var3_2[var14_2];
      var25_2 = ((var15_2 & 2147483520) == 128) ? (var16_2 ^ 283) : (var16_2);
      *var24_2 = var25_2;
      var26_2 = var20_2 << ((unsigned int) 1);
      var27_2 = var26_2 ^ var20_2;
      var28_2 = ((var27_2 & (-256)) == 256) ? ((var27_2 ^ var25_2) ^ 283) : (var27_2 ^ var25_2);
      *var24_2 = var28_2;
      *var24_2 = ((var22_2 ^ var10_2) ^ var28_2) ^ word_2[1][var23_2];
      var29_2 = &var3_2[var19_2];
      var30_2 = ((var20_2 & 2147483520) == 128) ? (var26_2 ^ 283) : (var26_2);
      *var29_2 = var30_2;
      var31_2 = var22_2 << ((unsigned int) 1);
      var32_2 = var31_2 ^ var22_2;
      var33_2 = ((var32_2 & (-256)) == 256) ? ((var32_2 ^ var30_2) ^ 283) : (var30_2 ^ var32_2);
      *var29_2 = var33_2;
      *var29_2 = ((var15_2 ^ var10_2) ^ var33_2) ^ word_2[2][var23_2];
      var34_2 = &var3_2[var21_2];
      var35_2 = ((var22_2 & 2147483520) == 128) ? (var31_2 ^ 283) : (var31_2);
      *var34_2 = var35_2;
      var36_2 = var11_2 ^ var10_2;
      var37_2 = ((var36_2 & (-256)) == 256) ? ((var35_2 ^ var36_2) ^ 283) : (var35_2 ^ var36_2);
      *var34_2 = var37_2;
      *var34_2 = ((var20_2 ^ var15_2) ^ var37_2) ^ word_2[3][var23_2];
      var38_2 = ((long) var8_phi_2) + ((long) 1);
    }
    while (var38_2 == var6_2);
    goto block3_2;
  }
  else
  {
    goto block3_2;
  }
  block3_1:
  if (((int) var1_1) > ((int) 0))
  {
    var7_1 = (unsigned long) var1_1;
    var39_phi_1 = 0;
    do
    {
      var39_phi_1 = var44_1;
      var40_1 = ((long) var39_phi_1) << ((long) ((unsigned long) ((long) 2)));
      *(((unsigned int *) var0_1) + var40_1) = var3_1[var40_1];
      var41_1 = var40_1 | 1;
      *(((unsigned int *) var0_1) + var41_1) = var3_1[var41_1];
      var42_1 = var40_1 | 2;
      *(((unsigned int *) var0_1) + var42_1) = var3_1[var42_1];
      var43_1 = var40_1 | 3;
      *(((unsigned int *) var0_1) + var43_1) = var3_1[var43_1];
      var44_1 = ((long) var39_phi_1) + ((long) 1);
    }
    while (var44_1 == var7_1);
    return 0;
  }
  else
  {
    return 0;
  }

  block3_2:
  if (((int) var1_2) > ((int) 0))
  {
    var7_2 = (unsigned long) var1_2;
    var39_phi_2 = 0;
    do
    {
      var39_phi_2 = var44_2;
      var40_2 = ((long) var39_phi_2) << ((long) ((unsigned long) ((long) 2)));
      *(((unsigned int *) var0_2) + var40_2) = var3_2[var40_2];
      var41_2 = var40_2 | 1;
      *(((unsigned int *) var0_2) + var41_2) = var3_2[var41_2];
      var42_2 = var40_2 | 2;
      *(((unsigned int *) var0_2) + var42_2) = var3_2[var42_2];
      var43_2 = var40_2 | 3;
      *(((unsigned int *) var0_2) + var43_2) = var3_2[var43_2];
      var44_2 = ((long) var39_phi_2) + ((long) 1);
    }
    while (var44_2 == var7_2);
    return 0;
  }
  else
  {
    return 0;
  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(var3_1[i_0] == var3_2[i_0]);
  }

  assert((*var4_1) == (*var4_2));
  assert(var8_phi_1 == var8_phi_2);
  assert(var39_phi_1 == var39_phi_2);
  assert(var5_1 == var5_2);
  assert(var6_1 == var6_2);
  assert(var7_1 == var7_2);
  assert(var9_1 == var9_2);
  assert(var10_1 == var10_2);
  assert(var11_1 == var11_2);
  assert((*var12_1) == (*var12_2));
  assert(var13_1 == var13_2);
  assert(var14_1 == var14_2);
  assert(var15_1 == var15_2);
  assert(var16_1 == var16_2);
  assert(var17_1 == var17_2);
  assert(var18_1 == var18_2);
  assert(var19_1 == var19_2);
  assert(var20_1 == var20_2);
  assert(var21_1 == var21_2);
  assert(var22_1 == var22_2);
  assert(var23_1 == var23_2);
  assert((*var24_1) == (*var24_2));
  assert(var25_1 == var25_2);
  assert(var26_1 == var26_2);
  assert(var27_1 == var27_2);
  assert(var28_1 == var28_2);
  assert((*var29_1) == (*var29_2));
  assert(var30_1 == var30_2);
  assert(var31_1 == var31_2);
  assert(var32_1 == var32_2);
  assert(var33_1 == var33_2);
  assert((*var34_1) == (*var34_2));
  assert(var35_1 == var35_2);
  assert(var36_1 == var36_2);
  assert(var37_1 == var37_2);
  assert(var38_1 == var38_2);
  assert(var40_1 == var40_2);
  assert(var41_1 == var41_2);
  assert(var42_1 == var42_2);
  assert(var43_1 == var43_2);
  assert(var44_1 == var44_2);
}

unsigned int MixColumn_AddRoundKey(unsigned int *var0, unsigned int var1, unsigned int var2)
{
  unsigned int var3[32];
  unsigned char *var4;
  unsigned long var8_phi;
  unsigned long var39_phi;
  long var5;
  unsigned long var6;
  unsigned long var7;
  long var9;
  unsigned int var10;
  unsigned int var11;
  unsigned int *var12;
  unsigned int var13;
  long var14;
  unsigned int var15;
  unsigned int var16;
  unsigned int var17;
  unsigned int var18;
  long var19;
  unsigned int var20;
  long var21;
  unsigned int var22;
  long var23;
  unsigned int *var24;
  unsigned int var25;
  unsigned int var26;
  unsigned int var27;
  unsigned int var28;
  unsigned int *var29;
  unsigned int var30;
  unsigned int var31;
  unsigned int var32;
  unsigned int var33;
  unsigned int *var34;
  unsigned int var35;
  unsigned int var36;
  unsigned int var37;
  long var38;
  long var40;
  long var41;
  long var42;
  long var43;
  long var44;
  block0:
  var4 = (unsigned char *) (&var3);

  if (((int) var1) > ((int) 0))
  {
    var5 = (long) ((int) (((int) var2) * ((int) var1)));
    var6 = (unsigned long) var1;
    var8_phi = 0;
    do
    {
      var8_phi = var38;
      var9 = ((long) var8_phi) << ((long) ((unsigned long) ((long) 2)));
      var10 = *(((unsigned int *) var0) + var9);
      var11 = var10 << ((unsigned int) 1);
      var12 = &var3[var9];
      var13 = ((var10 & 2147483520) == 128) ? (var11 ^ 283) : (var11);
      *var12 = var13;
      var14 = var9 | 1;
      var15 = *(((unsigned int *) var0) + var14);
      var16 = var15 << ((unsigned int) 1);
      var17 = var16 ^ var15;
      var18 = ((var17 & (-256)) == 256) ? ((var17 ^ var13) ^ 283) : (var17 ^ var13);
      *var12 = var18;
      var19 = var9 | 2;
      var20 = *(((unsigned int *) var0) + var19);
      var21 = var9 | 3;
      var22 = *(((unsigned int *) var0) + var21);
      var23 = ((long) var8_phi) + ((long) var5);
      *var12 = ((var22 ^ var20) ^ word[0][var23]) ^ var18;
      var24 = &var3[var14];
      var25 = ((var15 & 2147483520) == 128) ? (var16 ^ 283) : (var16);
      *var24 = var25;
      var26 = var20 << ((unsigned int) 1);
      var27 = var26 ^ var20;
      var28 = ((var27 & (-256)) == 256) ? ((var27 ^ var25) ^ 283) : (var27 ^ var25);
      *var24 = var28;
      *var24 = ((var22 ^ var10) ^ var28) ^ word[1][var23];
      var29 = &var3[var19];
      var30 = ((var20 & 2147483520) == 128) ? (var26 ^ 283) : (var26);
      *var29 = var30;
      var31 = var22 << ((unsigned int) 1);
      var32 = var31 ^ var22;
      var33 = ((var32 & (-256)) == 256) ? ((var32 ^ var30) ^ 283) : (var30 ^ var32);
      *var29 = var33;
      *var29 = ((var15 ^ var10) ^ var33) ^ word[2][var23];
      var34 = &var3[var21];
      var35 = ((var22 & 2147483520) == 128) ? (var31 ^ 283) : (var31);
      *var34 = var35;
      var36 = var11 ^ var10;
      var37 = ((var36 & (-256)) == 256) ? ((var35 ^ var36) ^ 283) : (var35 ^ var36);
      *var34 = var37;
      *var34 = ((var20 ^ var15) ^ var37) ^ word[3][var23];
      var38 = ((long) var8_phi) + ((long) 1);
    }
    while (var38 == var6);
    goto block3;
  }
  else
  {
    goto block3;
  }
  block3:
  if (((int) var1) > ((int) 0))
  {
    var7 = (unsigned long) var1;
    var39_phi = 0;
    do
    {
      var39_phi = var44;
      var40 = ((long) var39_phi) << ((long) ((unsigned long) ((long) 2)));
      *(((unsigned int *) var0) + var40) = var3[var40];
      var41 = var40 | 1;
      *(((unsigned int *) var0) + var41) = var3[var41];
      var42 = var40 | 2;
      *(((unsigned int *) var0) + var42) = var3[var42];
      var43 = var40 | 3;
      *(((unsigned int *) var0) + var43) = var3[var43];
      var44 = ((long) var39_phi) + ((long) 1);
    }
    while (var44 == var7);
    return 0;
  }
  else
  {
    return 0;
  }

}

void SubByte_2(unsigned int var0_1, unsigned int var0_2)
{
  block0_1:
  return Sbox_1[(long) ((int) (((int) var0_1) / ((int) 16)))][(long) ((int) (((int) var0_1) % ((int) 16)))];

  block0_2:
  return Sbox_2[(long) ((int) (((int) var0_2) / ((int) 16)))][(long) ((int) (((int) var0_2) % ((int) 16)))];

  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    for (int i_1 = 0; i_1 < 16; i_1++)
    {
      assert(Sbox_1[i_0][i_1] == Sbox_2[i_0][i_1]);
    }

  }

}

unsigned int SubByte(unsigned int var0)
{
  block0:
  return Sbox[(long) ((int) (((int) var0) / ((int) 16)))][(long) ((int) (((int) var0) % ((int) 16)))];

}

void aes_main_2()
{
  block0_1:
  encrypt(&statemt_1[0], &key_1[0], 128128);

  block0_2:
  encrypt(&statemt_2[0], &key_2[0], 128128);

  encrypt_2(&statemt_1[0], &key_1[0], 128128, &statemt_2[0], &key_2[0], 128128);
  decrypt(&statemt_1[0], &key_1[0], 128128);
  decrypt(&statemt_2[0], &key_2[0], 128128);
  decrypt_2(&statemt_1[0], &key_1[0], 128128, &statemt_2[0], &key_2[0], 128128);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(statemt_1[i_0] == statemt_2[i_0]);
  }

}

unsigned int aes_main()
{
  block0:
  encrypt(&statemt[0], &key[0], 128128);

  decrypt(&statemt[0], &key[0], 128128);
  return 0;
}

void decrypt_2(unsigned int *var0_1, unsigned int *var1_1, unsigned int var2_1, unsigned int *var0_2, unsigned int *var1_2, unsigned int var2_2)
{
  unsigned int var3_phi_1;
  unsigned int var3_phi_2;
  unsigned int var4_phi_1;
  unsigned int var4_phi_2;
  unsigned int var6_phi_1;
  unsigned int var6_phi_2;
  unsigned long var9_phi_1;
  unsigned long var9_phi_2;
  unsigned int var18_phi_1;
  unsigned int var18_phi_2;
  unsigned long var20_phi_1;
  unsigned long var20_phi_2;
  unsigned long var21_phi_1;
  unsigned long var21_phi_2;
  unsigned long var30_phi_1;
  unsigned long var30_phi_2;
  unsigned long var33_phi_1;
  unsigned long var33_phi_2;
  unsigned int var5_1;
  unsigned int var5_2;
  long var7_1;
  long var7_2;
  unsigned long var8_1;
  unsigned long var8_2;
  long var10_1;
  long var10_2;
  long var11_1;
  long var11_2;
  unsigned int *var12_1;
  unsigned int *var12_2;
  unsigned int *var13_1;
  unsigned int *var13_2;
  unsigned int *var14_1;
  unsigned int *var14_2;
  unsigned int *var15_1;
  unsigned int *var15_2;
  long var16_1;
  long var16_2;
  unsigned int var17_1;
  unsigned int var17_2;
  int var19_1;
  int var19_2;
  long var22_1;
  long var22_2;
  unsigned int *var23_1;
  unsigned int *var23_2;
  unsigned int *var24_1;
  unsigned int *var24_2;
  unsigned int *var25_1;
  unsigned int *var25_2;
  unsigned int *var26_1;
  unsigned int *var26_2;
  long var27_1;
  long var27_2;
  int var28_1;
  int var28_2;
  unsigned long var29_1;
  unsigned long var29_2;
  unsigned int *var31_1;
  unsigned int *var31_2;
  long var32_1;
  long var32_2;
  long var34_1;
  long var34_2;
  block0_1:
  KeySchedule(var2_1, var1_1);

  block0_2:
  KeySchedule(var2_2, var1_2);

  KeySchedule_2(var2_1, var1_1, var2_2, var1_2);
  switch (var2_1)
  {
    case 128128:
      goto block7_1;

    case 128192:
      goto block1_1;

    case 128256:
      goto block3_1;

    case 192128:
      var3_phi_1 = 12;
      var4_phi_1 = 4;
      goto block7_1;

    case 192192:
      goto block1_1;

    case 192256:
      goto block3_1;

    case 256128:
      var3_phi_1 = 14;
      var4_phi_1 = 4;
      goto block7_1;

    case 256192:
      var3_phi_1 = 14;
      var4_phi_1 = 6;
      goto block7_1;

    case 256256:
      var3_phi_1 = 14;
      var4_phi_1 = 8;
      goto block7_1;

    default:
      goto block8_1;

  }

  switch (var2_2)
  {
    case 128128:
      goto block7_2;

    case 128192:
      goto block1_2;

    case 128256:
      goto block3_2;

    case 192128:
      var3_phi_2 = 12;
      var4_phi_2 = 4;
      goto block7_2;

    case 192192:
      goto block1_2;

    case 192256:
      goto block3_2;

    case 256128:
      var3_phi_2 = 14;
      var4_phi_2 = 4;
      goto block7_2;

    case 256192:
      var3_phi_2 = 14;
      var4_phi_2 = 6;
      goto block7_2;

    case 256256:
      var3_phi_2 = 14;
      var4_phi_2 = 8;
      goto block7_2;

    default:
      goto block8_2;

  }

  block8_1:
  var5_1 = round_val_1;

  block8_2:
  var5_2 = round_val_2;

  switch (var2_1)
  {
    case 128192:
      goto block9_1;

    case 128256:
      goto block10_1;

    case 192192:
      goto block9_1;

    case 192256:
      goto block10_1;

    case 256192:
      goto block9_1;

    case 256256:
      goto block10_1;

    default:
      goto block11_1;

  }

  switch (var2_2)
  {
    case 128192:
      goto block9_2;

    case 128256:
      goto block10_2;

    case 192192:
      goto block9_2;

    case 192256:
      goto block10_2;

    case 256192:
      goto block9_2;

    case 256256:
      goto block10_2;

    default:
      goto block11_2;

  }

  block7_1:
  round_val_1 = var3_phi_1;

  block7_2:
  round_val_2 = var3_phi_2;

  nb_1 = var4_phi_1;
  nb_2 = var4_phi_2;
  goto block8_1;
  goto block8_2;
  block1_1:
  var3_phi_1 = 12;

  block1_2:
  var3_phi_2 = 12;

  var4_phi_1 = 6;
  var4_phi_2 = 6;
  goto block7_1;
  goto block7_2;
  block3_1:
  var3_phi_1 = 14;

  block3_2:
  var3_phi_2 = 14;

  var4_phi_1 = 8;
  var4_phi_2 = 8;
  goto block7_1;
  goto block7_2;
  block11_1:
  var7_1 = (long) ((int) (((int) var6_phi_1) * ((int) var5_1)));

  block11_2:
  var7_2 = (long) ((int) (((int) var6_phi_2) * ((int) var5_2)));

  var8_1 = (unsigned long) var6_phi_1;
  var8_2 = (unsigned long) var6_phi_2;
  var9_phi_1 = 0;
  var9_phi_2 = 0;
  do
  {
    var9_phi_1 = var16_1;
    var9_phi_2 = var16_2;
    var10_1 = ((long) var9_phi_1) + ((long) var7_1);
    var10_2 = ((long) var9_phi_2) + ((long) var7_2);
    var11_1 = ((long) var9_phi_1) << ((long) ((unsigned long) ((long) 2)));
    var11_2 = ((long) var9_phi_2) << ((long) ((unsigned long) ((long) 2)));
    var12_1 = &(*(((unsigned int *) var0_1) + var11_1));
    var12_2 = &(*(((unsigned int *) var0_2) + var11_2));
    *var12_1 = (*var12_1) ^ word_1[0][var10_1];
    *var12_2 = (*var12_2) ^ word_2[0][var10_2];
    var13_1 = &(*(((unsigned int *) var0_1) + (var11_1 | 1)));
    var13_2 = &(*(((unsigned int *) var0_2) + (var11_2 | 1)));
    *var13_1 = (*var13_1) ^ word_1[1][var10_1];
    *var13_2 = (*var13_2) ^ word_2[1][var10_2];
    var14_1 = &(*(((unsigned int *) var0_1) + (var11_1 | 2)));
    var14_2 = &(*(((unsigned int *) var0_2) + (var11_2 | 2)));
    *var14_1 = (*var14_1) ^ word_1[2][var10_1];
    *var14_2 = (*var14_2) ^ word_2[2][var10_2];
    var15_1 = &(*(((unsigned int *) var0_1) + (var11_1 | 3)));
    var15_2 = &(*(((unsigned int *) var0_2) + (var11_2 | 3)));
    *var15_1 = (*var15_1) ^ word_1[3][var10_1];
    *var15_2 = (*var15_2) ^ word_2[3][var10_2];
    var16_1 = ((long) var9_phi_1) + ((long) 1);
    var16_2 = ((long) var9_phi_2) + ((long) 1);
  }
  while ((var16_1 == var8_1) && (var16_2 == var8_2));
  InversShiftRow_ByteSub(var0_1, nb_1);
  InversShiftRow_ByteSub(var0_2, nb_2);
  InversShiftRow_ByteSub_2(var0_1, nb_1, var0_2, nb_2);
  var17_1 = round_val_1;
  var17_2 = round_val_2;
  if (((int) var17_1) > ((int) 1))
  {
    var18_phi_1 = var17_1;
    do
    {
      var18_phi_1 = var19_1;
      var19_1 = ((int) var18_phi_1) + ((int) (-1));
      AddRoundKey_InversMixColumn(var0_1, nb_1, var19_1);
      InversShiftRow_ByteSub(var0_1, nb_1);
    }
    while (var18_phi_1 > 2);
    goto block17_1;
  }
  else
  {
    goto block17_1;
  }
  if (((int) var17_2) > ((int) 1))
  {
    var18_phi_2 = var17_2;
    do
    {
      var18_phi_2 = var19_2;
      var19_2 = ((int) var18_phi_2) + ((int) (-1));
      AddRoundKey_InversMixColumn(var0_2, nb_2, var19_2);
      InversShiftRow_ByteSub(var0_2, nb_2);
    }
    while (var18_phi_2 > 2);
    goto block17_2;
  }
  else
  {
    goto block17_2;
  }
  AddRoundKey_InversMixColumn_2(var0_1, nb_1, var19_1, var0_2, nb_2, var19_2);
  InversShiftRow_ByteSub_2(var0_1, nb_1, var0_2, nb_2);
  block10_1:
  var6_phi_1 = 8;

  block10_2:
  var6_phi_2 = 8;

  goto block11_1;
  goto block11_2;
  block9_1:
  var6_phi_1 = 6;

  block9_2:
  var6_phi_2 = 6;

  goto block11_1;
  goto block11_2;
  block17_1:
  switch (var2_1)
  {
    case 128192:
      goto block18_1;

    case 128256:
      goto block19_1;

    case 192192:
      goto block18_1;

    case 192256:
      goto block19_1;

    case 256192:
      goto block18_1;

    case 256256:
      goto block19_1;

    default:
      goto block20_1;

  }


  block17_2:
  switch (var2_2)
  {
    case 128192:
      goto block18_2;

    case 128256:
      goto block19_2;

    case 192192:
      goto block18_2;

    case 192256:
      goto block19_2;

    case 256192:
      goto block18_2;

    case 256256:
      goto block19_2;

    default:
      goto block20_2;

  }


  block20_1:
  var21_phi_1 = 0;

  block20_2:
  var21_phi_2 = 0;

  do
  {
    var21_phi_1 = var27_1;
    var21_phi_2 = var27_2;
    var22_1 = ((long) var21_phi_1) << ((long) ((unsigned long) ((long) 2)));
    var22_2 = ((long) var21_phi_2) << ((long) ((unsigned long) ((long) 2)));
    var23_1 = &(*(((unsigned int *) var0_1) + var22_1));
    var23_2 = &(*(((unsigned int *) var0_2) + var22_2));
    *var23_1 = (*var23_1) ^ word_1[0][var21_phi_1];
    *var23_2 = (*var23_2) ^ word_2[0][var21_phi_2];
    var24_1 = &(*(((unsigned int *) var0_1) + (var22_1 | 1)));
    var24_2 = &(*(((unsigned int *) var0_2) + (var22_2 | 1)));
    *var24_1 = (*var24_1) ^ word_1[1][var21_phi_1];
    *var24_2 = (*var24_2) ^ word_2[1][var21_phi_2];
    var25_1 = &(*(((unsigned int *) var0_1) + (var22_1 | 2)));
    var25_2 = &(*(((unsigned int *) var0_2) + (var22_2 | 2)));
    *var25_1 = (*var25_1) ^ word_1[2][var21_phi_1];
    *var25_2 = (*var25_2) ^ word_2[2][var21_phi_2];
    var26_1 = &(*(((unsigned int *) var0_1) + (var22_1 | 3)));
    var26_2 = &(*(((unsigned int *) var0_2) + (var22_2 | 3)));
    *var26_1 = (*var26_1) ^ word_1[3][var21_phi_1];
    *var26_2 = (*var26_2) ^ word_2[3][var21_phi_2];
    var27_1 = ((long) var21_phi_1) + ((long) 1);
    var27_2 = ((long) var21_phi_2) + ((long) 1);
  }
  while ((var27_1 == var20_phi_1) && (var27_2 == var20_phi_2));
  printf(&_str_1[0]);
  printf(&_str_2[0]);
  printf_2(&_str_1[0], &_str_2[0]);
  var28_1 = ((int) var2_1) % ((int) 1000);
  var28_2 = ((int) var2_2) % ((int) 1000);
  if (var28_1 > ((int) 7))
  {
    var29_1 = (unsigned long) (((int) var28_1) / ((int) 8));
    var30_phi_1 = 0;
    do
    {
      var30_phi_1 = var32_1;
      var31_1 = &(*(((unsigned int *) var0_1) + var30_phi_1));
      if (((int) (*var31_1)) < ((int) 16))
      {
        putchar(48);
        goto block26_1;
      }
      else
      {
        goto block26_1;
      }
      block26_1:
      printf(&_str2_1[0], *var31_1);

      var32_1 = ((long) var30_phi_1) + ((long) 1);
    }
    while (var32_1 == var29_1);
    goto block28_1;
  }
  else
  {
    goto block28_1;
  }
  if (var28_2 > ((int) 7))
  {
    var29_2 = (unsigned long) (((int) var28_2) / ((int) 8));
    var30_phi_2 = 0;
    do
    {
      var30_phi_2 = var32_2;
      var31_2 = &(*(((unsigned int *) var0_2) + var30_phi_2));
      if (((int) (*var31_2)) < ((int) 16))
      {
        putchar(48);
        goto block26_2;
      }
      else
      {
        goto block26_2;
      }
      block26_2:
      printf(&_str2_2[0], *var31_2);

      var32_2 = ((long) var30_phi_2) + ((long) 1);
    }
    while (var32_2 == var29_2);
    goto block28_2;
  }
  else
  {
    goto block28_2;
  }
  putchar_2(48, 48);
  printf_2(&_str2_1[0], *var31_1, &_str2_2[0], *var31_2);
  block19_1:
  var20_phi_1 = 8;

  block19_2:
  var20_phi_2 = 8;

  goto block20_1;
  goto block20_2;
  block18_1:
  var20_phi_1 = 6;

  block18_2:
  var20_phi_2 = 6;

  goto block20_1;
  goto block20_2;
  block28_1:
  var33_phi_1 = 0;

  block28_2:
  var33_phi_2 = 0;

  do
  {
    var33_phi_1 = var34_1;
    var33_phi_2 = var34_2;
    main_result_1 = ((int) main_result_1) + ((int) ((unsigned int) ((*(((unsigned int *) var0_1) + var33_phi_1)) != __const_decrypt_out_dec_statemt_1[var33_phi_1])));
    main_result_2 = ((int) main_result_2) + ((int) ((unsigned int) ((*(((unsigned int *) var0_2) + var33_phi_2)) != __const_decrypt_out_dec_statemt_2[var33_phi_2])));
    var34_1 = ((long) var33_phi_1) + ((long) 1);
    var34_2 = ((long) var33_phi_2) + ((long) 1);
  }
  while ((var34_1 == 16) && (var34_2 == 16));
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    assert(__const_decrypt_out_dec_statemt_1[i_0] == __const_decrypt_out_dec_statemt_2[i_0]);
  }

  assert(round_val_1 == round_val_2);
  assert(nb_1 == nb_2);
  for (int i_0 = 0; i_0 < 19; i_0++)
  {
    assert(_str_1[i_0] == _str_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(_str2_1[i_0] == _str2_2[i_0]);
  }

  assert(main_result_1 == main_result_2);
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  assert(var3_phi_1 == var3_phi_2);
  assert(var4_phi_1 == var4_phi_2);
  assert(var6_phi_1 == var6_phi_2);
  assert(var9_phi_1 == var9_phi_2);
  assert(var18_phi_1 == var18_phi_2);
  assert(var20_phi_1 == var20_phi_2);
  assert(var21_phi_1 == var21_phi_2);
  assert(var30_phi_1 == var30_phi_2);
  assert(var33_phi_1 == var33_phi_2);
  assert(var5_1 == var5_2);
  assert(var7_1 == var7_2);
  assert(var8_1 == var8_2);
  assert(var10_1 == var10_2);
  assert(var11_1 == var11_2);
  assert((*var12_1) == (*var12_2));
  assert((*var13_1) == (*var13_2));
  assert((*var14_1) == (*var14_2));
  assert((*var15_1) == (*var15_2));
  assert(var16_1 == var16_2);
  assert(var17_1 == var17_2);
  assert(var19_1 == var19_2);
  assert(var22_1 == var22_2);
  assert((*var23_1) == (*var23_2));
  assert((*var24_1) == (*var24_2));
  assert((*var25_1) == (*var25_2));
  assert((*var26_1) == (*var26_2));
  assert(var27_1 == var27_2);
  assert(var28_1 == var28_2);
  assert(var29_1 == var29_2);
  assert((*var31_1) == (*var31_2));
  assert(var32_1 == var32_2);
  assert(var34_1 == var34_2);
}

unsigned int decrypt(unsigned int *var0, unsigned int *var1, unsigned int var2)
{
  unsigned int var3_phi;
  unsigned int var4_phi;
  unsigned int var6_phi;
  unsigned long var9_phi;
  unsigned int var18_phi;
  unsigned long var20_phi;
  unsigned long var21_phi;
  unsigned long var30_phi;
  unsigned long var33_phi;
  unsigned int var5;
  long var7;
  unsigned long var8;
  long var10;
  long var11;
  unsigned int *var12;
  unsigned int *var13;
  unsigned int *var14;
  unsigned int *var15;
  long var16;
  unsigned int var17;
  int var19;
  long var22;
  unsigned int *var23;
  unsigned int *var24;
  unsigned int *var25;
  unsigned int *var26;
  long var27;
  int var28;
  unsigned long var29;
  unsigned int *var31;
  long var32;
  long var34;
  block0:
  KeySchedule(var2, var1);

  switch (var2)
  {
    case 128128:
      goto block7;

    case 128192:
      goto block1;

    case 128256:
      goto block3;

    case 192128:
      var3_phi = 12;
      var4_phi = 4;
      goto block7;

    case 192192:
      goto block1;

    case 192256:
      goto block3;

    case 256128:
      var3_phi = 14;
      var4_phi = 4;
      goto block7;

    case 256192:
      var3_phi = 14;
      var4_phi = 6;
      goto block7;

    case 256256:
      var3_phi = 14;
      var4_phi = 8;
      goto block7;

    default:
      goto block8;

  }

  block8:
  var5 = round_val;

  switch (var2)
  {
    case 128192:
      goto block9;

    case 128256:
      goto block10;

    case 192192:
      goto block9;

    case 192256:
      goto block10;

    case 256192:
      goto block9;

    case 256256:
      goto block10;

    default:
      goto block11;

  }

  block7:
  round_val = var3_phi;

  nb = var4_phi;
  goto block8;
  block1:
  var3_phi = 12;

  var4_phi = 6;
  goto block7;
  block3:
  var3_phi = 14;

  var4_phi = 8;
  goto block7;
  block11:
  var7 = (long) ((int) (((int) var6_phi) * ((int) var5)));

  var8 = (unsigned long) var6_phi;
  var9_phi = 0;
  do
  {
    var9_phi = var16;
    var10 = ((long) var9_phi) + ((long) var7);
    var11 = ((long) var9_phi) << ((long) ((unsigned long) ((long) 2)));
    var12 = &(*(((unsigned int *) var0) + var11));
    *var12 = (*var12) ^ word[0][var10];
    var13 = &(*(((unsigned int *) var0) + (var11 | 1)));
    *var13 = (*var13) ^ word[1][var10];
    var14 = &(*(((unsigned int *) var0) + (var11 | 2)));
    *var14 = (*var14) ^ word[2][var10];
    var15 = &(*(((unsigned int *) var0) + (var11 | 3)));
    *var15 = (*var15) ^ word[3][var10];
    var16 = ((long) var9_phi) + ((long) 1);
  }
  while (var16 == var8);
  InversShiftRow_ByteSub(var0, nb);
  var17 = round_val;
  if (((int) var17) > ((int) 1))
  {
    var18_phi = var17;
    do
    {
      var18_phi = var19;
      var19 = ((int) var18_phi) + ((int) (-1));
      AddRoundKey_InversMixColumn(var0, nb, var19);
      InversShiftRow_ByteSub(var0, nb);
    }
    while (var18_phi > 2);
    goto block17;
  }
  else
  {
    goto block17;
  }
  block10:
  var6_phi = 8;

  goto block11;
  block9:
  var6_phi = 6;

  goto block11;
  block17:
  switch (var2)
  {
    case 128192:
      goto block18;

    case 128256:
      goto block19;

    case 192192:
      goto block18;

    case 192256:
      goto block19;

    case 256192:
      goto block18;

    case 256256:
      goto block19;

    default:
      goto block20;

  }


  block20:
  var21_phi = 0;

  do
  {
    var21_phi = var27;
    var22 = ((long) var21_phi) << ((long) ((unsigned long) ((long) 2)));
    var23 = &(*(((unsigned int *) var0) + var22));
    *var23 = (*var23) ^ word[0][var21_phi];
    var24 = &(*(((unsigned int *) var0) + (var22 | 1)));
    *var24 = (*var24) ^ word[1][var21_phi];
    var25 = &(*(((unsigned int *) var0) + (var22 | 2)));
    *var25 = (*var25) ^ word[2][var21_phi];
    var26 = &(*(((unsigned int *) var0) + (var22 | 3)));
    *var26 = (*var26) ^ word[3][var21_phi];
    var27 = ((long) var21_phi) + ((long) 1);
  }
  while (var27 == var20_phi);
  printf(&_str[0]);
  var28 = ((int) var2) % ((int) 1000);
  if (var28 > ((int) 7))
  {
    var29 = (unsigned long) (((int) var28) / ((int) 8));
    var30_phi = 0;
    do
    {
      var30_phi = var32;
      var31 = &(*(((unsigned int *) var0) + var30_phi));
      if (((int) (*var31)) < ((int) 16))
      {
        putchar(48);
        goto block26;
      }
      else
      {
        goto block26;
      }
      block26:
      printf(&_str2[0], *var31);

      var32 = ((long) var30_phi) + ((long) 1);
    }
    while (var32 == var29);
    goto block28;
  }
  else
  {
    goto block28;
  }
  block19:
  var20_phi = 8;

  goto block20;
  block18:
  var20_phi = 6;

  goto block20;
  block28:
  var33_phi = 0;

  do
  {
    var33_phi = var34;
    main_result = ((int) main_result) + ((int) ((unsigned int) ((*(((unsigned int *) var0) + var33_phi)) != __const_decrypt_out_dec_statemt[var33_phi])));
    var34 = ((long) var33_phi) + ((long) 1);
  }
  while (var34 == 16);
  return 0;
}

void encrypt_2(unsigned int *var0_1, unsigned int *var1_1, unsigned int var2_1, unsigned int *var0_2, unsigned int *var1_2, unsigned int var2_2)
{
  unsigned int var3_phi_1;
  unsigned int var3_phi_2;
  unsigned int var4_phi_1;
  unsigned int var4_phi_2;
  unsigned long var5_phi_1;
  unsigned long var5_phi_2;
  unsigned long var6_phi_1;
  unsigned long var6_phi_2;
  unsigned int var13_phi_1;
  unsigned int var13_phi_2;
  unsigned int var15_phi_1;
  unsigned int var15_phi_2;
  unsigned int var16_phi_1;
  unsigned int var16_phi_2;
  unsigned int var17_phi_1;
  unsigned int var17_phi_2;
  unsigned long var20_phi_1;
  unsigned long var20_phi_2;
  unsigned long var28_phi_1;
  unsigned long var28_phi_2;
  unsigned long var31_phi_1;
  unsigned long var31_phi_2;
  long var7_1;
  long var7_2;
  unsigned int *var8_1;
  unsigned int *var8_2;
  unsigned int *var9_1;
  unsigned int *var9_2;
  unsigned int *var10_1;
  unsigned int *var10_2;
  unsigned int *var11_1;
  unsigned int *var11_2;
  long var12_1;
  long var12_2;
  int var14_1;
  int var14_2;
  unsigned long var18_1;
  unsigned long var18_2;
  unsigned long var19_1;
  unsigned long var19_2;
  long var21_1;
  long var21_2;
  long var22_1;
  long var22_2;
  unsigned int *var23_1;
  unsigned int *var23_2;
  unsigned int *var24_1;
  unsigned int *var24_2;
  unsigned int *var25_1;
  unsigned int *var25_2;
  unsigned int *var26_1;
  unsigned int *var26_2;
  long var27_1;
  long var27_2;
  unsigned int *var29_1;
  unsigned int *var29_2;
  long var30_1;
  long var30_2;
  long var32_1;
  long var32_2;
  block0_1:
  KeySchedule(var2_1, var1_1);

  block0_2:
  KeySchedule(var2_2, var1_2);

  KeySchedule_2(var2_1, var1_1, var2_2, var1_2);
  switch (var2_1)
  {
    case 128128:
      goto block6_1;

    case 128192:
      goto block3_1;

    case 128256:
      goto block5_1;

    case 192128:
      var3_phi_1 = 2;
      var4_phi_1 = 4;
      goto block6_1;

    case 192192:
      goto block3_1;

    case 192256:
      goto block5_1;

    case 256128:
      var3_phi_1 = 4;
      var4_phi_1 = 4;
      goto block6_1;

    case 256192:
      var3_phi_1 = 4;
      var4_phi_1 = 6;
      goto block6_1;

    case 256256:
      goto block5_1;

    default:
      goto block9_1;

  }

  switch (var2_2)
  {
    case 128128:
      goto block6_2;

    case 128192:
      goto block3_2;

    case 128256:
      goto block5_2;

    case 192128:
      var3_phi_2 = 2;
      var4_phi_2 = 4;
      goto block6_2;

    case 192192:
      goto block3_2;

    case 192256:
      goto block5_2;

    case 256128:
      var3_phi_2 = 4;
      var4_phi_2 = 4;
      goto block6_2;

    case 256192:
      var3_phi_2 = 4;
      var4_phi_2 = 6;
      goto block6_2;

    case 256256:
      goto block5_2;

    default:
      goto block9_2;

  }

  block9_1:
  var6_phi_1 = 0;

  block9_2:
  var6_phi_2 = 0;

  do
  {
    var6_phi_1 = var12_1;
    var6_phi_2 = var12_2;
    var7_1 = ((long) var6_phi_1) << ((long) ((unsigned long) ((long) 2)));
    var7_2 = ((long) var6_phi_2) << ((long) ((unsigned long) ((long) 2)));
    var8_1 = &(*(((unsigned int *) var0_1) + var7_1));
    var8_2 = &(*(((unsigned int *) var0_2) + var7_2));
    *var8_1 = (*var8_1) ^ word_1[0][var6_phi_1];
    *var8_2 = (*var8_2) ^ word_2[0][var6_phi_2];
    var9_1 = &(*(((unsigned int *) var0_1) + (var7_1 | 1)));
    var9_2 = &(*(((unsigned int *) var0_2) + (var7_2 | 1)));
    *var9_1 = (*var9_1) ^ word_1[1][var6_phi_1];
    *var9_2 = (*var9_2) ^ word_2[1][var6_phi_2];
    var10_1 = &(*(((unsigned int *) var0_1) + (var7_1 | 2)));
    var10_2 = &(*(((unsigned int *) var0_2) + (var7_2 | 2)));
    *var10_1 = (*var10_1) ^ word_1[2][var6_phi_1];
    *var10_2 = (*var10_2) ^ word_2[2][var6_phi_2];
    var11_1 = &(*(((unsigned int *) var0_1) + (var7_1 | 3)));
    var11_2 = &(*(((unsigned int *) var0_2) + (var7_2 | 3)));
    *var11_1 = (*var11_1) ^ word_1[3][var6_phi_1];
    *var11_2 = (*var11_2) ^ word_2[3][var6_phi_2];
    var12_1 = ((long) var6_phi_1) + ((long) 1);
    var12_2 = ((long) var6_phi_2) + ((long) 1);
  }
  while ((var12_1 == var5_phi_1) && (var12_2 == var5_phi_2));
  if (((int) round_val_1) < ((int) (-8)))
  {
    var16_phi_1 = 1;
    goto block15_1;
  }
  else
  {
    var13_phi_1 = 1;
    do
    {
      var13_phi_1 = var14_1;
      ByteSub_ShiftRow(var0_1, nb_1);
      MixColumn_AddRoundKey(var0_1, nb_1, var13_phi_1);
      var14_1 = ((int) var13_phi_1) + ((int) 1);
    }
    while (var13_phi_1 < (((int) round_val_1) + ((int) 9)));
    var16_phi_1 = var15_phi_1;
    goto block15_1;
  }
  if (((int) round_val_2) < ((int) (-8)))
  {
    var16_phi_2 = 1;
    goto block15_2;
  }
  else
  {
    var13_phi_2 = 1;
    do
    {
      var13_phi_2 = var14_2;
      ByteSub_ShiftRow(var0_2, nb_2);
      MixColumn_AddRoundKey(var0_2, nb_2, var13_phi_2);
      var14_2 = ((int) var13_phi_2) + ((int) 1);
    }
    while (var13_phi_2 < (((int) round_val_2) + ((int) 9)));
    var16_phi_2 = var15_phi_2;
    goto block15_2;
  }
  ByteSub_ShiftRow_2(var0_1, nb_1, var0_2, nb_2);
  MixColumn_AddRoundKey_2(var0_1, nb_1, var13_phi_1, var0_2, nb_2, var13_phi_2);
  block6_1:
  round_val_1 = var3_phi_1;

  block6_2:
  round_val_2 = var3_phi_2;

  nb_1 = var4_phi_1;
  nb_2 = var4_phi_2;
  switch (var2_1)
  {
    case 128192:
      goto block7_1;

    case 128256:
      goto block8_1;

    case 192192:
      goto block7_1;

    case 192256:
      goto block8_1;

    case 256192:
      goto block7_1;

    case 256256:
      goto block8_1;

    default:
      goto block9_1;

  }

  switch (var2_2)
  {
    case 128192:
      goto block7_2;

    case 128256:
      goto block8_2;

    case 192192:
      goto block7_2;

    case 192256:
      goto block8_2;

    case 256192:
      goto block7_2;

    case 256256:
      goto block8_2;

    default:
      goto block9_2;

  }

  block3_1:
  var3_phi_1 = 2;

  block3_2:
  var3_phi_2 = 2;

  var4_phi_1 = 6;
  var4_phi_2 = 6;
  goto block6_1;
  goto block6_2;
  block5_1:
  var3_phi_1 = 4;

  block5_2:
  var3_phi_2 = 4;

  var4_phi_1 = 8;
  var4_phi_2 = 8;
  goto block6_1;
  goto block6_2;
  block8_1:
  var5_phi_1 = 8;

  block8_2:
  var5_phi_2 = 8;

  goto block9_1;
  goto block9_2;
  block7_1:
  var5_phi_1 = 6;

  block7_2:
  var5_phi_2 = 6;

  goto block9_1;
  goto block9_2;
  block15_1:
  ByteSub_ShiftRow(var0_1, nb_1);

  block15_2:
  ByteSub_ShiftRow(var0_2, nb_2);

  ByteSub_ShiftRow_2(var0_1, nb_1, var0_2, nb_2);
  switch (var2_1)
  {
    case 128192:
      goto block16_1;

    case 128256:
      goto block17_1;

    case 192192:
      goto block16_1;

    case 192256:
      goto block17_1;

    case 256192:
      goto block16_1;

    case 256256:
      goto block17_1;

    default:
      goto block18_1;

  }

  switch (var2_2)
  {
    case 128192:
      goto block16_2;

    case 128256:
      goto block17_2;

    case 192192:
      goto block16_2;

    case 192256:
      goto block17_2;

    case 256192:
      goto block16_2;

    case 256256:
      goto block17_2;

    default:
      goto block18_2;

  }

  block18_1:
  var18_1 = (unsigned long) (((int) var17_phi_1) * ((int) var16_phi_1));

  block18_2:
  var18_2 = (unsigned long) (((int) var17_phi_2) * ((int) var16_phi_2));

  var19_1 = (unsigned long) var17_phi_1;
  var19_2 = (unsigned long) var17_phi_2;
  var20_phi_1 = 0;
  var20_phi_2 = 0;
  do
  {
    var20_phi_1 = var27_1;
    var20_phi_2 = var27_2;
    var21_1 = ((long) var20_phi_1) + ((long) var18_1);
    var21_2 = ((long) var20_phi_2) + ((long) var18_2);
    var22_1 = ((long) var20_phi_1) << ((long) ((unsigned long) ((long) 2)));
    var22_2 = ((long) var20_phi_2) << ((long) ((unsigned long) ((long) 2)));
    var23_1 = &(*(((unsigned int *) var0_1) + var22_1));
    var23_2 = &(*(((unsigned int *) var0_2) + var22_2));
    *var23_1 = (*var23_1) ^ word_1[0][var21_1];
    *var23_2 = (*var23_2) ^ word_2[0][var21_2];
    var24_1 = &(*(((unsigned int *) var0_1) + (var22_1 | 1)));
    var24_2 = &(*(((unsigned int *) var0_2) + (var22_2 | 1)));
    *var24_1 = (*var24_1) ^ word_1[1][var21_1];
    *var24_2 = (*var24_2) ^ word_2[1][var21_2];
    var25_1 = &(*(((unsigned int *) var0_1) + (var22_1 | 2)));
    var25_2 = &(*(((unsigned int *) var0_2) + (var22_2 | 2)));
    *var25_1 = (*var25_1) ^ word_1[2][var21_1];
    *var25_2 = (*var25_2) ^ word_2[2][var21_2];
    var26_1 = &(*(((unsigned int *) var0_1) + (var22_1 | 3)));
    var26_2 = &(*(((unsigned int *) var0_2) + (var22_2 | 3)));
    *var26_1 = (*var26_1) ^ word_1[3][var21_1];
    *var26_2 = (*var26_2) ^ word_2[3][var21_2];
    var27_1 = ((long) var20_phi_1) + ((long) 1);
    var27_2 = ((long) var20_phi_2) + ((long) 1);
  }
  while ((var27_1 == var19_1) && (var27_2 == var19_2));
  printf(&_str_3_1[0]);
  printf(&_str_3_2[0]);
  printf_2(&_str_3_1[0], &_str_3_2[0]);
  if (((int) nb_1) > ((int) 0))
  {
    var28_phi_1 = 0;
    do
    {
      var28_phi_1 = var30_1;
      var29_1 = &(*(((unsigned int *) var0_1) + var28_phi_1));
      if (((int) (*var29_1)) < ((int) 16))
      {
        putchar(48);
        goto block24_1;
      }
      else
      {
        goto block24_1;
      }
      block24_1:
      printf(&_str2_1[0], *var29_1);

      var30_1 = ((long) var28_phi_1) + ((long) 1);
    }
    while (var30_1 < ((long) ((int) (((int) nb_1) << ((unsigned int) ((int) 2))))));
    goto block26_1;
  }
  else
  {
    goto block26_1;
  }
  if (((int) nb_2) > ((int) 0))
  {
    var28_phi_2 = 0;
    do
    {
      var28_phi_2 = var30_2;
      var29_2 = &(*(((unsigned int *) var0_2) + var28_phi_2));
      if (((int) (*var29_2)) < ((int) 16))
      {
        putchar(48);
        goto block24_2;
      }
      else
      {
        goto block24_2;
      }
      block24_2:
      printf(&_str2_2[0], *var29_2);

      var30_2 = ((long) var28_phi_2) + ((long) 1);
    }
    while (var30_2 < ((long) ((int) (((int) nb_2) << ((unsigned int) ((int) 2))))));
    goto block26_2;
  }
  else
  {
    goto block26_2;
  }
  putchar_2(48, 48);
  printf_2(&_str2_1[0], *var29_1, &_str2_2[0], *var29_2);
  block17_1:
  var17_phi_1 = 8;

  block17_2:
  var17_phi_2 = 8;

  goto block18_1;
  goto block18_2;
  block16_1:
  var17_phi_1 = 6;

  block16_2:
  var17_phi_2 = 6;

  goto block18_1;
  goto block18_2;
  block26_1:
  var31_phi_1 = 0;

  block26_2:
  var31_phi_2 = 0;

  do
  {
    var31_phi_1 = var32_1;
    var31_phi_2 = var32_2;
    main_result_1 = ((int) main_result_1) + ((int) ((unsigned int) ((*(((unsigned int *) var0_1) + var31_phi_1)) != __const_encrypt_out_enc_statemt_1[var31_phi_1])));
    main_result_2 = ((int) main_result_2) + ((int) ((unsigned int) ((*(((unsigned int *) var0_2) + var31_phi_2)) != __const_encrypt_out_enc_statemt_2[var31_phi_2])));
    var32_1 = ((long) var31_phi_1) + ((long) 1);
    var32_2 = ((long) var31_phi_2) + ((long) 1);
  }
  while ((var32_1 == 16) && (var32_2 == 16));
  assert(round_val_1 == round_val_2);
  assert(nb_1 == nb_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(_str2_1[i_0] == _str2_2[i_0]);
  }

  assert(main_result_1 == main_result_2);
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    assert(__const_encrypt_out_enc_statemt_1[i_0] == __const_encrypt_out_enc_statemt_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 20; i_0++)
  {
    assert(_str_3_1[i_0] == _str_3_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    for (int i_1 = 0; i_1 < 120; i_1++)
    {
      assert(word_1[i_0][i_1] == word_2[i_0][i_1]);
    }

  }

  assert(var3_phi_1 == var3_phi_2);
  assert(var4_phi_1 == var4_phi_2);
  assert(var5_phi_1 == var5_phi_2);
  assert(var6_phi_1 == var6_phi_2);
  assert(var13_phi_1 == var13_phi_2);
  assert(var15_phi_1 == var15_phi_2);
  assert(var16_phi_1 == var16_phi_2);
  assert(var17_phi_1 == var17_phi_2);
  assert(var20_phi_1 == var20_phi_2);
  assert(var28_phi_1 == var28_phi_2);
  assert(var31_phi_1 == var31_phi_2);
  assert(var7_1 == var7_2);
  assert((*var8_1) == (*var8_2));
  assert((*var9_1) == (*var9_2));
  assert((*var10_1) == (*var10_2));
  assert((*var11_1) == (*var11_2));
  assert(var12_1 == var12_2);
  assert(var14_1 == var14_2);
  assert(var18_1 == var18_2);
  assert(var19_1 == var19_2);
  assert(var21_1 == var21_2);
  assert(var22_1 == var22_2);
  assert((*var23_1) == (*var23_2));
  assert((*var24_1) == (*var24_2));
  assert((*var25_1) == (*var25_2));
  assert((*var26_1) == (*var26_2));
  assert(var27_1 == var27_2);
  assert((*var29_1) == (*var29_2));
  assert(var30_1 == var30_2);
  assert(var32_1 == var32_2);
}

unsigned int encrypt(unsigned int *var0, unsigned int *var1, unsigned int var2)
{
  unsigned int var3_phi;
  unsigned int var4_phi;
  unsigned long var5_phi;
  unsigned long var6_phi;
  unsigned int var13_phi;
  unsigned int var15_phi;
  unsigned int var16_phi;
  unsigned int var17_phi;
  unsigned long var20_phi;
  unsigned long var28_phi;
  unsigned long var31_phi;
  long var7;
  unsigned int *var8;
  unsigned int *var9;
  unsigned int *var10;
  unsigned int *var11;
  long var12;
  int var14;
  unsigned long var18;
  unsigned long var19;
  long var21;
  long var22;
  unsigned int *var23;
  unsigned int *var24;
  unsigned int *var25;
  unsigned int *var26;
  long var27;
  unsigned int *var29;
  long var30;
  long var32;
  block0:
  KeySchedule(var2, var1);

  switch (var2)
  {
    case 128128:
      goto block6;

    case 128192:
      goto block3;

    case 128256:
      goto block5;

    case 192128:
      var3_phi = 2;
      var4_phi = 4;
      goto block6;

    case 192192:
      goto block3;

    case 192256:
      goto block5;

    case 256128:
      var3_phi = 4;
      var4_phi = 4;
      goto block6;

    case 256192:
      var3_phi = 4;
      var4_phi = 6;
      goto block6;

    case 256256:
      goto block5;

    default:
      goto block9;

  }

  block9:
  var6_phi = 0;

  do
  {
    var6_phi = var12;
    var7 = ((long) var6_phi) << ((long) ((unsigned long) ((long) 2)));
    var8 = &(*(((unsigned int *) var0) + var7));
    *var8 = (*var8) ^ word[0][var6_phi];
    var9 = &(*(((unsigned int *) var0) + (var7 | 1)));
    *var9 = (*var9) ^ word[1][var6_phi];
    var10 = &(*(((unsigned int *) var0) + (var7 | 2)));
    *var10 = (*var10) ^ word[2][var6_phi];
    var11 = &(*(((unsigned int *) var0) + (var7 | 3)));
    *var11 = (*var11) ^ word[3][var6_phi];
    var12 = ((long) var6_phi) + ((long) 1);
  }
  while (var12 == var5_phi);
  if (((int) round_val) < ((int) (-8)))
  {
    var16_phi = 1;
    goto block15;
  }
  else
  {
    var13_phi = 1;
    do
    {
      var13_phi = var14;
      ByteSub_ShiftRow(var0, nb);
      MixColumn_AddRoundKey(var0, nb, var13_phi);
      var14 = ((int) var13_phi) + ((int) 1);
    }
    while (var13_phi < (((int) round_val) + ((int) 9)));
    var16_phi = var15_phi;
    goto block15;
  }
  block6:
  round_val = var3_phi;

  nb = var4_phi;
  switch (var2)
  {
    case 128192:
      goto block7;

    case 128256:
      goto block8;

    case 192192:
      goto block7;

    case 192256:
      goto block8;

    case 256192:
      goto block7;

    case 256256:
      goto block8;

    default:
      goto block9;

  }

  block3:
  var3_phi = 2;

  var4_phi = 6;
  goto block6;
  block5:
  var3_phi = 4;

  var4_phi = 8;
  goto block6;
  block8:
  var5_phi = 8;

  goto block9;
  block7:
  var5_phi = 6;

  goto block9;
  block15:
  ByteSub_ShiftRow(var0, nb);

  switch (var2)
  {
    case 128192:
      goto block16;

    case 128256:
      goto block17;

    case 192192:
      goto block16;

    case 192256:
      goto block17;

    case 256192:
      goto block16;

    case 256256:
      goto block17;

    default:
      goto block18;

  }

  block18:
  var18 = (unsigned long) (((int) var17_phi) * ((int) var16_phi));

  var19 = (unsigned long) var17_phi;
  var20_phi = 0;
  do
  {
    var20_phi = var27;
    var21 = ((long) var20_phi) + ((long) var18);
    var22 = ((long) var20_phi) << ((long) ((unsigned long) ((long) 2)));
    var23 = &(*(((unsigned int *) var0) + var22));
    *var23 = (*var23) ^ word[0][var21];
    var24 = &(*(((unsigned int *) var0) + (var22 | 1)));
    *var24 = (*var24) ^ word[1][var21];
    var25 = &(*(((unsigned int *) var0) + (var22 | 2)));
    *var25 = (*var25) ^ word[2][var21];
    var26 = &(*(((unsigned int *) var0) + (var22 | 3)));
    *var26 = (*var26) ^ word[3][var21];
    var27 = ((long) var20_phi) + ((long) 1);
  }
  while (var27 == var19);
  printf(&_str_3[0]);
  if (((int) nb) > ((int) 0))
  {
    var28_phi = 0;
    do
    {
      var28_phi = var30;
      var29 = &(*(((unsigned int *) var0) + var28_phi));
      if (((int) (*var29)) < ((int) 16))
      {
        putchar(48);
        goto block24;
      }
      else
      {
        goto block24;
      }
      block24:
      printf(&_str2[0], *var29);

      var30 = ((long) var28_phi) + ((long) 1);
    }
    while (var30 < ((long) ((int) (((int) nb) << ((unsigned int) ((int) 2))))));
    goto block26;
  }
  else
  {
    goto block26;
  }
  block17:
  var17_phi = 8;

  goto block18;
  block16:
  var17_phi = 6;

  goto block18;
  block26:
  var31_phi = 0;

  do
  {
    var31_phi = var32;
    main_result = ((int) main_result) + ((int) ((unsigned int) ((*(((unsigned int *) var0) + var31_phi)) != __const_encrypt_out_enc_statemt[var31_phi])));
    var32 = ((long) var31_phi) + ((long) 1);
  }
  while (var32 == 16);
  return 0;
}

void main()
{
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    key_1[i_0] = nd_key();
  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    key_2[i_0] = nd_key();
  }

  block0_1:
  main_result_1 = 0;

  block0_2:
  main_result_2 = 0;

  encrypt(&statemt_1[0], &key_1[0], 128128);
  encrypt(&statemt_2[0], &key_2[0], 128128);
  encrypt_2(&statemt_1[0], &key_1[0], 128128, &statemt_2[0], &key_2[0], 128128);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    __CPROVER_assume(key_1[i_0] != key_2[i_0]);
  }

  assert(main_result_1 == main_result_2);
  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(statemt_1[i_0] == statemt_2[i_0]);
  }

}


