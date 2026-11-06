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
struct CipherContext_R000857_5713_0
{
  int counter;
  int round_key;
  unsigned char flags;
  int buffer[3];
};
struct SensorNode_R000857_5713_1
{
  int calib;
  unsigned char gain;
  int reading;
  int status;
  unsigned char offset;
  int buffer[3];
};
struct DeviceConfig_R000857_5713_2
{
  short timeout;
  unsigned char parity;
  int id;
  short port;
  unsigned char baud_rate;
  int buffer[3];
};
struct MatrixBlock_R000857_5713_3
{
  int determinant;
  short density;
  unsigned char scale;
  int buffer[3];
};
union ColorPixel_R000857_5713_0
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
void fn_R000857_5713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000857_5713_2 st_1 = {0};
  struct DeviceConfig_R000857_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int accumulator_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_71_1)
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

  switch (accumulator_71_2)
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

  int segment_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_86_1) & 63;
  aux_2 = (aux_2 + segment_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_71_1 == accumulator_71_2);
  assert(segment_86_1 == segment_86_2);
}

int fn_R000857_5713_0(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000857_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int accumulator_71 = (aux + st.buffer[1]) & 3;
  switch (accumulator_71)
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

  int segment_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000857_5713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st_1 = {0};
  struct CipherContext_R000857_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_59_1 = local_arr_1[aux_1 % 3];
  int threshold_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_59_1 == threshold_59_2);
}

