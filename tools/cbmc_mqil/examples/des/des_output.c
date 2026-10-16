typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct 
{
  int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
uint64_t sub_key_1[16] = {0};
uint64_t sub_key_2[16] = {0};
uint64_t sub_key[16] = {0};
uint64_t calculationofkeys(uint32_t C, uint32_t D, uint32_t L, uint32_t R, char mode);
uint64_t initial_permuatation(uint64_t input, uint32_t L, uint32_t R, uint32_t C, uint32_t D, char mode);
uint64_t schedule_calculation(uint64_t key, uint32_t C, uint32_t D, uint32_t L, uint32_t R, char mode);
uint64_t shiftingcidi(uint32_t C, uint32_t D, uint32_t L, uint32_t R, char mode);
uint64_t calculationofkeys(uint32_t C, uint32_t D, uint32_t L, uint32_t R, char mode);
uint64_t inverse_intial_permuatation(uint32_t L, uint32_t R);
uint64_t nd_sub_key();
void initial_permuatation_2(uint64_t input_1, uint32_t L_1, uint32_t R_1, uint32_t C_1, uint32_t D_1, char mode_1, uint64_t input_2, uint32_t L_2, uint32_t R_2, uint32_t C_2, uint32_t D_2, char mode_2)
{
  static char IP_1[64];
  static char IP_2[64];
  int i_1;
  int i_2;
  uint64_t init_perm_res_1 = 0;
  uint64_t init_perm_res_2 = 0;
  uint32_t L1_1;
  uint32_t L1_2;
  uint32_t R1_1;
  uint32_t R1_2;
  for (i_1 = 0, i_2 = 0; (i_1 < 64) && (i_2 < 64); i_1++, i_2++)
  {
    init_perm_res_1 <<= 1;
    init_perm_res_2 <<= 1;
    init_perm_res_1 |= (input_1 >> (64 - IP_1[i_1])) & 0x0000000000000001;
    init_perm_res_2 |= (input_2 >> (64 - IP_2[i_2])) & 0x0000000000000001;
  }

  L1_1 = ((uint32_t) (init_perm_res_1 >> 32)) & 0x00000000ffffffff;
  L1_2 = ((uint32_t) (init_perm_res_2 >> 32)) & 0x00000000ffffffff;
  R1_1 = ((uint32_t) init_perm_res_1) & 0x00000000ffffffff;
  R1_2 = ((uint32_t) init_perm_res_2) & 0x00000000ffffffff;
  L_1 = L1_1;
  L_2 = L1_2;
  R_1 = R1_1;
  R_2 = R1_2;
  __CPROVER_assume(input_1 == input_2);
  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(IP_1[i_0] == IP_2[i_0]);
  }

  assert(i_1 == i_2);
  assert(init_perm_res_1 == init_perm_res_2);
  assert(L1_1 == L1_2);
  assert(R1_1 == R1_2);
}

uint64_t initial_permuatation(uint64_t input, uint32_t L, uint32_t R, uint32_t C, uint32_t D, char mode)
{
  static char IP[64];
  int i;
  uint64_t init_perm_res = 0;
  uint32_t L1;
  uint32_t R1;
  for (i = 0; i < 64; i++)
  {
    init_perm_res <<= 1;
    init_perm_res |= (input >> (64 - IP[i])) & 0x0000000000000001;
  }

  L1 = ((uint32_t) (init_perm_res >> 32)) & 0x00000000ffffffff;
  R1 = ((uint32_t) init_perm_res) & 0x00000000ffffffff;
  L = L1;
  R = R1;
  return schedule_calculation(input, C, D, L, R, mode);
}

