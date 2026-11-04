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
struct MatrixBlock_R000991_9113_0
{
  short dim;
  short scale;
  unsigned char density;
  short stride;
  int determinant;
  int buffer[3];
};
struct DeviceConfig_R000991_9113_1
{
  short id;
  int stop_bits;
  short port;
  int baud_rate;
  int timeout;
  short parity;
  int buffer[3];
};
struct AudioFrame_R000991_9113_2
{
  int gain;
  int channels;
  unsigned char peak;
  short sample_rate;
  short envelope;
  unsigned char rms;
  int buffer[3];
};
struct CipherContext_R000991_9113_3
{
  int counter;
  int nonce;
  int round_key;
  int iv;
  short tag;
  int buffer[3];
};
union TelemetryField_R000991_9113_0
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
void fn_R000991_9113_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st_1 = {0};
  struct MatrixBlock_R000991_9113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int sample_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_41_1 > 27)
  {
    acc_1 = ((acc_1 + (sample_41_1 * 2)) + 5) & 127;
    aux_1 ^= sample_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_41_2 > 27)
  {
    acc_2 = ((acc_2 + (sample_41_2 * 2)) + 5) & 127;
    aux_2 ^= sample_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_28_1 = local_arr_1[aux_1 % 3];
  int mask_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_41_1 == sample_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_28_1 == mask_28_2);
}