int fn_R000857_5713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_59 = local_arr[aux % 3];
  acc = (acc + (threshold_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000857_5713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000857_5713_1 st_1 = {0};
  struct SensorNode_R000857_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_78_1)
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

  switch (parity_78_2)
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
  int parity_21_1 = local_arr_1[aux_1 % 3];
  int parity_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_21_2 * 2)) & 127;
  int quotient_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_39_1 > 48)
  {
    acc_1 = ((acc_1 + (quotient_39_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_39_2 > 48)
  {
    acc_2 = ((acc_2 + (quotient_39_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_78_1 == parity_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_21_1 == parity_21_2);
  assert(quotient_39_1 == quotient_39_2);
}

int fn_R000857_5713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000857_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_78 = (aux + st.buffer[1]) & 3;
  switch (parity_78)
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
  int parity_21 = local_arr[aux % 3];
  acc = (acc + (parity_21 * 2)) & 127;
  int quotient_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_39 > 48)
  {
    acc = ((acc + (quotient_39 * 2)) + 5) & 127;
    aux ^= quotient_39 & 15;
  }
  else
  {
    acc = ((acc - quotient_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000857_5713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000857_5713_2 st_1 = {0};
  struct DeviceConfig_R000857_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_44_1)
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

  switch (factor_44_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_44_1 == factor_44_2);
}

int fn_R000857_5713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000857_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_44 = (aux + st.buffer[1]) & 3;
  switch (factor_44)
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

void fn_R000857_5713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000857_5713_3 st_1 = {0};
  struct MatrixBlock_R000857_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_28_1 = local_arr_1[aux_1 % 3];
  int residue_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_28_1 == residue_28_2);
}

int fn_R000857_5713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000857_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_28 = local_arr[aux % 3];
  acc = (acc + (residue_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000857_5713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000857_5713_3 st_1 = {0};
  struct MatrixBlock_R000857_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int threshold_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_64_1 > 20)
  {
    acc_1 = ((acc_1 + (threshold_64_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_64_2 > 20)
  {
    acc_2 = ((acc_2 + (threshold_64_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_64_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_42_1)
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

  switch (offset_42_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_64_1 == threshold_64_2);
  assert(offset_42_1 == offset_42_2);
}

int fn_R000857_5713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000857_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int threshold_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_64 > 20)
  {
    acc = ((acc + (threshold_64 * 2)) + 5) & 127;
    aux ^= threshold_64 & 15;
  }
  else
  {
    acc = ((acc - threshold_64) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_42 = (aux + st.buffer[1]) & 3;
  switch (offset_42)
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

void fn_R000857_5713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000857_5713_3 st_1 = {0};
  struct MatrixBlock_R000857_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int factor_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_66_1)
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

  switch (factor_66_2)
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

  int metric_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_31_1) & 63;
  aux_2 = (aux_2 + metric_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_66_1 == factor_66_2);
  assert(metric_31_1 == metric_31_2);
}

int fn_R000857_5713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000857_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int factor_66 = (aux + st.buffer[1]) & 3;
  switch (factor_66)
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

  int metric_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_31) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000857_5713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000857_5713_1 st_1 = {0};
  struct SensorNode_R000857_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int mask_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_98_1 > 18)
  {
    acc_1 = ((acc_1 + (mask_98_1 * 2)) + 5) & 127;
    aux_1 ^= mask_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_98_2 > 18)
  {
    acc_2 = ((acc_2 + (mask_98_2 * 2)) + 5) & 127;
    aux_2 ^= mask_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_80_1) & 63;
  aux_2 = (aux_2 + checksum_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_98_1 == mask_98_2);
  assert(checksum_80_1 == checksum_80_2);
}

int fn_R000857_5713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000857_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int mask_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_98 > 18)
  {
    acc = ((acc + (mask_98 * 2)) + 5) & 127;
    aux ^= mask_98 & 15;
  }
  else
  {
    acc = ((acc - mask_98) + 11) & 127;
    aux += 3;
  }
  int checksum_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000857_5713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st_1 = {0};
  struct CipherContext_R000857_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int vector_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_40_1)
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

  switch (vector_40_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_42_1 > 50)
  {
    acc_1 = ((acc_1 + (tracker_42_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_42_2 > 50)
  {
    acc_2 = ((acc_2 + (tracker_42_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_40_1 == vector_40_2);
  assert(tracker_42_1 == tracker_42_2);
}

int fn_R000857_5713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int vector_40 = (aux + st.buffer[1]) & 3;
  switch (vector_40)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_42 > 50)
  {
    acc = ((acc + (tracker_42 * 2)) + 5) & 127;
    aux ^= tracker_42 & 15;
  }
  else
  {
    acc = ((acc - tracker_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000857_5713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st_1 = {0};
  struct CipherContext_R000857_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int window_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_93_1) & 63;
  aux_2 = (aux_2 + window_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_57_1 > 23)
  {
    acc_1 = ((acc_1 + (index_reg_57_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_57_2 > 23)
  {
    acc_2 = ((acc_2 + (index_reg_57_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_93_1 == window_93_2);
  assert(index_reg_57_1 == index_reg_57_2);
}

int fn_R000857_5713_9(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int window_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_93) & 63;
  acc ^= aux;
  int index_reg_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_57 > 23)
  {
    acc = ((acc + (index_reg_57 * 2)) + 5) & 127;
    aux ^= index_reg_57 & 15;
  }
  else
  {
    acc = ((acc - index_reg_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000857_5713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000857_5713_2 st_1 = {0};
  struct DeviceConfig_R000857_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_51_1 = local_arr_1[aux_1 % 3];
  int tracker_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_51_2 * 2)) & 127;
  int stride_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_22_1)
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

  switch (stride_22_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_51_1 == tracker_51_2);
  assert(stride_22_1 == stride_22_2);
}

int fn_R000857_5713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000857_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tracker_51 = local_arr[aux % 3];
  acc = (acc + (tracker_51 * 2)) & 127;
  int stride_22 = (aux + st.buffer[1]) & 3;
  switch (stride_22)
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

void fn_R000857_5713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st_1 = {0};
  struct CipherContext_R000857_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_69_1 = local_arr_1[aux_1 % 3];
  int factor_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_69_2 * 2)) & 127;
  int accumulator_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_70_1)
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

  switch (accumulator_70_2)
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

  int index_reg_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_83_1 > 43)
  {
    acc_1 = ((acc_1 + (index_reg_83_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_83_2 > 43)
  {
    acc_2 = ((acc_2 + (index_reg_83_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_69_1 == factor_69_2);
  assert(accumulator_70_1 == accumulator_70_2);
  assert(index_reg_83_1 == index_reg_83_2);
}

int fn_R000857_5713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int factor_69 = local_arr[aux % 3];
  acc = (acc + (factor_69 * 2)) & 127;
  int accumulator_70 = (aux + st.buffer[1]) & 3;
  switch (accumulator_70)
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

  int index_reg_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_83 > 43)
  {
    acc = ((acc + (index_reg_83 * 2)) + 5) & 127;
    aux ^= index_reg_83 & 15;
  }
  else
  {
    acc = ((acc - index_reg_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000857_5713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st_1 = {0};
  struct CipherContext_R000857_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_35_1 > 19)
  {
    acc_1 = ((acc_1 + (scale_35_1 * 2)) + 5) & 127;
    aux_1 ^= scale_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_35_2 > 19)
  {
    acc_2 = ((acc_2 + (scale_35_2 * 2)) + 5) & 127;
    aux_2 ^= scale_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_35_1 == scale_35_2);
}

int fn_R000857_5713_12(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_35 > 19)
  {
    acc = ((acc + (scale_35 * 2)) + 5) & 127;
    aux ^= scale_35 & 15;
  }
  else
  {
    acc = ((acc - scale_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000857_5713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000857_5713_2 st_1 = {0};
  struct DeviceConfig_R000857_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_64_1 = local_arr_1[aux_1 % 3];
  int residue_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_64_2 * 2)) & 127;
  int margin_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_21_1 > 49)
  {
    acc_1 = ((acc_1 + (margin_21_1 * 2)) + 5) & 127;
    aux_1 ^= margin_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_21_2 > 49)
  {
    acc_2 = ((acc_2 + (margin_21_2 * 2)) + 5) & 127;
    aux_2 ^= margin_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_93_1)
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

  switch (offset_93_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_64_1 == residue_64_2);
  assert(margin_21_1 == margin_21_2);
  assert(offset_93_1 == offset_93_2);
}

int fn_R000857_5713_13(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000857_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int residue_64 = local_arr[aux % 3];
  acc = (acc + (residue_64 * 2)) & 127;
  int margin_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_21 > 49)
  {
    acc = ((acc + (margin_21 * 2)) + 5) & 127;
    aux ^= margin_21 & 15;
  }
  else
  {
    acc = ((acc - margin_21) + 11) & 127;
    aux += 3;
  }
  int offset_93 = (aux + st.buffer[1]) & 3;
  switch (offset_93)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000857_5713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000857_5713_1 st_1 = {0};
  struct SensorNode_R000857_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_56_1) & 63;
  aux_2 = (aux_2 + offset_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_87_1 > 26)
  {
    acc_1 = ((acc_1 + (window_87_1 * 2)) + 5) & 127;
    aux_1 ^= window_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_87_2 > 26)
  {
    acc_2 = ((acc_2 + (window_87_2 * 2)) + 5) & 127;
    aux_2 ^= window_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_87_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_56_1 == offset_56_2);
  assert(window_87_1 == window_87_2);
}

int fn_R000857_5713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000857_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_56) & 63;
  acc ^= aux;
  int window_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_87 > 26)
  {
    acc = ((acc + (window_87 * 2)) + 5) & 127;
    aux ^= window_87 & 15;
  }
  else
  {
    acc = ((acc - window_87) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000857_5713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000857_5713_2 st_1 = {0};
  struct DeviceConfig_R000857_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tally_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_15_1 > 20)
  {
    acc_1 = ((acc_1 + (tally_15_1 * 2)) + 5) & 127;
    aux_1 ^= tally_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_15_2 > 20)
  {
    acc_2 = ((acc_2 + (tally_15_2 * 2)) + 5) & 127;
    aux_2 ^= tally_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_84_1) & 63;
  aux_2 = (aux_2 + segment_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_15_1 == tally_15_2);
  assert(segment_84_1 == segment_84_2);
}

int fn_R000857_5713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000857_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tally_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_15 > 20)
  {
    acc = ((acc + (tally_15 * 2)) + 5) & 127;
    aux ^= tally_15 & 15;
  }
  else
  {
    acc = ((acc - tally_15) + 11) & 127;
    aux += 3;
  }
  int segment_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000857_5713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000857_5713_1 st_1 = {0};
  struct SensorNode_R000857_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int sample_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_44_1 > 34)
  {
    acc_1 = ((acc_1 + (sample_44_1 * 2)) + 5) & 127;
    aux_1 ^= sample_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_44_2 > 34)
  {
    acc_2 = ((acc_2 + (sample_44_2 * 2)) + 5) & 127;
    aux_2 ^= sample_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_32_1)
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

  switch (factor_32_2)
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

  int anchor_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_59_1) & 63;
  aux_2 = (aux_2 + anchor_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_45_1 = local_arr_1[aux_1 % 3];
  int window_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_44_1 == sample_44_2);
  assert(factor_32_1 == factor_32_2);
  assert(anchor_59_1 == anchor_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_45_1 == window_45_2);
}

int fn_R000857_5713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000857_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int sample_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_44 > 34)
  {
    acc = ((acc + (sample_44 * 2)) + 5) & 127;
    aux ^= sample_44 & 15;
  }
  else
  {
    acc = ((acc - sample_44) + 11) & 127;
    aux += 3;
  }
  int factor_32 = (aux + st.buffer[1]) & 3;
  switch (factor_32)
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

  int anchor_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_59) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_45 = local_arr[aux % 3];
  acc = (acc + (window_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000857_5713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000857_5713_1 st_1 = {0};
  struct SensorNode_R000857_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int phase_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_92_1) & 63;
  aux_2 = (aux_2 + phase_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_91_1 > 49)
  {
    acc_1 = ((acc_1 + (weight_91_1 * 2)) + 5) & 127;
    aux_1 ^= weight_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_91_2 > 49)
  {
    acc_2 = ((acc_2 + (weight_91_2 * 2)) + 5) & 127;
    aux_2 ^= weight_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_91_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_45_1)
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

  switch (damping_45_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_92_1 == phase_92_2);
  assert(weight_91_1 == weight_91_2);
  assert(damping_45_1 == damping_45_2);
}

int fn_R000857_5713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000857_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int phase_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_92) & 63;
  acc ^= aux;
  int weight_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_91 > 49)
  {
    acc = ((acc + (weight_91 * 2)) + 5) & 127;
    aux ^= weight_91 & 15;
  }
  else
  {
    acc = ((acc - weight_91) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_45 = (aux + st.buffer[1]) & 3;
  switch (damping_45)
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

void fn_R000857_5713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st_1 = {0};
  struct CipherContext_R000857_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_85_1) & 63;
  aux_2 = (aux_2 + scale_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_85_1 == scale_85_2);
}

