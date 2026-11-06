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
struct MatrixBlock_R000244_4413_0
{
  unsigned char scale;
  short stride;
  unsigned char determinant;
  int buffer[3];
};
struct CipherContext_R000244_4413_1
{
  int counter;
  unsigned char round_key;
  int flags;
  int tag;
  int buffer[3];
};
struct SensorNode_R000244_4413_2
{
  int status;
  int offset;
  int threshold;
  int reading;
  short gain;
  unsigned char calib;
  int buffer[3];
};
struct Transaction_R000244_4413_3
{
  unsigned char balance;
  int auth_code;
  short fee;
  int buffer[3];
};
union PacketPayload_R000244_4413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000244_4413_1
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
void fn_R000244_4413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st_1 = {0};
  struct CipherContext_R000244_4413_1 st_2 = {0};
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
  int coefficient_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_79_1 > 30)
  {
    acc_1 = ((acc_1 + (coefficient_79_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_79_2 > 30)
  {
    acc_2 = ((acc_2 + (coefficient_79_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_79_1 == coefficient_79_2);
}

int fn_R000244_4413_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_79 > 30)
  {
    acc = ((acc + (coefficient_79 * 2)) + 5) & 127;
    aux ^= coefficient_79 & 15;
  }
  else
  {
    acc = ((acc - coefficient_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000244_4413_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st_1 = {0};
  struct CipherContext_R000244_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int bound_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_37_1 > 50)
  {
    acc_1 = ((acc_1 + (bound_37_1 * 2)) + 5) & 127;
    aux_1 ^= bound_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_37_2 > 50)
  {
    acc_2 = ((acc_2 + (bound_37_2 * 2)) + 5) & 127;
    aux_2 ^= bound_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_37_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_72_1)
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

  switch (phase_72_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_37_1 == bound_37_2);
  assert(phase_72_1 == phase_72_2);
}

int fn_R000244_4413_1(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int bound_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_37 > 50)
  {
    acc = ((acc + (bound_37 * 2)) + 5) & 127;
    aux ^= bound_37 & 15;
  }
  else
  {
    acc = ((acc - bound_37) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_72 = (aux + st.buffer[1]) & 3;
  switch (phase_72)
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

void fn_R000244_4413_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st_1 = {0};
  struct MatrixBlock_R000244_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int offset_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_40_1) & 63;
  aux_2 = (aux_2 + offset_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_99_1 = local_arr_1[aux_1 % 3];
  int phase_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_99_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_40_1 == offset_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_99_1 == phase_99_2);
}

int fn_R000244_4413_2(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int offset_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_40) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_99 = local_arr[aux % 3];
  acc = (acc + (phase_99 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000244_4413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st_1 = {0};
  struct MatrixBlock_R000244_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_70_1 > 33)
  {
    acc_1 = ((acc_1 + (window_70_1 * 2)) + 5) & 127;
    aux_1 ^= window_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_70_2 > 33)
  {
    acc_2 = ((acc_2 + (window_70_2 * 2)) + 5) & 127;
    aux_2 ^= window_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_25_1)
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

  switch (tally_25_2)
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

  int tally_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_42_1) & 63;
  aux_2 = (aux_2 + tally_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_70_1 == window_70_2);
  assert(tally_25_1 == tally_25_2);
  assert(tally_42_1 == tally_42_2);
}

int fn_R000244_4413_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_70 > 33)
  {
    acc = ((acc + (window_70 * 2)) + 5) & 127;
    aux ^= window_70 & 15;
  }
  else
  {
    acc = ((acc - window_70) + 11) & 127;
    aux += 3;
  }
  int tally_25 = (aux + st.buffer[1]) & 3;
  switch (tally_25)
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

  int tally_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000244_4413_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000244_4413_2 st_1 = {0};
  struct SensorNode_R000244_4413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_70_1 > 45)
  {
    acc_1 = ((acc_1 + (parity_70_1 * 2)) + 5) & 127;
    aux_1 ^= parity_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_70_2 > 45)
  {
    acc_2 = ((acc_2 + (parity_70_2 * 2)) + 5) & 127;
    aux_2 ^= parity_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_16_1 = local_arr_1[aux_1 % 3];
  int sample_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_70_1 == parity_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_16_1 == sample_16_2);
}

int fn_R000244_4413_4(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000244_4413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_70 > 45)
  {
    acc = ((acc + (parity_70 * 2)) + 5) & 127;
    aux ^= parity_70 & 15;
  }
  else
  {
    acc = ((acc - parity_70) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_16 = local_arr[aux % 3];
  acc = (acc + (sample_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000244_4413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st_1 = {0};
  struct CipherContext_R000244_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int margin_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_86_1)
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

  switch (margin_86_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_86_1 == margin_86_2);
}

int fn_R000244_4413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int margin_86 = (aux + st.buffer[1]) & 3;
  switch (margin_86)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000244_4413_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000244_4413_3 st_1 = {0};
  struct Transaction_R000244_4413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_44_1 > 20)
  {
    acc_1 = ((acc_1 + (bound_44_1 * 2)) + 5) & 127;
    aux_1 ^= bound_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_44_2 > 20)
  {
    acc_2 = ((acc_2 + (bound_44_2 * 2)) + 5) & 127;
    aux_2 ^= bound_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_44_1 == bound_44_2);
}

int fn_R000244_4413_6(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000244_4413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_44 > 20)
  {
    acc = ((acc + (bound_44 * 2)) + 5) & 127;
    aux ^= bound_44 & 15;
  }
  else
  {
    acc = ((acc - bound_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000244_4413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st_1 = {0};
  struct CipherContext_R000244_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_63_1)
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

  switch (parity_63_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_63_1 == parity_63_2);
}

int fn_R000244_4413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_63 = (aux + st.buffer[1]) & 3;
  switch (parity_63)
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

void fn_R000244_4413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000244_4413_2 st_1 = {0};
  struct SensorNode_R000244_4413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_59_1 = local_arr_1[aux_1 % 3];
  int phase_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_59_2 * 2)) & 127;
  int offset_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_36_1 > 36)
  {
    acc_1 = ((acc_1 + (offset_36_1 * 2)) + 5) & 127;
    aux_1 ^= offset_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_36_2 > 36)
  {
    acc_2 = ((acc_2 + (offset_36_2 * 2)) + 5) & 127;
    aux_2 ^= offset_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_19_1)
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

  switch (margin_19_2)
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

  int sample_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_89_1) & 63;
  aux_2 = (aux_2 + sample_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_59_1 == phase_59_2);
  assert(offset_36_1 == offset_36_2);
  assert(margin_19_1 == margin_19_2);
  assert(sample_89_1 == sample_89_2);
}

