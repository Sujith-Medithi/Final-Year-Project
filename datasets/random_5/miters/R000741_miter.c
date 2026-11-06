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
struct DeviceConfig_R000741_4113_0
{
  unsigned char baud_rate;
  int port;
  int stop_bits;
  unsigned char timeout;
  int buffer[3];
};
struct Vector3D_R000741_4113_1
{
  short coord_x;
  unsigned char coord_z;
  int pitch;
  short coord_y;
  int buffer[3];
};
struct CipherContext_R000741_4113_2
{
  unsigned char nonce;
  int tag;
  int iv;
  int buffer[3];
};
union TelemetryField_R000741_4113_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000741_4113_1
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
void fn_R000741_4113_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st_1 = {0};
  struct CipherContext_R000741_4113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_19_1 = local_arr_1[aux_1 % 3];
  int coefficient_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_19_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_93_1)
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

  switch (factor_93_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_19_1 == coefficient_19_2);
  assert(factor_93_1 == factor_93_2);
}

int fn_R000741_4113_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int coefficient_19 = local_arr[aux % 3];
  acc = (acc + (coefficient_19 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_93 = (aux + st.buffer[1]) & 3;
  switch (factor_93)
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

void fn_R000741_4113_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st_1 = {0};
  struct Vector3D_R000741_4113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int threshold_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_14_1 > 48)
  {
    acc_1 = ((acc_1 + (threshold_14_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_14_2 > 48)
  {
    acc_2 = ((acc_2 + (threshold_14_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_14_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_83_1) & 63;
  aux_2 = (aux_2 + pivot_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_32_1)
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

  switch (window_32_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_14_1 == threshold_14_2);
  assert(pivot_83_1 == pivot_83_2);
  assert(window_32_1 == window_32_2);
}

int fn_R000741_4113_1(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int threshold_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_14 > 48)
  {
    acc = ((acc + (threshold_14 * 2)) + 5) & 127;
    aux ^= threshold_14 & 15;
  }
  else
  {
    acc = ((acc - threshold_14) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_83) & 63;
  acc ^= aux;
  int window_32 = (aux + st.buffer[1]) & 3;
  switch (window_32)
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

void fn_R000741_4113_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st_1 = {0};
  struct CipherContext_R000741_4113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_35_1)
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

  switch (sample_35_2)
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
  int threshold_30_1 = local_arr_1[aux_1 % 3];
  int threshold_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_30_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_35_1 == sample_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_30_1 == threshold_30_2);
}

int fn_R000741_4113_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_35 = (aux + st.buffer[1]) & 3;
  switch (sample_35)
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
  int threshold_30 = local_arr[aux % 3];
  acc = (acc + (threshold_30 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000741_4113_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st_1 = {0};
  struct Vector3D_R000741_4113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int residue_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_12_1 > 24)
  {
    acc_1 = ((acc_1 + (residue_12_1 * 2)) + 5) & 127;
    aux_1 ^= residue_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_12_2 > 24)
  {
    acc_2 = ((acc_2 + (residue_12_2 * 2)) + 5) & 127;
    aux_2 ^= residue_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_30_1 = local_arr_1[aux_1 % 3];
  int offset_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_30_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_12_1 == residue_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_30_1 == offset_30_2);
}

int fn_R000741_4113_3(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int residue_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_12 > 24)
  {
    acc = ((acc + (residue_12 * 2)) + 5) & 127;
    aux ^= residue_12 & 15;
  }
  else
  {
    acc = ((acc - residue_12) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_30 = local_arr[aux % 3];
  acc = (acc + (offset_30 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000741_4113_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st_1 = {0};
  struct Vector3D_R000741_4113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int parity_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_88_1)
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

  switch (parity_88_2)
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
  int coefficient_81_1 = local_arr_1[aux_1 % 3];
  int coefficient_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_81_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_88_1 == parity_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_81_1 == coefficient_81_2);
}

int fn_R000741_4113_4(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int parity_88 = (aux + st.buffer[1]) & 3;
  switch (parity_88)
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
  int coefficient_81 = local_arr[aux % 3];
  acc = (acc + (coefficient_81 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000741_4113_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st_1 = {0};
  struct Vector3D_R000741_4113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_10_1 = local_arr_1[aux_1 % 3];
  int index_reg_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_10_2 * 2)) & 127;
  int segment_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_29_1 > 19)
  {
    acc_1 = ((acc_1 + (segment_29_1 * 2)) + 5) & 127;
    aux_1 ^= segment_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_29_2 > 19)
  {
    acc_2 = ((acc_2 + (segment_29_2 * 2)) + 5) & 127;
    aux_2 ^= segment_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_91_1)
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

  switch (offset_91_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_10_1 == index_reg_10_2);
  assert(segment_29_1 == segment_29_2);
  assert(offset_91_1 == offset_91_2);
}

int fn_R000741_4113_5(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_10 = local_arr[aux % 3];
  acc = (acc + (index_reg_10 * 2)) & 127;
  int segment_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_29 > 19)
  {
    acc = ((acc + (segment_29 * 2)) + 5) & 127;
    aux ^= segment_29 & 15;
  }
  else
  {
    acc = ((acc - segment_29) + 11) & 127;
    aux += 3;
  }
  int offset_91 = (aux + st.buffer[1]) & 3;
  switch (offset_91)
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

void fn_R000741_4113_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000741_4113_0 st_1 = {0};
  struct DeviceConfig_R000741_4113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int segment_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_75_1 > 30)
  {
    acc_1 = ((acc_1 + (segment_75_1 * 2)) + 5) & 127;
    aux_1 ^= segment_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_75_2 > 30)
  {
    acc_2 = ((acc_2 + (segment_75_2 * 2)) + 5) & 127;
    aux_2 ^= segment_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_75_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_62_1)
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

  switch (mask_62_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_75_1 == segment_75_2);
  assert(mask_62_1 == mask_62_2);
}

int fn_R000741_4113_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000741_4113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int segment_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_75 > 30)
  {
    acc = ((acc + (segment_75 * 2)) + 5) & 127;
    aux ^= segment_75 & 15;
  }
  else
  {
    acc = ((acc - segment_75) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_62 = (aux + st.buffer[1]) & 3;
  switch (mask_62)
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

void fn_R000741_4113_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st_1 = {0};
  struct CipherContext_R000741_4113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int accumulator_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_58_1)
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

  switch (accumulator_58_2)
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
  int anchor_28_1 = local_arr_1[aux_1 % 3];
  int anchor_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_58_1 == accumulator_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_28_1 == anchor_28_2);
}

int fn_R000741_4113_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int accumulator_58 = (aux + st.buffer[1]) & 3;
  switch (accumulator_58)
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
  int anchor_28 = local_arr[aux % 3];
  acc = (acc + (anchor_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000741_4113_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000741_4113_0 st_1 = {0};
  struct DeviceConfig_R000741_4113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int delta_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_90_1) & 63;
  aux_2 = (aux_2 + delta_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_64_1 = local_arr_1[aux_1 % 3];
  int offset_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_90_1 == delta_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_64_1 == offset_64_2);
}

int fn_R000741_4113_8(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000741_4113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int delta_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_90) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_64 = local_arr[aux % 3];
  acc = (acc + (offset_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000741_4113_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000741_4113_0 st_1 = {0};
  struct DeviceConfig_R000741_4113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_31_1 > 34)
  {
    acc_1 = ((acc_1 + (residue_31_1 * 2)) + 5) & 127;
    aux_1 ^= residue_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_31_2 > 34)
  {
    acc_2 = ((acc_2 + (residue_31_2 * 2)) + 5) & 127;
    aux_2 ^= residue_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_75_1)
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

  switch (vector_75_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_31_1 == residue_31_2);
  assert(vector_75_1 == vector_75_2);
}

int fn_R000741_4113_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000741_4113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_31 > 34)
  {
    acc = ((acc + (residue_31 * 2)) + 5) & 127;
    aux ^= residue_31 & 15;
  }
  else
  {
    acc = ((acc - residue_31) + 11) & 127;
    aux += 3;
  }
  int vector_75 = (aux + st.buffer[1]) & 3;
  switch (vector_75)
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

void fn_R000741_4113_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st_1 = {0};
  struct CipherContext_R000741_4113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int stride_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_30_1) & 63;
  aux_2 = (aux_2 + stride_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_16_1 > 48)
  {
    acc_1 = ((acc_1 + (stride_16_1 * 2)) + 5) & 127;
    aux_1 ^= stride_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_16_2 > 48)
  {
    acc_2 = ((acc_2 + (stride_16_2 * 2)) + 5) & 127;
    aux_2 ^= stride_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_30_1 == stride_30_2);
  assert(stride_16_1 == stride_16_2);
}

