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
struct Transaction_R001677_7713_0
{
  int account_id;
  short status;
  unsigned char balance;
  int fee;
  int rate;
  int buffer[3];
};
struct Vector3D_R001677_7713_1
{
  short coord_y;
  int norm_sq;
  int coord_x;
  int heading;
  int buffer[3];
};
struct MatrixBlock_R001677_7713_2
{
  short stride;
  short trace;
  short dim;
  unsigned char scale;
  int buffer[3];
};
union PacketPayload_R001677_7713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001677_7713_1
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
void fn_R001677_7713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st_1 = {0};
  struct Transaction_R001677_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int pivot_34_1 = 0;
  int pivot_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_34_1 = ((pivot_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_34_2 = ((pivot_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_34_1) & 127;
    acc_2 = (acc_2 + pivot_34_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_46_1 = local_arr_1[aux_1 % 3];
  int damping_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_34_1 == pivot_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_46_1 == damping_46_2);
}

int fn_R001677_7713_0(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int pivot_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_34 = ((pivot_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_34) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int damping_46 = local_arr[aux % 3];
  acc = (acc + (damping_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001677_7713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st_1 = {0};
  struct Vector3D_R001677_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int residue_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_95_1)
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

  switch (residue_95_2)
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

  int threshold_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_67_1) & 63;
  aux_2 = (aux_2 + threshold_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_66_1 = local_arr_1[aux_1 % 3];
  int quotient_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_95_1 == residue_95_2);
  assert(threshold_67_1 == threshold_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_66_1 == quotient_66_2);
}

int fn_R001677_7713_1(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int residue_95 = (aux + st.buffer[1]) & 3;
  switch (residue_95)
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

  int threshold_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_66 = local_arr[aux % 3];
  acc = (acc + (quotient_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001677_7713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st_1 = {0};
  struct Transaction_R001677_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_88_1 = 0;
  int tally_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_88_1 = ((tally_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_88_2 = ((tally_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_88_1) & 127;
    acc_2 = (acc_2 + tally_88_2) & 127;
  }

  int index_reg_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_19_1 > 13)
  {
    acc_1 = ((acc_1 + (index_reg_19_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_19_2 > 13)
  {
    acc_2 = ((acc_2 + (index_reg_19_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_19_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_88_1 == tally_88_2);
  assert(index_reg_19_1 == index_reg_19_2);
}

int fn_R001677_7713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_88 = ((tally_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_88) & 127;
  }

  int index_reg_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_19 > 13)
  {
    acc = ((acc + (index_reg_19 * 2)) + 5) & 127;
    aux ^= index_reg_19 & 15;
  }
  else
  {
    acc = ((acc - index_reg_19) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001677_7713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st_1 = {0};
  struct Transaction_R001677_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int coefficient_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_61_1)
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

  switch (coefficient_61_2)
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

  int coefficient_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_32_1 > 16)
  {
    acc_1 = ((acc_1 + (coefficient_32_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_32_2 > 16)
  {
    acc_2 = ((acc_2 + (coefficient_32_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_61_1 == coefficient_61_2);
  assert(coefficient_32_1 == coefficient_32_2);
}

int fn_R001677_7713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int coefficient_61 = (aux + st.buffer[1]) & 3;
  switch (coefficient_61)
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

  int coefficient_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_32 > 16)
  {
    acc = ((acc + (coefficient_32 * 2)) + 5) & 127;
    aux ^= coefficient_32 & 15;
  }
  else
  {
    acc = ((acc - coefficient_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001677_7713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st_1 = {0};
  struct Vector3D_R001677_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int metric_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_49_1)
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

  switch (metric_49_2)
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

  int phase_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_45_1) & 63;
  aux_2 = (aux_2 + phase_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_81_1 > 14)
  {
    acc_1 = ((acc_1 + (index_reg_81_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_81_2 > 14)
  {
    acc_2 = ((acc_2 + (index_reg_81_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_49_1 == metric_49_2);
  assert(phase_45_1 == phase_45_2);
  assert(index_reg_81_1 == index_reg_81_2);
}

int fn_R001677_7713_4(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int metric_49 = (aux + st.buffer[1]) & 3;
  switch (metric_49)
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

  int phase_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_45) & 63;
  acc ^= aux;
  int index_reg_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_81 > 14)
  {
    acc = ((acc + (index_reg_81 * 2)) + 5) & 127;
    aux ^= index_reg_81 & 15;
  }
  else
  {
    acc = ((acc - index_reg_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001677_7713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001677_7713_2 st_1 = {0};
  struct MatrixBlock_R001677_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int delta_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_55_1 > 18)
  {
    acc_1 = ((acc_1 + (delta_55_1 * 2)) + 5) & 127;
    aux_1 ^= delta_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_55_2 > 18)
  {
    acc_2 = ((acc_2 + (delta_55_2 * 2)) + 5) & 127;
    aux_2 ^= delta_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_25_1)
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

  switch (delta_25_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_55_1 == delta_55_2);
  assert(delta_25_1 == delta_25_2);
}

int fn_R001677_7713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001677_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int delta_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_55 > 18)
  {
    acc = ((acc + (delta_55 * 2)) + 5) & 127;
    aux ^= delta_55 & 15;
  }
  else
  {
    acc = ((acc - delta_55) + 11) & 127;
    aux += 3;
  }
  int delta_25 = (aux + st.buffer[1]) & 3;
  switch (delta_25)
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

  return (acc + aux) & 255;
}

void fn_R001677_7713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st_1 = {0};
  struct Transaction_R001677_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int parity_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_56_1)
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

  switch (parity_56_2)
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

  int delta_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_55_1) & 63;
  aux_2 = (aux_2 + delta_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_73_1 = local_arr_1[aux_1 % 3];
  int parity_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_73_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_56_1 == parity_56_2);
  assert(delta_55_1 == delta_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_73_1 == parity_73_2);
}

int fn_R001677_7713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int parity_56 = (aux + st.buffer[1]) & 3;
  switch (parity_56)
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

  int delta_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_55) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_73 = local_arr[aux % 3];
  acc = (acc + (parity_73 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001677_7713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st_1 = {0};
  struct Vector3D_R001677_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int residue_44_1 = 0;
  int residue_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_44_1 = ((residue_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_44_2 = ((residue_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_44_1) & 127;
    acc_2 = (acc_2 + residue_44_2) & 127;
  }

  int metric_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_76_1) & 63;
  aux_2 = (aux_2 + metric_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_32_1)
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

  switch (sample_32_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_44_1 == residue_44_2);
  assert(metric_76_1 == metric_76_2);
  assert(sample_32_1 == sample_32_2);
}

int fn_R001677_7713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int residue_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_44 = ((residue_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_44) & 127;
  }

  int metric_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_76) & 63;
  acc ^= aux;
  int sample_32 = (aux + st.buffer[1]) & 3;
  switch (sample_32)
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

  return (acc + aux) & 255;
}

void fn_R001677_7713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st_1 = {0};
  struct Transaction_R001677_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int offset_41_1 = 0;
  int offset_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_41_1 = ((offset_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_41_2 = ((offset_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_41_1) & 127;
    acc_2 = (acc_2 + offset_41_2) & 127;
  }

  int delta_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_83_1)
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

  switch (delta_83_2)
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
  int weight_30_1 = local_arr_1[aux_1 % 3];
  int weight_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_30_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_41_1 == offset_41_2);
  assert(delta_83_1 == delta_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_30_1 == weight_30_2);
}

int fn_R001677_7713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int offset_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_41 = ((offset_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_41) & 127;
  }

  int delta_83 = (aux + st.buffer[1]) & 3;
  switch (delta_83)
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
  int weight_30 = local_arr[aux % 3];
  acc = (acc + (weight_30 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001677_7713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001677_7713_2 st_1 = {0};
  struct MatrixBlock_R001677_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int offset_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_22_1)
  {
    case 0:
      acc_1 = (acc_1 + 9) & 127;
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

  switch (offset_22_2)
  {
    case 0:
      acc_2 = (acc_2 + 9) & 127;
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

  int residue_89_1 = 0;
  int residue_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_89_1 = ((residue_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_89_2 = ((residue_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_89_1) & 127;
    acc_2 = (acc_2 + residue_89_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_22_1 == offset_22_2);
  assert(residue_89_1 == residue_89_2);
}

int fn_R001677_7713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001677_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int offset_22 = (aux + st.buffer[1]) & 3;
  switch (offset_22)
  {
    case 0:
      acc = (acc + 9) & 127;
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

  int residue_89 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_89 = ((residue_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_89) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001677_7713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st_1 = {0};
  struct Transaction_R001677_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int index_reg_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_29_1 > 49)
  {
    acc_1 = ((acc_1 + (index_reg_29_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_29_2 > 49)
  {
    acc_2 = ((acc_2 + (index_reg_29_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_56_1 = local_arr_1[aux_1 % 3];
  int tally_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_56_2 * 2)) & 127;
  int window_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_31_1)
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

  switch (window_31_2)
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

  int checksum_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_40_1) & 63;
  aux_2 = (aux_2 + checksum_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_29_1 == index_reg_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_56_1 == tally_56_2);
  assert(window_31_1 == window_31_2);
  assert(checksum_40_1 == checksum_40_2);
}

int fn_R001677_7713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int index_reg_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_29 > 49)
  {
    acc = ((acc + (index_reg_29 * 2)) + 5) & 127;
    aux ^= index_reg_29 & 15;
  }
  else
  {
    acc = ((acc - index_reg_29) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_56 = local_arr[aux % 3];
  acc = (acc + (tally_56 * 2)) & 127;
  int window_31 = (aux + st.buffer[1]) & 3;
  switch (window_31)
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

  int checksum_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_40) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001677_7713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001677_7713_2 st_1 = {0};
  struct MatrixBlock_R001677_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int pivot_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_50_1)
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

  switch (pivot_50_2)
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

  int coefficient_38_1 = 0;
  int coefficient_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_38_1 = ((coefficient_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_38_2 = ((coefficient_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_38_1) & 127;
    acc_2 = (acc_2 + coefficient_38_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_34_1 > 30)
  {
    acc_1 = ((acc_1 + (anchor_34_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_34_2 > 30)
  {
    acc_2 = ((acc_2 + (anchor_34_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_50_1 == pivot_50_2);
  assert(coefficient_38_1 == coefficient_38_2);
  assert(anchor_34_1 == anchor_34_2);
}

int fn_R001677_7713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001677_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int pivot_50 = (aux + st.buffer[1]) & 3;
  switch (pivot_50)
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

  int coefficient_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_38 = ((coefficient_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_38) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_34 > 30)
  {
    acc = ((acc + (anchor_34 * 2)) + 5) & 127;
    aux ^= anchor_34 & 15;
  }
  else
  {
    acc = ((acc - anchor_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001677_7713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001677_7713_2 st_1 = {0};
  struct MatrixBlock_R001677_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int vector_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_68_1 > 46)
  {
    acc_1 = ((acc_1 + (vector_68_1 * 2)) + 5) & 127;
    aux_1 ^= vector_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_68_2 > 46)
  {
    acc_2 = ((acc_2 + (vector_68_2 * 2)) + 5) & 127;
    aux_2 ^= vector_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_11_1) & 63;
  aux_2 = (aux_2 + residue_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_68_1 == vector_68_2);
  assert(residue_11_1 == residue_11_2);
}

int fn_R001677_7713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001677_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int vector_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_68 > 46)
  {
    acc = ((acc + (vector_68 * 2)) + 5) & 127;
    aux ^= vector_68 & 15;
  }
  else
  {
    acc = ((acc - vector_68) + 11) & 127;
    aux += 3;
  }
  int residue_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_11) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001677_7713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001677_7713_2 st_1 = {0};
  struct MatrixBlock_R001677_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tracker_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_91_1)
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

  switch (tracker_91_2)
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

  int vector_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_49_1) & 63;
  aux_2 = (aux_2 + vector_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_91_1 == tracker_91_2);
  assert(vector_49_1 == vector_49_2);
}

int fn_R001677_7713_13(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001677_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tracker_91 = (aux + st.buffer[1]) & 3;
  switch (tracker_91)
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

  int vector_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_49) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001677_7713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st_1 = {0};
  struct Transaction_R001677_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_30_1) & 63;
  aux_2 = (aux_2 + metric_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_82_1 = local_arr_1[aux_1 % 3];
  int vector_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_30_1 == metric_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_82_1 == vector_82_2);
}

int fn_R001677_7713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_82 = local_arr[aux % 3];
  acc = (acc + (vector_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001677_7713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st_1 = {0};
  struct Vector3D_R001677_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int checksum_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_82_1)
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

  switch (checksum_82_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_10_1 = local_arr_1[aux_1 % 3];
  int vector_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_10_2 * 2)) & 127;
  int delta_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_45_1) & 63;
  aux_2 = (aux_2 + delta_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_15_1 > 25)
  {
    acc_1 = ((acc_1 + (stride_15_1 * 2)) + 5) & 127;
    aux_1 ^= stride_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_15_2 > 25)
  {
    acc_2 = ((acc_2 + (stride_15_2 * 2)) + 5) & 127;
    aux_2 ^= stride_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_82_1 == checksum_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_10_1 == vector_10_2);
  assert(delta_45_1 == delta_45_2);
  assert(stride_15_1 == stride_15_2);
}

int fn_R001677_7713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int checksum_82 = (aux + st.buffer[1]) & 3;
  switch (checksum_82)
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

  int local_arr[3] = {4, 9, 15};
  int vector_10 = local_arr[aux % 3];
  acc = (acc + (vector_10 * 2)) & 127;
  int delta_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_45) & 63;
  acc ^= aux;
  int stride_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_15 > 25)
  {
    acc = ((acc + (stride_15 * 2)) + 5) & 127;
    aux ^= stride_15 & 15;
  }
  else
  {
    acc = ((acc - stride_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001677_7713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st_1 = {0};
  struct Vector3D_R001677_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int accumulator_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_64_1 > 23)
  {
    acc_1 = ((acc_1 + (accumulator_64_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_64_2 > 23)
  {
    acc_2 = ((acc_2 + (accumulator_64_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_69_1 = local_arr_1[aux_1 % 3];
  int coefficient_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_69_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_64_1 == accumulator_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_69_1 == coefficient_69_2);
}

int fn_R001677_7713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int accumulator_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_64 > 23)
  {
    acc = ((acc + (accumulator_64 * 2)) + 5) & 127;
    aux ^= accumulator_64 & 15;
  }
  else
  {
    acc = ((acc - accumulator_64) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_69 = local_arr[aux % 3];
  acc = (acc + (coefficient_69 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001677_7713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st_1 = {0};
  struct Transaction_R001677_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int quantum_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_23_1 > 42)
  {
    acc_1 = ((acc_1 + (quantum_23_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_23_2 > 42)
  {
    acc_2 = ((acc_2 + (quantum_23_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_17_1 = 0;
  int phase_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_17_1 = ((phase_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_17_2 = ((phase_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_17_1) & 127;
    acc_2 = (acc_2 + phase_17_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_21_1 = local_arr_1[aux_1 % 3];
  int sample_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_23_1 == quantum_23_2);
  assert(phase_17_1 == phase_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_21_1 == sample_21_2);
}

int fn_R001677_7713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int quantum_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_23 > 42)
  {
    acc = ((acc + (quantum_23 * 2)) + 5) & 127;
    aux ^= quantum_23 & 15;
  }
  else
  {
    acc = ((acc - quantum_23) + 11) & 127;
    aux += 3;
  }
  int phase_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_17 = ((phase_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_17) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_21 = local_arr[aux % 3];
  acc = (acc + (sample_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001677_7713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st_1 = {0};
  struct Transaction_R001677_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int scale_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_29_1) & 63;
  aux_2 = (aux_2 + scale_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_34_1 > 41)
  {
    acc_1 = ((acc_1 + (offset_34_1 * 2)) + 5) & 127;
    aux_1 ^= offset_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_34_2 > 41)
  {
    acc_2 = ((acc_2 + (offset_34_2 * 2)) + 5) & 127;
    aux_2 ^= offset_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_50_1)
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

  switch (parity_50_2)
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

  int sample_10_1 = 0;
  int sample_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_10_1 = ((sample_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_10_2 = ((sample_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_10_1) & 127;
    acc_2 = (acc_2 + sample_10_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_29_1 == scale_29_2);
  assert(offset_34_1 == offset_34_2);
  assert(parity_50_1 == parity_50_2);
  assert(sample_10_1 == sample_10_2);
}

int fn_R001677_7713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int scale_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_29) & 63;
  acc ^= aux;
  int offset_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_34 > 41)
  {
    acc = ((acc + (offset_34 * 2)) + 5) & 127;
    aux ^= offset_34 & 15;
  }
  else
  {
    acc = ((acc - offset_34) + 11) & 127;
    aux += 3;
  }
  int parity_50 = (aux + st.buffer[1]) & 3;
  switch (parity_50)
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

  int sample_10 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_10 = ((sample_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_10) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001677_7713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st_1 = {0};
  struct Transaction_R001677_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_67_1)
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

  switch (window_67_2)
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

  int parity_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_45_1) & 63;
  aux_2 = (aux_2 + parity_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_67_1 == window_67_2);
  assert(parity_45_1 == parity_45_2);
}

int fn_R001677_7713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001677_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_67 = (aux + st.buffer[1]) & 3;
  switch (window_67)
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

  int parity_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_45) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001677_7713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st_1 = {0};
  struct Vector3D_R001677_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int mask_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_71_1 > 34)
  {
    acc_1 = ((acc_1 + (mask_71_1 * 2)) + 5) & 127;
    aux_1 ^= mask_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_71_2 > 34)
  {
    acc_2 = ((acc_2 + (mask_71_2 * 2)) + 5) & 127;
    aux_2 ^= mask_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_40_1 = local_arr_1[aux_1 % 3];
  int tally_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_71_1 == mask_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_40_1 == tally_40_2);
}

int fn_R001677_7713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int mask_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_71 > 34)
  {
    acc = ((acc + (mask_71 * 2)) + 5) & 127;
    aux ^= mask_71 & 15;
  }
  else
  {
    acc = ((acc - mask_71) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_40 = local_arr[aux % 3];
  acc = (acc + (tally_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001677_7713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st_1 = {0};
  struct Vector3D_R001677_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int parity_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_78_1)
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

  switch (parity_78_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_33_1 > 43)
  {
    acc_1 = ((acc_1 + (damping_33_1 * 2)) + 5) & 127;
    aux_1 ^= damping_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_33_2 > 43)
  {
    acc_2 = ((acc_2 + (damping_33_2 * 2)) + 5) & 127;
    aux_2 ^= damping_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_78_1 == parity_78_2);
  assert(damping_33_1 == damping_33_2);
}

int fn_R001677_7713_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001677_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int parity_78 = (aux + st.buffer[1]) & 3;
  switch (parity_78)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_33 > 43)
  {
    acc = ((acc + (damping_33 * 2)) + 5) & 127;
    aux ^= damping_33 & 15;
  }
  else
  {
    acc = ((acc - damping_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001677_0_1;
  int sec_r001677_0_2;
  int sec_r001677_1_1;
  int sec_r001677_1_2;
  int sec_r001677_2_1;
  int sec_r001677_2_2;
  int sec_r001677_3_1;
  int sec_r001677_3_2;
  int sec_r001677_4_1;
  int sec_r001677_4_2;
  int sec_r001677_5_1;
  int sec_r001677_5_2;
  int sec_r001677_6_1;
  int sec_r001677_6_2;
  int sec_r001677_7_1;
  int sec_r001677_7_2;
  int sec_r001677_8_1;
  int sec_r001677_8_2;
  int sec_r001677_9_1;
  int sec_r001677_9_2;
  int sec_r001677_10_1;
  int sec_r001677_10_2;
  int sec_r001677_11_1;
  int sec_r001677_11_2;
  int sec_r001677_12_1;
  int sec_r001677_12_2;
  int sec_r001677_13_1;
  int sec_r001677_13_2;
  int sec_r001677_14_1;
  int sec_r001677_14_2;
  int sec_r001677_15_1;
  int sec_r001677_15_2;
  int sec_r001677_16_1;
  int sec_r001677_16_2;
  int sec_r001677_17_1;
  int sec_r001677_17_2;
  int sec_r001677_18_1;
  int sec_r001677_18_2;
  int sec_r001677_19_1;
  int sec_r001677_19_2;
  int sec_r001677_20_1;
  int sec_r001677_20_2;
  int sec_r001677_21_1;
  int sec_r001677_21_2;
  int pub_r001677_0_1;
  int pub_r001677_0_2;
  int pub_r001677_1_1;
  int pub_r001677_1_2;
  int pub_r001677_2_1;
  int pub_r001677_2_2;
  int pub_r001677_3_1;
  int pub_r001677_3_2;
  int pub_r001677_4_1;
  int pub_r001677_4_2;
  int pub_r001677_5_1;
  int pub_r001677_5_2;
  int pub_r001677_6_1;
  int pub_r001677_6_2;
  int pub_r001677_7_1;
  int pub_r001677_7_2;
  int pub_r001677_8_1;
  int pub_r001677_8_2;
  int pub_r001677_9_1;
  int pub_r001677_9_2;
  int pub_r001677_10_1;
  int pub_r001677_10_2;
  int pub_r001677_11_1;
  int pub_r001677_11_2;
  int pub_r001677_12_1;
  int pub_r001677_12_2;
  int pub_r001677_13_1;
  int pub_r001677_13_2;
  int pub_r001677_14_1;
  int pub_r001677_14_2;
  int pub_r001677_15_1;
  int pub_r001677_15_2;
  int pub_r001677_16_1;
  int pub_r001677_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001677_0_1 >= (-100)) && (pub_r001677_0_1 <= 100));
  __CPROVER_assume((pub_r001677_0_2 >= (-100)) && (pub_r001677_0_2 <= 100));
  __CPROVER_assume((pub_r001677_1_1 >= (-100)) && (pub_r001677_1_1 <= 100));
  __CPROVER_assume((pub_r001677_1_2 >= (-100)) && (pub_r001677_1_2 <= 100));
  __CPROVER_assume((pub_r001677_2_1 >= (-100)) && (pub_r001677_2_1 <= 100));
  __CPROVER_assume((pub_r001677_2_2 >= (-100)) && (pub_r001677_2_2 <= 100));
  __CPROVER_assume((pub_r001677_3_1 >= (-100)) && (pub_r001677_3_1 <= 100));
  __CPROVER_assume((pub_r001677_3_2 >= (-100)) && (pub_r001677_3_2 <= 100));
  __CPROVER_assume((pub_r001677_4_1 >= (-100)) && (pub_r001677_4_1 <= 100));
  __CPROVER_assume((pub_r001677_4_2 >= (-100)) && (pub_r001677_4_2 <= 100));
  __CPROVER_assume((pub_r001677_5_1 >= (-100)) && (pub_r001677_5_1 <= 100));
  __CPROVER_assume((pub_r001677_5_2 >= (-100)) && (pub_r001677_5_2 <= 100));
  __CPROVER_assume((pub_r001677_6_1 >= (-100)) && (pub_r001677_6_1 <= 100));
  __CPROVER_assume((pub_r001677_6_2 >= (-100)) && (pub_r001677_6_2 <= 100));
  __CPROVER_assume((pub_r001677_7_1 >= (-100)) && (pub_r001677_7_1 <= 100));
  __CPROVER_assume((pub_r001677_7_2 >= (-100)) && (pub_r001677_7_2 <= 100));
  __CPROVER_assume((pub_r001677_8_1 >= (-100)) && (pub_r001677_8_1 <= 100));
  __CPROVER_assume((pub_r001677_8_2 >= (-100)) && (pub_r001677_8_2 <= 100));
  __CPROVER_assume((pub_r001677_9_1 >= (-100)) && (pub_r001677_9_1 <= 100));
  __CPROVER_assume((pub_r001677_9_2 >= (-100)) && (pub_r001677_9_2 <= 100));
  __CPROVER_assume((pub_r001677_10_1 >= (-100)) && (pub_r001677_10_1 <= 100));
  __CPROVER_assume((pub_r001677_10_2 >= (-100)) && (pub_r001677_10_2 <= 100));
  __CPROVER_assume((pub_r001677_11_1 >= (-100)) && (pub_r001677_11_1 <= 100));
  __CPROVER_assume((pub_r001677_11_2 >= (-100)) && (pub_r001677_11_2 <= 100));
  __CPROVER_assume((pub_r001677_12_1 >= (-100)) && (pub_r001677_12_1 <= 100));
  __CPROVER_assume((pub_r001677_12_2 >= (-100)) && (pub_r001677_12_2 <= 100));
  __CPROVER_assume((pub_r001677_13_1 >= (-100)) && (pub_r001677_13_1 <= 100));
  __CPROVER_assume((pub_r001677_13_2 >= (-100)) && (pub_r001677_13_2 <= 100));
  __CPROVER_assume((pub_r001677_14_1 >= (-100)) && (pub_r001677_14_1 <= 100));
  __CPROVER_assume((pub_r001677_14_2 >= (-100)) && (pub_r001677_14_2 <= 100));
  __CPROVER_assume((pub_r001677_15_1 >= (-100)) && (pub_r001677_15_1 <= 100));
  __CPROVER_assume((pub_r001677_15_2 >= (-100)) && (pub_r001677_15_2 <= 100));
  __CPROVER_assume((pub_r001677_16_1 >= (-100)) && (pub_r001677_16_1 <= 100));
  __CPROVER_assume((pub_r001677_16_2 >= (-100)) && (pub_r001677_16_2 <= 100));
  __CPROVER_assume((sec_r001677_0_1 >= 0) && (sec_r001677_0_1 <= 255));
  __CPROVER_assume((sec_r001677_0_2 >= 0) && (sec_r001677_0_2 <= 255));
  __CPROVER_assume((sec_r001677_1_1 >= 0) && (sec_r001677_1_1 <= 255));
  __CPROVER_assume((sec_r001677_1_2 >= 0) && (sec_r001677_1_2 <= 255));
  __CPROVER_assume((sec_r001677_2_1 >= 0) && (sec_r001677_2_1 <= 255));
  __CPROVER_assume((sec_r001677_2_2 >= 0) && (sec_r001677_2_2 <= 255));
  __CPROVER_assume((sec_r001677_3_1 >= 0) && (sec_r001677_3_1 <= 255));
  __CPROVER_assume((sec_r001677_3_2 >= 0) && (sec_r001677_3_2 <= 255));
  __CPROVER_assume((sec_r001677_4_1 >= 0) && (sec_r001677_4_1 <= 255));
  __CPROVER_assume((sec_r001677_4_2 >= 0) && (sec_r001677_4_2 <= 255));
  __CPROVER_assume((sec_r001677_5_1 >= 0) && (sec_r001677_5_1 <= 255));
  __CPROVER_assume((sec_r001677_5_2 >= 0) && (sec_r001677_5_2 <= 255));
  __CPROVER_assume((sec_r001677_6_1 >= 0) && (sec_r001677_6_1 <= 255));
  __CPROVER_assume((sec_r001677_6_2 >= 0) && (sec_r001677_6_2 <= 255));
  __CPROVER_assume((sec_r001677_7_1 >= 0) && (sec_r001677_7_1 <= 255));
  __CPROVER_assume((sec_r001677_7_2 >= 0) && (sec_r001677_7_2 <= 255));
  __CPROVER_assume((sec_r001677_8_1 >= 0) && (sec_r001677_8_1 <= 255));
  __CPROVER_assume((sec_r001677_8_2 >= 0) && (sec_r001677_8_2 <= 255));
  __CPROVER_assume((sec_r001677_9_1 >= 0) && (sec_r001677_9_1 <= 255));
  __CPROVER_assume((sec_r001677_9_2 >= 0) && (sec_r001677_9_2 <= 255));
  __CPROVER_assume((sec_r001677_10_1 >= 0) && (sec_r001677_10_1 <= 255));
  __CPROVER_assume((sec_r001677_10_2 >= 0) && (sec_r001677_10_2 <= 255));
  __CPROVER_assume((sec_r001677_11_1 >= 0) && (sec_r001677_11_1 <= 255));
  __CPROVER_assume((sec_r001677_11_2 >= 0) && (sec_r001677_11_2 <= 255));
  __CPROVER_assume((sec_r001677_12_1 >= 0) && (sec_r001677_12_1 <= 255));
  __CPROVER_assume((sec_r001677_12_2 >= 0) && (sec_r001677_12_2 <= 255));
  __CPROVER_assume((sec_r001677_13_1 >= 0) && (sec_r001677_13_1 <= 255));
  __CPROVER_assume((sec_r001677_13_2 >= 0) && (sec_r001677_13_2 <= 255));
  __CPROVER_assume((sec_r001677_14_1 >= 0) && (sec_r001677_14_1 <= 255));
  __CPROVER_assume((sec_r001677_14_2 >= 0) && (sec_r001677_14_2 <= 255));
  __CPROVER_assume((sec_r001677_15_1 >= 0) && (sec_r001677_15_1 <= 255));
  __CPROVER_assume((sec_r001677_15_2 >= 0) && (sec_r001677_15_2 <= 255));
  __CPROVER_assume((sec_r001677_16_1 >= 0) && (sec_r001677_16_1 <= 255));
  __CPROVER_assume((sec_r001677_16_2 >= 0) && (sec_r001677_16_2 <= 255));
  __CPROVER_assume((sec_r001677_17_1 >= 0) && (sec_r001677_17_1 <= 255));
  __CPROVER_assume((sec_r001677_17_2 >= 0) && (sec_r001677_17_2 <= 255));
  __CPROVER_assume((sec_r001677_18_1 >= 0) && (sec_r001677_18_1 <= 255));
  __CPROVER_assume((sec_r001677_18_2 >= 0) && (sec_r001677_18_2 <= 255));
  __CPROVER_assume((sec_r001677_19_1 >= 0) && (sec_r001677_19_1 <= 255));
  __CPROVER_assume((sec_r001677_19_2 >= 0) && (sec_r001677_19_2 <= 255));
  __CPROVER_assume((sec_r001677_20_1 >= 0) && (sec_r001677_20_1 <= 255));
  __CPROVER_assume((sec_r001677_20_2 >= 0) && (sec_r001677_20_2 <= 255));
  __CPROVER_assume((sec_r001677_21_1 >= 0) && (sec_r001677_21_1 <= 255));
  __CPROVER_assume((sec_r001677_21_2 >= 0) && (sec_r001677_21_2 <= 255));
  struct Transaction_R001677_7713_0 st_var_0_1 = {0};
  struct Transaction_R001677_7713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001677_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001677_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001677_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001677_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001677_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001677_0_2 + 7) & 15;
  struct Vector3D_R001677_7713_1 st_var_1_1 = {0};
  struct Vector3D_R001677_7713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001677_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001677_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001677_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001677_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001677_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001677_0_2 + 9) & 15;
  struct MatrixBlock_R001677_7713_2 st_var_2_1 = {0};
  struct MatrixBlock_R001677_7713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001677_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001677_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001677_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001677_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001677_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001677_0_2 + 11) & 15;
  union PacketPayload_R001677_7713_0 u_var_1;
  union PacketPayload_R001677_7713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001677_7713_0(sec_r001677_0_1, sec_r001677_1_1);
  int helper_flow_0_2 = fn_R001677_7713_0(sec_r001677_0_2, sec_r001677_1_2);
  fn_R001677_7713_0_2(sec_r001677_0_1, sec_r001677_1_1, sec_r001677_0_2, sec_r001677_1_2);
  int helper_flow_1_1 = fn_R001677_7713_1(sec_r001677_1_1, pub_r001677_2_1);
  int helper_flow_1_2 = fn_R001677_7713_1(sec_r001677_1_2, pub_r001677_2_2);
  fn_R001677_7713_1_2(sec_r001677_1_1, pub_r001677_2_1, sec_r001677_1_2, pub_r001677_2_2);
  int helper_flow_2_1 = fn_R001677_7713_2(sec_r001677_2_1, pub_r001677_3_1, pub_r001677_4_1, pub_r001677_5_1);
  int helper_flow_2_2 = fn_R001677_7713_2(sec_r001677_2_2, pub_r001677_3_2, pub_r001677_4_2, pub_r001677_5_2);
  fn_R001677_7713_2_2(sec_r001677_2_1, pub_r001677_3_1, pub_r001677_4_1, pub_r001677_5_1, sec_r001677_2_2, pub_r001677_3_2, pub_r001677_4_2, pub_r001677_5_2);
  int helper_flow_3_1 = fn_R001677_7713_3(sec_r001677_3_1, sec_r001677_4_1, pub_r001677_5_1);
  int helper_flow_3_2 = fn_R001677_7713_3(sec_r001677_3_2, sec_r001677_4_2, pub_r001677_5_2);
  fn_R001677_7713_3_2(sec_r001677_3_1, sec_r001677_4_1, pub_r001677_5_1, sec_r001677_3_2, sec_r001677_4_2, pub_r001677_5_2);
  int helper_flow_4_1 = fn_R001677_7713_4(sec_r001677_4_1, pub_r001677_5_1);
  int helper_flow_4_2 = fn_R001677_7713_4(sec_r001677_4_2, pub_r001677_5_2);
  fn_R001677_7713_4_2(sec_r001677_4_1, pub_r001677_5_1, sec_r001677_4_2, pub_r001677_5_2);
  int helper_flow_5_1 = fn_R001677_7713_5(sec_r001677_5_1, sec_r001677_6_1, pub_r001677_7_1, pub_r001677_8_1);
  int helper_flow_5_2 = fn_R001677_7713_5(sec_r001677_5_2, sec_r001677_6_2, pub_r001677_7_2, pub_r001677_8_2);
  fn_R001677_7713_5_2(sec_r001677_5_1, sec_r001677_6_1, pub_r001677_7_1, pub_r001677_8_1, sec_r001677_5_2, sec_r001677_6_2, pub_r001677_7_2, pub_r001677_8_2);
  int helper_flow_6_1 = fn_R001677_7713_6(sec_r001677_6_1, pub_r001677_7_1, pub_r001677_8_1);
  int helper_flow_6_2 = fn_R001677_7713_6(sec_r001677_6_2, pub_r001677_7_2, pub_r001677_8_2);
  fn_R001677_7713_6_2(sec_r001677_6_1, pub_r001677_7_1, pub_r001677_8_1, sec_r001677_6_2, pub_r001677_7_2, pub_r001677_8_2);
  int stage_v_0_1 = (sec_r001677_6_1 ^ pub_r001677_9_1) & 63;
  int stage_v_0_2 = (sec_r001677_6_2 ^ pub_r001677_9_2) & 63;
  if ((stage_v_0_1 & 1) != 0)
  {
    if ((sec_r001677_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_0_1 * 2)) & 255;
  }
  if ((stage_v_0_2 & 1) != 0)
  {
    if ((sec_r001677_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_0_2 * 2)) & 255;
  }
  int stage_v_1_1 = ((pub_r001677_2_1 * 2) + 34) & 63;
  int stage_v_1_2 = ((pub_r001677_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (helper_flow_6_1 ^ pub_r001677_5_1) & 63;
  int stage_v_2_2 = (helper_flow_6_2 ^ pub_r001677_5_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
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
    if ((helper_flow_5_2 & 2) != 0)
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
  int stage_v_3_1 = (helper_flow_1_1 ^ pub_r001677_7_1) & 63;
  int stage_v_3_2 = (helper_flow_1_2 ^ pub_r001677_7_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_4_1 = ((pub_r001677_12_1 * 2) + 49) & 63;
  int stage_v_4_2 = ((pub_r001677_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001677_6_1 * 2) + 49) & 63;
  int stage_v_5_2 = ((pub_r001677_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (sec_r001677_13_1 ^ pub_r001677_1_1) & 63;
  int stage_v_6_2 = (sec_r001677_13_2 ^ pub_r001677_1_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
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
    if ((stage_v_0_2 & 2) != 0)
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
  int stage_v_7_1 = (sec_r001677_21_1 ^ pub_r001677_7_1) & 63;
  int stage_v_7_2 = (sec_r001677_21_2 ^ pub_r001677_7_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_7_1 * 2)) & 255;
  }
  if ((stage_v_7_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_7_2 * 2)) & 255;
  }
  int stage_v_8_1 = (sec_r001677_4_1 ^ pub_r001677_15_1) & 63;
  int stage_v_8_2 = (sec_r001677_4_2 ^ pub_r001677_15_2) & 63;
  if ((stage_v_8_1 & 1) != 0)
  {
    if ((sec_r001677_17_1 & 2) != 0)
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
    if ((sec_r001677_17_2 & 2) != 0)
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
  int stage_v_9_1 = ((pub_r001677_1_1 * 2) + 7) & 63;
  int stage_v_9_2 = ((pub_r001677_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001677_10_1 * 2) + 37) & 63;
  int stage_v_10_2 = ((pub_r001677_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (sec_r001677_16_1 ^ pub_r001677_12_1) & 63;
  int stage_v_11_2 = (sec_r001677_16_2 ^ pub_r001677_12_2) & 63;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_11_1 * 2)) & 255;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_11_2 * 2)) & 255;
  }
  int stage_v_12_1 = (sec_r001677_1_1 ^ pub_r001677_1_1) & 63;
  int stage_v_12_2 = (sec_r001677_1_2 ^ pub_r001677_1_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r001677_2_1 & 2) != 0)
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
    if ((sec_r001677_2_2 & 2) != 0)
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
  int stage_v_13_1 = (sec_r001677_20_1 ^ pub_r001677_1_1) & 63;
  int stage_v_13_2 = (sec_r001677_20_2 ^ pub_r001677_1_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
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
    if ((stage_v_0_2 & 2) != 0)
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
  int stage_v_14_1 = (sec_r001677_20_1 ^ pub_r001677_16_1) & 63;
  int stage_v_14_2 = (sec_r001677_20_2 ^ pub_r001677_16_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r001677_15_1 & 2) != 0)
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
    if ((sec_r001677_15_2 & 2) != 0)
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
  int stage_v_15_1 = (sec_r001677_17_1 ^ pub_r001677_9_1) & 63;
  int stage_v_15_2 = (sec_r001677_17_2 ^ pub_r001677_9_2) & 63;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r001677_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_15_1 * 2)) & 255;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r001677_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_15_2 * 2)) & 255;
  }
  int stage_v_16_1 = (helper_flow_5_1 ^ pub_r001677_10_1) & 63;
  int stage_v_16_2 = (helper_flow_5_2 ^ pub_r001677_10_2) & 63;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_16_1 * 2)) & 255;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((stage_v_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_16_2 * 2)) & 255;
  }
  int stage_v_17_1 = ((pub_r001677_13_1 * 2) + 38) & 63;
  int stage_v_17_2 = ((pub_r001677_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001677_6_1 * 2) + 17) & 63;
  int stage_v_18_2 = ((pub_r001677_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (stage_v_3_1 ^ pub_r001677_3_1) & 63;
  int stage_v_19_2 = (stage_v_3_2 ^ pub_r001677_3_2) & 63;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r001677_12_1 & 2) != 0)
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
    if ((sec_r001677_12_2 & 2) != 0)
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
  int stage_v_20_1 = ((pub_r001677_15_1 * 2) + 48) & 63;
  int stage_v_20_2 = ((pub_r001677_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (sec_r001677_10_1 ^ pub_r001677_5_1) & 63;
  int stage_v_21_2 = (sec_r001677_10_2 ^ pub_r001677_5_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r001677_13_1 & 2) != 0)
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
    if ((sec_r001677_13_2 & 2) != 0)
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
  int stage_v_22_1 = (sec_r001677_11_1 ^ pub_r001677_9_1) & 63;
  int stage_v_22_2 = (sec_r001677_11_2 ^ pub_r001677_9_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
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
    if ((stage_v_0_2 & 2) != 0)
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
  int stage_v_23_1 = (stage_v_0_1 ^ pub_r001677_15_1) & 63;
  int stage_v_23_2 = (stage_v_0_2 ^ pub_r001677_15_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
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
    if ((helper_flow_0_2 & 2) != 0)
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
  int stage_v_24_1 = (stage_v_19_1 ^ pub_r001677_6_1) & 63;
  int stage_v_24_2 = (stage_v_19_2 ^ pub_r001677_6_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
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
    if ((helper_flow_1_2 & 2) != 0)
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
  int stage_v_25_1 = (sec_r001677_20_1 ^ pub_r001677_4_1) & 63;
  int stage_v_25_2 = (sec_r001677_20_2 ^ pub_r001677_4_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
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
    if ((stage_v_3_2 & 2) != 0)
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
  int stage_v_26_1 = ((pub_r001677_6_1 * 2) + 27) & 63;
  int stage_v_26_2 = ((pub_r001677_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001677_9_1 * 2) + 47) & 63;
  int stage_v_27_2 = ((pub_r001677_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (stage_v_22_1 ^ pub_r001677_0_1) & 63;
  int stage_v_28_2 = (stage_v_22_2 ^ pub_r001677_0_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
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
    if ((stage_v_3_2 & 2) != 0)
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
  int stage_v_29_1 = (helper_flow_0_1 ^ pub_r001677_14_1) & 63;
  int stage_v_29_2 = (helper_flow_0_2 ^ pub_r001677_14_2) & 63;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r001677_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_29_1 * 2)) & 255;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r001677_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_29_2 * 2)) & 255;
  }
  int stage_v_30_1 = (sec_r001677_21_1 ^ pub_r001677_1_1) & 63;
  int stage_v_30_2 = (sec_r001677_21_2 ^ pub_r001677_1_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
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
    if ((helper_flow_6_2 & 2) != 0)
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
  int stage_v_31_1 = ((pub_r001677_3_1 * 2) + 5) & 63;
  int stage_v_31_2 = ((pub_r001677_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (sec_r001677_1_1 ^ pub_r001677_16_1) & 63;
  int stage_v_32_2 = (sec_r001677_1_2 ^ pub_r001677_16_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r001677_18_1 & 2) != 0)
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
    if ((sec_r001677_18_2 & 2) != 0)
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
  int stage_v_33_1 = ((pub_r001677_0_1 * 2) + 11) & 63;
  int stage_v_33_2 = ((pub_r001677_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (stage_v_8_1 ^ pub_r001677_14_1) & 63;
  int stage_v_34_2 = (stage_v_8_2 ^ pub_r001677_14_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
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
    if ((stage_v_16_2 & 2) != 0)
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
  int stage_v_35_1 = ((pub_r001677_9_1 * 2) + 40) & 63;
  int stage_v_35_2 = ((pub_r001677_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (stage_v_32_1 ^ pub_r001677_0_1) & 63;
  int stage_v_36_2 = (stage_v_32_2 ^ pub_r001677_0_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_37_1 = (stage_v_24_1 ^ pub_r001677_4_1) & 63;
  int stage_v_37_2 = (stage_v_24_2 ^ pub_r001677_4_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_37_1 * 2)) & 255;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_37_2 * 2)) & 255;
  }
  int stage_v_38_1 = (sec_r001677_19_1 ^ pub_r001677_12_1) & 63;
  int stage_v_38_2 = (sec_r001677_19_2 ^ pub_r001677_12_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r001677_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_38_1 * 2)) & 255;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r001677_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_38_2 * 2)) & 255;
  }
  int stage_v_39_1 = (stage_v_22_1 ^ pub_r001677_7_1) & 63;
  int stage_v_39_2 = (stage_v_22_2 ^ pub_r001677_7_2) & 63;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r001677_13_1 & 2) != 0)
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
    if ((sec_r001677_13_2 & 2) != 0)
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
  int stage_v_40_1 = ((pub_r001677_9_1 * 2) + 25) & 63;
  int stage_v_40_2 = ((pub_r001677_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001677_5_1 * 2) + 20) & 63;
  int stage_v_41_2 = ((pub_r001677_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001677_10_1 * 2) + 30) & 63;
  int stage_v_42_2 = ((pub_r001677_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (stage_v_14_1 ^ pub_r001677_16_1) & 63;
  int stage_v_43_2 = (stage_v_14_2 ^ pub_r001677_16_2) & 63;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r001677_4_1 & 2) != 0)
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
    if ((sec_r001677_4_2 & 2) != 0)
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
  int stage_v_44_1 = (stage_v_22_1 ^ pub_r001677_11_1) & 63;
  int stage_v_44_2 = (stage_v_22_2 ^ pub_r001677_11_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
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
    if ((stage_v_3_2 & 2) != 0)
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
  int stage_v_45_1 = ((pub_r001677_6_1 * 2) + 14) & 63;
  int stage_v_45_2 = ((pub_r001677_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (sec_r001677_16_1 ^ pub_r001677_5_1) & 63;
  int stage_v_46_2 = (sec_r001677_16_2 ^ pub_r001677_5_2) & 63;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((stage_v_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_46_1 * 2)) & 255;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((stage_v_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_46_2 * 2)) & 255;
  }
  int stage_v_47_1 = ((pub_r001677_0_1 * 2) + 23) & 63;
  int stage_v_47_2 = ((pub_r001677_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (stage_v_12_1 ^ pub_r001677_8_1) & 63;
  int stage_v_48_2 = (stage_v_12_2 ^ pub_r001677_8_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r001677_1_1 & 2) != 0)
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
    if ((sec_r001677_1_2 & 2) != 0)
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
  int stage_v_49_1 = ((pub_r001677_11_1 * 2) + 34) & 63;
  int stage_v_49_2 = ((pub_r001677_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (sec_r001677_2_1 ^ pub_r001677_12_1) & 63;
  int stage_v_50_2 = (sec_r001677_2_2 ^ pub_r001677_12_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r001677_10_1 & 2) != 0)
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
    if ((sec_r001677_10_2 & 2) != 0)
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
  int stage_v_51_1 = ((pub_r001677_8_1 * 2) + 46) & 63;
  int stage_v_51_2 = ((pub_r001677_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001677_2_1 * 2) + 18) & 63;
  int stage_v_52_2 = ((pub_r001677_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (sec_r001677_8_1 ^ pub_r001677_10_1) & 63;
  int stage_v_53_2 = (sec_r001677_8_2 ^ pub_r001677_10_2) & 63;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_54_1 = (stage_v_15_1 ^ pub_r001677_11_1) & 63;
  int stage_v_54_2 = (stage_v_15_2 ^ pub_r001677_11_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((stage_v_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  }
  int stage_v_55_1 = (sec_r001677_12_1 ^ pub_r001677_0_1) & 63;
  int stage_v_55_2 = (sec_r001677_12_2 ^ pub_r001677_0_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((stage_v_30_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  }
  int stage_v_56_1 = (stage_v_16_1 ^ pub_r001677_1_1) & 63;
  int stage_v_56_2 = (stage_v_16_2 ^ pub_r001677_1_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r001677_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r001677_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  }
  int stage_v_57_1 = (stage_v_56_1 ^ pub_r001677_14_1) & 63;
  int stage_v_57_2 = (stage_v_56_2 ^ pub_r001677_14_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((stage_v_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  }
  int stage_v_58_1 = ((pub_r001677_2_1 * 2) + 42) & 63;
  int stage_v_58_2 = ((pub_r001677_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (sec_r001677_19_1 ^ pub_r001677_2_1) & 63;
  int stage_v_59_2 = (sec_r001677_19_2 ^ pub_r001677_2_2) & 63;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((stage_v_22_1 & 2) != 0)
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
    if ((stage_v_22_2 & 2) != 0)
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
  int stage_v_60_1 = ((pub_r001677_13_1 * 2) + 18) & 63;
  int stage_v_60_2 = ((pub_r001677_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (stage_v_55_1 ^ pub_r001677_1_1) & 63;
  int stage_v_61_2 = (stage_v_55_2 ^ pub_r001677_1_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  }
  int stage_v_62_1 = (sec_r001677_12_1 ^ pub_r001677_0_1) & 63;
  int stage_v_62_2 = (sec_r001677_12_2 ^ pub_r001677_0_2) & 63;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r001677_5_1 & 2) != 0)
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
    if ((sec_r001677_5_2 & 2) != 0)
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
  int stage_v_63_1 = ((pub_r001677_9_1 * 2) + 50) & 63;
  int stage_v_63_2 = ((pub_r001677_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (stage_v_44_1 ^ pub_r001677_5_1) & 63;
  int stage_v_64_2 = (stage_v_44_2 ^ pub_r001677_5_2) & 63;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r001677_10_1 & 2) != 0)
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
    if ((sec_r001677_10_2 & 2) != 0)
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
  int stage_v_65_1 = (stage_v_44_1 ^ pub_r001677_15_1) & 63;
  int stage_v_65_2 = (stage_v_44_2 ^ pub_r001677_15_2) & 63;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((stage_v_56_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((stage_v_56_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  }
  int stage_v_66_1 = (sec_r001677_8_1 ^ pub_r001677_2_1) & 63;
  int stage_v_66_2 = (sec_r001677_8_2 ^ pub_r001677_2_2) & 63;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((stage_v_34_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  }
  int stage_v_67_1 = (sec_r001677_19_1 ^ pub_r001677_15_1) & 63;
  int stage_v_67_2 = (sec_r001677_19_2 ^ pub_r001677_15_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r001677_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r001677_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  }
  int stage_v_68_1 = (sec_r001677_6_1 ^ pub_r001677_11_1) & 63;
  int stage_v_68_2 = (sec_r001677_6_2 ^ pub_r001677_11_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((stage_v_43_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((stage_v_43_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  }
  int stage_v_69_1 = (sec_r001677_5_1 ^ pub_r001677_0_1) & 63;
  int stage_v_69_2 = (sec_r001677_5_2 ^ pub_r001677_0_2) & 63;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((stage_v_50_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((stage_v_50_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  }
  int stage_v_70_1 = (sec_r001677_9_1 ^ pub_r001677_12_1) & 63;
  int stage_v_70_2 = (sec_r001677_9_2 ^ pub_r001677_12_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((stage_v_65_1 & 2) != 0)
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
    if ((stage_v_65_2 & 2) != 0)
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
  int stage_v_71_1 = (stage_v_6_1 ^ pub_r001677_3_1) & 63;
  int stage_v_71_2 = (stage_v_6_2 ^ pub_r001677_3_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r001677_15_1 & 2) != 0)
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
    if ((sec_r001677_15_2 & 2) != 0)
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
  int stage_v_72_1 = (stage_v_19_1 ^ pub_r001677_15_1) & 63;
  int stage_v_72_2 = (stage_v_19_2 ^ pub_r001677_15_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((stage_v_64_1 & 2) != 0)
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
    if ((stage_v_64_2 & 2) != 0)
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
  int stage_v_73_1 = (sec_r001677_14_1 ^ pub_r001677_9_1) & 63;
  int stage_v_73_2 = (sec_r001677_14_2 ^ pub_r001677_9_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((stage_v_48_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  }
  int stage_v_74_1 = ((pub_r001677_12_1 * 2) + 10) & 63;
  int stage_v_74_2 = ((pub_r001677_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (sec_r001677_13_1 ^ pub_r001677_7_1) & 63;
  int stage_v_75_2 = (sec_r001677_13_2 ^ pub_r001677_7_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r001677_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r001677_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  }
  int stage_v_76_1 = (stage_v_16_1 ^ pub_r001677_7_1) & 63;
  int stage_v_76_2 = (stage_v_16_2 ^ pub_r001677_7_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
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
    if ((stage_v_34_2 & 2) != 0)
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
  int stage_v_77_1 = (stage_v_30_1 ^ pub_r001677_11_1) & 63;
  int stage_v_77_2 = (stage_v_30_2 ^ pub_r001677_11_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_53_1 & 2) != 0)
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
    if ((stage_v_53_2 & 2) != 0)
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
  int stage_v_78_1 = ((pub_r001677_4_1 * 2) + 21) & 63;
  int stage_v_78_2 = ((pub_r001677_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (stage_v_34_1 ^ pub_r001677_0_1) & 63;
  int stage_v_79_2 = (stage_v_34_2 ^ pub_r001677_0_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r001677_8_1 & 2) != 0)
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
    if ((sec_r001677_8_2 & 2) != 0)
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
  int stage_v_80_1 = (stage_v_24_1 ^ pub_r001677_3_1) & 63;
  int stage_v_80_2 = (stage_v_24_2 ^ pub_r001677_3_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r001677_2_1 & 2) != 0)
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
    if ((sec_r001677_2_2 & 2) != 0)
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
  int stage_v_81_1 = (stage_v_53_1 ^ pub_r001677_10_1) & 63;
  int stage_v_81_2 = (stage_v_53_2 ^ pub_r001677_10_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((stage_v_39_1 & 2) != 0)
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
    if ((stage_v_39_2 & 2) != 0)
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
  int stage_v_82_1 = (stage_v_3_1 ^ pub_r001677_10_1) & 63;
  int stage_v_82_2 = (stage_v_3_2 ^ pub_r001677_10_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
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
    if ((stage_v_34_2 & 2) != 0)
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
  int stage_v_83_1 = (sec_r001677_12_1 ^ pub_r001677_10_1) & 63;
  int stage_v_83_2 = (sec_r001677_12_2 ^ pub_r001677_10_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r001677_18_1 & 2) != 0)
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
    if ((sec_r001677_18_2 & 2) != 0)
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
  int stage_v_84_1 = ((pub_r001677_2_1 * 2) + 34) & 63;
  int stage_v_84_2 = ((pub_r001677_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001677_14_1 * 2) + 27) & 63;
  int stage_v_85_2 = ((pub_r001677_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (sec_r001677_5_1 ^ pub_r001677_5_1) & 63;
  int stage_v_86_2 = (sec_r001677_5_2 ^ pub_r001677_5_2) & 63;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r001677_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r001677_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  }
  int stage_v_87_1 = ((pub_r001677_5_1 * 2) + 14) & 63;
  int stage_v_87_2 = ((pub_r001677_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (sec_r001677_14_1 ^ pub_r001677_15_1) & 63;
  int stage_v_88_2 = (sec_r001677_14_2 ^ pub_r001677_15_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  }
  int stage_v_89_1 = ((pub_r001677_11_1 * 2) + 43) & 63;
  int stage_v_89_2 = ((pub_r001677_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001677_5_1 * 2) + 46) & 63;
  int stage_v_90_2 = ((pub_r001677_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (stage_v_36_1 ^ pub_r001677_16_1) & 63;
  int stage_v_91_2 = (stage_v_36_2 ^ pub_r001677_16_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r001677_15_1 & 2) != 0)
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
    if ((sec_r001677_15_2 & 2) != 0)
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
  int stage_v_92_1 = (stage_v_28_1 ^ pub_r001677_9_1) & 63;
  int stage_v_92_2 = (stage_v_28_2 ^ pub_r001677_9_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r001677_21_1 & 2) != 0)
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
    if ((sec_r001677_21_2 & 2) != 0)
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
  int stage_v_93_1 = (stage_v_50_1 ^ pub_r001677_0_1) & 63;
  int stage_v_93_2 = (stage_v_50_2 ^ pub_r001677_0_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
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
    if ((helper_flow_1_2 & 2) != 0)
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
  int stage_v_94_1 = ((pub_r001677_2_1 * 2) + 46) & 63;
  int stage_v_94_2 = ((pub_r001677_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (stage_v_24_1 ^ pub_r001677_1_1) & 63;
  int stage_v_95_2 = (stage_v_24_2 ^ pub_r001677_1_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
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
    if ((stage_v_46_2 & 2) != 0)
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
  int stage_v_96_1 = (stage_v_15_1 ^ pub_r001677_1_1) & 63;
  int stage_v_96_2 = (stage_v_15_2 ^ pub_r001677_1_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
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
    if ((stage_v_80_2 & 2) != 0)
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
  int stage_v_97_1 = (stage_v_11_1 ^ pub_r001677_11_1) & 63;
  int stage_v_97_2 = (stage_v_11_2 ^ pub_r001677_11_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((stage_v_96_1 & 2) != 0)
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
    if ((stage_v_96_2 & 2) != 0)
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
  int stage_v_98_1 = ((pub_r001677_4_1 * 2) + 33) & 63;
  int stage_v_98_2 = ((pub_r001677_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001677_9_1 * 2) + 14) & 63;
  int stage_v_99_2 = ((pub_r001677_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001677_14_1 * 2) + 44) & 63;
  int stage_v_100_2 = ((pub_r001677_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (sec_r001677_8_1 ^ pub_r001677_10_1) & 63;
  int stage_v_101_2 = (sec_r001677_8_2 ^ pub_r001677_10_2) & 63;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_102_1 = ((pub_r001677_3_1 * 2) + 13) & 63;
  int stage_v_102_2 = ((pub_r001677_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (stage_v_66_1 ^ pub_r001677_7_1) & 63;
  int stage_v_103_2 = (stage_v_66_2 ^ pub_r001677_7_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
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
    if ((stage_v_72_2 & 2) != 0)
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
  int stage_v_104_1 = (stage_v_24_1 ^ pub_r001677_2_1) & 63;
  int stage_v_104_2 = (stage_v_24_2 ^ pub_r001677_2_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((stage_v_88_1 & 2) != 0)
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
    if ((stage_v_88_2 & 2) != 0)
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
  int stage_v_105_1 = ((pub_r001677_2_1 * 2) + 19) & 63;
  int stage_v_105_2 = ((pub_r001677_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (stage_v_13_1 ^ pub_r001677_16_1) & 63;
  int stage_v_106_2 = (stage_v_13_2 ^ pub_r001677_16_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((stage_v_101_1 & 2) != 0)
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
    if ((stage_v_101_2 & 2) != 0)
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
  int stage_v_107_1 = ((pub_r001677_7_1 * 2) + 19) & 63;
  int stage_v_107_2 = ((pub_r001677_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001677_11_1 * 2) + 11) & 63;
  int stage_v_108_2 = ((pub_r001677_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (sec_r001677_11_1 ^ pub_r001677_3_1) & 63;
  int stage_v_109_2 = (sec_r001677_11_2 ^ pub_r001677_3_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r001677_11_1 & 2) != 0)
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
    if ((sec_r001677_11_2 & 2) != 0)
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
  int stage_v_110_1 = (stage_v_81_1 ^ pub_r001677_1_1) & 63;
  int stage_v_110_2 = (stage_v_81_2 ^ pub_r001677_1_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r001677_14_1 & 2) != 0)
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
    if ((sec_r001677_14_2 & 2) != 0)
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
  int stage_v_111_1 = ((pub_r001677_12_1 * 2) + 19) & 63;
  int stage_v_111_2 = ((pub_r001677_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (stage_v_68_1 ^ pub_r001677_3_1) & 63;
  int stage_v_112_2 = (stage_v_68_2 ^ pub_r001677_3_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_91_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((stage_v_91_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  }
  int stage_v_113_1 = (stage_v_0_1 ^ pub_r001677_3_1) & 63;
  int stage_v_113_2 = (stage_v_0_2 ^ pub_r001677_3_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
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
    if ((stage_v_11_2 & 2) != 0)
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
  int stage_v_114_1 = ((pub_r001677_0_1 * 2) + 37) & 63;
  int stage_v_114_2 = ((pub_r001677_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001677_10_1 * 2) + 37) & 63;
  int stage_v_115_2 = ((pub_r001677_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001677_8_1 * 2) + 33) & 63;
  int stage_v_116_2 = ((pub_r001677_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001677_7_1 * 2) + 34) & 63;
  int stage_v_117_2 = ((pub_r001677_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (sec_r001677_5_1 ^ pub_r001677_2_1) & 63;
  int stage_v_118_2 = (sec_r001677_5_2 ^ pub_r001677_2_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_69_1 & 2) != 0)
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
    if ((stage_v_69_2 & 2) != 0)
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
  int stage_v_119_1 = ((pub_r001677_8_1 * 2) + 18) & 63;
  int stage_v_119_2 = ((pub_r001677_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (stage_v_65_1 ^ pub_r001677_5_1) & 63;
  int stage_v_120_2 = (stage_v_65_2 ^ pub_r001677_5_2) & 63;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r001677_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r001677_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  }
  int stage_v_121_1 = ((pub_r001677_4_1 * 2) + 37) & 63;
  int stage_v_121_2 = ((pub_r001677_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001677_3_1 * 2) + 10) & 63;
  int stage_v_122_2 = ((pub_r001677_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (stage_v_14_1 ^ pub_r001677_4_1) & 63;
  int stage_v_123_2 = (stage_v_14_2 ^ pub_r001677_4_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r001677_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r001677_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  }
  int stage_v_124_1 = (stage_v_54_1 ^ pub_r001677_15_1) & 63;
  int stage_v_124_2 = (stage_v_54_2 ^ pub_r001677_15_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  }
  int stage_v_125_1 = (sec_r001677_17_1 ^ pub_r001677_4_1) & 63;
  int stage_v_125_2 = (sec_r001677_17_2 ^ pub_r001677_4_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_124_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((stage_v_124_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  }
  int stage_v_126_1 = ((pub_r001677_5_1 * 2) + 47) & 63;
  int stage_v_126_2 = ((pub_r001677_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001677_4_1 * 2) + 45) & 63;
  int stage_v_127_2 = ((pub_r001677_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001677_3_1 * 2) + 34) & 63;
  int stage_v_128_2 = ((pub_r001677_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (stage_v_66_1 ^ pub_r001677_8_1) & 63;
  int stage_v_129_2 = (stage_v_66_2 ^ pub_r001677_8_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((sec_r001677_4_1 & 2) != 0)
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
    if ((sec_r001677_4_2 & 2) != 0)
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
  int stage_v_130_1 = (sec_r001677_9_1 ^ pub_r001677_11_1) & 63;
  int stage_v_130_2 = (sec_r001677_9_2 ^ pub_r001677_11_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((stage_v_76_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((stage_v_76_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  }
  int stage_v_131_1 = ((pub_r001677_14_1 * 2) + 42) & 63;
  int stage_v_131_2 = ((pub_r001677_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (stage_v_3_1 ^ pub_r001677_8_1) & 63;
  int stage_v_132_2 = (stage_v_3_2 ^ pub_r001677_8_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_92_1 & 2) != 0)
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
    if ((stage_v_92_2 & 2) != 0)
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
  int stage_v_133_1 = (helper_flow_4_1 ^ pub_r001677_3_1) & 63;
  int stage_v_133_2 = (helper_flow_4_2 ^ pub_r001677_3_2) & 63;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((stage_v_75_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((stage_v_75_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  }
  int stage_v_134_1 = ((pub_r001677_5_1 * 2) + 31) & 63;
  int stage_v_134_2 = ((pub_r001677_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (stage_v_110_1 ^ pub_r001677_12_1) & 63;
  int stage_v_135_2 = (stage_v_110_2 ^ pub_r001677_12_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_91_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  }
  if ((stage_v_135_2 & 1) != 0)
  {
    if ((stage_v_91_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  }
  int stage_v_136_1 = (stage_v_120_1 ^ pub_r001677_5_1) & 63;
  int stage_v_136_2 = (stage_v_120_2 ^ pub_r001677_5_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((stage_v_95_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((stage_v_95_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  }
  int stage_v_137_1 = (stage_v_50_1 ^ pub_r001677_11_1) & 63;
  int stage_v_137_2 = (stage_v_50_2 ^ pub_r001677_11_2) & 63;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((stage_v_83_1 & 2) != 0)
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
    if ((stage_v_83_2 & 2) != 0)
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
  int stage_v_138_1 = (stage_v_96_1 ^ pub_r001677_2_1) & 63;
  int stage_v_138_2 = (stage_v_96_2 ^ pub_r001677_2_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((stage_v_15_1 & 2) != 0)
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
    if ((stage_v_15_2 & 2) != 0)
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
  int stage_v_139_1 = ((pub_r001677_11_1 * 2) + 14) & 63;
  int stage_v_139_2 = ((pub_r001677_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (helper_flow_3_1 ^ pub_r001677_0_1) & 63;
  int stage_v_140_2 = (helper_flow_3_2 ^ pub_r001677_0_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
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
    if ((stage_v_72_2 & 2) != 0)
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
  int stage_v_141_1 = ((pub_r001677_4_1 * 2) + 30) & 63;
  int stage_v_141_2 = ((pub_r001677_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (stage_v_14_1 ^ pub_r001677_5_1) & 63;
  int stage_v_142_2 = (stage_v_14_2 ^ pub_r001677_5_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
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
    if ((stage_v_80_2 & 2) != 0)
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
  int stage_v_143_1 = ((pub_r001677_7_1 * 2) + 14) & 63;
  int stage_v_143_2 = ((pub_r001677_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (stage_v_132_1 ^ pub_r001677_13_1) & 63;
  int stage_v_144_2 = (stage_v_132_2 ^ pub_r001677_13_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((stage_v_36_1 & 2) != 0)
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
    if ((stage_v_36_2 & 2) != 0)
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
  int stage_v_145_1 = (stage_v_2_1 ^ pub_r001677_10_1) & 63;
  int stage_v_145_2 = (stage_v_2_2 ^ pub_r001677_10_2) & 63;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((stage_v_120_1 & 2) != 0)
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
    if ((stage_v_120_2 & 2) != 0)
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
  int stage_v_146_1 = (helper_flow_0_1 ^ pub_r001677_15_1) & 63;
  int stage_v_146_2 = (helper_flow_0_2 ^ pub_r001677_15_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
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
    if ((stage_v_62_2 & 2) != 0)
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
  int stage_v_147_1 = (stage_v_22_1 ^ pub_r001677_7_1) & 63;
  int stage_v_147_2 = (stage_v_22_2 ^ pub_r001677_7_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_86_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  }
  if ((stage_v_147_2 & 1) != 0)
  {
    if ((stage_v_86_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  }
  int stage_v_148_1 = (sec_r001677_7_1 ^ pub_r001677_2_1) & 63;
  int stage_v_148_2 = (sec_r001677_7_2 ^ pub_r001677_2_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_133_1 & 2) != 0)
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
    if ((stage_v_133_2 & 2) != 0)
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
  int stage_v_149_1 = (sec_r001677_10_1 ^ pub_r001677_8_1) & 63;
  int stage_v_149_2 = (sec_r001677_10_2 ^ pub_r001677_8_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((sec_r001677_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  }
  if ((stage_v_149_2 & 1) != 0)
  {
    if ((sec_r001677_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  }
  int stage_v_150_1 = (stage_v_133_1 ^ pub_r001677_8_1) & 63;
  int stage_v_150_2 = (stage_v_133_2 ^ pub_r001677_8_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
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
    if ((stage_v_80_2 & 2) != 0)
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
  int stage_v_151_1 = (stage_v_8_1 ^ pub_r001677_0_1) & 63;
  int stage_v_151_2 = (stage_v_8_2 ^ pub_r001677_0_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_152_1 = (stage_v_34_1 ^ pub_r001677_13_1) & 63;
  int stage_v_152_2 = (stage_v_34_2 ^ pub_r001677_13_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
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
    if ((stage_v_32_2 & 2) != 0)
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
  int stage_v_153_1 = ((pub_r001677_16_1 * 2) + 25) & 63;
  int stage_v_153_2 = ((pub_r001677_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (stage_v_91_1 ^ pub_r001677_3_1) & 63;
  int stage_v_154_2 = (stage_v_91_2 ^ pub_r001677_3_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_81_1 & 2) != 0)
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
    if ((stage_v_81_2 & 2) != 0)
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
  int stage_v_155_1 = (sec_r001677_12_1 ^ pub_r001677_14_1) & 63;
  int stage_v_155_2 = (sec_r001677_12_2 ^ pub_r001677_14_2) & 63;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((sec_r001677_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  }
  if ((stage_v_155_2 & 1) != 0)
  {
    if ((sec_r001677_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  }
  int stage_v_156_1 = (stage_v_96_1 ^ pub_r001677_11_1) & 63;
  int stage_v_156_2 = (stage_v_96_2 ^ pub_r001677_11_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_124_1 & 2) != 0)
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
    if ((stage_v_124_2 & 2) != 0)
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
  int stage_v_157_1 = (stage_v_50_1 ^ pub_r001677_4_1) & 63;
  int stage_v_157_2 = (stage_v_50_2 ^ pub_r001677_4_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((sec_r001677_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  }
  if ((stage_v_157_2 & 1) != 0)
  {
    if ((sec_r001677_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  }
  int stage_v_158_1 = (stage_v_152_1 ^ pub_r001677_6_1) & 63;
  int stage_v_158_2 = (stage_v_152_2 ^ pub_r001677_6_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  }
  if ((stage_v_158_2 & 1) != 0)
  {
    if ((stage_v_80_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  }
  int stage_v_159_1 = (stage_v_13_1 ^ pub_r001677_2_1) & 63;
  int stage_v_159_2 = (stage_v_13_2 ^ pub_r001677_2_2) & 63;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  }
  if ((stage_v_159_2 & 1) != 0)
  {
    if ((stage_v_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  }
  int stage_v_160_1 = (stage_v_21_1 ^ pub_r001677_0_1) & 63;
  int stage_v_160_2 = (stage_v_21_2 ^ pub_r001677_0_2) & 63;
  if ((stage_v_160_1 & 1) != 0)
  {
    if ((stage_v_123_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  }
  if ((stage_v_160_2 & 1) != 0)
  {
    if ((stage_v_123_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  }
  int stage_v_161_1 = (stage_v_129_1 ^ pub_r001677_2_1) & 63;
  int stage_v_161_2 = (stage_v_129_2 ^ pub_r001677_2_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((sec_r001677_16_1 & 2) != 0)
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
    if ((sec_r001677_16_2 & 2) != 0)
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
  int stage_v_162_1 = ((pub_r001677_10_1 * 2) + 31) & 63;
  int stage_v_162_2 = ((pub_r001677_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (sec_r001677_8_1 ^ pub_r001677_8_1) & 63;
  int stage_v_163_2 = (sec_r001677_8_2 ^ pub_r001677_8_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_149_1 & 2) != 0)
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
    if ((stage_v_149_2 & 2) != 0)
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
  int stage_v_164_1 = (stage_v_163_1 ^ pub_r001677_12_1) & 63;
  int stage_v_164_2 = (stage_v_163_2 ^ pub_r001677_12_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((stage_v_132_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  }
  if ((stage_v_164_2 & 1) != 0)
  {
    if ((stage_v_132_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  }
  int stage_v_165_1 = (stage_v_7_1 ^ pub_r001677_0_1) & 63;
  int stage_v_165_2 = (stage_v_7_2 ^ pub_r001677_0_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_22_1 & 2) != 0)
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
    if ((stage_v_22_2 & 2) != 0)
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
  int stage_v_166_1 = (stage_v_152_1 ^ pub_r001677_9_1) & 63;
  int stage_v_166_2 = (stage_v_152_2 ^ pub_r001677_9_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((stage_v_152_1 & 2) != 0)
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
    if ((stage_v_152_2 & 2) != 0)
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
  int stage_v_167_1 = (stage_v_164_1 ^ pub_r001677_15_1) & 63;
  int stage_v_167_2 = (stage_v_164_2 ^ pub_r001677_15_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_168_1 = (sec_r001677_4_1 ^ pub_r001677_8_1) & 63;
  int stage_v_168_2 = (sec_r001677_4_2 ^ pub_r001677_8_2) & 63;
  if ((stage_v_168_1 & 1) != 0)
  {
    if ((stage_v_147_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  }
  if ((stage_v_168_2 & 1) != 0)
  {
    if ((stage_v_147_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  }
  int stage_v_169_1 = (stage_v_136_1 ^ pub_r001677_9_1) & 63;
  int stage_v_169_2 = (stage_v_136_2 ^ pub_r001677_9_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  }
  if ((stage_v_169_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  }
  int stage_v_170_1 = ((pub_r001677_10_1 * 2) + 5) & 63;
  int stage_v_170_2 = ((pub_r001677_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (stage_v_160_1 ^ pub_r001677_7_1) & 63;
  int stage_v_171_2 = (stage_v_160_2 ^ pub_r001677_7_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((stage_v_142_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_171_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  }
  if ((stage_v_171_2 & 1) != 0)
  {
    if ((stage_v_142_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_171_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  }
  int stage_v_172_1 = (stage_v_155_1 ^ pub_r001677_7_1) & 63;
  int stage_v_172_2 = (stage_v_155_2 ^ pub_r001677_7_2) & 63;
  if ((stage_v_172_1 & 1) != 0)
  {
    if ((stage_v_129_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  }
  if ((stage_v_172_2 & 1) != 0)
  {
    if ((stage_v_129_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  }
  int stage_v_173_1 = (stage_v_37_1 ^ pub_r001677_4_1) & 63;
  int stage_v_173_2 = (stage_v_37_2 ^ pub_r001677_4_2) & 63;
  if ((stage_v_173_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_174_1 = ((pub_r001677_15_1 * 2) + 16) & 63;
  int stage_v_174_2 = ((pub_r001677_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (sec_r001677_17_1 ^ pub_r001677_13_1) & 63;
  int stage_v_175_2 = (sec_r001677_17_2 ^ pub_r001677_13_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_67_1 & 2) != 0)
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
    if ((stage_v_67_2 & 2) != 0)
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
  int stage_v_176_1 = ((pub_r001677_14_1 * 2) + 27) & 63;
  int stage_v_176_2 = ((pub_r001677_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (stage_v_160_1 ^ pub_r001677_4_1) & 63;
  int stage_v_177_2 = (stage_v_160_2 ^ pub_r001677_4_2) & 63;
  if ((stage_v_177_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
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
    if ((stage_v_72_2 & 2) != 0)
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
  int stage_v_178_1 = (stage_v_172_1 ^ pub_r001677_5_1) & 63;
  int stage_v_178_2 = (stage_v_172_2 ^ pub_r001677_5_2) & 63;
  if ((stage_v_178_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
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
    if ((stage_v_66_2 & 2) != 0)
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
  int stage_v_179_1 = (stage_v_64_1 ^ pub_r001677_7_1) & 63;
  int stage_v_179_2 = (stage_v_64_2 ^ pub_r001677_7_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((stage_v_68_1 & 2) != 0)
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
    if ((stage_v_68_2 & 2) != 0)
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
  int stage_v_180_1 = (stage_v_77_1 ^ pub_r001677_5_1) & 63;
  int stage_v_180_2 = (stage_v_77_2 ^ pub_r001677_5_2) & 63;
  if ((stage_v_180_1 & 1) != 0)
  {
    if ((sec_r001677_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_180_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  }
  if ((stage_v_180_2 & 1) != 0)
  {
    if ((sec_r001677_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_180_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  }
  int stage_v_181_1 = ((pub_r001677_9_1 * 2) + 13) & 63;
  int stage_v_181_2 = ((pub_r001677_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001677_15_1 * 2) + 25) & 63;
  int stage_v_182_2 = ((pub_r001677_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (stage_v_142_1 ^ pub_r001677_12_1) & 63;
  int stage_v_183_2 = (stage_v_142_2 ^ pub_r001677_12_2) & 63;
  if ((stage_v_183_1 & 1) != 0)
  {
    if ((sec_r001677_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  }
  if ((stage_v_183_2 & 1) != 0)
  {
    if ((sec_r001677_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  }
  int stage_v_184_1 = ((pub_r001677_15_1 * 2) + 7) & 63;
  int stage_v_184_2 = ((pub_r001677_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (stage_v_180_1 ^ pub_r001677_3_1) & 63;
  int stage_v_185_2 = (stage_v_180_2 ^ pub_r001677_3_2) & 63;
  if ((stage_v_185_1 & 1) != 0)
  {
    if ((sec_r001677_3_1 & 2) != 0)
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
    if ((sec_r001677_3_2 & 2) != 0)
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
  int stage_v_186_1 = (sec_r001677_11_1 ^ pub_r001677_1_1) & 63;
  int stage_v_186_2 = (sec_r001677_11_2 ^ pub_r001677_1_2) & 63;
  if ((stage_v_186_1 & 1) != 0)
  {
    if ((stage_v_68_1 & 2) != 0)
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
    if ((stage_v_68_2 & 2) != 0)
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
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001677_0_1 != sec_r001677_0_2);
  __CPROVER_assume(pub_r001677_1_1 == pub_r001677_1_2);
  __CPROVER_assume(pub_r001677_2_1 == pub_r001677_2_2);
  __CPROVER_assume(sec_r001677_10_1 != sec_r001677_10_2);
  __CPROVER_assume(pub_r001677_12_1 == pub_r001677_12_2);
  __CPROVER_assume(sec_r001677_20_1 != sec_r001677_20_2);
  __CPROVER_assume(pub_r001677_6_1 == pub_r001677_6_2);
  __CPROVER_assume(pub_r001677_3_1 == pub_r001677_3_2);
  __CPROVER_assume(pub_r001677_16_1 == pub_r001677_16_2);
  __CPROVER_assume(sec_r001677_13_1 != sec_r001677_13_2);
  __CPROVER_assume(sec_r001677_5_1 != sec_r001677_5_2);
  __CPROVER_assume(sec_r001677_12_1 != sec_r001677_12_2);
  __CPROVER_assume(pub_r001677_13_1 == pub_r001677_13_2);
  __CPROVER_assume(sec_r001677_16_1 != sec_r001677_16_2);
  __CPROVER_assume(sec_r001677_4_1 != sec_r001677_4_2);
  __CPROVER_assume(pub_r001677_10_1 == pub_r001677_10_2);
  __CPROVER_assume(sec_r001677_8_1 != sec_r001677_8_2);
  __CPROVER_assume(sec_r001677_18_1 != sec_r001677_18_2);
  __CPROVER_assume(sec_r001677_19_1 != sec_r001677_19_2);
  __CPROVER_assume(pub_r001677_5_1 == pub_r001677_5_2);
  __CPROVER_assume(pub_r001677_4_1 == pub_r001677_4_2);
  __CPROVER_assume(pub_r001677_8_1 == pub_r001677_8_2);
  __CPROVER_assume(pub_r001677_14_1 == pub_r001677_14_2);
  __CPROVER_assume(sec_r001677_15_1 != sec_r001677_15_2);
  __CPROVER_assume(pub_r001677_15_1 == pub_r001677_15_2);
  __CPROVER_assume(sec_r001677_2_1 != sec_r001677_2_2);
  __CPROVER_assume(sec_r001677_11_1 != sec_r001677_11_2);
  __CPROVER_assume(sec_r001677_1_1 != sec_r001677_1_2);
  __CPROVER_assume(sec_r001677_3_1 != sec_r001677_3_2);
  __CPROVER_assume(sec_r001677_21_1 != sec_r001677_21_2);
  __CPROVER_assume(pub_r001677_9_1 == pub_r001677_9_2);
  __CPROVER_assume(pub_r001677_11_1 == pub_r001677_11_2);
  __CPROVER_assume(sec_r001677_9_1 != sec_r001677_9_2);
  __CPROVER_assume(sec_r001677_7_1 != sec_r001677_7_2);
  __CPROVER_assume(pub_r001677_7_1 == pub_r001677_7_2);
  __CPROVER_assume(sec_r001677_17_1 != sec_r001677_17_2);
  __CPROVER_assume(sec_r001677_14_1 != sec_r001677_14_2);
  __CPROVER_assume(sec_r001677_6_1 != sec_r001677_6_2);
  __CPROVER_assume(pub_r001677_0_1 == pub_r001677_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
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
}


