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
struct AudioFrame_R001254_5413_0
{
  int gain;
  int sample_rate;
  short channels;
  int envelope;
  short peak;
  int rms;
  int buffer[3];
};
struct EventLog_R001254_5413_1
{
  short timestamp;
  int facility;
  unsigned char seq;
  int buffer[3];
};
struct Transaction_R001254_5413_2
{
  short balance;
  int fee;
  int rate;
  short account_id;
  int buffer[3];
};
struct DeviceConfig_R001254_5413_3
{
  short stop_bits;
  unsigned char parity;
  int timeout;
  int baud_rate;
  int buffer[3];
};
union ColorPixel_R001254_5413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001254_5413_1
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
void fn_R001254_5413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001254_5413_1 st_1 = {0};
  struct EventLog_R001254_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int scale_68_1 = 0;
  int scale_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_68_1 = ((scale_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_68_2 = ((scale_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_68_1) & 127;
    acc_2 = (acc_2 + scale_68_2) & 127;
  }

  int tracker_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_42_1) & 63;
  aux_2 = (aux_2 + tracker_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_42_1 > 22)
  {
    acc_1 = ((acc_1 + (parity_42_1 * 2)) + 5) & 127;
    aux_1 ^= parity_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_42_2 > 22)
  {
    acc_2 = ((acc_2 + (parity_42_2 * 2)) + 5) & 127;
    aux_2 ^= parity_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_42_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_68_1 == scale_68_2);
  assert(tracker_42_1 == tracker_42_2);
  assert(parity_42_1 == parity_42_2);
}

