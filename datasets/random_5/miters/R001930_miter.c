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
struct AudioFrame_R001930_3013_0
{
  unsigned char sample_rate;
  int rms;
  unsigned char gain;
  short envelope;
  int peak;
  int channels;
  int buffer[3];
};
struct SensorNode_R001930_3013_1
{
  int calib;
  unsigned char offset;
  short status;
  int buffer[3];
};
struct Transaction_R001930_3013_2
{
  int status;
  short auth_code;
  int account_id;
  int fee;
  int buffer[3];
};
struct DeviceConfig_R001930_3013_3
{
  int baud_rate;
  int stop_bits;
  unsigned char timeout;
  int parity;
  short id;
  int buffer[3];
};
union ColorPixel_R001930_3013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001930_3013_1
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
void fn_R001930_3013_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001930_3013_3 st_1 = {0};
  struct DeviceConfig_R001930_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int vector_41_1 = 0;
  int vector_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_41_1 = ((vector_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_41_2 = ((vector_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_41_1) & 127;
    acc_2 = (acc_2 + vector_41_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_13_1 = local_arr_1[aux_1 % 3];
  int threshold_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_41_1 == vector_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_13_1 == threshold_13_2);
}

int fn_R001930_3013_0(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001930_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int vector_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_41 = ((vector_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_41) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int threshold_13 = local_arr[aux % 3];
  acc = (acc + (threshold_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001930_3013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st_1 = {0};
  struct SensorNode_R001930_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int bound_39_1 = 0;
  int bound_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_39_1 = ((bound_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_39_2 = ((bound_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_39_1) & 127;
    acc_2 = (acc_2 + bound_39_2) & 127;
  }

  int quantum_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_98_1) & 63;
  aux_2 = (aux_2 + quantum_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_39_1 == bound_39_2);
  assert(quantum_98_1 == quantum_98_2);
}

int fn_R001930_3013_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int bound_39 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_39 = ((bound_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_39) & 127;
  }

  int quantum_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001930_3013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001930_3013_0 st_1 = {0};
  struct AudioFrame_R001930_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int checksum_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_16_1 > 42)
  {
    acc_1 = ((acc_1 + (checksum_16_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_16_2 > 42)
  {
    acc_2 = ((acc_2 + (checksum_16_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_26_1 = local_arr_1[aux_1 % 3];
  int delta_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_26_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_53_1 = 0;
  int offset_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_53_1 = ((offset_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_53_2 = ((offset_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_53_1) & 127;
    acc_2 = (acc_2 + offset_53_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_16_1 == checksum_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_26_1 == delta_26_2);
  assert(offset_53_1 == offset_53_2);
}

int fn_R001930_3013_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001930_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int checksum_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_16 > 42)
  {
    acc = ((acc + (checksum_16 * 2)) + 5) & 127;
    aux ^= checksum_16 & 15;
  }
  else
  {
    acc = ((acc - checksum_16) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_26 = local_arr[aux % 3];
  acc = (acc + (delta_26 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_53 = ((offset_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_53) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001930_3013_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st_1 = {0};
  struct SensorNode_R001930_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_62_1 = local_arr_1[aux_1 % 3];
  int damping_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_62_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_62_1 == damping_62_2);
}

int fn_R001930_3013_3(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int damping_62 = local_arr[aux % 3];
  acc = (acc + (damping_62 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001930_3013_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001930_3013_2 st_1 = {0};
  struct Transaction_R001930_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int factor_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_63_1) & 63;
  aux_2 = (aux_2 + factor_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_15_1 > 21)
  {
    acc_1 = ((acc_1 + (vector_15_1 * 2)) + 5) & 127;
    aux_1 ^= vector_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_15_2 > 21)
  {
    acc_2 = ((acc_2 + (vector_15_2 * 2)) + 5) & 127;
    aux_2 ^= vector_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_63_1 == factor_63_2);
  assert(vector_15_1 == vector_15_2);
}

int fn_R001930_3013_4(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001930_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int factor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_63) & 63;
  acc ^= aux;
  int vector_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_15 > 21)
  {
    acc = ((acc + (vector_15 * 2)) + 5) & 127;
    aux ^= vector_15 & 15;
  }
  else
  {
    acc = ((acc - vector_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001930_3013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st_1 = {0};
  struct SensorNode_R001930_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_73_1 = 0;
  int damping_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_73_1 = ((damping_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_73_2 = ((damping_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_73_1) & 127;
    acc_2 = (acc_2 + damping_73_2) & 127;
  }

  int quotient_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_99_1)
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

  switch (quotient_99_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_73_1 == damping_73_2);
  assert(quotient_99_1 == quotient_99_2);
}

int fn_R001930_3013_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_73 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_73 = ((damping_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_73) & 127;
  }

  int quotient_99 = (aux + st.buffer[1]) & 3;
  switch (quotient_99)
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

void fn_R001930_3013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001930_3013_2 st_1 = {0};
  struct Transaction_R001930_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_48_1 = local_arr_1[aux_1 % 3];
  int accumulator_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_48_2 * 2)) & 127;
  int mask_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_79_1 > 33)
  {
    acc_1 = ((acc_1 + (mask_79_1 * 2)) + 5) & 127;
    aux_1 ^= mask_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_79_2 > 33)
  {
    acc_2 = ((acc_2 + (mask_79_2 * 2)) + 5) & 127;
    aux_2 ^= mask_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_77_1)
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

  switch (residue_77_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_48_1 == accumulator_48_2);
  assert(mask_79_1 == mask_79_2);
  assert(residue_77_1 == residue_77_2);
}

int fn_R001930_3013_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001930_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int accumulator_48 = local_arr[aux % 3];
  acc = (acc + (accumulator_48 * 2)) & 127;
  int mask_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_79 > 33)
  {
    acc = ((acc + (mask_79 * 2)) + 5) & 127;
    aux ^= mask_79 & 15;
  }
  else
  {
    acc = ((acc - mask_79) + 11) & 127;
    aux += 3;
  }
  int residue_77 = (aux + st.buffer[1]) & 3;
  switch (residue_77)
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

void fn_R001930_3013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001930_3013_0 st_1 = {0};
  struct AudioFrame_R001930_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_45_1 > 15)
  {
    acc_1 = ((acc_1 + (parity_45_1 * 2)) + 5) & 127;
    aux_1 ^= parity_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_45_2 > 15)
  {
    acc_2 = ((acc_2 + (parity_45_2 * 2)) + 5) & 127;
    aux_2 ^= parity_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_40_1 = 0;
  int window_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_40_1 = ((window_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_40_2 = ((window_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_40_1) & 127;
    acc_2 = (acc_2 + window_40_2) & 127;
  }

  int coefficient_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_37_1) & 63;
  aux_2 = (aux_2 + coefficient_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_45_1 == parity_45_2);
  assert(window_40_1 == window_40_2);
  assert(coefficient_37_1 == coefficient_37_2);
}

int fn_R001930_3013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001930_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_45 > 15)
  {
    acc = ((acc + (parity_45 * 2)) + 5) & 127;
    aux ^= parity_45 & 15;
  }
  else
  {
    acc = ((acc - parity_45) + 11) & 127;
    aux += 3;
  }
  int window_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_40 = ((window_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_40) & 127;
  }

  int coefficient_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001930_3013_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st_1 = {0};
  struct SensorNode_R001930_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int cursor_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_11_1 > 24)
  {
    acc_1 = ((acc_1 + (cursor_11_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_11_2 > 24)
  {
    acc_2 = ((acc_2 + (cursor_11_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_54_1) & 63;
  aux_2 = (aux_2 + phase_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_77_1 = local_arr_1[aux_1 % 3];
  int pivot_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_11_1 == cursor_11_2);
  assert(phase_54_1 == phase_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_77_1 == pivot_77_2);
}

int fn_R001930_3013_8(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int cursor_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_11 > 24)
  {
    acc = ((acc + (cursor_11 * 2)) + 5) & 127;
    aux ^= cursor_11 & 15;
  }
  else
  {
    acc = ((acc - cursor_11) + 11) & 127;
    aux += 3;
  }
  int phase_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_54) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_77 = local_arr[aux % 3];
  acc = (acc + (pivot_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001930_3013_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001930_3013_3 st_1 = {0};
  struct DeviceConfig_R001930_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_26_1 > 48)
  {
    acc_1 = ((acc_1 + (tracker_26_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_26_2 > 48)
  {
    acc_2 = ((acc_2 + (tracker_26_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_26_1 == tracker_26_2);
}

int fn_R001930_3013_9(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001930_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_26 > 48)
  {
    acc = ((acc + (tracker_26 * 2)) + 5) & 127;
    aux ^= tracker_26 & 15;
  }
  else
  {
    acc = ((acc - tracker_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001930_3013_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st_1 = {0};
  struct SensorNode_R001930_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int mask_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_40_1)
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

  switch (mask_40_2)
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
  int damping_93_1 = local_arr_1[aux_1 % 3];
  int damping_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_93_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_40_1 == mask_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_93_1 == damping_93_2);
}

int fn_R001930_3013_10(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int mask_40 = (aux + st.buffer[1]) & 3;
  switch (mask_40)
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
  int damping_93 = local_arr[aux % 3];
  acc = (acc + (damping_93 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001930_3013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001930_3013_3 st_1 = {0};
  struct DeviceConfig_R001930_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_11_1 = local_arr_1[aux_1 % 3];
  int quantum_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_11_2 * 2)) & 127;
  int margin_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_11_1 > 47)
  {
    acc_1 = ((acc_1 + (margin_11_1 * 2)) + 5) & 127;
    aux_1 ^= margin_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_11_2 > 47)
  {
    acc_2 = ((acc_2 + (margin_11_2 * 2)) + 5) & 127;
    aux_2 ^= margin_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_49_1) & 63;
  aux_2 = (aux_2 + metric_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_11_1 == quantum_11_2);
  assert(margin_11_1 == margin_11_2);
  assert(metric_49_1 == metric_49_2);
}

int fn_R001930_3013_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001930_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int quantum_11 = local_arr[aux % 3];
  acc = (acc + (quantum_11 * 2)) & 127;
  int margin_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_11 > 47)
  {
    acc = ((acc + (margin_11 * 2)) + 5) & 127;
    aux ^= margin_11 & 15;
  }
  else
  {
    acc = ((acc - margin_11) + 11) & 127;
    aux += 3;
  }
  int metric_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_49) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001930_3013_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st_1 = {0};
  struct SensorNode_R001930_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_62_1 = local_arr_1[aux_1 % 3];
  int accumulator_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_62_2 * 2)) & 127;
  int sample_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_29_1 > 39)
  {
    acc_1 = ((acc_1 + (sample_29_1 * 2)) + 5) & 127;
    aux_1 ^= sample_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_29_2 > 39)
  {
    acc_2 = ((acc_2 + (sample_29_2 * 2)) + 5) & 127;
    aux_2 ^= sample_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_27_1 = 0;
  int delta_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_27_1 = ((delta_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_27_2 = ((delta_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_27_1) & 127;
    acc_2 = (acc_2 + delta_27_2) & 127;
  }

  int stride_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_24_1)
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

  switch (stride_24_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_62_1 == accumulator_62_2);
  assert(sample_29_1 == sample_29_2);
  assert(delta_27_1 == delta_27_2);
  assert(stride_24_1 == stride_24_2);
}

int fn_R001930_3013_12(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001930_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int accumulator_62 = local_arr[aux % 3];
  acc = (acc + (accumulator_62 * 2)) & 127;
  int sample_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_29 > 39)
  {
    acc = ((acc + (sample_29 * 2)) + 5) & 127;
    aux ^= sample_29 & 15;
  }
  else
  {
    acc = ((acc - sample_29) + 11) & 127;
    aux += 3;
  }
  int delta_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_27 = ((delta_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_27) & 127;
  }

  int stride_24 = (aux + st.buffer[1]) & 3;
  switch (stride_24)
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

void fn_R001930_3013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001930_3013_3 st_1 = {0};
  struct DeviceConfig_R001930_3013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int parity_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_42_1)
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

  switch (parity_42_2)
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

  int offset_61_1 = 0;
  int offset_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_61_1 = ((offset_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_61_2 = ((offset_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_61_1) & 127;
    acc_2 = (acc_2 + offset_61_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_36_1 = local_arr_1[aux_1 % 3];
  int segment_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_42_1 == parity_42_2);
  assert(offset_61_1 == offset_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_36_1 == segment_36_2);
}

int fn_R001930_3013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001930_3013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int parity_42 = (aux + st.buffer[1]) & 3;
  switch (parity_42)
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

  int offset_61 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_61 = ((offset_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_61) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_36 = local_arr[aux % 3];
  acc = (acc + (segment_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001930_3013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001930_3013_2 st_1 = {0};
  struct Transaction_R001930_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int delta_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_98_1) & 63;
  aux_2 = (aux_2 + delta_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_47_1 = local_arr_1[aux_1 % 3];
  int factor_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_47_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_92_1)
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

  switch (cursor_92_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_98_1 == delta_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_47_1 == factor_47_2);
  assert(cursor_92_1 == cursor_92_2);
}

int fn_R001930_3013_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001930_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int delta_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_98) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_47 = local_arr[aux % 3];
  acc = (acc + (factor_47 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_92 = (aux + st.buffer[1]) & 3;
  switch (cursor_92)
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

void main()
{
  int sec_r001930_0_1;
  int sec_r001930_0_2;
  int sec_r001930_1_1;
  int sec_r001930_1_2;
  int sec_r001930_2_1;
  int sec_r001930_2_2;
  int sec_r001930_3_1;
  int sec_r001930_3_2;
  int sec_r001930_4_1;
  int sec_r001930_4_2;
  int sec_r001930_5_1;
  int sec_r001930_5_2;
  int sec_r001930_6_1;
  int sec_r001930_6_2;
  int sec_r001930_7_1;
  int sec_r001930_7_2;
  int sec_r001930_8_1;
  int sec_r001930_8_2;
  int sec_r001930_9_1;
  int sec_r001930_9_2;
  int sec_r001930_10_1;
  int sec_r001930_10_2;
  int sec_r001930_11_1;
  int sec_r001930_11_2;
  int sec_r001930_12_1;
  int sec_r001930_12_2;
  int sec_r001930_13_1;
  int sec_r001930_13_2;
  int sec_r001930_14_1;
  int sec_r001930_14_2;
  int sec_r001930_15_1;
  int sec_r001930_15_2;
  int sec_r001930_16_1;
  int sec_r001930_16_2;
  int sec_r001930_17_1;
  int sec_r001930_17_2;
  int pub_r001930_0_1;
  int pub_r001930_0_2;
  int pub_r001930_1_1;
  int pub_r001930_1_2;
  int pub_r001930_2_1;
  int pub_r001930_2_2;
  int pub_r001930_3_1;
  int pub_r001930_3_2;
  int pub_r001930_4_1;
  int pub_r001930_4_2;
  int pub_r001930_5_1;
  int pub_r001930_5_2;
  int pub_r001930_6_1;
  int pub_r001930_6_2;
  int pub_r001930_7_1;
  int pub_r001930_7_2;
  int pub_r001930_8_1;
  int pub_r001930_8_2;
  int pub_r001930_9_1;
  int pub_r001930_9_2;
  int pub_r001930_10_1;
  int pub_r001930_10_2;
  int pub_r001930_11_1;
  int pub_r001930_11_2;
  int pub_r001930_12_1;
  int pub_r001930_12_2;
  int pub_r001930_13_1;
  int pub_r001930_13_2;
  int pub_r001930_14_1;
  int pub_r001930_14_2;
  int pub_r001930_15_1;
  int pub_r001930_15_2;
  int pub_r001930_16_1;
  int pub_r001930_16_2;
  int pub_r001930_17_1;
  int pub_r001930_17_2;
  int pub_r001930_18_1;
  int pub_r001930_18_2;
  int pub_r001930_19_1;
  int pub_r001930_19_2;
  int pub_r001930_20_1;
  int pub_r001930_20_2;
  int pub_r001930_21_1;
  int pub_r001930_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001930_0_1 >= (-100)) && (pub_r001930_0_1 <= 100));
  __CPROVER_assume((pub_r001930_0_2 >= (-100)) && (pub_r001930_0_2 <= 100));
  __CPROVER_assume((pub_r001930_1_1 >= (-100)) && (pub_r001930_1_1 <= 100));
  __CPROVER_assume((pub_r001930_1_2 >= (-100)) && (pub_r001930_1_2 <= 100));
  __CPROVER_assume((pub_r001930_2_1 >= (-100)) && (pub_r001930_2_1 <= 100));
  __CPROVER_assume((pub_r001930_2_2 >= (-100)) && (pub_r001930_2_2 <= 100));
  __CPROVER_assume((pub_r001930_3_1 >= (-100)) && (pub_r001930_3_1 <= 100));
  __CPROVER_assume((pub_r001930_3_2 >= (-100)) && (pub_r001930_3_2 <= 100));
  __CPROVER_assume((pub_r001930_4_1 >= (-100)) && (pub_r001930_4_1 <= 100));
  __CPROVER_assume((pub_r001930_4_2 >= (-100)) && (pub_r001930_4_2 <= 100));
  __CPROVER_assume((pub_r001930_5_1 >= (-100)) && (pub_r001930_5_1 <= 100));
  __CPROVER_assume((pub_r001930_5_2 >= (-100)) && (pub_r001930_5_2 <= 100));
  __CPROVER_assume((pub_r001930_6_1 >= (-100)) && (pub_r001930_6_1 <= 100));
  __CPROVER_assume((pub_r001930_6_2 >= (-100)) && (pub_r001930_6_2 <= 100));
  __CPROVER_assume((pub_r001930_7_1 >= (-100)) && (pub_r001930_7_1 <= 100));
  __CPROVER_assume((pub_r001930_7_2 >= (-100)) && (pub_r001930_7_2 <= 100));
  __CPROVER_assume((pub_r001930_8_1 >= (-100)) && (pub_r001930_8_1 <= 100));
  __CPROVER_assume((pub_r001930_8_2 >= (-100)) && (pub_r001930_8_2 <= 100));
  __CPROVER_assume((pub_r001930_9_1 >= (-100)) && (pub_r001930_9_1 <= 100));
  __CPROVER_assume((pub_r001930_9_2 >= (-100)) && (pub_r001930_9_2 <= 100));
  __CPROVER_assume((pub_r001930_10_1 >= (-100)) && (pub_r001930_10_1 <= 100));
  __CPROVER_assume((pub_r001930_10_2 >= (-100)) && (pub_r001930_10_2 <= 100));
  __CPROVER_assume((pub_r001930_11_1 >= (-100)) && (pub_r001930_11_1 <= 100));
  __CPROVER_assume((pub_r001930_11_2 >= (-100)) && (pub_r001930_11_2 <= 100));
  __CPROVER_assume((pub_r001930_12_1 >= (-100)) && (pub_r001930_12_1 <= 100));
  __CPROVER_assume((pub_r001930_12_2 >= (-100)) && (pub_r001930_12_2 <= 100));
  __CPROVER_assume((pub_r001930_13_1 >= (-100)) && (pub_r001930_13_1 <= 100));
  __CPROVER_assume((pub_r001930_13_2 >= (-100)) && (pub_r001930_13_2 <= 100));
  __CPROVER_assume((pub_r001930_14_1 >= (-100)) && (pub_r001930_14_1 <= 100));
  __CPROVER_assume((pub_r001930_14_2 >= (-100)) && (pub_r001930_14_2 <= 100));
  __CPROVER_assume((pub_r001930_15_1 >= (-100)) && (pub_r001930_15_1 <= 100));
  __CPROVER_assume((pub_r001930_15_2 >= (-100)) && (pub_r001930_15_2 <= 100));
  __CPROVER_assume((pub_r001930_16_1 >= (-100)) && (pub_r001930_16_1 <= 100));
  __CPROVER_assume((pub_r001930_16_2 >= (-100)) && (pub_r001930_16_2 <= 100));
  __CPROVER_assume((pub_r001930_17_1 >= (-100)) && (pub_r001930_17_1 <= 100));
  __CPROVER_assume((pub_r001930_17_2 >= (-100)) && (pub_r001930_17_2 <= 100));
  __CPROVER_assume((pub_r001930_18_1 >= (-100)) && (pub_r001930_18_1 <= 100));
  __CPROVER_assume((pub_r001930_18_2 >= (-100)) && (pub_r001930_18_2 <= 100));
  __CPROVER_assume((pub_r001930_19_1 >= (-100)) && (pub_r001930_19_1 <= 100));
  __CPROVER_assume((pub_r001930_19_2 >= (-100)) && (pub_r001930_19_2 <= 100));
  __CPROVER_assume((pub_r001930_20_1 >= (-100)) && (pub_r001930_20_1 <= 100));
  __CPROVER_assume((pub_r001930_20_2 >= (-100)) && (pub_r001930_20_2 <= 100));
  __CPROVER_assume((pub_r001930_21_1 >= (-100)) && (pub_r001930_21_1 <= 100));
  __CPROVER_assume((pub_r001930_21_2 >= (-100)) && (pub_r001930_21_2 <= 100));
  __CPROVER_assume((sec_r001930_0_1 >= 0) && (sec_r001930_0_1 <= 255));
  __CPROVER_assume((sec_r001930_0_2 >= 0) && (sec_r001930_0_2 <= 255));
  __CPROVER_assume((sec_r001930_1_1 >= 0) && (sec_r001930_1_1 <= 255));
  __CPROVER_assume((sec_r001930_1_2 >= 0) && (sec_r001930_1_2 <= 255));
  __CPROVER_assume((sec_r001930_2_1 >= 0) && (sec_r001930_2_1 <= 255));
  __CPROVER_assume((sec_r001930_2_2 >= 0) && (sec_r001930_2_2 <= 255));
  __CPROVER_assume((sec_r001930_3_1 >= 0) && (sec_r001930_3_1 <= 255));
  __CPROVER_assume((sec_r001930_3_2 >= 0) && (sec_r001930_3_2 <= 255));
  __CPROVER_assume((sec_r001930_4_1 >= 0) && (sec_r001930_4_1 <= 255));
  __CPROVER_assume((sec_r001930_4_2 >= 0) && (sec_r001930_4_2 <= 255));
  __CPROVER_assume((sec_r001930_5_1 >= 0) && (sec_r001930_5_1 <= 255));
  __CPROVER_assume((sec_r001930_5_2 >= 0) && (sec_r001930_5_2 <= 255));
  __CPROVER_assume((sec_r001930_6_1 >= 0) && (sec_r001930_6_1 <= 255));
  __CPROVER_assume((sec_r001930_6_2 >= 0) && (sec_r001930_6_2 <= 255));
  __CPROVER_assume((sec_r001930_7_1 >= 0) && (sec_r001930_7_1 <= 255));
  __CPROVER_assume((sec_r001930_7_2 >= 0) && (sec_r001930_7_2 <= 255));
  __CPROVER_assume((sec_r001930_8_1 >= 0) && (sec_r001930_8_1 <= 255));
  __CPROVER_assume((sec_r001930_8_2 >= 0) && (sec_r001930_8_2 <= 255));
  __CPROVER_assume((sec_r001930_9_1 >= 0) && (sec_r001930_9_1 <= 255));
  __CPROVER_assume((sec_r001930_9_2 >= 0) && (sec_r001930_9_2 <= 255));
  __CPROVER_assume((sec_r001930_10_1 >= 0) && (sec_r001930_10_1 <= 255));
  __CPROVER_assume((sec_r001930_10_2 >= 0) && (sec_r001930_10_2 <= 255));
  __CPROVER_assume((sec_r001930_11_1 >= 0) && (sec_r001930_11_1 <= 255));
  __CPROVER_assume((sec_r001930_11_2 >= 0) && (sec_r001930_11_2 <= 255));
  __CPROVER_assume((sec_r001930_12_1 >= 0) && (sec_r001930_12_1 <= 255));
  __CPROVER_assume((sec_r001930_12_2 >= 0) && (sec_r001930_12_2 <= 255));
  __CPROVER_assume((sec_r001930_13_1 >= 0) && (sec_r001930_13_1 <= 255));
  __CPROVER_assume((sec_r001930_13_2 >= 0) && (sec_r001930_13_2 <= 255));
  __CPROVER_assume((sec_r001930_14_1 >= 0) && (sec_r001930_14_1 <= 255));
  __CPROVER_assume((sec_r001930_14_2 >= 0) && (sec_r001930_14_2 <= 255));
  __CPROVER_assume((sec_r001930_15_1 >= 0) && (sec_r001930_15_1 <= 255));
  __CPROVER_assume((sec_r001930_15_2 >= 0) && (sec_r001930_15_2 <= 255));
  __CPROVER_assume((sec_r001930_16_1 >= 0) && (sec_r001930_16_1 <= 255));
  __CPROVER_assume((sec_r001930_16_2 >= 0) && (sec_r001930_16_2 <= 255));
  __CPROVER_assume((sec_r001930_17_1 >= 0) && (sec_r001930_17_1 <= 255));
  __CPROVER_assume((sec_r001930_17_2 >= 0) && (sec_r001930_17_2 <= 255));
  struct AudioFrame_R001930_3013_0 st_var_0_1 = {0};
  struct AudioFrame_R001930_3013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001930_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001930_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001930_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001930_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001930_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001930_0_2 + 7) & 15;
  struct SensorNode_R001930_3013_1 st_var_1_1 = {0};
  struct SensorNode_R001930_3013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001930_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001930_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001930_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001930_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001930_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001930_0_2 + 9) & 15;
  struct Transaction_R001930_3013_2 st_var_2_1 = {0};
  struct Transaction_R001930_3013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001930_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001930_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001930_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001930_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001930_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001930_0_2 + 11) & 15;
  struct DeviceConfig_R001930_3013_3 st_var_3_1 = {0};
  struct DeviceConfig_R001930_3013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001930_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001930_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001930_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001930_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001930_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001930_0_2 + 13) & 15;
  union ColorPixel_R001930_3013_0 u_var_1;
  union ColorPixel_R001930_3013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001930_3013_0(sec_r001930_0_1, pub_r001930_1_1, pub_r001930_2_1);
  int helper_flow_0_2 = fn_R001930_3013_0(sec_r001930_0_2, pub_r001930_1_2, pub_r001930_2_2);
  fn_R001930_3013_0_2(sec_r001930_0_1, pub_r001930_1_1, pub_r001930_2_1, sec_r001930_0_2, pub_r001930_1_2, pub_r001930_2_2);
  int helper_flow_1_1 = fn_R001930_3013_1(sec_r001930_1_1, pub_r001930_2_1, pub_r001930_3_1, pub_r001930_4_1);
  int helper_flow_1_2 = fn_R001930_3013_1(sec_r001930_1_2, pub_r001930_2_2, pub_r001930_3_2, pub_r001930_4_2);
  fn_R001930_3013_1_2(sec_r001930_1_1, pub_r001930_2_1, pub_r001930_3_1, pub_r001930_4_1, sec_r001930_1_2, pub_r001930_2_2, pub_r001930_3_2, pub_r001930_4_2);
  int helper_flow_2_1 = fn_R001930_3013_2(sec_r001930_2_1, sec_r001930_3_1, pub_r001930_4_1, pub_r001930_5_1);
  int helper_flow_2_2 = fn_R001930_3013_2(sec_r001930_2_2, sec_r001930_3_2, pub_r001930_4_2, pub_r001930_5_2);
  fn_R001930_3013_2_2(sec_r001930_2_1, sec_r001930_3_1, pub_r001930_4_1, pub_r001930_5_1, sec_r001930_2_2, sec_r001930_3_2, pub_r001930_4_2, pub_r001930_5_2);
  int helper_flow_3_1 = fn_R001930_3013_3(sec_r001930_3_1, pub_r001930_4_1, pub_r001930_5_1);
  int helper_flow_3_2 = fn_R001930_3013_3(sec_r001930_3_2, pub_r001930_4_2, pub_r001930_5_2);
  fn_R001930_3013_3_2(sec_r001930_3_1, pub_r001930_4_1, pub_r001930_5_1, sec_r001930_3_2, pub_r001930_4_2, pub_r001930_5_2);
  int helper_flow_4_1 = fn_R001930_3013_4(sec_r001930_4_1, sec_r001930_5_1);
  int helper_flow_4_2 = fn_R001930_3013_4(sec_r001930_4_2, sec_r001930_5_2);
  fn_R001930_3013_4_2(sec_r001930_4_1, sec_r001930_5_1, sec_r001930_4_2, sec_r001930_5_2);
  int helper_flow_5_1 = fn_R001930_3013_5(sec_r001930_5_1, pub_r001930_6_1, pub_r001930_7_1, pub_r001930_8_1);
  int helper_flow_5_2 = fn_R001930_3013_5(sec_r001930_5_2, pub_r001930_6_2, pub_r001930_7_2, pub_r001930_8_2);
  fn_R001930_3013_5_2(sec_r001930_5_1, pub_r001930_6_1, pub_r001930_7_1, pub_r001930_8_1, sec_r001930_5_2, pub_r001930_6_2, pub_r001930_7_2, pub_r001930_8_2);
  int helper_flow_6_1 = fn_R001930_3013_6(sec_r001930_6_1, sec_r001930_7_1, pub_r001930_8_1, pub_r001930_9_1);
  int helper_flow_6_2 = fn_R001930_3013_6(sec_r001930_6_2, sec_r001930_7_2, pub_r001930_8_2, pub_r001930_9_2);
  fn_R001930_3013_6_2(sec_r001930_6_1, sec_r001930_7_1, pub_r001930_8_1, pub_r001930_9_1, sec_r001930_6_2, sec_r001930_7_2, pub_r001930_8_2, pub_r001930_9_2);
  int helper_flow_7_1 = fn_R001930_3013_7(sec_r001930_7_1, sec_r001930_8_1, pub_r001930_9_1, pub_r001930_10_1, pub_r001930_11_1);
  int helper_flow_7_2 = fn_R001930_3013_7(sec_r001930_7_2, sec_r001930_8_2, pub_r001930_9_2, pub_r001930_10_2, pub_r001930_11_2);
  fn_R001930_3013_7_2(sec_r001930_7_1, sec_r001930_8_1, pub_r001930_9_1, pub_r001930_10_1, pub_r001930_11_1, sec_r001930_7_2, sec_r001930_8_2, pub_r001930_9_2, pub_r001930_10_2, pub_r001930_11_2);
  int helper_flow_8_1 = fn_R001930_3013_8(sec_r001930_8_1, pub_r001930_9_1);
  int helper_flow_8_2 = fn_R001930_3013_8(sec_r001930_8_2, pub_r001930_9_2);
  fn_R001930_3013_8_2(sec_r001930_8_1, pub_r001930_9_1, sec_r001930_8_2, pub_r001930_9_2);
  int helper_flow_9_1 = fn_R001930_3013_9(sec_r001930_9_1, sec_r001930_10_1, pub_r001930_11_1);
  int helper_flow_9_2 = fn_R001930_3013_9(sec_r001930_9_2, sec_r001930_10_2, pub_r001930_11_2);
  fn_R001930_3013_9_2(sec_r001930_9_1, sec_r001930_10_1, pub_r001930_11_1, sec_r001930_9_2, sec_r001930_10_2, pub_r001930_11_2);
  int helper_flow_10_1 = fn_R001930_3013_10(sec_r001930_10_1, pub_r001930_11_1);
  int helper_flow_10_2 = fn_R001930_3013_10(sec_r001930_10_2, pub_r001930_11_2);
  fn_R001930_3013_10_2(sec_r001930_10_1, pub_r001930_11_1, sec_r001930_10_2, pub_r001930_11_2);
  int helper_flow_11_1 = fn_R001930_3013_11(sec_r001930_11_1, sec_r001930_12_1, pub_r001930_13_1, pub_r001930_14_1);
  int helper_flow_11_2 = fn_R001930_3013_11(sec_r001930_11_2, sec_r001930_12_2, pub_r001930_13_2, pub_r001930_14_2);
  fn_R001930_3013_11_2(sec_r001930_11_1, sec_r001930_12_1, pub_r001930_13_1, pub_r001930_14_1, sec_r001930_11_2, sec_r001930_12_2, pub_r001930_13_2, pub_r001930_14_2);
  int helper_flow_12_1 = fn_R001930_3013_12(sec_r001930_12_1, sec_r001930_13_1);
  int helper_flow_12_2 = fn_R001930_3013_12(sec_r001930_12_2, sec_r001930_13_2);
  fn_R001930_3013_12_2(sec_r001930_12_1, sec_r001930_13_1, sec_r001930_12_2, sec_r001930_13_2);
  int stage_v_0_1 = ((pub_r001930_1_1 * 2) + 10) & 63;
  int stage_v_0_2 = ((pub_r001930_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001930_16_1) & 127;
  int stage_v_1_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001930_16_2) & 127;
  if (stage_v_1_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((sec_r001930_5_1 ^ 0x2A) * 2) + pub_r001930_1_1) & 127;
  int stage_v_2_2 = (((sec_r001930_5_2 ^ 0x2A) * 2) + pub_r001930_1_2) & 127;
  if (stage_v_2_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001930_8_1 ^ 0x2A) * 2) + pub_r001930_15_1) & 127;
  int stage_v_3_2 = (((sec_r001930_8_2 ^ 0x2A) * 2) + pub_r001930_15_2) & 127;
  if (stage_v_3_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001930_1_1) & 127;
  int stage_v_4_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001930_1_2) & 127;
  if (stage_v_4_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((sec_r001930_0_1 ^ 0x2A) * 2) + pub_r001930_0_1) & 127;
  int stage_v_5_2 = (((sec_r001930_0_2 ^ 0x2A) * 2) + pub_r001930_0_2) & 127;
  if (stage_v_5_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((sec_r001930_11_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_6_2 = (((sec_r001930_11_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_6_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((sec_r001930_16_1 ^ 0x2A) * 2) + pub_r001930_15_1) & 127;
  int stage_v_7_2 = (((sec_r001930_16_2 ^ 0x2A) * 2) + pub_r001930_15_2) & 127;
  if (stage_v_7_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((sec_r001930_12_1 ^ 0x2A) * 2) + pub_r001930_5_1) & 127;
  int stage_v_8_2 = (((sec_r001930_12_2 ^ 0x2A) * 2) + pub_r001930_5_2) & 127;
  if (stage_v_8_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((pub_r001930_7_1 * 2) + 34) & 63;
  int stage_v_9_2 = ((pub_r001930_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001930_19_1) & 127;
  int stage_v_10_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001930_19_2) & 127;
  if (stage_v_10_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((sec_r001930_2_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_11_2 = (((sec_r001930_2_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_11_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((pub_r001930_18_1 * 2) + 24) & 63;
  int stage_v_12_2 = ((pub_r001930_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001930_16_1) & 127;
  int stage_v_13_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001930_16_2) & 127;
  if (stage_v_13_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001930_4_1) & 127;
  int stage_v_14_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001930_4_2) & 127;
  if (stage_v_14_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001930_8_1) & 127;
  int stage_v_15_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001930_8_2) & 127;
  if (stage_v_15_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((sec_r001930_4_1 ^ 0x2A) * 2) + pub_r001930_2_1) & 127;
  int stage_v_16_2 = (((sec_r001930_4_2 ^ 0x2A) * 2) + pub_r001930_2_2) & 127;
  if (stage_v_16_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((pub_r001930_5_1 * 2) + 14) & 63;
  int stage_v_17_2 = ((pub_r001930_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001930_7_1) & 127;
  int stage_v_18_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001930_7_2) & 127;
  if (stage_v_18_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001930_14_1) & 127;
  int stage_v_19_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001930_14_2) & 127;
  if (stage_v_19_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001930_11_1) & 127;
  int stage_v_20_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001930_11_2) & 127;
  if (stage_v_20_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((pub_r001930_4_1 * 2) + 40) & 63;
  int stage_v_21_2 = ((pub_r001930_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((sec_r001930_10_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_22_2 = (((sec_r001930_10_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_22_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((pub_r001930_11_1 * 2) + 45) & 63;
  int stage_v_23_2 = ((pub_r001930_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001930_15_1 * 2) + 14) & 63;
  int stage_v_24_2 = ((pub_r001930_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_25_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_25_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001930_18_1) & 127;
  int stage_v_26_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001930_18_2) & 127;
  if (stage_v_26_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001930_2_1) & 127;
  int stage_v_27_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001930_2_2) & 127;
  if (stage_v_27_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((pub_r001930_10_1 * 2) + 32) & 63;
  int stage_v_28_2 = ((pub_r001930_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001930_9_1) & 127;
  int stage_v_29_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001930_9_2) & 127;
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
  int stage_v_30_1 = ((pub_r001930_0_1 * 2) + 6) & 63;
  int stage_v_30_2 = ((pub_r001930_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001930_9_1) & 127;
  int stage_v_31_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001930_9_2) & 127;
  if (stage_v_31_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001930_2_1) & 127;
  int stage_v_32_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001930_2_2) & 127;
  if (stage_v_32_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001930_19_1) & 127;
  int stage_v_33_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001930_19_2) & 127;
  if (stage_v_33_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((pub_r001930_19_1 * 2) + 8) & 63;
  int stage_v_34_2 = ((pub_r001930_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001930_1_1 * 2) + 32) & 63;
  int stage_v_35_2 = ((pub_r001930_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((sec_r001930_0_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_36_2 = (((sec_r001930_0_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_36_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((sec_r001930_14_1 ^ 0x2A) * 2) + pub_r001930_14_1) & 127;
  int stage_v_37_2 = (((sec_r001930_14_2 ^ 0x2A) * 2) + pub_r001930_14_2) & 127;
  if (stage_v_37_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((pub_r001930_17_1 * 2) + 14) & 63;
  int stage_v_38_2 = ((pub_r001930_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001930_0_1 * 2) + 49) & 63;
  int stage_v_39_2 = ((pub_r001930_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((sec_r001930_5_1 ^ 0x2A) * 2) + pub_r001930_7_1) & 127;
  int stage_v_40_2 = (((sec_r001930_5_2 ^ 0x2A) * 2) + pub_r001930_7_2) & 127;
  if (stage_v_40_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001930_4_1) & 127;
  int stage_v_41_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001930_4_2) & 127;
  if (stage_v_41_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001930_11_1) & 127;
  int stage_v_42_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001930_11_2) & 127;
  if (stage_v_42_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001930_2_1) & 127;
  int stage_v_43_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001930_2_2) & 127;
  if (stage_v_43_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001930_11_1) & 127;
  int stage_v_44_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001930_11_2) & 127;
  if (stage_v_44_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001930_17_1) & 127;
  int stage_v_45_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001930_17_2) & 127;
  if (stage_v_45_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((sec_r001930_0_1 ^ 0x2A) * 2) + pub_r001930_19_1) & 127;
  int stage_v_46_2 = (((sec_r001930_0_2 ^ 0x2A) * 2) + pub_r001930_19_2) & 127;
  if (stage_v_46_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001930_17_1) & 127;
  int stage_v_47_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001930_17_2) & 127;
  if (stage_v_47_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((pub_r001930_20_1 * 2) + 32) & 63;
  int stage_v_48_2 = ((pub_r001930_20_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001930_5_1) & 127;
  int stage_v_49_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001930_5_2) & 127;
  if (stage_v_49_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((pub_r001930_14_1 * 2) + 19) & 63;
  int stage_v_50_2 = ((pub_r001930_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001930_19_1) & 127;
  int stage_v_51_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001930_19_2) & 127;
  if (stage_v_51_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_52_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_52_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001930_4_1) & 127;
  int stage_v_53_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001930_4_2) & 127;
  if (stage_v_53_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((sec_r001930_2_1 ^ 0x2A) * 2) + pub_r001930_2_1) & 127;
  int stage_v_54_2 = (((sec_r001930_2_2 ^ 0x2A) * 2) + pub_r001930_2_2) & 127;
  if (stage_v_54_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((sec_r001930_15_1 ^ 0x2A) * 2) + pub_r001930_11_1) & 127;
  int stage_v_55_2 = (((sec_r001930_15_2 ^ 0x2A) * 2) + pub_r001930_11_2) & 127;
  if (stage_v_55_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001930_2_1) & 127;
  int stage_v_56_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001930_2_2) & 127;
  if (stage_v_56_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001930_20_1) & 127;
  int stage_v_57_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001930_20_2) & 127;
  if (stage_v_57_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001930_1_1) & 127;
  int stage_v_58_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001930_1_2) & 127;
  if (stage_v_58_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((sec_r001930_7_1 ^ 0x2A) * 2) + pub_r001930_8_1) & 127;
  int stage_v_59_2 = (((sec_r001930_7_2 ^ 0x2A) * 2) + pub_r001930_8_2) & 127;
  if (stage_v_59_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001930_5_1) & 127;
  int stage_v_60_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001930_5_2) & 127;
  if (stage_v_60_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001930_19_1) & 127;
  int stage_v_61_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001930_19_2) & 127;
  if (stage_v_61_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001930_10_1) & 127;
  int stage_v_62_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001930_10_2) & 127;
  if (stage_v_62_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001930_10_1) & 127;
  int stage_v_63_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001930_10_2) & 127;
  if (stage_v_63_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001930_10_1) & 127;
  int stage_v_64_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001930_10_2) & 127;
  if (stage_v_64_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001930_12_1) & 127;
  int stage_v_65_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001930_12_2) & 127;
  if (stage_v_65_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001930_5_1) & 127;
  int stage_v_66_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001930_5_2) & 127;
  if (stage_v_66_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((sec_r001930_17_1 ^ 0x2A) * 2) + pub_r001930_4_1) & 127;
  int stage_v_67_2 = (((sec_r001930_17_2 ^ 0x2A) * 2) + pub_r001930_4_2) & 127;
  if (stage_v_67_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_68_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_68_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((sec_r001930_7_1 ^ 0x2A) * 2) + pub_r001930_21_1) & 127;
  int stage_v_69_2 = (((sec_r001930_7_2 ^ 0x2A) * 2) + pub_r001930_21_2) & 127;
  if (stage_v_69_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001930_10_1) & 127;
  int stage_v_70_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001930_10_2) & 127;
  if (stage_v_70_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_71_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_71_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001930_7_1) & 127;
  int stage_v_72_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001930_7_2) & 127;
  if (stage_v_72_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((sec_r001930_12_1 ^ 0x2A) * 2) + pub_r001930_0_1) & 127;
  int stage_v_73_2 = (((sec_r001930_12_2 ^ 0x2A) * 2) + pub_r001930_0_2) & 127;
  if (stage_v_73_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((pub_r001930_21_1 * 2) + 40) & 63;
  int stage_v_74_2 = ((pub_r001930_21_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001930_21_1 * 2) + 36) & 63;
  int stage_v_75_2 = ((pub_r001930_21_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (((sec_r001930_13_1 ^ 0x2A) * 2) + pub_r001930_5_1) & 127;
  int stage_v_76_2 = (((sec_r001930_13_2 ^ 0x2A) * 2) + pub_r001930_5_2) & 127;
  if (stage_v_76_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((pub_r001930_17_1 * 2) + 35) & 63;
  int stage_v_77_2 = ((pub_r001930_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001930_10_1) & 127;
  int stage_v_78_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001930_10_2) & 127;
  if (stage_v_78_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001930_1_1) & 127;
  int stage_v_79_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001930_1_2) & 127;
  if (stage_v_79_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001930_3_1) & 127;
  int stage_v_80_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001930_3_2) & 127;
  if (stage_v_80_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001930_9_1) & 127;
  int stage_v_81_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001930_9_2) & 127;
  if (stage_v_81_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_82_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_82_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((pub_r001930_0_1 * 2) + 19) & 63;
  int stage_v_83_2 = ((pub_r001930_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001930_17_1 * 2) + 49) & 63;
  int stage_v_84_2 = ((pub_r001930_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001930_8_1) & 127;
  int stage_v_85_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001930_8_2) & 127;
  if (stage_v_85_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_86_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_86_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001930_18_1) & 127;
  int stage_v_87_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001930_18_2) & 127;
  if (stage_v_87_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((sec_r001930_7_1 ^ 0x2A) * 2) + pub_r001930_8_1) & 127;
  int stage_v_88_2 = (((sec_r001930_7_2 ^ 0x2A) * 2) + pub_r001930_8_2) & 127;
  if (stage_v_88_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001930_20_1) & 127;
  int stage_v_89_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001930_20_2) & 127;
  if (stage_v_89_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001930_20_1) & 127;
  int stage_v_90_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001930_20_2) & 127;
  if (stage_v_90_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_91_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_91_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((pub_r001930_17_1 * 2) + 26) & 63;
  int stage_v_92_2 = ((pub_r001930_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((sec_r001930_1_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_93_2 = (((sec_r001930_1_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_93_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001930_0_1) & 127;
  int stage_v_94_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001930_0_2) & 127;
  if (stage_v_94_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((pub_r001930_10_1 * 2) + 9) & 63;
  int stage_v_95_2 = ((pub_r001930_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((sec_r001930_11_1 ^ 0x2A) * 2) + pub_r001930_19_1) & 127;
  int stage_v_96_2 = (((sec_r001930_11_2 ^ 0x2A) * 2) + pub_r001930_19_2) & 127;
  if (stage_v_96_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((pub_r001930_4_1 * 2) + 42) & 63;
  int stage_v_97_2 = ((pub_r001930_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001930_11_1) & 127;
  int stage_v_98_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001930_11_2) & 127;
  if (stage_v_98_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((sec_r001930_11_1 ^ 0x2A) * 2) + pub_r001930_20_1) & 127;
  int stage_v_99_2 = (((sec_r001930_11_2 ^ 0x2A) * 2) + pub_r001930_20_2) & 127;
  if (stage_v_99_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001930_11_1) & 127;
  int stage_v_100_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001930_11_2) & 127;
  if (stage_v_100_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((pub_r001930_12_1 * 2) + 7) & 63;
  int stage_v_101_2 = ((pub_r001930_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001930_16_1 * 2) + 5) & 63;
  int stage_v_102_2 = ((pub_r001930_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001930_4_1) & 127;
  int stage_v_103_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001930_4_2) & 127;
  if (stage_v_103_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((pub_r001930_0_1 * 2) + 48) & 63;
  int stage_v_104_2 = ((pub_r001930_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_105_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_105_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001930_15_1) & 127;
  int stage_v_106_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001930_15_2) & 127;
  if (stage_v_106_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001930_8_1) & 127;
  int stage_v_107_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001930_8_2) & 127;
  if (stage_v_107_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001930_3_1) & 127;
  int stage_v_108_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001930_3_2) & 127;
  if (stage_v_108_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001930_2_1) & 127;
  int stage_v_109_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001930_2_2) & 127;
  if (stage_v_109_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((pub_r001930_5_1 * 2) + 29) & 63;
  int stage_v_110_2 = ((pub_r001930_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001930_4_1) & 127;
  int stage_v_111_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001930_4_2) & 127;
  if (stage_v_111_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((pub_r001930_15_1 * 2) + 46) & 63;
  int stage_v_112_2 = ((pub_r001930_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001930_12_1) & 127;
  int stage_v_113_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001930_12_2) & 127;
  if (stage_v_113_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((pub_r001930_9_1 * 2) + 46) & 63;
  int stage_v_114_2 = ((pub_r001930_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_115_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_115_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001930_5_1) & 127;
  int stage_v_116_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001930_5_2) & 127;
  if (stage_v_116_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001930_14_1) & 127;
  int stage_v_117_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001930_14_2) & 127;
  if (stage_v_117_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_118_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_118_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((sec_r001930_14_1 ^ 0x2A) * 2) + pub_r001930_12_1) & 127;
  int stage_v_119_2 = (((sec_r001930_14_2 ^ 0x2A) * 2) + pub_r001930_12_2) & 127;
  if (stage_v_119_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001930_21_1) & 127;
  int stage_v_120_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001930_21_2) & 127;
  if (stage_v_120_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((pub_r001930_5_1 * 2) + 42) & 63;
  int stage_v_121_2 = ((pub_r001930_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001930_17_1) & 127;
  int stage_v_122_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001930_17_2) & 127;
  if (stage_v_122_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((sec_r001930_14_1 ^ 0x2A) * 2) + pub_r001930_7_1) & 127;
  int stage_v_123_2 = (((sec_r001930_14_2 ^ 0x2A) * 2) + pub_r001930_7_2) & 127;
  if (stage_v_123_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001930_19_1) & 127;
  int stage_v_124_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001930_19_2) & 127;
  if (stage_v_124_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001930_10_1) & 127;
  int stage_v_125_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001930_10_2) & 127;
  if (stage_v_125_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((sec_r001930_2_1 ^ 0x2A) * 2) + pub_r001930_12_1) & 127;
  int stage_v_126_2 = (((sec_r001930_2_2 ^ 0x2A) * 2) + pub_r001930_12_2) & 127;
  if (stage_v_126_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001930_4_1) & 127;
  int stage_v_127_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001930_4_2) & 127;
  if (stage_v_127_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((pub_r001930_4_1 * 2) + 41) & 63;
  int stage_v_128_2 = ((pub_r001930_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((sec_r001930_6_1 ^ 0x2A) * 2) + pub_r001930_10_1) & 127;
  int stage_v_129_2 = (((sec_r001930_6_2 ^ 0x2A) * 2) + pub_r001930_10_2) & 127;
  if (stage_v_129_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001930_1_1) & 127;
  int stage_v_130_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001930_1_2) & 127;
  if (stage_v_130_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001930_18_1) & 127;
  int stage_v_131_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001930_18_2) & 127;
  if (stage_v_131_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001930_16_1) & 127;
  int stage_v_132_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001930_16_2) & 127;
  if (stage_v_132_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((pub_r001930_11_1 * 2) + 6) & 63;
  int stage_v_133_2 = ((pub_r001930_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001930_3_1) & 127;
  int stage_v_134_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001930_3_2) & 127;
  if (stage_v_134_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((pub_r001930_7_1 * 2) + 12) & 63;
  int stage_v_135_2 = ((pub_r001930_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001930_2_1) & 127;
  int stage_v_136_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001930_2_2) & 127;
  if (stage_v_136_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((pub_r001930_9_1 * 2) + 22) & 63;
  int stage_v_137_2 = ((pub_r001930_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((sec_r001930_9_1 ^ 0x2A) * 2) + pub_r001930_1_1) & 127;
  int stage_v_138_2 = (((sec_r001930_9_2 ^ 0x2A) * 2) + pub_r001930_1_2) & 127;
  if (stage_v_138_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001930_1_1) & 127;
  int stage_v_139_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001930_1_2) & 127;
  if (stage_v_139_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((sec_r001930_7_1 ^ 0x2A) * 2) + pub_r001930_10_1) & 127;
  int stage_v_140_2 = (((sec_r001930_7_2 ^ 0x2A) * 2) + pub_r001930_10_2) & 127;
  if (stage_v_140_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((pub_r001930_12_1 * 2) + 14) & 63;
  int stage_v_141_2 = ((pub_r001930_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001930_15_1) & 127;
  int stage_v_142_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001930_15_2) & 127;
  if (stage_v_142_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_143_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_143_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((pub_r001930_3_1 * 2) + 46) & 63;
  int stage_v_144_2 = ((pub_r001930_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001930_10_1) & 127;
  int stage_v_145_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001930_10_2) & 127;
  if (stage_v_145_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_146_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_146_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((pub_r001930_18_1 * 2) + 15) & 63;
  int stage_v_147_2 = ((pub_r001930_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001930_18_1) & 127;
  int stage_v_148_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001930_18_2) & 127;
  if (stage_v_148_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001930_1_1) & 127;
  int stage_v_149_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001930_1_2) & 127;
  if (stage_v_149_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001930_16_1) & 127;
  int stage_v_150_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001930_16_2) & 127;
  if (stage_v_150_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001930_4_1) & 127;
  int stage_v_151_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001930_4_2) & 127;
  if (stage_v_151_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_152_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_152_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001930_20_1) & 127;
  int stage_v_153_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001930_20_2) & 127;
  if (stage_v_153_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((sec_r001930_2_1 ^ 0x2A) * 2) + pub_r001930_4_1) & 127;
  int stage_v_154_2 = (((sec_r001930_2_2 ^ 0x2A) * 2) + pub_r001930_4_2) & 127;
  if (stage_v_154_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((pub_r001930_7_1 * 2) + 21) & 63;
  int stage_v_155_2 = ((pub_r001930_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001930_19_1) & 127;
  int stage_v_156_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001930_19_2) & 127;
  if (stage_v_156_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001930_15_1) & 127;
  int stage_v_157_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001930_15_2) & 127;
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
  int stage_v_158_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001930_11_1) & 127;
  int stage_v_158_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001930_11_2) & 127;
  if (stage_v_158_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_159_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_159_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((sec_r001930_6_1 ^ 0x2A) * 2) + pub_r001930_7_1) & 127;
  int stage_v_160_2 = (((sec_r001930_6_2 ^ 0x2A) * 2) + pub_r001930_7_2) & 127;
  if (stage_v_160_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001930_7_1) & 127;
  int stage_v_161_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001930_7_2) & 127;
  if (stage_v_161_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((pub_r001930_0_1 * 2) + 14) & 63;
  int stage_v_162_2 = ((pub_r001930_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_146_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_163_2 = (((stage_v_146_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_163_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001930_0_1) & 127;
  int stage_v_164_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001930_0_2) & 127;
  if (stage_v_164_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001930_3_1) & 127;
  int stage_v_165_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001930_3_2) & 127;
  if (stage_v_165_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_151_1 ^ 0x2A) * 2) + pub_r001930_2_1) & 127;
  int stage_v_166_2 = (((stage_v_151_2 ^ 0x2A) * 2) + pub_r001930_2_2) & 127;
  if (stage_v_166_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_115_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_167_2 = (((stage_v_115_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_167_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001930_10_1) & 127;
  int stage_v_168_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001930_10_2) & 127;
  if (stage_v_168_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_167_1 ^ 0x2A) * 2) + pub_r001930_20_1) & 127;
  int stage_v_169_2 = (((stage_v_167_2 ^ 0x2A) * 2) + pub_r001930_20_2) & 127;
  if (stage_v_169_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001930_16_1) & 127;
  int stage_v_170_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001930_16_2) & 127;
  if (stage_v_170_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((pub_r001930_10_1 * 2) + 32) & 63;
  int stage_v_171_2 = ((pub_r001930_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_159_1 ^ 0x2A) * 2) + pub_r001930_18_1) & 127;
  int stage_v_172_2 = (((stage_v_159_2 ^ 0x2A) * 2) + pub_r001930_18_2) & 127;
  if (stage_v_172_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_173_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_173_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((pub_r001930_8_1 * 2) + 6) & 63;
  int stage_v_174_2 = ((pub_r001930_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001930_16_1 * 2) + 35) & 63;
  int stage_v_175_2 = ((pub_r001930_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001930_11_1 * 2) + 12) & 63;
  int stage_v_176_2 = ((pub_r001930_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001930_20_1) & 127;
  int stage_v_177_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001930_20_2) & 127;
  if (stage_v_177_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_161_1 ^ 0x2A) * 2) + pub_r001930_17_1) & 127;
  int stage_v_178_2 = (((stage_v_161_2 ^ 0x2A) * 2) + pub_r001930_17_2) & 127;
  if (stage_v_178_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_178_1 ^ 0x2A) * 2) + pub_r001930_1_1) & 127;
  int stage_v_179_2 = (((stage_v_178_2 ^ 0x2A) * 2) + pub_r001930_1_2) & 127;
  if (stage_v_179_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((pub_r001930_13_1 * 2) + 5) & 63;
  int stage_v_180_2 = ((pub_r001930_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((sec_r001930_0_1 ^ 0x2A) * 2) + pub_r001930_9_1) & 127;
  int stage_v_181_2 = (((sec_r001930_0_2 ^ 0x2A) * 2) + pub_r001930_9_2) & 127;
  if (stage_v_181_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((pub_r001930_6_1 * 2) + 7) & 63;
  int stage_v_182_2 = ((pub_r001930_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001930_9_1 * 2) + 22) & 63;
  int stage_v_183_2 = ((pub_r001930_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001930_9_1 * 2) + 48) & 63;
  int stage_v_184_2 = ((pub_r001930_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001930_7_1) & 127;
  int stage_v_185_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001930_7_2) & 127;
  if (stage_v_185_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((pub_r001930_10_1 * 2) + 9) & 63;
  int stage_v_186_2 = ((pub_r001930_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001930_15_1) & 127;
  int stage_v_187_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001930_15_2) & 127;
  if (stage_v_187_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001930_7_1) & 127;
  int stage_v_188_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001930_7_2) & 127;
  if (stage_v_188_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001930_9_1) & 127;
  int stage_v_189_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001930_9_2) & 127;
  if (stage_v_189_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_190_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_190_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((pub_r001930_4_1 * 2) + 34) & 63;
  int stage_v_191_2 = ((pub_r001930_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001930_7_1) & 127;
  int stage_v_192_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001930_7_2) & 127;
  if (stage_v_192_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_157_1 ^ 0x2A) * 2) + pub_r001930_10_1) & 127;
  int stage_v_193_2 = (((stage_v_157_2 ^ 0x2A) * 2) + pub_r001930_10_2) & 127;
  if (stage_v_193_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001930_11_1) & 127;
  int stage_v_194_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001930_11_2) & 127;
  if (stage_v_194_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001930_5_1) & 127;
  int stage_v_195_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001930_5_2) & 127;
  if (stage_v_195_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001930_13_1) & 127;
  int stage_v_196_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001930_13_2) & 127;
  if (stage_v_196_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((pub_r001930_10_1 * 2) + 8) & 63;
  int stage_v_197_2 = ((pub_r001930_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001930_5_1 * 2) + 9) & 63;
  int stage_v_198_2 = ((pub_r001930_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001930_8_1 * 2) + 42) & 63;
  int stage_v_199_2 = ((pub_r001930_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_170_1 ^ 0x2A) * 2) + pub_r001930_18_1) & 127;
  int stage_v_200_2 = (((stage_v_170_2 ^ 0x2A) * 2) + pub_r001930_18_2) & 127;
  if (stage_v_200_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001930_16_1) & 127;
  int stage_v_201_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001930_16_2) & 127;
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
  int stage_v_202_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_202_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_202_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((pub_r001930_14_1 * 2) + 9) & 63;
  int stage_v_203_2 = ((pub_r001930_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001930_9_1) & 127;
  int stage_v_204_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001930_9_2) & 127;
  if (stage_v_204_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((pub_r001930_13_1 * 2) + 10) & 63;
  int stage_v_205_2 = ((pub_r001930_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001930_13_1 * 2) + 32) & 63;
  int stage_v_206_2 = ((pub_r001930_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001930_15_1) & 127;
  int stage_v_207_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001930_15_2) & 127;
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
  int stage_v_208_1 = (((stage_v_207_1 ^ 0x2A) * 2) + pub_r001930_7_1) & 127;
  int stage_v_208_2 = (((stage_v_207_2 ^ 0x2A) * 2) + pub_r001930_7_2) & 127;
  if (stage_v_208_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((pub_r001930_18_1 * 2) + 21) & 63;
  int stage_v_209_2 = ((pub_r001930_18_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001930_4_1) & 127;
  int stage_v_210_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001930_4_2) & 127;
  if (stage_v_210_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((stage_v_164_1 ^ 0x2A) * 2) + pub_r001930_15_1) & 127;
  int stage_v_211_2 = (((stage_v_164_2 ^ 0x2A) * 2) + pub_r001930_15_2) & 127;
  if (stage_v_211_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((pub_r001930_20_1 * 2) + 33) & 63;
  int stage_v_212_2 = ((pub_r001930_20_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001930_4_1 * 2) + 42) & 63;
  int stage_v_213_2 = ((pub_r001930_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001930_2_1) & 127;
  int stage_v_214_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001930_2_2) & 127;
  if (stage_v_214_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((pub_r001930_16_1 * 2) + 44) & 63;
  int stage_v_215_2 = ((pub_r001930_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001930_11_1) & 127;
  int stage_v_216_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001930_11_2) & 127;
  if (stage_v_216_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((sec_r001930_16_1 ^ 0x2A) * 2) + pub_r001930_16_1) & 127;
  int stage_v_217_2 = (((sec_r001930_16_2 ^ 0x2A) * 2) + pub_r001930_16_2) & 127;
  if (stage_v_217_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001930_5_1) & 127;
  int stage_v_218_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001930_5_2) & 127;
  if (stage_v_218_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001930_16_1) & 127;
  int stage_v_219_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001930_16_2) & 127;
  if (stage_v_219_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = (((stage_v_105_1 ^ 0x2A) * 2) + pub_r001930_9_1) & 127;
  int stage_v_220_2 = (((stage_v_105_2 ^ 0x2A) * 2) + pub_r001930_9_2) & 127;
  if (stage_v_220_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001930_17_1) & 127;
  int stage_v_221_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001930_17_2) & 127;
  if (stage_v_221_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((pub_r001930_9_1 * 2) + 15) & 63;
  int stage_v_222_2 = ((pub_r001930_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_211_1 ^ 0x2A) * 2) + pub_r001930_5_1) & 127;
  int stage_v_223_2 = (((stage_v_211_2 ^ 0x2A) * 2) + pub_r001930_5_2) & 127;
  if (stage_v_223_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((pub_r001930_11_1 * 2) + 32) & 63;
  int stage_v_224_2 = ((pub_r001930_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001930_15_1 * 2) + 48) & 63;
  int stage_v_225_2 = ((pub_r001930_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001930_0_1) & 127;
  int stage_v_226_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001930_0_2) & 127;
  if (stage_v_226_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = (((stage_v_202_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_227_2 = (((stage_v_202_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_227_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001930_6_1) & 127;
  int stage_v_228_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001930_6_2) & 127;
  if (stage_v_228_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((pub_r001930_0_1 * 2) + 50) & 63;
  int stage_v_229_2 = ((pub_r001930_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001930_12_1) & 127;
  int stage_v_230_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001930_12_2) & 127;
  if (stage_v_230_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001930_5_1) & 127;
  int stage_v_231_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001930_5_2) & 127;
  if (stage_v_231_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
  }
  if (stage_v_231_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001930_7_1) & 127;
  int stage_v_232_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001930_7_2) & 127;
  if (stage_v_232_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
  }
  if (stage_v_232_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = (((stage_v_178_1 ^ 0x2A) * 2) + pub_r001930_19_1) & 127;
  int stage_v_233_2 = (((stage_v_178_2 ^ 0x2A) * 2) + pub_r001930_19_2) & 127;
  if (stage_v_233_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = (((stage_v_125_1 ^ 0x2A) * 2) + pub_r001930_16_1) & 127;
  int stage_v_234_2 = (((stage_v_125_2 ^ 0x2A) * 2) + pub_r001930_16_2) & 127;
  if (stage_v_234_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
  }
  if (stage_v_234_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = (((sec_r001930_13_1 ^ 0x2A) * 2) + pub_r001930_9_1) & 127;
  int stage_v_235_2 = (((sec_r001930_13_2 ^ 0x2A) * 2) + pub_r001930_9_2) & 127;
  if (stage_v_235_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
  }
  if (stage_v_235_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001930_1_1) & 127;
  int stage_v_236_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001930_1_2) & 127;
  if (stage_v_236_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
  }
  if (stage_v_236_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001930_1_1) & 127;
  int stage_v_237_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001930_1_2) & 127;
  if (stage_v_237_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001930_9_1) & 127;
  int stage_v_238_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001930_9_2) & 127;
  if (stage_v_238_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
  }
  if (stage_v_238_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001930_9_1 != sec_r001930_9_2);
  __CPROVER_assume(pub_r001930_3_1 == pub_r001930_3_2);
  __CPROVER_assume(pub_r001930_19_1 == pub_r001930_19_2);
  __CPROVER_assume(pub_r001930_5_1 == pub_r001930_5_2);
  __CPROVER_assume(pub_r001930_2_1 == pub_r001930_2_2);
  __CPROVER_assume(sec_r001930_4_1 != sec_r001930_4_2);
  __CPROVER_assume(sec_r001930_10_1 != sec_r001930_10_2);
  __CPROVER_assume(pub_r001930_0_1 == pub_r001930_0_2);
  __CPROVER_assume(pub_r001930_21_1 == pub_r001930_21_2);
  __CPROVER_assume(pub_r001930_13_1 == pub_r001930_13_2);
  __CPROVER_assume(sec_r001930_6_1 != sec_r001930_6_2);
  __CPROVER_assume(pub_r001930_17_1 == pub_r001930_17_2);
  __CPROVER_assume(pub_r001930_18_1 == pub_r001930_18_2);
  __CPROVER_assume(pub_r001930_6_1 == pub_r001930_6_2);
  __CPROVER_assume(pub_r001930_20_1 == pub_r001930_20_2);
  __CPROVER_assume(sec_r001930_17_1 != sec_r001930_17_2);
  __CPROVER_assume(pub_r001930_14_1 == pub_r001930_14_2);
  __CPROVER_assume(pub_r001930_16_1 == pub_r001930_16_2);
  __CPROVER_assume(sec_r001930_3_1 != sec_r001930_3_2);
  __CPROVER_assume(sec_r001930_5_1 != sec_r001930_5_2);
  __CPROVER_assume(pub_r001930_8_1 == pub_r001930_8_2);
  __CPROVER_assume(sec_r001930_1_1 != sec_r001930_1_2);
  __CPROVER_assume(sec_r001930_0_1 != sec_r001930_0_2);
  __CPROVER_assume(sec_r001930_2_1 != sec_r001930_2_2);
  __CPROVER_assume(pub_r001930_12_1 == pub_r001930_12_2);
  __CPROVER_assume(sec_r001930_14_1 != sec_r001930_14_2);
  __CPROVER_assume(pub_r001930_4_1 == pub_r001930_4_2);
  __CPROVER_assume(sec_r001930_11_1 != sec_r001930_11_2);
  __CPROVER_assume(sec_r001930_16_1 != sec_r001930_16_2);
  __CPROVER_assume(sec_r001930_15_1 != sec_r001930_15_2);
  __CPROVER_assume(pub_r001930_7_1 == pub_r001930_7_2);
  __CPROVER_assume(sec_r001930_13_1 != sec_r001930_13_2);
  __CPROVER_assume(pub_r001930_10_1 == pub_r001930_10_2);
  __CPROVER_assume(pub_r001930_15_1 == pub_r001930_15_2);
  __CPROVER_assume(sec_r001930_12_1 != sec_r001930_12_2);
  __CPROVER_assume(pub_r001930_1_1 == pub_r001930_1_2);
  __CPROVER_assume(pub_r001930_11_1 == pub_r001930_11_2);
  __CPROVER_assume(pub_r001930_9_1 == pub_r001930_9_2);
  __CPROVER_assume(sec_r001930_8_1 != sec_r001930_8_2);
  __CPROVER_assume(sec_r001930_7_1 != sec_r001930_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.status == st_var_1_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.baud_rate == st_var_3_2.baud_rate);
  assert(st_var_3_1.stop_bits == st_var_3_2.stop_bits);
  assert(st_var_3_1.timeout == st_var_3_2.timeout);
  assert(st_var_3_1.parity == st_var_3_2.parity);
  assert(st_var_3_1.id == st_var_3_2.id);
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
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
  assert(helper_flow_11_1 == helper_flow_11_2);
  assert(helper_flow_12_1 == helper_flow_12_2);
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
}


