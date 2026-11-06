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
struct SensorNode_R000197_9713_0
{
  unsigned char reading;
  unsigned char calib;
  int status;
  int buffer[3];
};
struct Transaction_R000197_9713_1
{
  int account_id;
  short auth_code;
  short balance;
  int fee;
  short rate;
  int status;
  int buffer[3];
};
union ColorPixel_R000197_9713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000197_9713_1
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
void fn_R000197_9713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int weight_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_63_1 > 26)
  {
    acc_1 = ((acc_1 + (weight_63_1 * 2)) + 5) & 127;
    aux_1 ^= weight_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_63_2 > 26)
  {
    acc_2 = ((acc_2 + (weight_63_2 * 2)) + 5) & 127;
    aux_2 ^= weight_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_88_1)
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

  switch (pivot_88_2)
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

  int tracker_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_96_1) & 63;
  aux_2 = (aux_2 + tracker_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_63_1 == weight_63_2);
  assert(pivot_88_1 == pivot_88_2);
  assert(tracker_96_1 == tracker_96_2);
}

int fn_R000197_9713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int weight_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_63 > 26)
  {
    acc = ((acc + (weight_63 * 2)) + 5) & 127;
    aux ^= weight_63 & 15;
  }
  else
  {
    acc = ((acc - weight_63) + 11) & 127;
    aux += 3;
  }
  int pivot_88 = (aux + st.buffer[1]) & 3;
  switch (pivot_88)
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

  int tracker_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000197_9713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int delta_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_44_1) & 63;
  aux_2 = (aux_2 + delta_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_78_1 = local_arr_1[aux_1 % 3];
  int sample_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_78_2 * 2)) & 127;
  int index_reg_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_98_1 > 32)
  {
    acc_1 = ((acc_1 + (index_reg_98_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_98_2 > 32)
  {
    acc_2 = ((acc_2 + (index_reg_98_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_22_1)
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

  switch (segment_22_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_44_1 == delta_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_78_1 == sample_78_2);
  assert(index_reg_98_1 == index_reg_98_2);
  assert(segment_22_1 == segment_22_2);
}

int fn_R000197_9713_1(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int delta_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_44) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_78 = local_arr[aux % 3];
  acc = (acc + (sample_78 * 2)) & 127;
  int index_reg_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_98 > 32)
  {
    acc = ((acc + (index_reg_98 * 2)) + 5) & 127;
    aux ^= index_reg_98 & 15;
  }
  else
  {
    acc = ((acc - index_reg_98) + 11) & 127;
    aux += 3;
  }
  int segment_22 = (aux + st.buffer[1]) & 3;
  switch (segment_22)
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

void fn_R000197_9713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st_1 = {0};
  struct Transaction_R000197_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_20_1)
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

  switch (accumulator_20_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_20_1 == accumulator_20_2);
}

int fn_R000197_9713_2(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_20 = (aux + st.buffer[1]) & 3;
  switch (accumulator_20)
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

void fn_R000197_9713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int coefficient_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_56_1) & 63;
  aux_2 = (aux_2 + coefficient_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_87_1 = local_arr_1[aux_1 % 3];
  int quotient_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_87_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_56_1 == coefficient_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_87_1 == quotient_87_2);
}

int fn_R000197_9713_3(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int coefficient_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_56) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_87 = local_arr[aux % 3];
  acc = (acc + (quotient_87 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000197_9713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st_1 = {0};
  struct Transaction_R000197_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int damping_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_10_1 > 45)
  {
    acc_1 = ((acc_1 + (damping_10_1 * 2)) + 5) & 127;
    aux_1 ^= damping_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_10_2 > 45)
  {
    acc_2 = ((acc_2 + (damping_10_2 * 2)) + 5) & 127;
    aux_2 ^= damping_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_57_1) & 63;
  aux_2 = (aux_2 + anchor_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_10_1 == damping_10_2);
  assert(anchor_57_1 == anchor_57_2);
}

int fn_R000197_9713_4(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int damping_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_10 > 45)
  {
    acc = ((acc + (damping_10 * 2)) + 5) & 127;
    aux ^= damping_10 & 15;
  }
  else
  {
    acc = ((acc - damping_10) + 11) & 127;
    aux += 3;
  }
  int anchor_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000197_9713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int threshold_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_73_1 > 17)
  {
    acc_1 = ((acc_1 + (threshold_73_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_73_2 > 17)
  {
    acc_2 = ((acc_2 + (threshold_73_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_15_1) & 63;
  aux_2 = (aux_2 + vector_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_34_1)
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

  switch (factor_34_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_73_1 == threshold_73_2);
  assert(vector_15_1 == vector_15_2);
  assert(factor_34_1 == factor_34_2);
}

int fn_R000197_9713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int threshold_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_73 > 17)
  {
    acc = ((acc + (threshold_73 * 2)) + 5) & 127;
    aux ^= threshold_73 & 15;
  }
  else
  {
    acc = ((acc - threshold_73) + 11) & 127;
    aux += 3;
  }
  int vector_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_15) & 63;
  acc ^= aux;
  int factor_34 = (aux + st.buffer[1]) & 3;
  switch (factor_34)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000197_9713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st_1 = {0};
  struct Transaction_R000197_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tracker_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_85_1 > 17)
  {
    acc_1 = ((acc_1 + (tracker_85_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_85_2 > 17)
  {
    acc_2 = ((acc_2 + (tracker_85_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_78_1 = local_arr_1[aux_1 % 3];
  int factor_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_78_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_85_1 == tracker_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_78_1 == factor_78_2);
}

int fn_R000197_9713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tracker_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_85 > 17)
  {
    acc = ((acc + (tracker_85 * 2)) + 5) & 127;
    aux ^= tracker_85 & 15;
  }
  else
  {
    acc = ((acc - tracker_85) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_78 = local_arr[aux % 3];
  acc = (acc + (factor_78 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000197_9713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st_1 = {0};
  struct Transaction_R000197_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_66_1 = local_arr_1[aux_1 % 3];
  int damping_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_66_2 * 2)) & 127;
  int delta_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_30_1 > 41)
  {
    acc_1 = ((acc_1 + (delta_30_1 * 2)) + 5) & 127;
    aux_1 ^= delta_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_30_2 > 41)
  {
    acc_2 = ((acc_2 + (delta_30_2 * 2)) + 5) & 127;
    aux_2 ^= delta_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_66_1 == damping_66_2);
  assert(delta_30_1 == delta_30_2);
}

int fn_R000197_9713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int damping_66 = local_arr[aux % 3];
  acc = (acc + (damping_66 * 2)) & 127;
  int delta_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_30 > 41)
  {
    acc = ((acc + (delta_30 * 2)) + 5) & 127;
    aux ^= delta_30 & 15;
  }
  else
  {
    acc = ((acc - delta_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000197_9713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_71_1 = local_arr_1[aux_1 % 3];
  int threshold_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_71_2 * 2)) & 127;
  int checksum_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_50_1) & 63;
  aux_2 = (aux_2 + checksum_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_29_1)
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

  switch (tracker_29_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_71_1 == threshold_71_2);
  assert(checksum_50_1 == checksum_50_2);
  assert(tracker_29_1 == tracker_29_2);
}

int fn_R000197_9713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int threshold_71 = local_arr[aux % 3];
  acc = (acc + (threshold_71 * 2)) & 127;
  int checksum_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_50) & 63;
  acc ^= aux;
  int tracker_29 = (aux + st.buffer[1]) & 3;
  switch (tracker_29)
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

void fn_R000197_9713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st_1 = {0};
  struct Transaction_R000197_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int accumulator_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_43_1 > 41)
  {
    acc_1 = ((acc_1 + (accumulator_43_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_43_2 > 41)
  {
    acc_2 = ((acc_2 + (accumulator_43_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_83_1) & 63;
  aux_2 = (aux_2 + offset_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_43_1 == accumulator_43_2);
  assert(offset_83_1 == offset_83_2);
}

int fn_R000197_9713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int accumulator_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_43 > 41)
  {
    acc = ((acc + (accumulator_43 * 2)) + 5) & 127;
    aux ^= accumulator_43 & 15;
  }
  else
  {
    acc = ((acc - accumulator_43) + 11) & 127;
    aux += 3;
  }
  int offset_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000197_9713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st_1 = {0};
  struct Transaction_R000197_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int delta_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_58_1) & 63;
  aux_2 = (aux_2 + delta_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_62_1)
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

  switch (vector_62_2)
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
  int damping_26_1 = local_arr_1[aux_1 % 3];
  int damping_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_26_2 * 2)) & 127;
  int sample_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_32_1 > 17)
  {
    acc_1 = ((acc_1 + (sample_32_1 * 2)) + 5) & 127;
    aux_1 ^= sample_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_32_2 > 17)
  {
    acc_2 = ((acc_2 + (sample_32_2 * 2)) + 5) & 127;
    aux_2 ^= sample_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_58_1 == delta_58_2);
  assert(vector_62_1 == vector_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_26_1 == damping_26_2);
  assert(sample_32_1 == sample_32_2);
}

int fn_R000197_9713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int delta_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_58) & 63;
  acc ^= aux;
  int vector_62 = (aux + st.buffer[1]) & 3;
  switch (vector_62)
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
  int damping_26 = local_arr[aux % 3];
  acc = (acc + (damping_26 * 2)) & 127;
  int sample_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_32 > 17)
  {
    acc = ((acc + (sample_32 * 2)) + 5) & 127;
    aux ^= sample_32 & 15;
  }
  else
  {
    acc = ((acc - sample_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000197_9713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st_1 = {0};
  struct Transaction_R000197_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_85_1)
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

  switch (segment_85_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_85_1 == segment_85_2);
}

int fn_R000197_9713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_85 = (aux + st.buffer[1]) & 3;
  switch (segment_85)
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

void fn_R000197_9713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_26_1 = local_arr_1[aux_1 % 3];
  int quotient_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_26_2 * 2)) & 127;
  int parity_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_96_1 > 21)
  {
    acc_1 = ((acc_1 + (parity_96_1 * 2)) + 5) & 127;
    aux_1 ^= parity_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_96_2 > 21)
  {
    acc_2 = ((acc_2 + (parity_96_2 * 2)) + 5) & 127;
    aux_2 ^= parity_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_96_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_38_1) & 63;
  aux_2 = (aux_2 + quantum_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_26_1 == quotient_26_2);
  assert(parity_96_1 == parity_96_2);
  assert(quantum_38_1 == quantum_38_2);
}