void schedule_calculation_2(uint64_t key_1, uint32_t C_1, uint32_t D_1, uint32_t L_1, uint32_t R_1, char mode_1, uint64_t key_2, uint32_t C_2, uint32_t D_2, uint32_t L_2, uint32_t R_2, char mode_2)
{
  static char PC1_1[56];
  static char PC1_2[56];
  int i_1;
  int i_2;
  uint64_t permuted_choice_1_1 = 0;
  uint64_t permuted_choice_1_2 = 0;
  uint64_t C1_1;
  uint64_t C1_2;
  uint64_t D1_1;
  uint64_t D1_2;
  for (i_1 = 0, i_2 = 0; (i_1 < 56) && (i_2 < 56); i_1++, i_2++)
  {
    permuted_choice_1_1 <<= 1;
    permuted_choice_1_2 <<= 1;
    permuted_choice_1_1 |= (key_1 >> (64 - PC1_1[i_1])) & 0x0000000000000001;
    permuted_choice_1_2 |= (key_2 >> (64 - PC1_2[i_2])) & 0x0000000000000001;
  }

  C1_1 = (uint32_t) ((permuted_choice_1_1 >> 28) & 0x000000000fffffff);
  C1_2 = (uint32_t) ((permuted_choice_1_2 >> 28) & 0x000000000fffffff);
  D1_1 = (uint32_t) (permuted_choice_1_1 & 0x000000000fffffff);
  D1_2 = (uint32_t) (permuted_choice_1_2 & 0x000000000fffffff);
  C_1 = C1_1;
  C_2 = C1_2;
  D_1 = D1_1;
  D_2 = D1_2;
  __CPROVER_assume(key_1 != key_2);
  for (int i_0 = 0; i_0 < 56; i_0++)
  {
    assert(PC1_1[i_0] == PC1_2[i_0]);
  }

  assert(i_1 == i_2);
  assert(permuted_choice_1_1 == permuted_choice_1_2);
  assert(C1_1 == C1_2);
  assert(D1_1 == D1_2);
}

uint64_t schedule_calculation(uint64_t key, uint32_t C, uint32_t D, uint32_t L, uint32_t R, char mode)
{
  static char PC1[56];
  int i;
  uint64_t permuted_choice_1 = 0;
  uint64_t C1;
  uint64_t D1;
  for (i = 0; i < 56; i++)
  {
    permuted_choice_1 <<= 1;
    permuted_choice_1 |= (key >> (64 - PC1[i])) & 0x0000000000000001;
  }

  C1 = (uint32_t) ((permuted_choice_1 >> 28) & 0x000000000fffffff);
  D1 = (uint32_t) (permuted_choice_1 & 0x000000000fffffff);
  C = C1;
  D = D1;
  return shiftingcidi(C, D, L, R, mode);
}

void shiftingcidi_2(uint32_t C_1, uint32_t D_1, uint32_t L_1, uint32_t R_1, char mode_1, uint32_t C_2, uint32_t D_2, uint32_t L_2, uint32_t R_2, char mode_2)
{
  static char iteration_shift_1[16];
  static char iteration_shift_2[16];
  static char PC2_1[48];
  static char PC2_2[48];
  uint64_t permuted_choice_2_1 = 0;
  uint64_t permuted_choice_2_2 = 0;
  uint32_t C1_1 = C_1;
  uint32_t C1_2 = C_2;
  uint32_t D1_1 = D_1;
  uint32_t D1_2 = D_2;
  int i_1;
  int i_2;
  int j_1;
  int j_2;
  for (i_1 = 0, i_2 = 0; (i_1 < 16) && (i_2 < 16); i_1++, i_2++)
  {
    for (j_1 = 0, j_2 = 0; (j_1 < iteration_shift_1[i_1]) && (j_2 < iteration_shift_2[i_2]); j_1++, j_2++)
    {
      C1_1 = (0x0fffffff & (C1_1 << 1)) | (0x00000001 & (C1_1 >> 27));
      C1_2 = (0x0fffffff & (C1_2 << 1)) | (0x00000001 & (C1_2 >> 27));
      D1_1 = (0x0fffffff & (D1_1 << 1)) | (0x00000001 & (D1_1 >> 27));
      D1_2 = (0x0fffffff & (D1_2 << 1)) | (0x00000001 & (D1_2 >> 27));
    }

    permuted_choice_2_1 = 0;
    permuted_choice_2_2 = 0;
    permuted_choice_2_1 = (((uint64_t) C1_1) << 28) | ((uint64_t) D1_1);
    permuted_choice_2_2 = (((uint64_t) C1_2) << 28) | ((uint64_t) D1_2);
    sub_key_1[i_1] = 0;
    sub_key_2[i_2] = 0;
    for (j_1 = 0, j_2 = 0; (j_1 < 48) && (j_2 < 48); j_1++, j_2++)
    {
      sub_key_1[i_1] <<= 1;
      sub_key_2[i_2] <<= 1;
      sub_key_1[i_1] |= (permuted_choice_2_1 >> (56 - PC2_1[j_1])) & 0x0000000000000001;
      sub_key_2[i_2] |= (permuted_choice_2_2 >> (56 - PC2_2[j_2])) & 0x0000000000000001;
    }

  }

  C_1 = C1_1;
  C_2 = C1_2;
  D_1 = D1_1;
  D_2 = D1_2;
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    assert(iteration_shift_1[i_0] == iteration_shift_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 48; i_0++)
  {
    assert(PC2_1[i_0] == PC2_2[i_0]);
  }

  assert(permuted_choice_2_1 == permuted_choice_2_2);
  assert(C1_1 == C1_2);
  assert(D1_1 == D1_2);
  assert(i_1 == i_2);
  assert(j_1 == j_2);
}

