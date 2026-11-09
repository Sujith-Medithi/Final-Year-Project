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
struct SensorNode_R001524_2413_0
{
  unsigned char offset;
  int calib;
  int gain;
  unsigned char threshold;
  int status;
  int reading;
  int buffer[3];
};
struct Transaction_R001524_2413_1
{
  unsigned char account_id;
  int rate;
  short fee;
  int status;
  int balance;
  int buffer[3];
};
struct StreamBuffer_R001524_2413_2
{
  int capacity;
  int head;
  short state;
  unsigned char tail;
  int buffer[3];
};
union TelemetryField_R001524_2413_0
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
void fn_R001524_2413_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st_1 = {0};
  struct StreamBuffer_R001524_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_90_1)
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

  switch (quotient_90_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_90_1 == quotient_90_2);
}

int fn_R001524_2413_0(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_90 = (aux + st.buffer[1]) & 3;
  switch (quotient_90)
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

void fn_R001524_2413_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st_1 = {0};
  struct Transaction_R001524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int index_reg_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_56_1)
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

  switch (index_reg_56_2)
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

  int offset_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_37_1 > 30)
  {
    acc_1 = ((acc_1 + (offset_37_1 * 2)) + 5) & 127;
    aux_1 ^= offset_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_37_2 > 30)
  {
    acc_2 = ((acc_2 + (offset_37_2 * 2)) + 5) & 127;
    aux_2 ^= offset_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_80_1 = 0;
  int offset_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_80_1 = ((offset_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_80_2 = ((offset_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_80_1) & 127;
    acc_2 = (acc_2 + offset_80_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_23_1 = local_arr_1[aux_1 % 3];
  int pivot_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_23_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_56_1 == index_reg_56_2);
  assert(offset_37_1 == offset_37_2);
  assert(offset_80_1 == offset_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_23_1 == pivot_23_2);
}

int fn_R001524_2413_1(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int index_reg_56 = (aux + st.buffer[1]) & 3;
  switch (index_reg_56)
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

  int offset_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_37 > 30)
  {
    acc = ((acc + (offset_37 * 2)) + 5) & 127;
    aux ^= offset_37 & 15;
  }
  else
  {
    acc = ((acc - offset_37) + 11) & 127;
    aux += 3;
  }
  int offset_80 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_80 = ((offset_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_80) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_23 = local_arr[aux % 3];
  acc = (acc + (pivot_23 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001524_2413_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st_1 = {0};
  struct StreamBuffer_R001524_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int accumulator_69_1 = 0;
  int accumulator_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_69_1 = ((accumulator_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_69_2 = ((accumulator_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_69_1) & 127;
    acc_2 = (acc_2 + accumulator_69_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_45_1 = local_arr_1[aux_1 % 3];
  int coefficient_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_45_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_42_1)
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

  switch (cursor_42_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_69_1 == accumulator_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_45_1 == coefficient_45_2);
  assert(cursor_42_1 == cursor_42_2);
}

int fn_R001524_2413_2(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int accumulator_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_69 = ((accumulator_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_69) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int coefficient_45 = local_arr[aux % 3];
  acc = (acc + (coefficient_45 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_42 = (aux + st.buffer[1]) & 3;
  switch (cursor_42)
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

void fn_R001524_2413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st_1 = {0};
  struct Transaction_R001524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_54_1 = local_arr_1[aux_1 % 3];
  int tally_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_54_2 * 2)) & 127;
  int metric_80_1 = 0;
  int metric_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_80_1 = ((metric_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_80_2 = ((metric_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_80_1) & 127;
    acc_2 = (acc_2 + metric_80_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_54_1 == tally_54_2);
  assert(metric_80_1 == metric_80_2);
}

int fn_R001524_2413_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int tally_54 = local_arr[aux % 3];
  acc = (acc + (tally_54 * 2)) & 127;
  int metric_80 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_80 = ((metric_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_80) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001524_2413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st_1 = {0};
  struct Transaction_R001524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int delta_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_42_1) & 63;
  aux_2 = (aux_2 + delta_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_88_1 = local_arr_1[aux_1 % 3];
  int residue_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_88_2 * 2)) & 127;
  int damping_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_34_1 > 31)
  {
    acc_1 = ((acc_1 + (damping_34_1 * 2)) + 5) & 127;
    aux_1 ^= damping_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_34_2 > 31)
  {
    acc_2 = ((acc_2 + (damping_34_2 * 2)) + 5) & 127;
    aux_2 ^= damping_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_34_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_42_1 == delta_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_88_1 == residue_88_2);
  assert(damping_34_1 == damping_34_2);
}

int fn_R001524_2413_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int delta_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_42) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_88 = local_arr[aux % 3];
  acc = (acc + (residue_88 * 2)) & 127;
  int damping_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_34 > 31)
  {
    acc = ((acc + (damping_34 * 2)) + 5) & 127;
    aux ^= damping_34 & 15;
  }
  else
  {
    acc = ((acc - damping_34) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001524_2413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st_1 = {0};
  struct Transaction_R001524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_26_1 = local_arr_1[aux_1 % 3];
  int segment_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_26_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_26_1 == segment_26_2);
}

int fn_R001524_2413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_26 = local_arr[aux % 3];
  acc = (acc + (segment_26 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001524_2413_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st_1 = {0};
  struct SensorNode_R001524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int factor_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_66_1)
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

  switch (factor_66_2)
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

  int quotient_11_1 = 0;
  int quotient_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_11_1 = ((quotient_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_11_2 = ((quotient_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_11_1) & 127;
    acc_2 = (acc_2 + quotient_11_2) & 127;
  }

  int tally_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_49_1) & 63;
  aux_2 = (aux_2 + tally_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_71_1 = local_arr_1[aux_1 % 3];
  int stride_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_66_1 == factor_66_2);
  assert(quotient_11_1 == quotient_11_2);
  assert(tally_49_1 == tally_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_71_1 == stride_71_2);
}

int fn_R001524_2413_6(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int factor_66 = (aux + st.buffer[1]) & 3;
  switch (factor_66)
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

  int quotient_11 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_11 = ((quotient_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_11) & 127;
  }

  int tally_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_49) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_71 = local_arr[aux % 3];
  acc = (acc + (stride_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001524_2413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st_1 = {0};
  struct Transaction_R001524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int damping_86_1 = 0;
  int damping_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_86_1 = ((damping_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_86_2 = ((damping_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_86_1) & 127;
    acc_2 = (acc_2 + damping_86_2) & 127;
  }

  int margin_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_73_1) & 63;
  aux_2 = (aux_2 + margin_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_62_1 = local_arr_1[aux_1 % 3];
  int accumulator_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_62_2 * 2)) & 127;
  int margin_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_58_1 > 38)
  {
    acc_1 = ((acc_1 + (margin_58_1 * 2)) + 5) & 127;
    aux_1 ^= margin_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_58_2 > 38)
  {
    acc_2 = ((acc_2 + (margin_58_2 * 2)) + 5) & 127;
    aux_2 ^= margin_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_86_1 == damping_86_2);
  assert(margin_73_1 == margin_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_62_1 == accumulator_62_2);
  assert(margin_58_1 == margin_58_2);
}

int fn_R001524_2413_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int damping_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_86 = ((damping_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_86) & 127;
  }

  int margin_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_73) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_62 = local_arr[aux % 3];
  acc = (acc + (accumulator_62 * 2)) & 127;
  int margin_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_58 > 38)
  {
    acc = ((acc + (margin_58 * 2)) + 5) & 127;
    aux ^= margin_58 & 15;
  }
  else
  {
    acc = ((acc - margin_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001524_2413_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st_1 = {0};
  struct StreamBuffer_R001524_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_25_1)
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

  switch (quantum_25_2)
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

  int bound_64_1 = 0;
  int bound_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_64_1 = ((bound_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_64_2 = ((bound_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_64_1) & 127;
    acc_2 = (acc_2 + bound_64_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_25_1 == quantum_25_2);
  assert(bound_64_1 == bound_64_2);
}

int fn_R001524_2413_8(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_25 = (aux + st.buffer[1]) & 3;
  switch (quantum_25)
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

  int bound_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_64 = ((bound_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_64) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001524_2413_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st_1 = {0};
  struct SensorNode_R001524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int tracker_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_68_1)
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

  switch (tracker_68_2)
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

  int quantum_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_67_1 > 29)
  {
    acc_1 = ((acc_1 + (quantum_67_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_67_2 > 29)
  {
    acc_2 = ((acc_2 + (quantum_67_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_68_1 == tracker_68_2);
  assert(quantum_67_1 == quantum_67_2);
}

int fn_R001524_2413_9(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int tracker_68 = (aux + st.buffer[1]) & 3;
  switch (tracker_68)
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

  int quantum_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_67 > 29)
  {
    acc = ((acc + (quantum_67 * 2)) + 5) & 127;
    aux ^= quantum_67 & 15;
  }
  else
  {
    acc = ((acc - quantum_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001524_2413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st_1 = {0};
  struct Transaction_R001524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_61_1 > 36)
  {
    acc_1 = ((acc_1 + (checksum_61_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_61_2 > 36)
  {
    acc_2 = ((acc_2 + (checksum_61_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_30_1)
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

  switch (accumulator_30_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_61_1 == checksum_61_2);
  assert(accumulator_30_1 == accumulator_30_2);
}

int fn_R001524_2413_10(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_61 > 36)
  {
    acc = ((acc + (checksum_61 * 2)) + 5) & 127;
    aux ^= checksum_61 & 15;
  }
  else
  {
    acc = ((acc - checksum_61) + 11) & 127;
    aux += 3;
  }
  int accumulator_30 = (aux + st.buffer[1]) & 3;
  switch (accumulator_30)
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

void fn_R001524_2413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st_1 = {0};
  struct SensorNode_R001524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int tally_46_1 = 0;
  int tally_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_46_1 = ((tally_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_46_2 = ((tally_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_46_1) & 127;
    acc_2 = (acc_2 + tally_46_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_50_1 = local_arr_1[aux_1 % 3];
  int factor_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_50_2 * 2)) & 127;
  int quantum_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_69_1 > 24)
  {
    acc_1 = ((acc_1 + (quantum_69_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_69_2 > 24)
  {
    acc_2 = ((acc_2 + (quantum_69_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_46_1 == tally_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_50_1 == factor_50_2);
  assert(quantum_69_1 == quantum_69_2);
}

int fn_R001524_2413_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int tally_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_46 = ((tally_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_46) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int factor_50 = local_arr[aux % 3];
  acc = (acc + (factor_50 * 2)) & 127;
  int quantum_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_69 > 24)
  {
    acc = ((acc + (quantum_69 * 2)) + 5) & 127;
    aux ^= quantum_69 & 15;
  }
  else
  {
    acc = ((acc - quantum_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001524_2413_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st_1 = {0};
  struct Transaction_R001524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int scale_57_1 = 0;
  int scale_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_57_1 = ((scale_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_57_2 = ((scale_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_57_1) & 127;
    acc_2 = (acc_2 + scale_57_2) & 127;
  }

  int tally_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_30_1 > 21)
  {
    acc_1 = ((acc_1 + (tally_30_1 * 2)) + 5) & 127;
    aux_1 ^= tally_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_30_2 > 21)
  {
    acc_2 = ((acc_2 + (tally_30_2 * 2)) + 5) & 127;
    aux_2 ^= tally_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_30_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_57_1 == scale_57_2);
  assert(tally_30_1 == tally_30_2);
}

int fn_R001524_2413_12(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int scale_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_57 = ((scale_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_57) & 127;
  }

  int tally_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_30 > 21)
  {
    acc = ((acc + (tally_30 * 2)) + 5) & 127;
    aux ^= tally_30 & 15;
  }
  else
  {
    acc = ((acc - tally_30) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001524_2413_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st_1 = {0};
  struct SensorNode_R001524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int sample_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_94_1 > 33)
  {
    acc_1 = ((acc_1 + (sample_94_1 * 2)) + 5) & 127;
    aux_1 ^= sample_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_94_2 > 33)
  {
    acc_2 = ((acc_2 + (sample_94_2 * 2)) + 5) & 127;
    aux_2 ^= sample_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_71_1 = 0;
  int stride_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_71_1 = ((stride_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_71_2 = ((stride_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_71_1) & 127;
    acc_2 = (acc_2 + stride_71_2) & 127;
  }

  int bound_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_44_1)
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

  switch (bound_44_2)
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

  int parity_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_15_1) & 63;
  aux_2 = (aux_2 + parity_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_94_1 == sample_94_2);
  assert(stride_71_1 == stride_71_2);
  assert(bound_44_1 == bound_44_2);
  assert(parity_15_1 == parity_15_2);
}

int fn_R001524_2413_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int sample_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_94 > 33)
  {
    acc = ((acc + (sample_94 * 2)) + 5) & 127;
    aux ^= sample_94 & 15;
  }
  else
  {
    acc = ((acc - sample_94) + 11) & 127;
    aux += 3;
  }
  int stride_71 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_71 = ((stride_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_71) & 127;
  }

  int bound_44 = (aux + st.buffer[1]) & 3;
  switch (bound_44)
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

  int parity_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001524_2413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st_1 = {0};
  struct SensorNode_R001524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int bound_82_1 = 0;
  int bound_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_82_1 = ((bound_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_82_2 = ((bound_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_82_1) & 127;
    acc_2 = (acc_2 + bound_82_2) & 127;
  }

  int pivot_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_53_1)
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

  switch (pivot_53_2)
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
  int residue_36_1 = local_arr_1[aux_1 % 3];
  int residue_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_82_1 == bound_82_2);
  assert(pivot_53_1 == pivot_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_36_1 == residue_36_2);
}

int fn_R001524_2413_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int bound_82 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_82 = ((bound_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_82) & 127;
  }

  int pivot_53 = (aux + st.buffer[1]) & 3;
  switch (pivot_53)
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
  int residue_36 = local_arr[aux % 3];
  acc = (acc + (residue_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001524_2413_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st_1 = {0};
  struct Transaction_R001524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_57_1 = local_arr_1[aux_1 % 3];
  int index_reg_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_57_2 * 2)) & 127;
  int bound_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_88_1)
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

  switch (bound_88_2)
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

  int bound_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_59_1 > 10)
  {
    acc_1 = ((acc_1 + (bound_59_1 * 2)) + 5) & 127;
    aux_1 ^= bound_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_59_2 > 10)
  {
    acc_2 = ((acc_2 + (bound_59_2 * 2)) + 5) & 127;
    aux_2 ^= bound_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_59_2) + 11) & 127;
    aux_2 += 3;
  }
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_57_1 == index_reg_57_2);
  assert(bound_88_1 == bound_88_2);
  assert(bound_59_1 == bound_59_2);
  assert(margin_64_1 == margin_64_2);
}

int fn_R001524_2413_15(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int index_reg_57 = local_arr[aux % 3];
  acc = (acc + (index_reg_57 * 2)) & 127;
  int bound_88 = (aux + st.buffer[1]) & 3;
  switch (bound_88)
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

  int bound_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_59 > 10)
  {
    acc = ((acc + (bound_59 * 2)) + 5) & 127;
    aux ^= bound_59 & 15;
  }
  else
  {
    acc = ((acc - bound_59) + 11) & 127;
    aux += 3;
  }
  int margin_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_64 = ((margin_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_64) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001524_2413_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st_1 = {0};
  struct StreamBuffer_R001524_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int accumulator_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_19_1 > 40)
  {
    acc_1 = ((acc_1 + (accumulator_19_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_19_2 > 40)
  {
    acc_2 = ((acc_2 + (accumulator_19_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_39_1) & 63;
  aux_2 = (aux_2 + mask_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_59_1 = local_arr_1[aux_1 % 3];
  int segment_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_19_1 == accumulator_19_2);
  assert(mask_39_1 == mask_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_59_1 == segment_59_2);
}

int fn_R001524_2413_16(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int accumulator_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_19 > 40)
  {
    acc = ((acc + (accumulator_19 * 2)) + 5) & 127;
    aux ^= accumulator_19 & 15;
  }
  else
  {
    acc = ((acc - accumulator_19) + 11) & 127;
    aux += 3;
  }
  int mask_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_39) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_59 = local_arr[aux % 3];
  acc = (acc + (segment_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001524_2413_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st_1 = {0};
  struct Transaction_R001524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int quotient_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_59_1)
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

  switch (quotient_59_2)
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
  int margin_57_1 = local_arr_1[aux_1 % 3];
  int margin_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_57_2 * 2)) & 127;
  int window_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_36_1) & 63;
  aux_2 = (aux_2 + window_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_18_1 = 0;
  int phase_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_18_1 = ((phase_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_18_2 = ((phase_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_18_1) & 127;
    acc_2 = (acc_2 + phase_18_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_59_1 == quotient_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_57_1 == margin_57_2);
  assert(window_36_1 == window_36_2);
  assert(phase_18_1 == phase_18_2);
}

int fn_R001524_2413_17(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int quotient_59 = (aux + st.buffer[1]) & 3;
  switch (quotient_59)
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
  int margin_57 = local_arr[aux % 3];
  acc = (acc + (margin_57 * 2)) & 127;
  int window_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_36) & 63;
  acc ^= aux;
  int phase_18 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_18 = ((phase_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_18) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001524_2413_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st_1 = {0};
  struct Transaction_R001524_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int metric_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_31_1 > 19)
  {
    acc_1 = ((acc_1 + (metric_31_1 * 2)) + 5) & 127;
    aux_1 ^= metric_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_31_2 > 19)
  {
    acc_2 = ((acc_2 + (metric_31_2 * 2)) + 5) & 127;
    aux_2 ^= metric_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_31_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_31_1 == metric_31_2);
}

int fn_R001524_2413_18(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001524_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int metric_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_31 > 19)
  {
    acc = ((acc + (metric_31 * 2)) + 5) & 127;
    aux ^= metric_31 & 15;
  }
  else
  {
    acc = ((acc - metric_31) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001524_2413_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st_1 = {0};
  struct SensorNode_R001524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int window_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_35_1)
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

  switch (window_35_2)
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
  int coefficient_70_1 = local_arr_1[aux_1 % 3];
  int coefficient_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_35_1 == window_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_70_1 == coefficient_70_2);
}

int fn_R001524_2413_19(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int window_35 = (aux + st.buffer[1]) & 3;
  switch (window_35)
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
  int coefficient_70 = local_arr[aux % 3];
  acc = (acc + (coefficient_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001524_2413_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st_1 = {0};
  struct StreamBuffer_R001524_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_10_1 = local_arr_1[aux_1 % 3];
  int residue_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_10_2 * 2)) & 127;
  int quantum_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_52_1)
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

  switch (quantum_52_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_10_1 == residue_10_2);
  assert(quantum_52_1 == quantum_52_2);
}

int fn_R001524_2413_20(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int residue_10 = local_arr[aux % 3];
  acc = (acc + (residue_10 * 2)) & 127;
  int quantum_52 = (aux + st.buffer[1]) & 3;
  switch (quantum_52)
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

  return (acc + aux) & 255;
}

void fn_R001524_2413_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st_1 = {0};
  struct StreamBuffer_R001524_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tally_93_1 = 0;
  int tally_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_93_1 = ((tally_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_93_2 = ((tally_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_93_1) & 127;
    acc_2 = (acc_2 + tally_93_2) & 127;
  }

  int residue_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_42_1 > 42)
  {
    acc_1 = ((acc_1 + (residue_42_1 * 2)) + 5) & 127;
    aux_1 ^= residue_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_42_2 > 42)
  {
    acc_2 = ((acc_2 + (residue_42_2 * 2)) + 5) & 127;
    aux_2 ^= residue_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_42_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_93_1 == tally_93_2);
  assert(residue_42_1 == residue_42_2);
}

int fn_R001524_2413_21(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tally_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_93 = ((tally_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_93) & 127;
  }

  int residue_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_42 > 42)
  {
    acc = ((acc + (residue_42 * 2)) + 5) & 127;
    aux ^= residue_42 & 15;
  }
  else
  {
    acc = ((acc - residue_42) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001524_2413_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st_1 = {0};
  struct SensorNode_R001524_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_25_1 = local_arr_1[aux_1 % 3];
  int pivot_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_25_2 * 2)) & 127;
  int quantum_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_58_1 > 12)
  {
    acc_1 = ((acc_1 + (quantum_58_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_58_2 > 12)
  {
    acc_2 = ((acc_2 + (quantum_58_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_58_1 = 0;
  int tracker_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_58_1 = ((tracker_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_58_2 = ((tracker_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_58_1) & 127;
    acc_2 = (acc_2 + tracker_58_2) & 127;
  }

  int mask_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_23_1)
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

  switch (mask_23_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_25_1 == pivot_25_2);
  assert(quantum_58_1 == quantum_58_2);
  assert(tracker_58_1 == tracker_58_2);
  assert(mask_23_1 == mask_23_2);
}

int fn_R001524_2413_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001524_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int pivot_25 = local_arr[aux % 3];
  acc = (acc + (pivot_25 * 2)) & 127;
  int quantum_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_58 > 12)
  {
    acc = ((acc + (quantum_58 * 2)) + 5) & 127;
    aux ^= quantum_58 & 15;
  }
  else
  {
    acc = ((acc - quantum_58) + 11) & 127;
    aux += 3;
  }
  int tracker_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_58 = ((tracker_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_58) & 127;
  }

  int mask_23 = (aux + st.buffer[1]) & 3;
  switch (mask_23)
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

void fn_R001524_2413_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st_1 = {0};
  struct StreamBuffer_R001524_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int accumulator_26_1 = 0;
  int accumulator_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_26_1 = ((accumulator_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_26_2 = ((accumulator_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_26_1) & 127;
    acc_2 = (acc_2 + accumulator_26_2) & 127;
  }

  int scale_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_84_1) & 63;
  aux_2 = (aux_2 + scale_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_26_1 == accumulator_26_2);
  assert(scale_84_1 == scale_84_2);
}

int fn_R001524_2413_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001524_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int accumulator_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_26 = ((accumulator_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_26) & 127;
  }

  int scale_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_84) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001524_0_1;
  int sec_r001524_0_2;
  int sec_r001524_1_1;
  int sec_r001524_1_2;
  int sec_r001524_2_1;
  int sec_r001524_2_2;
  int sec_r001524_3_1;
  int sec_r001524_3_2;
  int sec_r001524_4_1;
  int sec_r001524_4_2;
  int sec_r001524_5_1;
  int sec_r001524_5_2;
  int sec_r001524_6_1;
  int sec_r001524_6_2;
  int sec_r001524_7_1;
  int sec_r001524_7_2;
  int sec_r001524_8_1;
  int sec_r001524_8_2;
  int sec_r001524_9_1;
  int sec_r001524_9_2;
  int sec_r001524_10_1;
  int sec_r001524_10_2;
  int sec_r001524_11_1;
  int sec_r001524_11_2;
  int sec_r001524_12_1;
  int sec_r001524_12_2;
  int sec_r001524_13_1;
  int sec_r001524_13_2;
  int sec_r001524_14_1;
  int sec_r001524_14_2;
  int sec_r001524_15_1;
  int sec_r001524_15_2;
  int sec_r001524_16_1;
  int sec_r001524_16_2;
  int sec_r001524_17_1;
  int sec_r001524_17_2;
  int sec_r001524_18_1;
  int sec_r001524_18_2;
  int sec_r001524_19_1;
  int sec_r001524_19_2;
  int sec_r001524_20_1;
  int sec_r001524_20_2;
  int sec_r001524_21_1;
  int sec_r001524_21_2;
  int sec_r001524_22_1;
  int sec_r001524_22_2;
  int sec_r001524_23_1;
  int sec_r001524_23_2;
  int pub_r001524_0_1;
  int pub_r001524_0_2;
  int pub_r001524_1_1;
  int pub_r001524_1_2;
  int pub_r001524_2_1;
  int pub_r001524_2_2;
  int pub_r001524_3_1;
  int pub_r001524_3_2;
  int pub_r001524_4_1;
  int pub_r001524_4_2;
  int pub_r001524_5_1;
  int pub_r001524_5_2;
  int pub_r001524_6_1;
  int pub_r001524_6_2;
  int pub_r001524_7_1;
  int pub_r001524_7_2;
  int pub_r001524_8_1;
  int pub_r001524_8_2;
  int pub_r001524_9_1;
  int pub_r001524_9_2;
  int pub_r001524_10_1;
  int pub_r001524_10_2;
  int pub_r001524_11_1;
  int pub_r001524_11_2;
  int pub_r001524_12_1;
  int pub_r001524_12_2;
  int pub_r001524_13_1;
  int pub_r001524_13_2;
  int pub_r001524_14_1;
  int pub_r001524_14_2;
  int pub_r001524_15_1;
  int pub_r001524_15_2;
  int pub_r001524_16_1;
  int pub_r001524_16_2;
  int pub_r001524_17_1;
  int pub_r001524_17_2;
  int pub_r001524_18_1;
  int pub_r001524_18_2;
  int pub_r001524_19_1;
  int pub_r001524_19_2;
  int pub_r001524_20_1;
  int pub_r001524_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001524_0_1 >= (-100)) && (pub_r001524_0_1 <= 100));
  __CPROVER_assume((pub_r001524_0_2 >= (-100)) && (pub_r001524_0_2 <= 100));
  __CPROVER_assume((pub_r001524_1_1 >= (-100)) && (pub_r001524_1_1 <= 100));
  __CPROVER_assume((pub_r001524_1_2 >= (-100)) && (pub_r001524_1_2 <= 100));
  __CPROVER_assume((pub_r001524_2_1 >= (-100)) && (pub_r001524_2_1 <= 100));
  __CPROVER_assume((pub_r001524_2_2 >= (-100)) && (pub_r001524_2_2 <= 100));
  __CPROVER_assume((pub_r001524_3_1 >= (-100)) && (pub_r001524_3_1 <= 100));
  __CPROVER_assume((pub_r001524_3_2 >= (-100)) && (pub_r001524_3_2 <= 100));
  __CPROVER_assume((pub_r001524_4_1 >= (-100)) && (pub_r001524_4_1 <= 100));
  __CPROVER_assume((pub_r001524_4_2 >= (-100)) && (pub_r001524_4_2 <= 100));
  __CPROVER_assume((pub_r001524_5_1 >= (-100)) && (pub_r001524_5_1 <= 100));
  __CPROVER_assume((pub_r001524_5_2 >= (-100)) && (pub_r001524_5_2 <= 100));
  __CPROVER_assume((pub_r001524_6_1 >= (-100)) && (pub_r001524_6_1 <= 100));
  __CPROVER_assume((pub_r001524_6_2 >= (-100)) && (pub_r001524_6_2 <= 100));
  __CPROVER_assume((pub_r001524_7_1 >= (-100)) && (pub_r001524_7_1 <= 100));
  __CPROVER_assume((pub_r001524_7_2 >= (-100)) && (pub_r001524_7_2 <= 100));
  __CPROVER_assume((pub_r001524_8_1 >= (-100)) && (pub_r001524_8_1 <= 100));
  __CPROVER_assume((pub_r001524_8_2 >= (-100)) && (pub_r001524_8_2 <= 100));
  __CPROVER_assume((pub_r001524_9_1 >= (-100)) && (pub_r001524_9_1 <= 100));
  __CPROVER_assume((pub_r001524_9_2 >= (-100)) && (pub_r001524_9_2 <= 100));
  __CPROVER_assume((pub_r001524_10_1 >= (-100)) && (pub_r001524_10_1 <= 100));
  __CPROVER_assume((pub_r001524_10_2 >= (-100)) && (pub_r001524_10_2 <= 100));
  __CPROVER_assume((pub_r001524_11_1 >= (-100)) && (pub_r001524_11_1 <= 100));
  __CPROVER_assume((pub_r001524_11_2 >= (-100)) && (pub_r001524_11_2 <= 100));
  __CPROVER_assume((pub_r001524_12_1 >= (-100)) && (pub_r001524_12_1 <= 100));
  __CPROVER_assume((pub_r001524_12_2 >= (-100)) && (pub_r001524_12_2 <= 100));
  __CPROVER_assume((pub_r001524_13_1 >= (-100)) && (pub_r001524_13_1 <= 100));
  __CPROVER_assume((pub_r001524_13_2 >= (-100)) && (pub_r001524_13_2 <= 100));
  __CPROVER_assume((pub_r001524_14_1 >= (-100)) && (pub_r001524_14_1 <= 100));
  __CPROVER_assume((pub_r001524_14_2 >= (-100)) && (pub_r001524_14_2 <= 100));
  __CPROVER_assume((pub_r001524_15_1 >= (-100)) && (pub_r001524_15_1 <= 100));
  __CPROVER_assume((pub_r001524_15_2 >= (-100)) && (pub_r001524_15_2 <= 100));
  __CPROVER_assume((pub_r001524_16_1 >= (-100)) && (pub_r001524_16_1 <= 100));
  __CPROVER_assume((pub_r001524_16_2 >= (-100)) && (pub_r001524_16_2 <= 100));
  __CPROVER_assume((pub_r001524_17_1 >= (-100)) && (pub_r001524_17_1 <= 100));
  __CPROVER_assume((pub_r001524_17_2 >= (-100)) && (pub_r001524_17_2 <= 100));
  __CPROVER_assume((pub_r001524_18_1 >= (-100)) && (pub_r001524_18_1 <= 100));
  __CPROVER_assume((pub_r001524_18_2 >= (-100)) && (pub_r001524_18_2 <= 100));
  __CPROVER_assume((pub_r001524_19_1 >= (-100)) && (pub_r001524_19_1 <= 100));
  __CPROVER_assume((pub_r001524_19_2 >= (-100)) && (pub_r001524_19_2 <= 100));
  __CPROVER_assume((pub_r001524_20_1 >= (-100)) && (pub_r001524_20_1 <= 100));
  __CPROVER_assume((pub_r001524_20_2 >= (-100)) && (pub_r001524_20_2 <= 100));
  __CPROVER_assume((sec_r001524_0_1 >= 0) && (sec_r001524_0_1 <= 255));
  __CPROVER_assume((sec_r001524_0_2 >= 0) && (sec_r001524_0_2 <= 255));
  __CPROVER_assume((sec_r001524_1_1 >= 0) && (sec_r001524_1_1 <= 255));
  __CPROVER_assume((sec_r001524_1_2 >= 0) && (sec_r001524_1_2 <= 255));
  __CPROVER_assume((sec_r001524_2_1 >= 0) && (sec_r001524_2_1 <= 255));
  __CPROVER_assume((sec_r001524_2_2 >= 0) && (sec_r001524_2_2 <= 255));
  __CPROVER_assume((sec_r001524_3_1 >= 0) && (sec_r001524_3_1 <= 255));
  __CPROVER_assume((sec_r001524_3_2 >= 0) && (sec_r001524_3_2 <= 255));
  __CPROVER_assume((sec_r001524_4_1 >= 0) && (sec_r001524_4_1 <= 255));
  __CPROVER_assume((sec_r001524_4_2 >= 0) && (sec_r001524_4_2 <= 255));
  __CPROVER_assume((sec_r001524_5_1 >= 0) && (sec_r001524_5_1 <= 255));
  __CPROVER_assume((sec_r001524_5_2 >= 0) && (sec_r001524_5_2 <= 255));
  __CPROVER_assume((sec_r001524_6_1 >= 0) && (sec_r001524_6_1 <= 255));
  __CPROVER_assume((sec_r001524_6_2 >= 0) && (sec_r001524_6_2 <= 255));
  __CPROVER_assume((sec_r001524_7_1 >= 0) && (sec_r001524_7_1 <= 255));
  __CPROVER_assume((sec_r001524_7_2 >= 0) && (sec_r001524_7_2 <= 255));
  __CPROVER_assume((sec_r001524_8_1 >= 0) && (sec_r001524_8_1 <= 255));
  __CPROVER_assume((sec_r001524_8_2 >= 0) && (sec_r001524_8_2 <= 255));
  __CPROVER_assume((sec_r001524_9_1 >= 0) && (sec_r001524_9_1 <= 255));
  __CPROVER_assume((sec_r001524_9_2 >= 0) && (sec_r001524_9_2 <= 255));
  __CPROVER_assume((sec_r001524_10_1 >= 0) && (sec_r001524_10_1 <= 255));
  __CPROVER_assume((sec_r001524_10_2 >= 0) && (sec_r001524_10_2 <= 255));
  __CPROVER_assume((sec_r001524_11_1 >= 0) && (sec_r001524_11_1 <= 255));
  __CPROVER_assume((sec_r001524_11_2 >= 0) && (sec_r001524_11_2 <= 255));
  __CPROVER_assume((sec_r001524_12_1 >= 0) && (sec_r001524_12_1 <= 255));
  __CPROVER_assume((sec_r001524_12_2 >= 0) && (sec_r001524_12_2 <= 255));
  __CPROVER_assume((sec_r001524_13_1 >= 0) && (sec_r001524_13_1 <= 255));
  __CPROVER_assume((sec_r001524_13_2 >= 0) && (sec_r001524_13_2 <= 255));
  __CPROVER_assume((sec_r001524_14_1 >= 0) && (sec_r001524_14_1 <= 255));
  __CPROVER_assume((sec_r001524_14_2 >= 0) && (sec_r001524_14_2 <= 255));
  __CPROVER_assume((sec_r001524_15_1 >= 0) && (sec_r001524_15_1 <= 255));
  __CPROVER_assume((sec_r001524_15_2 >= 0) && (sec_r001524_15_2 <= 255));
  __CPROVER_assume((sec_r001524_16_1 >= 0) && (sec_r001524_16_1 <= 255));
  __CPROVER_assume((sec_r001524_16_2 >= 0) && (sec_r001524_16_2 <= 255));
  __CPROVER_assume((sec_r001524_17_1 >= 0) && (sec_r001524_17_1 <= 255));
  __CPROVER_assume((sec_r001524_17_2 >= 0) && (sec_r001524_17_2 <= 255));
  __CPROVER_assume((sec_r001524_18_1 >= 0) && (sec_r001524_18_1 <= 255));
  __CPROVER_assume((sec_r001524_18_2 >= 0) && (sec_r001524_18_2 <= 255));
  __CPROVER_assume((sec_r001524_19_1 >= 0) && (sec_r001524_19_1 <= 255));
  __CPROVER_assume((sec_r001524_19_2 >= 0) && (sec_r001524_19_2 <= 255));
  __CPROVER_assume((sec_r001524_20_1 >= 0) && (sec_r001524_20_1 <= 255));
  __CPROVER_assume((sec_r001524_20_2 >= 0) && (sec_r001524_20_2 <= 255));
  __CPROVER_assume((sec_r001524_21_1 >= 0) && (sec_r001524_21_1 <= 255));
  __CPROVER_assume((sec_r001524_21_2 >= 0) && (sec_r001524_21_2 <= 255));
  __CPROVER_assume((sec_r001524_22_1 >= 0) && (sec_r001524_22_1 <= 255));
  __CPROVER_assume((sec_r001524_22_2 >= 0) && (sec_r001524_22_2 <= 255));
  __CPROVER_assume((sec_r001524_23_1 >= 0) && (sec_r001524_23_1 <= 255));
  __CPROVER_assume((sec_r001524_23_2 >= 0) && (sec_r001524_23_2 <= 255));
  struct SensorNode_R001524_2413_0 st_var_0_1 = {0};
  struct SensorNode_R001524_2413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001524_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001524_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001524_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001524_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001524_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001524_0_2 + 7) & 15;
  struct Transaction_R001524_2413_1 st_var_1_1 = {0};
  struct Transaction_R001524_2413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001524_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001524_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001524_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001524_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001524_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001524_0_2 + 9) & 15;
  struct StreamBuffer_R001524_2413_2 st_var_2_1 = {0};
  struct StreamBuffer_R001524_2413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001524_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001524_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001524_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001524_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001524_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001524_0_2 + 11) & 15;
  union TelemetryField_R001524_2413_0 u_var_1;
  union TelemetryField_R001524_2413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001524_2413_0(sec_r001524_0_1, pub_r001524_1_1, pub_r001524_2_1);
  int helper_flow_0_2 = fn_R001524_2413_0(sec_r001524_0_2, pub_r001524_1_2, pub_r001524_2_2);
  fn_R001524_2413_0_2(sec_r001524_0_1, pub_r001524_1_1, pub_r001524_2_1, sec_r001524_0_2, pub_r001524_1_2, pub_r001524_2_2);
  int helper_flow_1_1 = fn_R001524_2413_1(sec_r001524_1_1, pub_r001524_2_1);
  int helper_flow_1_2 = fn_R001524_2413_1(sec_r001524_1_2, pub_r001524_2_2);
  fn_R001524_2413_1_2(sec_r001524_1_1, pub_r001524_2_1, sec_r001524_1_2, pub_r001524_2_2);
  int helper_flow_2_1 = fn_R001524_2413_2(sec_r001524_2_1, pub_r001524_3_1, pub_r001524_4_1);
  int helper_flow_2_2 = fn_R001524_2413_2(sec_r001524_2_2, pub_r001524_3_2, pub_r001524_4_2);
  fn_R001524_2413_2_2(sec_r001524_2_1, pub_r001524_3_1, pub_r001524_4_1, sec_r001524_2_2, pub_r001524_3_2, pub_r001524_4_2);
  int helper_flow_3_1 = fn_R001524_2413_3(sec_r001524_3_1, pub_r001524_4_1, pub_r001524_5_1, pub_r001524_6_1);
  int helper_flow_3_2 = fn_R001524_2413_3(sec_r001524_3_2, pub_r001524_4_2, pub_r001524_5_2, pub_r001524_6_2);
  fn_R001524_2413_3_2(sec_r001524_3_1, pub_r001524_4_1, pub_r001524_5_1, pub_r001524_6_1, sec_r001524_3_2, pub_r001524_4_2, pub_r001524_5_2, pub_r001524_6_2);
  int helper_flow_4_1 = fn_R001524_2413_4(sec_r001524_4_1, pub_r001524_5_1, pub_r001524_6_1, pub_r001524_7_1, pub_r001524_8_1);
  int helper_flow_4_2 = fn_R001524_2413_4(sec_r001524_4_2, pub_r001524_5_2, pub_r001524_6_2, pub_r001524_7_2, pub_r001524_8_2);
  fn_R001524_2413_4_2(sec_r001524_4_1, pub_r001524_5_1, pub_r001524_6_1, pub_r001524_7_1, pub_r001524_8_1, sec_r001524_4_2, pub_r001524_5_2, pub_r001524_6_2, pub_r001524_7_2, pub_r001524_8_2);
  int helper_flow_5_1 = fn_R001524_2413_5(sec_r001524_5_1, pub_r001524_6_1, pub_r001524_7_1, pub_r001524_8_1, pub_r001524_9_1);
  int helper_flow_5_2 = fn_R001524_2413_5(sec_r001524_5_2, pub_r001524_6_2, pub_r001524_7_2, pub_r001524_8_2, pub_r001524_9_2);
  fn_R001524_2413_5_2(sec_r001524_5_1, pub_r001524_6_1, pub_r001524_7_1, pub_r001524_8_1, pub_r001524_9_1, sec_r001524_5_2, pub_r001524_6_2, pub_r001524_7_2, pub_r001524_8_2, pub_r001524_9_2);
  int helper_flow_6_1 = fn_R001524_2413_6(sec_r001524_6_1, pub_r001524_7_1, pub_r001524_8_1);
  int helper_flow_6_2 = fn_R001524_2413_6(sec_r001524_6_2, pub_r001524_7_2, pub_r001524_8_2);
  fn_R001524_2413_6_2(sec_r001524_6_1, pub_r001524_7_1, pub_r001524_8_1, sec_r001524_6_2, pub_r001524_7_2, pub_r001524_8_2);
  int stage_v_0_1 = ((pub_r001524_11_1 * 2) + 21) & 63;
  int stage_v_0_2 = ((pub_r001524_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001524_14_1 * 2) + 29) & 63;
  int stage_v_1_2 = ((pub_r001524_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001524_18_1 * 3) + pub_r001524_12_1) + 39) & 127;
  int stage_v_2_2 = (((sec_r001524_18_2 * 3) + pub_r001524_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = (((sec_r001524_14_1 * 3) + pub_r001524_3_1) + 6) & 127;
  int stage_v_3_2 = (((sec_r001524_14_2 * 3) + pub_r001524_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((sec_r001524_8_1 * 3) + pub_r001524_3_1) + 15) & 127;
  int stage_v_4_2 = (((sec_r001524_8_2 * 3) + pub_r001524_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = (((helper_flow_4_1 * 3) + pub_r001524_5_1) + 6) & 127;
  int stage_v_5_2 = (((helper_flow_4_2 * 3) + pub_r001524_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((sec_r001524_2_1 * 3) + pub_r001524_11_1) + 38) & 127;
  int stage_v_6_2 = (((sec_r001524_2_2 * 3) + pub_r001524_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = (((stage_v_4_1 * 3) + pub_r001524_4_1) + 6) & 127;
  int stage_v_7_2 = (((stage_v_4_2 * 3) + pub_r001524_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001524_20_1 * 2) + 11) & 63;
  int stage_v_8_2 = ((pub_r001524_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (((stage_v_5_1 * 3) + pub_r001524_11_1) + 25) & 127;
  int stage_v_9_2 = (((stage_v_5_2 * 3) + pub_r001524_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = ((pub_r001524_13_1 * 2) + 45) & 63;
  int stage_v_10_2 = ((pub_r001524_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001524_15_1 * 2) + 18) & 63;
  int stage_v_11_2 = ((pub_r001524_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((stage_v_6_1 * 3) + pub_r001524_17_1) + 39) & 127;
  int stage_v_12_2 = (((stage_v_6_2 * 3) + pub_r001524_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((stage_v_6_1 * 3) + pub_r001524_9_1) + 26) & 127;
  int stage_v_13_2 = (((stage_v_6_2 * 3) + pub_r001524_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((sec_r001524_23_1 * 3) + pub_r001524_8_1) + 26) & 127;
  int stage_v_14_2 = (((sec_r001524_23_2 * 3) + pub_r001524_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((helper_flow_5_1 * 3) + pub_r001524_20_1) + 23) & 127;
  int stage_v_15_2 = (((helper_flow_5_2 * 3) + pub_r001524_20_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001524_0_1 * 2) + 9) & 63;
  int stage_v_16_2 = ((pub_r001524_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((stage_v_15_1 * 3) + pub_r001524_1_1) + 10) & 127;
  int stage_v_17_2 = (((stage_v_15_2 * 3) + pub_r001524_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001524_5_1 * 2) + 50) & 63;
  int stage_v_18_2 = ((pub_r001524_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001524_7_1 * 2) + 48) & 63;
  int stage_v_19_2 = ((pub_r001524_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((sec_r001524_13_1 * 3) + pub_r001524_3_1) + 8) & 127;
  int stage_v_20_2 = (((sec_r001524_13_2 * 3) + pub_r001524_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001524_17_1 * 2) + 24) & 63;
  int stage_v_21_2 = ((pub_r001524_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((sec_r001524_21_1 * 3) + pub_r001524_20_1) + 31) & 127;
  int stage_v_22_2 = (((sec_r001524_21_2 * 3) + pub_r001524_20_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = (((stage_v_7_1 * 3) + pub_r001524_20_1) + 32) & 127;
  int stage_v_23_2 = (((stage_v_7_2 * 3) + pub_r001524_20_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = ((pub_r001524_18_1 * 2) + 35) & 63;
  int stage_v_24_2 = ((pub_r001524_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001524_6_1 * 2) + 5) & 63;
  int stage_v_25_2 = ((pub_r001524_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001524_1_1 * 2) + 40) & 63;
  int stage_v_26_2 = ((pub_r001524_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (((stage_v_13_1 * 3) + pub_r001524_14_1) + 41) & 127;
  int stage_v_27_2 = (((stage_v_13_2 * 3) + pub_r001524_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = ((pub_r001524_5_1 * 2) + 20) & 63;
  int stage_v_28_2 = ((pub_r001524_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001524_14_1 * 2) + 46) & 63;
  int stage_v_29_2 = ((pub_r001524_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001524_6_1 * 3) + pub_r001524_1_1) + 10) & 127;
  int stage_v_30_2 = (((sec_r001524_6_2 * 3) + pub_r001524_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((stage_v_9_1 * 3) + pub_r001524_16_1) + 12) & 127;
  int stage_v_31_2 = (((stage_v_9_2 * 3) + pub_r001524_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((helper_flow_4_1 * 3) + pub_r001524_2_1) + 28) & 127;
  int stage_v_32_2 = (((helper_flow_4_2 * 3) + pub_r001524_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = ((pub_r001524_16_1 * 2) + 50) & 63;
  int stage_v_33_2 = ((pub_r001524_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((stage_v_22_1 * 3) + pub_r001524_4_1) + 38) & 127;
  int stage_v_34_2 = (((stage_v_22_2 * 3) + pub_r001524_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = (((helper_flow_5_1 * 3) + pub_r001524_4_1) + 44) & 127;
  int stage_v_35_2 = (((helper_flow_5_2 * 3) + pub_r001524_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = (((stage_v_3_1 * 3) + pub_r001524_15_1) + 22) & 127;
  int stage_v_36_2 = (((stage_v_3_2 * 3) + pub_r001524_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = (((stage_v_6_1 * 3) + pub_r001524_14_1) + 30) & 127;
  int stage_v_37_2 = (((stage_v_6_2 * 3) + pub_r001524_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = (((stage_v_7_1 * 3) + pub_r001524_20_1) + 39) & 127;
  int stage_v_38_2 = (((stage_v_7_2 * 3) + pub_r001524_20_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((stage_v_38_1 * 3) + pub_r001524_5_1) + 33) & 127;
  int stage_v_39_2 = (((stage_v_38_2 * 3) + pub_r001524_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = ((pub_r001524_0_1 * 2) + 27) & 63;
  int stage_v_40_2 = ((pub_r001524_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001524_18_1 * 2) + 28) & 63;
  int stage_v_41_2 = ((pub_r001524_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001524_12_1 * 2) + 40) & 63;
  int stage_v_42_2 = ((pub_r001524_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((sec_r001524_18_1 * 3) + pub_r001524_3_1) + 9) & 127;
  int stage_v_43_2 = (((sec_r001524_18_2 * 3) + pub_r001524_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001524_15_1 * 2) + 48) & 63;
  int stage_v_44_2 = ((pub_r001524_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((stage_v_43_1 * 3) + pub_r001524_5_1) + 15) & 127;
  int stage_v_45_2 = (((stage_v_43_2 * 3) + pub_r001524_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = ((pub_r001524_7_1 * 2) + 10) & 63;
  int stage_v_46_2 = ((pub_r001524_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((helper_flow_2_1 * 3) + pub_r001524_8_1) + 38) & 127;
  int stage_v_47_2 = (((helper_flow_2_2 * 3) + pub_r001524_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((sec_r001524_4_1 * 3) + pub_r001524_8_1) + 34) & 127;
  int stage_v_48_2 = (((sec_r001524_4_2 * 3) + pub_r001524_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = ((pub_r001524_20_1 * 2) + 41) & 63;
  int stage_v_49_2 = ((pub_r001524_20_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((stage_v_38_1 * 3) + pub_r001524_15_1) + 5) & 127;
  int stage_v_50_2 = (((stage_v_38_2 * 3) + pub_r001524_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = (((stage_v_7_1 * 3) + pub_r001524_16_1) + 45) & 127;
  int stage_v_51_2 = (((stage_v_7_2 * 3) + pub_r001524_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = ((pub_r001524_4_1 * 2) + 27) & 63;
  int stage_v_52_2 = ((pub_r001524_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001524_3_1 * 2) + 11) & 63;
  int stage_v_53_2 = ((pub_r001524_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((sec_r001524_14_1 * 3) + pub_r001524_7_1) + 30) & 127;
  int stage_v_54_2 = (((sec_r001524_14_2 * 3) + pub_r001524_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((sec_r001524_0_1 * 3) + pub_r001524_4_1) + 32) & 127;
  int stage_v_55_2 = (((sec_r001524_0_2 * 3) + pub_r001524_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001524_14_1 * 2) + 7) & 63;
  int stage_v_56_2 = ((pub_r001524_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001524_1_1 * 2) + 40) & 63;
  int stage_v_57_2 = ((pub_r001524_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001524_7_1 * 2) + 24) & 63;
  int stage_v_58_2 = ((pub_r001524_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((stage_v_27_1 * 3) + pub_r001524_16_1) + 43) & 127;
  int stage_v_59_2 = (((stage_v_27_2 * 3) + pub_r001524_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001524_6_1 * 2) + 5) & 63;
  int stage_v_60_2 = ((pub_r001524_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001524_5_1 * 2) + 42) & 63;
  int stage_v_61_2 = ((pub_r001524_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((stage_v_5_1 * 3) + pub_r001524_5_1) + 38) & 127;
  int stage_v_62_2 = (((stage_v_5_2 * 3) + pub_r001524_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((sec_r001524_4_1 * 3) + pub_r001524_9_1) + 26) & 127;
  int stage_v_63_2 = (((sec_r001524_4_2 * 3) + pub_r001524_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((sec_r001524_22_1 * 3) + pub_r001524_16_1) + 14) & 127;
  int stage_v_64_2 = (((sec_r001524_22_2 * 3) + pub_r001524_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((sec_r001524_5_1 * 3) + pub_r001524_15_1) + 15) & 127;
  int stage_v_65_2 = (((sec_r001524_5_2 * 3) + pub_r001524_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = (((sec_r001524_18_1 * 3) + pub_r001524_12_1) + 42) & 127;
  int stage_v_66_2 = (((sec_r001524_18_2 * 3) + pub_r001524_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = ((pub_r001524_0_1 * 2) + 38) & 63;
  int stage_v_67_2 = ((pub_r001524_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001524_18_1 * 2) + 6) & 63;
  int stage_v_68_2 = ((pub_r001524_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001524_0_1 * 2) + 9) & 63;
  int stage_v_69_2 = ((pub_r001524_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001524_2_1 * 2) + 41) & 63;
  int stage_v_70_2 = ((pub_r001524_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((stage_v_50_1 * 3) + pub_r001524_20_1) + 30) & 127;
  int stage_v_71_2 = (((stage_v_50_2 * 3) + pub_r001524_20_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = (((stage_v_55_1 * 3) + pub_r001524_12_1) + 14) & 127;
  int stage_v_72_2 = (((stage_v_55_2 * 3) + pub_r001524_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = (((sec_r001524_1_1 * 3) + pub_r001524_4_1) + 4) & 127;
  int stage_v_73_2 = (((sec_r001524_1_2 * 3) + pub_r001524_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((stage_v_39_1 * 3) + pub_r001524_18_1) + 4) & 127;
  int stage_v_74_2 = (((stage_v_39_2 * 3) + pub_r001524_18_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = ((pub_r001524_7_1 * 2) + 8) & 63;
  int stage_v_75_2 = ((pub_r001524_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (((helper_flow_0_1 * 3) + pub_r001524_16_1) + 43) & 127;
  int stage_v_76_2 = (((helper_flow_0_2 * 3) + pub_r001524_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001524_4_1 * 2) + 26) & 63;
  int stage_v_77_2 = ((pub_r001524_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001524_18_1 * 2) + 7) & 63;
  int stage_v_78_2 = ((pub_r001524_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001524_9_1 * 2) + 38) & 63;
  int stage_v_79_2 = ((pub_r001524_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((stage_v_5_1 * 3) + pub_r001524_20_1) + 30) & 127;
  int stage_v_80_2 = (((stage_v_5_2 * 3) + pub_r001524_20_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = (((stage_v_3_1 * 3) + pub_r001524_14_1) + 45) & 127;
  int stage_v_81_2 = (((stage_v_3_2 * 3) + pub_r001524_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = ((pub_r001524_20_1 * 2) + 31) & 63;
  int stage_v_82_2 = ((pub_r001524_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((helper_flow_1_1 * 3) + pub_r001524_1_1) + 21) & 127;
  int stage_v_83_2 = (((helper_flow_1_2 * 3) + pub_r001524_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((stage_v_83_1 * 3) + pub_r001524_18_1) + 23) & 127;
  int stage_v_84_2 = (((stage_v_83_2 * 3) + pub_r001524_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((sec_r001524_7_1 * 3) + pub_r001524_17_1) + 26) & 127;
  int stage_v_85_2 = (((sec_r001524_7_2 * 3) + pub_r001524_17_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001524_13_1 * 2) + 26) & 63;
  int stage_v_86_2 = ((pub_r001524_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001524_10_1 * 2) + 31) & 63;
  int stage_v_87_2 = ((pub_r001524_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_72_1 * 3) + pub_r001524_11_1) + 40) & 127;
  int stage_v_88_2 = (((stage_v_72_2 * 3) + pub_r001524_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001524_11_1 * 2) + 24) & 63;
  int stage_v_89_2 = ((pub_r001524_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001524_18_1 * 2) + 11) & 63;
  int stage_v_90_2 = ((pub_r001524_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((stage_v_55_1 * 3) + pub_r001524_0_1) + 44) & 127;
  int stage_v_91_2 = (((stage_v_55_2 * 3) + pub_r001524_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001524_16_1 * 2) + 24) & 63;
  int stage_v_92_2 = ((pub_r001524_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((stage_v_36_1 * 3) + pub_r001524_18_1) + 21) & 127;
  int stage_v_93_2 = (((stage_v_36_2 * 3) + pub_r001524_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = (((stage_v_63_1 * 3) + pub_r001524_19_1) + 35) & 127;
  int stage_v_94_2 = (((stage_v_63_2 * 3) + pub_r001524_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((sec_r001524_2_1 * 3) + pub_r001524_10_1) + 42) & 127;
  int stage_v_95_2 = (((sec_r001524_2_2 * 3) + pub_r001524_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = (((stage_v_22_1 * 3) + pub_r001524_15_1) + 32) & 127;
  int stage_v_96_2 = (((stage_v_22_2 * 3) + pub_r001524_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = (((sec_r001524_14_1 * 3) + pub_r001524_17_1) + 7) & 127;
  int stage_v_97_2 = (((sec_r001524_14_2 * 3) + pub_r001524_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = ((pub_r001524_12_1 * 2) + 40) & 63;
  int stage_v_98_2 = ((pub_r001524_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_14_1 * 3) + pub_r001524_11_1) + 21) & 127;
  int stage_v_99_2 = (((stage_v_14_2 * 3) + pub_r001524_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001524_9_1 * 2) + 5) & 63;
  int stage_v_100_2 = ((pub_r001524_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((sec_r001524_20_1 * 3) + pub_r001524_15_1) + 38) & 127;
  int stage_v_101_2 = (((sec_r001524_20_2 * 3) + pub_r001524_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001524_14_1 * 2) + 11) & 63;
  int stage_v_102_2 = ((pub_r001524_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((sec_r001524_21_1 * 3) + pub_r001524_12_1) + 27) & 127;
  int stage_v_103_2 = (((sec_r001524_21_2 * 3) + pub_r001524_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = (((stage_v_4_1 * 3) + pub_r001524_12_1) + 12) & 127;
  int stage_v_104_2 = (((stage_v_4_2 * 3) + pub_r001524_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001524_1_1 * 2) + 14) & 63;
  int stage_v_105_2 = ((pub_r001524_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001524_15_1 * 2) + 38) & 63;
  int stage_v_106_2 = ((pub_r001524_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001524_19_1 * 2) + 42) & 63;
  int stage_v_107_2 = ((pub_r001524_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((sec_r001524_9_1 * 3) + pub_r001524_18_1) + 44) & 127;
  int stage_v_108_2 = (((sec_r001524_9_2 * 3) + pub_r001524_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((sec_r001524_6_1 * 3) + pub_r001524_6_1) + 6) & 127;
  int stage_v_109_2 = (((sec_r001524_6_2 * 3) + pub_r001524_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((sec_r001524_10_1 * 3) + pub_r001524_8_1) + 15) & 127;
  int stage_v_110_2 = (((sec_r001524_10_2 * 3) + pub_r001524_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001524_1_1 * 2) + 37) & 63;
  int stage_v_111_2 = ((pub_r001524_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_73_1 * 3) + pub_r001524_16_1) + 34) & 127;
  int stage_v_112_2 = (((stage_v_73_2 * 3) + pub_r001524_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = ((pub_r001524_19_1 * 2) + 36) & 63;
  int stage_v_113_2 = ((pub_r001524_19_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((sec_r001524_2_1 * 3) + pub_r001524_12_1) + 30) & 127;
  int stage_v_114_2 = (((sec_r001524_2_2 * 3) + pub_r001524_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = ((pub_r001524_8_1 * 2) + 6) & 63;
  int stage_v_115_2 = ((pub_r001524_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001524_5_1 * 2) + 12) & 63;
  int stage_v_116_2 = ((pub_r001524_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001524_9_1 * 2) + 11) & 63;
  int stage_v_117_2 = ((pub_r001524_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((stage_v_36_1 * 3) + pub_r001524_14_1) + 3) & 127;
  int stage_v_118_2 = (((stage_v_36_2 * 3) + pub_r001524_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001524_20_1 * 2) + 22) & 63;
  int stage_v_119_2 = ((pub_r001524_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_12_1 * 3) + pub_r001524_14_1) + 32) & 127;
  int stage_v_120_2 = (((stage_v_12_2 * 3) + pub_r001524_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((stage_v_94_1 * 3) + pub_r001524_0_1) + 33) & 127;
  int stage_v_121_2 = (((stage_v_94_2 * 3) + pub_r001524_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = ((pub_r001524_13_1 * 2) + 11) & 63;
  int stage_v_122_2 = ((pub_r001524_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001524_0_1 * 2) + 39) & 63;
  int stage_v_123_2 = ((pub_r001524_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((stage_v_73_1 * 3) + pub_r001524_5_1) + 41) & 127;
  int stage_v_124_2 = (((stage_v_73_2 * 3) + pub_r001524_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((sec_r001524_5_1 * 3) + pub_r001524_12_1) + 42) & 127;
  int stage_v_125_2 = (((sec_r001524_5_2 * 3) + pub_r001524_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((stage_v_125_1 * 3) + pub_r001524_9_1) + 5) & 127;
  int stage_v_126_2 = (((stage_v_125_2 * 3) + pub_r001524_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001524_5_1 * 2) + 47) & 63;
  int stage_v_127_2 = ((pub_r001524_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001524_17_1 * 2) + 42) & 63;
  int stage_v_128_2 = ((pub_r001524_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_80_1 * 3) + pub_r001524_14_1) + 17) & 127;
  int stage_v_129_2 = (((stage_v_80_2 * 3) + pub_r001524_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001524_18_1 * 2) + 17) & 63;
  int stage_v_130_2 = ((pub_r001524_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_91_1 * 3) + pub_r001524_14_1) + 5) & 127;
  int stage_v_131_2 = (((stage_v_91_2 * 3) + pub_r001524_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = ((pub_r001524_6_1 * 2) + 28) & 63;
  int stage_v_132_2 = ((pub_r001524_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_62_1 * 3) + pub_r001524_5_1) + 15) & 127;
  int stage_v_133_2 = (((stage_v_62_2 * 3) + pub_r001524_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_88_1 * 3) + pub_r001524_0_1) + 37) & 127;
  int stage_v_134_2 = (((stage_v_88_2 * 3) + pub_r001524_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = ((pub_r001524_2_1 * 2) + 18) & 63;
  int stage_v_135_2 = ((pub_r001524_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_37_1 * 3) + pub_r001524_16_1) + 6) & 127;
  int stage_v_136_2 = (((stage_v_37_2 * 3) + pub_r001524_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((helper_flow_1_1 * 3) + pub_r001524_12_1) + 22) & 127;
  int stage_v_137_2 = (((helper_flow_1_2 * 3) + pub_r001524_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001524_3_1 * 2) + 12) & 63;
  int stage_v_138_2 = ((pub_r001524_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_97_1 * 3) + pub_r001524_2_1) + 13) & 127;
  int stage_v_139_2 = (((stage_v_97_2 * 3) + pub_r001524_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = ((pub_r001524_5_1 * 2) + 39) & 63;
  int stage_v_140_2 = ((pub_r001524_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((stage_v_12_1 * 3) + pub_r001524_10_1) + 17) & 127;
  int stage_v_141_2 = (((stage_v_12_2 * 3) + pub_r001524_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_45_1 * 3) + pub_r001524_8_1) + 45) & 127;
  int stage_v_142_2 = (((stage_v_45_2 * 3) + pub_r001524_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001524_17_1 * 2) + 39) & 63;
  int stage_v_143_2 = ((pub_r001524_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001524_19_1 * 2) + 28) & 63;
  int stage_v_144_2 = ((pub_r001524_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001524_8_1 * 2) + 7) & 63;
  int stage_v_145_2 = ((pub_r001524_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (((sec_r001524_4_1 * 3) + pub_r001524_2_1) + 25) & 127;
  int stage_v_146_2 = (((sec_r001524_4_2 * 3) + pub_r001524_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = (((helper_flow_0_1 * 3) + pub_r001524_2_1) + 22) & 127;
  int stage_v_147_2 = (((helper_flow_0_2 * 3) + pub_r001524_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001524_9_1 * 2) + 46) & 63;
  int stage_v_148_2 = ((pub_r001524_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001524_14_1 * 2) + 5) & 63;
  int stage_v_149_2 = ((pub_r001524_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((stage_v_99_1 * 3) + pub_r001524_0_1) + 22) & 127;
  int stage_v_150_2 = (((stage_v_99_2 * 3) + pub_r001524_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_137_1 * 3) + pub_r001524_4_1) + 44) & 127;
  int stage_v_151_2 = (((stage_v_137_2 * 3) + pub_r001524_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = ((pub_r001524_13_1 * 2) + 15) & 63;
  int stage_v_152_2 = ((pub_r001524_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_76_1 * 3) + pub_r001524_19_1) + 18) & 127;
  int stage_v_153_2 = (((stage_v_76_2 * 3) + pub_r001524_19_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = ((pub_r001524_4_1 * 2) + 43) & 63;
  int stage_v_154_2 = ((pub_r001524_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_5_1 * 3) + pub_r001524_6_1) + 14) & 127;
  int stage_v_155_2 = (((stage_v_5_2 * 3) + pub_r001524_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((helper_flow_1_1 * 3) + pub_r001524_17_1) + 17) & 127;
  int stage_v_156_2 = (((helper_flow_1_2 * 3) + pub_r001524_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_13_1 * 3) + pub_r001524_6_1) + 22) & 127;
  int stage_v_157_2 = (((stage_v_13_2 * 3) + pub_r001524_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001524_10_1 * 2) + 39) & 63;
  int stage_v_158_2 = ((pub_r001524_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001524_14_1 * 2) + 20) & 63;
  int stage_v_159_2 = ((pub_r001524_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((stage_v_146_1 * 3) + pub_r001524_7_1) + 7) & 127;
  int stage_v_160_2 = (((stage_v_146_2 * 3) + pub_r001524_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((stage_v_4_1 * 3) + pub_r001524_2_1) + 44) & 127;
  int stage_v_161_2 = (((stage_v_4_2 * 3) + pub_r001524_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((stage_v_108_1 * 3) + pub_r001524_4_1) + 35) & 127;
  int stage_v_162_2 = (((stage_v_108_2 * 3) + pub_r001524_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001524_18_1 * 2) + 34) & 63;
  int stage_v_163_2 = ((pub_r001524_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001524_12_1 * 2) + 16) & 63;
  int stage_v_164_2 = ((pub_r001524_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_63_1 * 3) + pub_r001524_5_1) + 34) & 127;
  int stage_v_165_2 = (((stage_v_63_2 * 3) + pub_r001524_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001524_11_1 * 2) + 43) & 63;
  int stage_v_166_2 = ((pub_r001524_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001524_19_1 * 2) + 24) & 63;
  int stage_v_167_2 = ((pub_r001524_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((stage_v_147_1 * 3) + pub_r001524_4_1) + 23) & 127;
  int stage_v_168_2 = (((stage_v_147_2 * 3) + pub_r001524_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((stage_v_30_1 * 3) + pub_r001524_1_1) + 13) & 127;
  int stage_v_169_2 = (((stage_v_30_2 * 3) + pub_r001524_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = ((pub_r001524_15_1 * 2) + 44) & 63;
  int stage_v_170_2 = ((pub_r001524_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_3_1 * 3) + pub_r001524_10_1) + 13) & 127;
  int stage_v_171_2 = (((stage_v_3_2 * 3) + pub_r001524_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((stage_v_15_1 * 3) + pub_r001524_11_1) + 14) & 127;
  int stage_v_172_2 = (((stage_v_15_2 * 3) + pub_r001524_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001524_9_1 * 2) + 20) & 63;
  int stage_v_173_2 = ((pub_r001524_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_88_1 * 3) + pub_r001524_14_1) + 27) & 127;
  int stage_v_174_2 = (((stage_v_88_2 * 3) + pub_r001524_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = (((stage_v_55_1 * 3) + pub_r001524_15_1) + 32) & 127;
  int stage_v_175_2 = (((stage_v_55_2 * 3) + pub_r001524_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((sec_r001524_17_1 * 3) + pub_r001524_18_1) + 15) & 127;
  int stage_v_176_2 = (((sec_r001524_17_2 * 3) + pub_r001524_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001524_8_1 * 2) + 33) & 63;
  int stage_v_177_2 = ((pub_r001524_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001524_20_1 * 2) + 19) & 63;
  int stage_v_178_2 = ((pub_r001524_20_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001524_7_1 * 2) + 47) & 63;
  int stage_v_179_2 = ((pub_r001524_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_161_1 * 3) + pub_r001524_6_1) + 14) & 127;
  int stage_v_180_2 = (((stage_v_161_2 * 3) + pub_r001524_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((sec_r001524_17_1 * 3) + pub_r001524_7_1) + 44) & 127;
  int stage_v_181_2 = (((sec_r001524_17_2 * 3) + pub_r001524_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((stage_v_121_1 * 3) + pub_r001524_11_1) + 35) & 127;
  int stage_v_182_2 = (((stage_v_121_2 * 3) + pub_r001524_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = ((pub_r001524_14_1 * 2) + 24) & 63;
  int stage_v_183_2 = ((pub_r001524_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_133_1 * 3) + pub_r001524_9_1) + 42) & 127;
  int stage_v_184_2 = (((stage_v_133_2 * 3) + pub_r001524_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((helper_flow_4_1 * 3) + pub_r001524_14_1) + 38) & 127;
  int stage_v_185_2 = (((helper_flow_4_2 * 3) + pub_r001524_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001524_20_1 * 2) + 21) & 63;
  int stage_v_186_2 = ((pub_r001524_20_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001524_4_1 * 2) + 37) & 63;
  int stage_v_187_2 = ((pub_r001524_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_84_1 * 3) + pub_r001524_19_1) + 40) & 127;
  int stage_v_188_2 = (((stage_v_84_2 * 3) + pub_r001524_19_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = (((stage_v_180_1 * 3) + pub_r001524_10_1) + 23) & 127;
  int stage_v_189_2 = (((stage_v_180_2 * 3) + pub_r001524_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = (((stage_v_38_1 * 3) + pub_r001524_15_1) + 41) & 127;
  int stage_v_190_2 = (((stage_v_38_2 * 3) + pub_r001524_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_121_1 * 3) + pub_r001524_17_1) + 25) & 127;
  int stage_v_191_2 = (((stage_v_121_2 * 3) + pub_r001524_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001524_5_1 * 2) + 30) & 63;
  int stage_v_192_2 = ((pub_r001524_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001524_11_1 * 2) + 30) & 63;
  int stage_v_193_2 = ((pub_r001524_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001524_8_1 * 2) + 45) & 63;
  int stage_v_194_2 = ((pub_r001524_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((sec_r001524_18_1 * 3) + pub_r001524_16_1) + 13) & 127;
  int stage_v_195_2 = (((sec_r001524_18_2 * 3) + pub_r001524_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001524_11_1 * 2) + 8) & 63;
  int stage_v_196_2 = ((pub_r001524_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_15_1 * 3) + pub_r001524_19_1) + 40) & 127;
  int stage_v_197_2 = (((stage_v_15_2 * 3) + pub_r001524_19_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = ((pub_r001524_2_1 * 2) + 46) & 63;
  int stage_v_198_2 = ((pub_r001524_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_62_1 * 3) + pub_r001524_6_1) + 17) & 127;
  int stage_v_199_2 = (((stage_v_62_2 * 3) + pub_r001524_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = (((stage_v_73_1 * 3) + pub_r001524_2_1) + 25) & 127;
  int stage_v_200_2 = (((stage_v_73_2 * 3) + pub_r001524_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = (((stage_v_189_1 * 3) + pub_r001524_13_1) + 4) & 127;
  int stage_v_201_2 = (((stage_v_189_2 * 3) + pub_r001524_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = (((stage_v_97_1 * 3) + pub_r001524_0_1) + 31) & 127;
  int stage_v_202_2 = (((stage_v_97_2 * 3) + pub_r001524_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = (((stage_v_85_1 * 3) + pub_r001524_15_1) + 6) & 127;
  int stage_v_203_2 = (((stage_v_85_2 * 3) + pub_r001524_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_109_1 * 3) + pub_r001524_18_1) + 33) & 127;
  int stage_v_204_2 = (((stage_v_109_2 * 3) + pub_r001524_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_43_1 * 3) + pub_r001524_6_1) + 13) & 127;
  int stage_v_205_2 = (((stage_v_43_2 * 3) + pub_r001524_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001524_10_1 * 2) + 20) & 63;
  int stage_v_206_2 = ((pub_r001524_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_108_1 * 3) + pub_r001524_2_1) + 33) & 127;
  int stage_v_207_2 = (((stage_v_108_2 * 3) + pub_r001524_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = (((stage_v_36_1 * 3) + pub_r001524_14_1) + 40) & 127;
  int stage_v_208_2 = (((stage_v_36_2 * 3) + pub_r001524_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = (((stage_v_6_1 * 3) + pub_r001524_11_1) + 8) & 127;
  int stage_v_209_2 = (((stage_v_6_2 * 3) + pub_r001524_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = ((pub_r001524_12_1 * 2) + 17) & 63;
  int stage_v_210_2 = ((pub_r001524_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_139_1 * 3) + pub_r001524_7_1) + 12) & 127;
  int stage_v_211_2 = (((stage_v_139_2 * 3) + pub_r001524_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_96_1 * 3) + pub_r001524_10_1) + 21) & 127;
  int stage_v_212_2 = (((stage_v_96_2 * 3) + pub_r001524_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_99_1 * 3) + pub_r001524_9_1) + 27) & 127;
  int stage_v_213_2 = (((stage_v_99_2 * 3) + pub_r001524_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = (((stage_v_114_1 * 3) + pub_r001524_10_1) + 26) & 127;
  int stage_v_214_2 = (((stage_v_114_2 * 3) + pub_r001524_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = ((pub_r001524_7_1 * 2) + 42) & 63;
  int stage_v_215_2 = ((pub_r001524_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (((stage_v_153_1 * 3) + pub_r001524_6_1) + 41) & 127;
  int stage_v_216_2 = (((stage_v_153_2 * 3) + pub_r001524_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = (((stage_v_9_1 * 3) + pub_r001524_12_1) + 28) & 127;
  int stage_v_217_2 = (((stage_v_9_2 * 3) + pub_r001524_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = (((sec_r001524_3_1 * 3) + pub_r001524_5_1) + 15) & 127;
  int stage_v_218_2 = (((sec_r001524_3_2 * 3) + pub_r001524_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = ((pub_r001524_19_1 * 2) + 39) & 63;
  int stage_v_219_2 = ((pub_r001524_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001524_14_1 * 2) + 42) & 63;
  int stage_v_220_2 = ((pub_r001524_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001524_17_1 * 2) + 18) & 63;
  int stage_v_221_2 = ((pub_r001524_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_71_1 * 3) + pub_r001524_20_1) + 3) & 127;
  int stage_v_222_2 = (((stage_v_71_2 * 3) + pub_r001524_20_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001524_16_1 * 2) + 6) & 63;
  int stage_v_223_2 = ((pub_r001524_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((sec_r001524_13_1 * 3) + pub_r001524_13_1) + 5) & 127;
  int stage_v_224_2 = (((sec_r001524_13_2 * 3) + pub_r001524_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = (((stage_v_9_1 * 3) + pub_r001524_8_1) + 43) & 127;
  int stage_v_225_2 = (((stage_v_9_2 * 3) + pub_r001524_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((stage_v_112_1 * 3) + pub_r001524_18_1) + 8) & 127;
  int stage_v_226_2 = (((stage_v_112_2 * 3) + pub_r001524_18_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_205_1 * 3) + pub_r001524_9_1) + 42) & 127;
  int stage_v_227_2 = (((stage_v_205_2 * 3) + pub_r001524_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001524_9_1 * 2) + 49) & 63;
  int stage_v_228_2 = ((pub_r001524_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_71_1 * 3) + pub_r001524_16_1) + 33) & 127;
  int stage_v_229_2 = (((stage_v_71_2 * 3) + pub_r001524_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001524_9_1 * 2) + 35) & 63;
  int stage_v_230_2 = ((pub_r001524_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((helper_flow_6_1 * 3) + pub_r001524_1_1) + 6) & 127;
  int stage_v_231_2 = (((helper_flow_6_2 * 3) + pub_r001524_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001524_20_1 * 2) + 17) & 63;
  int stage_v_232_2 = ((pub_r001524_20_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((stage_v_153_1 * 3) + pub_r001524_8_1) + 37) & 127;
  int stage_v_233_2 = (((stage_v_153_2 * 3) + pub_r001524_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = ((pub_r001524_4_1 * 2) + 7) & 63;
  int stage_v_234_2 = ((pub_r001524_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001524_12_1 * 2) + 27) & 63;
  int stage_v_235_2 = ((pub_r001524_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001524_11_1 * 2) + 5) & 63;
  int stage_v_236_2 = ((pub_r001524_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001524_9_1 * 2) + 11) & 63;
  int stage_v_237_2 = ((pub_r001524_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = (((helper_flow_1_1 * 3) + pub_r001524_16_1) + 3) & 127;
  int stage_v_238_2 = (((helper_flow_1_2 * 3) + pub_r001524_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = (((stage_v_212_1 * 3) + pub_r001524_11_1) + 7) & 127;
  int stage_v_239_2 = (((stage_v_212_2 * 3) + pub_r001524_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((sec_r001524_10_1 * 3) + pub_r001524_12_1) + 19) & 127;
  int stage_v_240_2 = (((sec_r001524_10_2 * 3) + pub_r001524_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = ((pub_r001524_3_1 * 2) + 39) & 63;
  int stage_v_241_2 = ((pub_r001524_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001524_5_1 * 2) + 39) & 63;
  int stage_v_242_2 = ((pub_r001524_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((helper_flow_5_1 * 3) + pub_r001524_17_1) + 21) & 127;
  int stage_v_243_2 = (((helper_flow_5_2 * 3) + pub_r001524_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_12_1 * 3) + pub_r001524_11_1) + 16) & 127;
  int stage_v_244_2 = (((stage_v_12_2 * 3) + pub_r001524_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_189_1 * 3) + pub_r001524_13_1) + 6) & 127;
  int stage_v_245_2 = (((stage_v_189_2 * 3) + pub_r001524_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = (((stage_v_48_1 * 3) + pub_r001524_0_1) + 11) & 127;
  int stage_v_246_2 = (((stage_v_48_2 * 3) + pub_r001524_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = (((stage_v_213_1 * 3) + pub_r001524_16_1) + 21) & 127;
  int stage_v_247_2 = (((stage_v_213_2 * 3) + pub_r001524_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = (((sec_r001524_15_1 * 3) + pub_r001524_8_1) + 35) & 127;
  int stage_v_248_2 = (((sec_r001524_15_2 * 3) + pub_r001524_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_84_1 * 3) + pub_r001524_12_1) + 29) & 127;
  int stage_v_249_2 = (((stage_v_84_2 * 3) + pub_r001524_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_71_1 * 3) + pub_r001524_20_1) + 32) & 127;
  int stage_v_250_2 = (((stage_v_71_2 * 3) + pub_r001524_20_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((sec_r001524_12_1 * 3) + pub_r001524_19_1) + 33) & 127;
  int stage_v_251_2 = (((sec_r001524_12_2 * 3) + pub_r001524_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((stage_v_103_1 * 3) + pub_r001524_6_1) + 26) & 127;
  int stage_v_252_2 = (((stage_v_103_2 * 3) + pub_r001524_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((stage_v_231_1 * 3) + pub_r001524_10_1) + 38) & 127;
  int stage_v_253_2 = (((stage_v_231_2 * 3) + pub_r001524_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001524_9_1 * 2) + 16) & 63;
  int stage_v_254_2 = ((pub_r001524_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001524_20_1 * 2) + 49) & 63;
  int stage_v_255_2 = ((pub_r001524_20_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = (((stage_v_114_1 * 3) + pub_r001524_8_1) + 16) & 127;
  int stage_v_256_2 = (((stage_v_114_2 * 3) + pub_r001524_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001524_9_1 * 2) + 47) & 63;
  int stage_v_257_2 = ((pub_r001524_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001524_0_1 * 2) + 36) & 63;
  int stage_v_258_2 = ((pub_r001524_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001524_9_1 * 2) + 21) & 63;
  int stage_v_259_2 = ((pub_r001524_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001524_6_1 * 2) + 38) & 63;
  int stage_v_260_2 = ((pub_r001524_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_214_1 * 3) + pub_r001524_10_1) + 5) & 127;
  int stage_v_261_2 = (((stage_v_214_2 * 3) + pub_r001524_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001524_7_1 * 2) + 22) & 63;
  int stage_v_262_2 = ((pub_r001524_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001524_14_1 * 2) + 13) & 63;
  int stage_v_263_2 = ((pub_r001524_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = (((stage_v_157_1 * 3) + pub_r001524_16_1) + 39) & 127;
  int stage_v_264_2 = (((stage_v_157_2 * 3) + pub_r001524_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = ((pub_r001524_16_1 * 2) + 50) & 63;
  int stage_v_265_2 = ((pub_r001524_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001524_15_1 * 2) + 15) & 63;
  int stage_v_266_2 = ((pub_r001524_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = (((stage_v_99_1 * 3) + pub_r001524_9_1) + 44) & 127;
  int stage_v_267_2 = (((stage_v_99_2 * 3) + pub_r001524_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_5_1 * 3) + pub_r001524_18_1) + 30) & 127;
  int stage_v_268_2 = (((stage_v_5_2 * 3) + pub_r001524_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001524_4_1 * 2) + 32) & 63;
  int stage_v_269_2 = ((pub_r001524_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((stage_v_84_1 * 3) + pub_r001524_19_1) + 7) & 127;
  int stage_v_270_2 = (((stage_v_84_2 * 3) + pub_r001524_19_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((stage_v_131_1 * 3) + pub_r001524_2_1) + 26) & 127;
  int stage_v_271_2 = (((stage_v_131_2 * 3) + pub_r001524_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001524_11_1 * 2) + 35) & 63;
  int stage_v_272_2 = ((pub_r001524_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((stage_v_176_1 * 3) + pub_r001524_16_1) + 26) & 127;
  int stage_v_273_2 = (((stage_v_176_2 * 3) + pub_r001524_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001524_1_1 * 2) + 30) & 63;
  int stage_v_274_2 = ((pub_r001524_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = (((stage_v_264_1 * 3) + pub_r001524_17_1) + 3) & 127;
  int stage_v_275_2 = (((stage_v_264_2 * 3) + pub_r001524_17_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((stage_v_66_1 * 3) + pub_r001524_15_1) + 38) & 127;
  int stage_v_276_2 = (((stage_v_66_2 * 3) + pub_r001524_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001524_10_1 * 2) + 27) & 63;
  int stage_v_277_2 = ((pub_r001524_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((sec_r001524_15_1 * 3) + pub_r001524_15_1) + 21) & 127;
  int stage_v_278_2 = (((sec_r001524_15_2 * 3) + pub_r001524_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_81_1 * 3) + pub_r001524_17_1) + 20) & 127;
  int stage_v_279_2 = (((stage_v_81_2 * 3) + pub_r001524_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((sec_r001524_3_1 * 3) + pub_r001524_15_1) + 26) & 127;
  int stage_v_280_2 = (((sec_r001524_3_2 * 3) + pub_r001524_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = ((pub_r001524_2_1 * 2) + 6) & 63;
  int stage_v_281_2 = ((pub_r001524_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001524_12_1 * 2) + 49) & 63;
  int stage_v_282_2 = ((pub_r001524_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001524_18_1 * 2) + 18) & 63;
  int stage_v_283_2 = ((pub_r001524_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = (((stage_v_51_1 * 3) + pub_r001524_16_1) + 11) & 127;
  int stage_v_284_2 = (((stage_v_51_2 * 3) + pub_r001524_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001524_10_1 * 2) + 7) & 63;
  int stage_v_285_2 = ((pub_r001524_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((sec_r001524_22_1 * 3) + pub_r001524_18_1) + 16) & 127;
  int stage_v_286_2 = (((sec_r001524_22_2 * 3) + pub_r001524_18_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((sec_r001524_6_1 * 3) + pub_r001524_10_1) + 43) & 127;
  int stage_v_287_2 = (((sec_r001524_6_2 * 3) + pub_r001524_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001524_3_1 * 2) + 28) & 63;
  int stage_v_288_2 = ((pub_r001524_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001524_17_1 * 2) + 25) & 63;
  int stage_v_289_2 = ((pub_r001524_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001524_13_1 * 2) + 33) & 63;
  int stage_v_290_2 = ((pub_r001524_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = (((stage_v_275_1 * 3) + pub_r001524_0_1) + 36) & 127;
  int stage_v_291_2 = (((stage_v_275_2 * 3) + pub_r001524_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001524_8_1 * 2) + 37) & 63;
  int stage_v_292_2 = ((pub_r001524_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001524_3_1 * 2) + 21) & 63;
  int stage_v_293_2 = ((pub_r001524_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001524_2_1 * 2) + 50) & 63;
  int stage_v_294_2 = ((pub_r001524_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001524_19_1 * 2) + 26) & 63;
  int stage_v_295_2 = ((pub_r001524_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((stage_v_182_1 * 3) + pub_r001524_16_1) + 22) & 127;
  int stage_v_296_2 = (((stage_v_182_2 * 3) + pub_r001524_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = (((stage_v_3_1 * 3) + pub_r001524_3_1) + 24) & 127;
  int stage_v_297_2 = (((stage_v_3_2 * 3) + pub_r001524_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((stage_v_31_1 * 3) + pub_r001524_20_1) + 7) & 127;
  int stage_v_298_2 = (((stage_v_31_2 * 3) + pub_r001524_20_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((sec_r001524_9_1 * 3) + pub_r001524_20_1) + 43) & 127;
  int stage_v_299_2 = (((sec_r001524_9_2 * 3) + pub_r001524_20_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = (((sec_r001524_13_1 * 3) + pub_r001524_13_1) + 18) & 127;
  int stage_v_300_2 = (((sec_r001524_13_2 * 3) + pub_r001524_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = (((sec_r001524_20_1 * 3) + pub_r001524_7_1) + 44) & 127;
  int stage_v_301_2 = (((sec_r001524_20_2 * 3) + pub_r001524_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001524_9_1 * 2) + 5) & 63;
  int stage_v_302_2 = ((pub_r001524_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001524_8_1 * 2) + 16) & 63;
  int stage_v_303_2 = ((pub_r001524_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001524_13_1 * 2) + 34) & 63;
  int stage_v_304_2 = ((pub_r001524_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001524_6_1 * 2) + 23) & 63;
  int stage_v_305_2 = ((pub_r001524_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_48_1 * 3) + pub_r001524_11_1) + 13) & 127;
  int stage_v_306_2 = (((stage_v_48_2 * 3) + pub_r001524_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = ((pub_r001524_17_1 * 2) + 11) & 63;
  int stage_v_307_2 = ((pub_r001524_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001524_5_1 * 2) + 41) & 63;
  int stage_v_308_2 = ((pub_r001524_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_125_1 * 3) + pub_r001524_14_1) + 41) & 127;
  int stage_v_309_2 = (((stage_v_125_2 * 3) + pub_r001524_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = (((stage_v_23_1 * 3) + pub_r001524_13_1) + 4) & 127;
  int stage_v_310_2 = (((stage_v_23_2 * 3) + pub_r001524_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = (((stage_v_17_1 * 3) + pub_r001524_10_1) + 43) & 127;
  int stage_v_311_2 = (((stage_v_17_2 * 3) + pub_r001524_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001524_20_1 * 2) + 16) & 63;
  int stage_v_312_2 = ((pub_r001524_20_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_80_1 * 3) + pub_r001524_0_1) + 37) & 127;
  int stage_v_313_2 = (((stage_v_80_2 * 3) + pub_r001524_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001524_0_1 * 2) + 31) & 63;
  int stage_v_314_2 = ((pub_r001524_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001524_10_1 * 2) + 45) & 63;
  int stage_v_315_2 = ((pub_r001524_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_195_1 * 3) + pub_r001524_6_1) + 44) & 127;
  int stage_v_316_2 = (((stage_v_195_2 * 3) + pub_r001524_6_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001524_19_1 * 2) + 29) & 63;
  int stage_v_317_2 = ((pub_r001524_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001524_9_1 * 2) + 47) & 63;
  int stage_v_318_2 = ((pub_r001524_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = (((stage_v_38_1 * 3) + pub_r001524_12_1) + 39) & 127;
  int stage_v_319_2 = (((stage_v_38_2 * 3) + pub_r001524_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = (((stage_v_35_1 * 3) + pub_r001524_15_1) + 15) & 127;
  int stage_v_320_2 = (((stage_v_35_2 * 3) + pub_r001524_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_146_1 * 3) + pub_r001524_0_1) + 39) & 127;
  int stage_v_321_2 = (((stage_v_146_2 * 3) + pub_r001524_0_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((sec_r001524_9_1 * 3) + pub_r001524_19_1) + 17) & 127;
  int stage_v_322_2 = (((sec_r001524_9_2 * 3) + pub_r001524_19_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = (((sec_r001524_14_1 * 3) + pub_r001524_8_1) + 28) & 127;
  int stage_v_323_2 = (((sec_r001524_14_2 * 3) + pub_r001524_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((stage_v_74_1 * 3) + pub_r001524_1_1) + 42) & 127;
  int stage_v_324_2 = (((stage_v_74_2 * 3) + pub_r001524_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_30_1 * 3) + pub_r001524_20_1) + 32) & 127;
  int stage_v_325_2 = (((stage_v_30_2 * 3) + pub_r001524_20_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001524_6_1 * 2) + 9) & 63;
  int stage_v_326_2 = ((pub_r001524_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001524_6_1 * 2) + 9) & 63;
  int stage_v_327_2 = ((pub_r001524_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_202_1 * 3) + pub_r001524_12_1) + 10) & 127;
  int stage_v_328_2 = (((stage_v_202_2 * 3) + pub_r001524_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((stage_v_189_1 * 3) + pub_r001524_1_1) + 7) & 127;
  int stage_v_329_2 = (((stage_v_189_2 * 3) + pub_r001524_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = (((stage_v_131_1 * 3) + pub_r001524_11_1) + 27) & 127;
  int stage_v_330_2 = (((stage_v_131_2 * 3) + pub_r001524_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = (((stage_v_189_1 * 3) + pub_r001524_12_1) + 30) & 127;
  int stage_v_331_2 = (((stage_v_189_2 * 3) + pub_r001524_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((sec_r001524_19_1 * 3) + pub_r001524_15_1) + 24) & 127;
  int stage_v_332_2 = (((sec_r001524_19_2 * 3) + pub_r001524_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = ((pub_r001524_2_1 * 2) + 18) & 63;
  int stage_v_333_2 = ((pub_r001524_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001524_2_1 * 2) + 32) & 63;
  int stage_v_334_2 = ((pub_r001524_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001524_12_1 * 2) + 8) & 63;
  int stage_v_335_2 = ((pub_r001524_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = (((stage_v_136_1 * 3) + pub_r001524_6_1) + 23) & 127;
  int stage_v_336_2 = (((stage_v_136_2 * 3) + pub_r001524_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((helper_flow_0_1 * 3) + pub_r001524_1_1) + 9) & 127;
  int stage_v_337_2 = (((helper_flow_0_2 * 3) + pub_r001524_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_91_1 * 3) + pub_r001524_12_1) + 15) & 127;
  int stage_v_338_2 = (((stage_v_91_2 * 3) + pub_r001524_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001524_10_1 * 2) + 28) & 63;
  int stage_v_339_2 = ((pub_r001524_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_211_1 * 3) + pub_r001524_11_1) + 24) & 127;
  int stage_v_340_2 = (((stage_v_211_2 * 3) + pub_r001524_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001524_16_1 * 2) + 17) & 63;
  int stage_v_341_2 = ((pub_r001524_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = (((sec_r001524_0_1 * 3) + pub_r001524_6_1) + 33) & 127;
  int stage_v_342_2 = (((sec_r001524_0_2 * 3) + pub_r001524_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_202_1 * 3) + pub_r001524_20_1) + 29) & 127;
  int stage_v_343_2 = (((stage_v_202_2 * 3) + pub_r001524_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_93_1 * 3) + pub_r001524_13_1) + 29) & 127;
  int stage_v_344_2 = (((stage_v_93_2 * 3) + pub_r001524_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001524_7_1 * 2) + 33) & 63;
  int stage_v_345_2 = ((pub_r001524_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_275_1 * 3) + pub_r001524_16_1) + 41) & 127;
  int stage_v_346_2 = (((stage_v_275_2 * 3) + pub_r001524_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001524_5_1 * 2) + 39) & 63;
  int stage_v_347_2 = ((pub_r001524_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_213_1 * 3) + pub_r001524_4_1) + 11) & 127;
  int stage_v_348_2 = (((stage_v_213_2 * 3) + pub_r001524_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_340_1 * 3) + pub_r001524_4_1) + 33) & 127;
  int stage_v_349_2 = (((stage_v_340_2 * 3) + pub_r001524_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_124_1 * 3) + pub_r001524_20_1) + 34) & 127;
  int stage_v_350_2 = (((stage_v_124_2 * 3) + pub_r001524_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((helper_flow_2_1 * 3) + pub_r001524_10_1) + 4) & 127;
  int stage_v_351_2 = (((helper_flow_2_2 * 3) + pub_r001524_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_162_1 * 3) + pub_r001524_3_1) + 13) & 127;
  int stage_v_352_2 = (((stage_v_162_2 * 3) + pub_r001524_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_286_1 * 3) + pub_r001524_2_1) + 34) & 127;
  int stage_v_353_2 = (((stage_v_286_2 * 3) + pub_r001524_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((sec_r001524_3_1 * 3) + pub_r001524_10_1) + 26) & 127;
  int stage_v_354_2 = (((sec_r001524_3_2 * 3) + pub_r001524_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = ((pub_r001524_15_1 * 2) + 11) & 63;
  int stage_v_355_2 = ((pub_r001524_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001524_3_1 * 2) + 22) & 63;
  int stage_v_356_2 = ((pub_r001524_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001524_17_1 * 2) + 7) & 63;
  int stage_v_357_2 = ((pub_r001524_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001524_4_1 * 2) + 26) & 63;
  int stage_v_358_2 = ((pub_r001524_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_103_1 * 3) + pub_r001524_17_1) + 6) & 127;
  int stage_v_359_2 = (((stage_v_103_2 * 3) + pub_r001524_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001524_20_1 * 2) + 24) & 63;
  int stage_v_360_2 = ((pub_r001524_20_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((sec_r001524_19_1 * 3) + pub_r001524_18_1) + 24) & 127;
  int stage_v_361_2 = (((sec_r001524_19_2 * 3) + pub_r001524_18_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((sec_r001524_16_1 * 3) + pub_r001524_19_1) + 34) & 127;
  int stage_v_362_2 = (((sec_r001524_16_2 * 3) + pub_r001524_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = (((stage_v_337_1 * 3) + pub_r001524_3_1) + 32) & 127;
  int stage_v_363_2 = (((stage_v_337_2 * 3) + pub_r001524_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_344_1 * 3) + pub_r001524_18_1) + 19) & 127;
  int stage_v_364_2 = (((stage_v_344_2 * 3) + pub_r001524_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((sec_r001524_3_1 * 3) + pub_r001524_0_1) + 36) & 127;
  int stage_v_365_2 = (((sec_r001524_3_2 * 3) + pub_r001524_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = (((stage_v_17_1 * 3) + pub_r001524_8_1) + 39) & 127;
  int stage_v_366_2 = (((stage_v_17_2 * 3) + pub_r001524_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_279_1 * 3) + pub_r001524_4_1) + 26) & 127;
  int stage_v_367_2 = (((stage_v_279_2 * 3) + pub_r001524_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001524_10_1 * 2) + 15) & 63;
  int stage_v_368_2 = ((pub_r001524_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = (((stage_v_329_1 * 3) + pub_r001524_20_1) + 26) & 127;
  int stage_v_369_2 = (((stage_v_329_2 * 3) + pub_r001524_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = ((pub_r001524_9_1 * 2) + 30) & 63;
  int stage_v_370_2 = ((pub_r001524_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((stage_v_188_1 * 3) + pub_r001524_11_1) + 6) & 127;
  int stage_v_371_2 = (((stage_v_188_2 * 3) + pub_r001524_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = (((sec_r001524_22_1 * 3) + pub_r001524_16_1) + 43) & 127;
  int stage_v_372_2 = (((sec_r001524_22_2 * 3) + pub_r001524_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = (((stage_v_240_1 * 3) + pub_r001524_9_1) + 40) & 127;
  int stage_v_373_2 = (((stage_v_240_2 * 3) + pub_r001524_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((stage_v_267_1 * 3) + pub_r001524_6_1) + 13) & 127;
  int stage_v_374_2 = (((stage_v_267_2 * 3) + pub_r001524_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((sec_r001524_3_1 * 3) + pub_r001524_8_1) + 38) & 127;
  int stage_v_375_2 = (((sec_r001524_3_2 * 3) + pub_r001524_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_66_1 * 3) + pub_r001524_3_1) + 10) & 127;
  int stage_v_376_2 = (((stage_v_66_2 * 3) + pub_r001524_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((stage_v_74_1 * 3) + pub_r001524_14_1) + 27) & 127;
  int stage_v_377_2 = (((stage_v_74_2 * 3) + pub_r001524_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = ((pub_r001524_9_1 * 2) + 7) & 63;
  int stage_v_378_2 = ((pub_r001524_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = (((stage_v_136_1 * 3) + pub_r001524_13_1) + 3) & 127;
  int stage_v_379_2 = (((stage_v_136_2 * 3) + pub_r001524_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_246_1 * 3) + pub_r001524_20_1) + 34) & 127;
  int stage_v_380_2 = (((stage_v_246_2 * 3) + pub_r001524_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_364_1 * 3) + pub_r001524_16_1) + 40) & 127;
  int stage_v_381_2 = (((stage_v_364_2 * 3) + pub_r001524_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001524_16_1 * 2) + 6) & 63;
  int stage_v_382_2 = ((pub_r001524_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = (((stage_v_95_1 * 3) + pub_r001524_11_1) + 13) & 127;
  int stage_v_383_2 = (((stage_v_95_2 * 3) + pub_r001524_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((stage_v_240_1 * 3) + pub_r001524_18_1) + 36) & 127;
  int stage_v_384_2 = (((stage_v_240_2 * 3) + pub_r001524_18_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = (((stage_v_147_1 * 3) + pub_r001524_0_1) + 31) & 127;
  int stage_v_385_2 = (((stage_v_147_2 * 3) + pub_r001524_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = ((pub_r001524_18_1 * 2) + 33) & 63;
  int stage_v_386_2 = ((pub_r001524_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_160_1 * 3) + pub_r001524_20_1) + 4) & 127;
  int stage_v_387_2 = (((stage_v_160_2 * 3) + pub_r001524_20_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = (((stage_v_279_1 * 3) + pub_r001524_7_1) + 15) & 127;
  int stage_v_388_2 = (((stage_v_279_2 * 3) + pub_r001524_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = (((stage_v_388_1 * 3) + pub_r001524_13_1) + 16) & 127;
  int stage_v_389_2 = (((stage_v_388_2 * 3) + pub_r001524_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = (((stage_v_6_1 * 3) + pub_r001524_16_1) + 13) & 127;
  int stage_v_390_2 = (((stage_v_6_2 * 3) + pub_r001524_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((stage_v_224_1 * 3) + pub_r001524_10_1) + 15) & 127;
  int stage_v_391_2 = (((stage_v_224_2 * 3) + pub_r001524_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((sec_r001524_0_1 * 3) + pub_r001524_8_1) + 44) & 127;
  int stage_v_392_2 = (((sec_r001524_0_2 * 3) + pub_r001524_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = (((stage_v_176_1 * 3) + pub_r001524_0_1) + 41) & 127;
  int stage_v_393_2 = (((stage_v_176_2 * 3) + pub_r001524_0_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = (((stage_v_309_1 * 3) + pub_r001524_18_1) + 6) & 127;
  int stage_v_394_2 = (((stage_v_309_2 * 3) + pub_r001524_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = (((stage_v_85_1 * 3) + pub_r001524_19_1) + 39) & 127;
  int stage_v_395_2 = (((stage_v_85_2 * 3) + pub_r001524_19_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = ((pub_r001524_1_1 * 2) + 48) & 63;
  int stage_v_396_2 = ((pub_r001524_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = (((stage_v_114_1 * 3) + pub_r001524_19_1) + 36) & 127;
  int stage_v_397_2 = (((stage_v_114_2 * 3) + pub_r001524_19_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = (((stage_v_371_1 * 3) + pub_r001524_12_1) + 27) & 127;
  int stage_v_398_2 = (((stage_v_371_2 * 3) + pub_r001524_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = (((stage_v_175_1 * 3) + pub_r001524_5_1) + 45) & 127;
  int stage_v_399_2 = (((stage_v_175_2 * 3) + pub_r001524_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = (((stage_v_287_1 * 3) + pub_r001524_4_1) + 12) & 127;
  int stage_v_400_2 = (((stage_v_287_2 * 3) + pub_r001524_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = (((stage_v_96_1 * 3) + pub_r001524_0_1) + 5) & 127;
  int stage_v_401_2 = (((stage_v_96_2 * 3) + pub_r001524_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = (((stage_v_55_1 * 3) + pub_r001524_18_1) + 43) & 127;
  int stage_v_402_2 = (((stage_v_55_2 * 3) + pub_r001524_18_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = (((stage_v_336_1 * 3) + pub_r001524_18_1) + 28) & 127;
  int stage_v_403_2 = (((stage_v_336_2 * 3) + pub_r001524_18_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = (((stage_v_48_1 * 3) + pub_r001524_12_1) + 22) & 127;
  int stage_v_404_2 = (((stage_v_48_2 * 3) + pub_r001524_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_388_1 * 3) + pub_r001524_19_1) + 19) & 127;
  int stage_v_405_2 = (((stage_v_388_2 * 3) + pub_r001524_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((stage_v_403_1 * 3) + pub_r001524_8_1) + 37) & 127;
  int stage_v_406_2 = (((stage_v_403_2 * 3) + pub_r001524_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001524_4_1 * 2) + 45) & 63;
  int stage_v_407_2 = ((pub_r001524_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_279_1 * 3) + pub_r001524_15_1) + 5) & 127;
  int stage_v_408_2 = (((stage_v_279_2 * 3) + pub_r001524_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001524_6_1 * 2) + 39) & 63;
  int stage_v_409_2 = ((pub_r001524_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001524_7_1 * 2) + 7) & 63;
  int stage_v_410_2 = ((pub_r001524_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001524_6_1 * 2) + 29) & 63;
  int stage_v_411_2 = ((pub_r001524_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((stage_v_108_1 * 3) + pub_r001524_7_1) + 6) & 127;
  int stage_v_412_2 = (((stage_v_108_2 * 3) + pub_r001524_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = (((stage_v_390_1 * 3) + pub_r001524_8_1) + 26) & 127;
  int stage_v_413_2 = (((stage_v_390_2 * 3) + pub_r001524_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = ((pub_r001524_16_1 * 2) + 7) & 63;
  int stage_v_414_2 = ((pub_r001524_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((pub_r001524_15_1 * 2) + 8) & 63;
  int stage_v_415_2 = ((pub_r001524_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = (((stage_v_367_1 * 3) + pub_r001524_4_1) + 11) & 127;
  int stage_v_416_2 = (((stage_v_367_2 * 3) + pub_r001524_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = ((pub_r001524_2_1 * 2) + 34) & 63;
  int stage_v_417_2 = ((pub_r001524_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001524_12_1 * 2) + 9) & 63;
  int stage_v_418_2 = ((pub_r001524_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001524_2_1 * 2) + 41) & 63;
  int stage_v_419_2 = ((pub_r001524_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = (((helper_flow_3_1 * 3) + pub_r001524_16_1) + 27) & 127;
  int stage_v_420_2 = (((helper_flow_3_2 * 3) + pub_r001524_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = ((pub_r001524_9_1 * 2) + 28) & 63;
  int stage_v_421_2 = ((pub_r001524_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001524_16_1 == pub_r001524_16_2);
  __CPROVER_assume(sec_r001524_15_1 != sec_r001524_15_2);
  __CPROVER_assume(sec_r001524_9_1 != sec_r001524_9_2);
  __CPROVER_assume(pub_r001524_1_1 == pub_r001524_1_2);
  __CPROVER_assume(pub_r001524_15_1 == pub_r001524_15_2);
  __CPROVER_assume(sec_r001524_22_1 != sec_r001524_22_2);
  __CPROVER_assume(sec_r001524_13_1 != sec_r001524_13_2);
  __CPROVER_assume(sec_r001524_4_1 != sec_r001524_4_2);
  __CPROVER_assume(sec_r001524_0_1 != sec_r001524_0_2);
  __CPROVER_assume(sec_r001524_6_1 != sec_r001524_6_2);
  __CPROVER_assume(pub_r001524_11_1 == pub_r001524_11_2);
  __CPROVER_assume(pub_r001524_2_1 == pub_r001524_2_2);
  __CPROVER_assume(sec_r001524_16_1 != sec_r001524_16_2);
  __CPROVER_assume(pub_r001524_19_1 == pub_r001524_19_2);
  __CPROVER_assume(pub_r001524_6_1 == pub_r001524_6_2);
  __CPROVER_assume(sec_r001524_11_1 != sec_r001524_11_2);
  __CPROVER_assume(sec_r001524_23_1 != sec_r001524_23_2);
  __CPROVER_assume(pub_r001524_4_1 == pub_r001524_4_2);
  __CPROVER_assume(sec_r001524_21_1 != sec_r001524_21_2);
  __CPROVER_assume(sec_r001524_1_1 != sec_r001524_1_2);
  __CPROVER_assume(sec_r001524_10_1 != sec_r001524_10_2);
  __CPROVER_assume(pub_r001524_9_1 == pub_r001524_9_2);
  __CPROVER_assume(pub_r001524_14_1 == pub_r001524_14_2);
  __CPROVER_assume(pub_r001524_8_1 == pub_r001524_8_2);
  __CPROVER_assume(pub_r001524_20_1 == pub_r001524_20_2);
  __CPROVER_assume(sec_r001524_3_1 != sec_r001524_3_2);
  __CPROVER_assume(pub_r001524_13_1 == pub_r001524_13_2);
  __CPROVER_assume(pub_r001524_18_1 == pub_r001524_18_2);
  __CPROVER_assume(sec_r001524_14_1 != sec_r001524_14_2);
  __CPROVER_assume(sec_r001524_18_1 != sec_r001524_18_2);
  __CPROVER_assume(pub_r001524_0_1 == pub_r001524_0_2);
  __CPROVER_assume(sec_r001524_8_1 != sec_r001524_8_2);
  __CPROVER_assume(pub_r001524_3_1 == pub_r001524_3_2);
  __CPROVER_assume(sec_r001524_2_1 != sec_r001524_2_2);
  __CPROVER_assume(sec_r001524_12_1 != sec_r001524_12_2);
  __CPROVER_assume(sec_r001524_17_1 != sec_r001524_17_2);
  __CPROVER_assume(pub_r001524_12_1 == pub_r001524_12_2);
  __CPROVER_assume(pub_r001524_5_1 == pub_r001524_5_2);
  __CPROVER_assume(pub_r001524_17_1 == pub_r001524_17_2);
  __CPROVER_assume(sec_r001524_19_1 != sec_r001524_19_2);
  __CPROVER_assume(sec_r001524_7_1 != sec_r001524_7_2);
  __CPROVER_assume(pub_r001524_10_1 == pub_r001524_10_2);
  __CPROVER_assume(sec_r001524_20_1 != sec_r001524_20_2);
  __CPROVER_assume(sec_r001524_5_1 != sec_r001524_5_2);
  __CPROVER_assume(pub_r001524_7_1 == pub_r001524_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.tail == st_var_2_2.tail);
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
}


