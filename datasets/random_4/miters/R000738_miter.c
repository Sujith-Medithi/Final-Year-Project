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
struct Transaction_R000738_3813_0
{
  int status;
  int balance;
  int rate;
  int buffer[3];
};
struct StreamBuffer_R000738_3813_1
{
  unsigned char checksum;
  int head;
  short tail;
  int capacity;
  int state;
  int buffer[3];
};
struct SensorNode_R000738_3813_2
{
  int gain;
  int reading;
  unsigned char status;
  int threshold;
  int calib;
  int buffer[3];
};
union RegisterBank_R000738_3813_0
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
void fn_R000738_3813_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st_1 = {0};
  struct SensorNode_R000738_3813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int threshold_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_83_1)
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

  switch (threshold_83_2)
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

  int index_reg_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_87_1) & 63;
  aux_2 = (aux_2 + index_reg_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_27_1 = 0;
  int accumulator_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_27_1 = ((accumulator_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_27_2 = ((accumulator_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_27_1) & 127;
    acc_2 = (acc_2 + accumulator_27_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_83_1 == threshold_83_2);
  assert(index_reg_87_1 == index_reg_87_2);
  assert(accumulator_27_1 == accumulator_27_2);
}

int fn_R000738_3813_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int threshold_83 = (aux + st.buffer[1]) & 3;
  switch (threshold_83)
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

  int index_reg_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_87) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_27 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_27 = ((accumulator_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_27) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000738_3813_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st_1 = {0};
  struct StreamBuffer_R000738_3813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int quantum_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_49_1 > 45)
  {
    acc_1 = ((acc_1 + (quantum_49_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_49_2 > 45)
  {
    acc_2 = ((acc_2 + (quantum_49_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_44_1 = local_arr_1[aux_1 % 3];
  int metric_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_44_2 * 2)) & 127;
  int anchor_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_15_1)
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

  switch (anchor_15_2)
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

  int bound_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_71_1) & 63;
  aux_2 = (aux_2 + bound_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_49_1 == quantum_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_44_1 == metric_44_2);
  assert(anchor_15_1 == anchor_15_2);
  assert(bound_71_1 == bound_71_2);
}

int fn_R000738_3813_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int quantum_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_49 > 45)
  {
    acc = ((acc + (quantum_49 * 2)) + 5) & 127;
    aux ^= quantum_49 & 15;
  }
  else
  {
    acc = ((acc - quantum_49) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_44 = local_arr[aux % 3];
  acc = (acc + (metric_44 * 2)) & 127;
  int anchor_15 = (aux + st.buffer[1]) & 3;
  switch (anchor_15)
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

  int bound_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_71) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000738_3813_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st_1 = {0};
  struct SensorNode_R000738_3813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_32_1 = local_arr_1[aux_1 % 3];
  int threshold_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_32_2 * 2)) & 127;
  int tracker_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_73_1)
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

  switch (tracker_73_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_32_1 == threshold_32_2);
  assert(tracker_73_1 == tracker_73_2);
}

int fn_R000738_3813_2(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int threshold_32 = local_arr[aux % 3];
  acc = (acc + (threshold_32 * 2)) & 127;
  int tracker_73 = (aux + st.buffer[1]) & 3;
  switch (tracker_73)
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

void fn_R000738_3813_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st_1 = {0};
  struct Transaction_R000738_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int sample_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_92_1) & 63;
  aux_2 = (aux_2 + sample_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_69_1 > 40)
  {
    acc_1 = ((acc_1 + (pivot_69_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_69_2 > 40)
  {
    acc_2 = ((acc_2 + (pivot_69_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_69_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_57_1 = local_arr_1[aux_1 % 3];
  int tally_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_57_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_92_1 == sample_92_2);
  assert(pivot_69_1 == pivot_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_57_1 == tally_57_2);
}

int fn_R000738_3813_3(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int sample_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_92) & 63;
  acc ^= aux;
  int pivot_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_69 > 40)
  {
    acc = ((acc + (pivot_69 * 2)) + 5) & 127;
    aux ^= pivot_69 & 15;
  }
  else
  {
    acc = ((acc - pivot_69) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_57 = local_arr[aux % 3];
  acc = (acc + (tally_57 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000738_3813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st_1 = {0};
  struct StreamBuffer_R000738_3813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int coefficient_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_59_1) & 63;
  aux_2 = (aux_2 + coefficient_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_59_1 == coefficient_59_2);
}

int fn_R000738_3813_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int coefficient_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_59) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000738_3813_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st_1 = {0};
  struct Transaction_R000738_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int vector_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_87_1) & 63;
  aux_2 = (aux_2 + vector_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_96_1)
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

  switch (stride_96_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_87_1 == vector_87_2);
  assert(stride_96_1 == stride_96_2);
}

int fn_R000738_3813_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int vector_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_87) & 63;
  acc ^= aux;
  int stride_96 = (aux + st.buffer[1]) & 3;
  switch (stride_96)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000738_3813_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st_1 = {0};
  struct StreamBuffer_R000738_3813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_18_1 = local_arr_1[aux_1 % 3];
  int metric_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_18_2 * 2)) & 127;
  int mask_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_54_1)
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

  switch (mask_54_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_18_1 == metric_18_2);
  assert(mask_54_1 == mask_54_2);
}

int fn_R000738_3813_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int metric_18 = local_arr[aux % 3];
  acc = (acc + (metric_18 * 2)) & 127;
  int mask_54 = (aux + st.buffer[1]) & 3;
  switch (mask_54)
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

