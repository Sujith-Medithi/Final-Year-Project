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
struct DeviceConfig_R001070_7013_0
{
  unsigned char parity;
  int baud_rate;
  int id;
  int port;
  int buffer[3];
};
struct AudioFrame_R001070_7013_1
{
  int sample_rate;
  short rms;
  short envelope;
  unsigned char peak;
  int buffer[3];
};
union RegisterBank_R001070_7013_0
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
void fn_R001070_7013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st_1 = {0};
  struct DeviceConfig_R001070_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_67_1 = local_arr_1[aux_1 % 3];
  int tally_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_67_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_22_1 > 16)
  {
    acc_1 = ((acc_1 + (phase_22_1 * 2)) + 5) & 127;
    aux_1 ^= phase_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_22_2 > 16)
  {
    acc_2 = ((acc_2 + (phase_22_2 * 2)) + 5) & 127;
    aux_2 ^= phase_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_22_1)
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

  switch (sample_22_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_67_1 == tally_67_2);
  assert(phase_22_1 == phase_22_2);
  assert(sample_22_1 == sample_22_2);
}

int fn_R001070_7013_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int tally_67 = local_arr[aux % 3];
  acc = (acc + (tally_67 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_22 > 16)
  {
    acc = ((acc + (phase_22 * 2)) + 5) & 127;
    aux ^= phase_22 & 15;
  }
  else
  {
    acc = ((acc - phase_22) + 11) & 127;
    aux += 3;
  }
  int sample_22 = (aux + st.buffer[1]) & 3;
  switch (sample_22)
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

void fn_R001070_7013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_14_1 = local_arr_1[aux_1 % 3];
  int stride_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_14_2 * 2)) & 127;
  int scale_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_54_1 > 15)
  {
    acc_1 = ((acc_1 + (scale_54_1 * 2)) + 5) & 127;
    aux_1 ^= scale_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_54_2 > 15)
  {
    acc_2 = ((acc_2 + (scale_54_2 * 2)) + 5) & 127;
    aux_2 ^= scale_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_54_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_14_1 == stride_14_2);
  assert(scale_54_1 == scale_54_2);
}

