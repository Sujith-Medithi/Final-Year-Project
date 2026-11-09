#include <assert.h>
typedef void FILE;
typedef unsigned int size_t;
extern FILE *stdin_1;
extern FILE *stdin_2;
extern FILE *stdin;
extern FILE *stdout_1;
extern FILE *stdout_2;
extern FILE *stdout;
extern FILE *stderr_1;
extern FILE *stderr_2;
extern FILE *stderr;
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);
int puts(const char *str);
int putchar(int c);
int getchar(void);
typedef unsigned int size_t;
void *malloc(size_t size);
void *calloc(size_t num, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
void exit(int status);
void abort(void);
int abs(int j);
long int labs(long int j);
int rand(void);
void srand(unsigned int seed);
typedef unsigned int size_t;
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
size_t strlen(const char *s);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char *strcat(char *dest, const char *src);
struct FilterState_R001217_1713_0
{
  int cutoff;
  unsigned char damping;
  int gain_db;
  int mode;
  int buffer[3];
};
struct Transaction_R001217_1713_1
{
  unsigned char rate;
  unsigned char fee;
  unsigned char account_id;
  int status;
  short balance;
  int buffer[3];
};
union RegisterBank_R001217_1713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001217_1713_1
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
int g_out_1 = 0;
int g_out_2 = 0;
int g_out = 0;
int g_chk_1 = 0;
int g_chk_2 = 0;
int g_chk = 0;
int g_telemetry_1 = 0;
int g_telemetry_2 = 0;
int g_telemetry = 0;
void fn_R001217_1713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_76_1 = local_arr_1[aux_1 % 3];
  int stride_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_76_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_41_1 = 0;
  int threshold_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_41_1 = ((threshold_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_41_2 = ((threshold_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_41_1) & 127;
    acc_2 = (acc_2 + threshold_41_2) & 127;
  }

  int index_reg_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_54_1 > 31)
  {
    acc_1 = ((acc_1 + (index_reg_54_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_54_2 > 31)
  {
    acc_2 = ((acc_2 + (index_reg_54_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_54_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_76_1 == stride_76_2);
  assert(threshold_41_1 == threshold_41_2);
  assert(index_reg_54_1 == index_reg_54_2);
}

int fn_R001217_1713_0(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int stride_76 = local_arr[aux % 3];
  acc = (acc + (stride_76 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_41 = ((threshold_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_41) & 127;
  }

  int index_reg_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_54 > 31)
  {
    acc = ((acc + (index_reg_54 * 2)) + 5) & 127;
    aux ^= index_reg_54 & 15;
  }
  else
  {
    acc = ((acc - index_reg_54) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001217_1713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int sample_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_74_1)
  {
    case 0:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (sample_74_2)
  {
    case 0:
      acc_2 = (acc_2 + 6) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_87_1 = 0;
  int offset_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_87_1 = ((offset_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_87_2 = ((offset_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_87_1) & 127;
    acc_2 = (acc_2 + offset_87_2) & 127;
  }

  int weight_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_89_1 > 24)
  {
    acc_1 = ((acc_1 + (weight_89_1 * 2)) + 5) & 127;
    aux_1 ^= weight_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_89_2 > 24)
  {
    acc_2 = ((acc_2 + (weight_89_2 * 2)) + 5) & 127;
    aux_2 ^= weight_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_74_1 == sample_74_2);
  assert(offset_87_1 == offset_87_2);
  assert(weight_89_1 == weight_89_2);
}

int fn_R001217_1713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int sample_74 = (aux + st.buffer[1]) & 3;
  switch (sample_74)
  {
    case 0:
      acc = (acc + 6) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_87 = ((offset_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_87) & 127;
  }

  int weight_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_89 > 24)
  {
    acc = ((acc + (weight_89 * 2)) + 5) & 127;
    aux ^= weight_89 & 15;
  }
  else
  {
    acc = ((acc - weight_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001217_1713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int coefficient_25_1 = 0;
  int coefficient_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_25_1 = ((coefficient_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_25_2 = ((coefficient_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_25_1) & 127;
    acc_2 = (acc_2 + coefficient_25_2) & 127;
  }

  int index_reg_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_84_1)
  {
    case 0:
      acc_1 = (acc_1 + 1) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (index_reg_84_2)
  {
    case 0:
      acc_2 = (acc_2 + 1) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int pivot_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_50_1) & 63;
  aux_2 = (aux_2 + pivot_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_60_1 = local_arr_1[aux_1 % 3];
  int index_reg_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_25_1 == coefficient_25_2);
  assert(index_reg_84_1 == index_reg_84_2);
  assert(pivot_50_1 == pivot_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_60_1 == index_reg_60_2);
}

int fn_R001217_1713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int coefficient_25 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_25 = ((coefficient_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_25) & 127;
  }

  int index_reg_84 = (aux + st.buffer[1]) & 3;
  switch (index_reg_84)
  {
    case 0:
      acc = (acc + 1) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int pivot_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_50) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_60 = local_arr[aux % 3];
  acc = (acc + (index_reg_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001217_1713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int accumulator_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_25_1)
  {
    case 0:
      acc_1 = (acc_1 + 5) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (accumulator_25_2)
  {
    case 0:
      acc_2 = (acc_2 + 5) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_37_1 = local_arr_1[aux_1 % 3];
  int offset_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_37_2 * 2)) & 127;
  int parity_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_81_1 > 29)
  {
    acc_1 = ((acc_1 + (parity_81_1 * 2)) + 5) & 127;
    aux_1 ^= parity_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_81_2 > 29)
  {
    acc_2 = ((acc_2 + (parity_81_2 * 2)) + 5) & 127;
    aux_2 ^= parity_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_25_1 == accumulator_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_37_1 == offset_37_2);
  assert(parity_81_1 == parity_81_2);
}

int fn_R001217_1713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int accumulator_25 = (aux + st.buffer[1]) & 3;
  switch (accumulator_25)
  {
    case 0:
      acc = (acc + 5) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int local_arr[3] = {4, 9, 15};
  int offset_37 = local_arr[aux % 3];
  acc = (acc + (offset_37 * 2)) & 127;
  int parity_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_81 > 29)
  {
    acc = ((acc + (parity_81 * 2)) + 5) & 127;
    aux ^= parity_81 & 15;
  }
  else
  {
    acc = ((acc - parity_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001217_1713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st_1 = {0};
  struct FilterState_R001217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_25_1 = local_arr_1[aux_1 % 3];
  int quantum_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_25_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_27_1)
  {
    case 0:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (stride_27_2)
  {
    case 0:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_25_1 == quantum_25_2);
  assert(stride_27_1 == stride_27_2);
}

int fn_R001217_1713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int quantum_25 = local_arr[aux % 3];
  acc = (acc + (quantum_25 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_27 = (aux + st.buffer[1]) & 3;
  switch (stride_27)
  {
    case 0:
      acc = (acc + 8) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  return (acc + aux) & 255;
}

void fn_R001217_1713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st_1 = {0};
  struct FilterState_R001217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int index_reg_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_30_1)
  {
    case 0:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (index_reg_30_2)
  {
    case 0:
      acc_2 = (acc_2 + 6) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_19_1 = local_arr_1[aux_1 % 3];
  int damping_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_19_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_70_1 = 0;
  int margin_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_70_1 = ((margin_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_70_2 = ((margin_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_70_1) & 127;
    acc_2 = (acc_2 + margin_70_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_30_1 == index_reg_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_19_1 == damping_19_2);
  assert(margin_70_1 == margin_70_2);
}

int fn_R001217_1713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int index_reg_30 = (aux + st.buffer[1]) & 3;
  switch (index_reg_30)
  {
    case 0:
      acc = (acc + 6) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int local_arr[3] = {4, 9, 15};
  int damping_19 = local_arr[aux % 3];
  acc = (acc + (damping_19 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_70 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_70 = ((margin_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_70) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001217_1713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st_1 = {0};
  struct FilterState_R001217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int tracker_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_29_1) & 63;
  aux_2 = (aux_2 + tracker_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_74_1)
  {
    case 0:
      acc_1 = (acc_1 + 4) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (window_74_2)
  {
    case 0:
      acc_2 = (acc_2 + 4) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_29_1 == tracker_29_2);
  assert(window_74_1 == window_74_2);
}

int fn_R001217_1713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int tracker_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_29) & 63;
  acc ^= aux;
  int window_74 = (aux + st.buffer[1]) & 3;
  switch (window_74)
  {
    case 0:
      acc = (acc + 4) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  return (acc + aux) & 255;
}

void fn_R001217_1713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st_1 = {0};
  struct FilterState_R001217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int window_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_92_1 > 14)
  {
    acc_1 = ((acc_1 + (window_92_1 * 2)) + 5) & 127;
    aux_1 ^= window_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_92_2 > 14)
  {
    acc_2 = ((acc_2 + (window_92_2 * 2)) + 5) & 127;
    aux_2 ^= window_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_85_1) & 63;
  aux_2 = (aux_2 + tally_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_25_1 = 0;
  int checksum_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_25_1 = ((checksum_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_25_2 = ((checksum_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_25_1) & 127;
    acc_2 = (acc_2 + checksum_25_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_95_1 = local_arr_1[aux_1 % 3];
  int residue_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_92_1 == window_92_2);
  assert(tally_85_1 == tally_85_2);
  assert(checksum_25_1 == checksum_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_95_1 == residue_95_2);
}

int fn_R001217_1713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int window_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_92 > 14)
  {
    acc = ((acc + (window_92 * 2)) + 5) & 127;
    aux ^= window_92 & 15;
  }
  else
  {
    acc = ((acc - window_92) + 11) & 127;
    aux += 3;
  }
  int tally_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_85) & 63;
  acc ^= aux;
  int checksum_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_25 = ((checksum_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_25) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int residue_95 = local_arr[aux % 3];
  acc = (acc + (residue_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001217_1713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int parity_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_32_1)
  {
    case 0:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (parity_32_2)
  {
    case 0:
      acc_2 = (acc_2 + 6) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int factor_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_78_1) & 63;
  aux_2 = (aux_2 + factor_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_65_1 > 30)
  {
    acc_1 = ((acc_1 + (checksum_65_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_65_2 > 30)
  {
    acc_2 = ((acc_2 + (checksum_65_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_32_1 == parity_32_2);
  assert(factor_78_1 == factor_78_2);
  assert(checksum_65_1 == checksum_65_2);
}

int fn_R001217_1713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int parity_32 = (aux + st.buffer[1]) & 3;
  switch (parity_32)
  {
    case 0:
      acc = (acc + 6) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int factor_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_78) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_65 > 30)
  {
    acc = ((acc + (checksum_65 * 2)) + 5) & 127;
    aux ^= checksum_65 & 15;
  }
  else
  {
    acc = ((acc - checksum_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001217_1713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int tracker_89_1 = 0;
  int tracker_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_89_1 = ((tracker_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_89_2 = ((tracker_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_89_1) & 127;
    acc_2 = (acc_2 + tracker_89_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_70_1 = local_arr_1[aux_1 % 3];
  int anchor_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_70_2 * 2)) & 127;
  int offset_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_28_1 > 10)
  {
    acc_1 = ((acc_1 + (offset_28_1 * 2)) + 5) & 127;
    aux_1 ^= offset_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_28_2 > 10)
  {
    acc_2 = ((acc_2 + (offset_28_2 * 2)) + 5) & 127;
    aux_2 ^= offset_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_55_1)
  {
    case 0:
      acc_1 = (acc_1 + 2) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (anchor_55_2)
  {
    case 0:
      acc_2 = (acc_2 + 2) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_89_1 == tracker_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_70_1 == anchor_70_2);
  assert(offset_28_1 == offset_28_2);
  assert(anchor_55_1 == anchor_55_2);
}

int fn_R001217_1713_9(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int tracker_89 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_89 = ((tracker_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_89) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_70 = local_arr[aux % 3];
  acc = (acc + (anchor_70 * 2)) & 127;
  int offset_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_28 > 10)
  {
    acc = ((acc + (offset_28 * 2)) + 5) & 127;
    aux ^= offset_28 & 15;
  }
  else
  {
    acc = ((acc - offset_28) + 11) & 127;
    aux += 3;
  }
  int anchor_55 = (aux + st.buffer[1]) & 3;
  switch (anchor_55)
  {
    case 0:
      acc = (acc + 2) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  return (acc + aux) & 255;
}

void fn_R001217_1713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int quantum_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_52_1 > 38)
  {
    acc_1 = ((acc_1 + (quantum_52_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_52_2 > 38)
  {
    acc_2 = ((acc_2 + (quantum_52_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_63_1) & 63;
  aux_2 = (aux_2 + quotient_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_34_1 = 0;
  int damping_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_34_1 = ((damping_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_34_2 = ((damping_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_34_1) & 127;
    acc_2 = (acc_2 + damping_34_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_52_1 == quantum_52_2);
  assert(quotient_63_1 == quotient_63_2);
  assert(damping_34_1 == damping_34_2);
}

int fn_R001217_1713_10(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int quantum_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_52 > 38)
  {
    acc = ((acc + (quantum_52 * 2)) + 5) & 127;
    aux ^= quantum_52 & 15;
  }
  else
  {
    acc = ((acc - quantum_52) + 11) & 127;
    aux += 3;
  }
  int quotient_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_63) & 63;
  acc ^= aux;
  int damping_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_34 = ((damping_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_34) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001217_1713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int threshold_12_1 = 0;
  int threshold_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_12_1 = ((threshold_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_12_2 = ((threshold_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_12_1) & 127;
    acc_2 = (acc_2 + threshold_12_2) & 127;
  }

  int offset_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_10_1)
  {
    case 0:
      acc_1 = (acc_1 + 3) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (offset_10_2)
  {
    case 0:
      acc_2 = (acc_2 + 3) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_12_1 == threshold_12_2);
  assert(offset_10_1 == offset_10_2);
}

int fn_R001217_1713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int threshold_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_12 = ((threshold_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_12) & 127;
  }

  int offset_10 = (aux + st.buffer[1]) & 3;
  switch (offset_10)
  {
    case 0:
      acc = (acc + 3) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  return (acc + aux) & 255;
}

void fn_R001217_1713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int weight_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_96_1) & 63;
  aux_2 = (aux_2 + weight_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_12_1 = local_arr_1[aux_1 % 3];
  int tally_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_96_1 == weight_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_12_1 == tally_12_2);
}

int fn_R001217_1713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int weight_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_96) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_12 = local_arr[aux % 3];
  acc = (acc + (tally_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001217_1713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st_1 = {0};
  struct FilterState_R001217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int delta_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_46_1)
  {
    case 0:
      acc_1 = (acc_1 + 4) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (delta_46_2)
  {
    case 0:
      acc_2 = (acc_2 + 4) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int tally_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_29_1 > 26)
  {
    acc_1 = ((acc_1 + (tally_29_1 * 2)) + 5) & 127;
    aux_1 ^= tally_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_29_2 > 26)
  {
    acc_2 = ((acc_2 + (tally_29_2 * 2)) + 5) & 127;
    aux_2 ^= tally_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_46_1 == delta_46_2);
  assert(tally_29_1 == tally_29_2);
}

int fn_R001217_1713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int delta_46 = (aux + st.buffer[1]) & 3;
  switch (delta_46)
  {
    case 0:
      acc = (acc + 4) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int tally_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_29 > 26)
  {
    acc = ((acc + (tally_29 * 2)) + 5) & 127;
    aux ^= tally_29 & 15;
  }
  else
  {
    acc = ((acc - tally_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001217_1713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st_1 = {0};
  struct FilterState_R001217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int vector_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_80_1 > 50)
  {
    acc_1 = ((acc_1 + (vector_80_1 * 2)) + 5) & 127;
    aux_1 ^= vector_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_80_2 > 50)
  {
    acc_2 = ((acc_2 + (vector_80_2 * 2)) + 5) & 127;
    aux_2 ^= vector_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_79_1 = 0;
  int index_reg_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_79_1 = ((index_reg_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_79_2 = ((index_reg_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_79_1) & 127;
    acc_2 = (acc_2 + index_reg_79_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_80_1 == vector_80_2);
  assert(index_reg_79_1 == index_reg_79_2);
}

int fn_R001217_1713_14(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int vector_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_80 > 50)
  {
    acc = ((acc + (vector_80 * 2)) + 5) & 127;
    aux ^= vector_80 & 15;
  }
  else
  {
    acc = ((acc - vector_80) + 11) & 127;
    aux += 3;
  }
  int index_reg_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_79 = ((index_reg_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_79) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001217_1713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int checksum_95_1 = 0;
  int checksum_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_95_1 = ((checksum_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_95_2 = ((checksum_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_95_1) & 127;
    acc_2 = (acc_2 + checksum_95_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_73_1 = local_arr_1[aux_1 % 3];
  int bound_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_95_1 == checksum_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_73_1 == bound_73_2);
}

int fn_R001217_1713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int checksum_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_95 = ((checksum_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_95) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int bound_73 = local_arr[aux % 3];
  acc = (acc + (bound_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001217_1713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_55_1 = local_arr_1[aux_1 % 3];
  int cursor_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_55_2 * 2)) & 127;
  int stride_44_1 = 0;
  int stride_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_44_1 = ((stride_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_44_2 = ((stride_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_44_1) & 127;
    acc_2 = (acc_2 + stride_44_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_55_1 == cursor_55_2);
  assert(stride_44_1 == stride_44_2);
}

int fn_R001217_1713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int cursor_55 = local_arr[aux % 3];
  acc = (acc + (cursor_55 * 2)) & 127;
  int stride_44 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_44 = ((stride_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_44) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001217_1713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st_1 = {0};
  struct FilterState_R001217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_25_1 = 0;
  int damping_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_25_1 = ((damping_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_25_2 = ((damping_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_25_1) & 127;
    acc_2 = (acc_2 + damping_25_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_25_1 == damping_25_2);
}

int fn_R001217_1713_17(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_25 = ((damping_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_25) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001217_1713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st_1 = {0};
  struct FilterState_R001217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tracker_14_1 = 0;
  int tracker_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_14_1 = ((tracker_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_14_2 = ((tracker_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_14_1) & 127;
    acc_2 = (acc_2 + tracker_14_2) & 127;
  }

  int weight_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_32_1 > 15)
  {
    acc_1 = ((acc_1 + (weight_32_1 * 2)) + 5) & 127;
    aux_1 ^= weight_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_32_2 > 15)
  {
    acc_2 = ((acc_2 + (weight_32_2 * 2)) + 5) & 127;
    aux_2 ^= weight_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_32_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_14_1 == tracker_14_2);
  assert(weight_32_1 == weight_32_2);
}

int fn_R001217_1713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tracker_14 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_14 = ((tracker_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_14) & 127;
  }

  int weight_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_32 > 15)
  {
    acc = ((acc + (weight_32 * 2)) + 5) & 127;
    aux ^= weight_32 & 15;
  }
  else
  {
    acc = ((acc - weight_32) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001217_1713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int residue_60_1 = 0;
  int residue_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_60_1 = ((residue_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_60_2 = ((residue_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_60_1) & 127;
    acc_2 = (acc_2 + residue_60_2) & 127;
  }

  int anchor_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_25_1)
  {
    case 0:
      acc_1 = (acc_1 + 8) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (anchor_25_2)
  {
    case 0:
      acc_2 = (acc_2 + 8) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int stride_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_27_1 > 50)
  {
    acc_1 = ((acc_1 + (stride_27_1 * 2)) + 5) & 127;
    aux_1 ^= stride_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_27_2 > 50)
  {
    acc_2 = ((acc_2 + (stride_27_2 * 2)) + 5) & 127;
    aux_2 ^= stride_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_27_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_60_1 == residue_60_2);
  assert(anchor_25_1 == anchor_25_2);
  assert(stride_27_1 == stride_27_2);
}

int fn_R001217_1713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int residue_60 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_60 = ((residue_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_60) & 127;
  }

  int anchor_25 = (aux + st.buffer[1]) & 3;
  switch (anchor_25)
  {
    case 0:
      acc = (acc + 8) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int stride_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_27 > 50)
  {
    acc = ((acc + (stride_27 * 2)) + 5) & 127;
    aux ^= stride_27 & 15;
  }
  else
  {
    acc = ((acc - stride_27) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001217_1713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st_1 = {0};
  struct Transaction_R001217_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int mask_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_18_1)
  {
    case 0:
      acc_1 = (acc_1 + 3) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (mask_18_2)
  {
    case 0:
      acc_2 = (acc_2 + 3) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int parity_53_1 = 0;
  int parity_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_53_1 = ((parity_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_53_2 = ((parity_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_53_1) & 127;
    acc_2 = (acc_2 + parity_53_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_18_1 == mask_18_2);
  assert(parity_53_1 == parity_53_2);
}

int fn_R001217_1713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001217_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int mask_18 = (aux + st.buffer[1]) & 3;
  switch (mask_18)
  {
    case 0:
      acc = (acc + 3) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int parity_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_53 = ((parity_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_53) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001217_1713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st_1 = {0};
  struct FilterState_R001217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_60_1 = local_arr_1[aux_1 % 3];
  int checksum_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_60_1 == checksum_60_2);
}

int fn_R001217_1713_21(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_60 = local_arr[aux % 3];
  acc = (acc + (checksum_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001217_1713_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st_1 = {0};
  struct FilterState_R001217_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_91_1 = local_arr_1[aux_1 % 3];
  int margin_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_91_2 * 2)) & 127;
  int vector_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_44_1)
  {
    case 0:
      acc_1 = (acc_1 + 6) & 127;
      break;

    case 1:
      aux_1 ^= 0x1F;
      break;

    case 2:
      acc_1 = (acc_1 ^ 0x2A) & 127;
      break;

    default:
      acc_1 = (acc_1 + 7) & 127;
      break;

  }

  switch (vector_44_2)
  {
    case 0:
      acc_2 = (acc_2 + 6) & 127;
      break;

    case 1:
      aux_2 ^= 0x1F;
      break;

    case 2:
      acc_2 = (acc_2 ^ 0x2A) & 127;
      break;

    default:
      acc_2 = (acc_2 + 7) & 127;
      break;

  }

  int scale_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_99_1) & 63;
  aux_2 = (aux_2 + scale_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_91_1 == margin_91_2);
  assert(vector_44_1 == vector_44_2);
  assert(scale_99_1 == scale_99_2);
}

int fn_R001217_1713_22(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001217_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int margin_91 = local_arr[aux % 3];
  acc = (acc + (margin_91 * 2)) & 127;
  int vector_44 = (aux + st.buffer[1]) & 3;
  switch (vector_44)
  {
    case 0:
      acc = (acc + 6) & 127;
      break;

    case 1:
      aux ^= 0x1F;
      break;

    case 2:
      acc = (acc ^ 0x2A) & 127;
      break;

    default:
      acc = (acc + 7) & 127;
      break;

  }

  int scale_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001217_0_1;
  int sec_r001217_0_2;
  int sec_r001217_1_1;
  int sec_r001217_1_2;
  int sec_r001217_2_1;
  int sec_r001217_2_2;
  int sec_r001217_3_1;
  int sec_r001217_3_2;
  int sec_r001217_4_1;
  int sec_r001217_4_2;
  int sec_r001217_5_1;
  int sec_r001217_5_2;
  int sec_r001217_6_1;
  int sec_r001217_6_2;
  int sec_r001217_7_1;
  int sec_r001217_7_2;
  int sec_r001217_8_1;
  int sec_r001217_8_2;
  int sec_r001217_9_1;
  int sec_r001217_9_2;
  int sec_r001217_10_1;
  int sec_r001217_10_2;
  int sec_r001217_11_1;
  int sec_r001217_11_2;
  int sec_r001217_12_1;
  int sec_r001217_12_2;
  int sec_r001217_13_1;
  int sec_r001217_13_2;
  int sec_r001217_14_1;
  int sec_r001217_14_2;
  int sec_r001217_15_1;
  int sec_r001217_15_2;
  int sec_r001217_16_1;
  int sec_r001217_16_2;
  int sec_r001217_17_1;
  int sec_r001217_17_2;
  int sec_r001217_18_1;
  int sec_r001217_18_2;
  int sec_r001217_19_1;
  int sec_r001217_19_2;
  int sec_r001217_20_1;
  int sec_r001217_20_2;
  int sec_r001217_21_1;
  int sec_r001217_21_2;
  int sec_r001217_22_1;
  int sec_r001217_22_2;
  int pub_r001217_0_1;
  int pub_r001217_0_2;
  int pub_r001217_1_1;
  int pub_r001217_1_2;
  int pub_r001217_2_1;
  int pub_r001217_2_2;
  int pub_r001217_3_1;
  int pub_r001217_3_2;
  int pub_r001217_4_1;
  int pub_r001217_4_2;
  int pub_r001217_5_1;
  int pub_r001217_5_2;
  int pub_r001217_6_1;
  int pub_r001217_6_2;
  int pub_r001217_7_1;
  int pub_r001217_7_2;
  int pub_r001217_8_1;
  int pub_r001217_8_2;
  int pub_r001217_9_1;
  int pub_r001217_9_2;
  int pub_r001217_10_1;
  int pub_r001217_10_2;
  int pub_r001217_11_1;
  int pub_r001217_11_2;
  int pub_r001217_12_1;
  int pub_r001217_12_2;
  int pub_r001217_13_1;
  int pub_r001217_13_2;
  int pub_r001217_14_1;
  int pub_r001217_14_2;
  int pub_r001217_15_1;
  int pub_r001217_15_2;
  int pub_r001217_16_1;
  int pub_r001217_16_2;
  int pub_r001217_17_1;
  int pub_r001217_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001217_0_1 >= (-100)) && (pub_r001217_0_1 <= 100));
  __CPROVER_assume((pub_r001217_0_2 >= (-100)) && (pub_r001217_0_2 <= 100));
  __CPROVER_assume((pub_r001217_1_1 >= (-100)) && (pub_r001217_1_1 <= 100));
  __CPROVER_assume((pub_r001217_1_2 >= (-100)) && (pub_r001217_1_2 <= 100));
  __CPROVER_assume((pub_r001217_2_1 >= (-100)) && (pub_r001217_2_1 <= 100));
  __CPROVER_assume((pub_r001217_2_2 >= (-100)) && (pub_r001217_2_2 <= 100));
  __CPROVER_assume((pub_r001217_3_1 >= (-100)) && (pub_r001217_3_1 <= 100));
  __CPROVER_assume((pub_r001217_3_2 >= (-100)) && (pub_r001217_3_2 <= 100));
  __CPROVER_assume((pub_r001217_4_1 >= (-100)) && (pub_r001217_4_1 <= 100));
  __CPROVER_assume((pub_r001217_4_2 >= (-100)) && (pub_r001217_4_2 <= 100));
  __CPROVER_assume((pub_r001217_5_1 >= (-100)) && (pub_r001217_5_1 <= 100));
  __CPROVER_assume((pub_r001217_5_2 >= (-100)) && (pub_r001217_5_2 <= 100));
  __CPROVER_assume((pub_r001217_6_1 >= (-100)) && (pub_r001217_6_1 <= 100));
  __CPROVER_assume((pub_r001217_6_2 >= (-100)) && (pub_r001217_6_2 <= 100));
  __CPROVER_assume((pub_r001217_7_1 >= (-100)) && (pub_r001217_7_1 <= 100));
  __CPROVER_assume((pub_r001217_7_2 >= (-100)) && (pub_r001217_7_2 <= 100));
  __CPROVER_assume((pub_r001217_8_1 >= (-100)) && (pub_r001217_8_1 <= 100));
  __CPROVER_assume((pub_r001217_8_2 >= (-100)) && (pub_r001217_8_2 <= 100));
  __CPROVER_assume((pub_r001217_9_1 >= (-100)) && (pub_r001217_9_1 <= 100));
  __CPROVER_assume((pub_r001217_9_2 >= (-100)) && (pub_r001217_9_2 <= 100));
  __CPROVER_assume((pub_r001217_10_1 >= (-100)) && (pub_r001217_10_1 <= 100));
  __CPROVER_assume((pub_r001217_10_2 >= (-100)) && (pub_r001217_10_2 <= 100));
  __CPROVER_assume((pub_r001217_11_1 >= (-100)) && (pub_r001217_11_1 <= 100));
  __CPROVER_assume((pub_r001217_11_2 >= (-100)) && (pub_r001217_11_2 <= 100));
  __CPROVER_assume((pub_r001217_12_1 >= (-100)) && (pub_r001217_12_1 <= 100));
  __CPROVER_assume((pub_r001217_12_2 >= (-100)) && (pub_r001217_12_2 <= 100));
  __CPROVER_assume((pub_r001217_13_1 >= (-100)) && (pub_r001217_13_1 <= 100));
  __CPROVER_assume((pub_r001217_13_2 >= (-100)) && (pub_r001217_13_2 <= 100));
  __CPROVER_assume((pub_r001217_14_1 >= (-100)) && (pub_r001217_14_1 <= 100));
  __CPROVER_assume((pub_r001217_14_2 >= (-100)) && (pub_r001217_14_2 <= 100));
  __CPROVER_assume((pub_r001217_15_1 >= (-100)) && (pub_r001217_15_1 <= 100));
  __CPROVER_assume((pub_r001217_15_2 >= (-100)) && (pub_r001217_15_2 <= 100));
  __CPROVER_assume((pub_r001217_16_1 >= (-100)) && (pub_r001217_16_1 <= 100));
  __CPROVER_assume((pub_r001217_16_2 >= (-100)) && (pub_r001217_16_2 <= 100));
  __CPROVER_assume((pub_r001217_17_1 >= (-100)) && (pub_r001217_17_1 <= 100));
  __CPROVER_assume((pub_r001217_17_2 >= (-100)) && (pub_r001217_17_2 <= 100));
  __CPROVER_assume((sec_r001217_0_1 >= 0) && (sec_r001217_0_1 <= 255));
  __CPROVER_assume((sec_r001217_0_2 >= 0) && (sec_r001217_0_2 <= 255));
  __CPROVER_assume((sec_r001217_1_1 >= 0) && (sec_r001217_1_1 <= 255));
  __CPROVER_assume((sec_r001217_1_2 >= 0) && (sec_r001217_1_2 <= 255));
  __CPROVER_assume((sec_r001217_2_1 >= 0) && (sec_r001217_2_1 <= 255));
  __CPROVER_assume((sec_r001217_2_2 >= 0) && (sec_r001217_2_2 <= 255));
  __CPROVER_assume((sec_r001217_3_1 >= 0) && (sec_r001217_3_1 <= 255));
  __CPROVER_assume((sec_r001217_3_2 >= 0) && (sec_r001217_3_2 <= 255));
  __CPROVER_assume((sec_r001217_4_1 >= 0) && (sec_r001217_4_1 <= 255));
  __CPROVER_assume((sec_r001217_4_2 >= 0) && (sec_r001217_4_2 <= 255));
  __CPROVER_assume((sec_r001217_5_1 >= 0) && (sec_r001217_5_1 <= 255));
  __CPROVER_assume((sec_r001217_5_2 >= 0) && (sec_r001217_5_2 <= 255));
  __CPROVER_assume((sec_r001217_6_1 >= 0) && (sec_r001217_6_1 <= 255));
  __CPROVER_assume((sec_r001217_6_2 >= 0) && (sec_r001217_6_2 <= 255));
  __CPROVER_assume((sec_r001217_7_1 >= 0) && (sec_r001217_7_1 <= 255));
  __CPROVER_assume((sec_r001217_7_2 >= 0) && (sec_r001217_7_2 <= 255));
  __CPROVER_assume((sec_r001217_8_1 >= 0) && (sec_r001217_8_1 <= 255));
  __CPROVER_assume((sec_r001217_8_2 >= 0) && (sec_r001217_8_2 <= 255));
  __CPROVER_assume((sec_r001217_9_1 >= 0) && (sec_r001217_9_1 <= 255));
  __CPROVER_assume((sec_r001217_9_2 >= 0) && (sec_r001217_9_2 <= 255));
  __CPROVER_assume((sec_r001217_10_1 >= 0) && (sec_r001217_10_1 <= 255));
  __CPROVER_assume((sec_r001217_10_2 >= 0) && (sec_r001217_10_2 <= 255));
  __CPROVER_assume((sec_r001217_11_1 >= 0) && (sec_r001217_11_1 <= 255));
  __CPROVER_assume((sec_r001217_11_2 >= 0) && (sec_r001217_11_2 <= 255));
  __CPROVER_assume((sec_r001217_12_1 >= 0) && (sec_r001217_12_1 <= 255));
  __CPROVER_assume((sec_r001217_12_2 >= 0) && (sec_r001217_12_2 <= 255));
  __CPROVER_assume((sec_r001217_13_1 >= 0) && (sec_r001217_13_1 <= 255));
  __CPROVER_assume((sec_r001217_13_2 >= 0) && (sec_r001217_13_2 <= 255));
  __CPROVER_assume((sec_r001217_14_1 >= 0) && (sec_r001217_14_1 <= 255));
  __CPROVER_assume((sec_r001217_14_2 >= 0) && (sec_r001217_14_2 <= 255));
  __CPROVER_assume((sec_r001217_15_1 >= 0) && (sec_r001217_15_1 <= 255));
  __CPROVER_assume((sec_r001217_15_2 >= 0) && (sec_r001217_15_2 <= 255));
  __CPROVER_assume((sec_r001217_16_1 >= 0) && (sec_r001217_16_1 <= 255));
  __CPROVER_assume((sec_r001217_16_2 >= 0) && (sec_r001217_16_2 <= 255));
  __CPROVER_assume((sec_r001217_17_1 >= 0) && (sec_r001217_17_1 <= 255));
  __CPROVER_assume((sec_r001217_17_2 >= 0) && (sec_r001217_17_2 <= 255));
  __CPROVER_assume((sec_r001217_18_1 >= 0) && (sec_r001217_18_1 <= 255));
  __CPROVER_assume((sec_r001217_18_2 >= 0) && (sec_r001217_18_2 <= 255));
  __CPROVER_assume((sec_r001217_19_1 >= 0) && (sec_r001217_19_1 <= 255));
  __CPROVER_assume((sec_r001217_19_2 >= 0) && (sec_r001217_19_2 <= 255));
  __CPROVER_assume((sec_r001217_20_1 >= 0) && (sec_r001217_20_1 <= 255));
  __CPROVER_assume((sec_r001217_20_2 >= 0) && (sec_r001217_20_2 <= 255));
  __CPROVER_assume((sec_r001217_21_1 >= 0) && (sec_r001217_21_1 <= 255));
  __CPROVER_assume((sec_r001217_21_2 >= 0) && (sec_r001217_21_2 <= 255));
  __CPROVER_assume((sec_r001217_22_1 >= 0) && (sec_r001217_22_1 <= 255));
  __CPROVER_assume((sec_r001217_22_2 >= 0) && (sec_r001217_22_2 <= 255));
  struct FilterState_R001217_1713_0 st_var_0_1 = {0};
  struct FilterState_R001217_1713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001217_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001217_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001217_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001217_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001217_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001217_0_2 + 7) & 15;
  struct Transaction_R001217_1713_1 st_var_1_1 = {0};
  struct Transaction_R001217_1713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001217_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001217_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001217_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001217_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001217_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001217_0_2 + 9) & 15;
  union RegisterBank_R001217_1713_0 u_var_1;
  union RegisterBank_R001217_1713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001217_1713_0(sec_r001217_0_1, pub_r001217_1_1);
  int helper_flow_0_2 = fn_R001217_1713_0(sec_r001217_0_2, pub_r001217_1_2);
  fn_R001217_1713_0_2(sec_r001217_0_1, pub_r001217_1_1, sec_r001217_0_2, pub_r001217_1_2);
  int helper_flow_1_1 = fn_R001217_1713_1(sec_r001217_1_1, pub_r001217_2_1, pub_r001217_3_1, pub_r001217_4_1, pub_r001217_5_1);
  int helper_flow_1_2 = fn_R001217_1713_1(sec_r001217_1_2, pub_r001217_2_2, pub_r001217_3_2, pub_r001217_4_2, pub_r001217_5_2);
  fn_R001217_1713_1_2(sec_r001217_1_1, pub_r001217_2_1, pub_r001217_3_1, pub_r001217_4_1, pub_r001217_5_1, sec_r001217_1_2, pub_r001217_2_2, pub_r001217_3_2, pub_r001217_4_2, pub_r001217_5_2);
  int helper_flow_2_1 = fn_R001217_1713_2(sec_r001217_2_1, pub_r001217_3_1, pub_r001217_4_1, pub_r001217_5_1, pub_r001217_6_1);
  int helper_flow_2_2 = fn_R001217_1713_2(sec_r001217_2_2, pub_r001217_3_2, pub_r001217_4_2, pub_r001217_5_2, pub_r001217_6_2);
  fn_R001217_1713_2_2(sec_r001217_2_1, pub_r001217_3_1, pub_r001217_4_1, pub_r001217_5_1, pub_r001217_6_1, sec_r001217_2_2, pub_r001217_3_2, pub_r001217_4_2, pub_r001217_5_2, pub_r001217_6_2);
  int helper_flow_3_1 = fn_R001217_1713_3(sec_r001217_3_1, pub_r001217_4_1, pub_r001217_5_1);
  int helper_flow_3_2 = fn_R001217_1713_3(sec_r001217_3_2, pub_r001217_4_2, pub_r001217_5_2);
  fn_R001217_1713_3_2(sec_r001217_3_1, pub_r001217_4_1, pub_r001217_5_1, sec_r001217_3_2, pub_r001217_4_2, pub_r001217_5_2);
  int helper_flow_4_1 = fn_R001217_1713_4(sec_r001217_4_1, sec_r001217_5_1, pub_r001217_6_1, pub_r001217_7_1);
  int helper_flow_4_2 = fn_R001217_1713_4(sec_r001217_4_2, sec_r001217_5_2, pub_r001217_6_2, pub_r001217_7_2);
  fn_R001217_1713_4_2(sec_r001217_4_1, sec_r001217_5_1, pub_r001217_6_1, pub_r001217_7_1, sec_r001217_4_2, sec_r001217_5_2, pub_r001217_6_2, pub_r001217_7_2);
  int helper_flow_5_1 = fn_R001217_1713_5(sec_r001217_5_1, sec_r001217_6_1, pub_r001217_7_1, pub_r001217_8_1, pub_r001217_9_1);
  int helper_flow_5_2 = fn_R001217_1713_5(sec_r001217_5_2, sec_r001217_6_2, pub_r001217_7_2, pub_r001217_8_2, pub_r001217_9_2);
  fn_R001217_1713_5_2(sec_r001217_5_1, sec_r001217_6_1, pub_r001217_7_1, pub_r001217_8_1, pub_r001217_9_1, sec_r001217_5_2, sec_r001217_6_2, pub_r001217_7_2, pub_r001217_8_2, pub_r001217_9_2);
  int helper_flow_6_1 = fn_R001217_1713_6(sec_r001217_6_1, pub_r001217_7_1, pub_r001217_8_1, pub_r001217_9_1, pub_r001217_10_1);
  int helper_flow_6_2 = fn_R001217_1713_6(sec_r001217_6_2, pub_r001217_7_2, pub_r001217_8_2, pub_r001217_9_2, pub_r001217_10_2);
  fn_R001217_1713_6_2(sec_r001217_6_1, pub_r001217_7_1, pub_r001217_8_1, pub_r001217_9_1, pub_r001217_10_1, sec_r001217_6_2, pub_r001217_7_2, pub_r001217_8_2, pub_r001217_9_2, pub_r001217_10_2);
  int helper_flow_7_1 = fn_R001217_1713_7(sec_r001217_7_1, pub_r001217_8_1, pub_r001217_9_1);
  int helper_flow_7_2 = fn_R001217_1713_7(sec_r001217_7_2, pub_r001217_8_2, pub_r001217_9_2);
  fn_R001217_1713_7_2(sec_r001217_7_1, pub_r001217_8_1, pub_r001217_9_1, sec_r001217_7_2, pub_r001217_8_2, pub_r001217_9_2);
  int helper_flow_8_1 = fn_R001217_1713_8(sec_r001217_8_1, pub_r001217_9_1, pub_r001217_10_1, pub_r001217_11_1);
  int helper_flow_8_2 = fn_R001217_1713_8(sec_r001217_8_2, pub_r001217_9_2, pub_r001217_10_2, pub_r001217_11_2);
  fn_R001217_1713_8_2(sec_r001217_8_1, pub_r001217_9_1, pub_r001217_10_1, pub_r001217_11_1, sec_r001217_8_2, pub_r001217_9_2, pub_r001217_10_2, pub_r001217_11_2);
  int helper_flow_9_1 = fn_R001217_1713_9(sec_r001217_9_1, sec_r001217_10_1);
  int helper_flow_9_2 = fn_R001217_1713_9(sec_r001217_9_2, sec_r001217_10_2);
  fn_R001217_1713_9_2(sec_r001217_9_1, sec_r001217_10_1, sec_r001217_9_2, sec_r001217_10_2);
  int helper_flow_10_1 = fn_R001217_1713_10(sec_r001217_10_1, pub_r001217_11_1);
  int helper_flow_10_2 = fn_R001217_1713_10(sec_r001217_10_2, pub_r001217_11_2);
  fn_R001217_1713_10_2(sec_r001217_10_1, pub_r001217_11_1, sec_r001217_10_2, pub_r001217_11_2);
  int stage_v_0_1 = ((pub_r001217_15_1 * 2) + 32) & 63;
  int stage_v_0_2 = ((pub_r001217_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001217_5_1 * 2) + 31) & 63;
  int stage_v_1_2 = ((pub_r001217_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (sec_r001217_18_1 ^ pub_r001217_13_1) & 63;
  int stage_v_2_2 = (sec_r001217_18_2 ^ pub_r001217_13_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((sec_r001217_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_2_1 * 2)) & 255;
  }
  if ((stage_v_2_2 & 1) != 0)
  {
    if ((sec_r001217_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_2_2 * 2)) & 255;
  }
  int stage_v_3_1 = (sec_r001217_1_1 ^ pub_r001217_1_1) & 63;
  int stage_v_3_2 = (sec_r001217_1_2 ^ pub_r001217_1_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_3_1 * 2)) & 255;
  }
  if ((stage_v_3_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_3_2 * 2)) & 255;
  }
  int stage_v_4_1 = ((pub_r001217_0_1 * 2) + 19) & 63;
  int stage_v_4_2 = ((pub_r001217_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (sec_r001217_10_1 ^ pub_r001217_13_1) & 63;
  int stage_v_5_2 = (sec_r001217_10_2 ^ pub_r001217_13_2) & 63;
  if ((stage_v_5_1 & 1) != 0)
  {
    if ((sec_r001217_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_5_1 * 2)) & 255;
  }
  if ((stage_v_5_2 & 1) != 0)
  {
    if ((sec_r001217_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_5_2 * 2)) & 255;
  }
  int stage_v_6_1 = (sec_r001217_20_1 ^ pub_r001217_1_1) & 63;
  int stage_v_6_2 = (sec_r001217_20_2 ^ pub_r001217_1_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((sec_r001217_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_6_1 * 2)) & 255;
  }
  if ((stage_v_6_2 & 1) != 0)
  {
    if ((sec_r001217_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_6_2 * 2)) & 255;
  }
  int stage_v_7_1 = ((pub_r001217_8_1 * 2) + 36) & 63;
  int stage_v_7_2 = ((pub_r001217_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (sec_r001217_8_1 ^ pub_r001217_2_1) & 63;
  int stage_v_8_2 = (sec_r001217_8_2 ^ pub_r001217_2_2) & 63;
  if ((stage_v_8_1 & 1) != 0)
  {
    if ((sec_r001217_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_8_1 * 2)) & 255;
  }
  if ((stage_v_8_2 & 1) != 0)
  {
    if ((sec_r001217_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_8_2 * 2)) & 255;
  }
  int stage_v_9_1 = ((pub_r001217_6_1 * 2) + 16) & 63;
  int stage_v_9_2 = ((pub_r001217_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001217_0_1 * 2) + 36) & 63;
  int stage_v_10_2 = ((pub_r001217_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001217_2_1 * 2) + 33) & 63;
  int stage_v_11_2 = ((pub_r001217_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (sec_r001217_6_1 ^ pub_r001217_9_1) & 63;
  int stage_v_12_2 = (sec_r001217_6_2 ^ pub_r001217_9_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_12_1 * 2)) & 255;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((stage_v_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_12_2 * 2)) & 255;
  }
  int stage_v_13_1 = (sec_r001217_18_1 ^ pub_r001217_0_1) & 63;
  int stage_v_13_2 = (sec_r001217_18_2 ^ pub_r001217_0_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_13_1 * 2)) & 255;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_13_2 * 2)) & 255;
  }
  int stage_v_14_1 = (sec_r001217_1_1 ^ pub_r001217_10_1) & 63;
  int stage_v_14_2 = (sec_r001217_1_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r001217_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_14_1 * 2)) & 255;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r001217_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_14_2 * 2)) & 255;
  }
  int stage_v_15_1 = ((pub_r001217_2_1 * 2) + 9) & 63;
  int stage_v_15_2 = ((pub_r001217_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001217_15_1 * 2) + 16) & 63;
  int stage_v_16_2 = ((pub_r001217_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001217_14_1 * 2) + 24) & 63;
  int stage_v_17_2 = ((pub_r001217_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (stage_v_3_1 ^ pub_r001217_11_1) & 63;
  int stage_v_18_2 = (stage_v_3_2 ^ pub_r001217_11_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_18_1 * 2)) & 255;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_18_2 * 2)) & 255;
  }
  int stage_v_19_1 = (helper_flow_6_1 ^ pub_r001217_14_1) & 63;
  int stage_v_19_2 = (helper_flow_6_2 ^ pub_r001217_14_2) & 63;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r001217_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_19_1 * 2)) & 255;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r001217_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_19_2 * 2)) & 255;
  }
  int stage_v_20_1 = (helper_flow_0_1 ^ pub_r001217_6_1) & 63;
  int stage_v_20_2 = (helper_flow_0_2 ^ pub_r001217_6_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r001217_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_20_1 * 2)) & 255;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r001217_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_20_2 * 2)) & 255;
  }
  int stage_v_21_1 = (sec_r001217_19_1 ^ pub_r001217_8_1) & 63;
  int stage_v_21_2 = (sec_r001217_19_2 ^ pub_r001217_8_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_21_1 * 2)) & 255;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((helper_flow_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_21_2 * 2)) & 255;
  }
  int stage_v_22_1 = (stage_v_2_1 ^ pub_r001217_12_1) & 63;
  int stage_v_22_2 = (stage_v_2_2 ^ pub_r001217_12_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r001217_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_22_1 * 2)) & 255;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r001217_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_22_2 * 2)) & 255;
  }
  int stage_v_23_1 = (stage_v_13_1 ^ pub_r001217_16_1) & 63;
  int stage_v_23_2 = (stage_v_13_2 ^ pub_r001217_16_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r001217_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_23_1 * 2)) & 255;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r001217_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_23_2 * 2)) & 255;
  }
  int stage_v_24_1 = (helper_flow_3_1 ^ pub_r001217_3_1) & 63;
  int stage_v_24_2 = (helper_flow_3_2 ^ pub_r001217_3_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((stage_v_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_24_1 * 2)) & 255;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((stage_v_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_24_2 * 2)) & 255;
  }
  int stage_v_25_1 = (sec_r001217_3_1 ^ pub_r001217_10_1) & 63;
  int stage_v_25_2 = (sec_r001217_3_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r001217_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_25_1 * 2)) & 255;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r001217_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_25_2 * 2)) & 255;
  }
  int stage_v_26_1 = (stage_v_25_1 ^ pub_r001217_4_1) & 63;
  int stage_v_26_2 = (stage_v_25_2 ^ pub_r001217_4_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r001217_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_26_1 * 2)) & 255;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r001217_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_26_2 * 2)) & 255;
  }
  int stage_v_27_1 = (sec_r001217_17_1 ^ pub_r001217_10_1) & 63;
  int stage_v_27_2 = (sec_r001217_17_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_27_1 * 2)) & 255;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_27_2 * 2)) & 255;
  }
  int stage_v_28_1 = (sec_r001217_9_1 ^ pub_r001217_17_1) & 63;
  int stage_v_28_2 = (sec_r001217_9_2 ^ pub_r001217_17_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r001217_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_28_1 * 2)) & 255;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r001217_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_28_2 * 2)) & 255;
  }
  int stage_v_29_1 = ((pub_r001217_15_1 * 2) + 21) & 63;
  int stage_v_29_2 = ((pub_r001217_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (helper_flow_5_1 ^ pub_r001217_8_1) & 63;
  int stage_v_30_2 = (helper_flow_5_2 ^ pub_r001217_8_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_30_1 * 2)) & 255;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((stage_v_26_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_30_2 * 2)) & 255;
  }
  int stage_v_31_1 = (sec_r001217_19_1 ^ pub_r001217_10_1) & 63;
  int stage_v_31_2 = (sec_r001217_19_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r001217_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_31_1 * 2)) & 255;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r001217_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_31_2 * 2)) & 255;
  }
  int stage_v_32_1 = (sec_r001217_2_1 ^ pub_r001217_10_1) & 63;
  int stage_v_32_2 = (sec_r001217_2_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r001217_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_32_1 * 2)) & 255;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r001217_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_32_2 * 2)) & 255;
  }
  int stage_v_33_1 = ((pub_r001217_6_1 * 2) + 34) & 63;
  int stage_v_33_2 = ((pub_r001217_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (stage_v_25_1 ^ pub_r001217_2_1) & 63;
  int stage_v_34_2 = (stage_v_25_2 ^ pub_r001217_2_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r001217_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_34_1 * 2)) & 255;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r001217_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_34_2 * 2)) & 255;
  }
  int stage_v_35_1 = ((pub_r001217_3_1 * 2) + 28) & 63;
  int stage_v_35_2 = ((pub_r001217_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (stage_v_2_1 ^ pub_r001217_7_1) & 63;
  int stage_v_36_2 = (stage_v_2_2 ^ pub_r001217_7_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r001217_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_36_1 * 2)) & 255;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r001217_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_36_2 * 2)) & 255;
  }
  int stage_v_37_1 = ((pub_r001217_14_1 * 2) + 37) & 63;
  int stage_v_37_2 = ((pub_r001217_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001217_11_1 * 2) + 37) & 63;
  int stage_v_38_2 = ((pub_r001217_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (stage_v_30_1 ^ pub_r001217_12_1) & 63;
  int stage_v_39_2 = (stage_v_30_2 ^ pub_r001217_12_2) & 63;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_39_1 * 2)) & 255;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((stage_v_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_39_2 * 2)) & 255;
  }
  int stage_v_40_1 = (stage_v_14_1 ^ pub_r001217_2_1) & 63;
  int stage_v_40_2 = (stage_v_14_2 ^ pub_r001217_2_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_40_1 * 2)) & 255;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_40_2 * 2)) & 255;
  }
  int stage_v_41_1 = ((pub_r001217_14_1 * 2) + 37) & 63;
  int stage_v_41_2 = ((pub_r001217_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (sec_r001217_10_1 ^ pub_r001217_10_1) & 63;
  int stage_v_42_2 = (sec_r001217_10_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_42_1 * 2)) & 255;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((helper_flow_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_42_2 * 2)) & 255;
  }
  int stage_v_43_1 = (stage_v_8_1 ^ pub_r001217_11_1) & 63;
  int stage_v_43_2 = (stage_v_8_2 ^ pub_r001217_11_2) & 63;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((stage_v_22_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_43_1 * 2)) & 255;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((stage_v_22_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_43_2 * 2)) & 255;
  }
  int stage_v_44_1 = (helper_flow_9_1 ^ pub_r001217_8_1) & 63;
  int stage_v_44_2 = (helper_flow_9_2 ^ pub_r001217_8_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((stage_v_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  }
  int stage_v_45_1 = (helper_flow_7_1 ^ pub_r001217_15_1) & 63;
  int stage_v_45_2 = (helper_flow_7_2 ^ pub_r001217_15_2) & 63;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r001217_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_45_1 * 2)) & 255;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r001217_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_45_2 * 2)) & 255;
  }
  int stage_v_46_1 = ((pub_r001217_5_1 * 2) + 26) & 63;
  int stage_v_46_2 = ((pub_r001217_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001217_6_1 * 2) + 19) & 63;
  int stage_v_47_2 = ((pub_r001217_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (stage_v_2_1 ^ pub_r001217_0_1) & 63;
  int stage_v_48_2 = (stage_v_2_2 ^ pub_r001217_0_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r001217_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r001217_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  }
  int stage_v_49_1 = (stage_v_13_1 ^ pub_r001217_11_1) & 63;
  int stage_v_49_2 = (stage_v_13_2 ^ pub_r001217_11_2) & 63;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_49_1 * 2)) & 255;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_49_2 * 2)) & 255;
  }
  int stage_v_50_1 = (stage_v_14_1 ^ pub_r001217_11_1) & 63;
  int stage_v_50_2 = (stage_v_14_2 ^ pub_r001217_11_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r001217_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r001217_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  }
  int stage_v_51_1 = (helper_flow_1_1 ^ pub_r001217_10_1) & 63;
  int stage_v_51_2 = (helper_flow_1_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  }
  int stage_v_52_1 = (sec_r001217_10_1 ^ pub_r001217_9_1) & 63;
  int stage_v_52_2 = (sec_r001217_10_2 ^ pub_r001217_9_2) & 63;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r001217_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r001217_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  }
  int stage_v_53_1 = (stage_v_21_1 ^ pub_r001217_0_1) & 63;
  int stage_v_53_2 = (stage_v_21_2 ^ pub_r001217_0_2) & 63;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_53_1 * 2)) & 255;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((stage_v_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_53_2 * 2)) & 255;
  }
  int stage_v_54_1 = ((pub_r001217_8_1 * 2) + 8) & 63;
  int stage_v_54_2 = ((pub_r001217_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001217_17_1 * 2) + 21) & 63;
  int stage_v_55_2 = ((pub_r001217_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001217_0_1 * 2) + 28) & 63;
  int stage_v_56_2 = ((pub_r001217_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001217_14_1 * 2) + 8) & 63;
  int stage_v_57_2 = ((pub_r001217_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001217_4_1 * 2) + 14) & 63;
  int stage_v_58_2 = ((pub_r001217_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (stage_v_20_1 ^ pub_r001217_6_1) & 63;
  int stage_v_59_2 = (stage_v_20_2 ^ pub_r001217_6_2) & 63;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_59_1 * 2)) & 255;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((stage_v_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_59_2 * 2)) & 255;
  }
  int stage_v_60_1 = ((pub_r001217_12_1 * 2) + 49) & 63;
  int stage_v_60_2 = ((pub_r001217_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001217_14_1 * 2) + 13) & 63;
  int stage_v_61_2 = ((pub_r001217_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (stage_v_59_1 ^ pub_r001217_11_1) & 63;
  int stage_v_62_2 = (stage_v_59_2 ^ pub_r001217_11_2) & 63;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r001217_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r001217_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  }
  int stage_v_63_1 = (helper_flow_2_1 ^ pub_r001217_14_1) & 63;
  int stage_v_63_2 = (helper_flow_2_2 ^ pub_r001217_14_2) & 63;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((stage_v_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  }
  int stage_v_64_1 = (stage_v_48_1 ^ pub_r001217_13_1) & 63;
  int stage_v_64_2 = (stage_v_48_2 ^ pub_r001217_13_2) & 63;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((stage_v_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((stage_v_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  }
  int stage_v_65_1 = ((pub_r001217_11_1 * 2) + 20) & 63;
  int stage_v_65_2 = ((pub_r001217_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001217_15_1 * 2) + 43) & 63;
  int stage_v_66_2 = ((pub_r001217_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001217_8_1 * 2) + 29) & 63;
  int stage_v_67_2 = ((pub_r001217_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001217_5_1 * 2) + 14) & 63;
  int stage_v_68_2 = ((pub_r001217_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001217_8_1 * 2) + 22) & 63;
  int stage_v_69_2 = ((pub_r001217_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (stage_v_52_1 ^ pub_r001217_13_1) & 63;
  int stage_v_70_2 = (stage_v_52_2 ^ pub_r001217_13_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r001217_22_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r001217_22_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  }
  int stage_v_71_1 = (stage_v_63_1 ^ pub_r001217_2_1) & 63;
  int stage_v_71_2 = (stage_v_63_2 ^ pub_r001217_2_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r001217_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r001217_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  }
  int stage_v_72_1 = (helper_flow_7_1 ^ pub_r001217_10_1) & 63;
  int stage_v_72_2 = (helper_flow_7_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((stage_v_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  }
  int stage_v_73_1 = ((pub_r001217_4_1 * 2) + 8) & 63;
  int stage_v_73_2 = ((pub_r001217_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (sec_r001217_18_1 ^ pub_r001217_10_1) & 63;
  int stage_v_74_2 = (sec_r001217_18_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((stage_v_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  }
  int stage_v_75_1 = ((pub_r001217_10_1 * 2) + 33) & 63;
  int stage_v_75_2 = ((pub_r001217_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (sec_r001217_5_1 ^ pub_r001217_12_1) & 63;
  int stage_v_76_2 = (sec_r001217_5_2 ^ pub_r001217_12_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((stage_v_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  }
  int stage_v_77_1 = (stage_v_51_1 ^ pub_r001217_10_1) & 63;
  int stage_v_77_2 = (stage_v_51_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  }
  int stage_v_78_1 = ((pub_r001217_7_1 * 2) + 34) & 63;
  int stage_v_78_2 = ((pub_r001217_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (stage_v_72_1 ^ pub_r001217_7_1) & 63;
  int stage_v_79_2 = (stage_v_72_2 ^ pub_r001217_7_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  }
  int stage_v_80_1 = (sec_r001217_18_1 ^ pub_r001217_16_1) & 63;
  int stage_v_80_2 = (sec_r001217_18_2 ^ pub_r001217_16_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((stage_v_44_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  }
  int stage_v_81_1 = (helper_flow_1_1 ^ pub_r001217_1_1) & 63;
  int stage_v_81_2 = (helper_flow_1_2 ^ pub_r001217_1_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r001217_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r001217_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  }
  int stage_v_82_1 = (sec_r001217_21_1 ^ pub_r001217_13_1) & 63;
  int stage_v_82_2 = (sec_r001217_21_2 ^ pub_r001217_13_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  }
  int stage_v_83_1 = (sec_r001217_14_1 ^ pub_r001217_3_1) & 63;
  int stage_v_83_2 = (sec_r001217_14_2 ^ pub_r001217_3_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r001217_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r001217_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  }
  int stage_v_84_1 = (stage_v_12_1 ^ pub_r001217_4_1) & 63;
  int stage_v_84_2 = (stage_v_12_2 ^ pub_r001217_4_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((stage_v_53_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((stage_v_53_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  }
  int stage_v_85_1 = ((pub_r001217_9_1 * 2) + 37) & 63;
  int stage_v_85_2 = ((pub_r001217_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001217_5_1 * 2) + 21) & 63;
  int stage_v_86_2 = ((pub_r001217_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (sec_r001217_19_1 ^ pub_r001217_16_1) & 63;
  int stage_v_87_2 = (sec_r001217_19_2 ^ pub_r001217_16_2) & 63;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((stage_v_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  }
  int stage_v_88_1 = ((pub_r001217_6_1 * 2) + 15) & 63;
  int stage_v_88_2 = ((pub_r001217_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (stage_v_22_1 ^ pub_r001217_5_1) & 63;
  int stage_v_89_2 = (stage_v_22_2 ^ pub_r001217_5_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r001217_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r001217_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  }
  int stage_v_90_1 = (stage_v_83_1 ^ pub_r001217_10_1) & 63;
  int stage_v_90_2 = (stage_v_83_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((stage_v_32_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  }
  int stage_v_91_1 = (stage_v_6_1 ^ pub_r001217_10_1) & 63;
  int stage_v_91_2 = (stage_v_6_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r001217_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r001217_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  }
  int stage_v_92_1 = (sec_r001217_11_1 ^ pub_r001217_0_1) & 63;
  int stage_v_92_2 = (sec_r001217_11_2 ^ pub_r001217_0_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_74_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((stage_v_74_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  }
  int stage_v_93_1 = (stage_v_71_1 ^ pub_r001217_9_1) & 63;
  int stage_v_93_2 = (stage_v_71_2 ^ pub_r001217_9_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((stage_v_92_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((stage_v_92_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  }
  int stage_v_94_1 = (sec_r001217_18_1 ^ pub_r001217_16_1) & 63;
  int stage_v_94_2 = (sec_r001217_18_2 ^ pub_r001217_16_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((stage_v_62_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  }
  int stage_v_95_1 = (stage_v_21_1 ^ pub_r001217_15_1) & 63;
  int stage_v_95_2 = (stage_v_21_2 ^ pub_r001217_15_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((stage_v_94_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((stage_v_94_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  }
  int stage_v_96_1 = (stage_v_70_1 ^ pub_r001217_7_1) & 63;
  int stage_v_96_2 = (stage_v_70_2 ^ pub_r001217_7_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r001217_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r001217_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  }
  int stage_v_97_1 = (sec_r001217_14_1 ^ pub_r001217_3_1) & 63;
  int stage_v_97_2 = (sec_r001217_14_2 ^ pub_r001217_3_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((helper_flow_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  }
  int stage_v_98_1 = ((pub_r001217_0_1 * 2) + 39) & 63;
  int stage_v_98_2 = ((pub_r001217_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (helper_flow_1_1 ^ pub_r001217_7_1) & 63;
  int stage_v_99_2 = (helper_flow_1_2 ^ pub_r001217_7_2) & 63;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  }
  int stage_v_100_1 = (stage_v_8_1 ^ pub_r001217_17_1) & 63;
  int stage_v_100_2 = (stage_v_8_2 ^ pub_r001217_17_2) & 63;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  }
  int stage_v_101_1 = (sec_r001217_16_1 ^ pub_r001217_6_1) & 63;
  int stage_v_101_2 = (sec_r001217_16_2 ^ pub_r001217_6_2) & 63;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((stage_v_39_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((stage_v_39_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  }
  int stage_v_102_1 = (stage_v_49_1 ^ pub_r001217_10_1) & 63;
  int stage_v_102_2 = (stage_v_49_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r001217_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r001217_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  }
  int stage_v_103_1 = (helper_flow_1_1 ^ pub_r001217_6_1) & 63;
  int stage_v_103_2 = (helper_flow_1_2 ^ pub_r001217_6_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((stage_v_91_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((stage_v_91_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  }
  int stage_v_104_1 = (sec_r001217_3_1 ^ pub_r001217_13_1) & 63;
  int stage_v_104_2 = (sec_r001217_3_2 ^ pub_r001217_13_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r001217_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r001217_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  }
  int stage_v_105_1 = ((pub_r001217_5_1 * 2) + 6) & 63;
  int stage_v_105_2 = ((pub_r001217_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (sec_r001217_2_1 ^ pub_r001217_6_1) & 63;
  int stage_v_106_2 = (sec_r001217_2_2 ^ pub_r001217_6_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((stage_v_71_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((stage_v_71_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  }
  int stage_v_107_1 = ((pub_r001217_4_1 * 2) + 8) & 63;
  int stage_v_107_2 = ((pub_r001217_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (stage_v_74_1 ^ pub_r001217_11_1) & 63;
  int stage_v_108_2 = (stage_v_74_2 ^ pub_r001217_11_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((stage_v_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  }
  int stage_v_109_1 = (sec_r001217_16_1 ^ pub_r001217_0_1) & 63;
  int stage_v_109_2 = (sec_r001217_16_2 ^ pub_r001217_0_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((stage_v_39_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((stage_v_39_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  }
  int stage_v_110_1 = (stage_v_53_1 ^ pub_r001217_4_1) & 63;
  int stage_v_110_2 = (stage_v_53_2 ^ pub_r001217_4_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((stage_v_104_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((stage_v_104_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  }
  int stage_v_111_1 = (sec_r001217_5_1 ^ pub_r001217_11_1) & 63;
  int stage_v_111_2 = (sec_r001217_5_2 ^ pub_r001217_11_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((stage_v_52_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  }
  int stage_v_112_1 = ((pub_r001217_0_1 * 2) + 19) & 63;
  int stage_v_112_2 = ((pub_r001217_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (stage_v_70_1 ^ pub_r001217_14_1) & 63;
  int stage_v_113_2 = (stage_v_70_2 ^ pub_r001217_14_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((stage_v_80_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  }
  int stage_v_114_1 = (stage_v_84_1 ^ pub_r001217_10_1) & 63;
  int stage_v_114_2 = (stage_v_84_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r001217_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r001217_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  }
  int stage_v_115_1 = (stage_v_90_1 ^ pub_r001217_11_1) & 63;
  int stage_v_115_2 = (stage_v_90_2 ^ pub_r001217_11_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((stage_v_71_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((stage_v_71_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  }
  int stage_v_116_1 = (stage_v_89_1 ^ pub_r001217_0_1) & 63;
  int stage_v_116_2 = (stage_v_89_2 ^ pub_r001217_0_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r001217_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r001217_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  }
  int stage_v_117_1 = (stage_v_49_1 ^ pub_r001217_9_1) & 63;
  int stage_v_117_2 = (stage_v_49_2 ^ pub_r001217_9_2) & 63;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((stage_v_83_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((stage_v_83_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  }
  int stage_v_118_1 = (stage_v_27_1 ^ pub_r001217_4_1) & 63;
  int stage_v_118_2 = (stage_v_27_2 ^ pub_r001217_4_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_84_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((stage_v_84_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  }
  int stage_v_119_1 = (stage_v_31_1 ^ pub_r001217_15_1) & 63;
  int stage_v_119_2 = (stage_v_31_2 ^ pub_r001217_15_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((stage_v_104_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((stage_v_104_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  }
  int stage_v_120_1 = ((pub_r001217_6_1 * 2) + 42) & 63;
  int stage_v_120_2 = ((pub_r001217_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (stage_v_70_1 ^ pub_r001217_4_1) & 63;
  int stage_v_121_2 = (stage_v_70_2 ^ pub_r001217_4_2) & 63;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((stage_v_119_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((stage_v_119_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  }
  int stage_v_122_1 = (stage_v_26_1 ^ pub_r001217_14_1) & 63;
  int stage_v_122_2 = (stage_v_26_2 ^ pub_r001217_14_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((stage_v_79_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((stage_v_79_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  }
  int stage_v_123_1 = ((pub_r001217_4_1 * 2) + 24) & 63;
  int stage_v_123_2 = ((pub_r001217_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001217_10_1 * 2) + 39) & 63;
  int stage_v_124_2 = ((pub_r001217_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001217_3_1 * 2) + 48) & 63;
  int stage_v_125_2 = ((pub_r001217_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001217_10_1 * 2) + 12) & 63;
  int stage_v_126_2 = ((pub_r001217_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001217_9_1 * 2) + 25) & 63;
  int stage_v_127_2 = ((pub_r001217_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001217_5_1 * 2) + 43) & 63;
  int stage_v_128_2 = ((pub_r001217_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (helper_flow_1_1 ^ pub_r001217_14_1) & 63;
  int stage_v_129_2 = (helper_flow_1_2 ^ pub_r001217_14_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((stage_v_30_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  }
  int stage_v_130_1 = ((pub_r001217_6_1 * 2) + 50) & 63;
  int stage_v_130_2 = ((pub_r001217_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (stage_v_42_1 ^ pub_r001217_1_1) & 63;
  int stage_v_131_2 = (stage_v_42_2 ^ pub_r001217_1_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r001217_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((sec_r001217_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  }
  int stage_v_132_1 = (sec_r001217_8_1 ^ pub_r001217_3_1) & 63;
  int stage_v_132_2 = (sec_r001217_8_2 ^ pub_r001217_3_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  }
  int stage_v_133_1 = ((pub_r001217_12_1 * 2) + 11) & 63;
  int stage_v_133_2 = ((pub_r001217_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (stage_v_48_1 ^ pub_r001217_13_1) & 63;
  int stage_v_134_2 = (stage_v_48_2 ^ pub_r001217_13_2) & 63;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  }
  int stage_v_135_1 = ((pub_r001217_13_1 * 2) + 11) & 63;
  int stage_v_135_2 = ((pub_r001217_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001217_9_1 * 2) + 24) & 63;
  int stage_v_136_2 = ((pub_r001217_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (sec_r001217_7_1 ^ pub_r001217_10_1) & 63;
  int stage_v_137_2 = (sec_r001217_7_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((stage_v_100_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((stage_v_100_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  }
  int stage_v_138_1 = (stage_v_118_1 ^ pub_r001217_14_1) & 63;
  int stage_v_138_2 = (stage_v_118_2 ^ pub_r001217_14_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((stage_v_70_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((stage_v_70_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  }
  int stage_v_139_1 = (sec_r001217_21_1 ^ pub_r001217_3_1) & 63;
  int stage_v_139_2 = (sec_r001217_21_2 ^ pub_r001217_3_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((stage_v_71_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((stage_v_71_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  }
  int stage_v_140_1 = (helper_flow_1_1 ^ pub_r001217_4_1) & 63;
  int stage_v_140_2 = (helper_flow_1_2 ^ pub_r001217_4_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((stage_v_59_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((stage_v_59_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  }
  int stage_v_141_1 = ((pub_r001217_1_1 * 2) + 10) & 63;
  int stage_v_141_2 = ((pub_r001217_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (stage_v_94_1 ^ pub_r001217_13_1) & 63;
  int stage_v_142_2 = (stage_v_94_2 ^ pub_r001217_13_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((sec_r001217_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((sec_r001217_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  }
  int stage_v_143_1 = (stage_v_80_1 ^ pub_r001217_10_1) & 63;
  int stage_v_143_2 = (stage_v_80_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  }
  if ((stage_v_143_2 & 1) != 0)
  {
    if ((stage_v_62_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  }
  int stage_v_144_1 = (sec_r001217_8_1 ^ pub_r001217_1_1) & 63;
  int stage_v_144_2 = (sec_r001217_8_2 ^ pub_r001217_1_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((stage_v_118_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((stage_v_118_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  }
  int stage_v_145_1 = (stage_v_109_1 ^ pub_r001217_11_1) & 63;
  int stage_v_145_2 = (stage_v_109_2 ^ pub_r001217_11_2) & 63;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((sec_r001217_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((sec_r001217_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  }
  int stage_v_146_1 = (sec_r001217_3_1 ^ pub_r001217_8_1) & 63;
  int stage_v_146_2 = (sec_r001217_3_2 ^ pub_r001217_8_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((stage_v_92_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((stage_v_92_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  }
  int stage_v_147_1 = ((pub_r001217_17_1 * 2) + 21) & 63;
  int stage_v_147_2 = ((pub_r001217_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (stage_v_92_1 ^ pub_r001217_7_1) & 63;
  int stage_v_148_2 = (stage_v_92_2 ^ pub_r001217_7_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_113_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  }
  if ((stage_v_148_2 & 1) != 0)
  {
    if ((stage_v_113_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  }
  int stage_v_149_1 = ((pub_r001217_2_1 * 2) + 11) & 63;
  int stage_v_149_2 = ((pub_r001217_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (stage_v_19_1 ^ pub_r001217_5_1) & 63;
  int stage_v_150_2 = (stage_v_19_2 ^ pub_r001217_5_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((stage_v_93_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((stage_v_93_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  }
  int stage_v_151_1 = (sec_r001217_1_1 ^ pub_r001217_7_1) & 63;
  int stage_v_151_2 = (sec_r001217_1_2 ^ pub_r001217_7_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((stage_v_96_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  }
  if ((stage_v_151_2 & 1) != 0)
  {
    if ((stage_v_96_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  }
  int stage_v_152_1 = (stage_v_143_1 ^ pub_r001217_2_1) & 63;
  int stage_v_152_2 = (stage_v_143_2 ^ pub_r001217_2_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((stage_v_106_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  }
  if ((stage_v_152_2 & 1) != 0)
  {
    if ((stage_v_106_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  }
  int stage_v_153_1 = ((pub_r001217_6_1 * 2) + 18) & 63;
  int stage_v_153_2 = ((pub_r001217_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (helper_flow_1_1 ^ pub_r001217_7_1) & 63;
  int stage_v_154_2 = (helper_flow_1_2 ^ pub_r001217_7_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((sec_r001217_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  }
  if ((stage_v_154_2 & 1) != 0)
  {
    if ((sec_r001217_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  }
  int stage_v_155_1 = ((pub_r001217_17_1 * 2) + 46) & 63;
  int stage_v_155_2 = ((pub_r001217_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (stage_v_26_1 ^ pub_r001217_7_1) & 63;
  int stage_v_156_2 = (stage_v_26_2 ^ pub_r001217_7_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_87_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  }
  if ((stage_v_156_2 & 1) != 0)
  {
    if ((stage_v_87_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  }
  int stage_v_157_1 = ((pub_r001217_15_1 * 2) + 25) & 63;
  int stage_v_157_2 = ((pub_r001217_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001217_16_1 * 2) + 19) & 63;
  int stage_v_158_2 = ((pub_r001217_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001217_15_1 * 2) + 14) & 63;
  int stage_v_159_2 = ((pub_r001217_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001217_0_1 * 2) + 15) & 63;
  int stage_v_160_2 = ((pub_r001217_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (stage_v_100_1 ^ pub_r001217_8_1) & 63;
  int stage_v_161_2 = (stage_v_100_2 ^ pub_r001217_8_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  }
  if ((stage_v_161_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  }
  int stage_v_162_1 = ((pub_r001217_4_1 * 2) + 25) & 63;
  int stage_v_162_2 = ((pub_r001217_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (stage_v_138_1 ^ pub_r001217_1_1) & 63;
  int stage_v_163_2 = (stage_v_138_2 ^ pub_r001217_1_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_82_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  }
  if ((stage_v_163_2 & 1) != 0)
  {
    if ((stage_v_82_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  }
  int stage_v_164_1 = ((pub_r001217_6_1 * 2) + 11) & 63;
  int stage_v_164_2 = ((pub_r001217_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (stage_v_59_1 ^ pub_r001217_7_1) & 63;
  int stage_v_165_2 = (stage_v_59_2 ^ pub_r001217_7_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_101_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  }
  if ((stage_v_165_2 & 1) != 0)
  {
    if ((stage_v_101_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  }
  int stage_v_166_1 = (stage_v_96_1 ^ pub_r001217_10_1) & 63;
  int stage_v_166_2 = (stage_v_96_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((stage_v_111_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  }
  if ((stage_v_166_2 & 1) != 0)
  {
    if ((stage_v_111_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  }
  int stage_v_167_1 = (stage_v_144_1 ^ pub_r001217_6_1) & 63;
  int stage_v_167_2 = (stage_v_144_2 ^ pub_r001217_6_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((stage_v_117_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  }
  if ((stage_v_167_2 & 1) != 0)
  {
    if ((stage_v_117_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  }
  int stage_v_168_1 = ((pub_r001217_4_1 * 2) + 18) & 63;
  int stage_v_168_2 = ((pub_r001217_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001217_1_1 * 2) + 47) & 63;
  int stage_v_169_2 = ((pub_r001217_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001217_15_1 * 2) + 21) & 63;
  int stage_v_170_2 = ((pub_r001217_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001217_2_1 * 2) + 26) & 63;
  int stage_v_171_2 = ((pub_r001217_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001217_16_1 * 2) + 41) & 63;
  int stage_v_172_2 = ((pub_r001217_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (stage_v_110_1 ^ pub_r001217_17_1) & 63;
  int stage_v_173_2 = (stage_v_110_2 ^ pub_r001217_17_2) & 63;
  if ((stage_v_173_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  }
  if ((stage_v_173_2 & 1) != 0)
  {
    if ((stage_v_49_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  }
  int stage_v_174_1 = ((pub_r001217_7_1 * 2) + 6) & 63;
  int stage_v_174_2 = ((pub_r001217_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (stage_v_173_1 ^ pub_r001217_14_1) & 63;
  int stage_v_175_2 = (stage_v_173_2 ^ pub_r001217_14_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_175_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  }
  if ((stage_v_175_2 & 1) != 0)
  {
    if ((stage_v_26_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_175_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  }
  int stage_v_176_1 = (stage_v_25_1 ^ pub_r001217_2_1) & 63;
  int stage_v_176_2 = (stage_v_25_2 ^ pub_r001217_2_2) & 63;
  if ((stage_v_176_1 & 1) != 0)
  {
    if ((stage_v_134_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  }
  if ((stage_v_176_2 & 1) != 0)
  {
    if ((stage_v_134_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  }
  int stage_v_177_1 = (stage_v_59_1 ^ pub_r001217_16_1) & 63;
  int stage_v_177_2 = (stage_v_59_2 ^ pub_r001217_16_2) & 63;
  if ((stage_v_177_1 & 1) != 0)
  {
    if ((stage_v_113_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_177_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  }
  if ((stage_v_177_2 & 1) != 0)
  {
    if ((stage_v_113_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_177_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  }
  int stage_v_178_1 = (sec_r001217_7_1 ^ pub_r001217_16_1) & 63;
  int stage_v_178_2 = (sec_r001217_7_2 ^ pub_r001217_16_2) & 63;
  if ((stage_v_178_1 & 1) != 0)
  {
    if ((stage_v_140_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_178_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  }
  if ((stage_v_178_2 & 1) != 0)
  {
    if ((stage_v_140_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_178_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  }
  int stage_v_179_1 = (stage_v_12_1 ^ pub_r001217_11_1) & 63;
  int stage_v_179_2 = (stage_v_12_2 ^ pub_r001217_11_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((stage_v_118_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_179_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  }
  if ((stage_v_179_2 & 1) != 0)
  {
    if ((stage_v_118_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_179_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  }
  int stage_v_180_1 = ((pub_r001217_1_1 * 2) + 33) & 63;
  int stage_v_180_2 = ((pub_r001217_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (stage_v_175_1 ^ pub_r001217_13_1) & 63;
  int stage_v_181_2 = (stage_v_175_2 ^ pub_r001217_13_2) & 63;
  if ((stage_v_181_1 & 1) != 0)
  {
    if ((stage_v_178_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_181_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  }
  if ((stage_v_181_2 & 1) != 0)
  {
    if ((stage_v_178_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_181_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  }
  int stage_v_182_1 = ((pub_r001217_10_1 * 2) + 15) & 63;
  int stage_v_182_2 = ((pub_r001217_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001217_2_1 * 2) + 36) & 63;
  int stage_v_183_2 = ((pub_r001217_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (stage_v_80_1 ^ pub_r001217_6_1) & 63;
  int stage_v_184_2 = (stage_v_80_2 ^ pub_r001217_6_2) & 63;
  if ((stage_v_184_1 & 1) != 0)
  {
    if ((sec_r001217_22_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_184_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  }
  if ((stage_v_184_2 & 1) != 0)
  {
    if ((sec_r001217_22_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_184_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  }
  int stage_v_185_1 = (sec_r001217_8_1 ^ pub_r001217_8_1) & 63;
  int stage_v_185_2 = (sec_r001217_8_2 ^ pub_r001217_8_2) & 63;
  if ((stage_v_185_1 & 1) != 0)
  {
    if ((stage_v_82_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_185_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  }
  if ((stage_v_185_2 & 1) != 0)
  {
    if ((stage_v_82_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_185_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  }
  int stage_v_186_1 = (stage_v_93_1 ^ pub_r001217_8_1) & 63;
  int stage_v_186_2 = (stage_v_93_2 ^ pub_r001217_8_2) & 63;
  if ((stage_v_186_1 & 1) != 0)
  {
    if ((stage_v_92_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_186_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  }
  if ((stage_v_186_2 & 1) != 0)
  {
    if ((stage_v_92_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_186_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  }
  int stage_v_187_1 = (stage_v_121_1 ^ pub_r001217_8_1) & 63;
  int stage_v_187_2 = (stage_v_121_2 ^ pub_r001217_8_2) & 63;
  if ((stage_v_187_1 & 1) != 0)
  {
    if ((stage_v_144_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_187_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  }
  if ((stage_v_187_2 & 1) != 0)
  {
    if ((stage_v_144_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_187_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  }
  int stage_v_188_1 = ((pub_r001217_14_1 * 2) + 13) & 63;
  int stage_v_188_2 = ((pub_r001217_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (helper_flow_4_1 ^ pub_r001217_10_1) & 63;
  int stage_v_189_2 = (helper_flow_4_2 ^ pub_r001217_10_2) & 63;
  if ((stage_v_189_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_189_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  }
  if ((stage_v_189_2 & 1) != 0)
  {
    if ((stage_v_24_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_189_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  }
  int stage_v_190_1 = (stage_v_119_1 ^ pub_r001217_3_1) & 63;
  int stage_v_190_2 = (stage_v_119_2 ^ pub_r001217_3_2) & 63;
  if ((stage_v_190_1 & 1) != 0)
  {
    if ((stage_v_42_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_190_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  }
  if ((stage_v_190_2 & 1) != 0)
  {
    if ((stage_v_42_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_190_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  }
  int stage_v_191_1 = (stage_v_21_1 ^ pub_r001217_2_1) & 63;
  int stage_v_191_2 = (stage_v_21_2 ^ pub_r001217_2_2) & 63;
  if ((stage_v_191_1 & 1) != 0)
  {
    if ((stage_v_146_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_191_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  }
  if ((stage_v_191_2 & 1) != 0)
  {
    if ((stage_v_146_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_191_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  }
  int stage_v_192_1 = (stage_v_114_1 ^ pub_r001217_7_1) & 63;
  int stage_v_192_2 = (stage_v_114_2 ^ pub_r001217_7_2) & 63;
  if ((stage_v_192_1 & 1) != 0)
  {
    if ((stage_v_184_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_192_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  }
  if ((stage_v_192_2 & 1) != 0)
  {
    if ((stage_v_184_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_192_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001217_13_1 == pub_r001217_13_2);
  __CPROVER_assume(sec_r001217_11_1 != sec_r001217_11_2);
  __CPROVER_assume(pub_r001217_9_1 == pub_r001217_9_2);
  __CPROVER_assume(pub_r001217_12_1 == pub_r001217_12_2);
  __CPROVER_assume(sec_r001217_14_1 != sec_r001217_14_2);
  __CPROVER_assume(pub_r001217_6_1 == pub_r001217_6_2);
  __CPROVER_assume(pub_r001217_8_1 == pub_r001217_8_2);
  __CPROVER_assume(pub_r001217_11_1 == pub_r001217_11_2);
  __CPROVER_assume(pub_r001217_5_1 == pub_r001217_5_2);
  __CPROVER_assume(pub_r001217_10_1 == pub_r001217_10_2);
  __CPROVER_assume(sec_r001217_7_1 != sec_r001217_7_2);
  __CPROVER_assume(sec_r001217_6_1 != sec_r001217_6_2);
  __CPROVER_assume(sec_r001217_13_1 != sec_r001217_13_2);
  __CPROVER_assume(sec_r001217_19_1 != sec_r001217_19_2);
  __CPROVER_assume(pub_r001217_16_1 == pub_r001217_16_2);
  __CPROVER_assume(sec_r001217_21_1 != sec_r001217_21_2);
  __CPROVER_assume(pub_r001217_2_1 == pub_r001217_2_2);
  __CPROVER_assume(sec_r001217_9_1 != sec_r001217_9_2);
  __CPROVER_assume(pub_r001217_7_1 == pub_r001217_7_2);
  __CPROVER_assume(sec_r001217_20_1 != sec_r001217_20_2);
  __CPROVER_assume(pub_r001217_1_1 == pub_r001217_1_2);
  __CPROVER_assume(pub_r001217_14_1 == pub_r001217_14_2);
  __CPROVER_assume(sec_r001217_5_1 != sec_r001217_5_2);
  __CPROVER_assume(sec_r001217_0_1 != sec_r001217_0_2);
  __CPROVER_assume(sec_r001217_8_1 != sec_r001217_8_2);
  __CPROVER_assume(sec_r001217_18_1 != sec_r001217_18_2);
  __CPROVER_assume(sec_r001217_10_1 != sec_r001217_10_2);
  __CPROVER_assume(sec_r001217_3_1 != sec_r001217_3_2);
  __CPROVER_assume(pub_r001217_0_1 == pub_r001217_0_2);
  __CPROVER_assume(sec_r001217_16_1 != sec_r001217_16_2);
  __CPROVER_assume(pub_r001217_15_1 == pub_r001217_15_2);
  __CPROVER_assume(sec_r001217_17_1 != sec_r001217_17_2);
  __CPROVER_assume(sec_r001217_4_1 != sec_r001217_4_2);
  __CPROVER_assume(pub_r001217_17_1 == pub_r001217_17_2);
  __CPROVER_assume(sec_r001217_2_1 != sec_r001217_2_2);
  __CPROVER_assume(sec_r001217_22_1 != sec_r001217_22_2);
  __CPROVER_assume(pub_r001217_3_1 == pub_r001217_3_2);
  __CPROVER_assume(sec_r001217_15_1 != sec_r001217_15_2);
  __CPROVER_assume(pub_r001217_4_1 == pub_r001217_4_2);
  __CPROVER_assume(sec_r001217_1_1 != sec_r001217_1_2);
  __CPROVER_assume(sec_r001217_12_1 != sec_r001217_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(u_var_1.word == u_var_2.word);
  for (int i_raw = 0; i_raw < 4; i_raw++)
  {
    assert(u_var_1.raw[i_raw] == u_var_2.raw[i_raw]);
  }

  for (int i_pairs = 0; i_pairs < 2; i_pairs++)
  {
    assert(u_var_1.pairs[i_pairs] == u_var_2.pairs[i_pairs]);
  }

  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(table_1[i_0] == table_2[i_0]);
  }

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
  assert(stage_v_0_1 == stage_v_0_2);
  assert(stage_v_1_1 == stage_v_1_2);
  assert(stage_v_2_1 == stage_v_2_2);
  assert(stage_v_3_1 == stage_v_3_2);
  assert(stage_v_4_1 == stage_v_4_2);
  assert(stage_v_5_1 == stage_v_5_2);
  assert(stage_v_6_1 == stage_v_6_2);
  assert(stage_v_7_1 == stage_v_7_2);
  assert(stage_v_8_1 == stage_v_8_2);
  assert(stage_v_9_1 == stage_v_9_2);
  assert(stage_v_10_1 == stage_v_10_2);
  assert(stage_v_11_1 == stage_v_11_2);
  assert(stage_v_12_1 == stage_v_12_2);
  assert(stage_v_13_1 == stage_v_13_2);
  assert(stage_v_14_1 == stage_v_14_2);
  assert(stage_v_15_1 == stage_v_15_2);
  assert(stage_v_16_1 == stage_v_16_2);
  assert(stage_v_17_1 == stage_v_17_2);
  assert(stage_v_18_1 == stage_v_18_2);
  assert(stage_v_19_1 == stage_v_19_2);
  assert(stage_v_20_1 == stage_v_20_2);
  assert(stage_v_21_1 == stage_v_21_2);
  assert(stage_v_22_1 == stage_v_22_2);
  assert(stage_v_23_1 == stage_v_23_2);
  assert(stage_v_24_1 == stage_v_24_2);
  assert(stage_v_25_1 == stage_v_25_2);
  assert(stage_v_26_1 == stage_v_26_2);
  assert(stage_v_27_1 == stage_v_27_2);
  assert(stage_v_28_1 == stage_v_28_2);
  assert(stage_v_29_1 == stage_v_29_2);
  assert(stage_v_30_1 == stage_v_30_2);
  assert(stage_v_31_1 == stage_v_31_2);
  assert(stage_v_32_1 == stage_v_32_2);
  assert(stage_v_33_1 == stage_v_33_2);
  assert(stage_v_34_1 == stage_v_34_2);
  assert(stage_v_35_1 == stage_v_35_2);
  assert(stage_v_36_1 == stage_v_36_2);
  assert(stage_v_37_1 == stage_v_37_2);
  assert(stage_v_38_1 == stage_v_38_2);
  assert(stage_v_39_1 == stage_v_39_2);
  assert(stage_v_40_1 == stage_v_40_2);
  assert(stage_v_41_1 == stage_v_41_2);
  assert(stage_v_42_1 == stage_v_42_2);
  assert(stage_v_43_1 == stage_v_43_2);
  assert(stage_v_44_1 == stage_v_44_2);
  assert(stage_v_45_1 == stage_v_45_2);
  assert(stage_v_46_1 == stage_v_46_2);
  assert(stage_v_47_1 == stage_v_47_2);
  assert(stage_v_48_1 == stage_v_48_2);
  assert(stage_v_49_1 == stage_v_49_2);
  assert(stage_v_50_1 == stage_v_50_2);
  assert(stage_v_51_1 == stage_v_51_2);
  assert(stage_v_52_1 == stage_v_52_2);
  assert(stage_v_53_1 == stage_v_53_2);
  assert(stage_v_54_1 == stage_v_54_2);
  assert(stage_v_55_1 == stage_v_55_2);
  assert(stage_v_56_1 == stage_v_56_2);
  assert(stage_v_57_1 == stage_v_57_2);
  assert(stage_v_58_1 == stage_v_58_2);
  assert(stage_v_59_1 == stage_v_59_2);
  assert(stage_v_60_1 == stage_v_60_2);
  assert(stage_v_61_1 == stage_v_61_2);
  assert(stage_v_62_1 == stage_v_62_2);
  assert(stage_v_63_1 == stage_v_63_2);
  assert(stage_v_64_1 == stage_v_64_2);
  assert(stage_v_65_1 == stage_v_65_2);
  assert(stage_v_66_1 == stage_v_66_2);
  assert(stage_v_67_1 == stage_v_67_2);
  assert(stage_v_68_1 == stage_v_68_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(stage_v_192_1 == stage_v_192_2);
}