uint64_t shiftingcidi(uint32_t C, uint32_t D, uint32_t L, uint32_t R, char mode)
{
  static char iteration_shift[16];
  static char PC2[48];
  uint64_t permuted_choice_2 = 0;
  uint32_t C1 = C;
  uint32_t D1 = D;
  int i;
  int j;
  for (i = 0; i < 16; i++)
  {
    for (j = 0; j < iteration_shift[i]; j++)
    {
      C1 = (0x0fffffff & (C1 << 1)) | (0x00000001 & (C1 >> 27));
      D1 = (0x0fffffff & (D1 << 1)) | (0x00000001 & (D1 >> 27));
    }

    permuted_choice_2 = 0;
    permuted_choice_2 = (((uint64_t) C1) << 28) | ((uint64_t) D1);
    sub_key[i] = 0;
    for (j = 0; j < 48; j++)
    {
      sub_key[i] <<= 1;
      sub_key[i] |= (permuted_choice_2 >> (56 - PC2[j])) & 0x0000000000000001;
    }

  }

  C = C1;
  D = D1;
  return calculationofkeys(C, D, L, R, mode);
}

void calculationofkeys_2(uint32_t C_1, uint32_t D_1, uint32_t L_1, uint32_t R_1, char mode_1, uint32_t C_2, uint32_t D_2, uint32_t L_2, uint32_t R_2, char mode_2)
{
  static char E_1[48];
  static char E_2[48];
  static char S_1[8][64];
  static char S_2[8][64];
  static char P_1[32];
  static char P_2[32];
  char row_1;
  char row_2;
  char column_1;
  char column_2;
  uint32_t temp_1;
  uint32_t temp_2;
  uint32_t f_function_res_1 = 0;
  uint32_t f_function_res_2 = 0;
  int i_1;
  int i_2;
  int j_1;
  int j_2;
  uint32_t s_output_1 = 0;
  uint32_t s_output_2 = 0;
  uint64_t s_input_1 = 0;
  uint64_t s_input_2 = 0;
  uint32_t C1_1 = C_1;
  uint32_t C1_2 = C_2;
  uint32_t D1_1 = D_1;
  uint32_t D1_2 = D_2;
  uint32_t L1_1 = L_1;
  uint32_t L1_2 = L_2;
  uint32_t R1_1 = R_1;
  uint32_t R1_2 = R_2;
  for (i_1 = 0, i_2 = 0; (i_1 < 16) && (i_2 < 16); i_1++, i_2++)
  {
    s_input_1 = 0;
    s_input_2 = 0;
    for (j_1 = 0, j_2 = 0; (j_1 < 48) && (j_2 < 48); j_1++, j_2++)
    {
      s_input_1 <<= 1;
      s_input_2 <<= 1;
      s_input_1 |= (uint64_t) ((R1_1 >> (32 - E_1[j_1])) & 0x00000001);
      s_input_2 |= (uint64_t) ((R1_2 >> (32 - E_2[j_2])) & 0x00000001);
    }

    if (mode_1 == 'd')
    {
      s_input_1 = s_input_1 ^ sub_key_1[15 - i_1];
    }
    else
    {
      s_input_1 = s_input_1 ^ sub_key_1[i_1];
    }
    if (mode_2 == 'd')
    {
      s_input_2 = s_input_2 ^ sub_key_2[15 - i_2];
    }
    else
    {
      s_input_2 = s_input_2 ^ sub_key_2[i_2];
    }
    for (j_1 = 0, j_2 = 0; (j_1 < 8) && (j_2 < 8); j_1++, j_2++)
    {
      row_1 = (char) ((s_input_1 & (0x0000840000000000 >> (6 * j_1))) >> (42 - (6 * j_1)));
      row_2 = (char) ((s_input_2 & (0x0000840000000000 >> (6 * j_2))) >> (42 - (6 * j_2)));
      row_1 = (row_1 >> 4) | (row_1 & 0x01);
      row_2 = (row_2 >> 4) | (row_2 & 0x01);
      column_1 = (char) ((s_input_1 & (0x0000780000000000 >> (6 * j_1))) >> (43 - (6 * j_1)));
      column_2 = (char) ((s_input_2 & (0x0000780000000000 >> (6 * j_2))) >> (43 - (6 * j_2)));
      s_output_1 <<= 4;
      s_output_2 <<= 4;
      s_output_1 |= (uint32_t) (S_1[j_1][(16 * row_1) + column_1] & 0x0f);
      s_output_2 |= (uint32_t) (S_2[j_2][(16 * row_2) + column_2] & 0x0f);
    }

    f_function_res_1 = 0;
    f_function_res_2 = 0;
    for (j_1 = 0, j_2 = 0; (j_1 < 32) && (j_2 < 32); j_1++, j_2++)
    {
      f_function_res_1 <<= 1;
      f_function_res_2 <<= 1;
      f_function_res_1 |= (s_output_1 >> (32 - P_1[j_1])) & 0x00000001;
      f_function_res_2 |= (s_output_2 >> (32 - P_2[j_2])) & 0x00000001;
    }

    temp_1 = R1_1;
    temp_2 = R1_2;
    R1_1 = L1_1 ^ f_function_res_1;
    R1_2 = L1_2 ^ f_function_res_2;
    L1_1 = temp_1;
    L1_2 = temp_2;
    C_1 = C1_1;
    C_2 = C1_2;
    D_1 = D1_1;
    D_2 = D1_2;
    L_1 = L1_1;
    L_2 = L1_2;
    R_1 = R1_1;
    R_2 = R1_2;
  }

  for (int i_0 = 0; i_0 < 48; i_0++)
  {
    assert(E_1[i_0] == E_2[i_0]);
  }

  for (int i_0 = 0; i_0 < 8; i_0++)
  {
    for (int i_1 = 0; i_1 < 64; i_1++)
    {
      assert(S_1[i_0][i_1] == S_2[i_0][i_1]);
    }

  }

  for (int i_0 = 0; i_0 < 32; i_0++)
  {
    assert(P_1[i_0] == P_2[i_0]);
  }

  assert(row_1 == row_2);
  assert(column_1 == column_2);
  assert(temp_1 == temp_2);
  assert(f_function_res_1 == f_function_res_2);
  assert(i_1 == i_2);
  assert(j_1 == j_2);
  assert(s_output_1 == s_output_2);
  assert(s_input_1 == s_input_2);
  assert(C1_1 == C1_2);
  assert(D1_1 == D1_2);
  assert(L1_1 == L1_2);
  assert(R1_1 == R1_2);
}