int fn_R000197_9713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int quotient_26 = local_arr[aux % 3];
  acc = (acc + (quotient_26 * 2)) & 127;
  int parity_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_96 > 21)
  {
    acc = ((acc + (parity_96 * 2)) + 5) & 127;
    aux ^= parity_96 & 15;
  }
  else
  {
    acc = ((acc - parity_96) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000197_9713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int weight_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_67_1)
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

  switch (weight_67_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_98_1 > 50)
  {
    acc_1 = ((acc_1 + (parity_98_1 * 2)) + 5) & 127;
    aux_1 ^= parity_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_98_2 > 50)
  {
    acc_2 = ((acc_2 + (parity_98_2 * 2)) + 5) & 127;
    aux_2 ^= parity_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_67_1 == weight_67_2);
  assert(parity_98_1 == parity_98_2);
}

int fn_R000197_9713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int weight_67 = (aux + st.buffer[1]) & 3;
  switch (weight_67)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_98 > 50)
  {
    acc = ((acc + (parity_98 * 2)) + 5) & 127;
    aux ^= parity_98 & 15;
  }
  else
  {
    acc = ((acc - parity_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000197_9713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int margin_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_88_1)
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

  switch (margin_88_2)
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

  int index_reg_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_69_1) & 63;
  aux_2 = (aux_2 + index_reg_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_88_1 == margin_88_2);
  assert(index_reg_69_1 == index_reg_69_2);
}

int fn_R000197_9713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int margin_88 = (aux + st.buffer[1]) & 3;
  switch (margin_88)
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

  int index_reg_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000197_9713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_39_1 = local_arr_1[aux_1 % 3];
  int checksum_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_39_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_39_1 == checksum_39_2);
}

int fn_R000197_9713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_39 = local_arr[aux % 3];
  acc = (acc + (checksum_39 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000197_9713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int coefficient_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_35_1)
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

  switch (coefficient_35_2)
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
  int anchor_48_1 = local_arr_1[aux_1 % 3];
  int anchor_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_48_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_44_1) & 63;
  aux_2 = (aux_2 + damping_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_35_1 == coefficient_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_48_1 == anchor_48_2);
  assert(damping_44_1 == damping_44_2);
}

int fn_R000197_9713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int coefficient_35 = (aux + st.buffer[1]) & 3;
  switch (coefficient_35)
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
  int anchor_48 = local_arr[aux % 3];
  acc = (acc + (anchor_48 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000197_9713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st_1 = {0};
  struct Transaction_R000197_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int sample_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_39_1) & 63;
  aux_2 = (aux_2 + sample_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_31_1 = local_arr_1[aux_1 % 3];
  int threshold_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_39_1 == sample_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_31_1 == threshold_31_2);
}

