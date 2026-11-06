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
struct AudioFrame_R000157_5713_0
{
  int rms;
  unsigned char gain;
  int envelope;
  int peak;
  int channels;
  int buffer[3];
};
struct Transaction_R000157_5713_1
{
  int fee;
  int status;
  int account_id;
  short balance;
  int buffer[3];
};
struct MatrixBlock_R000157_5713_2
{
  int stride;
  unsigned char density;
  short scale;
  unsigned char dim;
  unsigned char determinant;
  int buffer[3];
};
struct Vector3D_R000157_5713_3
{
  unsigned char norm_sq;
  int coord_z;
  int pitch;
  int buffer[3];
};
union ColorPixel_R000157_5713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000157_5713_1
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
void fn_R000157_5713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000157_5713_0 st_1 = {0};
  struct AudioFrame_R000157_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int metric_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_41_1 > 48)
  {
    acc_1 = ((acc_1 + (metric_41_1 * 2)) + 5) & 127;
    aux_1 ^= metric_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_41_2 > 48)
  {
    acc_2 = ((acc_2 + (metric_41_2 * 2)) + 5) & 127;
    aux_2 ^= metric_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_41_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_41_1 == metric_41_2);
}

int fn_R000157_5713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000157_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int metric_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_41 > 48)
  {
    acc = ((acc + (metric_41 * 2)) + 5) & 127;
    aux ^= metric_41 & 15;
  }
  else
  {
    acc = ((acc - metric_41) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000157_5713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st_1 = {0};
  struct Transaction_R000157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_88_1)
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

  switch (checksum_88_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_79_1 = local_arr_1[aux_1 % 3];
  int damping_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_88_1 == checksum_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_79_1 == damping_79_2);
}

int fn_R000157_5713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_88 = (aux + st.buffer[1]) & 3;
  switch (checksum_88)
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

  int local_arr[3] = {4, 9, 15};
  int damping_79 = local_arr[aux % 3];
  acc = (acc + (damping_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000157_5713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000157_5713_0 st_1 = {0};
  struct AudioFrame_R000157_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_74_1 = local_arr_1[aux_1 % 3];
  int threshold_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_74_2 * 2)) & 127;
  int sample_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_29_1)
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

  switch (sample_29_2)
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

  int window_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_63_1 > 43)
  {
    acc_1 = ((acc_1 + (window_63_1 * 2)) + 5) & 127;
    aux_1 ^= window_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_63_2 > 43)
  {
    acc_2 = ((acc_2 + (window_63_2 * 2)) + 5) & 127;
    aux_2 ^= window_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_23_1) & 63;
  aux_2 = (aux_2 + window_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_74_1 == threshold_74_2);
  assert(sample_29_1 == sample_29_2);
  assert(window_63_1 == window_63_2);
  assert(window_23_1 == window_23_2);
}

int fn_R000157_5713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000157_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int threshold_74 = local_arr[aux % 3];
  acc = (acc + (threshold_74 * 2)) & 127;
  int sample_29 = (aux + st.buffer[1]) & 3;
  switch (sample_29)
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

  int window_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_63 > 43)
  {
    acc = ((acc + (window_63 * 2)) + 5) & 127;
    aux ^= window_63 & 15;
  }
  else
  {
    acc = ((acc - window_63) + 11) & 127;
    aux += 3;
  }
  int window_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000157_5713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000157_5713_2 st_1 = {0};
  struct MatrixBlock_R000157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_29_1 = local_arr_1[aux_1 % 3];
  int sample_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_29_2 * 2)) & 127;
  int scale_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_47_1) & 63;
  aux_2 = (aux_2 + scale_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_29_1 == sample_29_2);
  assert(scale_47_1 == scale_47_2);
}

int fn_R000157_5713_3(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int sample_29 = local_arr[aux % 3];
  acc = (acc + (sample_29 * 2)) & 127;
  int scale_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000157_5713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st_1 = {0};
  struct Transaction_R000157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int pivot_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_19_1) & 63;
  aux_2 = (aux_2 + pivot_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_66_1)
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

  switch (tally_66_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_19_1 == pivot_19_2);
  assert(tally_66_1 == tally_66_2);
}

int fn_R000157_5713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int pivot_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_19) & 63;
  acc ^= aux;
  int tally_66 = (aux + st.buffer[1]) & 3;
  switch (tally_66)
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

  return (acc + aux) & 255;
}

