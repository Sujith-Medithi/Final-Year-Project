unsigned int rsa(unsigned int var0, unsigned int var1, unsigned int var2, unsigned int var3, unsigned int var4);

void main(void)
{
  int p_1;
  int p_2;
  int q_1;
  int q_2;
  int e_1;
  int e_2;
  int msg_1;
  int msg_2;
  int k_1;
  int k_2;
  int res_1 = rsa(p_1, q_1, e_1, k_1, msg_1);
  int res_2 = rsa(p_2, q_2, e_2, k_2, msg_2);
  rsa_2(p_1, q_1, e_1, k_1, msg_1, p_2, q_2, e_2, k_2, msg_2);
  __CPROVER_assume(p_1 == p_2);
  __CPROVER_assume(msg_1 == msg_2);
  __CPROVER_assume(q_1 == q_2);
   __CPROVER_assume(e_1==e_2);
  __CPROVER_assume(k_1 != k_2);
 
  assert(res_1 == res_2);
}

void rsa_2(unsigned int var0_1, unsigned int var1_1, unsigned int var2_1, unsigned int var3_1, unsigned int var4_1, unsigned int var0_2, unsigned int var1_2, unsigned int var2_2, unsigned int var3_2, unsigned int var4_2)
{
  int var5_1;
  int var5_2;
  int var6_1;
  int var6_2;
  unsigned int var7_phi_1;
  unsigned int var7_phi_2;
  unsigned int var8_phi_1;
  unsigned int var8_phi_2;
  unsigned int var10_phi_1;
  unsigned int var10_phi_2;
  unsigned int var12_phi_1;
  unsigned int var12_phi_2;
  unsigned int var14_phi_1;
  unsigned int var14_phi_2;
  unsigned int var15_phi_1;
  unsigned int var15_phi_2;
  unsigned int var18_phi_1;
  unsigned int var18_phi_2;
  unsigned int var20_phi_1;
  unsigned int var20_phi_2;
  unsigned int var21_phi_1;
  unsigned int var21_phi_2;
  unsigned int var24_phi_1;
  unsigned int var24_phi_2;
  int var9_1;
  int var9_2;
  unsigned int var11_1;
  unsigned int var11_2;
  int var13_1;
  int var13_2;
  int var16_1;
  int var16_2;
  int var17_1;
  int var17_2;
  int var19_1;
  int var19_2;
  int var22_1;
  int var22_2;
  int var23_1;
  int var23_2;
  block0_1:
  var5_1 = ((int) var1_1) * ((int) var0_1);

  block0_2:
  var5_2 = ((int) var1_2) * ((int) var0_2);

  var6_1 = ((unsigned int) (((int) var1_1) + ((int) (-1)))) * ((unsigned int) (((int) var0_1) + ((int) (-1))));
  var6_2 = ((unsigned int) (((int) var1_2) + ((int) (-1)))) * ((unsigned int) (((int) var0_2) + ((int) (-1))));
  if (var6_1 > ((int) var2_1))
  {
    var7_phi_1 = var2_1;
    goto block1_1;
  }
  else
  {
    var12_phi_1 = var2_1;
    goto block7_1;
  }
  if (var6_2 > ((int) var2_2))
  {
    var7_phi_2 = var2_2;
    goto block1_2;
  }
  else
  {
    var12_phi_2 = var2_2;
    goto block7_2;
  }
  block1_1:
  if (((int) var7_phi_1) > ((int) 0))
  {
    var8_phi_1 = var7_phi_1;
    goto block2_1;
  }
  else
  {
    var10_phi_1 = var7_phi_1;
    goto block5_1;
  }

  block1_2:
  if (((int) var7_phi_2) > ((int) 0))
  {
    var8_phi_2 = var7_phi_2;
    goto block2_2;
  }
  else
  {
    var10_phi_2 = var7_phi_2;
    goto block5_2;
  }

  block7_1:
  var13_1 = ((int) (((int) (((int) var6_1) * ((int) var3_1))) + ((int) 1))) / ((int) var12_phi_1);

  block7_2:
  var13_2 = ((int) (((int) (((int) var6_2) * ((int) var3_2))) + ((int) 1))) / ((int) var12_phi_2);

  if (((int) var12_phi_1) > ((int) 0))
  {
    var14_phi_1 = 0;
    var15_phi_1 = 1;
    goto block8_1;
  }
  else
  {
    var18_phi_1 = 1;
    goto block9_1;
  }
  if (((int) var12_phi_2) > ((int) 0))
  {
    var14_phi_2 = 0;
    var15_phi_2 = 1;
    goto block8_2;
  }
  else
  {
    var18_phi_2 = 1;
    goto block9_2;
  }
  block2_1:
  if ((((int) var7_phi_1) % ((int) var8_phi_1)) == 0)
  {
    if ((((int) var6_1) % ((int) var8_phi_1)) == 0)
    {
      var10_phi_1 = var8_phi_1;
      goto block5_1;
    }
    else
    {
      goto block4_1;
    }
  }
  else
  {
    goto block4_1;
  }

  block2_2:
  if ((((int) var7_phi_2) % ((int) var8_phi_2)) == 0)
  {
    if ((((int) var6_2) % ((int) var8_phi_2)) == 0)
    {
      var10_phi_2 = var8_phi_2;
      goto block5_2;
    }
    else
    {
      goto block4_2;
    }
  }
  else
  {
    goto block4_2;
  }

  block5_1:
  if (var10_phi_1 == 1)
  {
    var12_phi_1 = var7_phi_1;
    goto block7_1;
  }
  else
  {
    var11_1 = var7_phi_1 + 1;
    if (var11_1 == var6_1)
    {
      var12_phi_1 = var6_1;
      goto block7_1;
    }
    else
    {
      var7_phi_1 = var11_1;
      goto block1_1;
    }
  }

  block5_2:
  if (var10_phi_2 == 1)
  {
    var12_phi_2 = var7_phi_2;
    goto block7_2;
  }
  else
  {
    var11_2 = var7_phi_2 + 1;
    if (var11_2 == var6_2)
    {
      var12_phi_2 = var6_2;
      goto block7_2;
    }
    else
    {
      var7_phi_2 = var11_2;
      goto block1_2;
    }
  }

  block4_1:
  var9_1 = ((int) var8_phi_1) + ((int) (-1));

  block4_2:
  var9_2 = ((int) var8_phi_2) + ((int) (-1));

  if (((int) var8_phi_1) > ((int) 1))
  {
    var8_phi_1 = var9_1;
    goto block2_1;
  }
  else
  {
    var10_phi_1 = 0;
    goto block5_1;
  }
  if (((int) var8_phi_2) > ((int) 1))
  {
    var8_phi_2 = var9_2;
    goto block2_2;
  }
  else
  {
    var10_phi_2 = 0;
    goto block5_2;
  }
  block8_1:
  var16_1 = ((int) var15_phi_1) * ((int) var4_1);

  block8_2:
  var16_2 = ((int) var15_phi_2) * ((int) var4_2);

  var17_1 = ((int) var14_phi_1) + ((int) 1);
  var17_2 = ((int) var14_phi_2) + ((int) 1);
  if (var17_1 == var12_phi_1)
  {
    var18_phi_1 = var16_1;
    goto block9_1;
  }
  else
  {
    var14_phi_1 = var17_1;
    var15_phi_1 = var16_1;
    goto block8_1;
  }
  if (var17_2 == var12_phi_2)
  {
    var18_phi_2 = var16_2;
    goto block9_2;
  }
  else
  {
    var14_phi_2 = var17_2;
    var15_phi_2 = var16_2;
    goto block8_2;
  }
  block9_1:
  var19_1 = ((int) var18_phi_1) % ((int) var5_1);

  block9_2:
  var19_2 = ((int) var18_phi_2) % ((int) var5_2);

  if (var13_1 > ((int) 0))
  {
    var20_phi_1 = 0;
    var21_phi_1 = 1;
    goto block10_1;
  }
  else
  {
    var24_phi_1 = 1;
    return ((int) var24_phi_1) % ((int) var5_1);
  }
  if (var13_2 > ((int) 0))
  {
    var20_phi_2 = 0;
    var21_phi_2 = 1;
    goto block10_2;
  }
  else
  {
    var24_phi_2 = 1;
    return ((int) var24_phi_2) % ((int) var5_2);
  }
  block10_1:
  var22_1 = ((int) var21_phi_1) * ((int) var19_1);

  block10_2:
  var22_2 = ((int) var21_phi_2) * ((int) var19_2);

  var23_1 = ((int) var20_phi_1) + ((int) 1);
  var23_2 = ((int) var20_phi_2) + ((int) 1);
  if (var23_1 == var13_1)
  {
    var24_phi_1 = var22_1;
    return ((int) var24_phi_1) % ((int) var5_1);
  }
  else
  {
    var20_phi_1 = var23_1;
    var21_phi_1 = var22_1;
    goto block10_1;
  }
  if (var23_2 == var13_2)
  {
    var24_phi_2 = var22_2;
    return ((int) var24_phi_2) % ((int) var5_2);
  }
  else
  {
    var20_phi_2 = var23_2;
    var21_phi_2 = var22_2;
    goto block10_2;
  }
  assert(var5_1 == var5_2);
  assert(var6_1 == var6_2);
  assert(var7_phi_1 == var7_phi_2);
  assert(var8_phi_1 == var8_phi_2);
  assert(var10_phi_1 == var10_phi_2);
  assert(var12_phi_1 == var12_phi_2);
  assert(var14_phi_1 == var14_phi_2);
  assert(var15_phi_1 == var15_phi_2);
  assert(var18_phi_1 == var18_phi_2);
  assert(var20_phi_1 == var20_phi_2);
  assert(var21_phi_1 == var21_phi_2);
  assert(var24_phi_1 == var24_phi_2);
  assert(var9_1 == var9_2);
  assert(var11_1 == var11_2);
  assert(var13_1 == var13_2);
  assert(var16_1 == var16_2);
  assert(var17_1 == var17_2);
  assert(var19_1 == var19_2);
  assert(var22_1 == var22_2);
  assert(var23_1 == var23_2);
}