int fn_R000197_9713_17(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000197_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int sample_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_39) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_31 = local_arr[aux % 3];
  acc = (acc + (threshold_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000197_9713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int phase_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_95_1) & 63;
  aux_2 = (aux_2 + phase_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_41_1 = local_arr_1[aux_1 % 3];
  int sample_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_41_2 * 2)) & 127;
  int bound_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_85_1)
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

  switch (bound_85_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_95_1 == phase_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_41_1 == sample_41_2);
  assert(bound_85_1 == bound_85_2);
}

int fn_R000197_9713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int phase_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_95) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_41 = local_arr[aux % 3];
  acc = (acc + (sample_41 * 2)) & 127;
  int bound_85 = (aux + st.buffer[1]) & 3;
  switch (bound_85)
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

void fn_R000197_9713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int factor_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_30_1) & 63;
  aux_2 = (aux_2 + factor_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_86_1 = local_arr_1[aux_1 % 3];
  int parity_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_30_1 == factor_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_86_1 == parity_86_2);
}

int fn_R000197_9713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int factor_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_86 = local_arr[aux % 3];
  acc = (acc + (parity_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000197_9713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int anchor_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_16_1)
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

  switch (anchor_16_2)
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

  int window_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_12_1 > 33)
  {
    acc_1 = ((acc_1 + (window_12_1 * 2)) + 5) & 127;
    aux_1 ^= window_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_12_2 > 33)
  {
    acc_2 = ((acc_2 + (window_12_2 * 2)) + 5) & 127;
    aux_2 ^= window_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_16_1 == anchor_16_2);
  assert(window_12_1 == window_12_2);
}

int fn_R000197_9713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int anchor_16 = (aux + st.buffer[1]) & 3;
  switch (anchor_16)
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

  int window_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_12 > 33)
  {
    acc = ((acc + (window_12 * 2)) + 5) & 127;
    aux ^= window_12 & 15;
  }
  else
  {
    acc = ((acc - window_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000197_9713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tally_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_36_1)
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

  switch (tally_36_2)
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
  int weight_66_1 = local_arr_1[aux_1 % 3];
  int weight_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_66_2 * 2)) & 127;
  int metric_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_81_1 > 44)
  {
    acc_1 = ((acc_1 + (metric_81_1 * 2)) + 5) & 127;
    aux_1 ^= metric_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_81_2 > 44)
  {
    acc_2 = ((acc_2 + (metric_81_2 * 2)) + 5) & 127;
    aux_2 ^= metric_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_36_1 == tally_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_66_1 == weight_66_2);
  assert(metric_81_1 == metric_81_2);
}

int fn_R000197_9713_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tally_36 = (aux + st.buffer[1]) & 3;
  switch (tally_36)
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
  int weight_66 = local_arr[aux % 3];
  acc = (acc + (weight_66 * 2)) & 127;
  int metric_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_81 > 44)
  {
    acc = ((acc + (metric_81 * 2)) + 5) & 127;
    aux ^= metric_81 & 15;
  }
  else
  {
    acc = ((acc - metric_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000197_9713_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st_1 = {0};
  struct SensorNode_R000197_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int vector_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_36_1)
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

  switch (vector_36_2)
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
  int scale_52_1 = local_arr_1[aux_1 % 3];
  int scale_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_36_1 == vector_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_52_1 == scale_52_2);
}