int fn_R001070_7013_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int stride_14 = local_arr[aux % 3];
  acc = (acc + (stride_14 * 2)) & 127;
  int scale_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_54 > 15)
  {
    acc = ((acc + (scale_54 * 2)) + 5) & 127;
    aux ^= scale_54 & 15;
  }
  else
  {
    acc = ((acc - scale_54) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001070_7013_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st_1 = {0};
  struct DeviceConfig_R001070_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int mask_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_77_1 > 45)
  {
    acc_1 = ((acc_1 + (mask_77_1 * 2)) + 5) & 127;
    aux_1 ^= mask_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_77_2 > 45)
  {
    acc_2 = ((acc_2 + (mask_77_2 * 2)) + 5) & 127;
    aux_2 ^= mask_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_64_1 = 0;
  int tally_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_64_1 = ((tally_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_64_2 = ((tally_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_64_1) & 127;
    acc_2 = (acc_2 + tally_64_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_86_1 = local_arr_1[aux_1 % 3];
  int sample_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_77_1 == mask_77_2);
  assert(tally_64_1 == tally_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_86_1 == sample_86_2);
}

int fn_R001070_7013_2(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int mask_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_77 > 45)
  {
    acc = ((acc + (mask_77 * 2)) + 5) & 127;
    aux ^= mask_77 & 15;
  }
  else
  {
    acc = ((acc - mask_77) + 11) & 127;
    aux += 3;
  }
  int tally_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_64 = ((tally_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_64) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_86 = local_arr[aux % 3];
  acc = (acc + (sample_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001070_7013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int stride_51_1 = 0;
  int stride_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_51_1 = ((stride_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_51_2 = ((stride_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_51_1) & 127;
    acc_2 = (acc_2 + stride_51_2) & 127;
  }

  int stride_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_48_1 > 13)
  {
    acc_1 = ((acc_1 + (stride_48_1 * 2)) + 5) & 127;
    aux_1 ^= stride_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_48_2 > 13)
  {
    acc_2 = ((acc_2 + (stride_48_2 * 2)) + 5) & 127;
    aux_2 ^= stride_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_38_1)
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

  switch (segment_38_2)
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

  int checksum_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_11_1) & 63;
  aux_2 = (aux_2 + checksum_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_51_1 == stride_51_2);
  assert(stride_48_1 == stride_48_2);
  assert(segment_38_1 == segment_38_2);
  assert(checksum_11_1 == checksum_11_2);
}

int fn_R001070_7013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int stride_51 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_51 = ((stride_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_51) & 127;
  }

  int stride_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_48 > 13)
  {
    acc = ((acc + (stride_48 * 2)) + 5) & 127;
    aux ^= stride_48 & 15;
  }
  else
  {
    acc = ((acc - stride_48) + 11) & 127;
    aux += 3;
  }
  int segment_38 = (aux + st.buffer[1]) & 3;
  switch (segment_38)
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

  int checksum_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_11) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001070_7013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st_1 = {0};
  struct DeviceConfig_R001070_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_75_1 = local_arr_1[aux_1 % 3];
  int stride_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_75_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_75_1 == stride_75_2);
}

int fn_R001070_7013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int stride_75 = local_arr[aux % 3];
  acc = (acc + (stride_75 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001070_7013_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tracker_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_59_1)
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

  switch (tracker_59_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_49_1 = local_arr_1[aux_1 % 3];
  int tally_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_49_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_59_1 == tracker_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_49_1 == tally_49_2);
}

int fn_R001070_7013_5(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tracker_59 = (aux + st.buffer[1]) & 3;
  switch (tracker_59)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_49 = local_arr[aux % 3];
  acc = (acc + (tally_49 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001070_7013_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st_1 = {0};
  struct DeviceConfig_R001070_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int parity_86_1 = 0;
  int parity_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_86_1 = ((parity_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_86_2 = ((parity_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_86_1) & 127;
    acc_2 = (acc_2 + parity_86_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_81_1 = local_arr_1[aux_1 % 3];
  int metric_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_81_2 * 2)) & 127;
  int tally_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_95_1)
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

  switch (tally_95_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_86_1 == parity_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_81_1 == metric_81_2);
  assert(tally_95_1 == tally_95_2);
}

int fn_R001070_7013_6(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int parity_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_86 = ((parity_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_86) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int metric_81 = local_arr[aux % 3];
  acc = (acc + (metric_81 * 2)) & 127;
  int tally_95 = (aux + st.buffer[1]) & 3;
  switch (tally_95)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001070_7013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int pivot_91_1 = 0;
  int pivot_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_91_1 = ((pivot_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_91_2 = ((pivot_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_91_1) & 127;
    acc_2 = (acc_2 + pivot_91_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_72_1 = local_arr_1[aux_1 % 3];
  int offset_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_72_2 * 2)) & 127;
  int phase_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_57_1)
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

  switch (phase_57_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_91_1 == pivot_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_72_1 == offset_72_2);
  assert(phase_57_1 == phase_57_2);
}

int fn_R001070_7013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int pivot_91 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_91 = ((pivot_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_91) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_72 = local_arr[aux % 3];
  acc = (acc + (offset_72 * 2)) & 127;
  int phase_57 = (aux + st.buffer[1]) & 3;
  switch (phase_57)
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

void fn_R001070_7013_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int index_reg_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_44_1) & 63;
  aux_2 = (aux_2 + index_reg_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_23_1)
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

  switch (tally_23_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_44_1 == index_reg_44_2);
  assert(tally_23_1 == tally_23_2);
}

int fn_R001070_7013_8(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int index_reg_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_44) & 63;
  acc ^= aux;
  int tally_23 = (aux + st.buffer[1]) & 3;
  switch (tally_23)
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

void fn_R001070_7013_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int weight_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_76_1 > 26)
  {
    acc_1 = ((acc_1 + (weight_76_1 * 2)) + 5) & 127;
    aux_1 ^= weight_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_76_2 > 26)
  {
    acc_2 = ((acc_2 + (weight_76_2 * 2)) + 5) & 127;
    aux_2 ^= weight_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_69_1 = local_arr_1[aux_1 % 3];
  int mask_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_69_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_76_1 == weight_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_69_1 == mask_69_2);
}

int fn_R001070_7013_9(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int weight_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_76 > 26)
  {
    acc = ((acc + (weight_76 * 2)) + 5) & 127;
    aux ^= weight_76 & 15;
  }
  else
  {
    acc = ((acc - weight_76) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_69 = local_arr[aux % 3];
  acc = (acc + (mask_69 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001070_7013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st_1 = {0};
  struct DeviceConfig_R001070_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_54_1)
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

  switch (factor_54_2)
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

  int scale_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_37_1) & 63;
  aux_2 = (aux_2 + scale_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_40_1 > 25)
  {
    acc_1 = ((acc_1 + (parity_40_1 * 2)) + 5) & 127;
    aux_1 ^= parity_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_40_2 > 25)
  {
    acc_2 = ((acc_2 + (parity_40_2 * 2)) + 5) & 127;
    aux_2 ^= parity_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_54_1 == factor_54_2);
  assert(scale_37_1 == scale_37_2);
  assert(parity_40_1 == parity_40_2);
}

int fn_R001070_7013_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_54 = (aux + st.buffer[1]) & 3;
  switch (factor_54)
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

  int scale_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_37) & 63;
  acc ^= aux;
  int parity_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_40 > 25)
  {
    acc = ((acc + (parity_40 * 2)) + 5) & 127;
    aux ^= parity_40 & 15;
  }
  else
  {
    acc = ((acc - parity_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001070_7013_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int mask_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_44_1) & 63;
  aux_2 = (aux_2 + mask_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_20_1 > 18)
  {
    acc_1 = ((acc_1 + (pivot_20_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_20_2 > 18)
  {
    acc_2 = ((acc_2 + (pivot_20_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_20_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_44_1 == mask_44_2);
  assert(pivot_20_1 == pivot_20_2);
}

int fn_R001070_7013_11(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int mask_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_44) & 63;
  acc ^= aux;
  int pivot_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_20 > 18)
  {
    acc = ((acc + (pivot_20 * 2)) + 5) & 127;
    aux ^= pivot_20 & 15;
  }
  else
  {
    acc = ((acc - pivot_20) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001070_7013_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_50_1 = local_arr_1[aux_1 % 3];
  int scale_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_50_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_50_1 == scale_50_2);
}

int fn_R001070_7013_12(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int scale_50 = local_arr[aux % 3];
  acc = (acc + (scale_50 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001070_7013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st_1 = {0};
  struct DeviceConfig_R001070_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int sample_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_37_1)
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

  switch (sample_37_2)
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
  int margin_23_1 = local_arr_1[aux_1 % 3];
  int margin_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_23_2 * 2)) & 127;
  int segment_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_54_1 > 42)
  {
    acc_1 = ((acc_1 + (segment_54_1 * 2)) + 5) & 127;
    aux_1 ^= segment_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_54_2 > 42)
  {
    acc_2 = ((acc_2 + (segment_54_2 * 2)) + 5) & 127;
    aux_2 ^= segment_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_54_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_37_1 == sample_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_23_1 == margin_23_2);
  assert(segment_54_1 == segment_54_2);
}

int fn_R001070_7013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int sample_37 = (aux + st.buffer[1]) & 3;
  switch (sample_37)
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
  int margin_23 = local_arr[aux % 3];
  acc = (acc + (margin_23 * 2)) & 127;
  int segment_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_54 > 42)
  {
    acc = ((acc + (segment_54 * 2)) + 5) & 127;
    aux ^= segment_54 & 15;
  }
  else
  {
    acc = ((acc - segment_54) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001070_7013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quotient_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_39_1)
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

  switch (quotient_39_2)
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

  int stride_17_1 = 0;
  int stride_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_17_1 = ((stride_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_17_2 = ((stride_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_17_1) & 127;
    acc_2 = (acc_2 + stride_17_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_62_1 = local_arr_1[aux_1 % 3];
  int threshold_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_62_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_39_1 == quotient_39_2);
  assert(stride_17_1 == stride_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_62_1 == threshold_62_2);
}

int fn_R001070_7013_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quotient_39 = (aux + st.buffer[1]) & 3;
  switch (quotient_39)
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

  int stride_17 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_17 = ((stride_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_17) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int threshold_62 = local_arr[aux % 3];
  acc = (acc + (threshold_62 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001070_7013_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_65_1 = local_arr_1[aux_1 % 3];
  int mask_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_65_2 * 2)) & 127;
  int stride_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_66_1) & 63;
  aux_2 = (aux_2 + stride_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_15_1 = 0;
  int damping_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_15_1 = ((damping_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_15_2 = ((damping_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_15_1) & 127;
    acc_2 = (acc_2 + damping_15_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_65_1 == mask_65_2);
  assert(stride_66_1 == stride_66_2);
  assert(damping_15_1 == damping_15_2);
}

int fn_R001070_7013_15(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int mask_65 = local_arr[aux % 3];
  acc = (acc + (mask_65 * 2)) & 127;
  int stride_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_66) & 63;
  acc ^= aux;
  int damping_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_15 = ((damping_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_15) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001070_7013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st_1 = {0};
  struct DeviceConfig_R001070_7013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int metric_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_61_1)
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

  switch (metric_61_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_61_1 == metric_61_2);
}

int fn_R001070_7013_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001070_7013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int metric_61 = (aux + st.buffer[1]) & 3;
  switch (metric_61)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001070_7013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int delta_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_78_1)
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

  switch (delta_78_2)
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

  int accumulator_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_84_1) & 63;
  aux_2 = (aux_2 + accumulator_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_78_1 == delta_78_2);
  assert(accumulator_84_1 == accumulator_84_2);
}

int fn_R001070_7013_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int delta_78 = (aux + st.buffer[1]) & 3;
  switch (delta_78)
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

  int accumulator_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001070_7013_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st_1 = {0};
  struct AudioFrame_R001070_7013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tally_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_37_1 > 32)
  {
    acc_1 = ((acc_1 + (tally_37_1 * 2)) + 5) & 127;
    aux_1 ^= tally_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_37_2 > 32)
  {
    acc_2 = ((acc_2 + (tally_37_2 * 2)) + 5) & 127;
    aux_2 ^= tally_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_74_1 = local_arr_1[aux_1 % 3];
  int bound_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_74_2 * 2)) & 127;
  int delta_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_46_1) & 63;
  aux_2 = (aux_2 + delta_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_37_1 == tally_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_74_1 == bound_74_2);
  assert(delta_46_1 == delta_46_2);
}

int fn_R001070_7013_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001070_7013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tally_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_37 > 32)
  {
    acc = ((acc + (tally_37 * 2)) + 5) & 127;
    aux ^= tally_37 & 15;
  }
  else
  {
    acc = ((acc - tally_37) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_74 = local_arr[aux % 3];
  acc = (acc + (bound_74 * 2)) & 127;
  int delta_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_46) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001070_0_1;
  int sec_r001070_0_2;
  int sec_r001070_1_1;
  int sec_r001070_1_2;
  int sec_r001070_2_1;
  int sec_r001070_2_2;
  int sec_r001070_3_1;
  int sec_r001070_3_2;
  int sec_r001070_4_1;
  int sec_r001070_4_2;
  int sec_r001070_5_1;
  int sec_r001070_5_2;
  int sec_r001070_6_1;
  int sec_r001070_6_2;
  int sec_r001070_7_1;
  int sec_r001070_7_2;
  int sec_r001070_8_1;
  int sec_r001070_8_2;
  int sec_r001070_9_1;
  int sec_r001070_9_2;
  int sec_r001070_10_1;
  int sec_r001070_10_2;
  int sec_r001070_11_1;
  int sec_r001070_11_2;
  int sec_r001070_12_1;
  int sec_r001070_12_2;
  int sec_r001070_13_1;
  int sec_r001070_13_2;
  int sec_r001070_14_1;
  int sec_r001070_14_2;
  int sec_r001070_15_1;
  int sec_r001070_15_2;
  int sec_r001070_16_1;
  int sec_r001070_16_2;
  int sec_r001070_17_1;
  int sec_r001070_17_2;
  int sec_r001070_18_1;
  int sec_r001070_18_2;
  int sec_r001070_19_1;
  int sec_r001070_19_2;
  int sec_r001070_20_1;
  int sec_r001070_20_2;
  int sec_r001070_21_1;
  int sec_r001070_21_2;
  int pub_r001070_0_1;
  int pub_r001070_0_2;
  int pub_r001070_1_1;
  int pub_r001070_1_2;
  int pub_r001070_2_1;
  int pub_r001070_2_2;
  int pub_r001070_3_1;
  int pub_r001070_3_2;
  int pub_r001070_4_1;
  int pub_r001070_4_2;
  int pub_r001070_5_1;
  int pub_r001070_5_2;
  int pub_r001070_6_1;
  int pub_r001070_6_2;
  int pub_r001070_7_1;
  int pub_r001070_7_2;
  int pub_r001070_8_1;
  int pub_r001070_8_2;
  int pub_r001070_9_1;
  int pub_r001070_9_2;
  int pub_r001070_10_1;
  int pub_r001070_10_2;
  int pub_r001070_11_1;
  int pub_r001070_11_2;
  int pub_r001070_12_1;
  int pub_r001070_12_2;
  int pub_r001070_13_1;
  int pub_r001070_13_2;
  int pub_r001070_14_1;
  int pub_r001070_14_2;
  int pub_r001070_15_1;
  int pub_r001070_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001070_0_1 >= (-100)) && (pub_r001070_0_1 <= 100));
  __CPROVER_assume((pub_r001070_0_2 >= (-100)) && (pub_r001070_0_2 <= 100));
  __CPROVER_assume((pub_r001070_1_1 >= (-100)) && (pub_r001070_1_1 <= 100));
  __CPROVER_assume((pub_r001070_1_2 >= (-100)) && (pub_r001070_1_2 <= 100));
  __CPROVER_assume((pub_r001070_2_1 >= (-100)) && (pub_r001070_2_1 <= 100));
  __CPROVER_assume((pub_r001070_2_2 >= (-100)) && (pub_r001070_2_2 <= 100));
  __CPROVER_assume((pub_r001070_3_1 >= (-100)) && (pub_r001070_3_1 <= 100));
  __CPROVER_assume((pub_r001070_3_2 >= (-100)) && (pub_r001070_3_2 <= 100));
  __CPROVER_assume((pub_r001070_4_1 >= (-100)) && (pub_r001070_4_1 <= 100));
  __CPROVER_assume((pub_r001070_4_2 >= (-100)) && (pub_r001070_4_2 <= 100));
  __CPROVER_assume((pub_r001070_5_1 >= (-100)) && (pub_r001070_5_1 <= 100));
  __CPROVER_assume((pub_r001070_5_2 >= (-100)) && (pub_r001070_5_2 <= 100));
  __CPROVER_assume((pub_r001070_6_1 >= (-100)) && (pub_r001070_6_1 <= 100));
  __CPROVER_assume((pub_r001070_6_2 >= (-100)) && (pub_r001070_6_2 <= 100));
  __CPROVER_assume((pub_r001070_7_1 >= (-100)) && (pub_r001070_7_1 <= 100));
  __CPROVER_assume((pub_r001070_7_2 >= (-100)) && (pub_r001070_7_2 <= 100));
  __CPROVER_assume((pub_r001070_8_1 >= (-100)) && (pub_r001070_8_1 <= 100));
  __CPROVER_assume((pub_r001070_8_2 >= (-100)) && (pub_r001070_8_2 <= 100));
  __CPROVER_assume((pub_r001070_9_1 >= (-100)) && (pub_r001070_9_1 <= 100));
  __CPROVER_assume((pub_r001070_9_2 >= (-100)) && (pub_r001070_9_2 <= 100));
  __CPROVER_assume((pub_r001070_10_1 >= (-100)) && (pub_r001070_10_1 <= 100));
  __CPROVER_assume((pub_r001070_10_2 >= (-100)) && (pub_r001070_10_2 <= 100));
  __CPROVER_assume((pub_r001070_11_1 >= (-100)) && (pub_r001070_11_1 <= 100));
  __CPROVER_assume((pub_r001070_11_2 >= (-100)) && (pub_r001070_11_2 <= 100));
  __CPROVER_assume((pub_r001070_12_1 >= (-100)) && (pub_r001070_12_1 <= 100));
  __CPROVER_assume((pub_r001070_12_2 >= (-100)) && (pub_r001070_12_2 <= 100));
  __CPROVER_assume((pub_r001070_13_1 >= (-100)) && (pub_r001070_13_1 <= 100));
  __CPROVER_assume((pub_r001070_13_2 >= (-100)) && (pub_r001070_13_2 <= 100));
  __CPROVER_assume((pub_r001070_14_1 >= (-100)) && (pub_r001070_14_1 <= 100));
  __CPROVER_assume((pub_r001070_14_2 >= (-100)) && (pub_r001070_14_2 <= 100));
  __CPROVER_assume((pub_r001070_15_1 >= (-100)) && (pub_r001070_15_1 <= 100));
  __CPROVER_assume((pub_r001070_15_2 >= (-100)) && (pub_r001070_15_2 <= 100));
  __CPROVER_assume((sec_r001070_0_1 >= 0) && (sec_r001070_0_1 <= 255));
  __CPROVER_assume((sec_r001070_0_2 >= 0) && (sec_r001070_0_2 <= 255));
  __CPROVER_assume((sec_r001070_1_1 >= 0) && (sec_r001070_1_1 <= 255));
  __CPROVER_assume((sec_r001070_1_2 >= 0) && (sec_r001070_1_2 <= 255));
  __CPROVER_assume((sec_r001070_2_1 >= 0) && (sec_r001070_2_1 <= 255));
  __CPROVER_assume((sec_r001070_2_2 >= 0) && (sec_r001070_2_2 <= 255));
  __CPROVER_assume((sec_r001070_3_1 >= 0) && (sec_r001070_3_1 <= 255));
  __CPROVER_assume((sec_r001070_3_2 >= 0) && (sec_r001070_3_2 <= 255));
  __CPROVER_assume((sec_r001070_4_1 >= 0) && (sec_r001070_4_1 <= 255));
  __CPROVER_assume((sec_r001070_4_2 >= 0) && (sec_r001070_4_2 <= 255));
  __CPROVER_assume((sec_r001070_5_1 >= 0) && (sec_r001070_5_1 <= 255));
  __CPROVER_assume((sec_r001070_5_2 >= 0) && (sec_r001070_5_2 <= 255));
  __CPROVER_assume((sec_r001070_6_1 >= 0) && (sec_r001070_6_1 <= 255));
  __CPROVER_assume((sec_r001070_6_2 >= 0) && (sec_r001070_6_2 <= 255));
  __CPROVER_assume((sec_r001070_7_1 >= 0) && (sec_r001070_7_1 <= 255));
  __CPROVER_assume((sec_r001070_7_2 >= 0) && (sec_r001070_7_2 <= 255));
  __CPROVER_assume((sec_r001070_8_1 >= 0) && (sec_r001070_8_1 <= 255));
  __CPROVER_assume((sec_r001070_8_2 >= 0) && (sec_r001070_8_2 <= 255));
  __CPROVER_assume((sec_r001070_9_1 >= 0) && (sec_r001070_9_1 <= 255));
  __CPROVER_assume((sec_r001070_9_2 >= 0) && (sec_r001070_9_2 <= 255));
  __CPROVER_assume((sec_r001070_10_1 >= 0) && (sec_r001070_10_1 <= 255));
  __CPROVER_assume((sec_r001070_10_2 >= 0) && (sec_r001070_10_2 <= 255));
  __CPROVER_assume((sec_r001070_11_1 >= 0) && (sec_r001070_11_1 <= 255));
  __CPROVER_assume((sec_r001070_11_2 >= 0) && (sec_r001070_11_2 <= 255));
  __CPROVER_assume((sec_r001070_12_1 >= 0) && (sec_r001070_12_1 <= 255));
  __CPROVER_assume((sec_r001070_12_2 >= 0) && (sec_r001070_12_2 <= 255));
  __CPROVER_assume((sec_r001070_13_1 >= 0) && (sec_r001070_13_1 <= 255));
  __CPROVER_assume((sec_r001070_13_2 >= 0) && (sec_r001070_13_2 <= 255));
  __CPROVER_assume((sec_r001070_14_1 >= 0) && (sec_r001070_14_1 <= 255));
  __CPROVER_assume((sec_r001070_14_2 >= 0) && (sec_r001070_14_2 <= 255));
  __CPROVER_assume((sec_r001070_15_1 >= 0) && (sec_r001070_15_1 <= 255));
  __CPROVER_assume((sec_r001070_15_2 >= 0) && (sec_r001070_15_2 <= 255));
  __CPROVER_assume((sec_r001070_16_1 >= 0) && (sec_r001070_16_1 <= 255));
  __CPROVER_assume((sec_r001070_16_2 >= 0) && (sec_r001070_16_2 <= 255));
  __CPROVER_assume((sec_r001070_17_1 >= 0) && (sec_r001070_17_1 <= 255));
  __CPROVER_assume((sec_r001070_17_2 >= 0) && (sec_r001070_17_2 <= 255));
  __CPROVER_assume((sec_r001070_18_1 >= 0) && (sec_r001070_18_1 <= 255));
  __CPROVER_assume((sec_r001070_18_2 >= 0) && (sec_r001070_18_2 <= 255));
  __CPROVER_assume((sec_r001070_19_1 >= 0) && (sec_r001070_19_1 <= 255));
  __CPROVER_assume((sec_r001070_19_2 >= 0) && (sec_r001070_19_2 <= 255));
  __CPROVER_assume((sec_r001070_20_1 >= 0) && (sec_r001070_20_1 <= 255));
  __CPROVER_assume((sec_r001070_20_2 >= 0) && (sec_r001070_20_2 <= 255));
  __CPROVER_assume((sec_r001070_21_1 >= 0) && (sec_r001070_21_1 <= 255));
  __CPROVER_assume((sec_r001070_21_2 >= 0) && (sec_r001070_21_2 <= 255));
  struct DeviceConfig_R001070_7013_0 st_var_0_1 = {0};
  struct DeviceConfig_R001070_7013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001070_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001070_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001070_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001070_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001070_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001070_0_2 + 7) & 15;
  struct AudioFrame_R001070_7013_1 st_var_1_1 = {0};
  struct AudioFrame_R001070_7013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001070_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001070_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001070_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001070_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001070_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001070_0_2 + 9) & 15;
  union RegisterBank_R001070_7013_0 u_var_1;
  union RegisterBank_R001070_7013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001070_7013_0(sec_r001070_0_1, sec_r001070_1_1, pub_r001070_2_1, pub_r001070_3_1);
  int helper_flow_0_2 = fn_R001070_7013_0(sec_r001070_0_2, sec_r001070_1_2, pub_r001070_2_2, pub_r001070_3_2);
  fn_R001070_7013_0_2(sec_r001070_0_1, sec_r001070_1_1, pub_r001070_2_1, pub_r001070_3_1, sec_r001070_0_2, sec_r001070_1_2, pub_r001070_2_2, pub_r001070_3_2);
  int helper_flow_1_1 = fn_R001070_7013_1(sec_r001070_1_1, sec_r001070_2_1, pub_r001070_3_1, pub_r001070_4_1);
  int helper_flow_1_2 = fn_R001070_7013_1(sec_r001070_1_2, sec_r001070_2_2, pub_r001070_3_2, pub_r001070_4_2);
  fn_R001070_7013_1_2(sec_r001070_1_1, sec_r001070_2_1, pub_r001070_3_1, pub_r001070_4_1, sec_r001070_1_2, sec_r001070_2_2, pub_r001070_3_2, pub_r001070_4_2);
  int helper_flow_2_1 = fn_R001070_7013_2(sec_r001070_2_1, sec_r001070_3_1, pub_r001070_4_1);
  int helper_flow_2_2 = fn_R001070_7013_2(sec_r001070_2_2, sec_r001070_3_2, pub_r001070_4_2);
  fn_R001070_7013_2_2(sec_r001070_2_1, sec_r001070_3_1, pub_r001070_4_1, sec_r001070_2_2, sec_r001070_3_2, pub_r001070_4_2);
  int helper_flow_3_1 = fn_R001070_7013_3(sec_r001070_3_1, pub_r001070_4_1, pub_r001070_5_1, pub_r001070_6_1, pub_r001070_7_1);
  int helper_flow_3_2 = fn_R001070_7013_3(sec_r001070_3_2, pub_r001070_4_2, pub_r001070_5_2, pub_r001070_6_2, pub_r001070_7_2);
  fn_R001070_7013_3_2(sec_r001070_3_1, pub_r001070_4_1, pub_r001070_5_1, pub_r001070_6_1, pub_r001070_7_1, sec_r001070_3_2, pub_r001070_4_2, pub_r001070_5_2, pub_r001070_6_2, pub_r001070_7_2);
  int helper_flow_4_1 = fn_R001070_7013_4(sec_r001070_4_1, sec_r001070_5_1, pub_r001070_6_1, pub_r001070_7_1, pub_r001070_8_1);
  int helper_flow_4_2 = fn_R001070_7013_4(sec_r001070_4_2, sec_r001070_5_2, pub_r001070_6_2, pub_r001070_7_2, pub_r001070_8_2);
  fn_R001070_7013_4_2(sec_r001070_4_1, sec_r001070_5_1, pub_r001070_6_1, pub_r001070_7_1, pub_r001070_8_1, sec_r001070_4_2, sec_r001070_5_2, pub_r001070_6_2, pub_r001070_7_2, pub_r001070_8_2);
  int helper_flow_5_1 = fn_R001070_7013_5(sec_r001070_5_1, pub_r001070_6_1, pub_r001070_7_1);
  int helper_flow_5_2 = fn_R001070_7013_5(sec_r001070_5_2, pub_r001070_6_2, pub_r001070_7_2);
  fn_R001070_7013_5_2(sec_r001070_5_1, pub_r001070_6_1, pub_r001070_7_1, sec_r001070_5_2, pub_r001070_6_2, pub_r001070_7_2);
  int helper_flow_6_1 = fn_R001070_7013_6(sec_r001070_6_1, sec_r001070_7_1);
  int helper_flow_6_2 = fn_R001070_7013_6(sec_r001070_6_2, sec_r001070_7_2);
  fn_R001070_7013_6_2(sec_r001070_6_1, sec_r001070_7_1, sec_r001070_6_2, sec_r001070_7_2);
  int helper_flow_7_1 = fn_R001070_7013_7(sec_r001070_7_1, pub_r001070_8_1, pub_r001070_9_1, pub_r001070_10_1, pub_r001070_11_1);
  int helper_flow_7_2 = fn_R001070_7013_7(sec_r001070_7_2, pub_r001070_8_2, pub_r001070_9_2, pub_r001070_10_2, pub_r001070_11_2);
  fn_R001070_7013_7_2(sec_r001070_7_1, pub_r001070_8_1, pub_r001070_9_1, pub_r001070_10_1, pub_r001070_11_1, sec_r001070_7_2, pub_r001070_8_2, pub_r001070_9_2, pub_r001070_10_2, pub_r001070_11_2);
  int helper_flow_8_1 = fn_R001070_7013_8(sec_r001070_8_1, sec_r001070_9_1);
  int helper_flow_8_2 = fn_R001070_7013_8(sec_r001070_8_2, sec_r001070_9_2);
  fn_R001070_7013_8_2(sec_r001070_8_1, sec_r001070_9_1, sec_r001070_8_2, sec_r001070_9_2);
  int stage_v_0_1 = (((sec_r001070_2_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_0_2 = (((sec_r001070_2_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_0_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((sec_r001070_10_1 ^ 0x2A) * 2) + pub_r001070_9_1) & 127;
  int stage_v_1_2 = (((sec_r001070_10_2 ^ 0x2A) * 2) + pub_r001070_9_2) & 127;
  if (stage_v_1_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001070_13_1) & 127;
  int stage_v_2_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001070_13_2) & 127;
  if (stage_v_2_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = ((pub_r001070_15_1 * 2) + 19) & 63;
  int stage_v_3_2 = ((pub_r001070_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((sec_r001070_4_1 ^ 0x2A) * 2) + pub_r001070_13_1) & 127;
  int stage_v_4_2 = (((sec_r001070_4_2 ^ 0x2A) * 2) + pub_r001070_13_2) & 127;
  if (stage_v_4_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_5_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_5_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((sec_r001070_1_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_6_2 = (((sec_r001070_1_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_6_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_7_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_7_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((sec_r001070_1_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_8_2 = (((sec_r001070_1_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_8_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001070_11_1) & 127;
  int stage_v_9_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001070_11_2) & 127;
  if (stage_v_9_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((sec_r001070_9_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_10_2 = (((sec_r001070_9_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_10_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((pub_r001070_15_1 * 2) + 19) & 63;
  int stage_v_11_2 = ((pub_r001070_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_12_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_12_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((pub_r001070_5_1 * 2) + 48) & 63;
  int stage_v_13_2 = ((pub_r001070_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001070_11_1 ^ 0x2A) * 2) + pub_r001070_11_1) & 127;
  int stage_v_14_2 = (((sec_r001070_11_2 ^ 0x2A) * 2) + pub_r001070_11_2) & 127;
  if (stage_v_14_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((pub_r001070_12_1 * 2) + 46) & 63;
  int stage_v_15_2 = ((pub_r001070_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001070_14_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_16_2 = (((sec_r001070_14_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_16_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_17_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_17_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((sec_r001070_2_1 ^ 0x2A) * 2) + pub_r001070_13_1) & 127;
  int stage_v_18_2 = (((sec_r001070_2_2 ^ 0x2A) * 2) + pub_r001070_13_2) & 127;
  if (stage_v_18_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((pub_r001070_13_1 * 2) + 47) & 63;
  int stage_v_19_2 = ((pub_r001070_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((sec_r001070_3_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_20_2 = (((sec_r001070_3_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_20_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_21_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_21_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((sec_r001070_19_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_22_2 = (((sec_r001070_19_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_22_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_23_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_23_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001070_14_1) & 127;
  int stage_v_24_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001070_14_2) & 127;
  if (stage_v_24_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((pub_r001070_8_1 * 2) + 29) & 63;
  int stage_v_25_2 = ((pub_r001070_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_26_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_26_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_27_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_27_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_28_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_28_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((sec_r001070_15_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_29_2 = (((sec_r001070_15_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_29_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((sec_r001070_11_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_30_2 = (((sec_r001070_11_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_30_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((pub_r001070_9_1 * 2) + 47) & 63;
  int stage_v_31_2 = ((pub_r001070_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_32_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_32_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((pub_r001070_14_1 * 2) + 30) & 63;
  int stage_v_33_2 = ((pub_r001070_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001070_11_1) & 127;
  int stage_v_34_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001070_11_2) & 127;
  if (stage_v_34_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_35_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_35_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_36_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_36_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_37_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_37_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((sec_r001070_5_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_38_2 = (((sec_r001070_5_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_38_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_39_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_39_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((sec_r001070_4_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_40_2 = (((sec_r001070_4_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_40_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_41_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_41_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((sec_r001070_8_1 ^ 0x2A) * 2) + pub_r001070_14_1) & 127;
  int stage_v_42_2 = (((sec_r001070_8_2 ^ 0x2A) * 2) + pub_r001070_14_2) & 127;
  if (stage_v_42_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_43_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_43_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_44_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_44_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_45_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_45_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((sec_r001070_19_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_46_2 = (((sec_r001070_19_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_46_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((sec_r001070_1_1 ^ 0x2A) * 2) + pub_r001070_9_1) & 127;
  int stage_v_47_2 = (((sec_r001070_1_2 ^ 0x2A) * 2) + pub_r001070_9_2) & 127;
  if (stage_v_47_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_48_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_48_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((pub_r001070_11_1 * 2) + 28) & 63;
  int stage_v_49_2 = ((pub_r001070_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001070_0_1 * 2) + 39) & 63;
  int stage_v_50_2 = ((pub_r001070_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001070_14_1) & 127;
  int stage_v_51_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001070_14_2) & 127;
  if (stage_v_51_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((pub_r001070_8_1 * 2) + 25) & 63;
  int stage_v_52_2 = ((pub_r001070_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((sec_r001070_7_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_53_2 = (((sec_r001070_7_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_53_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((sec_r001070_6_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_54_2 = (((sec_r001070_6_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_54_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_55_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_55_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001070_13_1) & 127;
  int stage_v_56_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001070_13_2) & 127;
  if (stage_v_56_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_57_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_57_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((sec_r001070_1_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_58_2 = (((sec_r001070_1_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_58_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_59_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_59_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((pub_r001070_11_1 * 2) + 19) & 63;
  int stage_v_60_2 = ((pub_r001070_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001070_4_1 * 2) + 37) & 63;
  int stage_v_61_2 = ((pub_r001070_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001070_1_1 * 2) + 48) & 63;
  int stage_v_62_2 = ((pub_r001070_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_63_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_63_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((pub_r001070_1_1 * 2) + 11) & 63;
  int stage_v_64_2 = ((pub_r001070_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_65_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_65_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_66_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_66_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((pub_r001070_6_1 * 2) + 34) & 63;
  int stage_v_67_2 = ((pub_r001070_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001070_13_1 * 2) + 36) & 63;
  int stage_v_68_2 = ((pub_r001070_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001070_13_1 * 2) + 40) & 63;
  int stage_v_69_2 = ((pub_r001070_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001070_5_1) & 127;
  int stage_v_70_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001070_5_2) & 127;
  if (stage_v_70_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_71_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_71_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((pub_r001070_5_1 * 2) + 35) & 63;
  int stage_v_72_2 = ((pub_r001070_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_73_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_73_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_74_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_74_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001070_9_1) & 127;
  int stage_v_75_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001070_9_2) & 127;
  if (stage_v_75_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((pub_r001070_3_1 * 2) + 27) & 63;
  int stage_v_76_2 = ((pub_r001070_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001070_9_1) & 127;
  int stage_v_77_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001070_9_2) & 127;
  if (stage_v_77_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((pub_r001070_13_1 * 2) + 18) & 63;
  int stage_v_78_2 = ((pub_r001070_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_79_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_79_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_80_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_80_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((pub_r001070_0_1 * 2) + 24) & 63;
  int stage_v_81_2 = ((pub_r001070_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((sec_r001070_8_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_82_2 = (((sec_r001070_8_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_82_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((sec_r001070_4_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_83_2 = (((sec_r001070_4_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_83_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_84_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_84_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((pub_r001070_5_1 * 2) + 36) & 63;
  int stage_v_85_2 = ((pub_r001070_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_86_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_86_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_87_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_87_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((pub_r001070_15_1 * 2) + 50) & 63;
  int stage_v_88_2 = ((pub_r001070_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_89_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_89_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_90_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_90_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((pub_r001070_0_1 * 2) + 32) & 63;
  int stage_v_91_2 = ((pub_r001070_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_92_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_92_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_93_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_93_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((pub_r001070_15_1 * 2) + 29) & 63;
  int stage_v_94_2 = ((pub_r001070_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_95_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_95_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_96_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_96_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((pub_r001070_10_1 * 2) + 6) & 63;
  int stage_v_97_2 = ((pub_r001070_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_98_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_98_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((sec_r001070_17_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_99_2 = (((sec_r001070_17_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_99_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_100_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_100_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((pub_r001070_10_1 * 2) + 16) & 63;
  int stage_v_101_2 = ((pub_r001070_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_102_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_102_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_103_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_103_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((pub_r001070_3_1 * 2) + 17) & 63;
  int stage_v_104_2 = ((pub_r001070_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_105_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_105_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_106_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_106_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((pub_r001070_7_1 * 2) + 32) & 63;
  int stage_v_107_2 = ((pub_r001070_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001070_14_1) & 127;
  int stage_v_108_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001070_14_2) & 127;
  if (stage_v_108_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_109_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_109_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001070_14_1) & 127;
  int stage_v_110_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001070_14_2) & 127;
  if (stage_v_110_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((pub_r001070_11_1 * 2) + 12) & 63;
  int stage_v_111_2 = ((pub_r001070_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((sec_r001070_18_1 ^ 0x2A) * 2) + pub_r001070_11_1) & 127;
  int stage_v_112_2 = (((sec_r001070_18_2 ^ 0x2A) * 2) + pub_r001070_11_2) & 127;
  if (stage_v_112_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((pub_r001070_15_1 * 2) + 49) & 63;
  int stage_v_113_2 = ((pub_r001070_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001070_14_1) & 127;
  int stage_v_114_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001070_14_2) & 127;
  if (stage_v_114_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((pub_r001070_1_1 * 2) + 43) & 63;
  int stage_v_115_2 = ((pub_r001070_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_116_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_116_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((pub_r001070_9_1 * 2) + 18) & 63;
  int stage_v_117_2 = ((pub_r001070_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((sec_r001070_17_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_118_2 = (((sec_r001070_17_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_118_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((sec_r001070_16_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_119_2 = (((sec_r001070_16_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_119_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((stage_v_110_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_120_2 = (((stage_v_110_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_120_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_121_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_121_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_122_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_122_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((sec_r001070_16_1 ^ 0x2A) * 2) + pub_r001070_13_1) & 127;
  int stage_v_123_2 = (((sec_r001070_16_2 ^ 0x2A) * 2) + pub_r001070_13_2) & 127;
  if (stage_v_123_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_124_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_124_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_125_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_125_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((sec_r001070_13_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_126_2 = (((sec_r001070_13_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_126_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_124_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_127_2 = (((stage_v_124_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_127_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_128_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_128_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_129_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_129_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_130_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_130_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((pub_r001070_2_1 * 2) + 42) & 63;
  int stage_v_131_2 = ((pub_r001070_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_132_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_132_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_133_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_133_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_134_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_134_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((pub_r001070_14_1 * 2) + 29) & 63;
  int stage_v_135_2 = ((pub_r001070_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_136_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_136_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((sec_r001070_10_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_137_2 = (((sec_r001070_10_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_137_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_138_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_138_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_139_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_139_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((pub_r001070_4_1 * 2) + 46) & 63;
  int stage_v_140_2 = ((pub_r001070_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((sec_r001070_5_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_141_2 = (((sec_r001070_5_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_141_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((sec_r001070_20_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_142_2 = (((sec_r001070_20_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_142_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((sec_r001070_7_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_143_2 = (((sec_r001070_7_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_143_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_144_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_144_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001070_14_1) & 127;
  int stage_v_145_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001070_14_2) & 127;
  if (stage_v_145_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_146_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_146_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_147_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_147_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((pub_r001070_7_1 * 2) + 42) & 63;
  int stage_v_148_2 = ((pub_r001070_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001070_5_1) & 127;
  int stage_v_149_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001070_5_2) & 127;
  if (stage_v_149_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_150_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_150_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((stage_v_145_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_151_2 = (((stage_v_145_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_151_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_152_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_152_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((pub_r001070_1_1 * 2) + 48) & 63;
  int stage_v_153_2 = ((pub_r001070_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001070_13_1 * 2) + 20) & 63;
  int stage_v_154_2 = ((pub_r001070_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_141_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_155_2 = (((stage_v_141_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_155_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001070_13_1) & 127;
  int stage_v_156_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001070_13_2) & 127;
  if (stage_v_156_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_149_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_157_2 = (((stage_v_149_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_157_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((pub_r001070_9_1 * 2) + 22) & 63;
  int stage_v_158_2 = ((pub_r001070_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((stage_v_121_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_159_2 = (((stage_v_121_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_159_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_160_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_160_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001070_13_1) & 127;
  int stage_v_161_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001070_13_2) & 127;
  if (stage_v_161_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((pub_r001070_7_1 * 2) + 20) & 63;
  int stage_v_162_2 = ((pub_r001070_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001070_13_1) & 127;
  int stage_v_163_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001070_13_2) & 127;
  if (stage_v_163_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_164_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_164_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_165_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_165_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_166_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_166_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_160_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_167_2 = (((stage_v_160_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_167_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_168_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_168_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((pub_r001070_2_1 * 2) + 29) & 63;
  int stage_v_169_2 = ((pub_r001070_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001070_14_1 * 2) + 41) & 63;
  int stage_v_170_2 = ((pub_r001070_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_171_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_171_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001070_14_1) & 127;
  int stage_v_172_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001070_14_2) & 127;
  if (stage_v_172_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((pub_r001070_2_1 * 2) + 50) & 63;
  int stage_v_173_2 = ((pub_r001070_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001070_13_1 * 2) + 38) & 63;
  int stage_v_174_2 = ((pub_r001070_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001070_0_1 * 2) + 35) & 63;
  int stage_v_175_2 = ((pub_r001070_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_176_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_176_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_177_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_177_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_178_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_178_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_179_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_179_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((pub_r001070_7_1 * 2) + 31) & 63;
  int stage_v_180_2 = ((pub_r001070_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001070_4_1 * 2) + 47) & 63;
  int stage_v_181_2 = ((pub_r001070_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_134_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_182_2 = (((stage_v_134_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_182_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((pub_r001070_9_1 * 2) + 35) & 63;
  int stage_v_183_2 = ((pub_r001070_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001070_14_1) & 127;
  int stage_v_184_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001070_14_2) & 127;
  if (stage_v_184_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (((sec_r001070_18_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_185_2 = (((sec_r001070_18_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_185_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((pub_r001070_5_1 * 2) + 12) & 63;
  int stage_v_186_2 = ((pub_r001070_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001070_4_1 * 2) + 44) & 63;
  int stage_v_187_2 = ((pub_r001070_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_161_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_188_2 = (((stage_v_161_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_188_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_189_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_189_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_165_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_190_2 = (((stage_v_165_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_190_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((pub_r001070_6_1 * 2) + 39) & 63;
  int stage_v_191_2 = ((pub_r001070_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001070_5_1) & 127;
  int stage_v_192_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001070_5_2) & 127;
  if (stage_v_192_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((sec_r001070_15_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_193_2 = (((sec_r001070_15_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_193_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_118_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_194_2 = (((stage_v_118_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_194_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001070_9_1) & 127;
  int stage_v_195_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001070_9_2) & 127;
  if (stage_v_195_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001070_11_1) & 127;
  int stage_v_196_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001070_11_2) & 127;
  if (stage_v_196_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_132_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_197_2 = (((stage_v_132_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_197_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_198_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_198_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (((stage_v_161_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_199_2 = (((stage_v_161_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_199_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((pub_r001070_3_1 * 2) + 6) & 63;
  int stage_v_200_2 = ((pub_r001070_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_201_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_201_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_124_1 ^ 0x2A) * 2) + pub_r001070_11_1) & 127;
  int stage_v_202_2 = (((stage_v_124_2 ^ 0x2A) * 2) + pub_r001070_11_2) & 127;
  if (stage_v_202_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((pub_r001070_5_1 * 2) + 27) & 63;
  int stage_v_203_2 = ((pub_r001070_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001070_6_1 * 2) + 9) & 63;
  int stage_v_204_2 = ((pub_r001070_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_205_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_205_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_206_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_206_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_207_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_207_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_157_1 ^ 0x2A) * 2) + pub_r001070_11_1) & 127;
  int stage_v_208_2 = (((stage_v_157_2 ^ 0x2A) * 2) + pub_r001070_11_2) & 127;
  if (stage_v_208_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_209_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_209_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_210_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_210_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((stage_v_145_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_211_2 = (((stage_v_145_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_211_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = (((sec_r001070_19_1 ^ 0x2A) * 2) + pub_r001070_5_1) & 127;
  int stage_v_212_2 = (((sec_r001070_19_2 ^ 0x2A) * 2) + pub_r001070_5_2) & 127;
  if (stage_v_212_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((sec_r001070_12_1 ^ 0x2A) * 2) + pub_r001070_11_1) & 127;
  int stage_v_213_2 = (((sec_r001070_12_2 ^ 0x2A) * 2) + pub_r001070_11_2) & 127;
  if (stage_v_213_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((sec_r001070_16_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_214_2 = (((sec_r001070_16_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_214_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001070_13_1) & 127;
  int stage_v_215_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001070_13_2) & 127;
  if (stage_v_215_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001070_14_1) & 127;
  int stage_v_216_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001070_14_2) & 127;
  if (stage_v_216_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_215_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_217_2 = (((stage_v_215_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_217_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001070_14_1) & 127;
  int stage_v_218_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001070_14_2) & 127;
  if (stage_v_218_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_214_1 ^ 0x2A) * 2) + pub_r001070_9_1) & 127;
  int stage_v_219_2 = (((stage_v_214_2 ^ 0x2A) * 2) + pub_r001070_9_2) & 127;
  if (stage_v_219_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_220_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_220_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_221_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_221_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_222_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_222_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((sec_r001070_2_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_223_2 = (((sec_r001070_2_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_223_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_224_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_224_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((pub_r001070_12_1 * 2) + 24) & 63;
  int stage_v_225_2 = ((pub_r001070_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((sec_r001070_9_1 ^ 0x2A) * 2) + pub_r001070_5_1) & 127;
  int stage_v_226_2 = (((sec_r001070_9_2 ^ 0x2A) * 2) + pub_r001070_5_2) & 127;
  if (stage_v_226_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = (((sec_r001070_18_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_227_2 = (((sec_r001070_18_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_227_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_228_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_228_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = (((sec_r001070_16_1 ^ 0x2A) * 2) + pub_r001070_9_1) & 127;
  int stage_v_229_2 = (((sec_r001070_16_2 ^ 0x2A) * 2) + pub_r001070_9_2) & 127;
  if (stage_v_229_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_230_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_230_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((pub_r001070_1_1 * 2) + 28) & 63;
  int stage_v_231_2 = ((pub_r001070_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((stage_v_149_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_232_2 = (((stage_v_149_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_232_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
  }
  if (stage_v_232_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = (((stage_v_144_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_233_2 = (((stage_v_144_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_233_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_234_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_234_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
  }
  if (stage_v_234_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = (((stage_v_146_1 ^ 0x2A) * 2) + pub_r001070_9_1) & 127;
  int stage_v_235_2 = (((stage_v_146_2 ^ 0x2A) * 2) + pub_r001070_9_2) & 127;
  if (stage_v_235_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
  }
  if (stage_v_235_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001070_5_1) & 127;
  int stage_v_236_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001070_5_2) & 127;
  if (stage_v_236_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
  }
  if (stage_v_236_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = (((stage_v_206_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_237_2 = (((stage_v_206_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_237_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_238_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_238_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
  }
  if (stage_v_238_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((pub_r001070_15_1 * 2) + 33) & 63;
  int stage_v_239_2 = ((pub_r001070_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001070_12_1 * 2) + 17) & 63;
  int stage_v_240_2 = ((pub_r001070_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_241_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_241_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
  }
  if (stage_v_241_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = (((stage_v_192_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_242_2 = (((stage_v_192_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_242_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
  }
  if (stage_v_242_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = (((stage_v_198_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_243_2 = (((stage_v_198_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_243_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_243_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_243_1) + 13) & 255;
  }
  if (stage_v_243_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_243_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_243_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = (((sec_r001070_13_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_244_2 = (((sec_r001070_13_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_244_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
  }
  if (stage_v_244_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001070_13_1) & 127;
  int stage_v_245_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001070_13_2) & 127;
  if (stage_v_245_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_245_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_245_1) + 13) & 255;
  }
  if (stage_v_245_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_245_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_245_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = (((stage_v_121_1 ^ 0x2A) * 2) + pub_r001070_6_1) & 127;
  int stage_v_246_2 = (((stage_v_121_2 ^ 0x2A) * 2) + pub_r001070_6_2) & 127;
  if (stage_v_246_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
  }
  if (stage_v_246_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_247_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_247_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
  }
  if (stage_v_247_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = (((stage_v_210_1 ^ 0x2A) * 2) + pub_r001070_1_1) & 127;
  int stage_v_248_2 = (((stage_v_210_2 ^ 0x2A) * 2) + pub_r001070_1_2) & 127;
  if (stage_v_248_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_248_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_248_1) + 13) & 255;
  }
  if (stage_v_248_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_248_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_248_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_249_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_249_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_249_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_249_1) + 13) & 255;
  }
  if (stage_v_249_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_249_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_249_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = (((stage_v_144_1 ^ 0x2A) * 2) + pub_r001070_11_1) & 127;
  int stage_v_250_2 = (((stage_v_144_2 ^ 0x2A) * 2) + pub_r001070_11_2) & 127;
  if (stage_v_250_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_250_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_250_1) + 13) & 255;
  }
  if (stage_v_250_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_250_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_250_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = (((stage_v_149_1 ^ 0x2A) * 2) + pub_r001070_9_1) & 127;
  int stage_v_251_2 = (((stage_v_149_2 ^ 0x2A) * 2) + pub_r001070_9_2) & 127;
  if (stage_v_251_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_251_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_251_1) + 13) & 255;
  }
  if (stage_v_251_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_251_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_251_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_252_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_252_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_252_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_252_1) + 13) & 255;
  }
  if (stage_v_252_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_252_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_252_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((pub_r001070_0_1 * 2) + 18) & 63;
  int stage_v_253_2 = ((pub_r001070_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_232_1 ^ 0x2A) * 2) + pub_r001070_4_1) & 127;
  int stage_v_254_2 = (((stage_v_232_2 ^ 0x2A) * 2) + pub_r001070_4_2) & 127;
  if (stage_v_254_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_254_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_254_1) + 13) & 255;
  }
  if (stage_v_254_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_254_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_254_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((pub_r001070_15_1 * 2) + 40) & 63;
  int stage_v_255_2 = ((pub_r001070_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001070_8_1 * 2) + 14) & 63;
  int stage_v_256_2 = ((pub_r001070_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001070_12_1) & 127;
  int stage_v_257_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001070_12_2) & 127;
  if (stage_v_257_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_257_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_257_1) + 13) & 255;
  }
  if (stage_v_257_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_257_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_257_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001070_3_1) & 127;
  int stage_v_258_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001070_3_2) & 127;
  if (stage_v_258_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_258_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_258_1) + 13) & 255;
  }
  if (stage_v_258_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_258_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_258_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((pub_r001070_2_1 * 2) + 46) & 63;
  int stage_v_259_2 = ((pub_r001070_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001070_13_1 * 2) + 13) & 63;
  int stage_v_260_2 = ((pub_r001070_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_182_1 ^ 0x2A) * 2) + pub_r001070_11_1) & 127;
  int stage_v_261_2 = (((stage_v_182_2 ^ 0x2A) * 2) + pub_r001070_11_2) & 127;
  if (stage_v_261_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_261_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_261_1) + 13) & 255;
  }
  if (stage_v_261_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_261_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_261_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_262_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_262_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_262_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_262_1) + 13) & 255;
  }
  if (stage_v_262_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_262_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_262_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = (((stage_v_152_1 ^ 0x2A) * 2) + pub_r001070_7_1) & 127;
  int stage_v_263_2 = (((stage_v_152_2 ^ 0x2A) * 2) + pub_r001070_7_2) & 127;
  if (stage_v_263_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_263_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_263_1) + 13) & 255;
  }
  if (stage_v_263_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_263_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_263_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((pub_r001070_3_1 * 2) + 43) & 63;
  int stage_v_264_2 = ((pub_r001070_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_168_1 ^ 0x2A) * 2) + pub_r001070_15_1) & 127;
  int stage_v_265_2 = (((stage_v_168_2 ^ 0x2A) * 2) + pub_r001070_15_2) & 127;
  if (stage_v_265_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_265_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_265_1) + 13) & 255;
  }
  if (stage_v_265_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_265_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_265_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001070_2_1) & 127;
  int stage_v_266_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001070_2_2) & 127;
  if (stage_v_266_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_266_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_266_1) + 13) & 255;
  }
  if (stage_v_266_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_266_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_266_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001070_0_1) & 127;
  int stage_v_267_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001070_0_2) & 127;
  if (stage_v_267_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_267_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_267_1) + 13) & 255;
  }
  if (stage_v_267_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_267_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_267_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001070_10_1) & 127;
  int stage_v_268_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001070_10_2) & 127;
  if (stage_v_268_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_268_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_268_1) + 13) & 255;
  }
  if (stage_v_268_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_268_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_268_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = (((stage_v_211_1 ^ 0x2A) * 2) + pub_r001070_11_1) & 127;
  int stage_v_269_2 = (((stage_v_211_2 ^ 0x2A) * 2) + pub_r001070_11_2) & 127;
  if (stage_v_269_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_269_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_269_1) + 13) & 255;
  }
  if (stage_v_269_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_269_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_269_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((pub_r001070_0_1 * 2) + 11) & 63;
  int stage_v_270_2 = ((pub_r001070_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001070_8_1) & 127;
  int stage_v_271_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001070_8_2) & 127;
  if (stage_v_271_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_271_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_271_1) + 13) & 255;
  }
  if (stage_v_271_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_271_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_271_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001070_2_1 != sec_r001070_2_2);
  __CPROVER_assume(sec_r001070_3_1 != sec_r001070_3_2);
  __CPROVER_assume(pub_r001070_3_1 == pub_r001070_3_2);
  __CPROVER_assume(sec_r001070_14_1 != sec_r001070_14_2);
  __CPROVER_assume(sec_r001070_20_1 != sec_r001070_20_2);
  __CPROVER_assume(sec_r001070_16_1 != sec_r001070_16_2);
  __CPROVER_assume(pub_r001070_5_1 == pub_r001070_5_2);
  __CPROVER_assume(pub_r001070_6_1 == pub_r001070_6_2);
  __CPROVER_assume(pub_r001070_9_1 == pub_r001070_9_2);
  __CPROVER_assume(sec_r001070_0_1 != sec_r001070_0_2);
  __CPROVER_assume(sec_r001070_11_1 != sec_r001070_11_2);
  __CPROVER_assume(sec_r001070_12_1 != sec_r001070_12_2);
  __CPROVER_assume(sec_r001070_4_1 != sec_r001070_4_2);
  __CPROVER_assume(sec_r001070_5_1 != sec_r001070_5_2);
  __CPROVER_assume(sec_r001070_19_1 != sec_r001070_19_2);
  __CPROVER_assume(sec_r001070_21_1 != sec_r001070_21_2);
  __CPROVER_assume(pub_r001070_1_1 == pub_r001070_1_2);
  __CPROVER_assume(pub_r001070_8_1 == pub_r001070_8_2);
  __CPROVER_assume(sec_r001070_15_1 != sec_r001070_15_2);
  __CPROVER_assume(pub_r001070_10_1 == pub_r001070_10_2);
  __CPROVER_assume(sec_r001070_7_1 != sec_r001070_7_2);
  __CPROVER_assume(sec_r001070_17_1 != sec_r001070_17_2);
  __CPROVER_assume(sec_r001070_18_1 != sec_r001070_18_2);
  __CPROVER_assume(pub_r001070_15_1 == pub_r001070_15_2);
  __CPROVER_assume(pub_r001070_13_1 == pub_r001070_13_2);
  __CPROVER_assume(pub_r001070_4_1 == pub_r001070_4_2);
  __CPROVER_assume(sec_r001070_1_1 != sec_r001070_1_2);
  __CPROVER_assume(pub_r001070_11_1 == pub_r001070_11_2);
  __CPROVER_assume(sec_r001070_8_1 != sec_r001070_8_2);
  __CPROVER_assume(pub_r001070_0_1 == pub_r001070_0_2);
  __CPROVER_assume(sec_r001070_9_1 != sec_r001070_9_2);
  __CPROVER_assume(pub_r001070_7_1 == pub_r001070_7_2);
  __CPROVER_assume(sec_r001070_10_1 != sec_r001070_10_2);
  __CPROVER_assume(pub_r001070_14_1 == pub_r001070_14_2);
  __CPROVER_assume(sec_r001070_6_1 != sec_r001070_6_2);
  __CPROVER_assume(pub_r001070_12_1 == pub_r001070_12_2);
  __CPROVER_assume(sec_r001070_13_1 != sec_r001070_13_2);
  __CPROVER_assume(pub_r001070_2_1 == pub_r001070_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.port == st_var_0_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.peak == st_var_1_2.peak);
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
}