unsigned int rsa(unsigned int var0, unsigned int var1, unsigned int var2, unsigned int var3, unsigned int var4)
{
  int var5;
  int var6;
  unsigned int var7_phi;
  unsigned int var8_phi;
  unsigned int var10_phi;
  unsigned int var12_phi;
  unsigned int var14_phi;
  unsigned int var15_phi;
  unsigned int var18_phi;
  unsigned int var20_phi;
  unsigned int var21_phi;
  unsigned int var24_phi;
  int var9;
  unsigned int var11;
  int var13;
  int var16;
  int var17;
  int var19;
  int var22;
  int var23;
  block0:
  var5 = ((int) var1) * ((int) var0);

  var6 = ((unsigned int) (((int) var1) + ((int) (-1)))) * ((unsigned int) (((int) var0) + ((int) (-1))));
  if (var6 > ((int) var2))
  {
    var7_phi = var2;
    goto block1;
  }
  else
  {
    var12_phi = var2;
    goto block7;
  }
  block1:
  if (((int) var7_phi) > ((int) 0))
  {
    var8_phi = var7_phi;
    goto block2;
  }
  else
  {
    var10_phi = var7_phi;
    goto block5;
  }

  block7:
  var13 = ((int) (((int) (((int) var6) * ((int) var3))) + ((int) 1))) / ((int) var12_phi);

  if (((int) var12_phi) > ((int) 0))
  {
    var14_phi = 0;
    var15_phi = 1;
    goto block8;
  }
  else
  {
    var18_phi = 1;
    goto block9;
  }
  block2:
  if ((((int) var7_phi) % ((int) var8_phi)) == 0)
  {
    if ((((int) var6) % ((int) var8_phi)) == 0)
    {
      var10_phi = var8_phi;
      goto block5;
    }
    else
    {
      goto block4;
    }
  }
  else
  {
    goto block4;
  }

  block5:
  if (var10_phi == 1)
  {
    var12_phi = var7_phi;
    goto block7;
  }
  else
  {
    var11 = var7_phi + 1;
    if (var11 == var6)
    {
      var12_phi = var6;
      goto block7;
    }
    else
    {
      var7_phi = var11;
      goto block1;
    }
  }

  block4:
  var9 = ((int) var8_phi) + ((int) (-1));

  if (((int) var8_phi) > ((int) 1))
  {
    var8_phi = var9;
    goto block2;
  }
  else
  {
    var10_phi = 0;
    goto block5;
  }
  block8:
  var16 = ((int) var15_phi) * ((int) var4);

  var17 = ((int) var14_phi) + ((int) 1);
  if (var17 == var12_phi)
  {
    var18_phi = var16;
    goto block9;
  }
  else
  {
    var14_phi = var17;
    var15_phi = var16;
    goto block8;
  }
  block9:
  var19 = ((int) var18_phi) % ((int) var5);

  if (var13 > ((int) 0))
  {
    var20_phi = 0;
    var21_phi = 1;
    goto block10;
  }
  else
  {
    var24_phi = 1;
    return ((int) var24_phi) % ((int) var5);
  }
  block10:
  var22 = ((int) var21_phi) * ((int) var19);

  var23 = ((int) var20_phi) + ((int) 1);
  if (var23 == var13)
  {
    var24_phi = var22;
    return ((int) var24_phi) % ((int) var5);
  }
  else
  {
    var20_phi = var23;
    var21_phi = var22;
    goto block10;
  }
}


