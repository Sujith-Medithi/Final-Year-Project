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
struct FilterState_R000395_9513_0
{
  short mode;
  short damping;
  int prev_in;
  int gain_db;
  short prev_out;
  int cutoff;
  int buffer[3];
};
struct EventLog_R000395_9513_1
{
  int signature;
  short timestamp;
  int code;
  short seq;
  int facility;
  int buffer[3];
};
struct DeviceConfig_R000395_9513_2
{
  short baud_rate;
  short stop_bits;
  int port;
  short parity;
  int buffer[3];
};
union TelemetryField_R000395_9513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000395_9513_1
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
void fn_R000395_9513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st_1 = {0};
  struct FilterState_R000395_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tally_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_57_1 > 22)
  {
    acc_1 = ((acc_1 + (tally_57_1 * 2)) + 5) & 127;
    aux_1 ^= tally_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_57_2 > 22)
  {
    acc_2 = ((acc_2 + (tally_57_2 * 2)) + 5) & 127;
    aux_2 ^= tally_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_57_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_56_1)
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

  switch (segment_56_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_80_1 = local_arr_1[aux_1 % 3];
  int phase_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_57_1 == tally_57_2);
  assert(segment_56_1 == segment_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_80_1 == phase_80_2);
}

int fn_R000395_9513_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tally_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_57 > 22)
  {
    acc = ((acc + (tally_57 * 2)) + 5) & 127;
    aux ^= tally_57 & 15;
  }
  else
  {
    acc = ((acc - tally_57) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_56 = (aux + st.buffer[1]) & 3;
  switch (segment_56)
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

  int local_arr[3] = {4, 9, 15};
  int phase_80 = local_arr[aux % 3];
  acc = (acc + (phase_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000395_9513_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000395_9513_1 st_1 = {0};
  struct EventLog_R000395_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quantum_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_99_1)
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

  switch (quantum_99_2)
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
  int coefficient_39_1 = local_arr_1[aux_1 % 3];
  int coefficient_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_39_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_30_1) & 63;
  aux_2 = (aux_2 + damping_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_99_1 == quantum_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_39_1 == coefficient_39_2);
  assert(damping_30_1 == damping_30_2);
}

int fn_R000395_9513_1(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000395_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quantum_99 = (aux + st.buffer[1]) & 3;
  switch (quantum_99)
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
  int coefficient_39 = local_arr[aux % 3];
  acc = (acc + (coefficient_39 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000395_9513_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000395_9513_2 st_1 = {0};
  struct DeviceConfig_R000395_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_70_1 = local_arr_1[aux_1 % 3];
  int threshold_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_70_2 * 2)) & 127;
  int coefficient_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_75_1)
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

  switch (coefficient_75_2)
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

  int tally_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_18_1) & 63;
  aux_2 = (aux_2 + tally_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_53_1 > 36)
  {
    acc_1 = ((acc_1 + (weight_53_1 * 2)) + 5) & 127;
    aux_1 ^= weight_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_53_2 > 36)
  {
    acc_2 = ((acc_2 + (weight_53_2 * 2)) + 5) & 127;
    aux_2 ^= weight_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
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

  assert(threshold_70_1 == threshold_70_2);
  assert(coefficient_75_1 == coefficient_75_2);
  assert(tally_18_1 == tally_18_2);
  assert(weight_53_1 == weight_53_2);
}

