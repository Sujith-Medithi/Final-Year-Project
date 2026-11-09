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
struct MatrixBlock_R001446_4613_0
{
  unsigned char density;
  short trace;
  int stride;
  int dim;
  int buffer[3];
};
struct DeviceConfig_R001446_4613_1
{
  unsigned char port;
  int parity;
  int baud_rate;
  short stop_bits;
  int id;
  unsigned char timeout;
  int buffer[3];
};
struct SensorNode_R001446_4613_2
{
  short status;
  unsigned char offset;
  int reading;
  int threshold;
  int buffer[3];
};
union PacketPayload_R001446_4613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001446_4613_1
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
void fn_R001446_4613_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_26_1)
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

  switch (scale_26_2)
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

  int anchor_80_1 = 0;
  int anchor_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_80_1 = ((anchor_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_80_2 = ((anchor_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_80_1) & 127;
    acc_2 = (acc_2 + anchor_80_2) & 127;
  }

  int phase_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_81_1) & 63;
  aux_2 = (aux_2 + phase_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_26_1 == scale_26_2);
  assert(anchor_80_1 == anchor_80_2);
  assert(phase_81_1 == phase_81_2);
}

int fn_R001446_4613_0(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_26 = (aux + st.buffer[1]) & 3;
  switch (scale_26)
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

  int anchor_80 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_80 = ((anchor_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_80) & 127;
  }

  int phase_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001446_4613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_20_1 = local_arr_1[aux_1 % 3];
  int tally_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_20_2 * 2)) & 127;
  int vector_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_38_1 > 21)
  {
    acc_1 = ((acc_1 + (vector_38_1 * 2)) + 5) & 127;
    aux_1 ^= vector_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_38_2 > 21)
  {
    acc_2 = ((acc_2 + (vector_38_2 * 2)) + 5) & 127;
    aux_2 ^= vector_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
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

  assert(tally_20_1 == tally_20_2);
  assert(vector_38_1 == vector_38_2);
}

