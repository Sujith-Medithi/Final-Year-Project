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
struct StreamBuffer_R001134_3413_0
{
  int watermark;
  unsigned char state;
  int head;
  int buffer[3];
};
struct AudioFrame_R001134_3413_1
{
  short gain;
  unsigned char sample_rate;
  short rms;
  unsigned char peak;
  int buffer[3];
};
struct DeviceConfig_R001134_3413_2
{
  unsigned char port;
  int parity;
  int timeout;
  unsigned char baud_rate;
  short stop_bits;
  unsigned char id;
  int buffer[3];
};
struct FilterState_R001134_3413_3
{
  int gain_db;
  unsigned char prev_out;
  int cutoff;
  unsigned char prev_in;
  unsigned char mode;
  int damping;
  int buffer[3];
};
union PacketPayload_R001134_3413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001134_3413_1
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
void fn_R001134_3413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001134_3413_3 st_1 = {0};
  struct FilterState_R001134_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_21_1 = local_arr_1[aux_1 % 3];
  int stride_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_21_2 * 2)) & 127;
  int metric_61_1 = 0;
  int metric_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_61_1 = ((metric_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_61_2 = ((metric_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_61_1) & 127;
    acc_2 = (acc_2 + metric_61_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_21_1 == stride_21_2);
  assert(metric_61_1 == metric_61_2);
}

int fn_R001134_3413_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001134_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int stride_21 = local_arr[aux % 3];
  acc = (acc + (stride_21 * 2)) & 127;
  int metric_61 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_61 = ((metric_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_61) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001134_3413_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001134_3413_0 st_1 = {0};
  struct StreamBuffer_R001134_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int tracker_36_1 = 0;
  int tracker_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_36_1 = ((tracker_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_36_2 = ((tracker_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_36_1) & 127;
    acc_2 = (acc_2 + tracker_36_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_36_1 == tracker_36_2);
}

int fn_R001134_3413_1(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001134_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int tracker_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_36 = ((tracker_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_36) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001134_3413_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001134_3413_2 st_1 = {0};
  struct DeviceConfig_R001134_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_51_1 = local_arr_1[aux_1 % 3];
  int cursor_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_51_2 * 2)) & 127;
  int coefficient_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_56_1)
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

  switch (coefficient_56_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_51_1 == cursor_51_2);
  assert(coefficient_56_1 == coefficient_56_2);
}

int fn_R001134_3413_2(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001134_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int cursor_51 = local_arr[aux % 3];
  acc = (acc + (cursor_51 * 2)) & 127;
  int coefficient_56 = (aux + st.buffer[1]) & 3;
  switch (coefficient_56)
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

void fn_R001134_3413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001134_3413_1 st_1 = {0};
  struct AudioFrame_R001134_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int accumulator_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_72_1) & 63;
  aux_2 = (aux_2 + accumulator_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_94_1 = 0;
  int scale_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_94_1 = ((scale_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_94_2 = ((scale_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_94_1) & 127;
    acc_2 = (acc_2 + scale_94_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_36_1 = local_arr_1[aux_1 % 3];
  int segment_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_36_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_72_1 == accumulator_72_2);
  assert(scale_94_1 == scale_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_36_1 == segment_36_2);
}

int fn_R001134_3413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001134_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int accumulator_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_72) & 63;
  acc ^= aux;
  int scale_94 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_94 = ((scale_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_94) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_36 = local_arr[aux % 3];
  acc = (acc + (segment_36 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001134_3413_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001134_3413_2 st_1 = {0};
  struct DeviceConfig_R001134_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int weight_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_86_1 > 37)
  {
    acc_1 = ((acc_1 + (weight_86_1 * 2)) + 5) & 127;
    aux_1 ^= weight_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_86_2 > 37)
  {
    acc_2 = ((acc_2 + (weight_86_2 * 2)) + 5) & 127;
    aux_2 ^= weight_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_38_1 = local_arr_1[aux_1 % 3];
  int residue_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_38_2 * 2)) & 127;
  int anchor_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_40_1)
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

  switch (anchor_40_2)
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

  int coefficient_35_1 = 0;
  int coefficient_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_35_1 = ((coefficient_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_35_2 = ((coefficient_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_35_1) & 127;
    acc_2 = (acc_2 + coefficient_35_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_86_1 == weight_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_38_1 == residue_38_2);
  assert(anchor_40_1 == anchor_40_2);
  assert(coefficient_35_1 == coefficient_35_2);
}

int fn_R001134_3413_4(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001134_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int weight_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_86 > 37)
  {
    acc = ((acc + (weight_86 * 2)) + 5) & 127;
    aux ^= weight_86 & 15;
  }
  else
  {
    acc = ((acc - weight_86) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_38 = local_arr[aux % 3];
  acc = (acc + (residue_38 * 2)) & 127;
  int anchor_40 = (aux + st.buffer[1]) & 3;
  switch (anchor_40)
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

  int coefficient_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_35 = ((coefficient_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_35) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001134_3413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001134_3413_1 st_1 = {0};
  struct AudioFrame_R001134_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_27_1) & 63;
  aux_2 = (aux_2 + delta_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_12_1 > 47)
  {
    acc_1 = ((acc_1 + (phase_12_1 * 2)) + 5) & 127;
    aux_1 ^= phase_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_12_2 > 47)
  {
    acc_2 = ((acc_2 + (phase_12_2 * 2)) + 5) & 127;
    aux_2 ^= phase_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_27_1 == delta_27_2);
  assert(phase_12_1 == phase_12_2);
}

int fn_R001134_3413_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001134_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_27) & 63;
  acc ^= aux;
  int phase_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_12 > 47)
  {
    acc = ((acc + (phase_12 * 2)) + 5) & 127;
    aux ^= phase_12 & 15;
  }
  else
  {
    acc = ((acc - phase_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001134_3413_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001134_3413_1 st_1 = {0};
  struct AudioFrame_R001134_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int phase_33_1 = 0;
  int phase_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_33_1 = ((phase_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_33_2 = ((phase_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_33_1) & 127;
    acc_2 = (acc_2 + phase_33_2) & 127;
  }

  int sample_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_93_1)
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

  switch (sample_93_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_33_1 == phase_33_2);
  assert(sample_93_1 == sample_93_2);
}

int fn_R001134_3413_6(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001134_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int phase_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_33 = ((phase_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_33) & 127;
  }

  int sample_93 = (aux + st.buffer[1]) & 3;
  switch (sample_93)
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

void fn_R001134_3413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001134_3413_0 st_1 = {0};
  struct StreamBuffer_R001134_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int stride_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_50_1 > 11)
  {
    acc_1 = ((acc_1 + (stride_50_1 * 2)) + 5) & 127;
    aux_1 ^= stride_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_50_2 > 11)
  {
    acc_2 = ((acc_2 + (stride_50_2 * 2)) + 5) & 127;
    aux_2 ^= stride_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_82_1)
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

  switch (phase_82_2)
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

  int tracker_36_1 = 0;
  int tracker_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_36_1 = ((tracker_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_36_2 = ((tracker_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_36_1) & 127;
    acc_2 = (acc_2 + tracker_36_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_99_1 = local_arr_1[aux_1 % 3];
  int segment_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_50_1 == stride_50_2);
  assert(phase_82_1 == phase_82_2);
  assert(tracker_36_1 == tracker_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_99_1 == segment_99_2);
}

int fn_R001134_3413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001134_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int stride_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_50 > 11)
  {
    acc = ((acc + (stride_50 * 2)) + 5) & 127;
    aux ^= stride_50 & 15;
  }
  else
  {
    acc = ((acc - stride_50) + 11) & 127;
    aux += 3;
  }
  int phase_82 = (aux + st.buffer[1]) & 3;
  switch (phase_82)
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

  int tracker_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_36 = ((tracker_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_36) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_99 = local_arr[aux % 3];
  acc = (acc + (segment_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001134_3413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001134_3413_1 st_1 = {0};
  struct AudioFrame_R001134_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int mask_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_25_1)
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

  switch (mask_25_2)
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

  int quotient_62_1 = 0;
  int quotient_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_62_1 = ((quotient_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_62_2 = ((quotient_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_62_1) & 127;
    acc_2 = (acc_2 + quotient_62_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_75_1 = local_arr_1[aux_1 % 3];
  int index_reg_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_75_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_25_1 == mask_25_2);
  assert(quotient_62_1 == quotient_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_75_1 == index_reg_75_2);
}

int fn_R001134_3413_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001134_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int mask_25 = (aux + st.buffer[1]) & 3;
  switch (mask_25)
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

  int quotient_62 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_62 = ((quotient_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_62) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int index_reg_75 = local_arr[aux % 3];
  acc = (acc + (index_reg_75 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001134_3413_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001134_3413_2 st_1 = {0};
  struct DeviceConfig_R001134_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int delta_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_95_1 > 13)
  {
    acc_1 = ((acc_1 + (delta_95_1 * 2)) + 5) & 127;
    aux_1 ^= delta_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_95_2 > 13)
  {
    acc_2 = ((acc_2 + (delta_95_2 * 2)) + 5) & 127;
    aux_2 ^= delta_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_31_1 = local_arr_1[aux_1 % 3];
  int stride_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_31_2 * 2)) & 127;
  int delta_56_1 = 0;
  int delta_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_56_1 = ((delta_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_56_2 = ((delta_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_56_1) & 127;
    acc_2 = (acc_2 + delta_56_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_95_1 == delta_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_31_1 == stride_31_2);
  assert(delta_56_1 == delta_56_2);
}

int fn_R001134_3413_9(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001134_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int delta_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_95 > 13)
  {
    acc = ((acc + (delta_95 * 2)) + 5) & 127;
    aux ^= delta_95 & 15;
  }
  else
  {
    acc = ((acc - delta_95) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_31 = local_arr[aux % 3];
  acc = (acc + (stride_31 * 2)) & 127;
  int delta_56 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_56 = ((delta_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_56) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001134_3413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001134_3413_1 st_1 = {0};
  struct AudioFrame_R001134_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int phase_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_12_1 > 49)
  {
    acc_1 = ((acc_1 + (phase_12_1 * 2)) + 5) & 127;
    aux_1 ^= phase_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_12_2 > 49)
  {
    acc_2 = ((acc_2 + (phase_12_2 * 2)) + 5) & 127;
    aux_2 ^= phase_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_45_1 = 0;
  int sample_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_45_1 = ((sample_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_45_2 = ((sample_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_45_1) & 127;
    acc_2 = (acc_2 + sample_45_2) & 127;
  }

  int pivot_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_91_1) & 63;
  aux_2 = (aux_2 + pivot_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_12_1 == phase_12_2);
  assert(sample_45_1 == sample_45_2);
  assert(pivot_91_1 == pivot_91_2);
}

int fn_R001134_3413_10(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001134_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int phase_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_12 > 49)
  {
    acc = ((acc + (phase_12 * 2)) + 5) & 127;
    aux ^= phase_12 & 15;
  }
  else
  {
    acc = ((acc - phase_12) + 11) & 127;
    aux += 3;
  }
  int sample_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_45 = ((sample_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_45) & 127;
  }

  int pivot_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_91) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001134_3413_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001134_3413_0 st_1 = {0};
  struct StreamBuffer_R001134_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int bound_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_78_1 > 42)
  {
    acc_1 = ((acc_1 + (bound_78_1 * 2)) + 5) & 127;
    aux_1 ^= bound_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_78_2 > 42)
  {
    acc_2 = ((acc_2 + (bound_78_2 * 2)) + 5) & 127;
    aux_2 ^= bound_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_18_1) & 63;
  aux_2 = (aux_2 + metric_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_16_1)
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

  switch (residue_16_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_78_1 == bound_78_2);
  assert(metric_18_1 == metric_18_2);
  assert(residue_16_1 == residue_16_2);
}

int fn_R001134_3413_11(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001134_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int bound_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_78 > 42)
  {
    acc = ((acc + (bound_78 * 2)) + 5) & 127;
    aux ^= bound_78 & 15;
  }
  else
  {
    acc = ((acc - bound_78) + 11) & 127;
    aux += 3;
  }
  int metric_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_18) & 63;
  acc ^= aux;
  int residue_16 = (aux + st.buffer[1]) & 3;
  switch (residue_16)
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

void fn_R001134_3413_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001134_3413_2 st_1 = {0};
  struct DeviceConfig_R001134_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_20_1 > 10)
  {
    acc_1 = ((acc_1 + (factor_20_1 * 2)) + 5) & 127;
    aux_1 ^= factor_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_20_2 > 10)
  {
    acc_2 = ((acc_2 + (factor_20_2 * 2)) + 5) & 127;
    aux_2 ^= factor_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_20_1 == factor_20_2);
}

int fn_R001134_3413_12(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001134_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_20 > 10)
  {
    acc = ((acc + (factor_20 * 2)) + 5) & 127;
    aux ^= factor_20 & 15;
  }
  else
  {
    acc = ((acc - factor_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001134_3413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001134_3413_3 st_1 = {0};
  struct FilterState_R001134_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int segment_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_43_1) & 63;
  aux_2 = (aux_2 + segment_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_58_1 = 0;
  int accumulator_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_58_1 = ((accumulator_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_58_2 = ((accumulator_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_58_1) & 127;
    acc_2 = (acc_2 + accumulator_58_2) & 127;
  }

  int segment_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_97_1 > 16)
  {
    acc_1 = ((acc_1 + (segment_97_1 * 2)) + 5) & 127;
    aux_1 ^= segment_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_97_2 > 16)
  {
    acc_2 = ((acc_2 + (segment_97_2 * 2)) + 5) & 127;
    aux_2 ^= segment_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_43_1 == segment_43_2);
  assert(accumulator_58_1 == accumulator_58_2);
  assert(segment_97_1 == segment_97_2);
}

int fn_R001134_3413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001134_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int segment_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_43) & 63;
  acc ^= aux;
  int accumulator_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_58 = ((accumulator_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_58) & 127;
  }

  int segment_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_97 > 16)
  {
    acc = ((acc + (segment_97 * 2)) + 5) & 127;
    aux ^= segment_97 & 15;
  }
  else
  {
    acc = ((acc - segment_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001134_3413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001134_3413_0 st_1 = {0};
  struct StreamBuffer_R001134_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_37_1 = local_arr_1[aux_1 % 3];
  int vector_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_37_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_99_1) & 63;
  aux_2 = (aux_2 + index_reg_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_37_1 == vector_37_2);
  assert(index_reg_99_1 == index_reg_99_2);
}

int fn_R001134_3413_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001134_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int vector_37 = local_arr[aux % 3];
  acc = (acc + (vector_37 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001134_3413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001134_3413_3 st_1 = {0};
  struct FilterState_R001134_3413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int offset_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_32_1 > 17)
  {
    acc_1 = ((acc_1 + (offset_32_1 * 2)) + 5) & 127;
    aux_1 ^= offset_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_32_2 > 17)
  {
    acc_2 = ((acc_2 + (offset_32_2 * 2)) + 5) & 127;
    aux_2 ^= offset_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_92_1 = 0;
  int bound_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_92_1 = ((bound_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_92_2 = ((bound_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_92_1) & 127;
    acc_2 = (acc_2 + bound_92_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_77_1 = local_arr_1[aux_1 % 3];
  int parity_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_77_2 * 2)) & 127;
  int phase_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_83_1)
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

  switch (phase_83_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_32_1 == offset_32_2);
  assert(bound_92_1 == bound_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_77_1 == parity_77_2);
  assert(phase_83_1 == phase_83_2);
}

int fn_R001134_3413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001134_3413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int offset_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_32 > 17)
  {
    acc = ((acc + (offset_32 * 2)) + 5) & 127;
    aux ^= offset_32 & 15;
  }
  else
  {
    acc = ((acc - offset_32) + 11) & 127;
    aux += 3;
  }
  int bound_92 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_92 = ((bound_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_92) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int parity_77 = local_arr[aux % 3];
  acc = (acc + (parity_77 * 2)) & 127;
  int phase_83 = (aux + st.buffer[1]) & 3;
  switch (phase_83)
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

void main()
{
  int sec_r001134_0_1;
  int sec_r001134_0_2;
  int sec_r001134_1_1;
  int sec_r001134_1_2;
  int sec_r001134_2_1;
  int sec_r001134_2_2;
  int sec_r001134_3_1;
  int sec_r001134_3_2;
  int sec_r001134_4_1;
  int sec_r001134_4_2;
  int sec_r001134_5_1;
  int sec_r001134_5_2;
  int sec_r001134_6_1;
  int sec_r001134_6_2;
  int sec_r001134_7_1;
  int sec_r001134_7_2;
  int sec_r001134_8_1;
  int sec_r001134_8_2;
  int sec_r001134_9_1;
  int sec_r001134_9_2;
  int sec_r001134_10_1;
  int sec_r001134_10_2;
  int sec_r001134_11_1;
  int sec_r001134_11_2;
  int sec_r001134_12_1;
  int sec_r001134_12_2;
  int sec_r001134_13_1;
  int sec_r001134_13_2;
  int sec_r001134_14_1;
  int sec_r001134_14_2;
  int sec_r001134_15_1;
  int sec_r001134_15_2;
  int sec_r001134_16_1;
  int sec_r001134_16_2;
  int pub_r001134_0_1;
  int pub_r001134_0_2;
  int pub_r001134_1_1;
  int pub_r001134_1_2;
  int pub_r001134_2_1;
  int pub_r001134_2_2;
  int pub_r001134_3_1;
  int pub_r001134_3_2;
  int pub_r001134_4_1;
  int pub_r001134_4_2;
  int pub_r001134_5_1;
  int pub_r001134_5_2;
  int pub_r001134_6_1;
  int pub_r001134_6_2;
  int pub_r001134_7_1;
  int pub_r001134_7_2;
  int pub_r001134_8_1;
  int pub_r001134_8_2;
  int pub_r001134_9_1;
  int pub_r001134_9_2;
  int pub_r001134_10_1;
  int pub_r001134_10_2;
  int pub_r001134_11_1;
  int pub_r001134_11_2;
  int pub_r001134_12_1;
  int pub_r001134_12_2;
  int pub_r001134_13_1;
  int pub_r001134_13_2;
  int pub_r001134_14_1;
  int pub_r001134_14_2;
  int pub_r001134_15_1;
  int pub_r001134_15_2;
  int pub_r001134_16_1;
  int pub_r001134_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001134_0_1 >= (-100)) && (pub_r001134_0_1 <= 100));
  __CPROVER_assume((pub_r001134_0_2 >= (-100)) && (pub_r001134_0_2 <= 100));
  __CPROVER_assume((pub_r001134_1_1 >= (-100)) && (pub_r001134_1_1 <= 100));
  __CPROVER_assume((pub_r001134_1_2 >= (-100)) && (pub_r001134_1_2 <= 100));
  __CPROVER_assume((pub_r001134_2_1 >= (-100)) && (pub_r001134_2_1 <= 100));
  __CPROVER_assume((pub_r001134_2_2 >= (-100)) && (pub_r001134_2_2 <= 100));
  __CPROVER_assume((pub_r001134_3_1 >= (-100)) && (pub_r001134_3_1 <= 100));
  __CPROVER_assume((pub_r001134_3_2 >= (-100)) && (pub_r001134_3_2 <= 100));
  __CPROVER_assume((pub_r001134_4_1 >= (-100)) && (pub_r001134_4_1 <= 100));
  __CPROVER_assume((pub_r001134_4_2 >= (-100)) && (pub_r001134_4_2 <= 100));
  __CPROVER_assume((pub_r001134_5_1 >= (-100)) && (pub_r001134_5_1 <= 100));
  __CPROVER_assume((pub_r001134_5_2 >= (-100)) && (pub_r001134_5_2 <= 100));
  __CPROVER_assume((pub_r001134_6_1 >= (-100)) && (pub_r001134_6_1 <= 100));
  __CPROVER_assume((pub_r001134_6_2 >= (-100)) && (pub_r001134_6_2 <= 100));
  __CPROVER_assume((pub_r001134_7_1 >= (-100)) && (pub_r001134_7_1 <= 100));
  __CPROVER_assume((pub_r001134_7_2 >= (-100)) && (pub_r001134_7_2 <= 100));
  __CPROVER_assume((pub_r001134_8_1 >= (-100)) && (pub_r001134_8_1 <= 100));
  __CPROVER_assume((pub_r001134_8_2 >= (-100)) && (pub_r001134_8_2 <= 100));
  __CPROVER_assume((pub_r001134_9_1 >= (-100)) && (pub_r001134_9_1 <= 100));
  __CPROVER_assume((pub_r001134_9_2 >= (-100)) && (pub_r001134_9_2 <= 100));
  __CPROVER_assume((pub_r001134_10_1 >= (-100)) && (pub_r001134_10_1 <= 100));
  __CPROVER_assume((pub_r001134_10_2 >= (-100)) && (pub_r001134_10_2 <= 100));
  __CPROVER_assume((pub_r001134_11_1 >= (-100)) && (pub_r001134_11_1 <= 100));
  __CPROVER_assume((pub_r001134_11_2 >= (-100)) && (pub_r001134_11_2 <= 100));
  __CPROVER_assume((pub_r001134_12_1 >= (-100)) && (pub_r001134_12_1 <= 100));
  __CPROVER_assume((pub_r001134_12_2 >= (-100)) && (pub_r001134_12_2 <= 100));
  __CPROVER_assume((pub_r001134_13_1 >= (-100)) && (pub_r001134_13_1 <= 100));
  __CPROVER_assume((pub_r001134_13_2 >= (-100)) && (pub_r001134_13_2 <= 100));
  __CPROVER_assume((pub_r001134_14_1 >= (-100)) && (pub_r001134_14_1 <= 100));
  __CPROVER_assume((pub_r001134_14_2 >= (-100)) && (pub_r001134_14_2 <= 100));
  __CPROVER_assume((pub_r001134_15_1 >= (-100)) && (pub_r001134_15_1 <= 100));
  __CPROVER_assume((pub_r001134_15_2 >= (-100)) && (pub_r001134_15_2 <= 100));
  __CPROVER_assume((pub_r001134_16_1 >= (-100)) && (pub_r001134_16_1 <= 100));
  __CPROVER_assume((pub_r001134_16_2 >= (-100)) && (pub_r001134_16_2 <= 100));
  __CPROVER_assume((sec_r001134_0_1 >= 0) && (sec_r001134_0_1 <= 255));
  __CPROVER_assume((sec_r001134_0_2 >= 0) && (sec_r001134_0_2 <= 255));
  __CPROVER_assume((sec_r001134_1_1 >= 0) && (sec_r001134_1_1 <= 255));
  __CPROVER_assume((sec_r001134_1_2 >= 0) && (sec_r001134_1_2 <= 255));
  __CPROVER_assume((sec_r001134_2_1 >= 0) && (sec_r001134_2_1 <= 255));
  __CPROVER_assume((sec_r001134_2_2 >= 0) && (sec_r001134_2_2 <= 255));
  __CPROVER_assume((sec_r001134_3_1 >= 0) && (sec_r001134_3_1 <= 255));
  __CPROVER_assume((sec_r001134_3_2 >= 0) && (sec_r001134_3_2 <= 255));
  __CPROVER_assume((sec_r001134_4_1 >= 0) && (sec_r001134_4_1 <= 255));
  __CPROVER_assume((sec_r001134_4_2 >= 0) && (sec_r001134_4_2 <= 255));
  __CPROVER_assume((sec_r001134_5_1 >= 0) && (sec_r001134_5_1 <= 255));
  __CPROVER_assume((sec_r001134_5_2 >= 0) && (sec_r001134_5_2 <= 255));
  __CPROVER_assume((sec_r001134_6_1 >= 0) && (sec_r001134_6_1 <= 255));
  __CPROVER_assume((sec_r001134_6_2 >= 0) && (sec_r001134_6_2 <= 255));
  __CPROVER_assume((sec_r001134_7_1 >= 0) && (sec_r001134_7_1 <= 255));
  __CPROVER_assume((sec_r001134_7_2 >= 0) && (sec_r001134_7_2 <= 255));
  __CPROVER_assume((sec_r001134_8_1 >= 0) && (sec_r001134_8_1 <= 255));
  __CPROVER_assume((sec_r001134_8_2 >= 0) && (sec_r001134_8_2 <= 255));
  __CPROVER_assume((sec_r001134_9_1 >= 0) && (sec_r001134_9_1 <= 255));
  __CPROVER_assume((sec_r001134_9_2 >= 0) && (sec_r001134_9_2 <= 255));
  __CPROVER_assume((sec_r001134_10_1 >= 0) && (sec_r001134_10_1 <= 255));
  __CPROVER_assume((sec_r001134_10_2 >= 0) && (sec_r001134_10_2 <= 255));
  __CPROVER_assume((sec_r001134_11_1 >= 0) && (sec_r001134_11_1 <= 255));
  __CPROVER_assume((sec_r001134_11_2 >= 0) && (sec_r001134_11_2 <= 255));
  __CPROVER_assume((sec_r001134_12_1 >= 0) && (sec_r001134_12_1 <= 255));
  __CPROVER_assume((sec_r001134_12_2 >= 0) && (sec_r001134_12_2 <= 255));
  __CPROVER_assume((sec_r001134_13_1 >= 0) && (sec_r001134_13_1 <= 255));
  __CPROVER_assume((sec_r001134_13_2 >= 0) && (sec_r001134_13_2 <= 255));
  __CPROVER_assume((sec_r001134_14_1 >= 0) && (sec_r001134_14_1 <= 255));
  __CPROVER_assume((sec_r001134_14_2 >= 0) && (sec_r001134_14_2 <= 255));
  __CPROVER_assume((sec_r001134_15_1 >= 0) && (sec_r001134_15_1 <= 255));
  __CPROVER_assume((sec_r001134_15_2 >= 0) && (sec_r001134_15_2 <= 255));
  __CPROVER_assume((sec_r001134_16_1 >= 0) && (sec_r001134_16_1 <= 255));
  __CPROVER_assume((sec_r001134_16_2 >= 0) && (sec_r001134_16_2 <= 255));
  struct StreamBuffer_R001134_3413_0 st_var_0_1 = {0};
  struct StreamBuffer_R001134_3413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001134_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001134_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001134_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001134_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001134_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001134_0_2 + 7) & 15;
  struct AudioFrame_R001134_3413_1 st_var_1_1 = {0};
  struct AudioFrame_R001134_3413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001134_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001134_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001134_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001134_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001134_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001134_0_2 + 9) & 15;
  struct DeviceConfig_R001134_3413_2 st_var_2_1 = {0};
  struct DeviceConfig_R001134_3413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001134_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001134_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001134_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001134_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001134_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001134_0_2 + 11) & 15;
  struct FilterState_R001134_3413_3 st_var_3_1 = {0};
  struct FilterState_R001134_3413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001134_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001134_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001134_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001134_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001134_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001134_0_2 + 13) & 15;
  union PacketPayload_R001134_3413_0 u_var_1;
  union PacketPayload_R001134_3413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001134_3413_0(sec_r001134_0_1, sec_r001134_1_1, pub_r001134_2_1, pub_r001134_3_1, pub_r001134_4_1);
  int helper_flow_0_2 = fn_R001134_3413_0(sec_r001134_0_2, sec_r001134_1_2, pub_r001134_2_2, pub_r001134_3_2, pub_r001134_4_2);
  fn_R001134_3413_0_2(sec_r001134_0_1, sec_r001134_1_1, pub_r001134_2_1, pub_r001134_3_1, pub_r001134_4_1, sec_r001134_0_2, sec_r001134_1_2, pub_r001134_2_2, pub_r001134_3_2, pub_r001134_4_2);
  int helper_flow_1_1 = fn_R001134_3413_1(sec_r001134_1_1, sec_r001134_2_1, pub_r001134_3_1);
  int helper_flow_1_2 = fn_R001134_3413_1(sec_r001134_1_2, sec_r001134_2_2, pub_r001134_3_2);
  fn_R001134_3413_1_2(sec_r001134_1_1, sec_r001134_2_1, pub_r001134_3_1, sec_r001134_1_2, sec_r001134_2_2, pub_r001134_3_2);
  int helper_flow_2_1 = fn_R001134_3413_2(sec_r001134_2_1, pub_r001134_3_1);
  int helper_flow_2_2 = fn_R001134_3413_2(sec_r001134_2_2, pub_r001134_3_2);
  fn_R001134_3413_2_2(sec_r001134_2_1, pub_r001134_3_1, sec_r001134_2_2, pub_r001134_3_2);
  int helper_flow_3_1 = fn_R001134_3413_3(sec_r001134_3_1, pub_r001134_4_1, pub_r001134_5_1, pub_r001134_6_1, pub_r001134_7_1);
  int helper_flow_3_2 = fn_R001134_3413_3(sec_r001134_3_2, pub_r001134_4_2, pub_r001134_5_2, pub_r001134_6_2, pub_r001134_7_2);
  fn_R001134_3413_3_2(sec_r001134_3_1, pub_r001134_4_1, pub_r001134_5_1, pub_r001134_6_1, pub_r001134_7_1, sec_r001134_3_2, pub_r001134_4_2, pub_r001134_5_2, pub_r001134_6_2, pub_r001134_7_2);
  int helper_flow_4_1 = fn_R001134_3413_4(sec_r001134_4_1, pub_r001134_5_1, pub_r001134_6_1);
  int helper_flow_4_2 = fn_R001134_3413_4(sec_r001134_4_2, pub_r001134_5_2, pub_r001134_6_2);
  fn_R001134_3413_4_2(sec_r001134_4_1, pub_r001134_5_1, pub_r001134_6_1, sec_r001134_4_2, pub_r001134_5_2, pub_r001134_6_2);
  int stage_v_0_1 = (((helper_flow_4_1 * 3) + pub_r001134_8_1) + 28) & 127;
  int stage_v_0_2 = (((helper_flow_4_2 * 3) + pub_r001134_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = (((sec_r001134_5_1 * 3) + pub_r001134_5_1) + 32) & 127;
  int stage_v_1_2 = (((sec_r001134_5_2 * 3) + pub_r001134_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001134_5_1 * 2) + 8) & 63;
  int stage_v_2_2 = ((pub_r001134_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001134_8_1 * 3) + pub_r001134_7_1) + 21) & 127;
  int stage_v_3_2 = (((sec_r001134_8_2 * 3) + pub_r001134_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((sec_r001134_3_1 * 3) + pub_r001134_3_1) + 24) & 127;
  int stage_v_4_2 = (((sec_r001134_3_2 * 3) + pub_r001134_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = (((sec_r001134_16_1 * 3) + pub_r001134_12_1) + 13) & 127;
  int stage_v_5_2 = (((sec_r001134_16_2 * 3) + pub_r001134_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((sec_r001134_1_1 * 3) + pub_r001134_3_1) + 7) & 127;
  int stage_v_6_2 = (((sec_r001134_1_2 * 3) + pub_r001134_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = (((sec_r001134_12_1 * 3) + pub_r001134_5_1) + 40) & 127;
  int stage_v_7_2 = (((sec_r001134_12_2 * 3) + pub_r001134_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001134_11_1 * 2) + 5) & 63;
  int stage_v_8_2 = ((pub_r001134_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001134_7_1 * 2) + 19) & 63;
  int stage_v_9_2 = ((pub_r001134_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((helper_flow_3_1 * 3) + pub_r001134_15_1) + 5) & 127;
  int stage_v_10_2 = (((helper_flow_3_2 * 3) + pub_r001134_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001134_6_1 * 2) + 13) & 63;
  int stage_v_11_2 = ((pub_r001134_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001134_3_1 * 2) + 39) & 63;
  int stage_v_12_2 = ((pub_r001134_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((stage_v_5_1 * 3) + pub_r001134_10_1) + 26) & 127;
  int stage_v_13_2 = (((stage_v_5_2 * 3) + pub_r001134_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = ((pub_r001134_12_1 * 2) + 49) & 63;
  int stage_v_14_2 = ((pub_r001134_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001134_3_1 * 2) + 8) & 63;
  int stage_v_15_2 = ((pub_r001134_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((stage_v_5_1 * 3) + pub_r001134_10_1) + 45) & 127;
  int stage_v_16_2 = (((stage_v_5_2 * 3) + pub_r001134_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((sec_r001134_9_1 * 3) + pub_r001134_6_1) + 17) & 127;
  int stage_v_17_2 = (((sec_r001134_9_2 * 3) + pub_r001134_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001134_10_1 * 2) + 16) & 63;
  int stage_v_18_2 = ((pub_r001134_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001134_1_1 * 2) + 9) & 63;
  int stage_v_19_2 = ((pub_r001134_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001134_10_1 * 2) + 38) & 63;
  int stage_v_20_2 = ((pub_r001134_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001134_0_1 * 2) + 26) & 63;
  int stage_v_21_2 = ((pub_r001134_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001134_1_1 * 2) + 13) & 63;
  int stage_v_22_2 = ((pub_r001134_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001134_12_1 * 2) + 27) & 63;
  int stage_v_23_2 = ((pub_r001134_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((sec_r001134_5_1 * 3) + pub_r001134_5_1) + 23) & 127;
  int stage_v_24_2 = (((sec_r001134_5_2 * 3) + pub_r001134_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001134_0_1 * 2) + 16) & 63;
  int stage_v_25_2 = ((pub_r001134_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001134_9_1 * 2) + 11) & 63;
  int stage_v_26_2 = ((pub_r001134_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001134_11_1 * 2) + 44) & 63;
  int stage_v_27_2 = ((pub_r001134_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001134_6_1 * 3) + pub_r001134_9_1) + 14) & 127;
  int stage_v_28_2 = (((sec_r001134_6_2 * 3) + pub_r001134_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((helper_flow_0_1 * 3) + pub_r001134_5_1) + 19) & 127;
  int stage_v_29_2 = (((helper_flow_0_2 * 3) + pub_r001134_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((helper_flow_2_1 * 3) + pub_r001134_1_1) + 35) & 127;
  int stage_v_30_2 = (((helper_flow_2_2 * 3) + pub_r001134_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001134_1_1 * 2) + 38) & 63;
  int stage_v_31_2 = ((pub_r001134_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((sec_r001134_7_1 * 3) + pub_r001134_15_1) + 10) & 127;
  int stage_v_32_2 = (((sec_r001134_7_2 * 3) + pub_r001134_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = ((pub_r001134_9_1 * 2) + 45) & 63;
  int stage_v_33_2 = ((pub_r001134_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((sec_r001134_5_1 * 3) + pub_r001134_10_1) + 40) & 127;
  int stage_v_34_2 = (((sec_r001134_5_2 * 3) + pub_r001134_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = (((helper_flow_0_1 * 3) + pub_r001134_14_1) + 43) & 127;
  int stage_v_35_2 = (((helper_flow_0_2 * 3) + pub_r001134_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = ((pub_r001134_12_1 * 2) + 46) & 63;
  int stage_v_36_2 = ((pub_r001134_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((sec_r001134_3_1 * 3) + pub_r001134_0_1) + 10) & 127;
  int stage_v_37_2 = (((sec_r001134_3_2 * 3) + pub_r001134_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = (((sec_r001134_3_1 * 3) + pub_r001134_8_1) + 22) & 127;
  int stage_v_38_2 = (((sec_r001134_3_2 * 3) + pub_r001134_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((stage_v_4_1 * 3) + pub_r001134_8_1) + 41) & 127;
  int stage_v_39_2 = (((stage_v_4_2 * 3) + pub_r001134_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = (((sec_r001134_14_1 * 3) + pub_r001134_8_1) + 34) & 127;
  int stage_v_40_2 = (((sec_r001134_14_2 * 3) + pub_r001134_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((stage_v_24_1 * 3) + pub_r001134_10_1) + 28) & 127;
  int stage_v_41_2 = (((stage_v_24_2 * 3) + pub_r001134_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = (((sec_r001134_6_1 * 3) + pub_r001134_14_1) + 18) & 127;
  int stage_v_42_2 = (((sec_r001134_6_2 * 3) + pub_r001134_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = (((sec_r001134_0_1 * 3) + pub_r001134_7_1) + 4) & 127;
  int stage_v_43_2 = (((sec_r001134_0_2 * 3) + pub_r001134_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001134_15_1 * 2) + 7) & 63;
  int stage_v_44_2 = ((pub_r001134_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((stage_v_5_1 * 3) + pub_r001134_9_1) + 35) & 127;
  int stage_v_45_2 = (((stage_v_5_2 * 3) + pub_r001134_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = ((pub_r001134_7_1 * 2) + 29) & 63;
  int stage_v_46_2 = ((pub_r001134_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001134_8_1 * 2) + 6) & 63;
  int stage_v_47_2 = ((pub_r001134_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001134_15_1 * 2) + 33) & 63;
  int stage_v_48_2 = ((pub_r001134_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((stage_v_39_1 * 3) + pub_r001134_14_1) + 33) & 127;
  int stage_v_49_2 = (((stage_v_39_2 * 3) + pub_r001134_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((stage_v_35_1 * 3) + pub_r001134_5_1) + 6) & 127;
  int stage_v_50_2 = (((stage_v_35_2 * 3) + pub_r001134_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = (((stage_v_45_1 * 3) + pub_r001134_14_1) + 19) & 127;
  int stage_v_51_2 = (((stage_v_45_2 * 3) + pub_r001134_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = (((stage_v_10_1 * 3) + pub_r001134_8_1) + 14) & 127;
  int stage_v_52_2 = (((stage_v_10_2 * 3) + pub_r001134_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = (((sec_r001134_10_1 * 3) + pub_r001134_4_1) + 5) & 127;
  int stage_v_53_2 = (((sec_r001134_10_2 * 3) + pub_r001134_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = ((pub_r001134_3_1 * 2) + 31) & 63;
  int stage_v_54_2 = ((pub_r001134_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((stage_v_39_1 * 3) + pub_r001134_2_1) + 32) & 127;
  int stage_v_55_2 = (((stage_v_39_2 * 3) + pub_r001134_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((sec_r001134_11_1 * 3) + pub_r001134_10_1) + 3) & 127;
  int stage_v_56_2 = (((sec_r001134_11_2 * 3) + pub_r001134_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((sec_r001134_11_1 * 3) + pub_r001134_14_1) + 12) & 127;
  int stage_v_57_2 = (((sec_r001134_11_2 * 3) + pub_r001134_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((stage_v_17_1 * 3) + pub_r001134_3_1) + 27) & 127;
  int stage_v_58_2 = (((stage_v_17_2 * 3) + pub_r001134_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((helper_flow_2_1 * 3) + pub_r001134_13_1) + 39) & 127;
  int stage_v_59_2 = (((helper_flow_2_2 * 3) + pub_r001134_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = (((stage_v_16_1 * 3) + pub_r001134_7_1) + 16) & 127;
  int stage_v_60_2 = (((stage_v_16_2 * 3) + pub_r001134_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = ((pub_r001134_12_1 * 2) + 45) & 63;
  int stage_v_61_2 = ((pub_r001134_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001134_14_1 * 2) + 20) & 63;
  int stage_v_62_2 = ((pub_r001134_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001134_11_1 * 2) + 49) & 63;
  int stage_v_63_2 = ((pub_r001134_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((sec_r001134_6_1 * 3) + pub_r001134_6_1) + 45) & 127;
  int stage_v_64_2 = (((sec_r001134_6_2 * 3) + pub_r001134_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((stage_v_0_1 * 3) + pub_r001134_1_1) + 6) & 127;
  int stage_v_65_2 = (((stage_v_0_2 * 3) + pub_r001134_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001134_15_1 * 2) + 29) & 63;
  int stage_v_66_2 = ((pub_r001134_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((sec_r001134_6_1 * 3) + pub_r001134_9_1) + 44) & 127;
  int stage_v_67_2 = (((sec_r001134_6_2 * 3) + pub_r001134_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = ((pub_r001134_11_1 * 2) + 15) & 63;
  int stage_v_68_2 = ((pub_r001134_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((stage_v_60_1 * 3) + pub_r001134_1_1) + 38) & 127;
  int stage_v_69_2 = (((stage_v_60_2 * 3) + pub_r001134_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((stage_v_37_1 * 3) + pub_r001134_6_1) + 24) & 127;
  int stage_v_70_2 = (((stage_v_37_2 * 3) + pub_r001134_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((sec_r001134_3_1 * 3) + pub_r001134_12_1) + 14) & 127;
  int stage_v_71_2 = (((sec_r001134_3_2 * 3) + pub_r001134_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = (((stage_v_34_1 * 3) + pub_r001134_15_1) + 22) & 127;
  int stage_v_72_2 = (((stage_v_34_2 * 3) + pub_r001134_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = (((stage_v_53_1 * 3) + pub_r001134_7_1) + 22) & 127;
  int stage_v_73_2 = (((stage_v_53_2 * 3) + pub_r001134_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((helper_flow_4_1 * 3) + pub_r001134_11_1) + 17) & 127;
  int stage_v_74_2 = (((helper_flow_4_2 * 3) + pub_r001134_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((stage_v_34_1 * 3) + pub_r001134_2_1) + 39) & 127;
  int stage_v_75_2 = (((stage_v_34_2 * 3) + pub_r001134_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((stage_v_37_1 * 3) + pub_r001134_12_1) + 41) & 127;
  int stage_v_76_2 = (((stage_v_37_2 * 3) + pub_r001134_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = (((stage_v_70_1 * 3) + pub_r001134_12_1) + 45) & 127;
  int stage_v_77_2 = (((stage_v_70_2 * 3) + pub_r001134_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((stage_v_74_1 * 3) + pub_r001134_5_1) + 43) & 127;
  int stage_v_78_2 = (((stage_v_74_2 * 3) + pub_r001134_5_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = (((stage_v_71_1 * 3) + pub_r001134_8_1) + 36) & 127;
  int stage_v_79_2 = (((stage_v_71_2 * 3) + pub_r001134_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001134_0_1 * 2) + 5) & 63;
  int stage_v_80_2 = ((pub_r001134_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001134_6_1 * 2) + 9) & 63;
  int stage_v_81_2 = ((pub_r001134_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((sec_r001134_8_1 * 3) + pub_r001134_5_1) + 22) & 127;
  int stage_v_82_2 = (((sec_r001134_8_2 * 3) + pub_r001134_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = (((stage_v_0_1 * 3) + pub_r001134_12_1) + 4) & 127;
  int stage_v_83_2 = (((stage_v_0_2 * 3) + pub_r001134_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = ((pub_r001134_4_1 * 2) + 27) & 63;
  int stage_v_84_2 = ((pub_r001134_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001134_11_1 * 2) + 42) & 63;
  int stage_v_85_2 = ((pub_r001134_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001134_8_1 * 2) + 8) & 63;
  int stage_v_86_2 = ((pub_r001134_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((sec_r001134_4_1 * 3) + pub_r001134_15_1) + 12) & 127;
  int stage_v_87_2 = (((sec_r001134_4_2 * 3) + pub_r001134_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = (((stage_v_30_1 * 3) + pub_r001134_12_1) + 25) & 127;
  int stage_v_88_2 = (((stage_v_30_2 * 3) + pub_r001134_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001134_5_1 * 2) + 30) & 63;
  int stage_v_89_2 = ((pub_r001134_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_52_1 * 3) + pub_r001134_11_1) + 4) & 127;
  int stage_v_90_2 = (((stage_v_52_2 * 3) + pub_r001134_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((stage_v_38_1 * 3) + pub_r001134_4_1) + 21) & 127;
  int stage_v_91_2 = (((stage_v_38_2 * 3) + pub_r001134_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001134_5_1 * 2) + 27) & 63;
  int stage_v_92_2 = ((pub_r001134_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001134_0_1 * 2) + 17) & 63;
  int stage_v_93_2 = ((pub_r001134_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((sec_r001134_8_1 * 3) + pub_r001134_16_1) + 25) & 127;
  int stage_v_94_2 = (((sec_r001134_8_2 * 3) + pub_r001134_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((sec_r001134_9_1 * 3) + pub_r001134_3_1) + 3) & 127;
  int stage_v_95_2 = (((sec_r001134_9_2 * 3) + pub_r001134_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001134_13_1 * 2) + 30) & 63;
  int stage_v_96_2 = ((pub_r001134_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_71_1 * 3) + pub_r001134_15_1) + 19) & 127;
  int stage_v_97_2 = (((stage_v_71_2 * 3) + pub_r001134_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((stage_v_77_1 * 3) + pub_r001134_13_1) + 42) & 127;
  int stage_v_98_2 = (((stage_v_77_2 * 3) + pub_r001134_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = ((pub_r001134_7_1 * 2) + 20) & 63;
  int stage_v_99_2 = ((pub_r001134_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((stage_v_40_1 * 3) + pub_r001134_8_1) + 31) & 127;
  int stage_v_100_2 = (((stage_v_40_2 * 3) + pub_r001134_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = (((stage_v_50_1 * 3) + pub_r001134_16_1) + 6) & 127;
  int stage_v_101_2 = (((stage_v_50_2 * 3) + pub_r001134_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = (((sec_r001134_7_1 * 3) + pub_r001134_11_1) + 25) & 127;
  int stage_v_102_2 = (((sec_r001134_7_2 * 3) + pub_r001134_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = (((sec_r001134_14_1 * 3) + pub_r001134_13_1) + 22) & 127;
  int stage_v_103_2 = (((sec_r001134_14_2 * 3) + pub_r001134_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001134_7_1 * 2) + 26) & 63;
  int stage_v_104_2 = ((pub_r001134_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_24_1 * 3) + pub_r001134_7_1) + 24) & 127;
  int stage_v_105_2 = (((stage_v_24_2 * 3) + pub_r001134_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((stage_v_38_1 * 3) + pub_r001134_16_1) + 44) & 127;
  int stage_v_106_2 = (((stage_v_38_2 * 3) + pub_r001134_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001134_7_1 * 2) + 9) & 63;
  int stage_v_107_2 = ((pub_r001134_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001134_4_1 * 2) + 30) & 63;
  int stage_v_108_2 = ((pub_r001134_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001134_11_1 * 2) + 15) & 63;
  int stage_v_109_2 = ((pub_r001134_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001134_15_1 * 2) + 30) & 63;
  int stage_v_110_2 = ((pub_r001134_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((stage_v_77_1 * 3) + pub_r001134_1_1) + 42) & 127;
  int stage_v_111_2 = (((stage_v_77_2 * 3) + pub_r001134_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001134_9_1 * 2) + 8) & 63;
  int stage_v_112_2 = ((pub_r001134_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_59_1 * 3) + pub_r001134_6_1) + 45) & 127;
  int stage_v_113_2 = (((stage_v_59_2 * 3) + pub_r001134_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = (((stage_v_78_1 * 3) + pub_r001134_2_1) + 20) & 127;
  int stage_v_114_2 = (((stage_v_78_2 * 3) + pub_r001134_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = ((pub_r001134_16_1 * 2) + 7) & 63;
  int stage_v_115_2 = ((pub_r001134_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_74_1 * 3) + pub_r001134_6_1) + 40) & 127;
  int stage_v_116_2 = (((stage_v_74_2 * 3) + pub_r001134_6_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = (((stage_v_56_1 * 3) + pub_r001134_16_1) + 6) & 127;
  int stage_v_117_2 = (((stage_v_56_2 * 3) + pub_r001134_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = (((sec_r001134_2_1 * 3) + pub_r001134_1_1) + 36) & 127;
  int stage_v_118_2 = (((sec_r001134_2_2 * 3) + pub_r001134_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001134_1_1 * 2) + 17) & 63;
  int stage_v_119_2 = ((pub_r001134_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((sec_r001134_2_1 * 3) + pub_r001134_16_1) + 24) & 127;
  int stage_v_120_2 = (((sec_r001134_2_2 * 3) + pub_r001134_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001134_7_1 * 2) + 35) & 63;
  int stage_v_121_2 = ((pub_r001134_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001134_3_1 * 2) + 47) & 63;
  int stage_v_122_2 = ((pub_r001134_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_113_1 * 3) + pub_r001134_1_1) + 39) & 127;
  int stage_v_123_2 = (((stage_v_113_2 * 3) + pub_r001134_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((stage_v_114_1 * 3) + pub_r001134_6_1) + 34) & 127;
  int stage_v_124_2 = (((stage_v_114_2 * 3) + pub_r001134_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((stage_v_105_1 * 3) + pub_r001134_13_1) + 37) & 127;
  int stage_v_125_2 = (((stage_v_105_2 * 3) + pub_r001134_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((stage_v_103_1 * 3) + pub_r001134_7_1) + 8) & 127;
  int stage_v_126_2 = (((stage_v_103_2 * 3) + pub_r001134_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((stage_v_3_1 * 3) + pub_r001134_4_1) + 37) & 127;
  int stage_v_127_2 = (((stage_v_3_2 * 3) + pub_r001134_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_101_1 * 3) + pub_r001134_9_1) + 33) & 127;
  int stage_v_128_2 = (((stage_v_101_2 * 3) + pub_r001134_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = ((pub_r001134_4_1 * 2) + 31) & 63;
  int stage_v_129_2 = ((pub_r001134_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((stage_v_117_1 * 3) + pub_r001134_8_1) + 4) & 127;
  int stage_v_130_2 = (((stage_v_117_2 * 3) + pub_r001134_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001134_2_1 * 2) + 7) & 63;
  int stage_v_131_2 = ((pub_r001134_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001134_4_1 * 2) + 17) & 63;
  int stage_v_132_2 = ((pub_r001134_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_130_1 * 3) + pub_r001134_15_1) + 20) & 127;
  int stage_v_133_2 = (((stage_v_130_2 * 3) + pub_r001134_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001134_11_1 * 2) + 35) & 63;
  int stage_v_134_2 = ((pub_r001134_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((sec_r001134_16_1 * 3) + pub_r001134_16_1) + 6) & 127;
  int stage_v_135_2 = (((sec_r001134_16_2 * 3) + pub_r001134_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001134_2_1 * 2) + 12) & 63;
  int stage_v_136_2 = ((pub_r001134_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((stage_v_88_1 * 3) + pub_r001134_5_1) + 14) & 127;
  int stage_v_137_2 = (((stage_v_88_2 * 3) + pub_r001134_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((stage_v_74_1 * 3) + pub_r001134_11_1) + 42) & 127;
  int stage_v_138_2 = (((stage_v_74_2 * 3) + pub_r001134_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((stage_v_30_1 * 3) + pub_r001134_4_1) + 37) & 127;
  int stage_v_139_2 = (((stage_v_30_2 * 3) + pub_r001134_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((stage_v_7_1 * 3) + pub_r001134_2_1) + 40) & 127;
  int stage_v_140_2 = (((stage_v_7_2 * 3) + pub_r001134_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((stage_v_69_1 * 3) + pub_r001134_4_1) + 38) & 127;
  int stage_v_141_2 = (((stage_v_69_2 * 3) + pub_r001134_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = ((pub_r001134_9_1 * 2) + 49) & 63;
  int stage_v_142_2 = ((pub_r001134_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((stage_v_51_1 * 3) + pub_r001134_8_1) + 31) & 127;
  int stage_v_143_2 = (((stage_v_51_2 * 3) + pub_r001134_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001134_1_1 * 2) + 19) & 63;
  int stage_v_144_2 = ((pub_r001134_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001134_2_1 * 2) + 12) & 63;
  int stage_v_145_2 = ((pub_r001134_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001134_12_1 * 2) + 11) & 63;
  int stage_v_146_2 = ((pub_r001134_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001134_10_1 * 2) + 36) & 63;
  int stage_v_147_2 = ((pub_r001134_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((sec_r001134_0_1 * 3) + pub_r001134_7_1) + 5) & 127;
  int stage_v_148_2 = (((sec_r001134_0_2 * 3) + pub_r001134_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_3_1 * 3) + pub_r001134_8_1) + 5) & 127;
  int stage_v_149_2 = (((stage_v_3_2 * 3) + pub_r001134_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_127_1 * 3) + pub_r001134_16_1) + 18) & 127;
  int stage_v_150_2 = (((stage_v_127_2 * 3) + pub_r001134_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_37_1 * 3) + pub_r001134_8_1) + 31) & 127;
  int stage_v_151_2 = (((stage_v_37_2 * 3) + pub_r001134_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((stage_v_74_1 * 3) + pub_r001134_9_1) + 32) & 127;
  int stage_v_152_2 = (((stage_v_74_2 * 3) + pub_r001134_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001134_4_1 * 2) + 25) & 63;
  int stage_v_153_2 = ((pub_r001134_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_6_1 * 3) + pub_r001134_10_1) + 30) & 127;
  int stage_v_154_2 = (((stage_v_6_2 * 3) + pub_r001134_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001134_12_1 * 2) + 20) & 63;
  int stage_v_155_2 = ((pub_r001134_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_150_1 * 3) + pub_r001134_10_1) + 42) & 127;
  int stage_v_156_2 = (((stage_v_150_2 * 3) + pub_r001134_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((sec_r001134_7_1 * 3) + pub_r001134_6_1) + 13) & 127;
  int stage_v_157_2 = (((sec_r001134_7_2 * 3) + pub_r001134_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001134_0_1 * 2) + 20) & 63;
  int stage_v_158_2 = ((pub_r001134_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((stage_v_135_1 * 3) + pub_r001134_14_1) + 29) & 127;
  int stage_v_159_2 = (((stage_v_135_2 * 3) + pub_r001134_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = ((pub_r001134_2_1 * 2) + 14) & 63;
  int stage_v_160_2 = ((pub_r001134_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_125_1 * 3) + pub_r001134_5_1) + 26) & 127;
  int stage_v_161_2 = (((stage_v_125_2 * 3) + pub_r001134_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((stage_v_67_1 * 3) + pub_r001134_2_1) + 36) & 127;
  int stage_v_162_2 = (((stage_v_67_2 * 3) + pub_r001134_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = (((stage_v_123_1 * 3) + pub_r001134_11_1) + 7) & 127;
  int stage_v_163_2 = (((stage_v_123_2 * 3) + pub_r001134_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = ((pub_r001134_12_1 * 2) + 34) & 63;
  int stage_v_164_2 = ((pub_r001134_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_124_1 * 3) + pub_r001134_16_1) + 6) & 127;
  int stage_v_165_2 = (((stage_v_124_2 * 3) + pub_r001134_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = (((stage_v_65_1 * 3) + pub_r001134_11_1) + 44) & 127;
  int stage_v_166_2 = (((stage_v_65_2 * 3) + pub_r001134_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = (((stage_v_42_1 * 3) + pub_r001134_6_1) + 26) & 127;
  int stage_v_167_2 = (((stage_v_42_2 * 3) + pub_r001134_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((stage_v_135_1 * 3) + pub_r001134_6_1) + 38) & 127;
  int stage_v_168_2 = (((stage_v_135_2 * 3) + pub_r001134_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((sec_r001134_1_1 * 3) + pub_r001134_13_1) + 39) & 127;
  int stage_v_169_2 = (((sec_r001134_1_2 * 3) + pub_r001134_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = ((pub_r001134_6_1 * 2) + 45) & 63;
  int stage_v_170_2 = ((pub_r001134_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001134_14_1 * 2) + 38) & 63;
  int stage_v_171_2 = ((pub_r001134_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001134_14_1 * 2) + 43) & 63;
  int stage_v_172_2 = ((pub_r001134_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001134_2_1 * 2) + 26) & 63;
  int stage_v_173_2 = ((pub_r001134_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_29_1 * 3) + pub_r001134_13_1) + 33) & 127;
  int stage_v_174_2 = (((stage_v_29_2 * 3) + pub_r001134_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001134_10_1 * 2) + 7) & 63;
  int stage_v_175_2 = ((pub_r001134_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_35_1 * 3) + pub_r001134_11_1) + 8) & 127;
  int stage_v_176_2 = (((stage_v_35_2 * 3) + pub_r001134_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((stage_v_163_1 * 3) + pub_r001134_6_1) + 18) & 127;
  int stage_v_177_2 = (((stage_v_163_2 * 3) + pub_r001134_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = ((pub_r001134_5_1 * 2) + 31) & 63;
  int stage_v_178_2 = ((pub_r001134_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((stage_v_159_1 * 3) + pub_r001134_13_1) + 9) & 127;
  int stage_v_179_2 = (((stage_v_159_2 * 3) + pub_r001134_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = ((pub_r001134_7_1 * 2) + 18) & 63;
  int stage_v_180_2 = ((pub_r001134_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_76_1 * 3) + pub_r001134_8_1) + 43) & 127;
  int stage_v_181_2 = (((stage_v_76_2 * 3) + pub_r001134_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((stage_v_72_1 * 3) + pub_r001134_1_1) + 29) & 127;
  int stage_v_182_2 = (((stage_v_72_2 * 3) + pub_r001134_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((stage_v_5_1 * 3) + pub_r001134_6_1) + 30) & 127;
  int stage_v_183_2 = (((stage_v_5_2 * 3) + pub_r001134_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = ((pub_r001134_9_1 * 2) + 30) & 63;
  int stage_v_184_2 = ((pub_r001134_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001134_6_1 * 2) + 31) & 63;
  int stage_v_185_2 = ((pub_r001134_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001134_6_1 * 2) + 9) & 63;
  int stage_v_186_2 = ((pub_r001134_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((sec_r001134_12_1 * 3) + pub_r001134_3_1) + 41) & 127;
  int stage_v_187_2 = (((sec_r001134_12_2 * 3) + pub_r001134_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = (((stage_v_56_1 * 3) + pub_r001134_10_1) + 45) & 127;
  int stage_v_188_2 = (((stage_v_56_2 * 3) + pub_r001134_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = (((stage_v_148_1 * 3) + pub_r001134_11_1) + 27) & 127;
  int stage_v_189_2 = (((stage_v_148_2 * 3) + pub_r001134_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = ((pub_r001134_4_1 * 2) + 29) & 63;
  int stage_v_190_2 = ((pub_r001134_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_71_1 * 3) + pub_r001134_9_1) + 9) & 127;
  int stage_v_191_2 = (((stage_v_71_2 * 3) + pub_r001134_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001134_14_1 * 2) + 36) & 63;
  int stage_v_192_2 = ((pub_r001134_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001134_2_1 * 2) + 42) & 63;
  int stage_v_193_2 = ((pub_r001134_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_141_1 * 3) + pub_r001134_3_1) + 21) & 127;
  int stage_v_194_2 = (((stage_v_141_2 * 3) + pub_r001134_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((stage_v_177_1 * 3) + pub_r001134_5_1) + 13) & 127;
  int stage_v_195_2 = (((stage_v_177_2 * 3) + pub_r001134_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = (((sec_r001134_2_1 * 3) + pub_r001134_16_1) + 28) & 127;
  int stage_v_196_2 = (((sec_r001134_2_2 * 3) + pub_r001134_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = (((sec_r001134_12_1 * 3) + pub_r001134_9_1) + 18) & 127;
  int stage_v_197_2 = (((sec_r001134_12_2 * 3) + pub_r001134_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((stage_v_38_1 * 3) + pub_r001134_3_1) + 26) & 127;
  int stage_v_198_2 = (((stage_v_38_2 * 3) + pub_r001134_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((stage_v_37_1 * 3) + pub_r001134_10_1) + 14) & 127;
  int stage_v_199_2 = (((stage_v_37_2 * 3) + pub_r001134_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = (((stage_v_83_1 * 3) + pub_r001134_4_1) + 26) & 127;
  int stage_v_200_2 = (((stage_v_83_2 * 3) + pub_r001134_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = ((pub_r001134_9_1 * 2) + 20) & 63;
  int stage_v_201_2 = ((pub_r001134_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_90_1 * 3) + pub_r001134_11_1) + 25) & 127;
  int stage_v_202_2 = (((stage_v_90_2 * 3) + pub_r001134_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001134_0_1 * 2) + 11) & 63;
  int stage_v_203_2 = ((pub_r001134_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_29_1 * 3) + pub_r001134_9_1) + 37) & 127;
  int stage_v_204_2 = (((stage_v_29_2 * 3) + pub_r001134_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_32_1 * 3) + pub_r001134_15_1) + 31) & 127;
  int stage_v_205_2 = (((stage_v_32_2 * 3) + pub_r001134_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((stage_v_24_1 * 3) + pub_r001134_9_1) + 19) & 127;
  int stage_v_206_2 = (((stage_v_24_2 * 3) + pub_r001134_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = ((pub_r001134_6_1 * 2) + 37) & 63;
  int stage_v_207_2 = ((pub_r001134_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001134_16_1 * 2) + 41) & 63;
  int stage_v_208_2 = ((pub_r001134_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001134_3_1 * 2) + 47) & 63;
  int stage_v_209_2 = ((pub_r001134_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_137_1 * 3) + pub_r001134_9_1) + 12) & 127;
  int stage_v_210_2 = (((stage_v_137_2 * 3) + pub_r001134_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = ((pub_r001134_13_1 * 2) + 49) & 63;
  int stage_v_211_2 = ((pub_r001134_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001134_7_1 * 2) + 29) & 63;
  int stage_v_212_2 = ((pub_r001134_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_88_1 * 3) + pub_r001134_15_1) + 6) & 127;
  int stage_v_213_2 = (((stage_v_88_2 * 3) + pub_r001134_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001134_16_1 * 2) + 30) & 63;
  int stage_v_214_2 = ((pub_r001134_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_64_1 * 3) + pub_r001134_1_1) + 16) & 127;
  int stage_v_215_2 = (((stage_v_64_2 * 3) + pub_r001134_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_82_1 * 3) + pub_r001134_13_1) + 7) & 127;
  int stage_v_216_2 = (((stage_v_82_2 * 3) + pub_r001134_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001134_4_1 * 2) + 43) & 63;
  int stage_v_217_2 = ((pub_r001134_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001134_11_1 * 2) + 41) & 63;
  int stage_v_218_2 = ((pub_r001134_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_94_1 * 3) + pub_r001134_9_1) + 39) & 127;
  int stage_v_219_2 = (((stage_v_94_2 * 3) + pub_r001134_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = ((pub_r001134_16_1 * 2) + 33) & 63;
  int stage_v_220_2 = ((pub_r001134_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_187_1 * 3) + pub_r001134_2_1) + 21) & 127;
  int stage_v_221_2 = (((stage_v_187_2 * 3) + pub_r001134_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = ((pub_r001134_13_1 * 2) + 39) & 63;
  int stage_v_222_2 = ((pub_r001134_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_75_1 * 3) + pub_r001134_7_1) + 43) & 127;
  int stage_v_223_2 = (((stage_v_75_2 * 3) + pub_r001134_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((stage_v_128_1 * 3) + pub_r001134_15_1) + 24) & 127;
  int stage_v_224_2 = (((stage_v_128_2 * 3) + pub_r001134_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001134_9_1 * 2) + 6) & 63;
  int stage_v_225_2 = ((pub_r001134_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((stage_v_123_1 * 3) + pub_r001134_9_1) + 21) & 127;
  int stage_v_226_2 = (((stage_v_123_2 * 3) + pub_r001134_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_113_1 * 3) + pub_r001134_6_1) + 16) & 127;
  int stage_v_227_2 = (((stage_v_113_2 * 3) + pub_r001134_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001134_9_1 * 2) + 44) & 63;
  int stage_v_228_2 = ((pub_r001134_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_3_1 * 3) + pub_r001134_10_1) + 31) & 127;
  int stage_v_229_2 = (((stage_v_3_2 * 3) + pub_r001134_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((stage_v_65_1 * 3) + pub_r001134_9_1) + 36) & 127;
  int stage_v_230_2 = (((stage_v_65_2 * 3) + pub_r001134_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = ((pub_r001134_12_1 * 2) + 36) & 63;
  int stage_v_231_2 = ((pub_r001134_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((stage_v_126_1 * 3) + pub_r001134_6_1) + 10) & 127;
  int stage_v_232_2 = (((stage_v_126_2 * 3) + pub_r001134_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((stage_v_221_1 * 3) + pub_r001134_2_1) + 25) & 127;
  int stage_v_233_2 = (((stage_v_221_2 * 3) + pub_r001134_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((sec_r001134_11_1 * 3) + pub_r001134_4_1) + 11) & 127;
  int stage_v_234_2 = (((sec_r001134_11_2 * 3) + pub_r001134_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_133_1 * 3) + pub_r001134_6_1) + 4) & 127;
  int stage_v_235_2 = (((stage_v_133_2 * 3) + pub_r001134_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = (((stage_v_191_1 * 3) + pub_r001134_11_1) + 26) & 127;
  int stage_v_236_2 = (((stage_v_191_2 * 3) + pub_r001134_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = (((stage_v_127_1 * 3) + pub_r001134_8_1) + 32) & 127;
  int stage_v_237_2 = (((stage_v_127_2 * 3) + pub_r001134_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = (((stage_v_69_1 * 3) + pub_r001134_6_1) + 35) & 127;
  int stage_v_238_2 = (((stage_v_69_2 * 3) + pub_r001134_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001134_6_1 * 2) + 12) & 63;
  int stage_v_239_2 = ((pub_r001134_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_88_1 * 3) + pub_r001134_8_1) + 40) & 127;
  int stage_v_240_2 = (((stage_v_88_2 * 3) + pub_r001134_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_56_1 * 3) + pub_r001134_7_1) + 6) & 127;
  int stage_v_241_2 = (((stage_v_56_2 * 3) + pub_r001134_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001134_7_1 * 2) + 44) & 63;
  int stage_v_242_2 = ((pub_r001134_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((stage_v_4_1 * 3) + pub_r001134_3_1) + 23) & 127;
  int stage_v_243_2 = (((stage_v_4_2 * 3) + pub_r001134_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_97_1 * 3) + pub_r001134_4_1) + 23) & 127;
  int stage_v_244_2 = (((stage_v_97_2 * 3) + pub_r001134_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_58_1 * 3) + pub_r001134_12_1) + 26) & 127;
  int stage_v_245_2 = (((stage_v_58_2 * 3) + pub_r001134_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = (((stage_v_28_1 * 3) + pub_r001134_5_1) + 14) & 127;
  int stage_v_246_2 = (((stage_v_28_2 * 3) + pub_r001134_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001134_5_1 * 2) + 47) & 63;
  int stage_v_247_2 = ((pub_r001134_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001134_15_1 * 2) + 7) & 63;
  int stage_v_248_2 = ((pub_r001134_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001134_14_1 * 2) + 42) & 63;
  int stage_v_249_2 = ((pub_r001134_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = (((stage_v_55_1 * 3) + pub_r001134_6_1) + 13) & 127;
  int stage_v_250_2 = (((stage_v_55_2 * 3) + pub_r001134_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_156_1 * 3) + pub_r001134_6_1) + 22) & 127;
  int stage_v_251_2 = (((stage_v_156_2 * 3) + pub_r001134_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((stage_v_237_1 * 3) + pub_r001134_14_1) + 24) & 127;
  int stage_v_252_2 = (((stage_v_237_2 * 3) + pub_r001134_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = ((pub_r001134_15_1 * 2) + 15) & 63;
  int stage_v_253_2 = ((pub_r001134_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_161_1 * 3) + pub_r001134_2_1) + 6) & 127;
  int stage_v_254_2 = (((stage_v_161_2 * 3) + pub_r001134_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((stage_v_73_1 * 3) + pub_r001134_8_1) + 4) & 127;
  int stage_v_255_2 = (((stage_v_73_2 * 3) + pub_r001134_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001134_8_1 * 2) + 15) & 63;
  int stage_v_256_2 = ((pub_r001134_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((stage_v_152_1 * 3) + pub_r001134_10_1) + 30) & 127;
  int stage_v_257_2 = (((stage_v_152_2 * 3) + pub_r001134_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = (((stage_v_189_1 * 3) + pub_r001134_7_1) + 21) & 127;
  int stage_v_258_2 = (((stage_v_189_2 * 3) + pub_r001134_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001134_7_1 * 2) + 16) & 63;
  int stage_v_259_2 = ((pub_r001134_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001134_11_1 * 2) + 23) & 63;
  int stage_v_260_2 = ((pub_r001134_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_182_1 * 3) + pub_r001134_8_1) + 39) & 127;
  int stage_v_261_2 = (((stage_v_182_2 * 3) + pub_r001134_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001134_13_1 * 2) + 9) & 63;
  int stage_v_262_2 = ((pub_r001134_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((sec_r001134_15_1 * 3) + pub_r001134_8_1) + 16) & 127;
  int stage_v_263_2 = (((sec_r001134_15_2 * 3) + pub_r001134_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = (((stage_v_76_1 * 3) + pub_r001134_1_1) + 7) & 127;
  int stage_v_264_2 = (((stage_v_76_2 * 3) + pub_r001134_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = (((stage_v_13_1 * 3) + pub_r001134_0_1) + 5) & 127;
  int stage_v_265_2 = (((stage_v_13_2 * 3) + pub_r001134_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = ((pub_r001134_14_1 * 2) + 24) & 63;
  int stage_v_266_2 = ((pub_r001134_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = (((stage_v_162_1 * 3) + pub_r001134_9_1) + 45) & 127;
  int stage_v_267_2 = (((stage_v_162_2 * 3) + pub_r001134_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = ((pub_r001134_12_1 * 2) + 49) & 63;
  int stage_v_268_2 = ((pub_r001134_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001134_2_1 * 2) + 23) & 63;
  int stage_v_269_2 = ((pub_r001134_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001134_10_1 * 2) + 19) & 63;
  int stage_v_270_2 = ((pub_r001134_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = (((stage_v_237_1 * 3) + pub_r001134_1_1) + 38) & 127;
  int stage_v_271_2 = (((stage_v_237_2 * 3) + pub_r001134_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001134_8_1 * 2) + 48) & 63;
  int stage_v_272_2 = ((pub_r001134_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((stage_v_187_1 * 3) + pub_r001134_13_1) + 18) & 127;
  int stage_v_273_2 = (((stage_v_187_2 * 3) + pub_r001134_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = (((stage_v_74_1 * 3) + pub_r001134_13_1) + 3) & 127;
  int stage_v_274_2 = (((stage_v_74_2 * 3) + pub_r001134_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_106_1 * 3) + pub_r001134_15_1) + 17) & 127;
  int stage_v_275_2 = (((stage_v_106_2 * 3) + pub_r001134_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = ((pub_r001134_5_1 * 2) + 39) & 63;
  int stage_v_276_2 = ((pub_r001134_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001134_10_1 * 2) + 43) & 63;
  int stage_v_277_2 = ((pub_r001134_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001134_2_1 * 2) + 31) & 63;
  int stage_v_278_2 = ((pub_r001134_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001134_16_1 * 2) + 20) & 63;
  int stage_v_279_2 = ((pub_r001134_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001134_0_1 * 2) + 5) & 63;
  int stage_v_280_2 = ((pub_r001134_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = (((stage_v_202_1 * 3) + pub_r001134_5_1) + 29) & 127;
  int stage_v_281_2 = (((stage_v_202_2 * 3) + pub_r001134_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001134_5_1 * 2) + 45) & 63;
  int stage_v_282_2 = ((pub_r001134_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001134_0_1 * 2) + 26) & 63;
  int stage_v_283_2 = ((pub_r001134_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = (((stage_v_139_1 * 3) + pub_r001134_15_1) + 31) & 127;
  int stage_v_284_2 = (((stage_v_139_2 * 3) + pub_r001134_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001134_1_1 * 2) + 26) & 63;
  int stage_v_285_2 = ((pub_r001134_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((sec_r001134_5_1 * 3) + pub_r001134_15_1) + 15) & 127;
  int stage_v_286_2 = (((sec_r001134_5_2 * 3) + pub_r001134_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = ((pub_r001134_12_1 * 2) + 20) & 63;
  int stage_v_287_2 = ((pub_r001134_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = (((sec_r001134_11_1 * 3) + pub_r001134_15_1) + 41) & 127;
  int stage_v_288_2 = (((sec_r001134_11_2 * 3) + pub_r001134_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((stage_v_152_1 * 3) + pub_r001134_12_1) + 4) & 127;
  int stage_v_289_2 = (((stage_v_152_2 * 3) + pub_r001134_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_57_1 * 3) + pub_r001134_0_1) + 19) & 127;
  int stage_v_290_2 = (((stage_v_57_2 * 3) + pub_r001134_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001134_16_1 * 2) + 23) & 63;
  int stage_v_291_2 = ((pub_r001134_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001134_1_1 * 2) + 10) & 63;
  int stage_v_292_2 = ((pub_r001134_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001134_12_1 * 2) + 23) & 63;
  int stage_v_293_2 = ((pub_r001134_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001134_5_1 * 2) + 46) & 63;
  int stage_v_294_2 = ((pub_r001134_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_72_1 * 3) + pub_r001134_0_1) + 19) & 127;
  int stage_v_295_2 = (((stage_v_72_2 * 3) + pub_r001134_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((stage_v_169_1 * 3) + pub_r001134_12_1) + 18) & 127;
  int stage_v_296_2 = (((stage_v_169_2 * 3) + pub_r001134_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001134_2_1 * 2) + 34) & 63;
  int stage_v_297_2 = ((pub_r001134_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_102_1 * 3) + pub_r001134_3_1) + 32) & 127;
  int stage_v_298_2 = (((stage_v_102_2 * 3) + pub_r001134_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001134_13_1 * 2) + 29) & 63;
  int stage_v_299_2 = ((pub_r001134_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((stage_v_264_1 * 3) + pub_r001134_2_1) + 8) & 127;
  int stage_v_300_2 = (((stage_v_264_2 * 3) + pub_r001134_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = (((stage_v_254_1 * 3) + pub_r001134_7_1) + 22) & 127;
  int stage_v_301_2 = (((stage_v_254_2 * 3) + pub_r001134_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = (((sec_r001134_5_1 * 3) + pub_r001134_16_1) + 41) & 127;
  int stage_v_302_2 = (((sec_r001134_5_2 * 3) + pub_r001134_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = (((stage_v_101_1 * 3) + pub_r001134_7_1) + 10) & 127;
  int stage_v_303_2 = (((stage_v_101_2 * 3) + pub_r001134_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = (((stage_v_251_1 * 3) + pub_r001134_5_1) + 41) & 127;
  int stage_v_304_2 = (((stage_v_251_2 * 3) + pub_r001134_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001134_12_1 * 2) + 9) & 63;
  int stage_v_305_2 = ((pub_r001134_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_45_1 * 3) + pub_r001134_6_1) + 23) & 127;
  int stage_v_306_2 = (((stage_v_45_2 * 3) + pub_r001134_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = (((stage_v_103_1 * 3) + pub_r001134_7_1) + 42) & 127;
  int stage_v_307_2 = (((stage_v_103_2 * 3) + pub_r001134_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = (((stage_v_224_1 * 3) + pub_r001134_4_1) + 26) & 127;
  int stage_v_308_2 = (((stage_v_224_2 * 3) + pub_r001134_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = (((sec_r001134_7_1 * 3) + pub_r001134_5_1) + 19) & 127;
  int stage_v_309_2 = (((sec_r001134_7_2 * 3) + pub_r001134_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = (((stage_v_1_1 * 3) + pub_r001134_13_1) + 45) & 127;
  int stage_v_310_2 = (((stage_v_1_2 * 3) + pub_r001134_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = ((pub_r001134_5_1 * 2) + 37) & 63;
  int stage_v_311_2 = ((pub_r001134_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001134_5_1 * 2) + 14) & 63;
  int stage_v_312_2 = ((pub_r001134_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001134_12_1 * 2) + 26) & 63;
  int stage_v_313_2 = ((pub_r001134_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_73_1 * 3) + pub_r001134_9_1) + 36) & 127;
  int stage_v_314_2 = (((stage_v_73_2 * 3) + pub_r001134_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = ((pub_r001134_10_1 * 2) + 5) & 63;
  int stage_v_315_2 = ((pub_r001134_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001134_8_1 * 2) + 12) & 63;
  int stage_v_316_2 = ((pub_r001134_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001134_1_1 * 2) + 41) & 63;
  int stage_v_317_2 = ((pub_r001134_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = (((stage_v_40_1 * 3) + pub_r001134_3_1) + 40) & 127;
  int stage_v_318_2 = (((stage_v_40_2 * 3) + pub_r001134_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = ((pub_r001134_5_1 * 2) + 9) & 63;
  int stage_v_319_2 = ((pub_r001134_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_125_1 * 3) + pub_r001134_6_1) + 34) & 127;
  int stage_v_320_2 = (((stage_v_125_2 * 3) + pub_r001134_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_117_1 * 3) + pub_r001134_5_1) + 34) & 127;
  int stage_v_321_2 = (((stage_v_117_2 * 3) + pub_r001134_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = ((pub_r001134_8_1 * 2) + 6) & 63;
  int stage_v_322_2 = ((pub_r001134_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001134_1_1 * 2) + 16) & 63;
  int stage_v_323_2 = ((pub_r001134_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((sec_r001134_11_1 * 3) + pub_r001134_0_1) + 44) & 127;
  int stage_v_324_2 = (((sec_r001134_11_2 * 3) + pub_r001134_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = ((pub_r001134_0_1 * 2) + 33) & 63;
  int stage_v_325_2 = ((pub_r001134_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001134_7_1 * 2) + 27) & 63;
  int stage_v_326_2 = ((pub_r001134_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = (((stage_v_34_1 * 3) + pub_r001134_9_1) + 45) & 127;
  int stage_v_327_2 = (((stage_v_34_2 * 3) + pub_r001134_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = ((pub_r001134_6_1 * 2) + 33) & 63;
  int stage_v_328_2 = ((pub_r001134_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = (((stage_v_17_1 * 3) + pub_r001134_4_1) + 33) & 127;
  int stage_v_329_2 = (((stage_v_17_2 * 3) + pub_r001134_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = ((pub_r001134_4_1 * 2) + 30) & 63;
  int stage_v_330_2 = ((pub_r001134_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = (((helper_flow_0_1 * 3) + pub_r001134_9_1) + 8) & 127;
  int stage_v_331_2 = (((helper_flow_0_2 * 3) + pub_r001134_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((sec_r001134_10_1 * 3) + pub_r001134_2_1) + 20) & 127;
  int stage_v_332_2 = (((sec_r001134_10_2 * 3) + pub_r001134_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((helper_flow_3_1 * 3) + pub_r001134_10_1) + 22) & 127;
  int stage_v_333_2 = (((helper_flow_3_2 * 3) + pub_r001134_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = (((sec_r001134_5_1 * 3) + pub_r001134_16_1) + 13) & 127;
  int stage_v_334_2 = (((sec_r001134_5_2 * 3) + pub_r001134_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((stage_v_140_1 * 3) + pub_r001134_3_1) + 26) & 127;
  int stage_v_335_2 = (((stage_v_140_2 * 3) + pub_r001134_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = ((pub_r001134_8_1 * 2) + 27) & 63;
  int stage_v_336_2 = ((pub_r001134_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001134_13_1 * 2) + 9) & 63;
  int stage_v_337_2 = ((pub_r001134_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = (((sec_r001134_8_1 * 3) + pub_r001134_13_1) + 15) & 127;
  int stage_v_338_2 = (((sec_r001134_8_2 * 3) + pub_r001134_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001134_6_1 * 2) + 20) & 63;
  int stage_v_339_2 = ((pub_r001134_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_0_1 * 3) + pub_r001134_9_1) + 39) & 127;
  int stage_v_340_2 = (((stage_v_0_2 * 3) + pub_r001134_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((stage_v_126_1 * 3) + pub_r001134_9_1) + 28) & 127;
  int stage_v_341_2 = (((stage_v_126_2 * 3) + pub_r001134_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_233_1 * 3) + pub_r001134_11_1) + 11) & 127;
  int stage_v_342_2 = (((stage_v_233_2 * 3) + pub_r001134_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = ((pub_r001134_5_1 * 2) + 23) & 63;
  int stage_v_343_2 = ((pub_r001134_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001134_16_1 * 2) + 12) & 63;
  int stage_v_344_2 = ((pub_r001134_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((stage_v_229_1 * 3) + pub_r001134_12_1) + 20) & 127;
  int stage_v_345_2 = (((stage_v_229_2 * 3) + pub_r001134_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = (((stage_v_125_1 * 3) + pub_r001134_11_1) + 13) & 127;
  int stage_v_346_2 = (((stage_v_125_2 * 3) + pub_r001134_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = (((stage_v_307_1 * 3) + pub_r001134_2_1) + 4) & 127;
  int stage_v_347_2 = (((stage_v_307_2 * 3) + pub_r001134_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_67_1 * 3) + pub_r001134_16_1) + 20) & 127;
  int stage_v_348_2 = (((stage_v_67_2 * 3) + pub_r001134_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_215_1 * 3) + pub_r001134_14_1) + 37) & 127;
  int stage_v_349_2 = (((stage_v_215_2 * 3) + pub_r001134_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_166_1 * 3) + pub_r001134_12_1) + 9) & 127;
  int stage_v_350_2 = (((stage_v_166_2 * 3) + pub_r001134_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_194_1 * 3) + pub_r001134_2_1) + 35) & 127;
  int stage_v_351_2 = (((stage_v_194_2 * 3) + pub_r001134_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_139_1 * 3) + pub_r001134_15_1) + 45) & 127;
  int stage_v_352_2 = (((stage_v_139_2 * 3) + pub_r001134_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = ((pub_r001134_7_1 * 2) + 46) & 63;
  int stage_v_353_2 = ((pub_r001134_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001134_12_1 * 2) + 29) & 63;
  int stage_v_354_2 = ((pub_r001134_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((stage_v_238_1 * 3) + pub_r001134_11_1) + 42) & 127;
  int stage_v_355_2 = (((stage_v_238_2 * 3) + pub_r001134_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001134_15_1 * 2) + 20) & 63;
  int stage_v_356_2 = ((pub_r001134_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001134_12_1 * 2) + 49) & 63;
  int stage_v_357_2 = ((pub_r001134_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001134_13_1 * 2) + 15) & 63;
  int stage_v_358_2 = ((pub_r001134_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_60_1 * 3) + pub_r001134_1_1) + 11) & 127;
  int stage_v_359_2 = (((stage_v_60_2 * 3) + pub_r001134_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001134_14_1 * 2) + 38) & 63;
  int stage_v_360_2 = ((pub_r001134_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((stage_v_40_1 * 3) + pub_r001134_11_1) + 43) & 127;
  int stage_v_361_2 = (((stage_v_40_2 * 3) + pub_r001134_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((stage_v_213_1 * 3) + pub_r001134_13_1) + 8) & 127;
  int stage_v_362_2 = (((stage_v_213_2 * 3) + pub_r001134_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = ((pub_r001134_7_1 * 2) + 48) & 63;
  int stage_v_363_2 = ((pub_r001134_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = (((stage_v_105_1 * 3) + pub_r001134_8_1) + 33) & 127;
  int stage_v_364_2 = (((stage_v_105_2 * 3) + pub_r001134_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = ((pub_r001134_5_1 * 2) + 38) & 63;
  int stage_v_365_2 = ((pub_r001134_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = (((stage_v_154_1 * 3) + pub_r001134_16_1) + 37) & 127;
  int stage_v_366_2 = (((stage_v_154_2 * 3) + pub_r001134_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_345_1 * 3) + pub_r001134_2_1) + 39) & 127;
  int stage_v_367_2 = (((stage_v_345_2 * 3) + pub_r001134_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_41_1 * 3) + pub_r001134_14_1) + 17) & 127;
  int stage_v_368_2 = (((stage_v_41_2 * 3) + pub_r001134_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = (((stage_v_364_1 * 3) + pub_r001134_12_1) + 44) & 127;
  int stage_v_369_2 = (((stage_v_364_2 * 3) + pub_r001134_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = ((pub_r001134_3_1 * 2) + 36) & 63;
  int stage_v_370_2 = ((pub_r001134_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((stage_v_87_1 * 3) + pub_r001134_16_1) + 28) & 127;
  int stage_v_371_2 = (((stage_v_87_2 * 3) + pub_r001134_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001134_15_1 * 2) + 37) & 63;
  int stage_v_372_2 = ((pub_r001134_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_13_1 * 3) + pub_r001134_4_1) + 38) & 127;
  int stage_v_373_2 = (((stage_v_13_2 * 3) + pub_r001134_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = ((pub_r001134_5_1 * 2) + 37) & 63;
  int stage_v_374_2 = ((pub_r001134_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001134_0_1 * 2) + 16) & 63;
  int stage_v_375_2 = ((pub_r001134_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001134_10_1 * 2) + 7) & 63;
  int stage_v_376_2 = ((pub_r001134_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_58_1 * 3) + pub_r001134_12_1) + 23) & 127;
  int stage_v_377_2 = (((stage_v_58_2 * 3) + pub_r001134_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_275_1 * 3) + pub_r001134_0_1) + 37) & 127;
  int stage_v_378_2 = (((stage_v_275_2 * 3) + pub_r001134_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_234_1 * 3) + pub_r001134_16_1) + 44) & 127;
  int stage_v_379_2 = (((stage_v_234_2 * 3) + pub_r001134_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_257_1 * 3) + pub_r001134_7_1) + 14) & 127;
  int stage_v_380_2 = (((stage_v_257_2 * 3) + pub_r001134_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_116_1 * 3) + pub_r001134_3_1) + 22) & 127;
  int stage_v_381_2 = (((stage_v_116_2 * 3) + pub_r001134_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = (((stage_v_72_1 * 3) + pub_r001134_8_1) + 34) & 127;
  int stage_v_382_2 = (((stage_v_72_2 * 3) + pub_r001134_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_219_1 * 3) + pub_r001134_2_1) + 18) & 127;
  int stage_v_383_2 = (((stage_v_219_2 * 3) + pub_r001134_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((stage_v_195_1 * 3) + pub_r001134_0_1) + 19) & 127;
  int stage_v_384_2 = (((stage_v_195_2 * 3) + pub_r001134_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = (((sec_r001134_2_1 * 3) + pub_r001134_9_1) + 22) & 127;
  int stage_v_385_2 = (((sec_r001134_2_2 * 3) + pub_r001134_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = ((pub_r001134_16_1 * 2) + 19) & 63;
  int stage_v_386_2 = ((pub_r001134_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001134_11_1 * 2) + 26) & 63;
  int stage_v_387_2 = ((pub_r001134_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001134_15_1 * 2) + 49) & 63;
  int stage_v_388_2 = ((pub_r001134_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_162_1 * 3) + pub_r001134_7_1) + 29) & 127;
  int stage_v_389_2 = (((stage_v_162_2 * 3) + pub_r001134_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001134_9_1 * 2) + 14) & 63;
  int stage_v_390_2 = ((pub_r001134_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = (((stage_v_373_1 * 3) + pub_r001134_3_1) + 6) & 127;
  int stage_v_391_2 = (((stage_v_373_2 * 3) + pub_r001134_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_135_1 * 3) + pub_r001134_11_1) + 10) & 127;
  int stage_v_392_2 = (((stage_v_135_2 * 3) + pub_r001134_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = (((stage_v_213_1 * 3) + pub_r001134_3_1) + 22) & 127;
  int stage_v_393_2 = (((stage_v_213_2 * 3) + pub_r001134_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001134_14_1 * 2) + 11) & 63;
  int stage_v_394_2 = ((pub_r001134_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001134_16_1 * 2) + 29) & 63;
  int stage_v_395_2 = ((pub_r001134_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001134_0_1 * 2) + 36) & 63;
  int stage_v_396_2 = ((pub_r001134_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = (((stage_v_102_1 * 3) + pub_r001134_3_1) + 42) & 127;
  int stage_v_397_2 = (((stage_v_102_2 * 3) + pub_r001134_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = ((pub_r001134_2_1 * 2) + 33) & 63;
  int stage_v_398_2 = ((pub_r001134_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = (((stage_v_1_1 * 3) + pub_r001134_3_1) + 33) & 127;
  int stage_v_399_2 = (((stage_v_1_2 * 3) + pub_r001134_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = (((stage_v_378_1 * 3) + pub_r001134_0_1) + 28) & 127;
  int stage_v_400_2 = (((stage_v_378_2 * 3) + pub_r001134_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = ((pub_r001134_13_1 * 2) + 22) & 63;
  int stage_v_401_2 = ((pub_r001134_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = (((stage_v_382_1 * 3) + pub_r001134_15_1) + 12) & 127;
  int stage_v_402_2 = (((stage_v_382_2 * 3) + pub_r001134_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = ((pub_r001134_8_1 * 2) + 12) & 63;
  int stage_v_403_2 = ((pub_r001134_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001134_15_1 * 2) + 10) & 63;
  int stage_v_404_2 = ((pub_r001134_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = (((stage_v_258_1 * 3) + pub_r001134_9_1) + 45) & 127;
  int stage_v_405_2 = (((stage_v_258_2 * 3) + pub_r001134_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((stage_v_232_1 * 3) + pub_r001134_11_1) + 27) & 127;
  int stage_v_406_2 = (((stage_v_232_2 * 3) + pub_r001134_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = (((stage_v_111_1 * 3) + pub_r001134_6_1) + 25) & 127;
  int stage_v_407_2 = (((stage_v_111_2 * 3) + pub_r001134_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_407_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_407_2 * 2)) & 255;
  int stage_v_408_1 = (((stage_v_384_1 * 3) + pub_r001134_14_1) + 18) & 127;
  int stage_v_408_2 = (((stage_v_384_2 * 3) + pub_r001134_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = (((stage_v_307_1 * 3) + pub_r001134_13_1) + 26) & 127;
  int stage_v_409_2 = (((stage_v_307_2 * 3) + pub_r001134_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = (((stage_v_83_1 * 3) + pub_r001134_4_1) + 7) & 127;
  int stage_v_410_2 = (((stage_v_83_2 * 3) + pub_r001134_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_410_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_410_2 * 2)) & 255;
  int stage_v_411_1 = ((pub_r001134_3_1 * 2) + 40) & 63;
  int stage_v_411_2 = ((pub_r001134_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((pub_r001134_1_1 * 2) + 16) & 63;
  int stage_v_412_2 = ((pub_r001134_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((pub_r001134_5_1 * 2) + 33) & 63;
  int stage_v_413_2 = ((pub_r001134_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = (((stage_v_383_1 * 3) + pub_r001134_15_1) + 36) & 127;
  int stage_v_414_2 = (((stage_v_383_2 * 3) + pub_r001134_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = (((stage_v_335_1 * 3) + pub_r001134_14_1) + 40) & 127;
  int stage_v_415_2 = (((stage_v_335_2 * 3) + pub_r001134_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001134_13_1 * 2) + 41) & 63;
  int stage_v_416_2 = ((pub_r001134_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = (((stage_v_240_1 * 3) + pub_r001134_10_1) + 6) & 127;
  int stage_v_417_2 = (((stage_v_240_2 * 3) + pub_r001134_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001134_11_1 * 2) + 31) & 63;
  int stage_v_418_2 = ((pub_r001134_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_400_1 * 3) + pub_r001134_8_1) + 35) & 127;
  int stage_v_419_2 = (((stage_v_400_2 * 3) + pub_r001134_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = (((stage_v_189_1 * 3) + pub_r001134_14_1) + 22) & 127;
  int stage_v_420_2 = (((stage_v_189_2 * 3) + pub_r001134_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001134_3_1 != sec_r001134_3_2);
  __CPROVER_assume(sec_r001134_14_1 != sec_r001134_14_2);
  __CPROVER_assume(pub_r001134_3_1 == pub_r001134_3_2);
  __CPROVER_assume(sec_r001134_10_1 != sec_r001134_10_2);
  __CPROVER_assume(pub_r001134_16_1 == pub_r001134_16_2);
  __CPROVER_assume(pub_r001134_11_1 == pub_r001134_11_2);
  __CPROVER_assume(sec_r001134_16_1 != sec_r001134_16_2);
  __CPROVER_assume(sec_r001134_6_1 != sec_r001134_6_2);
  __CPROVER_assume(sec_r001134_5_1 != sec_r001134_5_2);
  __CPROVER_assume(sec_r001134_4_1 != sec_r001134_4_2);
  __CPROVER_assume(sec_r001134_7_1 != sec_r001134_7_2);
  __CPROVER_assume(sec_r001134_11_1 != sec_r001134_11_2);
  __CPROVER_assume(pub_r001134_10_1 == pub_r001134_10_2);
  __CPROVER_assume(pub_r001134_2_1 == pub_r001134_2_2);
  __CPROVER_assume(pub_r001134_13_1 == pub_r001134_13_2);
  __CPROVER_assume(pub_r001134_9_1 == pub_r001134_9_2);
  __CPROVER_assume(sec_r001134_8_1 != sec_r001134_8_2);
  __CPROVER_assume(pub_r001134_4_1 == pub_r001134_4_2);
  __CPROVER_assume(sec_r001134_9_1 != sec_r001134_9_2);
  __CPROVER_assume(sec_r001134_15_1 != sec_r001134_15_2);
  __CPROVER_assume(sec_r001134_1_1 != sec_r001134_1_2);
  __CPROVER_assume(pub_r001134_6_1 == pub_r001134_6_2);
  __CPROVER_assume(sec_r001134_0_1 != sec_r001134_0_2);
  __CPROVER_assume(pub_r001134_12_1 == pub_r001134_12_2);
  __CPROVER_assume(pub_r001134_14_1 == pub_r001134_14_2);
  __CPROVER_assume(sec_r001134_2_1 != sec_r001134_2_2);
  __CPROVER_assume(pub_r001134_15_1 == pub_r001134_15_2);
  __CPROVER_assume(pub_r001134_0_1 == pub_r001134_0_2);
  __CPROVER_assume(pub_r001134_7_1 == pub_r001134_7_2);
  __CPROVER_assume(pub_r001134_8_1 == pub_r001134_8_2);
  __CPROVER_assume(pub_r001134_1_1 == pub_r001134_1_2);
  __CPROVER_assume(sec_r001134_12_1 != sec_r001134_12_2);
  __CPROVER_assume(pub_r001134_5_1 == pub_r001134_5_2);
  __CPROVER_assume(sec_r001134_13_1 != sec_r001134_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.head == st_var_0_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.id == st_var_2_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.gain_db == st_var_3_2.gain_db);
  assert(st_var_3_1.prev_out == st_var_3_2.prev_out);
  assert(st_var_3_1.cutoff == st_var_3_2.cutoff);
  assert(st_var_3_1.prev_in == st_var_3_2.prev_in);
  assert(st_var_3_1.mode == st_var_3_2.mode);
  assert(st_var_3_1.damping == st_var_3_2.damping);
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
}


