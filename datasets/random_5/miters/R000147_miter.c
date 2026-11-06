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
struct SensorNode_R000147_4713_0
{
  short threshold;
  unsigned char calib;
  int offset;
  int reading;
  int buffer[3];
};
struct DeviceConfig_R000147_4713_1
{
  int parity;
  short baud_rate;
  int timeout;
  int buffer[3];
};
struct Transaction_R000147_4713_2
{
  int fee;
  int rate;
  int auth_code;
  int status;
  int buffer[3];
};
struct EventLog_R000147_4713_3
{
  short facility;
  unsigned char signature;
  unsigned char timestamp;
  unsigned char seq;
  int buffer[3];
};
union ColorPixel_R000147_4713_0
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
void fn_R000147_4713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st_1 = {0};
  struct DeviceConfig_R000147_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int offset_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_63_1 > 43)
  {
    acc_1 = ((acc_1 + (offset_63_1 * 2)) + 5) & 127;
    aux_1 ^= offset_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_63_2 > 43)
  {
    acc_2 = ((acc_2 + (offset_63_2 * 2)) + 5) & 127;
    aux_2 ^= offset_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_63_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_74_1)
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

  switch (quotient_74_2)
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
  int factor_89_1 = local_arr_1[aux_1 % 3];
  int factor_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_63_1 == offset_63_2);
  assert(quotient_74_1 == quotient_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_89_1 == factor_89_2);
}