void fn_R000157_5713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st_1 = {0};
  struct Transaction_R000157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int threshold_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_57_1) & 63;
  aux_2 = (aux_2 + threshold_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_55_1 = local_arr_1[aux_1 % 3];
  int parity_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_55_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_79_1 > 35)
  {
    acc_1 = ((acc_1 + (quantum_79_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_79_2 > 35)
  {
    acc_2 = ((acc_2 + (quantum_79_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_57_1 == threshold_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_55_1 == parity_55_2);
  assert(quantum_79_1 == quantum_79_2);
}

int fn_R000157_5713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int threshold_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_57) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_55 = local_arr[aux % 3];
  acc = (acc + (parity_55 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_79 > 35)
  {
    acc = ((acc + (quantum_79 * 2)) + 5) & 127;
    aux ^= quantum_79 & 15;
  }
  else
  {
    acc = ((acc - quantum_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000157_5713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st_1 = {0};
  struct Transaction_R000157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int tracker_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_19_1) & 63;
  aux_2 = (aux_2 + tracker_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_80_1 = local_arr_1[aux_1 % 3];
  int mask_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_80_2 * 2)) & 127;
  int vector_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_70_1)
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

  switch (vector_70_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_19_1 == tracker_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_80_1 == mask_80_2);
  assert(vector_70_1 == vector_70_2);
}

int fn_R000157_5713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int tracker_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_19) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_80 = local_arr[aux % 3];
  acc = (acc + (mask_80 * 2)) & 127;
  int vector_70 = (aux + st.buffer[1]) & 3;
  switch (vector_70)
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

void fn_R000157_5713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st_1 = {0};
  struct Transaction_R000157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int threshold_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_64_1)
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

  switch (threshold_64_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_45_1 > 41)
  {
    acc_1 = ((acc_1 + (residue_45_1 * 2)) + 5) & 127;
    aux_1 ^= residue_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_45_2 > 41)
  {
    acc_2 = ((acc_2 + (residue_45_2 * 2)) + 5) & 127;
    aux_2 ^= residue_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_45_1) & 63;
  aux_2 = (aux_2 + damping_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_64_1 == threshold_64_2);
  assert(residue_45_1 == residue_45_2);
  assert(damping_45_1 == damping_45_2);
}

int fn_R000157_5713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int threshold_64 = (aux + st.buffer[1]) & 3;
  switch (threshold_64)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_45 > 41)
  {
    acc = ((acc + (residue_45 * 2)) + 5) & 127;
    aux ^= residue_45 & 15;
  }
  else
  {
    acc = ((acc - residue_45) + 11) & 127;
    aux += 3;
  }
  int damping_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000157_5713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000157_5713_2 st_1 = {0};
  struct MatrixBlock_R000157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quantum_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_38_1) & 63;
  aux_2 = (aux_2 + quantum_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_31_1 > 26)
  {
    acc_1 = ((acc_1 + (vector_31_1 * 2)) + 5) & 127;
    aux_1 ^= vector_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_31_2 > 26)
  {
    acc_2 = ((acc_2 + (vector_31_2 * 2)) + 5) & 127;
    aux_2 ^= vector_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_46_1 = local_arr_1[aux_1 % 3];
  int quotient_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_38_1 == quantum_38_2);
  assert(vector_31_1 == vector_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_46_1 == quotient_46_2);
}

