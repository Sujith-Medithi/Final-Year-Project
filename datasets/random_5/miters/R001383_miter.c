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
struct SensorNode_R001383_8313_0
{
  int reading;
  short offset;
  int calib;
  int threshold;
  int status;
  short gain;
  int buffer[3];
};
struct AudioFrame_R001383_8313_1
{
  int sample_rate;
  unsigned char envelope;
  int gain;
  int peak;
  int channels;
  int buffer[3];
};
struct DeviceConfig_R001383_8313_2
{
  int port;
  int stop_bits;
  int parity;
  unsigned char id;
  short timeout;
  int buffer[3];
};
union RegisterBank_R001383_8313_0
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
void fn_R001383_8313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st_1 = {0};
  struct SensorNode_R001383_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_70_1 = local_arr_1[aux_1 % 3];
  int anchor_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_70_2 * 2)) & 127;
  int anchor_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_92_1) & 63;
  aux_2 = (aux_2 + anchor_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_58_1 > 33)
  {
    acc_1 = ((acc_1 + (index_reg_58_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_58_2 > 33)
  {
    acc_2 = ((acc_2 + (index_reg_58_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_70_1 == anchor_70_2);
  assert(anchor_92_1 == anchor_92_2);
  assert(index_reg_58_1 == index_reg_58_2);
}

int fn_R001383_8313_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int anchor_70 = local_arr[aux % 3];
  acc = (acc + (anchor_70 * 2)) & 127;
  int anchor_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_92) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_58 > 33)
  {
    acc = ((acc + (index_reg_58 * 2)) + 5) & 127;
    aux ^= index_reg_58 & 15;
  }
  else
  {
    acc = ((acc - index_reg_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001383_8313_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st_1 = {0};
  struct DeviceConfig_R001383_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int margin_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_94_1 > 33)
  {
    acc_1 = ((acc_1 + (margin_94_1 * 2)) + 5) & 127;
    aux_1 ^= margin_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_94_2 > 33)
  {
    acc_2 = ((acc_2 + (margin_94_2 * 2)) + 5) & 127;
    aux_2 ^= margin_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_34_1 = 0;
  int coefficient_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_34_1 = ((coefficient_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_34_2 = ((coefficient_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_34_1) & 127;
    acc_2 = (acc_2 + coefficient_34_2) & 127;
  }

  int weight_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_59_1) & 63;
  aux_2 = (aux_2 + weight_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_94_1 == margin_94_2);
  assert(coefficient_34_1 == coefficient_34_2);
  assert(weight_59_1 == weight_59_2);
}

int fn_R001383_8313_1(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int margin_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_94 > 33)
  {
    acc = ((acc + (margin_94 * 2)) + 5) & 127;
    aux ^= margin_94 & 15;
  }
  else
  {
    acc = ((acc - margin_94) + 11) & 127;
    aux += 3;
  }
  int coefficient_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_34 = ((coefficient_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_34) & 127;
  }

  int weight_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001383_8313_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st_1 = {0};
  struct SensorNode_R001383_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int vector_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_80_1 > 19)
  {
    acc_1 = ((acc_1 + (vector_80_1 * 2)) + 5) & 127;
    aux_1 ^= vector_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_80_2 > 19)
  {
    acc_2 = ((acc_2 + (vector_80_2 * 2)) + 5) & 127;
    aux_2 ^= vector_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_80_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_34_1 = 0;
  int damping_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_34_1 = ((damping_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_34_2 = ((damping_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_34_1) & 127;
    acc_2 = (acc_2 + damping_34_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_80_1 == vector_80_2);
  assert(damping_34_1 == damping_34_2);
}

int fn_R001383_8313_2(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int vector_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_80 > 19)
  {
    acc = ((acc + (vector_80 * 2)) + 5) & 127;
    aux ^= vector_80 & 15;
  }
  else
  {
    acc = ((acc - vector_80) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_34 = ((damping_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_34) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001383_8313_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st_1 = {0};
  struct DeviceConfig_R001383_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_29_1 = local_arr_1[aux_1 % 3];
  int stride_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_29_2 * 2)) & 127;
  int phase_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_45_1 > 48)
  {
    acc_1 = ((acc_1 + (phase_45_1 * 2)) + 5) & 127;
    aux_1 ^= phase_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_45_2 > 48)
  {
    acc_2 = ((acc_2 + (phase_45_2 * 2)) + 5) & 127;
    aux_2 ^= phase_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_46_1) & 63;
  aux_2 = (aux_2 + threshold_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_29_1 == stride_29_2);
  assert(phase_45_1 == phase_45_2);
  assert(threshold_46_1 == threshold_46_2);
}

int fn_R001383_8313_3(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int stride_29 = local_arr[aux % 3];
  acc = (acc + (stride_29 * 2)) & 127;
  int phase_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_45 > 48)
  {
    acc = ((acc + (phase_45 * 2)) + 5) & 127;
    aux ^= phase_45 & 15;
  }
  else
  {
    acc = ((acc - phase_45) + 11) & 127;
    aux += 3;
  }
  int threshold_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_46) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001383_8313_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st_1 = {0};
  struct SensorNode_R001383_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int anchor_85_1 = 0;
  int anchor_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_85_1 = ((anchor_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_85_2 = ((anchor_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_85_1) & 127;
    acc_2 = (acc_2 + anchor_85_2) & 127;
  }

  int offset_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_60_1) & 63;
  aux_2 = (aux_2 + offset_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_78_1 > 43)
  {
    acc_1 = ((acc_1 + (stride_78_1 * 2)) + 5) & 127;
    aux_1 ^= stride_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_78_2 > 43)
  {
    acc_2 = ((acc_2 + (stride_78_2 * 2)) + 5) & 127;
    aux_2 ^= stride_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_85_1 == anchor_85_2);
  assert(offset_60_1 == offset_60_2);
  assert(stride_78_1 == stride_78_2);
}

int fn_R001383_8313_4(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int anchor_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_85 = ((anchor_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_85) & 127;
  }

  int offset_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_60) & 63;
  acc ^= aux;
  int stride_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_78 > 43)
  {
    acc = ((acc + (stride_78 * 2)) + 5) & 127;
    aux ^= stride_78 & 15;
  }
  else
  {
    acc = ((acc - stride_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001383_8313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st_1 = {0};
  struct DeviceConfig_R001383_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int sample_54_1 = 0;
  int sample_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_54_1 = ((sample_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_54_2 = ((sample_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_54_1) & 127;
    acc_2 = (acc_2 + sample_54_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_54_1 > 30)
  {
    acc_1 = ((acc_1 + (quantum_54_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_54_2 > 30)
  {
    acc_2 = ((acc_2 + (quantum_54_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_54_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_54_1 == sample_54_2);
  assert(quantum_54_1 == quantum_54_2);
}

int fn_R001383_8313_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int sample_54 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_54 = ((sample_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_54) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_54 > 30)
  {
    acc = ((acc + (quantum_54 * 2)) + 5) & 127;
    aux ^= quantum_54 & 15;
  }
  else
  {
    acc = ((acc - quantum_54) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001383_8313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st_1 = {0};
  struct SensorNode_R001383_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int cursor_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_12_1 > 10)
  {
    acc_1 = ((acc_1 + (cursor_12_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_12_2 > 10)
  {
    acc_2 = ((acc_2 + (cursor_12_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_24_1 = 0;
  int index_reg_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_24_1 = ((index_reg_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_24_2 = ((index_reg_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_24_1) & 127;
    acc_2 = (acc_2 + index_reg_24_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_12_1 == cursor_12_2);
  assert(index_reg_24_1 == index_reg_24_2);
}

int fn_R001383_8313_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int cursor_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_12 > 10)
  {
    acc = ((acc + (cursor_12 * 2)) + 5) & 127;
    aux ^= cursor_12 & 15;
  }
  else
  {
    acc = ((acc - cursor_12) + 11) & 127;
    aux += 3;
  }
  int index_reg_24 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_24 = ((index_reg_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_24) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001383_8313_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st_1 = {0};
  struct SensorNode_R001383_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quantum_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_35_1) & 63;
  aux_2 = (aux_2 + quantum_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_34_1 = local_arr_1[aux_1 % 3];
  int tally_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_34_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_35_1 == quantum_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_34_1 == tally_34_2);
}

int fn_R001383_8313_7(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quantum_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_35) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_34 = local_arr[aux % 3];
  acc = (acc + (tally_34 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001383_8313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st_1 = {0};
  struct DeviceConfig_R001383_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int pivot_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_47_1)
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

  switch (pivot_47_2)
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
  int checksum_88_1 = local_arr_1[aux_1 % 3];
  int checksum_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_88_2 * 2)) & 127;
  int segment_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_37_1 > 30)
  {
    acc_1 = ((acc_1 + (segment_37_1 * 2)) + 5) & 127;
    aux_1 ^= segment_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_37_2 > 30)
  {
    acc_2 = ((acc_2 + (segment_37_2 * 2)) + 5) & 127;
    aux_2 ^= segment_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_20_1) & 63;
  aux_2 = (aux_2 + anchor_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_47_1 == pivot_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_88_1 == checksum_88_2);
  assert(segment_37_1 == segment_37_2);
  assert(anchor_20_1 == anchor_20_2);
}

int fn_R001383_8313_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int pivot_47 = (aux + st.buffer[1]) & 3;
  switch (pivot_47)
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
  int checksum_88 = local_arr[aux % 3];
  acc = (acc + (checksum_88 * 2)) & 127;
  int segment_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_37 > 30)
  {
    acc = ((acc + (segment_37 * 2)) + 5) & 127;
    aux ^= segment_37 & 15;
  }
  else
  {
    acc = ((acc - segment_37) + 11) & 127;
    aux += 3;
  }
  int anchor_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_20) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001383_8313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st_1 = {0};
  struct SensorNode_R001383_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_28_1) & 63;
  aux_2 = (aux_2 + window_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_37_1 = 0;
  int index_reg_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_37_1 = ((index_reg_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_37_2 = ((index_reg_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_37_1) & 127;
    acc_2 = (acc_2 + index_reg_37_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_42_1 = local_arr_1[aux_1 % 3];
  int tally_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_28_1 == window_28_2);
  assert(index_reg_37_1 == index_reg_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_42_1 == tally_42_2);
}

int fn_R001383_8313_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_28) & 63;
  acc ^= aux;
  int index_reg_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_37 = ((index_reg_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_37) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tally_42 = local_arr[aux % 3];
  acc = (acc + (tally_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001383_8313_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001383_8313_1 st_1 = {0};
  struct AudioFrame_R001383_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int coefficient_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_60_1) & 63;
  aux_2 = (aux_2 + coefficient_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_26_1)
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

  switch (tracker_26_2)
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

  int anchor_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_37_1 > 10)
  {
    acc_1 = ((acc_1 + (anchor_37_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_37_2 > 10)
  {
    acc_2 = ((acc_2 + (anchor_37_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_58_1 = 0;
  int accumulator_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_58_1 = ((accumulator_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_58_2 = ((accumulator_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_58_1) & 127;
    acc_2 = (acc_2 + accumulator_58_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_60_1 == coefficient_60_2);
  assert(tracker_26_1 == tracker_26_2);
  assert(anchor_37_1 == anchor_37_2);
  assert(accumulator_58_1 == accumulator_58_2);
}

int fn_R001383_8313_10(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001383_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int coefficient_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_60) & 63;
  acc ^= aux;
  int tracker_26 = (aux + st.buffer[1]) & 3;
  switch (tracker_26)
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

  int anchor_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_37 > 10)
  {
    acc = ((acc + (anchor_37 * 2)) + 5) & 127;
    aux ^= anchor_37 & 15;
  }
  else
  {
    acc = ((acc - anchor_37) + 11) & 127;
    aux += 3;
  }
  int accumulator_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_58 = ((accumulator_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_58) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001383_8313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st_1 = {0};
  struct SensorNode_R001383_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_81_1 = local_arr_1[aux_1 % 3];
  int coefficient_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_81_2 * 2)) & 127;
  int margin_64_1 = 0;
  int margin_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_64_1 = ((margin_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_64_2 = ((margin_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_64_1) & 127;
    acc_2 = (acc_2 + margin_64_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_81_1 == coefficient_81_2);
  assert(margin_64_1 == margin_64_2);
}

int fn_R001383_8313_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int coefficient_81 = local_arr[aux % 3];
  acc = (acc + (coefficient_81 * 2)) & 127;
  int margin_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_64 = ((margin_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_64) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001383_8313_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st_1 = {0};
  struct DeviceConfig_R001383_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int offset_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_13_1) & 63;
  aux_2 = (aux_2 + offset_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_40_1 = local_arr_1[aux_1 % 3];
  int window_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_40_2 * 2)) & 127;
  int pivot_20_1 = 0;
  int pivot_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_20_1 = ((pivot_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_20_2 = ((pivot_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_20_1) & 127;
    acc_2 = (acc_2 + pivot_20_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_13_1 == offset_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_40_1 == window_40_2);
  assert(pivot_20_1 == pivot_20_2);
}

int fn_R001383_8313_12(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int offset_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_13) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int window_40 = local_arr[aux % 3];
  acc = (acc + (window_40 * 2)) & 127;
  int pivot_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_20 = ((pivot_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_20) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001383_8313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st_1 = {0};
  struct DeviceConfig_R001383_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int scale_42_1 = 0;
  int scale_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_42_1 = ((scale_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_42_2 = ((scale_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_42_1) & 127;
    acc_2 = (acc_2 + scale_42_2) & 127;
  }

  int metric_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_42_1) & 63;
  aux_2 = (aux_2 + metric_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_98_1)
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

  switch (stride_98_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_42_1 == scale_42_2);
  assert(metric_42_1 == metric_42_2);
  assert(stride_98_1 == stride_98_2);
}

int fn_R001383_8313_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int scale_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_42 = ((scale_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_42) & 127;
  }

  int metric_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_42) & 63;
  acc ^= aux;
  int stride_98 = (aux + st.buffer[1]) & 3;
  switch (stride_98)
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

void fn_R001383_8313_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st_1 = {0};
  struct SensorNode_R001383_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int metric_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_80_1 > 14)
  {
    acc_1 = ((acc_1 + (metric_80_1 * 2)) + 5) & 127;
    aux_1 ^= metric_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_80_2 > 14)
  {
    acc_2 = ((acc_2 + (metric_80_2 * 2)) + 5) & 127;
    aux_2 ^= metric_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_28_1)
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

  switch (anchor_28_2)
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
  int cursor_49_1 = local_arr_1[aux_1 % 3];
  int cursor_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_49_2 * 2)) & 127;
  int offset_64_1 = 0;
  int offset_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_64_1 = ((offset_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_64_2 = ((offset_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_64_1) & 127;
    acc_2 = (acc_2 + offset_64_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_80_1 == metric_80_2);
  assert(anchor_28_1 == anchor_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_49_1 == cursor_49_2);
  assert(offset_64_1 == offset_64_2);
}

int fn_R001383_8313_14(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int metric_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_80 > 14)
  {
    acc = ((acc + (metric_80 * 2)) + 5) & 127;
    aux ^= metric_80 & 15;
  }
  else
  {
    acc = ((acc - metric_80) + 11) & 127;
    aux += 3;
  }
  int anchor_28 = (aux + st.buffer[1]) & 3;
  switch (anchor_28)
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
  int cursor_49 = local_arr[aux % 3];
  acc = (acc + (cursor_49 * 2)) & 127;
  int offset_64 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_64 = ((offset_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_64) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001383_8313_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001383_8313_1 st_1 = {0};
  struct AudioFrame_R001383_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_12_1 = local_arr_1[aux_1 % 3];
  int sample_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_12_2 * 2)) & 127;
  int stride_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_68_1) & 63;
  aux_2 = (aux_2 + stride_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
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

  assert(sample_12_1 == sample_12_2);
  assert(stride_68_1 == stride_68_2);
}

int fn_R001383_8313_15(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001383_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_12 = local_arr[aux % 3];
  acc = (acc + (sample_12 * 2)) & 127;
  int stride_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001383_8313_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001383_8313_1 st_1 = {0};
  struct AudioFrame_R001383_8313_1 st_2 = {0};
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
  int tracker_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_92_1) & 63;
  aux_2 = (aux_2 + tracker_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_59_1 = 0;
  int quotient_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_59_1 = ((quotient_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_59_2 = ((quotient_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_59_1) & 127;
    acc_2 = (acc_2 + quotient_59_2) & 127;
  }

  int segment_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_18_1 > 48)
  {
    acc_1 = ((acc_1 + (segment_18_1 * 2)) + 5) & 127;
    aux_1 ^= segment_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_18_2 > 48)
  {
    acc_2 = ((acc_2 + (segment_18_2 * 2)) + 5) & 127;
    aux_2 ^= segment_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_92_1 == tracker_92_2);
  assert(quotient_59_1 == quotient_59_2);
  assert(segment_18_1 == segment_18_2);
}

int fn_R001383_8313_16(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001383_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_92) & 63;
  acc ^= aux;
  int quotient_59 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_59 = ((quotient_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_59) & 127;
  }

  int segment_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_18 > 48)
  {
    acc = ((acc + (segment_18 * 2)) + 5) & 127;
    aux ^= segment_18 & 15;
  }
  else
  {
    acc = ((acc - segment_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001383_8313_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st_1 = {0};
  struct SensorNode_R001383_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_23_1)
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

  switch (delta_23_2)
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

  int offset_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_49_1 > 16)
  {
    acc_1 = ((acc_1 + (offset_49_1 * 2)) + 5) & 127;
    aux_1 ^= offset_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_49_2 > 16)
  {
    acc_2 = ((acc_2 + (offset_49_2 * 2)) + 5) & 127;
    aux_2 ^= offset_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_23_1 == delta_23_2);
  assert(offset_49_1 == offset_49_2);
}

int fn_R001383_8313_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001383_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_23 = (aux + st.buffer[1]) & 3;
  switch (delta_23)
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

  int offset_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_49 > 16)
  {
    acc = ((acc + (offset_49 * 2)) + 5) & 127;
    aux ^= offset_49 & 15;
  }
  else
  {
    acc = ((acc - offset_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001383_8313_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st_1 = {0};
  struct DeviceConfig_R001383_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int anchor_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_14_1 > 17)
  {
    acc_1 = ((acc_1 + (anchor_14_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_14_2 > 17)
  {
    acc_2 = ((acc_2 + (anchor_14_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_31_1 = local_arr_1[aux_1 % 3];
  int segment_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_14_1 == anchor_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_31_1 == segment_31_2);
}

int fn_R001383_8313_18(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int anchor_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_14 > 17)
  {
    acc = ((acc + (anchor_14 * 2)) + 5) & 127;
    aux ^= anchor_14 & 15;
  }
  else
  {
    acc = ((acc - anchor_14) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_31 = local_arr[aux % 3];
  acc = (acc + (segment_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001383_8313_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001383_8313_1 st_1 = {0};
  struct AudioFrame_R001383_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int weight_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_90_1) & 63;
  aux_2 = (aux_2 + weight_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_45_1 > 27)
  {
    acc_1 = ((acc_1 + (delta_45_1 * 2)) + 5) & 127;
    aux_1 ^= delta_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_45_2 > 27)
  {
    acc_2 = ((acc_2 + (delta_45_2 * 2)) + 5) & 127;
    aux_2 ^= delta_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_90_1 == weight_90_2);
  assert(delta_45_1 == delta_45_2);
}

int fn_R001383_8313_19(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001383_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int weight_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_90) & 63;
  acc ^= aux;
  int delta_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_45 > 27)
  {
    acc = ((acc + (delta_45 * 2)) + 5) & 127;
    aux ^= delta_45 & 15;
  }
  else
  {
    acc = ((acc - delta_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001383_8313_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001383_8313_1 st_1 = {0};
  struct AudioFrame_R001383_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int tally_66_1 = 0;
  int tally_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_66_1 = ((tally_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_66_2 = ((tally_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_66_1) & 127;
    acc_2 = (acc_2 + tally_66_2) & 127;
  }

  int delta_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_16_1)
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

  switch (delta_16_2)
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

  int delta_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_81_1 > 36)
  {
    acc_1 = ((acc_1 + (delta_81_1 * 2)) + 5) & 127;
    aux_1 ^= delta_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_81_2 > 36)
  {
    acc_2 = ((acc_2 + (delta_81_2 * 2)) + 5) & 127;
    aux_2 ^= delta_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_81_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_66_1 == tally_66_2);
  assert(delta_16_1 == delta_16_2);
  assert(delta_81_1 == delta_81_2);
}

int fn_R001383_8313_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001383_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int tally_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_66 = ((tally_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_66) & 127;
  }

  int delta_16 = (aux + st.buffer[1]) & 3;
  switch (delta_16)
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

  int delta_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_81 > 36)
  {
    acc = ((acc + (delta_81 * 2)) + 5) & 127;
    aux ^= delta_81 & 15;
  }
  else
  {
    acc = ((acc - delta_81) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001383_8313_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st_1 = {0};
  struct DeviceConfig_R001383_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quantum_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_28_1)
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

  switch (quantum_28_2)
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

  int tracker_38_1 = 0;
  int tracker_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_38_1 = ((tracker_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_38_2 = ((tracker_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_38_1) & 127;
    acc_2 = (acc_2 + tracker_38_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_48_1 = local_arr_1[aux_1 % 3];
  int tracker_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_48_2 * 2)) & 127;
  int metric_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_29_1 > 28)
  {
    acc_1 = ((acc_1 + (metric_29_1 * 2)) + 5) & 127;
    aux_1 ^= metric_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_29_2 > 28)
  {
    acc_2 = ((acc_2 + (metric_29_2 * 2)) + 5) & 127;
    aux_2 ^= metric_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_28_1 == quantum_28_2);
  assert(tracker_38_1 == tracker_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_48_1 == tracker_48_2);
  assert(metric_29_1 == metric_29_2);
}

int fn_R001383_8313_21(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quantum_28 = (aux + st.buffer[1]) & 3;
  switch (quantum_28)
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

  int tracker_38 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_38 = ((tracker_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_38) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tracker_48 = local_arr[aux % 3];
  acc = (acc + (tracker_48 * 2)) & 127;
  int metric_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_29 > 28)
  {
    acc = ((acc + (metric_29 * 2)) + 5) & 127;
    aux ^= metric_29 & 15;
  }
  else
  {
    acc = ((acc - metric_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001383_8313_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st_1 = {0};
  struct DeviceConfig_R001383_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int offset_57_1 = 0;
  int offset_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_57_1 = ((offset_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_57_2 = ((offset_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_57_1) & 127;
    acc_2 = (acc_2 + offset_57_2) & 127;
  }

  int stride_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_76_1)
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

  switch (stride_76_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_57_1 == offset_57_2);
  assert(stride_76_1 == stride_76_2);
}

int fn_R001383_8313_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001383_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int offset_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_57 = ((offset_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_57) & 127;
  }

  int stride_76 = (aux + st.buffer[1]) & 3;
  switch (stride_76)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001383_0_1;
  int sec_r001383_0_2;
  int sec_r001383_1_1;
  int sec_r001383_1_2;
  int sec_r001383_2_1;
  int sec_r001383_2_2;
  int sec_r001383_3_1;
  int sec_r001383_3_2;
  int sec_r001383_4_1;
  int sec_r001383_4_2;
  int sec_r001383_5_1;
  int sec_r001383_5_2;
  int sec_r001383_6_1;
  int sec_r001383_6_2;
  int sec_r001383_7_1;
  int sec_r001383_7_2;
  int sec_r001383_8_1;
  int sec_r001383_8_2;
  int sec_r001383_9_1;
  int sec_r001383_9_2;
  int sec_r001383_10_1;
  int sec_r001383_10_2;
  int sec_r001383_11_1;
  int sec_r001383_11_2;
  int sec_r001383_12_1;
  int sec_r001383_12_2;
  int sec_r001383_13_1;
  int sec_r001383_13_2;
  int sec_r001383_14_1;
  int sec_r001383_14_2;
  int sec_r001383_15_1;
  int sec_r001383_15_2;
  int pub_r001383_0_1;
  int pub_r001383_0_2;
  int pub_r001383_1_1;
  int pub_r001383_1_2;
  int pub_r001383_2_1;
  int pub_r001383_2_2;
  int pub_r001383_3_1;
  int pub_r001383_3_2;
  int pub_r001383_4_1;
  int pub_r001383_4_2;
  int pub_r001383_5_1;
  int pub_r001383_5_2;
  int pub_r001383_6_1;
  int pub_r001383_6_2;
  int pub_r001383_7_1;
  int pub_r001383_7_2;
  int pub_r001383_8_1;
  int pub_r001383_8_2;
  int pub_r001383_9_1;
  int pub_r001383_9_2;
  int pub_r001383_10_1;
  int pub_r001383_10_2;
  int pub_r001383_11_1;
  int pub_r001383_11_2;
  int pub_r001383_12_1;
  int pub_r001383_12_2;
  int pub_r001383_13_1;
  int pub_r001383_13_2;
  int pub_r001383_14_1;
  int pub_r001383_14_2;
  int pub_r001383_15_1;
  int pub_r001383_15_2;
  int pub_r001383_16_1;
  int pub_r001383_16_2;
  int pub_r001383_17_1;
  int pub_r001383_17_2;
  int pub_r001383_18_1;
  int pub_r001383_18_2;
  int pub_r001383_19_1;
  int pub_r001383_19_2;
  int pub_r001383_20_1;
  int pub_r001383_20_2;
  int pub_r001383_21_1;
  int pub_r001383_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001383_0_1 >= (-100)) && (pub_r001383_0_1 <= 100));
  __CPROVER_assume((pub_r001383_0_2 >= (-100)) && (pub_r001383_0_2 <= 100));
  __CPROVER_assume((pub_r001383_1_1 >= (-100)) && (pub_r001383_1_1 <= 100));
  __CPROVER_assume((pub_r001383_1_2 >= (-100)) && (pub_r001383_1_2 <= 100));
  __CPROVER_assume((pub_r001383_2_1 >= (-100)) && (pub_r001383_2_1 <= 100));
  __CPROVER_assume((pub_r001383_2_2 >= (-100)) && (pub_r001383_2_2 <= 100));
  __CPROVER_assume((pub_r001383_3_1 >= (-100)) && (pub_r001383_3_1 <= 100));
  __CPROVER_assume((pub_r001383_3_2 >= (-100)) && (pub_r001383_3_2 <= 100));
  __CPROVER_assume((pub_r001383_4_1 >= (-100)) && (pub_r001383_4_1 <= 100));
  __CPROVER_assume((pub_r001383_4_2 >= (-100)) && (pub_r001383_4_2 <= 100));
  __CPROVER_assume((pub_r001383_5_1 >= (-100)) && (pub_r001383_5_1 <= 100));
  __CPROVER_assume((pub_r001383_5_2 >= (-100)) && (pub_r001383_5_2 <= 100));
  __CPROVER_assume((pub_r001383_6_1 >= (-100)) && (pub_r001383_6_1 <= 100));
  __CPROVER_assume((pub_r001383_6_2 >= (-100)) && (pub_r001383_6_2 <= 100));
  __CPROVER_assume((pub_r001383_7_1 >= (-100)) && (pub_r001383_7_1 <= 100));
  __CPROVER_assume((pub_r001383_7_2 >= (-100)) && (pub_r001383_7_2 <= 100));
  __CPROVER_assume((pub_r001383_8_1 >= (-100)) && (pub_r001383_8_1 <= 100));
  __CPROVER_assume((pub_r001383_8_2 >= (-100)) && (pub_r001383_8_2 <= 100));
  __CPROVER_assume((pub_r001383_9_1 >= (-100)) && (pub_r001383_9_1 <= 100));
  __CPROVER_assume((pub_r001383_9_2 >= (-100)) && (pub_r001383_9_2 <= 100));
  __CPROVER_assume((pub_r001383_10_1 >= (-100)) && (pub_r001383_10_1 <= 100));
  __CPROVER_assume((pub_r001383_10_2 >= (-100)) && (pub_r001383_10_2 <= 100));
  __CPROVER_assume((pub_r001383_11_1 >= (-100)) && (pub_r001383_11_1 <= 100));
  __CPROVER_assume((pub_r001383_11_2 >= (-100)) && (pub_r001383_11_2 <= 100));
  __CPROVER_assume((pub_r001383_12_1 >= (-100)) && (pub_r001383_12_1 <= 100));
  __CPROVER_assume((pub_r001383_12_2 >= (-100)) && (pub_r001383_12_2 <= 100));
  __CPROVER_assume((pub_r001383_13_1 >= (-100)) && (pub_r001383_13_1 <= 100));
  __CPROVER_assume((pub_r001383_13_2 >= (-100)) && (pub_r001383_13_2 <= 100));
  __CPROVER_assume((pub_r001383_14_1 >= (-100)) && (pub_r001383_14_1 <= 100));
  __CPROVER_assume((pub_r001383_14_2 >= (-100)) && (pub_r001383_14_2 <= 100));
  __CPROVER_assume((pub_r001383_15_1 >= (-100)) && (pub_r001383_15_1 <= 100));
  __CPROVER_assume((pub_r001383_15_2 >= (-100)) && (pub_r001383_15_2 <= 100));
  __CPROVER_assume((pub_r001383_16_1 >= (-100)) && (pub_r001383_16_1 <= 100));
  __CPROVER_assume((pub_r001383_16_2 >= (-100)) && (pub_r001383_16_2 <= 100));
  __CPROVER_assume((pub_r001383_17_1 >= (-100)) && (pub_r001383_17_1 <= 100));
  __CPROVER_assume((pub_r001383_17_2 >= (-100)) && (pub_r001383_17_2 <= 100));
  __CPROVER_assume((pub_r001383_18_1 >= (-100)) && (pub_r001383_18_1 <= 100));
  __CPROVER_assume((pub_r001383_18_2 >= (-100)) && (pub_r001383_18_2 <= 100));
  __CPROVER_assume((pub_r001383_19_1 >= (-100)) && (pub_r001383_19_1 <= 100));
  __CPROVER_assume((pub_r001383_19_2 >= (-100)) && (pub_r001383_19_2 <= 100));
  __CPROVER_assume((pub_r001383_20_1 >= (-100)) && (pub_r001383_20_1 <= 100));
  __CPROVER_assume((pub_r001383_20_2 >= (-100)) && (pub_r001383_20_2 <= 100));
  __CPROVER_assume((pub_r001383_21_1 >= (-100)) && (pub_r001383_21_1 <= 100));
  __CPROVER_assume((pub_r001383_21_2 >= (-100)) && (pub_r001383_21_2 <= 100));
  __CPROVER_assume((sec_r001383_0_1 >= 0) && (sec_r001383_0_1 <= 255));
  __CPROVER_assume((sec_r001383_0_2 >= 0) && (sec_r001383_0_2 <= 255));
  __CPROVER_assume((sec_r001383_1_1 >= 0) && (sec_r001383_1_1 <= 255));
  __CPROVER_assume((sec_r001383_1_2 >= 0) && (sec_r001383_1_2 <= 255));
  __CPROVER_assume((sec_r001383_2_1 >= 0) && (sec_r001383_2_1 <= 255));
  __CPROVER_assume((sec_r001383_2_2 >= 0) && (sec_r001383_2_2 <= 255));
  __CPROVER_assume((sec_r001383_3_1 >= 0) && (sec_r001383_3_1 <= 255));
  __CPROVER_assume((sec_r001383_3_2 >= 0) && (sec_r001383_3_2 <= 255));
  __CPROVER_assume((sec_r001383_4_1 >= 0) && (sec_r001383_4_1 <= 255));
  __CPROVER_assume((sec_r001383_4_2 >= 0) && (sec_r001383_4_2 <= 255));
  __CPROVER_assume((sec_r001383_5_1 >= 0) && (sec_r001383_5_1 <= 255));
  __CPROVER_assume((sec_r001383_5_2 >= 0) && (sec_r001383_5_2 <= 255));
  __CPROVER_assume((sec_r001383_6_1 >= 0) && (sec_r001383_6_1 <= 255));
  __CPROVER_assume((sec_r001383_6_2 >= 0) && (sec_r001383_6_2 <= 255));
  __CPROVER_assume((sec_r001383_7_1 >= 0) && (sec_r001383_7_1 <= 255));
  __CPROVER_assume((sec_r001383_7_2 >= 0) && (sec_r001383_7_2 <= 255));
  __CPROVER_assume((sec_r001383_8_1 >= 0) && (sec_r001383_8_1 <= 255));
  __CPROVER_assume((sec_r001383_8_2 >= 0) && (sec_r001383_8_2 <= 255));
  __CPROVER_assume((sec_r001383_9_1 >= 0) && (sec_r001383_9_1 <= 255));
  __CPROVER_assume((sec_r001383_9_2 >= 0) && (sec_r001383_9_2 <= 255));
  __CPROVER_assume((sec_r001383_10_1 >= 0) && (sec_r001383_10_1 <= 255));
  __CPROVER_assume((sec_r001383_10_2 >= 0) && (sec_r001383_10_2 <= 255));
  __CPROVER_assume((sec_r001383_11_1 >= 0) && (sec_r001383_11_1 <= 255));
  __CPROVER_assume((sec_r001383_11_2 >= 0) && (sec_r001383_11_2 <= 255));
  __CPROVER_assume((sec_r001383_12_1 >= 0) && (sec_r001383_12_1 <= 255));
  __CPROVER_assume((sec_r001383_12_2 >= 0) && (sec_r001383_12_2 <= 255));
  __CPROVER_assume((sec_r001383_13_1 >= 0) && (sec_r001383_13_1 <= 255));
  __CPROVER_assume((sec_r001383_13_2 >= 0) && (sec_r001383_13_2 <= 255));
  __CPROVER_assume((sec_r001383_14_1 >= 0) && (sec_r001383_14_1 <= 255));
  __CPROVER_assume((sec_r001383_14_2 >= 0) && (sec_r001383_14_2 <= 255));
  __CPROVER_assume((sec_r001383_15_1 >= 0) && (sec_r001383_15_1 <= 255));
  __CPROVER_assume((sec_r001383_15_2 >= 0) && (sec_r001383_15_2 <= 255));
  struct SensorNode_R001383_8313_0 st_var_0_1 = {0};
  struct SensorNode_R001383_8313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001383_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001383_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001383_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001383_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001383_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001383_0_2 + 7) & 15;
  struct AudioFrame_R001383_8313_1 st_var_1_1 = {0};
  struct AudioFrame_R001383_8313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001383_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001383_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001383_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001383_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001383_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001383_0_2 + 9) & 15;
  struct DeviceConfig_R001383_8313_2 st_var_2_1 = {0};
  struct DeviceConfig_R001383_8313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001383_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001383_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001383_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001383_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001383_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001383_0_2 + 11) & 15;
  union RegisterBank_R001383_8313_0 u_var_1;
  union RegisterBank_R001383_8313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001383_8313_0(sec_r001383_0_1, pub_r001383_1_1, pub_r001383_2_1, pub_r001383_3_1);
  int helper_flow_0_2 = fn_R001383_8313_0(sec_r001383_0_2, pub_r001383_1_2, pub_r001383_2_2, pub_r001383_3_2);
  fn_R001383_8313_0_2(sec_r001383_0_1, pub_r001383_1_1, pub_r001383_2_1, pub_r001383_3_1, sec_r001383_0_2, pub_r001383_1_2, pub_r001383_2_2, pub_r001383_3_2);
  int helper_flow_1_1 = fn_R001383_8313_1(sec_r001383_1_1, pub_r001383_2_1);
  int helper_flow_1_2 = fn_R001383_8313_1(sec_r001383_1_2, pub_r001383_2_2);
  fn_R001383_8313_1_2(sec_r001383_1_1, pub_r001383_2_1, sec_r001383_1_2, pub_r001383_2_2);
  int helper_flow_2_1 = fn_R001383_8313_2(sec_r001383_2_1, pub_r001383_3_1);
  int helper_flow_2_2 = fn_R001383_8313_2(sec_r001383_2_2, pub_r001383_3_2);
  fn_R001383_8313_2_2(sec_r001383_2_1, pub_r001383_3_1, sec_r001383_2_2, pub_r001383_3_2);
  int helper_flow_3_1 = fn_R001383_8313_3(sec_r001383_3_1, sec_r001383_4_1);
  int helper_flow_3_2 = fn_R001383_8313_3(sec_r001383_3_2, sec_r001383_4_2);
  fn_R001383_8313_3_2(sec_r001383_3_1, sec_r001383_4_1, sec_r001383_3_2, sec_r001383_4_2);
  int helper_flow_4_1 = fn_R001383_8313_4(sec_r001383_4_1, sec_r001383_5_1, pub_r001383_6_1);
  int helper_flow_4_2 = fn_R001383_8313_4(sec_r001383_4_2, sec_r001383_5_2, pub_r001383_6_2);
  fn_R001383_8313_4_2(sec_r001383_4_1, sec_r001383_5_1, pub_r001383_6_1, sec_r001383_4_2, sec_r001383_5_2, pub_r001383_6_2);
  int helper_flow_5_1 = fn_R001383_8313_5(sec_r001383_5_1, sec_r001383_6_1, pub_r001383_7_1, pub_r001383_8_1);
  int helper_flow_5_2 = fn_R001383_8313_5(sec_r001383_5_2, sec_r001383_6_2, pub_r001383_7_2, pub_r001383_8_2);
  fn_R001383_8313_5_2(sec_r001383_5_1, sec_r001383_6_1, pub_r001383_7_1, pub_r001383_8_1, sec_r001383_5_2, sec_r001383_6_2, pub_r001383_7_2, pub_r001383_8_2);
  int helper_flow_6_1 = fn_R001383_8313_6(sec_r001383_6_1, pub_r001383_7_1, pub_r001383_8_1, pub_r001383_9_1);
  int helper_flow_6_2 = fn_R001383_8313_6(sec_r001383_6_2, pub_r001383_7_2, pub_r001383_8_2, pub_r001383_9_2);
  fn_R001383_8313_6_2(sec_r001383_6_1, pub_r001383_7_1, pub_r001383_8_1, pub_r001383_9_1, sec_r001383_6_2, pub_r001383_7_2, pub_r001383_8_2, pub_r001383_9_2);
  int helper_flow_7_1 = fn_R001383_8313_7(sec_r001383_7_1, pub_r001383_8_1, pub_r001383_9_1);
  int helper_flow_7_2 = fn_R001383_8313_7(sec_r001383_7_2, pub_r001383_8_2, pub_r001383_9_2);
  fn_R001383_8313_7_2(sec_r001383_7_1, pub_r001383_8_1, pub_r001383_9_1, sec_r001383_7_2, pub_r001383_8_2, pub_r001383_9_2);
  int stage_v_0_1 = (((sec_r001383_13_1 * 3) + pub_r001383_9_1) + 36) & 127;
  int stage_v_0_2 = (((sec_r001383_13_2 * 3) + pub_r001383_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = ((pub_r001383_15_1 * 2) + 16) & 63;
  int stage_v_1_2 = ((pub_r001383_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001383_17_1 * 2) + 40) & 63;
  int stage_v_2_2 = ((pub_r001383_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001383_3_1 * 3) + pub_r001383_17_1) + 10) & 127;
  int stage_v_3_2 = (((sec_r001383_3_2 * 3) + pub_r001383_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = ((pub_r001383_14_1 * 2) + 43) & 63;
  int stage_v_4_2 = ((pub_r001383_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((sec_r001383_15_1 * 3) + pub_r001383_9_1) + 15) & 127;
  int stage_v_5_2 = (((sec_r001383_15_2 * 3) + pub_r001383_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((helper_flow_3_1 * 3) + pub_r001383_6_1) + 15) & 127;
  int stage_v_6_2 = (((helper_flow_3_2 * 3) + pub_r001383_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = ((pub_r001383_14_1 * 2) + 27) & 63;
  int stage_v_7_2 = ((pub_r001383_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001383_14_1 * 2) + 19) & 63;
  int stage_v_8_2 = ((pub_r001383_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001383_13_1 * 2) + 34) & 63;
  int stage_v_9_2 = ((pub_r001383_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001383_3_1 * 2) + 5) & 63;
  int stage_v_10_2 = ((pub_r001383_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001383_17_1 * 2) + 31) & 63;
  int stage_v_11_2 = ((pub_r001383_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001383_2_1 * 2) + 47) & 63;
  int stage_v_12_2 = ((pub_r001383_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((sec_r001383_12_1 * 3) + pub_r001383_7_1) + 14) & 127;
  int stage_v_13_2 = (((sec_r001383_12_2 * 3) + pub_r001383_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = ((pub_r001383_6_1 * 2) + 38) & 63;
  int stage_v_14_2 = ((pub_r001383_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001383_21_1 * 2) + 22) & 63;
  int stage_v_15_2 = ((pub_r001383_21_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001383_0_1 * 3) + pub_r001383_8_1) + 17) & 127;
  int stage_v_16_2 = (((sec_r001383_0_2 * 3) + pub_r001383_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((helper_flow_3_1 * 3) + pub_r001383_14_1) + 6) & 127;
  int stage_v_17_2 = (((helper_flow_3_2 * 3) + pub_r001383_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001383_3_1 * 2) + 46) & 63;
  int stage_v_18_2 = ((pub_r001383_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((stage_v_13_1 * 3) + pub_r001383_12_1) + 39) & 127;
  int stage_v_19_2 = (((stage_v_13_2 * 3) + pub_r001383_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001383_3_1 * 2) + 5) & 63;
  int stage_v_20_2 = ((pub_r001383_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001383_17_1 * 2) + 46) & 63;
  int stage_v_21_2 = ((pub_r001383_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((sec_r001383_9_1 * 3) + pub_r001383_8_1) + 12) & 127;
  int stage_v_22_2 = (((sec_r001383_9_2 * 3) + pub_r001383_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001383_13_1 * 2) + 44) & 63;
  int stage_v_23_2 = ((pub_r001383_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001383_6_1 * 2) + 22) & 63;
  int stage_v_24_2 = ((pub_r001383_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (((stage_v_0_1 * 3) + pub_r001383_19_1) + 7) & 127;
  int stage_v_25_2 = (((stage_v_0_2 * 3) + pub_r001383_19_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = ((pub_r001383_16_1 * 2) + 20) & 63;
  int stage_v_26_2 = ((pub_r001383_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (((sec_r001383_1_1 * 3) + pub_r001383_8_1) + 25) & 127;
  int stage_v_27_2 = (((sec_r001383_1_2 * 3) + pub_r001383_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = (((sec_r001383_12_1 * 3) + pub_r001383_21_1) + 12) & 127;
  int stage_v_28_2 = (((sec_r001383_12_2 * 3) + pub_r001383_21_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = ((pub_r001383_6_1 * 2) + 30) & 63;
  int stage_v_29_2 = ((pub_r001383_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001383_6_1 * 2) + 42) & 63;
  int stage_v_30_2 = ((pub_r001383_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001383_11_1 * 2) + 22) & 63;
  int stage_v_31_2 = ((pub_r001383_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((sec_r001383_1_1 * 3) + pub_r001383_14_1) + 5) & 127;
  int stage_v_32_2 = (((sec_r001383_1_2 * 3) + pub_r001383_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((sec_r001383_12_1 * 3) + pub_r001383_16_1) + 39) & 127;
  int stage_v_33_2 = (((sec_r001383_12_2 * 3) + pub_r001383_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001383_7_1 * 2) + 47) & 63;
  int stage_v_34_2 = ((pub_r001383_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001383_7_1 * 2) + 46) & 63;
  int stage_v_35_2 = ((pub_r001383_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001383_8_1 * 2) + 31) & 63;
  int stage_v_36_2 = ((pub_r001383_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001383_14_1 * 2) + 24) & 63;
  int stage_v_37_2 = ((pub_r001383_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((sec_r001383_1_1 * 3) + pub_r001383_8_1) + 35) & 127;
  int stage_v_38_2 = (((sec_r001383_1_2 * 3) + pub_r001383_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((stage_v_27_1 * 3) + pub_r001383_21_1) + 44) & 127;
  int stage_v_39_2 = (((stage_v_27_2 * 3) + pub_r001383_21_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = (((stage_v_0_1 * 3) + pub_r001383_20_1) + 14) & 127;
  int stage_v_40_2 = (((stage_v_0_2 * 3) + pub_r001383_20_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = ((pub_r001383_4_1 * 2) + 10) & 63;
  int stage_v_41_2 = ((pub_r001383_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((stage_v_39_1 * 3) + pub_r001383_0_1) + 31) & 127;
  int stage_v_42_2 = (((stage_v_39_2 * 3) + pub_r001383_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = (((sec_r001383_1_1 * 3) + pub_r001383_1_1) + 23) & 127;
  int stage_v_43_2 = (((sec_r001383_1_2 * 3) + pub_r001383_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001383_13_1 * 2) + 18) & 63;
  int stage_v_44_2 = ((pub_r001383_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((sec_r001383_2_1 * 3) + pub_r001383_21_1) + 37) & 127;
  int stage_v_45_2 = (((sec_r001383_2_2 * 3) + pub_r001383_21_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = ((pub_r001383_21_1 * 2) + 33) & 63;
  int stage_v_46_2 = ((pub_r001383_21_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((sec_r001383_3_1 * 3) + pub_r001383_20_1) + 24) & 127;
  int stage_v_47_2 = (((sec_r001383_3_2 * 3) + pub_r001383_20_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = ((pub_r001383_17_1 * 2) + 35) & 63;
  int stage_v_48_2 = ((pub_r001383_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001383_21_1 * 2) + 28) & 63;
  int stage_v_49_2 = ((pub_r001383_21_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((stage_v_6_1 * 3) + pub_r001383_5_1) + 13) & 127;
  int stage_v_50_2 = (((stage_v_6_2 * 3) + pub_r001383_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001383_5_1 * 2) + 9) & 63;
  int stage_v_51_2 = ((pub_r001383_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_16_1 * 3) + pub_r001383_18_1) + 20) & 127;
  int stage_v_52_2 = (((stage_v_16_2 * 3) + pub_r001383_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001383_2_1 * 2) + 12) & 63;
  int stage_v_53_2 = ((pub_r001383_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001383_15_1 * 2) + 20) & 63;
  int stage_v_54_2 = ((pub_r001383_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((stage_v_47_1 * 3) + pub_r001383_11_1) + 22) & 127;
  int stage_v_55_2 = (((stage_v_47_2 * 3) + pub_r001383_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001383_12_1 * 2) + 37) & 63;
  int stage_v_56_2 = ((pub_r001383_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001383_2_1 * 2) + 27) & 63;
  int stage_v_57_2 = ((pub_r001383_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((stage_v_32_1 * 3) + pub_r001383_0_1) + 42) & 127;
  int stage_v_58_2 = (((stage_v_32_2 * 3) + pub_r001383_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((sec_r001383_7_1 * 3) + pub_r001383_14_1) + 18) & 127;
  int stage_v_59_2 = (((sec_r001383_7_2 * 3) + pub_r001383_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = (((stage_v_13_1 * 3) + pub_r001383_2_1) + 24) & 127;
  int stage_v_60_2 = (((stage_v_13_2 * 3) + pub_r001383_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((sec_r001383_8_1 * 3) + pub_r001383_12_1) + 7) & 127;
  int stage_v_61_2 = (((sec_r001383_8_2 * 3) + pub_r001383_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = (((sec_r001383_3_1 * 3) + pub_r001383_18_1) + 3) & 127;
  int stage_v_62_2 = (((sec_r001383_3_2 * 3) + pub_r001383_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = ((pub_r001383_14_1 * 2) + 26) & 63;
  int stage_v_63_2 = ((pub_r001383_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001383_20_1 * 2) + 18) & 63;
  int stage_v_64_2 = ((pub_r001383_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((stage_v_28_1 * 3) + pub_r001383_16_1) + 7) & 127;
  int stage_v_65_2 = (((stage_v_28_2 * 3) + pub_r001383_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001383_19_1 * 2) + 31) & 63;
  int stage_v_66_2 = ((pub_r001383_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001383_2_1 * 2) + 7) & 63;
  int stage_v_67_2 = ((pub_r001383_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001383_6_1 * 2) + 44) & 63;
  int stage_v_68_2 = ((pub_r001383_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001383_5_1 * 2) + 14) & 63;
  int stage_v_69_2 = ((pub_r001383_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((stage_v_38_1 * 3) + pub_r001383_6_1) + 36) & 127;
  int stage_v_70_2 = (((stage_v_38_2 * 3) + pub_r001383_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001383_3_1 * 2) + 39) & 63;
  int stage_v_71_2 = ((pub_r001383_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001383_8_1 * 2) + 37) & 63;
  int stage_v_72_2 = ((pub_r001383_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001383_14_1 * 2) + 48) & 63;
  int stage_v_73_2 = ((pub_r001383_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001383_6_1 * 2) + 19) & 63;
  int stage_v_74_2 = ((pub_r001383_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((helper_flow_0_1 * 3) + pub_r001383_6_1) + 36) & 127;
  int stage_v_75_2 = (((helper_flow_0_2 * 3) + pub_r001383_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001383_0_1 * 2) + 40) & 63;
  int stage_v_76_2 = ((pub_r001383_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((stage_v_13_1 * 3) + pub_r001383_15_1) + 28) & 127;
  int stage_v_77_2 = (((stage_v_13_2 * 3) + pub_r001383_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001383_10_1 * 2) + 14) & 63;
  int stage_v_78_2 = ((pub_r001383_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_61_1 * 3) + pub_r001383_20_1) + 41) & 127;
  int stage_v_79_2 = (((stage_v_61_2 * 3) + pub_r001383_20_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = (((stage_v_65_1 * 3) + pub_r001383_10_1) + 13) & 127;
  int stage_v_80_2 = (((stage_v_65_2 * 3) + pub_r001383_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = ((pub_r001383_4_1 * 2) + 36) & 63;
  int stage_v_81_2 = ((pub_r001383_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001383_0_1 * 2) + 47) & 63;
  int stage_v_82_2 = ((pub_r001383_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((stage_v_75_1 * 3) + pub_r001383_8_1) + 26) & 127;
  int stage_v_83_2 = (((stage_v_75_2 * 3) + pub_r001383_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((stage_v_42_1 * 3) + pub_r001383_13_1) + 12) & 127;
  int stage_v_84_2 = (((stage_v_42_2 * 3) + pub_r001383_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((stage_v_58_1 * 3) + pub_r001383_0_1) + 13) & 127;
  int stage_v_85_2 = (((stage_v_58_2 * 3) + pub_r001383_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001383_20_1 * 2) + 17) & 63;
  int stage_v_86_2 = ((pub_r001383_20_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_85_1 * 3) + pub_r001383_17_1) + 23) & 127;
  int stage_v_87_2 = (((stage_v_85_2 * 3) + pub_r001383_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = ((pub_r001383_14_1 * 2) + 30) & 63;
  int stage_v_88_2 = ((pub_r001383_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001383_11_1 * 2) + 29) & 63;
  int stage_v_89_2 = ((pub_r001383_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_87_1 * 3) + pub_r001383_1_1) + 45) & 127;
  int stage_v_90_2 = (((stage_v_87_2 * 3) + pub_r001383_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001383_10_1 * 2) + 44) & 63;
  int stage_v_91_2 = ((pub_r001383_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001383_2_1 * 2) + 46) & 63;
  int stage_v_92_2 = ((pub_r001383_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001383_3_1 * 2) + 11) & 63;
  int stage_v_93_2 = ((pub_r001383_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001383_8_1 * 2) + 7) & 63;
  int stage_v_94_2 = ((pub_r001383_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_42_1 * 3) + pub_r001383_1_1) + 16) & 127;
  int stage_v_95_2 = (((stage_v_42_2 * 3) + pub_r001383_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001383_16_1 * 2) + 6) & 63;
  int stage_v_96_2 = ((pub_r001383_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_19_1 * 3) + pub_r001383_7_1) + 9) & 127;
  int stage_v_97_2 = (((stage_v_19_2 * 3) + pub_r001383_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((stage_v_83_1 * 3) + pub_r001383_12_1) + 25) & 127;
  int stage_v_98_2 = (((stage_v_83_2 * 3) + pub_r001383_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((stage_v_42_1 * 3) + pub_r001383_0_1) + 27) & 127;
  int stage_v_99_2 = (((stage_v_42_2 * 3) + pub_r001383_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = (((stage_v_22_1 * 3) + pub_r001383_17_1) + 10) & 127;
  int stage_v_100_2 = (((stage_v_22_2 * 3) + pub_r001383_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = (((stage_v_75_1 * 3) + pub_r001383_8_1) + 44) & 127;
  int stage_v_101_2 = (((stage_v_75_2 * 3) + pub_r001383_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001383_11_1 * 2) + 44) & 63;
  int stage_v_102_2 = ((pub_r001383_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((sec_r001383_13_1 * 3) + pub_r001383_13_1) + 22) & 127;
  int stage_v_103_2 = (((sec_r001383_13_2 * 3) + pub_r001383_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = (((helper_flow_3_1 * 3) + pub_r001383_8_1) + 27) & 127;
  int stage_v_104_2 = (((helper_flow_3_2 * 3) + pub_r001383_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001383_4_1 * 2) + 30) & 63;
  int stage_v_105_2 = ((pub_r001383_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001383_16_1 * 2) + 39) & 63;
  int stage_v_106_2 = ((pub_r001383_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001383_18_1 * 2) + 33) & 63;
  int stage_v_107_2 = ((pub_r001383_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_22_1 * 3) + pub_r001383_10_1) + 27) & 127;
  int stage_v_108_2 = (((stage_v_22_2 * 3) + pub_r001383_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = ((pub_r001383_18_1 * 2) + 26) & 63;
  int stage_v_109_2 = ((pub_r001383_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_38_1 * 3) + pub_r001383_9_1) + 23) & 127;
  int stage_v_110_2 = (((stage_v_38_2 * 3) + pub_r001383_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001383_14_1 * 2) + 13) & 63;
  int stage_v_111_2 = ((pub_r001383_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((helper_flow_0_1 * 3) + pub_r001383_12_1) + 18) & 127;
  int stage_v_112_2 = (((helper_flow_0_2 * 3) + pub_r001383_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = (((stage_v_33_1 * 3) + pub_r001383_21_1) + 15) & 127;
  int stage_v_113_2 = (((stage_v_33_2 * 3) + pub_r001383_21_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001383_10_1 * 2) + 13) & 63;
  int stage_v_114_2 = ((pub_r001383_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001383_13_1 * 2) + 30) & 63;
  int stage_v_115_2 = ((pub_r001383_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001383_16_1 * 2) + 7) & 63;
  int stage_v_116_2 = ((pub_r001383_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_19_1 * 3) + pub_r001383_15_1) + 39) & 127;
  int stage_v_117_2 = (((stage_v_19_2 * 3) + pub_r001383_15_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = ((pub_r001383_18_1 * 2) + 27) & 63;
  int stage_v_118_2 = ((pub_r001383_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_97_1 * 3) + pub_r001383_6_1) + 8) & 127;
  int stage_v_119_2 = (((stage_v_97_2 * 3) + pub_r001383_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((stage_v_60_1 * 3) + pub_r001383_18_1) + 29) & 127;
  int stage_v_120_2 = (((stage_v_60_2 * 3) + pub_r001383_18_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((stage_v_98_1 * 3) + pub_r001383_16_1) + 32) & 127;
  int stage_v_121_2 = (((stage_v_98_2 * 3) + pub_r001383_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((stage_v_112_1 * 3) + pub_r001383_8_1) + 40) & 127;
  int stage_v_122_2 = (((stage_v_112_2 * 3) + pub_r001383_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((stage_v_65_1 * 3) + pub_r001383_5_1) + 11) & 127;
  int stage_v_123_2 = (((stage_v_65_2 * 3) + pub_r001383_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((stage_v_33_1 * 3) + pub_r001383_10_1) + 38) & 127;
  int stage_v_124_2 = (((stage_v_33_2 * 3) + pub_r001383_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((stage_v_108_1 * 3) + pub_r001383_21_1) + 42) & 127;
  int stage_v_125_2 = (((stage_v_108_2 * 3) + pub_r001383_21_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((stage_v_16_1 * 3) + pub_r001383_16_1) + 45) & 127;
  int stage_v_126_2 = (((stage_v_16_2 * 3) + pub_r001383_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((stage_v_45_1 * 3) + pub_r001383_9_1) + 32) & 127;
  int stage_v_127_2 = (((stage_v_45_2 * 3) + pub_r001383_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((sec_r001383_0_1 * 3) + pub_r001383_3_1) + 7) & 127;
  int stage_v_128_2 = (((sec_r001383_0_2 * 3) + pub_r001383_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_95_1 * 3) + pub_r001383_0_1) + 6) & 127;
  int stage_v_129_2 = (((stage_v_95_2 * 3) + pub_r001383_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((stage_v_121_1 * 3) + pub_r001383_21_1) + 17) & 127;
  int stage_v_130_2 = (((stage_v_121_2 * 3) + pub_r001383_21_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = (((stage_v_17_1 * 3) + pub_r001383_7_1) + 24) & 127;
  int stage_v_131_2 = (((stage_v_17_2 * 3) + pub_r001383_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = (((sec_r001383_1_1 * 3) + pub_r001383_20_1) + 14) & 127;
  int stage_v_132_2 = (((sec_r001383_1_2 * 3) + pub_r001383_20_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_50_1 * 3) + pub_r001383_11_1) + 16) & 127;
  int stage_v_133_2 = (((stage_v_50_2 * 3) + pub_r001383_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001383_1_1 * 2) + 12) & 63;
  int stage_v_134_2 = ((pub_r001383_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((stage_v_108_1 * 3) + pub_r001383_12_1) + 9) & 127;
  int stage_v_135_2 = (((stage_v_108_2 * 3) + pub_r001383_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((stage_v_6_1 * 3) + pub_r001383_15_1) + 11) & 127;
  int stage_v_136_2 = (((stage_v_6_2 * 3) + pub_r001383_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((stage_v_97_1 * 3) + pub_r001383_5_1) + 14) & 127;
  int stage_v_137_2 = (((stage_v_97_2 * 3) + pub_r001383_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001383_8_1 * 2) + 49) & 63;
  int stage_v_138_2 = ((pub_r001383_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001383_4_1 * 2) + 40) & 63;
  int stage_v_139_2 = ((pub_r001383_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((stage_v_129_1 * 3) + pub_r001383_16_1) + 16) & 127;
  int stage_v_140_2 = (((stage_v_129_2 * 3) + pub_r001383_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((stage_v_128_1 * 3) + pub_r001383_2_1) + 18) & 127;
  int stage_v_141_2 = (((stage_v_128_2 * 3) + pub_r001383_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_3_1 * 3) + pub_r001383_9_1) + 19) & 127;
  int stage_v_142_2 = (((stage_v_3_2 * 3) + pub_r001383_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((stage_v_28_1 * 3) + pub_r001383_6_1) + 28) & 127;
  int stage_v_143_2 = (((stage_v_28_2 * 3) + pub_r001383_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((stage_v_77_1 * 3) + pub_r001383_17_1) + 8) & 127;
  int stage_v_144_2 = (((stage_v_77_2 * 3) + pub_r001383_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = ((pub_r001383_16_1 * 2) + 38) & 63;
  int stage_v_145_2 = ((pub_r001383_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001383_0_1 * 2) + 21) & 63;
  int stage_v_146_2 = ((pub_r001383_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_135_1 * 3) + pub_r001383_17_1) + 13) & 127;
  int stage_v_147_2 = (((stage_v_135_2 * 3) + pub_r001383_17_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = (((helper_flow_1_1 * 3) + pub_r001383_2_1) + 32) & 127;
  int stage_v_148_2 = (((helper_flow_1_2 * 3) + pub_r001383_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_117_1 * 3) + pub_r001383_20_1) + 8) & 127;
  int stage_v_149_2 = (((stage_v_117_2 * 3) + pub_r001383_20_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_112_1 * 3) + pub_r001383_7_1) + 29) & 127;
  int stage_v_150_2 = (((stage_v_112_2 * 3) + pub_r001383_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = ((pub_r001383_13_1 * 2) + 10) & 63;
  int stage_v_151_2 = ((pub_r001383_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001383_0_1 * 2) + 5) & 63;
  int stage_v_152_2 = ((pub_r001383_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_147_1 * 3) + pub_r001383_5_1) + 11) & 127;
  int stage_v_153_2 = (((stage_v_147_2 * 3) + pub_r001383_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = ((pub_r001383_8_1 * 2) + 20) & 63;
  int stage_v_154_2 = ((pub_r001383_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001383_17_1 * 2) + 16) & 63;
  int stage_v_155_2 = ((pub_r001383_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001383_0_1 * 2) + 44) & 63;
  int stage_v_156_2 = ((pub_r001383_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (((stage_v_136_1 * 3) + pub_r001383_11_1) + 10) & 127;
  int stage_v_157_2 = (((stage_v_136_2 * 3) + pub_r001383_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001383_16_1 * 2) + 11) & 63;
  int stage_v_158_2 = ((pub_r001383_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((helper_flow_5_1 * 3) + pub_r001383_17_1) + 9) & 127;
  int stage_v_159_2 = (((helper_flow_5_2 * 3) + pub_r001383_17_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = ((pub_r001383_15_1 * 2) + 31) & 63;
  int stage_v_160_2 = ((pub_r001383_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_136_1 * 3) + pub_r001383_8_1) + 3) & 127;
  int stage_v_161_2 = (((stage_v_136_2 * 3) + pub_r001383_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((stage_v_153_1 * 3) + pub_r001383_12_1) + 14) & 127;
  int stage_v_162_2 = (((stage_v_153_2 * 3) + pub_r001383_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = (((stage_v_28_1 * 3) + pub_r001383_11_1) + 12) & 127;
  int stage_v_163_2 = (((stage_v_28_2 * 3) + pub_r001383_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((stage_v_19_1 * 3) + pub_r001383_4_1) + 42) & 127;
  int stage_v_164_2 = (((stage_v_19_2 * 3) + pub_r001383_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001383_13_1 * 2) + 35) & 63;
  int stage_v_165_2 = ((pub_r001383_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001383_1_1 * 2) + 15) & 63;
  int stage_v_166_2 = ((pub_r001383_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_40_1 * 3) + pub_r001383_19_1) + 43) & 127;
  int stage_v_167_2 = (((stage_v_40_2 * 3) + pub_r001383_19_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001383_13_1 * 2) + 18) & 63;
  int stage_v_168_2 = ((pub_r001383_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_124_1 * 3) + pub_r001383_20_1) + 33) & 127;
  int stage_v_169_2 = (((stage_v_124_2 * 3) + pub_r001383_20_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((helper_flow_1_1 * 3) + pub_r001383_7_1) + 44) & 127;
  int stage_v_170_2 = (((helper_flow_1_2 * 3) + pub_r001383_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((stage_v_22_1 * 3) + pub_r001383_3_1) + 7) & 127;
  int stage_v_171_2 = (((stage_v_22_2 * 3) + pub_r001383_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((sec_r001383_12_1 * 3) + pub_r001383_9_1) + 24) & 127;
  int stage_v_172_2 = (((sec_r001383_12_2 * 3) + pub_r001383_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((sec_r001383_4_1 * 3) + pub_r001383_20_1) + 29) & 127;
  int stage_v_173_2 = (((sec_r001383_4_2 * 3) + pub_r001383_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = ((pub_r001383_21_1 * 2) + 33) & 63;
  int stage_v_174_2 = ((pub_r001383_21_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001383_6_1 * 2) + 6) & 63;
  int stage_v_175_2 = ((pub_r001383_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_148_1 * 3) + pub_r001383_10_1) + 40) & 127;
  int stage_v_176_2 = (((stage_v_148_2 * 3) + pub_r001383_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((helper_flow_5_1 * 3) + pub_r001383_5_1) + 35) & 127;
  int stage_v_177_2 = (((helper_flow_5_2 * 3) + pub_r001383_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((helper_flow_0_1 * 3) + pub_r001383_6_1) + 25) & 127;
  int stage_v_178_2 = (((helper_flow_0_2 * 3) + pub_r001383_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = ((pub_r001383_11_1 * 2) + 13) & 63;
  int stage_v_179_2 = ((pub_r001383_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_87_1 * 3) + pub_r001383_21_1) + 12) & 127;
  int stage_v_180_2 = (((stage_v_87_2 * 3) + pub_r001383_21_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001383_10_1 * 2) + 8) & 63;
  int stage_v_181_2 = ((pub_r001383_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001383_21_1 * 2) + 48) & 63;
  int stage_v_182_2 = ((pub_r001383_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_80_1 * 3) + pub_r001383_0_1) + 9) & 127;
  int stage_v_183_2 = (((stage_v_80_2 * 3) + pub_r001383_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = ((pub_r001383_7_1 * 2) + 20) & 63;
  int stage_v_184_2 = ((pub_r001383_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001383_11_1 * 2) + 20) & 63;
  int stage_v_185_2 = ((pub_r001383_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_70_1 * 3) + pub_r001383_8_1) + 3) & 127;
  int stage_v_186_2 = (((stage_v_70_2 * 3) + pub_r001383_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001383_8_1 * 2) + 30) & 63;
  int stage_v_187_2 = ((pub_r001383_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((sec_r001383_14_1 * 3) + pub_r001383_9_1) + 29) & 127;
  int stage_v_188_2 = (((sec_r001383_14_2 * 3) + pub_r001383_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001383_9_1 * 2) + 36) & 63;
  int stage_v_189_2 = ((pub_r001383_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((sec_r001383_8_1 * 3) + pub_r001383_17_1) + 38) & 127;
  int stage_v_190_2 = (((sec_r001383_8_2 * 3) + pub_r001383_17_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001383_9_1 * 2) + 22) & 63;
  int stage_v_191_2 = ((pub_r001383_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001383_8_1 * 2) + 36) & 63;
  int stage_v_192_2 = ((pub_r001383_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_87_1 * 3) + pub_r001383_8_1) + 8) & 127;
  int stage_v_193_2 = (((stage_v_87_2 * 3) + pub_r001383_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001383_1_1 * 2) + 48) & 63;
  int stage_v_194_2 = ((pub_r001383_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001383_18_1 * 2) + 28) & 63;
  int stage_v_195_2 = ((pub_r001383_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((sec_r001383_6_1 * 3) + pub_r001383_13_1) + 7) & 127;
  int stage_v_196_2 = (((sec_r001383_6_2 * 3) + pub_r001383_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = (((stage_v_59_1 * 3) + pub_r001383_6_1) + 31) & 127;
  int stage_v_197_2 = (((stage_v_59_2 * 3) + pub_r001383_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((helper_flow_2_1 * 3) + pub_r001383_9_1) + 35) & 127;
  int stage_v_198_2 = (((helper_flow_2_2 * 3) + pub_r001383_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((stage_v_133_1 * 3) + pub_r001383_1_1) + 29) & 127;
  int stage_v_199_2 = (((stage_v_133_2 * 3) + pub_r001383_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001383_13_1 * 2) + 37) & 63;
  int stage_v_200_2 = ((pub_r001383_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_163_1 * 3) + pub_r001383_19_1) + 43) & 127;
  int stage_v_201_2 = (((stage_v_163_2 * 3) + pub_r001383_19_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = ((pub_r001383_20_1 * 2) + 31) & 63;
  int stage_v_202_2 = ((pub_r001383_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((sec_r001383_10_1 * 3) + pub_r001383_1_1) + 45) & 127;
  int stage_v_203_2 = (((sec_r001383_10_2 * 3) + pub_r001383_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((sec_r001383_4_1 * 3) + pub_r001383_18_1) + 15) & 127;
  int stage_v_204_2 = (((sec_r001383_4_2 * 3) + pub_r001383_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001383_21_1 * 2) + 19) & 63;
  int stage_v_205_2 = ((pub_r001383_21_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001383_20_1 * 2) + 28) & 63;
  int stage_v_206_2 = ((pub_r001383_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001383_16_1 * 2) + 41) & 63;
  int stage_v_207_2 = ((pub_r001383_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001383_1_1 * 2) + 8) & 63;
  int stage_v_208_2 = ((pub_r001383_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001383_11_1 * 2) + 13) & 63;
  int stage_v_209_2 = ((pub_r001383_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001383_8_1 * 2) + 39) & 63;
  int stage_v_210_2 = ((pub_r001383_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001383_17_1 * 2) + 48) & 63;
  int stage_v_211_2 = ((pub_r001383_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001383_13_1 * 2) + 33) & 63;
  int stage_v_212_2 = ((pub_r001383_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001383_10_1 * 2) + 47) & 63;
  int stage_v_213_2 = ((pub_r001383_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001383_12_1 * 2) + 45) & 63;
  int stage_v_214_2 = ((pub_r001383_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((sec_r001383_11_1 * 3) + pub_r001383_18_1) + 44) & 127;
  int stage_v_215_2 = (((sec_r001383_11_2 * 3) + pub_r001383_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_90_1 * 3) + pub_r001383_10_1) + 14) & 127;
  int stage_v_216_2 = (((stage_v_90_2 * 3) + pub_r001383_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = (((sec_r001383_15_1 * 3) + pub_r001383_3_1) + 44) & 127;
  int stage_v_217_2 = (((sec_r001383_15_2 * 3) + pub_r001383_3_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = (((sec_r001383_3_1 * 3) + pub_r001383_5_1) + 5) & 127;
  int stage_v_218_2 = (((sec_r001383_3_2 * 3) + pub_r001383_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((stage_v_130_1 * 3) + pub_r001383_3_1) + 13) & 127;
  int stage_v_219_2 = (((stage_v_130_2 * 3) + pub_r001383_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = ((pub_r001383_5_1 * 2) + 50) & 63;
  int stage_v_220_2 = ((pub_r001383_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001383_12_1 * 2) + 21) & 63;
  int stage_v_221_2 = ((pub_r001383_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001383_9_1 * 2) + 11) & 63;
  int stage_v_222_2 = ((pub_r001383_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001383_20_1 * 2) + 40) & 63;
  int stage_v_223_2 = ((pub_r001383_20_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001383_16_1 * 2) + 27) & 63;
  int stage_v_224_2 = ((pub_r001383_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_131_1 * 3) + pub_r001383_20_1) + 24) & 127;
  int stage_v_225_2 = (((stage_v_131_2 * 3) + pub_r001383_20_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((helper_flow_4_1 * 3) + pub_r001383_10_1) + 24) & 127;
  int stage_v_226_2 = (((helper_flow_4_2 * 3) + pub_r001383_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_161_1 * 3) + pub_r001383_16_1) + 9) & 127;
  int stage_v_227_2 = (((stage_v_161_2 * 3) + pub_r001383_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001383_16_1 * 2) + 25) & 63;
  int stage_v_228_2 = ((pub_r001383_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_95_1 * 3) + pub_r001383_14_1) + 42) & 127;
  int stage_v_229_2 = (((stage_v_95_2 * 3) + pub_r001383_14_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001383_2_1 * 2) + 48) & 63;
  int stage_v_230_2 = ((pub_r001383_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001383_1_1 * 2) + 6) & 63;
  int stage_v_231_2 = ((pub_r001383_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001383_21_1 * 2) + 37) & 63;
  int stage_v_232_2 = ((pub_r001383_21_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((stage_v_149_1 * 3) + pub_r001383_13_1) + 13) & 127;
  int stage_v_233_2 = (((stage_v_149_2 * 3) + pub_r001383_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = ((pub_r001383_3_1 * 2) + 20) & 63;
  int stage_v_234_2 = ((pub_r001383_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((stage_v_90_1 * 3) + pub_r001383_9_1) + 44) & 127;
  int stage_v_235_2 = (((stage_v_90_2 * 3) + pub_r001383_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001383_6_1 * 2) + 7) & 63;
  int stage_v_236_2 = ((pub_r001383_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001383_18_1 * 2) + 23) & 63;
  int stage_v_237_2 = ((pub_r001383_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = (((stage_v_171_1 * 3) + pub_r001383_19_1) + 23) & 127;
  int stage_v_238_2 = (((stage_v_171_2 * 3) + pub_r001383_19_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001383_2_1 * 2) + 26) & 63;
  int stage_v_239_2 = ((pub_r001383_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((helper_flow_1_1 * 3) + pub_r001383_8_1) + 5) & 127;
  int stage_v_240_2 = (((helper_flow_1_2 * 3) + pub_r001383_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_147_1 * 3) + pub_r001383_11_1) + 19) & 127;
  int stage_v_241_2 = (((stage_v_147_2 * 3) + pub_r001383_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_240_1 * 3) + pub_r001383_17_1) + 31) & 127;
  int stage_v_242_2 = (((stage_v_240_2 * 3) + pub_r001383_17_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001383_11_1 * 2) + 15) & 63;
  int stage_v_243_2 = ((pub_r001383_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001383_10_1 * 2) + 37) & 63;
  int stage_v_244_2 = ((pub_r001383_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = (((stage_v_235_1 * 3) + pub_r001383_16_1) + 19) & 127;
  int stage_v_245_2 = (((stage_v_235_2 * 3) + pub_r001383_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = (((stage_v_70_1 * 3) + pub_r001383_13_1) + 26) & 127;
  int stage_v_246_2 = (((stage_v_70_2 * 3) + pub_r001383_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001383_14_1 * 2) + 25) & 63;
  int stage_v_247_2 = ((pub_r001383_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_240_1 * 3) + pub_r001383_17_1) + 3) & 127;
  int stage_v_248_2 = (((stage_v_240_2 * 3) + pub_r001383_17_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_130_1 * 3) + pub_r001383_14_1) + 42) & 127;
  int stage_v_249_2 = (((stage_v_130_2 * 3) + pub_r001383_14_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_117_1 * 3) + pub_r001383_6_1) + 44) & 127;
  int stage_v_250_2 = (((stage_v_117_2 * 3) + pub_r001383_6_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_147_1 * 3) + pub_r001383_20_1) + 43) & 127;
  int stage_v_251_2 = (((stage_v_147_2 * 3) + pub_r001383_20_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((stage_v_245_1 * 3) + pub_r001383_10_1) + 31) & 127;
  int stage_v_252_2 = (((stage_v_245_2 * 3) + pub_r001383_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((stage_v_144_1 * 3) + pub_r001383_5_1) + 34) & 127;
  int stage_v_253_2 = (((stage_v_144_2 * 3) + pub_r001383_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_70_1 * 3) + pub_r001383_19_1) + 32) & 127;
  int stage_v_254_2 = (((stage_v_70_2 * 3) + pub_r001383_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001383_6_1 * 2) + 15) & 63;
  int stage_v_255_2 = ((pub_r001383_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001383_17_1 * 2) + 13) & 63;
  int stage_v_256_2 = ((pub_r001383_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((stage_v_219_1 * 3) + pub_r001383_9_1) + 43) & 127;
  int stage_v_257_2 = (((stage_v_219_2 * 3) + pub_r001383_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = ((pub_r001383_19_1 * 2) + 47) & 63;
  int stage_v_258_2 = ((pub_r001383_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001383_1_1 * 2) + 10) & 63;
  int stage_v_259_2 = ((pub_r001383_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001383_4_1 * 2) + 7) & 63;
  int stage_v_260_2 = ((pub_r001383_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_85_1 * 3) + pub_r001383_1_1) + 43) & 127;
  int stage_v_261_2 = (((stage_v_85_2 * 3) + pub_r001383_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = (((stage_v_226_1 * 3) + pub_r001383_5_1) + 36) & 127;
  int stage_v_262_2 = (((stage_v_226_2 * 3) + pub_r001383_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = (((stage_v_167_1 * 3) + pub_r001383_13_1) + 45) & 127;
  int stage_v_263_2 = (((stage_v_167_2 * 3) + pub_r001383_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = (((stage_v_218_1 * 3) + pub_r001383_3_1) + 34) & 127;
  int stage_v_264_2 = (((stage_v_218_2 * 3) + pub_r001383_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = (((stage_v_241_1 * 3) + pub_r001383_21_1) + 42) & 127;
  int stage_v_265_2 = (((stage_v_241_2 * 3) + pub_r001383_21_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_22_1 * 3) + pub_r001383_7_1) + 33) & 127;
  int stage_v_266_2 = (((stage_v_22_2 * 3) + pub_r001383_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((stage_v_198_1 * 3) + pub_r001383_9_1) + 16) & 127;
  int stage_v_267_2 = (((stage_v_198_2 * 3) + pub_r001383_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_45_1 * 3) + pub_r001383_13_1) + 14) & 127;
  int stage_v_268_2 = (((stage_v_45_2 * 3) + pub_r001383_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_140_1 * 3) + pub_r001383_6_1) + 31) & 127;
  int stage_v_269_2 = (((stage_v_140_2 * 3) + pub_r001383_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = ((pub_r001383_3_1 * 2) + 35) & 63;
  int stage_v_270_2 = ((pub_r001383_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001383_21_1 * 2) + 46) & 63;
  int stage_v_271_2 = ((pub_r001383_21_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_0_1 * 3) + pub_r001383_19_1) + 17) & 127;
  int stage_v_272_2 = (((stage_v_0_2 * 3) + pub_r001383_19_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((sec_r001383_11_1 * 3) + pub_r001383_21_1) + 23) & 127;
  int stage_v_273_2 = (((sec_r001383_11_2 * 3) + pub_r001383_21_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001383_14_1 * 2) + 10) & 63;
  int stage_v_274_2 = ((pub_r001383_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = (((stage_v_164_1 * 3) + pub_r001383_15_1) + 9) & 127;
  int stage_v_275_2 = (((stage_v_164_2 * 3) + pub_r001383_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((sec_r001383_12_1 * 3) + pub_r001383_3_1) + 32) & 127;
  int stage_v_276_2 = (((sec_r001383_12_2 * 3) + pub_r001383_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001383_11_1 * 2) + 50) & 63;
  int stage_v_277_2 = ((pub_r001383_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((stage_v_58_1 * 3) + pub_r001383_20_1) + 18) & 127;
  int stage_v_278_2 = (((stage_v_58_2 * 3) + pub_r001383_20_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001383_6_1 * 2) + 38) & 63;
  int stage_v_279_2 = ((pub_r001383_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001383_0_1 * 2) + 35) & 63;
  int stage_v_280_2 = ((pub_r001383_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001383_1_1 * 2) + 27) & 63;
  int stage_v_281_2 = ((pub_r001383_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_148_1 * 3) + pub_r001383_12_1) + 11) & 127;
  int stage_v_282_2 = (((stage_v_148_2 * 3) + pub_r001383_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001383_14_1 * 2) + 12) & 63;
  int stage_v_283_2 = ((pub_r001383_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001383_11_1 * 2) + 11) & 63;
  int stage_v_284_2 = ((pub_r001383_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001383_8_1 * 2) + 41) & 63;
  int stage_v_285_2 = ((pub_r001383_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((stage_v_80_1 * 3) + pub_r001383_16_1) + 13) & 127;
  int stage_v_286_2 = (((stage_v_80_2 * 3) + pub_r001383_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((stage_v_77_1 * 3) + pub_r001383_6_1) + 30) & 127;
  int stage_v_287_2 = (((stage_v_77_2 * 3) + pub_r001383_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_52_1 * 3) + pub_r001383_20_1) + 13) & 127;
  int stage_v_288_2 = (((stage_v_52_2 * 3) + pub_r001383_20_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = ((pub_r001383_0_1 * 2) + 36) & 63;
  int stage_v_289_2 = ((pub_r001383_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001383_16_1 * 2) + 35) & 63;
  int stage_v_290_2 = ((pub_r001383_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001383_1_1 * 2) + 48) & 63;
  int stage_v_291_2 = ((pub_r001383_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((stage_v_121_1 * 3) + pub_r001383_3_1) + 39) & 127;
  int stage_v_292_2 = (((stage_v_121_2 * 3) + pub_r001383_3_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = (((stage_v_250_1 * 3) + pub_r001383_21_1) + 10) & 127;
  int stage_v_293_2 = (((stage_v_250_2 * 3) + pub_r001383_21_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = ((pub_r001383_17_1 * 2) + 31) & 63;
  int stage_v_294_2 = ((pub_r001383_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_196_1 * 3) + pub_r001383_17_1) + 27) & 127;
  int stage_v_295_2 = (((stage_v_196_2 * 3) + pub_r001383_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((sec_r001383_5_1 * 3) + pub_r001383_16_1) + 15) & 127;
  int stage_v_296_2 = (((sec_r001383_5_2 * 3) + pub_r001383_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = (((stage_v_253_1 * 3) + pub_r001383_0_1) + 4) & 127;
  int stage_v_297_2 = (((stage_v_253_2 * 3) + pub_r001383_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = ((pub_r001383_21_1 * 2) + 27) & 63;
  int stage_v_298_2 = ((pub_r001383_21_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = (((helper_flow_7_1 * 3) + pub_r001383_21_1) + 32) & 127;
  int stage_v_299_2 = (((helper_flow_7_2 * 3) + pub_r001383_21_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001383_2_1 * 2) + 18) & 63;
  int stage_v_300_2 = ((pub_r001383_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001383_19_1 * 2) + 43) & 63;
  int stage_v_301_2 = ((pub_r001383_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((sec_r001383_8_1 * 3) + pub_r001383_9_1) + 35) & 127;
  int stage_v_302_2 = (((sec_r001383_8_2 * 3) + pub_r001383_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = ((pub_r001383_19_1 * 2) + 26) & 63;
  int stage_v_303_2 = ((pub_r001383_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = (((stage_v_299_1 * 3) + pub_r001383_10_1) + 44) & 127;
  int stage_v_304_2 = (((stage_v_299_2 * 3) + pub_r001383_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001383_17_1 * 2) + 39) & 63;
  int stage_v_305_2 = ((pub_r001383_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001383_14_1 * 2) + 17) & 63;
  int stage_v_306_2 = ((pub_r001383_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001383_19_1 * 2) + 32) & 63;
  int stage_v_307_2 = ((pub_r001383_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001383_11_1 * 2) + 30) & 63;
  int stage_v_308_2 = ((pub_r001383_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_180_1 * 3) + pub_r001383_17_1) + 28) & 127;
  int stage_v_309_2 = (((stage_v_180_2 * 3) + pub_r001383_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001383_0_1 * 2) + 22) & 63;
  int stage_v_310_2 = ((pub_r001383_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001383_7_1 * 2) + 29) & 63;
  int stage_v_311_2 = ((pub_r001383_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = (((stage_v_169_1 * 3) + pub_r001383_18_1) + 27) & 127;
  int stage_v_312_2 = (((stage_v_169_2 * 3) + pub_r001383_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = (((stage_v_226_1 * 3) + pub_r001383_10_1) + 5) & 127;
  int stage_v_313_2 = (((stage_v_226_2 * 3) + pub_r001383_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001383_7_1 * 2) + 25) & 63;
  int stage_v_314_2 = ((pub_r001383_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001383_18_1 * 2) + 8) & 63;
  int stage_v_315_2 = ((pub_r001383_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_16_1 * 3) + pub_r001383_0_1) + 33) & 127;
  int stage_v_316_2 = (((stage_v_16_2 * 3) + pub_r001383_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_262_1 * 3) + pub_r001383_4_1) + 3) & 127;
  int stage_v_317_2 = (((stage_v_262_2 * 3) + pub_r001383_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001383_4_1 * 2) + 48) & 63;
  int stage_v_318_2 = ((pub_r001383_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001383_4_1 * 2) + 16) & 63;
  int stage_v_319_2 = ((pub_r001383_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_80_1 * 3) + pub_r001383_0_1) + 35) & 127;
  int stage_v_320_2 = (((stage_v_80_2 * 3) + pub_r001383_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_254_1 * 3) + pub_r001383_5_1) + 42) & 127;
  int stage_v_321_2 = (((stage_v_254_2 * 3) + pub_r001383_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = ((pub_r001383_9_1 * 2) + 26) & 63;
  int stage_v_322_2 = ((pub_r001383_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = (((stage_v_75_1 * 3) + pub_r001383_5_1) + 45) & 127;
  int stage_v_323_2 = (((stage_v_75_2 * 3) + pub_r001383_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((stage_v_265_1 * 3) + pub_r001383_3_1) + 7) & 127;
  int stage_v_324_2 = (((stage_v_265_2 * 3) + pub_r001383_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_162_1 * 3) + pub_r001383_0_1) + 29) & 127;
  int stage_v_325_2 = (((stage_v_162_2 * 3) + pub_r001383_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001383_12_1 * 2) + 21) & 63;
  int stage_v_326_2 = ((pub_r001383_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = (((stage_v_33_1 * 3) + pub_r001383_3_1) + 5) & 127;
  int stage_v_327_2 = (((stage_v_33_2 * 3) + pub_r001383_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = (((sec_r001383_12_1 * 3) + pub_r001383_2_1) + 13) & 127;
  int stage_v_328_2 = (((sec_r001383_12_2 * 3) + pub_r001383_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001383_7_1 * 2) + 39) & 63;
  int stage_v_329_2 = ((pub_r001383_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001383_10_1 * 2) + 19) & 63;
  int stage_v_330_2 = ((pub_r001383_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001383_19_1 * 2) + 11) & 63;
  int stage_v_331_2 = ((pub_r001383_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001383_5_1 * 2) + 10) & 63;
  int stage_v_332_2 = ((pub_r001383_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001383_11_1 * 2) + 47) & 63;
  int stage_v_333_2 = ((pub_r001383_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_119_1 * 3) + pub_r001383_21_1) + 35) & 127;
  int stage_v_334_2 = (((stage_v_119_2 * 3) + pub_r001383_21_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001383_0_1 * 2) + 7) & 63;
  int stage_v_335_2 = ((pub_r001383_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001383_11_1 * 2) + 9) & 63;
  int stage_v_336_2 = ((pub_r001383_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = (((helper_flow_0_1 * 3) + pub_r001383_5_1) + 4) & 127;
  int stage_v_337_2 = (((helper_flow_0_2 * 3) + pub_r001383_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_297_1 * 3) + pub_r001383_9_1) + 40) & 127;
  int stage_v_338_2 = (((stage_v_297_2 * 3) + pub_r001383_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001383_7_1 * 2) + 14) & 63;
  int stage_v_339_2 = ((pub_r001383_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001383_10_1 * 2) + 19) & 63;
  int stage_v_340_2 = ((pub_r001383_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001383_11_1 * 2) + 11) & 63;
  int stage_v_341_2 = ((pub_r001383_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001383_0_1 * 2) + 32) & 63;
  int stage_v_342_2 = ((pub_r001383_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001383_4_1 * 2) + 40) & 63;
  int stage_v_343_2 = ((pub_r001383_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = (((stage_v_123_1 * 3) + pub_r001383_6_1) + 39) & 127;
  int stage_v_344_2 = (((stage_v_123_2 * 3) + pub_r001383_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001383_4_1 * 2) + 38) & 63;
  int stage_v_345_2 = ((pub_r001383_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001383_13_1 * 2) + 35) & 63;
  int stage_v_346_2 = ((pub_r001383_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001383_10_1 * 2) + 28) & 63;
  int stage_v_347_2 = ((pub_r001383_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((sec_r001383_2_1 * 3) + pub_r001383_16_1) + 32) & 127;
  int stage_v_348_2 = (((sec_r001383_2_2 * 3) + pub_r001383_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001383_21_1 * 2) + 9) & 63;
  int stage_v_349_2 = ((pub_r001383_21_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((stage_v_52_1 * 3) + pub_r001383_15_1) + 12) & 127;
  int stage_v_350_2 = (((stage_v_52_2 * 3) + pub_r001383_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001383_6_1 * 2) + 44) & 63;
  int stage_v_351_2 = ((pub_r001383_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = (((stage_v_150_1 * 3) + pub_r001383_10_1) + 23) & 127;
  int stage_v_352_2 = (((stage_v_150_2 * 3) + pub_r001383_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_273_1 * 3) + pub_r001383_17_1) + 22) & 127;
  int stage_v_353_2 = (((stage_v_273_2 * 3) + pub_r001383_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((stage_v_83_1 * 3) + pub_r001383_0_1) + 43) & 127;
  int stage_v_354_2 = (((stage_v_83_2 * 3) + pub_r001383_0_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = ((pub_r001383_0_1 * 2) + 33) & 63;
  int stage_v_355_2 = ((pub_r001383_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001383_14_1 * 2) + 40) & 63;
  int stage_v_356_2 = ((pub_r001383_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001383_0_1 * 2) + 18) & 63;
  int stage_v_357_2 = ((pub_r001383_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = (((stage_v_287_1 * 3) + pub_r001383_16_1) + 21) & 127;
  int stage_v_358_2 = (((stage_v_287_2 * 3) + pub_r001383_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = (((stage_v_254_1 * 3) + pub_r001383_10_1) + 28) & 127;
  int stage_v_359_2 = (((stage_v_254_2 * 3) + pub_r001383_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001383_9_1 * 2) + 29) & 63;
  int stage_v_360_2 = ((pub_r001383_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((stage_v_240_1 * 3) + pub_r001383_13_1) + 40) & 127;
  int stage_v_361_2 = (((stage_v_240_2 * 3) + pub_r001383_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((stage_v_218_1 * 3) + pub_r001383_17_1) + 26) & 127;
  int stage_v_362_2 = (((stage_v_218_2 * 3) + pub_r001383_17_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = ((pub_r001383_16_1 * 2) + 17) & 63;
  int stage_v_363_2 = ((pub_r001383_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = (((stage_v_249_1 * 3) + pub_r001383_13_1) + 31) & 127;
  int stage_v_364_2 = (((stage_v_249_2 * 3) + pub_r001383_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((stage_v_136_1 * 3) + pub_r001383_5_1) + 37) & 127;
  int stage_v_365_2 = (((stage_v_136_2 * 3) + pub_r001383_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = (((stage_v_176_1 * 3) + pub_r001383_5_1) + 30) & 127;
  int stage_v_366_2 = (((stage_v_176_2 * 3) + pub_r001383_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_99_1 * 3) + pub_r001383_8_1) + 29) & 127;
  int stage_v_367_2 = (((stage_v_99_2 * 3) + pub_r001383_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_188_1 * 3) + pub_r001383_20_1) + 42) & 127;
  int stage_v_368_2 = (((stage_v_188_2 * 3) + pub_r001383_20_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = (((stage_v_80_1 * 3) + pub_r001383_1_1) + 44) & 127;
  int stage_v_369_2 = (((stage_v_80_2 * 3) + pub_r001383_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = ((pub_r001383_12_1 * 2) + 19) & 63;
  int stage_v_370_2 = ((pub_r001383_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001383_2_1 * 2) + 5) & 63;
  int stage_v_371_2 = ((pub_r001383_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = (((stage_v_163_1 * 3) + pub_r001383_11_1) + 40) & 127;
  int stage_v_372_2 = (((stage_v_163_2 * 3) + pub_r001383_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = (((stage_v_275_1 * 3) + pub_r001383_12_1) + 23) & 127;
  int stage_v_373_2 = (((stage_v_275_2 * 3) + pub_r001383_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = ((pub_r001383_13_1 * 2) + 44) & 63;
  int stage_v_374_2 = ((pub_r001383_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = (((stage_v_368_1 * 3) + pub_r001383_7_1) + 28) & 127;
  int stage_v_375_2 = (((stage_v_368_2 * 3) + pub_r001383_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_13_1 * 3) + pub_r001383_19_1) + 39) & 127;
  int stage_v_376_2 = (((stage_v_13_2 * 3) + pub_r001383_19_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((stage_v_375_1 * 3) + pub_r001383_20_1) + 42) & 127;
  int stage_v_377_2 = (((stage_v_375_2 * 3) + pub_r001383_20_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_288_1 * 3) + pub_r001383_17_1) + 29) & 127;
  int stage_v_378_2 = (((stage_v_288_2 * 3) + pub_r001383_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = ((pub_r001383_7_1 * 2) + 19) & 63;
  int stage_v_379_2 = ((pub_r001383_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((pub_r001383_10_1 * 2) + 9) & 63;
  int stage_v_380_2 = ((pub_r001383_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = (((stage_v_262_1 * 3) + pub_r001383_20_1) + 39) & 127;
  int stage_v_381_2 = (((stage_v_262_2 * 3) + pub_r001383_20_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = (((stage_v_136_1 * 3) + pub_r001383_16_1) + 41) & 127;
  int stage_v_382_2 = (((stage_v_136_2 * 3) + pub_r001383_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001383_4_1 * 2) + 14) & 63;
  int stage_v_383_2 = ((pub_r001383_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001383_14_1 * 2) + 43) & 63;
  int stage_v_384_2 = ((pub_r001383_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001383_4_1 * 2) + 9) & 63;
  int stage_v_385_2 = ((pub_r001383_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001383_19_1 * 2) + 26) & 63;
  int stage_v_386_2 = ((pub_r001383_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001383_2_1 * 2) + 5) & 63;
  int stage_v_387_2 = ((pub_r001383_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = (((stage_v_241_1 * 3) + pub_r001383_19_1) + 13) & 127;
  int stage_v_388_2 = (((stage_v_241_2 * 3) + pub_r001383_19_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = ((pub_r001383_14_1 * 2) + 24) & 63;
  int stage_v_389_2 = ((pub_r001383_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((stage_v_262_1 * 3) + pub_r001383_19_1) + 42) & 127;
  int stage_v_390_2 = (((stage_v_262_2 * 3) + pub_r001383_19_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = ((pub_r001383_6_1 * 2) + 40) & 63;
  int stage_v_391_2 = ((pub_r001383_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001383_3_1 * 2) + 46) & 63;
  int stage_v_392_2 = ((pub_r001383_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = (((stage_v_240_1 * 3) + pub_r001383_9_1) + 31) & 127;
  int stage_v_393_2 = (((stage_v_240_2 * 3) + pub_r001383_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001383_19_1 * 2) + 44) & 63;
  int stage_v_394_2 = ((pub_r001383_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001383_4_1 * 2) + 24) & 63;
  int stage_v_395_2 = ((pub_r001383_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_317_1 * 3) + pub_r001383_20_1) + 38) & 127;
  int stage_v_396_2 = (((stage_v_317_2 * 3) + pub_r001383_20_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((stage_v_61_1 * 3) + pub_r001383_20_1) + 38) & 127;
  int stage_v_397_2 = (((stage_v_61_2 * 3) + pub_r001383_20_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = (((stage_v_268_1 * 3) + pub_r001383_0_1) + 14) & 127;
  int stage_v_398_2 = (((stage_v_268_2 * 3) + pub_r001383_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = (((sec_r001383_4_1 * 3) + pub_r001383_2_1) + 28) & 127;
  int stage_v_399_2 = (((sec_r001383_4_2 * 3) + pub_r001383_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = (((helper_flow_4_1 * 3) + pub_r001383_16_1) + 25) & 127;
  int stage_v_400_2 = (((helper_flow_4_2 * 3) + pub_r001383_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = ((pub_r001383_20_1 * 2) + 19) & 63;
  int stage_v_401_2 = ((pub_r001383_20_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001383_6_1 * 2) + 11) & 63;
  int stage_v_402_2 = ((pub_r001383_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001383_8_1 * 2) + 48) & 63;
  int stage_v_403_2 = ((pub_r001383_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = (((stage_v_183_1 * 3) + pub_r001383_17_1) + 28) & 127;
  int stage_v_404_2 = (((stage_v_183_2 * 3) + pub_r001383_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_85_1 * 3) + pub_r001383_11_1) + 20) & 127;
  int stage_v_405_2 = (((stage_v_85_2 * 3) + pub_r001383_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((stage_v_393_1 * 3) + pub_r001383_20_1) + 29) & 127;
  int stage_v_406_2 = (((stage_v_393_2 * 3) + pub_r001383_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001383_0_1 * 2) + 5) & 63;
  int stage_v_407_2 = ((pub_r001383_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_365_1 * 3) + pub_r001383_21_1) + 29) & 127;
  int stage_v_408_2 = (((stage_v_365_2 * 3) + pub_r001383_21_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001383_11_1 * 2) + 19) & 63;
  int stage_v_409_2 = ((pub_r001383_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = (((sec_r001383_0_1 * 3) + pub_r001383_0_1) + 40) & 127;
  int stage_v_410_2 = (((sec_r001383_0_2 * 3) + pub_r001383_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_410_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_410_2 * 2)) & 255;
  int stage_v_411_1 = ((pub_r001383_16_1 * 2) + 28) & 63;
  int stage_v_411_2 = ((pub_r001383_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((helper_flow_4_1 * 3) + pub_r001383_0_1) + 37) & 127;
  int stage_v_412_2 = (((helper_flow_4_2 * 3) + pub_r001383_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = (((stage_v_324_1 * 3) + pub_r001383_16_1) + 25) & 127;
  int stage_v_413_2 = (((stage_v_324_2 * 3) + pub_r001383_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = (((stage_v_3_1 * 3) + pub_r001383_14_1) + 28) & 127;
  int stage_v_414_2 = (((stage_v_3_2 * 3) + pub_r001383_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = ((pub_r001383_2_1 * 2) + 29) & 63;
  int stage_v_415_2 = ((pub_r001383_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = (((stage_v_55_1 * 3) + pub_r001383_5_1) + 10) & 127;
  int stage_v_416_2 = (((stage_v_55_2 * 3) + pub_r001383_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = (((sec_r001383_6_1 * 3) + pub_r001383_7_1) + 15) & 127;
  int stage_v_417_2 = (((sec_r001383_6_2 * 3) + pub_r001383_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001383_15_1 * 2) + 12) & 63;
  int stage_v_418_2 = ((pub_r001383_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((sec_r001383_2_1 * 3) + pub_r001383_2_1) + 36) & 127;
  int stage_v_419_2 = (((sec_r001383_2_2 * 3) + pub_r001383_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = (((stage_v_372_1 * 3) + pub_r001383_15_1) + 25) & 127;
  int stage_v_420_2 = (((stage_v_372_2 * 3) + pub_r001383_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = ((pub_r001383_18_1 * 2) + 28) & 63;
  int stage_v_421_2 = ((pub_r001383_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = (((stage_v_164_1 * 3) + pub_r001383_4_1) + 8) & 127;
  int stage_v_422_2 = (((stage_v_164_2 * 3) + pub_r001383_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = (((stage_v_201_1 * 3) + pub_r001383_11_1) + 26) & 127;
  int stage_v_423_2 = (((stage_v_201_2 * 3) + pub_r001383_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_423_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_423_2 * 2)) & 255;
  int stage_v_424_1 = ((pub_r001383_3_1 * 2) + 29) & 63;
  int stage_v_424_2 = ((pub_r001383_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = (((stage_v_225_1 * 3) + pub_r001383_12_1) + 9) & 127;
  int stage_v_425_2 = (((stage_v_225_2 * 3) + pub_r001383_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001383_20_1 * 2) + 14) & 63;
  int stage_v_426_2 = ((pub_r001383_20_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = (((helper_flow_4_1 * 3) + pub_r001383_17_1) + 25) & 127;
  int stage_v_427_2 = (((helper_flow_4_2 * 3) + pub_r001383_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = (((stage_v_302_1 * 3) + pub_r001383_9_1) + 20) & 127;
  int stage_v_428_2 = (((stage_v_302_2 * 3) + pub_r001383_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001383_13_1 != sec_r001383_13_2);
  __CPROVER_assume(pub_r001383_0_1 == pub_r001383_0_2);
  __CPROVER_assume(sec_r001383_2_1 != sec_r001383_2_2);
  __CPROVER_assume(pub_r001383_8_1 == pub_r001383_8_2);
  __CPROVER_assume(pub_r001383_2_1 == pub_r001383_2_2);
  __CPROVER_assume(pub_r001383_10_1 == pub_r001383_10_2);
  __CPROVER_assume(pub_r001383_11_1 == pub_r001383_11_2);
  __CPROVER_assume(pub_r001383_17_1 == pub_r001383_17_2);
  __CPROVER_assume(sec_r001383_14_1 != sec_r001383_14_2);
  __CPROVER_assume(pub_r001383_7_1 == pub_r001383_7_2);
  __CPROVER_assume(pub_r001383_1_1 == pub_r001383_1_2);
  __CPROVER_assume(sec_r001383_7_1 != sec_r001383_7_2);
  __CPROVER_assume(pub_r001383_12_1 == pub_r001383_12_2);
  __CPROVER_assume(pub_r001383_15_1 == pub_r001383_15_2);
  __CPROVER_assume(sec_r001383_0_1 != sec_r001383_0_2);
  __CPROVER_assume(sec_r001383_6_1 != sec_r001383_6_2);
  __CPROVER_assume(sec_r001383_12_1 != sec_r001383_12_2);
  __CPROVER_assume(sec_r001383_4_1 != sec_r001383_4_2);
  __CPROVER_assume(sec_r001383_10_1 != sec_r001383_10_2);
  __CPROVER_assume(pub_r001383_18_1 == pub_r001383_18_2);
  __CPROVER_assume(pub_r001383_19_1 == pub_r001383_19_2);
  __CPROVER_assume(pub_r001383_6_1 == pub_r001383_6_2);
  __CPROVER_assume(pub_r001383_16_1 == pub_r001383_16_2);
  __CPROVER_assume(pub_r001383_9_1 == pub_r001383_9_2);
  __CPROVER_assume(sec_r001383_11_1 != sec_r001383_11_2);
  __CPROVER_assume(sec_r001383_15_1 != sec_r001383_15_2);
  __CPROVER_assume(sec_r001383_9_1 != sec_r001383_9_2);
  __CPROVER_assume(sec_r001383_8_1 != sec_r001383_8_2);
  __CPROVER_assume(pub_r001383_5_1 == pub_r001383_5_2);
  __CPROVER_assume(pub_r001383_3_1 == pub_r001383_3_2);
  __CPROVER_assume(pub_r001383_20_1 == pub_r001383_20_2);
  __CPROVER_assume(pub_r001383_13_1 == pub_r001383_13_2);
  __CPROVER_assume(pub_r001383_4_1 == pub_r001383_4_2);
  __CPROVER_assume(pub_r001383_14_1 == pub_r001383_14_2);
  __CPROVER_assume(sec_r001383_1_1 != sec_r001383_1_2);
  __CPROVER_assume(sec_r001383_5_1 != sec_r001383_5_2);
  __CPROVER_assume(pub_r001383_21_1 == pub_r001383_21_2);
  __CPROVER_assume(sec_r001383_3_1 != sec_r001383_3_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.id == st_var_2_2.id);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
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
  assert(helper_flow_7_1 == helper_flow_7_2);
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
  assert(stage_v_404_1 == stage_v_404_2);
  assert(stage_v_405_1 == stage_v_405_2);
  assert(stage_v_406_1 == stage_v_406_2);
  assert(stage_v_407_1 == stage_v_407_2);
  assert(stage_v_408_1 == stage_v_408_2);
  assert(stage_v_409_1 == stage_v_409_2);
  assert(stage_v_410_1 == stage_v_410_2);
  assert(stage_v_411_1 == stage_v_411_2);
  assert(stage_v_412_1 == stage_v_412_2);
  assert(stage_v_413_1 == stage_v_413_2);
  assert(stage_v_414_1 == stage_v_414_2);
  assert(stage_v_415_1 == stage_v_415_2);
  assert(stage_v_416_1 == stage_v_416_2);
  assert(stage_v_417_1 == stage_v_417_2);
  assert(stage_v_418_1 == stage_v_418_2);
  assert(stage_v_419_1 == stage_v_419_2);
  assert(stage_v_420_1 == stage_v_420_2);
  assert(stage_v_421_1 == stage_v_421_2);
  assert(stage_v_422_1 == stage_v_422_2);
  assert(stage_v_423_1 == stage_v_423_2);
  assert(stage_v_424_1 == stage_v_424_2);
  assert(stage_v_425_1 == stage_v_425_2);
  assert(stage_v_426_1 == stage_v_426_2);
  assert(stage_v_427_1 == stage_v_427_2);
  assert(stage_v_428_1 == stage_v_428_2);
}


