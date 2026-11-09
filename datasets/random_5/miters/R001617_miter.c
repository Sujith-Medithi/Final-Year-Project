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
struct Vector3D_R001617_1713_0
{
  int coord_y;
  short norm_sq;
  unsigned char heading;
  int pitch;
  int coord_x;
  int buffer[3];
};
struct Transaction_R001617_1713_1
{
  int account_id;
  int auth_code;
  unsigned char rate;
  int balance;
  int buffer[3];
};
union ColorPixel_R001617_1713_0
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
void fn_R001617_1713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_93_1 > 35)
  {
    acc_1 = ((acc_1 + (parity_93_1 * 2)) + 5) & 127;
    aux_1 ^= parity_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_93_2 > 35)
  {
    acc_2 = ((acc_2 + (parity_93_2 * 2)) + 5) & 127;
    aux_2 ^= parity_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_93_1 == parity_93_2);
}

int fn_R001617_1713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_93 > 35)
  {
    acc = ((acc + (parity_93 * 2)) + 5) & 127;
    aux ^= parity_93 & 15;
  }
  else
  {
    acc = ((acc - parity_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001617_1713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st_1 = {0};
  struct Transaction_R001617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int bound_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_80_1) & 63;
  aux_2 = (aux_2 + bound_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_34_1 = local_arr_1[aux_1 % 3];
  int factor_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_34_2 * 2)) & 127;
  int bound_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_48_1)
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

  switch (bound_48_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_80_1 == bound_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_34_1 == factor_34_2);
  assert(bound_48_1 == bound_48_2);
}

int fn_R001617_1713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int bound_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_80) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_34 = local_arr[aux % 3];
  acc = (acc + (factor_34 * 2)) & 127;
  int bound_48 = (aux + st.buffer[1]) & 3;
  switch (bound_48)
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

void fn_R001617_1713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st_1 = {0};
  struct Transaction_R001617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int window_12_1 = 0;
  int window_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_12_1 = ((window_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_12_2 = ((window_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_12_1) & 127;
    acc_2 = (acc_2 + window_12_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_44_1 = local_arr_1[aux_1 % 3];
  int factor_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_44_2 * 2)) & 127;
  int quantum_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_85_1)
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

  switch (quantum_85_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_12_1 == window_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_44_1 == factor_44_2);
  assert(quantum_85_1 == quantum_85_2);
}

int fn_R001617_1713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int window_12 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_12 = ((window_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_12) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int factor_44 = local_arr[aux % 3];
  acc = (acc + (factor_44 * 2)) & 127;
  int quantum_85 = (aux + st.buffer[1]) & 3;
  switch (quantum_85)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001617_1713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st_1 = {0};
  struct Transaction_R001617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_47_1 = local_arr_1[aux_1 % 3];
  int coefficient_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_47_2 * 2)) & 127;
  int scale_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_54_1) & 63;
  aux_2 = (aux_2 + scale_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_47_1 == coefficient_47_2);
  assert(scale_54_1 == scale_54_2);
}