int fn_R000857_5713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000857_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_85) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000857_0_1;
  int sec_r000857_0_2;
  int sec_r000857_1_1;
  int sec_r000857_1_2;
  int sec_r000857_2_1;
  int sec_r000857_2_2;
  int sec_r000857_3_1;
  int sec_r000857_3_2;
  int sec_r000857_4_1;
  int sec_r000857_4_2;
  int sec_r000857_5_1;
  int sec_r000857_5_2;
  int sec_r000857_6_1;
  int sec_r000857_6_2;
  int sec_r000857_7_1;
  int sec_r000857_7_2;
  int sec_r000857_8_1;
  int sec_r000857_8_2;
  int sec_r000857_9_1;
  int sec_r000857_9_2;
  int sec_r000857_10_1;
  int sec_r000857_10_2;
  int sec_r000857_11_1;
  int sec_r000857_11_2;
  int sec_r000857_12_1;
  int sec_r000857_12_2;
  int sec_r000857_13_1;
  int sec_r000857_13_2;
  int sec_r000857_14_1;
  int sec_r000857_14_2;
  int sec_r000857_15_1;
  int sec_r000857_15_2;
  int sec_r000857_16_1;
  int sec_r000857_16_2;
  int sec_r000857_17_1;
  int sec_r000857_17_2;
  int sec_r000857_18_1;
  int sec_r000857_18_2;
  int sec_r000857_19_1;
  int sec_r000857_19_2;
  int sec_r000857_20_1;
  int sec_r000857_20_2;
  int sec_r000857_21_1;
  int sec_r000857_21_2;
  int sec_r000857_22_1;
  int sec_r000857_22_2;
  int sec_r000857_23_1;
  int sec_r000857_23_2;
  int pub_r000857_0_1;
  int pub_r000857_0_2;
  int pub_r000857_1_1;
  int pub_r000857_1_2;
  int pub_r000857_2_1;
  int pub_r000857_2_2;
  int pub_r000857_3_1;
  int pub_r000857_3_2;
  int pub_r000857_4_1;
  int pub_r000857_4_2;
  int pub_r000857_5_1;
  int pub_r000857_5_2;
  int pub_r000857_6_1;
  int pub_r000857_6_2;
  int pub_r000857_7_1;
  int pub_r000857_7_2;
  int pub_r000857_8_1;
  int pub_r000857_8_2;
  int pub_r000857_9_1;
  int pub_r000857_9_2;
  int pub_r000857_10_1;
  int pub_r000857_10_2;
  int pub_r000857_11_1;
  int pub_r000857_11_2;
  int pub_r000857_12_1;
  int pub_r000857_12_2;
  int pub_r000857_13_1;
  int pub_r000857_13_2;
  int pub_r000857_14_1;
  int pub_r000857_14_2;
  int pub_r000857_15_1;
  int pub_r000857_15_2;
  int pub_r000857_16_1;
  int pub_r000857_16_2;
  int pub_r000857_17_1;
  int pub_r000857_17_2;
  int pub_r000857_18_1;
  int pub_r000857_18_2;
  int pub_r000857_19_1;
  int pub_r000857_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000857_0_1 >= (-100)) && (pub_r000857_0_1 <= 100));
  __CPROVER_assume((pub_r000857_0_2 >= (-100)) && (pub_r000857_0_2 <= 100));
  __CPROVER_assume((pub_r000857_1_1 >= (-100)) && (pub_r000857_1_1 <= 100));
  __CPROVER_assume((pub_r000857_1_2 >= (-100)) && (pub_r000857_1_2 <= 100));
  __CPROVER_assume((pub_r000857_2_1 >= (-100)) && (pub_r000857_2_1 <= 100));
  __CPROVER_assume((pub_r000857_2_2 >= (-100)) && (pub_r000857_2_2 <= 100));
  __CPROVER_assume((pub_r000857_3_1 >= (-100)) && (pub_r000857_3_1 <= 100));
  __CPROVER_assume((pub_r000857_3_2 >= (-100)) && (pub_r000857_3_2 <= 100));
  __CPROVER_assume((pub_r000857_4_1 >= (-100)) && (pub_r000857_4_1 <= 100));
  __CPROVER_assume((pub_r000857_4_2 >= (-100)) && (pub_r000857_4_2 <= 100));
  __CPROVER_assume((pub_r000857_5_1 >= (-100)) && (pub_r000857_5_1 <= 100));
  __CPROVER_assume((pub_r000857_5_2 >= (-100)) && (pub_r000857_5_2 <= 100));
  __CPROVER_assume((pub_r000857_6_1 >= (-100)) && (pub_r000857_6_1 <= 100));
  __CPROVER_assume((pub_r000857_6_2 >= (-100)) && (pub_r000857_6_2 <= 100));
  __CPROVER_assume((pub_r000857_7_1 >= (-100)) && (pub_r000857_7_1 <= 100));
  __CPROVER_assume((pub_r000857_7_2 >= (-100)) && (pub_r000857_7_2 <= 100));
  __CPROVER_assume((pub_r000857_8_1 >= (-100)) && (pub_r000857_8_1 <= 100));
  __CPROVER_assume((pub_r000857_8_2 >= (-100)) && (pub_r000857_8_2 <= 100));
  __CPROVER_assume((pub_r000857_9_1 >= (-100)) && (pub_r000857_9_1 <= 100));
  __CPROVER_assume((pub_r000857_9_2 >= (-100)) && (pub_r000857_9_2 <= 100));
  __CPROVER_assume((pub_r000857_10_1 >= (-100)) && (pub_r000857_10_1 <= 100));
  __CPROVER_assume((pub_r000857_10_2 >= (-100)) && (pub_r000857_10_2 <= 100));
  __CPROVER_assume((pub_r000857_11_1 >= (-100)) && (pub_r000857_11_1 <= 100));
  __CPROVER_assume((pub_r000857_11_2 >= (-100)) && (pub_r000857_11_2 <= 100));
  __CPROVER_assume((pub_r000857_12_1 >= (-100)) && (pub_r000857_12_1 <= 100));
  __CPROVER_assume((pub_r000857_12_2 >= (-100)) && (pub_r000857_12_2 <= 100));
  __CPROVER_assume((pub_r000857_13_1 >= (-100)) && (pub_r000857_13_1 <= 100));
  __CPROVER_assume((pub_r000857_13_2 >= (-100)) && (pub_r000857_13_2 <= 100));
  __CPROVER_assume((pub_r000857_14_1 >= (-100)) && (pub_r000857_14_1 <= 100));
  __CPROVER_assume((pub_r000857_14_2 >= (-100)) && (pub_r000857_14_2 <= 100));
  __CPROVER_assume((pub_r000857_15_1 >= (-100)) && (pub_r000857_15_1 <= 100));
  __CPROVER_assume((pub_r000857_15_2 >= (-100)) && (pub_r000857_15_2 <= 100));
  __CPROVER_assume((pub_r000857_16_1 >= (-100)) && (pub_r000857_16_1 <= 100));
  __CPROVER_assume((pub_r000857_16_2 >= (-100)) && (pub_r000857_16_2 <= 100));
  __CPROVER_assume((pub_r000857_17_1 >= (-100)) && (pub_r000857_17_1 <= 100));
  __CPROVER_assume((pub_r000857_17_2 >= (-100)) && (pub_r000857_17_2 <= 100));
  __CPROVER_assume((pub_r000857_18_1 >= (-100)) && (pub_r000857_18_1 <= 100));
  __CPROVER_assume((pub_r000857_18_2 >= (-100)) && (pub_r000857_18_2 <= 100));
  __CPROVER_assume((pub_r000857_19_1 >= (-100)) && (pub_r000857_19_1 <= 100));
  __CPROVER_assume((pub_r000857_19_2 >= (-100)) && (pub_r000857_19_2 <= 100));
  __CPROVER_assume((sec_r000857_0_1 >= 0) && (sec_r000857_0_1 <= 255));
  __CPROVER_assume((sec_r000857_0_2 >= 0) && (sec_r000857_0_2 <= 255));
  __CPROVER_assume((sec_r000857_1_1 >= 0) && (sec_r000857_1_1 <= 255));
  __CPROVER_assume((sec_r000857_1_2 >= 0) && (sec_r000857_1_2 <= 255));
  __CPROVER_assume((sec_r000857_2_1 >= 0) && (sec_r000857_2_1 <= 255));
  __CPROVER_assume((sec_r000857_2_2 >= 0) && (sec_r000857_2_2 <= 255));
  __CPROVER_assume((sec_r000857_3_1 >= 0) && (sec_r000857_3_1 <= 255));
  __CPROVER_assume((sec_r000857_3_2 >= 0) && (sec_r000857_3_2 <= 255));
  __CPROVER_assume((sec_r000857_4_1 >= 0) && (sec_r000857_4_1 <= 255));
  __CPROVER_assume((sec_r000857_4_2 >= 0) && (sec_r000857_4_2 <= 255));
  __CPROVER_assume((sec_r000857_5_1 >= 0) && (sec_r000857_5_1 <= 255));
  __CPROVER_assume((sec_r000857_5_2 >= 0) && (sec_r000857_5_2 <= 255));
  __CPROVER_assume((sec_r000857_6_1 >= 0) && (sec_r000857_6_1 <= 255));
  __CPROVER_assume((sec_r000857_6_2 >= 0) && (sec_r000857_6_2 <= 255));
  __CPROVER_assume((sec_r000857_7_1 >= 0) && (sec_r000857_7_1 <= 255));
  __CPROVER_assume((sec_r000857_7_2 >= 0) && (sec_r000857_7_2 <= 255));
  __CPROVER_assume((sec_r000857_8_1 >= 0) && (sec_r000857_8_1 <= 255));
  __CPROVER_assume((sec_r000857_8_2 >= 0) && (sec_r000857_8_2 <= 255));
  __CPROVER_assume((sec_r000857_9_1 >= 0) && (sec_r000857_9_1 <= 255));
  __CPROVER_assume((sec_r000857_9_2 >= 0) && (sec_r000857_9_2 <= 255));
  __CPROVER_assume((sec_r000857_10_1 >= 0) && (sec_r000857_10_1 <= 255));
  __CPROVER_assume((sec_r000857_10_2 >= 0) && (sec_r000857_10_2 <= 255));
  __CPROVER_assume((sec_r000857_11_1 >= 0) && (sec_r000857_11_1 <= 255));
  __CPROVER_assume((sec_r000857_11_2 >= 0) && (sec_r000857_11_2 <= 255));
  __CPROVER_assume((sec_r000857_12_1 >= 0) && (sec_r000857_12_1 <= 255));
  __CPROVER_assume((sec_r000857_12_2 >= 0) && (sec_r000857_12_2 <= 255));
  __CPROVER_assume((sec_r000857_13_1 >= 0) && (sec_r000857_13_1 <= 255));
  __CPROVER_assume((sec_r000857_13_2 >= 0) && (sec_r000857_13_2 <= 255));
  __CPROVER_assume((sec_r000857_14_1 >= 0) && (sec_r000857_14_1 <= 255));
  __CPROVER_assume((sec_r000857_14_2 >= 0) && (sec_r000857_14_2 <= 255));
  __CPROVER_assume((sec_r000857_15_1 >= 0) && (sec_r000857_15_1 <= 255));
  __CPROVER_assume((sec_r000857_15_2 >= 0) && (sec_r000857_15_2 <= 255));
  __CPROVER_assume((sec_r000857_16_1 >= 0) && (sec_r000857_16_1 <= 255));
  __CPROVER_assume((sec_r000857_16_2 >= 0) && (sec_r000857_16_2 <= 255));
  __CPROVER_assume((sec_r000857_17_1 >= 0) && (sec_r000857_17_1 <= 255));
  __CPROVER_assume((sec_r000857_17_2 >= 0) && (sec_r000857_17_2 <= 255));
  __CPROVER_assume((sec_r000857_18_1 >= 0) && (sec_r000857_18_1 <= 255));
  __CPROVER_assume((sec_r000857_18_2 >= 0) && (sec_r000857_18_2 <= 255));
  __CPROVER_assume((sec_r000857_19_1 >= 0) && (sec_r000857_19_1 <= 255));
  __CPROVER_assume((sec_r000857_19_2 >= 0) && (sec_r000857_19_2 <= 255));
  __CPROVER_assume((sec_r000857_20_1 >= 0) && (sec_r000857_20_1 <= 255));
  __CPROVER_assume((sec_r000857_20_2 >= 0) && (sec_r000857_20_2 <= 255));
  __CPROVER_assume((sec_r000857_21_1 >= 0) && (sec_r000857_21_1 <= 255));
  __CPROVER_assume((sec_r000857_21_2 >= 0) && (sec_r000857_21_2 <= 255));
  __CPROVER_assume((sec_r000857_22_1 >= 0) && (sec_r000857_22_1 <= 255));
  __CPROVER_assume((sec_r000857_22_2 >= 0) && (sec_r000857_22_2 <= 255));
  __CPROVER_assume((sec_r000857_23_1 >= 0) && (sec_r000857_23_1 <= 255));
  __CPROVER_assume((sec_r000857_23_2 >= 0) && (sec_r000857_23_2 <= 255));
  struct CipherContext_R000857_5713_0 st_var_0_1 = {0};
  struct CipherContext_R000857_5713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000857_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000857_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000857_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000857_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000857_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000857_0_2 + 7) & 15;
  struct SensorNode_R000857_5713_1 st_var_1_1 = {0};
  struct SensorNode_R000857_5713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000857_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000857_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000857_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000857_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000857_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000857_0_2 + 9) & 15;
  struct DeviceConfig_R000857_5713_2 st_var_2_1 = {0};
  struct DeviceConfig_R000857_5713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000857_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000857_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000857_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000857_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000857_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000857_0_2 + 11) & 15;
  struct MatrixBlock_R000857_5713_3 st_var_3_1 = {0};
  struct MatrixBlock_R000857_5713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000857_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000857_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000857_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000857_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000857_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000857_0_2 + 13) & 15;
  union ColorPixel_R000857_5713_0 u_var_1;
  union ColorPixel_R000857_5713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

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
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 4) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 34)
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
  if (stage_v_4_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 34)
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
  int stage_v_5_1 = ((st_var_1_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_1_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 27)
    {
      chk_sum_1 ^= stage_v_5_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_5_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 27)
    {
      chk_sum_2 ^= stage_v_5_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = (st_var_3_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_3_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = ((st_var_3_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_3_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 49)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 49)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 23) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  int stage_v_23_1 = (st_var_3_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_3_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_27_1 = ((st_var_3_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_3_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 25)
    {
      chk_sum_1 ^= stage_v_27_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_27_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 25)
    {
      chk_sum_2 ^= stage_v_27_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 31) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = (st_var_0_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_0_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 43)
    {
      chk_sum_1 ^= stage_v_33_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_33_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 43)
    {
      chk_sum_2 ^= stage_v_33_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 35) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = table_1[1];
  int stage_v_37_2 = table_2[1];
  table_1[1] = (table_1[2] + 75) & 63;
  table_2[1] = (table_2[2] + 75) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_40_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 28)
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
  if (stage_v_41_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 28)
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
  int stage_v_43_1 = ((st_var_3_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_3_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 34)
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
  if (stage_v_43_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 34)
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
  int stage_v_44_1 = (st_var_0_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_0_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = (st_var_2_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_2_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
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

  switch (stage_v_46_2)
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

  int stage_v_47_1 = (st_var_3_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_3_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 41)
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
  if (stage_v_49_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 41)
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
  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  int stage_v_51_1 = (st_var_3_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_3_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 55) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 55) & 15;
  int stage_v_54_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_54_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= stage_v_54_1;
  chk_sum_2 ^= stage_v_54_2;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 56) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = (st_var_2_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_2_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  int stage_v_60_1 = ((st_var_0_1.buffer[0] * 2) + 187) & 63;
  int stage_v_60_2 = ((st_var_0_2.buffer[0] * 2) + 187) & 63;
  if (stage_v_60_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 48)
    {
      chk_sum_1 ^= stage_v_60_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_60_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 48)
    {
      chk_sum_2 ^= stage_v_60_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  int stage_v_63_1 = ((st_var_3_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_3_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 39)
    {
      chk_sum_1 ^= stage_v_63_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_63_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 39)
    {
      chk_sum_2 ^= stage_v_63_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000857_4_1 & 1) != 0)
  {
    if ((sec_r000857_8_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000857_5_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000857_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000857_5_1 + 7) & 127;
  }
  if ((sec_r000857_4_2 & 1) != 0)
  {
    if ((sec_r000857_8_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000857_5_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000857_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000857_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000857_20_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000857_6_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000857_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000857_6_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000857_20_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000857_6_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000857_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000857_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000857_19_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000857_11_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000857_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000857_11_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000857_19_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000857_11_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000857_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000857_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000857_5_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000857_5_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000857_3_1 & 1) != 0)
  {
    if ((sec_r000857_15_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000857_2_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000857_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000857_2_1 + 7) & 127;
  }
  if ((sec_r000857_3_2 & 1) != 0)
  {
    if ((sec_r000857_15_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000857_2_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000857_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000857_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000857_7_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000857_9_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000857_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000857_9_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000857_7_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000857_9_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000857_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000857_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000857_9_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000857_5_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000857_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000857_5_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000857_9_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000857_5_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000857_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000857_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000857_1_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000857_16_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000857_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000857_16_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000857_1_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000857_16_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000857_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000857_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000857_17_1 & 1) != 0)
  {
    if ((sec_r000857_23_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000857_13_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000857_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000857_13_1 + 7) & 127;
  }
  if ((sec_r000857_17_2 & 1) != 0)
  {
    if ((sec_r000857_23_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000857_13_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000857_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000857_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000857_21_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000857_18_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000857_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000857_18_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000857_21_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000857_18_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000857_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000857_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000857_20_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000857_4_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000857_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000857_4_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000857_20_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000857_4_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000857_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000857_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000857_19_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000857_6_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000857_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000857_6_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000857_19_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000857_6_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000857_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000857_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000857_5_1 & 1) != 0)
  {
    if ((sec_r000857_3_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000857_2_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000857_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000857_2_1 + 7) & 127;
  }
  if ((sec_r000857_5_2 & 1) != 0)
  {
    if ((sec_r000857_3_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000857_2_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000857_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000857_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000857_18_1 & 1) != 0)
  {
    if ((sec_r000857_9_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000857_5_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000857_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000857_5_1 + 7) & 127;
  }
  if ((sec_r000857_18_2 & 1) != 0)
  {
    if ((sec_r000857_9_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000857_5_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000857_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000857_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000857_12_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000857_13_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000857_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000857_13_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000857_12_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000857_13_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000857_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000857_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000857_11_1 & 1) != 0)
  {
    if ((sec_r000857_3_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000857_15_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000857_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000857_15_1 + 7) & 127;
  }
  if ((sec_r000857_11_2 & 1) != 0)
  {
    if ((sec_r000857_3_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000857_15_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000857_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000857_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000857_4_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000857_12_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000857_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000857_12_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000857_4_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000857_12_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000857_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000857_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000857_12_1 & 1) != 0)
  {
    if ((sec_r000857_5_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((sec_r000857_12_2 & 1) != 0)
  {
    if ((sec_r000857_5_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000857_2_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000857_13_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000857_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000857_13_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000857_2_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000857_13_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000857_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000857_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000857_18_1 & 1) != 0)
  {
    if ((sec_r000857_5_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000857_5_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000857_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000857_5_1 + 7) & 127;
  }
  if ((sec_r000857_18_2 & 1) != 0)
  {
    if ((sec_r000857_5_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000857_5_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000857_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000857_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000857_12_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000857_4_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000857_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000857_4_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000857_12_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000857_4_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000857_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000857_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000857_3_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000857_1_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000857_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000857_1_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000857_3_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000857_1_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000857_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000857_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000857_1_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000857_4_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000857_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000857_4_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000857_1_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000857_4_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000857_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000857_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000857_10_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000857_6_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000857_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000857_6_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000857_10_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000857_6_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000857_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000857_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000857_23_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000857_8_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000857_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000857_8_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000857_23_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000857_8_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000857_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000857_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000857_8_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000857_8_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000857_10_1 & 1) != 0)
  {
    if ((sec_r000857_0_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000857_13_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000857_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000857_13_1 + 7) & 127;
  }
  if ((sec_r000857_10_2 & 1) != 0)
  {
    if ((sec_r000857_0_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000857_13_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000857_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000857_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000857_21_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000857_21_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000857_6_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000857_15_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000857_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000857_15_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000857_6_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000857_15_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000857_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000857_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000857_0_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000857_18_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000857_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000857_18_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000857_0_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000857_18_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000857_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000857_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000857_4_1 & 1) != 0)
  {
    if ((sec_r000857_21_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000857_2_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000857_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000857_2_1 + 7) & 127;
  }
  if ((sec_r000857_4_2 & 1) != 0)
  {
    if ((sec_r000857_21_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000857_2_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000857_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000857_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000857_14_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000857_11_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000857_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000857_11_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000857_14_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000857_11_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000857_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000857_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000857_11_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000857_11_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000857_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000857_11_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000857_11_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000857_11_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000857_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000857_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000857_0_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000857_0_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000857_14_1 & 1) != 0)
  {
    if ((sec_r000857_16_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000857_7_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000857_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000857_7_1 + 7) & 127;
  }
  if ((sec_r000857_14_2 & 1) != 0)
  {
    if ((sec_r000857_16_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000857_7_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000857_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000857_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000857_14_1 & 1) != 0)
  {
    if ((sec_r000857_3_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000857_9_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000857_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000857_9_1 + 7) & 127;
  }
  if ((sec_r000857_14_2 & 1) != 0)
  {
    if ((sec_r000857_3_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000857_9_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000857_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000857_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000857_14_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000857_14_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000857_6_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000857_17_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000857_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000857_17_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000857_6_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000857_17_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000857_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000857_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000857_17_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000857_7_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000857_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000857_7_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000857_17_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000857_7_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000857_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000857_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000857_21_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000857_7_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000857_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000857_7_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000857_21_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000857_7_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000857_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000857_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000857_6_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000857_8_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000857_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000857_8_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000857_6_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000857_8_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000857_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000857_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000857_19_1 & 1) != 0)
  {
    if ((sec_r000857_10_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000857_0_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000857_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000857_0_1 + 7) & 127;
  }
  if ((sec_r000857_19_2 & 1) != 0)
  {
    if ((sec_r000857_10_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000857_0_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000857_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000857_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000857_21_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000857_6_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000857_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000857_6_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000857_21_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000857_6_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000857_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000857_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000857_9_1 & 1) != 0)
  {
    if ((sec_r000857_11_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000857_16_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000857_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000857_16_1 + 7) & 127;
  }
  if ((sec_r000857_9_2 & 1) != 0)
  {
    if ((sec_r000857_11_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000857_16_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000857_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000857_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000857_14_1 & 1) != 0)
  {
    if ((sec_r000857_16_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000857_17_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000857_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000857_17_1 + 7) & 127;
  }
  if ((sec_r000857_14_2 & 1) != 0)
  {
    if ((sec_r000857_16_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000857_17_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000857_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000857_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000857_19_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000857_14_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000857_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000857_14_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000857_19_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000857_14_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000857_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000857_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000857_1_1 & 1) != 0)
  {
    if ((sec_r000857_23_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000857_1_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000857_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000857_1_1 + 7) & 127;
  }
  if ((sec_r000857_1_2 & 1) != 0)
  {
    if ((sec_r000857_23_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000857_1_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000857_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000857_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000857_22_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000857_2_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000857_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000857_2_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000857_22_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000857_2_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000857_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000857_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000857_20_1 & 1) != 0)
  {
    if ((sec_r000857_7_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000857_16_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000857_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000857_16_1 + 7) & 127;
  }
  if ((sec_r000857_20_2 & 1) != 0)
  {
    if ((sec_r000857_7_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000857_16_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000857_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000857_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000857_18_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000857_17_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000857_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000857_17_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000857_18_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000857_17_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000857_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000857_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000857_10_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000857_2_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000857_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000857_2_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000857_10_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000857_2_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000857_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000857_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000857_20_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000857_12_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000857_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000857_12_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000857_20_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000857_12_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000857_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000857_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000857_3_1 & 1) != 0)
  {
    if ((sec_r000857_17_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000857_10_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000857_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000857_10_1 + 7) & 127;
  }
  if ((sec_r000857_3_2 & 1) != 0)
  {
    if ((sec_r000857_17_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000857_10_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000857_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000857_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000857_12_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000857_13_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000857_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000857_13_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000857_12_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000857_13_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000857_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000857_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000857_7_1 & 1) != 0)
  {
    if ((sec_r000857_20_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000857_18_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000857_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000857_18_1 + 7) & 127;
  }
  if ((sec_r000857_7_2 & 1) != 0)
  {
    if ((sec_r000857_20_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000857_18_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000857_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000857_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000857_14_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000857_12_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000857_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000857_12_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000857_14_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000857_12_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000857_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000857_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000857_4_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000857_12_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000857_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000857_12_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000857_4_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000857_12_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000857_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000857_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000857_18_1 & 1) != 0)
  {
    if ((sec_r000857_9_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((sec_r000857_18_2 & 1) != 0)
  {
    if ((sec_r000857_9_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000857_13_1 & 1) != 0)
  {
    if ((sec_r000857_18_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000857_16_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000857_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000857_16_1 + 7) & 127;
  }
  if ((sec_r000857_13_2 & 1) != 0)
  {
    if ((sec_r000857_18_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000857_16_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000857_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000857_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000857_0_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000857_0_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000857_17_1 & 1) != 0)
  {
    if ((sec_r000857_12_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000857_1_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000857_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000857_1_1 + 7) & 127;
  }
  if ((sec_r000857_17_2 & 1) != 0)
  {
    if ((sec_r000857_12_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000857_1_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000857_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000857_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000857_22_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000857_9_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000857_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000857_9_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000857_22_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000857_9_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000857_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000857_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000857_14_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000857_4_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000857_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000857_4_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000857_14_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000857_4_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000857_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000857_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000857_5_1 & 1) != 0)
  {
    if ((sec_r000857_22_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000857_18_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000857_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000857_18_1 + 7) & 127;
  }
  if ((sec_r000857_5_2 & 1) != 0)
  {
    if ((sec_r000857_22_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000857_18_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000857_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000857_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000857_18_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000857_8_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000857_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000857_8_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000857_18_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000857_8_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000857_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000857_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000857_9_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000857_18_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000857_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000857_18_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000857_9_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000857_18_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000857_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000857_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000857_3_1 & 1) != 0)
  {
    if ((sec_r000857_4_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000857_5_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000857_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000857_5_1 + 7) & 127;
  }
  if ((sec_r000857_3_2 & 1) != 0)
  {
    if ((sec_r000857_4_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000857_5_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000857_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000857_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000857_8_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000857_1_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000857_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000857_1_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000857_8_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000857_1_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000857_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000857_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000857_23_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000857_15_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000857_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000857_15_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000857_23_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000857_15_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000857_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000857_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000857_6_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000857_4_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000857_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000857_4_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000857_6_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000857_4_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000857_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000857_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000857_8_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000857_6_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000857_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000857_6_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000857_8_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000857_6_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000857_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000857_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000857_19_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000857_3_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000857_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000857_3_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000857_19_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000857_3_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000857_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000857_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((sec_r000857_18_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000857_17_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000857_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000857_17_1 + 7) & 127;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((sec_r000857_18_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000857_17_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000857_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000857_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000857_8_1 & 1) != 0)
  {
    if ((sec_r000857_21_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000857_10_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000857_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000857_10_1 + 7) & 127;
  }
  if ((sec_r000857_8_2 & 1) != 0)
  {
    if ((sec_r000857_21_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000857_10_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000857_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000857_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000857_10_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000857_12_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000857_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000857_12_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000857_10_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000857_12_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000857_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000857_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000857_2_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000857_11_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000857_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000857_11_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000857_2_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000857_11_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000857_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000857_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000857_8_1 & 1) != 0)
  {
    if ((sec_r000857_10_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000857_8_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000857_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000857_8_1 + 7) & 127;
  }
  if ((sec_r000857_8_2 & 1) != 0)
  {
    if ((sec_r000857_10_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000857_8_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000857_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000857_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000857_21_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000857_9_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000857_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000857_9_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000857_21_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000857_9_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000857_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000857_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000857_2_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000857_9_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000857_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000857_9_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000857_2_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000857_9_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000857_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000857_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000857_14_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000857_2_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000857_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000857_2_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000857_14_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000857_2_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000857_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000857_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000857_2_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000857_2_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000857_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000857_2_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000857_2_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000857_2_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000857_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000857_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000857_20_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000857_7_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000857_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000857_7_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000857_20_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000857_7_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000857_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000857_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000857_0_1 & 1) != 0)
  {
    if ((sec_r000857_1_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000857_15_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000857_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000857_15_1 + 7) & 127;
  }
  if ((sec_r000857_0_2 & 1) != 0)
  {
    if ((sec_r000857_1_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000857_15_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000857_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000857_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000857_15_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000857_14_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000857_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000857_14_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000857_15_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000857_14_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000857_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000857_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000857_20_1 & 1) != 0)
  {
    if ((sec_r000857_8_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000857_0_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000857_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000857_0_1 + 7) & 127;
  }
  if ((sec_r000857_20_2 & 1) != 0)
  {
    if ((sec_r000857_8_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000857_0_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000857_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000857_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000857_19_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000857_19_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000857_11_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000857_1_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000857_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000857_1_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000857_11_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000857_1_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000857_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000857_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000857_16_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000857_18_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000857_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000857_18_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000857_16_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000857_18_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000857_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000857_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((sec_r000857_11_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((sec_r000857_11_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000857_7_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000857_12_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000857_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000857_12_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000857_7_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000857_12_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000857_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000857_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000857_20_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000857_15_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000857_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000857_15_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000857_20_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000857_15_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000857_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000857_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((sec_r000857_2_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000857_4_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000857_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000857_4_1 + 7) & 127;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((sec_r000857_2_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000857_4_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000857_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000857_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000857_9_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000857_9_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((sec_r000857_14_1 & 1) != 0)
  {
    if ((sec_r000857_0_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000857_15_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000857_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000857_15_1 + 7) & 127;
  }
  if ((sec_r000857_14_2 & 1) != 0)
  {
    if ((sec_r000857_0_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000857_15_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000857_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000857_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000857_6_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000857_14_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000857_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000857_14_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000857_6_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000857_14_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000857_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000857_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((sec_r000857_1_1 & 1) != 0)
  {
    if ((sec_r000857_10_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000857_9_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000857_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000857_9_1 + 7) & 127;
  }
  if ((sec_r000857_1_2 & 1) != 0)
  {
    if ((sec_r000857_10_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000857_9_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000857_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000857_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000857_18_1 & 1) != 0)
  {
    if ((sec_r000857_17_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000857_0_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000857_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000857_0_1 + 7) & 127;
  }
  if ((sec_r000857_18_2 & 1) != 0)
  {
    if ((sec_r000857_17_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000857_0_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000857_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000857_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((sec_r000857_19_1 & 1) != 0)
  {
    if ((sec_r000857_23_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000857_1_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000857_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000857_1_1 + 7) & 127;
  }
  if ((sec_r000857_19_2 & 1) != 0)
  {
    if ((sec_r000857_23_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000857_1_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000857_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000857_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000857_21_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000857_19_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000857_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000857_19_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000857_21_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000857_19_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000857_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000857_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000857_20_1 != sec_r000857_20_2);
  __CPROVER_assume(sec_r000857_11_1 != sec_r000857_11_2);
  __CPROVER_assume(pub_r000857_10_1 == pub_r000857_10_2);
  __CPROVER_assume(sec_r000857_7_1 != sec_r000857_7_2);
  __CPROVER_assume(pub_r000857_11_1 == pub_r000857_11_2);
  __CPROVER_assume(pub_r000857_1_1 == pub_r000857_1_2);
  __CPROVER_assume(sec_r000857_3_1 != sec_r000857_3_2);
  __CPROVER_assume(pub_r000857_15_1 == pub_r000857_15_2);
  __CPROVER_assume(sec_r000857_8_1 != sec_r000857_8_2);
  __CPROVER_assume(sec_r000857_19_1 != sec_r000857_19_2);
  __CPROVER_assume(pub_r000857_2_1 == pub_r000857_2_2);
  __CPROVER_assume(pub_r000857_8_1 == pub_r000857_8_2);
  __CPROVER_assume(pub_r000857_6_1 == pub_r000857_6_2);
  __CPROVER_assume(sec_r000857_22_1 != sec_r000857_22_2);
  __CPROVER_assume(pub_r000857_9_1 == pub_r000857_9_2);
  __CPROVER_assume(pub_r000857_4_1 == pub_r000857_4_2);
  __CPROVER_assume(pub_r000857_7_1 == pub_r000857_7_2);
  __CPROVER_assume(pub_r000857_18_1 == pub_r000857_18_2);
  __CPROVER_assume(sec_r000857_2_1 != sec_r000857_2_2);
  __CPROVER_assume(sec_r000857_13_1 != sec_r000857_13_2);
  __CPROVER_assume(sec_r000857_23_1 != sec_r000857_23_2);
  __CPROVER_assume(pub_r000857_16_1 == pub_r000857_16_2);
  __CPROVER_assume(sec_r000857_14_1 != sec_r000857_14_2);
  __CPROVER_assume(pub_r000857_12_1 == pub_r000857_12_2);
  __CPROVER_assume(sec_r000857_15_1 != sec_r000857_15_2);
  __CPROVER_assume(pub_r000857_5_1 == pub_r000857_5_2);
  __CPROVER_assume(sec_r000857_5_1 != sec_r000857_5_2);
  __CPROVER_assume(sec_r000857_6_1 != sec_r000857_6_2);
  __CPROVER_assume(sec_r000857_9_1 != sec_r000857_9_2);
  __CPROVER_assume(sec_r000857_1_1 != sec_r000857_1_2);
  __CPROVER_assume(sec_r000857_10_1 != sec_r000857_10_2);
  __CPROVER_assume(sec_r000857_17_1 != sec_r000857_17_2);
  __CPROVER_assume(sec_r000857_21_1 != sec_r000857_21_2);
  __CPROVER_assume(sec_r000857_16_1 != sec_r000857_16_2);
  __CPROVER_assume(sec_r000857_18_1 != sec_r000857_18_2);
  __CPROVER_assume(sec_r000857_4_1 != sec_r000857_4_2);
  __CPROVER_assume(pub_r000857_0_1 == pub_r000857_0_2);
  __CPROVER_assume(sec_r000857_0_1 != sec_r000857_0_2);
  __CPROVER_assume(pub_r000857_13_1 == pub_r000857_13_2);
  __CPROVER_assume(pub_r000857_3_1 == pub_r000857_3_2);
  __CPROVER_assume(pub_r000857_14_1 == pub_r000857_14_2);
  __CPROVER_assume(pub_r000857_17_1 == pub_r000857_17_2);
  __CPROVER_assume(pub_r000857_19_1 == pub_r000857_19_2);
  __CPROVER_assume(sec_r000857_12_1 != sec_r000857_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.id == st_var_2_2.id);
  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.determinant == st_var_3_2.determinant);
  assert(st_var_3_1.density == st_var_3_2.density);
  assert(st_var_3_1.scale == st_var_3_2.scale);
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
  assert(stage_v_162_1 == stage_v_162_2);
}