void fn_R000738_3813_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st_1 = {0};
  struct Transaction_R000738_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_40_1 = local_arr_1[aux_1 % 3];
  int stride_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_40_2 * 2)) & 127;
  int delta_73_1 = 0;
  int delta_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_73_1 = ((delta_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_73_2 = ((delta_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_73_1) & 127;
    acc_2 = (acc_2 + delta_73_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_40_1 == stride_40_2);
  assert(delta_73_1 == delta_73_2);
}

int fn_R000738_3813_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int stride_40 = local_arr[aux % 3];
  acc = (acc + (stride_40 * 2)) & 127;
  int delta_73 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_73 = ((delta_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_73) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000738_3813_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st_1 = {0};
  struct StreamBuffer_R000738_3813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_11_1 > 10)
  {
    acc_1 = ((acc_1 + (anchor_11_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_11_2 > 10)
  {
    acc_2 = ((acc_2 + (anchor_11_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_22_1 = local_arr_1[aux_1 % 3];
  int phase_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_22_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_11_1 == anchor_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_22_1 == phase_22_2);
}

int fn_R000738_3813_8(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_11 > 10)
  {
    acc = ((acc + (anchor_11 * 2)) + 5) & 127;
    aux ^= anchor_11 & 15;
  }
  else
  {
    acc = ((acc - anchor_11) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_22 = local_arr[aux % 3];
  acc = (acc + (phase_22 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000738_3813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st_1 = {0};
  struct StreamBuffer_R000738_3813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int tally_47_1 = 0;
  int tally_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_47_1 = ((tally_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_47_2 = ((tally_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_47_1) & 127;
    acc_2 = (acc_2 + tally_47_2) & 127;
  }

  int metric_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_73_1)
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

  switch (metric_73_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_47_1 == tally_47_2);
  assert(metric_73_1 == metric_73_2);
}

int fn_R000738_3813_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int tally_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_47 = ((tally_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_47) & 127;
  }

  int metric_73 = (aux + st.buffer[1]) & 3;
  switch (metric_73)
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

void fn_R000738_3813_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st_1 = {0};
  struct SensorNode_R000738_3813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_37_1 = local_arr_1[aux_1 % 3];
  int scale_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_37_1 == scale_37_2);
}

int fn_R000738_3813_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_37 = local_arr[aux % 3];
  acc = (acc + (scale_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000738_3813_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st_1 = {0};
  struct Transaction_R000738_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int coefficient_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_52_1) & 63;
  aux_2 = (aux_2 + coefficient_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_92_1)
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

  switch (index_reg_92_2)
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

  int vector_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_23_1 > 22)
  {
    acc_1 = ((acc_1 + (vector_23_1 * 2)) + 5) & 127;
    aux_1 ^= vector_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_23_2 > 22)
  {
    acc_2 = ((acc_2 + (vector_23_2 * 2)) + 5) & 127;
    aux_2 ^= vector_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_65_1 = local_arr_1[aux_1 % 3];
  int factor_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_65_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_52_1 == coefficient_52_2);
  assert(index_reg_92_1 == index_reg_92_2);
  assert(vector_23_1 == vector_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_65_1 == factor_65_2);
}

int fn_R000738_3813_11(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int coefficient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_52) & 63;
  acc ^= aux;
  int index_reg_92 = (aux + st.buffer[1]) & 3;
  switch (index_reg_92)
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

  int vector_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_23 > 22)
  {
    acc = ((acc + (vector_23 * 2)) + 5) & 127;
    aux ^= vector_23 & 15;
  }
  else
  {
    acc = ((acc - vector_23) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_65 = local_arr[aux % 3];
  acc = (acc + (factor_65 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000738_3813_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st_1 = {0};
  struct Transaction_R000738_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int phase_20_1 = 0;
  int phase_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_20_1 = ((phase_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_20_2 = ((phase_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_20_1) & 127;
    acc_2 = (acc_2 + phase_20_2) & 127;
  }

  int margin_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_22_1)
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

  switch (margin_22_2)
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

  int accumulator_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_42_1) & 63;
  aux_2 = (aux_2 + accumulator_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_20_1 == phase_20_2);
  assert(margin_22_1 == margin_22_2);
  assert(accumulator_42_1 == accumulator_42_2);
}

int fn_R000738_3813_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int phase_20 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_20 = ((phase_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_20) & 127;
  }

  int margin_22 = (aux + st.buffer[1]) & 3;
  switch (margin_22)
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

  int accumulator_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000738_3813_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st_1 = {0};
  struct SensorNode_R000738_3813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_55_1 = local_arr_1[aux_1 % 3];
  int cursor_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_55_2 * 2)) & 127;
  int pivot_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_16_1 > 27)
  {
    acc_1 = ((acc_1 + (pivot_16_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_16_2 > 27)
  {
    acc_2 = ((acc_2 + (pivot_16_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_75_1) & 63;
  aux_2 = (aux_2 + threshold_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_28_1 = 0;
  int tally_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_28_1 = ((tally_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_28_2 = ((tally_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_28_1) & 127;
    acc_2 = (acc_2 + tally_28_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_55_1 == cursor_55_2);
  assert(pivot_16_1 == pivot_16_2);
  assert(threshold_75_1 == threshold_75_2);
  assert(tally_28_1 == tally_28_2);
}

int fn_R000738_3813_13(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int cursor_55 = local_arr[aux % 3];
  acc = (acc + (cursor_55 * 2)) & 127;
  int pivot_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_16 > 27)
  {
    acc = ((acc + (pivot_16 * 2)) + 5) & 127;
    aux ^= pivot_16 & 15;
  }
  else
  {
    acc = ((acc - pivot_16) + 11) & 127;
    aux += 3;
  }
  int threshold_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_75) & 63;
  acc ^= aux;
  int tally_28 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_28 = ((tally_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_28) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000738_3813_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st_1 = {0};
  struct SensorNode_R000738_3813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_76_1 = local_arr_1[aux_1 % 3];
  int accumulator_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_76_2 * 2)) & 127;
  int vector_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_39_1) & 63;
  aux_2 = (aux_2 + vector_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_76_1 == accumulator_76_2);
  assert(vector_39_1 == vector_39_2);
}

int fn_R000738_3813_14(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int accumulator_76 = local_arr[aux % 3];
  acc = (acc + (accumulator_76 * 2)) & 127;
  int vector_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000738_3813_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st_1 = {0};
  struct Transaction_R000738_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_29_1 = local_arr_1[aux_1 % 3];
  int mask_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_29_2 * 2)) & 127;
  int quantum_22_1 = 0;
  int quantum_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_22_1 = ((quantum_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_22_2 = ((quantum_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_22_1) & 127;
    acc_2 = (acc_2 + quantum_22_2) & 127;
  }

  int anchor_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_51_1)
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

  switch (anchor_51_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_29_1 == mask_29_2);
  assert(quantum_22_1 == quantum_22_2);
  assert(anchor_51_1 == anchor_51_2);
}

int fn_R000738_3813_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_29 = local_arr[aux % 3];
  acc = (acc + (mask_29 * 2)) & 127;
  int quantum_22 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_22 = ((quantum_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_22) & 127;
  }

  int anchor_51 = (aux + st.buffer[1]) & 3;
  switch (anchor_51)
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

void fn_R000738_3813_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st_1 = {0};
  struct Transaction_R000738_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int weight_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_70_1) & 63;
  aux_2 = (aux_2 + weight_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_83_1 > 25)
  {
    acc_1 = ((acc_1 + (anchor_83_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_83_2 > 25)
  {
    acc_2 = ((acc_2 + (anchor_83_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_70_1 == weight_70_2);
  assert(anchor_83_1 == anchor_83_2);
}

int fn_R000738_3813_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int weight_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_83 > 25)
  {
    acc = ((acc + (anchor_83 * 2)) + 5) & 127;
    aux ^= anchor_83 & 15;
  }
  else
  {
    acc = ((acc - anchor_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000738_3813_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st_1 = {0};
  struct StreamBuffer_R000738_3813_1 st_2 = {0};
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
  int weight_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_50_1 > 35)
  {
    acc_1 = ((acc_1 + (weight_50_1 * 2)) + 5) & 127;
    aux_1 ^= weight_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_50_2 > 35)
  {
    acc_2 = ((acc_2 + (weight_50_2 * 2)) + 5) & 127;
    aux_2 ^= weight_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_18_1 = local_arr_1[aux_1 % 3];
  int factor_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_18_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_50_1 == weight_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_18_1 == factor_18_2);
}

int fn_R000738_3813_17(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_50 > 35)
  {
    acc = ((acc + (weight_50 * 2)) + 5) & 127;
    aux ^= weight_50 & 15;
  }
  else
  {
    acc = ((acc - weight_50) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_18 = local_arr[aux % 3];
  acc = (acc + (factor_18 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000738_3813_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st_1 = {0};
  struct Transaction_R000738_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_76_1 = local_arr_1[aux_1 % 3];
  int tally_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_76_2 * 2)) & 127;
  int damping_72_1 = 0;
  int damping_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_72_1 = ((damping_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_72_2 = ((damping_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_72_1) & 127;
    acc_2 = (acc_2 + damping_72_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_76_1 == tally_76_2);
  assert(damping_72_1 == damping_72_2);
}

int fn_R000738_3813_18(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_76 = local_arr[aux % 3];
  acc = (acc + (tally_76 * 2)) & 127;
  int damping_72 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_72 = ((damping_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_72) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000738_3813_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st_1 = {0};
  struct Transaction_R000738_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_12_1)
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

  switch (bound_12_2)
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

  int tracker_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_10_1) & 63;
  aux_2 = (aux_2 + tracker_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_94_1 > 18)
  {
    acc_1 = ((acc_1 + (tracker_94_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_94_2 > 18)
  {
    acc_2 = ((acc_2 + (tracker_94_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_12_1 == bound_12_2);
  assert(tracker_10_1 == tracker_10_2);
  assert(tracker_94_1 == tracker_94_2);
}

int fn_R000738_3813_19(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_12 = (aux + st.buffer[1]) & 3;
  switch (bound_12)
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

  int tracker_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_10) & 63;
  acc ^= aux;
  int tracker_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_94 > 18)
  {
    acc = ((acc + (tracker_94 * 2)) + 5) & 127;
    aux ^= tracker_94 & 15;
  }
  else
  {
    acc = ((acc - tracker_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000738_3813_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st_1 = {0};
  struct Transaction_R000738_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_82_1 = local_arr_1[aux_1 % 3];
  int factor_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_82_2 * 2)) & 127;
  int delta_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_89_1 > 19)
  {
    acc_1 = ((acc_1 + (delta_89_1 * 2)) + 5) & 127;
    aux_1 ^= delta_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_89_2 > 19)
  {
    acc_2 = ((acc_2 + (delta_89_2 * 2)) + 5) & 127;
    aux_2 ^= delta_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_16_1)
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

  switch (factor_16_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_82_1 == factor_82_2);
  assert(delta_89_1 == delta_89_2);
  assert(factor_16_1 == factor_16_2);
}

int fn_R000738_3813_20(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int factor_82 = local_arr[aux % 3];
  acc = (acc + (factor_82 * 2)) & 127;
  int delta_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_89 > 19)
  {
    acc = ((acc + (delta_89 * 2)) + 5) & 127;
    aux ^= delta_89 & 15;
  }
  else
  {
    acc = ((acc - delta_89) + 11) & 127;
    aux += 3;
  }
  int factor_16 = (aux + st.buffer[1]) & 3;
  switch (factor_16)
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

void fn_R000738_3813_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st_1 = {0};
  struct SensorNode_R000738_3813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tally_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_21_1 > 39)
  {
    acc_1 = ((acc_1 + (tally_21_1 * 2)) + 5) & 127;
    aux_1 ^= tally_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_21_2 > 39)
  {
    acc_2 = ((acc_2 + (tally_21_2 * 2)) + 5) & 127;
    aux_2 ^= tally_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_21_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_47_1) & 63;
  aux_2 = (aux_2 + pivot_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_21_1 == tally_21_2);
  assert(pivot_47_1 == pivot_47_2);
}

int fn_R000738_3813_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000738_3813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tally_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_21 > 39)
  {
    acc = ((acc + (tally_21 * 2)) + 5) & 127;
    aux ^= tally_21 & 15;
  }
  else
  {
    acc = ((acc - tally_21) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000738_3813_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st_1 = {0};
  struct Transaction_R000738_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int sample_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_59_1 > 24)
  {
    acc_1 = ((acc_1 + (sample_59_1 * 2)) + 5) & 127;
    aux_1 ^= sample_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_59_2 > 24)
  {
    acc_2 = ((acc_2 + (sample_59_2 * 2)) + 5) & 127;
    aux_2 ^= sample_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_59_2) + 11) & 127;
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
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_59_1 == sample_59_2);
  assert(vector_21_1 == vector_21_2);
}

int fn_R000738_3813_22(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000738_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int sample_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_59 > 24)
  {
    acc = ((acc + (sample_59 * 2)) + 5) & 127;
    aux ^= sample_59 & 15;
  }
  else
  {
    acc = ((acc - sample_59) + 11) & 127;
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

void fn_R000738_3813_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st_1 = {0};
  struct StreamBuffer_R000738_3813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_16_1)
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

  switch (factor_16_2)
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

  int vector_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_32_1) & 63;
  aux_2 = (aux_2 + vector_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_82_1 > 33)
  {
    acc_1 = ((acc_1 + (mask_82_1 * 2)) + 5) & 127;
    aux_1 ^= mask_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_82_2 > 33)
  {
    acc_2 = ((acc_2 + (mask_82_2 * 2)) + 5) & 127;
    aux_2 ^= mask_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_16_1 == factor_16_2);
  assert(vector_32_1 == vector_32_2);
  assert(mask_82_1 == mask_82_2);
}

int fn_R000738_3813_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000738_3813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_16 = (aux + st.buffer[1]) & 3;
  switch (factor_16)
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

  int vector_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_32) & 63;
  acc ^= aux;
  int mask_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_82 > 33)
  {
    acc = ((acc + (mask_82 * 2)) + 5) & 127;
    aux ^= mask_82 & 15;
  }
  else
  {
    acc = ((acc - mask_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000738_0_1;
  int sec_r000738_0_2;
  int sec_r000738_1_1;
  int sec_r000738_1_2;
  int sec_r000738_2_1;
  int sec_r000738_2_2;
  int sec_r000738_3_1;
  int sec_r000738_3_2;
  int sec_r000738_4_1;
  int sec_r000738_4_2;
  int sec_r000738_5_1;
  int sec_r000738_5_2;
  int sec_r000738_6_1;
  int sec_r000738_6_2;
  int sec_r000738_7_1;
  int sec_r000738_7_2;
  int sec_r000738_8_1;
  int sec_r000738_8_2;
  int sec_r000738_9_1;
  int sec_r000738_9_2;
  int sec_r000738_10_1;
  int sec_r000738_10_2;
  int sec_r000738_11_1;
  int sec_r000738_11_2;
  int sec_r000738_12_1;
  int sec_r000738_12_2;
  int sec_r000738_13_1;
  int sec_r000738_13_2;
  int sec_r000738_14_1;
  int sec_r000738_14_2;
  int sec_r000738_15_1;
  int sec_r000738_15_2;
  int sec_r000738_16_1;
  int sec_r000738_16_2;
  int sec_r000738_17_1;
  int sec_r000738_17_2;
  int sec_r000738_18_1;
  int sec_r000738_18_2;
  int sec_r000738_19_1;
  int sec_r000738_19_2;
  int sec_r000738_20_1;
  int sec_r000738_20_2;
  int sec_r000738_21_1;
  int sec_r000738_21_2;
  int pub_r000738_0_1;
  int pub_r000738_0_2;
  int pub_r000738_1_1;
  int pub_r000738_1_2;
  int pub_r000738_2_1;
  int pub_r000738_2_2;
  int pub_r000738_3_1;
  int pub_r000738_3_2;
  int pub_r000738_4_1;
  int pub_r000738_4_2;
  int pub_r000738_5_1;
  int pub_r000738_5_2;
  int pub_r000738_6_1;
  int pub_r000738_6_2;
  int pub_r000738_7_1;
  int pub_r000738_7_2;
  int pub_r000738_8_1;
  int pub_r000738_8_2;
  int pub_r000738_9_1;
  int pub_r000738_9_2;
  int pub_r000738_10_1;
  int pub_r000738_10_2;
  int pub_r000738_11_1;
  int pub_r000738_11_2;
  int pub_r000738_12_1;
  int pub_r000738_12_2;
  int pub_r000738_13_1;
  int pub_r000738_13_2;
  int pub_r000738_14_1;
  int pub_r000738_14_2;
  int pub_r000738_15_1;
  int pub_r000738_15_2;
  int pub_r000738_16_1;
  int pub_r000738_16_2;
  int pub_r000738_17_1;
  int pub_r000738_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000738_0_1 >= (-100)) && (pub_r000738_0_1 <= 100));
  __CPROVER_assume((pub_r000738_0_2 >= (-100)) && (pub_r000738_0_2 <= 100));
  __CPROVER_assume((pub_r000738_1_1 >= (-100)) && (pub_r000738_1_1 <= 100));
  __CPROVER_assume((pub_r000738_1_2 >= (-100)) && (pub_r000738_1_2 <= 100));
  __CPROVER_assume((pub_r000738_2_1 >= (-100)) && (pub_r000738_2_1 <= 100));
  __CPROVER_assume((pub_r000738_2_2 >= (-100)) && (pub_r000738_2_2 <= 100));
  __CPROVER_assume((pub_r000738_3_1 >= (-100)) && (pub_r000738_3_1 <= 100));
  __CPROVER_assume((pub_r000738_3_2 >= (-100)) && (pub_r000738_3_2 <= 100));
  __CPROVER_assume((pub_r000738_4_1 >= (-100)) && (pub_r000738_4_1 <= 100));
  __CPROVER_assume((pub_r000738_4_2 >= (-100)) && (pub_r000738_4_2 <= 100));
  __CPROVER_assume((pub_r000738_5_1 >= (-100)) && (pub_r000738_5_1 <= 100));
  __CPROVER_assume((pub_r000738_5_2 >= (-100)) && (pub_r000738_5_2 <= 100));
  __CPROVER_assume((pub_r000738_6_1 >= (-100)) && (pub_r000738_6_1 <= 100));
  __CPROVER_assume((pub_r000738_6_2 >= (-100)) && (pub_r000738_6_2 <= 100));
  __CPROVER_assume((pub_r000738_7_1 >= (-100)) && (pub_r000738_7_1 <= 100));
  __CPROVER_assume((pub_r000738_7_2 >= (-100)) && (pub_r000738_7_2 <= 100));
  __CPROVER_assume((pub_r000738_8_1 >= (-100)) && (pub_r000738_8_1 <= 100));
  __CPROVER_assume((pub_r000738_8_2 >= (-100)) && (pub_r000738_8_2 <= 100));
  __CPROVER_assume((pub_r000738_9_1 >= (-100)) && (pub_r000738_9_1 <= 100));
  __CPROVER_assume((pub_r000738_9_2 >= (-100)) && (pub_r000738_9_2 <= 100));
  __CPROVER_assume((pub_r000738_10_1 >= (-100)) && (pub_r000738_10_1 <= 100));
  __CPROVER_assume((pub_r000738_10_2 >= (-100)) && (pub_r000738_10_2 <= 100));
  __CPROVER_assume((pub_r000738_11_1 >= (-100)) && (pub_r000738_11_1 <= 100));
  __CPROVER_assume((pub_r000738_11_2 >= (-100)) && (pub_r000738_11_2 <= 100));
  __CPROVER_assume((pub_r000738_12_1 >= (-100)) && (pub_r000738_12_1 <= 100));
  __CPROVER_assume((pub_r000738_12_2 >= (-100)) && (pub_r000738_12_2 <= 100));
  __CPROVER_assume((pub_r000738_13_1 >= (-100)) && (pub_r000738_13_1 <= 100));
  __CPROVER_assume((pub_r000738_13_2 >= (-100)) && (pub_r000738_13_2 <= 100));
  __CPROVER_assume((pub_r000738_14_1 >= (-100)) && (pub_r000738_14_1 <= 100));
  __CPROVER_assume((pub_r000738_14_2 >= (-100)) && (pub_r000738_14_2 <= 100));
  __CPROVER_assume((pub_r000738_15_1 >= (-100)) && (pub_r000738_15_1 <= 100));
  __CPROVER_assume((pub_r000738_15_2 >= (-100)) && (pub_r000738_15_2 <= 100));
  __CPROVER_assume((pub_r000738_16_1 >= (-100)) && (pub_r000738_16_1 <= 100));
  __CPROVER_assume((pub_r000738_16_2 >= (-100)) && (pub_r000738_16_2 <= 100));
  __CPROVER_assume((pub_r000738_17_1 >= (-100)) && (pub_r000738_17_1 <= 100));
  __CPROVER_assume((pub_r000738_17_2 >= (-100)) && (pub_r000738_17_2 <= 100));
  __CPROVER_assume((sec_r000738_0_1 >= 0) && (sec_r000738_0_1 <= 255));
  __CPROVER_assume((sec_r000738_0_2 >= 0) && (sec_r000738_0_2 <= 255));
  __CPROVER_assume((sec_r000738_1_1 >= 0) && (sec_r000738_1_1 <= 255));
  __CPROVER_assume((sec_r000738_1_2 >= 0) && (sec_r000738_1_2 <= 255));
  __CPROVER_assume((sec_r000738_2_1 >= 0) && (sec_r000738_2_1 <= 255));
  __CPROVER_assume((sec_r000738_2_2 >= 0) && (sec_r000738_2_2 <= 255));
  __CPROVER_assume((sec_r000738_3_1 >= 0) && (sec_r000738_3_1 <= 255));
  __CPROVER_assume((sec_r000738_3_2 >= 0) && (sec_r000738_3_2 <= 255));
  __CPROVER_assume((sec_r000738_4_1 >= 0) && (sec_r000738_4_1 <= 255));
  __CPROVER_assume((sec_r000738_4_2 >= 0) && (sec_r000738_4_2 <= 255));
  __CPROVER_assume((sec_r000738_5_1 >= 0) && (sec_r000738_5_1 <= 255));
  __CPROVER_assume((sec_r000738_5_2 >= 0) && (sec_r000738_5_2 <= 255));
  __CPROVER_assume((sec_r000738_6_1 >= 0) && (sec_r000738_6_1 <= 255));
  __CPROVER_assume((sec_r000738_6_2 >= 0) && (sec_r000738_6_2 <= 255));
  __CPROVER_assume((sec_r000738_7_1 >= 0) && (sec_r000738_7_1 <= 255));
  __CPROVER_assume((sec_r000738_7_2 >= 0) && (sec_r000738_7_2 <= 255));
  __CPROVER_assume((sec_r000738_8_1 >= 0) && (sec_r000738_8_1 <= 255));
  __CPROVER_assume((sec_r000738_8_2 >= 0) && (sec_r000738_8_2 <= 255));
  __CPROVER_assume((sec_r000738_9_1 >= 0) && (sec_r000738_9_1 <= 255));
  __CPROVER_assume((sec_r000738_9_2 >= 0) && (sec_r000738_9_2 <= 255));
  __CPROVER_assume((sec_r000738_10_1 >= 0) && (sec_r000738_10_1 <= 255));
  __CPROVER_assume((sec_r000738_10_2 >= 0) && (sec_r000738_10_2 <= 255));
  __CPROVER_assume((sec_r000738_11_1 >= 0) && (sec_r000738_11_1 <= 255));
  __CPROVER_assume((sec_r000738_11_2 >= 0) && (sec_r000738_11_2 <= 255));
  __CPROVER_assume((sec_r000738_12_1 >= 0) && (sec_r000738_12_1 <= 255));
  __CPROVER_assume((sec_r000738_12_2 >= 0) && (sec_r000738_12_2 <= 255));
  __CPROVER_assume((sec_r000738_13_1 >= 0) && (sec_r000738_13_1 <= 255));
  __CPROVER_assume((sec_r000738_13_2 >= 0) && (sec_r000738_13_2 <= 255));
  __CPROVER_assume((sec_r000738_14_1 >= 0) && (sec_r000738_14_1 <= 255));
  __CPROVER_assume((sec_r000738_14_2 >= 0) && (sec_r000738_14_2 <= 255));
  __CPROVER_assume((sec_r000738_15_1 >= 0) && (sec_r000738_15_1 <= 255));
  __CPROVER_assume((sec_r000738_15_2 >= 0) && (sec_r000738_15_2 <= 255));
  __CPROVER_assume((sec_r000738_16_1 >= 0) && (sec_r000738_16_1 <= 255));
  __CPROVER_assume((sec_r000738_16_2 >= 0) && (sec_r000738_16_2 <= 255));
  __CPROVER_assume((sec_r000738_17_1 >= 0) && (sec_r000738_17_1 <= 255));
  __CPROVER_assume((sec_r000738_17_2 >= 0) && (sec_r000738_17_2 <= 255));
  __CPROVER_assume((sec_r000738_18_1 >= 0) && (sec_r000738_18_1 <= 255));
  __CPROVER_assume((sec_r000738_18_2 >= 0) && (sec_r000738_18_2 <= 255));
  __CPROVER_assume((sec_r000738_19_1 >= 0) && (sec_r000738_19_1 <= 255));
  __CPROVER_assume((sec_r000738_19_2 >= 0) && (sec_r000738_19_2 <= 255));
  __CPROVER_assume((sec_r000738_20_1 >= 0) && (sec_r000738_20_1 <= 255));
  __CPROVER_assume((sec_r000738_20_2 >= 0) && (sec_r000738_20_2 <= 255));
  __CPROVER_assume((sec_r000738_21_1 >= 0) && (sec_r000738_21_1 <= 255));
  __CPROVER_assume((sec_r000738_21_2 >= 0) && (sec_r000738_21_2 <= 255));
  struct Transaction_R000738_3813_0 st_var_0_1 = {0};
  struct Transaction_R000738_3813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000738_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000738_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000738_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000738_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000738_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000738_0_2 + 7) & 15;
  struct StreamBuffer_R000738_3813_1 st_var_1_1 = {0};
  struct StreamBuffer_R000738_3813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000738_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000738_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000738_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000738_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000738_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000738_0_2 + 9) & 15;
  struct SensorNode_R000738_3813_2 st_var_2_1 = {0};
  struct SensorNode_R000738_3813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000738_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000738_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000738_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000738_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000738_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000738_0_2 + 11) & 15;
  union RegisterBank_R000738_3813_0 u_var_1;
  union RegisterBank_R000738_3813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = table_1[0];
  int stage_v_0_2 = table_2[0];
  table_1[0] = (table_1[1] + 1) & 63;
  table_2[0] = (table_2[1] + 1) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = ((st_var_0_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_0_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 35)
    {
      chk_sum_1 ^= stage_v_3_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_3_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 35)
    {
      chk_sum_2 ^= stage_v_3_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = (st_var_2_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_2_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 33)
    {
      chk_sum_1 ^= stage_v_6_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_6_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 33)
    {
      chk_sum_2 ^= stage_v_6_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = (st_var_1_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_1_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 12) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 15) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
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

  int stage_v_16_1 = (st_var_1_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_1_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = (st_var_2_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_2_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 48)
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
  if (stage_v_18_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 48)
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
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = ((st_var_1_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_1_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 49)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 49)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 29) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = ((st_var_2_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_2_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 31)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 31)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = (st_var_2_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_2_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 25)
    {
      chk_sum_1 ^= stage_v_38_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_38_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 25)
    {
      chk_sum_2 ^= stage_v_38_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 40) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (47 & 31);
  int stage_v_42_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (47 & 31);
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= (stage_v_42_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_42_2 << 1) & 127;
  int stage_v_43_1 = ((st_var_1_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_1_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 47)
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
  if (stage_v_43_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 47)
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
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (st_var_1_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_1_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
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

  switch (stage_v_46_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 48) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 48) & 15;
  int stage_v_47_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_47_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= stage_v_47_1;
  chk_sum_2 ^= stage_v_47_2;
  int stage_v_48_1 = (st_var_0_1.buffer[0] ^ 51) & 3;
  int stage_v_48_2 = (st_var_0_2.buffer[0] ^ 51) & 3;
  switch (stage_v_48_1)
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

  switch (stage_v_48_2)
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

  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 43)
    {
      chk_sum_1 ^= stage_v_49_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_49_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 43)
    {
      chk_sum_2 ^= stage_v_49_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (st_var_0_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_0_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
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
  if (stage_v_54_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 51)
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
  if (stage_v_54_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 51)
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
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((st_var_2_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_2_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 29)
    {
      chk_sum_1 ^= stage_v_56_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_56_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 29)
    {
      chk_sum_2 ^= stage_v_56_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_57_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_57_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_58_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (63 & 31);
  int stage_v_58_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (63 & 31);
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= (stage_v_58_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_58_2 << 1) & 127;
  int stage_v_59_1 = ((st_var_2_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_2_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 31)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 31)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = (st_var_0_1.buffer[0] ^ 63) & 3;
  int stage_v_60_2 = (st_var_0_2.buffer[0] ^ 63) & 3;
  switch (stage_v_60_1)
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

  switch (stage_v_60_2)
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

  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
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
  int stage_v_67_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (72 & 31);
  int stage_v_67_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (72 & 31);
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= (stage_v_67_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_67_2 << 1) & 127;
  int stage_v_68_1 = table_1[0];
  int stage_v_68_2 = table_2[0];
  table_1[0] = (table_1[1] + 137) & 63;
  table_2[0] = (table_2[1] + 137) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (76 & 31);
  int stage_v_71_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (76 & 31);
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= (stage_v_71_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_71_2 << 1) & 127;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 48)
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
  if (stage_v_72_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 48)
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
  int stage_v_73_1 = (st_var_1_1.buffer[0] ^ 76) & 3;
  int stage_v_73_2 = (st_var_1_2.buffer[0] ^ 76) & 3;
  switch (stage_v_73_1)
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

  switch (stage_v_73_2)
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

  int stage_v_74_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (79 & 31);
  int stage_v_74_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (79 & 31);
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= (stage_v_74_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_74_2 << 1) & 127;
  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 77) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = table_1[3];
  int stage_v_79_2 = table_2[3];
  table_1[3] = (table_1[0] + 159) & 63;
  table_2[3] = (table_2[0] + 159) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = table_1[0];
  int stage_v_80_2 = table_2[0];
  table_1[0] = (table_1[1] + 161) & 63;
  table_2[0] = (table_2[1] + 161) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = table_1[1];
  int stage_v_81_2 = table_2[1];
  table_1[1] = (table_1[2] + 163) & 63;
  table_2[1] = (table_2[2] + 163) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_82_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_85_1 = (st_var_1_1.buffer[0] ^ 88) & 3;
  int stage_v_85_2 = (st_var_1_2.buffer[0] ^ 88) & 3;
  switch (stage_v_85_1)
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

  switch (stage_v_85_2)
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

  int stage_v_86_1 = (st_var_2_1.buffer[0] ^ 89) & 3;
  int stage_v_86_2 = (st_var_2_2.buffer[0] ^ 89) & 3;
  switch (stage_v_86_1)
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

  switch (stage_v_86_2)
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

  int stage_v_87_1 = table_1[3];
  int stage_v_87_2 = table_2[3];
  table_1[3] = (table_1[0] + 175) & 63;
  table_2[3] = (table_2[0] + 175) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 89) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 89) & 15;
  int stage_v_88_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_88_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= stage_v_88_1;
  chk_sum_2 ^= stage_v_88_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 90) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 90) & 15;
  int stage_v_89_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_89_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= stage_v_89_1;
  chk_sum_2 ^= stage_v_89_2;
  int stage_v_90_1 = (st_var_0_1.buffer[0] ^ 93) & 3;
  int stage_v_90_2 = (st_var_0_2.buffer[0] ^ 93) & 3;
  switch (stage_v_90_1)
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

  switch (stage_v_90_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 92) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 92) & 15;
  int stage_v_91_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_91_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= stage_v_91_1;
  chk_sum_2 ^= stage_v_91_2;
  int stage_v_92_1 = ((st_var_2_1.buffer[2] * 2) + 283) & 63;
  int stage_v_92_2 = ((st_var_2_2.buffer[2] * 2) + 283) & 63;
  if (stage_v_92_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_92_1) - 5) & 255;
    if (stage_v_92_1 > 30)
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
  if (stage_v_92_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_92_2) - 5) & 255;
    if (stage_v_92_2 > 30)
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
  int stage_v_93_1 = (st_var_0_1.buffer[0] ^ 96) & 3;
  int stage_v_93_2 = (st_var_0_2.buffer[0] ^ 96) & 3;
  switch (stage_v_93_1)
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

  switch (stage_v_93_2)
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

  int stage_v_94_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (99 & 31);
  int stage_v_94_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (99 & 31);
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  chk_sum_1 ^= (stage_v_94_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_94_2 << 1) & 127;
  int stage_v_95_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (100 & 31);
  int stage_v_95_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (100 & 31);
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= (stage_v_95_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_95_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 97) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 97) & 15;
  int stage_v_96_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_96_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= stage_v_96_1;
  chk_sum_2 ^= stage_v_96_2;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = table_1[2];
  int stage_v_98_2 = table_2[2];
  table_1[2] = (table_1[3] + 197) & 63;
  table_2[2] = (table_2[3] + 197) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 101) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 101) & 15;
  int stage_v_100_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_100_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= stage_v_100_1;
  chk_sum_2 ^= stage_v_100_2;
  int stage_v_101_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (106 & 31);
  int stage_v_101_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (106 & 31);
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= (stage_v_101_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_101_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 103) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 103) & 15;
  int stage_v_102_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_102_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= stage_v_102_1;
  chk_sum_2 ^= stage_v_102_2;
  int stage_v_103_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (108 & 31);
  int stage_v_103_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (108 & 31);
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= (stage_v_103_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_103_2 << 1) & 127;
  int stage_v_104_1 = ((st_var_2_1.buffer[2] * 2) + 319) & 63;
  int stage_v_104_2 = ((st_var_2_2.buffer[2] * 2) + 319) & 63;
  if (stage_v_104_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_104_1) - 5) & 255;
    if (stage_v_104_1 > 43)
    {
      chk_sum_1 ^= stage_v_104_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_104_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_104_2) - 5) & 255;
    if (stage_v_104_2 > 43)
    {
      chk_sum_2 ^= stage_v_104_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 106) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 106) & 15;
  int stage_v_105_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_105_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= stage_v_105_1;
  chk_sum_2 ^= stage_v_105_2;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_106_1 = ((stage_v_106_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_106_2 = ((stage_v_106_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 109) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 109) & 15;
  int stage_v_108_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_108_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  chk_sum_1 ^= stage_v_108_1;
  chk_sum_2 ^= stage_v_108_2;
  int stage_v_109_1 = (st_var_1_1.buffer[0] ^ 112) & 3;
  int stage_v_109_2 = (st_var_1_2.buffer[0] ^ 112) & 3;
  switch (stage_v_109_1)
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

  switch (stage_v_109_2)
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

  int stage_v_110_1 = ((st_var_2_1.buffer[2] * 2) + 337) & 63;
  int stage_v_110_2 = ((st_var_2_2.buffer[2] * 2) + 337) & 63;
  if (stage_v_110_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_110_1) - 5) & 255;
    if (stage_v_110_1 > 33)
    {
      chk_sum_1 ^= stage_v_110_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_110_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_110_2) - 5) & 255;
    if (stage_v_110_2 > 33)
    {
      chk_sum_2 ^= stage_v_110_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 112) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 112) & 15;
  int stage_v_111_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_111_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  chk_sum_1 ^= stage_v_111_1;
  chk_sum_2 ^= stage_v_111_2;
  int stage_v_112_1 = ((st_var_1_1.buffer[1] * 2) + 343) & 63;
  int stage_v_112_2 = ((st_var_1_2.buffer[1] * 2) + 343) & 63;
  if (stage_v_112_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_112_1) - 5) & 255;
    if (stage_v_112_1 > 35)
    {
      chk_sum_1 ^= stage_v_112_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_112_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_112_2) - 5) & 255;
    if (stage_v_112_2 > 35)
    {
      chk_sum_2 ^= stage_v_112_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_113_1 = ((st_var_2_1.buffer[2] * 2) + 346) & 63;
  int stage_v_113_2 = ((st_var_2_2.buffer[2] * 2) + 346) & 63;
  if (stage_v_113_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_113_1) - 5) & 255;
    if (stage_v_113_1 > 49)
    {
      chk_sum_1 ^= stage_v_113_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_113_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_113_2) - 5) & 255;
    if (stage_v_113_2 > 49)
    {
      chk_sum_2 ^= stage_v_113_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 115) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 115) & 15;
  int stage_v_114_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_114_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= stage_v_114_1;
  chk_sum_2 ^= stage_v_114_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 116) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 116) & 15;
  int stage_v_115_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_115_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  chk_sum_1 ^= stage_v_115_1;
  chk_sum_2 ^= stage_v_115_2;
  int stage_v_116_1 = (st_var_2_1.buffer[0] ^ 119) & 3;
  int stage_v_116_2 = (st_var_2_2.buffer[0] ^ 119) & 3;
  switch (stage_v_116_1)
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

  switch (stage_v_116_2)
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

  int stage_v_117_1 = (st_var_0_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_0_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  int stage_v_118_1 = table_1[2];
  int stage_v_118_2 = table_2[2];
  table_1[2] = (table_1[3] + 237) & 63;
  table_2[2] = (table_2[3] + 237) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (st_var_2_1.buffer[0] ^ 122) & 3;
  int stage_v_119_2 = (st_var_2_2.buffer[0] ^ 122) & 3;
  switch (stage_v_119_1)
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

  switch (stage_v_119_2)
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

  int stage_v_120_1 = ((st_var_0_1.buffer[0] * 2) + 367) & 63;
  int stage_v_120_2 = ((st_var_0_2.buffer[0] * 2) + 367) & 63;
  if (stage_v_120_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_120_1) - 5) & 255;
    if (stage_v_120_1 > 53)
    {
      chk_sum_1 ^= stage_v_120_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_120_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_120_2) - 5) & 255;
    if (stage_v_120_2 > 53)
    {
      chk_sum_2 ^= stage_v_120_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_121_1 = table_1[1];
  int stage_v_121_2 = table_2[1];
  table_1[1] = (table_1[2] + 243) & 63;
  table_2[1] = (table_2[2] + 243) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_122_1 = ((stage_v_122_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_122_2 = ((stage_v_122_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = table_1[3];
  int stage_v_123_2 = table_2[3];
  table_1[3] = (table_1[0] + 247) & 63;
  table_2[3] = (table_2[0] + 247) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((st_var_1_1.buffer[1] * 2) + 379) & 63;
  int stage_v_124_2 = ((st_var_1_2.buffer[1] * 2) + 379) & 63;
  if (stage_v_124_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_124_1) - 5) & 255;
    if (stage_v_124_1 > 35)
    {
      chk_sum_1 ^= stage_v_124_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_124_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_124_2) - 5) & 255;
    if (stage_v_124_2 > 35)
    {
      chk_sum_2 ^= stage_v_124_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_125_1 = (st_var_2_1.buffer[0] ^ 128) & 3;
  int stage_v_125_2 = (st_var_2_2.buffer[0] ^ 128) & 3;
  switch (stage_v_125_1)
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

  switch (stage_v_125_2)
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

  int stage_v_126_1 = (st_var_0_1.buffer[0] ^ 129) & 3;
  int stage_v_126_2 = (st_var_0_2.buffer[0] ^ 129) & 3;
  switch (stage_v_126_1)
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

  switch (stage_v_126_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 128) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 128) & 15;
  int stage_v_127_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_127_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= stage_v_127_1;
  chk_sum_2 ^= stage_v_127_2;
  int stage_v_128_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_128_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 130) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 130) & 15;
  int stage_v_129_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_129_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  chk_sum_1 ^= stage_v_129_1;
  chk_sum_2 ^= stage_v_129_2;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_130_1 = ((stage_v_130_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_130_2 = ((stage_v_130_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((st_var_2_1.buffer[2] * 2) + 400) & 63;
  int stage_v_131_2 = ((st_var_2_2.buffer[2] * 2) + 400) & 63;
  if (stage_v_131_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_131_1) - 5) & 255;
    if (stage_v_131_1 > 42)
    {
      chk_sum_1 ^= stage_v_131_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_131_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_131_2) - 5) & 255;
    if (stage_v_131_2 > 42)
    {
      chk_sum_2 ^= stage_v_131_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_132_1 = (st_var_0_1.buffer[0] ^ 135) & 3;
  int stage_v_132_2 = (st_var_0_2.buffer[0] ^ 135) & 3;
  switch (stage_v_132_1)
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

  switch (stage_v_132_2)
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

  int stage_v_133_1 = table_1[1];
  int stage_v_133_2 = table_2[1];
  table_1[1] = (table_1[2] + 267) & 63;
  table_2[1] = (table_2[2] + 267) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((st_var_2_1.buffer[2] * 2) + 409) & 63;
  int stage_v_134_2 = ((st_var_2_2.buffer[2] * 2) + 409) & 63;
  if (stage_v_134_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_134_1) - 5) & 255;
    if (stage_v_134_1 > 30)
    {
      chk_sum_1 ^= stage_v_134_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_134_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_134_2) - 5) & 255;
    if (stage_v_134_2 > 30)
    {
      chk_sum_2 ^= stage_v_134_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_135_1 = (st_var_0_1.buffer[0] ^ 138) & 3;
  int stage_v_135_2 = (st_var_0_2.buffer[0] ^ 138) & 3;
  switch (stage_v_135_1)
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

  switch (stage_v_135_2)
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

  int stage_v_136_1 = table_1[0];
  int stage_v_136_2 = table_2[0];
  table_1[0] = (table_1[1] + 273) & 63;
  table_2[0] = (table_2[1] + 273) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_137_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 139) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 139) & 15;
  int stage_v_138_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_138_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  chk_sum_1 ^= stage_v_138_1;
  chk_sum_2 ^= stage_v_138_2;
  int stage_v_139_1 = ((st_var_1_1.buffer[1] * 2) + 424) & 63;
  int stage_v_139_2 = ((st_var_1_2.buffer[1] * 2) + 424) & 63;
  if (stage_v_139_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_139_1) - 5) & 255;
    if (stage_v_139_1 > 43)
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
  if (stage_v_139_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_139_2) - 5) & 255;
    if (stage_v_139_2 > 43)
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
  int stage_v_140_1 = ((st_var_2_1.buffer[2] * 2) + 427) & 63;
  int stage_v_140_2 = ((st_var_2_2.buffer[2] * 2) + 427) & 63;
  if (stage_v_140_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_140_1) - 5) & 255;
    if (stage_v_140_1 > 26)
    {
      chk_sum_1 ^= stage_v_140_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_140_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_140_2) - 5) & 255;
    if (stage_v_140_2 > 26)
    {
      chk_sum_2 ^= stage_v_140_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_141_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (146 & 31);
  int stage_v_141_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (146 & 31);
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= (stage_v_141_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_141_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 143) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 143) & 15;
  int stage_v_142_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_142_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= stage_v_142_1;
  chk_sum_2 ^= stage_v_142_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 144) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 144) & 15;
  int stage_v_143_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_143_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  chk_sum_1 ^= stage_v_143_1;
  chk_sum_2 ^= stage_v_143_2;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((st_var_1_1.buffer[1] * 2) + 442) & 63;
  int stage_v_145_2 = ((st_var_1_2.buffer[1] * 2) + 442) & 63;
  if (stage_v_145_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_145_1) - 5) & 255;
    if (stage_v_145_1 > 34)
    {
      chk_sum_1 ^= stage_v_145_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_145_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_145_2) - 5) & 255;
    if (stage_v_145_2 > 34)
    {
      chk_sum_2 ^= stage_v_145_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_146_1 = (st_var_2_1.buffer[0] ^ 149) & 3;
  int stage_v_146_2 = (st_var_2_2.buffer[0] ^ 149) & 3;
  switch (stage_v_146_1)
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

  switch (stage_v_146_2)
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

  int stage_v_147_1 = ((st_var_0_1.buffer[0] * 2) + 448) & 63;
  int stage_v_147_2 = ((st_var_0_2.buffer[0] * 2) + 448) & 63;
  if (stage_v_147_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_147_1) - 5) & 255;
    if (stage_v_147_1 > 30)
    {
      chk_sum_1 ^= stage_v_147_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_147_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_147_2) - 5) & 255;
    if (stage_v_147_2 > 30)
    {
      chk_sum_2 ^= stage_v_147_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_148_1 = (st_var_1_1.buffer[0] ^ 151) & 3;
  int stage_v_148_2 = (st_var_1_2.buffer[0] ^ 151) & 3;
  switch (stage_v_148_1)
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

  switch (stage_v_148_2)
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

  int stage_v_149_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_149_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_149_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_149_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_150_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (155 & 31);
  int stage_v_150_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (155 & 31);
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  chk_sum_1 ^= (stage_v_150_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_150_2 << 1) & 127;
  int stage_v_151_1 = table_1[3];
  int stage_v_151_2 = table_2[3];
  table_1[3] = (table_1[0] + 303) & 63;
  table_2[3] = (table_2[0] + 303) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_152_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 154) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 154) & 15;
  int stage_v_153_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_153_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  chk_sum_1 ^= stage_v_153_1;
  chk_sum_2 ^= stage_v_153_2;
  int stage_v_154_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (159 & 31);
  int stage_v_154_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (159 & 31);
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= (stage_v_154_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_154_2 << 1) & 127;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (161 & 31);
  int stage_v_156_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (161 & 31);
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= (stage_v_156_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_156_2 << 1) & 127;
  int stage_v_157_1 = ((st_var_1_1.buffer[1] * 2) + 478) & 63;
  int stage_v_157_2 = ((st_var_1_2.buffer[1] * 2) + 478) & 63;
  if (stage_v_157_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_157_1) - 5) & 255;
    if (stage_v_157_1 > 37)
    {
      chk_sum_1 ^= stage_v_157_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_157_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_157_2) - 5) & 255;
    if (stage_v_157_2 > 37)
    {
      chk_sum_2 ^= stage_v_157_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 159) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 159) & 15;
  int stage_v_158_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_158_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= stage_v_158_1;
  chk_sum_2 ^= stage_v_158_2;
  int l_bound_0_1 = (sec_r000738_3_1 & 1) + 1;
  int l_bound_0_2 = (sec_r000738_3_2 & 1) + 1;
  for (int it_1 = 0, it_2 = 0; (it_1 < l_bound_0_1) && (it_2 < l_bound_0_2); it_1++, it_2++)
  {
    out_sink_1 += (it_1 * 3) + 7;
    out_sink_2 += (it_2 * 3) + 7;
  }

  int l_bound_1_1 = (sec_r000738_21_1 & 1) + 1;
  int l_bound_1_2 = (sec_r000738_21_2 & 1) + 1;
  for (int it_1 = 0, it_2 = 0; (it_1 < l_bound_1_1) && (it_2 < l_bound_1_2); it_1++, it_2++)
  {
    out_sink_1 += (it_1 * 3) + 2;
    out_sink_2 += (it_2 * 3) + 2;
  }

  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000738_0_1 != sec_r000738_0_2);
  __CPROVER_assume(sec_r000738_2_1 != sec_r000738_2_2);
  __CPROVER_assume(pub_r000738_0_1 == pub_r000738_0_2);
  __CPROVER_assume(pub_r000738_4_1 == pub_r000738_4_2);
  __CPROVER_assume(pub_r000738_8_1 == pub_r000738_8_2);
  __CPROVER_assume(pub_r000738_15_1 == pub_r000738_15_2);
  __CPROVER_assume(sec_r000738_1_1 != sec_r000738_1_2);
  __CPROVER_assume(sec_r000738_4_1 != sec_r000738_4_2);
  __CPROVER_assume(sec_r000738_21_1 != sec_r000738_21_2);
  __CPROVER_assume(sec_r000738_15_1 != sec_r000738_15_2);
  __CPROVER_assume(pub_r000738_10_1 == pub_r000738_10_2);
  __CPROVER_assume(sec_r000738_5_1 != sec_r000738_5_2);
  __CPROVER_assume(sec_r000738_20_1 != sec_r000738_20_2);
  __CPROVER_assume(pub_r000738_2_1 == pub_r000738_2_2);
  __CPROVER_assume(pub_r000738_3_1 == pub_r000738_3_2);
  __CPROVER_assume(sec_r000738_19_1 != sec_r000738_19_2);
  __CPROVER_assume(pub_r000738_6_1 == pub_r000738_6_2);
  __CPROVER_assume(sec_r000738_3_1 != sec_r000738_3_2);
  __CPROVER_assume(sec_r000738_7_1 != sec_r000738_7_2);
  __CPROVER_assume(sec_r000738_17_1 != sec_r000738_17_2);
  __CPROVER_assume(sec_r000738_14_1 != sec_r000738_14_2);
  __CPROVER_assume(sec_r000738_12_1 != sec_r000738_12_2);
  __CPROVER_assume(pub_r000738_11_1 == pub_r000738_11_2);
  __CPROVER_assume(sec_r000738_13_1 != sec_r000738_13_2);
  __CPROVER_assume(pub_r000738_12_1 == pub_r000738_12_2);
  __CPROVER_assume(pub_r000738_5_1 == pub_r000738_5_2);
  __CPROVER_assume(sec_r000738_11_1 != sec_r000738_11_2);
  __CPROVER_assume(pub_r000738_7_1 == pub_r000738_7_2);
  __CPROVER_assume(sec_r000738_8_1 != sec_r000738_8_2);
  __CPROVER_assume(pub_r000738_9_1 == pub_r000738_9_2);
  __CPROVER_assume(pub_r000738_16_1 == pub_r000738_16_2);
  __CPROVER_assume(sec_r000738_9_1 != sec_r000738_9_2);
  __CPROVER_assume(sec_r000738_10_1 != sec_r000738_10_2);
  __CPROVER_assume(sec_r000738_16_1 != sec_r000738_16_2);
  __CPROVER_assume(pub_r000738_17_1 == pub_r000738_17_2);
  __CPROVER_assume(pub_r000738_13_1 == pub_r000738_13_2);
  __CPROVER_assume(sec_r000738_18_1 != sec_r000738_18_2);
  __CPROVER_assume(sec_r000738_6_1 != sec_r000738_6_2);
  __CPROVER_assume(pub_r000738_1_1 == pub_r000738_1_2);
  __CPROVER_assume(pub_r000738_14_1 == pub_r000738_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.state == st_var_1_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.calib == st_var_2_2.calib);
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
  assert(l_bound_0_1 == l_bound_0_2);
  assert(l_bound_1_1 == l_bound_1_2);
}