int fn_R000244_4413_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000244_4413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int phase_59 = local_arr[aux % 3];
  acc = (acc + (phase_59 * 2)) & 127;
  int offset_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_36 > 36)
  {
    acc = ((acc + (offset_36 * 2)) + 5) & 127;
    aux ^= offset_36 & 15;
  }
  else
  {
    acc = ((acc - offset_36) + 11) & 127;
    aux += 3;
  }
  int margin_19 = (aux + st.buffer[1]) & 3;
  switch (margin_19)
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

  int sample_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000244_4413_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st_1 = {0};
  struct CipherContext_R000244_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_13_1 = local_arr_1[aux_1 % 3];
  int mask_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_13_2 * 2)) & 127;
  int tracker_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_85_1) & 63;
  aux_2 = (aux_2 + tracker_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_63_1 > 24)
  {
    acc_1 = ((acc_1 + (anchor_63_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_63_2 > 24)
  {
    acc_2 = ((acc_2 + (anchor_63_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_29_1)
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

  switch (phase_29_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_13_1 == mask_13_2);
  assert(tracker_85_1 == tracker_85_2);
  assert(anchor_63_1 == anchor_63_2);
  assert(phase_29_1 == phase_29_2);
}

int fn_R000244_4413_9(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int mask_13 = local_arr[aux % 3];
  acc = (acc + (mask_13 * 2)) & 127;
  int tracker_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_85) & 63;
  acc ^= aux;
  int anchor_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_63 > 24)
  {
    acc = ((acc + (anchor_63 * 2)) + 5) & 127;
    aux ^= anchor_63 & 15;
  }
  else
  {
    acc = ((acc - anchor_63) + 11) & 127;
    aux += 3;
  }
  int phase_29 = (aux + st.buffer[1]) & 3;
  switch (phase_29)
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

void fn_R000244_4413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st_1 = {0};
  struct MatrixBlock_R000244_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int quantum_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_69_1)
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

  switch (quantum_69_2)
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

  int scale_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_52_1) & 63;
  aux_2 = (aux_2 + scale_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_34_1 > 40)
  {
    acc_1 = ((acc_1 + (accumulator_34_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_34_2 > 40)
  {
    acc_2 = ((acc_2 + (accumulator_34_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_34_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_69_1 == quantum_69_2);
  assert(scale_52_1 == scale_52_2);
  assert(accumulator_34_1 == accumulator_34_2);
}

int fn_R000244_4413_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int quantum_69 = (aux + st.buffer[1]) & 3;
  switch (quantum_69)
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

  int scale_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_52) & 63;
  acc ^= aux;
  int accumulator_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_34 > 40)
  {
    acc = ((acc + (accumulator_34 * 2)) + 5) & 127;
    aux ^= accumulator_34 & 15;
  }
  else
  {
    acc = ((acc - accumulator_34) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000244_4413_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st_1 = {0};
  struct CipherContext_R000244_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int offset_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_75_1) & 63;
  aux_2 = (aux_2 + offset_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_63_1)
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

  switch (stride_63_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_97_1 > 25)
  {
    acc_1 = ((acc_1 + (offset_97_1 * 2)) + 5) & 127;
    aux_1 ^= offset_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_97_2 > 25)
  {
    acc_2 = ((acc_2 + (offset_97_2 * 2)) + 5) & 127;
    aux_2 ^= offset_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_75_1 == offset_75_2);
  assert(stride_63_1 == stride_63_2);
  assert(offset_97_1 == offset_97_2);
}

int fn_R000244_4413_11(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int offset_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_75) & 63;
  acc ^= aux;
  int stride_63 = (aux + st.buffer[1]) & 3;
  switch (stride_63)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_97 > 25)
  {
    acc = ((acc + (offset_97 * 2)) + 5) & 127;
    aux ^= offset_97 & 15;
  }
  else
  {
    acc = ((acc - offset_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000244_4413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st_1 = {0};
  struct MatrixBlock_R000244_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_84_1 = local_arr_1[aux_1 % 3];
  int residue_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_84_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_35_1) & 63;
  aux_2 = (aux_2 + metric_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_77_1 > 20)
  {
    acc_1 = ((acc_1 + (checksum_77_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_77_2 > 20)
  {
    acc_2 = ((acc_2 + (checksum_77_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_84_1 == residue_84_2);
  assert(metric_35_1 == metric_35_2);
  assert(checksum_77_1 == checksum_77_2);
}

int fn_R000244_4413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int residue_84 = local_arr[aux % 3];
  acc = (acc + (residue_84 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_35) & 63;
  acc ^= aux;
  int checksum_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_77 > 20)
  {
    acc = ((acc + (checksum_77 * 2)) + 5) & 127;
    aux ^= checksum_77 & 15;
  }
  else
  {
    acc = ((acc - checksum_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000244_4413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st_1 = {0};
  struct CipherContext_R000244_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int delta_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_70_1) & 63;
  aux_2 = (aux_2 + delta_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_97_1)
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

  switch (threshold_97_2)
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
  int parity_85_1 = local_arr_1[aux_1 % 3];
  int parity_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_85_2 * 2)) & 127;
  int residue_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_99_1 > 15)
  {
    acc_1 = ((acc_1 + (residue_99_1 * 2)) + 5) & 127;
    aux_1 ^= residue_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_99_2 > 15)
  {
    acc_2 = ((acc_2 + (residue_99_2 * 2)) + 5) & 127;
    aux_2 ^= residue_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_70_1 == delta_70_2);
  assert(threshold_97_1 == threshold_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_85_1 == parity_85_2);
  assert(residue_99_1 == residue_99_2);
}

int fn_R000244_4413_13(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int delta_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_70) & 63;
  acc ^= aux;
  int threshold_97 = (aux + st.buffer[1]) & 3;
  switch (threshold_97)
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
  int parity_85 = local_arr[aux % 3];
  acc = (acc + (parity_85 * 2)) & 127;
  int residue_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_99 > 15)
  {
    acc = ((acc + (residue_99 * 2)) + 5) & 127;
    aux ^= residue_99 & 15;
  }
  else
  {
    acc = ((acc - residue_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000244_4413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st_1 = {0};
  struct CipherContext_R000244_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int metric_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_41_1 > 10)
  {
    acc_1 = ((acc_1 + (metric_41_1 * 2)) + 5) & 127;
    aux_1 ^= metric_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_41_2 > 10)
  {
    acc_2 = ((acc_2 + (metric_41_2 * 2)) + 5) & 127;
    aux_2 ^= metric_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_81_1 = local_arr_1[aux_1 % 3];
  int index_reg_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_81_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_41_1 == metric_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_81_1 == index_reg_81_2);
}

int fn_R000244_4413_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int metric_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_41 > 10)
  {
    acc = ((acc + (metric_41 * 2)) + 5) & 127;
    aux ^= metric_41 & 15;
  }
  else
  {
    acc = ((acc - metric_41) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_81 = local_arr[aux % 3];
  acc = (acc + (index_reg_81 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000244_4413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st_1 = {0};
  struct MatrixBlock_R000244_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int accumulator_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_61_1)
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

  switch (accumulator_61_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_58_1 > 39)
  {
    acc_1 = ((acc_1 + (coefficient_58_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_58_2 > 39)
  {
    acc_2 = ((acc_2 + (coefficient_58_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_61_1 == accumulator_61_2);
  assert(coefficient_58_1 == coefficient_58_2);
}

int fn_R000244_4413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int accumulator_61 = (aux + st.buffer[1]) & 3;
  switch (accumulator_61)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_58 > 39)
  {
    acc = ((acc + (coefficient_58 * 2)) + 5) & 127;
    aux ^= coefficient_58 & 15;
  }
  else
  {
    acc = ((acc - coefficient_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000244_4413_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st_1 = {0};
  struct CipherContext_R000244_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_62_1 = local_arr_1[aux_1 % 3];
  int vector_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_62_2 * 2)) & 127;
  int offset_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_60_1 > 32)
  {
    acc_1 = ((acc_1 + (offset_60_1 * 2)) + 5) & 127;
    aux_1 ^= offset_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_60_2 > 32)
  {
    acc_2 = ((acc_2 + (offset_60_2 * 2)) + 5) & 127;
    aux_2 ^= offset_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_62_1 == vector_62_2);
  assert(offset_60_1 == offset_60_2);
}

int fn_R000244_4413_16(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int vector_62 = local_arr[aux % 3];
  acc = (acc + (vector_62 * 2)) & 127;
  int offset_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_60 > 32)
  {
    acc = ((acc + (offset_60 * 2)) + 5) & 127;
    aux ^= offset_60 & 15;
  }
  else
  {
    acc = ((acc - offset_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000244_4413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000244_4413_3 st_1 = {0};
  struct Transaction_R000244_4413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_28_1 = local_arr_1[aux_1 % 3];
  int vector_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_28_2 * 2)) & 127;
  int segment_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_49_1 > 15)
  {
    acc_1 = ((acc_1 + (segment_49_1 * 2)) + 5) & 127;
    aux_1 ^= segment_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_49_2 > 15)
  {
    acc_2 = ((acc_2 + (segment_49_2 * 2)) + 5) & 127;
    aux_2 ^= segment_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_49_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_35_1) & 63;
  aux_2 = (aux_2 + anchor_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_28_1 == vector_28_2);
  assert(segment_49_1 == segment_49_2);
  assert(anchor_35_1 == anchor_35_2);
}

int fn_R000244_4413_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000244_4413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int vector_28 = local_arr[aux % 3];
  acc = (acc + (vector_28 * 2)) & 127;
  int segment_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_49 > 15)
  {
    acc = ((acc + (segment_49 * 2)) + 5) & 127;
    aux ^= segment_49 & 15;
  }
  else
  {
    acc = ((acc - segment_49) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000244_4413_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000244_4413_2 st_1 = {0};
  struct SensorNode_R000244_4413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int pivot_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_97_1 > 35)
  {
    acc_1 = ((acc_1 + (pivot_97_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_97_2 > 35)
  {
    acc_2 = ((acc_2 + (pivot_97_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_84_1 = local_arr_1[aux_1 % 3];
  int scale_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_84_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_97_1 == pivot_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_84_1 == scale_84_2);
}

int fn_R000244_4413_18(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000244_4413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int pivot_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_97 > 35)
  {
    acc = ((acc + (pivot_97 * 2)) + 5) & 127;
    aux ^= pivot_97 & 15;
  }
  else
  {
    acc = ((acc - pivot_97) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_84 = local_arr[aux % 3];
  acc = (acc + (scale_84 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000244_4413_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st_1 = {0};
  struct CipherContext_R000244_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_34_1) & 63;
  aux_2 = (aux_2 + segment_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_48_1)
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

  switch (damping_48_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_34_1 == segment_34_2);
  assert(damping_48_1 == damping_48_2);
}

int fn_R000244_4413_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_34) & 63;
  acc ^= aux;
  int damping_48 = (aux + st.buffer[1]) & 3;
  switch (damping_48)
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

void fn_R000244_4413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st_1 = {0};
  struct MatrixBlock_R000244_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_33_1)
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

  switch (weight_33_2)
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
  int cursor_41_1 = local_arr_1[aux_1 % 3];
  int cursor_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_41_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_33_1 == weight_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_41_1 == cursor_41_2);
}

int fn_R000244_4413_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000244_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_33 = (aux + st.buffer[1]) & 3;
  switch (weight_33)
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
  int cursor_41 = local_arr[aux % 3];
  acc = (acc + (cursor_41 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000244_4413_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st_1 = {0};
  struct CipherContext_R000244_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int checksum_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_33_1 > 48)
  {
    acc_1 = ((acc_1 + (checksum_33_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_33_2 > 48)
  {
    acc_2 = ((acc_2 + (checksum_33_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_85_1 = local_arr_1[aux_1 % 3];
  int factor_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_33_1 == checksum_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_85_1 == factor_85_2);
}

int fn_R000244_4413_21(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000244_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int checksum_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_33 > 48)
  {
    acc = ((acc + (checksum_33 * 2)) + 5) & 127;
    aux ^= checksum_33 & 15;
  }
  else
  {
    acc = ((acc - checksum_33) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_85 = local_arr[aux % 3];
  acc = (acc + (factor_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000244_0_1;
  int sec_r000244_0_2;
  int sec_r000244_1_1;
  int sec_r000244_1_2;
  int sec_r000244_2_1;
  int sec_r000244_2_2;
  int sec_r000244_3_1;
  int sec_r000244_3_2;
  int sec_r000244_4_1;
  int sec_r000244_4_2;
  int sec_r000244_5_1;
  int sec_r000244_5_2;
  int sec_r000244_6_1;
  int sec_r000244_6_2;
  int sec_r000244_7_1;
  int sec_r000244_7_2;
  int sec_r000244_8_1;
  int sec_r000244_8_2;
  int sec_r000244_9_1;
  int sec_r000244_9_2;
  int sec_r000244_10_1;
  int sec_r000244_10_2;
  int sec_r000244_11_1;
  int sec_r000244_11_2;
  int sec_r000244_12_1;
  int sec_r000244_12_2;
  int sec_r000244_13_1;
  int sec_r000244_13_2;
  int sec_r000244_14_1;
  int sec_r000244_14_2;
  int sec_r000244_15_1;
  int sec_r000244_15_2;
  int sec_r000244_16_1;
  int sec_r000244_16_2;
  int sec_r000244_17_1;
  int sec_r000244_17_2;
  int sec_r000244_18_1;
  int sec_r000244_18_2;
  int sec_r000244_19_1;
  int sec_r000244_19_2;
  int sec_r000244_20_1;
  int sec_r000244_20_2;
  int sec_r000244_21_1;
  int sec_r000244_21_2;
  int sec_r000244_22_1;
  int sec_r000244_22_2;
  int sec_r000244_23_1;
  int sec_r000244_23_2;
  int pub_r000244_0_1;
  int pub_r000244_0_2;
  int pub_r000244_1_1;
  int pub_r000244_1_2;
  int pub_r000244_2_1;
  int pub_r000244_2_2;
  int pub_r000244_3_1;
  int pub_r000244_3_2;
  int pub_r000244_4_1;
  int pub_r000244_4_2;
  int pub_r000244_5_1;
  int pub_r000244_5_2;
  int pub_r000244_6_1;
  int pub_r000244_6_2;
  int pub_r000244_7_1;
  int pub_r000244_7_2;
  int pub_r000244_8_1;
  int pub_r000244_8_2;
  int pub_r000244_9_1;
  int pub_r000244_9_2;
  int pub_r000244_10_1;
  int pub_r000244_10_2;
  int pub_r000244_11_1;
  int pub_r000244_11_2;
  int pub_r000244_12_1;
  int pub_r000244_12_2;
  int pub_r000244_13_1;
  int pub_r000244_13_2;
  int pub_r000244_14_1;
  int pub_r000244_14_2;
  int pub_r000244_15_1;
  int pub_r000244_15_2;
  int pub_r000244_16_1;
  int pub_r000244_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000244_0_1 >= (-100)) && (pub_r000244_0_1 <= 100));
  __CPROVER_assume((pub_r000244_0_2 >= (-100)) && (pub_r000244_0_2 <= 100));
  __CPROVER_assume((pub_r000244_1_1 >= (-100)) && (pub_r000244_1_1 <= 100));
  __CPROVER_assume((pub_r000244_1_2 >= (-100)) && (pub_r000244_1_2 <= 100));
  __CPROVER_assume((pub_r000244_2_1 >= (-100)) && (pub_r000244_2_1 <= 100));
  __CPROVER_assume((pub_r000244_2_2 >= (-100)) && (pub_r000244_2_2 <= 100));
  __CPROVER_assume((pub_r000244_3_1 >= (-100)) && (pub_r000244_3_1 <= 100));
  __CPROVER_assume((pub_r000244_3_2 >= (-100)) && (pub_r000244_3_2 <= 100));
  __CPROVER_assume((pub_r000244_4_1 >= (-100)) && (pub_r000244_4_1 <= 100));
  __CPROVER_assume((pub_r000244_4_2 >= (-100)) && (pub_r000244_4_2 <= 100));
  __CPROVER_assume((pub_r000244_5_1 >= (-100)) && (pub_r000244_5_1 <= 100));
  __CPROVER_assume((pub_r000244_5_2 >= (-100)) && (pub_r000244_5_2 <= 100));
  __CPROVER_assume((pub_r000244_6_1 >= (-100)) && (pub_r000244_6_1 <= 100));
  __CPROVER_assume((pub_r000244_6_2 >= (-100)) && (pub_r000244_6_2 <= 100));
  __CPROVER_assume((pub_r000244_7_1 >= (-100)) && (pub_r000244_7_1 <= 100));
  __CPROVER_assume((pub_r000244_7_2 >= (-100)) && (pub_r000244_7_2 <= 100));
  __CPROVER_assume((pub_r000244_8_1 >= (-100)) && (pub_r000244_8_1 <= 100));
  __CPROVER_assume((pub_r000244_8_2 >= (-100)) && (pub_r000244_8_2 <= 100));
  __CPROVER_assume((pub_r000244_9_1 >= (-100)) && (pub_r000244_9_1 <= 100));
  __CPROVER_assume((pub_r000244_9_2 >= (-100)) && (pub_r000244_9_2 <= 100));
  __CPROVER_assume((pub_r000244_10_1 >= (-100)) && (pub_r000244_10_1 <= 100));
  __CPROVER_assume((pub_r000244_10_2 >= (-100)) && (pub_r000244_10_2 <= 100));
  __CPROVER_assume((pub_r000244_11_1 >= (-100)) && (pub_r000244_11_1 <= 100));
  __CPROVER_assume((pub_r000244_11_2 >= (-100)) && (pub_r000244_11_2 <= 100));
  __CPROVER_assume((pub_r000244_12_1 >= (-100)) && (pub_r000244_12_1 <= 100));
  __CPROVER_assume((pub_r000244_12_2 >= (-100)) && (pub_r000244_12_2 <= 100));
  __CPROVER_assume((pub_r000244_13_1 >= (-100)) && (pub_r000244_13_1 <= 100));
  __CPROVER_assume((pub_r000244_13_2 >= (-100)) && (pub_r000244_13_2 <= 100));
  __CPROVER_assume((pub_r000244_14_1 >= (-100)) && (pub_r000244_14_1 <= 100));
  __CPROVER_assume((pub_r000244_14_2 >= (-100)) && (pub_r000244_14_2 <= 100));
  __CPROVER_assume((pub_r000244_15_1 >= (-100)) && (pub_r000244_15_1 <= 100));
  __CPROVER_assume((pub_r000244_15_2 >= (-100)) && (pub_r000244_15_2 <= 100));
  __CPROVER_assume((pub_r000244_16_1 >= (-100)) && (pub_r000244_16_1 <= 100));
  __CPROVER_assume((pub_r000244_16_2 >= (-100)) && (pub_r000244_16_2 <= 100));
  __CPROVER_assume((sec_r000244_0_1 >= 0) && (sec_r000244_0_1 <= 255));
  __CPROVER_assume((sec_r000244_0_2 >= 0) && (sec_r000244_0_2 <= 255));
  __CPROVER_assume((sec_r000244_1_1 >= 0) && (sec_r000244_1_1 <= 255));
  __CPROVER_assume((sec_r000244_1_2 >= 0) && (sec_r000244_1_2 <= 255));
  __CPROVER_assume((sec_r000244_2_1 >= 0) && (sec_r000244_2_1 <= 255));
  __CPROVER_assume((sec_r000244_2_2 >= 0) && (sec_r000244_2_2 <= 255));
  __CPROVER_assume((sec_r000244_3_1 >= 0) && (sec_r000244_3_1 <= 255));
  __CPROVER_assume((sec_r000244_3_2 >= 0) && (sec_r000244_3_2 <= 255));
  __CPROVER_assume((sec_r000244_4_1 >= 0) && (sec_r000244_4_1 <= 255));
  __CPROVER_assume((sec_r000244_4_2 >= 0) && (sec_r000244_4_2 <= 255));
  __CPROVER_assume((sec_r000244_5_1 >= 0) && (sec_r000244_5_1 <= 255));
  __CPROVER_assume((sec_r000244_5_2 >= 0) && (sec_r000244_5_2 <= 255));
  __CPROVER_assume((sec_r000244_6_1 >= 0) && (sec_r000244_6_1 <= 255));
  __CPROVER_assume((sec_r000244_6_2 >= 0) && (sec_r000244_6_2 <= 255));
  __CPROVER_assume((sec_r000244_7_1 >= 0) && (sec_r000244_7_1 <= 255));
  __CPROVER_assume((sec_r000244_7_2 >= 0) && (sec_r000244_7_2 <= 255));
  __CPROVER_assume((sec_r000244_8_1 >= 0) && (sec_r000244_8_1 <= 255));
  __CPROVER_assume((sec_r000244_8_2 >= 0) && (sec_r000244_8_2 <= 255));
  __CPROVER_assume((sec_r000244_9_1 >= 0) && (sec_r000244_9_1 <= 255));
  __CPROVER_assume((sec_r000244_9_2 >= 0) && (sec_r000244_9_2 <= 255));
  __CPROVER_assume((sec_r000244_10_1 >= 0) && (sec_r000244_10_1 <= 255));
  __CPROVER_assume((sec_r000244_10_2 >= 0) && (sec_r000244_10_2 <= 255));
  __CPROVER_assume((sec_r000244_11_1 >= 0) && (sec_r000244_11_1 <= 255));
  __CPROVER_assume((sec_r000244_11_2 >= 0) && (sec_r000244_11_2 <= 255));
  __CPROVER_assume((sec_r000244_12_1 >= 0) && (sec_r000244_12_1 <= 255));
  __CPROVER_assume((sec_r000244_12_2 >= 0) && (sec_r000244_12_2 <= 255));
  __CPROVER_assume((sec_r000244_13_1 >= 0) && (sec_r000244_13_1 <= 255));
  __CPROVER_assume((sec_r000244_13_2 >= 0) && (sec_r000244_13_2 <= 255));
  __CPROVER_assume((sec_r000244_14_1 >= 0) && (sec_r000244_14_1 <= 255));
  __CPROVER_assume((sec_r000244_14_2 >= 0) && (sec_r000244_14_2 <= 255));
  __CPROVER_assume((sec_r000244_15_1 >= 0) && (sec_r000244_15_1 <= 255));
  __CPROVER_assume((sec_r000244_15_2 >= 0) && (sec_r000244_15_2 <= 255));
  __CPROVER_assume((sec_r000244_16_1 >= 0) && (sec_r000244_16_1 <= 255));
  __CPROVER_assume((sec_r000244_16_2 >= 0) && (sec_r000244_16_2 <= 255));
  __CPROVER_assume((sec_r000244_17_1 >= 0) && (sec_r000244_17_1 <= 255));
  __CPROVER_assume((sec_r000244_17_2 >= 0) && (sec_r000244_17_2 <= 255));
  __CPROVER_assume((sec_r000244_18_1 >= 0) && (sec_r000244_18_1 <= 255));
  __CPROVER_assume((sec_r000244_18_2 >= 0) && (sec_r000244_18_2 <= 255));
  __CPROVER_assume((sec_r000244_19_1 >= 0) && (sec_r000244_19_1 <= 255));
  __CPROVER_assume((sec_r000244_19_2 >= 0) && (sec_r000244_19_2 <= 255));
  __CPROVER_assume((sec_r000244_20_1 >= 0) && (sec_r000244_20_1 <= 255));
  __CPROVER_assume((sec_r000244_20_2 >= 0) && (sec_r000244_20_2 <= 255));
  __CPROVER_assume((sec_r000244_21_1 >= 0) && (sec_r000244_21_1 <= 255));
  __CPROVER_assume((sec_r000244_21_2 >= 0) && (sec_r000244_21_2 <= 255));
  __CPROVER_assume((sec_r000244_22_1 >= 0) && (sec_r000244_22_1 <= 255));
  __CPROVER_assume((sec_r000244_22_2 >= 0) && (sec_r000244_22_2 <= 255));
  __CPROVER_assume((sec_r000244_23_1 >= 0) && (sec_r000244_23_1 <= 255));
  __CPROVER_assume((sec_r000244_23_2 >= 0) && (sec_r000244_23_2 <= 255));
  struct MatrixBlock_R000244_4413_0 st_var_0_1 = {0};
  struct MatrixBlock_R000244_4413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000244_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000244_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000244_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000244_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000244_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000244_0_2 + 7) & 15;
  struct CipherContext_R000244_4413_1 st_var_1_1 = {0};
  struct CipherContext_R000244_4413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000244_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000244_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000244_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000244_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000244_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000244_0_2 + 9) & 15;
  struct SensorNode_R000244_4413_2 st_var_2_1 = {0};
  struct SensorNode_R000244_4413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000244_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000244_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000244_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000244_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000244_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000244_0_2 + 11) & 15;
  struct Transaction_R000244_4413_3 st_var_3_1 = {0};
  struct Transaction_R000244_4413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000244_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000244_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000244_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000244_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000244_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000244_0_2 + 13) & 15;
  union PacketPayload_R000244_4413_0 u_var_1;
  union PacketPayload_R000244_4413_0 u_var_2;
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
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = (st_var_2_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_2_2.buffer[0] ^ 13) & 3;
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

  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 44)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 44)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 15) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = ((st_var_3_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_3_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 54)
    {
      chk_sum_1 ^= stage_v_15_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_15_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 54)
    {
      chk_sum_2 ^= stage_v_15_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 20) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 20) & 15;
  int stage_v_19_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_19_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= stage_v_19_1;
  chk_sum_2 ^= stage_v_19_2;
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = (st_var_2_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_2_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 37)
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
  if (stage_v_33_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 37)
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
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
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
  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (st_var_3_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_3_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
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
  int stage_v_44_1 = (st_var_0_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_0_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = (st_var_1_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_1_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = table_1[2];
  int stage_v_46_2 = table_2[2];
  table_1[2] = (table_1[3] + 93) & 63;
  table_2[2] = (table_2[3] + 93) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 49) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 49) & 15;
  int stage_v_48_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_48_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= stage_v_48_1;
  chk_sum_2 ^= stage_v_48_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (st_var_0_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_0_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 54) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 54) & 15;
  int stage_v_53_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_53_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= stage_v_53_1;
  chk_sum_2 ^= stage_v_53_2;
  int stage_v_54_1 = (st_var_2_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_2_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = table_1[0];
  int stage_v_56_2 = table_2[0];
  table_1[0] = (table_1[1] + 113) & 63;
  table_2[0] = (table_2[1] + 113) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((((sec_r000244_12_1 * 3) + (sec_r000244_12_1 * 2)) - pub_r000244_7_1) + 27) & 127;
  int stage_v_58_2 = ((((sec_r000244_12_2 * 3) + (sec_r000244_12_2 * 2)) - pub_r000244_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((((stage_v_58_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_10_1) + 26) & 127;
  int stage_v_59_2 = ((((stage_v_58_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_59_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_59_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((((stage_v_58_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_13_1) + 32) & 127;
  int stage_v_60_2 = ((((stage_v_58_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((((stage_v_59_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_3_1) + 24) & 127;
  int stage_v_61_2 = ((((stage_v_59_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((((stage_v_59_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_7_1) + 35) & 127;
  int stage_v_62_2 = ((((stage_v_59_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((((sec_r000244_17_1 * 3) + (sec_r000244_17_1 * 2)) - pub_r000244_14_1) + 4) & 127;
  int stage_v_63_2 = ((((sec_r000244_17_2 * 3) + (sec_r000244_17_2 * 2)) - pub_r000244_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((((stage_v_62_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_8_1) + 8) & 127;
  int stage_v_64_2 = ((((stage_v_62_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((((sec_r000244_3_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_13_1) + 36) & 127;
  int stage_v_65_2 = ((((sec_r000244_3_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((((stage_v_63_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_0_1) + 15) & 127;
  int stage_v_66_2 = ((((stage_v_63_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((((stage_v_62_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_9_1) + 37) & 127;
  int stage_v_67_2 = ((((stage_v_62_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((((stage_v_59_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_5_1) + 24) & 127;
  int stage_v_68_2 = ((((stage_v_59_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((((stage_v_63_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_12_1) + 29) & 127;
  int stage_v_69_2 = ((((stage_v_63_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((((sec_r000244_15_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_1_1) + 8) & 127;
  int stage_v_70_2 = ((((sec_r000244_15_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((((stage_v_68_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_3_1) + 29) & 127;
  int stage_v_71_2 = ((((stage_v_68_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((((stage_v_66_1 * 3) + (sec_r000244_11_1 * 2)) - pub_r000244_5_1) + 29) & 127;
  int stage_v_72_2 = ((((stage_v_66_2 * 3) + (sec_r000244_11_2 * 2)) - pub_r000244_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((((stage_v_68_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_5_1) + 35) & 127;
  int stage_v_73_2 = ((((stage_v_68_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((((sec_r000244_13_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_4_1) + 13) & 127;
  int stage_v_74_2 = ((((sec_r000244_13_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((((stage_v_62_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_0_1) + 4) & 127;
  int stage_v_75_2 = ((((stage_v_62_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((((sec_r000244_2_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_0_1) + 30) & 127;
  int stage_v_76_2 = ((((sec_r000244_2_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((((stage_v_58_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_0_1) + 14) & 127;
  int stage_v_77_2 = ((((stage_v_58_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((((stage_v_68_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_9_1) + 14) & 127;
  int stage_v_78_2 = ((((stage_v_68_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((((stage_v_61_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_16_1) + 8) & 127;
  int stage_v_79_2 = ((((stage_v_61_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((((stage_v_66_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_1_1) + 14) & 127;
  int stage_v_80_2 = ((((stage_v_66_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((((stage_v_60_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_13_1) + 27) & 127;
  int stage_v_81_2 = ((((stage_v_60_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((((stage_v_62_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_6_1) + 16) & 127;
  int stage_v_82_2 = ((((stage_v_62_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((((sec_r000244_12_1 * 3) + (sec_r000244_12_1 * 2)) - pub_r000244_9_1) + 11) & 127;
  int stage_v_83_2 = ((((sec_r000244_12_2 * 3) + (sec_r000244_12_2 * 2)) - pub_r000244_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((((stage_v_73_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_14_1) + 25) & 127;
  int stage_v_84_2 = ((((stage_v_73_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((((stage_v_81_1 * 3) + (sec_r000244_4_1 * 2)) - pub_r000244_6_1) + 14) & 127;
  int stage_v_85_2 = ((((stage_v_81_2 * 3) + (sec_r000244_4_2 * 2)) - pub_r000244_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((((stage_v_71_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_1_1) + 7) & 127;
  int stage_v_86_2 = ((((stage_v_71_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((((stage_v_61_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_3_1) + 28) & 127;
  int stage_v_87_2 = ((((stage_v_61_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((((stage_v_78_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_16_1) + 37) & 127;
  int stage_v_88_2 = ((((stage_v_78_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((((stage_v_60_1 * 3) + (sec_r000244_7_1 * 2)) - pub_r000244_10_1) + 23) & 127;
  int stage_v_89_2 = ((((stage_v_60_2 * 3) + (sec_r000244_7_2 * 2)) - pub_r000244_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((((stage_v_68_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_10_1) + 18) & 127;
  int stage_v_90_2 = ((((stage_v_68_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((((sec_r000244_11_1 * 3) + (sec_r000244_11_1 * 2)) - pub_r000244_3_1) + 8) & 127;
  int stage_v_91_2 = ((((sec_r000244_11_2 * 3) + (sec_r000244_11_2 * 2)) - pub_r000244_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((((sec_r000244_8_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_2_1) + 6) & 127;
  int stage_v_92_2 = ((((sec_r000244_8_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((((stage_v_86_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_6_1) + 32) & 127;
  int stage_v_93_2 = ((((stage_v_86_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((((stage_v_62_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_2_1) + 18) & 127;
  int stage_v_94_2 = ((((stage_v_62_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((sec_r000244_6_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_7_1) + 12) & 127;
  int stage_v_95_2 = ((((sec_r000244_6_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((stage_v_82_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_0_1) + 20) & 127;
  int stage_v_96_2 = ((((stage_v_82_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((stage_v_69_1 * 3) + (sec_r000244_16_1 * 2)) - pub_r000244_8_1) + 14) & 127;
  int stage_v_97_2 = ((((stage_v_69_2 * 3) + (sec_r000244_16_2 * 2)) - pub_r000244_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((sec_r000244_13_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_10_1) + 15) & 127;
  int stage_v_98_2 = ((((sec_r000244_13_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((sec_r000244_5_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_14_1) + 16) & 127;
  int stage_v_99_2 = ((((sec_r000244_5_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((stage_v_59_1 * 3) + (sec_r000244_12_1 * 2)) - pub_r000244_16_1) + 6) & 127;
  int stage_v_100_2 = ((((stage_v_59_2 * 3) + (sec_r000244_12_2 * 2)) - pub_r000244_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((sec_r000244_15_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_2_1) + 34) & 127;
  int stage_v_101_2 = ((((sec_r000244_15_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((stage_v_71_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_15_1) + 7) & 127;
  int stage_v_102_2 = ((((stage_v_71_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((stage_v_62_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_4_1) + 13) & 127;
  int stage_v_103_2 = ((((stage_v_62_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((sec_r000244_14_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_12_1) + 34) & 127;
  int stage_v_104_2 = ((((sec_r000244_14_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((stage_v_71_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_9_1) + 15) & 127;
  int stage_v_105_2 = ((((stage_v_71_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((stage_v_63_1 * 3) + (sec_r000244_17_1 * 2)) - pub_r000244_0_1) + 35) & 127;
  int stage_v_106_2 = ((((stage_v_63_2 * 3) + (sec_r000244_17_2 * 2)) - pub_r000244_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((sec_r000244_3_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_2_1) + 3) & 127;
  int stage_v_107_2 = ((((sec_r000244_3_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((sec_r000244_8_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_13_1) + 5) & 127;
  int stage_v_108_2 = ((((sec_r000244_8_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((stage_v_72_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_6_1) + 15) & 127;
  int stage_v_109_2 = ((((stage_v_72_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((stage_v_80_1 * 3) + (sec_r000244_7_1 * 2)) - pub_r000244_11_1) + 35) & 127;
  int stage_v_110_2 = ((((stage_v_80_2 * 3) + (sec_r000244_7_2 * 2)) - pub_r000244_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((stage_v_90_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_7_1) + 4) & 127;
  int stage_v_111_2 = ((((stage_v_90_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((stage_v_80_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_2_1) + 33) & 127;
  int stage_v_112_2 = ((((stage_v_80_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((sec_r000244_4_1 * 3) + (sec_r000244_4_1 * 2)) - pub_r000244_6_1) + 17) & 127;
  int stage_v_113_2 = ((((sec_r000244_4_2 * 3) + (sec_r000244_4_2 * 2)) - pub_r000244_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((stage_v_69_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_8_1) + 35) & 127;
  int stage_v_114_2 = ((((stage_v_69_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((sec_r000244_8_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_7_1) + 10) & 127;
  int stage_v_115_2 = ((((sec_r000244_8_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((stage_v_113_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_11_1) + 9) & 127;
  int stage_v_116_2 = ((((stage_v_113_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((sec_r000244_6_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_4_1) + 20) & 127;
  int stage_v_117_2 = ((((sec_r000244_6_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((stage_v_115_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_7_1) + 4) & 127;
  int stage_v_118_2 = ((((stage_v_115_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((stage_v_106_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_1_1) + 8) & 127;
  int stage_v_119_2 = ((((stage_v_106_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((stage_v_118_1 * 3) + (sec_r000244_18_1 * 2)) - pub_r000244_4_1) + 17) & 127;
  int stage_v_120_2 = ((((stage_v_118_2 * 3) + (sec_r000244_18_2 * 2)) - pub_r000244_4_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((sec_r000244_22_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_1_1) + 9) & 127;
  int stage_v_121_2 = ((((sec_r000244_22_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((stage_v_87_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_8_1) + 16) & 127;
  int stage_v_122_2 = ((((stage_v_87_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((stage_v_105_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_1_1) + 32) & 127;
  int stage_v_123_2 = ((((stage_v_105_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((stage_v_105_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_16_1) + 10) & 127;
  int stage_v_124_2 = ((((stage_v_105_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((sec_r000244_1_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_13_1) + 18) & 127;
  int stage_v_125_2 = ((((sec_r000244_1_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((stage_v_89_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_5_1) + 7) & 127;
  int stage_v_126_2 = ((((stage_v_89_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((sec_r000244_8_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_10_1) + 3) & 127;
  int stage_v_127_2 = ((((sec_r000244_8_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((stage_v_114_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_1_1) + 14) & 127;
  int stage_v_128_2 = ((((stage_v_114_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((stage_v_116_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_15_1) + 31) & 127;
  int stage_v_129_2 = ((((stage_v_116_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((sec_r000244_15_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_0_1) + 13) & 127;
  int stage_v_130_2 = ((((sec_r000244_15_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((stage_v_63_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_15_1) + 19) & 127;
  int stage_v_131_2 = ((((stage_v_63_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((sec_r000244_5_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_2_1) + 22) & 127;
  int stage_v_132_2 = ((((sec_r000244_5_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((sec_r000244_16_1 * 3) + (sec_r000244_16_1 * 2)) - pub_r000244_14_1) + 21) & 127;
  int stage_v_133_2 = ((((sec_r000244_16_2 * 3) + (sec_r000244_16_2 * 2)) - pub_r000244_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((stage_v_98_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_7_1) + 3) & 127;
  int stage_v_134_2 = ((((stage_v_98_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((stage_v_93_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_12_1) + 26) & 127;
  int stage_v_135_2 = ((((stage_v_93_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((sec_r000244_9_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_6_1) + 18) & 127;
  int stage_v_136_2 = ((((sec_r000244_9_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((sec_r000244_19_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_6_1) + 3) & 127;
  int stage_v_137_2 = ((((sec_r000244_19_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((sec_r000244_9_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_8_1) + 37) & 127;
  int stage_v_138_2 = ((((sec_r000244_9_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((stage_v_104_1 * 3) + (sec_r000244_4_1 * 2)) - pub_r000244_6_1) + 23) & 127;
  int stage_v_139_2 = ((((stage_v_104_2 * 3) + (sec_r000244_4_2 * 2)) - pub_r000244_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((stage_v_111_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_16_1) + 14) & 127;
  int stage_v_140_2 = ((((stage_v_111_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((stage_v_110_1 * 3) + (sec_r000244_18_1 * 2)) - pub_r000244_13_1) + 23) & 127;
  int stage_v_141_2 = ((((stage_v_110_2 * 3) + (sec_r000244_18_2 * 2)) - pub_r000244_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((stage_v_70_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_9_1) + 8) & 127;
  int stage_v_142_2 = ((((stage_v_70_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((sec_r000244_18_1 * 3) + (sec_r000244_18_1 * 2)) - pub_r000244_0_1) + 11) & 127;
  int stage_v_143_2 = ((((sec_r000244_18_2 * 3) + (sec_r000244_18_2 * 2)) - pub_r000244_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((stage_v_76_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_13_1) + 6) & 127;
  int stage_v_144_2 = ((((stage_v_76_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((stage_v_126_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_10_1) + 29) & 127;
  int stage_v_145_2 = ((((stage_v_126_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((stage_v_133_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_3_1) + 19) & 127;
  int stage_v_146_2 = ((((stage_v_133_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((sec_r000244_14_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_15_1) + 36) & 127;
  int stage_v_147_2 = ((((sec_r000244_14_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((stage_v_85_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_6_1) + 24) & 127;
  int stage_v_148_2 = ((((stage_v_85_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((stage_v_124_1 * 3) + (sec_r000244_17_1 * 2)) - pub_r000244_7_1) + 13) & 127;
  int stage_v_149_2 = ((((stage_v_124_2 * 3) + (sec_r000244_17_2 * 2)) - pub_r000244_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((sec_r000244_1_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_10_1) + 27) & 127;
  int stage_v_150_2 = ((((sec_r000244_1_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((stage_v_131_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_16_1) + 3) & 127;
  int stage_v_151_2 = ((((stage_v_131_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((stage_v_76_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_11_1) + 33) & 127;
  int stage_v_152_2 = ((((stage_v_76_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((stage_v_119_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_15_1) + 37) & 127;
  int stage_v_153_2 = ((((stage_v_119_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((stage_v_143_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_14_1) + 24) & 127;
  int stage_v_154_2 = ((((stage_v_143_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((stage_v_125_1 * 3) + (sec_r000244_11_1 * 2)) - pub_r000244_6_1) + 27) & 127;
  int stage_v_155_2 = ((((stage_v_125_2 * 3) + (sec_r000244_11_2 * 2)) - pub_r000244_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((stage_v_150_1 * 3) + (sec_r000244_7_1 * 2)) - pub_r000244_12_1) + 18) & 127;
  int stage_v_156_2 = ((((stage_v_150_2 * 3) + (sec_r000244_7_2 * 2)) - pub_r000244_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((stage_v_118_1 * 3) + (sec_r000244_21_1 * 2)) - pub_r000244_5_1) + 31) & 127;
  int stage_v_157_2 = ((((stage_v_118_2 * 3) + (sec_r000244_21_2 * 2)) - pub_r000244_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((stage_v_79_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_9_1) + 28) & 127;
  int stage_v_158_2 = ((((stage_v_79_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((stage_v_111_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_8_1) + 19) & 127;
  int stage_v_159_2 = ((((stage_v_111_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((stage_v_95_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_3_1) + 13) & 127;
  int stage_v_160_2 = ((((stage_v_95_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((stage_v_147_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_11_1) + 19) & 127;
  int stage_v_161_2 = ((((stage_v_147_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((sec_r000244_14_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_14_1) + 17) & 127;
  int stage_v_162_2 = ((((sec_r000244_14_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((sec_r000244_5_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_7_1) + 18) & 127;
  int stage_v_163_2 = ((((sec_r000244_5_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((sec_r000244_15_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_9_1) + 13) & 127;
  int stage_v_164_2 = ((((sec_r000244_15_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((stage_v_99_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_2_1) + 17) & 127;
  int stage_v_165_2 = ((((stage_v_99_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((stage_v_161_1 * 3) + (sec_r000244_4_1 * 2)) - pub_r000244_2_1) + 26) & 127;
  int stage_v_166_2 = ((((stage_v_161_2 * 3) + (sec_r000244_4_2 * 2)) - pub_r000244_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((stage_v_142_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_15_1) + 33) & 127;
  int stage_v_167_2 = ((((stage_v_142_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((stage_v_145_1 * 3) + (sec_r000244_18_1 * 2)) - pub_r000244_5_1) + 27) & 127;
  int stage_v_168_2 = ((((stage_v_145_2 * 3) + (sec_r000244_18_2 * 2)) - pub_r000244_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((sec_r000244_22_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_12_1) + 14) & 127;
  int stage_v_169_2 = ((((sec_r000244_22_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((stage_v_119_1 * 3) + (sec_r000244_17_1 * 2)) - pub_r000244_3_1) + 5) & 127;
  int stage_v_170_2 = ((((stage_v_119_2 * 3) + (sec_r000244_17_2 * 2)) - pub_r000244_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((sec_r000244_2_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_2_1) + 5) & 127;
  int stage_v_171_2 = ((((sec_r000244_2_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((stage_v_124_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_13_1) + 26) & 127;
  int stage_v_172_2 = ((((stage_v_124_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((stage_v_83_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_2_1) + 18) & 127;
  int stage_v_173_2 = ((((stage_v_83_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((stage_v_159_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_11_1) + 17) & 127;
  int stage_v_174_2 = ((((stage_v_159_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((sec_r000244_14_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_11_1) + 28) & 127;
  int stage_v_175_2 = ((((sec_r000244_14_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((sec_r000244_2_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_0_1) + 26) & 127;
  int stage_v_176_2 = ((((sec_r000244_2_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((stage_v_76_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_6_1) + 24) & 127;
  int stage_v_177_2 = ((((stage_v_76_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((sec_r000244_12_1 * 3) + (sec_r000244_12_1 * 2)) - pub_r000244_10_1) + 24) & 127;
  int stage_v_178_2 = ((((sec_r000244_12_2 * 3) + (sec_r000244_12_2 * 2)) - pub_r000244_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((stage_v_88_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_8_1) + 14) & 127;
  int stage_v_179_2 = ((((stage_v_88_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((stage_v_62_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_3_1) + 9) & 127;
  int stage_v_180_2 = ((((stage_v_62_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((stage_v_158_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_3_1) + 29) & 127;
  int stage_v_181_2 = ((((stage_v_158_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((stage_v_90_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_2_1) + 4) & 127;
  int stage_v_182_2 = ((((stage_v_90_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((stage_v_124_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_6_1) + 28) & 127;
  int stage_v_183_2 = ((((stage_v_124_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((stage_v_126_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_12_1) + 27) & 127;
  int stage_v_184_2 = ((((stage_v_126_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((stage_v_142_1 * 3) + (sec_r000244_11_1 * 2)) - pub_r000244_6_1) + 29) & 127;
  int stage_v_185_2 = ((((stage_v_142_2 * 3) + (sec_r000244_11_2 * 2)) - pub_r000244_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((stage_v_64_1 * 3) + (sec_r000244_7_1 * 2)) - pub_r000244_0_1) + 18) & 127;
  int stage_v_186_2 = ((((stage_v_64_2 * 3) + (sec_r000244_7_2 * 2)) - pub_r000244_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((sec_r000244_15_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_0_1) + 28) & 127;
  int stage_v_187_2 = ((((sec_r000244_15_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((stage_v_128_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_1_1) + 32) & 127;
  int stage_v_188_2 = ((((stage_v_128_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((stage_v_159_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_2_1) + 11) & 127;
  int stage_v_189_2 = ((((stage_v_159_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((stage_v_72_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_5_1) + 25) & 127;
  int stage_v_190_2 = ((((stage_v_72_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((stage_v_68_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_9_1) + 25) & 127;
  int stage_v_191_2 = ((((stage_v_68_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((stage_v_159_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_4_1) + 31) & 127;
  int stage_v_192_2 = ((((stage_v_159_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((stage_v_97_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_14_1) + 7) & 127;
  int stage_v_193_2 = ((((stage_v_97_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((stage_v_175_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_8_1) + 34) & 127;
  int stage_v_194_2 = ((((stage_v_175_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((stage_v_80_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_8_1) + 14) & 127;
  int stage_v_195_2 = ((((stage_v_80_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((sec_r000244_17_1 * 3) + (sec_r000244_17_1 * 2)) - pub_r000244_14_1) + 27) & 127;
  int stage_v_196_2 = ((((sec_r000244_17_2 * 3) + (sec_r000244_17_2 * 2)) - pub_r000244_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((sec_r000244_15_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_13_1) + 28) & 127;
  int stage_v_197_2 = ((((sec_r000244_15_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((sec_r000244_14_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_12_1) + 28) & 127;
  int stage_v_198_2 = ((((sec_r000244_14_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((stage_v_183_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_15_1) + 16) & 127;
  int stage_v_199_2 = ((((stage_v_183_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((sec_r000244_12_1 * 3) + (sec_r000244_12_1 * 2)) - pub_r000244_11_1) + 30) & 127;
  int stage_v_200_2 = ((((sec_r000244_12_2 * 3) + (sec_r000244_12_2 * 2)) - pub_r000244_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((stage_v_92_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_2_1) + 36) & 127;
  int stage_v_201_2 = ((((stage_v_92_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((stage_v_126_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_9_1) + 25) & 127;
  int stage_v_202_2 = ((((stage_v_126_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((sec_r000244_4_1 * 3) + (sec_r000244_4_1 * 2)) - pub_r000244_13_1) + 16) & 127;
  int stage_v_203_2 = ((((sec_r000244_4_2 * 3) + (sec_r000244_4_2 * 2)) - pub_r000244_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((sec_r000244_10_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_8_1) + 16) & 127;
  int stage_v_204_2 = ((((sec_r000244_10_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((stage_v_185_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_2_1) + 17) & 127;
  int stage_v_205_2 = ((((stage_v_185_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((sec_r000244_22_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_12_1) + 12) & 127;
  int stage_v_206_2 = ((((sec_r000244_22_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((stage_v_111_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_4_1) + 29) & 127;
  int stage_v_207_2 = ((((stage_v_111_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((stage_v_88_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_13_1) + 6) & 127;
  int stage_v_208_2 = ((((stage_v_88_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((sec_r000244_12_1 * 3) + (sec_r000244_12_1 * 2)) - pub_r000244_12_1) + 20) & 127;
  int stage_v_209_2 = ((((sec_r000244_12_2 * 3) + (sec_r000244_12_2 * 2)) - pub_r000244_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((stage_v_139_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_14_1) + 20) & 127;
  int stage_v_210_2 = ((((stage_v_139_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((stage_v_102_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_11_1) + 26) & 127;
  int stage_v_211_2 = ((((stage_v_102_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((stage_v_93_1 * 3) + (sec_r000244_7_1 * 2)) - pub_r000244_14_1) + 33) & 127;
  int stage_v_212_2 = ((((stage_v_93_2 * 3) + (sec_r000244_7_2 * 2)) - pub_r000244_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((sec_r000244_22_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_15_1) + 37) & 127;
  int stage_v_213_2 = ((((sec_r000244_22_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((stage_v_129_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_6_1) + 26) & 127;
  int stage_v_214_2 = ((((stage_v_129_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((stage_v_188_1 * 3) + (sec_r000244_11_1 * 2)) - pub_r000244_13_1) + 36) & 127;
  int stage_v_215_2 = ((((stage_v_188_2 * 3) + (sec_r000244_11_2 * 2)) - pub_r000244_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((stage_v_173_1 * 3) + (sec_r000244_21_1 * 2)) - pub_r000244_13_1) + 9) & 127;
  int stage_v_216_2 = ((((stage_v_173_2 * 3) + (sec_r000244_21_2 * 2)) - pub_r000244_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((sec_r000244_6_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_2_1) + 7) & 127;
  int stage_v_217_2 = ((((sec_r000244_6_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((stage_v_73_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_14_1) + 23) & 127;
  int stage_v_218_2 = ((((stage_v_73_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((stage_v_212_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_2_1) + 32) & 127;
  int stage_v_219_2 = ((((stage_v_212_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((stage_v_159_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_4_1) + 7) & 127;
  int stage_v_220_2 = ((((stage_v_159_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_103_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_0_1) + 13) & 127;
  int stage_v_221_2 = ((((stage_v_103_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((stage_v_202_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_9_1) + 36) & 127;
  int stage_v_222_2 = ((((stage_v_202_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((sec_r000244_21_1 * 3) + (sec_r000244_21_1 * 2)) - pub_r000244_1_1) + 20) & 127;
  int stage_v_223_2 = ((((sec_r000244_21_2 * 3) + (sec_r000244_21_2 * 2)) - pub_r000244_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((stage_v_109_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_13_1) + 3) & 127;
  int stage_v_224_2 = ((((stage_v_109_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((stage_v_177_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_15_1) + 28) & 127;
  int stage_v_225_2 = ((((stage_v_177_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((stage_v_176_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_10_1) + 27) & 127;
  int stage_v_226_2 = ((((stage_v_176_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((sec_r000244_3_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_9_1) + 14) & 127;
  int stage_v_227_2 = ((((sec_r000244_3_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((stage_v_198_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_9_1) + 12) & 127;
  int stage_v_228_2 = ((((stage_v_198_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((sec_r000244_15_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_5_1) + 36) & 127;
  int stage_v_229_2 = ((((sec_r000244_15_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((stage_v_108_1 * 3) + (sec_r000244_7_1 * 2)) - pub_r000244_6_1) + 7) & 127;
  int stage_v_230_2 = ((((stage_v_108_2 * 3) + (sec_r000244_7_2 * 2)) - pub_r000244_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((stage_v_152_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_0_1) + 3) & 127;
  int stage_v_231_2 = ((((stage_v_152_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((sec_r000244_3_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_6_1) + 6) & 127;
  int stage_v_232_2 = ((((sec_r000244_3_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((stage_v_70_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_13_1) + 28) & 127;
  int stage_v_233_2 = ((((stage_v_70_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((stage_v_62_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_13_1) + 28) & 127;
  int stage_v_234_2 = ((((stage_v_62_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((sec_r000244_21_1 * 3) + (sec_r000244_21_1 * 2)) - pub_r000244_8_1) + 21) & 127;
  int stage_v_235_2 = ((((sec_r000244_21_2 * 3) + (sec_r000244_21_2 * 2)) - pub_r000244_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((stage_v_152_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_8_1) + 19) & 127;
  int stage_v_236_2 = ((((stage_v_152_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((stage_v_230_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_12_1) + 14) & 127;
  int stage_v_237_2 = ((((stage_v_230_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((stage_v_195_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_5_1) + 23) & 127;
  int stage_v_238_2 = ((((stage_v_195_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((stage_v_66_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_3_1) + 6) & 127;
  int stage_v_239_2 = ((((stage_v_66_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((sec_r000244_10_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_13_1) + 32) & 127;
  int stage_v_240_2 = ((((sec_r000244_10_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((sec_r000244_23_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_0_1) + 37) & 127;
  int stage_v_241_2 = ((((sec_r000244_23_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((sec_r000244_9_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_5_1) + 10) & 127;
  int stage_v_242_2 = ((((sec_r000244_9_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_175_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_13_1) + 8) & 127;
  int stage_v_243_2 = ((((stage_v_175_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_82_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_10_1) + 26) & 127;
  int stage_v_244_2 = ((((stage_v_82_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((stage_v_156_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_10_1) + 28) & 127;
  int stage_v_245_2 = ((((stage_v_156_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((sec_r000244_17_1 * 3) + (sec_r000244_17_1 * 2)) - pub_r000244_5_1) + 14) & 127;
  int stage_v_246_2 = ((((sec_r000244_17_2 * 3) + (sec_r000244_17_2 * 2)) - pub_r000244_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((sec_r000244_23_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_0_1) + 33) & 127;
  int stage_v_247_2 = ((((sec_r000244_23_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((sec_r000244_9_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_14_1) + 9) & 127;
  int stage_v_248_2 = ((((sec_r000244_9_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((stage_v_206_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_7_1) + 23) & 127;
  int stage_v_249_2 = ((((stage_v_206_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((stage_v_148_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_15_1) + 7) & 127;
  int stage_v_250_2 = ((((stage_v_148_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((sec_r000244_20_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_2_1) + 37) & 127;
  int stage_v_251_2 = ((((sec_r000244_20_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((sec_r000244_13_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_11_1) + 36) & 127;
  int stage_v_252_2 = ((((sec_r000244_13_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((stage_v_186_1 * 3) + (sec_r000244_18_1 * 2)) - pub_r000244_8_1) + 36) & 127;
  int stage_v_253_2 = ((((stage_v_186_2 * 3) + (sec_r000244_18_2 * 2)) - pub_r000244_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((stage_v_110_1 * 3) + (sec_r000244_4_1 * 2)) - pub_r000244_13_1) + 8) & 127;
  int stage_v_254_2 = ((((stage_v_110_2 * 3) + (sec_r000244_4_2 * 2)) - pub_r000244_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((stage_v_134_1 * 3) + (sec_r000244_12_1 * 2)) - pub_r000244_13_1) + 33) & 127;
  int stage_v_255_2 = ((((stage_v_134_2 * 3) + (sec_r000244_12_2 * 2)) - pub_r000244_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((sec_r000244_14_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_3_1) + 32) & 127;
  int stage_v_256_2 = ((((sec_r000244_14_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((((stage_v_214_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_10_1) + 4) & 127;
  int stage_v_257_2 = ((((stage_v_214_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_257_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_257_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((((sec_r000244_23_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_7_1) + 17) & 127;
  int stage_v_258_2 = ((((sec_r000244_23_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_258_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_258_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((((stage_v_90_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_2_1) + 28) & 127;
  int stage_v_259_2 = ((((stage_v_90_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_259_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_259_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((((stage_v_249_1 * 3) + (sec_r000244_4_1 * 2)) - pub_r000244_11_1) + 7) & 127;
  int stage_v_260_2 = ((((stage_v_249_2 * 3) + (sec_r000244_4_2 * 2)) - pub_r000244_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_260_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_260_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((((stage_v_101_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_4_1) + 29) & 127;
  int stage_v_261_2 = ((((stage_v_101_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_261_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_261_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((((sec_r000244_10_1 * 3) + (sec_r000244_10_1 * 2)) - pub_r000244_15_1) + 22) & 127;
  int stage_v_262_2 = ((((sec_r000244_10_2 * 3) + (sec_r000244_10_2 * 2)) - pub_r000244_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_262_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_262_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((((stage_v_192_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_10_1) + 14) & 127;
  int stage_v_263_2 = ((((stage_v_192_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_263_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_263_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((((stage_v_115_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_5_1) + 20) & 127;
  int stage_v_264_2 = ((((stage_v_115_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_264_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_264_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((((stage_v_150_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_12_1) + 23) & 127;
  int stage_v_265_2 = ((((stage_v_150_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_265_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_265_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((((stage_v_120_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_16_1) + 36) & 127;
  int stage_v_266_2 = ((((stage_v_120_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_266_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_266_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((((sec_r000244_1_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_16_1) + 11) & 127;
  int stage_v_267_2 = ((((sec_r000244_1_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_267_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_267_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((((stage_v_66_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_5_1) + 27) & 127;
  int stage_v_268_2 = ((((stage_v_66_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_268_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_268_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((((stage_v_212_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_2_1) + 11) & 127;
  int stage_v_269_2 = ((((stage_v_212_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_269_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_269_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((((stage_v_215_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_16_1) + 32) & 127;
  int stage_v_270_2 = ((((stage_v_215_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_270_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_270_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((((stage_v_172_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_6_1) + 37) & 127;
  int stage_v_271_2 = ((((stage_v_172_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_271_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_271_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((((stage_v_192_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_0_1) + 22) & 127;
  int stage_v_272_2 = ((((stage_v_192_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_272_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_272_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((((sec_r000244_0_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_14_1) + 7) & 127;
  int stage_v_273_2 = ((((sec_r000244_0_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_273_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_273_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((((stage_v_141_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_14_1) + 25) & 127;
  int stage_v_274_2 = ((((stage_v_141_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_274_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_274_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((((stage_v_149_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_15_1) + 27) & 127;
  int stage_v_275_2 = ((((stage_v_149_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_275_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_275_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((((stage_v_149_1 * 3) + (sec_r000244_7_1 * 2)) - pub_r000244_4_1) + 3) & 127;
  int stage_v_276_2 = ((((stage_v_149_2 * 3) + (sec_r000244_7_2 * 2)) - pub_r000244_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_276_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_276_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((((stage_v_67_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_4_1) + 17) & 127;
  int stage_v_277_2 = ((((stage_v_67_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_4_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_277_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_277_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((((stage_v_147_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_5_1) + 3) & 127;
  int stage_v_278_2 = ((((stage_v_147_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_278_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_278_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((((stage_v_132_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_7_1) + 27) & 127;
  int stage_v_279_2 = ((((stage_v_132_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_279_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_279_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((((stage_v_67_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_3_1) + 29) & 127;
  int stage_v_280_2 = ((((stage_v_67_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_280_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_280_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((((sec_r000244_20_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_10_1) + 21) & 127;
  int stage_v_281_2 = ((((sec_r000244_20_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_281_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_281_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((((sec_r000244_7_1 * 3) + (sec_r000244_7_1 * 2)) - pub_r000244_12_1) + 13) & 127;
  int stage_v_282_2 = ((((sec_r000244_7_2 * 3) + (sec_r000244_7_2 * 2)) - pub_r000244_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_282_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_282_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((((stage_v_155_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_13_1) + 8) & 127;
  int stage_v_283_2 = ((((stage_v_155_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_283_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_283_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((((sec_r000244_17_1 * 3) + (sec_r000244_17_1 * 2)) - pub_r000244_8_1) + 6) & 127;
  int stage_v_284_2 = ((((sec_r000244_17_2 * 3) + (sec_r000244_17_2 * 2)) - pub_r000244_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_284_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_284_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((((stage_v_275_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_16_1) + 15) & 127;
  int stage_v_285_2 = ((((stage_v_275_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_285_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_285_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((((sec_r000244_2_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_5_1) + 11) & 127;
  int stage_v_286_2 = ((((sec_r000244_2_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_286_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_286_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((((sec_r000244_7_1 * 3) + (sec_r000244_7_1 * 2)) - pub_r000244_15_1) + 37) & 127;
  int stage_v_287_2 = ((((sec_r000244_7_2 * 3) + (sec_r000244_7_2 * 2)) - pub_r000244_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_287_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_287_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((((sec_r000244_21_1 * 3) + (sec_r000244_21_1 * 2)) - pub_r000244_2_1) + 21) & 127;
  int stage_v_288_2 = ((((sec_r000244_21_2 * 3) + (sec_r000244_21_2 * 2)) - pub_r000244_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_288_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_288_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((((sec_r000244_9_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_14_1) + 19) & 127;
  int stage_v_289_2 = ((((sec_r000244_9_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_289_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_289_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((((stage_v_100_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_4_1) + 18) & 127;
  int stage_v_290_2 = ((((stage_v_100_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_290_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_290_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((((stage_v_245_1 * 3) + (sec_r000244_12_1 * 2)) - pub_r000244_13_1) + 13) & 127;
  int stage_v_291_2 = ((((stage_v_245_2 * 3) + (sec_r000244_12_2 * 2)) - pub_r000244_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_291_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_291_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((((stage_v_208_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_2_1) + 11) & 127;
  int stage_v_292_2 = ((((stage_v_208_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_292_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_292_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((((stage_v_254_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_4_1) + 12) & 127;
  int stage_v_293_2 = ((((stage_v_254_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_293_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_293_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((((sec_r000244_13_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_1_1) + 19) & 127;
  int stage_v_294_2 = ((((sec_r000244_13_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_294_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_294_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((((stage_v_190_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_4_1) + 3) & 127;
  int stage_v_295_2 = ((((stage_v_190_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_295_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_295_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((((stage_v_94_1 * 3) + (sec_r000244_11_1 * 2)) - pub_r000244_12_1) + 19) & 127;
  int stage_v_296_2 = ((((stage_v_94_2 * 3) + (sec_r000244_11_2 * 2)) - pub_r000244_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_296_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_296_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((((stage_v_227_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_2_1) + 19) & 127;
  int stage_v_297_2 = ((((stage_v_227_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_297_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_297_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((((sec_r000244_12_1 * 3) + (sec_r000244_12_1 * 2)) - pub_r000244_11_1) + 3) & 127;
  int stage_v_298_2 = ((((sec_r000244_12_2 * 3) + (sec_r000244_12_2 * 2)) - pub_r000244_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_298_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_298_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((((sec_r000244_21_1 * 3) + (sec_r000244_21_1 * 2)) - pub_r000244_7_1) + 35) & 127;
  int stage_v_299_2 = ((((sec_r000244_21_2 * 3) + (sec_r000244_21_2 * 2)) - pub_r000244_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_299_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_299_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((((sec_r000244_1_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_16_1) + 33) & 127;
  int stage_v_300_2 = ((((sec_r000244_1_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_300_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_300_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((((sec_r000244_12_1 * 3) + (sec_r000244_12_1 * 2)) - pub_r000244_10_1) + 13) & 127;
  int stage_v_301_2 = ((((sec_r000244_12_2 * 3) + (sec_r000244_12_2 * 2)) - pub_r000244_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_301_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_301_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((((sec_r000244_6_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_11_1) + 29) & 127;
  int stage_v_302_2 = ((((sec_r000244_6_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_302_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_302_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((((sec_r000244_18_1 * 3) + (sec_r000244_18_1 * 2)) - pub_r000244_6_1) + 3) & 127;
  int stage_v_303_2 = ((((sec_r000244_18_2 * 3) + (sec_r000244_18_2 * 2)) - pub_r000244_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_303_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_303_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((((stage_v_123_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_14_1) + 14) & 127;
  int stage_v_304_2 = ((((stage_v_123_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_304_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_304_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((((stage_v_147_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_5_1) + 11) & 127;
  int stage_v_305_2 = ((((stage_v_147_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_305_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_305_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((((sec_r000244_11_1 * 3) + (sec_r000244_11_1 * 2)) - pub_r000244_10_1) + 30) & 127;
  int stage_v_306_2 = ((((sec_r000244_11_2 * 3) + (sec_r000244_11_2 * 2)) - pub_r000244_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_306_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_306_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((((sec_r000244_4_1 * 3) + (sec_r000244_4_1 * 2)) - pub_r000244_0_1) + 36) & 127;
  int stage_v_307_2 = ((((sec_r000244_4_2 * 3) + (sec_r000244_4_2 * 2)) - pub_r000244_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_307_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_307_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((((stage_v_96_1 * 3) + (sec_r000244_13_1 * 2)) - pub_r000244_8_1) + 36) & 127;
  int stage_v_308_2 = ((((stage_v_96_2 * 3) + (sec_r000244_13_2 * 2)) - pub_r000244_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_308_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_308_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((((stage_v_215_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_5_1) + 4) & 127;
  int stage_v_309_2 = ((((stage_v_215_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_309_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_309_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((((stage_v_164_1 * 3) + (sec_r000244_18_1 * 2)) - pub_r000244_4_1) + 3) & 127;
  int stage_v_310_2 = ((((stage_v_164_2 * 3) + (sec_r000244_18_2 * 2)) - pub_r000244_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_310_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_310_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((((sec_r000244_18_1 * 3) + (sec_r000244_18_1 * 2)) - pub_r000244_15_1) + 22) & 127;
  int stage_v_311_2 = ((((sec_r000244_18_2 * 3) + (sec_r000244_18_2 * 2)) - pub_r000244_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_311_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_311_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((((sec_r000244_14_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_10_1) + 28) & 127;
  int stage_v_312_2 = ((((sec_r000244_14_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_312_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_312_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((((stage_v_77_1 * 3) + (sec_r000244_16_1 * 2)) - pub_r000244_3_1) + 24) & 127;
  int stage_v_313_2 = ((((stage_v_77_2 * 3) + (sec_r000244_16_2 * 2)) - pub_r000244_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_313_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_313_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((((stage_v_243_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_8_1) + 12) & 127;
  int stage_v_314_2 = ((((stage_v_243_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_314_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_314_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((((sec_r000244_19_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_9_1) + 32) & 127;
  int stage_v_315_2 = ((((sec_r000244_19_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_315_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_315_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((((sec_r000244_17_1 * 3) + (sec_r000244_17_1 * 2)) - pub_r000244_5_1) + 13) & 127;
  int stage_v_316_2 = ((((sec_r000244_17_2 * 3) + (sec_r000244_17_2 * 2)) - pub_r000244_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_316_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_316_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((((stage_v_140_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_0_1) + 29) & 127;
  int stage_v_317_2 = ((((stage_v_140_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_317_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_317_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((((sec_r000244_11_1 * 3) + (sec_r000244_11_1 * 2)) - pub_r000244_5_1) + 30) & 127;
  int stage_v_318_2 = ((((sec_r000244_11_2 * 3) + (sec_r000244_11_2 * 2)) - pub_r000244_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_318_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_318_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((((stage_v_155_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_14_1) + 33) & 127;
  int stage_v_319_2 = ((((stage_v_155_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_319_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_319_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((((sec_r000244_7_1 * 3) + (sec_r000244_7_1 * 2)) - pub_r000244_4_1) + 27) & 127;
  int stage_v_320_2 = ((((sec_r000244_7_2 * 3) + (sec_r000244_7_2 * 2)) - pub_r000244_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_320_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_320_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((((sec_r000244_3_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_0_1) + 16) & 127;
  int stage_v_321_2 = ((((sec_r000244_3_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_321_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_321_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((((stage_v_318_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_0_1) + 25) & 127;
  int stage_v_322_2 = ((((stage_v_318_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_322_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_322_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((((stage_v_76_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_15_1) + 15) & 127;
  int stage_v_323_2 = ((((stage_v_76_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_323_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_323_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((((stage_v_119_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_4_1) + 16) & 127;
  int stage_v_324_2 = ((((stage_v_119_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_324_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_324_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((((stage_v_301_1 * 3) + (sec_r000244_3_1 * 2)) - pub_r000244_15_1) + 25) & 127;
  int stage_v_325_2 = ((((stage_v_301_2 * 3) + (sec_r000244_3_2 * 2)) - pub_r000244_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_325_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_325_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((((sec_r000244_12_1 * 3) + (sec_r000244_12_1 * 2)) - pub_r000244_3_1) + 15) & 127;
  int stage_v_326_2 = ((((sec_r000244_12_2 * 3) + (sec_r000244_12_2 * 2)) - pub_r000244_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_326_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_326_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((((sec_r000244_22_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_7_1) + 23) & 127;
  int stage_v_327_2 = ((((sec_r000244_22_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_327_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_327_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((((sec_r000244_20_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_14_1) + 7) & 127;
  int stage_v_328_2 = ((((sec_r000244_20_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_328_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_328_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((((sec_r000244_16_1 * 3) + (sec_r000244_16_1 * 2)) - pub_r000244_3_1) + 14) & 127;
  int stage_v_329_2 = ((((sec_r000244_16_2 * 3) + (sec_r000244_16_2 * 2)) - pub_r000244_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_329_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_329_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((((sec_r000244_1_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_7_1) + 7) & 127;
  int stage_v_330_2 = ((((sec_r000244_1_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_330_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_330_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((((stage_v_281_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_16_1) + 18) & 127;
  int stage_v_331_2 = ((((stage_v_281_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_331_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_331_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((((stage_v_257_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_13_1) + 25) & 127;
  int stage_v_332_2 = ((((stage_v_257_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_332_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_332_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((((sec_r000244_19_1 * 3) + (sec_r000244_19_1 * 2)) - pub_r000244_12_1) + 31) & 127;
  int stage_v_333_2 = ((((sec_r000244_19_2 * 3) + (sec_r000244_19_2 * 2)) - pub_r000244_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_333_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_333_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((((stage_v_231_1 * 3) + (sec_r000244_18_1 * 2)) - pub_r000244_11_1) + 7) & 127;
  int stage_v_334_2 = ((((stage_v_231_2 * 3) + (sec_r000244_18_2 * 2)) - pub_r000244_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_334_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_334_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((((sec_r000244_0_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_9_1) + 15) & 127;
  int stage_v_335_2 = ((((sec_r000244_0_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_335_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_335_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((((stage_v_330_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_10_1) + 15) & 127;
  int stage_v_336_2 = ((((stage_v_330_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_336_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_336_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  int stage_v_337_1 = ((((stage_v_175_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_0_1) + 5) & 127;
  int stage_v_337_2 = ((((stage_v_175_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_337_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_337_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_337_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_337_2) & 255;
  int stage_v_338_1 = ((((sec_r000244_2_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_10_1) + 7) & 127;
  int stage_v_338_2 = ((((sec_r000244_2_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_338_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_338_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_338_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_338_2) & 255;
  int stage_v_339_1 = ((((sec_r000244_5_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_0_1) + 20) & 127;
  int stage_v_339_2 = ((((sec_r000244_5_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_339_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_339_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_339_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_339_2) & 255;
  int stage_v_340_1 = ((((stage_v_98_1 * 3) + (sec_r000244_16_1 * 2)) - pub_r000244_0_1) + 7) & 127;
  int stage_v_340_2 = ((((stage_v_98_2 * 3) + (sec_r000244_16_2 * 2)) - pub_r000244_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_340_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_340_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_340_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_340_2) & 255;
  int stage_v_341_1 = ((((stage_v_182_1 * 3) + (sec_r000244_1_1 * 2)) - pub_r000244_5_1) + 20) & 127;
  int stage_v_341_2 = ((((stage_v_182_2 * 3) + (sec_r000244_1_2 * 2)) - pub_r000244_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_341_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_341_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_341_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_341_2) & 255;
  int stage_v_342_1 = ((((stage_v_300_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_14_1) + 15) & 127;
  int stage_v_342_2 = ((((stage_v_300_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_342_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_342_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_342_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_342_2) & 255;
  int stage_v_343_1 = ((((sec_r000244_0_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_4_1) + 25) & 127;
  int stage_v_343_2 = ((((sec_r000244_0_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_343_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_343_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_343_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_343_2) & 255;
  int stage_v_344_1 = ((((sec_r000244_15_1 * 3) + (sec_r000244_15_1 * 2)) - pub_r000244_13_1) + 22) & 127;
  int stage_v_344_2 = ((((sec_r000244_15_2 * 3) + (sec_r000244_15_2 * 2)) - pub_r000244_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_344_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_344_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_344_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_344_2) & 255;
  int stage_v_345_1 = ((((stage_v_163_1 * 3) + (sec_r000244_17_1 * 2)) - pub_r000244_0_1) + 33) & 127;
  int stage_v_345_2 = ((((stage_v_163_2 * 3) + (sec_r000244_17_2 * 2)) - pub_r000244_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_345_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_345_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_345_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_345_2) & 255;
  int stage_v_346_1 = ((((stage_v_307_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_5_1) + 18) & 127;
  int stage_v_346_2 = ((((stage_v_307_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_346_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_346_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_346_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_346_2) & 255;
  int stage_v_347_1 = ((((sec_r000244_6_1 * 3) + (sec_r000244_6_1 * 2)) - pub_r000244_7_1) + 30) & 127;
  int stage_v_347_2 = ((((sec_r000244_6_2 * 3) + (sec_r000244_6_2 * 2)) - pub_r000244_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_347_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_347_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_347_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_347_2) & 255;
  int stage_v_348_1 = ((((stage_v_335_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_9_1) + 6) & 127;
  int stage_v_348_2 = ((((stage_v_335_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_348_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_348_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_348_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_348_2) & 255;
  int stage_v_349_1 = ((((stage_v_75_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_5_1) + 19) & 127;
  int stage_v_349_2 = ((((stage_v_75_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_349_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_349_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_349_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_349_2) & 255;
  int stage_v_350_1 = ((((sec_r000244_0_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_16_1) + 34) & 127;
  int stage_v_350_2 = ((((sec_r000244_0_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_350_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_350_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_350_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_350_2) & 255;
  int stage_v_351_1 = ((((sec_r000244_0_1 * 3) + (sec_r000244_0_1 * 2)) - pub_r000244_12_1) + 30) & 127;
  int stage_v_351_2 = ((((sec_r000244_0_2 * 3) + (sec_r000244_0_2 * 2)) - pub_r000244_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_351_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_351_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_351_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_351_2) & 255;
  int stage_v_352_1 = ((((sec_r000244_20_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_15_1) + 31) & 127;
  int stage_v_352_2 = ((((sec_r000244_20_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_352_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_352_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_352_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_352_2) & 255;
  int stage_v_353_1 = ((((sec_r000244_23_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_7_1) + 19) & 127;
  int stage_v_353_2 = ((((sec_r000244_23_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_353_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_353_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_353_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_353_2) & 255;
  int stage_v_354_1 = ((((stage_v_303_1 * 3) + (sec_r000244_20_1 * 2)) - pub_r000244_7_1) + 27) & 127;
  int stage_v_354_2 = ((((stage_v_303_2 * 3) + (sec_r000244_20_2 * 2)) - pub_r000244_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_354_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_354_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_354_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_354_2) & 255;
  int stage_v_355_1 = ((((stage_v_287_1 * 3) + (sec_r000244_18_1 * 2)) - pub_r000244_13_1) + 15) & 127;
  int stage_v_355_2 = ((((stage_v_287_2 * 3) + (sec_r000244_18_2 * 2)) - pub_r000244_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_355_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_355_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_355_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_355_2) & 255;
  int stage_v_356_1 = ((((sec_r000244_23_1 * 3) + (sec_r000244_23_1 * 2)) - pub_r000244_2_1) + 34) & 127;
  int stage_v_356_2 = ((((sec_r000244_23_2 * 3) + (sec_r000244_23_2 * 2)) - pub_r000244_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_356_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_356_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_356_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_356_2) & 255;
  int stage_v_357_1 = ((((stage_v_210_1 * 3) + (sec_r000244_9_1 * 2)) - pub_r000244_0_1) + 25) & 127;
  int stage_v_357_2 = ((((stage_v_210_2 * 3) + (sec_r000244_9_2 * 2)) - pub_r000244_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_357_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_357_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_357_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_357_2) & 255;
  int stage_v_358_1 = ((((sec_r000244_2_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_6_1) + 11) & 127;
  int stage_v_358_2 = ((((sec_r000244_2_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_358_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_358_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_358_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_358_2) & 255;
  int stage_v_359_1 = ((((sec_r000244_16_1 * 3) + (sec_r000244_16_1 * 2)) - pub_r000244_0_1) + 31) & 127;
  int stage_v_359_2 = ((((sec_r000244_16_2 * 3) + (sec_r000244_16_2 * 2)) - pub_r000244_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_359_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_359_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_359_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_359_2) & 255;
  int stage_v_360_1 = ((((stage_v_354_1 * 3) + (sec_r000244_8_1 * 2)) - pub_r000244_9_1) + 22) & 127;
  int stage_v_360_2 = ((((stage_v_354_2 * 3) + (sec_r000244_8_2 * 2)) - pub_r000244_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_360_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_360_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_360_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_360_2) & 255;
  int stage_v_361_1 = ((((stage_v_152_1 * 3) + (sec_r000244_22_1 * 2)) - pub_r000244_16_1) + 22) & 127;
  int stage_v_361_2 = ((((stage_v_152_2 * 3) + (sec_r000244_22_2 * 2)) - pub_r000244_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_361_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_361_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_361_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_361_2) & 255;
  int stage_v_362_1 = ((((stage_v_65_1 * 3) + (sec_r000244_4_1 * 2)) - pub_r000244_0_1) + 9) & 127;
  int stage_v_362_2 = ((((stage_v_65_2 * 3) + (sec_r000244_4_2 * 2)) - pub_r000244_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_362_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_362_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_362_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_362_2) & 255;
  int stage_v_363_1 = ((((stage_v_124_1 * 3) + (sec_r000244_5_1 * 2)) - pub_r000244_2_1) + 18) & 127;
  int stage_v_363_2 = ((((stage_v_124_2 * 3) + (sec_r000244_5_2 * 2)) - pub_r000244_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_363_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_363_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_363_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_363_2) & 255;
  int stage_v_364_1 = ((((sec_r000244_14_1 * 3) + (sec_r000244_14_1 * 2)) - pub_r000244_9_1) + 28) & 127;
  int stage_v_364_2 = ((((sec_r000244_14_2 * 3) + (sec_r000244_14_2 * 2)) - pub_r000244_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_364_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_364_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_364_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_364_2) & 255;
  int stage_v_365_1 = ((((sec_r000244_2_1 * 3) + (sec_r000244_2_1 * 2)) - pub_r000244_12_1) + 15) & 127;
  int stage_v_365_2 = ((((sec_r000244_2_2 * 3) + (sec_r000244_2_2 * 2)) - pub_r000244_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_365_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_365_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_365_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_365_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000244_1_1 != sec_r000244_1_2);
  __CPROVER_assume(pub_r000244_0_1 == pub_r000244_0_2);
  __CPROVER_assume(pub_r000244_2_1 == pub_r000244_2_2);
  __CPROVER_assume(sec_r000244_18_1 != sec_r000244_18_2);
  __CPROVER_assume(pub_r000244_6_1 == pub_r000244_6_2);
  __CPROVER_assume(sec_r000244_9_1 != sec_r000244_9_2);
  __CPROVER_assume(sec_r000244_23_1 != sec_r000244_23_2);
  __CPROVER_assume(sec_r000244_16_1 != sec_r000244_16_2);
  __CPROVER_assume(sec_r000244_19_1 != sec_r000244_19_2);
  __CPROVER_assume(sec_r000244_6_1 != sec_r000244_6_2);
  __CPROVER_assume(sec_r000244_8_1 != sec_r000244_8_2);
  __CPROVER_assume(sec_r000244_14_1 != sec_r000244_14_2);
  __CPROVER_assume(sec_r000244_21_1 != sec_r000244_21_2);
  __CPROVER_assume(sec_r000244_13_1 != sec_r000244_13_2);
  __CPROVER_assume(sec_r000244_5_1 != sec_r000244_5_2);
  __CPROVER_assume(sec_r000244_3_1 != sec_r000244_3_2);
  __CPROVER_assume(sec_r000244_17_1 != sec_r000244_17_2);
  __CPROVER_assume(sec_r000244_22_1 != sec_r000244_22_2);
  __CPROVER_assume(sec_r000244_10_1 != sec_r000244_10_2);
  __CPROVER_assume(sec_r000244_20_1 != sec_r000244_20_2);
  __CPROVER_assume(pub_r000244_1_1 == pub_r000244_1_2);
  __CPROVER_assume(pub_r000244_13_1 == pub_r000244_13_2);
  __CPROVER_assume(sec_r000244_2_1 != sec_r000244_2_2);
  __CPROVER_assume(sec_r000244_0_1 != sec_r000244_0_2);
  __CPROVER_assume(sec_r000244_4_1 != sec_r000244_4_2);
  __CPROVER_assume(pub_r000244_14_1 == pub_r000244_14_2);
  __CPROVER_assume(pub_r000244_11_1 == pub_r000244_11_2);
  __CPROVER_assume(pub_r000244_7_1 == pub_r000244_7_2);
  __CPROVER_assume(pub_r000244_3_1 == pub_r000244_3_2);
  __CPROVER_assume(pub_r000244_5_1 == pub_r000244_5_2);
  __CPROVER_assume(pub_r000244_16_1 == pub_r000244_16_2);
  __CPROVER_assume(sec_r000244_11_1 != sec_r000244_11_2);
  __CPROVER_assume(pub_r000244_4_1 == pub_r000244_4_2);
  __CPROVER_assume(pub_r000244_8_1 == pub_r000244_8_2);
  __CPROVER_assume(pub_r000244_15_1 == pub_r000244_15_2);
  __CPROVER_assume(sec_r000244_12_1 != sec_r000244_12_2);
  __CPROVER_assume(pub_r000244_10_1 == pub_r000244_10_2);
  __CPROVER_assume(pub_r000244_12_1 == pub_r000244_12_2);
  __CPROVER_assume(pub_r000244_9_1 == pub_r000244_9_2);
  __CPROVER_assume(sec_r000244_7_1 != sec_r000244_7_2);
  __CPROVER_assume(sec_r000244_15_1 != sec_r000244_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.balance == st_var_3_2.balance);
  assert(st_var_3_1.auth_code == st_var_3_2.auth_code);
  assert(st_var_3_1.fee == st_var_3_2.fee);
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
}


