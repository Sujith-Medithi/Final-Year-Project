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
struct CipherContext_R001275_7513_0
{
  unsigned char counter;
  int tag;
  int iv;
  int nonce;
  int flags;
  unsigned char round_key;
  int buffer[3];
};
struct Vector3D_R001275_7513_1
{
  unsigned char coord_z;
  int pitch;
  short norm_sq;
  short heading;
  int buffer[3];
};
struct Transaction_R001275_7513_2
{
  int status;
  unsigned char fee;
  short account_id;
  int buffer[3];
};
struct MatrixBlock_R001275_7513_3
{
  int stride;
  short scale;
  int determinant;
  int buffer[3];
};
union ColorPixel_R001275_7513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001275_7513_1
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
void fn_R001275_7513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st_1 = {0};
  struct Vector3D_R001275_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int threshold_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_49_1) & 63;
  aux_2 = (aux_2 + threshold_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_69_1 > 15)
  {
    acc_1 = ((acc_1 + (phase_69_1 * 2)) + 5) & 127;
    aux_1 ^= phase_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_69_2 > 15)
  {
    acc_2 = ((acc_2 + (phase_69_2 * 2)) + 5) & 127;
    aux_2 ^= phase_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_14_1)
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

  switch (factor_14_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_49_1 == threshold_49_2);
  assert(phase_69_1 == phase_69_2);
  assert(factor_14_1 == factor_14_2);
}

int fn_R001275_7513_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int threshold_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_49) & 63;
  acc ^= aux;
  int phase_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_69 > 15)
  {
    acc = ((acc + (phase_69 * 2)) + 5) & 127;
    aux ^= phase_69 & 15;
  }
  else
  {
    acc = ((acc - phase_69) + 11) & 127;
    aux += 3;
  }
  int factor_14 = (aux + st.buffer[1]) & 3;
  switch (factor_14)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001275_7513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st_1 = {0};
  struct CipherContext_R001275_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_58_1 = local_arr_1[aux_1 % 3];
  int metric_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_58_2 * 2)) & 127;
  int checksum_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_61_1)
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

  switch (checksum_61_2)
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

  int coefficient_66_1 = 0;
  int coefficient_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_66_1 = ((coefficient_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_66_2 = ((coefficient_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_66_1) & 127;
    acc_2 = (acc_2 + coefficient_66_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_58_1 == metric_58_2);
  assert(checksum_61_1 == checksum_61_2);
  assert(coefficient_66_1 == coefficient_66_2);
}

int fn_R001275_7513_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int metric_58 = local_arr[aux % 3];
  acc = (acc + (metric_58 * 2)) & 127;
  int checksum_61 = (aux + st.buffer[1]) & 3;
  switch (checksum_61)
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

  int coefficient_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_66 = ((coefficient_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_66) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001275_7513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st_1 = {0};
  struct Vector3D_R001275_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_56_1 = local_arr_1[aux_1 % 3];
  int bound_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_56_1 == bound_56_2);
}

int fn_R001275_7513_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_56 = local_arr[aux % 3];
  acc = (acc + (bound_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001275_7513_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st_1 = {0};
  struct Vector3D_R001275_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int metric_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_16_1) & 63;
  aux_2 = (aux_2 + metric_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_15_1 = local_arr_1[aux_1 % 3];
  int margin_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_15_2 * 2)) & 127;
  int tracker_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_42_1)
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

  switch (tracker_42_2)
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

  int margin_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_78_1 > 38)
  {
    acc_1 = ((acc_1 + (margin_78_1 * 2)) + 5) & 127;
    aux_1 ^= margin_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_78_2 > 38)
  {
    acc_2 = ((acc_2 + (margin_78_2 * 2)) + 5) & 127;
    aux_2 ^= margin_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_16_1 == metric_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_15_1 == margin_15_2);
  assert(tracker_42_1 == tracker_42_2);
  assert(margin_78_1 == margin_78_2);
}