int fn_R000741_4113_10(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int stride_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_30) & 63;
  acc ^= aux;
  int stride_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_16 > 48)
  {
    acc = ((acc + (stride_16 * 2)) + 5) & 127;
    aux ^= stride_16 & 15;
  }
  else
  {
    acc = ((acc - stride_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000741_4113_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st_1 = {0};
  struct CipherContext_R000741_4113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_98_1 > 36)
  {
    acc_1 = ((acc_1 + (damping_98_1 * 2)) + 5) & 127;
    aux_1 ^= damping_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_98_2 > 36)
  {
    acc_2 = ((acc_2 + (damping_98_2 * 2)) + 5) & 127;
    aux_2 ^= damping_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_62_1)
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

  switch (offset_62_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_98_1 == damping_98_2);
  assert(offset_62_1 == offset_62_2);
}

int fn_R000741_4113_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_98 > 36)
  {
    acc = ((acc + (damping_98 * 2)) + 5) & 127;
    aux ^= damping_98 & 15;
  }
  else
  {
    acc = ((acc - damping_98) + 11) & 127;
    aux += 3;
  }
  int offset_62 = (aux + st.buffer[1]) & 3;
  switch (offset_62)
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

void fn_R000741_4113_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st_1 = {0};
  struct Vector3D_R000741_4113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_59_1 = local_arr_1[aux_1 % 3];
  int scale_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_59_2 * 2)) & 127;
  int margin_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_37_1)
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

  switch (margin_37_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_59_1 == scale_59_2);
  assert(margin_37_1 == margin_37_2);
}

