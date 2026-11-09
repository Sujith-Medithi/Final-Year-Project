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
struct FilterState_R001214_1413_0
{
  int cutoff;
  int gain_db;
  int prev_out;
  int mode;
  int buffer[3];
};
struct DeviceConfig_R001214_1413_1
{
  int timeout;
  int baud_rate;
  short port;
  int parity;
  int buffer[3];
};
struct StreamBuffer_R001214_1413_2
{
  int tail;
  int watermark;
  int checksum;
  int buffer[3];
};
struct SensorNode_R001214_1413_3
{
  int gain;
  short status;
  int threshold;
  int buffer[3];
};
union TelemetryField_R001214_1413_0
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
void fn_R001214_1413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001214_1413_0 st_1 = {0};
  struct FilterState_R001214_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int anchor_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_52_1)
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

  switch (anchor_52_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_52_1 == anchor_52_2);
}

int fn_R001214_1413_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001214_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int anchor_52 = (aux + st.buffer[1]) & 3;
  switch (anchor_52)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001214_1413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001214_1413_0 st_1 = {0};
  struct FilterState_R001214_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_38_1 = local_arr_1[aux_1 % 3];
  int tracker_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_38_2 * 2)) & 127;
  int window_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_53_1) & 63;
  aux_2 = (aux_2 + window_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_38_1 == tracker_38_2);
  assert(window_53_1 == window_53_2);
}