int fn_R001446_4613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int tally_20 = local_arr[aux % 3];
  acc = (acc + (tally_20 * 2)) & 127;
  int vector_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_38 > 21)
  {
    acc = ((acc + (vector_38 * 2)) + 5) & 127;
    aux ^= vector_38 & 15;
  }
  else
  {
    acc = ((acc - vector_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001446_4613_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int coefficient_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_15_1)
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

  switch (coefficient_15_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_82_1 = local_arr_1[aux_1 % 3];
  int margin_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_15_1 == coefficient_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_82_1 == margin_82_2);
}

int fn_R001446_4613_2(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int coefficient_15 = (aux + st.buffer[1]) & 3;
  switch (coefficient_15)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_82 = local_arr[aux % 3];
  acc = (acc + (margin_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001446_4613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int metric_32_1 = 0;
  int metric_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_32_1 = ((metric_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_32_2 = ((metric_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_32_1) & 127;
    acc_2 = (acc_2 + metric_32_2) & 127;
  }

  int coefficient_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_77_1 > 14)
  {
    acc_1 = ((acc_1 + (coefficient_77_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_77_2 > 14)
  {
    acc_2 = ((acc_2 + (coefficient_77_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_77_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_82_1) & 63;
  aux_2 = (aux_2 + accumulator_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_32_1 == metric_32_2);
  assert(coefficient_77_1 == coefficient_77_2);
  assert(accumulator_82_1 == accumulator_82_2);
}

int fn_R001446_4613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int metric_32 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_32 = ((metric_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_32) & 127;
  }

  int coefficient_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_77 > 14)
  {
    acc = ((acc + (coefficient_77 * 2)) + 5) & 127;
    aux ^= coefficient_77 & 15;
  }
  else
  {
    acc = ((acc - coefficient_77) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001446_4613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001446_4613_2 st_1 = {0};
  struct SensorNode_R001446_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_50_1 = local_arr_1[aux_1 % 3];
  int pivot_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_50_2 * 2)) & 127;
  int offset_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_53_1) & 63;
  aux_2 = (aux_2 + offset_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_19_1 > 42)
  {
    acc_1 = ((acc_1 + (sample_19_1 * 2)) + 5) & 127;
    aux_1 ^= sample_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_19_2 > 42)
  {
    acc_2 = ((acc_2 + (sample_19_2 * 2)) + 5) & 127;
    aux_2 ^= sample_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_19_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_50_1 == pivot_50_2);
  assert(offset_53_1 == offset_53_2);
  assert(sample_19_1 == sample_19_2);
}

int fn_R001446_4613_4(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001446_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int pivot_50 = local_arr[aux % 3];
  acc = (acc + (pivot_50 * 2)) & 127;
  int offset_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_53) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_19 > 42)
  {
    acc = ((acc + (sample_19 * 2)) + 5) & 127;
    aux ^= sample_19 & 15;
  }
  else
  {
    acc = ((acc - sample_19) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001446_4613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001446_4613_0 st_1 = {0};
  struct MatrixBlock_R001446_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int anchor_91_1 = 0;
  int anchor_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_91_1 = ((anchor_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_91_2 = ((anchor_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_91_1) & 127;
    acc_2 = (acc_2 + anchor_91_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_91_1 == anchor_91_2);
}

int fn_R001446_4613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001446_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int anchor_91 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_91 = ((anchor_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_91) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001446_4613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001446_4613_2 st_1 = {0};
  struct SensorNode_R001446_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int residue_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_47_1 > 28)
  {
    acc_1 = ((acc_1 + (residue_47_1 * 2)) + 5) & 127;
    aux_1 ^= residue_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_47_2 > 28)
  {
    acc_2 = ((acc_2 + (residue_47_2 * 2)) + 5) & 127;
    aux_2 ^= residue_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_89_1 = local_arr_1[aux_1 % 3];
  int metric_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_89_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_26_1 = 0;
  int weight_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_26_1 = ((weight_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_26_2 = ((weight_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_26_1) & 127;
    acc_2 = (acc_2 + weight_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_47_1 == residue_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_89_1 == metric_89_2);
  assert(weight_26_1 == weight_26_2);
}

int fn_R001446_4613_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001446_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int residue_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_47 > 28)
  {
    acc = ((acc + (residue_47 * 2)) + 5) & 127;
    aux ^= residue_47 & 15;
  }
  else
  {
    acc = ((acc - residue_47) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_89 = local_arr[aux % 3];
  acc = (acc + (metric_89 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_26 = ((weight_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_26) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001446_4613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int margin_74_1 = 0;
  int margin_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_74_1 = ((margin_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_74_2 = ((margin_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_74_1) & 127;
    acc_2 = (acc_2 + margin_74_2) & 127;
  }

  int damping_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_11_1)
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

  switch (damping_11_2)
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

  int offset_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_58_1) & 63;
  aux_2 = (aux_2 + offset_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_44_1 = local_arr_1[aux_1 % 3];
  int checksum_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_74_1 == margin_74_2);
  assert(damping_11_1 == damping_11_2);
  assert(offset_58_1 == offset_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_44_1 == checksum_44_2);
}

int fn_R001446_4613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int margin_74 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_74 = ((margin_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_74) & 127;
  }

  int damping_11 = (aux + st.buffer[1]) & 3;
  switch (damping_11)
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

  int offset_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_58) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_44 = local_arr[aux % 3];
  acc = (acc + (checksum_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001446_4613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001446_4613_0 st_1 = {0};
  struct MatrixBlock_R001446_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int scale_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_39_1) & 63;
  aux_2 = (aux_2 + scale_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_63_1 > 49)
  {
    acc_1 = ((acc_1 + (accumulator_63_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_63_2 > 49)
  {
    acc_2 = ((acc_2 + (accumulator_63_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_11_1)
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

  switch (parity_11_2)
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
  int metric_22_1 = local_arr_1[aux_1 % 3];
  int metric_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_22_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_39_1 == scale_39_2);
  assert(accumulator_63_1 == accumulator_63_2);
  assert(parity_11_1 == parity_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_22_1 == metric_22_2);
}

int fn_R001446_4613_8(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001446_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int scale_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_39) & 63;
  acc ^= aux;
  int accumulator_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_63 > 49)
  {
    acc = ((acc + (accumulator_63 * 2)) + 5) & 127;
    aux ^= accumulator_63 & 15;
  }
  else
  {
    acc = ((acc - accumulator_63) + 11) & 127;
    aux += 3;
  }
  int parity_11 = (aux + st.buffer[1]) & 3;
  switch (parity_11)
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
  int metric_22 = local_arr[aux % 3];
  acc = (acc + (metric_22 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001446_4613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_46_1 = local_arr_1[aux_1 % 3];
  int scale_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_46_2 * 2)) & 127;
  int stride_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_10_1) & 63;
  aux_2 = (aux_2 + stride_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_41_1 = 0;
  int quantum_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_41_1 = ((quantum_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_41_2 = ((quantum_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_41_1) & 127;
    acc_2 = (acc_2 + quantum_41_2) & 127;
  }

  int phase_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_59_1 > 20)
  {
    acc_1 = ((acc_1 + (phase_59_1 * 2)) + 5) & 127;
    aux_1 ^= phase_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_59_2 > 20)
  {
    acc_2 = ((acc_2 + (phase_59_2 * 2)) + 5) & 127;
    aux_2 ^= phase_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
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

  assert(scale_46_1 == scale_46_2);
  assert(stride_10_1 == stride_10_2);
  assert(quantum_41_1 == quantum_41_2);
  assert(phase_59_1 == phase_59_2);
}

int fn_R001446_4613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int scale_46 = local_arr[aux % 3];
  acc = (acc + (scale_46 * 2)) & 127;
  int stride_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_10) & 63;
  acc ^= aux;
  int quantum_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_41 = ((quantum_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_41) & 127;
  }

  int phase_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_59 > 20)
  {
    acc = ((acc + (phase_59 * 2)) + 5) & 127;
    aux ^= phase_59 & 15;
  }
  else
  {
    acc = ((acc - phase_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001446_4613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001446_4613_0 st_1 = {0};
  struct MatrixBlock_R001446_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int metric_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_12_1 > 31)
  {
    acc_1 = ((acc_1 + (metric_12_1 * 2)) + 5) & 127;
    aux_1 ^= metric_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_12_2 > 31)
  {
    acc_2 = ((acc_2 + (metric_12_2 * 2)) + 5) & 127;
    aux_2 ^= metric_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_74_1) & 63;
  aux_2 = (aux_2 + delta_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_12_1 == metric_12_2);
  assert(delta_74_1 == delta_74_2);
}

int fn_R001446_4613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001446_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int metric_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_12 > 31)
  {
    acc = ((acc + (metric_12 * 2)) + 5) & 127;
    aux ^= metric_12 & 15;
  }
  else
  {
    acc = ((acc - metric_12) + 11) & 127;
    aux += 3;
  }
  int delta_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001446_4613_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int segment_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_62_1)
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

  switch (segment_62_2)
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

  int quotient_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_78_1) & 63;
  aux_2 = (aux_2 + quotient_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_62_1 > 48)
  {
    acc_1 = ((acc_1 + (margin_62_1 * 2)) + 5) & 127;
    aux_1 ^= margin_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_62_2 > 48)
  {
    acc_2 = ((acc_2 + (margin_62_2 * 2)) + 5) & 127;
    aux_2 ^= margin_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_62_1 == segment_62_2);
  assert(quotient_78_1 == quotient_78_2);
  assert(margin_62_1 == margin_62_2);
}

int fn_R001446_4613_11(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int segment_62 = (aux + st.buffer[1]) & 3;
  switch (segment_62)
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

  int quotient_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_78) & 63;
  acc ^= aux;
  int margin_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_62 > 48)
  {
    acc = ((acc + (margin_62 * 2)) + 5) & 127;
    aux ^= margin_62 & 15;
  }
  else
  {
    acc = ((acc - margin_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001446_4613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001446_4613_0 st_1 = {0};
  struct MatrixBlock_R001446_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_36_1 = local_arr_1[aux_1 % 3];
  int accumulator_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_36_2 * 2)) & 127;
  int tracker_82_1 = 0;
  int tracker_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_82_1 = ((tracker_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_82_2 = ((tracker_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_82_1) & 127;
    acc_2 = (acc_2 + tracker_82_2) & 127;
  }

  int parity_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_64_1) & 63;
  aux_2 = (aux_2 + parity_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_36_1 == accumulator_36_2);
  assert(tracker_82_1 == tracker_82_2);
  assert(parity_64_1 == parity_64_2);
}

int fn_R001446_4613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001446_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int accumulator_36 = local_arr[aux % 3];
  acc = (acc + (accumulator_36 * 2)) & 127;
  int tracker_82 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_82 = ((tracker_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_82) & 127;
  }

  int parity_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001446_4613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001446_4613_2 st_1 = {0};
  struct SensorNode_R001446_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_60_1 = local_arr_1[aux_1 % 3];
  int mask_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_60_2 * 2)) & 127;
  int phase_96_1 = 0;
  int phase_96_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_96_1 = ((phase_96_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_96_2 = ((phase_96_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_96_1) & 127;
    acc_2 = (acc_2 + phase_96_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_60_1 == mask_60_2);
  assert(phase_96_1 == phase_96_2);
}

int fn_R001446_4613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001446_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int mask_60 = local_arr[aux % 3];
  acc = (acc + (mask_60 * 2)) & 127;
  int phase_96 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_96 = ((phase_96 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_96) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001446_4613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int anchor_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_94_1 > 24)
  {
    acc_1 = ((acc_1 + (anchor_94_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_94_2 > 24)
  {
    acc_2 = ((acc_2 + (anchor_94_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_51_1) & 63;
  aux_2 = (aux_2 + pivot_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_94_1 == anchor_94_2);
  assert(pivot_51_1 == pivot_51_2);
}

int fn_R001446_4613_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int anchor_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_94 > 24)
  {
    acc = ((acc + (anchor_94 * 2)) + 5) & 127;
    aux ^= anchor_94 & 15;
  }
  else
  {
    acc = ((acc - anchor_94) + 11) & 127;
    aux += 3;
  }
  int pivot_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_51) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001446_4613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int factor_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_19_1)
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

  switch (factor_19_2)
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

  int margin_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_47_1 > 38)
  {
    acc_1 = ((acc_1 + (margin_47_1 * 2)) + 5) & 127;
    aux_1 ^= margin_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_47_2 > 38)
  {
    acc_2 = ((acc_2 + (margin_47_2 * 2)) + 5) & 127;
    aux_2 ^= margin_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_81_1) & 63;
  aux_2 = (aux_2 + delta_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_19_1 == factor_19_2);
  assert(margin_47_1 == margin_47_2);
  assert(delta_81_1 == delta_81_2);
}

int fn_R001446_4613_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int factor_19 = (aux + st.buffer[1]) & 3;
  switch (factor_19)
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

  int margin_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_47 > 38)
  {
    acc = ((acc + (margin_47 * 2)) + 5) & 127;
    aux ^= margin_47 & 15;
  }
  else
  {
    acc = ((acc - margin_47) + 11) & 127;
    aux += 3;
  }
  int delta_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001446_4613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int cursor_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_32_1) & 63;
  aux_2 = (aux_2 + cursor_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_88_1 = 0;
  int mask_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_88_1 = ((mask_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_88_2 = ((mask_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_88_1) & 127;
    acc_2 = (acc_2 + mask_88_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_20_1)
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

  switch (factor_20_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_32_1 == cursor_32_2);
  assert(mask_88_1 == mask_88_2);
  assert(factor_20_1 == factor_20_2);
}

int fn_R001446_4613_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int cursor_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_32) & 63;
  acc ^= aux;
  int mask_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_88 = ((mask_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_88) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_20 = (aux + st.buffer[1]) & 3;
  switch (factor_20)
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

void fn_R001446_4613_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001446_4613_0 st_1 = {0};
  struct MatrixBlock_R001446_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_84_1 = local_arr_1[aux_1 % 3];
  int phase_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_84_2 * 2)) & 127;
  int parity_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_60_1 > 13)
  {
    acc_1 = ((acc_1 + (parity_60_1 * 2)) + 5) & 127;
    aux_1 ^= parity_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_60_2 > 13)
  {
    acc_2 = ((acc_2 + (parity_60_2 * 2)) + 5) & 127;
    aux_2 ^= parity_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_92_1)
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

  switch (mask_92_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_84_1 == phase_84_2);
  assert(parity_60_1 == parity_60_2);
  assert(mask_92_1 == mask_92_2);
}

int fn_R001446_4613_17(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001446_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_84 = local_arr[aux % 3];
  acc = (acc + (phase_84 * 2)) & 127;
  int parity_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_60 > 13)
  {
    acc = ((acc + (parity_60 * 2)) + 5) & 127;
    aux ^= parity_60 & 15;
  }
  else
  {
    acc = ((acc - parity_60) + 11) & 127;
    aux += 3;
  }
  int mask_92 = (aux + st.buffer[1]) & 3;
  switch (mask_92)
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

void fn_R001446_4613_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001446_4613_2 st_1 = {0};
  struct SensorNode_R001446_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int factor_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_14_1) & 63;
  aux_2 = (aux_2 + factor_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_35_1 > 28)
  {
    acc_1 = ((acc_1 + (index_reg_35_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_35_2 > 28)
  {
    acc_2 = ((acc_2 + (index_reg_35_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_14_1 == factor_14_2);
  assert(index_reg_35_1 == index_reg_35_2);
}

int fn_R001446_4613_18(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001446_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int factor_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_14) & 63;
  acc ^= aux;
  int index_reg_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_35 > 28)
  {
    acc = ((acc + (index_reg_35 * 2)) + 5) & 127;
    aux ^= index_reg_35 & 15;
  }
  else
  {
    acc = ((acc - index_reg_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001446_4613_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_80_1) & 63;
  aux_2 = (aux_2 + quotient_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_38_1 = 0;
  int anchor_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_38_1 = ((anchor_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_38_2 = ((anchor_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_38_1) & 127;
    acc_2 = (acc_2 + anchor_38_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_80_1 == quotient_80_2);
  assert(anchor_38_1 == anchor_38_2);
}

int fn_R001446_4613_19(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001446_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_80) & 63;
  acc ^= aux;
  int anchor_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_38 = ((anchor_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_38) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001446_0_1;
  int sec_r001446_0_2;
  int sec_r001446_1_1;
  int sec_r001446_1_2;
  int sec_r001446_2_1;
  int sec_r001446_2_2;
  int sec_r001446_3_1;
  int sec_r001446_3_2;
  int sec_r001446_4_1;
  int sec_r001446_4_2;
  int sec_r001446_5_1;
  int sec_r001446_5_2;
  int sec_r001446_6_1;
  int sec_r001446_6_2;
  int sec_r001446_7_1;
  int sec_r001446_7_2;
  int sec_r001446_8_1;
  int sec_r001446_8_2;
  int sec_r001446_9_1;
  int sec_r001446_9_2;
  int sec_r001446_10_1;
  int sec_r001446_10_2;
  int sec_r001446_11_1;
  int sec_r001446_11_2;
  int sec_r001446_12_1;
  int sec_r001446_12_2;
  int sec_r001446_13_1;
  int sec_r001446_13_2;
  int sec_r001446_14_1;
  int sec_r001446_14_2;
  int sec_r001446_15_1;
  int sec_r001446_15_2;
  int sec_r001446_16_1;
  int sec_r001446_16_2;
  int sec_r001446_17_1;
  int sec_r001446_17_2;
  int pub_r001446_0_1;
  int pub_r001446_0_2;
  int pub_r001446_1_1;
  int pub_r001446_1_2;
  int pub_r001446_2_1;
  int pub_r001446_2_2;
  int pub_r001446_3_1;
  int pub_r001446_3_2;
  int pub_r001446_4_1;
  int pub_r001446_4_2;
  int pub_r001446_5_1;
  int pub_r001446_5_2;
  int pub_r001446_6_1;
  int pub_r001446_6_2;
  int pub_r001446_7_1;
  int pub_r001446_7_2;
  int pub_r001446_8_1;
  int pub_r001446_8_2;
  int pub_r001446_9_1;
  int pub_r001446_9_2;
  int pub_r001446_10_1;
  int pub_r001446_10_2;
  int pub_r001446_11_1;
  int pub_r001446_11_2;
  int pub_r001446_12_1;
  int pub_r001446_12_2;
  int pub_r001446_13_1;
  int pub_r001446_13_2;
  int pub_r001446_14_1;
  int pub_r001446_14_2;
  int pub_r001446_15_1;
  int pub_r001446_15_2;
  int pub_r001446_16_1;
  int pub_r001446_16_2;
  int pub_r001446_17_1;
  int pub_r001446_17_2;
  int pub_r001446_18_1;
  int pub_r001446_18_2;
  int pub_r001446_19_1;
  int pub_r001446_19_2;
  int pub_r001446_20_1;
  int pub_r001446_20_2;
  int pub_r001446_21_1;
  int pub_r001446_21_2;
  int pub_r001446_22_1;
  int pub_r001446_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001446_0_1 >= (-100)) && (pub_r001446_0_1 <= 100));
  __CPROVER_assume((pub_r001446_0_2 >= (-100)) && (pub_r001446_0_2 <= 100));
  __CPROVER_assume((pub_r001446_1_1 >= (-100)) && (pub_r001446_1_1 <= 100));
  __CPROVER_assume((pub_r001446_1_2 >= (-100)) && (pub_r001446_1_2 <= 100));
  __CPROVER_assume((pub_r001446_2_1 >= (-100)) && (pub_r001446_2_1 <= 100));
  __CPROVER_assume((pub_r001446_2_2 >= (-100)) && (pub_r001446_2_2 <= 100));
  __CPROVER_assume((pub_r001446_3_1 >= (-100)) && (pub_r001446_3_1 <= 100));
  __CPROVER_assume((pub_r001446_3_2 >= (-100)) && (pub_r001446_3_2 <= 100));
  __CPROVER_assume((pub_r001446_4_1 >= (-100)) && (pub_r001446_4_1 <= 100));
  __CPROVER_assume((pub_r001446_4_2 >= (-100)) && (pub_r001446_4_2 <= 100));
  __CPROVER_assume((pub_r001446_5_1 >= (-100)) && (pub_r001446_5_1 <= 100));
  __CPROVER_assume((pub_r001446_5_2 >= (-100)) && (pub_r001446_5_2 <= 100));
  __CPROVER_assume((pub_r001446_6_1 >= (-100)) && (pub_r001446_6_1 <= 100));
  __CPROVER_assume((pub_r001446_6_2 >= (-100)) && (pub_r001446_6_2 <= 100));
  __CPROVER_assume((pub_r001446_7_1 >= (-100)) && (pub_r001446_7_1 <= 100));
  __CPROVER_assume((pub_r001446_7_2 >= (-100)) && (pub_r001446_7_2 <= 100));
  __CPROVER_assume((pub_r001446_8_1 >= (-100)) && (pub_r001446_8_1 <= 100));
  __CPROVER_assume((pub_r001446_8_2 >= (-100)) && (pub_r001446_8_2 <= 100));
  __CPROVER_assume((pub_r001446_9_1 >= (-100)) && (pub_r001446_9_1 <= 100));
  __CPROVER_assume((pub_r001446_9_2 >= (-100)) && (pub_r001446_9_2 <= 100));
  __CPROVER_assume((pub_r001446_10_1 >= (-100)) && (pub_r001446_10_1 <= 100));
  __CPROVER_assume((pub_r001446_10_2 >= (-100)) && (pub_r001446_10_2 <= 100));
  __CPROVER_assume((pub_r001446_11_1 >= (-100)) && (pub_r001446_11_1 <= 100));
  __CPROVER_assume((pub_r001446_11_2 >= (-100)) && (pub_r001446_11_2 <= 100));
  __CPROVER_assume((pub_r001446_12_1 >= (-100)) && (pub_r001446_12_1 <= 100));
  __CPROVER_assume((pub_r001446_12_2 >= (-100)) && (pub_r001446_12_2 <= 100));
  __CPROVER_assume((pub_r001446_13_1 >= (-100)) && (pub_r001446_13_1 <= 100));
  __CPROVER_assume((pub_r001446_13_2 >= (-100)) && (pub_r001446_13_2 <= 100));
  __CPROVER_assume((pub_r001446_14_1 >= (-100)) && (pub_r001446_14_1 <= 100));
  __CPROVER_assume((pub_r001446_14_2 >= (-100)) && (pub_r001446_14_2 <= 100));
  __CPROVER_assume((pub_r001446_15_1 >= (-100)) && (pub_r001446_15_1 <= 100));
  __CPROVER_assume((pub_r001446_15_2 >= (-100)) && (pub_r001446_15_2 <= 100));
  __CPROVER_assume((pub_r001446_16_1 >= (-100)) && (pub_r001446_16_1 <= 100));
  __CPROVER_assume((pub_r001446_16_2 >= (-100)) && (pub_r001446_16_2 <= 100));
  __CPROVER_assume((pub_r001446_17_1 >= (-100)) && (pub_r001446_17_1 <= 100));
  __CPROVER_assume((pub_r001446_17_2 >= (-100)) && (pub_r001446_17_2 <= 100));
  __CPROVER_assume((pub_r001446_18_1 >= (-100)) && (pub_r001446_18_1 <= 100));
  __CPROVER_assume((pub_r001446_18_2 >= (-100)) && (pub_r001446_18_2 <= 100));
  __CPROVER_assume((pub_r001446_19_1 >= (-100)) && (pub_r001446_19_1 <= 100));
  __CPROVER_assume((pub_r001446_19_2 >= (-100)) && (pub_r001446_19_2 <= 100));
  __CPROVER_assume((pub_r001446_20_1 >= (-100)) && (pub_r001446_20_1 <= 100));
  __CPROVER_assume((pub_r001446_20_2 >= (-100)) && (pub_r001446_20_2 <= 100));
  __CPROVER_assume((pub_r001446_21_1 >= (-100)) && (pub_r001446_21_1 <= 100));
  __CPROVER_assume((pub_r001446_21_2 >= (-100)) && (pub_r001446_21_2 <= 100));
  __CPROVER_assume((pub_r001446_22_1 >= (-100)) && (pub_r001446_22_1 <= 100));
  __CPROVER_assume((pub_r001446_22_2 >= (-100)) && (pub_r001446_22_2 <= 100));
  __CPROVER_assume((sec_r001446_0_1 >= 0) && (sec_r001446_0_1 <= 255));
  __CPROVER_assume((sec_r001446_0_2 >= 0) && (sec_r001446_0_2 <= 255));
  __CPROVER_assume((sec_r001446_1_1 >= 0) && (sec_r001446_1_1 <= 255));
  __CPROVER_assume((sec_r001446_1_2 >= 0) && (sec_r001446_1_2 <= 255));
  __CPROVER_assume((sec_r001446_2_1 >= 0) && (sec_r001446_2_1 <= 255));
  __CPROVER_assume((sec_r001446_2_2 >= 0) && (sec_r001446_2_2 <= 255));
  __CPROVER_assume((sec_r001446_3_1 >= 0) && (sec_r001446_3_1 <= 255));
  __CPROVER_assume((sec_r001446_3_2 >= 0) && (sec_r001446_3_2 <= 255));
  __CPROVER_assume((sec_r001446_4_1 >= 0) && (sec_r001446_4_1 <= 255));
  __CPROVER_assume((sec_r001446_4_2 >= 0) && (sec_r001446_4_2 <= 255));
  __CPROVER_assume((sec_r001446_5_1 >= 0) && (sec_r001446_5_1 <= 255));
  __CPROVER_assume((sec_r001446_5_2 >= 0) && (sec_r001446_5_2 <= 255));
  __CPROVER_assume((sec_r001446_6_1 >= 0) && (sec_r001446_6_1 <= 255));
  __CPROVER_assume((sec_r001446_6_2 >= 0) && (sec_r001446_6_2 <= 255));
  __CPROVER_assume((sec_r001446_7_1 >= 0) && (sec_r001446_7_1 <= 255));
  __CPROVER_assume((sec_r001446_7_2 >= 0) && (sec_r001446_7_2 <= 255));
  __CPROVER_assume((sec_r001446_8_1 >= 0) && (sec_r001446_8_1 <= 255));
  __CPROVER_assume((sec_r001446_8_2 >= 0) && (sec_r001446_8_2 <= 255));
  __CPROVER_assume((sec_r001446_9_1 >= 0) && (sec_r001446_9_1 <= 255));
  __CPROVER_assume((sec_r001446_9_2 >= 0) && (sec_r001446_9_2 <= 255));
  __CPROVER_assume((sec_r001446_10_1 >= 0) && (sec_r001446_10_1 <= 255));
  __CPROVER_assume((sec_r001446_10_2 >= 0) && (sec_r001446_10_2 <= 255));
  __CPROVER_assume((sec_r001446_11_1 >= 0) && (sec_r001446_11_1 <= 255));
  __CPROVER_assume((sec_r001446_11_2 >= 0) && (sec_r001446_11_2 <= 255));
  __CPROVER_assume((sec_r001446_12_1 >= 0) && (sec_r001446_12_1 <= 255));
  __CPROVER_assume((sec_r001446_12_2 >= 0) && (sec_r001446_12_2 <= 255));
  __CPROVER_assume((sec_r001446_13_1 >= 0) && (sec_r001446_13_1 <= 255));
  __CPROVER_assume((sec_r001446_13_2 >= 0) && (sec_r001446_13_2 <= 255));
  __CPROVER_assume((sec_r001446_14_1 >= 0) && (sec_r001446_14_1 <= 255));
  __CPROVER_assume((sec_r001446_14_2 >= 0) && (sec_r001446_14_2 <= 255));
  __CPROVER_assume((sec_r001446_15_1 >= 0) && (sec_r001446_15_1 <= 255));
  __CPROVER_assume((sec_r001446_15_2 >= 0) && (sec_r001446_15_2 <= 255));
  __CPROVER_assume((sec_r001446_16_1 >= 0) && (sec_r001446_16_1 <= 255));
  __CPROVER_assume((sec_r001446_16_2 >= 0) && (sec_r001446_16_2 <= 255));
  __CPROVER_assume((sec_r001446_17_1 >= 0) && (sec_r001446_17_1 <= 255));
  __CPROVER_assume((sec_r001446_17_2 >= 0) && (sec_r001446_17_2 <= 255));
  struct MatrixBlock_R001446_4613_0 st_var_0_1 = {0};
  struct MatrixBlock_R001446_4613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001446_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001446_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001446_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001446_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001446_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001446_0_2 + 7) & 15;
  struct DeviceConfig_R001446_4613_1 st_var_1_1 = {0};
  struct DeviceConfig_R001446_4613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001446_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001446_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001446_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001446_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001446_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001446_0_2 + 9) & 15;
  struct SensorNode_R001446_4613_2 st_var_2_1 = {0};
  struct SensorNode_R001446_4613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001446_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001446_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001446_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001446_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001446_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001446_0_2 + 11) & 15;
  union PacketPayload_R001446_4613_0 u_var_1;
  union PacketPayload_R001446_4613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001446_4613_0(sec_r001446_0_1, sec_r001446_1_1);
  int helper_flow_0_2 = fn_R001446_4613_0(sec_r001446_0_2, sec_r001446_1_2);
  fn_R001446_4613_0_2(sec_r001446_0_1, sec_r001446_1_1, sec_r001446_0_2, sec_r001446_1_2);
  int helper_flow_1_1 = fn_R001446_4613_1(sec_r001446_1_1, pub_r001446_2_1, pub_r001446_3_1);
  int helper_flow_1_2 = fn_R001446_4613_1(sec_r001446_1_2, pub_r001446_2_2, pub_r001446_3_2);
  fn_R001446_4613_1_2(sec_r001446_1_1, pub_r001446_2_1, pub_r001446_3_1, sec_r001446_1_2, pub_r001446_2_2, pub_r001446_3_2);
  int helper_flow_2_1 = fn_R001446_4613_2(sec_r001446_2_1, sec_r001446_3_1, pub_r001446_4_1);
  int helper_flow_2_2 = fn_R001446_4613_2(sec_r001446_2_2, sec_r001446_3_2, pub_r001446_4_2);
  fn_R001446_4613_2_2(sec_r001446_2_1, sec_r001446_3_1, pub_r001446_4_1, sec_r001446_2_2, sec_r001446_3_2, pub_r001446_4_2);
  int helper_flow_3_1 = fn_R001446_4613_3(sec_r001446_3_1, sec_r001446_4_1, pub_r001446_5_1, pub_r001446_6_1, pub_r001446_7_1);
  int helper_flow_3_2 = fn_R001446_4613_3(sec_r001446_3_2, sec_r001446_4_2, pub_r001446_5_2, pub_r001446_6_2, pub_r001446_7_2);
  fn_R001446_4613_3_2(sec_r001446_3_1, sec_r001446_4_1, pub_r001446_5_1, pub_r001446_6_1, pub_r001446_7_1, sec_r001446_3_2, sec_r001446_4_2, pub_r001446_5_2, pub_r001446_6_2, pub_r001446_7_2);
  int helper_flow_4_1 = fn_R001446_4613_4(sec_r001446_4_1, sec_r001446_5_1);
  int helper_flow_4_2 = fn_R001446_4613_4(sec_r001446_4_2, sec_r001446_5_2);
  fn_R001446_4613_4_2(sec_r001446_4_1, sec_r001446_5_1, sec_r001446_4_2, sec_r001446_5_2);
  int helper_flow_5_1 = fn_R001446_4613_5(sec_r001446_5_1, pub_r001446_6_1, pub_r001446_7_1, pub_r001446_8_1, pub_r001446_9_1);
  int helper_flow_5_2 = fn_R001446_4613_5(sec_r001446_5_2, pub_r001446_6_2, pub_r001446_7_2, pub_r001446_8_2, pub_r001446_9_2);
  fn_R001446_4613_5_2(sec_r001446_5_1, pub_r001446_6_1, pub_r001446_7_1, pub_r001446_8_1, pub_r001446_9_1, sec_r001446_5_2, pub_r001446_6_2, pub_r001446_7_2, pub_r001446_8_2, pub_r001446_9_2);
  int helper_flow_6_1 = fn_R001446_4613_6(sec_r001446_6_1, pub_r001446_7_1, pub_r001446_8_1, pub_r001446_9_1);
  int helper_flow_6_2 = fn_R001446_4613_6(sec_r001446_6_2, pub_r001446_7_2, pub_r001446_8_2, pub_r001446_9_2);
  fn_R001446_4613_6_2(sec_r001446_6_1, pub_r001446_7_1, pub_r001446_8_1, pub_r001446_9_1, sec_r001446_6_2, pub_r001446_7_2, pub_r001446_8_2, pub_r001446_9_2);
  int helper_flow_7_1 = fn_R001446_4613_7(sec_r001446_7_1, sec_r001446_8_1, pub_r001446_9_1, pub_r001446_10_1, pub_r001446_11_1);
  int helper_flow_7_2 = fn_R001446_4613_7(sec_r001446_7_2, sec_r001446_8_2, pub_r001446_9_2, pub_r001446_10_2, pub_r001446_11_2);
  fn_R001446_4613_7_2(sec_r001446_7_1, sec_r001446_8_1, pub_r001446_9_1, pub_r001446_10_1, pub_r001446_11_1, sec_r001446_7_2, sec_r001446_8_2, pub_r001446_9_2, pub_r001446_10_2, pub_r001446_11_2);
  int stage_v_0_1 = ((helper_flow_3_1 + (pub_r001446_6_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_3_2 + (pub_r001446_6_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((helper_flow_2_1 + (pub_r001446_20_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((helper_flow_2_2 + (pub_r001446_20_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001446_6_1 * 2) + 49) & 63;
  int stage_v_2_2 = ((pub_r001446_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((sec_r001446_14_1 + (pub_r001446_6_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001446_14_2 + (pub_r001446_6_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001446_11_1 * 2) + 6) & 63;
  int stage_v_4_2 = ((pub_r001446_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((helper_flow_1_1 + (pub_r001446_6_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((helper_flow_1_2 + (pub_r001446_6_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001446_0_1 + (pub_r001446_10_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001446_0_2 + (pub_r001446_10_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((sec_r001446_17_1 + (pub_r001446_1_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001446_17_2 + (pub_r001446_1_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((stage_v_0_1 + (pub_r001446_10_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((stage_v_0_2 + (pub_r001446_10_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001446_20_1 * 2) + 33) & 63;
  int stage_v_9_2 = ((pub_r001446_20_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((helper_flow_1_1 + (pub_r001446_22_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((helper_flow_1_2 + (pub_r001446_22_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((helper_flow_3_1 + (pub_r001446_7_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((helper_flow_3_2 + (pub_r001446_7_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((sec_r001446_11_1 + (pub_r001446_7_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001446_11_2 + (pub_r001446_7_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001446_9_1 + (pub_r001446_13_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001446_9_2 + (pub_r001446_13_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((pub_r001446_12_1 * 2) + 19) & 63;
  int stage_v_14_2 = ((pub_r001446_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001446_9_1 * 2) + 24) & 63;
  int stage_v_15_2 = ((pub_r001446_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((stage_v_13_1 + (pub_r001446_8_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((stage_v_13_2 + (pub_r001446_8_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((helper_flow_0_1 + (pub_r001446_21_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((helper_flow_0_2 + (pub_r001446_21_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((helper_flow_5_1 + (pub_r001446_13_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((helper_flow_5_2 + (pub_r001446_13_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((sec_r001446_4_1 + (pub_r001446_13_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((sec_r001446_4_2 + (pub_r001446_13_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((helper_flow_2_1 + (pub_r001446_7_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((helper_flow_2_2 + (pub_r001446_7_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((sec_r001446_13_1 + (pub_r001446_10_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((sec_r001446_13_2 + (pub_r001446_10_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((sec_r001446_8_1 + (pub_r001446_5_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001446_8_2 + (pub_r001446_5_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001446_22_1 * 2) + 12) & 63;
  int stage_v_23_2 = ((pub_r001446_22_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((stage_v_18_1 + (pub_r001446_7_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((stage_v_18_2 + (pub_r001446_7_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((helper_flow_7_1 + (pub_r001446_19_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((helper_flow_7_2 + (pub_r001446_19_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((pub_r001446_15_1 * 2) + 5) & 63;
  int stage_v_26_2 = ((pub_r001446_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((stage_v_21_1 + (pub_r001446_6_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((stage_v_21_2 + (pub_r001446_6_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((pub_r001446_3_1 * 2) + 49) & 63;
  int stage_v_28_2 = ((pub_r001446_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((stage_v_10_1 + (pub_r001446_6_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((stage_v_10_2 + (pub_r001446_6_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((stage_v_25_1 + (pub_r001446_18_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((stage_v_25_2 + (pub_r001446_18_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((sec_r001446_14_1 + (pub_r001446_20_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((sec_r001446_14_2 + (pub_r001446_20_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((pub_r001446_14_1 * 2) + 10) & 63;
  int stage_v_32_2 = ((pub_r001446_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((helper_flow_1_1 + (pub_r001446_2_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((helper_flow_1_2 + (pub_r001446_2_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((pub_r001446_12_1 * 2) + 32) & 63;
  int stage_v_34_2 = ((pub_r001446_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001446_1_1 * 2) + 50) & 63;
  int stage_v_35_2 = ((pub_r001446_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001446_7_1 * 2) + 13) & 63;
  int stage_v_36_2 = ((pub_r001446_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((helper_flow_0_1 + (pub_r001446_21_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((helper_flow_0_2 + (pub_r001446_21_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((stage_v_31_1 + (pub_r001446_13_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((stage_v_31_2 + (pub_r001446_13_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001446_12_1 * 2) + 21) & 63;
  int stage_v_39_2 = ((pub_r001446_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((stage_v_13_1 + (pub_r001446_15_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_13_2 + (pub_r001446_15_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((sec_r001446_9_1 + (pub_r001446_14_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((sec_r001446_9_2 + (pub_r001446_14_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((pub_r001446_15_1 * 2) + 10) & 63;
  int stage_v_42_2 = ((pub_r001446_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((sec_r001446_10_1 + (pub_r001446_1_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((sec_r001446_10_2 + (pub_r001446_1_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((pub_r001446_15_1 * 2) + 6) & 63;
  int stage_v_44_2 = ((pub_r001446_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001446_1_1 * 2) + 29) & 63;
  int stage_v_45_2 = ((pub_r001446_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001446_11_1 * 2) + 16) & 63;
  int stage_v_46_2 = ((pub_r001446_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001446_7_1 * 2) + 19) & 63;
  int stage_v_47_2 = ((pub_r001446_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((sec_r001446_10_1 + (pub_r001446_2_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((sec_r001446_10_2 + (pub_r001446_2_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((sec_r001446_2_1 + (pub_r001446_10_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((sec_r001446_2_2 + (pub_r001446_10_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((pub_r001446_22_1 * 2) + 25) & 63;
  int stage_v_50_2 = ((pub_r001446_22_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((sec_r001446_16_1 + (pub_r001446_7_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((sec_r001446_16_2 + (pub_r001446_7_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((pub_r001446_4_1 * 2) + 15) & 63;
  int stage_v_52_2 = ((pub_r001446_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((sec_r001446_17_1 + (pub_r001446_10_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((sec_r001446_17_2 + (pub_r001446_10_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((pub_r001446_13_1 * 2) + 35) & 63;
  int stage_v_54_2 = ((pub_r001446_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((helper_flow_2_1 + (pub_r001446_9_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((helper_flow_2_2 + (pub_r001446_9_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((sec_r001446_13_1 + (pub_r001446_17_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((sec_r001446_13_2 + (pub_r001446_17_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((pub_r001446_5_1 * 2) + 50) & 63;
  int stage_v_57_2 = ((pub_r001446_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((stage_v_16_1 + (pub_r001446_13_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_16_2 + (pub_r001446_13_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((sec_r001446_16_1 + (pub_r001446_6_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((sec_r001446_16_2 + (pub_r001446_6_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((stage_v_56_1 + (pub_r001446_19_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_56_2 + (pub_r001446_19_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_49_1 + (pub_r001446_1_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_49_2 + (pub_r001446_1_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((pub_r001446_8_1 * 2) + 9) & 63;
  int stage_v_62_2 = ((pub_r001446_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((helper_flow_6_1 + (pub_r001446_18_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((helper_flow_6_2 + (pub_r001446_18_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((sec_r001446_14_1 + (pub_r001446_14_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001446_14_2 + (pub_r001446_14_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_58_1 + (pub_r001446_4_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_58_2 + (pub_r001446_4_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((stage_v_25_1 + (pub_r001446_14_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_25_2 + (pub_r001446_14_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_18_1 + (pub_r001446_2_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_18_2 + (pub_r001446_2_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((stage_v_17_1 + (pub_r001446_1_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_17_2 + (pub_r001446_1_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((sec_r001446_0_1 + (pub_r001446_19_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((sec_r001446_0_2 + (pub_r001446_19_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((stage_v_12_1 + (pub_r001446_9_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_12_2 + (pub_r001446_9_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((sec_r001446_14_1 + (pub_r001446_18_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((sec_r001446_14_2 + (pub_r001446_18_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((stage_v_19_1 + (pub_r001446_3_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_19_2 + (pub_r001446_3_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((pub_r001446_5_1 * 2) + 31) & 63;
  int stage_v_73_2 = ((pub_r001446_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((stage_v_12_1 + (pub_r001446_7_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_12_2 + (pub_r001446_7_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((stage_v_5_1 + (pub_r001446_10_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_5_2 + (pub_r001446_10_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((pub_r001446_6_1 * 2) + 24) & 63;
  int stage_v_76_2 = ((pub_r001446_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((sec_r001446_9_1 + (pub_r001446_8_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((sec_r001446_9_2 + (pub_r001446_8_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_7_1 + (pub_r001446_20_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_7_2 + (pub_r001446_20_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001446_14_1 * 2) + 9) & 63;
  int stage_v_79_2 = ((pub_r001446_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001446_9_1 * 2) + 41) & 63;
  int stage_v_80_2 = ((pub_r001446_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((stage_v_24_1 + (pub_r001446_8_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_24_2 + (pub_r001446_8_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001446_14_1 * 2) + 26) & 63;
  int stage_v_82_2 = ((pub_r001446_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001446_1_1 * 2) + 49) & 63;
  int stage_v_83_2 = ((pub_r001446_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_67_1 + (pub_r001446_14_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_67_2 + (pub_r001446_14_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((pub_r001446_0_1 * 2) + 31) & 63;
  int stage_v_85_2 = ((pub_r001446_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((stage_v_61_1 + (pub_r001446_18_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_61_2 + (pub_r001446_18_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_69_1 + (pub_r001446_18_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_69_2 + (pub_r001446_18_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_61_1 + (pub_r001446_19_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_61_2 + (pub_r001446_19_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((sec_r001446_16_1 + (pub_r001446_19_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((sec_r001446_16_2 + (pub_r001446_19_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((pub_r001446_4_1 * 2) + 49) & 63;
  int stage_v_90_2 = ((pub_r001446_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((stage_v_40_1 + (pub_r001446_13_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_40_2 + (pub_r001446_13_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_16_1 + (pub_r001446_11_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_16_2 + (pub_r001446_11_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_43_1 + (pub_r001446_20_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_43_2 + (pub_r001446_20_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((pub_r001446_19_1 * 2) + 6) & 63;
  int stage_v_94_2 = ((pub_r001446_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001446_18_1 * 2) + 9) & 63;
  int stage_v_95_2 = ((pub_r001446_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((stage_v_51_1 + (pub_r001446_14_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_51_2 + (pub_r001446_14_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_86_1 + (pub_r001446_21_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_86_2 + (pub_r001446_21_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((pub_r001446_9_1 * 2) + 44) & 63;
  int stage_v_98_2 = ((pub_r001446_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_40_1 + (pub_r001446_21_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_40_2 + (pub_r001446_21_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_19_1 + (pub_r001446_8_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_19_2 + (pub_r001446_8_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((pub_r001446_2_1 * 2) + 28) & 63;
  int stage_v_101_2 = ((pub_r001446_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_96_1 + (pub_r001446_3_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_96_2 + (pub_r001446_3_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((sec_r001446_6_1 + (pub_r001446_14_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((sec_r001446_6_2 + (pub_r001446_14_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_27_1 + (pub_r001446_1_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_27_2 + (pub_r001446_1_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((pub_r001446_3_1 * 2) + 50) & 63;
  int stage_v_105_2 = ((pub_r001446_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001446_3_1 * 2) + 27) & 63;
  int stage_v_106_2 = ((pub_r001446_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((stage_v_51_1 + (pub_r001446_14_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_51_2 + (pub_r001446_14_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((stage_v_99_1 + (pub_r001446_10_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_99_2 + (pub_r001446_10_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_92_1 + (pub_r001446_7_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_92_2 + (pub_r001446_7_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((pub_r001446_13_1 * 2) + 14) & 63;
  int stage_v_110_2 = ((pub_r001446_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_67_1 + (pub_r001446_0_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_67_2 + (pub_r001446_0_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((stage_v_100_1 + (pub_r001446_1_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_100_2 + (pub_r001446_1_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((stage_v_66_1 + (pub_r001446_7_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_66_2 + (pub_r001446_7_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((pub_r001446_21_1 * 2) + 41) & 63;
  int stage_v_114_2 = ((pub_r001446_21_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001446_10_1 * 2) + 11) & 63;
  int stage_v_115_2 = ((pub_r001446_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((stage_v_43_1 + (pub_r001446_12_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_43_2 + (pub_r001446_12_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001446_8_1 * 2) + 28) & 63;
  int stage_v_117_2 = ((pub_r001446_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_11_1 + (pub_r001446_18_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_11_2 + (pub_r001446_18_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((pub_r001446_22_1 * 2) + 28) & 63;
  int stage_v_119_2 = ((pub_r001446_22_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((stage_v_58_1 + (pub_r001446_4_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_58_2 + (pub_r001446_4_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_108_1 + (pub_r001446_9_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_108_2 + (pub_r001446_9_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_69_1 + (pub_r001446_3_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_69_2 + (pub_r001446_3_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((pub_r001446_6_1 * 2) + 44) & 63;
  int stage_v_123_2 = ((pub_r001446_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001446_18_1 * 2) + 26) & 63;
  int stage_v_124_2 = ((pub_r001446_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_25_1 + (pub_r001446_19_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_25_2 + (pub_r001446_19_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_69_1 + (pub_r001446_4_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_69_2 + (pub_r001446_4_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((pub_r001446_14_1 * 2) + 15) & 63;
  int stage_v_127_2 = ((pub_r001446_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001446_11_1 * 2) + 44) & 63;
  int stage_v_128_2 = ((pub_r001446_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001446_12_1 * 2) + 49) & 63;
  int stage_v_129_2 = ((pub_r001446_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_67_1 + (pub_r001446_5_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_67_2 + (pub_r001446_5_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_69_1 + (pub_r001446_6_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_69_2 + (pub_r001446_6_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((pub_r001446_22_1 * 2) + 35) & 63;
  int stage_v_132_2 = ((pub_r001446_22_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((helper_flow_1_1 + (pub_r001446_5_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((helper_flow_1_2 + (pub_r001446_5_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001446_16_1 * 2) + 42) & 63;
  int stage_v_134_2 = ((pub_r001446_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((stage_v_108_1 + (pub_r001446_14_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_108_2 + (pub_r001446_14_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_133_1 + (pub_r001446_10_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_133_2 + (pub_r001446_10_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001446_2_1 * 2) + 35) & 63;
  int stage_v_137_2 = ((pub_r001446_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001446_3_1 * 2) + 28) & 63;
  int stage_v_138_2 = ((pub_r001446_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001446_1_1 * 2) + 19) & 63;
  int stage_v_139_2 = ((pub_r001446_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001446_8_1 * 2) + 8) & 63;
  int stage_v_140_2 = ((pub_r001446_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001446_20_1 * 2) + 28) & 63;
  int stage_v_141_2 = ((pub_r001446_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((sec_r001446_8_1 + (pub_r001446_3_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((sec_r001446_8_2 + (pub_r001446_3_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((sec_r001446_10_1 + (pub_r001446_5_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((sec_r001446_10_2 + (pub_r001446_5_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((sec_r001446_12_1 + (pub_r001446_1_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((sec_r001446_12_2 + (pub_r001446_1_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((pub_r001446_9_1 * 2) + 34) & 63;
  int stage_v_145_2 = ((pub_r001446_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((stage_v_135_1 + (pub_r001446_3_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_135_2 + (pub_r001446_3_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_31_1 + (pub_r001446_0_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_31_2 + (pub_r001446_0_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_97_1 + (pub_r001446_0_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_97_2 + (pub_r001446_0_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001446_9_1 * 2) + 11) & 63;
  int stage_v_149_2 = ((pub_r001446_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_29_1 + (pub_r001446_18_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_29_2 + (pub_r001446_18_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_68_1 + (pub_r001446_12_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_68_2 + (pub_r001446_12_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_109_1 + (pub_r001446_12_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_109_2 + (pub_r001446_12_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((pub_r001446_8_1 * 2) + 36) & 63;
  int stage_v_153_2 = ((pub_r001446_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001446_19_1 * 2) + 29) & 63;
  int stage_v_154_2 = ((pub_r001446_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_65_1 + (pub_r001446_11_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_65_2 + (pub_r001446_11_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((stage_v_147_1 + (pub_r001446_7_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_147_2 + (pub_r001446_7_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((stage_v_55_1 + (pub_r001446_4_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_55_2 + (pub_r001446_4_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_12_1 + (pub_r001446_22_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_12_2 + (pub_r001446_22_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_152_1 + (pub_r001446_5_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_152_2 + (pub_r001446_5_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_148_1 + (pub_r001446_9_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_148_2 + (pub_r001446_9_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_116_1 + (pub_r001446_16_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_116_2 + (pub_r001446_16_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((stage_v_100_1 + (pub_r001446_6_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_100_2 + (pub_r001446_6_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_146_1 + (pub_r001446_2_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_146_2 + (pub_r001446_2_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((pub_r001446_0_1 * 2) + 8) & 63;
  int stage_v_164_2 = ((pub_r001446_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((sec_r001446_10_1 + (pub_r001446_16_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((sec_r001446_10_2 + (pub_r001446_16_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_91_1 + (pub_r001446_18_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_91_2 + (pub_r001446_18_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((pub_r001446_1_1 * 2) + 21) & 63;
  int stage_v_167_2 = ((pub_r001446_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((stage_v_157_1 + (pub_r001446_6_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_157_2 + (pub_r001446_6_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((pub_r001446_22_1 * 2) + 30) & 63;
  int stage_v_169_2 = ((pub_r001446_22_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001446_17_1 * 2) + 34) & 63;
  int stage_v_170_2 = ((pub_r001446_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((stage_v_75_1 + (pub_r001446_3_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_75_2 + (pub_r001446_3_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((pub_r001446_9_1 * 2) + 42) & 63;
  int stage_v_172_2 = ((pub_r001446_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((sec_r001446_11_1 + (pub_r001446_13_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((sec_r001446_11_2 + (pub_r001446_13_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((pub_r001446_12_1 * 2) + 18) & 63;
  int stage_v_174_2 = ((pub_r001446_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((stage_v_33_1 + (pub_r001446_19_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_33_2 + (pub_r001446_19_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((pub_r001446_9_1 * 2) + 6) & 63;
  int stage_v_176_2 = ((pub_r001446_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_111_1 + (pub_r001446_21_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_111_2 + (pub_r001446_21_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_61_1 + (pub_r001446_2_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_61_2 + (pub_r001446_2_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((pub_r001446_4_1 * 2) + 16) & 63;
  int stage_v_179_2 = ((pub_r001446_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001446_15_1 * 2) + 17) & 63;
  int stage_v_180_2 = ((pub_r001446_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((stage_v_20_1 + (pub_r001446_11_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_20_2 + (pub_r001446_11_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_133_1 + (pub_r001446_22_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_133_2 + (pub_r001446_22_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((pub_r001446_0_1 * 2) + 8) & 63;
  int stage_v_183_2 = ((pub_r001446_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((stage_v_111_1 + (pub_r001446_7_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_111_2 + (pub_r001446_7_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((helper_flow_6_1 + (pub_r001446_1_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((helper_flow_6_2 + (pub_r001446_1_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((stage_v_60_1 + (pub_r001446_5_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_60_2 + (pub_r001446_5_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((sec_r001446_5_1 + (pub_r001446_1_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((sec_r001446_5_2 + (pub_r001446_1_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001446_6_1 * 2) + 33) & 63;
  int stage_v_188_2 = ((pub_r001446_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((helper_flow_1_1 + (pub_r001446_1_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((helper_flow_1_2 + (pub_r001446_1_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001446_1_1 * 2) + 50) & 63;
  int stage_v_190_2 = ((pub_r001446_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((stage_v_161_1 + (pub_r001446_19_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_161_2 + (pub_r001446_19_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_173_1 + (pub_r001446_12_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_173_2 + (pub_r001446_12_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((sec_r001446_12_1 + (pub_r001446_21_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((sec_r001446_12_2 + (pub_r001446_21_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_60_1 + (pub_r001446_1_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_60_2 + (pub_r001446_1_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((pub_r001446_12_1 * 2) + 38) & 63;
  int stage_v_195_2 = ((pub_r001446_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001446_15_1 * 2) + 14) & 63;
  int stage_v_196_2 = ((pub_r001446_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001446_13_1 * 2) + 5) & 63;
  int stage_v_197_2 = ((pub_r001446_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((stage_v_182_1 + (pub_r001446_0_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_182_2 + (pub_r001446_0_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((sec_r001446_1_1 + (pub_r001446_18_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((sec_r001446_1_2 + (pub_r001446_18_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_108_1 + (pub_r001446_8_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_108_2 + (pub_r001446_8_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((stage_v_20_1 + (pub_r001446_6_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_20_2 + (pub_r001446_6_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_122_1 + (pub_r001446_5_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_122_2 + (pub_r001446_5_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((sec_r001446_12_1 + (pub_r001446_1_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((sec_r001446_12_2 + (pub_r001446_1_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((pub_r001446_1_1 * 2) + 32) & 63;
  int stage_v_204_2 = ((pub_r001446_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((stage_v_21_1 + (pub_r001446_13_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_21_2 + (pub_r001446_13_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001446_13_1 * 2) + 26) & 63;
  int stage_v_206_2 = ((pub_r001446_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((stage_v_63_1 + (pub_r001446_18_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_63_2 + (pub_r001446_18_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_19_1 + (pub_r001446_16_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_19_2 + (pub_r001446_16_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((sec_r001446_4_1 + (pub_r001446_13_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((sec_r001446_4_2 + (pub_r001446_13_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((stage_v_156_1 + (pub_r001446_0_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_156_2 + (pub_r001446_0_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((pub_r001446_2_1 * 2) + 35) & 63;
  int stage_v_211_2 = ((pub_r001446_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001446_7_1 * 2) + 35) & 63;
  int stage_v_212_2 = ((pub_r001446_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001446_20_1 * 2) + 18) & 63;
  int stage_v_213_2 = ((pub_r001446_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((stage_v_96_1 + (pub_r001446_3_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_96_2 + (pub_r001446_3_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((pub_r001446_9_1 * 2) + 44) & 63;
  int stage_v_215_2 = ((pub_r001446_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001446_21_1 * 2) + 49) & 63;
  int stage_v_216_2 = ((pub_r001446_21_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001446_20_1 * 2) + 50) & 63;
  int stage_v_217_2 = ((pub_r001446_20_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001446_2_1 * 2) + 10) & 63;
  int stage_v_218_2 = ((pub_r001446_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001446_18_1 * 2) + 32) & 63;
  int stage_v_219_2 = ((pub_r001446_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001446_6_1 * 2) + 15) & 63;
  int stage_v_220_2 = ((pub_r001446_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((sec_r001446_5_1 + (pub_r001446_20_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((sec_r001446_5_2 + (pub_r001446_20_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_55_1 + (pub_r001446_18_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_55_2 + (pub_r001446_18_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_166_1 + (pub_r001446_11_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_166_2 + (pub_r001446_11_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((stage_v_112_1 + (pub_r001446_3_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_112_2 + (pub_r001446_3_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((pub_r001446_19_1 * 2) + 41) & 63;
  int stage_v_225_2 = ((pub_r001446_19_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001446_6_1 * 2) + 42) & 63;
  int stage_v_226_2 = ((pub_r001446_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_102_1 + (pub_r001446_13_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_102_2 + (pub_r001446_13_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((pub_r001446_21_1 * 2) + 34) & 63;
  int stage_v_228_2 = ((pub_r001446_21_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001446_0_1 * 2) + 6) & 63;
  int stage_v_229_2 = ((pub_r001446_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001446_17_1 * 2) + 16) & 63;
  int stage_v_230_2 = ((pub_r001446_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((stage_v_122_1 + (pub_r001446_11_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_122_2 + (pub_r001446_11_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((pub_r001446_0_1 * 2) + 24) & 63;
  int stage_v_232_2 = ((pub_r001446_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((stage_v_231_1 + (pub_r001446_20_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_231_2 + (pub_r001446_20_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((sec_r001446_13_1 + (pub_r001446_15_1 * 2)) + 707) & 127;
  int stage_v_234_2 = ((sec_r001446_13_2 + (pub_r001446_15_2 * 2)) + 707) & 127;
  if (stage_v_234_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_234_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_234_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_234_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_235_1 = ((stage_v_70_1 + (pub_r001446_9_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((stage_v_70_2 + (pub_r001446_9_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((pub_r001446_22_1 * 2) + 50) & 63;
  int stage_v_236_2 = ((pub_r001446_22_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((stage_v_40_1 + (pub_r001446_13_1 * 2)) + 716) & 127;
  int stage_v_237_2 = ((stage_v_40_2 + (pub_r001446_13_2 * 2)) + 716) & 127;
  if (stage_v_237_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_237_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_237_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_237_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_238_1 = ((stage_v_189_1 + (pub_r001446_7_1 * 2)) + 719) & 127;
  int stage_v_238_2 = ((stage_v_189_2 + (pub_r001446_7_2 * 2)) + 719) & 127;
  if (stage_v_238_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_238_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_238_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_238_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_239_1 = ((stage_v_0_1 + (pub_r001446_2_1 * 2)) + 722) & 127;
  int stage_v_239_2 = ((stage_v_0_2 + (pub_r001446_2_2 * 2)) + 722) & 127;
  if (stage_v_239_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_239_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_239_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_239_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_240_1 = ((stage_v_69_1 + (pub_r001446_8_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((stage_v_69_2 + (pub_r001446_8_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((pub_r001446_21_1 * 2) + 31) & 63;
  int stage_v_241_2 = ((pub_r001446_21_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((stage_v_120_1 + (pub_r001446_7_1 * 2)) + 731) & 127;
  int stage_v_242_2 = ((stage_v_120_2 + (pub_r001446_7_2 * 2)) + 731) & 127;
  if (stage_v_242_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_242_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_242_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_242_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_243_1 = ((pub_r001446_11_1 * 2) + 24) & 63;
  int stage_v_243_2 = ((pub_r001446_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((helper_flow_7_1 + (pub_r001446_16_1 * 2)) + 737) & 127;
  int stage_v_244_2 = ((helper_flow_7_2 + (pub_r001446_16_2 * 2)) + 737) & 127;
  if (stage_v_244_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_244_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_244_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_244_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001446_11_1 == pub_r001446_11_2);
  __CPROVER_assume(pub_r001446_17_1 == pub_r001446_17_2);
  __CPROVER_assume(pub_r001446_22_1 == pub_r001446_22_2);
  __CPROVER_assume(sec_r001446_6_1 != sec_r001446_6_2);
  __CPROVER_assume(sec_r001446_7_1 != sec_r001446_7_2);
  __CPROVER_assume(pub_r001446_19_1 == pub_r001446_19_2);
  __CPROVER_assume(sec_r001446_4_1 != sec_r001446_4_2);
  __CPROVER_assume(sec_r001446_17_1 != sec_r001446_17_2);
  __CPROVER_assume(sec_r001446_5_1 != sec_r001446_5_2);
  __CPROVER_assume(pub_r001446_15_1 == pub_r001446_15_2);
  __CPROVER_assume(sec_r001446_14_1 != sec_r001446_14_2);
  __CPROVER_assume(sec_r001446_15_1 != sec_r001446_15_2);
  __CPROVER_assume(pub_r001446_14_1 == pub_r001446_14_2);
  __CPROVER_assume(sec_r001446_12_1 != sec_r001446_12_2);
  __CPROVER_assume(sec_r001446_3_1 != sec_r001446_3_2);
  __CPROVER_assume(pub_r001446_4_1 == pub_r001446_4_2);
  __CPROVER_assume(pub_r001446_3_1 == pub_r001446_3_2);
  __CPROVER_assume(pub_r001446_12_1 == pub_r001446_12_2);
  __CPROVER_assume(sec_r001446_13_1 != sec_r001446_13_2);
  __CPROVER_assume(sec_r001446_0_1 != sec_r001446_0_2);
  __CPROVER_assume(pub_r001446_16_1 == pub_r001446_16_2);
  __CPROVER_assume(sec_r001446_16_1 != sec_r001446_16_2);
  __CPROVER_assume(pub_r001446_6_1 == pub_r001446_6_2);
  __CPROVER_assume(sec_r001446_8_1 != sec_r001446_8_2);
  __CPROVER_assume(pub_r001446_1_1 == pub_r001446_1_2);
  __CPROVER_assume(sec_r001446_11_1 != sec_r001446_11_2);
  __CPROVER_assume(pub_r001446_13_1 == pub_r001446_13_2);
  __CPROVER_assume(pub_r001446_2_1 == pub_r001446_2_2);
  __CPROVER_assume(sec_r001446_9_1 != sec_r001446_9_2);
  __CPROVER_assume(pub_r001446_0_1 == pub_r001446_0_2);
  __CPROVER_assume(pub_r001446_5_1 == pub_r001446_5_2);
  __CPROVER_assume(sec_r001446_2_1 != sec_r001446_2_2);
  __CPROVER_assume(pub_r001446_7_1 == pub_r001446_7_2);
  __CPROVER_assume(pub_r001446_9_1 == pub_r001446_9_2);
  __CPROVER_assume(pub_r001446_18_1 == pub_r001446_18_2);
  __CPROVER_assume(pub_r001446_20_1 == pub_r001446_20_2);
  __CPROVER_assume(pub_r001446_21_1 == pub_r001446_21_2);
  __CPROVER_assume(pub_r001446_8_1 == pub_r001446_8_2);
  __CPROVER_assume(pub_r001446_10_1 == pub_r001446_10_2);
  __CPROVER_assume(sec_r001446_1_1 != sec_r001446_1_2);
  __CPROVER_assume(sec_r001446_10_1 != sec_r001446_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
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
}