int fn_R001254_5413_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001254_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int scale_68 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_68 = ((scale_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_68) & 127;
  }

  int tracker_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_42) & 63;
  acc ^= aux;
  int parity_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_42 > 22)
  {
    acc = ((acc + (parity_42 * 2)) + 5) & 127;
    aux ^= parity_42 & 15;
  }
  else
  {
    acc = ((acc - parity_42) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001254_5413_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st_1 = {0};
  struct DeviceConfig_R001254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int offset_65_1 = 0;
  int offset_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_65_1 = ((offset_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_65_2 = ((offset_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_65_1) & 127;
    acc_2 = (acc_2 + offset_65_2) & 127;
  }

  int vector_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_68_1)
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

  switch (vector_68_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_65_1 == offset_65_2);
  assert(vector_68_1 == vector_68_2);
}

int fn_R001254_5413_1(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int offset_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_65 = ((offset_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_65) & 127;
  }

  int vector_68 = (aux + st.buffer[1]) & 3;
  switch (vector_68)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001254_5413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001254_5413_0 st_1 = {0};
  struct AudioFrame_R001254_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_94_1 = local_arr_1[aux_1 % 3];
  int sample_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_94_2 * 2)) & 127;
  int parity_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_58_1) & 63;
  aux_2 = (aux_2 + parity_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_91_1 = 0;
  int quotient_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_91_1 = ((quotient_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_91_2 = ((quotient_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_91_1) & 127;
    acc_2 = (acc_2 + quotient_91_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_94_1 == sample_94_2);
  assert(parity_58_1 == parity_58_2);
  assert(quotient_91_1 == quotient_91_2);
}

int fn_R001254_5413_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001254_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int sample_94 = local_arr[aux % 3];
  acc = (acc + (sample_94 * 2)) & 127;
  int parity_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_58) & 63;
  acc ^= aux;
  int quotient_91 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_91 = ((quotient_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_91) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001254_5413_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st_1 = {0};
  struct DeviceConfig_R001254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int weight_51_1 = 0;
  int weight_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_51_1 = ((weight_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_51_2 = ((weight_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_51_1) & 127;
    acc_2 = (acc_2 + weight_51_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_87_1 = local_arr_1[aux_1 % 3];
  int quantum_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_87_2 * 2)) & 127;
  int offset_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_33_1 > 42)
  {
    acc_1 = ((acc_1 + (offset_33_1 * 2)) + 5) & 127;
    aux_1 ^= offset_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_33_2 > 42)
  {
    acc_2 = ((acc_2 + (offset_33_2 * 2)) + 5) & 127;
    aux_2 ^= offset_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_51_1 == weight_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_87_1 == quantum_87_2);
  assert(offset_33_1 == offset_33_2);
}

int fn_R001254_5413_3(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int weight_51 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_51 = ((weight_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_51) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quantum_87 = local_arr[aux % 3];
  acc = (acc + (quantum_87 * 2)) & 127;
  int offset_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_33 > 42)
  {
    acc = ((acc + (offset_33 * 2)) + 5) & 127;
    aux ^= offset_33 & 15;
  }
  else
  {
    acc = ((acc - offset_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001254_5413_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001254_5413_1 st_1 = {0};
  struct EventLog_R001254_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int stride_40_1 = 0;
  int stride_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_40_1 = ((stride_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_40_2 = ((stride_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_40_1) & 127;
    acc_2 = (acc_2 + stride_40_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_10_1 = local_arr_1[aux_1 % 3];
  int delta_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_10_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_81_1 > 32)
  {
    acc_1 = ((acc_1 + (checksum_81_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_81_2 > 32)
  {
    acc_2 = ((acc_2 + (checksum_81_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_40_1 == stride_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_10_1 == delta_10_2);
  assert(checksum_81_1 == checksum_81_2);
}

int fn_R001254_5413_4(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001254_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int stride_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_40 = ((stride_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_40) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int delta_10 = local_arr[aux % 3];
  acc = (acc + (delta_10 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_81 > 32)
  {
    acc = ((acc + (checksum_81 * 2)) + 5) & 127;
    aux ^= checksum_81 & 15;
  }
  else
  {
    acc = ((acc - checksum_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001254_5413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st_1 = {0};
  struct DeviceConfig_R001254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quotient_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_79_1 > 48)
  {
    acc_1 = ((acc_1 + (quotient_79_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_79_2 > 48)
  {
    acc_2 = ((acc_2 + (quotient_79_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_57_1 = 0;
  int cursor_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_57_1 = ((cursor_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_57_2 = ((cursor_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_57_1) & 127;
    acc_2 = (acc_2 + cursor_57_2) & 127;
  }

  int index_reg_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_36_1) & 63;
  aux_2 = (aux_2 + index_reg_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_72_1 = local_arr_1[aux_1 % 3];
  int scale_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_79_1 == quotient_79_2);
  assert(cursor_57_1 == cursor_57_2);
  assert(index_reg_36_1 == index_reg_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_72_1 == scale_72_2);
}

int fn_R001254_5413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quotient_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_79 > 48)
  {
    acc = ((acc + (quotient_79 * 2)) + 5) & 127;
    aux ^= quotient_79 & 15;
  }
  else
  {
    acc = ((acc - quotient_79) + 11) & 127;
    aux += 3;
  }
  int cursor_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_57 = ((cursor_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_57) & 127;
  }

  int index_reg_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_36) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_72 = local_arr[aux % 3];
  acc = (acc + (scale_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001254_5413_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st_1 = {0};
  struct DeviceConfig_R001254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_94_1)
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

  switch (phase_94_2)
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
  int quotient_58_1 = local_arr_1[aux_1 % 3];
  int quotient_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_94_1 == phase_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_58_1 == quotient_58_2);
}

int fn_R001254_5413_6(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_94 = (aux + st.buffer[1]) & 3;
  switch (phase_94)
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
  int quotient_58 = local_arr[aux % 3];
  acc = (acc + (quotient_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001254_5413_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st_1 = {0};
  struct DeviceConfig_R001254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int accumulator_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_43_1 > 49)
  {
    acc_1 = ((acc_1 + (accumulator_43_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_43_2 > 49)
  {
    acc_2 = ((acc_2 + (accumulator_43_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_35_1) & 63;
  aux_2 = (aux_2 + factor_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_39_1)
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

  switch (tracker_39_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_43_1 == accumulator_43_2);
  assert(factor_35_1 == factor_35_2);
  assert(tracker_39_1 == tracker_39_2);
}

int fn_R001254_5413_7(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int accumulator_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_43 > 49)
  {
    acc = ((acc + (accumulator_43 * 2)) + 5) & 127;
    aux ^= accumulator_43 & 15;
  }
  else
  {
    acc = ((acc - accumulator_43) + 11) & 127;
    aux += 3;
  }
  int factor_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_39 = (aux + st.buffer[1]) & 3;
  switch (tracker_39)
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

void fn_R001254_5413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001254_5413_0 st_1 = {0};
  struct AudioFrame_R001254_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int segment_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_65_1 > 16)
  {
    acc_1 = ((acc_1 + (segment_65_1 * 2)) + 5) & 127;
    aux_1 ^= segment_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_65_2 > 16)
  {
    acc_2 = ((acc_2 + (segment_65_2 * 2)) + 5) & 127;
    aux_2 ^= segment_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_65_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_59_1)
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

  switch (margin_59_2)
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

  int stride_72_1 = 0;
  int stride_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_72_1 = ((stride_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_72_2 = ((stride_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_72_1) & 127;
    acc_2 = (acc_2 + stride_72_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_65_1 == segment_65_2);
  assert(margin_59_1 == margin_59_2);
  assert(stride_72_1 == stride_72_2);
}

int fn_R001254_5413_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001254_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int segment_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_65 > 16)
  {
    acc = ((acc + (segment_65 * 2)) + 5) & 127;
    aux ^= segment_65 & 15;
  }
  else
  {
    acc = ((acc - segment_65) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_59 = (aux + st.buffer[1]) & 3;
  switch (margin_59)
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

  int stride_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_72 = ((stride_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_72) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001254_5413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st_1 = {0};
  struct DeviceConfig_R001254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int stride_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_58_1)
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

  switch (stride_58_2)
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

  int checksum_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_26_1) & 63;
  aux_2 = (aux_2 + checksum_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_74_1 = local_arr_1[aux_1 % 3];
  int accumulator_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_74_2 * 2)) & 127;
  int index_reg_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_50_1 > 28)
  {
    acc_1 = ((acc_1 + (index_reg_50_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_50_2 > 28)
  {
    acc_2 = ((acc_2 + (index_reg_50_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_50_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_58_1 == stride_58_2);
  assert(checksum_26_1 == checksum_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_74_1 == accumulator_74_2);
  assert(index_reg_50_1 == index_reg_50_2);
}

int fn_R001254_5413_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int stride_58 = (aux + st.buffer[1]) & 3;
  switch (stride_58)
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

  int checksum_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_26) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_74 = local_arr[aux % 3];
  acc = (acc + (accumulator_74 * 2)) & 127;
  int index_reg_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_50 > 28)
  {
    acc = ((acc + (index_reg_50 * 2)) + 5) & 127;
    aux ^= index_reg_50 & 15;
  }
  else
  {
    acc = ((acc - index_reg_50) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001254_5413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001254_5413_0 st_1 = {0};
  struct AudioFrame_R001254_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_98_1)
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

  switch (delta_98_2)
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
  int mask_44_1 = local_arr_1[aux_1 % 3];
  int mask_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_98_1 == delta_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_44_1 == mask_44_2);
}

int fn_R001254_5413_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001254_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_98 = (aux + st.buffer[1]) & 3;
  switch (delta_98)
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
  int mask_44 = local_arr[aux % 3];
  acc = (acc + (mask_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001254_5413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001254_5413_1 st_1 = {0};
  struct EventLog_R001254_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int scale_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_68_1 > 14)
  {
    acc_1 = ((acc_1 + (scale_68_1 * 2)) + 5) & 127;
    aux_1 ^= scale_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_68_2 > 14)
  {
    acc_2 = ((acc_2 + (scale_68_2 * 2)) + 5) & 127;
    aux_2 ^= scale_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_68_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_32_1 = 0;
  int mask_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_32_1 = ((mask_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_32_2 = ((mask_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_32_1) & 127;
    acc_2 = (acc_2 + mask_32_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_68_1 == scale_68_2);
  assert(mask_32_1 == mask_32_2);
}

int fn_R001254_5413_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001254_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int scale_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_68 > 14)
  {
    acc = ((acc + (scale_68 * 2)) + 5) & 127;
    aux ^= scale_68 & 15;
  }
  else
  {
    acc = ((acc - scale_68) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_32 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_32 = ((mask_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_32) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001254_5413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001254_5413_2 st_1 = {0};
  struct Transaction_R001254_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int scale_57_1 = 0;
  int scale_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_57_1 = ((scale_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_57_2 = ((scale_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_57_1) & 127;
    acc_2 = (acc_2 + scale_57_2) & 127;
  }

  int quotient_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_92_1) & 63;
  aux_2 = (aux_2 + quotient_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_54_1)
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

  switch (parity_54_2)
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

  int window_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_75_1 > 40)
  {
    acc_1 = ((acc_1 + (window_75_1 * 2)) + 5) & 127;
    aux_1 ^= window_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_75_2 > 40)
  {
    acc_2 = ((acc_2 + (window_75_2 * 2)) + 5) & 127;
    aux_2 ^= window_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_57_1 == scale_57_2);
  assert(quotient_92_1 == quotient_92_2);
  assert(parity_54_1 == parity_54_2);
  assert(window_75_1 == window_75_2);
}

int fn_R001254_5413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001254_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int scale_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_57 = ((scale_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_57) & 127;
  }

  int quotient_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_92) & 63;
  acc ^= aux;
  int parity_54 = (aux + st.buffer[1]) & 3;
  switch (parity_54)
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

  int window_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_75 > 40)
  {
    acc = ((acc + (window_75 * 2)) + 5) & 127;
    aux ^= window_75 & 15;
  }
  else
  {
    acc = ((acc - window_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001254_5413_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001254_5413_1 st_1 = {0};
  struct EventLog_R001254_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int window_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_11_1 > 12)
  {
    acc_1 = ((acc_1 + (window_11_1 * 2)) + 5) & 127;
    aux_1 ^= window_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_11_2 > 12)
  {
    acc_2 = ((acc_2 + (window_11_2 * 2)) + 5) & 127;
    aux_2 ^= window_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_19_1 = 0;
  int tally_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_19_1 = ((tally_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_19_2 = ((tally_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_19_1) & 127;
    acc_2 = (acc_2 + tally_19_2) & 127;
  }

  int pivot_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_34_1) & 63;
  aux_2 = (aux_2 + pivot_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_33_1)
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

  switch (segment_33_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_11_1 == window_11_2);
  assert(tally_19_1 == tally_19_2);
  assert(pivot_34_1 == pivot_34_2);
  assert(segment_33_1 == segment_33_2);
}

int fn_R001254_5413_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001254_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int window_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_11 > 12)
  {
    acc = ((acc + (window_11 * 2)) + 5) & 127;
    aux ^= window_11 & 15;
  }
  else
  {
    acc = ((acc - window_11) + 11) & 127;
    aux += 3;
  }
  int tally_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_19 = ((tally_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_19) & 127;
  }

  int pivot_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_34) & 63;
  acc ^= aux;
  int segment_33 = (aux + st.buffer[1]) & 3;
  switch (segment_33)
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

void fn_R001254_5413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001254_5413_0 st_1 = {0};
  struct AudioFrame_R001254_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int vector_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_22_1) & 63;
  aux_2 = (aux_2 + vector_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_42_1 = 0;
  int phase_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_42_1 = ((phase_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_42_2 = ((phase_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_42_1) & 127;
    acc_2 = (acc_2 + phase_42_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_39_1)
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

  switch (coefficient_39_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_22_1 == vector_22_2);
  assert(phase_42_1 == phase_42_2);
  assert(coefficient_39_1 == coefficient_39_2);
}

int fn_R001254_5413_14(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001254_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int vector_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_22) & 63;
  acc ^= aux;
  int phase_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_42 = ((phase_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_42) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_39 = (aux + st.buffer[1]) & 3;
  switch (coefficient_39)
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

void fn_R001254_5413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001254_5413_2 st_1 = {0};
  struct Transaction_R001254_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int delta_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_36_1)
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

  switch (delta_36_2)
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

  int bound_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_75_1 > 23)
  {
    acc_1 = ((acc_1 + (bound_75_1 * 2)) + 5) & 127;
    aux_1 ^= bound_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_75_2 > 23)
  {
    acc_2 = ((acc_2 + (bound_75_2 * 2)) + 5) & 127;
    aux_2 ^= bound_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_56_1) & 63;
  aux_2 = (aux_2 + quantum_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_36_1 == delta_36_2);
  assert(bound_75_1 == bound_75_2);
  assert(quantum_56_1 == quantum_56_2);
}

int fn_R001254_5413_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001254_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int delta_36 = (aux + st.buffer[1]) & 3;
  switch (delta_36)
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

  int bound_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_75 > 23)
  {
    acc = ((acc + (bound_75 * 2)) + 5) & 127;
    aux ^= bound_75 & 15;
  }
  else
  {
    acc = ((acc - bound_75) + 11) & 127;
    aux += 3;
  }
  int quantum_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001254_0_1;
  int sec_r001254_0_2;
  int sec_r001254_1_1;
  int sec_r001254_1_2;
  int sec_r001254_2_1;
  int sec_r001254_2_2;
  int sec_r001254_3_1;
  int sec_r001254_3_2;
  int sec_r001254_4_1;
  int sec_r001254_4_2;
  int sec_r001254_5_1;
  int sec_r001254_5_2;
  int sec_r001254_6_1;
  int sec_r001254_6_2;
  int sec_r001254_7_1;
  int sec_r001254_7_2;
  int sec_r001254_8_1;
  int sec_r001254_8_2;
  int sec_r001254_9_1;
  int sec_r001254_9_2;
  int sec_r001254_10_1;
  int sec_r001254_10_2;
  int sec_r001254_11_1;
  int sec_r001254_11_2;
  int sec_r001254_12_1;
  int sec_r001254_12_2;
  int sec_r001254_13_1;
  int sec_r001254_13_2;
  int sec_r001254_14_1;
  int sec_r001254_14_2;
  int sec_r001254_15_1;
  int sec_r001254_15_2;
  int sec_r001254_16_1;
  int sec_r001254_16_2;
  int sec_r001254_17_1;
  int sec_r001254_17_2;
  int sec_r001254_18_1;
  int sec_r001254_18_2;
  int sec_r001254_19_1;
  int sec_r001254_19_2;
  int sec_r001254_20_1;
  int sec_r001254_20_2;
  int sec_r001254_21_1;
  int sec_r001254_21_2;
  int sec_r001254_22_1;
  int sec_r001254_22_2;
  int sec_r001254_23_1;
  int sec_r001254_23_2;
  int pub_r001254_0_1;
  int pub_r001254_0_2;
  int pub_r001254_1_1;
  int pub_r001254_1_2;
  int pub_r001254_2_1;
  int pub_r001254_2_2;
  int pub_r001254_3_1;
  int pub_r001254_3_2;
  int pub_r001254_4_1;
  int pub_r001254_4_2;
  int pub_r001254_5_1;
  int pub_r001254_5_2;
  int pub_r001254_6_1;
  int pub_r001254_6_2;
  int pub_r001254_7_1;
  int pub_r001254_7_2;
  int pub_r001254_8_1;
  int pub_r001254_8_2;
  int pub_r001254_9_1;
  int pub_r001254_9_2;
  int pub_r001254_10_1;
  int pub_r001254_10_2;
  int pub_r001254_11_1;
  int pub_r001254_11_2;
  int pub_r001254_12_1;
  int pub_r001254_12_2;
  int pub_r001254_13_1;
  int pub_r001254_13_2;
  int pub_r001254_14_1;
  int pub_r001254_14_2;
  int pub_r001254_15_1;
  int pub_r001254_15_2;
  int pub_r001254_16_1;
  int pub_r001254_16_2;
  int pub_r001254_17_1;
  int pub_r001254_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001254_0_1 >= (-100)) && (pub_r001254_0_1 <= 100));
  __CPROVER_assume((pub_r001254_0_2 >= (-100)) && (pub_r001254_0_2 <= 100));
  __CPROVER_assume((pub_r001254_1_1 >= (-100)) && (pub_r001254_1_1 <= 100));
  __CPROVER_assume((pub_r001254_1_2 >= (-100)) && (pub_r001254_1_2 <= 100));
  __CPROVER_assume((pub_r001254_2_1 >= (-100)) && (pub_r001254_2_1 <= 100));
  __CPROVER_assume((pub_r001254_2_2 >= (-100)) && (pub_r001254_2_2 <= 100));
  __CPROVER_assume((pub_r001254_3_1 >= (-100)) && (pub_r001254_3_1 <= 100));
  __CPROVER_assume((pub_r001254_3_2 >= (-100)) && (pub_r001254_3_2 <= 100));
  __CPROVER_assume((pub_r001254_4_1 >= (-100)) && (pub_r001254_4_1 <= 100));
  __CPROVER_assume((pub_r001254_4_2 >= (-100)) && (pub_r001254_4_2 <= 100));
  __CPROVER_assume((pub_r001254_5_1 >= (-100)) && (pub_r001254_5_1 <= 100));
  __CPROVER_assume((pub_r001254_5_2 >= (-100)) && (pub_r001254_5_2 <= 100));
  __CPROVER_assume((pub_r001254_6_1 >= (-100)) && (pub_r001254_6_1 <= 100));
  __CPROVER_assume((pub_r001254_6_2 >= (-100)) && (pub_r001254_6_2 <= 100));
  __CPROVER_assume((pub_r001254_7_1 >= (-100)) && (pub_r001254_7_1 <= 100));
  __CPROVER_assume((pub_r001254_7_2 >= (-100)) && (pub_r001254_7_2 <= 100));
  __CPROVER_assume((pub_r001254_8_1 >= (-100)) && (pub_r001254_8_1 <= 100));
  __CPROVER_assume((pub_r001254_8_2 >= (-100)) && (pub_r001254_8_2 <= 100));
  __CPROVER_assume((pub_r001254_9_1 >= (-100)) && (pub_r001254_9_1 <= 100));
  __CPROVER_assume((pub_r001254_9_2 >= (-100)) && (pub_r001254_9_2 <= 100));
  __CPROVER_assume((pub_r001254_10_1 >= (-100)) && (pub_r001254_10_1 <= 100));
  __CPROVER_assume((pub_r001254_10_2 >= (-100)) && (pub_r001254_10_2 <= 100));
  __CPROVER_assume((pub_r001254_11_1 >= (-100)) && (pub_r001254_11_1 <= 100));
  __CPROVER_assume((pub_r001254_11_2 >= (-100)) && (pub_r001254_11_2 <= 100));
  __CPROVER_assume((pub_r001254_12_1 >= (-100)) && (pub_r001254_12_1 <= 100));
  __CPROVER_assume((pub_r001254_12_2 >= (-100)) && (pub_r001254_12_2 <= 100));
  __CPROVER_assume((pub_r001254_13_1 >= (-100)) && (pub_r001254_13_1 <= 100));
  __CPROVER_assume((pub_r001254_13_2 >= (-100)) && (pub_r001254_13_2 <= 100));
  __CPROVER_assume((pub_r001254_14_1 >= (-100)) && (pub_r001254_14_1 <= 100));
  __CPROVER_assume((pub_r001254_14_2 >= (-100)) && (pub_r001254_14_2 <= 100));
  __CPROVER_assume((pub_r001254_15_1 >= (-100)) && (pub_r001254_15_1 <= 100));
  __CPROVER_assume((pub_r001254_15_2 >= (-100)) && (pub_r001254_15_2 <= 100));
  __CPROVER_assume((pub_r001254_16_1 >= (-100)) && (pub_r001254_16_1 <= 100));
  __CPROVER_assume((pub_r001254_16_2 >= (-100)) && (pub_r001254_16_2 <= 100));
  __CPROVER_assume((pub_r001254_17_1 >= (-100)) && (pub_r001254_17_1 <= 100));
  __CPROVER_assume((pub_r001254_17_2 >= (-100)) && (pub_r001254_17_2 <= 100));
  __CPROVER_assume((sec_r001254_0_1 >= 0) && (sec_r001254_0_1 <= 255));
  __CPROVER_assume((sec_r001254_0_2 >= 0) && (sec_r001254_0_2 <= 255));
  __CPROVER_assume((sec_r001254_1_1 >= 0) && (sec_r001254_1_1 <= 255));
  __CPROVER_assume((sec_r001254_1_2 >= 0) && (sec_r001254_1_2 <= 255));
  __CPROVER_assume((sec_r001254_2_1 >= 0) && (sec_r001254_2_1 <= 255));
  __CPROVER_assume((sec_r001254_2_2 >= 0) && (sec_r001254_2_2 <= 255));
  __CPROVER_assume((sec_r001254_3_1 >= 0) && (sec_r001254_3_1 <= 255));
  __CPROVER_assume((sec_r001254_3_2 >= 0) && (sec_r001254_3_2 <= 255));
  __CPROVER_assume((sec_r001254_4_1 >= 0) && (sec_r001254_4_1 <= 255));
  __CPROVER_assume((sec_r001254_4_2 >= 0) && (sec_r001254_4_2 <= 255));
  __CPROVER_assume((sec_r001254_5_1 >= 0) && (sec_r001254_5_1 <= 255));
  __CPROVER_assume((sec_r001254_5_2 >= 0) && (sec_r001254_5_2 <= 255));
  __CPROVER_assume((sec_r001254_6_1 >= 0) && (sec_r001254_6_1 <= 255));
  __CPROVER_assume((sec_r001254_6_2 >= 0) && (sec_r001254_6_2 <= 255));
  __CPROVER_assume((sec_r001254_7_1 >= 0) && (sec_r001254_7_1 <= 255));
  __CPROVER_assume((sec_r001254_7_2 >= 0) && (sec_r001254_7_2 <= 255));
  __CPROVER_assume((sec_r001254_8_1 >= 0) && (sec_r001254_8_1 <= 255));
  __CPROVER_assume((sec_r001254_8_2 >= 0) && (sec_r001254_8_2 <= 255));
  __CPROVER_assume((sec_r001254_9_1 >= 0) && (sec_r001254_9_1 <= 255));
  __CPROVER_assume((sec_r001254_9_2 >= 0) && (sec_r001254_9_2 <= 255));
  __CPROVER_assume((sec_r001254_10_1 >= 0) && (sec_r001254_10_1 <= 255));
  __CPROVER_assume((sec_r001254_10_2 >= 0) && (sec_r001254_10_2 <= 255));
  __CPROVER_assume((sec_r001254_11_1 >= 0) && (sec_r001254_11_1 <= 255));
  __CPROVER_assume((sec_r001254_11_2 >= 0) && (sec_r001254_11_2 <= 255));
  __CPROVER_assume((sec_r001254_12_1 >= 0) && (sec_r001254_12_1 <= 255));
  __CPROVER_assume((sec_r001254_12_2 >= 0) && (sec_r001254_12_2 <= 255));
  __CPROVER_assume((sec_r001254_13_1 >= 0) && (sec_r001254_13_1 <= 255));
  __CPROVER_assume((sec_r001254_13_2 >= 0) && (sec_r001254_13_2 <= 255));
  __CPROVER_assume((sec_r001254_14_1 >= 0) && (sec_r001254_14_1 <= 255));
  __CPROVER_assume((sec_r001254_14_2 >= 0) && (sec_r001254_14_2 <= 255));
  __CPROVER_assume((sec_r001254_15_1 >= 0) && (sec_r001254_15_1 <= 255));
  __CPROVER_assume((sec_r001254_15_2 >= 0) && (sec_r001254_15_2 <= 255));
  __CPROVER_assume((sec_r001254_16_1 >= 0) && (sec_r001254_16_1 <= 255));
  __CPROVER_assume((sec_r001254_16_2 >= 0) && (sec_r001254_16_2 <= 255));
  __CPROVER_assume((sec_r001254_17_1 >= 0) && (sec_r001254_17_1 <= 255));
  __CPROVER_assume((sec_r001254_17_2 >= 0) && (sec_r001254_17_2 <= 255));
  __CPROVER_assume((sec_r001254_18_1 >= 0) && (sec_r001254_18_1 <= 255));
  __CPROVER_assume((sec_r001254_18_2 >= 0) && (sec_r001254_18_2 <= 255));
  __CPROVER_assume((sec_r001254_19_1 >= 0) && (sec_r001254_19_1 <= 255));
  __CPROVER_assume((sec_r001254_19_2 >= 0) && (sec_r001254_19_2 <= 255));
  __CPROVER_assume((sec_r001254_20_1 >= 0) && (sec_r001254_20_1 <= 255));
  __CPROVER_assume((sec_r001254_20_2 >= 0) && (sec_r001254_20_2 <= 255));
  __CPROVER_assume((sec_r001254_21_1 >= 0) && (sec_r001254_21_1 <= 255));
  __CPROVER_assume((sec_r001254_21_2 >= 0) && (sec_r001254_21_2 <= 255));
  __CPROVER_assume((sec_r001254_22_1 >= 0) && (sec_r001254_22_1 <= 255));
  __CPROVER_assume((sec_r001254_22_2 >= 0) && (sec_r001254_22_2 <= 255));
  __CPROVER_assume((sec_r001254_23_1 >= 0) && (sec_r001254_23_1 <= 255));
  __CPROVER_assume((sec_r001254_23_2 >= 0) && (sec_r001254_23_2 <= 255));
  struct AudioFrame_R001254_5413_0 st_var_0_1 = {0};
  struct AudioFrame_R001254_5413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001254_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001254_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001254_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001254_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001254_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001254_0_2 + 7) & 15;
  struct EventLog_R001254_5413_1 st_var_1_1 = {0};
  struct EventLog_R001254_5413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001254_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001254_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001254_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001254_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001254_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001254_0_2 + 9) & 15;
  struct Transaction_R001254_5413_2 st_var_2_1 = {0};
  struct Transaction_R001254_5413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001254_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001254_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001254_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001254_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001254_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001254_0_2 + 11) & 15;
  struct DeviceConfig_R001254_5413_3 st_var_3_1 = {0};
  struct DeviceConfig_R001254_5413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001254_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001254_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001254_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001254_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001254_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001254_0_2 + 13) & 15;
  union ColorPixel_R001254_5413_0 u_var_1;
  union ColorPixel_R001254_5413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001254_5413_0(sec_r001254_0_1, pub_r001254_1_1, pub_r001254_2_1, pub_r001254_3_1, pub_r001254_4_1);
  int helper_flow_0_2 = fn_R001254_5413_0(sec_r001254_0_2, pub_r001254_1_2, pub_r001254_2_2, pub_r001254_3_2, pub_r001254_4_2);
  fn_R001254_5413_0_2(sec_r001254_0_1, pub_r001254_1_1, pub_r001254_2_1, pub_r001254_3_1, pub_r001254_4_1, sec_r001254_0_2, pub_r001254_1_2, pub_r001254_2_2, pub_r001254_3_2, pub_r001254_4_2);
  int helper_flow_1_1 = fn_R001254_5413_1(sec_r001254_1_1, sec_r001254_2_1);
  int helper_flow_1_2 = fn_R001254_5413_1(sec_r001254_1_2, sec_r001254_2_2);
  fn_R001254_5413_1_2(sec_r001254_1_1, sec_r001254_2_1, sec_r001254_1_2, sec_r001254_2_2);
  int helper_flow_2_1 = fn_R001254_5413_2(sec_r001254_2_1, pub_r001254_3_1, pub_r001254_4_1, pub_r001254_5_1, pub_r001254_6_1);
  int helper_flow_2_2 = fn_R001254_5413_2(sec_r001254_2_2, pub_r001254_3_2, pub_r001254_4_2, pub_r001254_5_2, pub_r001254_6_2);
  fn_R001254_5413_2_2(sec_r001254_2_1, pub_r001254_3_1, pub_r001254_4_1, pub_r001254_5_1, pub_r001254_6_1, sec_r001254_2_2, pub_r001254_3_2, pub_r001254_4_2, pub_r001254_5_2, pub_r001254_6_2);
  int helper_flow_3_1 = fn_R001254_5413_3(sec_r001254_3_1, sec_r001254_4_1, pub_r001254_5_1);
  int helper_flow_3_2 = fn_R001254_5413_3(sec_r001254_3_2, sec_r001254_4_2, pub_r001254_5_2);
  fn_R001254_5413_3_2(sec_r001254_3_1, sec_r001254_4_1, pub_r001254_5_1, sec_r001254_3_2, sec_r001254_4_2, pub_r001254_5_2);
  int helper_flow_4_1 = fn_R001254_5413_4(sec_r001254_4_1, sec_r001254_5_1, pub_r001254_6_1);
  int helper_flow_4_2 = fn_R001254_5413_4(sec_r001254_4_2, sec_r001254_5_2, pub_r001254_6_2);
  fn_R001254_5413_4_2(sec_r001254_4_1, sec_r001254_5_1, pub_r001254_6_1, sec_r001254_4_2, sec_r001254_5_2, pub_r001254_6_2);
  int helper_flow_5_1 = fn_R001254_5413_5(sec_r001254_5_1, sec_r001254_6_1, pub_r001254_7_1, pub_r001254_8_1, pub_r001254_9_1);
  int helper_flow_5_2 = fn_R001254_5413_5(sec_r001254_5_2, sec_r001254_6_2, pub_r001254_7_2, pub_r001254_8_2, pub_r001254_9_2);
  fn_R001254_5413_5_2(sec_r001254_5_1, sec_r001254_6_1, pub_r001254_7_1, pub_r001254_8_1, pub_r001254_9_1, sec_r001254_5_2, sec_r001254_6_2, pub_r001254_7_2, pub_r001254_8_2, pub_r001254_9_2);
  int stage_v_0_1 = ((pub_r001254_17_1 * 2) + 39) & 63;
  int stage_v_0_2 = ((pub_r001254_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((helper_flow_5_1 * 3) + pub_r001254_9_1) + 32) & 127;
  int stage_v_1_2 = (((helper_flow_5_2 * 3) + pub_r001254_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001254_15_1 * 2) + 32) & 63;
  int stage_v_2_2 = ((pub_r001254_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001254_13_1 * 2) + 22) & 63;
  int stage_v_3_2 = ((pub_r001254_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((sec_r001254_10_1 * 3) + pub_r001254_15_1) + 32) & 127;
  int stage_v_4_2 = (((sec_r001254_10_2 * 3) + pub_r001254_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = (((sec_r001254_0_1 * 3) + pub_r001254_4_1) + 3) & 127;
  int stage_v_5_2 = (((sec_r001254_0_2 * 3) + pub_r001254_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((helper_flow_2_1 * 3) + pub_r001254_8_1) + 23) & 127;
  int stage_v_6_2 = (((helper_flow_2_2 * 3) + pub_r001254_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = (((sec_r001254_19_1 * 3) + pub_r001254_3_1) + 3) & 127;
  int stage_v_7_2 = (((sec_r001254_19_2 * 3) + pub_r001254_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = (((helper_flow_2_1 * 3) + pub_r001254_6_1) + 21) & 127;
  int stage_v_8_2 = (((helper_flow_2_2 * 3) + pub_r001254_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = (((stage_v_6_1 * 3) + pub_r001254_3_1) + 41) & 127;
  int stage_v_9_2 = (((stage_v_6_2 * 3) + pub_r001254_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((stage_v_5_1 * 3) + pub_r001254_12_1) + 31) & 127;
  int stage_v_10_2 = (((stage_v_5_2 * 3) + pub_r001254_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001254_14_1 * 2) + 33) & 63;
  int stage_v_11_2 = ((pub_r001254_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001254_16_1 * 2) + 21) & 63;
  int stage_v_12_2 = ((pub_r001254_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001254_0_1 * 2) + 41) & 63;
  int stage_v_13_2 = ((pub_r001254_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((stage_v_6_1 * 3) + pub_r001254_9_1) + 28) & 127;
  int stage_v_14_2 = (((stage_v_6_2 * 3) + pub_r001254_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((stage_v_5_1 * 3) + pub_r001254_12_1) + 16) & 127;
  int stage_v_15_2 = (((stage_v_5_2 * 3) + pub_r001254_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001254_4_1 * 2) + 49) & 63;
  int stage_v_16_2 = ((pub_r001254_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((sec_r001254_8_1 * 3) + pub_r001254_2_1) + 7) & 127;
  int stage_v_17_2 = (((sec_r001254_8_2 * 3) + pub_r001254_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((stage_v_10_1 * 3) + pub_r001254_0_1) + 3) & 127;
  int stage_v_18_2 = (((stage_v_10_2 * 3) + pub_r001254_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = ((pub_r001254_6_1 * 2) + 33) & 63;
  int stage_v_19_2 = ((pub_r001254_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001254_1_1 * 2) + 8) & 63;
  int stage_v_20_2 = ((pub_r001254_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((sec_r001254_11_1 * 3) + pub_r001254_4_1) + 36) & 127;
  int stage_v_21_2 = (((sec_r001254_11_2 * 3) + pub_r001254_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = (((stage_v_9_1 * 3) + pub_r001254_8_1) + 25) & 127;
  int stage_v_22_2 = (((stage_v_9_2 * 3) + pub_r001254_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = (((sec_r001254_7_1 * 3) + pub_r001254_16_1) + 12) & 127;
  int stage_v_23_2 = (((sec_r001254_7_2 * 3) + pub_r001254_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((sec_r001254_10_1 * 3) + pub_r001254_3_1) + 14) & 127;
  int stage_v_24_2 = (((sec_r001254_10_2 * 3) + pub_r001254_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001254_1_1 * 2) + 41) & 63;
  int stage_v_25_2 = ((pub_r001254_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001254_1_1 * 2) + 39) & 63;
  int stage_v_26_2 = ((pub_r001254_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001254_1_1 * 2) + 8) & 63;
  int stage_v_27_2 = ((pub_r001254_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001254_6_1 * 3) + pub_r001254_10_1) + 17) & 127;
  int stage_v_28_2 = (((sec_r001254_6_2 * 3) + pub_r001254_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((sec_r001254_14_1 * 3) + pub_r001254_4_1) + 45) & 127;
  int stage_v_29_2 = (((sec_r001254_14_2 * 3) + pub_r001254_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((sec_r001254_11_1 * 3) + pub_r001254_3_1) + 21) & 127;
  int stage_v_30_2 = (((sec_r001254_11_2 * 3) + pub_r001254_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((sec_r001254_13_1 * 3) + pub_r001254_1_1) + 11) & 127;
  int stage_v_31_2 = (((sec_r001254_13_2 * 3) + pub_r001254_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((sec_r001254_12_1 * 3) + pub_r001254_5_1) + 40) & 127;
  int stage_v_32_2 = (((sec_r001254_12_2 * 3) + pub_r001254_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = ((pub_r001254_8_1 * 2) + 42) & 63;
  int stage_v_33_2 = ((pub_r001254_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((stage_v_18_1 * 3) + pub_r001254_14_1) + 26) & 127;
  int stage_v_34_2 = (((stage_v_18_2 * 3) + pub_r001254_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = (((stage_v_8_1 * 3) + pub_r001254_13_1) + 17) & 127;
  int stage_v_35_2 = (((stage_v_8_2 * 3) + pub_r001254_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = (((stage_v_28_1 * 3) + pub_r001254_3_1) + 15) & 127;
  int stage_v_36_2 = (((stage_v_28_2 * 3) + pub_r001254_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001254_15_1 * 2) + 25) & 63;
  int stage_v_37_2 = ((pub_r001254_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((sec_r001254_3_1 * 3) + pub_r001254_9_1) + 13) & 127;
  int stage_v_38_2 = (((sec_r001254_3_2 * 3) + pub_r001254_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((stage_v_6_1 * 3) + pub_r001254_13_1) + 28) & 127;
  int stage_v_39_2 = (((stage_v_6_2 * 3) + pub_r001254_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = ((pub_r001254_4_1 * 2) + 15) & 63;
  int stage_v_40_2 = ((pub_r001254_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001254_9_1 * 2) + 25) & 63;
  int stage_v_41_2 = ((pub_r001254_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((sec_r001254_12_1 * 3) + pub_r001254_8_1) + 40) & 127;
  int stage_v_42_2 = (((sec_r001254_12_2 * 3) + pub_r001254_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = (((stage_v_4_1 * 3) + pub_r001254_15_1) + 12) & 127;
  int stage_v_43_2 = (((stage_v_4_2 * 3) + pub_r001254_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((sec_r001254_6_1 * 3) + pub_r001254_7_1) + 9) & 127;
  int stage_v_44_2 = (((sec_r001254_6_2 * 3) + pub_r001254_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = (((stage_v_17_1 * 3) + pub_r001254_17_1) + 18) & 127;
  int stage_v_45_2 = (((stage_v_17_2 * 3) + pub_r001254_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((sec_r001254_14_1 * 3) + pub_r001254_0_1) + 37) & 127;
  int stage_v_46_2 = (((sec_r001254_14_2 * 3) + pub_r001254_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((sec_r001254_1_1 * 3) + pub_r001254_7_1) + 43) & 127;
  int stage_v_47_2 = (((sec_r001254_1_2 * 3) + pub_r001254_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((helper_flow_1_1 * 3) + pub_r001254_1_1) + 22) & 127;
  int stage_v_48_2 = (((helper_flow_1_2 * 3) + pub_r001254_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = (((stage_v_42_1 * 3) + pub_r001254_2_1) + 38) & 127;
  int stage_v_49_2 = (((stage_v_42_2 * 3) + pub_r001254_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = ((pub_r001254_5_1 * 2) + 42) & 63;
  int stage_v_50_2 = ((pub_r001254_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001254_1_1 * 2) + 12) & 63;
  int stage_v_51_2 = ((pub_r001254_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001254_13_1 * 2) + 35) & 63;
  int stage_v_52_2 = ((pub_r001254_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001254_12_1 * 2) + 19) & 63;
  int stage_v_53_2 = ((pub_r001254_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((stage_v_24_1 * 3) + pub_r001254_12_1) + 16) & 127;
  int stage_v_54_2 = (((stage_v_24_2 * 3) + pub_r001254_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((stage_v_35_1 * 3) + pub_r001254_8_1) + 27) & 127;
  int stage_v_55_2 = (((stage_v_35_2 * 3) + pub_r001254_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((stage_v_44_1 * 3) + pub_r001254_0_1) + 12) & 127;
  int stage_v_56_2 = (((stage_v_44_2 * 3) + pub_r001254_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((stage_v_15_1 * 3) + pub_r001254_3_1) + 32) & 127;
  int stage_v_57_2 = (((stage_v_15_2 * 3) + pub_r001254_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((stage_v_1_1 * 3) + pub_r001254_1_1) + 26) & 127;
  int stage_v_58_2 = (((stage_v_1_2 * 3) + pub_r001254_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = ((pub_r001254_15_1 * 2) + 6) & 63;
  int stage_v_59_2 = ((pub_r001254_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((sec_r001254_3_1 * 3) + pub_r001254_7_1) + 45) & 127;
  int stage_v_60_2 = (((sec_r001254_3_2 * 3) + pub_r001254_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((stage_v_58_1 * 3) + pub_r001254_6_1) + 20) & 127;
  int stage_v_61_2 = (((stage_v_58_2 * 3) + pub_r001254_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = (((sec_r001254_23_1 * 3) + pub_r001254_8_1) + 17) & 127;
  int stage_v_62_2 = (((sec_r001254_23_2 * 3) + pub_r001254_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((helper_flow_1_1 * 3) + pub_r001254_8_1) + 13) & 127;
  int stage_v_63_2 = (((helper_flow_1_2 * 3) + pub_r001254_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((stage_v_21_1 * 3) + pub_r001254_9_1) + 19) & 127;
  int stage_v_64_2 = (((stage_v_21_2 * 3) + pub_r001254_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001254_10_1 * 2) + 37) & 63;
  int stage_v_65_2 = ((pub_r001254_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((sec_r001254_7_1 * 3) + pub_r001254_2_1) + 40) & 127;
  int stage_v_66_2 = (((sec_r001254_7_2 * 3) + pub_r001254_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((sec_r001254_20_1 * 3) + pub_r001254_17_1) + 33) & 127;
  int stage_v_67_2 = (((sec_r001254_20_2 * 3) + pub_r001254_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((stage_v_1_1 * 3) + pub_r001254_5_1) + 32) & 127;
  int stage_v_68_2 = (((stage_v_1_2 * 3) + pub_r001254_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001254_17_1 * 2) + 31) & 63;
  int stage_v_69_2 = ((pub_r001254_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((stage_v_6_1 * 3) + pub_r001254_11_1) + 20) & 127;
  int stage_v_70_2 = (((stage_v_6_2 * 3) + pub_r001254_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((sec_r001254_2_1 * 3) + pub_r001254_8_1) + 3) & 127;
  int stage_v_71_2 = (((sec_r001254_2_2 * 3) + pub_r001254_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = (((stage_v_28_1 * 3) + pub_r001254_14_1) + 41) & 127;
  int stage_v_72_2 = (((stage_v_28_2 * 3) + pub_r001254_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = (((stage_v_64_1 * 3) + pub_r001254_16_1) + 9) & 127;
  int stage_v_73_2 = (((stage_v_64_2 * 3) + pub_r001254_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001254_13_1 * 2) + 34) & 63;
  int stage_v_74_2 = ((pub_r001254_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((stage_v_60_1 * 3) + pub_r001254_7_1) + 10) & 127;
  int stage_v_75_2 = (((stage_v_60_2 * 3) + pub_r001254_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((stage_v_21_1 * 3) + pub_r001254_11_1) + 22) & 127;
  int stage_v_76_2 = (((stage_v_21_2 * 3) + pub_r001254_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001254_5_1 * 2) + 10) & 63;
  int stage_v_77_2 = ((pub_r001254_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001254_11_1 * 2) + 46) & 63;
  int stage_v_78_2 = ((pub_r001254_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((sec_r001254_17_1 * 3) + pub_r001254_2_1) + 22) & 127;
  int stage_v_79_2 = (((sec_r001254_17_2 * 3) + pub_r001254_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001254_15_1 * 2) + 40) & 63;
  int stage_v_80_2 = ((pub_r001254_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((stage_v_4_1 * 3) + pub_r001254_4_1) + 42) & 127;
  int stage_v_81_2 = (((stage_v_4_2 * 3) + pub_r001254_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = ((pub_r001254_2_1 * 2) + 40) & 63;
  int stage_v_82_2 = ((pub_r001254_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001254_0_1 * 2) + 6) & 63;
  int stage_v_83_2 = ((pub_r001254_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_1_1 * 3) + pub_r001254_9_1) + 27) & 127;
  int stage_v_84_2 = (((stage_v_1_2 * 3) + pub_r001254_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001254_14_1 * 2) + 46) & 63;
  int stage_v_85_2 = ((pub_r001254_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((stage_v_31_1 * 3) + pub_r001254_17_1) + 33) & 127;
  int stage_v_86_2 = (((stage_v_31_2 * 3) + pub_r001254_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001254_9_1 * 2) + 20) & 63;
  int stage_v_87_2 = ((pub_r001254_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_48_1 * 3) + pub_r001254_2_1) + 28) & 127;
  int stage_v_88_2 = (((stage_v_48_2 * 3) + pub_r001254_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001254_6_1 * 2) + 5) & 63;
  int stage_v_89_2 = ((pub_r001254_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001254_11_1 * 2) + 9) & 63;
  int stage_v_90_2 = ((pub_r001254_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001254_11_1 * 2) + 21) & 63;
  int stage_v_91_2 = ((pub_r001254_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_17_1 * 3) + pub_r001254_13_1) + 28) & 127;
  int stage_v_92_2 = (((stage_v_17_2 * 3) + pub_r001254_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001254_11_1 * 2) + 35) & 63;
  int stage_v_93_2 = ((pub_r001254_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((sec_r001254_22_1 * 3) + pub_r001254_2_1) + 14) & 127;
  int stage_v_94_2 = (((sec_r001254_22_2 * 3) + pub_r001254_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = ((pub_r001254_15_1 * 2) + 21) & 63;
  int stage_v_95_2 = ((pub_r001254_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_58_1 * 3) + pub_r001254_2_1) + 34) & 127;
  int stage_v_96_2 = (((stage_v_58_2 * 3) + pub_r001254_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001254_6_1 * 2) + 40) & 63;
  int stage_v_97_2 = ((pub_r001254_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((helper_flow_5_1 * 3) + pub_r001254_15_1) + 44) & 127;
  int stage_v_98_2 = (((helper_flow_5_2 * 3) + pub_r001254_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((stage_v_62_1 * 3) + pub_r001254_11_1) + 27) & 127;
  int stage_v_99_2 = (((stage_v_62_2 * 3) + pub_r001254_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = (((stage_v_10_1 * 3) + pub_r001254_14_1) + 36) & 127;
  int stage_v_100_2 = (((stage_v_10_2 * 3) + pub_r001254_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = (((stage_v_73_1 * 3) + pub_r001254_8_1) + 15) & 127;
  int stage_v_101_2 = (((stage_v_73_2 * 3) + pub_r001254_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001254_12_1 * 2) + 49) & 63;
  int stage_v_102_2 = ((pub_r001254_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001254_11_1 * 2) + 50) & 63;
  int stage_v_103_2 = ((pub_r001254_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((sec_r001254_10_1 * 3) + pub_r001254_17_1) + 44) & 127;
  int stage_v_104_2 = (((sec_r001254_10_2 * 3) + pub_r001254_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001254_12_1 * 2) + 48) & 63;
  int stage_v_105_2 = ((pub_r001254_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((sec_r001254_12_1 * 3) + pub_r001254_12_1) + 3) & 127;
  int stage_v_106_2 = (((sec_r001254_12_2 * 3) + pub_r001254_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = (((stage_v_30_1 * 3) + pub_r001254_1_1) + 22) & 127;
  int stage_v_107_2 = (((stage_v_30_2 * 3) + pub_r001254_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((sec_r001254_15_1 * 3) + pub_r001254_8_1) + 27) & 127;
  int stage_v_108_2 = (((sec_r001254_15_2 * 3) + pub_r001254_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((stage_v_32_1 * 3) + pub_r001254_3_1) + 5) & 127;
  int stage_v_109_2 = (((stage_v_32_2 * 3) + pub_r001254_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((stage_v_99_1 * 3) + pub_r001254_8_1) + 10) & 127;
  int stage_v_110_2 = (((stage_v_99_2 * 3) + pub_r001254_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001254_6_1 * 2) + 16) & 63;
  int stage_v_111_2 = ((pub_r001254_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001254_5_1 * 2) + 17) & 63;
  int stage_v_112_2 = ((pub_r001254_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001254_12_1 * 2) + 23) & 63;
  int stage_v_113_2 = ((pub_r001254_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_79_1 * 3) + pub_r001254_5_1) + 29) & 127;
  int stage_v_114_2 = (((stage_v_79_2 * 3) + pub_r001254_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((sec_r001254_13_1 * 3) + pub_r001254_16_1) + 36) & 127;
  int stage_v_115_2 = (((sec_r001254_13_2 * 3) + pub_r001254_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001254_16_1 * 2) + 49) & 63;
  int stage_v_116_2 = ((pub_r001254_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001254_1_1 * 2) + 25) & 63;
  int stage_v_117_2 = ((pub_r001254_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((stage_v_30_1 * 3) + pub_r001254_4_1) + 34) & 127;
  int stage_v_118_2 = (((stage_v_30_2 * 3) + pub_r001254_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001254_3_1 * 2) + 43) & 63;
  int stage_v_119_2 = ((pub_r001254_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001254_15_1 * 2) + 12) & 63;
  int stage_v_120_2 = ((pub_r001254_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (((stage_v_115_1 * 3) + pub_r001254_2_1) + 9) & 127;
  int stage_v_121_2 = (((stage_v_115_2 * 3) + pub_r001254_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = ((pub_r001254_12_1 * 2) + 43) & 63;
  int stage_v_122_2 = ((pub_r001254_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_35_1 * 3) + pub_r001254_9_1) + 34) & 127;
  int stage_v_123_2 = (((stage_v_35_2 * 3) + pub_r001254_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = ((pub_r001254_12_1 * 2) + 15) & 63;
  int stage_v_124_2 = ((pub_r001254_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((stage_v_63_1 * 3) + pub_r001254_8_1) + 31) & 127;
  int stage_v_125_2 = (((stage_v_63_2 * 3) + pub_r001254_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = ((pub_r001254_11_1 * 2) + 19) & 63;
  int stage_v_126_2 = ((pub_r001254_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((sec_r001254_12_1 * 3) + pub_r001254_11_1) + 19) & 127;
  int stage_v_127_2 = (((sec_r001254_12_2 * 3) + pub_r001254_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = ((pub_r001254_4_1 * 2) + 15) & 63;
  int stage_v_128_2 = ((pub_r001254_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001254_11_1 * 2) + 18) & 63;
  int stage_v_129_2 = ((pub_r001254_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001254_4_1 * 2) + 47) & 63;
  int stage_v_130_2 = ((pub_r001254_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001254_11_1 * 2) + 40) & 63;
  int stage_v_131_2 = ((pub_r001254_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001254_13_1 * 2) + 27) & 63;
  int stage_v_132_2 = ((pub_r001254_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_1_1 * 3) + pub_r001254_1_1) + 30) & 127;
  int stage_v_133_2 = (((stage_v_1_2 * 3) + pub_r001254_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001254_10_1 * 2) + 5) & 63;
  int stage_v_134_2 = ((pub_r001254_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001254_7_1 * 2) + 15) & 63;
  int stage_v_135_2 = ((pub_r001254_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_118_1 * 3) + pub_r001254_14_1) + 15) & 127;
  int stage_v_136_2 = (((stage_v_118_2 * 3) + pub_r001254_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((sec_r001254_19_1 * 3) + pub_r001254_0_1) + 36) & 127;
  int stage_v_137_2 = (((sec_r001254_19_2 * 3) + pub_r001254_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((sec_r001254_1_1 * 3) + pub_r001254_8_1) + 11) & 127;
  int stage_v_138_2 = (((sec_r001254_1_2 * 3) + pub_r001254_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001254_14_1 * 2) + 34) & 63;
  int stage_v_139_2 = ((pub_r001254_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001254_4_1 * 2) + 39) & 63;
  int stage_v_140_2 = ((pub_r001254_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001254_7_1 * 2) + 39) & 63;
  int stage_v_141_2 = ((pub_r001254_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001254_11_1 * 2) + 36) & 63;
  int stage_v_142_2 = ((pub_r001254_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001254_9_1 * 2) + 50) & 63;
  int stage_v_143_2 = ((pub_r001254_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((sec_r001254_19_1 * 3) + pub_r001254_4_1) + 28) & 127;
  int stage_v_144_2 = (((sec_r001254_19_2 * 3) + pub_r001254_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_10_1 * 3) + pub_r001254_12_1) + 27) & 127;
  int stage_v_145_2 = (((stage_v_10_2 * 3) + pub_r001254_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = (((helper_flow_3_1 * 3) + pub_r001254_0_1) + 21) & 127;
  int stage_v_146_2 = (((helper_flow_3_2 * 3) + pub_r001254_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = ((pub_r001254_3_1 * 2) + 33) & 63;
  int stage_v_147_2 = ((pub_r001254_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001254_3_1 * 2) + 33) & 63;
  int stage_v_148_2 = ((pub_r001254_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001254_3_1 * 2) + 45) & 63;
  int stage_v_149_2 = ((pub_r001254_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((sec_r001254_1_1 * 3) + pub_r001254_0_1) + 29) & 127;
  int stage_v_150_2 = (((sec_r001254_1_2 * 3) + pub_r001254_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((sec_r001254_1_1 * 3) + pub_r001254_9_1) + 22) & 127;
  int stage_v_151_2 = (((sec_r001254_1_2 * 3) + pub_r001254_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = ((pub_r001254_12_1 * 2) + 48) & 63;
  int stage_v_152_2 = ((pub_r001254_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_145_1 * 3) + pub_r001254_7_1) + 3) & 127;
  int stage_v_153_2 = (((stage_v_145_2 * 3) + pub_r001254_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((stage_v_145_1 * 3) + pub_r001254_16_1) + 27) & 127;
  int stage_v_154_2 = (((stage_v_145_2 * 3) + pub_r001254_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((sec_r001254_0_1 * 3) + pub_r001254_0_1) + 12) & 127;
  int stage_v_155_2 = (((sec_r001254_0_2 * 3) + pub_r001254_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((stage_v_22_1 * 3) + pub_r001254_2_1) + 23) & 127;
  int stage_v_156_2 = (((stage_v_22_2 * 3) + pub_r001254_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_56_1 * 3) + pub_r001254_16_1) + 35) & 127;
  int stage_v_157_2 = (((stage_v_56_2 * 3) + pub_r001254_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001254_10_1 * 2) + 42) & 63;
  int stage_v_158_2 = ((pub_r001254_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001254_4_1 * 2) + 7) & 63;
  int stage_v_159_2 = ((pub_r001254_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((stage_v_22_1 * 3) + pub_r001254_1_1) + 41) & 127;
  int stage_v_160_2 = (((stage_v_22_2 * 3) + pub_r001254_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((stage_v_151_1 * 3) + pub_r001254_13_1) + 22) & 127;
  int stage_v_161_2 = (((stage_v_151_2 * 3) + pub_r001254_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001254_6_1 * 2) + 5) & 63;
  int stage_v_162_2 = ((pub_r001254_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001254_5_1 * 2) + 20) & 63;
  int stage_v_163_2 = ((pub_r001254_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001254_11_1 * 2) + 7) & 63;
  int stage_v_164_2 = ((pub_r001254_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_64_1 * 3) + pub_r001254_7_1) + 19) & 127;
  int stage_v_165_2 = (((stage_v_64_2 * 3) + pub_r001254_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001254_3_1 * 2) + 30) & 63;
  int stage_v_166_2 = ((pub_r001254_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_96_1 * 3) + pub_r001254_3_1) + 10) & 127;
  int stage_v_167_2 = (((stage_v_96_2 * 3) + pub_r001254_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((stage_v_18_1 * 3) + pub_r001254_7_1) + 45) & 127;
  int stage_v_168_2 = (((stage_v_18_2 * 3) + pub_r001254_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((stage_v_144_1 * 3) + pub_r001254_17_1) + 40) & 127;
  int stage_v_169_2 = (((stage_v_144_2 * 3) + pub_r001254_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_68_1 * 3) + pub_r001254_14_1) + 14) & 127;
  int stage_v_170_2 = (((stage_v_68_2 * 3) + pub_r001254_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((stage_v_165_1 * 3) + pub_r001254_2_1) + 22) & 127;
  int stage_v_171_2 = (((stage_v_165_2 * 3) + pub_r001254_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((stage_v_8_1 * 3) + pub_r001254_12_1) + 23) & 127;
  int stage_v_172_2 = (((stage_v_8_2 * 3) + pub_r001254_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((sec_r001254_17_1 * 3) + pub_r001254_3_1) + 19) & 127;
  int stage_v_173_2 = (((sec_r001254_17_2 * 3) + pub_r001254_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = (((stage_v_125_1 * 3) + pub_r001254_12_1) + 38) & 127;
  int stage_v_174_2 = (((stage_v_125_2 * 3) + pub_r001254_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = (((stage_v_138_1 * 3) + pub_r001254_8_1) + 40) & 127;
  int stage_v_175_2 = (((stage_v_138_2 * 3) + pub_r001254_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((stage_v_92_1 * 3) + pub_r001254_11_1) + 38) & 127;
  int stage_v_176_2 = (((stage_v_92_2 * 3) + pub_r001254_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((helper_flow_4_1 * 3) + pub_r001254_1_1) + 7) & 127;
  int stage_v_177_2 = (((helper_flow_4_2 * 3) + pub_r001254_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((helper_flow_1_1 * 3) + pub_r001254_7_1) + 34) & 127;
  int stage_v_178_2 = (((helper_flow_1_2 * 3) + pub_r001254_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((helper_flow_2_1 * 3) + pub_r001254_8_1) + 11) & 127;
  int stage_v_179_2 = (((helper_flow_2_2 * 3) + pub_r001254_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((stage_v_57_1 * 3) + pub_r001254_15_1) + 29) & 127;
  int stage_v_180_2 = (((stage_v_57_2 * 3) + pub_r001254_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((stage_v_157_1 * 3) + pub_r001254_13_1) + 13) & 127;
  int stage_v_181_2 = (((stage_v_157_2 * 3) + pub_r001254_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((sec_r001254_9_1 * 3) + pub_r001254_6_1) + 21) & 127;
  int stage_v_182_2 = (((sec_r001254_9_2 * 3) + pub_r001254_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((stage_v_133_1 * 3) + pub_r001254_14_1) + 27) & 127;
  int stage_v_183_2 = (((stage_v_133_2 * 3) + pub_r001254_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_9_1 * 3) + pub_r001254_14_1) + 34) & 127;
  int stage_v_184_2 = (((stage_v_9_2 * 3) + pub_r001254_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = ((pub_r001254_8_1 * 2) + 30) & 63;
  int stage_v_185_2 = ((pub_r001254_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_98_1 * 3) + pub_r001254_10_1) + 42) & 127;
  int stage_v_186_2 = (((stage_v_98_2 * 3) + pub_r001254_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = (((stage_v_94_1 * 3) + pub_r001254_3_1) + 31) & 127;
  int stage_v_187_2 = (((stage_v_94_2 * 3) + pub_r001254_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = ((pub_r001254_12_1 * 2) + 45) & 63;
  int stage_v_188_2 = ((pub_r001254_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_38_1 * 3) + pub_r001254_16_1) + 42) & 127;
  int stage_v_189_2 = (((stage_v_38_2 * 3) + pub_r001254_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = (((stage_v_153_1 * 3) + pub_r001254_12_1) + 25) & 127;
  int stage_v_190_2 = (((stage_v_153_2 * 3) + pub_r001254_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001254_15_1 * 2) + 50) & 63;
  int stage_v_191_2 = ((pub_r001254_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001254_3_1 * 2) + 7) & 63;
  int stage_v_192_2 = ((pub_r001254_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_24_1 * 3) + pub_r001254_3_1) + 39) & 127;
  int stage_v_193_2 = (((stage_v_24_2 * 3) + pub_r001254_3_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((sec_r001254_19_1 * 3) + pub_r001254_7_1) + 13) & 127;
  int stage_v_194_2 = (((sec_r001254_19_2 * 3) + pub_r001254_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((stage_v_64_1 * 3) + pub_r001254_11_1) + 39) & 127;
  int stage_v_195_2 = (((stage_v_64_2 * 3) + pub_r001254_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001254_13_1 * 2) + 17) & 63;
  int stage_v_196_2 = ((pub_r001254_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_6_1 * 3) + pub_r001254_17_1) + 22) & 127;
  int stage_v_197_2 = (((stage_v_6_2 * 3) + pub_r001254_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((stage_v_98_1 * 3) + pub_r001254_14_1) + 9) & 127;
  int stage_v_198_2 = (((stage_v_98_2 * 3) + pub_r001254_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((stage_v_46_1 * 3) + pub_r001254_7_1) + 22) & 127;
  int stage_v_199_2 = (((stage_v_46_2 * 3) + pub_r001254_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001254_7_1 * 2) + 39) & 63;
  int stage_v_200_2 = ((pub_r001254_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001254_0_1 * 2) + 27) & 63;
  int stage_v_201_2 = ((pub_r001254_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_46_1 * 3) + pub_r001254_1_1) + 15) & 127;
  int stage_v_202_2 = (((stage_v_46_2 * 3) + pub_r001254_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = (((stage_v_100_1 * 3) + pub_r001254_16_1) + 24) & 127;
  int stage_v_203_2 = (((stage_v_100_2 * 3) + pub_r001254_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = ((pub_r001254_15_1 * 2) + 12) & 63;
  int stage_v_204_2 = ((pub_r001254_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((stage_v_180_1 * 3) + pub_r001254_12_1) + 10) & 127;
  int stage_v_205_2 = (((stage_v_180_2 * 3) + pub_r001254_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001254_9_1 * 2) + 24) & 63;
  int stage_v_206_2 = ((pub_r001254_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001254_14_1 * 2) + 22) & 63;
  int stage_v_207_2 = ((pub_r001254_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001254_13_1 * 2) + 19) & 63;
  int stage_v_208_2 = ((pub_r001254_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((sec_r001254_6_1 * 3) + pub_r001254_17_1) + 15) & 127;
  int stage_v_209_2 = (((sec_r001254_6_2 * 3) + pub_r001254_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = ((pub_r001254_12_1 * 2) + 7) & 63;
  int stage_v_210_2 = ((pub_r001254_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001254_16_1 * 2) + 7) & 63;
  int stage_v_211_2 = ((pub_r001254_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_137_1 * 3) + pub_r001254_17_1) + 27) & 127;
  int stage_v_212_2 = (((stage_v_137_2 * 3) + pub_r001254_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = ((pub_r001254_16_1 * 2) + 15) & 63;
  int stage_v_213_2 = ((pub_r001254_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_8_1 * 3) + pub_r001254_5_1) + 39) & 127;
  int stage_v_214_2 = (((stage_v_8_2 * 3) + pub_r001254_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = ((pub_r001254_9_1 * 2) + 22) & 63;
  int stage_v_215_2 = ((pub_r001254_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (((stage_v_198_1 * 3) + pub_r001254_13_1) + 5) & 127;
  int stage_v_216_2 = (((stage_v_198_2 * 3) + pub_r001254_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001254_3_1 * 2) + 44) & 63;
  int stage_v_217_2 = ((pub_r001254_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((stage_v_168_1 * 3) + pub_r001254_17_1) + 21) & 127;
  int stage_v_218_2 = (((stage_v_168_2 * 3) + pub_r001254_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((stage_v_48_1 * 3) + pub_r001254_8_1) + 42) & 127;
  int stage_v_219_2 = (((stage_v_48_2 * 3) + pub_r001254_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_175_1 * 3) + pub_r001254_0_1) + 16) & 127;
  int stage_v_220_2 = (((stage_v_175_2 * 3) + pub_r001254_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_60_1 * 3) + pub_r001254_15_1) + 18) & 127;
  int stage_v_221_2 = (((stage_v_60_2 * 3) + pub_r001254_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((sec_r001254_3_1 * 3) + pub_r001254_8_1) + 31) & 127;
  int stage_v_222_2 = (((sec_r001254_3_2 * 3) + pub_r001254_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = (((stage_v_14_1 * 3) + pub_r001254_2_1) + 22) & 127;
  int stage_v_223_2 = (((stage_v_14_2 * 3) + pub_r001254_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = ((pub_r001254_2_1 * 2) + 20) & 63;
  int stage_v_224_2 = ((pub_r001254_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001254_0_1 * 2) + 7) & 63;
  int stage_v_225_2 = ((pub_r001254_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001254_2_1 * 2) + 41) & 63;
  int stage_v_226_2 = ((pub_r001254_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((sec_r001254_12_1 * 3) + pub_r001254_2_1) + 21) & 127;
  int stage_v_227_2 = (((sec_r001254_12_2 * 3) + pub_r001254_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_98_1 * 3) + pub_r001254_6_1) + 42) & 127;
  int stage_v_228_2 = (((stage_v_98_2 * 3) + pub_r001254_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = (((stage_v_10_1 * 3) + pub_r001254_11_1) + 14) & 127;
  int stage_v_229_2 = (((stage_v_10_2 * 3) + pub_r001254_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((sec_r001254_2_1 * 3) + pub_r001254_13_1) + 16) & 127;
  int stage_v_230_2 = (((sec_r001254_2_2 * 3) + pub_r001254_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = (((sec_r001254_21_1 * 3) + pub_r001254_12_1) + 32) & 127;
  int stage_v_231_2 = (((sec_r001254_21_2 * 3) + pub_r001254_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001254_5_1 * 2) + 15) & 63;
  int stage_v_232_2 = ((pub_r001254_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001254_15_1 * 2) + 36) & 63;
  int stage_v_233_2 = ((pub_r001254_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001254_0_1 * 2) + 16) & 63;
  int stage_v_234_2 = ((pub_r001254_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001254_10_1 * 2) + 47) & 63;
  int stage_v_235_2 = ((pub_r001254_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = (((stage_v_44_1 * 3) + pub_r001254_6_1) + 13) & 127;
  int stage_v_236_2 = (((stage_v_44_2 * 3) + pub_r001254_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = ((pub_r001254_4_1 * 2) + 47) & 63;
  int stage_v_237_2 = ((pub_r001254_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001254_1_1 * 2) + 44) & 63;
  int stage_v_238_2 = ((pub_r001254_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((stage_v_171_1 * 3) + pub_r001254_7_1) + 32) & 127;
  int stage_v_239_2 = (((stage_v_171_2 * 3) + pub_r001254_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((stage_v_62_1 * 3) + pub_r001254_17_1) + 43) & 127;
  int stage_v_240_2 = (((stage_v_62_2 * 3) + pub_r001254_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_178_1 * 3) + pub_r001254_15_1) + 38) & 127;
  int stage_v_241_2 = (((stage_v_178_2 * 3) + pub_r001254_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001254_8_1 * 2) + 8) & 63;
  int stage_v_242_2 = ((pub_r001254_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001254_13_1 * 2) + 41) & 63;
  int stage_v_243_2 = ((pub_r001254_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001254_1_1 * 2) + 28) & 63;
  int stage_v_244_2 = ((pub_r001254_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001254_14_1 * 2) + 30) & 63;
  int stage_v_245_2 = ((pub_r001254_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001254_17_1 * 2) + 42) & 63;
  int stage_v_246_2 = ((pub_r001254_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((stage_v_109_1 * 3) + pub_r001254_11_1) + 10) & 127;
  int stage_v_247_2 = (((stage_v_109_2 * 3) + pub_r001254_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001254_3_1 * 2) + 23) & 63;
  int stage_v_248_2 = ((pub_r001254_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001254_0_1 * 2) + 18) & 63;
  int stage_v_249_2 = ((pub_r001254_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001254_5_1 * 2) + 40) & 63;
  int stage_v_250_2 = ((pub_r001254_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((stage_v_157_1 * 3) + pub_r001254_8_1) + 31) & 127;
  int stage_v_251_2 = (((stage_v_157_2 * 3) + pub_r001254_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001254_7_1 * 2) + 39) & 63;
  int stage_v_252_2 = ((pub_r001254_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001254_11_1 * 2) + 36) & 63;
  int stage_v_253_2 = ((pub_r001254_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001254_15_1 * 2) + 27) & 63;
  int stage_v_254_2 = ((pub_r001254_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = (((sec_r001254_4_1 * 3) + pub_r001254_5_1) + 37) & 127;
  int stage_v_255_2 = (((sec_r001254_4_2 * 3) + pub_r001254_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001254_11_1 * 2) + 37) & 63;
  int stage_v_256_2 = ((pub_r001254_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001254_15_1 * 2) + 41) & 63;
  int stage_v_257_2 = ((pub_r001254_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001254_17_1 * 2) + 36) & 63;
  int stage_v_258_2 = ((pub_r001254_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = (((stage_v_171_1 * 3) + pub_r001254_4_1) + 7) & 127;
  int stage_v_259_2 = (((stage_v_171_2 * 3) + pub_r001254_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = (((sec_r001254_14_1 * 3) + pub_r001254_11_1) + 37) & 127;
  int stage_v_260_2 = (((sec_r001254_14_2 * 3) + pub_r001254_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = ((pub_r001254_4_1 * 2) + 22) & 63;
  int stage_v_261_2 = ((pub_r001254_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001254_8_1 * 2) + 16) & 63;
  int stage_v_262_2 = ((pub_r001254_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001254_7_1 * 2) + 15) & 63;
  int stage_v_263_2 = ((pub_r001254_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001254_14_1 * 2) + 10) & 63;
  int stage_v_264_2 = ((pub_r001254_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((helper_flow_4_1 * 3) + pub_r001254_14_1) + 42) & 127;
  int stage_v_265_2 = (((helper_flow_4_2 * 3) + pub_r001254_14_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_36_1 * 3) + pub_r001254_7_1) + 18) & 127;
  int stage_v_266_2 = (((stage_v_36_2 * 3) + pub_r001254_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = ((pub_r001254_12_1 * 2) + 40) & 63;
  int stage_v_267_2 = ((pub_r001254_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((stage_v_229_1 * 3) + pub_r001254_2_1) + 31) & 127;
  int stage_v_268_2 = (((stage_v_229_2 * 3) + pub_r001254_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001254_17_1 * 2) + 9) & 63;
  int stage_v_269_2 = ((pub_r001254_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001254_0_1 * 2) + 17) & 63;
  int stage_v_270_2 = ((pub_r001254_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001254_17_1 * 2) + 49) & 63;
  int stage_v_271_2 = ((pub_r001254_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_197_1 * 3) + pub_r001254_0_1) + 36) & 127;
  int stage_v_272_2 = (((stage_v_197_2 * 3) + pub_r001254_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((stage_v_31_1 * 3) + pub_r001254_7_1) + 24) & 127;
  int stage_v_273_2 = (((stage_v_31_2 * 3) + pub_r001254_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001254_11_1 * 2) + 14) & 63;
  int stage_v_274_2 = ((pub_r001254_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = (((sec_r001254_3_1 * 3) + pub_r001254_11_1) + 7) & 127;
  int stage_v_275_2 = (((sec_r001254_3_2 * 3) + pub_r001254_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = ((pub_r001254_14_1 * 2) + 36) & 63;
  int stage_v_276_2 = ((pub_r001254_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001254_14_1 * 2) + 9) & 63;
  int stage_v_277_2 = ((pub_r001254_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((helper_flow_0_1 * 3) + pub_r001254_13_1) + 37) & 127;
  int stage_v_278_2 = (((helper_flow_0_2 * 3) + pub_r001254_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_115_1 * 3) + pub_r001254_5_1) + 16) & 127;
  int stage_v_279_2 = (((stage_v_115_2 * 3) + pub_r001254_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = ((pub_r001254_14_1 * 2) + 17) & 63;
  int stage_v_280_2 = ((pub_r001254_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001254_8_1 * 2) + 13) & 63;
  int stage_v_281_2 = ((pub_r001254_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001254_8_1 * 2) + 11) & 63;
  int stage_v_282_2 = ((pub_r001254_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001254_10_1 * 2) + 11) & 63;
  int stage_v_283_2 = ((pub_r001254_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = (((sec_r001254_20_1 * 3) + pub_r001254_11_1) + 38) & 127;
  int stage_v_284_2 = (((sec_r001254_20_2 * 3) + pub_r001254_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001254_0_1 * 2) + 45) & 63;
  int stage_v_285_2 = ((pub_r001254_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((stage_v_71_1 * 3) + pub_r001254_1_1) + 23) & 127;
  int stage_v_286_2 = (((stage_v_71_2 * 3) + pub_r001254_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = ((pub_r001254_6_1 * 2) + 29) & 63;
  int stage_v_287_2 = ((pub_r001254_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001254_11_1 * 2) + 23) & 63;
  int stage_v_288_2 = ((pub_r001254_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_96_1 * 3) + pub_r001254_10_1) + 32) & 127;
  int stage_v_289_2 = (((stage_v_96_2 * 3) + pub_r001254_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = ((pub_r001254_16_1 * 2) + 41) & 63;
  int stage_v_290_2 = ((pub_r001254_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001254_16_1 * 2) + 17) & 63;
  int stage_v_291_2 = ((pub_r001254_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001254_12_1 * 2) + 40) & 63;
  int stage_v_292_2 = ((pub_r001254_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001254_4_1 * 2) + 22) & 63;
  int stage_v_293_2 = ((pub_r001254_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001254_13_1 * 2) + 28) & 63;
  int stage_v_294_2 = ((pub_r001254_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((sec_r001254_9_1 * 3) + pub_r001254_10_1) + 25) & 127;
  int stage_v_295_2 = (((sec_r001254_9_2 * 3) + pub_r001254_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001254_12_1 * 2) + 24) & 63;
  int stage_v_296_2 = ((pub_r001254_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = (((stage_v_76_1 * 3) + pub_r001254_17_1) + 6) & 127;
  int stage_v_297_2 = (((stage_v_76_2 * 3) + pub_r001254_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((stage_v_168_1 * 3) + pub_r001254_7_1) + 13) & 127;
  int stage_v_298_2 = (((stage_v_168_2 * 3) + pub_r001254_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001254_3_1 * 2) + 6) & 63;
  int stage_v_299_2 = ((pub_r001254_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((stage_v_177_1 * 3) + pub_r001254_15_1) + 37) & 127;
  int stage_v_300_2 = (((stage_v_177_2 * 3) + pub_r001254_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = ((pub_r001254_10_1 * 2) + 41) & 63;
  int stage_v_301_2 = ((pub_r001254_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((stage_v_32_1 * 3) + pub_r001254_12_1) + 4) & 127;
  int stage_v_302_2 = (((stage_v_32_2 * 3) + pub_r001254_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = ((pub_r001254_2_1 * 2) + 13) & 63;
  int stage_v_303_2 = ((pub_r001254_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = (((stage_v_157_1 * 3) + pub_r001254_13_1) + 32) & 127;
  int stage_v_304_2 = (((stage_v_157_2 * 3) + pub_r001254_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001254_16_1 * 2) + 23) & 63;
  int stage_v_305_2 = ((pub_r001254_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_219_1 * 3) + pub_r001254_1_1) + 11) & 127;
  int stage_v_306_2 = (((stage_v_219_2 * 3) + pub_r001254_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = (((stage_v_223_1 * 3) + pub_r001254_13_1) + 4) & 127;
  int stage_v_307_2 = (((stage_v_223_2 * 3) + pub_r001254_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001254_2_1 * 2) + 40) & 63;
  int stage_v_308_2 = ((pub_r001254_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_6_1 * 3) + pub_r001254_0_1) + 36) & 127;
  int stage_v_309_2 = (((stage_v_6_2 * 3) + pub_r001254_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001254_10_1 * 2) + 34) & 63;
  int stage_v_310_2 = ((pub_r001254_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001254_14_1 * 2) + 12) & 63;
  int stage_v_311_2 = ((pub_r001254_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = (((stage_v_194_1 * 3) + pub_r001254_8_1) + 41) & 127;
  int stage_v_312_2 = (((stage_v_194_2 * 3) + pub_r001254_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001254_14_1 * 2) + 46) & 63;
  int stage_v_313_2 = ((pub_r001254_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_14_1 * 3) + pub_r001254_16_1) + 26) & 127;
  int stage_v_314_2 = (((stage_v_14_2 * 3) + pub_r001254_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_10_1 * 3) + pub_r001254_11_1) + 38) & 127;
  int stage_v_315_2 = (((stage_v_10_2 * 3) + pub_r001254_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = ((pub_r001254_10_1 * 2) + 7) & 63;
  int stage_v_316_2 = ((pub_r001254_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = (((stage_v_101_1 * 3) + pub_r001254_0_1) + 45) & 127;
  int stage_v_317_2 = (((stage_v_101_2 * 3) + pub_r001254_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_56_1 * 3) + pub_r001254_16_1) + 8) & 127;
  int stage_v_318_2 = (((stage_v_56_2 * 3) + pub_r001254_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((stage_v_17_1 * 3) + pub_r001254_16_1) + 16) & 127;
  int stage_v_319_2 = (((stage_v_17_2 * 3) + pub_r001254_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = (((stage_v_265_1 * 3) + pub_r001254_7_1) + 19) & 127;
  int stage_v_320_2 = (((stage_v_265_2 * 3) + pub_r001254_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = ((pub_r001254_1_1 * 2) + 45) & 63;
  int stage_v_321_2 = ((pub_r001254_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = (((stage_v_88_1 * 3) + pub_r001254_6_1) + 3) & 127;
  int stage_v_322_2 = (((stage_v_88_2 * 3) + pub_r001254_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = (((stage_v_73_1 * 3) + pub_r001254_9_1) + 12) & 127;
  int stage_v_323_2 = (((stage_v_73_2 * 3) + pub_r001254_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((stage_v_315_1 * 3) + pub_r001254_13_1) + 39) & 127;
  int stage_v_324_2 = (((stage_v_315_2 * 3) + pub_r001254_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((sec_r001254_10_1 * 3) + pub_r001254_10_1) + 13) & 127;
  int stage_v_325_2 = (((sec_r001254_10_2 * 3) + pub_r001254_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_42_1 * 3) + pub_r001254_13_1) + 27) & 127;
  int stage_v_326_2 = (((stage_v_42_2 * 3) + pub_r001254_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = (((stage_v_92_1 * 3) + pub_r001254_15_1) + 36) & 127;
  int stage_v_327_2 = (((stage_v_92_2 * 3) + pub_r001254_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = ((pub_r001254_1_1 * 2) + 10) & 63;
  int stage_v_328_2 = ((pub_r001254_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = (((stage_v_123_1 * 3) + pub_r001254_7_1) + 23) & 127;
  int stage_v_329_2 = (((stage_v_123_2 * 3) + pub_r001254_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = ((pub_r001254_15_1 * 2) + 5) & 63;
  int stage_v_330_2 = ((pub_r001254_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001254_12_1 * 2) + 42) & 63;
  int stage_v_331_2 = ((pub_r001254_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_216_1 * 3) + pub_r001254_16_1) + 28) & 127;
  int stage_v_332_2 = (((stage_v_216_2 * 3) + pub_r001254_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = ((pub_r001254_12_1 * 2) + 40) & 63;
  int stage_v_333_2 = ((pub_r001254_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_177_1 * 3) + pub_r001254_6_1) + 10) & 127;
  int stage_v_334_2 = (((stage_v_177_2 * 3) + pub_r001254_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((stage_v_62_1 * 3) + pub_r001254_11_1) + 35) & 127;
  int stage_v_335_2 = (((stage_v_62_2 * 3) + pub_r001254_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_229_1 * 3) + pub_r001254_4_1) + 40) & 127;
  int stage_v_336_2 = (((stage_v_229_2 * 3) + pub_r001254_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = ((pub_r001254_9_1 * 2) + 16) & 63;
  int stage_v_337_2 = ((pub_r001254_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = (((stage_v_109_1 * 3) + pub_r001254_1_1) + 24) & 127;
  int stage_v_338_2 = (((stage_v_109_2 * 3) + pub_r001254_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((stage_v_251_1 * 3) + pub_r001254_4_1) + 36) & 127;
  int stage_v_339_2 = (((stage_v_251_2 * 3) + pub_r001254_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001254_3_1 * 2) + 30) & 63;
  int stage_v_340_2 = ((pub_r001254_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001254_16_1 * 2) + 18) & 63;
  int stage_v_341_2 = ((pub_r001254_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001254_17_1 * 2) + 39) & 63;
  int stage_v_342_2 = ((pub_r001254_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001254_14_1 * 2) + 19) & 63;
  int stage_v_343_2 = ((pub_r001254_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001254_11_1 * 2) + 37) & 63;
  int stage_v_344_2 = ((pub_r001254_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((sec_r001254_10_1 * 3) + pub_r001254_3_1) + 23) & 127;
  int stage_v_345_2 = (((sec_r001254_10_2 * 3) + pub_r001254_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = ((pub_r001254_14_1 * 2) + 11) & 63;
  int stage_v_346_2 = ((pub_r001254_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001254_17_1 * 2) + 18) & 63;
  int stage_v_347_2 = ((pub_r001254_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001254_3_1 * 2) + 47) & 63;
  int stage_v_348_2 = ((pub_r001254_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001254_14_1 * 2) + 34) & 63;
  int stage_v_349_2 = ((pub_r001254_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((pub_r001254_7_1 * 2) + 18) & 63;
  int stage_v_350_2 = ((pub_r001254_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001254_15_1 * 2) + 6) & 63;
  int stage_v_351_2 = ((pub_r001254_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001254_17_1 * 2) + 43) & 63;
  int stage_v_352_2 = ((pub_r001254_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = (((stage_v_155_1 * 3) + pub_r001254_3_1) + 21) & 127;
  int stage_v_353_2 = (((stage_v_155_2 * 3) + pub_r001254_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((stage_v_153_1 * 3) + pub_r001254_1_1) + 32) & 127;
  int stage_v_354_2 = (((stage_v_153_2 * 3) + pub_r001254_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_88_1 * 3) + pub_r001254_0_1) + 35) & 127;
  int stage_v_355_2 = (((stage_v_88_2 * 3) + pub_r001254_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001254_12_1 * 2) + 9) & 63;
  int stage_v_356_2 = ((pub_r001254_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = (((stage_v_219_1 * 3) + pub_r001254_6_1) + 11) & 127;
  int stage_v_357_2 = (((stage_v_219_2 * 3) + pub_r001254_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((stage_v_39_1 * 3) + pub_r001254_1_1) + 43) & 127;
  int stage_v_358_2 = (((stage_v_39_2 * 3) + pub_r001254_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = (((stage_v_125_1 * 3) + pub_r001254_12_1) + 8) & 127;
  int stage_v_359_2 = (((stage_v_125_2 * 3) + pub_r001254_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((stage_v_203_1 * 3) + pub_r001254_6_1) + 42) & 127;
  int stage_v_360_2 = (((stage_v_203_2 * 3) + pub_r001254_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_195_1 * 3) + pub_r001254_10_1) + 33) & 127;
  int stage_v_361_2 = (((stage_v_195_2 * 3) + pub_r001254_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((stage_v_198_1 * 3) + pub_r001254_8_1) + 16) & 127;
  int stage_v_362_2 = (((stage_v_198_2 * 3) + pub_r001254_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = (((sec_r001254_16_1 * 3) + pub_r001254_14_1) + 33) & 127;
  int stage_v_363_2 = (((sec_r001254_16_2 * 3) + pub_r001254_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_198_1 * 3) + pub_r001254_2_1) + 43) & 127;
  int stage_v_364_2 = (((stage_v_198_2 * 3) + pub_r001254_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((stage_v_110_1 * 3) + pub_r001254_1_1) + 17) & 127;
  int stage_v_365_2 = (((stage_v_110_2 * 3) + pub_r001254_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = (((stage_v_123_1 * 3) + pub_r001254_15_1) + 10) & 127;
  int stage_v_366_2 = (((stage_v_123_2 * 3) + pub_r001254_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_144_1 * 3) + pub_r001254_14_1) + 36) & 127;
  int stage_v_367_2 = (((stage_v_144_2 * 3) + pub_r001254_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001254_14_1 * 2) + 36) & 63;
  int stage_v_368_2 = ((pub_r001254_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001254_1_1 * 2) + 39) & 63;
  int stage_v_369_2 = ((pub_r001254_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001254_12_1 * 2) + 19) & 63;
  int stage_v_370_2 = ((pub_r001254_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001254_8_1 * 2) + 20) & 63;
  int stage_v_371_2 = ((pub_r001254_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001254_15_1 * 2) + 48) & 63;
  int stage_v_372_2 = ((pub_r001254_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001254_3_1 * 2) + 5) & 63;
  int stage_v_373_2 = ((pub_r001254_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_115_1 * 3) + pub_r001254_7_1) + 44) & 127;
  int stage_v_374_2 = (((stage_v_115_2 * 3) + pub_r001254_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_339_1 * 3) + pub_r001254_2_1) + 40) & 127;
  int stage_v_375_2 = (((stage_v_339_2 * 3) + pub_r001254_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_170_1 * 3) + pub_r001254_14_1) + 8) & 127;
  int stage_v_376_2 = (((stage_v_170_2 * 3) + pub_r001254_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((stage_v_54_1 * 3) + pub_r001254_5_1) + 14) & 127;
  int stage_v_377_2 = (((stage_v_54_2 * 3) + pub_r001254_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_222_1 * 3) + pub_r001254_7_1) + 12) & 127;
  int stage_v_378_2 = (((stage_v_222_2 * 3) + pub_r001254_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_170_1 * 3) + pub_r001254_5_1) + 26) & 127;
  int stage_v_379_2 = (((stage_v_170_2 * 3) + pub_r001254_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_92_1 * 3) + pub_r001254_2_1) + 42) & 127;
  int stage_v_380_2 = (((stage_v_92_2 * 3) + pub_r001254_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_326_1 * 3) + pub_r001254_10_1) + 32) & 127;
  int stage_v_381_2 = (((stage_v_326_2 * 3) + pub_r001254_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001254_5_1 * 2) + 5) & 63;
  int stage_v_382_2 = ((pub_r001254_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001254_9_1 * 2) + 15) & 63;
  int stage_v_383_2 = ((pub_r001254_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = (((stage_v_375_1 * 3) + pub_r001254_10_1) + 39) & 127;
  int stage_v_384_2 = (((stage_v_375_2 * 3) + pub_r001254_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = (((stage_v_197_1 * 3) + pub_r001254_10_1) + 44) & 127;
  int stage_v_385_2 = (((stage_v_197_2 * 3) + pub_r001254_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = ((pub_r001254_2_1 * 2) + 34) & 63;
  int stage_v_386_2 = ((pub_r001254_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_309_1 * 3) + pub_r001254_11_1) + 5) & 127;
  int stage_v_387_2 = (((stage_v_309_2 * 3) + pub_r001254_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001254_15_1 * 2) + 39) & 63;
  int stage_v_388_2 = ((pub_r001254_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001254_4_1 * 2) + 31) & 63;
  int stage_v_389_2 = ((pub_r001254_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((stage_v_99_1 * 3) + pub_r001254_0_1) + 22) & 127;
  int stage_v_390_2 = (((stage_v_99_2 * 3) + pub_r001254_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = ((pub_r001254_11_1 * 2) + 40) & 63;
  int stage_v_391_2 = ((pub_r001254_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = (((helper_flow_3_1 * 3) + pub_r001254_5_1) + 16) & 127;
  int stage_v_392_2 = (((helper_flow_3_2 * 3) + pub_r001254_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = ((pub_r001254_3_1 * 2) + 35) & 63;
  int stage_v_393_2 = ((pub_r001254_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = (((stage_v_363_1 * 3) + pub_r001254_11_1) + 32) & 127;
  int stage_v_394_2 = (((stage_v_363_2 * 3) + pub_r001254_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = ((pub_r001254_12_1 * 2) + 10) & 63;
  int stage_v_395_2 = ((pub_r001254_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001254_2_1 * 2) + 15) & 63;
  int stage_v_396_2 = ((pub_r001254_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = (((stage_v_260_1 * 3) + pub_r001254_17_1) + 17) & 127;
  int stage_v_397_2 = (((stage_v_260_2 * 3) + pub_r001254_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = (((stage_v_339_1 * 3) + pub_r001254_3_1) + 17) & 127;
  int stage_v_398_2 = (((stage_v_339_2 * 3) + pub_r001254_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = (((stage_v_114_1 * 3) + pub_r001254_7_1) + 43) & 127;
  int stage_v_399_2 = (((stage_v_114_2 * 3) + pub_r001254_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = (((stage_v_157_1 * 3) + pub_r001254_13_1) + 15) & 127;
  int stage_v_400_2 = (((stage_v_157_2 * 3) + pub_r001254_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = ((pub_r001254_11_1 * 2) + 30) & 63;
  int stage_v_401_2 = ((pub_r001254_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = (((stage_v_98_1 * 3) + pub_r001254_0_1) + 25) & 127;
  int stage_v_402_2 = (((stage_v_98_2 * 3) + pub_r001254_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = ((pub_r001254_3_1 * 2) + 29) & 63;
  int stage_v_403_2 = ((pub_r001254_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001254_17_1 != sec_r001254_17_2);
  __CPROVER_assume(sec_r001254_11_1 != sec_r001254_11_2);
  __CPROVER_assume(sec_r001254_12_1 != sec_r001254_12_2);
  __CPROVER_assume(sec_r001254_1_1 != sec_r001254_1_2);
  __CPROVER_assume(pub_r001254_0_1 == pub_r001254_0_2);
  __CPROVER_assume(sec_r001254_13_1 != sec_r001254_13_2);
  __CPROVER_assume(sec_r001254_16_1 != sec_r001254_16_2);
  __CPROVER_assume(pub_r001254_8_1 == pub_r001254_8_2);
  __CPROVER_assume(pub_r001254_15_1 == pub_r001254_15_2);
  __CPROVER_assume(pub_r001254_12_1 == pub_r001254_12_2);
  __CPROVER_assume(sec_r001254_5_1 != sec_r001254_5_2);
  __CPROVER_assume(sec_r001254_15_1 != sec_r001254_15_2);
  __CPROVER_assume(sec_r001254_2_1 != sec_r001254_2_2);
  __CPROVER_assume(pub_r001254_9_1 == pub_r001254_9_2);
  __CPROVER_assume(pub_r001254_1_1 == pub_r001254_1_2);
  __CPROVER_assume(sec_r001254_4_1 != sec_r001254_4_2);
  __CPROVER_assume(pub_r001254_2_1 == pub_r001254_2_2);
  __CPROVER_assume(sec_r001254_18_1 != sec_r001254_18_2);
  __CPROVER_assume(sec_r001254_0_1 != sec_r001254_0_2);
  __CPROVER_assume(pub_r001254_6_1 == pub_r001254_6_2);
  __CPROVER_assume(pub_r001254_3_1 == pub_r001254_3_2);
  __CPROVER_assume(sec_r001254_9_1 != sec_r001254_9_2);
  __CPROVER_assume(sec_r001254_20_1 != sec_r001254_20_2);
  __CPROVER_assume(sec_r001254_14_1 != sec_r001254_14_2);
  __CPROVER_assume(sec_r001254_22_1 != sec_r001254_22_2);
  __CPROVER_assume(pub_r001254_5_1 == pub_r001254_5_2);
  __CPROVER_assume(pub_r001254_4_1 == pub_r001254_4_2);
  __CPROVER_assume(sec_r001254_7_1 != sec_r001254_7_2);
  __CPROVER_assume(pub_r001254_13_1 == pub_r001254_13_2);
  __CPROVER_assume(sec_r001254_3_1 != sec_r001254_3_2);
  __CPROVER_assume(pub_r001254_11_1 == pub_r001254_11_2);
  __CPROVER_assume(sec_r001254_6_1 != sec_r001254_6_2);
  __CPROVER_assume(sec_r001254_19_1 != sec_r001254_19_2);
  __CPROVER_assume(pub_r001254_7_1 == pub_r001254_7_2);
  __CPROVER_assume(pub_r001254_14_1 == pub_r001254_14_2);
  __CPROVER_assume(pub_r001254_17_1 == pub_r001254_17_2);
  __CPROVER_assume(sec_r001254_8_1 != sec_r001254_8_2);
  __CPROVER_assume(sec_r001254_23_1 != sec_r001254_23_2);
  __CPROVER_assume(pub_r001254_16_1 == pub_r001254_16_2);
  __CPROVER_assume(sec_r001254_21_1 != sec_r001254_21_2);
  __CPROVER_assume(pub_r001254_10_1 == pub_r001254_10_2);
  __CPROVER_assume(sec_r001254_10_1 != sec_r001254_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.stop_bits == st_var_3_2.stop_bits);
  assert(st_var_3_1.parity == st_var_3_2.parity);
  assert(st_var_3_1.timeout == st_var_3_2.timeout);
  assert(st_var_3_1.baud_rate == st_var_3_2.baud_rate);
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
  assert(stage_v_383_1 == stage_v_383_2);
  assert(stage_v_384_1 == stage_v_384_2);
  assert(stage_v_385_1 == stage_v_385_2);
  assert(stage_v_386_1 == stage_v_386_2);
  assert(stage_v_387_1 == stage_v_387_2);
  assert(stage_v_388_1 == stage_v_388_2);
  assert(stage_v_389_1 == stage_v_389_2);
  assert(stage_v_390_1 == stage_v_390_2);
  assert(stage_v_391_1 == stage_v_391_2);
  assert(stage_v_392_1 == stage_v_392_2);
  assert(stage_v_393_1 == stage_v_393_2);
  assert(stage_v_394_1 == stage_v_394_2);
  assert(stage_v_395_1 == stage_v_395_2);
  assert(stage_v_396_1 == stage_v_396_2);
  assert(stage_v_397_1 == stage_v_397_2);
  assert(stage_v_398_1 == stage_v_398_2);
  assert(stage_v_399_1 == stage_v_399_2);
  assert(stage_v_400_1 == stage_v_400_2);
  assert(stage_v_401_1 == stage_v_401_2);
  assert(stage_v_402_1 == stage_v_402_2);
  assert(stage_v_403_1 == stage_v_403_2);
}


