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
struct EventLog_R001337_3713_0
{
  int code;
  int signature;
  int timestamp;
  short severity;
  int buffer[3];
};
struct SensorNode_R001337_3713_1
{
  unsigned char reading;
  unsigned char offset;
  int calib;
  short gain;
  int threshold;
  int buffer[3];
};
union ColorPixel_R001337_3713_0
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
void fn_R001337_3713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st_1 = {0};
  struct EventLog_R001337_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int pivot_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_85_1) & 63;
  aux_2 = (aux_2 + pivot_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_85_1 == pivot_85_2);
}

int fn_R001337_3713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int pivot_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_85) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001337_3713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st_1 = {0};
  struct SensorNode_R001337_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quantum_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_39_1) & 63;
  aux_2 = (aux_2 + quantum_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_66_1)
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

  switch (sample_66_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_39_1 == quantum_39_2);
  assert(sample_66_1 == sample_66_2);
}

int fn_R001337_3713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quantum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_39) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_66 = (aux + st.buffer[1]) & 3;
  switch (sample_66)
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

void fn_R001337_3713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st_1 = {0};
  struct SensorNode_R001337_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int vector_51_1 = 0;
  int vector_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_51_1 = ((vector_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_51_2 = ((vector_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_51_1) & 127;
    acc_2 = (acc_2 + vector_51_2) & 127;
  }

  int coefficient_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_34_1) & 63;
  aux_2 = (aux_2 + coefficient_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_23_1)
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

  switch (damping_23_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_51_1 == vector_51_2);
  assert(coefficient_34_1 == coefficient_34_2);
  assert(damping_23_1 == damping_23_2);
}

int fn_R001337_3713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int vector_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_51 = ((vector_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_51) & 127;
  }

  int coefficient_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_34) & 63;
  acc ^= aux;
  int damping_23 = (aux + st.buffer[1]) & 3;
  switch (damping_23)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001337_3713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st_1 = {0};
  struct EventLog_R001337_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_28_1 = local_arr_1[aux_1 % 3];
  int factor_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_28_2 * 2)) & 127;
  int window_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_74_1)
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

  switch (window_74_2)
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

  int sample_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_28_1 > 42)
  {
    acc_1 = ((acc_1 + (sample_28_1 * 2)) + 5) & 127;
    aux_1 ^= sample_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_28_2 > 42)
  {
    acc_2 = ((acc_2 + (sample_28_2 * 2)) + 5) & 127;
    aux_2 ^= sample_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_65_1 = 0;
  int tally_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_65_1 = ((tally_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_65_2 = ((tally_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_65_1) & 127;
    acc_2 = (acc_2 + tally_65_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_28_1 == factor_28_2);
  assert(window_74_1 == window_74_2);
  assert(sample_28_1 == sample_28_2);
  assert(tally_65_1 == tally_65_2);
}

int fn_R001337_3713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int factor_28 = local_arr[aux % 3];
  acc = (acc + (factor_28 * 2)) & 127;
  int window_74 = (aux + st.buffer[1]) & 3;
  switch (window_74)
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

  int sample_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_28 > 42)
  {
    acc = ((acc + (sample_28 * 2)) + 5) & 127;
    aux ^= sample_28 & 15;
  }
  else
  {
    acc = ((acc - sample_28) + 11) & 127;
    aux += 3;
  }
  int tally_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_65 = ((tally_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_65) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001337_3713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st_1 = {0};
  struct SensorNode_R001337_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_33_1 = local_arr_1[aux_1 % 3];
  int quotient_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_33_2 * 2)) & 127;
  int index_reg_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_10_1) & 63;
  aux_2 = (aux_2 + index_reg_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_33_1 == quotient_33_2);
  assert(index_reg_10_1 == index_reg_10_2);
}

int fn_R001337_3713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int quotient_33 = local_arr[aux % 3];
  acc = (acc + (quotient_33 * 2)) & 127;
  int index_reg_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_10) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001337_3713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st_1 = {0};
  struct EventLog_R001337_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int metric_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_39_1 > 22)
  {
    acc_1 = ((acc_1 + (metric_39_1 * 2)) + 5) & 127;
    aux_1 ^= metric_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_39_2 > 22)
  {
    acc_2 = ((acc_2 + (metric_39_2 * 2)) + 5) & 127;
    aux_2 ^= metric_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_32_1 = local_arr_1[aux_1 % 3];
  int damping_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_32_2 * 2)) & 127;
  int coefficient_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_44_1)
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

  switch (coefficient_44_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_39_1 == metric_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_32_1 == damping_32_2);
  assert(coefficient_44_1 == coefficient_44_2);
}