uint64_t calculationofkeys(uint32_t C, uint32_t D, uint32_t L, uint32_t R, char mode)
{
  static char E[48];
  static char S[8][64];
  static char P[32];
  char row;
  char column;
  uint32_t temp;
  uint32_t f_function_res = 0;
  int i;
  int j;
  uint32_t s_output = 0;
  uint64_t s_input = 0;
  uint32_t C1 = C;
  uint32_t D1 = D;
  uint32_t L1 = L;
  uint32_t R1 = R;
  for (i = 0; i < 16; i++)
  {
    s_input = 0;
    for (j = 0; j < 48; j++)
    {
      s_input <<= 1;
      s_input |= (uint64_t) ((R1 >> (32 - E[j])) & 0x00000001);
    }

    if (mode == 'd')
    {
      s_input = s_input ^ sub_key[15 - i];
    }
    else
    {
      s_input = s_input ^ sub_key[i];
    }
    for (j = 0; j < 8; j++)
    {
      row = (char) ((s_input & (0x0000840000000000 >> (6 * j))) >> (42 - (6 * j)));
      row = (row >> 4) | (row & 0x01);
      column = (char) ((s_input & (0x0000780000000000 >> (6 * j))) >> (43 - (6 * j)));
      s_output <<= 4;
      s_output |= (uint32_t) (S[j][(16 * row) + column] & 0x0f);
    }

    f_function_res = 0;
    for (j = 0; j < 32; j++)
    {
      f_function_res <<= 1;
      f_function_res |= (s_output >> (32 - P[j])) & 0x00000001;
    }

    temp = R1;
    R1 = L1 ^ f_function_res;
    L1 = temp;
    C = C1;
    D = D1;
    L = L1;
    R = R1;
  }

  return inverse_intial_permuatation(L, R);
}