int fn_R000741_4113_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int scale_59 = local_arr[aux % 3];
  acc = (acc + (scale_59 * 2)) & 127;
  int margin_37 = (aux + st.buffer[1]) & 3;
  switch (margin_37)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000741_4113_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st_1 = {0};
  struct CipherContext_R000741_4113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quantum_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_62_1 > 43)
  {
    acc_1 = ((acc_1 + (quantum_62_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_62_2 > 43)
  {
    acc_2 = ((acc_2 + (quantum_62_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_53_1 = local_arr_1[aux_1 % 3];
  int threshold_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_53_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_62_1 == quantum_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_53_1 == threshold_53_2);
}

int fn_R000741_4113_13(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000741_4113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quantum_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_62 > 43)
  {
    acc = ((acc + (quantum_62 * 2)) + 5) & 127;
    aux ^= quantum_62 & 15;
  }
  else
  {
    acc = ((acc - quantum_62) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_53 = local_arr[aux % 3];
  acc = (acc + (threshold_53 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000741_4113_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st_1 = {0};
  struct Vector3D_R000741_4113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_51_1 = local_arr_1[aux_1 % 3];
  int window_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_51_2 * 2)) & 127;
  int checksum_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_70_1 > 36)
  {
    acc_1 = ((acc_1 + (checksum_70_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_70_2 > 36)
  {
    acc_2 = ((acc_2 + (checksum_70_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_37_1)
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

  switch (quotient_37_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_51_1 == window_51_2);
  assert(checksum_70_1 == checksum_70_2);
  assert(quotient_37_1 == quotient_37_2);
}

int fn_R000741_4113_14(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int window_51 = local_arr[aux % 3];
  acc = (acc + (window_51 * 2)) & 127;
  int checksum_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_70 > 36)
  {
    acc = ((acc + (checksum_70 * 2)) + 5) & 127;
    aux ^= checksum_70 & 15;
  }
  else
  {
    acc = ((acc - checksum_70) + 11) & 127;
    aux += 3;
  }
  int quotient_37 = (aux + st.buffer[1]) & 3;
  switch (quotient_37)
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

void fn_R000741_4113_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000741_4113_0 st_1 = {0};
  struct DeviceConfig_R000741_4113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int vector_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_91_1)
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

  switch (vector_91_2)
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
  int parity_60_1 = local_arr_1[aux_1 % 3];
  int parity_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_91_1 == vector_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_60_1 == parity_60_2);
}

int fn_R000741_4113_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000741_4113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int vector_91 = (aux + st.buffer[1]) & 3;
  switch (vector_91)
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
  int parity_60 = local_arr[aux % 3];
  acc = (acc + (parity_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000741_4113_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st_1 = {0};
  struct Vector3D_R000741_4113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_95_1 > 32)
  {
    acc_1 = ((acc_1 + (mask_95_1 * 2)) + 5) & 127;
    aux_1 ^= mask_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_95_2 > 32)
  {
    acc_2 = ((acc_2 + (mask_95_2 * 2)) + 5) & 127;
    aux_2 ^= mask_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_86_1 = local_arr_1[aux_1 % 3];
  int quantum_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_95_1 == mask_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_86_1 == quantum_86_2);
}

int fn_R000741_4113_16(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000741_4113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_95 > 32)
  {
    acc = ((acc + (mask_95 * 2)) + 5) & 127;
    aux ^= mask_95 & 15;
  }
  else
  {
    acc = ((acc - mask_95) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_86 = local_arr[aux % 3];
  acc = (acc + (quantum_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000741_0_1;
  int sec_r000741_0_2;
  int sec_r000741_1_1;
  int sec_r000741_1_2;
  int sec_r000741_2_1;
  int sec_r000741_2_2;
  int sec_r000741_3_1;
  int sec_r000741_3_2;
  int sec_r000741_4_1;
  int sec_r000741_4_2;
  int sec_r000741_5_1;
  int sec_r000741_5_2;
  int sec_r000741_6_1;
  int sec_r000741_6_2;
  int sec_r000741_7_1;
  int sec_r000741_7_2;
  int sec_r000741_8_1;
  int sec_r000741_8_2;
  int sec_r000741_9_1;
  int sec_r000741_9_2;
  int sec_r000741_10_1;
  int sec_r000741_10_2;
  int sec_r000741_11_1;
  int sec_r000741_11_2;
  int sec_r000741_12_1;
  int sec_r000741_12_2;
  int sec_r000741_13_1;
  int sec_r000741_13_2;
  int sec_r000741_14_1;
  int sec_r000741_14_2;
  int sec_r000741_15_1;
  int sec_r000741_15_2;
  int sec_r000741_16_1;
  int sec_r000741_16_2;
  int sec_r000741_17_1;
  int sec_r000741_17_2;
  int sec_r000741_18_1;
  int sec_r000741_18_2;
  int sec_r000741_19_1;
  int sec_r000741_19_2;
  int sec_r000741_20_1;
  int sec_r000741_20_2;
  int sec_r000741_21_1;
  int sec_r000741_21_2;
  int pub_r000741_0_1;
  int pub_r000741_0_2;
  int pub_r000741_1_1;
  int pub_r000741_1_2;
  int pub_r000741_2_1;
  int pub_r000741_2_2;
  int pub_r000741_3_1;
  int pub_r000741_3_2;
  int pub_r000741_4_1;
  int pub_r000741_4_2;
  int pub_r000741_5_1;
  int pub_r000741_5_2;
  int pub_r000741_6_1;
  int pub_r000741_6_2;
  int pub_r000741_7_1;
  int pub_r000741_7_2;
  int pub_r000741_8_1;
  int pub_r000741_8_2;
  int pub_r000741_9_1;
  int pub_r000741_9_2;
  int pub_r000741_10_1;
  int pub_r000741_10_2;
  int pub_r000741_11_1;
  int pub_r000741_11_2;
  int pub_r000741_12_1;
  int pub_r000741_12_2;
  int pub_r000741_13_1;
  int pub_r000741_13_2;
  int pub_r000741_14_1;
  int pub_r000741_14_2;
  int pub_r000741_15_1;
  int pub_r000741_15_2;
  int pub_r000741_16_1;
  int pub_r000741_16_2;
  int pub_r000741_17_1;
  int pub_r000741_17_2;
  int pub_r000741_18_1;
  int pub_r000741_18_2;
  int pub_r000741_19_1;
  int pub_r000741_19_2;
  int pub_r000741_20_1;
  int pub_r000741_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000741_0_1 >= (-100)) && (pub_r000741_0_1 <= 100));
  __CPROVER_assume((pub_r000741_0_2 >= (-100)) && (pub_r000741_0_2 <= 100));
  __CPROVER_assume((pub_r000741_1_1 >= (-100)) && (pub_r000741_1_1 <= 100));
  __CPROVER_assume((pub_r000741_1_2 >= (-100)) && (pub_r000741_1_2 <= 100));
  __CPROVER_assume((pub_r000741_2_1 >= (-100)) && (pub_r000741_2_1 <= 100));
  __CPROVER_assume((pub_r000741_2_2 >= (-100)) && (pub_r000741_2_2 <= 100));
  __CPROVER_assume((pub_r000741_3_1 >= (-100)) && (pub_r000741_3_1 <= 100));
  __CPROVER_assume((pub_r000741_3_2 >= (-100)) && (pub_r000741_3_2 <= 100));
  __CPROVER_assume((pub_r000741_4_1 >= (-100)) && (pub_r000741_4_1 <= 100));
  __CPROVER_assume((pub_r000741_4_2 >= (-100)) && (pub_r000741_4_2 <= 100));
  __CPROVER_assume((pub_r000741_5_1 >= (-100)) && (pub_r000741_5_1 <= 100));
  __CPROVER_assume((pub_r000741_5_2 >= (-100)) && (pub_r000741_5_2 <= 100));
  __CPROVER_assume((pub_r000741_6_1 >= (-100)) && (pub_r000741_6_1 <= 100));
  __CPROVER_assume((pub_r000741_6_2 >= (-100)) && (pub_r000741_6_2 <= 100));
  __CPROVER_assume((pub_r000741_7_1 >= (-100)) && (pub_r000741_7_1 <= 100));
  __CPROVER_assume((pub_r000741_7_2 >= (-100)) && (pub_r000741_7_2 <= 100));
  __CPROVER_assume((pub_r000741_8_1 >= (-100)) && (pub_r000741_8_1 <= 100));
  __CPROVER_assume((pub_r000741_8_2 >= (-100)) && (pub_r000741_8_2 <= 100));
  __CPROVER_assume((pub_r000741_9_1 >= (-100)) && (pub_r000741_9_1 <= 100));
  __CPROVER_assume((pub_r000741_9_2 >= (-100)) && (pub_r000741_9_2 <= 100));
  __CPROVER_assume((pub_r000741_10_1 >= (-100)) && (pub_r000741_10_1 <= 100));
  __CPROVER_assume((pub_r000741_10_2 >= (-100)) && (pub_r000741_10_2 <= 100));
  __CPROVER_assume((pub_r000741_11_1 >= (-100)) && (pub_r000741_11_1 <= 100));
  __CPROVER_assume((pub_r000741_11_2 >= (-100)) && (pub_r000741_11_2 <= 100));
  __CPROVER_assume((pub_r000741_12_1 >= (-100)) && (pub_r000741_12_1 <= 100));
  __CPROVER_assume((pub_r000741_12_2 >= (-100)) && (pub_r000741_12_2 <= 100));
  __CPROVER_assume((pub_r000741_13_1 >= (-100)) && (pub_r000741_13_1 <= 100));
  __CPROVER_assume((pub_r000741_13_2 >= (-100)) && (pub_r000741_13_2 <= 100));
  __CPROVER_assume((pub_r000741_14_1 >= (-100)) && (pub_r000741_14_1 <= 100));
  __CPROVER_assume((pub_r000741_14_2 >= (-100)) && (pub_r000741_14_2 <= 100));
  __CPROVER_assume((pub_r000741_15_1 >= (-100)) && (pub_r000741_15_1 <= 100));
  __CPROVER_assume((pub_r000741_15_2 >= (-100)) && (pub_r000741_15_2 <= 100));
  __CPROVER_assume((pub_r000741_16_1 >= (-100)) && (pub_r000741_16_1 <= 100));
  __CPROVER_assume((pub_r000741_16_2 >= (-100)) && (pub_r000741_16_2 <= 100));
  __CPROVER_assume((pub_r000741_17_1 >= (-100)) && (pub_r000741_17_1 <= 100));
  __CPROVER_assume((pub_r000741_17_2 >= (-100)) && (pub_r000741_17_2 <= 100));
  __CPROVER_assume((pub_r000741_18_1 >= (-100)) && (pub_r000741_18_1 <= 100));
  __CPROVER_assume((pub_r000741_18_2 >= (-100)) && (pub_r000741_18_2 <= 100));
  __CPROVER_assume((pub_r000741_19_1 >= (-100)) && (pub_r000741_19_1 <= 100));
  __CPROVER_assume((pub_r000741_19_2 >= (-100)) && (pub_r000741_19_2 <= 100));
  __CPROVER_assume((pub_r000741_20_1 >= (-100)) && (pub_r000741_20_1 <= 100));
  __CPROVER_assume((pub_r000741_20_2 >= (-100)) && (pub_r000741_20_2 <= 100));
  __CPROVER_assume((sec_r000741_0_1 >= 0) && (sec_r000741_0_1 <= 255));
  __CPROVER_assume((sec_r000741_0_2 >= 0) && (sec_r000741_0_2 <= 255));
  __CPROVER_assume((sec_r000741_1_1 >= 0) && (sec_r000741_1_1 <= 255));
  __CPROVER_assume((sec_r000741_1_2 >= 0) && (sec_r000741_1_2 <= 255));
  __CPROVER_assume((sec_r000741_2_1 >= 0) && (sec_r000741_2_1 <= 255));
  __CPROVER_assume((sec_r000741_2_2 >= 0) && (sec_r000741_2_2 <= 255));
  __CPROVER_assume((sec_r000741_3_1 >= 0) && (sec_r000741_3_1 <= 255));
  __CPROVER_assume((sec_r000741_3_2 >= 0) && (sec_r000741_3_2 <= 255));
  __CPROVER_assume((sec_r000741_4_1 >= 0) && (sec_r000741_4_1 <= 255));
  __CPROVER_assume((sec_r000741_4_2 >= 0) && (sec_r000741_4_2 <= 255));
  __CPROVER_assume((sec_r000741_5_1 >= 0) && (sec_r000741_5_1 <= 255));
  __CPROVER_assume((sec_r000741_5_2 >= 0) && (sec_r000741_5_2 <= 255));
  __CPROVER_assume((sec_r000741_6_1 >= 0) && (sec_r000741_6_1 <= 255));
  __CPROVER_assume((sec_r000741_6_2 >= 0) && (sec_r000741_6_2 <= 255));
  __CPROVER_assume((sec_r000741_7_1 >= 0) && (sec_r000741_7_1 <= 255));
  __CPROVER_assume((sec_r000741_7_2 >= 0) && (sec_r000741_7_2 <= 255));
  __CPROVER_assume((sec_r000741_8_1 >= 0) && (sec_r000741_8_1 <= 255));
  __CPROVER_assume((sec_r000741_8_2 >= 0) && (sec_r000741_8_2 <= 255));
  __CPROVER_assume((sec_r000741_9_1 >= 0) && (sec_r000741_9_1 <= 255));
  __CPROVER_assume((sec_r000741_9_2 >= 0) && (sec_r000741_9_2 <= 255));
  __CPROVER_assume((sec_r000741_10_1 >= 0) && (sec_r000741_10_1 <= 255));
  __CPROVER_assume((sec_r000741_10_2 >= 0) && (sec_r000741_10_2 <= 255));
  __CPROVER_assume((sec_r000741_11_1 >= 0) && (sec_r000741_11_1 <= 255));
  __CPROVER_assume((sec_r000741_11_2 >= 0) && (sec_r000741_11_2 <= 255));
  __CPROVER_assume((sec_r000741_12_1 >= 0) && (sec_r000741_12_1 <= 255));
  __CPROVER_assume((sec_r000741_12_2 >= 0) && (sec_r000741_12_2 <= 255));
  __CPROVER_assume((sec_r000741_13_1 >= 0) && (sec_r000741_13_1 <= 255));
  __CPROVER_assume((sec_r000741_13_2 >= 0) && (sec_r000741_13_2 <= 255));
  __CPROVER_assume((sec_r000741_14_1 >= 0) && (sec_r000741_14_1 <= 255));
  __CPROVER_assume((sec_r000741_14_2 >= 0) && (sec_r000741_14_2 <= 255));
  __CPROVER_assume((sec_r000741_15_1 >= 0) && (sec_r000741_15_1 <= 255));
  __CPROVER_assume((sec_r000741_15_2 >= 0) && (sec_r000741_15_2 <= 255));
  __CPROVER_assume((sec_r000741_16_1 >= 0) && (sec_r000741_16_1 <= 255));
  __CPROVER_assume((sec_r000741_16_2 >= 0) && (sec_r000741_16_2 <= 255));
  __CPROVER_assume((sec_r000741_17_1 >= 0) && (sec_r000741_17_1 <= 255));
  __CPROVER_assume((sec_r000741_17_2 >= 0) && (sec_r000741_17_2 <= 255));
  __CPROVER_assume((sec_r000741_18_1 >= 0) && (sec_r000741_18_1 <= 255));
  __CPROVER_assume((sec_r000741_18_2 >= 0) && (sec_r000741_18_2 <= 255));
  __CPROVER_assume((sec_r000741_19_1 >= 0) && (sec_r000741_19_1 <= 255));
  __CPROVER_assume((sec_r000741_19_2 >= 0) && (sec_r000741_19_2 <= 255));
  __CPROVER_assume((sec_r000741_20_1 >= 0) && (sec_r000741_20_1 <= 255));
  __CPROVER_assume((sec_r000741_20_2 >= 0) && (sec_r000741_20_2 <= 255));
  __CPROVER_assume((sec_r000741_21_1 >= 0) && (sec_r000741_21_1 <= 255));
  __CPROVER_assume((sec_r000741_21_2 >= 0) && (sec_r000741_21_2 <= 255));
  struct DeviceConfig_R000741_4113_0 st_var_0_1 = {0};
  struct DeviceConfig_R000741_4113_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000741_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000741_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000741_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000741_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000741_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000741_0_2 + 7) & 15;
  struct Vector3D_R000741_4113_1 st_var_1_1 = {0};
  struct Vector3D_R000741_4113_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000741_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000741_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000741_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000741_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000741_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000741_0_2 + 9) & 15;
  struct CipherContext_R000741_4113_2 st_var_2_1 = {0};
  struct CipherContext_R000741_4113_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000741_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000741_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000741_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000741_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000741_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000741_0_2 + 11) & 15;
  union TelemetryField_R000741_4113_0 u_var_1;
  union TelemetryField_R000741_4113_0 u_var_2;
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
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 44)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 44)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 17) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 50)
    {
      chk_sum_1 ^= stage_v_18_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_18_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 50)
    {
      chk_sum_2 ^= stage_v_18_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 20) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 20) & 15;
  int stage_v_19_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_19_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= stage_v_19_1;
  chk_sum_2 ^= stage_v_19_2;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 54)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 54)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = (st_var_1_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_1_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 25)
    {
      chk_sum_1 ^= stage_v_25_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_25_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 25)
    {
      chk_sum_2 ^= stage_v_25_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (st_var_2_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_2_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (st_var_1_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_1_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 34) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = table_1[1];
  int stage_v_37_2 = table_2[1];
  table_1[1] = (table_1[2] + 75) & 63;
  table_2[1] = (table_2[2] + 75) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_40_1 = (st_var_1_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_1_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 43) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  int stage_v_43_1 = ((st_var_1_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_1_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 43)
    {
      chk_sum_1 ^= stage_v_43_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_43_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 43)
    {
      chk_sum_2 ^= stage_v_43_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 45) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 25)
    {
      chk_sum_1 ^= stage_v_48_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_48_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 25)
    {
      chk_sum_2 ^= stage_v_48_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 51) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
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
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = ((st_var_0_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_0_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 39)
    {
      chk_sum_1 ^= stage_v_54_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_54_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 39)
    {
      chk_sum_2 ^= stage_v_54_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_57_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 60) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 64) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= stage_v_63_1;
  chk_sum_2 ^= stage_v_63_2;
  int stage_v_64_1 = table_1[0];
  int stage_v_64_2 = table_2[0];
  table_1[0] = (table_1[1] + 129) & 63;
  table_2[0] = (table_2[1] + 129) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((st_var_2_1.buffer[2] * 2) + 202) & 63;
  int stage_v_65_2 = ((st_var_2_2.buffer[2] * 2) + 202) & 63;
  if (stage_v_65_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_65_1) - 5) & 255;
    if (stage_v_65_1 > 25)
    {
      chk_sum_1 ^= stage_v_65_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_65_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_65_2) - 5) & 255;
    if (stage_v_65_2 > 25)
    {
      chk_sum_2 ^= stage_v_65_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  int stage_v_68_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (73 & 31);
  int stage_v_68_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (73 & 31);
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= (stage_v_68_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_68_2 << 1) & 127;
  int stage_v_69_1 = (st_var_0_1.buffer[0] ^ 72) & 3;
  int stage_v_69_2 = (st_var_0_2.buffer[0] ^ 72) & 3;
  switch (stage_v_69_1)
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

  switch (stage_v_69_2)
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

  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = table_1[3];
  int stage_v_71_2 = table_2[3];
  table_1[3] = (table_1[0] + 143) & 63;
  table_2[3] = (table_2[0] + 143) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 28)
    {
      chk_sum_1 ^= stage_v_72_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_72_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 28)
    {
      chk_sum_2 ^= stage_v_72_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_73_1 = ((st_var_1_1.buffer[1] * 2) + 226) & 63;
  int stage_v_73_2 = ((st_var_1_2.buffer[1] * 2) + 226) & 63;
  if (stage_v_73_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_73_1) - 5) & 255;
    if (stage_v_73_1 > 39)
    {
      chk_sum_1 ^= stage_v_73_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_73_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_73_2) - 5) & 255;
    if (stage_v_73_2 > 39)
    {
      chk_sum_2 ^= stage_v_73_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_74_1 = (st_var_2_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_2_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
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

  switch (stage_v_74_2)
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

  int stage_v_75_1 = ((st_var_0_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_0_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 31)
    {
      chk_sum_1 ^= stage_v_75_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_75_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 31)
    {
      chk_sum_2 ^= stage_v_75_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_76_1 = ((st_var_1_1.buffer[1] * 2) + 235) & 63;
  int stage_v_76_2 = ((st_var_1_2.buffer[1] * 2) + 235) & 63;
  if (stage_v_76_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_76_1) - 5) & 255;
    if (stage_v_76_1 > 49)
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
  if (stage_v_76_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_76_2) - 5) & 255;
    if (stage_v_76_2 > 49)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 78) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  int stage_v_78_1 = table_1[2];
  int stage_v_78_2 = table_2[2];
  table_1[2] = (table_1[3] + 157) & 63;
  table_2[2] = (table_2[3] + 157) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
  int stage_v_81_1 = (st_var_0_1.buffer[0] ^ 84) & 3;
  int stage_v_81_2 = (st_var_0_2.buffer[0] ^ 84) & 3;
  switch (stage_v_81_1)
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

  switch (stage_v_81_2)
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

  int stage_v_82_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_82_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 84) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 84) & 15;
  int stage_v_83_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_83_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= stage_v_83_1;
  chk_sum_2 ^= stage_v_83_2;
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_85_1 = ((st_var_1_1.buffer[1] * 2) + 262) & 63;
  int stage_v_85_2 = ((st_var_1_2.buffer[1] * 2) + 262) & 63;
  if (stage_v_85_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_85_1) - 5) & 255;
    if (stage_v_85_1 > 49)
    {
      chk_sum_1 ^= stage_v_85_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_85_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_85_2) - 5) & 255;
    if (stage_v_85_2 > 49)
    {
      chk_sum_2 ^= stage_v_85_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 87) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 87) & 15;
  int stage_v_86_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_86_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= stage_v_86_1;
  chk_sum_2 ^= stage_v_86_2;
  int stage_v_87_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_87_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_88_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_88_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_89_1 = table_1[1];
  int stage_v_89_2 = table_2[1];
  table_1[1] = (table_1[2] + 179) & 63;
  table_2[1] = (table_2[2] + 179) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 91) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 91) & 15;
  int stage_v_90_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_90_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= stage_v_90_1;
  chk_sum_2 ^= stage_v_90_2;
  int stage_v_91_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_91_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_91_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_91_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_92_1 = ((st_var_2_1.buffer[2] * 2) + 283) & 63;
  int stage_v_92_2 = ((st_var_2_2.buffer[2] * 2) + 283) & 63;
  if (stage_v_92_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_92_1) - 5) & 255;
    if (stage_v_92_1 > 37)
    {
      chk_sum_1 ^= stage_v_92_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_92_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_92_2) - 5) & 255;
    if (stage_v_92_2 > 37)
    {
      chk_sum_2 ^= stage_v_92_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_94_1 = table_1[2];
  int stage_v_94_2 = table_2[2];
  table_1[2] = (table_1[3] + 189) & 63;
  table_2[2] = (table_2[3] + 189) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (100 & 31);
  int stage_v_95_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (100 & 31);
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= (stage_v_95_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_95_2 << 1) & 127;
  int stage_v_96_1 = ((st_var_0_1.buffer[0] * 2) + 295) & 63;
  int stage_v_96_2 = ((st_var_0_2.buffer[0] * 2) + 295) & 63;
  if (stage_v_96_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_96_1) - 5) & 255;
    if (stage_v_96_1 > 47)
    {
      chk_sum_1 ^= stage_v_96_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_96_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_96_2) - 5) & 255;
    if (stage_v_96_2 > 47)
    {
      chk_sum_2 ^= stage_v_96_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_97_1 = (st_var_1_1.buffer[0] ^ 100) & 3;
  int stage_v_97_2 = (st_var_1_2.buffer[0] ^ 100) & 3;
  switch (stage_v_97_1)
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

  switch (stage_v_97_2)
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

  int stage_v_98_1 = (st_var_2_1.buffer[0] ^ 101) & 3;
  int stage_v_98_2 = (st_var_2_2.buffer[0] ^ 101) & 3;
  switch (stage_v_98_1)
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

  switch (stage_v_98_2)
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

  int stage_v_99_1 = ((st_var_0_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_0_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 45)
    {
      chk_sum_1 ^= stage_v_99_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_99_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 45)
    {
      chk_sum_2 ^= stage_v_99_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 101) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 101) & 15;
  int stage_v_100_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_100_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= stage_v_100_1;
  chk_sum_2 ^= stage_v_100_2;
  int stage_v_101_1 = ((st_var_2_1.buffer[2] * 2) + 310) & 63;
  int stage_v_101_2 = ((st_var_2_2.buffer[2] * 2) + 310) & 63;
  if (stage_v_101_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_101_1) - 5) & 255;
    if (stage_v_101_1 > 40)
    {
      chk_sum_1 ^= stage_v_101_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_101_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_101_2) - 5) & 255;
    if (stage_v_101_2 > 40)
    {
      chk_sum_2 ^= stage_v_101_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_102_1 = ((st_var_0_1.buffer[0] * 2) + 313) & 63;
  int stage_v_102_2 = ((st_var_0_2.buffer[0] * 2) + 313) & 63;
  if (stage_v_102_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_102_1) - 5) & 255;
    if (stage_v_102_1 > 51)
    {
      chk_sum_1 ^= stage_v_102_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_102_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_102_2) - 5) & 255;
    if (stage_v_102_2 > 51)
    {
      chk_sum_2 ^= stage_v_102_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 104) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 104) & 15;
  int stage_v_103_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_103_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= stage_v_103_1;
  chk_sum_2 ^= stage_v_103_2;
  int stage_v_104_1 = table_1[0];
  int stage_v_104_2 = table_2[0];
  table_1[0] = (table_1[1] + 209) & 63;
  table_2[0] = (table_2[1] + 209) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = table_1[1];
  int stage_v_105_2 = table_2[1];
  table_1[1] = (table_1[2] + 211) & 63;
  table_2[1] = (table_2[2] + 211) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 107) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 107) & 15;
  int stage_v_106_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_106_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  chk_sum_1 ^= stage_v_106_1;
  chk_sum_2 ^= stage_v_106_2;
  int stage_v_107_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (112 & 31);
  int stage_v_107_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (112 & 31);
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  chk_sum_1 ^= (stage_v_107_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_107_2 << 1) & 127;
  int stage_v_108_1 = ((st_var_0_1.buffer[0] * 2) + 331) & 63;
  int stage_v_108_2 = ((st_var_0_2.buffer[0] * 2) + 331) & 63;
  if (stage_v_108_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_108_1) - 5) & 255;
    if (stage_v_108_1 > 52)
    {
      chk_sum_1 ^= stage_v_108_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_108_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_108_2) - 5) & 255;
    if (stage_v_108_2 > 52)
    {
      chk_sum_2 ^= stage_v_108_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_109_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_109_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_110_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (115 & 31);
  int stage_v_110_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (115 & 31);
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  chk_sum_1 ^= (stage_v_110_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_110_2 << 1) & 127;
  int stage_v_111_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_111_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_112_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_112_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_112_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_112_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_113_1 = table_1[1];
  int stage_v_113_2 = table_2[1];
  table_1[1] = (table_1[2] + 227) & 63;
  table_2[1] = (table_2[2] + 227) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 116) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 116) & 15;
  int stage_v_115_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_115_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  chk_sum_1 ^= stage_v_115_1;
  chk_sum_2 ^= stage_v_115_2;
  int stage_v_116_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_116_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_117_1 = (st_var_0_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_0_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  int stage_v_118_1 = ((st_var_1_1.buffer[1] * 2) + 361) & 63;
  int stage_v_118_2 = ((st_var_1_2.buffer[1] * 2) + 361) & 63;
  if (stage_v_118_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_118_1) - 5) & 255;
    if (stage_v_118_1 > 42)
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
  if (stage_v_118_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_118_2) - 5) & 255;
    if (stage_v_118_2 > 42)
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
  int stage_v_119_1 = table_1[3];
  int stage_v_119_2 = table_2[3];
  table_1[3] = (table_1[0] + 239) & 63;
  table_2[3] = (table_2[0] + 239) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = table_1[0];
  int stage_v_120_2 = table_2[0];
  table_1[0] = (table_1[1] + 241) & 63;
  table_2[0] = (table_2[1] + 241) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((st_var_1_1.buffer[1] * 2) + 370) & 63;
  int stage_v_121_2 = ((st_var_1_2.buffer[1] * 2) + 370) & 63;
  if (stage_v_121_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_121_1) - 5) & 255;
    if (stage_v_121_1 > 55)
    {
      chk_sum_1 ^= stage_v_121_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_121_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_121_2) - 5) & 255;
    if (stage_v_121_2 > 55)
    {
      chk_sum_2 ^= stage_v_121_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_122_1 = (st_var_2_1.buffer[0] ^ 125) & 3;
  int stage_v_122_2 = (st_var_2_2.buffer[0] ^ 125) & 3;
  switch (stage_v_122_1)
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

  switch (stage_v_122_2)
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

  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_124_1 = ((stage_v_124_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_124_2 = ((stage_v_124_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = table_1[1];
  int stage_v_125_2 = table_2[1];
  table_1[1] = (table_1[2] + 251) & 63;
  table_2[1] = (table_2[2] + 251) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (131 & 31);
  int stage_v_126_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (131 & 31);
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  chk_sum_1 ^= (stage_v_126_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_126_2 << 1) & 127;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = table_1[0];
  int stage_v_128_2 = table_2[0];
  table_1[0] = (table_1[1] + 257) & 63;
  table_2[0] = (table_2[1] + 257) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((st_var_0_1.buffer[0] * 2) + 394) & 63;
  int stage_v_129_2 = ((st_var_0_2.buffer[0] * 2) + 394) & 63;
  if (stage_v_129_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_129_1) - 5) & 255;
    if (stage_v_129_1 > 53)
    {
      chk_sum_1 ^= stage_v_129_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_129_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_129_2) - 5) & 255;
    if (stage_v_129_2 > 53)
    {
      chk_sum_2 ^= stage_v_129_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_130_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_130_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 132) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 132) & 15;
  int stage_v_131_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_131_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  chk_sum_1 ^= stage_v_131_1;
  chk_sum_2 ^= stage_v_131_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 133) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 133) & 15;
  int stage_v_132_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_132_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  chk_sum_1 ^= stage_v_132_1;
  chk_sum_2 ^= stage_v_132_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 134) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 134) & 15;
  int stage_v_133_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_133_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= stage_v_133_1;
  chk_sum_2 ^= stage_v_133_2;
  int stage_v_134_1 = table_1[2];
  int stage_v_134_2 = table_2[2];
  table_1[2] = (table_1[3] + 269) & 63;
  table_2[2] = (table_2[3] + 269) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 136) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 136) & 15;
  int stage_v_135_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_135_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= stage_v_135_1;
  chk_sum_2 ^= stage_v_135_2;
  int stage_v_136_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (141 & 31);
  int stage_v_136_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (141 & 31);
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= (stage_v_136_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_136_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 138) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 138) & 15;
  int stage_v_137_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_137_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  chk_sum_1 ^= stage_v_137_1;
  chk_sum_2 ^= stage_v_137_2;
  int stage_v_138_1 = (st_var_0_1.buffer[0] ^ 141) & 3;
  int stage_v_138_2 = (st_var_0_2.buffer[0] ^ 141) & 3;
  switch (stage_v_138_1)
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

  switch (stage_v_138_2)
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

  int stage_v_139_1 = ((st_var_1_1.buffer[1] * 2) + 424) & 63;
  int stage_v_139_2 = ((st_var_1_2.buffer[1] * 2) + 424) & 63;
  if (stage_v_139_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_139_1) - 5) & 255;
    if (stage_v_139_1 > 39)
    {
      chk_sum_1 ^= stage_v_139_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_139_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_139_2) - 5) & 255;
    if (stage_v_139_2 > 39)
    {
      chk_sum_2 ^= stage_v_139_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_140_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_140_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_141_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (146 & 31);
  int stage_v_141_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (146 & 31);
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= (stage_v_141_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_141_2 << 1) & 127;
  int stage_v_142_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (147 & 31);
  int stage_v_142_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (147 & 31);
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= (stage_v_142_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_142_2 << 1) & 127;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((st_var_0_1.buffer[0] * 2) + 439) & 63;
  int stage_v_144_2 = ((st_var_0_2.buffer[0] * 2) + 439) & 63;
  if (stage_v_144_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_144_1) - 5) & 255;
    if (stage_v_144_1 > 53)
    {
      chk_sum_1 ^= stage_v_144_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_144_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_144_2) - 5) & 255;
    if (stage_v_144_2 > 53)
    {
      chk_sum_2 ^= stage_v_144_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_146_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_146_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_146_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 148) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 148) & 15;
  int stage_v_147_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_147_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= stage_v_147_1;
  chk_sum_2 ^= stage_v_147_2;
  int stage_v_148_1 = table_1[0];
  int stage_v_148_2 = table_2[0];
  table_1[0] = (table_1[1] + 297) & 63;
  table_2[0] = (table_2[1] + 297) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_149_1 = ((stage_v_149_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_150_1 = ((stage_v_150_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_150_2 = ((stage_v_150_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (st_var_1_1.buffer[0] ^ 154) & 3;
  int stage_v_151_2 = (st_var_1_2.buffer[0] ^ 154) & 3;
  switch (stage_v_151_1)
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

  switch (stage_v_151_2)
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

  int stage_v_152_1 = table_1[0];
  int stage_v_152_2 = table_2[0];
  table_1[0] = (table_1[1] + 305) & 63;
  table_2[0] = (table_2[1] + 305) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = table_1[1];
  int stage_v_153_2 = table_2[1];
  table_1[1] = (table_1[2] + 307) & 63;
  table_2[1] = (table_2[2] + 307) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_154_1 = ((stage_v_154_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_154_2 = ((stage_v_154_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (st_var_2_1.buffer[0] ^ 158) & 3;
  int stage_v_155_2 = (st_var_2_2.buffer[0] ^ 158) & 3;
  switch (stage_v_155_1)
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

  switch (stage_v_155_2)
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

  int stage_v_156_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_156_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_156_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_156_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 158) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 158) & 15;
  int stage_v_157_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_157_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= stage_v_157_1;
  chk_sum_2 ^= stage_v_157_2;
  int stage_v_158_1 = ((st_var_2_1.buffer[2] * 2) + 481) & 63;
  int stage_v_158_2 = ((st_var_2_2.buffer[2] * 2) + 481) & 63;
  if (stage_v_158_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_158_1) - 5) & 255;
    if (stage_v_158_1 > 50)
    {
      chk_sum_1 ^= stage_v_158_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_158_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_158_2) - 5) & 255;
    if (stage_v_158_2 > 50)
    {
      chk_sum_2 ^= stage_v_158_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 160) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 160) & 15;
  int stage_v_159_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_159_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  chk_sum_1 ^= stage_v_159_1;
  chk_sum_2 ^= stage_v_159_2;
  int stage_v_160_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (165 & 31);
  int stage_v_160_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (165 & 31);
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= (stage_v_160_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_160_2 << 1) & 127;
  int stage_v_161_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_161_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_162_1 = ((st_var_0_1.buffer[0] * 2) + 493) & 63;
  int stage_v_162_2 = ((st_var_0_2.buffer[0] * 2) + 493) & 63;
  if (stage_v_162_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_162_1) - 5) & 255;
    if (stage_v_162_1 > 35)
    {
      chk_sum_1 ^= stage_v_162_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_162_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_162_2) - 5) & 255;
    if (stage_v_162_2 > 35)
    {
      chk_sum_2 ^= stage_v_162_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
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
  int stage_v_166_1 = ((st_var_1_1.buffer[1] * 2) + 505) & 63;
  int stage_v_166_2 = ((st_var_1_2.buffer[1] * 2) + 505) & 63;
  if (stage_v_166_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_166_1) - 5) & 255;
    if (stage_v_166_1 > 53)
    {
      chk_sum_1 ^= stage_v_166_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_166_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_166_2) - 5) & 255;
    if (stage_v_166_2 > 53)
    {
      chk_sum_2 ^= stage_v_166_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_167_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_167_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_168_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_168_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_168_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_168_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_169_1 = (st_var_1_1.buffer[0] ^ 172) & 3;
  int stage_v_169_2 = (st_var_1_2.buffer[0] ^ 172) & 3;
  switch (stage_v_169_1)
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

  switch (stage_v_169_2)
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

  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_170_1 = ((stage_v_170_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_170_2 = ((stage_v_170_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_171_1 = ((stage_v_171_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_171_2 = ((stage_v_171_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 173) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 173) & 15;
  int stage_v_172_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_172_2 = (st_var_1_2.buffer[1] * 3) & 63;
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 175) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 175) & 15;
  int stage_v_174_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_174_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  chk_sum_1 ^= stage_v_174_1;
  chk_sum_2 ^= stage_v_174_2;
  int stage_v_175_1 = table_1[3];
  int stage_v_175_2 = table_2[3];
  table_1[3] = (table_1[0] + 351) & 63;
  table_2[3] = (table_2[0] + 351) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((st_var_2_1.buffer[2] * 2) + 535) & 63;
  int stage_v_176_2 = ((st_var_2_2.buffer[2] * 2) + 535) & 63;
  if (stage_v_176_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_176_1) - 5) & 255;
    if (stage_v_176_1 > 25)
    {
      chk_sum_1 ^= stage_v_176_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_176_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_176_2) - 5) & 255;
    if (stage_v_176_2 > 25)
    {
      chk_sum_2 ^= stage_v_176_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 178) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 178) & 15;
  int stage_v_177_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_177_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  chk_sum_1 ^= stage_v_177_1;
  chk_sum_2 ^= stage_v_177_2;
  int stage_v_178_1 = ((st_var_1_1.buffer[1] * 2) + 541) & 63;
  int stage_v_178_2 = ((st_var_1_2.buffer[1] * 2) + 541) & 63;
  if (stage_v_178_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_178_1) - 5) & 255;
    if (stage_v_178_1 > 34)
    {
      chk_sum_1 ^= stage_v_178_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_178_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_178_2) - 5) & 255;
    if (stage_v_178_2 > 34)
    {
      chk_sum_2 ^= stage_v_178_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_179_1 = ((st_var_2_1.buffer[2] * 2) + 544) & 63;
  int stage_v_179_2 = ((st_var_2_2.buffer[2] * 2) + 544) & 63;
  if (stage_v_179_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_179_1) - 5) & 255;
    if (stage_v_179_1 > 53)
    {
      chk_sum_1 ^= stage_v_179_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_179_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_179_2) - 5) & 255;
    if (stage_v_179_2 > 53)
    {
      chk_sum_2 ^= stage_v_179_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_180_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_180_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_180_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_180_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_181_1 = table_1[1];
  int stage_v_181_2 = table_2[1];
  table_1[1] = (table_1[2] + 363) & 63;
  table_2[1] = (table_2[2] + 363) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((st_var_2_1.buffer[2] * 2) + 553) & 63;
  int stage_v_182_2 = ((st_var_2_2.buffer[2] * 2) + 553) & 63;
  if (stage_v_182_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_182_1) - 5) & 255;
    if (stage_v_182_1 > 31)
    {
      chk_sum_1 ^= stage_v_182_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_182_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_182_2) - 5) & 255;
    if (stage_v_182_2 > 31)
    {
      chk_sum_2 ^= stage_v_182_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_183_1 = ((st_var_0_1.buffer[0] * 2) + 556) & 63;
  int stage_v_183_2 = ((st_var_0_2.buffer[0] * 2) + 556) & 63;
  if (stage_v_183_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_183_1) - 5) & 255;
    if (stage_v_183_1 > 28)
    {
      chk_sum_1 ^= stage_v_183_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_183_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_183_2) - 5) & 255;
    if (stage_v_183_2 > 28)
    {
      chk_sum_2 ^= stage_v_183_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_184_1 = 0;
  int stage_v_184_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_184_1 = ((stage_v_184_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_184_2 = ((stage_v_184_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 186) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 186) & 15;
  int stage_v_185_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_185_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  chk_sum_1 ^= stage_v_185_1;
  chk_sum_2 ^= stage_v_185_2;
  int stage_v_186_1 = 0;
  int stage_v_186_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_186_1 = ((stage_v_186_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_186_2 = ((stage_v_186_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = table_1[3];
  int stage_v_187_2 = table_2[3];
  table_1[3] = (table_1[0] + 375) & 63;
  table_2[3] = (table_2[0] + 375) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (st_var_2_1.buffer[0] ^ 191) & 3;
  int stage_v_188_2 = (st_var_2_2.buffer[0] ^ 191) & 3;
  switch (stage_v_188_1)
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

  switch (stage_v_188_2)
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

  int stage_v_189_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_189_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_189_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_189_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_190_1 = 0;
  int stage_v_190_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_190_1 = ((stage_v_190_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_190_2 = ((stage_v_190_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = 0;
  int stage_v_191_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_191_1 = ((stage_v_191_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_191_2 = ((stage_v_191_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = table_1[0];
  int stage_v_192_2 = table_2[0];
  table_1[0] = (table_1[1] + 385) & 63;
  table_2[0] = (table_2[1] + 385) & 63;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = 0;
  int stage_v_193_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_193_1 = ((stage_v_193_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_193_2 = ((stage_v_193_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_194_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_194_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_194_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_195_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (200 & 31);
  int stage_v_195_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (200 & 31);
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  chk_sum_1 ^= (stage_v_195_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_195_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 197) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 197) & 15;
  int stage_v_196_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_196_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  chk_sum_1 ^= stage_v_196_1;
  chk_sum_2 ^= stage_v_196_2;
  int stage_v_197_1 = table_1[1];
  int stage_v_197_2 = table_2[1];
  table_1[1] = (table_1[2] + 395) & 63;
  table_2[1] = (table_2[2] + 395) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_198_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_198_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_198_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 200) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 200) & 15;
  int stage_v_199_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_199_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  chk_sum_1 ^= stage_v_199_1;
  chk_sum_2 ^= stage_v_199_2;
  int stage_v_200_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (205 & 31);
  int stage_v_200_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (205 & 31);
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  chk_sum_1 ^= (stage_v_200_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_200_2 << 1) & 127;
  int stage_v_201_1 = ((st_var_0_1.buffer[0] * 2) + 610) & 63;
  int stage_v_201_2 = ((st_var_0_2.buffer[0] * 2) + 610) & 63;
  if (stage_v_201_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_201_1) - 5) & 255;
    if (stage_v_201_1 > 44)
    {
      chk_sum_1 ^= stage_v_201_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_201_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_201_2) - 5) & 255;
    if (stage_v_201_2 > 44)
    {
      chk_sum_2 ^= stage_v_201_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_202_1 = (st_var_1_1.buffer[0] ^ 205) & 3;
  int stage_v_202_2 = (st_var_1_2.buffer[0] ^ 205) & 3;
  switch (stage_v_202_1)
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

  switch (stage_v_202_2)
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

  int stage_v_203_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_203_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_203_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_203_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_204_1 = 0;
  int stage_v_204_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_204_1 = ((stage_v_204_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_204_2 = ((stage_v_204_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (st_var_1_1.buffer[0] ^ 208) & 3;
  int stage_v_205_2 = (st_var_1_2.buffer[0] ^ 208) & 3;
  switch (stage_v_205_1)
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

  switch (stage_v_205_2)
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

  int stage_v_206_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_206_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_206_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_206_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_207_1 = table_1[3];
  int stage_v_207_2 = table_2[3];
  table_1[3] = (table_1[0] + 415) & 63;
  table_2[3] = (table_2[0] + 415) & 63;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 209) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 209) & 15;
  int stage_v_208_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_208_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  chk_sum_1 ^= stage_v_208_1;
  chk_sum_2 ^= stage_v_208_2;
  int stage_v_209_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (214 & 31);
  int stage_v_209_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (214 & 31);
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  chk_sum_1 ^= (stage_v_209_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_209_2 << 1) & 127;
  int stage_v_210_1 = ((st_var_0_1.buffer[0] * 2) + 637) & 63;
  int stage_v_210_2 = ((st_var_0_2.buffer[0] * 2) + 637) & 63;
  if (stage_v_210_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_210_1) - 5) & 255;
    if (stage_v_210_1 > 52)
    {
      chk_sum_1 ^= stage_v_210_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_210_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_210_2) - 5) & 255;
    if (stage_v_210_2 > 52)
    {
      chk_sum_2 ^= stage_v_210_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_211_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_211_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_211_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_211_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_212_1 = 0;
  int stage_v_212_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_212_1 = ((stage_v_212_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_212_2 = ((stage_v_212_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((st_var_0_1.buffer[0] * 2) + 646) & 63;
  int stage_v_213_2 = ((st_var_0_2.buffer[0] * 2) + 646) & 63;
  if (stage_v_213_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_213_1) - 5) & 255;
    if (stage_v_213_1 > 48)
    {
      chk_sum_1 ^= stage_v_213_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_213_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_213_2) - 5) & 255;
    if (stage_v_213_2 > 48)
    {
      chk_sum_2 ^= stage_v_213_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_214_1 = 0;
  int stage_v_214_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_214_1 = ((stage_v_214_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_214_2 = ((stage_v_214_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (220 & 31);
  int stage_v_215_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (220 & 31);
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  chk_sum_1 ^= (stage_v_215_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_215_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 217) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 217) & 15;
  int stage_v_216_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_216_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  chk_sum_1 ^= stage_v_216_1;
  chk_sum_2 ^= stage_v_216_2;
  int stage_v_217_1 = table_1[1];
  int stage_v_217_2 = table_2[1];
  table_1[1] = (table_1[2] + 435) & 63;
  table_2[1] = (table_2[2] + 435) & 63;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (223 & 31);
  int stage_v_218_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (223 & 31);
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  chk_sum_1 ^= (stage_v_218_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_218_2 << 1) & 127;
  int stage_v_219_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_219_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_219_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_219_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_220_1 = (st_var_1_1.buffer[0] ^ 223) & 3;
  int stage_v_220_2 = (st_var_1_2.buffer[0] ^ 223) & 3;
  switch (stage_v_220_1)
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

  switch (stage_v_220_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 222) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 222) & 15;
  int stage_v_221_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_221_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  chk_sum_1 ^= stage_v_221_1;
  chk_sum_2 ^= stage_v_221_2;
  int stage_v_222_1 = table_1[2];
  int stage_v_222_2 = table_2[2];
  table_1[2] = (table_1[3] + 445) & 63;
  table_2[2] = (table_2[3] + 445) & 63;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = 0;
  int stage_v_223_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_223_1 = ((stage_v_223_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_223_2 = ((stage_v_223_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_224_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_224_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_224_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_225_1 = 0;
  int stage_v_225_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_225_1 = ((stage_v_225_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_225_2 = ((stage_v_225_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = table_1[2];
  int stage_v_226_2 = table_2[2];
  table_1[2] = (table_1[3] + 453) & 63;
  table_2[2] = (table_2[3] + 453) & 63;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 228) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 228) & 15;
  int stage_v_227_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_227_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  chk_sum_1 ^= stage_v_227_1;
  chk_sum_2 ^= stage_v_227_2;
  int stage_v_228_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_228_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_228_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_228_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_229_1 = (st_var_1_1.buffer[0] ^ 232) & 3;
  int stage_v_229_2 = (st_var_1_2.buffer[0] ^ 232) & 3;
  switch (stage_v_229_1)
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

  switch (stage_v_229_2)
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

  int stage_v_230_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (235 & 31);
  int stage_v_230_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (235 & 31);
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  chk_sum_1 ^= (stage_v_230_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_230_2 << 1) & 127;
  int stage_v_231_1 = ((st_var_0_1.buffer[0] * 2) + 700) & 63;
  int stage_v_231_2 = ((st_var_0_2.buffer[0] * 2) + 700) & 63;
  if (stage_v_231_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_231_1) - 5) & 255;
    if (stage_v_231_1 > 49)
    {
      chk_sum_1 ^= stage_v_231_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_231_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_231_2) - 5) & 255;
    if (stage_v_231_2 > 49)
    {
      chk_sum_2 ^= stage_v_231_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_232_1 = ((st_var_1_1.buffer[1] * 2) + 703) & 63;
  int stage_v_232_2 = ((st_var_1_2.buffer[1] * 2) + 703) & 63;
  if (stage_v_232_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_232_1) - 5) & 255;
    if (stage_v_232_1 > 43)
    {
      chk_sum_1 ^= stage_v_232_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_232_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_232_2) - 5) & 255;
    if (stage_v_232_2 > 43)
    {
      chk_sum_2 ^= stage_v_232_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_233_1 = 0;
  int stage_v_233_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_233_1 = ((stage_v_233_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_233_2 = ((stage_v_233_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (239 & 31);
  int stage_v_234_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (239 & 31);
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  chk_sum_1 ^= (stage_v_234_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_234_2 << 1) & 127;
  int stage_v_235_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (240 & 31);
  int stage_v_235_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (240 & 31);
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  chk_sum_1 ^= (stage_v_235_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_235_2 << 1) & 127;
  int stage_v_236_1 = 0;
  int stage_v_236_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_236_1 = ((stage_v_236_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_236_2 = ((stage_v_236_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 238) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 238) & 15;
  int stage_v_237_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_237_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  chk_sum_1 ^= stage_v_237_1;
  chk_sum_2 ^= stage_v_237_2;
  int stage_v_238_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (243 & 31);
  int stage_v_238_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (243 & 31);
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  chk_sum_1 ^= (stage_v_238_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_238_2 << 1) & 127;
  int stage_v_239_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_239_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_239_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_239_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_240_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_240_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_240_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_240_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 242) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 242) & 15;
  int stage_v_241_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_241_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  chk_sum_1 ^= stage_v_241_1;
  chk_sum_2 ^= stage_v_241_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 243) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 243) & 15;
  int stage_v_242_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_242_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  chk_sum_1 ^= stage_v_242_1;
  chk_sum_2 ^= stage_v_242_2;
  int stage_v_243_1 = 0;
  int stage_v_243_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_243_1 = ((stage_v_243_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_243_2 = ((stage_v_243_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((st_var_1_1.buffer[1] * 2) + 739) & 63;
  int stage_v_244_2 = ((st_var_1_2.buffer[1] * 2) + 739) & 63;
  if (stage_v_244_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_244_1) - 5) & 255;
    if (stage_v_244_1 > 36)
    {
      chk_sum_1 ^= stage_v_244_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_244_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_244_2) - 5) & 255;
    if (stage_v_244_2 > 36)
    {
      chk_sum_2 ^= stage_v_244_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_245_1 = (st_var_2_1.buffer[0] ^ 248) & 3;
  int stage_v_245_2 = (st_var_2_2.buffer[0] ^ 248) & 3;
  switch (stage_v_245_1)
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

  switch (stage_v_245_2)
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

  int stage_v_246_1 = ((st_var_0_1.buffer[0] * 2) + 745) & 63;
  int stage_v_246_2 = ((st_var_0_2.buffer[0] * 2) + 745) & 63;
  if (stage_v_246_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_246_1) - 5) & 255;
    if (stage_v_246_1 > 27)
    {
      chk_sum_1 ^= stage_v_246_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_246_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_246_2) - 5) & 255;
    if (stage_v_246_2 > 27)
    {
      chk_sum_2 ^= stage_v_246_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int dead_sec_0_1 = (sec_r000741_0_1 ^ sec_r000741_0_1) * 0;
  int dead_sec_0_2 = (sec_r000741_0_2 ^ sec_r000741_0_2) * 0;
  int dead_sec_1_1 = (sec_r000741_1_1 ^ sec_r000741_1_1) * 0;
  int dead_sec_1_2 = (sec_r000741_1_2 ^ sec_r000741_1_2) * 0;
  int dead_sec_2_1 = (sec_r000741_2_1 ^ sec_r000741_2_1) * 0;
  int dead_sec_2_2 = (sec_r000741_2_2 ^ sec_r000741_2_2) * 0;
  int dead_sec_3_1 = (sec_r000741_3_1 ^ sec_r000741_3_1) * 0;
  int dead_sec_3_2 = (sec_r000741_3_2 ^ sec_r000741_3_2) * 0;
  out_sink_1 = ((((out_sink_1 + dead_sec_0_1) + dead_sec_1_1) + dead_sec_2_1) + dead_sec_3_1) & 255;
  out_sink_2 = ((((out_sink_2 + dead_sec_0_2) + dead_sec_1_2) + dead_sec_2_2) + dead_sec_3_2) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (chk_sum_1 ^ 0x55) & 127;
  g_telemetry_2 = (chk_sum_2 ^ 0x55) & 127;
  __CPROVER_assume(sec_r000741_20_1 != sec_r000741_20_2);
  __CPROVER_assume(sec_r000741_16_1 != sec_r000741_16_2);
  __CPROVER_assume(pub_r000741_16_1 == pub_r000741_16_2);
  __CPROVER_assume(sec_r000741_3_1 != sec_r000741_3_2);
  __CPROVER_assume(sec_r000741_17_1 != sec_r000741_17_2);
  __CPROVER_assume(pub_r000741_6_1 == pub_r000741_6_2);
  __CPROVER_assume(pub_r000741_19_1 == pub_r000741_19_2);
  __CPROVER_assume(sec_r000741_2_1 != sec_r000741_2_2);
  __CPROVER_assume(sec_r000741_4_1 != sec_r000741_4_2);
  __CPROVER_assume(pub_r000741_10_1 == pub_r000741_10_2);
  __CPROVER_assume(sec_r000741_10_1 != sec_r000741_10_2);
  __CPROVER_assume(sec_r000741_19_1 != sec_r000741_19_2);
  __CPROVER_assume(sec_r000741_15_1 != sec_r000741_15_2);
  __CPROVER_assume(pub_r000741_5_1 == pub_r000741_5_2);
  __CPROVER_assume(sec_r000741_12_1 != sec_r000741_12_2);
  __CPROVER_assume(pub_r000741_7_1 == pub_r000741_7_2);
  __CPROVER_assume(sec_r000741_18_1 != sec_r000741_18_2);
  __CPROVER_assume(pub_r000741_9_1 == pub_r000741_9_2);
  __CPROVER_assume(pub_r000741_12_1 == pub_r000741_12_2);
  __CPROVER_assume(sec_r000741_9_1 != sec_r000741_9_2);
  __CPROVER_assume(pub_r000741_8_1 == pub_r000741_8_2);
  __CPROVER_assume(pub_r000741_18_1 == pub_r000741_18_2);
  __CPROVER_assume(sec_r000741_5_1 != sec_r000741_5_2);
  __CPROVER_assume(pub_r000741_0_1 == pub_r000741_0_2);
  __CPROVER_assume(sec_r000741_1_1 != sec_r000741_1_2);
  __CPROVER_assume(sec_r000741_13_1 != sec_r000741_13_2);
  __CPROVER_assume(sec_r000741_6_1 != sec_r000741_6_2);
  __CPROVER_assume(pub_r000741_15_1 == pub_r000741_15_2);
  __CPROVER_assume(sec_r000741_0_1 != sec_r000741_0_2);
  __CPROVER_assume(pub_r000741_4_1 == pub_r000741_4_2);
  __CPROVER_assume(pub_r000741_2_1 == pub_r000741_2_2);
  __CPROVER_assume(pub_r000741_11_1 == pub_r000741_11_2);
  __CPROVER_assume(pub_r000741_20_1 == pub_r000741_20_2);
  __CPROVER_assume(sec_r000741_7_1 != sec_r000741_7_2);
  __CPROVER_assume(sec_r000741_11_1 != sec_r000741_11_2);
  __CPROVER_assume(sec_r000741_14_1 != sec_r000741_14_2);
  __CPROVER_assume(pub_r000741_1_1 == pub_r000741_1_2);
  __CPROVER_assume(sec_r000741_8_1 != sec_r000741_8_2);
  __CPROVER_assume(sec_r000741_21_1 != sec_r000741_21_2);
  __CPROVER_assume(pub_r000741_3_1 == pub_r000741_3_2);
  __CPROVER_assume(pub_r000741_13_1 == pub_r000741_13_2);
  __CPROVER_assume(pub_r000741_14_1 == pub_r000741_14_2);
  __CPROVER_assume(pub_r000741_17_1 == pub_r000741_17_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.nonce == st_var_2_2.nonce);
  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.iv == st_var_2_2.iv);
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
  assert(dead_sec_0_1 == dead_sec_0_2);
  assert(dead_sec_1_1 == dead_sec_1_2);
  assert(dead_sec_2_1 == dead_sec_2_2);
  assert(dead_sec_3_1 == dead_sec_3_2);
}


