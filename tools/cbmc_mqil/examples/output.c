void complex_hybrid_8_2(int s_1, int p_1, int s_2, int p_2)
{
  int buf_1[4] = {9, 10, 11, 12};
  int buf_2[4] = {9, 10, 11, 12};
  int acc_1 = 0;
  int acc_2 = 0;
  if (s_1 > 5)
  {
    for (int i_1 = 0; i_1 < 2; i_1++)
    {
      acc_1 += s_1 + buf_1[i_1];
    }

  }
  else
  {
    acc_1 = (p_1 * 3) + buf_1[0];
  }
  if (s_2 > 5)
  {
    for (int i_2 = 0; i_2 < 2; i_2++)
    {
      acc_2 += s_2 + buf_2[i_2];
    }

  }
  else
  {
    acc_2 = (p_2 * 3) + buf_2[0];
  }
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(buf_1[i_0] == buf_2[i_0]);
  }

  assert(acc_1 == acc_2);
}

int complex_hybrid_8(int s, int p)
{
  int buf[4] = {9, 10, 11, 12};
  int acc = 0;
  if (s > 5)
  {
    for (int i = 0; i < 2; i++)
    {
      acc += s + buf[i];
    }

  }
  else
  {
    acc = (p * 3) + buf[0];
  }
  return acc;
}

void main()
{
  int master_key_1;
  int master_key_2;
  int pub_config_1;
  int pub_config_2;
  int final_res_1;
  int final_res_2;
  final_res_1 = complex_hybrid_8(master_key_1, pub_config_1);
  final_res_2 = complex_hybrid_8(master_key_2, pub_config_2);
  complex_hybrid_8_2(master_key_1, pub_config_1, master_key_2, pub_config_2);
  __CPROVER_assume(master_key_1 != master_key_2);
  __CPROVER_assume(pub_config_1 == pub_config_2);
  assert(final_res_1 == final_res_2);
}