int fn_R000147_4713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int offset_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_63 > 43)
  {
    acc = ((acc + (offset_63 * 2)) + 5) & 127;
    aux ^= offset_63 & 15;
  }
  else
  {
    acc = ((acc - offset_63) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_74 = (aux + st.buffer[1]) & 3;
  switch (quotient_74)
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
  int factor_89 = local_arr[aux % 3];
  acc = (acc + (factor_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000147_4713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st_1 = {0};
  struct DeviceConfig_R000147_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int weight_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_17_1) & 63;
  aux_2 = (aux_2 + weight_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_77_1 = local_arr_1[aux_1 % 3];
  int stride_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_17_1 == weight_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_77_1 == stride_77_2);
}

int fn_R000147_4713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int weight_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_17) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_77 = local_arr[aux % 3];
  acc = (acc + (stride_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000147_4713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st_1 = {0};
  struct DeviceConfig_R000147_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int vector_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_20_1) & 63;
  aux_2 = (aux_2 + vector_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_73_1 > 22)
  {
    acc_1 = ((acc_1 + (parity_73_1 * 2)) + 5) & 127;
    aux_1 ^= parity_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_73_2 > 22)
  {
    acc_2 = ((acc_2 + (parity_73_2 * 2)) + 5) & 127;
    aux_2 ^= parity_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_20_1 == vector_20_2);
  assert(parity_73_1 == parity_73_2);
}

int fn_R000147_4713_2(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int vector_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_20) & 63;
  acc ^= aux;
  int parity_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_73 > 22)
  {
    acc = ((acc + (parity_73 * 2)) + 5) & 127;
    aux ^= parity_73 & 15;
  }
  else
  {
    acc = ((acc - parity_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000147_4713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000147_4713_3 st_1 = {0};
  struct EventLog_R000147_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int quantum_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_57_1 > 35)
  {
    acc_1 = ((acc_1 + (quantum_57_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_57_2 > 35)
  {
    acc_2 = ((acc_2 + (quantum_57_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_47_1)
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

  switch (coefficient_47_2)
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
  int segment_45_1 = local_arr_1[aux_1 % 3];
  int segment_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_45_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_57_1 == quantum_57_2);
  assert(coefficient_47_1 == coefficient_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_45_1 == segment_45_2);
}

int fn_R000147_4713_3(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000147_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int quantum_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_57 > 35)
  {
    acc = ((acc + (quantum_57 * 2)) + 5) & 127;
    aux ^= quantum_57 & 15;
  }
  else
  {
    acc = ((acc - quantum_57) + 11) & 127;
    aux += 3;
  }
  int coefficient_47 = (aux + st.buffer[1]) & 3;
  switch (coefficient_47)
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
  int segment_45 = local_arr[aux % 3];
  acc = (acc + (segment_45 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000147_4713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000147_4713_2 st_1 = {0};
  struct Transaction_R000147_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int accumulator_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_92_1) & 63;
  aux_2 = (aux_2 + accumulator_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_82_1 > 20)
  {
    acc_1 = ((acc_1 + (margin_82_1 * 2)) + 5) & 127;
    aux_1 ^= margin_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_82_2 > 20)
  {
    acc_2 = ((acc_2 + (margin_82_2 * 2)) + 5) & 127;
    aux_2 ^= margin_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_88_1 = local_arr_1[aux_1 % 3];
  int phase_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_88_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_92_1 == accumulator_92_2);
  assert(margin_82_1 == margin_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_88_1 == phase_88_2);
}

int fn_R000147_4713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000147_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int accumulator_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_92) & 63;
  acc ^= aux;
  int margin_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_82 > 20)
  {
    acc = ((acc + (margin_82 * 2)) + 5) & 127;
    aux ^= margin_82 & 15;
  }
  else
  {
    acc = ((acc - margin_82) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_88 = local_arr[aux % 3];
  acc = (acc + (phase_88 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000147_4713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000147_4713_2 st_1 = {0};
  struct Transaction_R000147_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int factor_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_28_1) & 63;
  aux_2 = (aux_2 + factor_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_78_1 > 17)
  {
    acc_1 = ((acc_1 + (segment_78_1 * 2)) + 5) & 127;
    aux_1 ^= segment_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_78_2 > 17)
  {
    acc_2 = ((acc_2 + (segment_78_2 * 2)) + 5) & 127;
    aux_2 ^= segment_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_54_1)
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

  switch (pivot_54_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_28_1 == factor_28_2);
  assert(segment_78_1 == segment_78_2);
  assert(pivot_54_1 == pivot_54_2);
}

int fn_R000147_4713_5(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000147_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int factor_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_28) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_78 > 17)
  {
    acc = ((acc + (segment_78 * 2)) + 5) & 127;
    aux ^= segment_78 & 15;
  }
  else
  {
    acc = ((acc - segment_78) + 11) & 127;
    aux += 3;
  }
  int pivot_54 = (aux + st.buffer[1]) & 3;
  switch (pivot_54)
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

void fn_R000147_4713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st_1 = {0};
  struct DeviceConfig_R000147_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_99_1 = local_arr_1[aux_1 % 3];
  int parity_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_99_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_21_1) & 63;
  aux_2 = (aux_2 + bound_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_86_1)
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

  switch (metric_86_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_99_1 == parity_99_2);
  assert(bound_21_1 == bound_21_2);
  assert(metric_86_1 == metric_86_2);
}

int fn_R000147_4713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int parity_99 = local_arr[aux % 3];
  acc = (acc + (parity_99 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_21) & 63;
  acc ^= aux;
  int metric_86 = (aux + st.buffer[1]) & 3;
  switch (metric_86)
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

void fn_R000147_4713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st_1 = {0};
  struct DeviceConfig_R000147_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int offset_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_58_1 > 42)
  {
    acc_1 = ((acc_1 + (offset_58_1 * 2)) + 5) & 127;
    aux_1 ^= offset_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_58_2 > 42)
  {
    acc_2 = ((acc_2 + (offset_58_2 * 2)) + 5) & 127;
    aux_2 ^= offset_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_11_1 = local_arr_1[aux_1 % 3];
  int offset_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_58_1 == offset_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_11_1 == offset_11_2);
}

int fn_R000147_4713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int offset_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_58 > 42)
  {
    acc = ((acc + (offset_58 * 2)) + 5) & 127;
    aux ^= offset_58 & 15;
  }
  else
  {
    acc = ((acc - offset_58) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_11 = local_arr[aux % 3];
  acc = (acc + (offset_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000147_4713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000147_4713_2 st_1 = {0};
  struct Transaction_R000147_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int anchor_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_33_1)
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

  switch (anchor_33_2)
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

  int tracker_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_50_1 > 43)
  {
    acc_1 = ((acc_1 + (tracker_50_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_50_2 > 43)
  {
    acc_2 = ((acc_2 + (tracker_50_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_12_1 = local_arr_1[aux_1 % 3];
  int index_reg_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_12_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_33_1 == anchor_33_2);
  assert(tracker_50_1 == tracker_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_12_1 == index_reg_12_2);
}

int fn_R000147_4713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000147_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int anchor_33 = (aux + st.buffer[1]) & 3;
  switch (anchor_33)
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

  int tracker_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_50 > 43)
  {
    acc = ((acc + (tracker_50 * 2)) + 5) & 127;
    aux ^= tracker_50 & 15;
  }
  else
  {
    acc = ((acc - tracker_50) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_12 = local_arr[aux % 3];
  acc = (acc + (index_reg_12 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000147_4713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000147_4713_2 st_1 = {0};
  struct Transaction_R000147_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_11_1 = local_arr_1[aux_1 % 3];
  int window_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_11_2 * 2)) & 127;
  int coefficient_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_96_1 > 44)
  {
    acc_1 = ((acc_1 + (coefficient_96_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_96_2 > 44)
  {
    acc_2 = ((acc_2 + (coefficient_96_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_11_1 == window_11_2);
  assert(coefficient_96_1 == coefficient_96_2);
}

int fn_R000147_4713_9(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000147_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int window_11 = local_arr[aux % 3];
  acc = (acc + (window_11 * 2)) & 127;
  int coefficient_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_96 > 44)
  {
    acc = ((acc + (coefficient_96 * 2)) + 5) & 127;
    aux ^= coefficient_96 & 15;
  }
  else
  {
    acc = ((acc - coefficient_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000147_4713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000147_4713_3 st_1 = {0};
  struct EventLog_R000147_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_87_1 = local_arr_1[aux_1 % 3];
  int tally_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_87_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_87_1 == tally_87_2);
}

int fn_R000147_4713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000147_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int tally_87 = local_arr[aux % 3];
  acc = (acc + (tally_87 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000147_4713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000147_4713_3 st_1 = {0};
  struct EventLog_R000147_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int factor_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_59_1 > 34)
  {
    acc_1 = ((acc_1 + (factor_59_1 * 2)) + 5) & 127;
    aux_1 ^= factor_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_59_2 > 34)
  {
    acc_2 = ((acc_2 + (factor_59_2 * 2)) + 5) & 127;
    aux_2 ^= factor_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_75_1) & 63;
  aux_2 = (aux_2 + tracker_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_92_1)
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

  switch (factor_92_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_59_1 == factor_59_2);
  assert(tracker_75_1 == tracker_75_2);
  assert(factor_92_1 == factor_92_2);
}

int fn_R000147_4713_11(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000147_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int factor_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_59 > 34)
  {
    acc = ((acc + (factor_59 * 2)) + 5) & 127;
    aux ^= factor_59 & 15;
  }
  else
  {
    acc = ((acc - factor_59) + 11) & 127;
    aux += 3;
  }
  int tracker_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_75) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_92 = (aux + st.buffer[1]) & 3;
  switch (factor_92)
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

void fn_R000147_4713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st_1 = {0};
  struct DeviceConfig_R000147_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int stride_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_64_1)
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

  switch (stride_64_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_64_1 == stride_64_2);
}

int fn_R000147_4713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int stride_64 = (aux + st.buffer[1]) & 3;
  switch (stride_64)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000147_4713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000147_4713_0 st_1 = {0};
  struct SensorNode_R000147_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int damping_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_25_1) & 63;
  aux_2 = (aux_2 + damping_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_44_1 > 23)
  {
    acc_1 = ((acc_1 + (checksum_44_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_44_2 > 23)
  {
    acc_2 = ((acc_2 + (checksum_44_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_14_1 = local_arr_1[aux_1 % 3];
  int metric_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_14_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_25_1 == damping_25_2);
  assert(checksum_44_1 == checksum_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_14_1 == metric_14_2);
}

int fn_R000147_4713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000147_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int damping_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_25) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_44 > 23)
  {
    acc = ((acc + (checksum_44 * 2)) + 5) & 127;
    aux ^= checksum_44 & 15;
  }
  else
  {
    acc = ((acc - checksum_44) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_14 = local_arr[aux % 3];
  acc = (acc + (metric_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000147_4713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st_1 = {0};
  struct DeviceConfig_R000147_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_32_1 = local_arr_1[aux_1 % 3];
  int coefficient_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_32_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_58_1) & 63;
  aux_2 = (aux_2 + segment_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_32_1 == coefficient_32_2);
  assert(segment_58_1 == segment_58_2);
}

int fn_R000147_4713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000147_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int coefficient_32 = local_arr[aux % 3];
  acc = (acc + (coefficient_32 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000147_0_1;
  int sec_r000147_0_2;
  int sec_r000147_1_1;
  int sec_r000147_1_2;
  int sec_r000147_2_1;
  int sec_r000147_2_2;
  int sec_r000147_3_1;
  int sec_r000147_3_2;
  int sec_r000147_4_1;
  int sec_r000147_4_2;
  int sec_r000147_5_1;
  int sec_r000147_5_2;
  int sec_r000147_6_1;
  int sec_r000147_6_2;
  int sec_r000147_7_1;
  int sec_r000147_7_2;
  int sec_r000147_8_1;
  int sec_r000147_8_2;
  int sec_r000147_9_1;
  int sec_r000147_9_2;
  int sec_r000147_10_1;
  int sec_r000147_10_2;
  int sec_r000147_11_1;
  int sec_r000147_11_2;
  int sec_r000147_12_1;
  int sec_r000147_12_2;
  int sec_r000147_13_1;
  int sec_r000147_13_2;
  int sec_r000147_14_1;
  int sec_r000147_14_2;
  int sec_r000147_15_1;
  int sec_r000147_15_2;
  int sec_r000147_16_1;
  int sec_r000147_16_2;
  int sec_r000147_17_1;
  int sec_r000147_17_2;
  int sec_r000147_18_1;
  int sec_r000147_18_2;
  int sec_r000147_19_1;
  int sec_r000147_19_2;
  int sec_r000147_20_1;
  int sec_r000147_20_2;
  int pub_r000147_0_1;
  int pub_r000147_0_2;
  int pub_r000147_1_1;
  int pub_r000147_1_2;
  int pub_r000147_2_1;
  int pub_r000147_2_2;
  int pub_r000147_3_1;
  int pub_r000147_3_2;
  int pub_r000147_4_1;
  int pub_r000147_4_2;
  int pub_r000147_5_1;
  int pub_r000147_5_2;
  int pub_r000147_6_1;
  int pub_r000147_6_2;
  int pub_r000147_7_1;
  int pub_r000147_7_2;
  int pub_r000147_8_1;
  int pub_r000147_8_2;
  int pub_r000147_9_1;
  int pub_r000147_9_2;
  int pub_r000147_10_1;
  int pub_r000147_10_2;
  int pub_r000147_11_1;
  int pub_r000147_11_2;
  int pub_r000147_12_1;
  int pub_r000147_12_2;
  int pub_r000147_13_1;
  int pub_r000147_13_2;
  int pub_r000147_14_1;
  int pub_r000147_14_2;
  int pub_r000147_15_1;
  int pub_r000147_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000147_0_1 >= (-100)) && (pub_r000147_0_1 <= 100));
  __CPROVER_assume((pub_r000147_0_2 >= (-100)) && (pub_r000147_0_2 <= 100));
  __CPROVER_assume((pub_r000147_1_1 >= (-100)) && (pub_r000147_1_1 <= 100));
  __CPROVER_assume((pub_r000147_1_2 >= (-100)) && (pub_r000147_1_2 <= 100));
  __CPROVER_assume((pub_r000147_2_1 >= (-100)) && (pub_r000147_2_1 <= 100));
  __CPROVER_assume((pub_r000147_2_2 >= (-100)) && (pub_r000147_2_2 <= 100));
  __CPROVER_assume((pub_r000147_3_1 >= (-100)) && (pub_r000147_3_1 <= 100));
  __CPROVER_assume((pub_r000147_3_2 >= (-100)) && (pub_r000147_3_2 <= 100));
  __CPROVER_assume((pub_r000147_4_1 >= (-100)) && (pub_r000147_4_1 <= 100));
  __CPROVER_assume((pub_r000147_4_2 >= (-100)) && (pub_r000147_4_2 <= 100));
  __CPROVER_assume((pub_r000147_5_1 >= (-100)) && (pub_r000147_5_1 <= 100));
  __CPROVER_assume((pub_r000147_5_2 >= (-100)) && (pub_r000147_5_2 <= 100));
  __CPROVER_assume((pub_r000147_6_1 >= (-100)) && (pub_r000147_6_1 <= 100));
  __CPROVER_assume((pub_r000147_6_2 >= (-100)) && (pub_r000147_6_2 <= 100));
  __CPROVER_assume((pub_r000147_7_1 >= (-100)) && (pub_r000147_7_1 <= 100));
  __CPROVER_assume((pub_r000147_7_2 >= (-100)) && (pub_r000147_7_2 <= 100));
  __CPROVER_assume((pub_r000147_8_1 >= (-100)) && (pub_r000147_8_1 <= 100));
  __CPROVER_assume((pub_r000147_8_2 >= (-100)) && (pub_r000147_8_2 <= 100));
  __CPROVER_assume((pub_r000147_9_1 >= (-100)) && (pub_r000147_9_1 <= 100));
  __CPROVER_assume((pub_r000147_9_2 >= (-100)) && (pub_r000147_9_2 <= 100));
  __CPROVER_assume((pub_r000147_10_1 >= (-100)) && (pub_r000147_10_1 <= 100));
  __CPROVER_assume((pub_r000147_10_2 >= (-100)) && (pub_r000147_10_2 <= 100));
  __CPROVER_assume((pub_r000147_11_1 >= (-100)) && (pub_r000147_11_1 <= 100));
  __CPROVER_assume((pub_r000147_11_2 >= (-100)) && (pub_r000147_11_2 <= 100));
  __CPROVER_assume((pub_r000147_12_1 >= (-100)) && (pub_r000147_12_1 <= 100));
  __CPROVER_assume((pub_r000147_12_2 >= (-100)) && (pub_r000147_12_2 <= 100));
  __CPROVER_assume((pub_r000147_13_1 >= (-100)) && (pub_r000147_13_1 <= 100));
  __CPROVER_assume((pub_r000147_13_2 >= (-100)) && (pub_r000147_13_2 <= 100));
  __CPROVER_assume((pub_r000147_14_1 >= (-100)) && (pub_r000147_14_1 <= 100));
  __CPROVER_assume((pub_r000147_14_2 >= (-100)) && (pub_r000147_14_2 <= 100));
  __CPROVER_assume((pub_r000147_15_1 >= (-100)) && (pub_r000147_15_1 <= 100));
  __CPROVER_assume((pub_r000147_15_2 >= (-100)) && (pub_r000147_15_2 <= 100));
  __CPROVER_assume((sec_r000147_0_1 >= 0) && (sec_r000147_0_1 <= 255));
  __CPROVER_assume((sec_r000147_0_2 >= 0) && (sec_r000147_0_2 <= 255));
  __CPROVER_assume((sec_r000147_1_1 >= 0) && (sec_r000147_1_1 <= 255));
  __CPROVER_assume((sec_r000147_1_2 >= 0) && (sec_r000147_1_2 <= 255));
  __CPROVER_assume((sec_r000147_2_1 >= 0) && (sec_r000147_2_1 <= 255));
  __CPROVER_assume((sec_r000147_2_2 >= 0) && (sec_r000147_2_2 <= 255));
  __CPROVER_assume((sec_r000147_3_1 >= 0) && (sec_r000147_3_1 <= 255));
  __CPROVER_assume((sec_r000147_3_2 >= 0) && (sec_r000147_3_2 <= 255));
  __CPROVER_assume((sec_r000147_4_1 >= 0) && (sec_r000147_4_1 <= 255));
  __CPROVER_assume((sec_r000147_4_2 >= 0) && (sec_r000147_4_2 <= 255));
  __CPROVER_assume((sec_r000147_5_1 >= 0) && (sec_r000147_5_1 <= 255));
  __CPROVER_assume((sec_r000147_5_2 >= 0) && (sec_r000147_5_2 <= 255));
  __CPROVER_assume((sec_r000147_6_1 >= 0) && (sec_r000147_6_1 <= 255));
  __CPROVER_assume((sec_r000147_6_2 >= 0) && (sec_r000147_6_2 <= 255));
  __CPROVER_assume((sec_r000147_7_1 >= 0) && (sec_r000147_7_1 <= 255));
  __CPROVER_assume((sec_r000147_7_2 >= 0) && (sec_r000147_7_2 <= 255));
  __CPROVER_assume((sec_r000147_8_1 >= 0) && (sec_r000147_8_1 <= 255));
  __CPROVER_assume((sec_r000147_8_2 >= 0) && (sec_r000147_8_2 <= 255));
  __CPROVER_assume((sec_r000147_9_1 >= 0) && (sec_r000147_9_1 <= 255));
  __CPROVER_assume((sec_r000147_9_2 >= 0) && (sec_r000147_9_2 <= 255));
  __CPROVER_assume((sec_r000147_10_1 >= 0) && (sec_r000147_10_1 <= 255));
  __CPROVER_assume((sec_r000147_10_2 >= 0) && (sec_r000147_10_2 <= 255));
  __CPROVER_assume((sec_r000147_11_1 >= 0) && (sec_r000147_11_1 <= 255));
  __CPROVER_assume((sec_r000147_11_2 >= 0) && (sec_r000147_11_2 <= 255));
  __CPROVER_assume((sec_r000147_12_1 >= 0) && (sec_r000147_12_1 <= 255));
  __CPROVER_assume((sec_r000147_12_2 >= 0) && (sec_r000147_12_2 <= 255));
  __CPROVER_assume((sec_r000147_13_1 >= 0) && (sec_r000147_13_1 <= 255));
  __CPROVER_assume((sec_r000147_13_2 >= 0) && (sec_r000147_13_2 <= 255));
  __CPROVER_assume((sec_r000147_14_1 >= 0) && (sec_r000147_14_1 <= 255));
  __CPROVER_assume((sec_r000147_14_2 >= 0) && (sec_r000147_14_2 <= 255));
  __CPROVER_assume((sec_r000147_15_1 >= 0) && (sec_r000147_15_1 <= 255));
  __CPROVER_assume((sec_r000147_15_2 >= 0) && (sec_r000147_15_2 <= 255));
  __CPROVER_assume((sec_r000147_16_1 >= 0) && (sec_r000147_16_1 <= 255));
  __CPROVER_assume((sec_r000147_16_2 >= 0) && (sec_r000147_16_2 <= 255));
  __CPROVER_assume((sec_r000147_17_1 >= 0) && (sec_r000147_17_1 <= 255));
  __CPROVER_assume((sec_r000147_17_2 >= 0) && (sec_r000147_17_2 <= 255));
  __CPROVER_assume((sec_r000147_18_1 >= 0) && (sec_r000147_18_1 <= 255));
  __CPROVER_assume((sec_r000147_18_2 >= 0) && (sec_r000147_18_2 <= 255));
  __CPROVER_assume((sec_r000147_19_1 >= 0) && (sec_r000147_19_1 <= 255));
  __CPROVER_assume((sec_r000147_19_2 >= 0) && (sec_r000147_19_2 <= 255));
  __CPROVER_assume((sec_r000147_20_1 >= 0) && (sec_r000147_20_1 <= 255));
  __CPROVER_assume((sec_r000147_20_2 >= 0) && (sec_r000147_20_2 <= 255));
  struct SensorNode_R000147_4713_0 st_var_0_1 = {0};
  struct SensorNode_R000147_4713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000147_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000147_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000147_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000147_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000147_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000147_0_2 + 7) & 15;
  struct DeviceConfig_R000147_4713_1 st_var_1_1 = {0};
  struct DeviceConfig_R000147_4713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000147_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000147_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000147_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000147_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000147_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000147_0_2 + 9) & 15;
  struct Transaction_R000147_4713_2 st_var_2_1 = {0};
  struct Transaction_R000147_4713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000147_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000147_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000147_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000147_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000147_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000147_0_2 + 11) & 15;
  struct EventLog_R000147_4713_3 st_var_3_1 = {0};
  struct EventLog_R000147_4713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000147_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000147_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000147_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000147_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000147_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000147_0_2 + 13) & 15;
  union ColorPixel_R000147_4713_0 u_var_1;
  union ColorPixel_R000147_4713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 26)
    {
      chk_sum_1 ^= stage_v_0_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_0_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 26)
    {
      chk_sum_2 ^= stage_v_0_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 32)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 32)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 55)
    {
      chk_sum_1 ^= stage_v_2_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_2_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 55)
    {
      chk_sum_2 ^= stage_v_2_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = ((st_var_3_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_3_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 27)
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
  if (stage_v_11_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 27)
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
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 38)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 38)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = ((st_var_2_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_2_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 35)
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
  if (stage_v_18_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 35)
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
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 24) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 40)
    {
      chk_sum_1 ^= stage_v_25_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_25_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 40)
    {
      chk_sum_2 ^= stage_v_25_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 55)
    {
      chk_sum_1 ^= stage_v_26_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_26_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 55)
    {
      chk_sum_2 ^= stage_v_26_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 34)
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
  if (stage_v_29_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 34)
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
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 31) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (st_var_0_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_0_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 35) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  int stage_v_37_1 = table_1[1];
  int stage_v_37_2 = table_2[1];
  table_1[1] = (table_1[2] + 75) & 63;
  table_2[1] = (table_2[2] + 75) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 40) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 35)
    {
      chk_sum_1 ^= stage_v_41_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_41_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 35)
    {
      chk_sum_2 ^= stage_v_41_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = ((st_var_1_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_1_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 32)
    {
      chk_sum_1 ^= stage_v_45_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_45_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 32)
    {
      chk_sum_2 ^= stage_v_45_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_46_1 = (st_var_2_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_2_2.buffer[0] ^ 49) & 3;
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 48) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 48) & 15;
  int stage_v_47_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_47_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= stage_v_47_1;
  chk_sum_2 ^= stage_v_47_2;
  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 51) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_52_1 = (st_var_0_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_0_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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

  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = ((st_var_0_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_0_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 54)
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
  if (stage_v_56_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 54)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 58) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = table_1[3];
  int stage_v_59_2 = table_2[3];
  table_1[3] = (table_1[0] + 119) & 63;
  table_2[3] = (table_2[0] + 119) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_65_1 = (st_var_1_1.buffer[0] ^ 68) & 3;
  int stage_v_65_2 = (st_var_1_2.buffer[0] ^ 68) & 3;
  switch (stage_v_65_1)
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

  switch (stage_v_65_2)
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

  int stage_v_66_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (71 & 31);
  int stage_v_66_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (71 & 31);
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= (stage_v_66_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_66_2 << 1) & 127;
  int stage_v_67_1 = (st_var_3_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_3_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 69) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  int stage_v_69_1 = table_1[1];
  int stage_v_69_2 = table_2[1];
  table_1[1] = (table_1[2] + 139) & 63;
  table_2[1] = (table_2[2] + 139) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (st_var_2_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_2_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 72) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (77 & 31);
  int stage_v_72_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (77 & 31);
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= (stage_v_72_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_72_2 << 1) & 127;
  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 77) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 78) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  int stage_v_78_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (83 & 31);
  int stage_v_78_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (83 & 31);
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= (stage_v_78_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_78_2 << 1) & 127;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_80_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_81_1 = table_1[1];
  int stage_v_81_2 = table_2[1];
  table_1[1] = (table_1[2] + 163) & 63;
  table_2[1] = (table_2[2] + 163) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (st_var_2_1.buffer[0] ^ 85) & 3;
  int stage_v_82_2 = (st_var_2_2.buffer[0] ^ 85) & 3;
  switch (stage_v_82_1)
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

  switch (stage_v_82_2)
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

  int stage_v_83_1 = (st_var_3_1.buffer[0] ^ 86) & 3;
  int stage_v_83_2 = (st_var_3_2.buffer[0] ^ 86) & 3;
  switch (stage_v_83_1)
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

  switch (stage_v_83_2)
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

  switch (stage_v_85_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 87) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 87) & 15;
  int stage_v_86_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_86_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= stage_v_86_1;
  chk_sum_2 ^= stage_v_86_2;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 88) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 88) & 15;
  int stage_v_87_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_87_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  chk_sum_1 ^= stage_v_87_1;
  chk_sum_2 ^= stage_v_87_2;
  int stage_v_88_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (93 & 31);
  int stage_v_88_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (93 & 31);
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= (stage_v_88_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_88_2 << 1) & 127;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000147_6_1 & 1) != 0)
  {
    if ((sec_r000147_17_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000147_15_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000147_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000147_15_1 + 7) & 127;
  }
  if ((sec_r000147_6_2 & 1) != 0)
  {
    if ((sec_r000147_17_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000147_15_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000147_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000147_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000147_6_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000147_5_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000147_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000147_5_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000147_6_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000147_5_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000147_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000147_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000147_0_1 & 1) != 0)
  {
    if ((sec_r000147_6_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000147_5_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000147_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000147_5_1 + 7) & 127;
  }
  if ((sec_r000147_0_2 & 1) != 0)
  {
    if ((sec_r000147_6_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000147_5_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000147_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000147_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000147_2_1 & 1) != 0)
  {
    if ((sec_r000147_17_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000147_6_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000147_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000147_6_1 + 7) & 127;
  }
  if ((sec_r000147_2_2 & 1) != 0)
  {
    if ((sec_r000147_17_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000147_6_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000147_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000147_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000147_4_1 & 1) != 0)
  {
    if ((sec_r000147_8_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000147_11_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000147_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000147_11_1 + 7) & 127;
  }
  if ((sec_r000147_4_2 & 1) != 0)
  {
    if ((sec_r000147_8_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000147_11_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000147_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000147_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000147_9_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000147_15_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000147_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000147_15_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000147_9_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000147_15_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000147_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000147_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000147_19_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000147_14_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000147_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000147_14_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000147_19_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000147_14_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000147_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000147_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000147_12_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000147_14_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000147_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000147_14_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000147_12_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000147_14_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000147_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000147_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000147_4_1 & 1) != 0)
  {
    if ((sec_r000147_0_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000147_15_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000147_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000147_15_1 + 7) & 127;
  }
  if ((sec_r000147_4_2 & 1) != 0)
  {
    if ((sec_r000147_0_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000147_15_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000147_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000147_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000147_17_1 & 1) != 0)
  {
    if ((sec_r000147_9_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000147_3_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000147_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000147_3_1 + 7) & 127;
  }
  if ((sec_r000147_17_2 & 1) != 0)
  {
    if ((sec_r000147_9_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000147_3_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000147_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000147_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000147_13_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000147_12_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000147_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000147_12_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000147_13_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000147_12_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000147_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000147_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000147_13_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000147_12_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000147_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000147_12_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000147_13_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000147_12_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000147_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000147_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000147_20_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000147_3_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000147_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000147_3_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000147_20_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000147_3_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000147_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000147_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000147_13_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000147_5_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000147_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000147_5_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000147_13_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000147_5_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000147_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000147_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000147_12_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000147_10_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000147_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000147_10_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000147_12_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000147_10_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000147_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000147_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000147_9_1 & 1) != 0)
  {
    if ((sec_r000147_7_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000147_1_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000147_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000147_1_1 + 7) & 127;
  }
  if ((sec_r000147_9_2 & 1) != 0)
  {
    if ((sec_r000147_7_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000147_1_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000147_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000147_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000147_3_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000147_2_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000147_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000147_2_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000147_3_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000147_2_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000147_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000147_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000147_18_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000147_6_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000147_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000147_6_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000147_18_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000147_6_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000147_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000147_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000147_13_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000147_9_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000147_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000147_9_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000147_13_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000147_9_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000147_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000147_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000147_1_1 & 1) != 0)
  {
    if ((sec_r000147_14_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000147_4_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000147_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000147_4_1 + 7) & 127;
  }
  if ((sec_r000147_1_2 & 1) != 0)
  {
    if ((sec_r000147_14_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000147_4_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000147_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000147_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000147_9_1 & 1) != 0)
  {
    if ((sec_r000147_0_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000147_7_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000147_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000147_7_1 + 7) & 127;
  }
  if ((sec_r000147_9_2 & 1) != 0)
  {
    if ((sec_r000147_0_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000147_7_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000147_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000147_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000147_18_1 & 1) != 0)
  {
    if ((sec_r000147_18_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000147_0_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000147_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000147_0_1 + 7) & 127;
  }
  if ((sec_r000147_18_2 & 1) != 0)
  {
    if ((sec_r000147_18_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000147_0_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000147_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000147_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000147_8_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000147_2_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000147_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000147_2_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000147_8_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000147_2_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000147_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000147_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000147_18_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000147_13_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000147_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000147_13_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000147_18_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000147_13_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000147_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000147_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000147_12_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000147_5_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000147_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000147_5_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000147_12_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000147_5_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000147_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000147_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000147_1_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000147_8_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000147_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000147_8_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000147_1_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000147_8_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000147_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000147_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000147_3_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000147_10_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000147_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000147_10_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000147_3_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000147_10_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000147_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000147_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000147_19_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000147_3_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000147_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000147_3_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000147_19_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000147_3_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000147_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000147_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000147_1_1 & 1) != 0)
  {
    if ((sec_r000147_1_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000147_8_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000147_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000147_8_1 + 7) & 127;
  }
  if ((sec_r000147_1_2 & 1) != 0)
  {
    if ((sec_r000147_1_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000147_8_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000147_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000147_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000147_20_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000147_4_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000147_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000147_4_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000147_20_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000147_4_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000147_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000147_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000147_20_1 & 1) != 0)
  {
    if ((sec_r000147_2_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000147_2_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000147_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000147_2_1 + 7) & 127;
  }
  if ((sec_r000147_20_2 & 1) != 0)
  {
    if ((sec_r000147_2_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000147_2_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000147_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000147_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000147_0_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000147_7_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000147_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000147_7_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000147_0_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000147_7_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000147_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000147_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000147_5_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000147_11_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000147_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000147_11_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000147_5_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000147_11_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000147_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000147_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000147_1_1 & 1) != 0)
  {
    if ((sec_r000147_0_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000147_3_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000147_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000147_3_1 + 7) & 127;
  }
  if ((sec_r000147_1_2 & 1) != 0)
  {
    if ((sec_r000147_0_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000147_3_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000147_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000147_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000147_18_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000147_6_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000147_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000147_6_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000147_18_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000147_6_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000147_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000147_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000147_14_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000147_2_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000147_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000147_2_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000147_14_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000147_2_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000147_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000147_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000147_2_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000147_0_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000147_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000147_0_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000147_2_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000147_0_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000147_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000147_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000147_11_1 & 1) != 0)
  {
    if ((sec_r000147_14_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000147_6_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000147_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000147_6_1 + 7) & 127;
  }
  if ((sec_r000147_11_2 & 1) != 0)
  {
    if ((sec_r000147_14_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000147_6_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000147_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000147_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((sec_r000147_3_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000147_1_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000147_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000147_1_1 + 7) & 127;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((sec_r000147_3_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000147_1_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000147_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000147_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000147_12_1 & 1) != 0)
  {
    if ((sec_r000147_9_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000147_12_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000147_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000147_12_1 + 7) & 127;
  }
  if ((sec_r000147_12_2 & 1) != 0)
  {
    if ((sec_r000147_9_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000147_12_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000147_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000147_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000147_8_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000147_2_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000147_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000147_2_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000147_8_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000147_2_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000147_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000147_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000147_4_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000147_0_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000147_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000147_0_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000147_4_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000147_0_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000147_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000147_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000147_12_1 & 1) != 0)
  {
    if ((sec_r000147_2_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000147_15_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000147_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000147_15_1 + 7) & 127;
  }
  if ((sec_r000147_12_2 & 1) != 0)
  {
    if ((sec_r000147_2_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000147_15_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000147_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000147_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000147_18_1 & 1) != 0)
  {
    if ((sec_r000147_18_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000147_11_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000147_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000147_11_1 + 7) & 127;
  }
  if ((sec_r000147_18_2 & 1) != 0)
  {
    if ((sec_r000147_18_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000147_11_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000147_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000147_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000147_5_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000147_15_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000147_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000147_15_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000147_5_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000147_15_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000147_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000147_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000147_14_1 & 1) != 0)
  {
    if ((sec_r000147_6_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000147_15_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000147_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000147_15_1 + 7) & 127;
  }
  if ((sec_r000147_14_2 & 1) != 0)
  {
    if ((sec_r000147_6_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000147_15_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000147_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000147_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000147_20_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000147_2_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000147_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000147_2_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000147_20_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000147_2_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000147_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000147_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000147_13_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000147_15_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000147_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000147_15_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000147_13_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000147_15_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000147_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000147_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000147_0_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000147_7_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000147_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000147_7_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000147_0_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000147_7_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000147_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000147_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000147_4_1 & 1) != 0)
  {
    if ((sec_r000147_3_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000147_11_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000147_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000147_11_1 + 7) & 127;
  }
  if ((sec_r000147_4_2 & 1) != 0)
  {
    if ((sec_r000147_3_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000147_11_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000147_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000147_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000147_19_1 & 1) != 0)
  {
    if ((sec_r000147_14_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000147_10_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000147_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000147_10_1 + 7) & 127;
  }
  if ((sec_r000147_19_2 & 1) != 0)
  {
    if ((sec_r000147_14_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000147_10_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000147_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000147_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000147_4_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000147_5_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000147_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000147_5_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000147_4_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000147_5_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000147_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000147_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000147_13_1 & 1) != 0)
  {
    if ((sec_r000147_11_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000147_15_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000147_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000147_15_1 + 7) & 127;
  }
  if ((sec_r000147_13_2 & 1) != 0)
  {
    if ((sec_r000147_11_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000147_15_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000147_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000147_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r000147_20_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000147_0_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000147_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000147_0_1 + 7) & 127;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((sec_r000147_20_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000147_0_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000147_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000147_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000147_9_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000147_0_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000147_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000147_0_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000147_9_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000147_0_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000147_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000147_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000147_0_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000147_6_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000147_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000147_6_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000147_0_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000147_6_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000147_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000147_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000147_7_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000147_5_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000147_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000147_5_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000147_7_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000147_5_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000147_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000147_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000147_18_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000147_3_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000147_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000147_3_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000147_18_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000147_3_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000147_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000147_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000147_1_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000147_6_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000147_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000147_6_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000147_1_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000147_6_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000147_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000147_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((sec_r000147_16_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000147_10_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000147_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000147_10_1 + 7) & 127;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((sec_r000147_16_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000147_10_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000147_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000147_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000147_13_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000147_11_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000147_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000147_11_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000147_13_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000147_11_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000147_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000147_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((sec_r000147_5_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000147_10_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000147_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000147_10_1 + 7) & 127;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((sec_r000147_5_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000147_10_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000147_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000147_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000147_12_1 & 1) != 0)
  {
    if ((sec_r000147_9_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000147_12_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000147_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000147_12_1 + 7) & 127;
  }
  if ((sec_r000147_12_2 & 1) != 0)
  {
    if ((sec_r000147_9_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000147_12_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000147_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000147_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000147_6_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000147_15_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000147_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000147_15_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000147_6_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000147_15_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000147_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000147_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((sec_r000147_14_1 & 1) != 0)
  {
    if ((sec_r000147_16_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000147_7_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000147_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000147_7_1 + 7) & 127;
  }
  if ((sec_r000147_14_2 & 1) != 0)
  {
    if ((sec_r000147_16_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000147_7_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000147_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000147_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((sec_r000147_9_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000147_12_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000147_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000147_12_1 + 7) & 127;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((sec_r000147_9_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000147_12_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000147_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000147_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((sec_r000147_1_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000147_14_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000147_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000147_14_1 + 7) & 127;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((sec_r000147_1_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000147_14_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000147_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000147_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((sec_r000147_16_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000147_2_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000147_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000147_2_1 + 7) & 127;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((sec_r000147_16_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000147_2_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000147_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000147_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000147_20_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000147_4_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000147_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000147_4_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000147_20_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000147_4_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000147_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000147_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r000147_15_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000147_8_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000147_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000147_8_1 + 7) & 127;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((sec_r000147_15_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000147_8_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000147_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000147_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000147_19_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000147_14_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000147_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000147_14_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000147_19_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000147_14_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000147_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000147_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000147_6_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000147_9_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000147_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000147_9_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000147_6_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000147_9_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000147_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000147_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((sec_r000147_7_1 & 1) != 0)
  {
    if ((sec_r000147_13_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000147_3_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000147_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000147_3_1 + 7) & 127;
  }
  if ((sec_r000147_7_2 & 1) != 0)
  {
    if ((sec_r000147_13_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000147_3_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000147_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000147_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000147_7_1 == pub_r000147_7_2);
  __CPROVER_assume(pub_r000147_1_1 == pub_r000147_1_2);
  __CPROVER_assume(sec_r000147_20_1 != sec_r000147_20_2);
  __CPROVER_assume(pub_r000147_6_1 == pub_r000147_6_2);
  __CPROVER_assume(sec_r000147_11_1 != sec_r000147_11_2);
  __CPROVER_assume(sec_r000147_14_1 != sec_r000147_14_2);
  __CPROVER_assume(pub_r000147_15_1 == pub_r000147_15_2);
  __CPROVER_assume(sec_r000147_4_1 != sec_r000147_4_2);
  __CPROVER_assume(pub_r000147_2_1 == pub_r000147_2_2);
  __CPROVER_assume(sec_r000147_10_1 != sec_r000147_10_2);
  __CPROVER_assume(sec_r000147_15_1 != sec_r000147_15_2);
  __CPROVER_assume(pub_r000147_11_1 == pub_r000147_11_2);
  __CPROVER_assume(sec_r000147_3_1 != sec_r000147_3_2);
  __CPROVER_assume(sec_r000147_7_1 != sec_r000147_7_2);
  __CPROVER_assume(sec_r000147_0_1 != sec_r000147_0_2);
  __CPROVER_assume(pub_r000147_14_1 == pub_r000147_14_2);
  __CPROVER_assume(sec_r000147_9_1 != sec_r000147_9_2);
  __CPROVER_assume(sec_r000147_17_1 != sec_r000147_17_2);
  __CPROVER_assume(sec_r000147_18_1 != sec_r000147_18_2);
  __CPROVER_assume(sec_r000147_19_1 != sec_r000147_19_2);
  __CPROVER_assume(pub_r000147_8_1 == pub_r000147_8_2);
  __CPROVER_assume(pub_r000147_3_1 == pub_r000147_3_2);
  __CPROVER_assume(pub_r000147_0_1 == pub_r000147_0_2);
  __CPROVER_assume(sec_r000147_5_1 != sec_r000147_5_2);
  __CPROVER_assume(sec_r000147_2_1 != sec_r000147_2_2);
  __CPROVER_assume(sec_r000147_8_1 != sec_r000147_8_2);
  __CPROVER_assume(pub_r000147_9_1 == pub_r000147_9_2);
  __CPROVER_assume(pub_r000147_12_1 == pub_r000147_12_2);
  __CPROVER_assume(pub_r000147_5_1 == pub_r000147_5_2);
  __CPROVER_assume(sec_r000147_13_1 != sec_r000147_13_2);
  __CPROVER_assume(sec_r000147_6_1 != sec_r000147_6_2);
  __CPROVER_assume(pub_r000147_10_1 == pub_r000147_10_2);
  __CPROVER_assume(pub_r000147_13_1 == pub_r000147_13_2);
  __CPROVER_assume(pub_r000147_4_1 == pub_r000147_4_2);
  __CPROVER_assume(sec_r000147_1_1 != sec_r000147_1_2);
  __CPROVER_assume(sec_r000147_12_1 != sec_r000147_12_2);
  __CPROVER_assume(sec_r000147_16_1 != sec_r000147_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.status == st_var_2_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.facility == st_var_3_2.facility);
  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.seq == st_var_3_2.seq);
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
}