int fn_R001214_1413_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001214_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int tracker_38 = local_arr[aux % 3];
  acc = (acc + (tracker_38 * 2)) & 127;
  int window_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_53) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001214_1413_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001214_1413_2 st_1 = {0};
  struct StreamBuffer_R001214_1413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int delta_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_79_1)
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

  switch (delta_79_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_69_1 = local_arr_1[aux_1 % 3];
  int quantum_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_69_2 * 2)) & 127;
  int factor_23_1 = 0;
  int factor_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_23_1 = ((factor_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_23_2 = ((factor_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_23_1) & 127;
    acc_2 = (acc_2 + factor_23_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_79_1 == delta_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_69_1 == quantum_69_2);
  assert(factor_23_1 == factor_23_2);
}

int fn_R001214_1413_2(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001214_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int delta_79 = (aux + st.buffer[1]) & 3;
  switch (delta_79)
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

  int local_arr[3] = {4, 9, 15};
  int quantum_69 = local_arr[aux % 3];
  acc = (acc + (quantum_69 * 2)) & 127;
  int factor_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_23 = ((factor_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_23) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001214_1413_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001214_1413_0 st_1 = {0};
  struct FilterState_R001214_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quantum_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_81_1)
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

  switch (quantum_81_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_81_1 == quantum_81_2);
}

int fn_R001214_1413_3(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001214_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quantum_81 = (aux + st.buffer[1]) & 3;
  switch (quantum_81)
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

void fn_R001214_1413_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001214_1413_3 st_1 = {0};
  struct SensorNode_R001214_1413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quantum_31_1 = 0;
  int quantum_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_31_1 = ((quantum_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_31_2 = ((quantum_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_31_1) & 127;
    acc_2 = (acc_2 + quantum_31_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_78_1) & 63;
  aux_2 = (aux_2 + weight_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_85_1)
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

  switch (stride_85_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_31_1 == quantum_31_2);
  assert(weight_78_1 == weight_78_2);
  assert(stride_85_1 == stride_85_2);
}

int fn_R001214_1413_4(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001214_1413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quantum_31 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_31 = ((quantum_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_31) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_78) & 63;
  acc ^= aux;
  int stride_85 = (aux + st.buffer[1]) & 3;
  switch (stride_85)
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

void fn_R001214_1413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001214_1413_1 st_1 = {0};
  struct DeviceConfig_R001214_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_57_1 = local_arr_1[aux_1 % 3];
  int cursor_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_57_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_64_1)
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

  switch (segment_64_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_57_1 == cursor_57_2);
  assert(segment_64_1 == segment_64_2);
}

int fn_R001214_1413_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001214_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int cursor_57 = local_arr[aux % 3];
  acc = (acc + (cursor_57 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_64 = (aux + st.buffer[1]) & 3;
  switch (segment_64)
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

void fn_R001214_1413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001214_1413_1 st_1 = {0};
  struct DeviceConfig_R001214_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_51_1 = 0;
  int metric_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_51_1 = ((metric_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_51_2 = ((metric_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_51_1) & 127;
    acc_2 = (acc_2 + metric_51_2) & 127;
  }

  int bound_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_66_1)
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

  switch (bound_66_2)
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

  int offset_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_15_1) & 63;
  aux_2 = (aux_2 + offset_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_51_1 == metric_51_2);
  assert(bound_66_1 == bound_66_2);
  assert(offset_15_1 == offset_15_2);
}

int fn_R001214_1413_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001214_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_51 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_51 = ((metric_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_51) & 127;
  }

  int bound_66 = (aux + st.buffer[1]) & 3;
  switch (bound_66)
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

  int offset_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001214_1413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001214_1413_3 st_1 = {0};
  struct SensorNode_R001214_1413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_81_1 = local_arr_1[aux_1 % 3];
  int offset_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_81_2 * 2)) & 127;
  int bound_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_35_1 > 24)
  {
    acc_1 = ((acc_1 + (bound_35_1 * 2)) + 5) & 127;
    aux_1 ^= bound_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_35_2 > 24)
  {
    acc_2 = ((acc_2 + (bound_35_2 * 2)) + 5) & 127;
    aux_2 ^= bound_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_21_1 = 0;
  int vector_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_21_1 = ((vector_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_21_2 = ((vector_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_21_1) & 127;
    acc_2 = (acc_2 + vector_21_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_81_1 == offset_81_2);
  assert(bound_35_1 == bound_35_2);
  assert(vector_21_1 == vector_21_2);
}

int fn_R001214_1413_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001214_1413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int offset_81 = local_arr[aux % 3];
  acc = (acc + (offset_81 * 2)) & 127;
  int bound_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_35 > 24)
  {
    acc = ((acc + (bound_35 * 2)) + 5) & 127;
    aux ^= bound_35 & 15;
  }
  else
  {
    acc = ((acc - bound_35) + 11) & 127;
    aux += 3;
  }
  int vector_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_21 = ((vector_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_21) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001214_1413_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001214_1413_3 st_1 = {0};
  struct SensorNode_R001214_1413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_67_1 = local_arr_1[aux_1 % 3];
  int quantum_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_67_2 * 2)) & 127;
  int window_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_19_1)
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

  switch (window_19_2)
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

  int threshold_69_1 = 0;
  int threshold_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_69_1 = ((threshold_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_69_2 = ((threshold_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_69_1) & 127;
    acc_2 = (acc_2 + threshold_69_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_67_1 == quantum_67_2);
  assert(window_19_1 == window_19_2);
  assert(threshold_69_1 == threshold_69_2);
}

int fn_R001214_1413_8(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001214_1413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int quantum_67 = local_arr[aux % 3];
  acc = (acc + (quantum_67 * 2)) & 127;
  int window_19 = (aux + st.buffer[1]) & 3;
  switch (window_19)
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

  int threshold_69 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_69 = ((threshold_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_69) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001214_1413_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001214_1413_1 st_1 = {0};
  struct DeviceConfig_R001214_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_87_1 = 0;
  int checksum_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_87_1 = ((checksum_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_87_2 = ((checksum_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_87_1) & 127;
    acc_2 = (acc_2 + checksum_87_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_26_1 = local_arr_1[aux_1 % 3];
  int sample_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_26_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_87_1 == checksum_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_26_1 == sample_26_2);
}

int fn_R001214_1413_9(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001214_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_87 = ((checksum_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_87) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_26 = local_arr[aux % 3];
  acc = (acc + (sample_26 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001214_1413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001214_1413_0 st_1 = {0};
  struct FilterState_R001214_1413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_51_1) & 63;
  aux_2 = (aux_2 + metric_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_85_1 = 0;
  int cursor_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_85_1 = ((cursor_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_85_2 = ((cursor_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_85_1) & 127;
    acc_2 = (acc_2 + cursor_85_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_79_1)
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

  switch (coefficient_79_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_51_1 == metric_51_2);
  assert(cursor_85_1 == cursor_85_2);
  assert(coefficient_79_1 == coefficient_79_2);
}

int fn_R001214_1413_10(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001214_1413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_51) & 63;
  acc ^= aux;
  int cursor_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_85 = ((cursor_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_85) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_79 = (aux + st.buffer[1]) & 3;
  switch (coefficient_79)
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

void fn_R001214_1413_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001214_1413_2 st_1 = {0};
  struct StreamBuffer_R001214_1413_2 st_2 = {0};
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
  int tally_40_1 = 0;
  int tally_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_40_1 = ((tally_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_40_2 = ((tally_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_40_1) & 127;
    acc_2 = (acc_2 + tally_40_2) & 127;
  }

  int anchor_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_68_1) & 63;
  aux_2 = (aux_2 + anchor_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_38_1 = local_arr_1[aux_1 % 3];
  int cursor_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_38_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_40_1 == tally_40_2);
  assert(anchor_68_1 == anchor_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_38_1 == cursor_38_2);
}

int fn_R001214_1413_11(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001214_1413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_40 = ((tally_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_40) & 127;
  }

  int anchor_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_68) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_38 = local_arr[aux % 3];
  acc = (acc + (cursor_38 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001214_1413_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001214_1413_3 st_1 = {0};
  struct SensorNode_R001214_1413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int bound_60_1 = 0;
  int bound_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_60_1 = ((bound_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_60_2 = ((bound_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_60_1) & 127;
    acc_2 = (acc_2 + bound_60_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_79_1 = local_arr_1[aux_1 % 3];
  int quotient_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_79_2 * 2)) & 127;
  int window_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_53_1 > 46)
  {
    acc_1 = ((acc_1 + (window_53_1 * 2)) + 5) & 127;
    aux_1 ^= window_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_53_2 > 46)
  {
    acc_2 = ((acc_2 + (window_53_2 * 2)) + 5) & 127;
    aux_2 ^= window_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_60_1 == bound_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_79_1 == quotient_79_2);
  assert(window_53_1 == window_53_2);
}

int fn_R001214_1413_12(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001214_1413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int bound_60 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_60 = ((bound_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_60) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_79 = local_arr[aux % 3];
  acc = (acc + (quotient_79 * 2)) & 127;
  int window_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_53 > 46)
  {
    acc = ((acc + (window_53 * 2)) + 5) & 127;
    aux ^= window_53 & 15;
  }
  else
  {
    acc = ((acc - window_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001214_1413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001214_1413_1 st_1 = {0};
  struct DeviceConfig_R001214_1413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_72_1) & 63;
  aux_2 = (aux_2 + index_reg_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_85_1 > 48)
  {
    acc_1 = ((acc_1 + (scale_85_1 * 2)) + 5) & 127;
    aux_1 ^= scale_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_85_2 > 48)
  {
    acc_2 = ((acc_2 + (scale_85_2 * 2)) + 5) & 127;
    aux_2 ^= scale_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_72_1 == index_reg_72_2);
  assert(scale_85_1 == scale_85_2);
}

int fn_R001214_1413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001214_1413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_72) & 63;
  acc ^= aux;
  int scale_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_85 > 48)
  {
    acc = ((acc + (scale_85 * 2)) + 5) & 127;
    aux ^= scale_85 & 15;
  }
  else
  {
    acc = ((acc - scale_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001214_0_1;
  int sec_r001214_0_2;
  int sec_r001214_1_1;
  int sec_r001214_1_2;
  int sec_r001214_2_1;
  int sec_r001214_2_2;
  int sec_r001214_3_1;
  int sec_r001214_3_2;
  int sec_r001214_4_1;
  int sec_r001214_4_2;
  int sec_r001214_5_1;
  int sec_r001214_5_2;
  int sec_r001214_6_1;
  int sec_r001214_6_2;
  int sec_r001214_7_1;
  int sec_r001214_7_2;
  int sec_r001214_8_1;
  int sec_r001214_8_2;
  int sec_r001214_9_1;
  int sec_r001214_9_2;
  int sec_r001214_10_1;
  int sec_r001214_10_2;
  int sec_r001214_11_1;
  int sec_r001214_11_2;
  int sec_r001214_12_1;
  int sec_r001214_12_2;
  int sec_r001214_13_1;
  int sec_r001214_13_2;
  int sec_r001214_14_1;
  int sec_r001214_14_2;
  int sec_r001214_15_1;
  int sec_r001214_15_2;
  int sec_r001214_16_1;
  int sec_r001214_16_2;
  int sec_r001214_17_1;
  int sec_r001214_17_2;
  int sec_r001214_18_1;
  int sec_r001214_18_2;
  int sec_r001214_19_1;
  int sec_r001214_19_2;
  int sec_r001214_20_1;
  int sec_r001214_20_2;
  int pub_r001214_0_1;
  int pub_r001214_0_2;
  int pub_r001214_1_1;
  int pub_r001214_1_2;
  int pub_r001214_2_1;
  int pub_r001214_2_2;
  int pub_r001214_3_1;
  int pub_r001214_3_2;
  int pub_r001214_4_1;
  int pub_r001214_4_2;
  int pub_r001214_5_1;
  int pub_r001214_5_2;
  int pub_r001214_6_1;
  int pub_r001214_6_2;
  int pub_r001214_7_1;
  int pub_r001214_7_2;
  int pub_r001214_8_1;
  int pub_r001214_8_2;
  int pub_r001214_9_1;
  int pub_r001214_9_2;
  int pub_r001214_10_1;
  int pub_r001214_10_2;
  int pub_r001214_11_1;
  int pub_r001214_11_2;
  int pub_r001214_12_1;
  int pub_r001214_12_2;
  int pub_r001214_13_1;
  int pub_r001214_13_2;
  int pub_r001214_14_1;
  int pub_r001214_14_2;
  int pub_r001214_15_1;
  int pub_r001214_15_2;
  int pub_r001214_16_1;
  int pub_r001214_16_2;
  int pub_r001214_17_1;
  int pub_r001214_17_2;
  int pub_r001214_18_1;
  int pub_r001214_18_2;
  int pub_r001214_19_1;
  int pub_r001214_19_2;
  int pub_r001214_20_1;
  int pub_r001214_20_2;
  int pub_r001214_21_1;
  int pub_r001214_21_2;
  int pub_r001214_22_1;
  int pub_r001214_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001214_0_1 >= (-100)) && (pub_r001214_0_1 <= 100));
  __CPROVER_assume((pub_r001214_0_2 >= (-100)) && (pub_r001214_0_2 <= 100));
  __CPROVER_assume((pub_r001214_1_1 >= (-100)) && (pub_r001214_1_1 <= 100));
  __CPROVER_assume((pub_r001214_1_2 >= (-100)) && (pub_r001214_1_2 <= 100));
  __CPROVER_assume((pub_r001214_2_1 >= (-100)) && (pub_r001214_2_1 <= 100));
  __CPROVER_assume((pub_r001214_2_2 >= (-100)) && (pub_r001214_2_2 <= 100));
  __CPROVER_assume((pub_r001214_3_1 >= (-100)) && (pub_r001214_3_1 <= 100));
  __CPROVER_assume((pub_r001214_3_2 >= (-100)) && (pub_r001214_3_2 <= 100));
  __CPROVER_assume((pub_r001214_4_1 >= (-100)) && (pub_r001214_4_1 <= 100));
  __CPROVER_assume((pub_r001214_4_2 >= (-100)) && (pub_r001214_4_2 <= 100));
  __CPROVER_assume((pub_r001214_5_1 >= (-100)) && (pub_r001214_5_1 <= 100));
  __CPROVER_assume((pub_r001214_5_2 >= (-100)) && (pub_r001214_5_2 <= 100));
  __CPROVER_assume((pub_r001214_6_1 >= (-100)) && (pub_r001214_6_1 <= 100));
  __CPROVER_assume((pub_r001214_6_2 >= (-100)) && (pub_r001214_6_2 <= 100));
  __CPROVER_assume((pub_r001214_7_1 >= (-100)) && (pub_r001214_7_1 <= 100));
  __CPROVER_assume((pub_r001214_7_2 >= (-100)) && (pub_r001214_7_2 <= 100));
  __CPROVER_assume((pub_r001214_8_1 >= (-100)) && (pub_r001214_8_1 <= 100));
  __CPROVER_assume((pub_r001214_8_2 >= (-100)) && (pub_r001214_8_2 <= 100));
  __CPROVER_assume((pub_r001214_9_1 >= (-100)) && (pub_r001214_9_1 <= 100));
  __CPROVER_assume((pub_r001214_9_2 >= (-100)) && (pub_r001214_9_2 <= 100));
  __CPROVER_assume((pub_r001214_10_1 >= (-100)) && (pub_r001214_10_1 <= 100));
  __CPROVER_assume((pub_r001214_10_2 >= (-100)) && (pub_r001214_10_2 <= 100));
  __CPROVER_assume((pub_r001214_11_1 >= (-100)) && (pub_r001214_11_1 <= 100));
  __CPROVER_assume((pub_r001214_11_2 >= (-100)) && (pub_r001214_11_2 <= 100));
  __CPROVER_assume((pub_r001214_12_1 >= (-100)) && (pub_r001214_12_1 <= 100));
  __CPROVER_assume((pub_r001214_12_2 >= (-100)) && (pub_r001214_12_2 <= 100));
  __CPROVER_assume((pub_r001214_13_1 >= (-100)) && (pub_r001214_13_1 <= 100));
  __CPROVER_assume((pub_r001214_13_2 >= (-100)) && (pub_r001214_13_2 <= 100));
  __CPROVER_assume((pub_r001214_14_1 >= (-100)) && (pub_r001214_14_1 <= 100));
  __CPROVER_assume((pub_r001214_14_2 >= (-100)) && (pub_r001214_14_2 <= 100));
  __CPROVER_assume((pub_r001214_15_1 >= (-100)) && (pub_r001214_15_1 <= 100));
  __CPROVER_assume((pub_r001214_15_2 >= (-100)) && (pub_r001214_15_2 <= 100));
  __CPROVER_assume((pub_r001214_16_1 >= (-100)) && (pub_r001214_16_1 <= 100));
  __CPROVER_assume((pub_r001214_16_2 >= (-100)) && (pub_r001214_16_2 <= 100));
  __CPROVER_assume((pub_r001214_17_1 >= (-100)) && (pub_r001214_17_1 <= 100));
  __CPROVER_assume((pub_r001214_17_2 >= (-100)) && (pub_r001214_17_2 <= 100));
  __CPROVER_assume((pub_r001214_18_1 >= (-100)) && (pub_r001214_18_1 <= 100));
  __CPROVER_assume((pub_r001214_18_2 >= (-100)) && (pub_r001214_18_2 <= 100));
  __CPROVER_assume((pub_r001214_19_1 >= (-100)) && (pub_r001214_19_1 <= 100));
  __CPROVER_assume((pub_r001214_19_2 >= (-100)) && (pub_r001214_19_2 <= 100));
  __CPROVER_assume((pub_r001214_20_1 >= (-100)) && (pub_r001214_20_1 <= 100));
  __CPROVER_assume((pub_r001214_20_2 >= (-100)) && (pub_r001214_20_2 <= 100));
  __CPROVER_assume((pub_r001214_21_1 >= (-100)) && (pub_r001214_21_1 <= 100));
  __CPROVER_assume((pub_r001214_21_2 >= (-100)) && (pub_r001214_21_2 <= 100));
  __CPROVER_assume((pub_r001214_22_1 >= (-100)) && (pub_r001214_22_1 <= 100));
  __CPROVER_assume((pub_r001214_22_2 >= (-100)) && (pub_r001214_22_2 <= 100));
  __CPROVER_assume((sec_r001214_0_1 >= 0) && (sec_r001214_0_1 <= 255));
  __CPROVER_assume((sec_r001214_0_2 >= 0) && (sec_r001214_0_2 <= 255));
  __CPROVER_assume((sec_r001214_1_1 >= 0) && (sec_r001214_1_1 <= 255));
  __CPROVER_assume((sec_r001214_1_2 >= 0) && (sec_r001214_1_2 <= 255));
  __CPROVER_assume((sec_r001214_2_1 >= 0) && (sec_r001214_2_1 <= 255));
  __CPROVER_assume((sec_r001214_2_2 >= 0) && (sec_r001214_2_2 <= 255));
  __CPROVER_assume((sec_r001214_3_1 >= 0) && (sec_r001214_3_1 <= 255));
  __CPROVER_assume((sec_r001214_3_2 >= 0) && (sec_r001214_3_2 <= 255));
  __CPROVER_assume((sec_r001214_4_1 >= 0) && (sec_r001214_4_1 <= 255));
  __CPROVER_assume((sec_r001214_4_2 >= 0) && (sec_r001214_4_2 <= 255));
  __CPROVER_assume((sec_r001214_5_1 >= 0) && (sec_r001214_5_1 <= 255));
  __CPROVER_assume((sec_r001214_5_2 >= 0) && (sec_r001214_5_2 <= 255));
  __CPROVER_assume((sec_r001214_6_1 >= 0) && (sec_r001214_6_1 <= 255));
  __CPROVER_assume((sec_r001214_6_2 >= 0) && (sec_r001214_6_2 <= 255));
  __CPROVER_assume((sec_r001214_7_1 >= 0) && (sec_r001214_7_1 <= 255));
  __CPROVER_assume((sec_r001214_7_2 >= 0) && (sec_r001214_7_2 <= 255));
  __CPROVER_assume((sec_r001214_8_1 >= 0) && (sec_r001214_8_1 <= 255));
  __CPROVER_assume((sec_r001214_8_2 >= 0) && (sec_r001214_8_2 <= 255));
  __CPROVER_assume((sec_r001214_9_1 >= 0) && (sec_r001214_9_1 <= 255));
  __CPROVER_assume((sec_r001214_9_2 >= 0) && (sec_r001214_9_2 <= 255));
  __CPROVER_assume((sec_r001214_10_1 >= 0) && (sec_r001214_10_1 <= 255));
  __CPROVER_assume((sec_r001214_10_2 >= 0) && (sec_r001214_10_2 <= 255));
  __CPROVER_assume((sec_r001214_11_1 >= 0) && (sec_r001214_11_1 <= 255));
  __CPROVER_assume((sec_r001214_11_2 >= 0) && (sec_r001214_11_2 <= 255));
  __CPROVER_assume((sec_r001214_12_1 >= 0) && (sec_r001214_12_1 <= 255));
  __CPROVER_assume((sec_r001214_12_2 >= 0) && (sec_r001214_12_2 <= 255));
  __CPROVER_assume((sec_r001214_13_1 >= 0) && (sec_r001214_13_1 <= 255));
  __CPROVER_assume((sec_r001214_13_2 >= 0) && (sec_r001214_13_2 <= 255));
  __CPROVER_assume((sec_r001214_14_1 >= 0) && (sec_r001214_14_1 <= 255));
  __CPROVER_assume((sec_r001214_14_2 >= 0) && (sec_r001214_14_2 <= 255));
  __CPROVER_assume((sec_r001214_15_1 >= 0) && (sec_r001214_15_1 <= 255));
  __CPROVER_assume((sec_r001214_15_2 >= 0) && (sec_r001214_15_2 <= 255));
  __CPROVER_assume((sec_r001214_16_1 >= 0) && (sec_r001214_16_1 <= 255));
  __CPROVER_assume((sec_r001214_16_2 >= 0) && (sec_r001214_16_2 <= 255));
  __CPROVER_assume((sec_r001214_17_1 >= 0) && (sec_r001214_17_1 <= 255));
  __CPROVER_assume((sec_r001214_17_2 >= 0) && (sec_r001214_17_2 <= 255));
  __CPROVER_assume((sec_r001214_18_1 >= 0) && (sec_r001214_18_1 <= 255));
  __CPROVER_assume((sec_r001214_18_2 >= 0) && (sec_r001214_18_2 <= 255));
  __CPROVER_assume((sec_r001214_19_1 >= 0) && (sec_r001214_19_1 <= 255));
  __CPROVER_assume((sec_r001214_19_2 >= 0) && (sec_r001214_19_2 <= 255));
  __CPROVER_assume((sec_r001214_20_1 >= 0) && (sec_r001214_20_1 <= 255));
  __CPROVER_assume((sec_r001214_20_2 >= 0) && (sec_r001214_20_2 <= 255));
  struct FilterState_R001214_1413_0 st_var_0_1 = {0};
  struct FilterState_R001214_1413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001214_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001214_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001214_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001214_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001214_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001214_0_2 + 7) & 15;
  struct DeviceConfig_R001214_1413_1 st_var_1_1 = {0};
  struct DeviceConfig_R001214_1413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001214_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001214_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001214_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001214_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001214_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001214_0_2 + 9) & 15;
  struct StreamBuffer_R001214_1413_2 st_var_2_1 = {0};
  struct StreamBuffer_R001214_1413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001214_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001214_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001214_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001214_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001214_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001214_0_2 + 11) & 15;
  struct SensorNode_R001214_1413_3 st_var_3_1 = {0};
  struct SensorNode_R001214_1413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001214_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001214_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001214_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001214_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001214_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001214_0_2 + 13) & 15;
  union TelemetryField_R001214_1413_0 u_var_1;
  union TelemetryField_R001214_1413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001214_1413_0(sec_r001214_0_1, pub_r001214_1_1, pub_r001214_2_1, pub_r001214_3_1);
  int helper_flow_0_2 = fn_R001214_1413_0(sec_r001214_0_2, pub_r001214_1_2, pub_r001214_2_2, pub_r001214_3_2);
  fn_R001214_1413_0_2(sec_r001214_0_1, pub_r001214_1_1, pub_r001214_2_1, pub_r001214_3_1, sec_r001214_0_2, pub_r001214_1_2, pub_r001214_2_2, pub_r001214_3_2);
  int helper_flow_1_1 = fn_R001214_1413_1(sec_r001214_1_1, sec_r001214_2_1, pub_r001214_3_1, pub_r001214_4_1, pub_r001214_5_1);
  int helper_flow_1_2 = fn_R001214_1413_1(sec_r001214_1_2, sec_r001214_2_2, pub_r001214_3_2, pub_r001214_4_2, pub_r001214_5_2);
  fn_R001214_1413_1_2(sec_r001214_1_1, sec_r001214_2_1, pub_r001214_3_1, pub_r001214_4_1, pub_r001214_5_1, sec_r001214_1_2, sec_r001214_2_2, pub_r001214_3_2, pub_r001214_4_2, pub_r001214_5_2);
  int helper_flow_2_1 = fn_R001214_1413_2(sec_r001214_2_1, pub_r001214_3_1, pub_r001214_4_1);
  int helper_flow_2_2 = fn_R001214_1413_2(sec_r001214_2_2, pub_r001214_3_2, pub_r001214_4_2);
  fn_R001214_1413_2_2(sec_r001214_2_1, pub_r001214_3_1, pub_r001214_4_1, sec_r001214_2_2, pub_r001214_3_2, pub_r001214_4_2);
  int helper_flow_3_1 = fn_R001214_1413_3(sec_r001214_3_1, sec_r001214_4_1, pub_r001214_5_1);
  int helper_flow_3_2 = fn_R001214_1413_3(sec_r001214_3_2, sec_r001214_4_2, pub_r001214_5_2);
  fn_R001214_1413_3_2(sec_r001214_3_1, sec_r001214_4_1, pub_r001214_5_1, sec_r001214_3_2, sec_r001214_4_2, pub_r001214_5_2);
  int helper_flow_4_1 = fn_R001214_1413_4(sec_r001214_4_1, sec_r001214_5_1, pub_r001214_6_1);
  int helper_flow_4_2 = fn_R001214_1413_4(sec_r001214_4_2, sec_r001214_5_2, pub_r001214_6_2);
  fn_R001214_1413_4_2(sec_r001214_4_1, sec_r001214_5_1, pub_r001214_6_1, sec_r001214_4_2, sec_r001214_5_2, pub_r001214_6_2);
  int helper_flow_5_1 = fn_R001214_1413_5(sec_r001214_5_1, pub_r001214_6_1, pub_r001214_7_1, pub_r001214_8_1);
  int helper_flow_5_2 = fn_R001214_1413_5(sec_r001214_5_2, pub_r001214_6_2, pub_r001214_7_2, pub_r001214_8_2);
  fn_R001214_1413_5_2(sec_r001214_5_1, pub_r001214_6_1, pub_r001214_7_1, pub_r001214_8_1, sec_r001214_5_2, pub_r001214_6_2, pub_r001214_7_2, pub_r001214_8_2);
  int helper_flow_6_1 = fn_R001214_1413_6(sec_r001214_6_1, pub_r001214_7_1, pub_r001214_8_1, pub_r001214_9_1, pub_r001214_10_1);
  int helper_flow_6_2 = fn_R001214_1413_6(sec_r001214_6_2, pub_r001214_7_2, pub_r001214_8_2, pub_r001214_9_2, pub_r001214_10_2);
  fn_R001214_1413_6_2(sec_r001214_6_1, pub_r001214_7_1, pub_r001214_8_1, pub_r001214_9_1, pub_r001214_10_1, sec_r001214_6_2, pub_r001214_7_2, pub_r001214_8_2, pub_r001214_9_2, pub_r001214_10_2);
  int helper_flow_7_1 = fn_R001214_1413_7(sec_r001214_7_1, pub_r001214_8_1, pub_r001214_9_1, pub_r001214_10_1);
  int helper_flow_7_2 = fn_R001214_1413_7(sec_r001214_7_2, pub_r001214_8_2, pub_r001214_9_2, pub_r001214_10_2);
  fn_R001214_1413_7_2(sec_r001214_7_1, pub_r001214_8_1, pub_r001214_9_1, pub_r001214_10_1, sec_r001214_7_2, pub_r001214_8_2, pub_r001214_9_2, pub_r001214_10_2);
  int helper_flow_8_1 = fn_R001214_1413_8(sec_r001214_8_1, pub_r001214_9_1, pub_r001214_10_1);
  int helper_flow_8_2 = fn_R001214_1413_8(sec_r001214_8_2, pub_r001214_9_2, pub_r001214_10_2);
  fn_R001214_1413_8_2(sec_r001214_8_1, pub_r001214_9_1, pub_r001214_10_1, sec_r001214_8_2, pub_r001214_9_2, pub_r001214_10_2);
  int stage_v_0_1 = (((sec_r001214_15_1 * 3) + pub_r001214_21_1) + 31) & 127;
  int stage_v_0_2 = (((sec_r001214_15_2 * 3) + pub_r001214_21_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = ((pub_r001214_17_1 * 2) + 39) & 63;
  int stage_v_1_2 = ((pub_r001214_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001214_10_1 * 2) + 18) & 63;
  int stage_v_2_2 = ((pub_r001214_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((helper_flow_0_1 * 3) + pub_r001214_16_1) + 44) & 127;
  int stage_v_3_2 = (((helper_flow_0_2 * 3) + pub_r001214_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((sec_r001214_5_1 * 3) + pub_r001214_21_1) + 39) & 127;
  int stage_v_4_2 = (((sec_r001214_5_2 * 3) + pub_r001214_21_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001214_0_1 * 2) + 19) & 63;
  int stage_v_5_2 = ((pub_r001214_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((sec_r001214_5_1 * 3) + pub_r001214_21_1) + 14) & 127;
  int stage_v_6_2 = (((sec_r001214_5_2 * 3) + pub_r001214_21_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = (((stage_v_6_1 * 3) + pub_r001214_18_1) + 25) & 127;
  int stage_v_7_2 = (((stage_v_6_2 * 3) + pub_r001214_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001214_10_1 * 2) + 18) & 63;
  int stage_v_8_2 = ((pub_r001214_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001214_2_1 * 2) + 35) & 63;
  int stage_v_9_2 = ((pub_r001214_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((stage_v_6_1 * 3) + pub_r001214_11_1) + 9) & 127;
  int stage_v_10_2 = (((stage_v_6_2 * 3) + pub_r001214_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((sec_r001214_19_1 * 3) + pub_r001214_19_1) + 16) & 127;
  int stage_v_11_2 = (((sec_r001214_19_2 * 3) + pub_r001214_19_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = ((pub_r001214_4_1 * 2) + 16) & 63;
  int stage_v_12_2 = ((pub_r001214_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001214_7_1 * 2) + 15) & 63;
  int stage_v_13_2 = ((pub_r001214_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001214_12_1 * 3) + pub_r001214_6_1) + 7) & 127;
  int stage_v_14_2 = (((sec_r001214_12_2 * 3) + pub_r001214_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = ((pub_r001214_10_1 * 2) + 12) & 63;
  int stage_v_15_2 = ((pub_r001214_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001214_17_1 * 3) + pub_r001214_14_1) + 38) & 127;
  int stage_v_16_2 = (((sec_r001214_17_2 * 3) + pub_r001214_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((sec_r001214_18_1 * 3) + pub_r001214_21_1) + 34) & 127;
  int stage_v_17_2 = (((sec_r001214_18_2 * 3) + pub_r001214_21_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((sec_r001214_11_1 * 3) + pub_r001214_14_1) + 26) & 127;
  int stage_v_18_2 = (((sec_r001214_11_2 * 3) + pub_r001214_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = (((sec_r001214_13_1 * 3) + pub_r001214_9_1) + 22) & 127;
  int stage_v_19_2 = (((sec_r001214_13_2 * 3) + pub_r001214_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = (((sec_r001214_17_1 * 3) + pub_r001214_1_1) + 34) & 127;
  int stage_v_20_2 = (((sec_r001214_17_2 * 3) + pub_r001214_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001214_17_1 * 2) + 14) & 63;
  int stage_v_21_2 = ((pub_r001214_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((sec_r001214_14_1 * 3) + pub_r001214_8_1) + 3) & 127;
  int stage_v_22_2 = (((sec_r001214_14_2 * 3) + pub_r001214_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001214_6_1 * 2) + 8) & 63;
  int stage_v_23_2 = ((pub_r001214_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((sec_r001214_19_1 * 3) + pub_r001214_8_1) + 20) & 127;
  int stage_v_24_2 = (((sec_r001214_19_2 * 3) + pub_r001214_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001214_15_1 * 2) + 12) & 63;
  int stage_v_25_2 = ((pub_r001214_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001214_18_1 * 2) + 24) & 63;
  int stage_v_26_2 = ((pub_r001214_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001214_8_1 * 2) + 39) & 63;
  int stage_v_27_2 = ((pub_r001214_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001214_4_1 * 2) + 9) & 63;
  int stage_v_28_2 = ((pub_r001214_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001214_16_1 * 2) + 5) & 63;
  int stage_v_29_2 = ((pub_r001214_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001214_2_1 * 3) + pub_r001214_15_1) + 17) & 127;
  int stage_v_30_2 = (((sec_r001214_2_2 * 3) + pub_r001214_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001214_19_1 * 2) + 22) & 63;
  int stage_v_31_2 = ((pub_r001214_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001214_19_1 * 2) + 7) & 63;
  int stage_v_32_2 = ((pub_r001214_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((sec_r001214_5_1 * 3) + pub_r001214_11_1) + 44) & 127;
  int stage_v_33_2 = (((sec_r001214_5_2 * 3) + pub_r001214_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((sec_r001214_19_1 * 3) + pub_r001214_21_1) + 26) & 127;
  int stage_v_34_2 = (((sec_r001214_19_2 * 3) + pub_r001214_21_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = (((sec_r001214_14_1 * 3) + pub_r001214_20_1) + 19) & 127;
  int stage_v_35_2 = (((sec_r001214_14_2 * 3) + pub_r001214_20_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = (((stage_v_7_1 * 3) + pub_r001214_20_1) + 40) & 127;
  int stage_v_36_2 = (((stage_v_7_2 * 3) + pub_r001214_20_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = (((sec_r001214_11_1 * 3) + pub_r001214_13_1) + 6) & 127;
  int stage_v_37_2 = (((sec_r001214_11_2 * 3) + pub_r001214_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = (((sec_r001214_16_1 * 3) + pub_r001214_1_1) + 36) & 127;
  int stage_v_38_2 = (((sec_r001214_16_2 * 3) + pub_r001214_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001214_4_1 * 2) + 42) & 63;
  int stage_v_39_2 = ((pub_r001214_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((sec_r001214_8_1 * 3) + pub_r001214_20_1) + 24) & 127;
  int stage_v_40_2 = (((sec_r001214_8_2 * 3) + pub_r001214_20_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((sec_r001214_2_1 * 3) + pub_r001214_9_1) + 26) & 127;
  int stage_v_41_2 = (((sec_r001214_2_2 * 3) + pub_r001214_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = (((sec_r001214_17_1 * 3) + pub_r001214_19_1) + 29) & 127;
  int stage_v_42_2 = (((sec_r001214_17_2 * 3) + pub_r001214_19_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = ((pub_r001214_4_1 * 2) + 12) & 63;
  int stage_v_43_2 = ((pub_r001214_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((stage_v_14_1 * 3) + pub_r001214_20_1) + 19) & 127;
  int stage_v_44_2 = (((stage_v_14_2 * 3) + pub_r001214_20_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = (((helper_flow_8_1 * 3) + pub_r001214_18_1) + 38) & 127;
  int stage_v_45_2 = (((helper_flow_8_2 * 3) + pub_r001214_18_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((sec_r001214_3_1 * 3) + pub_r001214_20_1) + 19) & 127;
  int stage_v_46_2 = (((sec_r001214_3_2 * 3) + pub_r001214_20_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001214_15_1 * 2) + 19) & 63;
  int stage_v_47_2 = ((pub_r001214_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001214_6_1 * 2) + 36) & 63;
  int stage_v_48_2 = ((pub_r001214_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001214_20_1 * 2) + 50) & 63;
  int stage_v_49_2 = ((pub_r001214_20_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((sec_r001214_19_1 * 3) + pub_r001214_4_1) + 37) & 127;
  int stage_v_50_2 = (((sec_r001214_19_2 * 3) + pub_r001214_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001214_12_1 * 2) + 16) & 63;
  int stage_v_51_2 = ((pub_r001214_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001214_9_1 * 2) + 42) & 63;
  int stage_v_52_2 = ((pub_r001214_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((stage_v_20_1 * 3) + pub_r001214_16_1) + 32) & 127;
  int stage_v_53_2 = (((stage_v_20_2 * 3) + pub_r001214_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = (((sec_r001214_6_1 * 3) + pub_r001214_17_1) + 35) & 127;
  int stage_v_54_2 = (((sec_r001214_6_2 * 3) + pub_r001214_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((sec_r001214_6_1 * 3) + pub_r001214_21_1) + 23) & 127;
  int stage_v_55_2 = (((sec_r001214_6_2 * 3) + pub_r001214_21_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((sec_r001214_1_1 * 3) + pub_r001214_21_1) + 43) & 127;
  int stage_v_56_2 = (((sec_r001214_1_2 * 3) + pub_r001214_21_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((stage_v_53_1 * 3) + pub_r001214_6_1) + 17) & 127;
  int stage_v_57_2 = (((stage_v_53_2 * 3) + pub_r001214_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = ((pub_r001214_14_1 * 2) + 21) & 63;
  int stage_v_58_2 = ((pub_r001214_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001214_0_1 * 2) + 30) & 63;
  int stage_v_59_2 = ((pub_r001214_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001214_19_1 * 2) + 21) & 63;
  int stage_v_60_2 = ((pub_r001214_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001214_22_1 * 2) + 41) & 63;
  int stage_v_61_2 = ((pub_r001214_22_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001214_6_1 * 2) + 10) & 63;
  int stage_v_62_2 = ((pub_r001214_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_4_1 * 3) + pub_r001214_22_1) + 42) & 127;
  int stage_v_63_2 = (((stage_v_4_2 * 3) + pub_r001214_22_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((sec_r001214_0_1 * 3) + pub_r001214_1_1) + 44) & 127;
  int stage_v_64_2 = (((sec_r001214_0_2 * 3) + pub_r001214_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((stage_v_33_1 * 3) + pub_r001214_6_1) + 3) & 127;
  int stage_v_65_2 = (((stage_v_33_2 * 3) + pub_r001214_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001214_7_1 * 2) + 39) & 63;
  int stage_v_66_2 = ((pub_r001214_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001214_19_1 * 2) + 45) & 63;
  int stage_v_67_2 = ((pub_r001214_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001214_2_1 * 2) + 12) & 63;
  int stage_v_68_2 = ((pub_r001214_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001214_4_1 * 2) + 41) & 63;
  int stage_v_69_2 = ((pub_r001214_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001214_8_1 * 2) + 35) & 63;
  int stage_v_70_2 = ((pub_r001214_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001214_9_1 * 2) + 45) & 63;
  int stage_v_71_2 = ((pub_r001214_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001214_5_1 * 2) + 7) & 63;
  int stage_v_72_2 = ((pub_r001214_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001214_21_1 * 2) + 34) & 63;
  int stage_v_73_2 = ((pub_r001214_21_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((stage_v_64_1 * 3) + pub_r001214_7_1) + 20) & 127;
  int stage_v_74_2 = (((stage_v_64_2 * 3) + pub_r001214_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((stage_v_10_1 * 3) + pub_r001214_11_1) + 27) & 127;
  int stage_v_75_2 = (((stage_v_10_2 * 3) + pub_r001214_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((stage_v_74_1 * 3) + pub_r001214_21_1) + 21) & 127;
  int stage_v_76_2 = (((stage_v_74_2 * 3) + pub_r001214_21_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001214_18_1 * 2) + 47) & 63;
  int stage_v_77_2 = ((pub_r001214_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001214_13_1 * 2) + 17) & 63;
  int stage_v_78_2 = ((pub_r001214_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001214_21_1 * 2) + 31) & 63;
  int stage_v_79_2 = ((pub_r001214_21_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((sec_r001214_1_1 * 3) + pub_r001214_17_1) + 23) & 127;
  int stage_v_80_2 = (((sec_r001214_1_2 * 3) + pub_r001214_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = ((pub_r001214_16_1 * 2) + 47) & 63;
  int stage_v_81_2 = ((pub_r001214_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((stage_v_37_1 * 3) + pub_r001214_6_1) + 44) & 127;
  int stage_v_82_2 = (((stage_v_37_2 * 3) + pub_r001214_6_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001214_5_1 * 2) + 37) & 63;
  int stage_v_83_2 = ((pub_r001214_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001214_7_1 * 2) + 7) & 63;
  int stage_v_84_2 = ((pub_r001214_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((stage_v_20_1 * 3) + pub_r001214_13_1) + 28) & 127;
  int stage_v_85_2 = (((stage_v_20_2 * 3) + pub_r001214_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = (((stage_v_65_1 * 3) + pub_r001214_3_1) + 42) & 127;
  int stage_v_86_2 = (((stage_v_65_2 * 3) + pub_r001214_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001214_13_1 * 2) + 31) & 63;
  int stage_v_87_2 = ((pub_r001214_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001214_7_1 * 2) + 32) & 63;
  int stage_v_88_2 = ((pub_r001214_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001214_20_1 * 2) + 39) & 63;
  int stage_v_89_2 = ((pub_r001214_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001214_0_1 * 2) + 22) & 63;
  int stage_v_90_2 = ((pub_r001214_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((sec_r001214_20_1 * 3) + pub_r001214_11_1) + 24) & 127;
  int stage_v_91_2 = (((sec_r001214_20_2 * 3) + pub_r001214_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001214_4_1 * 2) + 7) & 63;
  int stage_v_92_2 = ((pub_r001214_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001214_17_1 * 2) + 18) & 63;
  int stage_v_93_2 = ((pub_r001214_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((helper_flow_3_1 * 3) + pub_r001214_8_1) + 13) & 127;
  int stage_v_94_2 = (((helper_flow_3_2 * 3) + pub_r001214_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = ((pub_r001214_1_1 * 2) + 46) & 63;
  int stage_v_95_2 = ((pub_r001214_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_4_1 * 3) + pub_r001214_17_1) + 33) & 127;
  int stage_v_96_2 = (((stage_v_4_2 * 3) + pub_r001214_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = (((stage_v_24_1 * 3) + pub_r001214_16_1) + 41) & 127;
  int stage_v_97_2 = (((stage_v_24_2 * 3) + pub_r001214_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((stage_v_18_1 * 3) + pub_r001214_9_1) + 6) & 127;
  int stage_v_98_2 = (((stage_v_18_2 * 3) + pub_r001214_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = ((pub_r001214_10_1 * 2) + 30) & 63;
  int stage_v_99_2 = ((pub_r001214_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001214_19_1 * 2) + 48) & 63;
  int stage_v_100_2 = ((pub_r001214_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001214_13_1 * 2) + 46) & 63;
  int stage_v_101_2 = ((pub_r001214_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_18_1 * 3) + pub_r001214_16_1) + 11) & 127;
  int stage_v_102_2 = (((stage_v_18_2 * 3) + pub_r001214_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = (((sec_r001214_8_1 * 3) + pub_r001214_15_1) + 13) & 127;
  int stage_v_103_2 = (((sec_r001214_8_2 * 3) + pub_r001214_15_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = (((stage_v_63_1 * 3) + pub_r001214_16_1) + 3) & 127;
  int stage_v_104_2 = (((stage_v_63_2 * 3) + pub_r001214_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((stage_v_11_1 * 3) + pub_r001214_7_1) + 28) & 127;
  int stage_v_105_2 = (((stage_v_11_2 * 3) + pub_r001214_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = ((pub_r001214_5_1 * 2) + 17) & 63;
  int stage_v_106_2 = ((pub_r001214_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((helper_flow_7_1 * 3) + pub_r001214_7_1) + 14) & 127;
  int stage_v_107_2 = (((helper_flow_7_2 * 3) + pub_r001214_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = ((pub_r001214_18_1 * 2) + 18) & 63;
  int stage_v_108_2 = ((pub_r001214_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001214_10_1 * 2) + 44) & 63;
  int stage_v_109_2 = ((pub_r001214_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001214_16_1 * 2) + 50) & 63;
  int stage_v_110_2 = ((pub_r001214_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((stage_v_10_1 * 3) + pub_r001214_8_1) + 19) & 127;
  int stage_v_111_2 = (((stage_v_10_2 * 3) + pub_r001214_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001214_6_1 * 2) + 45) & 63;
  int stage_v_112_2 = ((pub_r001214_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001214_3_1 * 2) + 34) & 63;
  int stage_v_113_2 = ((pub_r001214_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_35_1 * 3) + pub_r001214_19_1) + 7) & 127;
  int stage_v_114_2 = (((stage_v_35_2 * 3) + pub_r001214_19_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((stage_v_18_1 * 3) + pub_r001214_1_1) + 14) & 127;
  int stage_v_115_2 = (((stage_v_18_2 * 3) + pub_r001214_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = (((stage_v_3_1 * 3) + pub_r001214_6_1) + 7) & 127;
  int stage_v_116_2 = (((stage_v_3_2 * 3) + pub_r001214_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = (((stage_v_30_1 * 3) + pub_r001214_6_1) + 32) & 127;
  int stage_v_117_2 = (((stage_v_30_2 * 3) + pub_r001214_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = ((pub_r001214_10_1 * 2) + 10) & 63;
  int stage_v_118_2 = ((pub_r001214_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001214_13_1 * 2) + 28) & 63;
  int stage_v_119_2 = ((pub_r001214_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001214_2_1 * 2) + 7) & 63;
  int stage_v_120_2 = ((pub_r001214_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001214_22_1 * 2) + 27) & 63;
  int stage_v_121_2 = ((pub_r001214_22_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((sec_r001214_15_1 * 3) + pub_r001214_16_1) + 20) & 127;
  int stage_v_122_2 = (((sec_r001214_15_2 * 3) + pub_r001214_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((helper_flow_8_1 * 3) + pub_r001214_10_1) + 20) & 127;
  int stage_v_123_2 = (((helper_flow_8_2 * 3) + pub_r001214_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = ((pub_r001214_10_1 * 2) + 13) & 63;
  int stage_v_124_2 = ((pub_r001214_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((sec_r001214_13_1 * 3) + pub_r001214_1_1) + 14) & 127;
  int stage_v_125_2 = (((sec_r001214_13_2 * 3) + pub_r001214_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((stage_v_111_1 * 3) + pub_r001214_13_1) + 45) & 127;
  int stage_v_126_2 = (((stage_v_111_2 * 3) + pub_r001214_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((sec_r001214_4_1 * 3) + pub_r001214_8_1) + 32) & 127;
  int stage_v_127_2 = (((sec_r001214_4_2 * 3) + pub_r001214_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_55_1 * 3) + pub_r001214_8_1) + 41) & 127;
  int stage_v_128_2 = (((stage_v_55_2 * 3) + pub_r001214_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_115_1 * 3) + pub_r001214_18_1) + 10) & 127;
  int stage_v_129_2 = (((stage_v_115_2 * 3) + pub_r001214_18_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((stage_v_105_1 * 3) + pub_r001214_9_1) + 34) & 127;
  int stage_v_130_2 = (((stage_v_105_2 * 3) + pub_r001214_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001214_2_1 * 2) + 21) & 63;
  int stage_v_131_2 = ((pub_r001214_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001214_5_1 * 2) + 23) & 63;
  int stage_v_132_2 = ((pub_r001214_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((sec_r001214_15_1 * 3) + pub_r001214_11_1) + 16) & 127;
  int stage_v_133_2 = (((sec_r001214_15_2 * 3) + pub_r001214_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001214_9_1 * 2) + 49) & 63;
  int stage_v_134_2 = ((pub_r001214_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((stage_v_98_1 * 3) + pub_r001214_7_1) + 23) & 127;
  int stage_v_135_2 = (((stage_v_98_2 * 3) + pub_r001214_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001214_4_1 * 2) + 12) & 63;
  int stage_v_136_2 = ((pub_r001214_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((stage_v_3_1 * 3) + pub_r001214_22_1) + 22) & 127;
  int stage_v_137_2 = (((stage_v_3_2 * 3) + pub_r001214_22_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001214_0_1 * 2) + 15) & 63;
  int stage_v_138_2 = ((pub_r001214_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_41_1 * 3) + pub_r001214_22_1) + 42) & 127;
  int stage_v_139_2 = (((stage_v_41_2 * 3) + pub_r001214_22_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((helper_flow_1_1 * 3) + pub_r001214_11_1) + 30) & 127;
  int stage_v_140_2 = (((helper_flow_1_2 * 3) + pub_r001214_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((stage_v_104_1 * 3) + pub_r001214_5_1) + 41) & 127;
  int stage_v_141_2 = (((stage_v_104_2 * 3) + pub_r001214_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_33_1 * 3) + pub_r001214_7_1) + 23) & 127;
  int stage_v_142_2 = (((stage_v_33_2 * 3) + pub_r001214_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((stage_v_38_1 * 3) + pub_r001214_16_1) + 12) & 127;
  int stage_v_143_2 = (((stage_v_38_2 * 3) + pub_r001214_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001214_5_1 * 2) + 47) & 63;
  int stage_v_144_2 = ((pub_r001214_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((stage_v_44_1 * 3) + pub_r001214_18_1) + 3) & 127;
  int stage_v_145_2 = (((stage_v_44_2 * 3) + pub_r001214_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001214_11_1 * 2) + 25) & 63;
  int stage_v_146_2 = ((pub_r001214_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_57_1 * 3) + pub_r001214_16_1) + 16) & 127;
  int stage_v_147_2 = (((stage_v_57_2 * 3) + pub_r001214_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001214_22_1 * 2) + 33) & 63;
  int stage_v_148_2 = ((pub_r001214_22_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001214_7_1 * 2) + 16) & 63;
  int stage_v_149_2 = ((pub_r001214_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((stage_v_128_1 * 3) + pub_r001214_9_1) + 31) & 127;
  int stage_v_150_2 = (((stage_v_128_2 * 3) + pub_r001214_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_63_1 * 3) + pub_r001214_18_1) + 42) & 127;
  int stage_v_151_2 = (((stage_v_63_2 * 3) + pub_r001214_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((stage_v_17_1 * 3) + pub_r001214_16_1) + 8) & 127;
  int stage_v_152_2 = (((stage_v_17_2 * 3) + pub_r001214_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001214_16_1 * 2) + 27) & 63;
  int stage_v_153_2 = ((pub_r001214_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001214_9_1 * 2) + 35) & 63;
  int stage_v_154_2 = ((pub_r001214_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((sec_r001214_12_1 * 3) + pub_r001214_1_1) + 12) & 127;
  int stage_v_155_2 = (((sec_r001214_12_2 * 3) + pub_r001214_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((helper_flow_2_1 * 3) + pub_r001214_20_1) + 43) & 127;
  int stage_v_156_2 = (((helper_flow_2_2 * 3) + pub_r001214_20_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_30_1 * 3) + pub_r001214_16_1) + 43) & 127;
  int stage_v_157_2 = (((stage_v_30_2 * 3) + pub_r001214_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001214_14_1 * 2) + 15) & 63;
  int stage_v_158_2 = ((pub_r001214_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((stage_v_76_1 * 3) + pub_r001214_4_1) + 4) & 127;
  int stage_v_159_2 = (((stage_v_76_2 * 3) + pub_r001214_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = ((pub_r001214_5_1 * 2) + 33) & 63;
  int stage_v_160_2 = ((pub_r001214_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_56_1 * 3) + pub_r001214_6_1) + 35) & 127;
  int stage_v_161_2 = (((stage_v_56_2 * 3) + pub_r001214_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001214_21_1 * 2) + 16) & 63;
  int stage_v_162_2 = ((pub_r001214_21_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001214_19_1 * 2) + 19) & 63;
  int stage_v_163_2 = ((pub_r001214_19_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((sec_r001214_7_1 * 3) + pub_r001214_14_1) + 5) & 127;
  int stage_v_164_2 = (((sec_r001214_7_2 * 3) + pub_r001214_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001214_0_1 * 2) + 28) & 63;
  int stage_v_165_2 = ((pub_r001214_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_57_1 * 3) + pub_r001214_4_1) + 20) & 127;
  int stage_v_166_2 = (((stage_v_57_2 * 3) + pub_r001214_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = ((pub_r001214_15_1 * 2) + 20) & 63;
  int stage_v_167_2 = ((pub_r001214_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((stage_v_55_1 * 3) + pub_r001214_15_1) + 4) & 127;
  int stage_v_168_2 = (((stage_v_55_2 * 3) + pub_r001214_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001214_14_1 * 2) + 46) & 63;
  int stage_v_169_2 = ((pub_r001214_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001214_12_1 * 2) + 19) & 63;
  int stage_v_170_2 = ((pub_r001214_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_33_1 * 3) + pub_r001214_22_1) + 20) & 127;
  int stage_v_171_2 = (((stage_v_33_2 * 3) + pub_r001214_22_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = ((pub_r001214_7_1 * 2) + 19) & 63;
  int stage_v_172_2 = ((pub_r001214_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((sec_r001214_10_1 * 3) + pub_r001214_10_1) + 37) & 127;
  int stage_v_173_2 = (((sec_r001214_10_2 * 3) + pub_r001214_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = ((pub_r001214_17_1 * 2) + 26) & 63;
  int stage_v_174_2 = ((pub_r001214_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((sec_r001214_2_1 * 3) + pub_r001214_22_1) + 22) & 127;
  int stage_v_175_2 = (((sec_r001214_2_2 * 3) + pub_r001214_22_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((stage_v_129_1 * 3) + pub_r001214_1_1) + 40) & 127;
  int stage_v_176_2 = (((stage_v_129_2 * 3) + pub_r001214_1_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((stage_v_34_1 * 3) + pub_r001214_18_1) + 24) & 127;
  int stage_v_177_2 = (((stage_v_34_2 * 3) + pub_r001214_18_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = ((pub_r001214_17_1 * 2) + 33) & 63;
  int stage_v_178_2 = ((pub_r001214_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((stage_v_155_1 * 3) + pub_r001214_3_1) + 24) & 127;
  int stage_v_179_2 = (((stage_v_155_2 * 3) + pub_r001214_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((sec_r001214_11_1 * 3) + pub_r001214_4_1) + 24) & 127;
  int stage_v_180_2 = (((sec_r001214_11_2 * 3) + pub_r001214_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((stage_v_139_1 * 3) + pub_r001214_20_1) + 19) & 127;
  int stage_v_181_2 = (((stage_v_139_2 * 3) + pub_r001214_20_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((stage_v_18_1 * 3) + pub_r001214_19_1) + 30) & 127;
  int stage_v_182_2 = (((stage_v_18_2 * 3) + pub_r001214_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((stage_v_4_1 * 3) + pub_r001214_9_1) + 25) & 127;
  int stage_v_183_2 = (((stage_v_4_2 * 3) + pub_r001214_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_129_1 * 3) + pub_r001214_5_1) + 27) & 127;
  int stage_v_184_2 = (((stage_v_129_2 * 3) + pub_r001214_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_107_1 * 3) + pub_r001214_20_1) + 39) & 127;
  int stage_v_185_2 = (((stage_v_107_2 * 3) + pub_r001214_20_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((sec_r001214_8_1 * 3) + pub_r001214_21_1) + 25) & 127;
  int stage_v_186_2 = (((sec_r001214_8_2 * 3) + pub_r001214_21_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001214_13_1 * 2) + 5) & 63;
  int stage_v_187_2 = ((pub_r001214_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001214_2_1 * 2) + 40) & 63;
  int stage_v_188_2 = ((pub_r001214_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001214_3_1 * 2) + 12) & 63;
  int stage_v_189_2 = ((pub_r001214_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_133_1 * 3) + pub_r001214_12_1) + 28) & 127;
  int stage_v_190_2 = (((stage_v_133_2 * 3) + pub_r001214_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001214_22_1 * 2) + 50) & 63;
  int stage_v_191_2 = ((pub_r001214_22_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001214_4_1 * 2) + 44) & 63;
  int stage_v_192_2 = ((pub_r001214_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((sec_r001214_12_1 * 3) + pub_r001214_0_1) + 5) & 127;
  int stage_v_193_2 = (((sec_r001214_12_2 * 3) + pub_r001214_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((stage_v_94_1 * 3) + pub_r001214_19_1) + 40) & 127;
  int stage_v_194_2 = (((stage_v_94_2 * 3) + pub_r001214_19_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((stage_v_142_1 * 3) + pub_r001214_22_1) + 39) & 127;
  int stage_v_195_2 = (((stage_v_142_2 * 3) + pub_r001214_22_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001214_21_1 * 2) + 50) & 63;
  int stage_v_196_2 = ((pub_r001214_21_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((sec_r001214_5_1 * 3) + pub_r001214_2_1) + 33) & 127;
  int stage_v_197_2 = (((sec_r001214_5_2 * 3) + pub_r001214_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = ((pub_r001214_21_1 * 2) + 39) & 63;
  int stage_v_198_2 = ((pub_r001214_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_173_1 * 3) + pub_r001214_9_1) + 21) & 127;
  int stage_v_199_2 = (((stage_v_173_2 * 3) + pub_r001214_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = (((stage_v_114_1 * 3) + pub_r001214_4_1) + 15) & 127;
  int stage_v_200_2 = (((stage_v_114_2 * 3) + pub_r001214_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = (((helper_flow_5_1 * 3) + pub_r001214_2_1) + 7) & 127;
  int stage_v_201_2 = (((helper_flow_5_2 * 3) + pub_r001214_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = (((stage_v_193_1 * 3) + pub_r001214_3_1) + 21) & 127;
  int stage_v_202_2 = (((stage_v_193_2 * 3) + pub_r001214_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001214_5_1 * 2) + 17) & 63;
  int stage_v_203_2 = ((pub_r001214_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001214_22_1 * 2) + 36) & 63;
  int stage_v_204_2 = ((pub_r001214_22_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001214_2_1 * 2) + 21) & 63;
  int stage_v_205_2 = ((pub_r001214_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001214_15_1 * 2) + 12) & 63;
  int stage_v_206_2 = ((pub_r001214_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_133_1 * 3) + pub_r001214_15_1) + 22) & 127;
  int stage_v_207_2 = (((stage_v_133_2 * 3) + pub_r001214_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001214_1_1 * 2) + 11) & 63;
  int stage_v_208_2 = ((pub_r001214_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_3_1 * 3) + pub_r001214_9_1) + 6) & 127;
  int stage_v_209_2 = (((stage_v_3_2 * 3) + pub_r001214_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = (((stage_v_91_1 * 3) + pub_r001214_18_1) + 3) & 127;
  int stage_v_210_2 = (((stage_v_91_2 * 3) + pub_r001214_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((helper_flow_5_1 * 3) + pub_r001214_19_1) + 30) & 127;
  int stage_v_211_2 = (((helper_flow_5_2 * 3) + pub_r001214_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_155_1 * 3) + pub_r001214_11_1) + 15) & 127;
  int stage_v_212_2 = (((stage_v_155_2 * 3) + pub_r001214_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = ((pub_r001214_6_1 * 2) + 50) & 63;
  int stage_v_213_2 = ((pub_r001214_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_137_1 * 3) + pub_r001214_6_1) + 26) & 127;
  int stage_v_214_2 = (((stage_v_137_2 * 3) + pub_r001214_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((sec_r001214_4_1 * 3) + pub_r001214_22_1) + 6) & 127;
  int stage_v_215_2 = (((sec_r001214_4_2 * 3) + pub_r001214_22_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_14_1 * 3) + pub_r001214_19_1) + 7) & 127;
  int stage_v_216_2 = (((stage_v_14_2 * 3) + pub_r001214_19_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001214_1_1 * 2) + 27) & 63;
  int stage_v_217_2 = ((pub_r001214_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((stage_v_91_1 * 3) + pub_r001214_7_1) + 14) & 127;
  int stage_v_218_2 = (((stage_v_91_2 * 3) + pub_r001214_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = ((pub_r001214_14_1 * 2) + 20) & 63;
  int stage_v_219_2 = ((pub_r001214_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_57_1 * 3) + pub_r001214_21_1) + 8) & 127;
  int stage_v_220_2 = (((stage_v_57_2 * 3) + pub_r001214_21_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_155_1 * 3) + pub_r001214_13_1) + 30) & 127;
  int stage_v_221_2 = (((stage_v_155_2 * 3) + pub_r001214_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((stage_v_94_1 * 3) + pub_r001214_20_1) + 18) & 127;
  int stage_v_222_2 = (((stage_v_94_2 * 3) + pub_r001214_20_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001214_7_1 * 2) + 34) & 63;
  int stage_v_223_2 = ((pub_r001214_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001214_13_1 * 2) + 30) & 63;
  int stage_v_224_2 = ((pub_r001214_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_54_1 * 3) + pub_r001214_4_1) + 11) & 127;
  int stage_v_225_2 = (((stage_v_54_2 * 3) + pub_r001214_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = ((pub_r001214_18_1 * 2) + 27) & 63;
  int stage_v_226_2 = ((pub_r001214_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((stage_v_199_1 * 3) + pub_r001214_21_1) + 15) & 127;
  int stage_v_227_2 = (((stage_v_199_2 * 3) + pub_r001214_21_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_24_1 * 3) + pub_r001214_22_1) + 37) & 127;
  int stage_v_228_2 = (((stage_v_24_2 * 3) + pub_r001214_22_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = (((stage_v_197_1 * 3) + pub_r001214_18_1) + 30) & 127;
  int stage_v_229_2 = (((stage_v_197_2 * 3) + pub_r001214_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((stage_v_76_1 * 3) + pub_r001214_10_1) + 22) & 127;
  int stage_v_230_2 = (((stage_v_76_2 * 3) + pub_r001214_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = (((stage_v_161_1 * 3) + pub_r001214_12_1) + 43) & 127;
  int stage_v_231_2 = (((stage_v_161_2 * 3) + pub_r001214_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((stage_v_168_1 * 3) + pub_r001214_16_1) + 28) & 127;
  int stage_v_232_2 = (((stage_v_168_2 * 3) + pub_r001214_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001214_0_1 * 2) + 9) & 63;
  int stage_v_233_2 = ((pub_r001214_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((stage_v_36_1 * 3) + pub_r001214_18_1) + 5) & 127;
  int stage_v_234_2 = (((stage_v_36_2 * 3) + pub_r001214_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_53_1 * 3) + pub_r001214_22_1) + 24) & 127;
  int stage_v_235_2 = (((stage_v_53_2 * 3) + pub_r001214_22_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001214_1_1 * 2) + 47) & 63;
  int stage_v_236_2 = ((pub_r001214_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001214_4_1 * 2) + 41) & 63;
  int stage_v_237_2 = ((pub_r001214_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001214_5_1 * 2) + 14) & 63;
  int stage_v_238_2 = ((pub_r001214_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001214_5_1 * 2) + 11) & 63;
  int stage_v_239_2 = ((pub_r001214_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001214_15_1 * 2) + 35) & 63;
  int stage_v_240_2 = ((pub_r001214_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001214_22_1 * 2) + 8) & 63;
  int stage_v_241_2 = ((pub_r001214_22_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((helper_flow_4_1 * 3) + pub_r001214_19_1) + 32) & 127;
  int stage_v_242_2 = (((helper_flow_4_2 * 3) + pub_r001214_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_85_1 * 3) + pub_r001214_1_1) + 29) & 127;
  int stage_v_243_2 = (((stage_v_85_2 * 3) + pub_r001214_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001214_0_1 * 2) + 19) & 63;
  int stage_v_244_2 = ((pub_r001214_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = (((stage_v_37_1 * 3) + pub_r001214_14_1) + 23) & 127;
  int stage_v_245_2 = (((stage_v_37_2 * 3) + pub_r001214_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001214_6_1 * 2) + 12) & 63;
  int stage_v_246_2 = ((pub_r001214_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001214_5_1 * 2) + 42) & 63;
  int stage_v_247_2 = ((pub_r001214_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_139_1 * 3) + pub_r001214_0_1) + 34) & 127;
  int stage_v_248_2 = (((stage_v_139_2 * 3) + pub_r001214_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((helper_flow_8_1 * 3) + pub_r001214_4_1) + 8) & 127;
  int stage_v_249_2 = (((helper_flow_8_2 * 3) + pub_r001214_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001214_0_1 * 2) + 12) & 63;
  int stage_v_250_2 = ((pub_r001214_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001214_18_1 * 2) + 44) & 63;
  int stage_v_251_2 = ((pub_r001214_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001214_10_1 * 2) + 39) & 63;
  int stage_v_252_2 = ((pub_r001214_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001214_6_1 * 2) + 33) & 63;
  int stage_v_253_2 = ((pub_r001214_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_10_1 * 3) + pub_r001214_2_1) + 31) & 127;
  int stage_v_254_2 = (((stage_v_10_2 * 3) + pub_r001214_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((stage_v_64_1 * 3) + pub_r001214_15_1) + 20) & 127;
  int stage_v_255_2 = (((stage_v_64_2 * 3) + pub_r001214_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = (((stage_v_17_1 * 3) + pub_r001214_2_1) + 26) & 127;
  int stage_v_256_2 = (((stage_v_17_2 * 3) + pub_r001214_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = (((sec_r001214_6_1 * 3) + pub_r001214_19_1) + 31) & 127;
  int stage_v_257_2 = (((sec_r001214_6_2 * 3) + pub_r001214_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = (((stage_v_17_1 * 3) + pub_r001214_5_1) + 14) & 127;
  int stage_v_258_2 = (((stage_v_17_2 * 3) + pub_r001214_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001214_22_1 * 2) + 38) & 63;
  int stage_v_259_2 = ((pub_r001214_22_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = (((stage_v_193_1 * 3) + pub_r001214_21_1) + 12) & 127;
  int stage_v_260_2 = (((stage_v_193_2 * 3) + pub_r001214_21_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((sec_r001214_3_1 * 3) + pub_r001214_20_1) + 35) & 127;
  int stage_v_261_2 = (((sec_r001214_3_2 * 3) + pub_r001214_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = (((stage_v_4_1 * 3) + pub_r001214_10_1) + 33) & 127;
  int stage_v_262_2 = (((stage_v_4_2 * 3) + pub_r001214_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = ((pub_r001214_22_1 * 2) + 26) & 63;
  int stage_v_263_2 = ((pub_r001214_22_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001214_11_1 * 2) + 6) & 63;
  int stage_v_264_2 = ((pub_r001214_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_116_1 * 3) + pub_r001214_12_1) + 7) & 127;
  int stage_v_265_2 = (((stage_v_116_2 * 3) + pub_r001214_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_76_1 * 3) + pub_r001214_5_1) + 30) & 127;
  int stage_v_266_2 = (((stage_v_76_2 * 3) + pub_r001214_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((stage_v_168_1 * 3) + pub_r001214_14_1) + 25) & 127;
  int stage_v_267_2 = (((stage_v_168_2 * 3) + pub_r001214_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = ((pub_r001214_6_1 * 2) + 12) & 63;
  int stage_v_268_2 = ((pub_r001214_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = (((helper_flow_7_1 * 3) + pub_r001214_14_1) + 10) & 127;
  int stage_v_269_2 = (((helper_flow_7_2 * 3) + pub_r001214_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = (((stage_v_55_1 * 3) + pub_r001214_1_1) + 42) & 127;
  int stage_v_270_2 = (((stage_v_55_2 * 3) + pub_r001214_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((helper_flow_7_1 * 3) + pub_r001214_7_1) + 31) & 127;
  int stage_v_271_2 = (((helper_flow_7_2 * 3) + pub_r001214_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001214_11_1 * 2) + 18) & 63;
  int stage_v_272_2 = ((pub_r001214_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001214_9_1 * 2) + 38) & 63;
  int stage_v_273_2 = ((pub_r001214_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001214_4_1 * 2) + 36) & 63;
  int stage_v_274_2 = ((pub_r001214_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = (((stage_v_24_1 * 3) + pub_r001214_7_1) + 18) & 127;
  int stage_v_275_2 = (((stage_v_24_2 * 3) + pub_r001214_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((stage_v_173_1 * 3) + pub_r001214_1_1) + 10) & 127;
  int stage_v_276_2 = (((stage_v_173_2 * 3) + pub_r001214_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001214_7_1 * 2) + 19) & 63;
  int stage_v_277_2 = ((pub_r001214_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001214_12_1 * 2) + 30) & 63;
  int stage_v_278_2 = ((pub_r001214_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = (((stage_v_157_1 * 3) + pub_r001214_16_1) + 42) & 127;
  int stage_v_279_2 = (((stage_v_157_2 * 3) + pub_r001214_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = ((pub_r001214_11_1 * 2) + 25) & 63;
  int stage_v_280_2 = ((pub_r001214_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001214_10_1 * 2) + 25) & 63;
  int stage_v_281_2 = ((pub_r001214_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_6_1 * 3) + pub_r001214_17_1) + 19) & 127;
  int stage_v_282_2 = (((stage_v_6_2 * 3) + pub_r001214_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = (((stage_v_261_1 * 3) + pub_r001214_16_1) + 35) & 127;
  int stage_v_283_2 = (((stage_v_261_2 * 3) + pub_r001214_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((sec_r001214_18_1 * 3) + pub_r001214_7_1) + 26) & 127;
  int stage_v_284_2 = (((sec_r001214_18_2 * 3) + pub_r001214_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = (((stage_v_97_1 * 3) + pub_r001214_14_1) + 24) & 127;
  int stage_v_285_2 = (((stage_v_97_2 * 3) + pub_r001214_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001214_2_1 * 2) + 49) & 63;
  int stage_v_286_2 = ((pub_r001214_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001214_1_1 * 2) + 5) & 63;
  int stage_v_287_2 = ((pub_r001214_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = (((stage_v_166_1 * 3) + pub_r001214_5_1) + 21) & 127;
  int stage_v_288_2 = (((stage_v_166_2 * 3) + pub_r001214_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = ((pub_r001214_11_1 * 2) + 12) & 63;
  int stage_v_289_2 = ((pub_r001214_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001214_15_1 * 2) + 49) & 63;
  int stage_v_290_2 = ((pub_r001214_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001214_7_1 * 2) + 45) & 63;
  int stage_v_291_2 = ((pub_r001214_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001214_2_1 * 2) + 49) & 63;
  int stage_v_292_2 = ((pub_r001214_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001214_10_1 * 2) + 13) & 63;
  int stage_v_293_2 = ((pub_r001214_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((sec_r001214_10_1 * 3) + pub_r001214_7_1) + 35) & 127;
  int stage_v_294_2 = (((sec_r001214_10_2 * 3) + pub_r001214_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_94_1 * 3) + pub_r001214_17_1) + 8) & 127;
  int stage_v_295_2 = (((stage_v_94_2 * 3) + pub_r001214_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((stage_v_104_1 * 3) + pub_r001214_18_1) + 35) & 127;
  int stage_v_296_2 = (((stage_v_104_2 * 3) + pub_r001214_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001214_15_1 * 2) + 8) & 63;
  int stage_v_297_2 = ((pub_r001214_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_151_1 * 3) + pub_r001214_7_1) + 8) & 127;
  int stage_v_298_2 = (((stage_v_151_2 * 3) + pub_r001214_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((stage_v_234_1 * 3) + pub_r001214_17_1) + 39) & 127;
  int stage_v_299_2 = (((stage_v_234_2 * 3) + pub_r001214_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = (((stage_v_182_1 * 3) + pub_r001214_0_1) + 27) & 127;
  int stage_v_300_2 = (((stage_v_182_2 * 3) + pub_r001214_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = (((stage_v_186_1 * 3) + pub_r001214_14_1) + 12) & 127;
  int stage_v_301_2 = (((stage_v_186_2 * 3) + pub_r001214_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001214_16_1 * 2) + 9) & 63;
  int stage_v_302_2 = ((pub_r001214_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001214_19_1 * 2) + 24) & 63;
  int stage_v_303_2 = ((pub_r001214_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001214_1_1 * 2) + 21) & 63;
  int stage_v_304_2 = ((pub_r001214_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001214_18_1 * 2) + 8) & 63;
  int stage_v_305_2 = ((pub_r001214_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_147_1 * 3) + pub_r001214_2_1) + 32) & 127;
  int stage_v_306_2 = (((stage_v_147_2 * 3) + pub_r001214_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = (((stage_v_20_1 * 3) + pub_r001214_4_1) + 5) & 127;
  int stage_v_307_2 = (((stage_v_20_2 * 3) + pub_r001214_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = (((stage_v_177_1 * 3) + pub_r001214_18_1) + 23) & 127;
  int stage_v_308_2 = (((stage_v_177_2 * 3) + pub_r001214_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001214_15_1 * 2) + 27) & 63;
  int stage_v_309_2 = ((pub_r001214_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001214_14_1 * 2) + 24) & 63;
  int stage_v_310_2 = ((pub_r001214_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_116_1 * 3) + pub_r001214_20_1) + 28) & 127;
  int stage_v_311_2 = (((stage_v_116_2 * 3) + pub_r001214_20_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001214_15_1 * 2) + 46) & 63;
  int stage_v_312_2 = ((pub_r001214_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_82_1 * 3) + pub_r001214_10_1) + 28) & 127;
  int stage_v_313_2 = (((stage_v_82_2 * 3) + pub_r001214_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001214_7_1 * 2) + 49) & 63;
  int stage_v_314_2 = ((pub_r001214_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001214_21_1 * 2) + 19) & 63;
  int stage_v_315_2 = ((pub_r001214_21_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_22_1 * 3) + pub_r001214_0_1) + 16) & 127;
  int stage_v_316_2 = (((stage_v_22_2 * 3) + pub_r001214_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_214_1 * 3) + pub_r001214_4_1) + 27) & 127;
  int stage_v_317_2 = (((stage_v_214_2 * 3) + pub_r001214_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_137_1 * 3) + pub_r001214_18_1) + 37) & 127;
  int stage_v_318_2 = (((stage_v_137_2 * 3) + pub_r001214_18_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((stage_v_150_1 * 3) + pub_r001214_13_1) + 25) & 127;
  int stage_v_319_2 = (((stage_v_150_2 * 3) + pub_r001214_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = (((stage_v_11_1 * 3) + pub_r001214_22_1) + 24) & 127;
  int stage_v_320_2 = (((stage_v_11_2 * 3) + pub_r001214_22_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_7_1 * 3) + pub_r001214_11_1) + 37) & 127;
  int stage_v_321_2 = (((stage_v_7_2 * 3) + pub_r001214_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_214_1 * 3) + pub_r001214_4_1) + 14) & 127;
  int stage_v_322_2 = (((stage_v_214_2 * 3) + pub_r001214_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001214_16_1 * 2) + 15) & 63;
  int stage_v_323_2 = ((pub_r001214_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_182_1 * 3) + pub_r001214_16_1) + 23) & 127;
  int stage_v_324_2 = (((stage_v_182_2 * 3) + pub_r001214_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_152_1 * 3) + pub_r001214_9_1) + 7) & 127;
  int stage_v_325_2 = (((stage_v_152_2 * 3) + pub_r001214_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001214_8_1 * 2) + 36) & 63;
  int stage_v_326_2 = ((pub_r001214_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = (((stage_v_74_1 * 3) + pub_r001214_0_1) + 33) & 127;
  int stage_v_327_2 = (((stage_v_74_2 * 3) + pub_r001214_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = ((pub_r001214_17_1 * 2) + 13) & 63;
  int stage_v_328_2 = ((pub_r001214_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001214_11_1 * 2) + 9) & 63;
  int stage_v_329_2 = ((pub_r001214_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001214_18_1 * 2) + 24) & 63;
  int stage_v_330_2 = ((pub_r001214_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = (((stage_v_324_1 * 3) + pub_r001214_5_1) + 21) & 127;
  int stage_v_331_2 = (((stage_v_324_2 * 3) + pub_r001214_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((stage_v_307_1 * 3) + pub_r001214_9_1) + 41) & 127;
  int stage_v_332_2 = (((stage_v_307_2 * 3) + pub_r001214_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_63_1 * 3) + pub_r001214_14_1) + 8) & 127;
  int stage_v_333_2 = (((stage_v_63_2 * 3) + pub_r001214_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = (((stage_v_42_1 * 3) + pub_r001214_1_1) + 26) & 127;
  int stage_v_334_2 = (((stage_v_42_2 * 3) + pub_r001214_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((stage_v_258_1 * 3) + pub_r001214_22_1) + 9) & 127;
  int stage_v_335_2 = (((stage_v_258_2 * 3) + pub_r001214_22_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_24_1 * 3) + pub_r001214_12_1) + 34) & 127;
  int stage_v_336_2 = (((stage_v_24_2 * 3) + pub_r001214_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = ((pub_r001214_17_1 * 2) + 33) & 63;
  int stage_v_337_2 = ((pub_r001214_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001214_22_1 * 2) + 20) & 63;
  int stage_v_338_2 = ((pub_r001214_22_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = (((helper_flow_8_1 * 3) + pub_r001214_7_1) + 17) & 127;
  int stage_v_339_2 = (((helper_flow_8_2 * 3) + pub_r001214_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001214_1_1 * 2) + 27) & 63;
  int stage_v_340_2 = ((pub_r001214_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = (((stage_v_207_1 * 3) + pub_r001214_4_1) + 6) & 127;
  int stage_v_341_2 = (((stage_v_207_2 * 3) + pub_r001214_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_35_1 * 3) + pub_r001214_22_1) + 9) & 127;
  int stage_v_342_2 = (((stage_v_35_2 * 3) + pub_r001214_22_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_231_1 * 3) + pub_r001214_22_1) + 26) & 127;
  int stage_v_343_2 = (((stage_v_231_2 * 3) + pub_r001214_22_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_36_1 * 3) + pub_r001214_17_1) + 28) & 127;
  int stage_v_344_2 = (((stage_v_36_2 * 3) + pub_r001214_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = (((stage_v_161_1 * 3) + pub_r001214_11_1) + 15) & 127;
  int stage_v_345_2 = (((stage_v_161_2 * 3) + pub_r001214_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = ((pub_r001214_11_1 * 2) + 36) & 63;
  int stage_v_346_2 = ((pub_r001214_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = (((stage_v_295_1 * 3) + pub_r001214_3_1) + 3) & 127;
  int stage_v_347_2 = (((stage_v_295_2 * 3) + pub_r001214_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_199_1 * 3) + pub_r001214_11_1) + 26) & 127;
  int stage_v_348_2 = (((stage_v_199_2 * 3) + pub_r001214_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001214_2_1 * 2) + 17) & 63;
  int stage_v_349_2 = ((pub_r001214_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((stage_v_55_1 * 3) + pub_r001214_16_1) + 6) & 127;
  int stage_v_350_2 = (((stage_v_55_2 * 3) + pub_r001214_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_279_1 * 3) + pub_r001214_13_1) + 35) & 127;
  int stage_v_351_2 = (((stage_v_279_2 * 3) + pub_r001214_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = ((pub_r001214_4_1 * 2) + 40) & 63;
  int stage_v_352_2 = ((pub_r001214_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = (((stage_v_265_1 * 3) + pub_r001214_2_1) + 35) & 127;
  int stage_v_353_2 = (((stage_v_265_2 * 3) + pub_r001214_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((stage_v_7_1 * 3) + pub_r001214_19_1) + 40) & 127;
  int stage_v_354_2 = (((stage_v_7_2 * 3) + pub_r001214_19_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_33_1 * 3) + pub_r001214_13_1) + 35) & 127;
  int stage_v_355_2 = (((stage_v_33_2 * 3) + pub_r001214_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_57_1 * 3) + pub_r001214_22_1) + 31) & 127;
  int stage_v_356_2 = (((stage_v_57_2 * 3) + pub_r001214_22_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001214_7_1 * 2) + 36) & 63;
  int stage_v_357_2 = ((pub_r001214_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001214_11_1 * 2) + 14) & 63;
  int stage_v_358_2 = ((pub_r001214_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_317_1 * 3) + pub_r001214_17_1) + 24) & 127;
  int stage_v_359_2 = (((stage_v_317_2 * 3) + pub_r001214_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((stage_v_334_1 * 3) + pub_r001214_7_1) + 27) & 127;
  int stage_v_360_2 = (((stage_v_334_2 * 3) + pub_r001214_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((sec_r001214_17_1 * 3) + pub_r001214_11_1) + 28) & 127;
  int stage_v_361_2 = (((sec_r001214_17_2 * 3) + pub_r001214_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001214_11_1 * 2) + 48) & 63;
  int stage_v_362_2 = ((pub_r001214_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((stage_v_230_1 * 3) + pub_r001214_6_1) + 18) & 127;
  int stage_v_363_2 = (((stage_v_230_2 * 3) + pub_r001214_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_50_1 * 3) + pub_r001214_15_1) + 20) & 127;
  int stage_v_364_2 = (((stage_v_50_2 * 3) + pub_r001214_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = ((pub_r001214_10_1 * 2) + 44) & 63;
  int stage_v_365_2 = ((pub_r001214_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001214_3_1 * 2) + 22) & 63;
  int stage_v_366_2 = ((pub_r001214_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_256_1 * 3) + pub_r001214_0_1) + 16) & 127;
  int stage_v_367_2 = (((stage_v_256_2 * 3) + pub_r001214_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001214_19_1 * 2) + 6) & 63;
  int stage_v_368_2 = ((pub_r001214_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = (((stage_v_261_1 * 3) + pub_r001214_19_1) + 17) & 127;
  int stage_v_369_2 = (((stage_v_261_2 * 3) + pub_r001214_19_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = ((pub_r001214_18_1 * 2) + 36) & 63;
  int stage_v_370_2 = ((pub_r001214_18_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001214_7_1 * 2) + 31) & 63;
  int stage_v_371_2 = ((pub_r001214_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001214_3_1 * 2) + 23) & 63;
  int stage_v_372_2 = ((pub_r001214_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_209_1 * 3) + pub_r001214_14_1) + 4) & 127;
  int stage_v_373_2 = (((stage_v_209_2 * 3) + pub_r001214_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((stage_v_114_1 * 3) + pub_r001214_9_1) + 27) & 127;
  int stage_v_374_2 = (((stage_v_114_2 * 3) + pub_r001214_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_30_1 * 3) + pub_r001214_11_1) + 5) & 127;
  int stage_v_375_2 = (((stage_v_30_2 * 3) + pub_r001214_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((sec_r001214_0_1 * 3) + pub_r001214_8_1) + 5) & 127;
  int stage_v_376_2 = (((sec_r001214_0_2 * 3) + pub_r001214_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((stage_v_97_1 * 3) + pub_r001214_6_1) + 5) & 127;
  int stage_v_377_2 = (((stage_v_97_2 * 3) + pub_r001214_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = ((pub_r001214_14_1 * 2) + 50) & 63;
  int stage_v_378_2 = ((pub_r001214_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = (((stage_v_245_1 * 3) + pub_r001214_2_1) + 35) & 127;
  int stage_v_379_2 = (((stage_v_245_2 * 3) + pub_r001214_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001214_22_1 * 2) + 42) & 63;
  int stage_v_380_2 = ((pub_r001214_22_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001214_10_1 * 2) + 31) & 63;
  int stage_v_381_2 = ((pub_r001214_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_320_1 * 3) + pub_r001214_17_1) + 15) & 127;
  int stage_v_382_2 = (((stage_v_320_2 * 3) + pub_r001214_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001214_10_1 * 2) + 23) & 63;
  int stage_v_383_2 = ((pub_r001214_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = (((stage_v_211_1 * 3) + pub_r001214_18_1) + 29) & 127;
  int stage_v_384_2 = (((stage_v_211_2 * 3) + pub_r001214_18_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = (((stage_v_235_1 * 3) + pub_r001214_0_1) + 6) & 127;
  int stage_v_385_2 = (((stage_v_235_2 * 3) + pub_r001214_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = ((pub_r001214_15_1 * 2) + 13) & 63;
  int stage_v_386_2 = ((pub_r001214_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((sec_r001214_9_1 * 3) + pub_r001214_21_1) + 33) & 127;
  int stage_v_387_2 = (((sec_r001214_9_2 * 3) + pub_r001214_21_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = (((stage_v_97_1 * 3) + pub_r001214_21_1) + 5) & 127;
  int stage_v_388_2 = (((stage_v_97_2 * 3) + pub_r001214_21_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = (((stage_v_190_1 * 3) + pub_r001214_2_1) + 22) & 127;
  int stage_v_389_2 = (((stage_v_190_2 * 3) + pub_r001214_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = (((stage_v_221_1 * 3) + pub_r001214_21_1) + 6) & 127;
  int stage_v_390_2 = (((stage_v_221_2 * 3) + pub_r001214_21_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = ((pub_r001214_3_1 * 2) + 25) & 63;
  int stage_v_391_2 = ((pub_r001214_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001214_22_1 * 2) + 7) & 63;
  int stage_v_392_2 = ((pub_r001214_22_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001214_18_1 * 2) + 41) & 63;
  int stage_v_393_2 = ((pub_r001214_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001214_11_1 * 2) + 17) & 63;
  int stage_v_394_2 = ((pub_r001214_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001214_17_1 * 2) + 29) & 63;
  int stage_v_395_2 = ((pub_r001214_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_215_1 * 3) + pub_r001214_7_1) + 28) & 127;
  int stage_v_396_2 = (((stage_v_215_2 * 3) + pub_r001214_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((stage_v_270_1 * 3) + pub_r001214_8_1) + 30) & 127;
  int stage_v_397_2 = (((stage_v_270_2 * 3) + pub_r001214_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = ((pub_r001214_5_1 * 2) + 44) & 63;
  int stage_v_398_2 = ((pub_r001214_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001214_3_1 * 2) + 17) & 63;
  int stage_v_399_2 = ((pub_r001214_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = (((sec_r001214_13_1 * 3) + pub_r001214_5_1) + 45) & 127;
  int stage_v_400_2 = (((sec_r001214_13_2 * 3) + pub_r001214_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = ((pub_r001214_3_1 * 2) + 11) & 63;
  int stage_v_401_2 = ((pub_r001214_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = (((stage_v_33_1 * 3) + pub_r001214_9_1) + 11) & 127;
  int stage_v_402_2 = (((stage_v_33_2 * 3) + pub_r001214_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = ((pub_r001214_14_1 * 2) + 7) & 63;
  int stage_v_403_2 = ((pub_r001214_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = (((stage_v_255_1 * 3) + pub_r001214_9_1) + 18) & 127;
  int stage_v_404_2 = (((stage_v_255_2 * 3) + pub_r001214_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_91_1 * 3) + pub_r001214_2_1) + 13) & 127;
  int stage_v_405_2 = (((stage_v_91_2 * 3) + pub_r001214_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = ((pub_r001214_7_1 * 2) + 44) & 63;
  int stage_v_406_2 = ((pub_r001214_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = (((stage_v_360_1 * 3) + pub_r001214_21_1) + 25) & 127;
  int stage_v_407_2 = (((stage_v_360_2 * 3) + pub_r001214_21_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_407_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_407_2 * 2)) & 255;
  int stage_v_408_1 = ((pub_r001214_4_1 * 2) + 32) & 63;
  int stage_v_408_2 = ((pub_r001214_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001214_5_1 * 2) + 20) & 63;
  int stage_v_409_2 = ((pub_r001214_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = (((stage_v_133_1 * 3) + pub_r001214_15_1) + 39) & 127;
  int stage_v_410_2 = (((stage_v_133_2 * 3) + pub_r001214_15_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_410_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_410_2 * 2)) & 255;
  int stage_v_411_1 = ((pub_r001214_4_1 * 2) + 29) & 63;
  int stage_v_411_2 = ((pub_r001214_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((pub_r001214_2_1 * 2) + 23) & 63;
  int stage_v_412_2 = ((pub_r001214_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((pub_r001214_12_1 * 2) + 37) & 63;
  int stage_v_413_2 = ((pub_r001214_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001214_11_1 * 2) + 34) & 63;
  int stage_v_414_2 = ((pub_r001214_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_107_1 * 3) + pub_r001214_12_1) + 41) & 127;
  int stage_v_415_2 = (((stage_v_107_2 * 3) + pub_r001214_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001214_6_1 * 2) + 17) & 63;
  int stage_v_416_2 = ((pub_r001214_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001214_8_1 * 2) + 22) & 63;
  int stage_v_417_2 = ((pub_r001214_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001214_18_1 * 2) + 44) & 63;
  int stage_v_418_2 = ((pub_r001214_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_130_1 * 3) + pub_r001214_13_1) + 27) & 127;
  int stage_v_419_2 = (((stage_v_130_2 * 3) + pub_r001214_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = (((stage_v_351_1 * 3) + pub_r001214_0_1) + 10) & 127;
  int stage_v_420_2 = (((stage_v_351_2 * 3) + pub_r001214_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = ((pub_r001214_22_1 * 2) + 39) & 63;
  int stage_v_421_2 = ((pub_r001214_22_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001214_5_1 * 2) + 21) & 63;
  int stage_v_422_2 = ((pub_r001214_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001214_19_1 * 2) + 42) & 63;
  int stage_v_423_2 = ((pub_r001214_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001214_3_1 * 2) + 12) & 63;
  int stage_v_424_2 = ((pub_r001214_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = (((sec_r001214_5_1 * 3) + pub_r001214_12_1) + 20) & 127;
  int stage_v_425_2 = (((sec_r001214_5_2 * 3) + pub_r001214_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001214_6_1 * 2) + 42) & 63;
  int stage_v_426_2 = ((pub_r001214_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = (((stage_v_126_1 * 3) + pub_r001214_2_1) + 22) & 127;
  int stage_v_427_2 = (((stage_v_126_2 * 3) + pub_r001214_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = (((stage_v_14_1 * 3) + pub_r001214_18_1) + 13) & 127;
  int stage_v_428_2 = (((stage_v_14_2 * 3) + pub_r001214_18_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = (((stage_v_98_1 * 3) + pub_r001214_9_1) + 9) & 127;
  int stage_v_429_2 = (((stage_v_98_2 * 3) + pub_r001214_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = (((stage_v_150_1 * 3) + pub_r001214_18_1) + 42) & 127;
  int stage_v_430_2 = (((stage_v_150_2 * 3) + pub_r001214_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = ((pub_r001214_19_1 * 2) + 22) & 63;
  int stage_v_431_2 = ((pub_r001214_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = (((stage_v_227_1 * 3) + pub_r001214_15_1) + 12) & 127;
  int stage_v_432_2 = (((stage_v_227_2 * 3) + pub_r001214_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = (((stage_v_306_1 * 3) + pub_r001214_1_1) + 35) & 127;
  int stage_v_433_2 = (((stage_v_306_2 * 3) + pub_r001214_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = (((stage_v_45_1 * 3) + pub_r001214_20_1) + 27) & 127;
  int stage_v_434_2 = (((stage_v_45_2 * 3) + pub_r001214_20_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = ((pub_r001214_3_1 * 2) + 23) & 63;
  int stage_v_435_2 = ((pub_r001214_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((stage_v_155_1 * 3) + pub_r001214_10_1) + 45) & 127;
  int stage_v_436_2 = (((stage_v_155_2 * 3) + pub_r001214_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = ((pub_r001214_11_1 * 2) + 36) & 63;
  int stage_v_437_2 = ((pub_r001214_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((pub_r001214_13_1 * 2) + 19) & 63;
  int stage_v_438_2 = ((pub_r001214_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = (((stage_v_105_1 * 3) + pub_r001214_9_1) + 17) & 127;
  int stage_v_439_2 = (((stage_v_105_2 * 3) + pub_r001214_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = (((stage_v_212_1 * 3) + pub_r001214_3_1) + 15) & 127;
  int stage_v_440_2 = (((stage_v_212_2 * 3) + pub_r001214_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = ((pub_r001214_7_1 * 2) + 19) & 63;
  int stage_v_441_2 = ((pub_r001214_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = (((stage_v_37_1 * 3) + pub_r001214_4_1) + 12) & 127;
  int stage_v_442_2 = (((stage_v_37_2 * 3) + pub_r001214_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = ((pub_r001214_3_1 * 2) + 22) & 63;
  int stage_v_443_2 = ((pub_r001214_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = (((helper_flow_8_1 * 3) + pub_r001214_5_1) + 22) & 127;
  int stage_v_444_2 = (((helper_flow_8_2 * 3) + pub_r001214_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_444_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_444_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_444_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_444_2 * 2)) & 255;
  int stage_v_445_1 = ((pub_r001214_12_1 * 2) + 44) & 63;
  int stage_v_445_2 = ((pub_r001214_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001214_22_1 == pub_r001214_22_2);
  __CPROVER_assume(sec_r001214_16_1 != sec_r001214_16_2);
  __CPROVER_assume(pub_r001214_16_1 == pub_r001214_16_2);
  __CPROVER_assume(pub_r001214_20_1 == pub_r001214_20_2);
  __CPROVER_assume(pub_r001214_21_1 == pub_r001214_21_2);
  __CPROVER_assume(sec_r001214_11_1 != sec_r001214_11_2);
  __CPROVER_assume(pub_r001214_6_1 == pub_r001214_6_2);
  __CPROVER_assume(pub_r001214_18_1 == pub_r001214_18_2);
  __CPROVER_assume(sec_r001214_20_1 != sec_r001214_20_2);
  __CPROVER_assume(sec_r001214_2_1 != sec_r001214_2_2);
  __CPROVER_assume(sec_r001214_9_1 != sec_r001214_9_2);
  __CPROVER_assume(sec_r001214_7_1 != sec_r001214_7_2);
  __CPROVER_assume(sec_r001214_17_1 != sec_r001214_17_2);
  __CPROVER_assume(pub_r001214_14_1 == pub_r001214_14_2);
  __CPROVER_assume(pub_r001214_9_1 == pub_r001214_9_2);
  __CPROVER_assume(sec_r001214_18_1 != sec_r001214_18_2);
  __CPROVER_assume(sec_r001214_3_1 != sec_r001214_3_2);
  __CPROVER_assume(pub_r001214_3_1 == pub_r001214_3_2);
  __CPROVER_assume(pub_r001214_0_1 == pub_r001214_0_2);
  __CPROVER_assume(pub_r001214_7_1 == pub_r001214_7_2);
  __CPROVER_assume(pub_r001214_1_1 == pub_r001214_1_2);
  __CPROVER_assume(sec_r001214_4_1 != sec_r001214_4_2);
  __CPROVER_assume(sec_r001214_0_1 != sec_r001214_0_2);
  __CPROVER_assume(sec_r001214_8_1 != sec_r001214_8_2);
  __CPROVER_assume(sec_r001214_13_1 != sec_r001214_13_2);
  __CPROVER_assume(sec_r001214_10_1 != sec_r001214_10_2);
  __CPROVER_assume(pub_r001214_2_1 == pub_r001214_2_2);
  __CPROVER_assume(pub_r001214_11_1 == pub_r001214_11_2);
  __CPROVER_assume(pub_r001214_17_1 == pub_r001214_17_2);
  __CPROVER_assume(pub_r001214_19_1 == pub_r001214_19_2);
  __CPROVER_assume(pub_r001214_15_1 == pub_r001214_15_2);
  __CPROVER_assume(sec_r001214_12_1 != sec_r001214_12_2);
  __CPROVER_assume(pub_r001214_4_1 == pub_r001214_4_2);
  __CPROVER_assume(pub_r001214_5_1 == pub_r001214_5_2);
  __CPROVER_assume(pub_r001214_8_1 == pub_r001214_8_2);
  __CPROVER_assume(sec_r001214_5_1 != sec_r001214_5_2);
  __CPROVER_assume(pub_r001214_13_1 == pub_r001214_13_2);
  __CPROVER_assume(sec_r001214_1_1 != sec_r001214_1_2);
  __CPROVER_assume(sec_r001214_14_1 != sec_r001214_14_2);
  __CPROVER_assume(sec_r001214_15_1 != sec_r001214_15_2);
  __CPROVER_assume(pub_r001214_12_1 == pub_r001214_12_2);
  __CPROVER_assume(sec_r001214_6_1 != sec_r001214_6_2);
  __CPROVER_assume(pub_r001214_10_1 == pub_r001214_10_2);
  __CPROVER_assume(sec_r001214_19_1 != sec_r001214_19_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.status == st_var_3_2.status);
  assert(st_var_3_1.threshold == st_var_3_2.threshold);
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
  assert(stage_v_429_1 == stage_v_429_2);
  assert(stage_v_430_1 == stage_v_430_2);
  assert(stage_v_431_1 == stage_v_431_2);
  assert(stage_v_432_1 == stage_v_432_2);
  assert(stage_v_433_1 == stage_v_433_2);
  assert(stage_v_434_1 == stage_v_434_2);
  assert(stage_v_435_1 == stage_v_435_2);
  assert(stage_v_436_1 == stage_v_436_2);
  assert(stage_v_437_1 == stage_v_437_2);
  assert(stage_v_438_1 == stage_v_438_2);
  assert(stage_v_439_1 == stage_v_439_2);
  assert(stage_v_440_1 == stage_v_440_2);
  assert(stage_v_441_1 == stage_v_441_2);
  assert(stage_v_442_1 == stage_v_442_2);
  assert(stage_v_443_1 == stage_v_443_2);
  assert(stage_v_444_1 == stage_v_444_2);
  assert(stage_v_445_1 == stage_v_445_2);
}