int fn_R001617_1713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int coefficient_47 = local_arr[aux % 3];
  acc = (acc + (coefficient_47 * 2)) & 127;
  int scale_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001617_1713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_32_1 > 11)
  {
    acc_1 = ((acc_1 + (checksum_32_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_32_2 > 11)
  {
    acc_2 = ((acc_2 + (checksum_32_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_32_1 == checksum_32_2);
}

int fn_R001617_1713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_32 > 11)
  {
    acc = ((acc + (checksum_32 * 2)) + 5) & 127;
    aux ^= checksum_32 & 15;
  }
  else
  {
    acc = ((acc - checksum_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001617_1713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int segment_39_1 = 0;
  int segment_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_39_1 = ((segment_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_39_2 = ((segment_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_39_1) & 127;
    acc_2 = (acc_2 + segment_39_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_74_1 = local_arr_1[aux_1 % 3];
  int anchor_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_39_1 == segment_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_74_1 == anchor_74_2);
}

int fn_R001617_1713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int segment_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_39 = ((segment_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_39) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_74 = local_arr[aux % 3];
  acc = (acc + (anchor_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001617_1713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st_1 = {0};
  struct Transaction_R001617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int margin_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_10_1)
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

  switch (margin_10_2)
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

  int checksum_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_64_1 > 34)
  {
    acc_1 = ((acc_1 + (checksum_64_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_64_2 > 34)
  {
    acc_2 = ((acc_2 + (checksum_64_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_26_1 = 0;
  int coefficient_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_26_1 = ((coefficient_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_26_2 = ((coefficient_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_26_1) & 127;
    acc_2 = (acc_2 + coefficient_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_10_1 == margin_10_2);
  assert(checksum_64_1 == checksum_64_2);
  assert(coefficient_26_1 == coefficient_26_2);
}

int fn_R001617_1713_6(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int margin_10 = (aux + st.buffer[1]) & 3;
  switch (margin_10)
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

  int checksum_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_64 > 34)
  {
    acc = ((acc + (checksum_64 * 2)) + 5) & 127;
    aux ^= checksum_64 & 15;
  }
  else
  {
    acc = ((acc - checksum_64) + 11) & 127;
    aux += 3;
  }
  int coefficient_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_26 = ((coefficient_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_26) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001617_1713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int threshold_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_88_1) & 63;
  aux_2 = (aux_2 + threshold_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_20_1)
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

  switch (anchor_20_2)
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

  int index_reg_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_59_1 > 48)
  {
    acc_1 = ((acc_1 + (index_reg_59_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_59_2 > 48)
  {
    acc_2 = ((acc_2 + (index_reg_59_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_88_1 == threshold_88_2);
  assert(anchor_20_1 == anchor_20_2);
  assert(index_reg_59_1 == index_reg_59_2);
}

int fn_R001617_1713_7(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int threshold_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_88) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_20 = (aux + st.buffer[1]) & 3;
  switch (anchor_20)
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

  int index_reg_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_59 > 48)
  {
    acc = ((acc + (index_reg_59 * 2)) + 5) & 127;
    aux ^= index_reg_59 & 15;
  }
  else
  {
    acc = ((acc - index_reg_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001617_1713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_74_1 = local_arr_1[aux_1 % 3];
  int coefficient_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_74_2 * 2)) & 127;
  int anchor_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_58_1)
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

  switch (anchor_58_2)
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

  int weight_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_97_1) & 63;
  aux_2 = (aux_2 + weight_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_74_1 == coefficient_74_2);
  assert(anchor_58_1 == anchor_58_2);
  assert(weight_97_1 == weight_97_2);
}

int fn_R001617_1713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int coefficient_74 = local_arr[aux % 3];
  acc = (acc + (coefficient_74 * 2)) & 127;
  int anchor_58 = (aux + st.buffer[1]) & 3;
  switch (anchor_58)
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

  int weight_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_97) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001617_1713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st_1 = {0};
  struct Transaction_R001617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quantum_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_61_1)
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

  switch (quantum_61_2)
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

  int stride_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_72_1) & 63;
  aux_2 = (aux_2 + stride_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_93_1 = local_arr_1[aux_1 % 3];
  int coefficient_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_93_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_61_1 == quantum_61_2);
  assert(stride_72_1 == stride_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_93_1 == coefficient_93_2);
}

int fn_R001617_1713_9(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quantum_61 = (aux + st.buffer[1]) & 3;
  switch (quantum_61)
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

  int stride_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_72) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_93 = local_arr[aux % 3];
  acc = (acc + (coefficient_93 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001617_1713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_46_1 = 0;
  int vector_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_46_1 = ((vector_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_46_2 = ((vector_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_46_1) & 127;
    acc_2 = (acc_2 + vector_46_2) & 127;
  }

  int metric_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_12_1)
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

  switch (metric_12_2)
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

  int tally_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_98_1) & 63;
  aux_2 = (aux_2 + tally_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_46_1 == vector_46_2);
  assert(metric_12_1 == metric_12_2);
  assert(tally_98_1 == tally_98_2);
}

int fn_R001617_1713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_46 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_46 = ((vector_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_46) & 127;
  }

  int metric_12 = (aux + st.buffer[1]) & 3;
  switch (metric_12)
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

  int tally_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001617_1713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st_1 = {0};
  struct Transaction_R001617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int checksum_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_87_1 > 45)
  {
    acc_1 = ((acc_1 + (checksum_87_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_87_2 > 45)
  {
    acc_2 = ((acc_2 + (checksum_87_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_87_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_87_1 == checksum_87_2);
}

int fn_R001617_1713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int checksum_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_87 > 45)
  {
    acc = ((acc + (checksum_87 * 2)) + 5) & 127;
    aux ^= checksum_87 & 15;
  }
  else
  {
    acc = ((acc - checksum_87) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001617_1713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int vector_53_1 = 0;
  int vector_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_53_1 = ((vector_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_53_2 = ((vector_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_53_1) & 127;
    acc_2 = (acc_2 + vector_53_2) & 127;
  }

  int pivot_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_45_1) & 63;
  aux_2 = (aux_2 + pivot_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_53_1 == vector_53_2);
  assert(pivot_45_1 == pivot_45_2);
}

int fn_R001617_1713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int vector_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_53 = ((vector_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_53) & 127;
  }

  int pivot_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001617_1713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int parity_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_97_1 > 16)
  {
    acc_1 = ((acc_1 + (parity_97_1 * 2)) + 5) & 127;
    aux_1 ^= parity_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_97_2 > 16)
  {
    acc_2 = ((acc_2 + (parity_97_2 * 2)) + 5) & 127;
    aux_2 ^= parity_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_50_1 = 0;
  int margin_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_50_1 = ((margin_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_50_2 = ((margin_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_50_1) & 127;
    acc_2 = (acc_2 + margin_50_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_90_1) & 63;
  aux_2 = (aux_2 + mask_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_97_1 == parity_97_2);
  assert(margin_50_1 == margin_50_2);
  assert(mask_90_1 == mask_90_2);
}

int fn_R001617_1713_13(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int parity_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_97 > 16)
  {
    acc = ((acc + (parity_97 * 2)) + 5) & 127;
    aux ^= parity_97 & 15;
  }
  else
  {
    acc = ((acc - parity_97) + 11) & 127;
    aux += 3;
  }
  int margin_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_50 = ((margin_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_50) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_90) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001617_1713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st_1 = {0};
  struct Transaction_R001617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_86_1 = local_arr_1[aux_1 % 3];
  int residue_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_86_2 * 2)) & 127;
  int offset_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_87_1 > 23)
  {
    acc_1 = ((acc_1 + (offset_87_1 * 2)) + 5) & 127;
    aux_1 ^= offset_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_87_2 > 23)
  {
    acc_2 = ((acc_2 + (offset_87_2 * 2)) + 5) & 127;
    aux_2 ^= offset_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_87_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_86_1 == residue_86_2);
  assert(offset_87_1 == offset_87_2);
}

int fn_R001617_1713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int residue_86 = local_arr[aux % 3];
  acc = (acc + (residue_86 * 2)) & 127;
  int offset_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_87 > 23)
  {
    acc = ((acc + (offset_87 * 2)) + 5) & 127;
    aux ^= offset_87 & 15;
  }
  else
  {
    acc = ((acc - offset_87) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001617_1713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st_1 = {0};
  struct Transaction_R001617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int quantum_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_37_1 > 46)
  {
    acc_1 = ((acc_1 + (quantum_37_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_37_2 > 46)
  {
    acc_2 = ((acc_2 + (quantum_37_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_34_1 = 0;
  int window_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_34_1 = ((window_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_34_2 = ((window_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_34_1) & 127;
    acc_2 = (acc_2 + window_34_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_37_1 == quantum_37_2);
  assert(window_34_1 == window_34_2);
}

int fn_R001617_1713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int quantum_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_37 > 46)
  {
    acc = ((acc + (quantum_37 * 2)) + 5) & 127;
    aux ^= quantum_37 & 15;
  }
  else
  {
    acc = ((acc - quantum_37) + 11) & 127;
    aux += 3;
  }
  int window_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_34 = ((window_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_34) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001617_1713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_70_1 = local_arr_1[aux_1 % 3];
  int bound_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_70_2 * 2)) & 127;
  int threshold_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_52_1)
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

  switch (threshold_52_2)
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

  int anchor_79_1 = 0;
  int anchor_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_79_1 = ((anchor_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_79_2 = ((anchor_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_79_1) & 127;
    acc_2 = (acc_2 + anchor_79_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_70_1 == bound_70_2);
  assert(threshold_52_1 == threshold_52_2);
  assert(anchor_79_1 == anchor_79_2);
}

int fn_R001617_1713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int bound_70 = local_arr[aux % 3];
  acc = (acc + (bound_70 * 2)) & 127;
  int threshold_52 = (aux + st.buffer[1]) & 3;
  switch (threshold_52)
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

  int anchor_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_79 = ((anchor_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_79) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001617_1713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int quotient_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_71_1) & 63;
  aux_2 = (aux_2 + quotient_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_97_1 > 44)
  {
    acc_1 = ((acc_1 + (tracker_97_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_97_2 > 44)
  {
    acc_2 = ((acc_2 + (tracker_97_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_17_1)
  {
    case 0:
      acc_1 = (acc_1 + 7) & 127;
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

  switch (scale_17_2)
  {
    case 0:
      acc_2 = (acc_2 + 7) & 127;
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_71_1 == quotient_71_2);
  assert(tracker_97_1 == tracker_97_2);
  assert(scale_17_1 == scale_17_2);
}

int fn_R001617_1713_17(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int quotient_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_71) & 63;
  acc ^= aux;
  int tracker_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_97 > 44)
  {
    acc = ((acc + (tracker_97 * 2)) + 5) & 127;
    aux ^= tracker_97 & 15;
  }
  else
  {
    acc = ((acc - tracker_97) + 11) & 127;
    aux += 3;
  }
  int scale_17 = (aux + st.buffer[1]) & 3;
  switch (scale_17)
  {
    case 0:
      acc = (acc + 7) & 127;
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

void fn_R001617_1713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int margin_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_92_1) & 63;
  aux_2 = (aux_2 + margin_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_24_1 = local_arr_1[aux_1 % 3];
  int scale_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_24_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_92_1 == margin_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_24_1 == scale_24_2);
}

int fn_R001617_1713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int margin_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_92) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_24 = local_arr[aux % 3];
  acc = (acc + (scale_24 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001617_1713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tally_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_92_1) & 63;
  aux_2 = (aux_2 + tally_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_10_1)
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

  switch (window_10_2)
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

  int checksum_29_1 = 0;
  int checksum_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_29_1 = ((checksum_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_29_2 = ((checksum_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_29_1) & 127;
    acc_2 = (acc_2 + checksum_29_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_92_1 = local_arr_1[aux_1 % 3];
  int phase_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_92_1 == tally_92_2);
  assert(window_10_1 == window_10_2);
  assert(checksum_29_1 == checksum_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_92_1 == phase_92_2);
}

int fn_R001617_1713_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tally_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_92) & 63;
  acc ^= aux;
  int window_10 = (aux + st.buffer[1]) & 3;
  switch (window_10)
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

  int checksum_29 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_29 = ((checksum_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_29) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_92 = local_arr[aux % 3];
  acc = (acc + (phase_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001617_1713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st_1 = {0};
  struct Vector3D_R001617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int sample_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_83_1) & 63;
  aux_2 = (aux_2 + sample_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_82_1 > 50)
  {
    acc_1 = ((acc_1 + (pivot_82_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_82_2 > 50)
  {
    acc_2 = ((acc_2 + (pivot_82_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_83_1 == sample_83_2);
  assert(pivot_82_1 == pivot_82_2);
}

int fn_R001617_1713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int sample_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_83) & 63;
  acc ^= aux;
  int pivot_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_82 > 50)
  {
    acc = ((acc + (pivot_82 * 2)) + 5) & 127;
    aux ^= pivot_82 & 15;
  }
  else
  {
    acc = ((acc - pivot_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001617_0_1;
  int sec_r001617_0_2;
  int sec_r001617_1_1;
  int sec_r001617_1_2;
  int sec_r001617_2_1;
  int sec_r001617_2_2;
  int sec_r001617_3_1;
  int sec_r001617_3_2;
  int sec_r001617_4_1;
  int sec_r001617_4_2;
  int sec_r001617_5_1;
  int sec_r001617_5_2;
  int sec_r001617_6_1;
  int sec_r001617_6_2;
  int sec_r001617_7_1;
  int sec_r001617_7_2;
  int sec_r001617_8_1;
  int sec_r001617_8_2;
  int sec_r001617_9_1;
  int sec_r001617_9_2;
  int sec_r001617_10_1;
  int sec_r001617_10_2;
  int sec_r001617_11_1;
  int sec_r001617_11_2;
  int sec_r001617_12_1;
  int sec_r001617_12_2;
  int sec_r001617_13_1;
  int sec_r001617_13_2;
  int sec_r001617_14_1;
  int sec_r001617_14_2;
  int sec_r001617_15_1;
  int sec_r001617_15_2;
  int sec_r001617_16_1;
  int sec_r001617_16_2;
  int sec_r001617_17_1;
  int sec_r001617_17_2;
  int sec_r001617_18_1;
  int sec_r001617_18_2;
  int sec_r001617_19_1;
  int sec_r001617_19_2;
  int sec_r001617_20_1;
  int sec_r001617_20_2;
  int sec_r001617_21_1;
  int sec_r001617_21_2;
  int sec_r001617_22_1;
  int sec_r001617_22_2;
  int sec_r001617_23_1;
  int sec_r001617_23_2;
  int pub_r001617_0_1;
  int pub_r001617_0_2;
  int pub_r001617_1_1;
  int pub_r001617_1_2;
  int pub_r001617_2_1;
  int pub_r001617_2_2;
  int pub_r001617_3_1;
  int pub_r001617_3_2;
  int pub_r001617_4_1;
  int pub_r001617_4_2;
  int pub_r001617_5_1;
  int pub_r001617_5_2;
  int pub_r001617_6_1;
  int pub_r001617_6_2;
  int pub_r001617_7_1;
  int pub_r001617_7_2;
  int pub_r001617_8_1;
  int pub_r001617_8_2;
  int pub_r001617_9_1;
  int pub_r001617_9_2;
  int pub_r001617_10_1;
  int pub_r001617_10_2;
  int pub_r001617_11_1;
  int pub_r001617_11_2;
  int pub_r001617_12_1;
  int pub_r001617_12_2;
  int pub_r001617_13_1;
  int pub_r001617_13_2;
  int pub_r001617_14_1;
  int pub_r001617_14_2;
  int pub_r001617_15_1;
  int pub_r001617_15_2;
  int pub_r001617_16_1;
  int pub_r001617_16_2;
  int pub_r001617_17_1;
  int pub_r001617_17_2;
  int pub_r001617_18_1;
  int pub_r001617_18_2;
  int pub_r001617_19_1;
  int pub_r001617_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001617_0_1 >= (-100)) && (pub_r001617_0_1 <= 100));
  __CPROVER_assume((pub_r001617_0_2 >= (-100)) && (pub_r001617_0_2 <= 100));
  __CPROVER_assume((pub_r001617_1_1 >= (-100)) && (pub_r001617_1_1 <= 100));
  __CPROVER_assume((pub_r001617_1_2 >= (-100)) && (pub_r001617_1_2 <= 100));
  __CPROVER_assume((pub_r001617_2_1 >= (-100)) && (pub_r001617_2_1 <= 100));
  __CPROVER_assume((pub_r001617_2_2 >= (-100)) && (pub_r001617_2_2 <= 100));
  __CPROVER_assume((pub_r001617_3_1 >= (-100)) && (pub_r001617_3_1 <= 100));
  __CPROVER_assume((pub_r001617_3_2 >= (-100)) && (pub_r001617_3_2 <= 100));
  __CPROVER_assume((pub_r001617_4_1 >= (-100)) && (pub_r001617_4_1 <= 100));
  __CPROVER_assume((pub_r001617_4_2 >= (-100)) && (pub_r001617_4_2 <= 100));
  __CPROVER_assume((pub_r001617_5_1 >= (-100)) && (pub_r001617_5_1 <= 100));
  __CPROVER_assume((pub_r001617_5_2 >= (-100)) && (pub_r001617_5_2 <= 100));
  __CPROVER_assume((pub_r001617_6_1 >= (-100)) && (pub_r001617_6_1 <= 100));
  __CPROVER_assume((pub_r001617_6_2 >= (-100)) && (pub_r001617_6_2 <= 100));
  __CPROVER_assume((pub_r001617_7_1 >= (-100)) && (pub_r001617_7_1 <= 100));
  __CPROVER_assume((pub_r001617_7_2 >= (-100)) && (pub_r001617_7_2 <= 100));
  __CPROVER_assume((pub_r001617_8_1 >= (-100)) && (pub_r001617_8_1 <= 100));
  __CPROVER_assume((pub_r001617_8_2 >= (-100)) && (pub_r001617_8_2 <= 100));
  __CPROVER_assume((pub_r001617_9_1 >= (-100)) && (pub_r001617_9_1 <= 100));
  __CPROVER_assume((pub_r001617_9_2 >= (-100)) && (pub_r001617_9_2 <= 100));
  __CPROVER_assume((pub_r001617_10_1 >= (-100)) && (pub_r001617_10_1 <= 100));
  __CPROVER_assume((pub_r001617_10_2 >= (-100)) && (pub_r001617_10_2 <= 100));
  __CPROVER_assume((pub_r001617_11_1 >= (-100)) && (pub_r001617_11_1 <= 100));
  __CPROVER_assume((pub_r001617_11_2 >= (-100)) && (pub_r001617_11_2 <= 100));
  __CPROVER_assume((pub_r001617_12_1 >= (-100)) && (pub_r001617_12_1 <= 100));
  __CPROVER_assume((pub_r001617_12_2 >= (-100)) && (pub_r001617_12_2 <= 100));
  __CPROVER_assume((pub_r001617_13_1 >= (-100)) && (pub_r001617_13_1 <= 100));
  __CPROVER_assume((pub_r001617_13_2 >= (-100)) && (pub_r001617_13_2 <= 100));
  __CPROVER_assume((pub_r001617_14_1 >= (-100)) && (pub_r001617_14_1 <= 100));
  __CPROVER_assume((pub_r001617_14_2 >= (-100)) && (pub_r001617_14_2 <= 100));
  __CPROVER_assume((pub_r001617_15_1 >= (-100)) && (pub_r001617_15_1 <= 100));
  __CPROVER_assume((pub_r001617_15_2 >= (-100)) && (pub_r001617_15_2 <= 100));
  __CPROVER_assume((pub_r001617_16_1 >= (-100)) && (pub_r001617_16_1 <= 100));
  __CPROVER_assume((pub_r001617_16_2 >= (-100)) && (pub_r001617_16_2 <= 100));
  __CPROVER_assume((pub_r001617_17_1 >= (-100)) && (pub_r001617_17_1 <= 100));
  __CPROVER_assume((pub_r001617_17_2 >= (-100)) && (pub_r001617_17_2 <= 100));
  __CPROVER_assume((pub_r001617_18_1 >= (-100)) && (pub_r001617_18_1 <= 100));
  __CPROVER_assume((pub_r001617_18_2 >= (-100)) && (pub_r001617_18_2 <= 100));
  __CPROVER_assume((pub_r001617_19_1 >= (-100)) && (pub_r001617_19_1 <= 100));
  __CPROVER_assume((pub_r001617_19_2 >= (-100)) && (pub_r001617_19_2 <= 100));
  __CPROVER_assume((sec_r001617_0_1 >= 0) && (sec_r001617_0_1 <= 255));
  __CPROVER_assume((sec_r001617_0_2 >= 0) && (sec_r001617_0_2 <= 255));
  __CPROVER_assume((sec_r001617_1_1 >= 0) && (sec_r001617_1_1 <= 255));
  __CPROVER_assume((sec_r001617_1_2 >= 0) && (sec_r001617_1_2 <= 255));
  __CPROVER_assume((sec_r001617_2_1 >= 0) && (sec_r001617_2_1 <= 255));
  __CPROVER_assume((sec_r001617_2_2 >= 0) && (sec_r001617_2_2 <= 255));
  __CPROVER_assume((sec_r001617_3_1 >= 0) && (sec_r001617_3_1 <= 255));
  __CPROVER_assume((sec_r001617_3_2 >= 0) && (sec_r001617_3_2 <= 255));
  __CPROVER_assume((sec_r001617_4_1 >= 0) && (sec_r001617_4_1 <= 255));
  __CPROVER_assume((sec_r001617_4_2 >= 0) && (sec_r001617_4_2 <= 255));
  __CPROVER_assume((sec_r001617_5_1 >= 0) && (sec_r001617_5_1 <= 255));
  __CPROVER_assume((sec_r001617_5_2 >= 0) && (sec_r001617_5_2 <= 255));
  __CPROVER_assume((sec_r001617_6_1 >= 0) && (sec_r001617_6_1 <= 255));
  __CPROVER_assume((sec_r001617_6_2 >= 0) && (sec_r001617_6_2 <= 255));
  __CPROVER_assume((sec_r001617_7_1 >= 0) && (sec_r001617_7_1 <= 255));
  __CPROVER_assume((sec_r001617_7_2 >= 0) && (sec_r001617_7_2 <= 255));
  __CPROVER_assume((sec_r001617_8_1 >= 0) && (sec_r001617_8_1 <= 255));
  __CPROVER_assume((sec_r001617_8_2 >= 0) && (sec_r001617_8_2 <= 255));
  __CPROVER_assume((sec_r001617_9_1 >= 0) && (sec_r001617_9_1 <= 255));
  __CPROVER_assume((sec_r001617_9_2 >= 0) && (sec_r001617_9_2 <= 255));
  __CPROVER_assume((sec_r001617_10_1 >= 0) && (sec_r001617_10_1 <= 255));
  __CPROVER_assume((sec_r001617_10_2 >= 0) && (sec_r001617_10_2 <= 255));
  __CPROVER_assume((sec_r001617_11_1 >= 0) && (sec_r001617_11_1 <= 255));
  __CPROVER_assume((sec_r001617_11_2 >= 0) && (sec_r001617_11_2 <= 255));
  __CPROVER_assume((sec_r001617_12_1 >= 0) && (sec_r001617_12_1 <= 255));
  __CPROVER_assume((sec_r001617_12_2 >= 0) && (sec_r001617_12_2 <= 255));
  __CPROVER_assume((sec_r001617_13_1 >= 0) && (sec_r001617_13_1 <= 255));
  __CPROVER_assume((sec_r001617_13_2 >= 0) && (sec_r001617_13_2 <= 255));
  __CPROVER_assume((sec_r001617_14_1 >= 0) && (sec_r001617_14_1 <= 255));
  __CPROVER_assume((sec_r001617_14_2 >= 0) && (sec_r001617_14_2 <= 255));
  __CPROVER_assume((sec_r001617_15_1 >= 0) && (sec_r001617_15_1 <= 255));
  __CPROVER_assume((sec_r001617_15_2 >= 0) && (sec_r001617_15_2 <= 255));
  __CPROVER_assume((sec_r001617_16_1 >= 0) && (sec_r001617_16_1 <= 255));
  __CPROVER_assume((sec_r001617_16_2 >= 0) && (sec_r001617_16_2 <= 255));
  __CPROVER_assume((sec_r001617_17_1 >= 0) && (sec_r001617_17_1 <= 255));
  __CPROVER_assume((sec_r001617_17_2 >= 0) && (sec_r001617_17_2 <= 255));
  __CPROVER_assume((sec_r001617_18_1 >= 0) && (sec_r001617_18_1 <= 255));
  __CPROVER_assume((sec_r001617_18_2 >= 0) && (sec_r001617_18_2 <= 255));
  __CPROVER_assume((sec_r001617_19_1 >= 0) && (sec_r001617_19_1 <= 255));
  __CPROVER_assume((sec_r001617_19_2 >= 0) && (sec_r001617_19_2 <= 255));
  __CPROVER_assume((sec_r001617_20_1 >= 0) && (sec_r001617_20_1 <= 255));
  __CPROVER_assume((sec_r001617_20_2 >= 0) && (sec_r001617_20_2 <= 255));
  __CPROVER_assume((sec_r001617_21_1 >= 0) && (sec_r001617_21_1 <= 255));
  __CPROVER_assume((sec_r001617_21_2 >= 0) && (sec_r001617_21_2 <= 255));
  __CPROVER_assume((sec_r001617_22_1 >= 0) && (sec_r001617_22_1 <= 255));
  __CPROVER_assume((sec_r001617_22_2 >= 0) && (sec_r001617_22_2 <= 255));
  __CPROVER_assume((sec_r001617_23_1 >= 0) && (sec_r001617_23_1 <= 255));
  __CPROVER_assume((sec_r001617_23_2 >= 0) && (sec_r001617_23_2 <= 255));
  struct Vector3D_R001617_1713_0 st_var_0_1 = {0};
  struct Vector3D_R001617_1713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001617_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001617_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001617_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001617_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001617_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001617_0_2 + 7) & 15;
  struct Transaction_R001617_1713_1 st_var_1_1 = {0};
  struct Transaction_R001617_1713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001617_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001617_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001617_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001617_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001617_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001617_0_2 + 9) & 15;
  union ColorPixel_R001617_1713_0 u_var_1;
  union ColorPixel_R001617_1713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001617_1713_0(sec_r001617_0_1, sec_r001617_1_1, pub_r001617_2_1, pub_r001617_3_1);
  int helper_flow_0_2 = fn_R001617_1713_0(sec_r001617_0_2, sec_r001617_1_2, pub_r001617_2_2, pub_r001617_3_2);
  fn_R001617_1713_0_2(sec_r001617_0_1, sec_r001617_1_1, pub_r001617_2_1, pub_r001617_3_1, sec_r001617_0_2, sec_r001617_1_2, pub_r001617_2_2, pub_r001617_3_2);
  int helper_flow_1_1 = fn_R001617_1713_1(sec_r001617_1_1, sec_r001617_2_1, pub_r001617_3_1, pub_r001617_4_1, pub_r001617_5_1);
  int helper_flow_1_2 = fn_R001617_1713_1(sec_r001617_1_2, sec_r001617_2_2, pub_r001617_3_2, pub_r001617_4_2, pub_r001617_5_2);
  fn_R001617_1713_1_2(sec_r001617_1_1, sec_r001617_2_1, pub_r001617_3_1, pub_r001617_4_1, pub_r001617_5_1, sec_r001617_1_2, sec_r001617_2_2, pub_r001617_3_2, pub_r001617_4_2, pub_r001617_5_2);
  int helper_flow_2_1 = fn_R001617_1713_2(sec_r001617_2_1, sec_r001617_3_1, pub_r001617_4_1, pub_r001617_5_1, pub_r001617_6_1);
  int helper_flow_2_2 = fn_R001617_1713_2(sec_r001617_2_2, sec_r001617_3_2, pub_r001617_4_2, pub_r001617_5_2, pub_r001617_6_2);
  fn_R001617_1713_2_2(sec_r001617_2_1, sec_r001617_3_1, pub_r001617_4_1, pub_r001617_5_1, pub_r001617_6_1, sec_r001617_2_2, sec_r001617_3_2, pub_r001617_4_2, pub_r001617_5_2, pub_r001617_6_2);
  int helper_flow_3_1 = fn_R001617_1713_3(sec_r001617_3_1, sec_r001617_4_1, pub_r001617_5_1, pub_r001617_6_1);
  int helper_flow_3_2 = fn_R001617_1713_3(sec_r001617_3_2, sec_r001617_4_2, pub_r001617_5_2, pub_r001617_6_2);
  fn_R001617_1713_3_2(sec_r001617_3_1, sec_r001617_4_1, pub_r001617_5_1, pub_r001617_6_1, sec_r001617_3_2, sec_r001617_4_2, pub_r001617_5_2, pub_r001617_6_2);
  int helper_flow_4_1 = fn_R001617_1713_4(sec_r001617_4_1, sec_r001617_5_1, pub_r001617_6_1, pub_r001617_7_1, pub_r001617_8_1);
  int helper_flow_4_2 = fn_R001617_1713_4(sec_r001617_4_2, sec_r001617_5_2, pub_r001617_6_2, pub_r001617_7_2, pub_r001617_8_2);
  fn_R001617_1713_4_2(sec_r001617_4_1, sec_r001617_5_1, pub_r001617_6_1, pub_r001617_7_1, pub_r001617_8_1, sec_r001617_4_2, sec_r001617_5_2, pub_r001617_6_2, pub_r001617_7_2, pub_r001617_8_2);
  int helper_flow_5_1 = fn_R001617_1713_5(sec_r001617_5_1, pub_r001617_6_1, pub_r001617_7_1, pub_r001617_8_1, pub_r001617_9_1);
  int helper_flow_5_2 = fn_R001617_1713_5(sec_r001617_5_2, pub_r001617_6_2, pub_r001617_7_2, pub_r001617_8_2, pub_r001617_9_2);
  fn_R001617_1713_5_2(sec_r001617_5_1, pub_r001617_6_1, pub_r001617_7_1, pub_r001617_8_1, pub_r001617_9_1, sec_r001617_5_2, pub_r001617_6_2, pub_r001617_7_2, pub_r001617_8_2, pub_r001617_9_2);
  int helper_flow_6_1 = fn_R001617_1713_6(sec_r001617_6_1, pub_r001617_7_1);
  int helper_flow_6_2 = fn_R001617_1713_6(sec_r001617_6_2, pub_r001617_7_2);
  fn_R001617_1713_6_2(sec_r001617_6_1, pub_r001617_7_1, sec_r001617_6_2, pub_r001617_7_2);
  int helper_flow_7_1 = fn_R001617_1713_7(sec_r001617_7_1, sec_r001617_8_1);
  int helper_flow_7_2 = fn_R001617_1713_7(sec_r001617_7_2, sec_r001617_8_2);
  fn_R001617_1713_7_2(sec_r001617_7_1, sec_r001617_8_1, sec_r001617_7_2, sec_r001617_8_2);
  int helper_flow_8_1 = fn_R001617_1713_8(sec_r001617_8_1, sec_r001617_9_1, pub_r001617_10_1, pub_r001617_11_1);
  int helper_flow_8_2 = fn_R001617_1713_8(sec_r001617_8_2, sec_r001617_9_2, pub_r001617_10_2, pub_r001617_11_2);
  fn_R001617_1713_8_2(sec_r001617_8_1, sec_r001617_9_1, pub_r001617_10_1, pub_r001617_11_1, sec_r001617_8_2, sec_r001617_9_2, pub_r001617_10_2, pub_r001617_11_2);
  int helper_flow_9_1 = fn_R001617_1713_9(sec_r001617_9_1, pub_r001617_10_1);
  int helper_flow_9_2 = fn_R001617_1713_9(sec_r001617_9_2, pub_r001617_10_2);
  fn_R001617_1713_9_2(sec_r001617_9_1, pub_r001617_10_1, sec_r001617_9_2, pub_r001617_10_2);
  int helper_flow_10_1 = fn_R001617_1713_10(sec_r001617_10_1, sec_r001617_11_1, pub_r001617_12_1, pub_r001617_13_1, pub_r001617_14_1);
  int helper_flow_10_2 = fn_R001617_1713_10(sec_r001617_10_2, sec_r001617_11_2, pub_r001617_12_2, pub_r001617_13_2, pub_r001617_14_2);
  fn_R001617_1713_10_2(sec_r001617_10_1, sec_r001617_11_1, pub_r001617_12_1, pub_r001617_13_1, pub_r001617_14_1, sec_r001617_10_2, sec_r001617_11_2, pub_r001617_12_2, pub_r001617_13_2, pub_r001617_14_2);
  int stage_v_0_1 = (sec_r001617_12_1 ^ pub_r001617_7_1) & 63;
  int stage_v_0_2 = (sec_r001617_12_2 ^ pub_r001617_7_2) & 63;
  if ((stage_v_0_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_1_1 = (sec_r001617_16_1 ^ pub_r001617_8_1) & 63;
  int stage_v_1_2 = (sec_r001617_16_2 ^ pub_r001617_8_2) & 63;
  if ((stage_v_1_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_1_1 * 2)) & 255;
  }
  if ((stage_v_1_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_1_2 * 2)) & 255;
  }
  int stage_v_2_1 = ((pub_r001617_14_1 * 2) + 21) & 63;
  int stage_v_2_2 = ((pub_r001617_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (helper_flow_3_1 ^ pub_r001617_10_1) & 63;
  int stage_v_3_2 = (helper_flow_3_2 ^ pub_r001617_10_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
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
    if ((helper_flow_2_2 & 2) != 0)
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
  int stage_v_4_1 = ((pub_r001617_5_1 * 2) + 14) & 63;
  int stage_v_4_2 = ((pub_r001617_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001617_2_1 * 2) + 35) & 63;
  int stage_v_5_2 = ((pub_r001617_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (helper_flow_0_1 ^ pub_r001617_4_1) & 63;
  int stage_v_6_2 = (helper_flow_0_2 ^ pub_r001617_4_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
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
    if ((helper_flow_5_2 & 2) != 0)
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
  int stage_v_7_1 = (stage_v_6_1 ^ pub_r001617_19_1) & 63;
  int stage_v_7_2 = (stage_v_6_2 ^ pub_r001617_19_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((sec_r001617_6_1 & 2) != 0)
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
    if ((sec_r001617_6_2 & 2) != 0)
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
  int stage_v_8_1 = ((pub_r001617_3_1 * 2) + 41) & 63;
  int stage_v_8_2 = ((pub_r001617_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (sec_r001617_12_1 ^ pub_r001617_18_1) & 63;
  int stage_v_9_2 = (sec_r001617_12_2 ^ pub_r001617_18_2) & 63;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_9_1 * 2)) & 255;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_9_2 * 2)) & 255;
  }
  int stage_v_10_1 = (helper_flow_3_1 ^ pub_r001617_12_1) & 63;
  int stage_v_10_2 = (helper_flow_3_2 ^ pub_r001617_12_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((sec_r001617_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_10_1 * 2)) & 255;
  }
  if ((stage_v_10_2 & 1) != 0)
  {
    if ((sec_r001617_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_10_2 * 2)) & 255;
  }
  int stage_v_11_1 = (sec_r001617_22_1 ^ pub_r001617_7_1) & 63;
  int stage_v_11_2 = (sec_r001617_22_2 ^ pub_r001617_7_2) & 63;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((sec_r001617_6_1 & 2) != 0)
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
    if ((sec_r001617_6_2 & 2) != 0)
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
  int stage_v_12_1 = ((pub_r001617_16_1 * 2) + 38) & 63;
  int stage_v_12_2 = ((pub_r001617_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (sec_r001617_8_1 ^ pub_r001617_9_1) & 63;
  int stage_v_13_2 = (sec_r001617_8_2 ^ pub_r001617_9_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
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
    if ((helper_flow_6_2 & 2) != 0)
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
  int stage_v_14_1 = (sec_r001617_14_1 ^ pub_r001617_10_1) & 63;
  int stage_v_14_2 = (sec_r001617_14_2 ^ pub_r001617_10_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
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
    if ((helper_flow_7_2 & 2) != 0)
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
  int stage_v_15_1 = (sec_r001617_23_1 ^ pub_r001617_11_1) & 63;
  int stage_v_15_2 = (sec_r001617_23_2 ^ pub_r001617_11_2) & 63;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_16_1 = ((pub_r001617_17_1 * 2) + 10) & 63;
  int stage_v_16_2 = ((pub_r001617_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (helper_flow_5_1 ^ pub_r001617_0_1) & 63;
  int stage_v_17_2 = (helper_flow_5_2 ^ pub_r001617_0_2) & 63;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_17_1 * 2)) & 255;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_17_2 * 2)) & 255;
  }
  int stage_v_18_1 = (sec_r001617_5_1 ^ pub_r001617_10_1) & 63;
  int stage_v_18_2 = (sec_r001617_5_2 ^ pub_r001617_10_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r001617_5_1 & 2) != 0)
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
    if ((sec_r001617_5_2 & 2) != 0)
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
  int stage_v_19_1 = ((pub_r001617_6_1 * 2) + 30) & 63;
  int stage_v_19_2 = ((pub_r001617_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (stage_v_11_1 ^ pub_r001617_6_1) & 63;
  int stage_v_20_2 = (stage_v_11_2 ^ pub_r001617_6_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r001617_14_1 & 2) != 0)
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
    if ((sec_r001617_14_2 & 2) != 0)
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
  int stage_v_21_1 = (helper_flow_4_1 ^ pub_r001617_5_1) & 63;
  int stage_v_21_2 = (helper_flow_4_2 ^ pub_r001617_5_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r001617_23_1 & 2) != 0)
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
    if ((sec_r001617_23_2 & 2) != 0)
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
  int stage_v_22_1 = ((pub_r001617_9_1 * 2) + 25) & 63;
  int stage_v_22_2 = ((pub_r001617_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (helper_flow_4_1 ^ pub_r001617_9_1) & 63;
  int stage_v_23_2 = (helper_flow_4_2 ^ pub_r001617_9_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r001617_0_1 & 2) != 0)
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
    if ((sec_r001617_0_2 & 2) != 0)
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
  int stage_v_24_1 = (stage_v_0_1 ^ pub_r001617_14_1) & 63;
  int stage_v_24_2 = (stage_v_0_2 ^ pub_r001617_14_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r001617_13_1 & 2) != 0)
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
    if ((sec_r001617_13_2 & 2) != 0)
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
  int stage_v_25_1 = (stage_v_7_1 ^ pub_r001617_16_1) & 63;
  int stage_v_25_2 = (stage_v_7_2 ^ pub_r001617_16_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
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
    if ((helper_flow_10_2 & 2) != 0)
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
  int stage_v_26_1 = (stage_v_25_1 ^ pub_r001617_9_1) & 63;
  int stage_v_26_2 = (stage_v_25_2 ^ pub_r001617_9_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
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
    if ((stage_v_24_2 & 2) != 0)
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
  int stage_v_27_1 = (stage_v_3_1 ^ pub_r001617_4_1) & 63;
  int stage_v_27_2 = (stage_v_3_2 ^ pub_r001617_4_2) & 63;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((helper_flow_9_1 & 2) != 0)
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
    if ((helper_flow_9_2 & 2) != 0)
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
  int stage_v_28_1 = ((pub_r001617_14_1 * 2) + 21) & 63;
  int stage_v_28_2 = ((pub_r001617_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001617_0_1 * 2) + 25) & 63;
  int stage_v_29_2 = ((pub_r001617_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (helper_flow_4_1 ^ pub_r001617_17_1) & 63;
  int stage_v_30_2 = (helper_flow_4_2 ^ pub_r001617_17_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r001617_21_1 & 2) != 0)
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
    if ((sec_r001617_21_2 & 2) != 0)
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
  int stage_v_31_1 = ((pub_r001617_10_1 * 2) + 21) & 63;
  int stage_v_31_2 = ((pub_r001617_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (helper_flow_4_1 ^ pub_r001617_3_1) & 63;
  int stage_v_32_2 = (helper_flow_4_2 ^ pub_r001617_3_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
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
    if ((stage_v_18_2 & 2) != 0)
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
  int stage_v_33_1 = (sec_r001617_19_1 ^ pub_r001617_10_1) & 63;
  int stage_v_33_2 = (sec_r001617_19_2 ^ pub_r001617_10_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_33_1 * 2)) & 255;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((stage_v_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_33_2 * 2)) & 255;
  }
  int stage_v_34_1 = (helper_flow_2_1 ^ pub_r001617_6_1) & 63;
  int stage_v_34_2 = (helper_flow_2_2 ^ pub_r001617_6_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r001617_6_1 & 2) != 0)
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
    if ((sec_r001617_6_2 & 2) != 0)
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
  int stage_v_35_1 = (stage_v_30_1 ^ pub_r001617_14_1) & 63;
  int stage_v_35_2 = (stage_v_30_2 ^ pub_r001617_14_2) & 63;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((helper_flow_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_35_1 * 2)) & 255;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((helper_flow_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_35_2 * 2)) & 255;
  }
  int stage_v_36_1 = (stage_v_14_1 ^ pub_r001617_0_1) & 63;
  int stage_v_36_2 = (stage_v_14_2 ^ pub_r001617_0_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
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
    if ((helper_flow_10_2 & 2) != 0)
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
  int stage_v_37_1 = (stage_v_14_1 ^ pub_r001617_18_1) & 63;
  int stage_v_37_2 = (stage_v_14_2 ^ pub_r001617_18_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r001617_9_1 & 2) != 0)
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
    if ((sec_r001617_9_2 & 2) != 0)
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
  int stage_v_38_1 = (stage_v_32_1 ^ pub_r001617_7_1) & 63;
  int stage_v_38_2 = (stage_v_32_2 ^ pub_r001617_7_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
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
    if ((stage_v_7_2 & 2) != 0)
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
  int stage_v_39_1 = (helper_flow_9_1 ^ pub_r001617_7_1) & 63;
  int stage_v_39_2 = (helper_flow_9_2 ^ pub_r001617_7_2) & 63;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
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
    if ((stage_v_25_2 & 2) != 0)
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
  int stage_v_40_1 = (sec_r001617_8_1 ^ pub_r001617_12_1) & 63;
  int stage_v_40_2 = (sec_r001617_8_2 ^ pub_r001617_12_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r001617_14_1 & 2) != 0)
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
    if ((sec_r001617_14_2 & 2) != 0)
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
  int stage_v_41_1 = (sec_r001617_6_1 ^ pub_r001617_18_1) & 63;
  int stage_v_41_2 = (sec_r001617_6_2 ^ pub_r001617_18_2) & 63;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_41_1 * 2)) & 255;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((helper_flow_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_41_2 * 2)) & 255;
  }
  int stage_v_42_1 = (helper_flow_6_1 ^ pub_r001617_12_1) & 63;
  int stage_v_42_2 = (helper_flow_6_2 ^ pub_r001617_12_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r001617_9_1 & 2) != 0)
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
    if ((sec_r001617_9_2 & 2) != 0)
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
  int stage_v_43_1 = ((pub_r001617_8_1 * 2) + 26) & 63;
  int stage_v_43_2 = ((pub_r001617_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (sec_r001617_8_1 ^ pub_r001617_13_1) & 63;
  int stage_v_44_2 = (sec_r001617_8_2 ^ pub_r001617_13_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r001617_13_1 & 2) != 0)
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
    if ((sec_r001617_13_2 & 2) != 0)
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
  int stage_v_45_1 = ((pub_r001617_12_1 * 2) + 22) & 63;
  int stage_v_45_2 = ((pub_r001617_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (stage_v_25_1 ^ pub_r001617_18_1) & 63;
  int stage_v_46_2 = (stage_v_25_2 ^ pub_r001617_18_2) & 63;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r001617_20_1 & 2) != 0)
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
    if ((sec_r001617_20_2 & 2) != 0)
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
  int stage_v_47_1 = (stage_v_34_1 ^ pub_r001617_9_1) & 63;
  int stage_v_47_2 = (stage_v_34_2 ^ pub_r001617_9_2) & 63;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r001617_22_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_47_1 * 2)) & 255;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r001617_22_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_47_2 * 2)) & 255;
  }
  int stage_v_48_1 = (sec_r001617_23_1 ^ pub_r001617_11_1) & 63;
  int stage_v_48_2 = (sec_r001617_23_2 ^ pub_r001617_11_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r001617_19_1 & 2) != 0)
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
    if ((sec_r001617_19_2 & 2) != 0)
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
  int stage_v_49_1 = (sec_r001617_1_1 ^ pub_r001617_9_1) & 63;
  int stage_v_49_2 = (sec_r001617_1_2 ^ pub_r001617_9_2) & 63;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r001617_4_1 & 2) != 0)
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
    if ((sec_r001617_4_2 & 2) != 0)
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
  int stage_v_50_1 = (sec_r001617_5_1 ^ pub_r001617_7_1) & 63;
  int stage_v_50_2 = (sec_r001617_5_2 ^ pub_r001617_7_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((stage_v_39_1 & 2) != 0)
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
    if ((stage_v_39_2 & 2) != 0)
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
  int stage_v_51_1 = (sec_r001617_5_1 ^ pub_r001617_2_1) & 63;
  int stage_v_51_2 = (sec_r001617_5_2 ^ pub_r001617_2_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((stage_v_47_1 & 2) != 0)
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
    if ((stage_v_47_2 & 2) != 0)
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
  int stage_v_52_1 = (sec_r001617_4_1 ^ pub_r001617_18_1) & 63;
  int stage_v_52_2 = (sec_r001617_4_2 ^ pub_r001617_18_2) & 63;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((stage_v_39_1 & 2) != 0)
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
    if ((stage_v_39_2 & 2) != 0)
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
  int stage_v_53_1 = ((pub_r001617_15_1 * 2) + 19) & 63;
  int stage_v_53_2 = ((pub_r001617_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (stage_v_18_1 ^ pub_r001617_9_1) & 63;
  int stage_v_54_2 = (stage_v_18_2 ^ pub_r001617_9_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
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
    if ((stage_v_30_2 & 2) != 0)
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
  int stage_v_55_1 = (sec_r001617_23_1 ^ pub_r001617_18_1) & 63;
  int stage_v_55_2 = (sec_r001617_23_2 ^ pub_r001617_18_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r001617_22_1 & 2) != 0)
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
    if ((sec_r001617_22_2 & 2) != 0)
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
  int stage_v_56_1 = (stage_v_51_1 ^ pub_r001617_8_1) & 63;
  int stage_v_56_2 = (stage_v_51_2 ^ pub_r001617_8_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
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
    if ((stage_v_9_2 & 2) != 0)
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
  int stage_v_57_1 = (stage_v_51_1 ^ pub_r001617_2_1) & 63;
  int stage_v_57_2 = (stage_v_51_2 ^ pub_r001617_2_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_58_1 = (stage_v_52_1 ^ pub_r001617_3_1) & 63;
  int stage_v_58_2 = (stage_v_52_2 ^ pub_r001617_3_2) & 63;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((helper_flow_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((helper_flow_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  }
  int stage_v_59_1 = (stage_v_15_1 ^ pub_r001617_10_1) & 63;
  int stage_v_59_2 = (stage_v_15_2 ^ pub_r001617_10_2) & 63;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_60_1 = (stage_v_25_1 ^ pub_r001617_7_1) & 63;
  int stage_v_60_2 = (stage_v_25_2 ^ pub_r001617_7_2) & 63;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((stage_v_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((stage_v_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  }
  int stage_v_61_1 = (helper_flow_10_1 ^ pub_r001617_3_1) & 63;
  int stage_v_61_2 = (helper_flow_10_2 ^ pub_r001617_3_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r001617_22_1 & 2) != 0)
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
    if ((sec_r001617_22_2 & 2) != 0)
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
  int stage_v_62_1 = (stage_v_42_1 ^ pub_r001617_12_1) & 63;
  int stage_v_62_2 = (stage_v_42_2 ^ pub_r001617_12_2) & 63;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((stage_v_42_1 & 2) != 0)
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
    if ((stage_v_42_2 & 2) != 0)
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
  int stage_v_63_1 = (helper_flow_10_1 ^ pub_r001617_4_1) & 63;
  int stage_v_63_2 = (helper_flow_10_2 ^ pub_r001617_4_2) & 63;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r001617_9_1 & 2) != 0)
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
    if ((sec_r001617_9_2 & 2) != 0)
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
  int stage_v_64_1 = ((pub_r001617_13_1 * 2) + 48) & 63;
  int stage_v_64_2 = ((pub_r001617_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001617_7_1 * 2) + 46) & 63;
  int stage_v_65_2 = ((pub_r001617_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (stage_v_15_1 ^ pub_r001617_16_1) & 63;
  int stage_v_66_2 = (stage_v_15_2 ^ pub_r001617_16_2) & 63;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_67_1 = ((pub_r001617_17_1 * 2) + 34) & 63;
  int stage_v_67_2 = ((pub_r001617_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001617_9_1 * 2) + 16) & 63;
  int stage_v_68_2 = ((pub_r001617_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (stage_v_48_1 ^ pub_r001617_11_1) & 63;
  int stage_v_69_2 = (stage_v_48_2 ^ pub_r001617_11_2) & 63;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r001617_5_1 & 2) != 0)
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
    if ((sec_r001617_5_2 & 2) != 0)
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
  int stage_v_70_1 = (sec_r001617_11_1 ^ pub_r001617_18_1) & 63;
  int stage_v_70_2 = (sec_r001617_11_2 ^ pub_r001617_18_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
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
    if ((stage_v_13_2 & 2) != 0)
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
  int stage_v_71_1 = (sec_r001617_18_1 ^ pub_r001617_17_1) & 63;
  int stage_v_71_2 = (sec_r001617_18_2 ^ pub_r001617_17_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r001617_19_1 & 2) != 0)
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
    if ((sec_r001617_19_2 & 2) != 0)
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
  int stage_v_72_1 = ((pub_r001617_15_1 * 2) + 40) & 63;
  int stage_v_72_2 = ((pub_r001617_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (stage_v_49_1 ^ pub_r001617_8_1) & 63;
  int stage_v_73_2 = (stage_v_49_2 ^ pub_r001617_8_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
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
    if ((stage_v_13_2 & 2) != 0)
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
  int stage_v_74_1 = ((pub_r001617_18_1 * 2) + 9) & 63;
  int stage_v_74_2 = ((pub_r001617_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (sec_r001617_23_1 ^ pub_r001617_14_1) & 63;
  int stage_v_75_2 = (sec_r001617_23_2 ^ pub_r001617_14_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
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
    if ((stage_v_34_2 & 2) != 0)
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
  int stage_v_76_1 = (stage_v_9_1 ^ pub_r001617_10_1) & 63;
  int stage_v_76_2 = (stage_v_9_2 ^ pub_r001617_10_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
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
    if ((stage_v_6_2 & 2) != 0)
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
  int stage_v_77_1 = (stage_v_18_1 ^ pub_r001617_18_1) & 63;
  int stage_v_77_2 = (stage_v_18_2 ^ pub_r001617_18_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
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
    if ((stage_v_26_2 & 2) != 0)
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
  int stage_v_78_1 = (sec_r001617_18_1 ^ pub_r001617_3_1) & 63;
  int stage_v_78_2 = (sec_r001617_18_2 ^ pub_r001617_3_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((stage_v_55_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  }
  int stage_v_79_1 = ((pub_r001617_17_1 * 2) + 13) & 63;
  int stage_v_79_2 = ((pub_r001617_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001617_7_1 * 2) + 50) & 63;
  int stage_v_80_2 = ((pub_r001617_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001617_4_1 * 2) + 27) & 63;
  int stage_v_81_2 = ((pub_r001617_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001617_0_1 * 2) + 49) & 63;
  int stage_v_82_2 = ((pub_r001617_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001617_13_1 * 2) + 26) & 63;
  int stage_v_83_2 = ((pub_r001617_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (stage_v_48_1 ^ pub_r001617_11_1) & 63;
  int stage_v_84_2 = (stage_v_48_2 ^ pub_r001617_11_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
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
    if ((stage_v_25_2 & 2) != 0)
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
  int stage_v_85_1 = (helper_flow_7_1 ^ pub_r001617_6_1) & 63;
  int stage_v_85_2 = (helper_flow_7_2 ^ pub_r001617_6_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((stage_v_62_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  }
  int stage_v_86_1 = (sec_r001617_22_1 ^ pub_r001617_18_1) & 63;
  int stage_v_86_2 = (sec_r001617_22_2 ^ pub_r001617_18_2) & 63;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
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
    if ((stage_v_44_2 & 2) != 0)
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
  int stage_v_87_1 = ((pub_r001617_11_1 * 2) + 13) & 63;
  int stage_v_87_2 = ((pub_r001617_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (stage_v_13_1 ^ pub_r001617_18_1) & 63;
  int stage_v_88_2 = (stage_v_13_2 ^ pub_r001617_18_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((stage_v_61_1 & 2) != 0)
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
    if ((stage_v_61_2 & 2) != 0)
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
  int stage_v_89_1 = (helper_flow_7_1 ^ pub_r001617_19_1) & 63;
  int stage_v_89_2 = (helper_flow_7_2 ^ pub_r001617_19_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((stage_v_61_1 & 2) != 0)
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
    if ((stage_v_61_2 & 2) != 0)
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
  int stage_v_90_1 = (stage_v_15_1 ^ pub_r001617_15_1) & 63;
  int stage_v_90_2 = (stage_v_15_2 ^ pub_r001617_15_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
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
    if ((stage_v_11_2 & 2) != 0)
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
  int stage_v_91_1 = (helper_flow_6_1 ^ pub_r001617_16_1) & 63;
  int stage_v_91_2 = (helper_flow_6_2 ^ pub_r001617_16_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r001617_1_1 & 2) != 0)
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
    if ((sec_r001617_1_2 & 2) != 0)
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
  int stage_v_92_1 = (stage_v_49_1 ^ pub_r001617_16_1) & 63;
  int stage_v_92_2 = (stage_v_49_2 ^ pub_r001617_16_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
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
    if ((stage_v_30_2 & 2) != 0)
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
  int stage_v_93_1 = (stage_v_46_1 ^ pub_r001617_4_1) & 63;
  int stage_v_93_2 = (stage_v_46_2 ^ pub_r001617_4_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((stage_v_71_1 & 2) != 0)
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
    if ((stage_v_71_2 & 2) != 0)
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
  int stage_v_94_1 = (stage_v_62_1 ^ pub_r001617_9_1) & 63;
  int stage_v_94_2 = (stage_v_62_2 ^ pub_r001617_9_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((stage_v_39_1 & 2) != 0)
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
    if ((stage_v_39_2 & 2) != 0)
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
  int stage_v_95_1 = (stage_v_56_1 ^ pub_r001617_3_1) & 63;
  int stage_v_95_2 = (stage_v_56_2 ^ pub_r001617_3_2) & 63;
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
  int stage_v_96_1 = (helper_flow_9_1 ^ pub_r001617_16_1) & 63;
  int stage_v_96_2 = (helper_flow_9_2 ^ pub_r001617_16_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_97_1 = (stage_v_55_1 ^ pub_r001617_14_1) & 63;
  int stage_v_97_2 = (stage_v_55_2 ^ pub_r001617_14_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r001617_4_1 & 2) != 0)
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
    if ((sec_r001617_4_2 & 2) != 0)
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
  int stage_v_98_1 = (stage_v_33_1 ^ pub_r001617_6_1) & 63;
  int stage_v_98_2 = (stage_v_33_2 ^ pub_r001617_6_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r001617_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r001617_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  }
  int stage_v_99_1 = ((pub_r001617_6_1 * 2) + 27) & 63;
  int stage_v_99_2 = ((pub_r001617_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (sec_r001617_12_1 ^ pub_r001617_2_1) & 63;
  int stage_v_100_2 = (sec_r001617_12_2 ^ pub_r001617_2_2) & 63;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
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
    if ((stage_v_27_2 & 2) != 0)
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
  int stage_v_101_1 = ((pub_r001617_15_1 * 2) + 40) & 63;
  int stage_v_101_2 = ((pub_r001617_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (stage_v_17_1 ^ pub_r001617_12_1) & 63;
  int stage_v_102_2 = (stage_v_17_2 ^ pub_r001617_12_2) & 63;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((stage_v_98_1 & 2) != 0)
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
    if ((stage_v_98_2 & 2) != 0)
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
  int stage_v_103_1 = (stage_v_56_1 ^ pub_r001617_6_1) & 63;
  int stage_v_103_2 = (stage_v_56_2 ^ pub_r001617_6_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
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
    if ((stage_v_26_2 & 2) != 0)
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
  int stage_v_104_1 = ((pub_r001617_10_1 * 2) + 8) & 63;
  int stage_v_104_2 = ((pub_r001617_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (stage_v_36_1 ^ pub_r001617_17_1) & 63;
  int stage_v_105_2 = (stage_v_36_2 ^ pub_r001617_17_2) & 63;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  }
  int stage_v_106_1 = (stage_v_32_1 ^ pub_r001617_13_1) & 63;
  int stage_v_106_2 = (stage_v_32_2 ^ pub_r001617_13_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r001617_15_1 & 2) != 0)
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
    if ((sec_r001617_15_2 & 2) != 0)
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
  int stage_v_107_1 = (sec_r001617_14_1 ^ pub_r001617_13_1) & 63;
  int stage_v_107_2 = (sec_r001617_14_2 ^ pub_r001617_13_2) & 63;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((stage_v_69_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((stage_v_69_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  }
  int stage_v_108_1 = (stage_v_51_1 ^ pub_r001617_19_1) & 63;
  int stage_v_108_2 = (stage_v_51_2 ^ pub_r001617_19_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
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
    if ((stage_v_40_2 & 2) != 0)
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
  int stage_v_109_1 = ((pub_r001617_11_1 * 2) + 30) & 63;
  int stage_v_109_2 = ((pub_r001617_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (stage_v_50_1 ^ pub_r001617_5_1) & 63;
  int stage_v_110_2 = (stage_v_50_2 ^ pub_r001617_5_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((stage_v_56_1 & 2) != 0)
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
    if ((stage_v_56_2 & 2) != 0)
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
  int stage_v_111_1 = (stage_v_94_1 ^ pub_r001617_8_1) & 63;
  int stage_v_111_2 = (stage_v_94_2 ^ pub_r001617_8_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((stage_v_56_1 & 2) != 0)
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
    if ((stage_v_56_2 & 2) != 0)
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
  int stage_v_112_1 = (stage_v_52_1 ^ pub_r001617_14_1) & 63;
  int stage_v_112_2 = (stage_v_52_2 ^ pub_r001617_14_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
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
    if ((stage_v_66_2 & 2) != 0)
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
  int stage_v_113_1 = (stage_v_24_1 ^ pub_r001617_1_1) & 63;
  int stage_v_113_2 = (stage_v_24_2 ^ pub_r001617_1_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
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
    if ((stage_v_55_2 & 2) != 0)
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
  int stage_v_114_1 = (stage_v_47_1 ^ pub_r001617_0_1) & 63;
  int stage_v_114_2 = (stage_v_47_2 ^ pub_r001617_0_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_115_1 = (stage_v_60_1 ^ pub_r001617_10_1) & 63;
  int stage_v_115_2 = (stage_v_60_2 ^ pub_r001617_10_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((stage_v_89_1 & 2) != 0)
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
    if ((stage_v_89_2 & 2) != 0)
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
  int stage_v_116_1 = (stage_v_35_1 ^ pub_r001617_5_1) & 63;
  int stage_v_116_2 = (stage_v_35_2 ^ pub_r001617_5_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
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
    if ((stage_v_48_2 & 2) != 0)
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
  int stage_v_117_1 = ((pub_r001617_3_1 * 2) + 33) & 63;
  int stage_v_117_2 = ((pub_r001617_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001617_12_1 * 2) + 19) & 63;
  int stage_v_118_2 = ((pub_r001617_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (stage_v_38_1 ^ pub_r001617_14_1) & 63;
  int stage_v_119_2 = (stage_v_38_2 ^ pub_r001617_14_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r001617_20_1 & 2) != 0)
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
    if ((sec_r001617_20_2 & 2) != 0)
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
  int stage_v_120_1 = (stage_v_63_1 ^ pub_r001617_19_1) & 63;
  int stage_v_120_2 = (stage_v_63_2 ^ pub_r001617_19_2) & 63;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((stage_v_119_1 & 2) != 0)
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
    if ((stage_v_119_2 & 2) != 0)
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
  int stage_v_121_1 = (stage_v_84_1 ^ pub_r001617_13_1) & 63;
  int stage_v_121_2 = (stage_v_84_2 ^ pub_r001617_13_2) & 63;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((stage_v_94_1 & 2) != 0)
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
    if ((stage_v_94_2 & 2) != 0)
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
  int stage_v_122_1 = (stage_v_20_1 ^ pub_r001617_9_1) & 63;
  int stage_v_122_2 = (stage_v_20_2 ^ pub_r001617_9_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((stage_v_59_1 & 2) != 0)
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
    if ((stage_v_59_2 & 2) != 0)
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
  int stage_v_123_1 = (stage_v_78_1 ^ pub_r001617_0_1) & 63;
  int stage_v_123_2 = (stage_v_78_2 ^ pub_r001617_0_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
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
    if ((stage_v_38_2 & 2) != 0)
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
  int stage_v_124_1 = (stage_v_33_1 ^ pub_r001617_4_1) & 63;
  int stage_v_124_2 = (stage_v_33_2 ^ pub_r001617_4_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
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
    if ((stage_v_3_2 & 2) != 0)
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
  int stage_v_125_1 = (stage_v_105_1 ^ pub_r001617_15_1) & 63;
  int stage_v_125_2 = (stage_v_105_2 ^ pub_r001617_15_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_106_1 & 2) != 0)
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
    if ((stage_v_106_2 & 2) != 0)
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
  int stage_v_126_1 = (stage_v_115_1 ^ pub_r001617_2_1) & 63;
  int stage_v_126_2 = (stage_v_115_2 ^ pub_r001617_2_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((stage_v_105_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((stage_v_105_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  }
  int stage_v_127_1 = (stage_v_119_1 ^ pub_r001617_7_1) & 63;
  int stage_v_127_2 = (stage_v_119_2 ^ pub_r001617_7_2) & 63;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((stage_v_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  }
  int stage_v_128_1 = ((pub_r001617_12_1 * 2) + 16) & 63;
  int stage_v_128_2 = ((pub_r001617_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (stage_v_46_1 ^ pub_r001617_13_1) & 63;
  int stage_v_129_2 = (stage_v_46_2 ^ pub_r001617_13_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
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
    if ((stage_v_34_2 & 2) != 0)
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
  int stage_v_130_1 = (stage_v_33_1 ^ pub_r001617_12_1) & 63;
  int stage_v_130_2 = (stage_v_33_2 ^ pub_r001617_12_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r001617_5_1 & 2) != 0)
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
    if ((sec_r001617_5_2 & 2) != 0)
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
  int stage_v_131_1 = (stage_v_124_1 ^ pub_r001617_15_1) & 63;
  int stage_v_131_2 = (stage_v_124_2 ^ pub_r001617_15_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
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
    if ((stage_v_11_2 & 2) != 0)
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
  int stage_v_132_1 = (sec_r001617_12_1 ^ pub_r001617_4_1) & 63;
  int stage_v_132_2 = (sec_r001617_12_2 ^ pub_r001617_4_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_107_1 & 2) != 0)
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
    if ((stage_v_107_2 & 2) != 0)
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
  int stage_v_133_1 = ((pub_r001617_1_1 * 2) + 40) & 63;
  int stage_v_133_2 = ((pub_r001617_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (stage_v_33_1 ^ pub_r001617_12_1) & 63;
  int stage_v_134_2 = (stage_v_33_2 ^ pub_r001617_12_2) & 63;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((stage_v_90_1 & 2) != 0)
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
    if ((stage_v_90_2 & 2) != 0)
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
  int stage_v_135_1 = (stage_v_77_1 ^ pub_r001617_12_1) & 63;
  int stage_v_135_2 = (stage_v_77_2 ^ pub_r001617_12_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
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
    if ((stage_v_18_2 & 2) != 0)
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
  int stage_v_136_1 = ((pub_r001617_1_1 * 2) + 27) & 63;
  int stage_v_136_2 = ((pub_r001617_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001617_3_1 * 2) + 16) & 63;
  int stage_v_137_2 = ((pub_r001617_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (stage_v_55_1 ^ pub_r001617_4_1) & 63;
  int stage_v_138_2 = (stage_v_55_2 ^ pub_r001617_4_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((sec_r001617_4_1 & 2) != 0)
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
    if ((sec_r001617_4_2 & 2) != 0)
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
  int stage_v_139_1 = ((pub_r001617_15_1 * 2) + 37) & 63;
  int stage_v_139_2 = ((pub_r001617_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (stage_v_119_1 ^ pub_r001617_1_1) & 63;
  int stage_v_140_2 = (stage_v_119_2 ^ pub_r001617_1_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((stage_v_54_1 & 2) != 0)
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
    if ((stage_v_54_2 & 2) != 0)
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
  int stage_v_141_1 = (stage_v_46_1 ^ pub_r001617_14_1) & 63;
  int stage_v_141_2 = (stage_v_46_2 ^ pub_r001617_14_2) & 63;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((stage_v_97_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((stage_v_97_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  }
  int stage_v_142_1 = (stage_v_100_1 ^ pub_r001617_0_1) & 63;
  int stage_v_142_2 = (stage_v_100_2 ^ pub_r001617_0_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_143_1 = (sec_r001617_15_1 ^ pub_r001617_16_1) & 63;
  int stage_v_143_2 = (sec_r001617_15_2 ^ pub_r001617_16_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((stage_v_103_1 & 2) != 0)
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
    if ((stage_v_103_2 & 2) != 0)
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
  int stage_v_144_1 = ((pub_r001617_1_1 * 2) + 15) & 63;
  int stage_v_144_2 = ((pub_r001617_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001617_7_1 * 2) + 37) & 63;
  int stage_v_145_2 = ((pub_r001617_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (stage_v_76_1 ^ pub_r001617_16_1) & 63;
  int stage_v_146_2 = (stage_v_76_2 ^ pub_r001617_16_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((sec_r001617_14_1 & 2) != 0)
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
    if ((sec_r001617_14_2 & 2) != 0)
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
  int stage_v_147_1 = (stage_v_1_1 ^ pub_r001617_9_1) & 63;
  int stage_v_147_2 = (stage_v_1_2 ^ pub_r001617_9_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_113_1 & 2) != 0)
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
    if ((stage_v_113_2 & 2) != 0)
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
  int stage_v_148_1 = (stage_v_123_1 ^ pub_r001617_3_1) & 63;
  int stage_v_148_2 = (stage_v_123_2 ^ pub_r001617_3_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_17_1 & 2) != 0)
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
    if ((stage_v_17_2 & 2) != 0)
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
  int stage_v_149_1 = (stage_v_1_1 ^ pub_r001617_17_1) & 63;
  int stage_v_149_2 = (stage_v_1_2 ^ pub_r001617_17_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((stage_v_63_1 & 2) != 0)
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
    if ((stage_v_63_2 & 2) != 0)
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
  int stage_v_150_1 = (helper_flow_9_1 ^ pub_r001617_1_1) & 63;
  int stage_v_150_2 = (helper_flow_9_2 ^ pub_r001617_1_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_151_1 = (stage_v_113_1 ^ pub_r001617_4_1) & 63;
  int stage_v_151_2 = (stage_v_113_2 ^ pub_r001617_4_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((sec_r001617_10_1 & 2) != 0)
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
    if ((sec_r001617_10_2 & 2) != 0)
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
  int stage_v_152_1 = ((pub_r001617_0_1 * 2) + 37) & 63;
  int stage_v_152_2 = ((pub_r001617_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (stage_v_14_1 ^ pub_r001617_0_1) & 63;
  int stage_v_153_2 = (stage_v_14_2 ^ pub_r001617_0_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((stage_v_129_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  }
  if ((stage_v_153_2 & 1) != 0)
  {
    if ((stage_v_129_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  }
  int stage_v_154_1 = (stage_v_151_1 ^ pub_r001617_7_1) & 63;
  int stage_v_154_2 = (stage_v_151_2 ^ pub_r001617_7_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((sec_r001617_5_1 & 2) != 0)
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
    if ((sec_r001617_5_2 & 2) != 0)
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
  int stage_v_155_1 = ((pub_r001617_1_1 * 2) + 24) & 63;
  int stage_v_155_2 = ((pub_r001617_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001617_3_1 * 2) + 6) & 63;
  int stage_v_156_2 = ((pub_r001617_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (stage_v_13_1 ^ pub_r001617_3_1) & 63;
  int stage_v_157_2 = (stage_v_13_2 ^ pub_r001617_3_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
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
    if ((stage_v_27_2 & 2) != 0)
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
  int stage_v_158_1 = ((pub_r001617_16_1 * 2) + 31) & 63;
  int stage_v_158_2 = ((pub_r001617_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (stage_v_134_1 ^ pub_r001617_15_1) & 63;
  int stage_v_159_2 = (stage_v_134_2 ^ pub_r001617_15_2) & 63;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((sec_r001617_7_1 & 2) != 0)
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
    if ((sec_r001617_7_2 & 2) != 0)
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
  int stage_v_160_1 = ((pub_r001617_14_1 * 2) + 41) & 63;
  int stage_v_160_2 = ((pub_r001617_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (stage_v_106_1 ^ pub_r001617_18_1) & 63;
  int stage_v_161_2 = (stage_v_106_2 ^ pub_r001617_18_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((sec_r001617_20_1 & 2) != 0)
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
    if ((sec_r001617_20_2 & 2) != 0)
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
  int stage_v_162_1 = (stage_v_135_1 ^ pub_r001617_10_1) & 63;
  int stage_v_162_2 = (stage_v_135_2 ^ pub_r001617_10_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((stage_v_110_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  }
  if ((stage_v_162_2 & 1) != 0)
  {
    if ((stage_v_110_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001617_2_1 == pub_r001617_2_2);
  __CPROVER_assume(sec_r001617_23_1 != sec_r001617_23_2);
  __CPROVER_assume(sec_r001617_2_1 != sec_r001617_2_2);
  __CPROVER_assume(sec_r001617_19_1 != sec_r001617_19_2);
  __CPROVER_assume(pub_r001617_3_1 == pub_r001617_3_2);
  __CPROVER_assume(sec_r001617_3_1 != sec_r001617_3_2);
  __CPROVER_assume(sec_r001617_4_1 != sec_r001617_4_2);
  __CPROVER_assume(sec_r001617_10_1 != sec_r001617_10_2);
  __CPROVER_assume(pub_r001617_15_1 == pub_r001617_15_2);
  __CPROVER_assume(sec_r001617_14_1 != sec_r001617_14_2);
  __CPROVER_assume(sec_r001617_11_1 != sec_r001617_11_2);
  __CPROVER_assume(sec_r001617_18_1 != sec_r001617_18_2);
  __CPROVER_assume(pub_r001617_11_1 == pub_r001617_11_2);
  __CPROVER_assume(pub_r001617_16_1 == pub_r001617_16_2);
  __CPROVER_assume(sec_r001617_13_1 != sec_r001617_13_2);
  __CPROVER_assume(pub_r001617_9_1 == pub_r001617_9_2);
  __CPROVER_assume(sec_r001617_1_1 != sec_r001617_1_2);
  __CPROVER_assume(pub_r001617_18_1 == pub_r001617_18_2);
  __CPROVER_assume(sec_r001617_15_1 != sec_r001617_15_2);
  __CPROVER_assume(sec_r001617_16_1 != sec_r001617_16_2);
  __CPROVER_assume(pub_r001617_19_1 == pub_r001617_19_2);
  __CPROVER_assume(sec_r001617_9_1 != sec_r001617_9_2);
  __CPROVER_assume(sec_r001617_7_1 != sec_r001617_7_2);
  __CPROVER_assume(sec_r001617_8_1 != sec_r001617_8_2);
  __CPROVER_assume(sec_r001617_22_1 != sec_r001617_22_2);
  __CPROVER_assume(pub_r001617_6_1 == pub_r001617_6_2);
  __CPROVER_assume(pub_r001617_17_1 == pub_r001617_17_2);
  __CPROVER_assume(pub_r001617_0_1 == pub_r001617_0_2);
  __CPROVER_assume(sec_r001617_6_1 != sec_r001617_6_2);
  __CPROVER_assume(pub_r001617_8_1 == pub_r001617_8_2);
  __CPROVER_assume(pub_r001617_1_1 == pub_r001617_1_2);
  __CPROVER_assume(sec_r001617_20_1 != sec_r001617_20_2);
  __CPROVER_assume(sec_r001617_17_1 != sec_r001617_17_2);
  __CPROVER_assume(pub_r001617_4_1 == pub_r001617_4_2);
  __CPROVER_assume(pub_r001617_10_1 == pub_r001617_10_2);
  __CPROVER_assume(sec_r001617_21_1 != sec_r001617_21_2);
  __CPROVER_assume(sec_r001617_0_1 != sec_r001617_0_2);
  __CPROVER_assume(pub_r001617_14_1 == pub_r001617_14_2);
  __CPROVER_assume(pub_r001617_5_1 == pub_r001617_5_2);
  __CPROVER_assume(sec_r001617_5_1 != sec_r001617_5_2);
  __CPROVER_assume(pub_r001617_7_1 == pub_r001617_7_2);
  __CPROVER_assume(pub_r001617_12_1 == pub_r001617_12_2);
  __CPROVER_assume(sec_r001617_12_1 != sec_r001617_12_2);
  __CPROVER_assume(pub_r001617_13_1 == pub_r001617_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.rate == st_var_1_2.rate);
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
}