int fn_R000197_9713_22(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000197_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int vector_36 = (aux + st.buffer[1]) & 3;
  switch (vector_36)
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
  int scale_52 = local_arr[aux % 3];
  acc = (acc + (scale_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000197_0_1;
  int sec_r000197_0_2;
  int sec_r000197_1_1;
  int sec_r000197_1_2;
  int sec_r000197_2_1;
  int sec_r000197_2_2;
  int sec_r000197_3_1;
  int sec_r000197_3_2;
  int sec_r000197_4_1;
  int sec_r000197_4_2;
  int sec_r000197_5_1;
  int sec_r000197_5_2;
  int sec_r000197_6_1;
  int sec_r000197_6_2;
  int sec_r000197_7_1;
  int sec_r000197_7_2;
  int sec_r000197_8_1;
  int sec_r000197_8_2;
  int sec_r000197_9_1;
  int sec_r000197_9_2;
  int sec_r000197_10_1;
  int sec_r000197_10_2;
  int sec_r000197_11_1;
  int sec_r000197_11_2;
  int sec_r000197_12_1;
  int sec_r000197_12_2;
  int sec_r000197_13_1;
  int sec_r000197_13_2;
  int sec_r000197_14_1;
  int sec_r000197_14_2;
  int sec_r000197_15_1;
  int sec_r000197_15_2;
  int pub_r000197_0_1;
  int pub_r000197_0_2;
  int pub_r000197_1_1;
  int pub_r000197_1_2;
  int pub_r000197_2_1;
  int pub_r000197_2_2;
  int pub_r000197_3_1;
  int pub_r000197_3_2;
  int pub_r000197_4_1;
  int pub_r000197_4_2;
  int pub_r000197_5_1;
  int pub_r000197_5_2;
  int pub_r000197_6_1;
  int pub_r000197_6_2;
  int pub_r000197_7_1;
  int pub_r000197_7_2;
  int pub_r000197_8_1;
  int pub_r000197_8_2;
  int pub_r000197_9_1;
  int pub_r000197_9_2;
  int pub_r000197_10_1;
  int pub_r000197_10_2;
  int pub_r000197_11_1;
  int pub_r000197_11_2;
  int pub_r000197_12_1;
  int pub_r000197_12_2;
  int pub_r000197_13_1;
  int pub_r000197_13_2;
  int pub_r000197_14_1;
  int pub_r000197_14_2;
  int pub_r000197_15_1;
  int pub_r000197_15_2;
  int pub_r000197_16_1;
  int pub_r000197_16_2;
  int pub_r000197_17_1;
  int pub_r000197_17_2;
  int pub_r000197_18_1;
  int pub_r000197_18_2;
  int pub_r000197_19_1;
  int pub_r000197_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000197_0_1 >= (-100)) && (pub_r000197_0_1 <= 100));
  __CPROVER_assume((pub_r000197_0_2 >= (-100)) && (pub_r000197_0_2 <= 100));
  __CPROVER_assume((pub_r000197_1_1 >= (-100)) && (pub_r000197_1_1 <= 100));
  __CPROVER_assume((pub_r000197_1_2 >= (-100)) && (pub_r000197_1_2 <= 100));
  __CPROVER_assume((pub_r000197_2_1 >= (-100)) && (pub_r000197_2_1 <= 100));
  __CPROVER_assume((pub_r000197_2_2 >= (-100)) && (pub_r000197_2_2 <= 100));
  __CPROVER_assume((pub_r000197_3_1 >= (-100)) && (pub_r000197_3_1 <= 100));
  __CPROVER_assume((pub_r000197_3_2 >= (-100)) && (pub_r000197_3_2 <= 100));
  __CPROVER_assume((pub_r000197_4_1 >= (-100)) && (pub_r000197_4_1 <= 100));
  __CPROVER_assume((pub_r000197_4_2 >= (-100)) && (pub_r000197_4_2 <= 100));
  __CPROVER_assume((pub_r000197_5_1 >= (-100)) && (pub_r000197_5_1 <= 100));
  __CPROVER_assume((pub_r000197_5_2 >= (-100)) && (pub_r000197_5_2 <= 100));
  __CPROVER_assume((pub_r000197_6_1 >= (-100)) && (pub_r000197_6_1 <= 100));
  __CPROVER_assume((pub_r000197_6_2 >= (-100)) && (pub_r000197_6_2 <= 100));
  __CPROVER_assume((pub_r000197_7_1 >= (-100)) && (pub_r000197_7_1 <= 100));
  __CPROVER_assume((pub_r000197_7_2 >= (-100)) && (pub_r000197_7_2 <= 100));
  __CPROVER_assume((pub_r000197_8_1 >= (-100)) && (pub_r000197_8_1 <= 100));
  __CPROVER_assume((pub_r000197_8_2 >= (-100)) && (pub_r000197_8_2 <= 100));
  __CPROVER_assume((pub_r000197_9_1 >= (-100)) && (pub_r000197_9_1 <= 100));
  __CPROVER_assume((pub_r000197_9_2 >= (-100)) && (pub_r000197_9_2 <= 100));
  __CPROVER_assume((pub_r000197_10_1 >= (-100)) && (pub_r000197_10_1 <= 100));
  __CPROVER_assume((pub_r000197_10_2 >= (-100)) && (pub_r000197_10_2 <= 100));
  __CPROVER_assume((pub_r000197_11_1 >= (-100)) && (pub_r000197_11_1 <= 100));
  __CPROVER_assume((pub_r000197_11_2 >= (-100)) && (pub_r000197_11_2 <= 100));
  __CPROVER_assume((pub_r000197_12_1 >= (-100)) && (pub_r000197_12_1 <= 100));
  __CPROVER_assume((pub_r000197_12_2 >= (-100)) && (pub_r000197_12_2 <= 100));
  __CPROVER_assume((pub_r000197_13_1 >= (-100)) && (pub_r000197_13_1 <= 100));
  __CPROVER_assume((pub_r000197_13_2 >= (-100)) && (pub_r000197_13_2 <= 100));
  __CPROVER_assume((pub_r000197_14_1 >= (-100)) && (pub_r000197_14_1 <= 100));
  __CPROVER_assume((pub_r000197_14_2 >= (-100)) && (pub_r000197_14_2 <= 100));
  __CPROVER_assume((pub_r000197_15_1 >= (-100)) && (pub_r000197_15_1 <= 100));
  __CPROVER_assume((pub_r000197_15_2 >= (-100)) && (pub_r000197_15_2 <= 100));
  __CPROVER_assume((pub_r000197_16_1 >= (-100)) && (pub_r000197_16_1 <= 100));
  __CPROVER_assume((pub_r000197_16_2 >= (-100)) && (pub_r000197_16_2 <= 100));
  __CPROVER_assume((pub_r000197_17_1 >= (-100)) && (pub_r000197_17_1 <= 100));
  __CPROVER_assume((pub_r000197_17_2 >= (-100)) && (pub_r000197_17_2 <= 100));
  __CPROVER_assume((pub_r000197_18_1 >= (-100)) && (pub_r000197_18_1 <= 100));
  __CPROVER_assume((pub_r000197_18_2 >= (-100)) && (pub_r000197_18_2 <= 100));
  __CPROVER_assume((pub_r000197_19_1 >= (-100)) && (pub_r000197_19_1 <= 100));
  __CPROVER_assume((pub_r000197_19_2 >= (-100)) && (pub_r000197_19_2 <= 100));
  __CPROVER_assume((sec_r000197_0_1 >= 0) && (sec_r000197_0_1 <= 255));
  __CPROVER_assume((sec_r000197_0_2 >= 0) && (sec_r000197_0_2 <= 255));
  __CPROVER_assume((sec_r000197_1_1 >= 0) && (sec_r000197_1_1 <= 255));
  __CPROVER_assume((sec_r000197_1_2 >= 0) && (sec_r000197_1_2 <= 255));
  __CPROVER_assume((sec_r000197_2_1 >= 0) && (sec_r000197_2_1 <= 255));
  __CPROVER_assume((sec_r000197_2_2 >= 0) && (sec_r000197_2_2 <= 255));
  __CPROVER_assume((sec_r000197_3_1 >= 0) && (sec_r000197_3_1 <= 255));
  __CPROVER_assume((sec_r000197_3_2 >= 0) && (sec_r000197_3_2 <= 255));
  __CPROVER_assume((sec_r000197_4_1 >= 0) && (sec_r000197_4_1 <= 255));
  __CPROVER_assume((sec_r000197_4_2 >= 0) && (sec_r000197_4_2 <= 255));
  __CPROVER_assume((sec_r000197_5_1 >= 0) && (sec_r000197_5_1 <= 255));
  __CPROVER_assume((sec_r000197_5_2 >= 0) && (sec_r000197_5_2 <= 255));
  __CPROVER_assume((sec_r000197_6_1 >= 0) && (sec_r000197_6_1 <= 255));
  __CPROVER_assume((sec_r000197_6_2 >= 0) && (sec_r000197_6_2 <= 255));
  __CPROVER_assume((sec_r000197_7_1 >= 0) && (sec_r000197_7_1 <= 255));
  __CPROVER_assume((sec_r000197_7_2 >= 0) && (sec_r000197_7_2 <= 255));
  __CPROVER_assume((sec_r000197_8_1 >= 0) && (sec_r000197_8_1 <= 255));
  __CPROVER_assume((sec_r000197_8_2 >= 0) && (sec_r000197_8_2 <= 255));
  __CPROVER_assume((sec_r000197_9_1 >= 0) && (sec_r000197_9_1 <= 255));
  __CPROVER_assume((sec_r000197_9_2 >= 0) && (sec_r000197_9_2 <= 255));
  __CPROVER_assume((sec_r000197_10_1 >= 0) && (sec_r000197_10_1 <= 255));
  __CPROVER_assume((sec_r000197_10_2 >= 0) && (sec_r000197_10_2 <= 255));
  __CPROVER_assume((sec_r000197_11_1 >= 0) && (sec_r000197_11_1 <= 255));
  __CPROVER_assume((sec_r000197_11_2 >= 0) && (sec_r000197_11_2 <= 255));
  __CPROVER_assume((sec_r000197_12_1 >= 0) && (sec_r000197_12_1 <= 255));
  __CPROVER_assume((sec_r000197_12_2 >= 0) && (sec_r000197_12_2 <= 255));
  __CPROVER_assume((sec_r000197_13_1 >= 0) && (sec_r000197_13_1 <= 255));
  __CPROVER_assume((sec_r000197_13_2 >= 0) && (sec_r000197_13_2 <= 255));
  __CPROVER_assume((sec_r000197_14_1 >= 0) && (sec_r000197_14_1 <= 255));
  __CPROVER_assume((sec_r000197_14_2 >= 0) && (sec_r000197_14_2 <= 255));
  __CPROVER_assume((sec_r000197_15_1 >= 0) && (sec_r000197_15_1 <= 255));
  __CPROVER_assume((sec_r000197_15_2 >= 0) && (sec_r000197_15_2 <= 255));
  struct SensorNode_R000197_9713_0 st_var_0_1 = {0};
  struct SensorNode_R000197_9713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000197_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000197_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000197_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000197_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000197_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000197_0_2 + 7) & 15;
  struct Transaction_R000197_9713_1 st_var_1_1 = {0};
  struct Transaction_R000197_9713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000197_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000197_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000197_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000197_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000197_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000197_0_2 + 9) & 15;
  union ColorPixel_R000197_9713_0 u_var_1;
  union ColorPixel_R000197_9713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 1) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 1) & 15;
  int stage_v_0_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_0_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= stage_v_0_1;
  chk_sum_2 ^= stage_v_0_2;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = ((st_var_0_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_0_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 32)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 32)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  if ((sec_r000197_15_1 & 1) != 0)
  {
    if ((sec_r000197_7_1 & 2) != 0)
    {
      stage_v_15_1 = (pub_r000197_0_1 + 31) & 127;
    }
    else
    {
      stage_v_15_1 = (pub_r000197_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_1 = (pub_r000197_0_1 + 7) & 127;
  }
  if ((sec_r000197_15_2 & 1) != 0)
  {
    if ((sec_r000197_7_2 & 2) != 0)
    {
      stage_v_15_2 = (pub_r000197_0_2 + 31) & 127;
    }
    else
    {
      stage_v_15_2 = (pub_r000197_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_2 = (pub_r000197_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000197_13_1 & 2) != 0)
    {
      stage_v_16_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_16_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000197_13_2 & 2) != 0)
    {
      stage_v_16_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_16_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000197_0_1 & 2) != 0)
    {
      stage_v_17_1 = (pub_r000197_17_1 + 31) & 127;
    }
    else
    {
      stage_v_17_1 = (pub_r000197_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_1 = (pub_r000197_17_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000197_0_2 & 2) != 0)
    {
      stage_v_17_2 = (pub_r000197_17_2 + 31) & 127;
    }
    else
    {
      stage_v_17_2 = (pub_r000197_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_2 = (pub_r000197_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000197_12_1 & 2) != 0)
    {
      stage_v_18_1 = (pub_r000197_14_1 + 31) & 127;
    }
    else
    {
      stage_v_18_1 = (pub_r000197_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_1 = (pub_r000197_14_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000197_12_2 & 2) != 0)
    {
      stage_v_18_2 = (pub_r000197_14_2 + 31) & 127;
    }
    else
    {
      stage_v_18_2 = (pub_r000197_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_2 = (pub_r000197_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000197_9_1 & 2) != 0)
    {
      stage_v_19_1 = (pub_r000197_12_1 + 31) & 127;
    }
    else
    {
      stage_v_19_1 = (pub_r000197_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_1 = (pub_r000197_12_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000197_9_2 & 2) != 0)
    {
      stage_v_19_2 = (pub_r000197_12_2 + 31) & 127;
    }
    else
    {
      stage_v_19_2 = (pub_r000197_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_2 = (pub_r000197_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000197_13_1 & 2) != 0)
    {
      stage_v_20_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_20_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000197_13_2 & 2) != 0)
    {
      stage_v_20_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_20_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  if ((sec_r000197_0_1 & 1) != 0)
  {
    if ((sec_r000197_4_1 & 2) != 0)
    {
      stage_v_21_1 = (pub_r000197_5_1 + 31) & 127;
    }
    else
    {
      stage_v_21_1 = (pub_r000197_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_1 = (pub_r000197_5_1 + 7) & 127;
  }
  if ((sec_r000197_0_2 & 1) != 0)
  {
    if ((sec_r000197_4_2 & 2) != 0)
    {
      stage_v_21_2 = (pub_r000197_5_2 + 31) & 127;
    }
    else
    {
      stage_v_21_2 = (pub_r000197_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_2 = (pub_r000197_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r000197_4_1 & 2) != 0)
    {
      stage_v_22_1 = (pub_r000197_6_1 + 31) & 127;
    }
    else
    {
      stage_v_22_1 = (pub_r000197_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_1 = (pub_r000197_6_1 + 7) & 127;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r000197_4_2 & 2) != 0)
    {
      stage_v_22_2 = (pub_r000197_6_2 + 31) & 127;
    }
    else
    {
      stage_v_22_2 = (pub_r000197_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_2 = (pub_r000197_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000197_1_1 & 2) != 0)
    {
      stage_v_23_1 = (pub_r000197_13_1 + 31) & 127;
    }
    else
    {
      stage_v_23_1 = (pub_r000197_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_1 = (pub_r000197_13_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000197_1_2 & 2) != 0)
    {
      stage_v_23_2 = (pub_r000197_13_2 + 31) & 127;
    }
    else
    {
      stage_v_23_2 = (pub_r000197_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_2 = (pub_r000197_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000197_4_1 & 2) != 0)
    {
      stage_v_24_1 = (pub_r000197_1_1 + 31) & 127;
    }
    else
    {
      stage_v_24_1 = (pub_r000197_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_1 = (pub_r000197_1_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000197_4_2 & 2) != 0)
    {
      stage_v_24_2 = (pub_r000197_1_2 + 31) & 127;
    }
    else
    {
      stage_v_24_2 = (pub_r000197_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_2 = (pub_r000197_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((sec_r000197_6_1 & 1) != 0)
  {
    if ((sec_r000197_7_1 & 2) != 0)
    {
      stage_v_25_1 = (pub_r000197_17_1 + 31) & 127;
    }
    else
    {
      stage_v_25_1 = (pub_r000197_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_1 = (pub_r000197_17_1 + 7) & 127;
  }
  if ((sec_r000197_6_2 & 1) != 0)
  {
    if ((sec_r000197_7_2 & 2) != 0)
    {
      stage_v_25_2 = (pub_r000197_17_2 + 31) & 127;
    }
    else
    {
      stage_v_25_2 = (pub_r000197_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_2 = (pub_r000197_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000197_13_1 & 2) != 0)
    {
      stage_v_26_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_26_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000197_13_2 & 2) != 0)
    {
      stage_v_26_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_26_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r000197_8_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000197_3_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000197_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000197_3_1 + 7) & 127;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r000197_8_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000197_3_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000197_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000197_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000197_2_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000197_0_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000197_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000197_0_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000197_2_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000197_0_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000197_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000197_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000197_5_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000197_5_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((sec_r000197_0_1 & 1) != 0)
  {
    if ((sec_r000197_13_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((sec_r000197_0_2 & 1) != 0)
  {
    if ((sec_r000197_13_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000197_9_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000197_9_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((sec_r000197_5_1 & 1) != 0)
  {
    if ((sec_r000197_5_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000197_5_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000197_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000197_5_1 + 7) & 127;
  }
  if ((sec_r000197_5_2 & 1) != 0)
  {
    if ((sec_r000197_5_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000197_5_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000197_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000197_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000197_0_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000197_15_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000197_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000197_15_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000197_0_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000197_15_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000197_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000197_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((sec_r000197_2_1 & 1) != 0)
  {
    if ((sec_r000197_10_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000197_3_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000197_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000197_3_1 + 7) & 127;
  }
  if ((sec_r000197_2_2 & 1) != 0)
  {
    if ((sec_r000197_10_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000197_3_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000197_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000197_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000197_6_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000197_13_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000197_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000197_13_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000197_6_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000197_13_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000197_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000197_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000197_2_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000197_2_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000197_1_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000197_1_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000197_1_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000197_1_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000197_1_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000197_17_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000197_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000197_17_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000197_1_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000197_17_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000197_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000197_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000197_7_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000197_12_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000197_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000197_12_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000197_7_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000197_12_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000197_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000197_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((sec_r000197_9_1 & 1) != 0)
  {
    if ((sec_r000197_8_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000197_5_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000197_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000197_5_1 + 7) & 127;
  }
  if ((sec_r000197_9_2 & 1) != 0)
  {
    if ((sec_r000197_8_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000197_5_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000197_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000197_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((sec_r000197_0_1 & 1) != 0)
  {
    if ((sec_r000197_11_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000197_15_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000197_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000197_15_1 + 7) & 127;
  }
  if ((sec_r000197_0_2 & 1) != 0)
  {
    if ((sec_r000197_11_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000197_15_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000197_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000197_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((sec_r000197_14_1 & 1) != 0)
  {
    if ((sec_r000197_2_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000197_11_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000197_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000197_11_1 + 7) & 127;
  }
  if ((sec_r000197_14_2 & 1) != 0)
  {
    if ((sec_r000197_2_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000197_11_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000197_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000197_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000197_12_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000197_12_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000197_5_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000197_4_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000197_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000197_4_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000197_5_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000197_4_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000197_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000197_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r000197_10_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r000197_10_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((sec_r000197_8_1 & 1) != 0)
  {
    if ((sec_r000197_10_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000197_0_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000197_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000197_0_1 + 7) & 127;
  }
  if ((sec_r000197_8_2 & 1) != 0)
  {
    if ((sec_r000197_10_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000197_0_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000197_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000197_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000197_14_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000197_12_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000197_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000197_12_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000197_14_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000197_12_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000197_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000197_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000197_8_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000197_8_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000197_4_1 & 1) != 0)
  {
    if ((sec_r000197_7_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000197_1_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000197_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000197_1_1 + 7) & 127;
  }
  if ((sec_r000197_4_2 & 1) != 0)
  {
    if ((sec_r000197_7_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000197_1_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000197_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000197_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((sec_r000197_11_1 & 1) != 0)
  {
    if ((sec_r000197_10_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((sec_r000197_11_2 & 1) != 0)
  {
    if ((sec_r000197_10_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000197_13_1 & 1) != 0)
  {
    if ((sec_r000197_7_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((sec_r000197_13_2 & 1) != 0)
  {
    if ((sec_r000197_7_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000197_15_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000197_15_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000197_4_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000197_10_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000197_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000197_10_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000197_4_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000197_10_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000197_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000197_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000197_10_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000197_17_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000197_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000197_17_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000197_10_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000197_17_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000197_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000197_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000197_6_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000197_5_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000197_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000197_5_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000197_6_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000197_5_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000197_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000197_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000197_15_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000197_14_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000197_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000197_14_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000197_15_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000197_14_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000197_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000197_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000197_7_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000197_15_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000197_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000197_15_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000197_7_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000197_15_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000197_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000197_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000197_5_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000197_5_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000197_1_1 & 1) != 0)
  {
    if ((sec_r000197_8_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000197_3_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000197_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000197_3_1 + 7) & 127;
  }
  if ((sec_r000197_1_2 & 1) != 0)
  {
    if ((sec_r000197_8_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000197_3_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000197_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000197_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000197_0_1 & 1) != 0)
  {
    if ((sec_r000197_15_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000197_9_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000197_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000197_9_1 + 7) & 127;
  }
  if ((sec_r000197_0_2 & 1) != 0)
  {
    if ((sec_r000197_15_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000197_9_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000197_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000197_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000197_5_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000197_5_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000197_1_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000197_7_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000197_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000197_7_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000197_1_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000197_7_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000197_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000197_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000197_8_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000197_17_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000197_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000197_17_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000197_8_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000197_17_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000197_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000197_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000197_10_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000197_0_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000197_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000197_0_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000197_10_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000197_0_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000197_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000197_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000197_3_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000197_3_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000197_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000197_3_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000197_3_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000197_3_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000197_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000197_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000197_12_1 & 1) != 0)
  {
    if ((sec_r000197_1_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000197_13_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000197_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000197_13_1 + 7) & 127;
  }
  if ((sec_r000197_12_2 & 1) != 0)
  {
    if ((sec_r000197_1_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000197_13_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000197_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000197_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000197_6_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000197_6_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000197_3_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000197_9_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000197_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000197_9_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000197_3_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000197_9_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000197_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000197_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000197_1_1 & 1) != 0)
  {
    if ((sec_r000197_3_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000197_0_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000197_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000197_0_1 + 7) & 127;
  }
  if ((sec_r000197_1_2 & 1) != 0)
  {
    if ((sec_r000197_3_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000197_0_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000197_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000197_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000197_7_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000197_7_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000197_13_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000197_13_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000197_10_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000197_12_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000197_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000197_12_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000197_10_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000197_12_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000197_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000197_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000197_2_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000197_14_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000197_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000197_14_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000197_2_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000197_14_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000197_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000197_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000197_13_1 & 1) != 0)
  {
    if ((sec_r000197_0_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000197_4_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000197_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000197_4_1 + 7) & 127;
  }
  if ((sec_r000197_13_2 & 1) != 0)
  {
    if ((sec_r000197_0_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000197_4_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000197_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000197_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000197_13_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000197_13_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000197_15_1 & 1) != 0)
  {
    if ((sec_r000197_3_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000197_3_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000197_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000197_3_1 + 7) & 127;
  }
  if ((sec_r000197_15_2 & 1) != 0)
  {
    if ((sec_r000197_3_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000197_3_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000197_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000197_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000197_13_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000197_10_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000197_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000197_10_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000197_13_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000197_10_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000197_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000197_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000197_12_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000197_12_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000197_0_1 & 1) != 0)
  {
    if ((sec_r000197_10_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000197_2_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000197_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000197_2_1 + 7) & 127;
  }
  if ((sec_r000197_0_2 & 1) != 0)
  {
    if ((sec_r000197_10_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000197_2_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000197_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000197_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000197_12_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000197_11_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000197_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000197_11_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000197_12_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000197_11_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000197_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000197_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000197_15_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000197_10_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000197_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000197_10_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000197_15_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000197_10_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000197_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000197_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000197_13_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000197_3_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000197_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000197_3_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000197_13_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000197_3_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000197_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000197_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000197_2_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000197_5_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000197_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000197_5_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000197_2_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000197_5_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000197_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000197_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000197_10_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000197_10_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000197_11_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000197_11_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000197_0_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000197_5_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000197_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000197_5_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000197_0_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000197_5_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000197_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000197_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000197_0_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000197_0_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000197_5_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000197_17_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000197_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000197_17_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000197_5_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000197_17_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000197_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000197_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000197_0_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000197_2_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000197_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000197_2_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000197_0_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000197_2_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000197_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000197_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000197_4_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000197_4_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000197_13_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000197_13_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000197_2_1 & 1) != 0)
  {
    if ((sec_r000197_6_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000197_10_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000197_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000197_10_1 + 7) & 127;
  }
  if ((sec_r000197_2_2 & 1) != 0)
  {
    if ((sec_r000197_6_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000197_10_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000197_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000197_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000197_5_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000197_5_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000197_2_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000197_10_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000197_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000197_10_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000197_2_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000197_10_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000197_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000197_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000197_15_1 & 1) != 0)
  {
    if ((sec_r000197_15_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000197_18_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000197_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000197_18_1 + 7) & 127;
  }
  if ((sec_r000197_15_2 & 1) != 0)
  {
    if ((sec_r000197_15_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000197_18_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000197_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000197_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000197_9_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000197_4_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000197_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000197_4_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000197_9_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000197_4_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000197_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000197_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000197_10_1 & 1) != 0)
  {
    if ((sec_r000197_11_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000197_18_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000197_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000197_18_1 + 7) & 127;
  }
  if ((sec_r000197_10_2 & 1) != 0)
  {
    if ((sec_r000197_11_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000197_18_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000197_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000197_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000197_9_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000197_11_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000197_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000197_11_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000197_9_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000197_11_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000197_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000197_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000197_7_1 & 1) != 0)
  {
    if ((sec_r000197_4_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000197_18_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000197_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000197_18_1 + 7) & 127;
  }
  if ((sec_r000197_7_2 & 1) != 0)
  {
    if ((sec_r000197_4_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000197_18_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000197_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000197_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000197_11_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000197_11_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000197_0_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000197_18_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000197_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000197_18_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000197_0_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000197_18_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000197_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000197_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000197_1_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000197_14_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000197_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000197_14_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000197_1_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000197_14_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000197_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000197_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000197_10_1 & 1) != 0)
  {
    if ((sec_r000197_3_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000197_0_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000197_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000197_0_1 + 7) & 127;
  }
  if ((sec_r000197_10_2 & 1) != 0)
  {
    if ((sec_r000197_3_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000197_0_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000197_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000197_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000197_5_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000197_5_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000197_4_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000197_4_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000197_5_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000197_7_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000197_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000197_7_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000197_5_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000197_7_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000197_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000197_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000197_7_1 & 1) != 0)
  {
    if ((sec_r000197_6_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000197_2_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000197_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000197_2_1 + 7) & 127;
  }
  if ((sec_r000197_7_2 & 1) != 0)
  {
    if ((sec_r000197_6_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000197_2_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000197_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000197_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000197_2_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000197_3_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000197_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000197_3_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000197_2_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000197_3_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000197_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000197_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000197_9_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000197_17_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000197_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000197_17_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000197_9_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000197_17_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000197_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000197_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000197_15_1 & 1) != 0)
  {
    if ((sec_r000197_1_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000197_2_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000197_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000197_2_1 + 7) & 127;
  }
  if ((sec_r000197_15_2 & 1) != 0)
  {
    if ((sec_r000197_1_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000197_2_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000197_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000197_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000197_14_1 & 1) != 0)
  {
    if ((sec_r000197_15_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000197_6_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000197_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000197_6_1 + 7) & 127;
  }
  if ((sec_r000197_14_2 & 1) != 0)
  {
    if ((sec_r000197_15_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000197_6_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000197_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000197_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000197_13_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000197_9_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000197_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000197_9_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000197_13_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000197_9_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000197_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000197_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000197_15_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000197_12_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000197_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000197_12_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000197_15_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000197_12_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000197_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000197_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000197_11_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000197_11_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000197_0_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000197_10_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000197_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000197_10_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000197_0_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000197_10_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000197_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000197_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000197_2_1 & 1) != 0)
  {
    if ((sec_r000197_2_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000197_10_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000197_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000197_10_1 + 7) & 127;
  }
  if ((sec_r000197_2_2 & 1) != 0)
  {
    if ((sec_r000197_2_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000197_10_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000197_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000197_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000197_2_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000197_2_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000197_12_1 & 1) != 0)
  {
    if ((sec_r000197_9_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000197_13_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000197_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000197_13_1 + 7) & 127;
  }
  if ((sec_r000197_12_2 & 1) != 0)
  {
    if ((sec_r000197_9_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000197_13_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000197_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000197_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000197_11_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000197_0_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000197_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000197_0_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000197_11_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000197_0_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000197_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000197_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000197_6_1 & 1) != 0)
  {
    if ((sec_r000197_5_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000197_18_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000197_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000197_18_1 + 7) & 127;
  }
  if ((sec_r000197_6_2 & 1) != 0)
  {
    if ((sec_r000197_5_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000197_18_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000197_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000197_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000197_12_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000197_12_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000197_4_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000197_4_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000197_14_1 & 1) != 0)
  {
    if ((sec_r000197_2_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000197_19_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000197_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000197_19_1 + 7) & 127;
  }
  if ((sec_r000197_14_2 & 1) != 0)
  {
    if ((sec_r000197_2_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000197_19_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000197_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000197_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000197_1_1 & 1) != 0)
  {
    if ((sec_r000197_9_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((sec_r000197_1_2 & 1) != 0)
  {
    if ((sec_r000197_9_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000197_9_1 & 1) != 0)
  {
    if ((sec_r000197_7_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000197_12_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000197_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000197_12_1 + 7) & 127;
  }
  if ((sec_r000197_9_2 & 1) != 0)
  {
    if ((sec_r000197_7_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000197_12_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000197_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000197_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000197_14_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000197_14_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000197_4_1 & 1) != 0)
  {
    if ((sec_r000197_3_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000197_9_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000197_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000197_9_1 + 7) & 127;
  }
  if ((sec_r000197_4_2 & 1) != 0)
  {
    if ((sec_r000197_3_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000197_9_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000197_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000197_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000197_8_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000197_7_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000197_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000197_7_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000197_8_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000197_7_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000197_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000197_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000197_7_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000197_13_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000197_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000197_13_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000197_7_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000197_13_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000197_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000197_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000197_5_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000197_5_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000197_10_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000197_17_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000197_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000197_17_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000197_10_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000197_17_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000197_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000197_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000197_15_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000197_8_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000197_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000197_8_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000197_15_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000197_8_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000197_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000197_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000197_11_1 & 1) != 0)
  {
    if ((sec_r000197_10_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000197_17_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000197_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000197_17_1 + 7) & 127;
  }
  if ((sec_r000197_11_2 & 1) != 0)
  {
    if ((sec_r000197_10_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000197_17_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000197_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000197_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000197_11_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000197_5_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000197_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000197_5_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000197_11_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000197_5_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000197_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000197_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000197_2_1 & 1) != 0)
  {
    if ((sec_r000197_2_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000197_16_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000197_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000197_16_1 + 7) & 127;
  }
  if ((sec_r000197_2_2 & 1) != 0)
  {
    if ((sec_r000197_2_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000197_16_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000197_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000197_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000197_8_1 != sec_r000197_8_2);
  __CPROVER_assume(pub_r000197_0_1 == pub_r000197_0_2);
  __CPROVER_assume(sec_r000197_12_1 != sec_r000197_12_2);
  __CPROVER_assume(pub_r000197_11_1 == pub_r000197_11_2);
  __CPROVER_assume(pub_r000197_18_1 == pub_r000197_18_2);
  __CPROVER_assume(sec_r000197_14_1 != sec_r000197_14_2);
  __CPROVER_assume(pub_r000197_15_1 == pub_r000197_15_2);
  __CPROVER_assume(pub_r000197_3_1 == pub_r000197_3_2);
  __CPROVER_assume(pub_r000197_10_1 == pub_r000197_10_2);
  __CPROVER_assume(sec_r000197_3_1 != sec_r000197_3_2);
  __CPROVER_assume(pub_r000197_4_1 == pub_r000197_4_2);
  __CPROVER_assume(pub_r000197_12_1 == pub_r000197_12_2);
  __CPROVER_assume(pub_r000197_6_1 == pub_r000197_6_2);
  __CPROVER_assume(pub_r000197_17_1 == pub_r000197_17_2);
  __CPROVER_assume(pub_r000197_2_1 == pub_r000197_2_2);
  __CPROVER_assume(sec_r000197_10_1 != sec_r000197_10_2);
  __CPROVER_assume(sec_r000197_9_1 != sec_r000197_9_2);
  __CPROVER_assume(pub_r000197_1_1 == pub_r000197_1_2);
  __CPROVER_assume(pub_r000197_19_1 == pub_r000197_19_2);
  __CPROVER_assume(sec_r000197_0_1 != sec_r000197_0_2);
  __CPROVER_assume(sec_r000197_7_1 != sec_r000197_7_2);
  __CPROVER_assume(sec_r000197_5_1 != sec_r000197_5_2);
  __CPROVER_assume(sec_r000197_1_1 != sec_r000197_1_2);
  __CPROVER_assume(pub_r000197_16_1 == pub_r000197_16_2);
  __CPROVER_assume(pub_r000197_13_1 == pub_r000197_13_2);
  __CPROVER_assume(sec_r000197_13_1 != sec_r000197_13_2);
  __CPROVER_assume(pub_r000197_5_1 == pub_r000197_5_2);
  __CPROVER_assume(sec_r000197_4_1 != sec_r000197_4_2);
  __CPROVER_assume(sec_r000197_15_1 != sec_r000197_15_2);
  __CPROVER_assume(pub_r000197_14_1 == pub_r000197_14_2);
  __CPROVER_assume(pub_r000197_9_1 == pub_r000197_9_2);
  __CPROVER_assume(sec_r000197_2_1 != sec_r000197_2_2);
  __CPROVER_assume(pub_r000197_8_1 == pub_r000197_8_2);
  __CPROVER_assume(sec_r000197_11_1 != sec_r000197_11_2);
  __CPROVER_assume(pub_r000197_7_1 == pub_r000197_7_2);
  __CPROVER_assume(sec_r000197_6_1 != sec_r000197_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.status == st_var_1_2.status);
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
}