void inverse_intial_permuatation_2(uint32_t L_1, uint32_t R_1, uint32_t L_2, uint32_t R_2)
{
  static char PI_1[64];
  static char PI_2[64];
  uint64_t pre_output_1 = 0;
  uint64_t pre_output_2 = 0;
  int i_1;
  int i_2;
  uint32_t L1_1 = L_1;
  uint32_t L1_2 = L_2;
  uint32_t R1_1 = R_1;
  uint32_t R1_2 = R_2;
  pre_output_1 = (((uint64_t) R1_1) << 32) | ((uint64_t) L1_1);
  pre_output_2 = (((uint64_t) R1_2) << 32) | ((uint64_t) L1_2);
  uint64_t inv_init_perm_res_1 = 0;
  uint64_t inv_init_perm_res_2 = 0;
  for (i_1 = 0, i_2 = 0; (i_1 < 64) && (i_2 < 64); i_1++, i_2++)
  {
    inv_init_perm_res_1 <<= 1;
    inv_init_perm_res_2 <<= 1;
    inv_init_perm_res_1 |= (pre_output_1 >> (64 - PI_1[i_1])) & 0x0000000000000001;
    inv_init_perm_res_2 |= (pre_output_2 >> (64 - PI_2[i_2])) & 0x0000000000000001;
  }

  for (int i_0 = 0; i_0 < 64; i_0++)
  {
    assert(PI_1[i_0] == PI_2[i_0]);
  }

  assert(pre_output_1 == pre_output_2);
  assert(i_1 == i_2);
  assert(L1_1 == L1_2);
  assert(R1_1 == R1_2);
  assert(inv_init_perm_res_1 == inv_init_perm_res_2);
}

uint64_t inverse_intial_permuatation(uint32_t L, uint32_t R)
{
  static char PI[64];
  uint64_t pre_output = 0;
  int i;
  uint32_t L1 = L;
  uint32_t R1 = R;
  pre_output = (((uint64_t) R1) << 32) | ((uint64_t) L1);
  uint64_t inv_init_perm_res = 0;
  for (i = 0; i < 64; i++)
  {
    inv_init_perm_res <<= 1;
    inv_init_perm_res |= (pre_output >> (64 - PI[i])) & 0x0000000000000001;
  }

  return inv_init_perm_res;
}

void main()
{
  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    sub_key_1[i_0] = nd_sub_key();
  }

  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    sub_key_2[i_0] = nd_sub_key();
  }

  int i_1;
  int i_2;
  uint64_t input_1;
  uint64_t input_2;
  uint64_t key_1;
  uint64_t key_2;
  uint64_t result_1 = input_1;
  uint64_t result_2 = input_2;
  uint32_t C_1 = 0;
  uint32_t C_2 = 0;
  uint32_t D_1 = 0;
  uint32_t D_2 = 0;
  uint32_t L_1 = 0;
  uint32_t L_2 = 0;
  uint32_t R_1 = 0;
  uint32_t R_2 = 0;
  char mode_1 = 'e';
  char mode_2 = 'e';
  for (i_1 = 0, i_2 = 0; (i_1 < 16) && (i_2 < 16); i_1++, i_2++)
  {
    C_1 = 0;
    C_2 = 0;
    L_1 = 0;
    L_2 = 0;
    R_1 = 0;
    R_2 = 0;
    D_1 = 0;
    D_2 = 0;
    result_1 = initial_permuatation(result_1, L_1, R_1, C_1, D_1, mode_1);
    result_2 = initial_permuatation(result_2, L_2, R_2, C_2, D_2, mode_2);
    initial_permuatation_2(result_1, L_1, R_1, C_1, D_1, mode_1, result_2, L_2, R_2, C_2, D_2, mode_2);
  }

  for (int i_0 = 0; i_0 < 16; i_0++)
  {
    __CPROVER_assume(sub_key_1[i_0] != sub_key_2[i_0]);
  }

  __CPROVER_assume(input_1 == input_2);
  assert(i_1 == i_2);
  assert(result_1 == result_2);
  assert(C_1 == C_2);
  assert(D_1 == D_2);
  assert(L_1 == L_2);
  assert(R_1 == R_2);
  assert(mode_1 == mode_2);
}