int fn_R001275_7513_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int metric_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_16) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_15 = local_arr[aux % 3];
  acc = (acc + (margin_15 * 2)) & 127;
  int tracker_42 = (aux + st.buffer[1]) & 3;
  switch (tracker_42)
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

  int margin_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_78 > 38)
  {
    acc = ((acc + (margin_78 * 2)) + 5) & 127;
    aux ^= margin_78 & 15;
  }
  else
  {
    acc = ((acc - margin_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001275_7513_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001275_7513_3 st_1 = {0};
  struct MatrixBlock_R001275_7513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int checksum_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_71_1 > 24)
  {
    acc_1 = ((acc_1 + (checksum_71_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_71_2 > 24)
  {
    acc_2 = ((acc_2 + (checksum_71_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_13_1) & 63;
  aux_2 = (aux_2 + quantum_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_67_1)
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

  switch (index_reg_67_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_71_1 == checksum_71_2);
  assert(quantum_13_1 == quantum_13_2);
  assert(index_reg_67_1 == index_reg_67_2);
}

int fn_R001275_7513_4(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001275_7513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int checksum_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_71 > 24)
  {
    acc = ((acc + (checksum_71 * 2)) + 5) & 127;
    aux ^= checksum_71 & 15;
  }
  else
  {
    acc = ((acc - checksum_71) + 11) & 127;
    aux += 3;
  }
  int quantum_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_13) & 63;
  acc ^= aux;
  int index_reg_67 = (aux + st.buffer[1]) & 3;
  switch (index_reg_67)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001275_7513_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st_1 = {0};
  struct CipherContext_R001275_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quantum_67_1 = 0;
  int quantum_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_67_1 = ((quantum_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_67_2 = ((quantum_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_67_1) & 127;
    acc_2 = (acc_2 + quantum_67_2) & 127;
  }

  int metric_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_50_1) & 63;
  aux_2 = (aux_2 + metric_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_67_1 == quantum_67_2);
  assert(metric_50_1 == metric_50_2);
}

int fn_R001275_7513_5(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quantum_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_67 = ((quantum_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_67) & 127;
  }

  int metric_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_50) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001275_7513_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st_1 = {0};
  struct Vector3D_R001275_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_69_1) & 63;
  aux_2 = (aux_2 + margin_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_43_1 = local_arr_1[aux_1 % 3];
  int anchor_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_43_2 * 2)) & 127;
  int residue_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_75_1)
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

  switch (residue_75_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_69_1 == margin_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_43_1 == anchor_43_2);
  assert(residue_75_1 == residue_75_2);
}

int fn_R001275_7513_6(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_69) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_43 = local_arr[aux % 3];
  acc = (acc + (anchor_43 * 2)) & 127;
  int residue_75 = (aux + st.buffer[1]) & 3;
  switch (residue_75)
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

void fn_R001275_7513_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st_1 = {0};
  struct Vector3D_R001275_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_47_1 = 0;
  int residue_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_47_1 = ((residue_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_47_2 = ((residue_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_47_1) & 127;
    acc_2 = (acc_2 + residue_47_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_47_1 == residue_47_2);
}

int fn_R001275_7513_7(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_47 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_47 = ((residue_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_47) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001275_7513_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st_1 = {0};
  struct CipherContext_R001275_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int phase_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_38_1) & 63;
  aux_2 = (aux_2 + phase_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_36_1 > 50)
  {
    acc_1 = ((acc_1 + (tracker_36_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_36_2 > 50)
  {
    acc_2 = ((acc_2 + (tracker_36_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_63_1)
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

  switch (pivot_63_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_38_1 == phase_38_2);
  assert(tracker_36_1 == tracker_36_2);
  assert(pivot_63_1 == pivot_63_2);
}

int fn_R001275_7513_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int phase_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_38) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_36 > 50)
  {
    acc = ((acc + (tracker_36 * 2)) + 5) & 127;
    aux ^= tracker_36 & 15;
  }
  else
  {
    acc = ((acc - tracker_36) + 11) & 127;
    aux += 3;
  }
  int pivot_63 = (aux + st.buffer[1]) & 3;
  switch (pivot_63)
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

void fn_R001275_7513_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st_1 = {0};
  struct CipherContext_R001275_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int residue_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_10_1 > 28)
  {
    acc_1 = ((acc_1 + (residue_10_1 * 2)) + 5) & 127;
    aux_1 ^= residue_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_10_2 > 28)
  {
    acc_2 = ((acc_2 + (residue_10_2 * 2)) + 5) & 127;
    aux_2 ^= residue_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_53_1 = 0;
  int sample_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_53_1 = ((sample_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_53_2 = ((sample_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_53_1) & 127;
    acc_2 = (acc_2 + sample_53_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_10_1 == residue_10_2);
  assert(sample_53_1 == sample_53_2);
}

int fn_R001275_7513_9(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int residue_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_10 > 28)
  {
    acc = ((acc + (residue_10 * 2)) + 5) & 127;
    aux ^= residue_10 & 15;
  }
  else
  {
    acc = ((acc - residue_10) + 11) & 127;
    aux += 3;
  }
  int sample_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_53 = ((sample_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_53) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001275_7513_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001275_7513_3 st_1 = {0};
  struct MatrixBlock_R001275_7513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int pivot_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_34_1 > 32)
  {
    acc_1 = ((acc_1 + (pivot_34_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_34_2 > 32)
  {
    acc_2 = ((acc_2 + (pivot_34_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_80_1 = local_arr_1[aux_1 % 3];
  int offset_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_80_2 * 2)) & 127;
  int index_reg_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_86_1)
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

  switch (index_reg_86_2)
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

  int anchor_91_1 = 0;
  int anchor_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_91_1 = ((anchor_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_91_2 = ((anchor_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_91_1) & 127;
    acc_2 = (acc_2 + anchor_91_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_34_1 == pivot_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_80_1 == offset_80_2);
  assert(index_reg_86_1 == index_reg_86_2);
  assert(anchor_91_1 == anchor_91_2);
}

int fn_R001275_7513_10(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001275_7513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int pivot_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_34 > 32)
  {
    acc = ((acc + (pivot_34 * 2)) + 5) & 127;
    aux ^= pivot_34 & 15;
  }
  else
  {
    acc = ((acc - pivot_34) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_80 = local_arr[aux % 3];
  acc = (acc + (offset_80 * 2)) & 127;
  int index_reg_86 = (aux + st.buffer[1]) & 3;
  switch (index_reg_86)
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

  int anchor_91 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_91 = ((anchor_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_91) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001275_7513_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st_1 = {0};
  struct CipherContext_R001275_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int window_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_49_1)
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

  switch (window_49_2)
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

  int tally_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_58_1 > 38)
  {
    acc_1 = ((acc_1 + (tally_58_1 * 2)) + 5) & 127;
    aux_1 ^= tally_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_58_2 > 38)
  {
    acc_2 = ((acc_2 + (tally_58_2 * 2)) + 5) & 127;
    aux_2 ^= tally_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_74_1 = local_arr_1[aux_1 % 3];
  int vector_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_49_1 == window_49_2);
  assert(tally_58_1 == tally_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_74_1 == vector_74_2);
}

int fn_R001275_7513_11(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int window_49 = (aux + st.buffer[1]) & 3;
  switch (window_49)
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

  int tally_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_58 > 38)
  {
    acc = ((acc + (tally_58 * 2)) + 5) & 127;
    aux ^= tally_58 & 15;
  }
  else
  {
    acc = ((acc - tally_58) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_74 = local_arr[aux % 3];
  acc = (acc + (vector_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001275_7513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st_1 = {0};
  struct Vector3D_R001275_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int checksum_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_20_1 > 26)
  {
    acc_1 = ((acc_1 + (checksum_20_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_20_2 > 26)
  {
    acc_2 = ((acc_2 + (checksum_20_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_74_1) & 63;
  aux_2 = (aux_2 + offset_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_57_1 = 0;
  int factor_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_57_1 = ((factor_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_57_2 = ((factor_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_57_1) & 127;
    acc_2 = (acc_2 + factor_57_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_82_1 = local_arr_1[aux_1 % 3];
  int sample_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_20_1 == checksum_20_2);
  assert(offset_74_1 == offset_74_2);
  assert(factor_57_1 == factor_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_82_1 == sample_82_2);
}

int fn_R001275_7513_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int checksum_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_20 > 26)
  {
    acc = ((acc + (checksum_20 * 2)) + 5) & 127;
    aux ^= checksum_20 & 15;
  }
  else
  {
    acc = ((acc - checksum_20) + 11) & 127;
    aux += 3;
  }
  int offset_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_74) & 63;
  acc ^= aux;
  int factor_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_57 = ((factor_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_57) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_82 = local_arr[aux % 3];
  acc = (acc + (sample_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001275_7513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001275_7513_2 st_1 = {0};
  struct Transaction_R001275_7513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int tracker_53_1 = 0;
  int tracker_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_53_1 = ((tracker_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_53_2 = ((tracker_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_53_1) & 127;
    acc_2 = (acc_2 + tracker_53_2) & 127;
  }

  int bound_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_39_1 > 13)
  {
    acc_1 = ((acc_1 + (bound_39_1 * 2)) + 5) & 127;
    aux_1 ^= bound_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_39_2 > 13)
  {
    acc_2 = ((acc_2 + (bound_39_2 * 2)) + 5) & 127;
    aux_2 ^= bound_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_53_1 == tracker_53_2);
  assert(bound_39_1 == bound_39_2);
}

int fn_R001275_7513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001275_7513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int tracker_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_53 = ((tracker_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_53) & 127;
  }

  int bound_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_39 > 13)
  {
    acc = ((acc + (bound_39 * 2)) + 5) & 127;
    aux ^= bound_39 & 15;
  }
  else
  {
    acc = ((acc - bound_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001275_7513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001275_7513_2 st_1 = {0};
  struct Transaction_R001275_7513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int segment_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_49_1) & 63;
  aux_2 = (aux_2 + segment_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_49_1 == segment_49_2);
}

int fn_R001275_7513_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001275_7513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int segment_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_49) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001275_7513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001275_7513_2 st_1 = {0};
  struct Transaction_R001275_7513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int coefficient_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_15_1 > 46)
  {
    acc_1 = ((acc_1 + (coefficient_15_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_15_2 > 46)
  {
    acc_2 = ((acc_2 + (coefficient_15_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_78_1)
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

  switch (anchor_78_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_15_1 == coefficient_15_2);
  assert(anchor_78_1 == anchor_78_2);
}

int fn_R001275_7513_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001275_7513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int coefficient_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_15 > 46)
  {
    acc = ((acc + (coefficient_15 * 2)) + 5) & 127;
    aux ^= coefficient_15 & 15;
  }
  else
  {
    acc = ((acc - coefficient_15) + 11) & 127;
    aux += 3;
  }
  int anchor_78 = (aux + st.buffer[1]) & 3;
  switch (anchor_78)
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

void fn_R001275_7513_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st_1 = {0};
  struct Vector3D_R001275_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int accumulator_78_1 = 0;
  int accumulator_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_78_1 = ((accumulator_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_78_2 = ((accumulator_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_78_1) & 127;
    acc_2 = (acc_2 + accumulator_78_2) & 127;
  }

  int mask_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_18_1 > 22)
  {
    acc_1 = ((acc_1 + (mask_18_1 * 2)) + 5) & 127;
    aux_1 ^= mask_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_18_2 > 22)
  {
    acc_2 = ((acc_2 + (mask_18_2 * 2)) + 5) & 127;
    aux_2 ^= mask_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_18_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_31_1 = local_arr_1[aux_1 % 3];
  int window_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_78_1 == accumulator_78_2);
  assert(mask_18_1 == mask_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_31_1 == window_31_2);
}

int fn_R001275_7513_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int accumulator_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_78 = ((accumulator_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_78) & 127;
  }

  int mask_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_18 > 22)
  {
    acc = ((acc + (mask_18 * 2)) + 5) & 127;
    aux ^= mask_18 & 15;
  }
  else
  {
    acc = ((acc - mask_18) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int window_31 = local_arr[aux % 3];
  acc = (acc + (window_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001275_7513_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001275_7513_3 st_1 = {0};
  struct MatrixBlock_R001275_7513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_83_1 = 0;
  int accumulator_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_83_1 = ((accumulator_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_83_2 = ((accumulator_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_83_1) & 127;
    acc_2 = (acc_2 + accumulator_83_2) & 127;
  }

  int vector_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_70_1 > 20)
  {
    acc_1 = ((acc_1 + (vector_70_1 * 2)) + 5) & 127;
    aux_1 ^= vector_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_70_2 > 20)
  {
    acc_2 = ((acc_2 + (vector_70_2 * 2)) + 5) & 127;
    aux_2 ^= vector_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_83_1 == accumulator_83_2);
  assert(vector_70_1 == vector_70_2);
}

int fn_R001275_7513_17(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001275_7513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_83 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_83 = ((accumulator_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_83) & 127;
  }

  int vector_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_70 > 20)
  {
    acc = ((acc + (vector_70 * 2)) + 5) & 127;
    aux ^= vector_70 & 15;
  }
  else
  {
    acc = ((acc - vector_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001275_7513_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st_1 = {0};
  struct CipherContext_R001275_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int factor_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_69_1) & 63;
  aux_2 = (aux_2 + factor_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_10_1)
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

  switch (residue_10_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_65_1 = local_arr_1[aux_1 % 3];
  int quotient_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_65_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_69_1 == factor_69_2);
  assert(residue_10_1 == residue_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_65_1 == quotient_65_2);
}

int fn_R001275_7513_18(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int factor_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_69) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_10 = (aux + st.buffer[1]) & 3;
  switch (residue_10)
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

  int local_arr[3] = {4, 9, 15};
  int quotient_65 = local_arr[aux % 3];
  acc = (acc + (quotient_65 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001275_7513_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st_1 = {0};
  struct CipherContext_R001275_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int parity_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_10_1) & 63;
  aux_2 = (aux_2 + parity_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_27_1 = local_arr_1[aux_1 % 3];
  int offset_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_27_2 * 2)) & 127;
  int parity_16_1 = 0;
  int parity_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_16_1 = ((parity_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_16_2 = ((parity_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_16_1) & 127;
    acc_2 = (acc_2 + parity_16_2) & 127;
  }

  int cursor_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_11_1)
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

  switch (cursor_11_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_10_1 == parity_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_27_1 == offset_27_2);
  assert(parity_16_1 == parity_16_2);
  assert(cursor_11_1 == cursor_11_2);
}

int fn_R001275_7513_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001275_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int parity_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_10) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_27 = local_arr[aux % 3];
  acc = (acc + (offset_27 * 2)) & 127;
  int parity_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_16 = ((parity_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_16) & 127;
  }

  int cursor_11 = (aux + st.buffer[1]) & 3;
  switch (cursor_11)
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

void fn_R001275_7513_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001275_7513_3 st_1 = {0};
  struct MatrixBlock_R001275_7513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int offset_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_36_1 > 20)
  {
    acc_1 = ((acc_1 + (offset_36_1 * 2)) + 5) & 127;
    aux_1 ^= offset_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_36_2 > 20)
  {
    acc_2 = ((acc_2 + (offset_36_2 * 2)) + 5) & 127;
    aux_2 ^= offset_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_67_1 = local_arr_1[aux_1 % 3];
  int sample_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_36_1 == offset_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_67_1 == sample_67_2);
}

int fn_R001275_7513_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001275_7513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int offset_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_36 > 20)
  {
    acc = ((acc + (offset_36 * 2)) + 5) & 127;
    aux ^= offset_36 & 15;
  }
  else
  {
    acc = ((acc - offset_36) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_67 = local_arr[aux % 3];
  acc = (acc + (sample_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001275_7513_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001275_7513_2 st_1 = {0};
  struct Transaction_R001275_7513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int sample_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_31_1 > 32)
  {
    acc_1 = ((acc_1 + (sample_31_1 * 2)) + 5) & 127;
    aux_1 ^= sample_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_31_2 > 32)
  {
    acc_2 = ((acc_2 + (sample_31_2 * 2)) + 5) & 127;
    aux_2 ^= sample_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_65_1 = 0;
  int quantum_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_65_1 = ((quantum_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_65_2 = ((quantum_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_65_1) & 127;
    acc_2 = (acc_2 + quantum_65_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_17_1 = local_arr_1[aux_1 % 3];
  int tally_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_17_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_31_1 == sample_31_2);
  assert(quantum_65_1 == quantum_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_17_1 == tally_17_2);
}

int fn_R001275_7513_21(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001275_7513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int sample_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_31 > 32)
  {
    acc = ((acc + (sample_31 * 2)) + 5) & 127;
    aux ^= sample_31 & 15;
  }
  else
  {
    acc = ((acc - sample_31) + 11) & 127;
    aux += 3;
  }
  int quantum_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_65 = ((quantum_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_65) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tally_17 = local_arr[aux % 3];
  acc = (acc + (tally_17 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001275_7513_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st_1 = {0};
  struct Vector3D_R001275_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int accumulator_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_48_1)
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

  switch (accumulator_48_2)
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

  int phase_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_35_1 > 18)
  {
    acc_1 = ((acc_1 + (phase_35_1 * 2)) + 5) & 127;
    aux_1 ^= phase_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_35_2 > 18)
  {
    acc_2 = ((acc_2 + (phase_35_2 * 2)) + 5) & 127;
    aux_2 ^= phase_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_57_1) & 63;
  aux_2 = (aux_2 + damping_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_48_1 == accumulator_48_2);
  assert(phase_35_1 == phase_35_2);
  assert(damping_57_1 == damping_57_2);
}

int fn_R001275_7513_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001275_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int accumulator_48 = (aux + st.buffer[1]) & 3;
  switch (accumulator_48)
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

  int phase_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_35 > 18)
  {
    acc = ((acc + (phase_35 * 2)) + 5) & 127;
    aux ^= phase_35 & 15;
  }
  else
  {
    acc = ((acc - phase_35) + 11) & 127;
    aux += 3;
  }
  int damping_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001275_7513_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001275_7513_3 st_1 = {0};
  struct MatrixBlock_R001275_7513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int threshold_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_10_1)
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

  switch (threshold_10_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_10_1 == threshold_10_2);
}

int fn_R001275_7513_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001275_7513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int threshold_10 = (aux + st.buffer[1]) & 3;
  switch (threshold_10)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001275_0_1;
  int sec_r001275_0_2;
  int sec_r001275_1_1;
  int sec_r001275_1_2;
  int sec_r001275_2_1;
  int sec_r001275_2_2;
  int sec_r001275_3_1;
  int sec_r001275_3_2;
  int sec_r001275_4_1;
  int sec_r001275_4_2;
  int sec_r001275_5_1;
  int sec_r001275_5_2;
  int sec_r001275_6_1;
  int sec_r001275_6_2;
  int sec_r001275_7_1;
  int sec_r001275_7_2;
  int sec_r001275_8_1;
  int sec_r001275_8_2;
  int sec_r001275_9_1;
  int sec_r001275_9_2;
  int sec_r001275_10_1;
  int sec_r001275_10_2;
  int sec_r001275_11_1;
  int sec_r001275_11_2;
  int sec_r001275_12_1;
  int sec_r001275_12_2;
  int sec_r001275_13_1;
  int sec_r001275_13_2;
  int sec_r001275_14_1;
  int sec_r001275_14_2;
  int sec_r001275_15_1;
  int sec_r001275_15_2;
  int sec_r001275_16_1;
  int sec_r001275_16_2;
  int sec_r001275_17_1;
  int sec_r001275_17_2;
  int sec_r001275_18_1;
  int sec_r001275_18_2;
  int sec_r001275_19_1;
  int sec_r001275_19_2;
  int sec_r001275_20_1;
  int sec_r001275_20_2;
  int sec_r001275_21_1;
  int sec_r001275_21_2;
  int pub_r001275_0_1;
  int pub_r001275_0_2;
  int pub_r001275_1_1;
  int pub_r001275_1_2;
  int pub_r001275_2_1;
  int pub_r001275_2_2;
  int pub_r001275_3_1;
  int pub_r001275_3_2;
  int pub_r001275_4_1;
  int pub_r001275_4_2;
  int pub_r001275_5_1;
  int pub_r001275_5_2;
  int pub_r001275_6_1;
  int pub_r001275_6_2;
  int pub_r001275_7_1;
  int pub_r001275_7_2;
  int pub_r001275_8_1;
  int pub_r001275_8_2;
  int pub_r001275_9_1;
  int pub_r001275_9_2;
  int pub_r001275_10_1;
  int pub_r001275_10_2;
  int pub_r001275_11_1;
  int pub_r001275_11_2;
  int pub_r001275_12_1;
  int pub_r001275_12_2;
  int pub_r001275_13_1;
  int pub_r001275_13_2;
  int pub_r001275_14_1;
  int pub_r001275_14_2;
  int pub_r001275_15_1;
  int pub_r001275_15_2;
  int pub_r001275_16_1;
  int pub_r001275_16_2;
  int pub_r001275_17_1;
  int pub_r001275_17_2;
  int pub_r001275_18_1;
  int pub_r001275_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001275_0_1 >= (-100)) && (pub_r001275_0_1 <= 100));
  __CPROVER_assume((pub_r001275_0_2 >= (-100)) && (pub_r001275_0_2 <= 100));
  __CPROVER_assume((pub_r001275_1_1 >= (-100)) && (pub_r001275_1_1 <= 100));
  __CPROVER_assume((pub_r001275_1_2 >= (-100)) && (pub_r001275_1_2 <= 100));
  __CPROVER_assume((pub_r001275_2_1 >= (-100)) && (pub_r001275_2_1 <= 100));
  __CPROVER_assume((pub_r001275_2_2 >= (-100)) && (pub_r001275_2_2 <= 100));
  __CPROVER_assume((pub_r001275_3_1 >= (-100)) && (pub_r001275_3_1 <= 100));
  __CPROVER_assume((pub_r001275_3_2 >= (-100)) && (pub_r001275_3_2 <= 100));
  __CPROVER_assume((pub_r001275_4_1 >= (-100)) && (pub_r001275_4_1 <= 100));
  __CPROVER_assume((pub_r001275_4_2 >= (-100)) && (pub_r001275_4_2 <= 100));
  __CPROVER_assume((pub_r001275_5_1 >= (-100)) && (pub_r001275_5_1 <= 100));
  __CPROVER_assume((pub_r001275_5_2 >= (-100)) && (pub_r001275_5_2 <= 100));
  __CPROVER_assume((pub_r001275_6_1 >= (-100)) && (pub_r001275_6_1 <= 100));
  __CPROVER_assume((pub_r001275_6_2 >= (-100)) && (pub_r001275_6_2 <= 100));
  __CPROVER_assume((pub_r001275_7_1 >= (-100)) && (pub_r001275_7_1 <= 100));
  __CPROVER_assume((pub_r001275_7_2 >= (-100)) && (pub_r001275_7_2 <= 100));
  __CPROVER_assume((pub_r001275_8_1 >= (-100)) && (pub_r001275_8_1 <= 100));
  __CPROVER_assume((pub_r001275_8_2 >= (-100)) && (pub_r001275_8_2 <= 100));
  __CPROVER_assume((pub_r001275_9_1 >= (-100)) && (pub_r001275_9_1 <= 100));
  __CPROVER_assume((pub_r001275_9_2 >= (-100)) && (pub_r001275_9_2 <= 100));
  __CPROVER_assume((pub_r001275_10_1 >= (-100)) && (pub_r001275_10_1 <= 100));
  __CPROVER_assume((pub_r001275_10_2 >= (-100)) && (pub_r001275_10_2 <= 100));
  __CPROVER_assume((pub_r001275_11_1 >= (-100)) && (pub_r001275_11_1 <= 100));
  __CPROVER_assume((pub_r001275_11_2 >= (-100)) && (pub_r001275_11_2 <= 100));
  __CPROVER_assume((pub_r001275_12_1 >= (-100)) && (pub_r001275_12_1 <= 100));
  __CPROVER_assume((pub_r001275_12_2 >= (-100)) && (pub_r001275_12_2 <= 100));
  __CPROVER_assume((pub_r001275_13_1 >= (-100)) && (pub_r001275_13_1 <= 100));
  __CPROVER_assume((pub_r001275_13_2 >= (-100)) && (pub_r001275_13_2 <= 100));
  __CPROVER_assume((pub_r001275_14_1 >= (-100)) && (pub_r001275_14_1 <= 100));
  __CPROVER_assume((pub_r001275_14_2 >= (-100)) && (pub_r001275_14_2 <= 100));
  __CPROVER_assume((pub_r001275_15_1 >= (-100)) && (pub_r001275_15_1 <= 100));
  __CPROVER_assume((pub_r001275_15_2 >= (-100)) && (pub_r001275_15_2 <= 100));
  __CPROVER_assume((pub_r001275_16_1 >= (-100)) && (pub_r001275_16_1 <= 100));
  __CPROVER_assume((pub_r001275_16_2 >= (-100)) && (pub_r001275_16_2 <= 100));
  __CPROVER_assume((pub_r001275_17_1 >= (-100)) && (pub_r001275_17_1 <= 100));
  __CPROVER_assume((pub_r001275_17_2 >= (-100)) && (pub_r001275_17_2 <= 100));
  __CPROVER_assume((pub_r001275_18_1 >= (-100)) && (pub_r001275_18_1 <= 100));
  __CPROVER_assume((pub_r001275_18_2 >= (-100)) && (pub_r001275_18_2 <= 100));
  __CPROVER_assume((sec_r001275_0_1 >= 0) && (sec_r001275_0_1 <= 255));
  __CPROVER_assume((sec_r001275_0_2 >= 0) && (sec_r001275_0_2 <= 255));
  __CPROVER_assume((sec_r001275_1_1 >= 0) && (sec_r001275_1_1 <= 255));
  __CPROVER_assume((sec_r001275_1_2 >= 0) && (sec_r001275_1_2 <= 255));
  __CPROVER_assume((sec_r001275_2_1 >= 0) && (sec_r001275_2_1 <= 255));
  __CPROVER_assume((sec_r001275_2_2 >= 0) && (sec_r001275_2_2 <= 255));
  __CPROVER_assume((sec_r001275_3_1 >= 0) && (sec_r001275_3_1 <= 255));
  __CPROVER_assume((sec_r001275_3_2 >= 0) && (sec_r001275_3_2 <= 255));
  __CPROVER_assume((sec_r001275_4_1 >= 0) && (sec_r001275_4_1 <= 255));
  __CPROVER_assume((sec_r001275_4_2 >= 0) && (sec_r001275_4_2 <= 255));
  __CPROVER_assume((sec_r001275_5_1 >= 0) && (sec_r001275_5_1 <= 255));
  __CPROVER_assume((sec_r001275_5_2 >= 0) && (sec_r001275_5_2 <= 255));
  __CPROVER_assume((sec_r001275_6_1 >= 0) && (sec_r001275_6_1 <= 255));
  __CPROVER_assume((sec_r001275_6_2 >= 0) && (sec_r001275_6_2 <= 255));
  __CPROVER_assume((sec_r001275_7_1 >= 0) && (sec_r001275_7_1 <= 255));
  __CPROVER_assume((sec_r001275_7_2 >= 0) && (sec_r001275_7_2 <= 255));
  __CPROVER_assume((sec_r001275_8_1 >= 0) && (sec_r001275_8_1 <= 255));
  __CPROVER_assume((sec_r001275_8_2 >= 0) && (sec_r001275_8_2 <= 255));
  __CPROVER_assume((sec_r001275_9_1 >= 0) && (sec_r001275_9_1 <= 255));
  __CPROVER_assume((sec_r001275_9_2 >= 0) && (sec_r001275_9_2 <= 255));
  __CPROVER_assume((sec_r001275_10_1 >= 0) && (sec_r001275_10_1 <= 255));
  __CPROVER_assume((sec_r001275_10_2 >= 0) && (sec_r001275_10_2 <= 255));
  __CPROVER_assume((sec_r001275_11_1 >= 0) && (sec_r001275_11_1 <= 255));
  __CPROVER_assume((sec_r001275_11_2 >= 0) && (sec_r001275_11_2 <= 255));
  __CPROVER_assume((sec_r001275_12_1 >= 0) && (sec_r001275_12_1 <= 255));
  __CPROVER_assume((sec_r001275_12_2 >= 0) && (sec_r001275_12_2 <= 255));
  __CPROVER_assume((sec_r001275_13_1 >= 0) && (sec_r001275_13_1 <= 255));
  __CPROVER_assume((sec_r001275_13_2 >= 0) && (sec_r001275_13_2 <= 255));
  __CPROVER_assume((sec_r001275_14_1 >= 0) && (sec_r001275_14_1 <= 255));
  __CPROVER_assume((sec_r001275_14_2 >= 0) && (sec_r001275_14_2 <= 255));
  __CPROVER_assume((sec_r001275_15_1 >= 0) && (sec_r001275_15_1 <= 255));
  __CPROVER_assume((sec_r001275_15_2 >= 0) && (sec_r001275_15_2 <= 255));
  __CPROVER_assume((sec_r001275_16_1 >= 0) && (sec_r001275_16_1 <= 255));
  __CPROVER_assume((sec_r001275_16_2 >= 0) && (sec_r001275_16_2 <= 255));
  __CPROVER_assume((sec_r001275_17_1 >= 0) && (sec_r001275_17_1 <= 255));
  __CPROVER_assume((sec_r001275_17_2 >= 0) && (sec_r001275_17_2 <= 255));
  __CPROVER_assume((sec_r001275_18_1 >= 0) && (sec_r001275_18_1 <= 255));
  __CPROVER_assume((sec_r001275_18_2 >= 0) && (sec_r001275_18_2 <= 255));
  __CPROVER_assume((sec_r001275_19_1 >= 0) && (sec_r001275_19_1 <= 255));
  __CPROVER_assume((sec_r001275_19_2 >= 0) && (sec_r001275_19_2 <= 255));
  __CPROVER_assume((sec_r001275_20_1 >= 0) && (sec_r001275_20_1 <= 255));
  __CPROVER_assume((sec_r001275_20_2 >= 0) && (sec_r001275_20_2 <= 255));
  __CPROVER_assume((sec_r001275_21_1 >= 0) && (sec_r001275_21_1 <= 255));
  __CPROVER_assume((sec_r001275_21_2 >= 0) && (sec_r001275_21_2 <= 255));
  struct CipherContext_R001275_7513_0 st_var_0_1 = {0};
  struct CipherContext_R001275_7513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001275_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001275_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001275_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001275_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001275_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001275_0_2 + 7) & 15;
  struct Vector3D_R001275_7513_1 st_var_1_1 = {0};
  struct Vector3D_R001275_7513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001275_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001275_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001275_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001275_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001275_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001275_0_2 + 9) & 15;
  struct Transaction_R001275_7513_2 st_var_2_1 = {0};
  struct Transaction_R001275_7513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001275_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001275_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001275_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001275_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001275_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001275_0_2 + 11) & 15;
  struct MatrixBlock_R001275_7513_3 st_var_3_1 = {0};
  struct MatrixBlock_R001275_7513_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001275_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001275_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001275_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001275_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001275_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001275_0_2 + 13) & 15;
  union ColorPixel_R001275_7513_0 u_var_1;
  union ColorPixel_R001275_7513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001275_7513_0(sec_r001275_0_1, pub_r001275_1_1, pub_r001275_2_1, pub_r001275_3_1);
  int helper_flow_0_2 = fn_R001275_7513_0(sec_r001275_0_2, pub_r001275_1_2, pub_r001275_2_2, pub_r001275_3_2);
  fn_R001275_7513_0_2(sec_r001275_0_1, pub_r001275_1_1, pub_r001275_2_1, pub_r001275_3_1, sec_r001275_0_2, pub_r001275_1_2, pub_r001275_2_2, pub_r001275_3_2);
  int helper_flow_1_1 = fn_R001275_7513_1(sec_r001275_1_1, sec_r001275_2_1, pub_r001275_3_1, pub_r001275_4_1, pub_r001275_5_1);
  int helper_flow_1_2 = fn_R001275_7513_1(sec_r001275_1_2, sec_r001275_2_2, pub_r001275_3_2, pub_r001275_4_2, pub_r001275_5_2);
  fn_R001275_7513_1_2(sec_r001275_1_1, sec_r001275_2_1, pub_r001275_3_1, pub_r001275_4_1, pub_r001275_5_1, sec_r001275_1_2, sec_r001275_2_2, pub_r001275_3_2, pub_r001275_4_2, pub_r001275_5_2);
  int helper_flow_2_1 = fn_R001275_7513_2(sec_r001275_2_1, pub_r001275_3_1, pub_r001275_4_1, pub_r001275_5_1);
  int helper_flow_2_2 = fn_R001275_7513_2(sec_r001275_2_2, pub_r001275_3_2, pub_r001275_4_2, pub_r001275_5_2);
  fn_R001275_7513_2_2(sec_r001275_2_1, pub_r001275_3_1, pub_r001275_4_1, pub_r001275_5_1, sec_r001275_2_2, pub_r001275_3_2, pub_r001275_4_2, pub_r001275_5_2);
  int helper_flow_3_1 = fn_R001275_7513_3(sec_r001275_3_1, sec_r001275_4_1, pub_r001275_5_1, pub_r001275_6_1);
  int helper_flow_3_2 = fn_R001275_7513_3(sec_r001275_3_2, sec_r001275_4_2, pub_r001275_5_2, pub_r001275_6_2);
  fn_R001275_7513_3_2(sec_r001275_3_1, sec_r001275_4_1, pub_r001275_5_1, pub_r001275_6_1, sec_r001275_3_2, sec_r001275_4_2, pub_r001275_5_2, pub_r001275_6_2);
  int helper_flow_4_1 = fn_R001275_7513_4(sec_r001275_4_1, sec_r001275_5_1);
  int helper_flow_4_2 = fn_R001275_7513_4(sec_r001275_4_2, sec_r001275_5_2);
  fn_R001275_7513_4_2(sec_r001275_4_1, sec_r001275_5_1, sec_r001275_4_2, sec_r001275_5_2);
  int helper_flow_5_1 = fn_R001275_7513_5(sec_r001275_5_1, sec_r001275_6_1, pub_r001275_7_1);
  int helper_flow_5_2 = fn_R001275_7513_5(sec_r001275_5_2, sec_r001275_6_2, pub_r001275_7_2);
  fn_R001275_7513_5_2(sec_r001275_5_1, sec_r001275_6_1, pub_r001275_7_1, sec_r001275_5_2, sec_r001275_6_2, pub_r001275_7_2);
  int stage_v_0_1 = ((sec_r001275_10_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_0_2 = ((sec_r001275_10_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_0_2 + 1) & 15;
  out_sink_1 ^= stage_v_0_1 & 63;
  out_sink_2 ^= stage_v_0_2 & 63;
  int stage_v_1_1 = ((sec_r001275_8_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_1_2 = ((sec_r001275_8_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_1_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_1_2 + 1) & 15;
  out_sink_1 ^= stage_v_1_1 & 63;
  out_sink_2 ^= stage_v_1_2 & 63;
  int stage_v_2_1 = ((helper_flow_0_1 << 1) ^ (pub_r001275_11_1 >> 1)) & 127;
  int stage_v_2_2 = ((helper_flow_0_2 << 1) ^ (pub_r001275_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_2_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_2_2 + 1) & 15;
  out_sink_1 ^= stage_v_2_1 & 63;
  out_sink_2 ^= stage_v_2_2 & 63;
  int stage_v_3_1 = ((pub_r001275_17_1 * 2) + 15) & 63;
  int stage_v_3_2 = ((pub_r001275_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001275_16_1 * 2) + 27) & 63;
  int stage_v_4_2 = ((pub_r001275_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001275_10_1 * 2) + 34) & 63;
  int stage_v_5_2 = ((pub_r001275_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((sec_r001275_19_1 << 1) ^ (pub_r001275_16_1 >> 1)) & 127;
  int stage_v_6_2 = ((sec_r001275_19_2 << 1) ^ (pub_r001275_16_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((stage_v_2_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_7_2 = ((stage_v_2_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_7_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_7_2 + 1) & 15;
  out_sink_1 ^= stage_v_7_1 & 63;
  out_sink_2 ^= stage_v_7_2 & 63;
  int stage_v_8_1 = ((stage_v_2_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_8_2 = ((stage_v_2_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((pub_r001275_8_1 * 2) + 15) & 63;
  int stage_v_9_2 = ((pub_r001275_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((sec_r001275_0_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_10_2 = ((sec_r001275_0_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((stage_v_2_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_11_2 = ((stage_v_2_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((pub_r001275_1_1 * 2) + 29) & 63;
  int stage_v_12_2 = ((pub_r001275_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((sec_r001275_18_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_13_2 = ((sec_r001275_18_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_13_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_13_2 + 1) & 15;
  out_sink_1 ^= stage_v_13_1 & 63;
  out_sink_2 ^= stage_v_13_2 & 63;
  int stage_v_14_1 = ((stage_v_10_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_14_2 = ((stage_v_10_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((sec_r001275_5_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_15_2 = ((sec_r001275_5_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((helper_flow_1_1 << 1) ^ (pub_r001275_5_1 >> 1)) & 127;
  int stage_v_16_2 = ((helper_flow_1_2 << 1) ^ (pub_r001275_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_16_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_16_2 + 1) & 15;
  out_sink_1 ^= stage_v_16_1 & 63;
  out_sink_2 ^= stage_v_16_2 & 63;
  int stage_v_17_1 = ((pub_r001275_14_1 * 2) + 13) & 63;
  int stage_v_17_2 = ((pub_r001275_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((stage_v_7_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_18_2 = ((stage_v_7_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_18_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_18_2 + 1) & 15;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = ((stage_v_14_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_19_2 = ((stage_v_14_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_19_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_19_2 + 1) & 15;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = ((sec_r001275_21_1 << 1) ^ (pub_r001275_2_1 >> 1)) & 127;
  int stage_v_20_2 = ((sec_r001275_21_2 << 1) ^ (pub_r001275_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((pub_r001275_9_1 * 2) + 35) & 63;
  int stage_v_21_2 = ((pub_r001275_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001275_2_1 * 2) + 17) & 63;
  int stage_v_22_2 = ((pub_r001275_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001275_8_1 * 2) + 24) & 63;
  int stage_v_23_2 = ((pub_r001275_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001275_4_1 * 2) + 29) & 63;
  int stage_v_24_2 = ((pub_r001275_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((sec_r001275_15_1 << 1) ^ (pub_r001275_0_1 >> 1)) & 127;
  int stage_v_25_2 = ((sec_r001275_15_2 << 1) ^ (pub_r001275_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_25_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_25_2 + 1) & 15;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = ((pub_r001275_17_1 * 2) + 33) & 63;
  int stage_v_26_2 = ((pub_r001275_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((helper_flow_5_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_27_2 = ((helper_flow_5_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_27_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_27_2 + 1) & 15;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = ((sec_r001275_5_1 << 1) ^ (pub_r001275_16_1 >> 1)) & 127;
  int stage_v_28_2 = ((sec_r001275_5_2 << 1) ^ (pub_r001275_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_28_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_28_2 + 1) & 15;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = ((stage_v_0_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_29_2 = ((stage_v_0_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_29_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_29_2 + 1) & 15;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = ((sec_r001275_1_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_30_2 = ((sec_r001275_1_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_30_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_30_2 + 1) & 15;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = ((stage_v_1_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_31_2 = ((stage_v_1_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_31_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_31_2 + 1) & 15;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = ((sec_r001275_17_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_32_2 = ((sec_r001275_17_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_32_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_32_2 + 1) & 15;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = ((stage_v_16_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_33_2 = ((stage_v_16_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_33_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_33_2 + 1) & 15;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = ((stage_v_18_1 << 1) ^ (pub_r001275_1_1 >> 1)) & 127;
  int stage_v_34_2 = ((stage_v_18_2 << 1) ^ (pub_r001275_1_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((pub_r001275_13_1 * 2) + 35) & 63;
  int stage_v_35_2 = ((pub_r001275_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((sec_r001275_8_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_36_2 = ((sec_r001275_8_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((pub_r001275_6_1 * 2) + 7) & 63;
  int stage_v_37_2 = ((pub_r001275_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001275_15_1 * 2) + 16) & 63;
  int stage_v_38_2 = ((pub_r001275_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((stage_v_0_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_39_2 = ((stage_v_0_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((sec_r001275_12_1 << 1) ^ (pub_r001275_0_1 >> 1)) & 127;
  int stage_v_40_2 = ((sec_r001275_12_2 << 1) ^ (pub_r001275_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_40_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_40_2 + 1) & 15;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = ((stage_v_13_1 << 1) ^ (pub_r001275_17_1 >> 1)) & 127;
  int stage_v_41_2 = ((stage_v_13_2 << 1) ^ (pub_r001275_17_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((helper_flow_4_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_42_2 = ((helper_flow_4_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((stage_v_16_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_43_2 = ((stage_v_16_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((pub_r001275_6_1 * 2) + 40) & 63;
  int stage_v_44_2 = ((pub_r001275_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((sec_r001275_5_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_45_2 = ((sec_r001275_5_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_45_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_45_2 + 1) & 15;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = ((stage_v_30_1 << 1) ^ (pub_r001275_9_1 >> 1)) & 127;
  int stage_v_46_2 = ((stage_v_30_2 << 1) ^ (pub_r001275_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_46_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_46_2 + 1) & 15;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = ((pub_r001275_13_1 * 2) + 10) & 63;
  int stage_v_47_2 = ((pub_r001275_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001275_2_1 * 2) + 29) & 63;
  int stage_v_48_2 = ((pub_r001275_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((sec_r001275_0_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_49_2 = ((sec_r001275_0_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((helper_flow_1_1 << 1) ^ (pub_r001275_17_1 >> 1)) & 127;
  int stage_v_50_2 = ((helper_flow_1_2 << 1) ^ (pub_r001275_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_50_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_50_2 + 1) & 15;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = ((sec_r001275_18_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_51_2 = ((sec_r001275_18_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_51_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_51_2 + 1) & 15;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = ((sec_r001275_21_1 << 1) ^ (pub_r001275_16_1 >> 1)) & 127;
  int stage_v_52_2 = ((sec_r001275_21_2 << 1) ^ (pub_r001275_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_52_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_52_2 + 1) & 15;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = ((pub_r001275_13_1 * 2) + 29) & 63;
  int stage_v_53_2 = ((pub_r001275_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((sec_r001275_19_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_54_2 = ((sec_r001275_19_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((pub_r001275_3_1 * 2) + 19) & 63;
  int stage_v_55_2 = ((pub_r001275_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((stage_v_40_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_56_2 = ((stage_v_40_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_56_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_56_2 + 1) & 15;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = ((pub_r001275_1_1 * 2) + 18) & 63;
  int stage_v_57_2 = ((pub_r001275_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((stage_v_13_1 << 1) ^ (pub_r001275_1_1 >> 1)) & 127;
  int stage_v_58_2 = ((stage_v_13_2 << 1) ^ (pub_r001275_1_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_58_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_58_2 + 1) & 15;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = ((stage_v_14_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_59_2 = ((stage_v_14_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_59_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_59_2 + 1) & 15;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = ((pub_r001275_7_1 * 2) + 48) & 63;
  int stage_v_60_2 = ((pub_r001275_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001275_11_1 * 2) + 18) & 63;
  int stage_v_61_2 = ((pub_r001275_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001275_8_1 * 2) + 22) & 63;
  int stage_v_62_2 = ((pub_r001275_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((stage_v_51_1 << 1) ^ (pub_r001275_17_1 >> 1)) & 127;
  int stage_v_63_2 = ((stage_v_51_2 << 1) ^ (pub_r001275_17_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_63_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_63_2 + 1) & 15;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = ((stage_v_31_1 << 1) ^ (pub_r001275_6_1 >> 1)) & 127;
  int stage_v_64_2 = ((stage_v_31_2 << 1) ^ (pub_r001275_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_64_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_64_2 + 1) & 15;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = ((pub_r001275_13_1 * 2) + 8) & 63;
  int stage_v_65_2 = ((pub_r001275_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001275_2_1 * 2) + 28) & 63;
  int stage_v_66_2 = ((pub_r001275_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((stage_v_2_1 << 1) ^ (pub_r001275_16_1 >> 1)) & 127;
  int stage_v_67_2 = ((stage_v_2_2 << 1) ^ (pub_r001275_16_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_67_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_67_2 + 1) & 15;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = ((stage_v_41_1 << 1) ^ (pub_r001275_17_1 >> 1)) & 127;
  int stage_v_68_2 = ((stage_v_41_2 << 1) ^ (pub_r001275_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_68_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_68_2 + 1) & 15;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = ((sec_r001275_5_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_69_2 = ((sec_r001275_5_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_69_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_69_2 + 1) & 15;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = ((pub_r001275_15_1 * 2) + 28) & 63;
  int stage_v_70_2 = ((pub_r001275_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((sec_r001275_15_1 << 1) ^ (pub_r001275_9_1 >> 1)) & 127;
  int stage_v_71_2 = ((sec_r001275_15_2 << 1) ^ (pub_r001275_9_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_71_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_71_2 + 1) & 15;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = ((pub_r001275_4_1 * 2) + 13) & 63;
  int stage_v_72_2 = ((pub_r001275_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((sec_r001275_3_1 << 1) ^ (pub_r001275_5_1 >> 1)) & 127;
  int stage_v_73_2 = ((sec_r001275_3_2 << 1) ^ (pub_r001275_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_73_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_73_2 + 1) & 15;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = ((pub_r001275_0_1 * 2) + 36) & 63;
  int stage_v_74_2 = ((pub_r001275_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((stage_v_41_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_75_2 = ((stage_v_41_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_75_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_75_2 + 1) & 15;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = ((stage_v_69_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_76_2 = ((stage_v_69_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_76_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_76_2 + 1) & 15;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = ((sec_r001275_8_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_77_2 = ((sec_r001275_8_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_77_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_77_2 + 1) & 15;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = ((pub_r001275_0_1 * 2) + 41) & 63;
  int stage_v_78_2 = ((pub_r001275_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((stage_v_63_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_79_2 = ((stage_v_63_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_79_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_79_2 + 1) & 15;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = ((pub_r001275_13_1 * 2) + 11) & 63;
  int stage_v_80_2 = ((pub_r001275_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001275_14_1 * 2) + 8) & 63;
  int stage_v_81_2 = ((pub_r001275_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_16_1 << 1) ^ (pub_r001275_5_1 >> 1)) & 127;
  int stage_v_82_2 = ((stage_v_16_2 << 1) ^ (pub_r001275_5_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((sec_r001275_21_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_83_2 = ((sec_r001275_21_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_83_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_83_2 + 1) & 15;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = ((pub_r001275_18_1 * 2) + 50) & 63;
  int stage_v_84_2 = ((pub_r001275_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001275_13_1 * 2) + 35) & 63;
  int stage_v_85_2 = ((pub_r001275_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((sec_r001275_8_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_86_2 = ((sec_r001275_8_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_86_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_86_2 + 1) & 15;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = ((stage_v_34_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_87_2 = ((stage_v_34_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_87_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_87_2 + 1) & 15;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = ((stage_v_18_1 << 1) ^ (pub_r001275_17_1 >> 1)) & 127;
  int stage_v_88_2 = ((stage_v_18_2 << 1) ^ (pub_r001275_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_88_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_88_2 + 1) & 15;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = ((pub_r001275_10_1 * 2) + 47) & 63;
  int stage_v_89_2 = ((pub_r001275_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001275_4_1 * 2) + 39) & 63;
  int stage_v_90_2 = ((pub_r001275_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001275_7_1 * 2) + 10) & 63;
  int stage_v_91_2 = ((pub_r001275_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001275_5_1 * 2) + 35) & 63;
  int stage_v_92_2 = ((pub_r001275_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001275_11_1 * 2) + 50) & 63;
  int stage_v_93_2 = ((pub_r001275_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001275_5_1 * 2) + 27) & 63;
  int stage_v_94_2 = ((pub_r001275_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((sec_r001275_3_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_95_2 = ((sec_r001275_3_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_95_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_95_2 + 1) & 15;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = ((pub_r001275_16_1 * 2) + 45) & 63;
  int stage_v_96_2 = ((pub_r001275_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((stage_v_67_1 << 1) ^ (pub_r001275_0_1 >> 1)) & 127;
  int stage_v_97_2 = ((stage_v_67_2 << 1) ^ (pub_r001275_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_97_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_97_2 + 1) & 15;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = ((pub_r001275_4_1 * 2) + 22) & 63;
  int stage_v_98_2 = ((pub_r001275_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_56_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_99_2 = ((stage_v_56_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_99_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_99_2 + 1) & 15;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = ((stage_v_33_1 << 1) ^ (pub_r001275_6_1 >> 1)) & 127;
  int stage_v_100_2 = ((stage_v_33_2 << 1) ^ (pub_r001275_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_100_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_100_2 + 1) & 15;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = ((stage_v_86_1 << 1) ^ (pub_r001275_5_1 >> 1)) & 127;
  int stage_v_101_2 = ((stage_v_86_2 << 1) ^ (pub_r001275_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((stage_v_30_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_102_2 = ((stage_v_30_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_102_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_102_2 + 1) & 15;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = ((pub_r001275_7_1 * 2) + 37) & 63;
  int stage_v_103_2 = ((pub_r001275_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((stage_v_40_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_104_2 = ((stage_v_40_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((pub_r001275_7_1 * 2) + 11) & 63;
  int stage_v_105_2 = ((pub_r001275_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((sec_r001275_5_1 << 1) ^ (pub_r001275_0_1 >> 1)) & 127;
  int stage_v_106_2 = ((sec_r001275_5_2 << 1) ^ (pub_r001275_0_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_106_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_106_2 + 1) & 15;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = ((pub_r001275_13_1 * 2) + 39) & 63;
  int stage_v_107_2 = ((pub_r001275_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001275_5_1 * 2) + 39) & 63;
  int stage_v_108_2 = ((pub_r001275_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_31_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_109_2 = ((stage_v_31_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((pub_r001275_17_1 * 2) + 38) & 63;
  int stage_v_110_2 = ((pub_r001275_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_42_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_111_2 = ((stage_v_42_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((pub_r001275_1_1 * 2) + 23) & 63;
  int stage_v_112_2 = ((pub_r001275_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((stage_v_58_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_113_2 = ((stage_v_58_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_113_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_113_2 + 1) & 15;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = ((pub_r001275_18_1 * 2) + 48) & 63;
  int stage_v_114_2 = ((pub_r001275_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((stage_v_11_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_115_2 = ((stage_v_11_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((stage_v_64_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_116_2 = ((stage_v_64_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_116_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_116_2 + 1) & 15;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = ((sec_r001275_14_1 << 1) ^ (pub_r001275_6_1 >> 1)) & 127;
  int stage_v_117_2 = ((sec_r001275_14_2 << 1) ^ (pub_r001275_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_117_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_117_2 + 1) & 15;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = ((stage_v_31_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_118_2 = ((stage_v_31_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_118_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_118_2 + 1) & 15;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = ((sec_r001275_19_1 << 1) ^ (pub_r001275_1_1 >> 1)) & 127;
  int stage_v_119_2 = ((sec_r001275_19_2 << 1) ^ (pub_r001275_1_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((stage_v_32_1 << 1) ^ (pub_r001275_6_1 >> 1)) & 127;
  int stage_v_120_2 = ((stage_v_32_2 << 1) ^ (pub_r001275_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_120_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_120_2 + 1) & 15;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = ((pub_r001275_15_1 * 2) + 20) & 63;
  int stage_v_121_2 = ((pub_r001275_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((stage_v_11_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_122_2 = ((stage_v_11_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((sec_r001275_11_1 << 1) ^ (pub_r001275_11_1 >> 1)) & 127;
  int stage_v_123_2 = ((sec_r001275_11_2 << 1) ^ (pub_r001275_11_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_123_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_123_2 + 1) & 15;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = ((pub_r001275_10_1 * 2) + 35) & 63;
  int stage_v_124_2 = ((pub_r001275_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_76_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_125_2 = ((stage_v_76_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((pub_r001275_4_1 * 2) + 34) & 63;
  int stage_v_126_2 = ((pub_r001275_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((stage_v_25_1 << 1) ^ (pub_r001275_17_1 >> 1)) & 127;
  int stage_v_127_2 = ((stage_v_25_2 << 1) ^ (pub_r001275_17_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((stage_v_99_1 << 1) ^ (pub_r001275_17_1 >> 1)) & 127;
  int stage_v_128_2 = ((stage_v_99_2 << 1) ^ (pub_r001275_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((stage_v_29_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_129_2 = ((stage_v_29_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((pub_r001275_18_1 * 2) + 49) & 63;
  int stage_v_130_2 = ((pub_r001275_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((sec_r001275_13_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_131_2 = ((sec_r001275_13_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_131_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_131_2 + 1) & 15;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = ((stage_v_99_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_132_2 = ((stage_v_99_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_132_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_132_2 + 1) & 15;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = ((pub_r001275_2_1 * 2) + 10) & 63;
  int stage_v_133_2 = ((pub_r001275_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001275_15_1 * 2) + 46) & 63;
  int stage_v_134_2 = ((pub_r001275_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((sec_r001275_16_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_135_2 = ((sec_r001275_16_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_135_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_135_2 + 1) & 15;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = ((stage_v_36_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_136_2 = ((stage_v_36_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((pub_r001275_0_1 * 2) + 24) & 63;
  int stage_v_137_2 = ((pub_r001275_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((stage_v_75_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_138_2 = ((stage_v_75_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_138_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_138_2 + 1) & 15;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = ((pub_r001275_1_1 * 2) + 35) & 63;
  int stage_v_139_2 = ((pub_r001275_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001275_11_1 * 2) + 15) & 63;
  int stage_v_140_2 = ((pub_r001275_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_11_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_141_2 = ((stage_v_11_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((stage_v_99_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_142_2 = ((stage_v_99_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((sec_r001275_6_1 << 1) ^ (pub_r001275_1_1 >> 1)) & 127;
  int stage_v_143_2 = ((sec_r001275_6_2 << 1) ^ (pub_r001275_1_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_143_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_143_2 + 1) & 15;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = ((stage_v_142_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_144_2 = ((stage_v_142_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((stage_v_64_1 << 1) ^ (pub_r001275_1_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_64_2 << 1) ^ (pub_r001275_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((sec_r001275_11_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_146_2 = ((sec_r001275_11_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((stage_v_1_1 << 1) ^ (pub_r001275_9_1 >> 1)) & 127;
  int stage_v_147_2 = ((stage_v_1_2 << 1) ^ (pub_r001275_9_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((pub_r001275_5_1 * 2) + 24) & 63;
  int stage_v_148_2 = ((pub_r001275_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001275_10_1 * 2) + 31) & 63;
  int stage_v_149_2 = ((pub_r001275_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001275_14_1 * 2) + 14) & 63;
  int stage_v_150_2 = ((pub_r001275_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_25_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_151_2 = ((stage_v_25_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_151_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_151_2 + 1) & 15;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = ((pub_r001275_2_1 * 2) + 41) & 63;
  int stage_v_152_2 = ((pub_r001275_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((sec_r001275_12_1 << 1) ^ (pub_r001275_5_1 >> 1)) & 127;
  int stage_v_153_2 = ((sec_r001275_12_2 << 1) ^ (pub_r001275_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_153_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_153_2 + 1) & 15;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = ((stage_v_99_1 << 1) ^ (pub_r001275_11_1 >> 1)) & 127;
  int stage_v_154_2 = ((stage_v_99_2 << 1) ^ (pub_r001275_11_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_154_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_154_2 + 1) & 15;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = ((pub_r001275_10_1 * 2) + 34) & 63;
  int stage_v_155_2 = ((pub_r001275_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((sec_r001275_4_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_156_2 = ((sec_r001275_4_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_156_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_156_2 + 1) & 15;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = ((helper_flow_2_1 << 1) ^ (pub_r001275_9_1 >> 1)) & 127;
  int stage_v_157_2 = ((helper_flow_2_2 << 1) ^ (pub_r001275_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_157_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_157_2 + 1) & 15;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = ((sec_r001275_5_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_158_2 = ((sec_r001275_5_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((pub_r001275_1_1 * 2) + 14) & 63;
  int stage_v_159_2 = ((pub_r001275_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001275_14_1 * 2) + 50) & 63;
  int stage_v_160_2 = ((pub_r001275_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001275_16_1 * 2) + 21) & 63;
  int stage_v_161_2 = ((pub_r001275_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001275_11_1 * 2) + 8) & 63;
  int stage_v_162_2 = ((pub_r001275_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001275_10_1 * 2) + 16) & 63;
  int stage_v_163_2 = ((pub_r001275_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_63_1 << 1) ^ (pub_r001275_16_1 >> 1)) & 127;
  int stage_v_164_2 = ((stage_v_63_2 << 1) ^ (pub_r001275_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_164_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_164_2 + 1) & 15;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = ((sec_r001275_21_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_165_2 = ((sec_r001275_21_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_165_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_165_2 + 1) & 15;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = ((stage_v_0_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_166_2 = ((stage_v_0_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_166_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_166_2 + 1) & 15;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = ((stage_v_87_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_167_2 = ((stage_v_87_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_167_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_167_2 + 1) & 15;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = ((stage_v_41_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_168_2 = ((stage_v_41_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_168_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_168_2 + 1) & 15;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = ((pub_r001275_8_1 * 2) + 5) & 63;
  int stage_v_169_2 = ((pub_r001275_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_131_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_131_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((pub_r001275_4_1 * 2) + 31) & 63;
  int stage_v_171_2 = ((pub_r001275_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_167_1 << 1) ^ (pub_r001275_2_1 >> 1)) & 127;
  int stage_v_172_2 = ((stage_v_167_2 << 1) ^ (pub_r001275_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_172_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_172_2 + 1) & 15;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = ((stage_v_2_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_173_2 = ((stage_v_2_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_173_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_173_2 + 1) & 15;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = ((sec_r001275_11_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_174_2 = ((sec_r001275_11_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((stage_v_41_1 << 1) ^ (pub_r001275_5_1 >> 1)) & 127;
  int stage_v_175_2 = ((stage_v_41_2 << 1) ^ (pub_r001275_5_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_175_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_175_2 + 1) & 15;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = ((stage_v_76_1 << 1) ^ (pub_r001275_16_1 >> 1)) & 127;
  int stage_v_176_2 = ((stage_v_76_2 << 1) ^ (pub_r001275_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_176_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_176_2 + 1) & 15;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = ((sec_r001275_14_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_177_2 = ((sec_r001275_14_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_177_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_177_2 + 1) & 15;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = ((pub_r001275_17_1 * 2) + 36) & 63;
  int stage_v_178_2 = ((pub_r001275_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001275_15_1 * 2) + 28) & 63;
  int stage_v_179_2 = ((pub_r001275_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((stage_v_168_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_180_2 = ((stage_v_168_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_180_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_180_2 + 1) & 15;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = ((stage_v_30_1 << 1) ^ (pub_r001275_1_1 >> 1)) & 127;
  int stage_v_181_2 = ((stage_v_30_2 << 1) ^ (pub_r001275_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_181_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_181_2 + 1) & 15;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = ((pub_r001275_17_1 * 2) + 35) & 63;
  int stage_v_182_2 = ((pub_r001275_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001275_18_1 * 2) + 37) & 63;
  int stage_v_183_2 = ((pub_r001275_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001275_0_1 * 2) + 44) & 63;
  int stage_v_184_2 = ((pub_r001275_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001275_2_1 * 2) + 9) & 63;
  int stage_v_185_2 = ((pub_r001275_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001275_15_1 * 2) + 10) & 63;
  int stage_v_186_2 = ((pub_r001275_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001275_7_1 * 2) + 29) & 63;
  int stage_v_187_2 = ((pub_r001275_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001275_17_1 * 2) + 13) & 63;
  int stage_v_188_2 = ((pub_r001275_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001275_16_1 * 2) + 6) & 63;
  int stage_v_189_2 = ((pub_r001275_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001275_18_1 * 2) + 22) & 63;
  int stage_v_190_2 = ((pub_r001275_18_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((stage_v_164_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_191_2 = ((stage_v_164_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((stage_v_100_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_192_2 = ((stage_v_100_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((sec_r001275_10_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_193_2 = ((sec_r001275_10_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((sec_r001275_1_1 << 1) ^ (pub_r001275_17_1 >> 1)) & 127;
  int stage_v_194_2 = ((sec_r001275_1_2 << 1) ^ (pub_r001275_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_194_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_194_2 + 1) & 15;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = ((pub_r001275_6_1 * 2) + 14) & 63;
  int stage_v_195_2 = ((pub_r001275_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001275_11_1 * 2) + 13) & 63;
  int stage_v_196_2 = ((pub_r001275_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_76_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_76_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((pub_r001275_3_1 * 2) + 29) & 63;
  int stage_v_198_2 = ((pub_r001275_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((stage_v_180_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_199_2 = ((stage_v_180_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((stage_v_63_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_200_2 = ((stage_v_63_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((stage_v_27_1 << 1) ^ (pub_r001275_16_1 >> 1)) & 127;
  int stage_v_201_2 = ((stage_v_27_2 << 1) ^ (pub_r001275_16_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_201_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_201_2 + 1) & 15;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = ((stage_v_127_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_202_2 = ((stage_v_127_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((stage_v_69_1 << 1) ^ (pub_r001275_5_1 >> 1)) & 127;
  int stage_v_203_2 = ((stage_v_69_2 << 1) ^ (pub_r001275_5_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_203_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_203_2 + 1) & 15;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = ((pub_r001275_18_1 * 2) + 43) & 63;
  int stage_v_204_2 = ((pub_r001275_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((stage_v_144_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_205_2 = ((stage_v_144_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_205_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_205_2 + 1) & 15;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = ((pub_r001275_3_1 * 2) + 44) & 63;
  int stage_v_206_2 = ((pub_r001275_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((stage_v_28_1 << 1) ^ (pub_r001275_1_1 >> 1)) & 127;
  int stage_v_207_2 = ((stage_v_28_2 << 1) ^ (pub_r001275_1_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_207_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_207_2 + 1) & 15;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = ((stage_v_30_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_208_2 = ((stage_v_30_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((stage_v_43_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_209_2 = ((stage_v_43_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_209_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_209_2 + 1) & 15;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = ((pub_r001275_12_1 * 2) + 22) & 63;
  int stage_v_210_2 = ((pub_r001275_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((stage_v_129_1 << 1) ^ (pub_r001275_5_1 >> 1)) & 127;
  int stage_v_211_2 = ((stage_v_129_2 << 1) ^ (pub_r001275_5_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_211_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_211_2 + 1) & 15;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = ((pub_r001275_14_1 * 2) + 44) & 63;
  int stage_v_212_2 = ((pub_r001275_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001275_11_1 * 2) + 14) & 63;
  int stage_v_213_2 = ((pub_r001275_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001275_17_1 * 2) + 23) & 63;
  int stage_v_214_2 = ((pub_r001275_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((stage_v_49_1 << 1) ^ (pub_r001275_16_1 >> 1)) & 127;
  int stage_v_215_2 = ((stage_v_49_2 << 1) ^ (pub_r001275_16_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_215_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_215_2 + 1) & 15;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = ((helper_flow_2_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_216_2 = ((helper_flow_2_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((stage_v_164_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_217_2 = ((stage_v_164_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_217_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_217_2 + 1) & 15;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = ((pub_r001275_13_1 * 2) + 42) & 63;
  int stage_v_218_2 = ((pub_r001275_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((stage_v_27_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_219_2 = ((stage_v_27_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_219_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_219_2 + 1) & 15;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = ((stage_v_129_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_220_2 = ((stage_v_129_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_220_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_220_2 + 1) & 15;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = ((stage_v_51_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_221_2 = ((stage_v_51_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((pub_r001275_9_1 * 2) + 40) & 63;
  int stage_v_222_2 = ((pub_r001275_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001275_4_1 * 2) + 5) & 63;
  int stage_v_223_2 = ((pub_r001275_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001275_12_1 * 2) + 32) & 63;
  int stage_v_224_2 = ((pub_r001275_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((stage_v_79_1 << 1) ^ (pub_r001275_9_1 >> 1)) & 127;
  int stage_v_225_2 = ((stage_v_79_2 << 1) ^ (pub_r001275_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((stage_v_87_1 << 1) ^ (pub_r001275_1_1 >> 1)) & 127;
  int stage_v_226_2 = ((stage_v_87_2 << 1) ^ (pub_r001275_1_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_226_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_226_2 + 1) & 15;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = ((pub_r001275_7_1 * 2) + 15) & 63;
  int stage_v_227_2 = ((pub_r001275_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((stage_v_225_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_228_2 = ((stage_v_225_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_228_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_228_2 + 1) & 15;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = ((stage_v_143_1 << 1) ^ (pub_r001275_6_1 >> 1)) & 127;
  int stage_v_229_2 = ((stage_v_143_2 << 1) ^ (pub_r001275_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_229_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_229_2 + 1) & 15;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = ((pub_r001275_10_1 * 2) + 35) & 63;
  int stage_v_230_2 = ((pub_r001275_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001275_14_1 * 2) + 9) & 63;
  int stage_v_231_2 = ((pub_r001275_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((stage_v_164_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_232_2 = ((stage_v_164_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_232_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_232_2 + 1) & 15;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = ((pub_r001275_6_1 * 2) + 21) & 63;
  int stage_v_233_2 = ((pub_r001275_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001275_10_1 * 2) + 33) & 63;
  int stage_v_234_2 = ((pub_r001275_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((stage_v_192_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_235_2 = ((stage_v_192_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((pub_r001275_18_1 * 2) + 41) & 63;
  int stage_v_236_2 = ((pub_r001275_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001275_4_1 * 2) + 15) & 63;
  int stage_v_237_2 = ((pub_r001275_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001275_14_1 * 2) + 29) & 63;
  int stage_v_238_2 = ((pub_r001275_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((stage_v_120_1 << 1) ^ (pub_r001275_11_1 >> 1)) & 127;
  int stage_v_239_2 = ((stage_v_120_2 << 1) ^ (pub_r001275_11_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_239_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_239_2 + 1) & 15;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = ((stage_v_50_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_240_2 = ((stage_v_50_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_240_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_240_2 + 1) & 15;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = ((pub_r001275_16_1 * 2) + 17) & 63;
  int stage_v_241_2 = ((pub_r001275_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((stage_v_1_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_242_2 = ((stage_v_1_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_242_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_242_2 + 1) & 15;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = ((stage_v_220_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_220_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((pub_r001275_9_1 * 2) + 44) & 63;
  int stage_v_244_2 = ((pub_r001275_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001275_16_1 * 2) + 31) & 63;
  int stage_v_245_2 = ((pub_r001275_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((stage_v_19_1 << 1) ^ (pub_r001275_0_1 >> 1)) & 127;
  int stage_v_246_2 = ((stage_v_19_2 << 1) ^ (pub_r001275_0_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_246_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_246_2 + 1) & 15;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = ((pub_r001275_3_1 * 2) + 8) & 63;
  int stage_v_247_2 = ((pub_r001275_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001275_4_1 * 2) + 16) & 63;
  int stage_v_248_2 = ((pub_r001275_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((stage_v_193_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_193_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((stage_v_33_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_250_2 = ((stage_v_33_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_250_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_250_2 + 1) & 15;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = ((stage_v_141_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_251_2 = ((stage_v_141_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_251_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_251_2 + 1) & 15;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = ((pub_r001275_11_1 * 2) + 35) & 63;
  int stage_v_252_2 = ((pub_r001275_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((stage_v_2_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_253_2 = ((stage_v_2_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((stage_v_29_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_254_2 = ((stage_v_29_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_254_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_254_2 + 1) & 15;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = ((pub_r001275_8_1 * 2) + 41) & 63;
  int stage_v_255_2 = ((pub_r001275_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((stage_v_6_1 << 1) ^ (pub_r001275_1_1 >> 1)) & 127;
  int stage_v_256_2 = ((stage_v_6_2 << 1) ^ (pub_r001275_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((sec_r001275_17_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_257_2 = ((sec_r001275_17_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_257_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_257_2 + 1) & 15;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = ((pub_r001275_0_1 * 2) + 46) & 63;
  int stage_v_258_2 = ((pub_r001275_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((stage_v_76_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_259_2 = ((stage_v_76_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((stage_v_221_1 << 1) ^ (pub_r001275_2_1 >> 1)) & 127;
  int stage_v_260_2 = ((stage_v_221_2 << 1) ^ (pub_r001275_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_260_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_260_2 + 1) & 15;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = ((pub_r001275_6_1 * 2) + 12) & 63;
  int stage_v_261_2 = ((pub_r001275_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001275_3_1 * 2) + 34) & 63;
  int stage_v_262_2 = ((pub_r001275_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001275_0_1 * 2) + 36) & 63;
  int stage_v_263_2 = ((pub_r001275_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((stage_v_136_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_264_2 = ((stage_v_136_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_264_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_264_2 + 1) & 15;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = ((stage_v_157_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_157_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((stage_v_144_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_266_2 = ((stage_v_144_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_266_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_266_2 + 1) & 15;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = ((stage_v_76_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_267_2 = ((stage_v_76_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_267_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_267_2 + 1) & 15;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = ((pub_r001275_1_1 * 2) + 30) & 63;
  int stage_v_268_2 = ((pub_r001275_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((stage_v_18_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_269_2 = ((stage_v_18_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((stage_v_180_1 << 1) ^ (pub_r001275_5_1 >> 1)) & 127;
  int stage_v_270_2 = ((stage_v_180_2 << 1) ^ (pub_r001275_5_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_270_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_270_2 + 1) & 15;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = ((stage_v_2_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_271_2 = ((stage_v_2_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_271_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_271_2 + 1) & 15;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = ((pub_r001275_16_1 * 2) + 27) & 63;
  int stage_v_272_2 = ((pub_r001275_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((helper_flow_5_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_273_2 = ((helper_flow_5_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((pub_r001275_13_1 * 2) + 13) & 63;
  int stage_v_274_2 = ((pub_r001275_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((stage_v_211_1 << 1) ^ (pub_r001275_11_1 >> 1)) & 127;
  int stage_v_275_2 = ((stage_v_211_2 << 1) ^ (pub_r001275_11_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((stage_v_100_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_276_2 = ((stage_v_100_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((stage_v_19_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_277_2 = ((stage_v_19_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_277_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_277_2 + 1) & 15;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = ((stage_v_166_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_278_2 = ((stage_v_166_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_278_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_278_2 + 1) & 15;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = ((pub_r001275_17_1 * 2) + 15) & 63;
  int stage_v_279_2 = ((pub_r001275_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001275_15_1 * 2) + 42) & 63;
  int stage_v_280_2 = ((pub_r001275_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((stage_v_79_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_281_2 = ((stage_v_79_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_281_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_281_2 + 1) & 15;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = ((pub_r001275_4_1 * 2) + 14) & 63;
  int stage_v_282_2 = ((pub_r001275_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001275_11_1 * 2) + 26) & 63;
  int stage_v_283_2 = ((pub_r001275_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((stage_v_120_1 << 1) ^ (pub_r001275_0_1 >> 1)) & 127;
  int stage_v_284_2 = ((stage_v_120_2 << 1) ^ (pub_r001275_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_284_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_284_2 + 1) & 15;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = ((pub_r001275_9_1 * 2) + 40) & 63;
  int stage_v_285_2 = ((pub_r001275_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001275_12_1 * 2) + 30) & 63;
  int stage_v_286_2 = ((pub_r001275_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((stage_v_7_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_287_2 = ((stage_v_7_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((pub_r001275_6_1 * 2) + 5) & 63;
  int stage_v_288_2 = ((pub_r001275_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001275_10_1 * 2) + 8) & 63;
  int stage_v_289_2 = ((pub_r001275_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((stage_v_41_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_290_2 = ((stage_v_41_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_290_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_290_2 + 1) & 15;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = ((pub_r001275_7_1 * 2) + 31) & 63;
  int stage_v_291_2 = ((pub_r001275_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001275_9_1 * 2) + 26) & 63;
  int stage_v_292_2 = ((pub_r001275_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((stage_v_52_1 << 1) ^ (pub_r001275_2_1 >> 1)) & 127;
  int stage_v_293_2 = ((stage_v_52_2 << 1) ^ (pub_r001275_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_293_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_293_2 + 1) & 15;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = ((sec_r001275_10_1 << 1) ^ (pub_r001275_13_1 >> 1)) & 127;
  int stage_v_294_2 = ((sec_r001275_10_2 << 1) ^ (pub_r001275_13_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_294_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_294_2 + 1) & 15;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = ((stage_v_15_1 << 1) ^ (pub_r001275_11_1 >> 1)) & 127;
  int stage_v_295_2 = ((stage_v_15_2 << 1) ^ (pub_r001275_11_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_295_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_295_2 + 1) & 15;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = ((pub_r001275_11_1 * 2) + 34) & 63;
  int stage_v_296_2 = ((pub_r001275_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001275_7_1 * 2) + 39) & 63;
  int stage_v_297_2 = ((pub_r001275_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001275_14_1 * 2) + 43) & 63;
  int stage_v_298_2 = ((pub_r001275_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001275_13_1 * 2) + 18) & 63;
  int stage_v_299_2 = ((pub_r001275_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((stage_v_43_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_300_2 = ((stage_v_43_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_300_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_300_2 + 1) & 15;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = ((stage_v_138_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_301_2 = ((stage_v_138_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_301_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_301_2 + 1) & 15;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = ((pub_r001275_17_1 * 2) + 30) & 63;
  int stage_v_302_2 = ((pub_r001275_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001275_12_1 * 2) + 28) & 63;
  int stage_v_303_2 = ((pub_r001275_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((stage_v_197_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_304_2 = ((stage_v_197_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_304_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_304_2 + 1) & 15;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = ((pub_r001275_9_1 * 2) + 39) & 63;
  int stage_v_305_2 = ((pub_r001275_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001275_12_1 * 2) + 47) & 63;
  int stage_v_306_2 = ((pub_r001275_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((stage_v_95_1 << 1) ^ (pub_r001275_2_1 >> 1)) & 127;
  int stage_v_307_2 = ((stage_v_95_2 << 1) ^ (pub_r001275_2_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_307_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_307_2 + 1) & 15;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = ((stage_v_101_1 << 1) ^ (pub_r001275_17_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_101_2 << 1) ^ (pub_r001275_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((pub_r001275_0_1 * 2) + 11) & 63;
  int stage_v_309_2 = ((pub_r001275_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001275_10_1 * 2) + 47) & 63;
  int stage_v_310_2 = ((pub_r001275_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((stage_v_11_1 << 1) ^ (pub_r001275_16_1 >> 1)) & 127;
  int stage_v_311_2 = ((stage_v_11_2 << 1) ^ (pub_r001275_16_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((stage_v_97_1 << 1) ^ (pub_r001275_6_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_97_2 << 1) ^ (pub_r001275_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((stage_v_158_1 << 1) ^ (pub_r001275_11_1 >> 1)) & 127;
  int stage_v_313_2 = ((stage_v_158_2 << 1) ^ (pub_r001275_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((pub_r001275_9_1 * 2) + 21) & 63;
  int stage_v_314_2 = ((pub_r001275_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001275_5_1 * 2) + 23) & 63;
  int stage_v_315_2 = ((pub_r001275_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001275_4_1 * 2) + 12) & 63;
  int stage_v_316_2 = ((pub_r001275_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001275_9_1 * 2) + 32) & 63;
  int stage_v_317_2 = ((pub_r001275_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001275_9_1 * 2) + 8) & 63;
  int stage_v_318_2 = ((pub_r001275_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((stage_v_207_1 << 1) ^ (pub_r001275_6_1 >> 1)) & 127;
  int stage_v_319_2 = ((stage_v_207_2 << 1) ^ (pub_r001275_6_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((stage_v_312_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_320_2 = ((stage_v_312_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_320_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_320_2 + 1) & 15;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = ((stage_v_129_1 << 1) ^ (pub_r001275_5_1 >> 1)) & 127;
  int stage_v_321_2 = ((stage_v_129_2 << 1) ^ (pub_r001275_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_321_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_321_2 + 1) & 15;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  int stage_v_322_1 = ((pub_r001275_2_1 * 2) + 17) & 63;
  int stage_v_322_2 = ((pub_r001275_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001275_6_1 * 2) + 38) & 63;
  int stage_v_323_2 = ((pub_r001275_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((stage_v_319_1 << 1) ^ (pub_r001275_9_1 >> 1)) & 127;
  int stage_v_324_2 = ((stage_v_319_2 << 1) ^ (pub_r001275_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_324_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_324_2 + 1) & 15;
  out_sink_1 ^= stage_v_324_1 & 63;
  out_sink_2 ^= stage_v_324_2 & 63;
  int stage_v_325_1 = ((stage_v_270_1 << 1) ^ (pub_r001275_3_1 >> 1)) & 127;
  int stage_v_325_2 = ((stage_v_270_2 << 1) ^ (pub_r001275_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((pub_r001275_5_1 * 2) + 48) & 63;
  int stage_v_326_2 = ((pub_r001275_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001275_6_1 * 2) + 7) & 63;
  int stage_v_327_2 = ((pub_r001275_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((stage_v_180_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_328_2 = ((stage_v_180_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_328_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_328_2 + 1) & 15;
  out_sink_1 ^= stage_v_328_1 & 63;
  out_sink_2 ^= stage_v_328_2 & 63;
  int stage_v_329_1 = ((pub_r001275_0_1 * 2) + 20) & 63;
  int stage_v_329_2 = ((pub_r001275_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001275_1_1 * 2) + 48) & 63;
  int stage_v_330_2 = ((pub_r001275_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((stage_v_293_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_331_2 = ((stage_v_293_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_331_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_331_2 + 1) & 15;
  out_sink_1 ^= stage_v_331_1 & 63;
  out_sink_2 ^= stage_v_331_2 & 63;
  int stage_v_332_1 = ((stage_v_259_1 << 1) ^ (pub_r001275_1_1 >> 1)) & 127;
  int stage_v_332_2 = ((stage_v_259_2 << 1) ^ (pub_r001275_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_332_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_332_2 + 1) & 15;
  out_sink_1 ^= stage_v_332_1 & 63;
  out_sink_2 ^= stage_v_332_2 & 63;
  int stage_v_333_1 = ((stage_v_265_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_333_2 = ((stage_v_265_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_333_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_333_2 + 1) & 15;
  out_sink_1 ^= stage_v_333_1 & 63;
  out_sink_2 ^= stage_v_333_2 & 63;
  int stage_v_334_1 = ((pub_r001275_0_1 * 2) + 9) & 63;
  int stage_v_334_2 = ((pub_r001275_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((helper_flow_5_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_335_2 = ((helper_flow_5_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((pub_r001275_1_1 * 2) + 42) & 63;
  int stage_v_336_2 = ((pub_r001275_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001275_2_1 * 2) + 40) & 63;
  int stage_v_337_2 = ((pub_r001275_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001275_4_1 * 2) + 34) & 63;
  int stage_v_338_2 = ((pub_r001275_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001275_3_1 * 2) + 29) & 63;
  int stage_v_339_2 = ((pub_r001275_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001275_10_1 * 2) + 8) & 63;
  int stage_v_340_2 = ((pub_r001275_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((stage_v_194_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_341_2 = ((stage_v_194_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_341_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_341_2 + 1) & 15;
  out_sink_1 ^= stage_v_341_1 & 63;
  out_sink_2 ^= stage_v_341_2 & 63;
  int stage_v_342_1 = ((sec_r001275_5_1 << 1) ^ (pub_r001275_11_1 >> 1)) & 127;
  int stage_v_342_2 = ((sec_r001275_5_2 << 1) ^ (pub_r001275_11_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_342_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_342_2 + 1) & 15;
  out_sink_1 ^= stage_v_342_1 & 63;
  out_sink_2 ^= stage_v_342_2 & 63;
  int stage_v_343_1 = ((stage_v_102_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_343_2 = ((stage_v_102_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_343_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_343_2 + 1) & 15;
  out_sink_1 ^= stage_v_343_1 & 63;
  out_sink_2 ^= stage_v_343_2 & 63;
  int stage_v_344_1 = ((stage_v_220_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_344_2 = ((stage_v_220_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_344_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_344_2 + 1) & 15;
  out_sink_1 ^= stage_v_344_1 & 63;
  out_sink_2 ^= stage_v_344_2 & 63;
  int stage_v_345_1 = ((pub_r001275_5_1 * 2) + 7) & 63;
  int stage_v_345_2 = ((pub_r001275_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((stage_v_104_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_346_2 = ((stage_v_104_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_346_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_346_2 + 1) & 15;
  out_sink_1 ^= stage_v_346_1 & 63;
  out_sink_2 ^= stage_v_346_2 & 63;
  int stage_v_347_1 = ((pub_r001275_18_1 * 2) + 13) & 63;
  int stage_v_347_2 = ((pub_r001275_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((helper_flow_5_1 << 1) ^ (pub_r001275_6_1 >> 1)) & 127;
  int stage_v_348_2 = ((helper_flow_5_2 << 1) ^ (pub_r001275_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_348_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_348_2 + 1) & 15;
  out_sink_1 ^= stage_v_348_1 & 63;
  out_sink_2 ^= stage_v_348_2 & 63;
  int stage_v_349_1 = ((stage_v_264_1 << 1) ^ (pub_r001275_2_1 >> 1)) & 127;
  int stage_v_349_2 = ((stage_v_264_2 << 1) ^ (pub_r001275_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_349_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_349_2 + 1) & 15;
  out_sink_1 ^= stage_v_349_1 & 63;
  out_sink_2 ^= stage_v_349_2 & 63;
  int stage_v_350_1 = ((stage_v_243_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_243_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((stage_v_293_1 << 1) ^ (pub_r001275_18_1 >> 1)) & 127;
  int stage_v_351_2 = ((stage_v_293_2 << 1) ^ (pub_r001275_18_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_351_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_351_2 + 1) & 15;
  out_sink_1 ^= stage_v_351_1 & 63;
  out_sink_2 ^= stage_v_351_2 & 63;
  int stage_v_352_1 = ((stage_v_127_1 << 1) ^ (pub_r001275_17_1 >> 1)) & 127;
  int stage_v_352_2 = ((stage_v_127_2 << 1) ^ (pub_r001275_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_352_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_352_2 + 1) & 15;
  out_sink_1 ^= stage_v_352_1 & 63;
  out_sink_2 ^= stage_v_352_2 & 63;
  int stage_v_353_1 = ((stage_v_99_1 << 1) ^ (pub_r001275_2_1 >> 1)) & 127;
  int stage_v_353_2 = ((stage_v_99_2 << 1) ^ (pub_r001275_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_353_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_353_2 + 1) & 15;
  out_sink_1 ^= stage_v_353_1 & 63;
  out_sink_2 ^= stage_v_353_2 & 63;
  int stage_v_354_1 = ((pub_r001275_2_1 * 2) + 15) & 63;
  int stage_v_354_2 = ((pub_r001275_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001275_14_1 * 2) + 37) & 63;
  int stage_v_355_2 = ((pub_r001275_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001275_0_1 * 2) + 47) & 63;
  int stage_v_356_2 = ((pub_r001275_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((stage_v_30_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_357_2 = ((stage_v_30_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_357_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_357_2 + 1) & 15;
  out_sink_1 ^= stage_v_357_1 & 63;
  out_sink_2 ^= stage_v_357_2 & 63;
  int stage_v_358_1 = ((stage_v_42_1 << 1) ^ (pub_r001275_2_1 >> 1)) & 127;
  int stage_v_358_2 = ((stage_v_42_2 << 1) ^ (pub_r001275_2_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_358_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_358_2 + 1) & 15;
  out_sink_1 ^= stage_v_358_1 & 63;
  out_sink_2 ^= stage_v_358_2 & 63;
  int stage_v_359_1 = ((pub_r001275_8_1 * 2) + 30) & 63;
  int stage_v_359_2 = ((pub_r001275_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((stage_v_208_1 << 1) ^ (pub_r001275_15_1 >> 1)) & 127;
  int stage_v_360_2 = ((stage_v_208_2 << 1) ^ (pub_r001275_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((pub_r001275_2_1 * 2) + 49) & 63;
  int stage_v_361_2 = ((pub_r001275_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001275_7_1 * 2) + 13) & 63;
  int stage_v_362_2 = ((pub_r001275_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001275_5_1 * 2) + 19) & 63;
  int stage_v_363_2 = ((pub_r001275_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((stage_v_250_1 << 1) ^ (pub_r001275_11_1 >> 1)) & 127;
  int stage_v_364_2 = ((stage_v_250_2 << 1) ^ (pub_r001275_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_6_1 << 1) ^ (pub_r001275_8_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_6_2 << 1) ^ (pub_r001275_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((pub_r001275_16_1 * 2) + 20) & 63;
  int stage_v_366_2 = ((pub_r001275_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001275_15_1 * 2) + 9) & 63;
  int stage_v_367_2 = ((pub_r001275_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((stage_v_357_1 << 1) ^ (pub_r001275_6_1 >> 1)) & 127;
  int stage_v_368_2 = ((stage_v_357_2 << 1) ^ (pub_r001275_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_368_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_368_2 + 1) & 15;
  out_sink_1 ^= stage_v_368_1 & 63;
  out_sink_2 ^= stage_v_368_2 & 63;
  int stage_v_369_1 = ((pub_r001275_10_1 * 2) + 39) & 63;
  int stage_v_369_2 = ((pub_r001275_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((stage_v_99_1 << 1) ^ (pub_r001275_12_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_99_2 << 1) ^ (pub_r001275_12_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((stage_v_73_1 << 1) ^ (pub_r001275_4_1 >> 1)) & 127;
  int stage_v_371_2 = ((stage_v_73_2 << 1) ^ (pub_r001275_4_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_371_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_371_2 + 1) & 15;
  out_sink_1 ^= stage_v_371_1 & 63;
  out_sink_2 ^= stage_v_371_2 & 63;
  int stage_v_372_1 = ((pub_r001275_15_1 * 2) + 25) & 63;
  int stage_v_372_2 = ((pub_r001275_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((stage_v_64_1 << 1) ^ (pub_r001275_9_1 >> 1)) & 127;
  int stage_v_373_2 = ((stage_v_64_2 << 1) ^ (pub_r001275_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_373_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_373_2 + 1) & 15;
  out_sink_1 ^= stage_v_373_1 & 63;
  out_sink_2 ^= stage_v_373_2 & 63;
  int stage_v_374_1 = ((pub_r001275_9_1 * 2) + 19) & 63;
  int stage_v_374_2 = ((pub_r001275_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((stage_v_342_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_375_2 = ((stage_v_342_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_375_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_375_2 + 1) & 15;
  out_sink_1 ^= stage_v_375_1 & 63;
  out_sink_2 ^= stage_v_375_2 & 63;
  int stage_v_376_1 = ((sec_r001275_0_1 << 1) ^ (pub_r001275_14_1 >> 1)) & 127;
  int stage_v_376_2 = ((sec_r001275_0_2 << 1) ^ (pub_r001275_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_376_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_376_2 + 1) & 15;
  out_sink_1 ^= stage_v_376_1 & 63;
  out_sink_2 ^= stage_v_376_2 & 63;
  int stage_v_377_1 = ((pub_r001275_17_1 * 2) + 32) & 63;
  int stage_v_377_2 = ((pub_r001275_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((stage_v_321_1 << 1) ^ (pub_r001275_6_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_321_2 << 1) ^ (pub_r001275_6_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((stage_v_166_1 << 1) ^ (pub_r001275_10_1 >> 1)) & 127;
  int stage_v_379_2 = ((stage_v_166_2 << 1) ^ (pub_r001275_10_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((stage_v_219_1 << 1) ^ (pub_r001275_11_1 >> 1)) & 127;
  int stage_v_380_2 = ((stage_v_219_2 << 1) ^ (pub_r001275_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((stage_v_14_1 << 1) ^ (pub_r001275_2_1 >> 1)) & 127;
  int stage_v_381_2 = ((stage_v_14_2 << 1) ^ (pub_r001275_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_381_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_381_2 + 1) & 15;
  out_sink_1 ^= stage_v_381_1 & 63;
  out_sink_2 ^= stage_v_381_2 & 63;
  int stage_v_382_1 = ((stage_v_68_1 << 1) ^ (pub_r001275_7_1 >> 1)) & 127;
  int stage_v_382_2 = ((stage_v_68_2 << 1) ^ (pub_r001275_7_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_382_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_382_2 + 1) & 15;
  out_sink_1 ^= stage_v_382_1 & 63;
  out_sink_2 ^= stage_v_382_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001275_16_1 != sec_r001275_16_2);
  __CPROVER_assume(pub_r001275_14_1 == pub_r001275_14_2);
  __CPROVER_assume(pub_r001275_2_1 == pub_r001275_2_2);
  __CPROVER_assume(sec_r001275_9_1 != sec_r001275_9_2);
  __CPROVER_assume(pub_r001275_3_1 == pub_r001275_3_2);
  __CPROVER_assume(pub_r001275_11_1 == pub_r001275_11_2);
  __CPROVER_assume(sec_r001275_2_1 != sec_r001275_2_2);
  __CPROVER_assume(pub_r001275_0_1 == pub_r001275_0_2);
  __CPROVER_assume(pub_r001275_9_1 == pub_r001275_9_2);
  __CPROVER_assume(sec_r001275_15_1 != sec_r001275_15_2);
  __CPROVER_assume(sec_r001275_3_1 != sec_r001275_3_2);
  __CPROVER_assume(pub_r001275_13_1 == pub_r001275_13_2);
  __CPROVER_assume(sec_r001275_1_1 != sec_r001275_1_2);
  __CPROVER_assume(sec_r001275_10_1 != sec_r001275_10_2);
  __CPROVER_assume(sec_r001275_21_1 != sec_r001275_21_2);
  __CPROVER_assume(pub_r001275_17_1 == pub_r001275_17_2);
  __CPROVER_assume(sec_r001275_12_1 != sec_r001275_12_2);
  __CPROVER_assume(pub_r001275_6_1 == pub_r001275_6_2);
  __CPROVER_assume(pub_r001275_4_1 == pub_r001275_4_2);
  __CPROVER_assume(pub_r001275_10_1 == pub_r001275_10_2);
  __CPROVER_assume(sec_r001275_11_1 != sec_r001275_11_2);
  __CPROVER_assume(sec_r001275_7_1 != sec_r001275_7_2);
  __CPROVER_assume(pub_r001275_12_1 == pub_r001275_12_2);
  __CPROVER_assume(sec_r001275_14_1 != sec_r001275_14_2);
  __CPROVER_assume(sec_r001275_20_1 != sec_r001275_20_2);
  __CPROVER_assume(sec_r001275_18_1 != sec_r001275_18_2);
  __CPROVER_assume(sec_r001275_17_1 != sec_r001275_17_2);
  __CPROVER_assume(pub_r001275_7_1 == pub_r001275_7_2);
  __CPROVER_assume(pub_r001275_18_1 == pub_r001275_18_2);
  __CPROVER_assume(sec_r001275_8_1 != sec_r001275_8_2);
  __CPROVER_assume(pub_r001275_15_1 == pub_r001275_15_2);
  __CPROVER_assume(sec_r001275_4_1 != sec_r001275_4_2);
  __CPROVER_assume(pub_r001275_1_1 == pub_r001275_1_2);
  __CPROVER_assume(pub_r001275_8_1 == pub_r001275_8_2);
  __CPROVER_assume(sec_r001275_13_1 != sec_r001275_13_2);
  __CPROVER_assume(sec_r001275_5_1 != sec_r001275_5_2);
  __CPROVER_assume(sec_r001275_19_1 != sec_r001275_19_2);
  __CPROVER_assume(pub_r001275_16_1 == pub_r001275_16_2);
  __CPROVER_assume(sec_r001275_6_1 != sec_r001275_6_2);
  __CPROVER_assume(pub_r001275_5_1 == pub_r001275_5_2);
  __CPROVER_assume(sec_r001275_0_1 != sec_r001275_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.stride == st_var_3_2.stride);
  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.determinant == st_var_3_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_3_1.buffer[i_buffer] == st_var_3_2.buffer[i_buffer]);
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
  assert(stage_v_193_1 == stage_v_193_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(stage_v_230_1 == stage_v_230_2);
  assert(stage_v_231_1 == stage_v_231_2);
  assert(stage_v_232_1 == stage_v_232_2);
  assert(stage_v_233_1 == stage_v_233_2);
  assert(stage_v_234_1 == stage_v_234_2);
  assert(stage_v_235_1 == stage_v_235_2);
  assert(stage_v_236_1 == stage_v_236_2);
  assert(stage_v_237_1 == stage_v_237_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(stage_v_240_1 == stage_v_240_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(stage_v_247_1 == stage_v_247_2);
  assert(stage_v_248_1 == stage_v_248_2);
  assert(stage_v_249_1 == stage_v_249_2);
  assert(stage_v_250_1 == stage_v_250_2);
  assert(stage_v_251_1 == stage_v_251_2);
  assert(stage_v_252_1 == stage_v_252_2);
  assert(stage_v_253_1 == stage_v_253_2);
  assert(stage_v_254_1 == stage_v_254_2);
  assert(stage_v_255_1 == stage_v_255_2);
  assert(stage_v_256_1 == stage_v_256_2);
  assert(stage_v_257_1 == stage_v_257_2);
  assert(stage_v_258_1 == stage_v_258_2);
  assert(stage_v_259_1 == stage_v_259_2);
  assert(stage_v_260_1 == stage_v_260_2);
  assert(stage_v_261_1 == stage_v_261_2);
  assert(stage_v_262_1 == stage_v_262_2);
  assert(stage_v_263_1 == stage_v_263_2);
  assert(stage_v_264_1 == stage_v_264_2);
  assert(stage_v_265_1 == stage_v_265_2);
  assert(stage_v_266_1 == stage_v_266_2);
  assert(stage_v_267_1 == stage_v_267_2);
  assert(stage_v_268_1 == stage_v_268_2);
  assert(stage_v_269_1 == stage_v_269_2);
  assert(stage_v_270_1 == stage_v_270_2);
  assert(stage_v_271_1 == stage_v_271_2);
  assert(stage_v_272_1 == stage_v_272_2);
  assert(stage_v_273_1 == stage_v_273_2);
  assert(stage_v_274_1 == stage_v_274_2);
  assert(stage_v_275_1 == stage_v_275_2);
  assert(stage_v_276_1 == stage_v_276_2);
  assert(stage_v_277_1 == stage_v_277_2);
  assert(stage_v_278_1 == stage_v_278_2);
  assert(stage_v_279_1 == stage_v_279_2);
  assert(stage_v_280_1 == stage_v_280_2);
  assert(stage_v_281_1 == stage_v_281_2);
  assert(stage_v_282_1 == stage_v_282_2);
  assert(stage_v_283_1 == stage_v_283_2);
  assert(stage_v_284_1 == stage_v_284_2);
  assert(stage_v_285_1 == stage_v_285_2);
  assert(stage_v_286_1 == stage_v_286_2);
  assert(stage_v_287_1 == stage_v_287_2);
  assert(stage_v_288_1 == stage_v_288_2);
  assert(stage_v_289_1 == stage_v_289_2);
  assert(stage_v_290_1 == stage_v_290_2);
  assert(stage_v_291_1 == stage_v_291_2);
  assert(stage_v_292_1 == stage_v_292_2);
  assert(stage_v_293_1 == stage_v_293_2);
  assert(stage_v_294_1 == stage_v_294_2);
  assert(stage_v_295_1 == stage_v_295_2);
  assert(stage_v_296_1 == stage_v_296_2);
  assert(stage_v_297_1 == stage_v_297_2);
  assert(stage_v_298_1 == stage_v_298_2);
  assert(stage_v_299_1 == stage_v_299_2);
  assert(stage_v_300_1 == stage_v_300_2);
  assert(stage_v_301_1 == stage_v_301_2);
  assert(stage_v_302_1 == stage_v_302_2);
  assert(stage_v_303_1 == stage_v_303_2);
  assert(stage_v_304_1 == stage_v_304_2);
  assert(stage_v_305_1 == stage_v_305_2);
  assert(stage_v_306_1 == stage_v_306_2);
  assert(stage_v_307_1 == stage_v_307_2);
  assert(stage_v_308_1 == stage_v_308_2);
  assert(stage_v_309_1 == stage_v_309_2);
  assert(stage_v_310_1 == stage_v_310_2);
  assert(stage_v_311_1 == stage_v_311_2);
  assert(stage_v_312_1 == stage_v_312_2);
  assert(stage_v_313_1 == stage_v_313_2);
  assert(stage_v_314_1 == stage_v_314_2);
  assert(stage_v_315_1 == stage_v_315_2);
  assert(stage_v_316_1 == stage_v_316_2);
  assert(stage_v_317_1 == stage_v_317_2);
  assert(stage_v_318_1 == stage_v_318_2);
  assert(stage_v_319_1 == stage_v_319_2);
  assert(stage_v_320_1 == stage_v_320_2);
  assert(stage_v_321_1 == stage_v_321_2);
  assert(stage_v_322_1 == stage_v_322_2);
  assert(stage_v_323_1 == stage_v_323_2);
  assert(stage_v_324_1 == stage_v_324_2);
  assert(stage_v_325_1 == stage_v_325_2);
  assert(stage_v_326_1 == stage_v_326_2);
  assert(stage_v_327_1 == stage_v_327_2);
  assert(stage_v_328_1 == stage_v_328_2);
  assert(stage_v_329_1 == stage_v_329_2);
  assert(stage_v_330_1 == stage_v_330_2);
  assert(stage_v_331_1 == stage_v_331_2);
  assert(stage_v_332_1 == stage_v_332_2);
  assert(stage_v_333_1 == stage_v_333_2);
  assert(stage_v_334_1 == stage_v_334_2);
  assert(stage_v_335_1 == stage_v_335_2);
  assert(stage_v_336_1 == stage_v_336_2);
  assert(stage_v_337_1 == stage_v_337_2);
  assert(stage_v_338_1 == stage_v_338_2);
  assert(stage_v_339_1 == stage_v_339_2);
  assert(stage_v_340_1 == stage_v_340_2);
  assert(stage_v_341_1 == stage_v_341_2);
  assert(stage_v_342_1 == stage_v_342_2);
  assert(stage_v_343_1 == stage_v_343_2);
  assert(stage_v_344_1 == stage_v_344_2);
  assert(stage_v_345_1 == stage_v_345_2);
  assert(stage_v_346_1 == stage_v_346_2);
  assert(stage_v_347_1 == stage_v_347_2);
  assert(stage_v_348_1 == stage_v_348_2);
  assert(stage_v_349_1 == stage_v_349_2);
  assert(stage_v_350_1 == stage_v_350_2);
  assert(stage_v_351_1 == stage_v_351_2);
  assert(stage_v_352_1 == stage_v_352_2);
  assert(stage_v_353_1 == stage_v_353_2);
  assert(stage_v_354_1 == stage_v_354_2);
  assert(stage_v_355_1 == stage_v_355_2);
  assert(stage_v_356_1 == stage_v_356_2);
  assert(stage_v_357_1 == stage_v_357_2);
  assert(stage_v_358_1 == stage_v_358_2);
  assert(stage_v_359_1 == stage_v_359_2);
  assert(stage_v_360_1 == stage_v_360_2);
  assert(stage_v_361_1 == stage_v_361_2);
  assert(stage_v_362_1 == stage_v_362_2);
  assert(stage_v_363_1 == stage_v_363_2);
  assert(stage_v_364_1 == stage_v_364_2);
  assert(stage_v_365_1 == stage_v_365_2);
  assert(stage_v_366_1 == stage_v_366_2);
  assert(stage_v_367_1 == stage_v_367_2);
  assert(stage_v_368_1 == stage_v_368_2);
  assert(stage_v_369_1 == stage_v_369_2);
  assert(stage_v_370_1 == stage_v_370_2);
  assert(stage_v_371_1 == stage_v_371_2);
  assert(stage_v_372_1 == stage_v_372_2);
  assert(stage_v_373_1 == stage_v_373_2);
  assert(stage_v_374_1 == stage_v_374_2);
  assert(stage_v_375_1 == stage_v_375_2);
  assert(stage_v_376_1 == stage_v_376_2);
  assert(stage_v_377_1 == stage_v_377_2);
  assert(stage_v_378_1 == stage_v_378_2);
  assert(stage_v_379_1 == stage_v_379_2);
  assert(stage_v_380_1 == stage_v_380_2);
  assert(stage_v_381_1 == stage_v_381_2);
  assert(stage_v_382_1 == stage_v_382_2);
}