int fn_R000157_5713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quantum_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_38) & 63;
  acc ^= aux;
  int vector_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_31 > 26)
  {
    acc = ((acc + (vector_31 * 2)) + 5) & 127;
    aux ^= vector_31 & 15;
  }
  else
  {
    acc = ((acc - vector_31) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_46 = local_arr[aux % 3];
  acc = (acc + (quotient_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000157_5713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st_1 = {0};
  struct Transaction_R000157_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int checksum_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_49_1 > 30)
  {
    acc_1 = ((acc_1 + (checksum_49_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_49_2 > 30)
  {
    acc_2 = ((acc_2 + (checksum_49_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_49_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_17_1 = local_arr_1[aux_1 % 3];
  int margin_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_17_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_49_1 == checksum_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_17_1 == margin_17_2);
}

int fn_R000157_5713_9(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000157_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int checksum_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_49 > 30)
  {
    acc = ((acc + (checksum_49 * 2)) + 5) & 127;
    aux ^= checksum_49 & 15;
  }
  else
  {
    acc = ((acc - checksum_49) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_17 = local_arr[aux % 3];
  acc = (acc + (margin_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000157_5713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000157_5713_3 st_1 = {0};
  struct Vector3D_R000157_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int margin_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_52_1)
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

  switch (margin_52_2)
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

  int coefficient_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_35_1 > 29)
  {
    acc_1 = ((acc_1 + (coefficient_35_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_35_2 > 29)
  {
    acc_2 = ((acc_2 + (coefficient_35_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_42_1) & 63;
  aux_2 = (aux_2 + vector_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_52_1 == margin_52_2);
  assert(coefficient_35_1 == coefficient_35_2);
  assert(vector_42_1 == vector_42_2);
}

int fn_R000157_5713_10(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000157_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int margin_52 = (aux + st.buffer[1]) & 3;
  switch (margin_52)
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

  int coefficient_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_35 > 29)
  {
    acc = ((acc + (coefficient_35 * 2)) + 5) & 127;
    aux ^= coefficient_35 & 15;
  }
  else
  {
    acc = ((acc - coefficient_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000157_5713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000157_5713_0 st_1 = {0};
  struct AudioFrame_R000157_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int cursor_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_84_1) & 63;
  aux_2 = (aux_2 + cursor_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_90_1 = local_arr_1[aux_1 % 3];
  int cursor_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_90_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_84_1 == cursor_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_90_1 == cursor_90_2);
}

int fn_R000157_5713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000157_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int cursor_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_84) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_90 = local_arr[aux % 3];
  acc = (acc + (cursor_90 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000157_5713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000157_5713_2 st_1 = {0};
  struct MatrixBlock_R000157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int residue_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_46_1)
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

  switch (residue_46_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_26_1 = local_arr_1[aux_1 % 3];
  int weight_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_26_2 * 2)) & 127;
  int pivot_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_80_1) & 63;
  aux_2 = (aux_2 + pivot_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_46_1 == residue_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_26_1 == weight_26_2);
  assert(pivot_80_1 == pivot_80_2);
}

int fn_R000157_5713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int residue_46 = (aux + st.buffer[1]) & 3;
  switch (residue_46)
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

  int local_arr[3] = {4, 9, 15};
  int weight_26 = local_arr[aux % 3];
  acc = (acc + (weight_26 * 2)) & 127;
  int pivot_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_80) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000157_5713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000157_5713_2 st_1 = {0};
  struct MatrixBlock_R000157_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_23_1 = local_arr_1[aux_1 % 3];
  int residue_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_23_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_50_1)
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

  switch (damping_50_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_23_1 == residue_23_2);
  assert(damping_50_1 == damping_50_2);
}

int fn_R000157_5713_13(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000157_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int residue_23 = local_arr[aux % 3];
  acc = (acc + (residue_23 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_50 = (aux + st.buffer[1]) & 3;
  switch (damping_50)
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

void main()
{
  int sec_r000157_0_1;
  int sec_r000157_0_2;
  int sec_r000157_1_1;
  int sec_r000157_1_2;
  int sec_r000157_2_1;
  int sec_r000157_2_2;
  int sec_r000157_3_1;
  int sec_r000157_3_2;
  int sec_r000157_4_1;
  int sec_r000157_4_2;
  int sec_r000157_5_1;
  int sec_r000157_5_2;
  int sec_r000157_6_1;
  int sec_r000157_6_2;
  int sec_r000157_7_1;
  int sec_r000157_7_2;
  int sec_r000157_8_1;
  int sec_r000157_8_2;
  int sec_r000157_9_1;
  int sec_r000157_9_2;
  int sec_r000157_10_1;
  int sec_r000157_10_2;
  int sec_r000157_11_1;
  int sec_r000157_11_2;
  int sec_r000157_12_1;
  int sec_r000157_12_2;
  int sec_r000157_13_1;
  int sec_r000157_13_2;
  int sec_r000157_14_1;
  int sec_r000157_14_2;
  int sec_r000157_15_1;
  int sec_r000157_15_2;
  int sec_r000157_16_1;
  int sec_r000157_16_2;
  int sec_r000157_17_1;
  int sec_r000157_17_2;
  int pub_r000157_0_1;
  int pub_r000157_0_2;
  int pub_r000157_1_1;
  int pub_r000157_1_2;
  int pub_r000157_2_1;
  int pub_r000157_2_2;
  int pub_r000157_3_1;
  int pub_r000157_3_2;
  int pub_r000157_4_1;
  int pub_r000157_4_2;
  int pub_r000157_5_1;
  int pub_r000157_5_2;
  int pub_r000157_6_1;
  int pub_r000157_6_2;
  int pub_r000157_7_1;
  int pub_r000157_7_2;
  int pub_r000157_8_1;
  int pub_r000157_8_2;
  int pub_r000157_9_1;
  int pub_r000157_9_2;
  int pub_r000157_10_1;
  int pub_r000157_10_2;
  int pub_r000157_11_1;
  int pub_r000157_11_2;
  int pub_r000157_12_1;
  int pub_r000157_12_2;
  int pub_r000157_13_1;
  int pub_r000157_13_2;
  int pub_r000157_14_1;
  int pub_r000157_14_2;
  int pub_r000157_15_1;
  int pub_r000157_15_2;
  int pub_r000157_16_1;
  int pub_r000157_16_2;
  int pub_r000157_17_1;
  int pub_r000157_17_2;
  int pub_r000157_18_1;
  int pub_r000157_18_2;
  int pub_r000157_19_1;
  int pub_r000157_19_2;
  int pub_r000157_20_1;
  int pub_r000157_20_2;
  int pub_r000157_21_1;
  int pub_r000157_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000157_0_1 >= (-100)) && (pub_r000157_0_1 <= 100));
  __CPROVER_assume((pub_r000157_0_2 >= (-100)) && (pub_r000157_0_2 <= 100));
  __CPROVER_assume((pub_r000157_1_1 >= (-100)) && (pub_r000157_1_1 <= 100));
  __CPROVER_assume((pub_r000157_1_2 >= (-100)) && (pub_r000157_1_2 <= 100));
  __CPROVER_assume((pub_r000157_2_1 >= (-100)) && (pub_r000157_2_1 <= 100));
  __CPROVER_assume((pub_r000157_2_2 >= (-100)) && (pub_r000157_2_2 <= 100));
  __CPROVER_assume((pub_r000157_3_1 >= (-100)) && (pub_r000157_3_1 <= 100));
  __CPROVER_assume((pub_r000157_3_2 >= (-100)) && (pub_r000157_3_2 <= 100));
  __CPROVER_assume((pub_r000157_4_1 >= (-100)) && (pub_r000157_4_1 <= 100));
  __CPROVER_assume((pub_r000157_4_2 >= (-100)) && (pub_r000157_4_2 <= 100));
  __CPROVER_assume((pub_r000157_5_1 >= (-100)) && (pub_r000157_5_1 <= 100));
  __CPROVER_assume((pub_r000157_5_2 >= (-100)) && (pub_r000157_5_2 <= 100));
  __CPROVER_assume((pub_r000157_6_1 >= (-100)) && (pub_r000157_6_1 <= 100));
  __CPROVER_assume((pub_r000157_6_2 >= (-100)) && (pub_r000157_6_2 <= 100));
  __CPROVER_assume((pub_r000157_7_1 >= (-100)) && (pub_r000157_7_1 <= 100));
  __CPROVER_assume((pub_r000157_7_2 >= (-100)) && (pub_r000157_7_2 <= 100));
  __CPROVER_assume((pub_r000157_8_1 >= (-100)) && (pub_r000157_8_1 <= 100));
  __CPROVER_assume((pub_r000157_8_2 >= (-100)) && (pub_r000157_8_2 <= 100));
  __CPROVER_assume((pub_r000157_9_1 >= (-100)) && (pub_r000157_9_1 <= 100));
  __CPROVER_assume((pub_r000157_9_2 >= (-100)) && (pub_r000157_9_2 <= 100));
  __CPROVER_assume((pub_r000157_10_1 >= (-100)) && (pub_r000157_10_1 <= 100));
  __CPROVER_assume((pub_r000157_10_2 >= (-100)) && (pub_r000157_10_2 <= 100));
  __CPROVER_assume((pub_r000157_11_1 >= (-100)) && (pub_r000157_11_1 <= 100));
  __CPROVER_assume((pub_r000157_11_2 >= (-100)) && (pub_r000157_11_2 <= 100));
  __CPROVER_assume((pub_r000157_12_1 >= (-100)) && (pub_r000157_12_1 <= 100));
  __CPROVER_assume((pub_r000157_12_2 >= (-100)) && (pub_r000157_12_2 <= 100));
  __CPROVER_assume((pub_r000157_13_1 >= (-100)) && (pub_r000157_13_1 <= 100));
  __CPROVER_assume((pub_r000157_13_2 >= (-100)) && (pub_r000157_13_2 <= 100));
  __CPROVER_assume((pub_r000157_14_1 >= (-100)) && (pub_r000157_14_1 <= 100));
  __CPROVER_assume((pub_r000157_14_2 >= (-100)) && (pub_r000157_14_2 <= 100));
  __CPROVER_assume((pub_r000157_15_1 >= (-100)) && (pub_r000157_15_1 <= 100));
  __CPROVER_assume((pub_r000157_15_2 >= (-100)) && (pub_r000157_15_2 <= 100));
  __CPROVER_assume((pub_r000157_16_1 >= (-100)) && (pub_r000157_16_1 <= 100));
  __CPROVER_assume((pub_r000157_16_2 >= (-100)) && (pub_r000157_16_2 <= 100));
  __CPROVER_assume((pub_r000157_17_1 >= (-100)) && (pub_r000157_17_1 <= 100));
  __CPROVER_assume((pub_r000157_17_2 >= (-100)) && (pub_r000157_17_2 <= 100));
  __CPROVER_assume((pub_r000157_18_1 >= (-100)) && (pub_r000157_18_1 <= 100));
  __CPROVER_assume((pub_r000157_18_2 >= (-100)) && (pub_r000157_18_2 <= 100));
  __CPROVER_assume((pub_r000157_19_1 >= (-100)) && (pub_r000157_19_1 <= 100));
  __CPROVER_assume((pub_r000157_19_2 >= (-100)) && (pub_r000157_19_2 <= 100));
  __CPROVER_assume((pub_r000157_20_1 >= (-100)) && (pub_r000157_20_1 <= 100));
  __CPROVER_assume((pub_r000157_20_2 >= (-100)) && (pub_r000157_20_2 <= 100));
  __CPROVER_assume((pub_r000157_21_1 >= (-100)) && (pub_r000157_21_1 <= 100));
  __CPROVER_assume((pub_r000157_21_2 >= (-100)) && (pub_r000157_21_2 <= 100));
  __CPROVER_assume((sec_r000157_0_1 >= 0) && (sec_r000157_0_1 <= 255));
  __CPROVER_assume((sec_r000157_0_2 >= 0) && (sec_r000157_0_2 <= 255));
  __CPROVER_assume((sec_r000157_1_1 >= 0) && (sec_r000157_1_1 <= 255));
  __CPROVER_assume((sec_r000157_1_2 >= 0) && (sec_r000157_1_2 <= 255));
  __CPROVER_assume((sec_r000157_2_1 >= 0) && (sec_r000157_2_1 <= 255));
  __CPROVER_assume((sec_r000157_2_2 >= 0) && (sec_r000157_2_2 <= 255));
  __CPROVER_assume((sec_r000157_3_1 >= 0) && (sec_r000157_3_1 <= 255));
  __CPROVER_assume((sec_r000157_3_2 >= 0) && (sec_r000157_3_2 <= 255));
  __CPROVER_assume((sec_r000157_4_1 >= 0) && (sec_r000157_4_1 <= 255));
  __CPROVER_assume((sec_r000157_4_2 >= 0) && (sec_r000157_4_2 <= 255));
  __CPROVER_assume((sec_r000157_5_1 >= 0) && (sec_r000157_5_1 <= 255));
  __CPROVER_assume((sec_r000157_5_2 >= 0) && (sec_r000157_5_2 <= 255));
  __CPROVER_assume((sec_r000157_6_1 >= 0) && (sec_r000157_6_1 <= 255));
  __CPROVER_assume((sec_r000157_6_2 >= 0) && (sec_r000157_6_2 <= 255));
  __CPROVER_assume((sec_r000157_7_1 >= 0) && (sec_r000157_7_1 <= 255));
  __CPROVER_assume((sec_r000157_7_2 >= 0) && (sec_r000157_7_2 <= 255));
  __CPROVER_assume((sec_r000157_8_1 >= 0) && (sec_r000157_8_1 <= 255));
  __CPROVER_assume((sec_r000157_8_2 >= 0) && (sec_r000157_8_2 <= 255));
  __CPROVER_assume((sec_r000157_9_1 >= 0) && (sec_r000157_9_1 <= 255));
  __CPROVER_assume((sec_r000157_9_2 >= 0) && (sec_r000157_9_2 <= 255));
  __CPROVER_assume((sec_r000157_10_1 >= 0) && (sec_r000157_10_1 <= 255));
  __CPROVER_assume((sec_r000157_10_2 >= 0) && (sec_r000157_10_2 <= 255));
  __CPROVER_assume((sec_r000157_11_1 >= 0) && (sec_r000157_11_1 <= 255));
  __CPROVER_assume((sec_r000157_11_2 >= 0) && (sec_r000157_11_2 <= 255));
  __CPROVER_assume((sec_r000157_12_1 >= 0) && (sec_r000157_12_1 <= 255));
  __CPROVER_assume((sec_r000157_12_2 >= 0) && (sec_r000157_12_2 <= 255));
  __CPROVER_assume((sec_r000157_13_1 >= 0) && (sec_r000157_13_1 <= 255));
  __CPROVER_assume((sec_r000157_13_2 >= 0) && (sec_r000157_13_2 <= 255));
  __CPROVER_assume((sec_r000157_14_1 >= 0) && (sec_r000157_14_1 <= 255));
  __CPROVER_assume((sec_r000157_14_2 >= 0) && (sec_r000157_14_2 <= 255));
  __CPROVER_assume((sec_r000157_15_1 >= 0) && (sec_r000157_15_1 <= 255));
  __CPROVER_assume((sec_r000157_15_2 >= 0) && (sec_r000157_15_2 <= 255));
  __CPROVER_assume((sec_r000157_16_1 >= 0) && (sec_r000157_16_1 <= 255));
  __CPROVER_assume((sec_r000157_16_2 >= 0) && (sec_r000157_16_2 <= 255));
  __CPROVER_assume((sec_r000157_17_1 >= 0) && (sec_r000157_17_1 <= 255));
  __CPROVER_assume((sec_r000157_17_2 >= 0) && (sec_r000157_17_2 <= 255));
  struct AudioFrame_R000157_5713_0 st_var_0_1 = {0};
  struct AudioFrame_R000157_5713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000157_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000157_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000157_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000157_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000157_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000157_0_2 + 7) & 15;
  struct Transaction_R000157_5713_1 st_var_1_1 = {0};
  struct Transaction_R000157_5713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000157_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000157_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000157_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000157_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000157_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000157_0_2 + 9) & 15;
  struct MatrixBlock_R000157_5713_2 st_var_2_1 = {0};
  struct MatrixBlock_R000157_5713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000157_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000157_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000157_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000157_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000157_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000157_0_2 + 11) & 15;
  struct Vector3D_R000157_5713_3 st_var_3_1 = {0};
  struct Vector3D_R000157_5713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000157_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000157_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000157_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000157_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000157_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000157_0_2 + 13) & 15;
  union ColorPixel_R000157_5713_0 u_var_1;
  union ColorPixel_R000157_5713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_1_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 39)
    {
      chk_sum_1 ^= stage_v_3_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_3_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 39)
    {
      chk_sum_2 ^= stage_v_3_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = ((st_var_2_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_2_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 30)
    {
      chk_sum_1 ^= stage_v_6_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_6_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 30)
    {
      chk_sum_2 ^= stage_v_6_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 2) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_8_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 2) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (st_var_2_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_2_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_10_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_14_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((st_var_0_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_0_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 26)
    {
      chk_sum_1 ^= stage_v_16_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_16_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 26)
    {
      chk_sum_2 ^= stage_v_16_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 47)
    {
      chk_sum_1 ^= stage_v_17_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_17_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 47)
    {
      chk_sum_2 ^= stage_v_17_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = (st_var_3_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_3_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_27_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 29) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 37)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 37)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_30_1 = (st_var_2_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_2_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_30_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 32) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  int stage_v_32_1 = (st_var_0_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_0_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_32_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = ((st_var_2_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_2_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 28)
    {
      chk_sum_1 ^= stage_v_34_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_34_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 28)
    {
      chk_sum_2 ^= stage_v_34_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_35_1 = (st_var_3_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_3_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 5) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_35_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 5) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 54)
    {
      chk_sum_1 ^= stage_v_38_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_38_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 54)
    {
      chk_sum_2 ^= stage_v_38_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_40_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (50 & 31);
  int stage_v_45_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (50 & 31);
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= (stage_v_45_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_45_2 << 1) & 127;
  int stage_v_46_1 = (st_var_2_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_2_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_46_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_49_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 52) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_55_1 = (st_var_3_1.buffer[0] ^ 58) & 3;
  int stage_v_55_2 = (st_var_3_2.buffer[0] ^ 58) & 3;
  switch (stage_v_55_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_55_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 57) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (st_var_2_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_2_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 2) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_58_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 2) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_59_1 = ((st_var_3_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_3_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 52)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 52)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_62_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((st_var_0_1.buffer[1] * 2) + 199) & 63;
  int stage_v_64_2 = ((st_var_0_2.buffer[1] * 2) + 199) & 63;
  if (stage_v_64_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_64_1) - 5) & 255;
    if (stage_v_64_1 > 25)
    {
      chk_sum_1 ^= stage_v_64_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_64_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_64_2) - 5) & 255;
    if (stage_v_64_2 > 25)
    {
      chk_sum_2 ^= stage_v_64_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 66) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 67) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
  int stage_v_67_1 = ((st_var_3_1.buffer[1] * 2) + 208) & 63;
  int stage_v_67_2 = ((st_var_3_2.buffer[1] * 2) + 208) & 63;
  if (stage_v_67_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_67_1) - 5) & 255;
    if (stage_v_67_1 > 44)
    {
      chk_sum_1 ^= stage_v_67_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_67_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_67_2) - 5) & 255;
    if (stage_v_67_2 > 44)
    {
      chk_sum_2 ^= stage_v_67_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((st_var_1_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_1_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 39)
    {
      chk_sum_1 ^= stage_v_69_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_69_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 39)
    {
      chk_sum_2 ^= stage_v_69_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_70_1 = ((st_var_2_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_2_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 39)
    {
      chk_sum_1 ^= stage_v_70_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_70_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 39)
    {
      chk_sum_2 ^= stage_v_70_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_71_1 = (st_var_3_1.buffer[0] ^ 74) & 3;
  int stage_v_71_2 = (st_var_3_2.buffer[0] ^ 74) & 3;
  switch (stage_v_71_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_71_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_74_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_75_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (80 & 31);
  int stage_v_75_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (80 & 31);
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= (stage_v_75_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_75_2 << 1) & 127;
  int stage_v_76_1 = ((st_var_0_1.buffer[1] * 2) + 235) & 63;
  int stage_v_76_2 = ((st_var_0_2.buffer[1] * 2) + 235) & 63;
  if (stage_v_76_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_76_1) - 5) & 255;
    if (stage_v_76_1 > 38)
    {
      chk_sum_1 ^= stage_v_76_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_76_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_76_2) - 5) & 255;
    if (stage_v_76_2 > 38)
    {
      chk_sum_2 ^= stage_v_76_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((st_var_2_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_2_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 31)
    {
      chk_sum_1 ^= stage_v_78_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_78_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 31)
    {
      chk_sum_2 ^= stage_v_78_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000157_6_1 & 1) != 0)
  {
    if ((sec_r000157_2_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000157_15_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000157_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000157_15_1 + 7) & 127;
  }
  if ((sec_r000157_6_2 & 1) != 0)
  {
    if ((sec_r000157_2_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000157_15_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000157_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000157_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000157_4_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000157_4_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000157_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000157_4_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000157_4_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000157_4_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000157_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000157_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000157_3_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000157_17_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000157_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000157_17_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000157_3_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000157_17_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000157_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000157_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000157_5_1 & 1) != 0)
  {
    if ((sec_r000157_16_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000157_3_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000157_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000157_3_1 + 7) & 127;
  }
  if ((sec_r000157_5_2 & 1) != 0)
  {
    if ((sec_r000157_16_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000157_3_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000157_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000157_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000157_13_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000157_4_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000157_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000157_4_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000157_13_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000157_4_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000157_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000157_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000157_4_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000157_1_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000157_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000157_1_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000157_4_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000157_1_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000157_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000157_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000157_10_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000157_6_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000157_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000157_6_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000157_10_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000157_6_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000157_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000157_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000157_11_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000157_15_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000157_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000157_15_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000157_11_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000157_15_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000157_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000157_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000157_11_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000157_14_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000157_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000157_14_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000157_11_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000157_14_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000157_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000157_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000157_4_1 & 1) != 0)
  {
    if ((sec_r000157_1_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000157_19_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000157_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000157_19_1 + 7) & 127;
  }
  if ((sec_r000157_4_2 & 1) != 0)
  {
    if ((sec_r000157_1_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000157_19_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000157_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000157_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000157_0_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000157_20_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000157_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000157_20_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000157_0_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000157_20_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000157_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000157_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000157_1_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000157_13_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000157_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000157_13_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000157_1_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000157_13_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000157_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000157_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000157_12_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000157_14_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000157_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000157_14_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000157_12_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000157_14_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000157_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000157_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000157_0_1 & 1) != 0)
  {
    if ((sec_r000157_11_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000157_15_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000157_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000157_15_1 + 7) & 127;
  }
  if ((sec_r000157_0_2 & 1) != 0)
  {
    if ((sec_r000157_11_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000157_15_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000157_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000157_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000157_5_1 & 1) != 0)
  {
    if ((sec_r000157_17_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000157_14_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000157_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000157_14_1 + 7) & 127;
  }
  if ((sec_r000157_5_2 & 1) != 0)
  {
    if ((sec_r000157_17_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000157_14_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000157_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000157_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000157_6_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000157_10_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000157_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000157_10_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000157_6_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000157_10_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000157_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000157_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000157_13_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000157_0_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000157_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000157_0_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000157_13_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000157_0_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000157_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000157_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000157_5_1 & 1) != 0)
  {
    if ((sec_r000157_17_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000157_12_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000157_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000157_12_1 + 7) & 127;
  }
  if ((sec_r000157_5_2 & 1) != 0)
  {
    if ((sec_r000157_17_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000157_12_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000157_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000157_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000157_6_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000157_14_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000157_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000157_14_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000157_6_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000157_14_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000157_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000157_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000157_16_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000157_20_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000157_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000157_20_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000157_16_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000157_20_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000157_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000157_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000157_7_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000157_11_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000157_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000157_11_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000157_7_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000157_11_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000157_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000157_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000157_8_1 & 1) != 0)
  {
    if ((sec_r000157_9_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000157_19_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000157_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000157_19_1 + 7) & 127;
  }
  if ((sec_r000157_8_2 & 1) != 0)
  {
    if ((sec_r000157_9_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000157_19_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000157_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000157_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000157_17_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000157_9_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000157_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000157_9_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000157_17_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000157_9_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000157_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000157_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000157_10_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000157_14_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000157_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000157_14_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000157_10_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000157_14_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000157_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000157_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000157_11_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000157_0_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000157_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000157_0_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000157_11_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000157_0_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000157_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000157_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000157_10_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000157_1_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000157_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000157_1_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000157_10_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000157_1_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000157_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000157_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000157_4_1 & 1) != 0)
  {
    if ((sec_r000157_7_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000157_2_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000157_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000157_2_1 + 7) & 127;
  }
  if ((sec_r000157_4_2 & 1) != 0)
  {
    if ((sec_r000157_7_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000157_2_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000157_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000157_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000157_1_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000157_20_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000157_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000157_20_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000157_1_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000157_20_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000157_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000157_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000157_14_1 & 1) != 0)
  {
    if ((sec_r000157_5_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000157_20_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000157_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000157_20_1 + 7) & 127;
  }
  if ((sec_r000157_14_2 & 1) != 0)
  {
    if ((sec_r000157_5_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000157_20_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000157_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000157_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000157_3_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000157_18_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000157_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000157_18_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000157_3_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000157_18_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000157_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000157_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000157_8_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000157_8_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000157_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000157_8_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000157_8_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000157_8_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000157_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000157_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000157_1_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000157_0_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000157_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000157_0_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000157_1_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000157_0_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000157_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000157_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000157_8_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000157_12_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000157_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000157_12_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000157_8_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000157_12_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000157_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000157_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000157_9_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000157_19_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000157_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000157_19_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000157_9_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000157_19_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000157_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000157_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000157_11_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000157_21_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000157_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000157_21_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000157_11_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000157_21_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000157_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000157_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000157_5_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000157_19_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000157_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000157_19_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000157_5_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000157_19_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000157_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000157_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000157_7_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000157_4_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000157_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000157_4_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000157_7_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000157_4_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000157_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000157_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000157_12_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000157_8_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000157_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000157_8_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000157_12_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000157_8_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000157_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000157_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000157_17_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000157_13_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000157_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000157_13_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000157_17_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000157_13_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000157_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000157_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000157_17_1 & 1) != 0)
  {
    if ((sec_r000157_15_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000157_5_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000157_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000157_5_1 + 7) & 127;
  }
  if ((sec_r000157_17_2 & 1) != 0)
  {
    if ((sec_r000157_15_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000157_5_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000157_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000157_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000157_14_1 & 1) != 0)
  {
    if ((sec_r000157_3_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000157_11_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000157_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000157_11_1 + 7) & 127;
  }
  if ((sec_r000157_14_2 & 1) != 0)
  {
    if ((sec_r000157_3_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000157_11_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000157_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000157_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000157_1_1 & 1) != 0)
  {
    if ((sec_r000157_6_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000157_17_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000157_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000157_17_1 + 7) & 127;
  }
  if ((sec_r000157_1_2 & 1) != 0)
  {
    if ((sec_r000157_6_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000157_17_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000157_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000157_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000157_14_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000157_6_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000157_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000157_6_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000157_14_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000157_6_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000157_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000157_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000157_15_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000157_1_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000157_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000157_1_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000157_15_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000157_1_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000157_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000157_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000157_15_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000157_11_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000157_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000157_11_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000157_15_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000157_11_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000157_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000157_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000157_1_1 & 1) != 0)
  {
    if ((sec_r000157_3_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000157_2_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000157_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000157_2_1 + 7) & 127;
  }
  if ((sec_r000157_1_2 & 1) != 0)
  {
    if ((sec_r000157_3_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000157_2_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000157_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000157_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000157_2_1 & 1) != 0)
  {
    if ((sec_r000157_10_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000157_7_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000157_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000157_7_1 + 7) & 127;
  }
  if ((sec_r000157_2_2 & 1) != 0)
  {
    if ((sec_r000157_10_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000157_7_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000157_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000157_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((sec_r000157_0_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000157_11_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000157_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000157_11_1 + 7) & 127;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((sec_r000157_0_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000157_11_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000157_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000157_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000157_7_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000157_16_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000157_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000157_16_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000157_7_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000157_16_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000157_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000157_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000157_6_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000157_15_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000157_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000157_15_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000157_6_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000157_15_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000157_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000157_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000157_5_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000157_10_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000157_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000157_10_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000157_5_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000157_10_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000157_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000157_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000157_10_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000157_19_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000157_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000157_19_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000157_10_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000157_19_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000157_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000157_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000157_5_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000157_21_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000157_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000157_21_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000157_5_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000157_21_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000157_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000157_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000157_17_1 & 1) != 0)
  {
    if ((sec_r000157_14_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000157_18_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000157_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000157_18_1 + 7) & 127;
  }
  if ((sec_r000157_17_2 & 1) != 0)
  {
    if ((sec_r000157_14_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000157_18_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000157_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000157_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000157_17_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000157_10_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000157_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000157_10_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000157_17_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000157_10_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000157_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000157_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000157_11_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000157_7_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000157_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000157_7_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000157_11_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000157_7_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000157_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000157_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000157_0_1 & 1) != 0)
  {
    if ((sec_r000157_12_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000157_17_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000157_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000157_17_1 + 7) & 127;
  }
  if ((sec_r000157_0_2 & 1) != 0)
  {
    if ((sec_r000157_12_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000157_17_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000157_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000157_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((sec_r000157_5_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000157_4_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000157_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000157_4_1 + 7) & 127;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((sec_r000157_5_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000157_4_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000157_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000157_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000157_7_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000157_10_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000157_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000157_10_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000157_7_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000157_10_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000157_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000157_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000157_13_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000157_3_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000157_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000157_3_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000157_13_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000157_3_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000157_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000157_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000157_12_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000157_5_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000157_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000157_5_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000157_12_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000157_5_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000157_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000157_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000157_1_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000157_10_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000157_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000157_10_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000157_1_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000157_10_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000157_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000157_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000157_5_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000157_21_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000157_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000157_21_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000157_5_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000157_21_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000157_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000157_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000157_4_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000157_8_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000157_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000157_8_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000157_4_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000157_8_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000157_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000157_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000157_16_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000157_21_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000157_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000157_21_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000157_16_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000157_21_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000157_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000157_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000157_9_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000157_2_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000157_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000157_2_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000157_9_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000157_2_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000157_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000157_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000157_17_1 & 1) != 0)
  {
    if ((sec_r000157_13_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000157_21_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000157_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000157_21_1 + 7) & 127;
  }
  if ((sec_r000157_17_2 & 1) != 0)
  {
    if ((sec_r000157_13_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000157_21_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000157_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000157_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000157_17_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000157_16_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000157_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000157_16_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000157_17_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000157_16_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000157_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000157_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000157_7_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000157_1_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000157_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000157_1_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000157_7_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000157_1_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000157_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000157_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000157_15_1 & 1) != 0)
  {
    if ((sec_r000157_1_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000157_21_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000157_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000157_21_1 + 7) & 127;
  }
  if ((sec_r000157_15_2 & 1) != 0)
  {
    if ((sec_r000157_1_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000157_21_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000157_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000157_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((sec_r000157_3_1 & 1) != 0)
  {
    if ((sec_r000157_5_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000157_2_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000157_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000157_2_1 + 7) & 127;
  }
  if ((sec_r000157_3_2 & 1) != 0)
  {
    if ((sec_r000157_5_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000157_2_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000157_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000157_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000157_17_1 & 1) != 0)
  {
    if ((sec_r000157_13_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000157_5_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000157_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000157_5_1 + 7) & 127;
  }
  if ((sec_r000157_17_2 & 1) != 0)
  {
    if ((sec_r000157_13_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000157_5_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000157_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000157_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000157_13_1 & 1) != 0)
  {
    if ((sec_r000157_0_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000157_21_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000157_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000157_21_1 + 7) & 127;
  }
  if ((sec_r000157_13_2 & 1) != 0)
  {
    if ((sec_r000157_0_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000157_21_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000157_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000157_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000157_17_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000157_0_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000157_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000157_0_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000157_17_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000157_0_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000157_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000157_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000157_11_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000157_2_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000157_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000157_2_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000157_11_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000157_2_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000157_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000157_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000157_6_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000157_16_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000157_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000157_16_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000157_6_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000157_16_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000157_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000157_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((sec_r000157_16_1 & 1) != 0)
  {
    if ((sec_r000157_1_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000157_14_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000157_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000157_14_1 + 7) & 127;
  }
  if ((sec_r000157_16_2 & 1) != 0)
  {
    if ((sec_r000157_1_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000157_14_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000157_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000157_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((sec_r000157_17_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000157_18_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000157_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000157_18_1 + 7) & 127;
  }
  if ((stage_v_155_2 & 1) != 0)
  {
    if ((sec_r000157_17_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000157_18_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000157_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000157_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((sec_r000157_9_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000157_12_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000157_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000157_12_1 + 7) & 127;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((sec_r000157_9_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000157_12_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000157_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000157_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000157_3_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000157_21_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000157_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000157_21_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000157_3_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000157_21_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000157_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000157_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((sec_r000157_3_1 & 1) != 0)
  {
    if ((sec_r000157_5_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000157_0_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000157_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000157_0_1 + 7) & 127;
  }
  if ((sec_r000157_3_2 & 1) != 0)
  {
    if ((sec_r000157_5_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000157_0_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000157_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000157_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((sec_r000157_10_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000157_8_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000157_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000157_8_1 + 7) & 127;
  }
  if ((stage_v_149_2 & 1) != 0)
  {
    if ((sec_r000157_10_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000157_8_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000157_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000157_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000157_5_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000157_5_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000157_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000157_5_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000157_5_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000157_5_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000157_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000157_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000157_16_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000157_19_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000157_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000157_19_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000157_16_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000157_19_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000157_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000157_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000157_6_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000157_7_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000157_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000157_7_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000157_6_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000157_7_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000157_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000157_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000157_2_1 != sec_r000157_2_2);
  __CPROVER_assume(pub_r000157_18_1 == pub_r000157_18_2);
  __CPROVER_assume(sec_r000157_11_1 != sec_r000157_11_2);
  __CPROVER_assume(sec_r000157_13_1 != sec_r000157_13_2);
  __CPROVER_assume(pub_r000157_1_1 == pub_r000157_1_2);
  __CPROVER_assume(sec_r000157_7_1 != sec_r000157_7_2);
  __CPROVER_assume(pub_r000157_21_1 == pub_r000157_21_2);
  __CPROVER_assume(sec_r000157_14_1 != sec_r000157_14_2);
  __CPROVER_assume(pub_r000157_17_1 == pub_r000157_17_2);
  __CPROVER_assume(sec_r000157_10_1 != sec_r000157_10_2);
  __CPROVER_assume(sec_r000157_9_1 != sec_r000157_9_2);
  __CPROVER_assume(sec_r000157_3_1 != sec_r000157_3_2);
  __CPROVER_assume(pub_r000157_3_1 == pub_r000157_3_2);
  __CPROVER_assume(sec_r000157_0_1 != sec_r000157_0_2);
  __CPROVER_assume(pub_r000157_2_1 == pub_r000157_2_2);
  __CPROVER_assume(pub_r000157_13_1 == pub_r000157_13_2);
  __CPROVER_assume(sec_r000157_12_1 != sec_r000157_12_2);
  __CPROVER_assume(pub_r000157_8_1 == pub_r000157_8_2);
  __CPROVER_assume(pub_r000157_10_1 == pub_r000157_10_2);
  __CPROVER_assume(pub_r000157_6_1 == pub_r000157_6_2);
  __CPROVER_assume(pub_r000157_15_1 == pub_r000157_15_2);
  __CPROVER_assume(pub_r000157_9_1 == pub_r000157_9_2);
  __CPROVER_assume(sec_r000157_5_1 != sec_r000157_5_2);
  __CPROVER_assume(pub_r000157_12_1 == pub_r000157_12_2);
  __CPROVER_assume(sec_r000157_8_1 != sec_r000157_8_2);
  __CPROVER_assume(sec_r000157_17_1 != sec_r000157_17_2);
  __CPROVER_assume(pub_r000157_20_1 == pub_r000157_20_2);
  __CPROVER_assume(pub_r000157_7_1 == pub_r000157_7_2);
  __CPROVER_assume(pub_r000157_14_1 == pub_r000157_14_2);
  __CPROVER_assume(sec_r000157_16_1 != sec_r000157_16_2);
  __CPROVER_assume(pub_r000157_19_1 == pub_r000157_19_2);
  __CPROVER_assume(sec_r000157_6_1 != sec_r000157_6_2);
  __CPROVER_assume(sec_r000157_15_1 != sec_r000157_15_2);
  __CPROVER_assume(sec_r000157_1_1 != sec_r000157_1_2);
  __CPROVER_assume(pub_r000157_5_1 == pub_r000157_5_2);
  __CPROVER_assume(pub_r000157_0_1 == pub_r000157_0_2);
  __CPROVER_assume(sec_r000157_4_1 != sec_r000157_4_2);
  __CPROVER_assume(pub_r000157_4_1 == pub_r000157_4_2);
  __CPROVER_assume(pub_r000157_16_1 == pub_r000157_16_2);
  __CPROVER_assume(pub_r000157_11_1 == pub_r000157_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.norm_sq == st_var_3_2.norm_sq);
  assert(st_var_3_1.coord_z == st_var_3_2.coord_z);
  assert(st_var_3_1.pitch == st_var_3_2.pitch);
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
}