int fn_R001337_3713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int metric_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_39 > 22)
  {
    acc = ((acc + (metric_39 * 2)) + 5) & 127;
    aux ^= metric_39 & 15;
  }
  else
  {
    acc = ((acc - metric_39) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int damping_32 = local_arr[aux % 3];
  acc = (acc + (damping_32 * 2)) & 127;
  int coefficient_44 = (aux + st.buffer[1]) & 3;
  switch (coefficient_44)
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

void fn_R001337_3713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st_1 = {0};
  struct SensorNode_R001337_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tally_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_69_1) & 63;
  aux_2 = (aux_2 + tally_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_94_1 = local_arr_1[aux_1 % 3];
  int delta_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_94_2 * 2)) & 127;
  int cursor_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_27_1)
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

  switch (cursor_27_2)
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

  int checksum_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_98_1 > 21)
  {
    acc_1 = ((acc_1 + (checksum_98_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_98_2 > 21)
  {
    acc_2 = ((acc_2 + (checksum_98_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_69_1 == tally_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_94_1 == delta_94_2);
  assert(cursor_27_1 == cursor_27_2);
  assert(checksum_98_1 == checksum_98_2);
}

int fn_R001337_3713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tally_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_69) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_94 = local_arr[aux % 3];
  acc = (acc + (delta_94 * 2)) & 127;
  int cursor_27 = (aux + st.buffer[1]) & 3;
  switch (cursor_27)
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

  int checksum_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_98 > 21)
  {
    acc = ((acc + (checksum_98 * 2)) + 5) & 127;
    aux ^= checksum_98 & 15;
  }
  else
  {
    acc = ((acc - checksum_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001337_3713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st_1 = {0};
  struct EventLog_R001337_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_84_1 = local_arr_1[aux_1 % 3];
  int phase_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_84_2 * 2)) & 127;
  int stride_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_41_1)
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

  switch (stride_41_2)
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

  int weight_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_66_1 > 30)
  {
    acc_1 = ((acc_1 + (weight_66_1 * 2)) + 5) & 127;
    aux_1 ^= weight_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_66_2 > 30)
  {
    acc_2 = ((acc_2 + (weight_66_2 * 2)) + 5) & 127;
    aux_2 ^= weight_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_73_1 = 0;
  int checksum_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_73_1 = ((checksum_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_73_2 = ((checksum_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_73_1) & 127;
    acc_2 = (acc_2 + checksum_73_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_84_1 == phase_84_2);
  assert(stride_41_1 == stride_41_2);
  assert(weight_66_1 == weight_66_2);
  assert(checksum_73_1 == checksum_73_2);
}

int fn_R001337_3713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int phase_84 = local_arr[aux % 3];
  acc = (acc + (phase_84 * 2)) & 127;
  int stride_41 = (aux + st.buffer[1]) & 3;
  switch (stride_41)
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

  int weight_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_66 > 30)
  {
    acc = ((acc + (weight_66 * 2)) + 5) & 127;
    aux ^= weight_66 & 15;
  }
  else
  {
    acc = ((acc - weight_66) + 11) & 127;
    aux += 3;
  }
  int checksum_73 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_73 = ((checksum_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_73) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001337_3713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st_1 = {0};
  struct SensorNode_R001337_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int stride_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_40_1) & 63;
  aux_2 = (aux_2 + stride_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_28_1)
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

  switch (scale_28_2)
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

  int anchor_84_1 = 0;
  int anchor_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_84_1 = ((anchor_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_84_2 = ((anchor_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_84_1) & 127;
    acc_2 = (acc_2 + anchor_84_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_40_1 == stride_40_2);
  assert(scale_28_1 == scale_28_2);
  assert(anchor_84_1 == anchor_84_2);
}

int fn_R001337_3713_8(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int stride_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_40) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_28 = (aux + st.buffer[1]) & 3;
  switch (scale_28)
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

  int anchor_84 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_84 = ((anchor_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_84) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001337_3713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st_1 = {0};
  struct EventLog_R001337_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_43_1 > 17)
  {
    acc_1 = ((acc_1 + (mask_43_1 * 2)) + 5) & 127;
    aux_1 ^= mask_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_43_2 > 17)
  {
    acc_2 = ((acc_2 + (mask_43_2 * 2)) + 5) & 127;
    aux_2 ^= mask_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_79_1) & 63;
  aux_2 = (aux_2 + damping_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_43_1 == mask_43_2);
  assert(damping_79_1 == damping_79_2);
}

int fn_R001337_3713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_43 > 17)
  {
    acc = ((acc + (mask_43 * 2)) + 5) & 127;
    aux ^= mask_43 & 15;
  }
  else
  {
    acc = ((acc - mask_43) + 11) & 127;
    aux += 3;
  }
  int damping_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_79) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001337_3713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st_1 = {0};
  struct SensorNode_R001337_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int quotient_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_90_1)
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

  switch (quotient_90_2)
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

  int pivot_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_60_1) & 63;
  aux_2 = (aux_2 + pivot_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_80_1 = 0;
  int tally_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_80_1 = ((tally_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_80_2 = ((tally_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_80_1) & 127;
    acc_2 = (acc_2 + tally_80_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_90_1 == quotient_90_2);
  assert(pivot_60_1 == pivot_60_2);
  assert(tally_80_1 == tally_80_2);
}

int fn_R001337_3713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int quotient_90 = (aux + st.buffer[1]) & 3;
  switch (quotient_90)
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

  int pivot_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_60) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_80 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_80 = ((tally_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_80) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001337_3713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st_1 = {0};
  struct SensorNode_R001337_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_50_1 = 0;
  int accumulator_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_50_1 = ((accumulator_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_50_2 = ((accumulator_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_50_1) & 127;
    acc_2 = (acc_2 + accumulator_50_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_88_1 = local_arr_1[aux_1 % 3];
  int sample_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_50_1 == accumulator_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_88_1 == sample_88_2);
}

int fn_R001337_3713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_50 = ((accumulator_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_50) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_88 = local_arr[aux % 3];
  acc = (acc + (sample_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001337_3713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st_1 = {0};
  struct EventLog_R001337_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int accumulator_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_28_1) & 63;
  aux_2 = (aux_2 + accumulator_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_57_1 = 0;
  int segment_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_57_1 = ((segment_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_57_2 = ((segment_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_57_1) & 127;
    acc_2 = (acc_2 + segment_57_2) & 127;
  }

  int accumulator_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_57_1 > 31)
  {
    acc_1 = ((acc_1 + (accumulator_57_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_57_2 > 31)
  {
    acc_2 = ((acc_2 + (accumulator_57_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_28_1 == accumulator_28_2);
  assert(segment_57_1 == segment_57_2);
  assert(accumulator_57_1 == accumulator_57_2);
}

int fn_R001337_3713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_28) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_57 = ((segment_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_57) & 127;
  }

  int accumulator_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_57 > 31)
  {
    acc = ((acc + (accumulator_57 * 2)) + 5) & 127;
    aux ^= accumulator_57 & 15;
  }
  else
  {
    acc = ((acc - accumulator_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001337_3713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st_1 = {0};
  struct SensorNode_R001337_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int mask_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_86_1 > 36)
  {
    acc_1 = ((acc_1 + (mask_86_1 * 2)) + 5) & 127;
    aux_1 ^= mask_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_86_2 > 36)
  {
    acc_2 = ((acc_2 + (mask_86_2 * 2)) + 5) & 127;
    aux_2 ^= mask_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_56_1 = 0;
  int damping_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_56_1 = ((damping_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_56_2 = ((damping_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_56_1) & 127;
    acc_2 = (acc_2 + damping_56_2) & 127;
  }

  int checksum_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_59_1)
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

  switch (checksum_59_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_86_1 == mask_86_2);
  assert(damping_56_1 == damping_56_2);
  assert(checksum_59_1 == checksum_59_2);
}

int fn_R001337_3713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int mask_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_86 > 36)
  {
    acc = ((acc + (mask_86 * 2)) + 5) & 127;
    aux ^= mask_86 & 15;
  }
  else
  {
    acc = ((acc - mask_86) + 11) & 127;
    aux += 3;
  }
  int damping_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_56 = ((damping_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_56) & 127;
  }

  int checksum_59 = (aux + st.buffer[1]) & 3;
  switch (checksum_59)
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
  return (acc + aux) & 255;
}

void fn_R001337_3713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st_1 = {0};
  struct SensorNode_R001337_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int sample_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_25_1)
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

  switch (sample_25_2)
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

  int checksum_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_99_1) & 63;
  aux_2 = (aux_2 + checksum_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_47_1 = local_arr_1[aux_1 % 3];
  int sample_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_47_2 * 2)) & 127;
  int weight_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_80_1 > 33)
  {
    acc_1 = ((acc_1 + (weight_80_1 * 2)) + 5) & 127;
    aux_1 ^= weight_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_80_2 > 33)
  {
    acc_2 = ((acc_2 + (weight_80_2 * 2)) + 5) & 127;
    aux_2 ^= weight_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_25_1 == sample_25_2);
  assert(checksum_99_1 == checksum_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_47_1 == sample_47_2);
  assert(weight_80_1 == weight_80_2);
}

int fn_R001337_3713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int sample_25 = (aux + st.buffer[1]) & 3;
  switch (sample_25)
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

  int checksum_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_99) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_47 = local_arr[aux % 3];
  acc = (acc + (sample_47 * 2)) & 127;
  int weight_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_80 > 33)
  {
    acc = ((acc + (weight_80 * 2)) + 5) & 127;
    aux ^= weight_80 & 15;
  }
  else
  {
    acc = ((acc - weight_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001337_3713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st_1 = {0};
  struct SensorNode_R001337_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int delta_59_1 = 0;
  int delta_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_59_1 = ((delta_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_59_2 = ((delta_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_59_1) & 127;
    acc_2 = (acc_2 + delta_59_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_20_1)
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

  switch (threshold_20_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_59_1 == delta_59_2);
  assert(threshold_20_1 == threshold_20_2);
}

int fn_R001337_3713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001337_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int delta_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_59 = ((delta_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_59) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_20 = (aux + st.buffer[1]) & 3;
  switch (threshold_20)
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

void fn_R001337_3713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st_1 = {0};
  struct EventLog_R001337_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_37_1 = local_arr_1[aux_1 % 3];
  int pivot_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_37_2 * 2)) & 127;
  int window_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_39_1) & 63;
  aux_2 = (aux_2 + window_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_53_1 > 13)
  {
    acc_1 = ((acc_1 + (anchor_53_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_53_2 > 13)
  {
    acc_2 = ((acc_2 + (anchor_53_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_12_1 = 0;
  int damping_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_12_1 = ((damping_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_12_2 = ((damping_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_12_1) & 127;
    acc_2 = (acc_2 + damping_12_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_37_1 == pivot_37_2);
  assert(window_39_1 == window_39_2);
  assert(anchor_53_1 == anchor_53_2);
  assert(damping_12_1 == damping_12_2);
}

int fn_R001337_3713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001337_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int pivot_37 = local_arr[aux % 3];
  acc = (acc + (pivot_37 * 2)) & 127;
  int window_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_39) & 63;
  acc ^= aux;
  int anchor_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_53 > 13)
  {
    acc = ((acc + (anchor_53 * 2)) + 5) & 127;
    aux ^= anchor_53 & 15;
  }
  else
  {
    acc = ((acc - anchor_53) + 11) & 127;
    aux += 3;
  }
  int damping_12 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_12 = ((damping_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_12) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001337_0_1;
  int sec_r001337_0_2;
  int sec_r001337_1_1;
  int sec_r001337_1_2;
  int sec_r001337_2_1;
  int sec_r001337_2_2;
  int sec_r001337_3_1;
  int sec_r001337_3_2;
  int sec_r001337_4_1;
  int sec_r001337_4_2;
  int sec_r001337_5_1;
  int sec_r001337_5_2;
  int sec_r001337_6_1;
  int sec_r001337_6_2;
  int sec_r001337_7_1;
  int sec_r001337_7_2;
  int sec_r001337_8_1;
  int sec_r001337_8_2;
  int sec_r001337_9_1;
  int sec_r001337_9_2;
  int sec_r001337_10_1;
  int sec_r001337_10_2;
  int sec_r001337_11_1;
  int sec_r001337_11_2;
  int sec_r001337_12_1;
  int sec_r001337_12_2;
  int sec_r001337_13_1;
  int sec_r001337_13_2;
  int sec_r001337_14_1;
  int sec_r001337_14_2;
  int sec_r001337_15_1;
  int sec_r001337_15_2;
  int sec_r001337_16_1;
  int sec_r001337_16_2;
  int sec_r001337_17_1;
  int sec_r001337_17_2;
  int sec_r001337_18_1;
  int sec_r001337_18_2;
  int pub_r001337_0_1;
  int pub_r001337_0_2;
  int pub_r001337_1_1;
  int pub_r001337_1_2;
  int pub_r001337_2_1;
  int pub_r001337_2_2;
  int pub_r001337_3_1;
  int pub_r001337_3_2;
  int pub_r001337_4_1;
  int pub_r001337_4_2;
  int pub_r001337_5_1;
  int pub_r001337_5_2;
  int pub_r001337_6_1;
  int pub_r001337_6_2;
  int pub_r001337_7_1;
  int pub_r001337_7_2;
  int pub_r001337_8_1;
  int pub_r001337_8_2;
  int pub_r001337_9_1;
  int pub_r001337_9_2;
  int pub_r001337_10_1;
  int pub_r001337_10_2;
  int pub_r001337_11_1;
  int pub_r001337_11_2;
  int pub_r001337_12_1;
  int pub_r001337_12_2;
  int pub_r001337_13_1;
  int pub_r001337_13_2;
  int pub_r001337_14_1;
  int pub_r001337_14_2;
  int pub_r001337_15_1;
  int pub_r001337_15_2;
  int pub_r001337_16_1;
  int pub_r001337_16_2;
  int pub_r001337_17_1;
  int pub_r001337_17_2;
  int pub_r001337_18_1;
  int pub_r001337_18_2;
  int pub_r001337_19_1;
  int pub_r001337_19_2;
  int pub_r001337_20_1;
  int pub_r001337_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001337_0_1 >= (-100)) && (pub_r001337_0_1 <= 100));
  __CPROVER_assume((pub_r001337_0_2 >= (-100)) && (pub_r001337_0_2 <= 100));
  __CPROVER_assume((pub_r001337_1_1 >= (-100)) && (pub_r001337_1_1 <= 100));
  __CPROVER_assume((pub_r001337_1_2 >= (-100)) && (pub_r001337_1_2 <= 100));
  __CPROVER_assume((pub_r001337_2_1 >= (-100)) && (pub_r001337_2_1 <= 100));
  __CPROVER_assume((pub_r001337_2_2 >= (-100)) && (pub_r001337_2_2 <= 100));
  __CPROVER_assume((pub_r001337_3_1 >= (-100)) && (pub_r001337_3_1 <= 100));
  __CPROVER_assume((pub_r001337_3_2 >= (-100)) && (pub_r001337_3_2 <= 100));
  __CPROVER_assume((pub_r001337_4_1 >= (-100)) && (pub_r001337_4_1 <= 100));
  __CPROVER_assume((pub_r001337_4_2 >= (-100)) && (pub_r001337_4_2 <= 100));
  __CPROVER_assume((pub_r001337_5_1 >= (-100)) && (pub_r001337_5_1 <= 100));
  __CPROVER_assume((pub_r001337_5_2 >= (-100)) && (pub_r001337_5_2 <= 100));
  __CPROVER_assume((pub_r001337_6_1 >= (-100)) && (pub_r001337_6_1 <= 100));
  __CPROVER_assume((pub_r001337_6_2 >= (-100)) && (pub_r001337_6_2 <= 100));
  __CPROVER_assume((pub_r001337_7_1 >= (-100)) && (pub_r001337_7_1 <= 100));
  __CPROVER_assume((pub_r001337_7_2 >= (-100)) && (pub_r001337_7_2 <= 100));
  __CPROVER_assume((pub_r001337_8_1 >= (-100)) && (pub_r001337_8_1 <= 100));
  __CPROVER_assume((pub_r001337_8_2 >= (-100)) && (pub_r001337_8_2 <= 100));
  __CPROVER_assume((pub_r001337_9_1 >= (-100)) && (pub_r001337_9_1 <= 100));
  __CPROVER_assume((pub_r001337_9_2 >= (-100)) && (pub_r001337_9_2 <= 100));
  __CPROVER_assume((pub_r001337_10_1 >= (-100)) && (pub_r001337_10_1 <= 100));
  __CPROVER_assume((pub_r001337_10_2 >= (-100)) && (pub_r001337_10_2 <= 100));
  __CPROVER_assume((pub_r001337_11_1 >= (-100)) && (pub_r001337_11_1 <= 100));
  __CPROVER_assume((pub_r001337_11_2 >= (-100)) && (pub_r001337_11_2 <= 100));
  __CPROVER_assume((pub_r001337_12_1 >= (-100)) && (pub_r001337_12_1 <= 100));
  __CPROVER_assume((pub_r001337_12_2 >= (-100)) && (pub_r001337_12_2 <= 100));
  __CPROVER_assume((pub_r001337_13_1 >= (-100)) && (pub_r001337_13_1 <= 100));
  __CPROVER_assume((pub_r001337_13_2 >= (-100)) && (pub_r001337_13_2 <= 100));
  __CPROVER_assume((pub_r001337_14_1 >= (-100)) && (pub_r001337_14_1 <= 100));
  __CPROVER_assume((pub_r001337_14_2 >= (-100)) && (pub_r001337_14_2 <= 100));
  __CPROVER_assume((pub_r001337_15_1 >= (-100)) && (pub_r001337_15_1 <= 100));
  __CPROVER_assume((pub_r001337_15_2 >= (-100)) && (pub_r001337_15_2 <= 100));
  __CPROVER_assume((pub_r001337_16_1 >= (-100)) && (pub_r001337_16_1 <= 100));
  __CPROVER_assume((pub_r001337_16_2 >= (-100)) && (pub_r001337_16_2 <= 100));
  __CPROVER_assume((pub_r001337_17_1 >= (-100)) && (pub_r001337_17_1 <= 100));
  __CPROVER_assume((pub_r001337_17_2 >= (-100)) && (pub_r001337_17_2 <= 100));
  __CPROVER_assume((pub_r001337_18_1 >= (-100)) && (pub_r001337_18_1 <= 100));
  __CPROVER_assume((pub_r001337_18_2 >= (-100)) && (pub_r001337_18_2 <= 100));
  __CPROVER_assume((pub_r001337_19_1 >= (-100)) && (pub_r001337_19_1 <= 100));
  __CPROVER_assume((pub_r001337_19_2 >= (-100)) && (pub_r001337_19_2 <= 100));
  __CPROVER_assume((pub_r001337_20_1 >= (-100)) && (pub_r001337_20_1 <= 100));
  __CPROVER_assume((pub_r001337_20_2 >= (-100)) && (pub_r001337_20_2 <= 100));
  __CPROVER_assume((sec_r001337_0_1 >= 0) && (sec_r001337_0_1 <= 255));
  __CPROVER_assume((sec_r001337_0_2 >= 0) && (sec_r001337_0_2 <= 255));
  __CPROVER_assume((sec_r001337_1_1 >= 0) && (sec_r001337_1_1 <= 255));
  __CPROVER_assume((sec_r001337_1_2 >= 0) && (sec_r001337_1_2 <= 255));
  __CPROVER_assume((sec_r001337_2_1 >= 0) && (sec_r001337_2_1 <= 255));
  __CPROVER_assume((sec_r001337_2_2 >= 0) && (sec_r001337_2_2 <= 255));
  __CPROVER_assume((sec_r001337_3_1 >= 0) && (sec_r001337_3_1 <= 255));
  __CPROVER_assume((sec_r001337_3_2 >= 0) && (sec_r001337_3_2 <= 255));
  __CPROVER_assume((sec_r001337_4_1 >= 0) && (sec_r001337_4_1 <= 255));
  __CPROVER_assume((sec_r001337_4_2 >= 0) && (sec_r001337_4_2 <= 255));
  __CPROVER_assume((sec_r001337_5_1 >= 0) && (sec_r001337_5_1 <= 255));
  __CPROVER_assume((sec_r001337_5_2 >= 0) && (sec_r001337_5_2 <= 255));
  __CPROVER_assume((sec_r001337_6_1 >= 0) && (sec_r001337_6_1 <= 255));
  __CPROVER_assume((sec_r001337_6_2 >= 0) && (sec_r001337_6_2 <= 255));
  __CPROVER_assume((sec_r001337_7_1 >= 0) && (sec_r001337_7_1 <= 255));
  __CPROVER_assume((sec_r001337_7_2 >= 0) && (sec_r001337_7_2 <= 255));
  __CPROVER_assume((sec_r001337_8_1 >= 0) && (sec_r001337_8_1 <= 255));
  __CPROVER_assume((sec_r001337_8_2 >= 0) && (sec_r001337_8_2 <= 255));
  __CPROVER_assume((sec_r001337_9_1 >= 0) && (sec_r001337_9_1 <= 255));
  __CPROVER_assume((sec_r001337_9_2 >= 0) && (sec_r001337_9_2 <= 255));
  __CPROVER_assume((sec_r001337_10_1 >= 0) && (sec_r001337_10_1 <= 255));
  __CPROVER_assume((sec_r001337_10_2 >= 0) && (sec_r001337_10_2 <= 255));
  __CPROVER_assume((sec_r001337_11_1 >= 0) && (sec_r001337_11_1 <= 255));
  __CPROVER_assume((sec_r001337_11_2 >= 0) && (sec_r001337_11_2 <= 255));
  __CPROVER_assume((sec_r001337_12_1 >= 0) && (sec_r001337_12_1 <= 255));
  __CPROVER_assume((sec_r001337_12_2 >= 0) && (sec_r001337_12_2 <= 255));
  __CPROVER_assume((sec_r001337_13_1 >= 0) && (sec_r001337_13_1 <= 255));
  __CPROVER_assume((sec_r001337_13_2 >= 0) && (sec_r001337_13_2 <= 255));
  __CPROVER_assume((sec_r001337_14_1 >= 0) && (sec_r001337_14_1 <= 255));
  __CPROVER_assume((sec_r001337_14_2 >= 0) && (sec_r001337_14_2 <= 255));
  __CPROVER_assume((sec_r001337_15_1 >= 0) && (sec_r001337_15_1 <= 255));
  __CPROVER_assume((sec_r001337_15_2 >= 0) && (sec_r001337_15_2 <= 255));
  __CPROVER_assume((sec_r001337_16_1 >= 0) && (sec_r001337_16_1 <= 255));
  __CPROVER_assume((sec_r001337_16_2 >= 0) && (sec_r001337_16_2 <= 255));
  __CPROVER_assume((sec_r001337_17_1 >= 0) && (sec_r001337_17_1 <= 255));
  __CPROVER_assume((sec_r001337_17_2 >= 0) && (sec_r001337_17_2 <= 255));
  __CPROVER_assume((sec_r001337_18_1 >= 0) && (sec_r001337_18_1 <= 255));
  __CPROVER_assume((sec_r001337_18_2 >= 0) && (sec_r001337_18_2 <= 255));
  struct EventLog_R001337_3713_0 st_var_0_1 = {0};
  struct EventLog_R001337_3713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001337_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001337_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001337_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001337_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001337_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001337_0_2 + 7) & 15;
  struct SensorNode_R001337_3713_1 st_var_1_1 = {0};
  struct SensorNode_R001337_3713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001337_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001337_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001337_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001337_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001337_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001337_0_2 + 9) & 15;
  union ColorPixel_R001337_3713_0 u_var_1;
  union ColorPixel_R001337_3713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001337_3713_0(sec_r001337_0_1, pub_r001337_1_1, pub_r001337_2_1, pub_r001337_3_1);
  int helper_flow_0_2 = fn_R001337_3713_0(sec_r001337_0_2, pub_r001337_1_2, pub_r001337_2_2, pub_r001337_3_2);
  fn_R001337_3713_0_2(sec_r001337_0_1, pub_r001337_1_1, pub_r001337_2_1, pub_r001337_3_1, sec_r001337_0_2, pub_r001337_1_2, pub_r001337_2_2, pub_r001337_3_2);
  int helper_flow_1_1 = fn_R001337_3713_1(sec_r001337_1_1, sec_r001337_2_1, pub_r001337_3_1);
  int helper_flow_1_2 = fn_R001337_3713_1(sec_r001337_1_2, sec_r001337_2_2, pub_r001337_3_2);
  fn_R001337_3713_1_2(sec_r001337_1_1, sec_r001337_2_1, pub_r001337_3_1, sec_r001337_1_2, sec_r001337_2_2, pub_r001337_3_2);
  int helper_flow_2_1 = fn_R001337_3713_2(sec_r001337_2_1, sec_r001337_3_1, pub_r001337_4_1, pub_r001337_5_1);
  int helper_flow_2_2 = fn_R001337_3713_2(sec_r001337_2_2, sec_r001337_3_2, pub_r001337_4_2, pub_r001337_5_2);
  fn_R001337_3713_2_2(sec_r001337_2_1, sec_r001337_3_1, pub_r001337_4_1, pub_r001337_5_1, sec_r001337_2_2, sec_r001337_3_2, pub_r001337_4_2, pub_r001337_5_2);
  int helper_flow_3_1 = fn_R001337_3713_3(sec_r001337_3_1, pub_r001337_4_1, pub_r001337_5_1, pub_r001337_6_1);
  int helper_flow_3_2 = fn_R001337_3713_3(sec_r001337_3_2, pub_r001337_4_2, pub_r001337_5_2, pub_r001337_6_2);
  fn_R001337_3713_3_2(sec_r001337_3_1, pub_r001337_4_1, pub_r001337_5_1, pub_r001337_6_1, sec_r001337_3_2, pub_r001337_4_2, pub_r001337_5_2, pub_r001337_6_2);
  int helper_flow_4_1 = fn_R001337_3713_4(sec_r001337_4_1, sec_r001337_5_1, pub_r001337_6_1);
  int helper_flow_4_2 = fn_R001337_3713_4(sec_r001337_4_2, sec_r001337_5_2, pub_r001337_6_2);
  fn_R001337_3713_4_2(sec_r001337_4_1, sec_r001337_5_1, pub_r001337_6_1, sec_r001337_4_2, sec_r001337_5_2, pub_r001337_6_2);
  int helper_flow_5_1 = fn_R001337_3713_5(sec_r001337_5_1, sec_r001337_6_1, pub_r001337_7_1, pub_r001337_8_1, pub_r001337_9_1);
  int helper_flow_5_2 = fn_R001337_3713_5(sec_r001337_5_2, sec_r001337_6_2, pub_r001337_7_2, pub_r001337_8_2, pub_r001337_9_2);
  fn_R001337_3713_5_2(sec_r001337_5_1, sec_r001337_6_1, pub_r001337_7_1, pub_r001337_8_1, pub_r001337_9_1, sec_r001337_5_2, sec_r001337_6_2, pub_r001337_7_2, pub_r001337_8_2, pub_r001337_9_2);
  int helper_flow_6_1 = fn_R001337_3713_6(sec_r001337_6_1, sec_r001337_7_1, pub_r001337_8_1);
  int helper_flow_6_2 = fn_R001337_3713_6(sec_r001337_6_2, sec_r001337_7_2, pub_r001337_8_2);
  fn_R001337_3713_6_2(sec_r001337_6_1, sec_r001337_7_1, pub_r001337_8_1, sec_r001337_6_2, sec_r001337_7_2, pub_r001337_8_2);
  int helper_flow_7_1 = fn_R001337_3713_7(sec_r001337_7_1, sec_r001337_8_1, pub_r001337_9_1, pub_r001337_10_1, pub_r001337_11_1);
  int helper_flow_7_2 = fn_R001337_3713_7(sec_r001337_7_2, sec_r001337_8_2, pub_r001337_9_2, pub_r001337_10_2, pub_r001337_11_2);
  fn_R001337_3713_7_2(sec_r001337_7_1, sec_r001337_8_1, pub_r001337_9_1, pub_r001337_10_1, pub_r001337_11_1, sec_r001337_7_2, sec_r001337_8_2, pub_r001337_9_2, pub_r001337_10_2, pub_r001337_11_2);
  int helper_flow_8_1 = fn_R001337_3713_8(sec_r001337_8_1, pub_r001337_9_1);
  int helper_flow_8_2 = fn_R001337_3713_8(sec_r001337_8_2, pub_r001337_9_2);
  fn_R001337_3713_8_2(sec_r001337_8_1, pub_r001337_9_1, sec_r001337_8_2, pub_r001337_9_2);
  int helper_flow_9_1 = fn_R001337_3713_9(sec_r001337_9_1, pub_r001337_10_1, pub_r001337_11_1);
  int helper_flow_9_2 = fn_R001337_3713_9(sec_r001337_9_2, pub_r001337_10_2, pub_r001337_11_2);
  fn_R001337_3713_9_2(sec_r001337_9_1, pub_r001337_10_1, pub_r001337_11_1, sec_r001337_9_2, pub_r001337_10_2, pub_r001337_11_2);
  int helper_flow_10_1 = fn_R001337_3713_10(sec_r001337_10_1, sec_r001337_11_1, pub_r001337_12_1);
  int helper_flow_10_2 = fn_R001337_3713_10(sec_r001337_10_2, sec_r001337_11_2, pub_r001337_12_2);
  fn_R001337_3713_10_2(sec_r001337_10_1, sec_r001337_11_1, pub_r001337_12_1, sec_r001337_10_2, sec_r001337_11_2, pub_r001337_12_2);
  int stage_v_0_1 = ((pub_r001337_18_1 * 2) + 47) & 63;
  int stage_v_0_2 = ((pub_r001337_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001337_9_1 * 2) + 20) & 63;
  int stage_v_1_2 = ((pub_r001337_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001337_0_1 * 2) + 29) & 63;
  int stage_v_2_2 = ((pub_r001337_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001337_5_1 * 2) + 34) & 63;
  int stage_v_3_2 = ((pub_r001337_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001337_18_1 * 2) + 12) & 63;
  int stage_v_4_2 = ((pub_r001337_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (helper_flow_2_1 ^ pub_r001337_11_1) & 63;
  int stage_v_5_2 = (helper_flow_2_2 ^ pub_r001337_11_2) & 63;
  if ((stage_v_5_1 & 1) != 0)
  {
    if ((sec_r001337_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_5_1 * 2)) & 255;
  }
  if ((stage_v_5_2 & 1) != 0)
  {
    if ((sec_r001337_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_5_2 * 2)) & 255;
  }
  int stage_v_6_1 = (sec_r001337_16_1 ^ pub_r001337_5_1) & 63;
  int stage_v_6_2 = (sec_r001337_16_2 ^ pub_r001337_5_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((sec_r001337_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_6_1 * 2)) & 255;
  }
  if ((stage_v_6_2 & 1) != 0)
  {
    if ((sec_r001337_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_6_2 * 2)) & 255;
  }
  int stage_v_7_1 = (sec_r001337_10_1 ^ pub_r001337_6_1) & 63;
  int stage_v_7_2 = (sec_r001337_10_2 ^ pub_r001337_6_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((sec_r001337_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_7_1 * 2)) & 255;
  }
  if ((stage_v_7_2 & 1) != 0)
  {
    if ((sec_r001337_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_7_2 * 2)) & 255;
  }
  int stage_v_8_1 = ((pub_r001337_9_1 * 2) + 21) & 63;
  int stage_v_8_2 = ((pub_r001337_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (sec_r001337_3_1 ^ pub_r001337_9_1) & 63;
  int stage_v_9_2 = (sec_r001337_3_2 ^ pub_r001337_9_2) & 63;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r001337_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_9_1 * 2)) & 255;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r001337_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_9_2 * 2)) & 255;
  }
  int stage_v_10_1 = (sec_r001337_2_1 ^ pub_r001337_13_1) & 63;
  int stage_v_10_2 = (sec_r001337_2_2 ^ pub_r001337_13_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((sec_r001337_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_10_1 * 2)) & 255;
  }
  if ((stage_v_10_2 & 1) != 0)
  {
    if ((sec_r001337_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_10_2 * 2)) & 255;
  }
  int stage_v_11_1 = ((pub_r001337_11_1 * 2) + 12) & 63;
  int stage_v_11_2 = ((pub_r001337_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (helper_flow_8_1 ^ pub_r001337_15_1) & 63;
  int stage_v_12_2 = (helper_flow_8_2 ^ pub_r001337_15_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((sec_r001337_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_12_1 * 2)) & 255;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((sec_r001337_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_12_2 * 2)) & 255;
  }
  int stage_v_13_1 = (stage_v_6_1 ^ pub_r001337_11_1) & 63;
  int stage_v_13_2 = (stage_v_6_2 ^ pub_r001337_11_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((sec_r001337_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_13_1 * 2)) & 255;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((sec_r001337_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_13_2 * 2)) & 255;
  }
  int stage_v_14_1 = ((pub_r001337_16_1 * 2) + 27) & 63;
  int stage_v_14_2 = ((pub_r001337_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001337_8_1 * 2) + 13) & 63;
  int stage_v_15_2 = ((pub_r001337_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (helper_flow_8_1 ^ pub_r001337_7_1) & 63;
  int stage_v_16_2 = (helper_flow_8_2 ^ pub_r001337_7_2) & 63;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_16_1 * 2)) & 255;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_16_2 * 2)) & 255;
  }
  int stage_v_17_1 = (sec_r001337_8_1 ^ pub_r001337_13_1) & 63;
  int stage_v_17_2 = (sec_r001337_8_2 ^ pub_r001337_13_2) & 63;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((stage_v_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_17_1 * 2)) & 255;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((stage_v_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_17_2 * 2)) & 255;
  }
  int stage_v_18_1 = (helper_flow_0_1 ^ pub_r001337_18_1) & 63;
  int stage_v_18_2 = (helper_flow_0_2 ^ pub_r001337_18_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((helper_flow_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_18_1 * 2)) & 255;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((helper_flow_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_18_2 * 2)) & 255;
  }
  int stage_v_19_1 = (helper_flow_1_1 ^ pub_r001337_18_1) & 63;
  int stage_v_19_2 = (helper_flow_1_2 ^ pub_r001337_18_2) & 63;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_19_1 * 2)) & 255;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((helper_flow_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_19_2 * 2)) & 255;
  }
  int stage_v_20_1 = ((pub_r001337_8_1 * 2) + 48) & 63;
  int stage_v_20_2 = ((pub_r001337_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (sec_r001337_5_1 ^ pub_r001337_13_1) & 63;
  int stage_v_21_2 = (sec_r001337_5_2 ^ pub_r001337_13_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r001337_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_21_1 * 2)) & 255;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r001337_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_21_2 * 2)) & 255;
  }
  int stage_v_22_1 = (stage_v_5_1 ^ pub_r001337_3_1) & 63;
  int stage_v_22_2 = (stage_v_5_2 ^ pub_r001337_3_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_22_1 * 2)) & 255;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((stage_v_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_22_2 * 2)) & 255;
  }
  int stage_v_23_1 = (helper_flow_3_1 ^ pub_r001337_13_1) & 63;
  int stage_v_23_2 = (helper_flow_3_2 ^ pub_r001337_13_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((helper_flow_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_23_1 * 2)) & 255;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((helper_flow_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_23_2 * 2)) & 255;
  }
  int stage_v_24_1 = ((pub_r001337_9_1 * 2) + 30) & 63;
  int stage_v_24_2 = ((pub_r001337_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (stage_v_16_1 ^ pub_r001337_3_1) & 63;
  int stage_v_25_2 = (stage_v_16_2 ^ pub_r001337_3_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_25_1 * 2)) & 255;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_25_2 * 2)) & 255;
  }
  int stage_v_26_1 = (sec_r001337_5_1 ^ pub_r001337_8_1) & 63;
  int stage_v_26_2 = (sec_r001337_5_2 ^ pub_r001337_8_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_26_1 * 2)) & 255;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_26_2 * 2)) & 255;
  }
  int stage_v_27_1 = ((pub_r001337_4_1 * 2) + 14) & 63;
  int stage_v_27_2 = ((pub_r001337_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (stage_v_26_1 ^ pub_r001337_11_1) & 63;
  int stage_v_28_2 = (stage_v_26_2 ^ pub_r001337_11_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r001337_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_28_1 * 2)) & 255;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r001337_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_28_2 * 2)) & 255;
  }
  int stage_v_29_1 = ((pub_r001337_2_1 * 2) + 39) & 63;
  int stage_v_29_2 = ((pub_r001337_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001337_3_1 * 2) + 49) & 63;
  int stage_v_30_2 = ((pub_r001337_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (stage_v_22_1 ^ pub_r001337_11_1) & 63;
  int stage_v_31_2 = (stage_v_22_2 ^ pub_r001337_11_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_31_1 * 2)) & 255;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((stage_v_28_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_31_2 * 2)) & 255;
  }
  int stage_v_32_1 = (stage_v_28_1 ^ pub_r001337_19_1) & 63;
  int stage_v_32_2 = (stage_v_28_2 ^ pub_r001337_19_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_32_1 * 2)) & 255;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_32_2 * 2)) & 255;
  }
  int stage_v_33_1 = (stage_v_21_1 ^ pub_r001337_3_1) & 63;
  int stage_v_33_2 = (stage_v_21_2 ^ pub_r001337_3_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_33_1 * 2)) & 255;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_33_2 * 2)) & 255;
  }
  int stage_v_34_1 = (stage_v_25_1 ^ pub_r001337_14_1) & 63;
  int stage_v_34_2 = (stage_v_25_2 ^ pub_r001337_14_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_34_1 * 2)) & 255;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_34_2 * 2)) & 255;
  }
  int stage_v_35_1 = (sec_r001337_8_1 ^ pub_r001337_15_1) & 63;
  int stage_v_35_2 = (sec_r001337_8_2 ^ pub_r001337_15_2) & 63;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_35_1 * 2)) & 255;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((stage_v_26_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_35_2 * 2)) & 255;
  }
  int stage_v_36_1 = (sec_r001337_10_1 ^ pub_r001337_11_1) & 63;
  int stage_v_36_2 = (sec_r001337_10_2 ^ pub_r001337_11_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r001337_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_36_1 * 2)) & 255;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r001337_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_36_2 * 2)) & 255;
  }
  int stage_v_37_1 = (stage_v_33_1 ^ pub_r001337_18_1) & 63;
  int stage_v_37_2 = (stage_v_33_2 ^ pub_r001337_18_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r001337_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_37_1 * 2)) & 255;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r001337_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_37_2 * 2)) & 255;
  }
  int stage_v_38_1 = (stage_v_21_1 ^ pub_r001337_20_1) & 63;
  int stage_v_38_2 = (stage_v_21_2 ^ pub_r001337_20_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_38_1 * 2)) & 255;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((stage_v_32_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_38_2 * 2)) & 255;
  }
  int stage_v_39_1 = ((pub_r001337_3_1 * 2) + 28) & 63;
  int stage_v_39_2 = ((pub_r001337_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (sec_r001337_5_1 ^ pub_r001337_3_1) & 63;
  int stage_v_40_2 = (sec_r001337_5_2 ^ pub_r001337_3_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_40_1 * 2)) & 255;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((stage_v_33_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_40_2 * 2)) & 255;
  }
  int stage_v_41_1 = ((pub_r001337_17_1 * 2) + 24) & 63;
  int stage_v_41_2 = ((pub_r001337_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001337_0_1 * 2) + 35) & 63;
  int stage_v_42_2 = ((pub_r001337_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001337_10_1 * 2) + 27) & 63;
  int stage_v_43_2 = ((pub_r001337_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (stage_v_38_1 ^ pub_r001337_9_1) & 63;
  int stage_v_44_2 = (stage_v_38_2 ^ pub_r001337_9_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r001337_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r001337_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  }
  int stage_v_45_1 = (sec_r001337_17_1 ^ pub_r001337_11_1) & 63;
  int stage_v_45_2 = (sec_r001337_17_2 ^ pub_r001337_11_2) & 63;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_45_1 * 2)) & 255;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((stage_v_34_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_45_2 * 2)) & 255;
  }
  int stage_v_46_1 = ((pub_r001337_6_1 * 2) + 9) & 63;
  int stage_v_46_2 = ((pub_r001337_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001337_5_1 * 2) + 31) & 63;
  int stage_v_47_2 = ((pub_r001337_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (helper_flow_9_1 ^ pub_r001337_4_1) & 63;
  int stage_v_48_2 = (helper_flow_9_2 ^ pub_r001337_4_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((stage_v_37_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((stage_v_37_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  }
  int stage_v_49_1 = ((pub_r001337_6_1 * 2) + 48) & 63;
  int stage_v_49_2 = ((pub_r001337_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (helper_flow_2_1 ^ pub_r001337_20_1) & 63;
  int stage_v_50_2 = (helper_flow_2_2 ^ pub_r001337_20_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((stage_v_35_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((stage_v_35_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  }
  int stage_v_51_1 = (stage_v_31_1 ^ pub_r001337_18_1) & 63;
  int stage_v_51_2 = (stage_v_31_2 ^ pub_r001337_18_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r001337_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r001337_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  }
  int stage_v_52_1 = ((pub_r001337_13_1 * 2) + 11) & 63;
  int stage_v_52_2 = ((pub_r001337_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (stage_v_40_1 ^ pub_r001337_13_1) & 63;
  int stage_v_53_2 = (stage_v_40_2 ^ pub_r001337_13_2) & 63;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_53_1 * 2)) & 255;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_53_2 * 2)) & 255;
  }
  int stage_v_54_1 = (helper_flow_4_1 ^ pub_r001337_12_1) & 63;
  int stage_v_54_2 = (helper_flow_4_2 ^ pub_r001337_12_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  }
  int stage_v_55_1 = (stage_v_28_1 ^ pub_r001337_14_1) & 63;
  int stage_v_55_2 = (stage_v_28_2 ^ pub_r001337_14_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  }
  int stage_v_56_1 = (stage_v_40_1 ^ pub_r001337_13_1) & 63;
  int stage_v_56_2 = (stage_v_40_2 ^ pub_r001337_13_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r001337_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r001337_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  }
  int stage_v_57_1 = (stage_v_9_1 ^ pub_r001337_13_1) & 63;
  int stage_v_57_2 = (stage_v_9_2 ^ pub_r001337_13_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r001337_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r001337_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  }
  int stage_v_58_1 = (stage_v_54_1 ^ pub_r001337_12_1) & 63;
  int stage_v_58_2 = (stage_v_54_2 ^ pub_r001337_12_2) & 63;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((stage_v_48_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  }
  int stage_v_59_1 = ((pub_r001337_13_1 * 2) + 21) & 63;
  int stage_v_59_2 = ((pub_r001337_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (sec_r001337_17_1 ^ pub_r001337_12_1) & 63;
  int stage_v_60_2 = (sec_r001337_17_2 ^ pub_r001337_12_2) & 63;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r001337_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r001337_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  }
  int stage_v_61_1 = (helper_flow_0_1 ^ pub_r001337_12_1) & 63;
  int stage_v_61_2 = (helper_flow_0_2 ^ pub_r001337_12_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  }
  int stage_v_62_1 = (stage_v_34_1 ^ pub_r001337_5_1) & 63;
  int stage_v_62_2 = (stage_v_34_2 ^ pub_r001337_5_2) & 63;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((helper_flow_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((helper_flow_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  }
  int stage_v_63_1 = (stage_v_35_1 ^ pub_r001337_20_1) & 63;
  int stage_v_63_2 = (stage_v_35_2 ^ pub_r001337_20_2) & 63;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  }
  int stage_v_64_1 = ((pub_r001337_8_1 * 2) + 25) & 63;
  int stage_v_64_2 = ((pub_r001337_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001337_2_1 * 2) + 43) & 63;
  int stage_v_65_2 = ((pub_r001337_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (stage_v_61_1 ^ pub_r001337_16_1) & 63;
  int stage_v_66_2 = (stage_v_61_2 ^ pub_r001337_16_2) & 63;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((stage_v_48_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  }
  int stage_v_67_1 = (stage_v_56_1 ^ pub_r001337_16_1) & 63;
  int stage_v_67_2 = (stage_v_56_2 ^ pub_r001337_16_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((stage_v_35_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((stage_v_35_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  }
  int stage_v_68_1 = (helper_flow_10_1 ^ pub_r001337_9_1) & 63;
  int stage_v_68_2 = (helper_flow_10_2 ^ pub_r001337_9_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r001337_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r001337_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  }
  int stage_v_69_1 = (stage_v_22_1 ^ pub_r001337_6_1) & 63;
  int stage_v_69_2 = (stage_v_22_2 ^ pub_r001337_6_2) & 63;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((stage_v_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((stage_v_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  }
  int stage_v_70_1 = (stage_v_25_1 ^ pub_r001337_18_1) & 63;
  int stage_v_70_2 = (stage_v_25_2 ^ pub_r001337_18_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((stage_v_25_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  }
  int stage_v_71_1 = (sec_r001337_14_1 ^ pub_r001337_17_1) & 63;
  int stage_v_71_2 = (sec_r001337_14_2 ^ pub_r001337_17_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((stage_v_70_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((stage_v_70_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  }
  int stage_v_72_1 = ((pub_r001337_0_1 * 2) + 28) & 63;
  int stage_v_72_2 = ((pub_r001337_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001337_5_1 * 2) + 7) & 63;
  int stage_v_73_2 = ((pub_r001337_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (sec_r001337_6_1 ^ pub_r001337_0_1) & 63;
  int stage_v_74_2 = (sec_r001337_6_2 ^ pub_r001337_0_2) & 63;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((stage_v_51_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  }
  int stage_v_75_1 = (stage_v_58_1 ^ pub_r001337_7_1) & 63;
  int stage_v_75_2 = (stage_v_58_2 ^ pub_r001337_7_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((stage_v_34_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  }
  int stage_v_76_1 = (stage_v_62_1 ^ pub_r001337_15_1) & 63;
  int stage_v_76_2 = (stage_v_62_2 ^ pub_r001337_15_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  }
  int stage_v_77_1 = (sec_r001337_16_1 ^ pub_r001337_8_1) & 63;
  int stage_v_77_2 = (sec_r001337_16_2 ^ pub_r001337_8_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((stage_v_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  }
  int stage_v_78_1 = (stage_v_5_1 ^ pub_r001337_15_1) & 63;
  int stage_v_78_2 = (stage_v_5_2 ^ pub_r001337_15_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r001337_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r001337_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  }
  int stage_v_79_1 = (sec_r001337_8_1 ^ pub_r001337_7_1) & 63;
  int stage_v_79_2 = (sec_r001337_8_2 ^ pub_r001337_7_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  }
  int stage_v_80_1 = (stage_v_38_1 ^ pub_r001337_5_1) & 63;
  int stage_v_80_2 = (stage_v_38_2 ^ pub_r001337_5_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  }
  int stage_v_81_1 = ((pub_r001337_18_1 * 2) + 29) & 63;
  int stage_v_81_2 = ((pub_r001337_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (sec_r001337_4_1 ^ pub_r001337_16_1) & 63;
  int stage_v_82_2 = (sec_r001337_4_2 ^ pub_r001337_16_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((stage_v_53_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((stage_v_53_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  }
  int stage_v_83_1 = (sec_r001337_5_1 ^ pub_r001337_6_1) & 63;
  int stage_v_83_2 = (sec_r001337_5_2 ^ pub_r001337_6_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r001337_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r001337_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  }
  int stage_v_84_1 = ((pub_r001337_5_1 * 2) + 50) & 63;
  int stage_v_84_2 = ((pub_r001337_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (stage_v_58_1 ^ pub_r001337_12_1) & 63;
  int stage_v_85_2 = (stage_v_58_2 ^ pub_r001337_12_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r001337_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r001337_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  }
  int stage_v_86_1 = (helper_flow_10_1 ^ pub_r001337_8_1) & 63;
  int stage_v_86_2 = (helper_flow_10_2 ^ pub_r001337_8_2) & 63;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((stage_v_78_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((stage_v_78_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  }
  int stage_v_87_1 = ((pub_r001337_17_1 * 2) + 12) & 63;
  int stage_v_87_2 = ((pub_r001337_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (stage_v_56_1 ^ pub_r001337_14_1) & 63;
  int stage_v_88_2 = (stage_v_56_2 ^ pub_r001337_14_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((stage_v_32_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  }
  int stage_v_89_1 = (stage_v_83_1 ^ pub_r001337_19_1) & 63;
  int stage_v_89_2 = (stage_v_83_2 ^ pub_r001337_19_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r001337_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r001337_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  }
  int stage_v_90_1 = (stage_v_77_1 ^ pub_r001337_13_1) & 63;
  int stage_v_90_2 = (stage_v_77_2 ^ pub_r001337_13_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  }
  int stage_v_91_1 = ((pub_r001337_6_1 * 2) + 16) & 63;
  int stage_v_91_2 = ((pub_r001337_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001337_3_1 * 2) + 7) & 63;
  int stage_v_92_2 = ((pub_r001337_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001337_11_1 * 2) + 28) & 63;
  int stage_v_93_2 = ((pub_r001337_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001337_8_1 * 2) + 23) & 63;
  int stage_v_94_2 = ((pub_r001337_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (stage_v_28_1 ^ pub_r001337_20_1) & 63;
  int stage_v_95_2 = (stage_v_28_2 ^ pub_r001337_20_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((stage_v_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  }
  int stage_v_96_1 = (stage_v_61_1 ^ pub_r001337_18_1) & 63;
  int stage_v_96_2 = (stage_v_61_2 ^ pub_r001337_18_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r001337_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r001337_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  }
  int stage_v_97_1 = (sec_r001337_4_1 ^ pub_r001337_9_1) & 63;
  int stage_v_97_2 = (sec_r001337_4_2 ^ pub_r001337_9_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  }
  int stage_v_98_1 = (stage_v_10_1 ^ pub_r001337_18_1) & 63;
  int stage_v_98_2 = (stage_v_10_2 ^ pub_r001337_18_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  }
  int stage_v_99_1 = ((pub_r001337_0_1 * 2) + 17) & 63;
  int stage_v_99_2 = ((pub_r001337_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001337_19_1 * 2) + 43) & 63;
  int stage_v_100_2 = ((pub_r001337_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001337_9_1 * 2) + 40) & 63;
  int stage_v_101_2 = ((pub_r001337_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (stage_v_26_1 ^ pub_r001337_5_1) & 63;
  int stage_v_102_2 = (stage_v_26_2 ^ pub_r001337_5_2) & 63;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  }
  int stage_v_103_1 = (stage_v_33_1 ^ pub_r001337_14_1) & 63;
  int stage_v_103_2 = (stage_v_33_2 ^ pub_r001337_14_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((stage_v_45_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  }
  int stage_v_104_1 = ((pub_r001337_20_1 * 2) + 43) & 63;
  int stage_v_104_2 = ((pub_r001337_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001337_20_1 * 2) + 11) & 63;
  int stage_v_105_2 = ((pub_r001337_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (stage_v_33_1 ^ pub_r001337_14_1) & 63;
  int stage_v_106_2 = (stage_v_33_2 ^ pub_r001337_14_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  }
  int stage_v_107_1 = (helper_flow_1_1 ^ pub_r001337_8_1) & 63;
  int stage_v_107_2 = (helper_flow_1_2 ^ pub_r001337_8_2) & 63;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((stage_v_106_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((stage_v_106_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  }
  int stage_v_108_1 = (stage_v_54_1 ^ pub_r001337_18_1) & 63;
  int stage_v_108_2 = (stage_v_54_2 ^ pub_r001337_18_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((stage_v_34_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  }
  int stage_v_109_1 = (sec_r001337_4_1 ^ pub_r001337_1_1) & 63;
  int stage_v_109_2 = (sec_r001337_4_2 ^ pub_r001337_1_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((stage_v_67_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((stage_v_67_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  }
  int stage_v_110_1 = (stage_v_32_1 ^ pub_r001337_8_1) & 63;
  int stage_v_110_2 = (stage_v_32_2 ^ pub_r001337_8_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((stage_v_95_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((stage_v_95_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  }
  int stage_v_111_1 = (sec_r001337_16_1 ^ pub_r001337_12_1) & 63;
  int stage_v_111_2 = (sec_r001337_16_2 ^ pub_r001337_12_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((stage_v_56_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((stage_v_56_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  }
  int stage_v_112_1 = (stage_v_53_1 ^ pub_r001337_11_1) & 63;
  int stage_v_112_2 = (stage_v_53_2 ^ pub_r001337_11_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((stage_v_45_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  }
  int stage_v_113_1 = ((pub_r001337_6_1 * 2) + 15) & 63;
  int stage_v_113_2 = ((pub_r001337_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (sec_r001337_10_1 ^ pub_r001337_2_1) & 63;
  int stage_v_114_2 = (sec_r001337_10_2 ^ pub_r001337_2_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((stage_v_103_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((stage_v_103_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  }
  int stage_v_115_1 = ((pub_r001337_9_1 * 2) + 48) & 63;
  int stage_v_115_2 = ((pub_r001337_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001337_5_1 * 2) + 18) & 63;
  int stage_v_116_2 = ((pub_r001337_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (stage_v_80_1 ^ pub_r001337_4_1) & 63;
  int stage_v_117_2 = (stage_v_80_2 ^ pub_r001337_4_2) & 63;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r001337_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r001337_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  }
  int stage_v_118_1 = (sec_r001337_6_1 ^ pub_r001337_11_1) & 63;
  int stage_v_118_2 = (sec_r001337_6_2 ^ pub_r001337_11_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_114_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((stage_v_114_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  }
  int stage_v_119_1 = (stage_v_78_1 ^ pub_r001337_12_1) & 63;
  int stage_v_119_2 = (stage_v_78_2 ^ pub_r001337_12_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((helper_flow_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((helper_flow_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  }
  int stage_v_120_1 = ((pub_r001337_6_1 * 2) + 50) & 63;
  int stage_v_120_2 = ((pub_r001337_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (helper_flow_0_1 ^ pub_r001337_20_1) & 63;
  int stage_v_121_2 = (helper_flow_0_2 ^ pub_r001337_20_2) & 63;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((stage_v_58_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((stage_v_58_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  }
  int stage_v_122_1 = (stage_v_97_1 ^ pub_r001337_12_1) & 63;
  int stage_v_122_2 = (stage_v_97_2 ^ pub_r001337_12_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r001337_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r001337_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  }
  int stage_v_123_1 = (sec_r001337_5_1 ^ pub_r001337_6_1) & 63;
  int stage_v_123_2 = (sec_r001337_5_2 ^ pub_r001337_6_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((stage_v_31_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  }
  int stage_v_124_1 = ((pub_r001337_15_1 * 2) + 42) & 63;
  int stage_v_124_2 = ((pub_r001337_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001337_11_1 * 2) + 49) & 63;
  int stage_v_125_2 = ((pub_r001337_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (stage_v_36_1 ^ pub_r001337_6_1) & 63;
  int stage_v_126_2 = (stage_v_36_2 ^ pub_r001337_6_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  }
  int stage_v_127_1 = ((pub_r001337_6_1 * 2) + 21) & 63;
  int stage_v_127_2 = ((pub_r001337_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (helper_flow_9_1 ^ pub_r001337_2_1) & 63;
  int stage_v_128_2 = (helper_flow_9_2 ^ pub_r001337_2_2) & 63;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((stage_v_107_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((stage_v_107_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  }
  int stage_v_129_1 = ((pub_r001337_15_1 * 2) + 11) & 63;
  int stage_v_129_2 = ((pub_r001337_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (stage_v_32_1 ^ pub_r001337_6_1) & 63;
  int stage_v_130_2 = (stage_v_32_2 ^ pub_r001337_6_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  }
  int stage_v_131_1 = (stage_v_98_1 ^ pub_r001337_5_1) & 63;
  int stage_v_131_2 = (stage_v_98_2 ^ pub_r001337_5_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((stage_v_25_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  }
  int stage_v_132_1 = (stage_v_56_1 ^ pub_r001337_15_1) & 63;
  int stage_v_132_2 = (stage_v_56_2 ^ pub_r001337_15_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((sec_r001337_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((sec_r001337_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  }
  int stage_v_133_1 = (stage_v_106_1 ^ pub_r001337_11_1) & 63;
  int stage_v_133_2 = (stage_v_106_2 ^ pub_r001337_11_2) & 63;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((sec_r001337_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((sec_r001337_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  }
  int stage_v_134_1 = (stage_v_5_1 ^ pub_r001337_19_1) & 63;
  int stage_v_134_2 = (stage_v_5_2 ^ pub_r001337_19_2) & 63;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((stage_v_98_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((stage_v_98_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  }
  int stage_v_135_1 = ((pub_r001337_10_1 * 2) + 16) & 63;
  int stage_v_135_2 = ((pub_r001337_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (stage_v_89_1 ^ pub_r001337_20_1) & 63;
  int stage_v_136_2 = (stage_v_89_2 ^ pub_r001337_20_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((stage_v_34_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  }
  int stage_v_137_1 = (stage_v_44_1 ^ pub_r001337_17_1) & 63;
  int stage_v_137_2 = (stage_v_44_2 ^ pub_r001337_17_2) & 63;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((stage_v_69_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((stage_v_69_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  }
  int stage_v_138_1 = (sec_r001337_13_1 ^ pub_r001337_14_1) & 63;
  int stage_v_138_2 = (sec_r001337_13_2 ^ pub_r001337_14_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((stage_v_34_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  }
  int stage_v_139_1 = (stage_v_70_1 ^ pub_r001337_4_1) & 63;
  int stage_v_139_2 = (stage_v_70_2 ^ pub_r001337_4_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((stage_v_82_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((stage_v_82_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  }
  int stage_v_140_1 = (stage_v_61_1 ^ pub_r001337_2_1) & 63;
  int stage_v_140_2 = (stage_v_61_2 ^ pub_r001337_2_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  }
  int stage_v_141_1 = ((pub_r001337_7_1 * 2) + 27) & 63;
  int stage_v_141_2 = ((pub_r001337_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (sec_r001337_5_1 ^ pub_r001337_3_1) & 63;
  int stage_v_142_2 = (sec_r001337_5_2 ^ pub_r001337_3_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  }
  int stage_v_143_1 = ((pub_r001337_7_1 * 2) + 45) & 63;
  int stage_v_143_2 = ((pub_r001337_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001337_20_1 * 2) + 18) & 63;
  int stage_v_144_2 = ((pub_r001337_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001337_4_1 * 2) + 18) & 63;
  int stage_v_145_2 = ((pub_r001337_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (sec_r001337_18_1 ^ pub_r001337_15_1) & 63;
  int stage_v_146_2 = (sec_r001337_18_2 ^ pub_r001337_15_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((stage_v_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  }
  int stage_v_147_1 = (stage_v_7_1 ^ pub_r001337_20_1) & 63;
  int stage_v_147_2 = (stage_v_7_2 ^ pub_r001337_20_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_117_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  }
  if ((stage_v_147_2 & 1) != 0)
  {
    if ((stage_v_117_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  }
  int stage_v_148_1 = ((pub_r001337_8_1 * 2) + 13) & 63;
  int stage_v_148_2 = ((pub_r001337_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001337_19_1 * 2) + 39) & 63;
  int stage_v_149_2 = ((pub_r001337_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (stage_v_58_1 ^ pub_r001337_3_1) & 63;
  int stage_v_150_2 = (stage_v_58_2 ^ pub_r001337_3_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((sec_r001337_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((sec_r001337_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  }
  int stage_v_151_1 = (sec_r001337_10_1 ^ pub_r001337_20_1) & 63;
  int stage_v_151_2 = (sec_r001337_10_2 ^ pub_r001337_20_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  }
  if ((stage_v_151_2 & 1) != 0)
  {
    if ((stage_v_28_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  }
  int stage_v_152_1 = ((pub_r001337_10_1 * 2) + 18) & 63;
  int stage_v_152_2 = ((pub_r001337_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (stage_v_19_1 ^ pub_r001337_8_1) & 63;
  int stage_v_153_2 = (stage_v_19_2 ^ pub_r001337_8_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((stage_v_109_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  }
  if ((stage_v_153_2 & 1) != 0)
  {
    if ((stage_v_109_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  }
  int stage_v_154_1 = (stage_v_23_1 ^ pub_r001337_11_1) & 63;
  int stage_v_154_2 = (stage_v_23_2 ^ pub_r001337_11_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_82_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  }
  if ((stage_v_154_2 & 1) != 0)
  {
    if ((stage_v_82_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  }
  int stage_v_155_1 = (stage_v_70_1 ^ pub_r001337_6_1) & 63;
  int stage_v_155_2 = (stage_v_70_2 ^ pub_r001337_6_2) & 63;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  }
  if ((stage_v_155_2 & 1) != 0)
  {
    if ((stage_v_28_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  }
  int stage_v_156_1 = ((pub_r001337_18_1 * 2) + 42) & 63;
  int stage_v_156_2 = ((pub_r001337_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001337_11_1 * 2) + 46) & 63;
  int stage_v_157_2 = ((pub_r001337_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (stage_v_22_1 ^ pub_r001337_12_1) & 63;
  int stage_v_158_2 = (stage_v_22_2 ^ pub_r001337_12_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((stage_v_102_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  }
  if ((stage_v_158_2 & 1) != 0)
  {
    if ((stage_v_102_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  }
  int stage_v_159_1 = (stage_v_119_1 ^ pub_r001337_10_1) & 63;
  int stage_v_159_2 = (stage_v_119_2 ^ pub_r001337_10_2) & 63;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((stage_v_90_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  }
  if ((stage_v_159_2 & 1) != 0)
  {
    if ((stage_v_90_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  }
  int stage_v_160_1 = ((pub_r001337_9_1 * 2) + 19) & 63;
  int stage_v_160_2 = ((pub_r001337_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (stage_v_66_1 ^ pub_r001337_18_1) & 63;
  int stage_v_161_2 = (stage_v_66_2 ^ pub_r001337_18_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((sec_r001337_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  }
  if ((stage_v_161_2 & 1) != 0)
  {
    if ((sec_r001337_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  }
  int stage_v_162_1 = (sec_r001337_5_1 ^ pub_r001337_14_1) & 63;
  int stage_v_162_2 = (sec_r001337_5_2 ^ pub_r001337_14_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  }
  if ((stage_v_162_2 & 1) != 0)
  {
    if ((stage_v_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  }
  int stage_v_163_1 = (helper_flow_1_1 ^ pub_r001337_20_1) & 63;
  int stage_v_163_2 = (helper_flow_1_2 ^ pub_r001337_20_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_138_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  }
  if ((stage_v_163_2 & 1) != 0)
  {
    if ((stage_v_138_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  }
  int stage_v_164_1 = (sec_r001337_6_1 ^ pub_r001337_5_1) & 63;
  int stage_v_164_2 = (sec_r001337_6_2 ^ pub_r001337_5_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((stage_v_138_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  }
  if ((stage_v_164_2 & 1) != 0)
  {
    if ((stage_v_138_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  }
  int stage_v_165_1 = (stage_v_114_1 ^ pub_r001337_14_1) & 63;
  int stage_v_165_2 = (stage_v_114_2 ^ pub_r001337_14_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_121_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  }
  if ((stage_v_165_2 & 1) != 0)
  {
    if ((stage_v_121_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  }
  int stage_v_166_1 = ((pub_r001337_8_1 * 2) + 11) & 63;
  int stage_v_166_2 = ((pub_r001337_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (stage_v_75_1 ^ pub_r001337_15_1) & 63;
  int stage_v_167_2 = (stage_v_75_2 ^ pub_r001337_15_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  }
  if ((stage_v_167_2 & 1) != 0)
  {
    if ((stage_v_26_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  }
  int stage_v_168_1 = (stage_v_103_1 ^ pub_r001337_4_1) & 63;
  int stage_v_168_2 = (stage_v_103_2 ^ pub_r001337_4_2) & 63;
  if ((stage_v_168_1 & 1) != 0)
  {
    if ((stage_v_151_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  }
  if ((stage_v_168_2 & 1) != 0)
  {
    if ((stage_v_151_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  }
  int stage_v_169_1 = ((pub_r001337_1_1 * 2) + 21) & 63;
  int stage_v_169_2 = ((pub_r001337_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (stage_v_34_1 ^ pub_r001337_5_1) & 63;
  int stage_v_170_2 = (stage_v_34_2 ^ pub_r001337_5_2) & 63;
  if ((stage_v_170_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_170_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  }
  if ((stage_v_170_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_170_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  }
  int stage_v_171_1 = (stage_v_142_1 ^ pub_r001337_20_1) & 63;
  int stage_v_171_2 = (stage_v_142_2 ^ pub_r001337_20_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((stage_v_137_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_171_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  }
  if ((stage_v_171_2 & 1) != 0)
  {
    if ((stage_v_137_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_171_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  }
  int stage_v_172_1 = ((pub_r001337_5_1 * 2) + 36) & 63;
  int stage_v_172_2 = ((pub_r001337_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (stage_v_71_1 ^ pub_r001337_5_1) & 63;
  int stage_v_173_2 = (stage_v_71_2 ^ pub_r001337_5_2) & 63;
  if ((stage_v_173_1 & 1) != 0)
  {
    if ((stage_v_128_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  }
  if ((stage_v_173_2 & 1) != 0)
  {
    if ((stage_v_128_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  }
  int stage_v_174_1 = ((pub_r001337_8_1 * 2) + 27) & 63;
  int stage_v_174_2 = ((pub_r001337_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001337_15_1 * 2) + 26) & 63;
  int stage_v_175_2 = ((pub_r001337_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (stage_v_132_1 ^ pub_r001337_16_1) & 63;
  int stage_v_176_2 = (stage_v_132_2 ^ pub_r001337_16_2) & 63;
  if ((stage_v_176_1 & 1) != 0)
  {
    if ((stage_v_154_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  }
  if ((stage_v_176_2 & 1) != 0)
  {
    if ((stage_v_154_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  }
  int stage_v_177_1 = (sec_r001337_16_1 ^ pub_r001337_8_1) & 63;
  int stage_v_177_2 = (sec_r001337_16_2 ^ pub_r001337_8_2) & 63;
  if ((stage_v_177_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_177_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  }
  if ((stage_v_177_2 & 1) != 0)
  {
    if ((stage_v_33_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_177_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  }
  int stage_v_178_1 = (stage_v_153_1 ^ pub_r001337_4_1) & 63;
  int stage_v_178_2 = (stage_v_153_2 ^ pub_r001337_4_2) & 63;
  if ((stage_v_178_1 & 1) != 0)
  {
    if ((stage_v_74_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_178_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  }
  if ((stage_v_178_2 & 1) != 0)
  {
    if ((stage_v_74_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_178_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  }
  int stage_v_179_1 = (stage_v_37_1 ^ pub_r001337_19_1) & 63;
  int stage_v_179_2 = (stage_v_37_2 ^ pub_r001337_19_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((sec_r001337_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_179_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  }
  if ((stage_v_179_2 & 1) != 0)
  {
    if ((sec_r001337_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_179_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  }
  int stage_v_180_1 = (stage_v_82_1 ^ pub_r001337_9_1) & 63;
  int stage_v_180_2 = (stage_v_82_2 ^ pub_r001337_9_2) & 63;
  if ((stage_v_180_1 & 1) != 0)
  {
    if ((stage_v_63_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_180_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  }
  if ((stage_v_180_2 & 1) != 0)
  {
    if ((stage_v_63_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_180_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  }
  int stage_v_181_1 = (stage_v_106_1 ^ pub_r001337_1_1) & 63;
  int stage_v_181_2 = (stage_v_106_2 ^ pub_r001337_1_2) & 63;
  if ((stage_v_181_1 & 1) != 0)
  {
    if ((stage_v_121_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_181_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  }
  if ((stage_v_181_2 & 1) != 0)
  {
    if ((stage_v_121_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_181_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  }
  int stage_v_182_1 = (stage_v_79_1 ^ pub_r001337_17_1) & 63;
  int stage_v_182_2 = (stage_v_79_2 ^ pub_r001337_17_2) & 63;
  if ((stage_v_182_1 & 1) != 0)
  {
    if ((stage_v_75_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_182_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  }
  if ((stage_v_182_2 & 1) != 0)
  {
    if ((stage_v_75_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_182_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  }
  int stage_v_183_1 = (stage_v_180_1 ^ pub_r001337_14_1) & 63;
  int stage_v_183_2 = (stage_v_180_2 ^ pub_r001337_14_2) & 63;
  if ((stage_v_183_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  }
  if ((stage_v_183_2 & 1) != 0)
  {
    if ((stage_v_44_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001337_1_1 == pub_r001337_1_2);
  __CPROVER_assume(pub_r001337_8_1 == pub_r001337_8_2);
  __CPROVER_assume(pub_r001337_10_1 == pub_r001337_10_2);
  __CPROVER_assume(sec_r001337_16_1 != sec_r001337_16_2);
  __CPROVER_assume(sec_r001337_2_1 != sec_r001337_2_2);
  __CPROVER_assume(sec_r001337_9_1 != sec_r001337_9_2);
  __CPROVER_assume(sec_r001337_14_1 != sec_r001337_14_2);
  __CPROVER_assume(pub_r001337_17_1 == pub_r001337_17_2);
  __CPROVER_assume(sec_r001337_12_1 != sec_r001337_12_2);
  __CPROVER_assume(sec_r001337_8_1 != sec_r001337_8_2);
  __CPROVER_assume(pub_r001337_15_1 == pub_r001337_15_2);
  __CPROVER_assume(sec_r001337_10_1 != sec_r001337_10_2);
  __CPROVER_assume(pub_r001337_4_1 == pub_r001337_4_2);
  __CPROVER_assume(pub_r001337_11_1 == pub_r001337_11_2);
  __CPROVER_assume(pub_r001337_19_1 == pub_r001337_19_2);
  __CPROVER_assume(sec_r001337_4_1 != sec_r001337_4_2);
  __CPROVER_assume(sec_r001337_18_1 != sec_r001337_18_2);
  __CPROVER_assume(pub_r001337_14_1 == pub_r001337_14_2);
  __CPROVER_assume(pub_r001337_3_1 == pub_r001337_3_2);
  __CPROVER_assume(pub_r001337_16_1 == pub_r001337_16_2);
  __CPROVER_assume(pub_r001337_5_1 == pub_r001337_5_2);
  __CPROVER_assume(sec_r001337_7_1 != sec_r001337_7_2);
  __CPROVER_assume(pub_r001337_18_1 == pub_r001337_18_2);
  __CPROVER_assume(sec_r001337_11_1 != sec_r001337_11_2);
  __CPROVER_assume(pub_r001337_2_1 == pub_r001337_2_2);
  __CPROVER_assume(pub_r001337_20_1 == pub_r001337_20_2);
  __CPROVER_assume(sec_r001337_6_1 != sec_r001337_6_2);
  __CPROVER_assume(sec_r001337_15_1 != sec_r001337_15_2);
  __CPROVER_assume(sec_r001337_1_1 != sec_r001337_1_2);
  __CPROVER_assume(pub_r001337_0_1 == pub_r001337_0_2);
  __CPROVER_assume(sec_r001337_0_1 != sec_r001337_0_2);
  __CPROVER_assume(pub_r001337_9_1 == pub_r001337_9_2);
  __CPROVER_assume(pub_r001337_6_1 == pub_r001337_6_2);
  __CPROVER_assume(sec_r001337_5_1 != sec_r001337_5_2);
  __CPROVER_assume(sec_r001337_3_1 != sec_r001337_3_2);
  __CPROVER_assume(sec_r001337_13_1 != sec_r001337_13_2);
  __CPROVER_assume(pub_r001337_7_1 == pub_r001337_7_2);
  __CPROVER_assume(sec_r001337_17_1 != sec_r001337_17_2);
  __CPROVER_assume(pub_r001337_12_1 == pub_r001337_12_2);
  __CPROVER_assume(pub_r001337_13_1 == pub_r001337_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
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
}