int fn_R000395_9513_2(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000395_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int threshold_70 = local_arr[aux % 3];
  acc = (acc + (threshold_70 * 2)) & 127;
  int coefficient_75 = (aux + st.buffer[1]) & 3;
  switch (coefficient_75)
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

  int tally_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_18) & 63;
  acc ^= aux;
  int weight_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_53 > 36)
  {
    acc = ((acc + (weight_53 * 2)) + 5) & 127;
    aux ^= weight_53 & 15;
  }
  else
  {
    acc = ((acc - weight_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000395_9513_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st_1 = {0};
  struct FilterState_R000395_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int index_reg_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_23_1) & 63;
  aux_2 = (aux_2 + index_reg_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_34_1 = local_arr_1[aux_1 % 3];
  int index_reg_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_34_2 * 2)) & 127;
  int window_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_54_1)
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

  switch (window_54_2)
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

  int threshold_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_70_1 > 22)
  {
    acc_1 = ((acc_1 + (threshold_70_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_70_2 > 22)
  {
    acc_2 = ((acc_2 + (threshold_70_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_23_1 == index_reg_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_34_1 == index_reg_34_2);
  assert(window_54_1 == window_54_2);
  assert(threshold_70_1 == threshold_70_2);
}

int fn_R000395_9513_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int index_reg_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_23) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_34 = local_arr[aux % 3];
  acc = (acc + (index_reg_34 * 2)) & 127;
  int window_54 = (aux + st.buffer[1]) & 3;
  switch (window_54)
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

  int threshold_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_70 > 22)
  {
    acc = ((acc + (threshold_70 * 2)) + 5) & 127;
    aux ^= threshold_70 & 15;
  }
  else
  {
    acc = ((acc - threshold_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000395_9513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st_1 = {0};
  struct FilterState_R000395_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_45_1 = local_arr_1[aux_1 % 3];
  int metric_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_45_2 * 2)) & 127;
  int margin_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_95_1) & 63;
  aux_2 = (aux_2 + margin_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_11_1 > 13)
  {
    acc_1 = ((acc_1 + (quotient_11_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_11_2 > 13)
  {
    acc_2 = ((acc_2 + (quotient_11_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_47_1)
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

  switch (bound_47_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_45_1 == metric_45_2);
  assert(margin_95_1 == margin_95_2);
  assert(quotient_11_1 == quotient_11_2);
  assert(bound_47_1 == bound_47_2);
}

int fn_R000395_9513_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int metric_45 = local_arr[aux % 3];
  acc = (acc + (metric_45 * 2)) & 127;
  int margin_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_95) & 63;
  acc ^= aux;
  int quotient_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_11 > 13)
  {
    acc = ((acc + (quotient_11 * 2)) + 5) & 127;
    aux ^= quotient_11 & 15;
  }
  else
  {
    acc = ((acc - quotient_11) + 11) & 127;
    aux += 3;
  }
  int bound_47 = (aux + st.buffer[1]) & 3;
  switch (bound_47)
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

void fn_R000395_9513_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000395_9513_1 st_1 = {0};
  struct EventLog_R000395_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quantum_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_29_1) & 63;
  aux_2 = (aux_2 + quantum_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_62_1 = local_arr_1[aux_1 % 3];
  int damping_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_62_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_29_1 == quantum_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_62_1 == damping_62_2);
}

int fn_R000395_9513_5(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000395_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quantum_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_29) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_62 = local_arr[aux % 3];
  acc = (acc + (damping_62 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000395_9513_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st_1 = {0};
  struct FilterState_R000395_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_24_1 = local_arr_1[aux_1 % 3];
  int quantum_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_24_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_39_1)
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

  switch (margin_39_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_24_1 == quantum_24_2);
  assert(margin_39_1 == margin_39_2);
}

int fn_R000395_9513_6(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int quantum_24 = local_arr[aux % 3];
  acc = (acc + (quantum_24 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_39 = (aux + st.buffer[1]) & 3;
  switch (margin_39)
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

void fn_R000395_9513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st_1 = {0};
  struct FilterState_R000395_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_53_1 = local_arr_1[aux_1 % 3];
  int segment_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_66_1 == tally_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_53_1 == segment_53_2);
}

int fn_R000395_9513_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
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

  int local_arr[3] = {4, 9, 15};
  int segment_53 = local_arr[aux % 3];
  acc = (acc + (segment_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000395_9513_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st_1 = {0};
  struct FilterState_R000395_9513_0 st_2 = {0};
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
  int index_reg_75_1 = local_arr_1[aux_1 % 3];
  int index_reg_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_75_2 * 2)) & 127;
  int metric_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_39_1)
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

  switch (metric_39_2)
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

  int residue_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_38_1 > 31)
  {
    acc_1 = ((acc_1 + (residue_38_1 * 2)) + 5) & 127;
    aux_1 ^= residue_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_38_2 > 31)
  {
    acc_2 = ((acc_2 + (residue_38_2 * 2)) + 5) & 127;
    aux_2 ^= residue_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_75_1 == index_reg_75_2);
  assert(metric_39_1 == metric_39_2);
  assert(residue_38_1 == residue_38_2);
}

int fn_R000395_9513_8(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_75 = local_arr[aux % 3];
  acc = (acc + (index_reg_75 * 2)) & 127;
  int metric_39 = (aux + st.buffer[1]) & 3;
  switch (metric_39)
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

  int residue_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_38 > 31)
  {
    acc = ((acc + (residue_38 * 2)) + 5) & 127;
    aux ^= residue_38 & 15;
  }
  else
  {
    acc = ((acc - residue_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000395_9513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000395_9513_1 st_1 = {0};
  struct EventLog_R000395_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int offset_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_31_1) & 63;
  aux_2 = (aux_2 + offset_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_16_1 > 10)
  {
    acc_1 = ((acc_1 + (threshold_16_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_16_2 > 10)
  {
    acc_2 = ((acc_2 + (threshold_16_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_53_1)
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

  switch (weight_53_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_31_1 == offset_31_2);
  assert(threshold_16_1 == threshold_16_2);
  assert(weight_53_1 == weight_53_2);
}

int fn_R000395_9513_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000395_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int offset_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_31) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_16 > 10)
  {
    acc = ((acc + (threshold_16 * 2)) + 5) & 127;
    aux ^= threshold_16 & 15;
  }
  else
  {
    acc = ((acc - threshold_16) + 11) & 127;
    aux += 3;
  }
  int weight_53 = (aux + st.buffer[1]) & 3;
  switch (weight_53)
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

void fn_R000395_9513_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000395_9513_1 st_1 = {0};
  struct EventLog_R000395_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int delta_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_75_1) & 63;
  aux_2 = (aux_2 + delta_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_23_1 > 26)
  {
    acc_1 = ((acc_1 + (threshold_23_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_23_2 > 26)
  {
    acc_2 = ((acc_2 + (threshold_23_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_60_1 = local_arr_1[aux_1 % 3];
  int delta_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_75_1 == delta_75_2);
  assert(threshold_23_1 == threshold_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_60_1 == delta_60_2);
}

int fn_R000395_9513_10(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000395_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int delta_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_75) & 63;
  acc ^= aux;
  int threshold_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_23 > 26)
  {
    acc = ((acc + (threshold_23 * 2)) + 5) & 127;
    aux ^= threshold_23 & 15;
  }
  else
  {
    acc = ((acc - threshold_23) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_60 = local_arr[aux % 3];
  acc = (acc + (delta_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000395_9513_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st_1 = {0};
  struct FilterState_R000395_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_98_1)
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

  switch (quantum_98_2)
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
  int damping_89_1 = local_arr_1[aux_1 % 3];
  int damping_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_98_1 == quantum_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_89_1 == damping_89_2);
}

int fn_R000395_9513_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_98 = (aux + st.buffer[1]) & 3;
  switch (quantum_98)
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
  int damping_89 = local_arr[aux % 3];
  acc = (acc + (damping_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000395_9513_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st_1 = {0};
  struct FilterState_R000395_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int index_reg_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_33_1 > 29)
  {
    acc_1 = ((acc_1 + (index_reg_33_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_33_2 > 29)
  {
    acc_2 = ((acc_2 + (index_reg_33_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_92_1) & 63;
  aux_2 = (aux_2 + accumulator_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_28_1 = local_arr_1[aux_1 % 3];
  int damping_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_33_1 == index_reg_33_2);
  assert(accumulator_92_1 == accumulator_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_28_1 == damping_28_2);
}

int fn_R000395_9513_12(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int index_reg_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_33 > 29)
  {
    acc = ((acc + (index_reg_33 * 2)) + 5) & 127;
    aux ^= index_reg_33 & 15;
  }
  else
  {
    acc = ((acc - index_reg_33) + 11) & 127;
    aux += 3;
  }
  int accumulator_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_92) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_28 = local_arr[aux % 3];
  acc = (acc + (damping_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000395_9513_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000395_9513_1 st_1 = {0};
  struct EventLog_R000395_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int window_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_13_1)
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

  switch (window_13_2)
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

  int bound_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_14_1) & 63;
  aux_2 = (aux_2 + bound_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_10_1 > 30)
  {
    acc_1 = ((acc_1 + (tally_10_1 * 2)) + 5) & 127;
    aux_1 ^= tally_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_10_2 > 30)
  {
    acc_2 = ((acc_2 + (tally_10_2 * 2)) + 5) & 127;
    aux_2 ^= tally_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_13_1 == window_13_2);
  assert(bound_14_1 == bound_14_2);
  assert(tally_10_1 == tally_10_2);
}

int fn_R000395_9513_13(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000395_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int window_13 = (aux + st.buffer[1]) & 3;
  switch (window_13)
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

  int bound_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_14) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_10 > 30)
  {
    acc = ((acc + (tally_10 * 2)) + 5) & 127;
    aux ^= tally_10 & 15;
  }
  else
  {
    acc = ((acc - tally_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000395_9513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st_1 = {0};
  struct FilterState_R000395_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_54_1) & 63;
  aux_2 = (aux_2 + quotient_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_54_1 == quotient_54_2);
}

int fn_R000395_9513_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000395_9513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000395_9513_2 st_1 = {0};
  struct DeviceConfig_R000395_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tally_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_99_1)
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

  switch (tally_99_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_90_1 = local_arr_1[aux_1 % 3];
  int tally_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_99_1 == tally_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_90_1 == tally_90_2);
}

int fn_R000395_9513_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000395_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tally_99 = (aux + st.buffer[1]) & 3;
  switch (tally_99)
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

  int local_arr[3] = {4, 9, 15};
  int tally_90 = local_arr[aux % 3];
  acc = (acc + (tally_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000395_9513_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000395_9513_2 st_1 = {0};
  struct DeviceConfig_R000395_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int metric_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_40_1)
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

  switch (metric_40_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_98_1) & 63;
  aux_2 = (aux_2 + pivot_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_74_1 = local_arr_1[aux_1 % 3];
  int quantum_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_40_1 == metric_40_2);
  assert(pivot_98_1 == pivot_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_74_1 == quantum_74_2);
}

int fn_R000395_9513_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000395_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int metric_40 = (aux + st.buffer[1]) & 3;
  switch (metric_40)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_98) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_74 = local_arr[aux % 3];
  acc = (acc + (quantum_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000395_9513_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st_1 = {0};
  struct FilterState_R000395_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int cursor_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_75_1) & 63;
  aux_2 = (aux_2 + cursor_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_76_1 = local_arr_1[aux_1 % 3];
  int segment_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_76_2 * 2)) & 127;
  int quantum_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_18_1)
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

  switch (quantum_18_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_75_1 == cursor_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_76_1 == segment_76_2);
  assert(quantum_18_1 == quantum_18_2);
}

int fn_R000395_9513_17(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000395_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int cursor_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_75) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_76 = local_arr[aux % 3];
  acc = (acc + (segment_76 * 2)) & 127;
  int quantum_18 = (aux + st.buffer[1]) & 3;
  switch (quantum_18)
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

void fn_R000395_9513_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000395_9513_2 st_1 = {0};
  struct DeviceConfig_R000395_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int checksum_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_95_1)
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

  switch (checksum_95_2)
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
  int offset_90_1 = local_arr_1[aux_1 % 3];
  int offset_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_90_2 * 2)) & 127;
  int margin_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_11_1 > 45)
  {
    acc_1 = ((acc_1 + (margin_11_1 * 2)) + 5) & 127;
    aux_1 ^= margin_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_11_2 > 45)
  {
    acc_2 = ((acc_2 + (margin_11_2 * 2)) + 5) & 127;
    aux_2 ^= margin_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_95_1 == checksum_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_90_1 == offset_90_2);
  assert(margin_11_1 == margin_11_2);
}

int fn_R000395_9513_18(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000395_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int checksum_95 = (aux + st.buffer[1]) & 3;
  switch (checksum_95)
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
  int offset_90 = local_arr[aux % 3];
  acc = (acc + (offset_90 * 2)) & 127;
  int margin_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_11 > 45)
  {
    acc = ((acc + (margin_11 * 2)) + 5) & 127;
    aux ^= margin_11 & 15;
  }
  else
  {
    acc = ((acc - margin_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000395_0_1;
  int sec_r000395_0_2;
  int sec_r000395_1_1;
  int sec_r000395_1_2;
  int sec_r000395_2_1;
  int sec_r000395_2_2;
  int sec_r000395_3_1;
  int sec_r000395_3_2;
  int sec_r000395_4_1;
  int sec_r000395_4_2;
  int sec_r000395_5_1;
  int sec_r000395_5_2;
  int sec_r000395_6_1;
  int sec_r000395_6_2;
  int sec_r000395_7_1;
  int sec_r000395_7_2;
  int sec_r000395_8_1;
  int sec_r000395_8_2;
  int sec_r000395_9_1;
  int sec_r000395_9_2;
  int sec_r000395_10_1;
  int sec_r000395_10_2;
  int sec_r000395_11_1;
  int sec_r000395_11_2;
  int sec_r000395_12_1;
  int sec_r000395_12_2;
  int sec_r000395_13_1;
  int sec_r000395_13_2;
  int sec_r000395_14_1;
  int sec_r000395_14_2;
  int sec_r000395_15_1;
  int sec_r000395_15_2;
  int sec_r000395_16_1;
  int sec_r000395_16_2;
  int sec_r000395_17_1;
  int sec_r000395_17_2;
  int sec_r000395_18_1;
  int sec_r000395_18_2;
  int sec_r000395_19_1;
  int sec_r000395_19_2;
  int pub_r000395_0_1;
  int pub_r000395_0_2;
  int pub_r000395_1_1;
  int pub_r000395_1_2;
  int pub_r000395_2_1;
  int pub_r000395_2_2;
  int pub_r000395_3_1;
  int pub_r000395_3_2;
  int pub_r000395_4_1;
  int pub_r000395_4_2;
  int pub_r000395_5_1;
  int pub_r000395_5_2;
  int pub_r000395_6_1;
  int pub_r000395_6_2;
  int pub_r000395_7_1;
  int pub_r000395_7_2;
  int pub_r000395_8_1;
  int pub_r000395_8_2;
  int pub_r000395_9_1;
  int pub_r000395_9_2;
  int pub_r000395_10_1;
  int pub_r000395_10_2;
  int pub_r000395_11_1;
  int pub_r000395_11_2;
  int pub_r000395_12_1;
  int pub_r000395_12_2;
  int pub_r000395_13_1;
  int pub_r000395_13_2;
  int pub_r000395_14_1;
  int pub_r000395_14_2;
  int pub_r000395_15_1;
  int pub_r000395_15_2;
  int pub_r000395_16_1;
  int pub_r000395_16_2;
  int pub_r000395_17_1;
  int pub_r000395_17_2;
  int pub_r000395_18_1;
  int pub_r000395_18_2;
  int pub_r000395_19_1;
  int pub_r000395_19_2;
  int pub_r000395_20_1;
  int pub_r000395_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000395_0_1 >= (-100)) && (pub_r000395_0_1 <= 100));
  __CPROVER_assume((pub_r000395_0_2 >= (-100)) && (pub_r000395_0_2 <= 100));
  __CPROVER_assume((pub_r000395_1_1 >= (-100)) && (pub_r000395_1_1 <= 100));
  __CPROVER_assume((pub_r000395_1_2 >= (-100)) && (pub_r000395_1_2 <= 100));
  __CPROVER_assume((pub_r000395_2_1 >= (-100)) && (pub_r000395_2_1 <= 100));
  __CPROVER_assume((pub_r000395_2_2 >= (-100)) && (pub_r000395_2_2 <= 100));
  __CPROVER_assume((pub_r000395_3_1 >= (-100)) && (pub_r000395_3_1 <= 100));
  __CPROVER_assume((pub_r000395_3_2 >= (-100)) && (pub_r000395_3_2 <= 100));
  __CPROVER_assume((pub_r000395_4_1 >= (-100)) && (pub_r000395_4_1 <= 100));
  __CPROVER_assume((pub_r000395_4_2 >= (-100)) && (pub_r000395_4_2 <= 100));
  __CPROVER_assume((pub_r000395_5_1 >= (-100)) && (pub_r000395_5_1 <= 100));
  __CPROVER_assume((pub_r000395_5_2 >= (-100)) && (pub_r000395_5_2 <= 100));
  __CPROVER_assume((pub_r000395_6_1 >= (-100)) && (pub_r000395_6_1 <= 100));
  __CPROVER_assume((pub_r000395_6_2 >= (-100)) && (pub_r000395_6_2 <= 100));
  __CPROVER_assume((pub_r000395_7_1 >= (-100)) && (pub_r000395_7_1 <= 100));
  __CPROVER_assume((pub_r000395_7_2 >= (-100)) && (pub_r000395_7_2 <= 100));
  __CPROVER_assume((pub_r000395_8_1 >= (-100)) && (pub_r000395_8_1 <= 100));
  __CPROVER_assume((pub_r000395_8_2 >= (-100)) && (pub_r000395_8_2 <= 100));
  __CPROVER_assume((pub_r000395_9_1 >= (-100)) && (pub_r000395_9_1 <= 100));
  __CPROVER_assume((pub_r000395_9_2 >= (-100)) && (pub_r000395_9_2 <= 100));
  __CPROVER_assume((pub_r000395_10_1 >= (-100)) && (pub_r000395_10_1 <= 100));
  __CPROVER_assume((pub_r000395_10_2 >= (-100)) && (pub_r000395_10_2 <= 100));
  __CPROVER_assume((pub_r000395_11_1 >= (-100)) && (pub_r000395_11_1 <= 100));
  __CPROVER_assume((pub_r000395_11_2 >= (-100)) && (pub_r000395_11_2 <= 100));
  __CPROVER_assume((pub_r000395_12_1 >= (-100)) && (pub_r000395_12_1 <= 100));
  __CPROVER_assume((pub_r000395_12_2 >= (-100)) && (pub_r000395_12_2 <= 100));
  __CPROVER_assume((pub_r000395_13_1 >= (-100)) && (pub_r000395_13_1 <= 100));
  __CPROVER_assume((pub_r000395_13_2 >= (-100)) && (pub_r000395_13_2 <= 100));
  __CPROVER_assume((pub_r000395_14_1 >= (-100)) && (pub_r000395_14_1 <= 100));
  __CPROVER_assume((pub_r000395_14_2 >= (-100)) && (pub_r000395_14_2 <= 100));
  __CPROVER_assume((pub_r000395_15_1 >= (-100)) && (pub_r000395_15_1 <= 100));
  __CPROVER_assume((pub_r000395_15_2 >= (-100)) && (pub_r000395_15_2 <= 100));
  __CPROVER_assume((pub_r000395_16_1 >= (-100)) && (pub_r000395_16_1 <= 100));
  __CPROVER_assume((pub_r000395_16_2 >= (-100)) && (pub_r000395_16_2 <= 100));
  __CPROVER_assume((pub_r000395_17_1 >= (-100)) && (pub_r000395_17_1 <= 100));
  __CPROVER_assume((pub_r000395_17_2 >= (-100)) && (pub_r000395_17_2 <= 100));
  __CPROVER_assume((pub_r000395_18_1 >= (-100)) && (pub_r000395_18_1 <= 100));
  __CPROVER_assume((pub_r000395_18_2 >= (-100)) && (pub_r000395_18_2 <= 100));
  __CPROVER_assume((pub_r000395_19_1 >= (-100)) && (pub_r000395_19_1 <= 100));
  __CPROVER_assume((pub_r000395_19_2 >= (-100)) && (pub_r000395_19_2 <= 100));
  __CPROVER_assume((pub_r000395_20_1 >= (-100)) && (pub_r000395_20_1 <= 100));
  __CPROVER_assume((pub_r000395_20_2 >= (-100)) && (pub_r000395_20_2 <= 100));
  __CPROVER_assume((sec_r000395_0_1 >= 0) && (sec_r000395_0_1 <= 255));
  __CPROVER_assume((sec_r000395_0_2 >= 0) && (sec_r000395_0_2 <= 255));
  __CPROVER_assume((sec_r000395_1_1 >= 0) && (sec_r000395_1_1 <= 255));
  __CPROVER_assume((sec_r000395_1_2 >= 0) && (sec_r000395_1_2 <= 255));
  __CPROVER_assume((sec_r000395_2_1 >= 0) && (sec_r000395_2_1 <= 255));
  __CPROVER_assume((sec_r000395_2_2 >= 0) && (sec_r000395_2_2 <= 255));
  __CPROVER_assume((sec_r000395_3_1 >= 0) && (sec_r000395_3_1 <= 255));
  __CPROVER_assume((sec_r000395_3_2 >= 0) && (sec_r000395_3_2 <= 255));
  __CPROVER_assume((sec_r000395_4_1 >= 0) && (sec_r000395_4_1 <= 255));
  __CPROVER_assume((sec_r000395_4_2 >= 0) && (sec_r000395_4_2 <= 255));
  __CPROVER_assume((sec_r000395_5_1 >= 0) && (sec_r000395_5_1 <= 255));
  __CPROVER_assume((sec_r000395_5_2 >= 0) && (sec_r000395_5_2 <= 255));
  __CPROVER_assume((sec_r000395_6_1 >= 0) && (sec_r000395_6_1 <= 255));
  __CPROVER_assume((sec_r000395_6_2 >= 0) && (sec_r000395_6_2 <= 255));
  __CPROVER_assume((sec_r000395_7_1 >= 0) && (sec_r000395_7_1 <= 255));
  __CPROVER_assume((sec_r000395_7_2 >= 0) && (sec_r000395_7_2 <= 255));
  __CPROVER_assume((sec_r000395_8_1 >= 0) && (sec_r000395_8_1 <= 255));
  __CPROVER_assume((sec_r000395_8_2 >= 0) && (sec_r000395_8_2 <= 255));
  __CPROVER_assume((sec_r000395_9_1 >= 0) && (sec_r000395_9_1 <= 255));
  __CPROVER_assume((sec_r000395_9_2 >= 0) && (sec_r000395_9_2 <= 255));
  __CPROVER_assume((sec_r000395_10_1 >= 0) && (sec_r000395_10_1 <= 255));
  __CPROVER_assume((sec_r000395_10_2 >= 0) && (sec_r000395_10_2 <= 255));
  __CPROVER_assume((sec_r000395_11_1 >= 0) && (sec_r000395_11_1 <= 255));
  __CPROVER_assume((sec_r000395_11_2 >= 0) && (sec_r000395_11_2 <= 255));
  __CPROVER_assume((sec_r000395_12_1 >= 0) && (sec_r000395_12_1 <= 255));
  __CPROVER_assume((sec_r000395_12_2 >= 0) && (sec_r000395_12_2 <= 255));
  __CPROVER_assume((sec_r000395_13_1 >= 0) && (sec_r000395_13_1 <= 255));
  __CPROVER_assume((sec_r000395_13_2 >= 0) && (sec_r000395_13_2 <= 255));
  __CPROVER_assume((sec_r000395_14_1 >= 0) && (sec_r000395_14_1 <= 255));
  __CPROVER_assume((sec_r000395_14_2 >= 0) && (sec_r000395_14_2 <= 255));
  __CPROVER_assume((sec_r000395_15_1 >= 0) && (sec_r000395_15_1 <= 255));
  __CPROVER_assume((sec_r000395_15_2 >= 0) && (sec_r000395_15_2 <= 255));
  __CPROVER_assume((sec_r000395_16_1 >= 0) && (sec_r000395_16_1 <= 255));
  __CPROVER_assume((sec_r000395_16_2 >= 0) && (sec_r000395_16_2 <= 255));
  __CPROVER_assume((sec_r000395_17_1 >= 0) && (sec_r000395_17_1 <= 255));
  __CPROVER_assume((sec_r000395_17_2 >= 0) && (sec_r000395_17_2 <= 255));
  __CPROVER_assume((sec_r000395_18_1 >= 0) && (sec_r000395_18_1 <= 255));
  __CPROVER_assume((sec_r000395_18_2 >= 0) && (sec_r000395_18_2 <= 255));
  __CPROVER_assume((sec_r000395_19_1 >= 0) && (sec_r000395_19_1 <= 255));
  __CPROVER_assume((sec_r000395_19_2 >= 0) && (sec_r000395_19_2 <= 255));
  struct FilterState_R000395_9513_0 st_var_0_1 = {0};
  struct FilterState_R000395_9513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000395_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000395_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000395_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000395_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000395_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000395_0_2 + 7) & 15;
  struct EventLog_R000395_9513_1 st_var_1_1 = {0};
  struct EventLog_R000395_9513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000395_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000395_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000395_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000395_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000395_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000395_0_2 + 9) & 15;
  struct DeviceConfig_R000395_9513_2 st_var_2_1 = {0};
  struct DeviceConfig_R000395_9513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000395_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000395_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000395_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000395_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000395_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000395_0_2 + 11) & 15;
  union TelemetryField_R000395_9513_0 u_var_1;
  union TelemetryField_R000395_9513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 4) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = ((st_var_1_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_1_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 49)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 49)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = (st_var_2_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_2_2.buffer[0] ^ 11) & 3;
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 10) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = (st_var_1_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_1_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 28)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 28)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = (((sec_r000395_1_1 << 1) ^ (sec_r000395_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_17_2 = (((sec_r000395_1_2 << 1) ^ (sec_r000395_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_17_1 & 63;
  out_sink_2 ^= stage_v_17_2 & 63;
  int stage_v_18_1 = (((sec_r000395_17_1 << 1) ^ (sec_r000395_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_18_2 = (((sec_r000395_17_2 << 1) ^ (sec_r000395_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = (((stage_v_18_1 << 2) ^ (sec_r000395_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_19_2 = (((stage_v_18_2 << 2) ^ (sec_r000395_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = (((sec_r000395_19_1 << 2) ^ (sec_r000395_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_20_2 = (((sec_r000395_19_2 << 2) ^ (sec_r000395_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = (((stage_v_17_1 << 2) ^ (sec_r000395_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_21_2 = (((stage_v_17_2 << 2) ^ (sec_r000395_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_21_1 & 63;
  out_sink_2 ^= stage_v_21_2 & 63;
  int stage_v_22_1 = (((stage_v_19_1 << 1) ^ (sec_r000395_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_22_2 = (((stage_v_19_2 << 1) ^ (sec_r000395_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = (((sec_r000395_0_1 << 2) ^ (sec_r000395_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_23_2 = (((sec_r000395_0_2 << 2) ^ (sec_r000395_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = (((sec_r000395_11_1 << 1) ^ (sec_r000395_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_24_2 = (((sec_r000395_11_2 << 1) ^ (sec_r000395_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = (((stage_v_20_1 << 2) ^ (sec_r000395_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_25_2 = (((stage_v_20_2 << 2) ^ (sec_r000395_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = (((stage_v_19_1 << 1) ^ (sec_r000395_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_26_2 = (((stage_v_19_2 << 1) ^ (sec_r000395_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = (((stage_v_19_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_27_2 = (((stage_v_19_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = (((stage_v_20_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_28_2 = (((stage_v_20_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = (((stage_v_25_1 << 1) ^ (sec_r000395_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_29_2 = (((stage_v_25_2 << 1) ^ (sec_r000395_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = (((sec_r000395_13_1 << 1) ^ (sec_r000395_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_30_2 = (((sec_r000395_13_2 << 1) ^ (sec_r000395_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = (((stage_v_26_1 << 2) ^ (sec_r000395_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_31_2 = (((stage_v_26_2 << 2) ^ (sec_r000395_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = (((sec_r000395_16_1 << 2) ^ (sec_r000395_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_32_2 = (((sec_r000395_16_2 << 2) ^ (sec_r000395_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = (((stage_v_31_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_33_2 = (((stage_v_31_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = (((stage_v_21_1 << 1) ^ (sec_r000395_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_34_2 = (((stage_v_21_2 << 1) ^ (sec_r000395_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = (((sec_r000395_15_1 << 2) ^ (sec_r000395_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_35_2 = (((sec_r000395_15_2 << 2) ^ (sec_r000395_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = (((sec_r000395_19_1 << 2) ^ (sec_r000395_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_36_2 = (((sec_r000395_19_2 << 2) ^ (sec_r000395_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = (((stage_v_30_1 << 1) ^ (sec_r000395_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_37_2 = (((stage_v_30_2 << 1) ^ (sec_r000395_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = (((stage_v_30_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_38_2 = (((stage_v_30_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = (((sec_r000395_8_1 << 1) ^ (sec_r000395_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_39_2 = (((sec_r000395_8_2 << 1) ^ (sec_r000395_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = (((sec_r000395_10_1 << 1) ^ (sec_r000395_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_40_2 = (((sec_r000395_10_2 << 1) ^ (sec_r000395_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = (((stage_v_29_1 << 1) ^ (sec_r000395_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_41_2 = (((stage_v_29_2 << 1) ^ (sec_r000395_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = (((sec_r000395_13_1 << 1) ^ (sec_r000395_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_42_2 = (((sec_r000395_13_2 << 1) ^ (sec_r000395_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = (((stage_v_35_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_43_2 = (((stage_v_35_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = (((stage_v_20_1 << 2) ^ (sec_r000395_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_44_2 = (((stage_v_20_2 << 2) ^ (sec_r000395_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = (((stage_v_18_1 << 1) ^ (sec_r000395_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_45_2 = (((stage_v_18_2 << 1) ^ (sec_r000395_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = (((stage_v_45_1 << 1) ^ (sec_r000395_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_46_2 = (((stage_v_45_2 << 1) ^ (sec_r000395_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = (((stage_v_31_1 << 2) ^ (sec_r000395_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_47_2 = (((stage_v_31_2 << 2) ^ (sec_r000395_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_47_1 & 63;
  out_sink_2 ^= stage_v_47_2 & 63;
  int stage_v_48_1 = (((sec_r000395_9_1 << 1) ^ (sec_r000395_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_48_2 = (((sec_r000395_9_2 << 1) ^ (sec_r000395_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = (((sec_r000395_12_1 << 1) ^ (sec_r000395_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_49_2 = (((sec_r000395_12_2 << 1) ^ (sec_r000395_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = (((stage_v_24_1 << 1) ^ (sec_r000395_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_50_2 = (((stage_v_24_2 << 1) ^ (sec_r000395_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = (((stage_v_43_1 << 1) ^ (sec_r000395_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_51_2 = (((stage_v_43_2 << 1) ^ (sec_r000395_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = (((stage_v_42_1 << 2) ^ (sec_r000395_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_52_2 = (((stage_v_42_2 << 2) ^ (sec_r000395_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = (((sec_r000395_8_1 << 2) ^ (sec_r000395_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_53_2 = (((sec_r000395_8_2 << 2) ^ (sec_r000395_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = (((stage_v_22_1 << 2) ^ (sec_r000395_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_54_2 = (((stage_v_22_2 << 2) ^ (sec_r000395_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = (((stage_v_18_1 << 1) ^ (sec_r000395_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_55_2 = (((stage_v_18_2 << 1) ^ (sec_r000395_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = (((stage_v_50_1 << 2) ^ (sec_r000395_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_56_2 = (((stage_v_50_2 << 2) ^ (sec_r000395_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = (((stage_v_27_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_57_2 = (((stage_v_27_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = (((sec_r000395_19_1 << 2) ^ (sec_r000395_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_58_2 = (((sec_r000395_19_2 << 2) ^ (sec_r000395_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = (((sec_r000395_17_1 << 1) ^ (sec_r000395_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_59_2 = (((sec_r000395_17_2 << 1) ^ (sec_r000395_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = (((sec_r000395_7_1 << 2) ^ (sec_r000395_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_60_2 = (((sec_r000395_7_2 << 2) ^ (sec_r000395_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = (((stage_v_56_1 << 2) ^ (sec_r000395_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_61_2 = (((stage_v_56_2 << 2) ^ (sec_r000395_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = (((stage_v_51_1 << 1) ^ (sec_r000395_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_62_2 = (((stage_v_51_2 << 1) ^ (sec_r000395_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = (((stage_v_21_1 << 1) ^ (sec_r000395_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_63_2 = (((stage_v_21_2 << 1) ^ (sec_r000395_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = (((sec_r000395_15_1 << 2) ^ (sec_r000395_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_64_2 = (((sec_r000395_15_2 << 2) ^ (sec_r000395_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = (((stage_v_49_1 << 2) ^ (sec_r000395_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_65_2 = (((stage_v_49_2 << 2) ^ (sec_r000395_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = (((sec_r000395_12_1 << 1) ^ (sec_r000395_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_66_2 = (((sec_r000395_12_2 << 1) ^ (sec_r000395_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = (((sec_r000395_13_1 << 2) ^ (sec_r000395_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_67_2 = (((sec_r000395_13_2 << 2) ^ (sec_r000395_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = (((stage_v_56_1 << 1) ^ (sec_r000395_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_68_2 = (((stage_v_56_2 << 1) ^ (sec_r000395_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = (((stage_v_64_1 << 2) ^ (sec_r000395_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_69_2 = (((stage_v_64_2 << 2) ^ (sec_r000395_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = (((sec_r000395_13_1 << 2) ^ (sec_r000395_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_70_2 = (((sec_r000395_13_2 << 2) ^ (sec_r000395_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = (((stage_v_69_1 << 1) ^ (sec_r000395_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_71_2 = (((stage_v_69_2 << 1) ^ (sec_r000395_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = (((stage_v_26_1 << 1) ^ (sec_r000395_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_72_2 = (((stage_v_26_2 << 1) ^ (sec_r000395_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = (((stage_v_63_1 << 1) ^ (sec_r000395_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_73_2 = (((stage_v_63_2 << 1) ^ (sec_r000395_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = (((stage_v_72_1 << 2) ^ (sec_r000395_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_74_2 = (((stage_v_72_2 << 2) ^ (sec_r000395_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = (((stage_v_22_1 << 2) ^ (sec_r000395_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_75_2 = (((stage_v_22_2 << 2) ^ (sec_r000395_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = (((stage_v_70_1 << 2) ^ (sec_r000395_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_76_2 = (((stage_v_70_2 << 2) ^ (sec_r000395_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = (((stage_v_47_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_77_2 = (((stage_v_47_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_77_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_77_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = (((sec_r000395_11_1 << 2) ^ (sec_r000395_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_78_2 = (((sec_r000395_11_2 << 2) ^ (sec_r000395_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = (((stage_v_65_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_79_2 = (((stage_v_65_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = (((sec_r000395_8_1 << 1) ^ (sec_r000395_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_80_2 = (((sec_r000395_8_2 << 1) ^ (sec_r000395_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = (((sec_r000395_10_1 << 2) ^ (sec_r000395_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_81_2 = (((sec_r000395_10_2 << 2) ^ (sec_r000395_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = (((stage_v_51_1 << 2) ^ (sec_r000395_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_82_2 = (((stage_v_51_2 << 2) ^ (sec_r000395_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = (((sec_r000395_15_1 << 2) ^ (sec_r000395_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_83_2 = (((sec_r000395_15_2 << 2) ^ (sec_r000395_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_83_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_83_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = (((sec_r000395_12_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_84_2 = (((sec_r000395_12_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = (((stage_v_74_1 << 2) ^ (sec_r000395_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_85_2 = (((stage_v_74_2 << 2) ^ (sec_r000395_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = (((sec_r000395_16_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_86_2 = (((sec_r000395_16_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = (((sec_r000395_16_1 << 2) ^ (sec_r000395_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_87_2 = (((sec_r000395_16_2 << 2) ^ (sec_r000395_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = (((stage_v_28_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_88_2 = (((stage_v_28_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = (((stage_v_67_1 << 1) ^ (sec_r000395_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_89_2 = (((stage_v_67_2 << 1) ^ (sec_r000395_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_89_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_89_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = (((stage_v_50_1 << 2) ^ (sec_r000395_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_90_2 = (((stage_v_50_2 << 2) ^ (sec_r000395_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = (((stage_v_34_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_91_2 = (((stage_v_34_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_91_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_91_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = (((stage_v_49_1 << 2) ^ (sec_r000395_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_92_2 = (((stage_v_49_2 << 2) ^ (sec_r000395_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_92_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_92_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = (((sec_r000395_14_1 << 2) ^ (sec_r000395_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_93_2 = (((sec_r000395_14_2 << 2) ^ (sec_r000395_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_93_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_93_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = (((stage_v_44_1 << 2) ^ (sec_r000395_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_94_2 = (((stage_v_44_2 << 2) ^ (sec_r000395_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = (((stage_v_92_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_95_2 = (((stage_v_92_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = (((stage_v_24_1 << 2) ^ (sec_r000395_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_96_2 = (((stage_v_24_2 << 2) ^ (sec_r000395_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = (((stage_v_69_1 << 2) ^ (sec_r000395_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_97_2 = (((stage_v_69_2 << 2) ^ (sec_r000395_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_97_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_97_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = (((stage_v_61_1 << 1) ^ (sec_r000395_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_98_2 = (((stage_v_61_2 << 1) ^ (sec_r000395_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_98_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_98_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = (((stage_v_59_1 << 2) ^ (sec_r000395_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_99_2 = (((stage_v_59_2 << 2) ^ (sec_r000395_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_99_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_99_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = (((stage_v_72_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_100_2 = (((stage_v_72_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_100_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_100_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = (((sec_r000395_9_1 << 2) ^ (sec_r000395_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_101_2 = (((sec_r000395_9_2 << 2) ^ (sec_r000395_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = (((stage_v_28_1 << 2) ^ (sec_r000395_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_102_2 = (((stage_v_28_2 << 2) ^ (sec_r000395_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = (((stage_v_102_1 << 1) ^ (sec_r000395_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_103_2 = (((stage_v_102_2 << 1) ^ (sec_r000395_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_103_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_103_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = (((stage_v_61_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_104_2 = (((stage_v_61_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_104_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_104_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = (((sec_r000395_11_1 << 1) ^ (sec_r000395_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_105_2 = (((sec_r000395_11_2 << 1) ^ (sec_r000395_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_105_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_105_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = (((sec_r000395_1_1 << 1) ^ (sec_r000395_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_106_2 = (((sec_r000395_1_2 << 1) ^ (sec_r000395_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = (((stage_v_83_1 << 1) ^ (sec_r000395_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_107_2 = (((stage_v_83_2 << 1) ^ (sec_r000395_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = (((sec_r000395_3_1 << 2) ^ (sec_r000395_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_108_2 = (((sec_r000395_3_2 << 2) ^ (sec_r000395_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_108_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_108_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = (((sec_r000395_0_1 << 1) ^ (sec_r000395_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_109_2 = (((sec_r000395_0_2 << 1) ^ (sec_r000395_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = (((stage_v_103_1 << 1) ^ (sec_r000395_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_110_2 = (((stage_v_103_2 << 1) ^ (sec_r000395_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_110_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_110_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = (((stage_v_48_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_111_2 = (((stage_v_48_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = (((stage_v_74_1 << 2) ^ (sec_r000395_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_112_2 = (((stage_v_74_2 << 2) ^ (sec_r000395_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_112_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_112_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = (((sec_r000395_18_1 << 1) ^ (sec_r000395_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_113_2 = (((sec_r000395_18_2 << 1) ^ (sec_r000395_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_113_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_113_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = (((sec_r000395_2_1 << 1) ^ (sec_r000395_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_114_2 = (((sec_r000395_2_2 << 1) ^ (sec_r000395_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_114_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_114_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = (((stage_v_46_1 << 2) ^ (sec_r000395_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_115_2 = (((stage_v_46_2 << 2) ^ (sec_r000395_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_115_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_115_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = (((sec_r000395_3_1 << 1) ^ (sec_r000395_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_116_2 = (((sec_r000395_3_2 << 1) ^ (sec_r000395_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = (((sec_r000395_12_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_117_2 = (((sec_r000395_12_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_117_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_117_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = (((stage_v_102_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_118_2 = (((stage_v_102_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = (((sec_r000395_7_1 << 2) ^ (sec_r000395_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_119_2 = (((sec_r000395_7_2 << 2) ^ (sec_r000395_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_119_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_119_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = (((stage_v_39_1 << 2) ^ (sec_r000395_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_120_2 = (((stage_v_39_2 << 2) ^ (sec_r000395_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = (((sec_r000395_18_1 << 2) ^ (sec_r000395_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_121_2 = (((sec_r000395_18_2 << 2) ^ (sec_r000395_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = (((stage_v_93_1 << 2) ^ (sec_r000395_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_122_2 = (((stage_v_93_2 << 2) ^ (sec_r000395_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_122_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_122_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = (((stage_v_120_1 << 1) ^ (sec_r000395_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_123_2 = (((stage_v_120_2 << 1) ^ (sec_r000395_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_123_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_123_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = (((stage_v_23_1 << 2) ^ (sec_r000395_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_124_2 = (((stage_v_23_2 << 2) ^ (sec_r000395_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = (((sec_r000395_11_1 << 1) ^ (sec_r000395_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_125_2 = (((sec_r000395_11_2 << 1) ^ (sec_r000395_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = (((sec_r000395_9_1 << 1) ^ (sec_r000395_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_126_2 = (((sec_r000395_9_2 << 1) ^ (sec_r000395_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_126_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_126_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = (((stage_v_38_1 << 2) ^ (sec_r000395_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_127_2 = (((stage_v_38_2 << 2) ^ (sec_r000395_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = (((stage_v_33_1 << 2) ^ (sec_r000395_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_128_2 = (((stage_v_33_2 << 2) ^ (sec_r000395_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = (((stage_v_126_1 << 2) ^ (sec_r000395_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_129_2 = (((stage_v_126_2 << 2) ^ (sec_r000395_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_129_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_129_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = (((stage_v_116_1 << 1) ^ (sec_r000395_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_130_2 = (((stage_v_116_2 << 1) ^ (sec_r000395_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = (((stage_v_85_1 << 2) ^ (sec_r000395_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_131_2 = (((stage_v_85_2 << 2) ^ (sec_r000395_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = (((sec_r000395_16_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_132_2 = (((sec_r000395_16_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = (((stage_v_78_1 << 2) ^ (sec_r000395_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_133_2 = (((stage_v_78_2 << 2) ^ (sec_r000395_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = (((stage_v_70_1 << 1) ^ (sec_r000395_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_134_2 = (((stage_v_70_2 << 1) ^ (sec_r000395_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_134_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_134_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = (((sec_r000395_3_1 << 1) ^ (sec_r000395_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_135_2 = (((sec_r000395_3_2 << 1) ^ (sec_r000395_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = (((stage_v_95_1 << 2) ^ (sec_r000395_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_136_2 = (((stage_v_95_2 << 2) ^ (sec_r000395_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_136_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_136_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = (((sec_r000395_14_1 << 2) ^ (sec_r000395_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_137_2 = (((sec_r000395_14_2 << 2) ^ (sec_r000395_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = (((sec_r000395_3_1 << 2) ^ (sec_r000395_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_138_2 = (((sec_r000395_3_2 << 2) ^ (sec_r000395_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = (((sec_r000395_15_1 << 1) ^ (sec_r000395_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_139_2 = (((sec_r000395_15_2 << 1) ^ (sec_r000395_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = (((stage_v_69_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_140_2 = (((stage_v_69_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = (((sec_r000395_8_1 << 1) ^ (sec_r000395_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_141_2 = (((sec_r000395_8_2 << 1) ^ (sec_r000395_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_141_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_141_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = (((sec_r000395_13_1 << 2) ^ (sec_r000395_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_142_2 = (((sec_r000395_13_2 << 2) ^ (sec_r000395_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_142_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_142_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = (((sec_r000395_0_1 << 2) ^ (sec_r000395_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_143_2 = (((sec_r000395_0_2 << 2) ^ (sec_r000395_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = (((stage_v_68_1 << 2) ^ (sec_r000395_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_144_2 = (((stage_v_68_2 << 2) ^ (sec_r000395_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = (((stage_v_66_1 << 1) ^ (sec_r000395_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_145_2 = (((stage_v_66_2 << 1) ^ (sec_r000395_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = (((stage_v_109_1 << 2) ^ (sec_r000395_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_146_2 = (((stage_v_109_2 << 2) ^ (sec_r000395_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_146_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_146_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = (((stage_v_146_1 << 2) ^ (sec_r000395_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_147_2 = (((stage_v_146_2 << 2) ^ (sec_r000395_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = (((stage_v_121_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_148_2 = (((stage_v_121_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = (((stage_v_103_1 << 2) ^ (sec_r000395_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_149_2 = (((stage_v_103_2 << 2) ^ (sec_r000395_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_149_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_149_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = (((stage_v_103_1 << 1) ^ (sec_r000395_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_150_2 = (((stage_v_103_2 << 1) ^ (sec_r000395_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_150_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_150_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = (((stage_v_69_1 << 1) ^ (sec_r000395_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_151_2 = (((stage_v_69_2 << 1) ^ (sec_r000395_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_151_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_151_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = (((stage_v_72_1 << 1) ^ (sec_r000395_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_152_2 = (((stage_v_72_2 << 1) ^ (sec_r000395_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = (((stage_v_22_1 << 2) ^ (sec_r000395_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_153_2 = (((stage_v_22_2 << 2) ^ (sec_r000395_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = (((stage_v_73_1 << 1) ^ (sec_r000395_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_154_2 = (((stage_v_73_2 << 1) ^ (sec_r000395_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_154_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_154_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = (((stage_v_87_1 << 1) ^ (sec_r000395_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_155_2 = (((stage_v_87_2 << 1) ^ (sec_r000395_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = (((stage_v_87_1 << 2) ^ (sec_r000395_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_156_2 = (((stage_v_87_2 << 2) ^ (sec_r000395_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_156_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_156_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = (((stage_v_140_1 << 2) ^ (sec_r000395_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_157_2 = (((stage_v_140_2 << 2) ^ (sec_r000395_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_157_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_157_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = (((stage_v_150_1 << 1) ^ (sec_r000395_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_158_2 = (((stage_v_150_2 << 1) ^ (sec_r000395_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_158_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_158_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = (((stage_v_135_1 << 2) ^ (sec_r000395_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_159_2 = (((stage_v_135_2 << 2) ^ (sec_r000395_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_159_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_159_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = (((stage_v_85_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_160_2 = (((stage_v_85_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = (((stage_v_71_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_161_2 = (((stage_v_71_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = (((stage_v_114_1 << 1) ^ (sec_r000395_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_162_2 = (((stage_v_114_2 << 1) ^ (sec_r000395_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_162_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_162_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = (((sec_r000395_10_1 << 1) ^ (sec_r000395_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_163_2 = (((sec_r000395_10_2 << 1) ^ (sec_r000395_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = (((sec_r000395_18_1 << 2) ^ (sec_r000395_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_164_2 = (((sec_r000395_18_2 << 2) ^ (sec_r000395_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_164_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_164_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = (((sec_r000395_13_1 << 2) ^ (sec_r000395_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_165_2 = (((sec_r000395_13_2 << 2) ^ (sec_r000395_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_165_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_165_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = (((stage_v_87_1 << 2) ^ (sec_r000395_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_166_2 = (((stage_v_87_2 << 2) ^ (sec_r000395_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = (((stage_v_63_1 << 2) ^ (sec_r000395_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_167_2 = (((stage_v_63_2 << 2) ^ (sec_r000395_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = (((sec_r000395_17_1 << 1) ^ (sec_r000395_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_168_2 = (((sec_r000395_17_2 << 1) ^ (sec_r000395_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_168_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_168_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = (((stage_v_28_1 << 1) ^ (sec_r000395_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_169_2 = (((stage_v_28_2 << 1) ^ (sec_r000395_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = (((stage_v_96_1 << 1) ^ (sec_r000395_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_170_2 = (((stage_v_96_2 << 1) ^ (sec_r000395_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_170_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_170_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = (((stage_v_120_1 << 2) ^ (sec_r000395_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_171_2 = (((stage_v_120_2 << 2) ^ (sec_r000395_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_171_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_171_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = (((stage_v_93_1 << 1) ^ (sec_r000395_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_172_2 = (((stage_v_93_2 << 1) ^ (sec_r000395_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_172_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_172_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = (((stage_v_25_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_173_2 = (((stage_v_25_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = (((sec_r000395_7_1 << 2) ^ (sec_r000395_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_174_2 = (((sec_r000395_7_2 << 2) ^ (sec_r000395_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_174_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_174_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = (((sec_r000395_1_1 << 1) ^ (sec_r000395_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_175_2 = (((sec_r000395_1_2 << 1) ^ (sec_r000395_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_175_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_175_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = (((stage_v_130_1 << 1) ^ (sec_r000395_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_176_2 = (((stage_v_130_2 << 1) ^ (sec_r000395_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_176_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_176_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = (((stage_v_27_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_177_2 = (((stage_v_27_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_177_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_177_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = (((stage_v_66_1 << 2) ^ (sec_r000395_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_178_2 = (((stage_v_66_2 << 2) ^ (sec_r000395_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_178_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_178_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = (((stage_v_60_1 << 1) ^ (sec_r000395_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_179_2 = (((stage_v_60_2 << 1) ^ (sec_r000395_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_179_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_179_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = (((sec_r000395_19_1 << 1) ^ (sec_r000395_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_180_2 = (((sec_r000395_19_2 << 1) ^ (sec_r000395_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_180_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_180_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = (((stage_v_149_1 << 1) ^ (sec_r000395_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_181_2 = (((stage_v_149_2 << 1) ^ (sec_r000395_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = (((sec_r000395_11_1 << 2) ^ (sec_r000395_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_182_2 = (((sec_r000395_11_2 << 2) ^ (sec_r000395_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_182_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_182_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = (((stage_v_86_1 << 1) ^ (sec_r000395_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_183_2 = (((stage_v_86_2 << 1) ^ (sec_r000395_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_183_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_183_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = (((sec_r000395_19_1 << 2) ^ (sec_r000395_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_184_2 = (((sec_r000395_19_2 << 2) ^ (sec_r000395_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_184_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_184_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = (((sec_r000395_19_1 << 2) ^ (sec_r000395_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_185_2 = (((sec_r000395_19_2 << 2) ^ (sec_r000395_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_185_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_185_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = (((sec_r000395_4_1 << 1) ^ (sec_r000395_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_186_2 = (((sec_r000395_4_2 << 1) ^ (sec_r000395_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_186_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_186_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_186_1 & 63;
  out_sink_2 ^= stage_v_186_2 & 63;
  int stage_v_187_1 = (((stage_v_141_1 << 1) ^ (sec_r000395_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_187_2 = (((stage_v_141_2 << 1) ^ (sec_r000395_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_187_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_187_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = (((stage_v_84_1 << 1) ^ (sec_r000395_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_188_2 = (((stage_v_84_2 << 1) ^ (sec_r000395_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_188_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_188_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = (((stage_v_56_1 << 1) ^ (sec_r000395_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_189_2 = (((stage_v_56_2 << 1) ^ (sec_r000395_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_189_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_189_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = (((stage_v_140_1 << 2) ^ (sec_r000395_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_190_2 = (((stage_v_140_2 << 2) ^ (sec_r000395_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_190_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_190_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = (((stage_v_116_1 << 1) ^ (sec_r000395_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_191_2 = (((stage_v_116_2 << 1) ^ (sec_r000395_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_191_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_191_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = (((stage_v_26_1 << 1) ^ (sec_r000395_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_192_2 = (((stage_v_26_2 << 1) ^ (sec_r000395_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_192_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_192_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = (((stage_v_124_1 << 2) ^ (sec_r000395_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_193_2 = (((stage_v_124_2 << 2) ^ (sec_r000395_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_193_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_193_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = (((sec_r000395_3_1 << 1) ^ (sec_r000395_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_194_2 = (((sec_r000395_3_2 << 1) ^ (sec_r000395_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_194_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_194_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = (((sec_r000395_13_1 << 2) ^ (sec_r000395_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_195_2 = (((sec_r000395_13_2 << 2) ^ (sec_r000395_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_195_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_195_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = (((stage_v_150_1 << 2) ^ (sec_r000395_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_196_2 = (((stage_v_150_2 << 2) ^ (sec_r000395_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_196_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_196_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = (((sec_r000395_0_1 << 2) ^ (sec_r000395_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_197_2 = (((sec_r000395_0_2 << 2) ^ (sec_r000395_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_197_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_197_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = (((stage_v_160_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_198_2 = (((stage_v_160_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_198_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_198_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = (((stage_v_155_1 << 2) ^ (sec_r000395_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_199_2 = (((stage_v_155_2 << 2) ^ (sec_r000395_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_199_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_199_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = (((sec_r000395_10_1 << 1) ^ (sec_r000395_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_200_2 = (((sec_r000395_10_2 << 1) ^ (sec_r000395_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_200_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_200_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = (((stage_v_49_1 << 1) ^ (sec_r000395_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_201_2 = (((stage_v_49_2 << 1) ^ (sec_r000395_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_201_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_201_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = (((stage_v_30_1 << 1) ^ (sec_r000395_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_202_2 = (((stage_v_30_2 << 1) ^ (sec_r000395_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_202_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_202_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = (((stage_v_150_1 << 1) ^ (sec_r000395_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_203_2 = (((stage_v_150_2 << 1) ^ (sec_r000395_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_203_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_203_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = (((stage_v_188_1 << 1) ^ (sec_r000395_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_204_2 = (((stage_v_188_2 << 1) ^ (sec_r000395_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_204_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_204_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = (((stage_v_177_1 << 1) ^ (sec_r000395_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_205_2 = (((stage_v_177_2 << 1) ^ (sec_r000395_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_205_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_205_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = (((sec_r000395_1_1 << 2) ^ (sec_r000395_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_206_2 = (((sec_r000395_1_2 << 2) ^ (sec_r000395_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_206_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_206_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = (((stage_v_157_1 << 1) ^ (sec_r000395_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_207_2 = (((stage_v_157_2 << 1) ^ (sec_r000395_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_207_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_207_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = (((stage_v_166_1 << 2) ^ (sec_r000395_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_208_2 = (((stage_v_166_2 << 2) ^ (sec_r000395_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_208_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_208_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = (((sec_r000395_18_1 << 1) ^ (sec_r000395_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_209_2 = (((sec_r000395_18_2 << 1) ^ (sec_r000395_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_209_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_209_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = (((stage_v_164_1 << 2) ^ (sec_r000395_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_210_2 = (((stage_v_164_2 << 2) ^ (sec_r000395_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_210_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_210_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = (((stage_v_85_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_211_2 = (((stage_v_85_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_211_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_211_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = (((stage_v_137_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_212_2 = (((stage_v_137_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_212_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_212_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = (((sec_r000395_18_1 << 2) ^ (sec_r000395_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_213_2 = (((sec_r000395_18_2 << 2) ^ (sec_r000395_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_213_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_213_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = (((stage_v_167_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_214_2 = (((stage_v_167_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_214_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_214_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = (((stage_v_128_1 << 2) ^ (sec_r000395_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_215_2 = (((stage_v_128_2 << 2) ^ (sec_r000395_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_215_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_215_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = (((stage_v_49_1 << 1) ^ (sec_r000395_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_216_2 = (((stage_v_49_2 << 1) ^ (sec_r000395_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_216_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_216_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = (((stage_v_191_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_217_2 = (((stage_v_191_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_217_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_217_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = (((stage_v_30_1 << 1) ^ (sec_r000395_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_218_2 = (((stage_v_30_2 << 1) ^ (sec_r000395_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_218_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_218_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = (((stage_v_60_1 << 2) ^ (sec_r000395_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_219_2 = (((stage_v_60_2 << 2) ^ (sec_r000395_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_219_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_219_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = (((sec_r000395_11_1 << 1) ^ (sec_r000395_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_220_2 = (((sec_r000395_11_2 << 1) ^ (sec_r000395_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_220_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_220_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = (((stage_v_144_1 << 2) ^ (sec_r000395_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_221_2 = (((stage_v_144_2 << 2) ^ (sec_r000395_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_221_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_221_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = (((sec_r000395_6_1 << 2) ^ (sec_r000395_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_222_2 = (((sec_r000395_6_2 << 2) ^ (sec_r000395_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_222_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_222_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = (((stage_v_138_1 << 1) ^ (sec_r000395_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_223_2 = (((stage_v_138_2 << 1) ^ (sec_r000395_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_223_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_223_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_223_1 & 63;
  out_sink_2 ^= stage_v_223_2 & 63;
  int stage_v_224_1 = (((stage_v_163_1 << 1) ^ (sec_r000395_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_224_2 = (((stage_v_163_2 << 1) ^ (sec_r000395_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_224_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_224_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = (((stage_v_143_1 << 2) ^ (sec_r000395_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_225_2 = (((stage_v_143_2 << 2) ^ (sec_r000395_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_225_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_225_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = (((sec_r000395_17_1 << 2) ^ (sec_r000395_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_226_2 = (((sec_r000395_17_2 << 2) ^ (sec_r000395_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_226_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_226_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = (((sec_r000395_11_1 << 1) ^ (sec_r000395_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_227_2 = (((sec_r000395_11_2 << 1) ^ (sec_r000395_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_227_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_227_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = (((stage_v_47_1 << 2) ^ (sec_r000395_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_228_2 = (((stage_v_47_2 << 2) ^ (sec_r000395_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_228_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_228_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = (((sec_r000395_6_1 << 2) ^ (sec_r000395_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_229_2 = (((sec_r000395_6_2 << 2) ^ (sec_r000395_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_229_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_229_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = (((stage_v_29_1 << 1) ^ (sec_r000395_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_230_2 = (((stage_v_29_2 << 1) ^ (sec_r000395_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_230_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_230_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = (((sec_r000395_15_1 << 1) ^ (sec_r000395_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_231_2 = (((sec_r000395_15_2 << 1) ^ (sec_r000395_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_231_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_231_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = (((stage_v_32_1 << 2) ^ (sec_r000395_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_232_2 = (((stage_v_32_2 << 2) ^ (sec_r000395_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_232_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_232_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = (((sec_r000395_11_1 << 2) ^ (sec_r000395_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_233_2 = (((sec_r000395_11_2 << 2) ^ (sec_r000395_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_233_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_233_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = (((sec_r000395_2_1 << 2) ^ (sec_r000395_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_234_2 = (((sec_r000395_2_2 << 2) ^ (sec_r000395_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_234_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_234_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = (((stage_v_159_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_235_2 = (((stage_v_159_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_235_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_235_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = (((stage_v_203_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_236_2 = (((stage_v_203_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_236_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_236_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = (((stage_v_179_1 << 1) ^ (sec_r000395_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_237_2 = (((stage_v_179_2 << 1) ^ (sec_r000395_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_237_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_237_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = (((sec_r000395_11_1 << 2) ^ (sec_r000395_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_238_2 = (((sec_r000395_11_2 << 2) ^ (sec_r000395_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_238_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_238_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = (((sec_r000395_14_1 << 1) ^ (sec_r000395_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_239_2 = (((sec_r000395_14_2 << 1) ^ (sec_r000395_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_239_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_239_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = (((stage_v_194_1 << 2) ^ (sec_r000395_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_240_2 = (((stage_v_194_2 << 2) ^ (sec_r000395_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_240_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_240_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = (((sec_r000395_18_1 << 2) ^ (sec_r000395_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_241_2 = (((sec_r000395_18_2 << 2) ^ (sec_r000395_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_241_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_241_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = (((stage_v_152_1 << 2) ^ (sec_r000395_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_242_2 = (((stage_v_152_2 << 2) ^ (sec_r000395_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_242_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_242_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = (((stage_v_203_1 << 2) ^ (sec_r000395_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_243_2 = (((stage_v_203_2 << 2) ^ (sec_r000395_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_243_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_243_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = (((stage_v_196_1 << 2) ^ (sec_r000395_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_244_2 = (((stage_v_196_2 << 2) ^ (sec_r000395_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_244_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_244_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = (((sec_r000395_6_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_245_2 = (((sec_r000395_6_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_245_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_245_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = (((stage_v_85_1 << 1) ^ (sec_r000395_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_246_2 = (((stage_v_85_2 << 1) ^ (sec_r000395_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_246_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_246_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = (((stage_v_63_1 << 2) ^ (sec_r000395_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_247_2 = (((stage_v_63_2 << 2) ^ (sec_r000395_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_247_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_247_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = (((sec_r000395_10_1 << 2) ^ (sec_r000395_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_248_2 = (((sec_r000395_10_2 << 2) ^ (sec_r000395_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_248_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_248_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = (((sec_r000395_10_1 << 1) ^ (sec_r000395_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_249_2 = (((sec_r000395_10_2 << 1) ^ (sec_r000395_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_249_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_249_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = (((sec_r000395_14_1 << 2) ^ (sec_r000395_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_250_2 = (((sec_r000395_14_2 << 2) ^ (sec_r000395_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_250_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_250_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = (((stage_v_125_1 << 1) ^ (sec_r000395_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_251_2 = (((stage_v_125_2 << 1) ^ (sec_r000395_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_251_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_251_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = (((stage_v_22_1 << 2) ^ (sec_r000395_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_252_2 = (((stage_v_22_2 << 2) ^ (sec_r000395_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_252_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_252_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = (((sec_r000395_18_1 << 1) ^ (sec_r000395_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_253_2 = (((sec_r000395_18_2 << 1) ^ (sec_r000395_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_253_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_253_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = (((stage_v_145_1 << 1) ^ (sec_r000395_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_254_2 = (((stage_v_145_2 << 1) ^ (sec_r000395_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_254_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_254_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = (((sec_r000395_2_1 << 1) ^ (sec_r000395_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_255_2 = (((sec_r000395_2_2 << 1) ^ (sec_r000395_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_255_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_255_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = (((sec_r000395_12_1 << 1) ^ (sec_r000395_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_256_2 = (((sec_r000395_12_2 << 1) ^ (sec_r000395_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_256_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_256_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = (((stage_v_210_1 << 1) ^ (sec_r000395_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_257_2 = (((stage_v_210_2 << 1) ^ (sec_r000395_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_257_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_257_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = (((stage_v_159_1 << 2) ^ (sec_r000395_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_258_2 = (((stage_v_159_2 << 2) ^ (sec_r000395_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_258_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_258_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = (((stage_v_161_1 << 1) ^ (sec_r000395_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_259_2 = (((stage_v_161_2 << 1) ^ (sec_r000395_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_259_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_259_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = (((stage_v_109_1 << 2) ^ (sec_r000395_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_260_2 = (((stage_v_109_2 << 2) ^ (sec_r000395_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_260_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_260_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = (((stage_v_179_1 << 1) ^ (sec_r000395_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_261_2 = (((stage_v_179_2 << 1) ^ (sec_r000395_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_261_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_261_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = (((stage_v_110_1 << 2) ^ (sec_r000395_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_262_2 = (((stage_v_110_2 << 2) ^ (sec_r000395_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_262_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_262_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = (((sec_r000395_13_1 << 1) ^ (sec_r000395_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_263_2 = (((sec_r000395_13_2 << 1) ^ (sec_r000395_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_263_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_263_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = (((sec_r000395_19_1 << 1) ^ (sec_r000395_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_264_2 = (((sec_r000395_19_2 << 1) ^ (sec_r000395_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_264_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_264_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = (((stage_v_85_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_265_2 = (((stage_v_85_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_265_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_265_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = (((sec_r000395_9_1 << 1) ^ (sec_r000395_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_266_2 = (((sec_r000395_9_2 << 1) ^ (sec_r000395_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_266_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_266_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = (((stage_v_92_1 << 1) ^ (sec_r000395_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_267_2 = (((stage_v_92_2 << 1) ^ (sec_r000395_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_267_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_267_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = (((stage_v_222_1 << 2) ^ (sec_r000395_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_268_2 = (((stage_v_222_2 << 2) ^ (sec_r000395_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_268_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_268_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_268_1 & 63;
  out_sink_2 ^= stage_v_268_2 & 63;
  int stage_v_269_1 = (((stage_v_143_1 << 2) ^ (sec_r000395_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_269_2 = (((stage_v_143_2 << 2) ^ (sec_r000395_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_269_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_269_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = (((stage_v_143_1 << 2) ^ (sec_r000395_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_270_2 = (((stage_v_143_2 << 2) ^ (sec_r000395_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_270_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_270_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = (((sec_r000395_10_1 << 1) ^ (sec_r000395_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_271_2 = (((sec_r000395_10_2 << 1) ^ (sec_r000395_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_271_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_271_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = (((stage_v_264_1 << 2) ^ (sec_r000395_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_272_2 = (((stage_v_264_2 << 2) ^ (sec_r000395_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_272_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_272_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = (((stage_v_103_1 << 1) ^ (sec_r000395_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_273_2 = (((stage_v_103_2 << 1) ^ (sec_r000395_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_273_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_273_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = (((sec_r000395_8_1 << 2) ^ (sec_r000395_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_274_2 = (((sec_r000395_8_2 << 2) ^ (sec_r000395_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_274_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_274_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = (((sec_r000395_9_1 << 2) ^ (sec_r000395_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_275_2 = (((sec_r000395_9_2 << 2) ^ (sec_r000395_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_275_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_275_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = (((stage_v_238_1 << 1) ^ (sec_r000395_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_276_2 = (((stage_v_238_2 << 1) ^ (sec_r000395_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_276_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_276_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = (((stage_v_200_1 << 1) ^ (sec_r000395_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_277_2 = (((stage_v_200_2 << 1) ^ (sec_r000395_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_277_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_277_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = (((stage_v_160_1 << 2) ^ (sec_r000395_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_278_2 = (((stage_v_160_2 << 2) ^ (sec_r000395_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_278_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_278_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = (((stage_v_120_1 << 2) ^ (sec_r000395_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_279_2 = (((stage_v_120_2 << 2) ^ (sec_r000395_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_279_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_279_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = (((stage_v_244_1 << 1) ^ (sec_r000395_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_280_2 = (((stage_v_244_2 << 1) ^ (sec_r000395_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_280_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_280_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = (((stage_v_204_1 << 2) ^ (sec_r000395_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_281_2 = (((stage_v_204_2 << 2) ^ (sec_r000395_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_281_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_281_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = (((sec_r000395_5_1 << 1) ^ (sec_r000395_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_282_2 = (((sec_r000395_5_2 << 1) ^ (sec_r000395_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_282_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_282_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = (((stage_v_28_1 << 1) ^ (sec_r000395_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_283_2 = (((stage_v_28_2 << 1) ^ (sec_r000395_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_283_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_283_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = (((sec_r000395_12_1 << 1) ^ (sec_r000395_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_284_2 = (((sec_r000395_12_2 << 1) ^ (sec_r000395_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_284_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_284_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = (((sec_r000395_7_1 << 2) ^ (sec_r000395_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_285_2 = (((sec_r000395_7_2 << 2) ^ (sec_r000395_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_285_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_285_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_285_1 & 63;
  out_sink_2 ^= stage_v_285_2 & 63;
  int stage_v_286_1 = (((stage_v_77_1 << 1) ^ (sec_r000395_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_286_2 = (((stage_v_77_2 << 1) ^ (sec_r000395_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_286_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_286_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = (((stage_v_207_1 << 2) ^ (sec_r000395_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_287_2 = (((stage_v_207_2 << 2) ^ (sec_r000395_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_287_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_287_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = (((sec_r000395_10_1 << 1) ^ (sec_r000395_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_288_2 = (((sec_r000395_10_2 << 1) ^ (sec_r000395_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_288_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_288_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_288_1 & 63;
  out_sink_2 ^= stage_v_288_2 & 63;
  int stage_v_289_1 = (((sec_r000395_17_1 << 2) ^ (sec_r000395_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_289_2 = (((sec_r000395_17_2 << 2) ^ (sec_r000395_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_289_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_289_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = (((stage_v_229_1 << 1) ^ (sec_r000395_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_290_2 = (((stage_v_229_2 << 1) ^ (sec_r000395_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_290_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_290_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = (((sec_r000395_15_1 << 2) ^ (sec_r000395_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_291_2 = (((sec_r000395_15_2 << 2) ^ (sec_r000395_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_291_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_291_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = (((stage_v_18_1 << 1) ^ (sec_r000395_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_292_2 = (((stage_v_18_2 << 1) ^ (sec_r000395_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_292_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_292_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = (((sec_r000395_16_1 << 1) ^ (sec_r000395_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_293_2 = (((sec_r000395_16_2 << 1) ^ (sec_r000395_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_293_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_293_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = (((stage_v_55_1 << 2) ^ (sec_r000395_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_294_2 = (((stage_v_55_2 << 2) ^ (sec_r000395_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_294_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_294_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = (((stage_v_115_1 << 1) ^ (sec_r000395_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_295_2 = (((stage_v_115_2 << 1) ^ (sec_r000395_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_295_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_295_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = (((stage_v_272_1 << 2) ^ (sec_r000395_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_296_2 = (((stage_v_272_2 << 2) ^ (sec_r000395_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_296_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_296_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = (((sec_r000395_17_1 << 1) ^ (sec_r000395_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_297_2 = (((sec_r000395_17_2 << 1) ^ (sec_r000395_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_297_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_297_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = (((stage_v_78_1 << 1) ^ (sec_r000395_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_298_2 = (((stage_v_78_2 << 1) ^ (sec_r000395_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_298_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_298_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = (((sec_r000395_1_1 << 2) ^ (sec_r000395_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_299_2 = (((sec_r000395_1_2 << 2) ^ (sec_r000395_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_299_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_299_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = (((sec_r000395_18_1 << 2) ^ (sec_r000395_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_300_2 = (((sec_r000395_18_2 << 2) ^ (sec_r000395_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_300_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_300_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = (((stage_v_40_1 << 2) ^ (sec_r000395_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_301_2 = (((stage_v_40_2 << 2) ^ (sec_r000395_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_301_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_301_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = (((stage_v_281_1 << 1) ^ (sec_r000395_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_302_2 = (((stage_v_281_2 << 1) ^ (sec_r000395_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_302_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_302_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_302_1 & 63;
  out_sink_2 ^= stage_v_302_2 & 63;
  int stage_v_303_1 = (((stage_v_96_1 << 2) ^ (sec_r000395_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_303_2 = (((stage_v_96_2 << 2) ^ (sec_r000395_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_303_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_303_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = (((stage_v_167_1 << 2) ^ (sec_r000395_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_304_2 = (((stage_v_167_2 << 2) ^ (sec_r000395_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_304_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_304_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = (((sec_r000395_15_1 << 1) ^ (sec_r000395_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_305_2 = (((sec_r000395_15_2 << 1) ^ (sec_r000395_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_305_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_305_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = (((stage_v_200_1 << 1) ^ (sec_r000395_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_306_2 = (((stage_v_200_2 << 1) ^ (sec_r000395_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_306_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_306_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = (((sec_r000395_19_1 << 2) ^ (sec_r000395_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_307_2 = (((sec_r000395_19_2 << 2) ^ (sec_r000395_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_307_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_307_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = (((stage_v_292_1 << 2) ^ (sec_r000395_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_308_2 = (((stage_v_292_2 << 2) ^ (sec_r000395_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_308_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_308_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = (((stage_v_299_1 << 2) ^ (sec_r000395_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_309_2 = (((stage_v_299_2 << 2) ^ (sec_r000395_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_309_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_309_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = (((stage_v_287_1 << 2) ^ (sec_r000395_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_310_2 = (((stage_v_287_2 << 2) ^ (sec_r000395_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_310_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_310_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = (((stage_v_234_1 << 2) ^ (sec_r000395_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_311_2 = (((stage_v_234_2 << 2) ^ (sec_r000395_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_311_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_311_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = (((stage_v_18_1 << 2) ^ (sec_r000395_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_312_2 = (((stage_v_18_2 << 2) ^ (sec_r000395_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_312_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_312_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = (((stage_v_292_1 << 2) ^ (sec_r000395_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_313_2 = (((stage_v_292_2 << 2) ^ (sec_r000395_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_313_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_313_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = (((stage_v_176_1 << 2) ^ (sec_r000395_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_314_2 = (((stage_v_176_2 << 2) ^ (sec_r000395_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_314_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_314_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_314_1 & 63;
  out_sink_2 ^= stage_v_314_2 & 63;
  int stage_v_315_1 = (((stage_v_159_1 << 1) ^ (sec_r000395_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_315_2 = (((stage_v_159_2 << 1) ^ (sec_r000395_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_315_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_315_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = (((sec_r000395_1_1 << 1) ^ (sec_r000395_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_316_2 = (((sec_r000395_1_2 << 1) ^ (sec_r000395_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_316_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_316_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_316_1 & 63;
  out_sink_2 ^= stage_v_316_2 & 63;
  int stage_v_317_1 = (((stage_v_219_1 << 2) ^ (sec_r000395_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_317_2 = (((stage_v_219_2 << 2) ^ (sec_r000395_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_317_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_317_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = (((sec_r000395_3_1 << 2) ^ (sec_r000395_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_318_2 = (((sec_r000395_3_2 << 2) ^ (sec_r000395_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_318_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_318_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = (((stage_v_182_1 << 2) ^ (sec_r000395_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_319_2 = (((stage_v_182_2 << 2) ^ (sec_r000395_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_319_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_319_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = (((stage_v_19_1 << 2) ^ (sec_r000395_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_320_2 = (((stage_v_19_2 << 2) ^ (sec_r000395_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_320_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_320_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = (((stage_v_188_1 << 1) ^ (sec_r000395_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_321_2 = (((stage_v_188_2 << 1) ^ (sec_r000395_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_321_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_321_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  int stage_v_322_1 = (((stage_v_209_1 << 1) ^ (sec_r000395_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_322_2 = (((stage_v_209_2 << 1) ^ (sec_r000395_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_322_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_322_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_322_1 & 63;
  out_sink_2 ^= stage_v_322_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000395_19_1 != sec_r000395_19_2);
  __CPROVER_assume(sec_r000395_4_1 != sec_r000395_4_2);
  __CPROVER_assume(sec_r000395_13_1 != sec_r000395_13_2);
  __CPROVER_assume(sec_r000395_1_1 != sec_r000395_1_2);
  __CPROVER_assume(sec_r000395_10_1 != sec_r000395_10_2);
  __CPROVER_assume(sec_r000395_12_1 != sec_r000395_12_2);
  __CPROVER_assume(pub_r000395_0_1 == pub_r000395_0_2);
  __CPROVER_assume(pub_r000395_5_1 == pub_r000395_5_2);
  __CPROVER_assume(pub_r000395_20_1 == pub_r000395_20_2);
  __CPROVER_assume(sec_r000395_3_1 != sec_r000395_3_2);
  __CPROVER_assume(sec_r000395_8_1 != sec_r000395_8_2);
  __CPROVER_assume(sec_r000395_7_1 != sec_r000395_7_2);
  __CPROVER_assume(sec_r000395_15_1 != sec_r000395_15_2);
  __CPROVER_assume(pub_r000395_9_1 == pub_r000395_9_2);
  __CPROVER_assume(sec_r000395_17_1 != sec_r000395_17_2);
  __CPROVER_assume(sec_r000395_6_1 != sec_r000395_6_2);
  __CPROVER_assume(pub_r000395_3_1 == pub_r000395_3_2);
  __CPROVER_assume(sec_r000395_16_1 != sec_r000395_16_2);
  __CPROVER_assume(pub_r000395_14_1 == pub_r000395_14_2);
  __CPROVER_assume(sec_r000395_2_1 != sec_r000395_2_2);
  __CPROVER_assume(pub_r000395_19_1 == pub_r000395_19_2);
  __CPROVER_assume(pub_r000395_10_1 == pub_r000395_10_2);
  __CPROVER_assume(pub_r000395_15_1 == pub_r000395_15_2);
  __CPROVER_assume(pub_r000395_2_1 == pub_r000395_2_2);
  __CPROVER_assume(pub_r000395_1_1 == pub_r000395_1_2);
  __CPROVER_assume(pub_r000395_7_1 == pub_r000395_7_2);
  __CPROVER_assume(pub_r000395_17_1 == pub_r000395_17_2);
  __CPROVER_assume(sec_r000395_0_1 != sec_r000395_0_2);
  __CPROVER_assume(pub_r000395_16_1 == pub_r000395_16_2);
  __CPROVER_assume(sec_r000395_5_1 != sec_r000395_5_2);
  __CPROVER_assume(pub_r000395_8_1 == pub_r000395_8_2);
  __CPROVER_assume(pub_r000395_18_1 == pub_r000395_18_2);
  __CPROVER_assume(pub_r000395_12_1 == pub_r000395_12_2);
  __CPROVER_assume(sec_r000395_11_1 != sec_r000395_11_2);
  __CPROVER_assume(sec_r000395_18_1 != sec_r000395_18_2);
  __CPROVER_assume(pub_r000395_13_1 == pub_r000395_13_2);
  __CPROVER_assume(pub_r000395_4_1 == pub_r000395_4_2);
  __CPROVER_assume(pub_r000395_11_1 == pub_r000395_11_2);
  __CPROVER_assume(pub_r000395_6_1 == pub_r000395_6_2);
  __CPROVER_assume(sec_r000395_9_1 != sec_r000395_9_2);
  __CPROVER_assume(sec_r000395_14_1 != sec_r000395_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.parity == st_var_2_2.parity);
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
}