int fn_R000991_9113_0(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int sample_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_41 > 27)
  {
    acc = ((acc + (sample_41 * 2)) + 5) & 127;
    aux ^= sample_41 & 15;
  }
  else
  {
    acc = ((acc - sample_41) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_28 = local_arr[aux % 3];
  acc = (acc + (mask_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st_1 = {0};
  struct AudioFrame_R000991_9113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_23_1 = local_arr_1[aux_1 % 3];
  int scale_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_23_2 * 2)) & 127;
  int anchor_33_1 = 0;
  int anchor_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_33_1 = ((anchor_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_33_2 = ((anchor_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_33_1) & 127;
    acc_2 = (acc_2 + anchor_33_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_23_1 == scale_23_2);
  assert(anchor_33_1 == anchor_33_2);
}

int fn_R000991_9113_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int scale_23 = local_arr[aux % 3];
  acc = (acc + (scale_23 * 2)) & 127;
  int anchor_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_33 = ((anchor_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_33) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st_1 = {0};
  struct MatrixBlock_R000991_9113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int parity_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_74_1 > 33)
  {
    acc_1 = ((acc_1 + (parity_74_1 * 2)) + 5) & 127;
    aux_1 ^= parity_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_74_2 > 33)
  {
    acc_2 = ((acc_2 + (parity_74_2 * 2)) + 5) & 127;
    aux_2 ^= parity_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_74_1)
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

  switch (bound_74_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_37_1 = local_arr_1[aux_1 % 3];
  int checksum_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_37_2 * 2)) & 127;
  int coefficient_94_1 = 0;
  int coefficient_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_94_1 = ((coefficient_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_94_2 = ((coefficient_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_94_1) & 127;
    acc_2 = (acc_2 + coefficient_94_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_74_1 == parity_74_2);
  assert(bound_74_1 == bound_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_37_1 == checksum_37_2);
  assert(coefficient_94_1 == coefficient_94_2);
}

int fn_R000991_9113_2(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int parity_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_74 > 33)
  {
    acc = ((acc + (parity_74 * 2)) + 5) & 127;
    aux ^= parity_74 & 15;
  }
  else
  {
    acc = ((acc - parity_74) + 11) & 127;
    aux += 3;
  }
  int bound_74 = (aux + st.buffer[1]) & 3;
  switch (bound_74)
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

  int local_arr[3] = {4, 9, 15};
  int checksum_37 = local_arr[aux % 3];
  acc = (acc + (checksum_37 * 2)) & 127;
  int coefficient_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_94 = ((coefficient_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_94) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000991_9113_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st_1 = {0};
  struct MatrixBlock_R000991_9113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int offset_72_1 = 0;
  int offset_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_72_1 = ((offset_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_72_2 = ((offset_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_72_1) & 127;
    acc_2 = (acc_2 + offset_72_2) & 127;
  }

  int weight_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_49_1)
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

  switch (weight_49_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_55_1 = local_arr_1[aux_1 % 3];
  int residue_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_72_1 == offset_72_2);
  assert(weight_49_1 == weight_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_55_1 == residue_55_2);
}

int fn_R000991_9113_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int offset_72 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_72 = ((offset_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_72) & 127;
  }

  int weight_49 = (aux + st.buffer[1]) & 3;
  switch (weight_49)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_55 = local_arr[aux % 3];
  acc = (acc + (residue_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st_1 = {0};
  struct MatrixBlock_R000991_9113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int damping_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_41_1) & 63;
  aux_2 = (aux_2 + damping_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_32_1 = local_arr_1[aux_1 % 3];
  int metric_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_32_2 * 2)) & 127;
  int index_reg_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_29_1)
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

  switch (index_reg_29_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_41_1 == damping_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_32_1 == metric_32_2);
  assert(index_reg_29_1 == index_reg_29_2);
}

int fn_R000991_9113_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int damping_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_32 = local_arr[aux % 3];
  acc = (acc + (metric_32 * 2)) & 127;
  int index_reg_29 = (aux + st.buffer[1]) & 3;
  switch (index_reg_29)
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

void fn_R000991_9113_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000991_9113_3 st_1 = {0};
  struct CipherContext_R000991_9113_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int pivot_55_1 = 0;
  int pivot_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_55_1 = ((pivot_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_55_2 = ((pivot_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_55_1) & 127;
    acc_2 = (acc_2 + pivot_55_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_64_1 = local_arr_1[aux_1 % 3];
  int anchor_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_64_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_23_1)
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

  switch (factor_23_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_55_1 == pivot_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_64_1 == anchor_64_2);
  assert(factor_23_1 == factor_23_2);
}

int fn_R000991_9113_5(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000991_9113_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int pivot_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_55 = ((pivot_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_55) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_64 = local_arr[aux % 3];
  acc = (acc + (anchor_64 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_23 = (aux + st.buffer[1]) & 3;
  switch (factor_23)
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

void fn_R000991_9113_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st_1 = {0};
  struct DeviceConfig_R000991_9113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int margin_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_36_1 > 49)
  {
    acc_1 = ((acc_1 + (margin_36_1 * 2)) + 5) & 127;
    aux_1 ^= margin_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_36_2 > 49)
  {
    acc_2 = ((acc_2 + (margin_36_2 * 2)) + 5) & 127;
    aux_2 ^= margin_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_86_1) & 63;
  aux_2 = (aux_2 + threshold_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_36_1 == margin_36_2);
  assert(threshold_86_1 == threshold_86_2);
}

int fn_R000991_9113_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int margin_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_36 > 49)
  {
    acc = ((acc + (margin_36 * 2)) + 5) & 127;
    aux ^= margin_36 & 15;
  }
  else
  {
    acc = ((acc - margin_36) + 11) & 127;
    aux += 3;
  }
  int threshold_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000991_9113_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st_1 = {0};
  struct AudioFrame_R000991_9113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int threshold_27_1 = 0;
  int threshold_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_27_1 = ((threshold_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_27_2 = ((threshold_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_27_1) & 127;
    acc_2 = (acc_2 + threshold_27_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_27_1 == threshold_27_2);
}

int fn_R000991_9113_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int threshold_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_27 = ((threshold_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_27) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000991_9113_3 st_1 = {0};
  struct CipherContext_R000991_9113_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int mask_65_1 = 0;
  int mask_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_65_1 = ((mask_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_65_2 = ((mask_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_65_1) & 127;
    acc_2 = (acc_2 + mask_65_2) & 127;
  }

  int phase_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_93_1 > 37)
  {
    acc_1 = ((acc_1 + (phase_93_1 * 2)) + 5) & 127;
    aux_1 ^= phase_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_93_2 > 37)
  {
    acc_2 = ((acc_2 + (phase_93_2 * 2)) + 5) & 127;
    aux_2 ^= phase_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_91_1)
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

  switch (mask_91_2)
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

  int bound_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_96_1) & 63;
  aux_2 = (aux_2 + bound_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_65_1 == mask_65_2);
  assert(phase_93_1 == phase_93_2);
  assert(mask_91_1 == mask_91_2);
  assert(bound_96_1 == bound_96_2);
}

int fn_R000991_9113_8(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000991_9113_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int mask_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_65 = ((mask_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_65) & 127;
  }

  int phase_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_93 > 37)
  {
    acc = ((acc + (phase_93 * 2)) + 5) & 127;
    aux ^= phase_93 & 15;
  }
  else
  {
    acc = ((acc - phase_93) + 11) & 127;
    aux += 3;
  }
  int mask_91 = (aux + st.buffer[1]) & 3;
  switch (mask_91)
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

  int bound_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000991_9113_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st_1 = {0};
  struct MatrixBlock_R000991_9113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_37_1 = 0;
  int tally_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_37_1 = ((tally_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_37_2 = ((tally_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_37_1) & 127;
    acc_2 = (acc_2 + tally_37_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_37_1 == tally_37_2);
}

int fn_R000991_9113_9(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_37 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_37 = ((tally_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_37) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000991_9113_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st_1 = {0};
  struct AudioFrame_R000991_9113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_39_1 = local_arr_1[aux_1 % 3];
  int vector_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_39_2 * 2)) & 127;
  int window_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_84_1 > 41)
  {
    acc_1 = ((acc_1 + (window_84_1 * 2)) + 5) & 127;
    aux_1 ^= window_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_84_2 > 41)
  {
    acc_2 = ((acc_2 + (window_84_2 * 2)) + 5) & 127;
    aux_2 ^= window_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_25_1)
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

  switch (phase_25_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_39_1 == vector_39_2);
  assert(window_84_1 == window_84_2);
  assert(phase_25_1 == phase_25_2);
}

int fn_R000991_9113_10(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int vector_39 = local_arr[aux % 3];
  acc = (acc + (vector_39 * 2)) & 127;
  int window_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_84 > 41)
  {
    acc = ((acc + (window_84 * 2)) + 5) & 127;
    aux ^= window_84 & 15;
  }
  else
  {
    acc = ((acc - window_84) + 11) & 127;
    aux += 3;
  }
  int phase_25 = (aux + st.buffer[1]) & 3;
  switch (phase_25)
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

void fn_R000991_9113_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st_1 = {0};
  struct DeviceConfig_R000991_9113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_52_1 = local_arr_1[aux_1 % 3];
  int quantum_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_52_2 * 2)) & 127;
  int quotient_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_39_1)
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

  switch (quotient_39_2)
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

  int weight_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_38_1 > 15)
  {
    acc_1 = ((acc_1 + (weight_38_1 * 2)) + 5) & 127;
    aux_1 ^= weight_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_38_2 > 15)
  {
    acc_2 = ((acc_2 + (weight_38_2 * 2)) + 5) & 127;
    aux_2 ^= weight_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_52_1 == quantum_52_2);
  assert(quotient_39_1 == quotient_39_2);
  assert(weight_38_1 == weight_38_2);
}

int fn_R000991_9113_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int quantum_52 = local_arr[aux % 3];
  acc = (acc + (quantum_52 * 2)) & 127;
  int quotient_39 = (aux + st.buffer[1]) & 3;
  switch (quotient_39)
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

  int weight_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_38 > 15)
  {
    acc = ((acc + (weight_38 * 2)) + 5) & 127;
    aux ^= weight_38 & 15;
  }
  else
  {
    acc = ((acc - weight_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000991_9113_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st_1 = {0};
  struct AudioFrame_R000991_9113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int mask_85_1 = 0;
  int mask_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_85_1 = ((mask_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_85_2 = ((mask_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_85_1) & 127;
    acc_2 = (acc_2 + mask_85_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_85_1 == mask_85_2);
}

int fn_R000991_9113_12(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int mask_85 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_85 = ((mask_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_85) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st_1 = {0};
  struct AudioFrame_R000991_9113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quotient_41_1 = 0;
  int quotient_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_41_1 = ((quotient_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_41_2 = ((quotient_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_41_1) & 127;
    acc_2 = (acc_2 + quotient_41_2) & 127;
  }

  int window_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_24_1 > 35)
  {
    acc_1 = ((acc_1 + (window_24_1 * 2)) + 5) & 127;
    aux_1 ^= window_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_24_2 > 35)
  {
    acc_2 = ((acc_2 + (window_24_2 * 2)) + 5) & 127;
    aux_2 ^= window_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_35_1 = local_arr_1[aux_1 % 3];
  int vector_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_41_1 == quotient_41_2);
  assert(window_24_1 == window_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_35_1 == vector_35_2);
}

int fn_R000991_9113_13(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quotient_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_41 = ((quotient_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_41) & 127;
  }

  int window_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_24 > 35)
  {
    acc = ((acc + (window_24 * 2)) + 5) & 127;
    aux ^= window_24 & 15;
  }
  else
  {
    acc = ((acc - window_24) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_35 = local_arr[aux % 3];
  acc = (acc + (vector_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000991_9113_3 st_1 = {0};
  struct CipherContext_R000991_9113_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int sample_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_26_1 > 17)
  {
    acc_1 = ((acc_1 + (sample_26_1 * 2)) + 5) & 127;
    aux_1 ^= sample_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_26_2 > 17)
  {
    acc_2 = ((acc_2 + (sample_26_2 * 2)) + 5) & 127;
    aux_2 ^= sample_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_41_1 = local_arr_1[aux_1 % 3];
  int quotient_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_41_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_26_1 == sample_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_41_1 == quotient_41_2);
}

int fn_R000991_9113_14(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000991_9113_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int sample_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_26 > 17)
  {
    acc = ((acc + (sample_26 * 2)) + 5) & 127;
    aux ^= sample_26 & 15;
  }
  else
  {
    acc = ((acc - sample_26) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_41 = local_arr[aux % 3];
  acc = (acc + (quotient_41 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st_1 = {0};
  struct DeviceConfig_R000991_9113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_42_1 = local_arr_1[aux_1 % 3];
  int quotient_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_42_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_42_1 == quotient_42_2);
}

int fn_R000991_9113_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int quotient_42 = local_arr[aux % 3];
  acc = (acc + (quotient_42 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st_1 = {0};
  struct DeviceConfig_R000991_9113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_17_1 = local_arr_1[aux_1 % 3];
  int scale_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_17_2 * 2)) & 127;
  int cursor_93_1 = 0;
  int cursor_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_93_1 = ((cursor_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_93_2 = ((cursor_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_93_1) & 127;
    acc_2 = (acc_2 + cursor_93_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_83_1)
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

  switch (delta_83_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_17_1 == scale_17_2);
  assert(cursor_93_1 == cursor_93_2);
  assert(delta_83_1 == delta_83_2);
}

int fn_R000991_9113_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int scale_17 = local_arr[aux % 3];
  acc = (acc + (scale_17 * 2)) & 127;
  int cursor_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_93 = ((cursor_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_93) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_83 = (aux + st.buffer[1]) & 3;
  switch (delta_83)
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

void fn_R000991_9113_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000991_9113_3 st_1 = {0};
  struct CipherContext_R000991_9113_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int scale_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_46_1) & 63;
  aux_2 = (aux_2 + scale_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_98_1)
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

  switch (delta_98_2)
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
  int sample_37_1 = local_arr_1[aux_1 % 3];
  int sample_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_37_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_46_1 == scale_46_2);
  assert(delta_98_1 == delta_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_37_1 == sample_37_2);
}

int fn_R000991_9113_17(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000991_9113_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int scale_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_46) & 63;
  acc ^= aux;
  int delta_98 = (aux + st.buffer[1]) & 3;
  switch (delta_98)
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
  int sample_37 = local_arr[aux % 3];
  acc = (acc + (sample_37 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st_1 = {0};
  struct DeviceConfig_R000991_9113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int anchor_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_36_1)
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

  switch (anchor_36_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_56_1 = local_arr_1[aux_1 % 3];
  int margin_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_36_1 == anchor_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_56_1 == margin_56_2);
}

int fn_R000991_9113_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int anchor_36 = (aux + st.buffer[1]) & 3;
  switch (anchor_36)
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

  int local_arr[3] = {4, 9, 15};
  int margin_56 = local_arr[aux % 3];
  acc = (acc + (margin_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st_1 = {0};
  struct MatrixBlock_R000991_9113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int margin_31_1 = 0;
  int margin_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_31_1 = ((margin_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_31_2 = ((margin_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_31_1) & 127;
    acc_2 = (acc_2 + margin_31_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_76_1 = local_arr_1[aux_1 % 3];
  int tally_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_76_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_31_1 == margin_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_76_1 == tally_76_2);
}

int fn_R000991_9113_19(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int margin_31 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_31 = ((margin_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_31) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_76 = local_arr[aux % 3];
  acc = (acc + (tally_76 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st_1 = {0};
  struct MatrixBlock_R000991_9113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int window_87_1 = 0;
  int window_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_87_1 = ((window_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_87_2 = ((window_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_87_1) & 127;
    acc_2 = (acc_2 + window_87_2) & 127;
  }

  int offset_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_23_1 > 24)
  {
    acc_1 = ((acc_1 + (offset_23_1 * 2)) + 5) & 127;
    aux_1 ^= offset_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_23_2 > 24)
  {
    acc_2 = ((acc_2 + (offset_23_2 * 2)) + 5) & 127;
    aux_2 ^= offset_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_71_1 = local_arr_1[aux_1 % 3];
  int factor_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_71_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_87_1 == window_87_2);
  assert(offset_23_1 == offset_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_71_1 == factor_71_2);
}

int fn_R000991_9113_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int window_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_87 = ((window_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_87) & 127;
  }

  int offset_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_23 > 24)
  {
    acc = ((acc + (offset_23 * 2)) + 5) & 127;
    aux ^= offset_23 & 15;
  }
  else
  {
    acc = ((acc - offset_23) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_71 = local_arr[aux % 3];
  acc = (acc + (factor_71 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st_1 = {0};
  struct MatrixBlock_R000991_9113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int threshold_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_42_1 > 23)
  {
    acc_1 = ((acc_1 + (threshold_42_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_42_2 > 23)
  {
    acc_2 = ((acc_2 + (threshold_42_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_27_1)
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

  switch (offset_27_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_42_1 == threshold_42_2);
  assert(offset_27_1 == offset_27_2);
}

int fn_R000991_9113_21(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000991_9113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int threshold_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_42 > 23)
  {
    acc = ((acc + (threshold_42 * 2)) + 5) & 127;
    aux ^= threshold_42 & 15;
  }
  else
  {
    acc = ((acc - threshold_42) + 11) & 127;
    aux += 3;
  }
  int offset_27 = (aux + st.buffer[1]) & 3;
  switch (offset_27)
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

void fn_R000991_9113_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st_1 = {0};
  struct DeviceConfig_R000991_9113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_76_1 = local_arr_1[aux_1 % 3];
  int quantum_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_76_2 * 2)) & 127;
  int residue_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_59_1)
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

  switch (residue_59_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_76_1 == quantum_76_2);
  assert(residue_59_1 == residue_59_2);
}

int fn_R000991_9113_22(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int quantum_76 = local_arr[aux % 3];
  acc = (acc + (quantum_76 * 2)) & 127;
  int residue_59 = (aux + st.buffer[1]) & 3;
  switch (residue_59)
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

void fn_R000991_9113_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st_1 = {0};
  struct DeviceConfig_R000991_9113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int delta_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_55_1 > 17)
  {
    acc_1 = ((acc_1 + (delta_55_1 * 2)) + 5) & 127;
    aux_1 ^= delta_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_55_2 > 17)
  {
    acc_2 = ((acc_2 + (delta_55_2 * 2)) + 5) & 127;
    aux_2 ^= delta_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_84_1)
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

  switch (checksum_84_2)
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

  int mask_12_1 = 0;
  int mask_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_12_1 = ((mask_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_12_2 = ((mask_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_12_1) & 127;
    acc_2 = (acc_2 + mask_12_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_55_1 == delta_55_2);
  assert(checksum_84_1 == checksum_84_2);
  assert(mask_12_1 == mask_12_2);
}

int fn_R000991_9113_23(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000991_9113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int delta_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_55 > 17)
  {
    acc = ((acc + (delta_55 * 2)) + 5) & 127;
    aux ^= delta_55 & 15;
  }
  else
  {
    acc = ((acc - delta_55) + 11) & 127;
    aux += 3;
  }
  int checksum_84 = (aux + st.buffer[1]) & 3;
  switch (checksum_84)
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

  int mask_12 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_12 = ((mask_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_12) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000991_9113_24_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st_1 = {0};
  struct AudioFrame_R000991_9113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int sample_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_55_1) & 63;
  aux_2 = (aux_2 + sample_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_84_1 = 0;
  int metric_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_84_1 = ((metric_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_84_2 = ((metric_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_84_1) & 127;
    acc_2 = (acc_2 + metric_84_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_29_1 = local_arr_1[aux_1 % 3];
  int vector_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_55_1 == sample_55_2);
  assert(metric_84_1 == metric_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_29_1 == vector_29_2);
}

int fn_R000991_9113_24(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int sample_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_55) & 63;
  acc ^= aux;
  int metric_84 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_84 = ((metric_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_84) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int vector_29 = local_arr[aux % 3];
  acc = (acc + (vector_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000991_9113_25_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st_1 = {0};
  struct AudioFrame_R000991_9113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int margin_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_19_1)
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

  switch (margin_19_2)
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

  int factor_55_1 = 0;
  int factor_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_55_1 = ((factor_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_55_2 = ((factor_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_55_1) & 127;
    acc_2 = (acc_2 + factor_55_2) & 127;
  }

  int phase_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_32_1 > 23)
  {
    acc_1 = ((acc_1 + (phase_32_1 * 2)) + 5) & 127;
    aux_1 ^= phase_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_32_2 > 23)
  {
    acc_2 = ((acc_2 + (phase_32_2 * 2)) + 5) & 127;
    aux_2 ^= phase_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_66_1) & 63;
  aux_2 = (aux_2 + vector_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_19_1 == margin_19_2);
  assert(factor_55_1 == factor_55_2);
  assert(phase_32_1 == phase_32_2);
  assert(vector_66_1 == vector_66_2);
}

int fn_R000991_9113_25(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000991_9113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int margin_19 = (aux + st.buffer[1]) & 3;
  switch (margin_19)
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

  int factor_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_55 = ((factor_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_55) & 127;
  }

  int phase_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_32 > 23)
  {
    acc = ((acc + (phase_32 * 2)) + 5) & 127;
    aux ^= phase_32 & 15;
  }
  else
  {
    acc = ((acc - phase_32) + 11) & 127;
    aux += 3;
  }
  int vector_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000991_0_1;
  int sec_r000991_0_2;
  int sec_r000991_1_1;
  int sec_r000991_1_2;
  int sec_r000991_2_1;
  int sec_r000991_2_2;
  int sec_r000991_3_1;
  int sec_r000991_3_2;
  int sec_r000991_4_1;
  int sec_r000991_4_2;
  int sec_r000991_5_1;
  int sec_r000991_5_2;
  int sec_r000991_6_1;
  int sec_r000991_6_2;
  int sec_r000991_7_1;
  int sec_r000991_7_2;
  int sec_r000991_8_1;
  int sec_r000991_8_2;
  int sec_r000991_9_1;
  int sec_r000991_9_2;
  int sec_r000991_10_1;
  int sec_r000991_10_2;
  int sec_r000991_11_1;
  int sec_r000991_11_2;
  int sec_r000991_12_1;
  int sec_r000991_12_2;
  int sec_r000991_13_1;
  int sec_r000991_13_2;
  int sec_r000991_14_1;
  int sec_r000991_14_2;
  int sec_r000991_15_1;
  int sec_r000991_15_2;
  int sec_r000991_16_1;
  int sec_r000991_16_2;
  int sec_r000991_17_1;
  int sec_r000991_17_2;
  int sec_r000991_18_1;
  int sec_r000991_18_2;
  int pub_r000991_0_1;
  int pub_r000991_0_2;
  int pub_r000991_1_1;
  int pub_r000991_1_2;
  int pub_r000991_2_1;
  int pub_r000991_2_2;
  int pub_r000991_3_1;
  int pub_r000991_3_2;
  int pub_r000991_4_1;
  int pub_r000991_4_2;
  int pub_r000991_5_1;
  int pub_r000991_5_2;
  int pub_r000991_6_1;
  int pub_r000991_6_2;
  int pub_r000991_7_1;
  int pub_r000991_7_2;
  int pub_r000991_8_1;
  int pub_r000991_8_2;
  int pub_r000991_9_1;
  int pub_r000991_9_2;
  int pub_r000991_10_1;
  int pub_r000991_10_2;
  int pub_r000991_11_1;
  int pub_r000991_11_2;
  int pub_r000991_12_1;
  int pub_r000991_12_2;
  int pub_r000991_13_1;
  int pub_r000991_13_2;
  int pub_r000991_14_1;
  int pub_r000991_14_2;
  int pub_r000991_15_1;
  int pub_r000991_15_2;
  int pub_r000991_16_1;
  int pub_r000991_16_2;
  int pub_r000991_17_1;
  int pub_r000991_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000991_0_1 >= (-100)) && (pub_r000991_0_1 <= 100));
  __CPROVER_assume((pub_r000991_0_2 >= (-100)) && (pub_r000991_0_2 <= 100));
  __CPROVER_assume((pub_r000991_1_1 >= (-100)) && (pub_r000991_1_1 <= 100));
  __CPROVER_assume((pub_r000991_1_2 >= (-100)) && (pub_r000991_1_2 <= 100));
  __CPROVER_assume((pub_r000991_2_1 >= (-100)) && (pub_r000991_2_1 <= 100));
  __CPROVER_assume((pub_r000991_2_2 >= (-100)) && (pub_r000991_2_2 <= 100));
  __CPROVER_assume((pub_r000991_3_1 >= (-100)) && (pub_r000991_3_1 <= 100));
  __CPROVER_assume((pub_r000991_3_2 >= (-100)) && (pub_r000991_3_2 <= 100));
  __CPROVER_assume((pub_r000991_4_1 >= (-100)) && (pub_r000991_4_1 <= 100));
  __CPROVER_assume((pub_r000991_4_2 >= (-100)) && (pub_r000991_4_2 <= 100));
  __CPROVER_assume((pub_r000991_5_1 >= (-100)) && (pub_r000991_5_1 <= 100));
  __CPROVER_assume((pub_r000991_5_2 >= (-100)) && (pub_r000991_5_2 <= 100));
  __CPROVER_assume((pub_r000991_6_1 >= (-100)) && (pub_r000991_6_1 <= 100));
  __CPROVER_assume((pub_r000991_6_2 >= (-100)) && (pub_r000991_6_2 <= 100));
  __CPROVER_assume((pub_r000991_7_1 >= (-100)) && (pub_r000991_7_1 <= 100));
  __CPROVER_assume((pub_r000991_7_2 >= (-100)) && (pub_r000991_7_2 <= 100));
  __CPROVER_assume((pub_r000991_8_1 >= (-100)) && (pub_r000991_8_1 <= 100));
  __CPROVER_assume((pub_r000991_8_2 >= (-100)) && (pub_r000991_8_2 <= 100));
  __CPROVER_assume((pub_r000991_9_1 >= (-100)) && (pub_r000991_9_1 <= 100));
  __CPROVER_assume((pub_r000991_9_2 >= (-100)) && (pub_r000991_9_2 <= 100));
  __CPROVER_assume((pub_r000991_10_1 >= (-100)) && (pub_r000991_10_1 <= 100));
  __CPROVER_assume((pub_r000991_10_2 >= (-100)) && (pub_r000991_10_2 <= 100));
  __CPROVER_assume((pub_r000991_11_1 >= (-100)) && (pub_r000991_11_1 <= 100));
  __CPROVER_assume((pub_r000991_11_2 >= (-100)) && (pub_r000991_11_2 <= 100));
  __CPROVER_assume((pub_r000991_12_1 >= (-100)) && (pub_r000991_12_1 <= 100));
  __CPROVER_assume((pub_r000991_12_2 >= (-100)) && (pub_r000991_12_2 <= 100));
  __CPROVER_assume((pub_r000991_13_1 >= (-100)) && (pub_r000991_13_1 <= 100));
  __CPROVER_assume((pub_r000991_13_2 >= (-100)) && (pub_r000991_13_2 <= 100));
  __CPROVER_assume((pub_r000991_14_1 >= (-100)) && (pub_r000991_14_1 <= 100));
  __CPROVER_assume((pub_r000991_14_2 >= (-100)) && (pub_r000991_14_2 <= 100));
  __CPROVER_assume((pub_r000991_15_1 >= (-100)) && (pub_r000991_15_1 <= 100));
  __CPROVER_assume((pub_r000991_15_2 >= (-100)) && (pub_r000991_15_2 <= 100));
  __CPROVER_assume((pub_r000991_16_1 >= (-100)) && (pub_r000991_16_1 <= 100));
  __CPROVER_assume((pub_r000991_16_2 >= (-100)) && (pub_r000991_16_2 <= 100));
  __CPROVER_assume((pub_r000991_17_1 >= (-100)) && (pub_r000991_17_1 <= 100));
  __CPROVER_assume((pub_r000991_17_2 >= (-100)) && (pub_r000991_17_2 <= 100));
  __CPROVER_assume((sec_r000991_0_1 >= 0) && (sec_r000991_0_1 <= 255));
  __CPROVER_assume((sec_r000991_0_2 >= 0) && (sec_r000991_0_2 <= 255));
  __CPROVER_assume((sec_r000991_1_1 >= 0) && (sec_r000991_1_1 <= 255));
  __CPROVER_assume((sec_r000991_1_2 >= 0) && (sec_r000991_1_2 <= 255));
  __CPROVER_assume((sec_r000991_2_1 >= 0) && (sec_r000991_2_1 <= 255));
  __CPROVER_assume((sec_r000991_2_2 >= 0) && (sec_r000991_2_2 <= 255));
  __CPROVER_assume((sec_r000991_3_1 >= 0) && (sec_r000991_3_1 <= 255));
  __CPROVER_assume((sec_r000991_3_2 >= 0) && (sec_r000991_3_2 <= 255));
  __CPROVER_assume((sec_r000991_4_1 >= 0) && (sec_r000991_4_1 <= 255));
  __CPROVER_assume((sec_r000991_4_2 >= 0) && (sec_r000991_4_2 <= 255));
  __CPROVER_assume((sec_r000991_5_1 >= 0) && (sec_r000991_5_1 <= 255));
  __CPROVER_assume((sec_r000991_5_2 >= 0) && (sec_r000991_5_2 <= 255));
  __CPROVER_assume((sec_r000991_6_1 >= 0) && (sec_r000991_6_1 <= 255));
  __CPROVER_assume((sec_r000991_6_2 >= 0) && (sec_r000991_6_2 <= 255));
  __CPROVER_assume((sec_r000991_7_1 >= 0) && (sec_r000991_7_1 <= 255));
  __CPROVER_assume((sec_r000991_7_2 >= 0) && (sec_r000991_7_2 <= 255));
  __CPROVER_assume((sec_r000991_8_1 >= 0) && (sec_r000991_8_1 <= 255));
  __CPROVER_assume((sec_r000991_8_2 >= 0) && (sec_r000991_8_2 <= 255));
  __CPROVER_assume((sec_r000991_9_1 >= 0) && (sec_r000991_9_1 <= 255));
  __CPROVER_assume((sec_r000991_9_2 >= 0) && (sec_r000991_9_2 <= 255));
  __CPROVER_assume((sec_r000991_10_1 >= 0) && (sec_r000991_10_1 <= 255));
  __CPROVER_assume((sec_r000991_10_2 >= 0) && (sec_r000991_10_2 <= 255));
  __CPROVER_assume((sec_r000991_11_1 >= 0) && (sec_r000991_11_1 <= 255));
  __CPROVER_assume((sec_r000991_11_2 >= 0) && (sec_r000991_11_2 <= 255));
  __CPROVER_assume((sec_r000991_12_1 >= 0) && (sec_r000991_12_1 <= 255));
  __CPROVER_assume((sec_r000991_12_2 >= 0) && (sec_r000991_12_2 <= 255));
  __CPROVER_assume((sec_r000991_13_1 >= 0) && (sec_r000991_13_1 <= 255));
  __CPROVER_assume((sec_r000991_13_2 >= 0) && (sec_r000991_13_2 <= 255));
  __CPROVER_assume((sec_r000991_14_1 >= 0) && (sec_r000991_14_1 <= 255));
  __CPROVER_assume((sec_r000991_14_2 >= 0) && (sec_r000991_14_2 <= 255));
  __CPROVER_assume((sec_r000991_15_1 >= 0) && (sec_r000991_15_1 <= 255));
  __CPROVER_assume((sec_r000991_15_2 >= 0) && (sec_r000991_15_2 <= 255));
  __CPROVER_assume((sec_r000991_16_1 >= 0) && (sec_r000991_16_1 <= 255));
  __CPROVER_assume((sec_r000991_16_2 >= 0) && (sec_r000991_16_2 <= 255));
  __CPROVER_assume((sec_r000991_17_1 >= 0) && (sec_r000991_17_1 <= 255));
  __CPROVER_assume((sec_r000991_17_2 >= 0) && (sec_r000991_17_2 <= 255));
  __CPROVER_assume((sec_r000991_18_1 >= 0) && (sec_r000991_18_1 <= 255));
  __CPROVER_assume((sec_r000991_18_2 >= 0) && (sec_r000991_18_2 <= 255));
  struct MatrixBlock_R000991_9113_0 st_var_0_1 = {0};
  struct MatrixBlock_R000991_9113_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000991_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000991_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000991_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000991_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000991_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000991_0_2 + 7) & 15;
  struct DeviceConfig_R000991_9113_1 st_var_1_1 = {0};
  struct DeviceConfig_R000991_9113_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000991_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000991_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000991_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000991_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000991_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000991_0_2 + 9) & 15;
  struct AudioFrame_R000991_9113_2 st_var_2_1 = {0};
  struct AudioFrame_R000991_9113_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000991_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000991_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000991_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000991_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000991_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000991_0_2 + 11) & 15;
  struct CipherContext_R000991_9113_3 st_var_3_1 = {0};
  struct CipherContext_R000991_9113_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000991_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000991_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000991_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000991_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000991_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000991_0_2 + 13) & 15;
  union TelemetryField_R000991_9113_0 u_var_1;
  union TelemetryField_R000991_9113_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 1) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 1) & 15;
  int stage_v_0_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_0_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= stage_v_0_1;
  chk_sum_2 ^= stage_v_0_2;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 15) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 16) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
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
  int stage_v_23_1 = (st_var_3_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_3_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((st_var_3_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_3_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 47)
    {
      chk_sum_1 ^= stage_v_27_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_27_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 47)
    {
      chk_sum_2 ^= stage_v_27_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (st_var_1_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_1_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (st_var_3_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_3_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 33) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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

  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  int stage_v_39_1 = table_1[3];
  int stage_v_39_2 = table_2[3];
  table_1[3] = (table_1[0] + 79) & 63;
  table_2[3] = (table_2[0] + 79) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 53)
    {
      chk_sum_1 ^= stage_v_40_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_40_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 53)
    {
      chk_sum_2 ^= stage_v_40_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (st_var_2_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_2_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
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

  switch (stage_v_46_2)
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

  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 29)
    {
      chk_sum_1 ^= stage_v_50_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_50_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 29)
    {
      chk_sum_2 ^= stage_v_50_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_51_1 = (st_var_3_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_3_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 54) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 54) & 15;
  int stage_v_53_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_53_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= stage_v_53_1;
  chk_sum_2 ^= stage_v_53_2;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 55) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 55) & 15;
  int stage_v_54_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_54_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= stage_v_54_1;
  chk_sum_2 ^= stage_v_54_2;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 56) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  int stage_v_56_1 = table_1[0];
  int stage_v_56_2 = table_2[0];
  table_1[0] = (table_1[1] + 113) & 63;
  table_2[0] = (table_2[1] + 113) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_57_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_58_1 = ((st_var_2_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_2_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 36)
    {
      chk_sum_1 ^= stage_v_58_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_58_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 36)
    {
      chk_sum_2 ^= stage_v_58_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = table_1[0];
  int stage_v_60_2 = table_2[0];
  table_1[0] = (table_1[1] + 121) & 63;
  table_2[0] = (table_2[1] + 121) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 63) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 63) & 15;
  int stage_v_62_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_62_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= stage_v_62_1;
  chk_sum_2 ^= stage_v_62_2;
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
  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (st_var_3_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_3_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  int stage_v_68_1 = table_1[0];
  int stage_v_68_2 = table_2[0];
  table_1[0] = (table_1[1] + 137) & 63;
  table_2[0] = (table_2[1] + 137) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((st_var_3_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_3_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 41)
    {
      chk_sum_1 ^= stage_v_71_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_71_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 41)
    {
      chk_sum_2 ^= stage_v_71_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_72_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (77 & 31);
  int stage_v_72_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (77 & 31);
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= (stage_v_72_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_72_2 << 1) & 127;
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (st_var_2_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_2_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
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

  switch (stage_v_74_2)
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

  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (st_var_0_1.buffer[0] ^ 79) & 3;
  int stage_v_76_2 = (st_var_0_2.buffer[0] ^ 79) & 3;
  switch (stage_v_76_1)
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

  switch (stage_v_76_2)
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

  int stage_v_77_1 = (st_var_1_1.buffer[0] ^ 80) & 3;
  int stage_v_77_2 = (st_var_1_2.buffer[0] ^ 80) & 3;
  switch (stage_v_77_1)
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

  switch (stage_v_77_2)
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

  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 79) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 79) & 15;
  int stage_v_78_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_78_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= stage_v_78_1;
  chk_sum_2 ^= stage_v_78_2;
  int stage_v_79_1 = (st_var_3_1.buffer[0] ^ 82) & 3;
  int stage_v_79_2 = (st_var_3_2.buffer[0] ^ 82) & 3;
  switch (stage_v_79_1)
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

  switch (stage_v_79_2)
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

  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 82) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 82) & 15;
  int stage_v_81_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_81_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= stage_v_81_1;
  chk_sum_2 ^= stage_v_81_2;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_83_1 = ((stage_v_83_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_86_1 = ((stage_v_86_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_86_2 = ((stage_v_86_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = table_1[3];
  int stage_v_87_2 = table_2[3];
  table_1[3] = (table_1[0] + 175) & 63;
  table_2[3] = (table_2[0] + 175) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((st_var_0_1.buffer[1] * 2) + 271) & 63;
  int stage_v_88_2 = ((st_var_0_2.buffer[1] * 2) + 271) & 63;
  if (stage_v_88_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_88_1) - 5) & 255;
    if (stage_v_88_1 > 39)
    {
      chk_sum_1 ^= stage_v_88_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_88_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_88_2) - 5) & 255;
    if (stage_v_88_2 > 39)
    {
      chk_sum_2 ^= stage_v_88_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_89_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_89_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_89_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_89_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_90_1 = ((st_var_2_1.buffer[0] * 2) + 277) & 63;
  int stage_v_90_2 = ((st_var_2_2.buffer[0] * 2) + 277) & 63;
  if (stage_v_90_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_90_1) - 5) & 255;
    if (stage_v_90_1 > 48)
    {
      chk_sum_1 ^= stage_v_90_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_90_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_90_2) - 5) & 255;
    if (stage_v_90_2 > 48)
    {
      chk_sum_2 ^= stage_v_90_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_91_1 = ((st_var_3_1.buffer[1] * 2) + 280) & 63;
  int stage_v_91_2 = ((st_var_3_2.buffer[1] * 2) + 280) & 63;
  if (stage_v_91_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_91_1) - 5) & 255;
    if (stage_v_91_1 > 53)
    {
      chk_sum_1 ^= stage_v_91_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_91_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_91_2) - 5) & 255;
    if (stage_v_91_2 > 53)
    {
      chk_sum_2 ^= stage_v_91_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_92_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_92_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_92_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_92_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_93_1 = ((stage_v_93_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_93_2 = ((stage_v_93_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_94_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_95_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (100 & 31);
  int stage_v_95_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (100 & 31);
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= (stage_v_95_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_95_2 << 1) & 127;
  int stage_v_96_1 = table_1[0];
  int stage_v_96_2 = table_2[0];
  table_1[0] = (table_1[1] + 193) & 63;
  table_2[0] = (table_2[1] + 193) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (102 & 31);
  int stage_v_97_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (102 & 31);
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= (stage_v_97_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_97_2 << 1) & 127;
  int stage_v_98_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (103 & 31);
  int stage_v_98_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (103 & 31);
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  chk_sum_1 ^= (stage_v_98_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_98_2 << 1) & 127;
  int stage_v_99_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (104 & 31);
  int stage_v_99_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (104 & 31);
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  chk_sum_1 ^= (stage_v_99_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_99_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 101) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 101) & 15;
  int stage_v_100_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_100_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= stage_v_100_1;
  chk_sum_2 ^= stage_v_100_2;
  int stage_v_101_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (106 & 31);
  int stage_v_101_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (106 & 31);
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= (stage_v_101_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_101_2 << 1) & 127;
  int stage_v_102_1 = (st_var_2_1.buffer[0] ^ 105) & 3;
  int stage_v_102_2 = (st_var_2_2.buffer[0] ^ 105) & 3;
  switch (stage_v_102_1)
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

  switch (stage_v_102_2)
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

  int stage_v_103_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (108 & 31);
  int stage_v_103_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (108 & 31);
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= (stage_v_103_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_103_2 << 1) & 127;
  int stage_v_104_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (109 & 31);
  int stage_v_104_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (109 & 31);
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  chk_sum_1 ^= (stage_v_104_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_104_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 106) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 106) & 15;
  int stage_v_105_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_105_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= stage_v_105_1;
  chk_sum_2 ^= stage_v_105_2;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_106_1 = ((stage_v_106_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_106_2 = ((stage_v_106_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = table_1[3];
  int stage_v_107_2 = table_2[3];
  table_1[3] = (table_1[0] + 215) & 63;
  table_2[3] = (table_2[0] + 215) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (st_var_0_1.buffer[0] ^ 111) & 3;
  int stage_v_108_2 = (st_var_0_2.buffer[0] ^ 111) & 3;
  switch (stage_v_108_1)
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

  switch (stage_v_108_2)
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

  int stage_v_109_1 = (st_var_1_1.buffer[0] ^ 112) & 3;
  int stage_v_109_2 = (st_var_1_2.buffer[0] ^ 112) & 3;
  switch (stage_v_109_1)
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

  switch (stage_v_109_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 111) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 111) & 15;
  int stage_v_110_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_110_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  chk_sum_1 ^= stage_v_110_1;
  chk_sum_2 ^= stage_v_110_2;
  int stage_v_111_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (116 & 31);
  int stage_v_111_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (116 & 31);
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  chk_sum_1 ^= (stage_v_111_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_111_2 << 1) & 127;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (118 & 31);
  int stage_v_113_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (118 & 31);
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  chk_sum_1 ^= (stage_v_113_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_113_2 << 1) & 127;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_115_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_115_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_115_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_116_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (121 & 31);
  int stage_v_116_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (121 & 31);
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= (stage_v_116_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_116_2 << 1) & 127;
  int stage_v_117_1 = (st_var_1_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_1_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  int stage_v_118_1 = ((st_var_2_1.buffer[1] * 2) + 361) & 63;
  int stage_v_118_2 = ((st_var_2_2.buffer[1] * 2) + 361) & 63;
  if (stage_v_118_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_118_1) - 5) & 255;
    if (stage_v_118_1 > 31)
    {
      chk_sum_1 ^= stage_v_118_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_118_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_118_2) - 5) & 255;
    if (stage_v_118_2 > 31)
    {
      chk_sum_2 ^= stage_v_118_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_119_1 = ((st_var_3_1.buffer[2] * 2) + 364) & 63;
  int stage_v_119_2 = ((st_var_3_2.buffer[2] * 2) + 364) & 63;
  if (stage_v_119_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_119_1) - 5) & 255;
    if (stage_v_119_1 > 28)
    {
      chk_sum_1 ^= stage_v_119_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_119_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_119_2) - 5) & 255;
    if (stage_v_119_2 > 28)
    {
      chk_sum_2 ^= stage_v_119_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_120_1 = (st_var_0_1.buffer[0] ^ 123) & 3;
  int stage_v_120_2 = (st_var_0_2.buffer[0] ^ 123) & 3;
  switch (stage_v_120_1)
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

  switch (stage_v_120_2)
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

  int stage_v_121_1 = table_1[1];
  int stage_v_121_2 = table_2[1];
  table_1[1] = (table_1[2] + 243) & 63;
  table_2[1] = (table_2[2] + 243) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = table_1[2];
  int stage_v_122_2 = table_2[2];
  table_1[2] = (table_1[3] + 245) & 63;
  table_2[2] = (table_2[3] + 245) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_123_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_123_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_123_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_124_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (129 & 31);
  int stage_v_124_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (129 & 31);
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= (stage_v_124_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_124_2 << 1) & 127;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_126_1 = ((stage_v_126_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_126_2 = ((stage_v_126_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_127_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_128_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_128_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (135 & 31);
  int stage_v_130_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (135 & 31);
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= (stage_v_130_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_130_2 << 1) & 127;
  int stage_v_131_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (136 & 31);
  int stage_v_131_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (136 & 31);
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  chk_sum_1 ^= (stage_v_131_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_131_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 133) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 133) & 15;
  int stage_v_132_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_132_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  chk_sum_1 ^= stage_v_132_1;
  chk_sum_2 ^= stage_v_132_2;
  int stage_v_133_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_133_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_134_1 = ((stage_v_134_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_134_2 = ((stage_v_134_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 136) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 136) & 15;
  int stage_v_135_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_135_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= stage_v_135_1;
  chk_sum_2 ^= stage_v_135_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 137) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 137) & 15;
  int stage_v_136_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_136_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= stage_v_136_1;
  chk_sum_2 ^= stage_v_136_2;
  int stage_v_137_1 = ((st_var_1_1.buffer[2] * 2) + 418) & 63;
  int stage_v_137_2 = ((st_var_1_2.buffer[2] * 2) + 418) & 63;
  if (stage_v_137_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_137_1) - 5) & 255;
    if (stage_v_137_1 > 30)
    {
      chk_sum_1 ^= stage_v_137_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_137_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_137_2) - 5) & 255;
    if (stage_v_137_2 > 30)
    {
      chk_sum_2 ^= stage_v_137_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (st_var_3_1.buffer[0] ^ 142) & 3;
  int stage_v_139_2 = (st_var_3_2.buffer[0] ^ 142) & 3;
  switch (stage_v_139_1)
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

  switch (stage_v_139_2)
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

  int stage_v_140_1 = ((st_var_0_1.buffer[2] * 2) + 427) & 63;
  int stage_v_140_2 = ((st_var_0_2.buffer[2] * 2) + 427) & 63;
  if (stage_v_140_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_140_1) - 5) & 255;
    if (stage_v_140_1 > 40)
    {
      chk_sum_1 ^= stage_v_140_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_140_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_140_2) - 5) & 255;
    if (stage_v_140_2 > 40)
    {
      chk_sum_2 ^= stage_v_140_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_141_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_141_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_141_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_141_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_142_1 = table_1[2];
  int stage_v_142_2 = table_2[2];
  table_1[2] = (table_1[3] + 285) & 63;
  table_2[2] = (table_2[3] + 285) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((st_var_3_1.buffer[2] * 2) + 436) & 63;
  int stage_v_143_2 = ((st_var_3_2.buffer[2] * 2) + 436) & 63;
  if (stage_v_143_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_143_1) - 5) & 255;
    if (stage_v_143_1 > 40)
    {
      chk_sum_1 ^= stage_v_143_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_143_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_143_2) - 5) & 255;
    if (stage_v_143_2 > 40)
    {
      chk_sum_2 ^= stage_v_143_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_144_1 = (st_var_0_1.buffer[0] ^ 147) & 3;
  int stage_v_144_2 = (st_var_0_2.buffer[0] ^ 147) & 3;
  switch (stage_v_144_1)
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

  switch (stage_v_144_2)
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

  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (151 & 31);
  int stage_v_146_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (151 & 31);
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= (stage_v_146_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_146_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 148) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 148) & 15;
  int stage_v_147_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_147_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= stage_v_147_1;
  chk_sum_2 ^= stage_v_147_2;
  int stage_v_148_1 = (st_var_0_1.buffer[0] ^ 151) & 3;
  int stage_v_148_2 = (st_var_0_2.buffer[0] ^ 151) & 3;
  switch (stage_v_148_1)
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

  switch (stage_v_148_2)
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

  int stage_v_149_1 = ((st_var_1_1.buffer[2] * 2) + 454) & 63;
  int stage_v_149_2 = ((st_var_1_2.buffer[2] * 2) + 454) & 63;
  if (stage_v_149_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_149_1) - 5) & 255;
    if (stage_v_149_1 > 28)
    {
      chk_sum_1 ^= stage_v_149_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_149_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_149_2) - 5) & 255;
    if (stage_v_149_2 > 28)
    {
      chk_sum_2 ^= stage_v_149_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_150_1 = ((st_var_2_1.buffer[0] * 2) + 457) & 63;
  int stage_v_150_2 = ((st_var_2_2.buffer[0] * 2) + 457) & 63;
  if (stage_v_150_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_150_1) - 5) & 255;
    if (stage_v_150_1 > 33)
    {
      chk_sum_1 ^= stage_v_150_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_150_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_150_2) - 5) & 255;
    if (stage_v_150_2 > 33)
    {
      chk_sum_2 ^= stage_v_150_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_151_1 = table_1[3];
  int stage_v_151_2 = table_2[3];
  table_1[3] = (table_1[0] + 303) & 63;
  table_2[3] = (table_2[0] + 303) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 153) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 153) & 15;
  int stage_v_152_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_152_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  chk_sum_1 ^= stage_v_152_1;
  chk_sum_2 ^= stage_v_152_2;
  int stage_v_153_1 = (st_var_1_1.buffer[0] ^ 156) & 3;
  int stage_v_153_2 = (st_var_1_2.buffer[0] ^ 156) & 3;
  switch (stage_v_153_1)
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

  switch (stage_v_153_2)
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

  int stage_v_154_1 = table_1[2];
  int stage_v_154_2 = table_2[2];
  table_1[2] = (table_1[3] + 309) & 63;
  table_2[2] = (table_2[3] + 309) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 157) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 157) & 15;
  int stage_v_156_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_156_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= stage_v_156_1;
  chk_sum_2 ^= stage_v_156_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 158) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 158) & 15;
  int stage_v_157_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_157_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= stage_v_157_1;
  chk_sum_2 ^= stage_v_157_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 159) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 159) & 15;
  int stage_v_158_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_158_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= stage_v_158_1;
  chk_sum_2 ^= stage_v_158_2;
  int stage_v_159_1 = table_1[3];
  int stage_v_159_2 = table_2[3];
  table_1[3] = (table_1[0] + 319) & 63;
  table_2[3] = (table_2[0] + 319) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_161_1 = ((stage_v_161_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_161_2 = ((stage_v_161_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (st_var_2_1.buffer[0] ^ 165) & 3;
  int stage_v_162_2 = (st_var_2_2.buffer[0] ^ 165) & 3;
  switch (stage_v_162_1)
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

  switch (stage_v_162_2)
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

  int stage_v_163_1 = ((st_var_3_1.buffer[1] * 2) + 496) & 63;
  int stage_v_163_2 = ((st_var_3_2.buffer[1] * 2) + 496) & 63;
  if (stage_v_163_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_163_1) - 5) & 255;
    if (stage_v_163_1 > 32)
    {
      chk_sum_1 ^= stage_v_163_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_163_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_163_2) - 5) & 255;
    if (stage_v_163_2 > 32)
    {
      chk_sum_2 ^= stage_v_163_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_164_1 = table_1[0];
  int stage_v_164_2 = table_2[0];
  table_1[0] = (table_1[1] + 329) & 63;
  table_2[0] = (table_2[1] + 329) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = table_1[1];
  int stage_v_165_2 = table_2[1];
  table_1[1] = (table_1[2] + 331) & 63;
  table_2[1] = (table_2[2] + 331) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (171 & 31);
  int stage_v_166_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (171 & 31);
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  chk_sum_1 ^= (stage_v_166_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_166_2 << 1) & 127;
  int stage_v_167_1 = table_1[3];
  int stage_v_167_2 = table_2[3];
  table_1[3] = (table_1[0] + 335) & 63;
  table_2[3] = (table_2[0] + 335) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_168_1 = ((stage_v_168_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_168_2 = ((stage_v_168_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((st_var_1_1.buffer[1] * 2) + 514) & 63;
  int stage_v_169_2 = ((st_var_1_2.buffer[1] * 2) + 514) & 63;
  if (stage_v_169_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_169_1) - 5) & 255;
    if (stage_v_169_1 > 47)
    {
      chk_sum_1 ^= stage_v_169_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_169_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_169_2) - 5) & 255;
    if (stage_v_169_2 > 47)
    {
      chk_sum_2 ^= stage_v_169_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_170_1 = (st_var_2_1.buffer[0] ^ 173) & 3;
  int stage_v_170_2 = (st_var_2_2.buffer[0] ^ 173) & 3;
  switch (stage_v_170_1)
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

  switch (stage_v_170_2)
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

  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 172) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 172) & 15;
  int stage_v_171_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_171_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  chk_sum_1 ^= stage_v_171_1;
  chk_sum_2 ^= stage_v_171_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 173) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 173) & 15;
  int stage_v_172_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_172_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  chk_sum_1 ^= stage_v_172_1;
  chk_sum_2 ^= stage_v_172_2;
  int stage_v_173_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_173_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_174_1 = ((st_var_2_1.buffer[0] * 2) + 529) & 63;
  int stage_v_174_2 = ((st_var_2_2.buffer[0] * 2) + 529) & 63;
  if (stage_v_174_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_174_1) - 5) & 255;
    if (stage_v_174_1 > 27)
    {
      chk_sum_1 ^= stage_v_174_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_174_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_174_2) - 5) & 255;
    if (stage_v_174_2 > 27)
    {
      chk_sum_2 ^= stage_v_174_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int m_var_1 = (sec_r000991_13_1 ^ 0x55) & 63;
  int m_var_2 = (sec_r000991_13_2 ^ 0x55) & 63;
  if (m_var_1 > 27)
  {
    out_sink_1 += ((m_var_1 * 2) + pub_r000991_5_1) & 127;
  }
  else
  {
    out_sink_1 -= (m_var_1 + 12) & 31;
  }
  if (m_var_2 > 27)
  {
    out_sink_2 += ((m_var_2 * 2) + pub_r000991_5_2) & 127;
  }
  else
  {
    out_sink_2 -= (m_var_2 + 12) & 31;
  }
  out_sink_1 ^= sec_r000991_7_1 & 15;
  out_sink_2 ^= sec_r000991_7_2 & 15;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000991_1_1 != sec_r000991_1_2);
  __CPROVER_assume(pub_r000991_3_1 == pub_r000991_3_2);
  __CPROVER_assume(sec_r000991_12_1 != sec_r000991_12_2);
  __CPROVER_assume(pub_r000991_1_1 == pub_r000991_1_2);
  __CPROVER_assume(sec_r000991_9_1 != sec_r000991_9_2);
  __CPROVER_assume(sec_r000991_13_1 != sec_r000991_13_2);
  __CPROVER_assume(sec_r000991_2_1 != sec_r000991_2_2);
  __CPROVER_assume(sec_r000991_14_1 != sec_r000991_14_2);
  __CPROVER_assume(pub_r000991_12_1 == pub_r000991_12_2);
  __CPROVER_assume(pub_r000991_6_1 == pub_r000991_6_2);
  __CPROVER_assume(pub_r000991_11_1 == pub_r000991_11_2);
  __CPROVER_assume(pub_r000991_2_1 == pub_r000991_2_2);
  __CPROVER_assume(pub_r000991_15_1 == pub_r000991_15_2);
  __CPROVER_assume(pub_r000991_9_1 == pub_r000991_9_2);
  __CPROVER_assume(pub_r000991_16_1 == pub_r000991_16_2);
  __CPROVER_assume(pub_r000991_4_1 == pub_r000991_4_2);
  __CPROVER_assume(sec_r000991_11_1 != sec_r000991_11_2);
  __CPROVER_assume(sec_r000991_17_1 != sec_r000991_17_2);
  __CPROVER_assume(sec_r000991_7_1 != sec_r000991_7_2);
  __CPROVER_assume(sec_r000991_6_1 != sec_r000991_6_2);
  __CPROVER_assume(sec_r000991_5_1 != sec_r000991_5_2);
  __CPROVER_assume(pub_r000991_17_1 == pub_r000991_17_2);
  __CPROVER_assume(pub_r000991_10_1 == pub_r000991_10_2);
  __CPROVER_assume(sec_r000991_10_1 != sec_r000991_10_2);
  __CPROVER_assume(pub_r000991_8_1 == pub_r000991_8_2);
  __CPROVER_assume(pub_r000991_7_1 == pub_r000991_7_2);
  __CPROVER_assume(pub_r000991_14_1 == pub_r000991_14_2);
  __CPROVER_assume(pub_r000991_13_1 == pub_r000991_13_2);
  __CPROVER_assume(sec_r000991_0_1 != sec_r000991_0_2);
  __CPROVER_assume(sec_r000991_18_1 != sec_r000991_18_2);
  __CPROVER_assume(sec_r000991_8_1 != sec_r000991_8_2);
  __CPROVER_assume(sec_r000991_16_1 != sec_r000991_16_2);
  __CPROVER_assume(sec_r000991_3_1 != sec_r000991_3_2);
  __CPROVER_assume(sec_r000991_15_1 != sec_r000991_15_2);
  __CPROVER_assume(pub_r000991_5_1 == pub_r000991_5_2);
  __CPROVER_assume(pub_r000991_0_1 == pub_r000991_0_2);
  __CPROVER_assume(sec_r000991_4_1 != sec_r000991_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.channels == st_var_2_2.channels);
  assert(st_var_2_1.peak == st_var_2_2.peak);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.rms == st_var_2_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.counter == st_var_3_2.counter);
  assert(st_var_3_1.nonce == st_var_3_2.nonce);
  assert(st_var_3_1.round_key == st_var_3_2.round_key);
  assert(st_var_3_1.iv == st_var_3_2.iv);
  assert(st_var_3_1.tag == st_var_3_2.tag);
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
  assert(m_var_1 == m_var_2);
}


