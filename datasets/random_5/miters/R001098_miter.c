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
struct MatrixBlock_R001098_9813_0
{
  unsigned char stride;
  unsigned char determinant;
  unsigned char dim;
  unsigned char trace;
  unsigned char scale;
  int buffer[3];
};
struct EventLog_R001098_9813_1
{
  short severity;
  short code;
  int signature;
  int buffer[3];
};
struct SensorNode_R001098_9813_2
{
  int gain;
  int status;
  short calib;
  int reading;
  int offset;
  int buffer[3];
};
union ColorPixel_R001098_9813_0
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
void fn_R001098_9813_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st_1 = {0};
  struct EventLog_R001098_9813_1 st_2 = {0};
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
  int cursor_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_97_1)
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

  switch (cursor_97_2)
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

  int pivot_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_84_1 > 33)
  {
    acc_1 = ((acc_1 + (pivot_84_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_84_2 > 33)
  {
    acc_2 = ((acc_2 + (pivot_84_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_32_1) & 63;
  aux_2 = (aux_2 + mask_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_97_1 == cursor_97_2);
  assert(pivot_84_1 == pivot_84_2);
  assert(mask_32_1 == mask_32_2);
}

int fn_R001098_9813_0(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_97 = (aux + st.buffer[1]) & 3;
  switch (cursor_97)
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

  int pivot_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_84 > 33)
  {
    acc = ((acc + (pivot_84 * 2)) + 5) & 127;
    aux ^= pivot_84 & 15;
  }
  else
  {
    acc = ((acc - pivot_84) + 11) & 127;
    aux += 3;
  }
  int mask_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001098_9813_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st_1 = {0};
  struct EventLog_R001098_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int tally_75_1 = 0;
  int tally_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_75_1 = ((tally_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_75_2 = ((tally_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_75_1) & 127;
    acc_2 = (acc_2 + tally_75_2) & 127;
  }

  int damping_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_77_1 > 38)
  {
    acc_1 = ((acc_1 + (damping_77_1 * 2)) + 5) & 127;
    aux_1 ^= damping_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_77_2 > 38)
  {
    acc_2 = ((acc_2 + (damping_77_2 * 2)) + 5) & 127;
    aux_2 ^= damping_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_75_1 == tally_75_2);
  assert(damping_77_1 == damping_77_2);
}

int fn_R001098_9813_1(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int tally_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_75 = ((tally_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_75) & 127;
  }

  int damping_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_77 > 38)
  {
    acc = ((acc + (damping_77 * 2)) + 5) & 127;
    aux ^= damping_77 & 15;
  }
  else
  {
    acc = ((acc - damping_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001098_9813_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st_1 = {0};
  struct EventLog_R001098_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int stride_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_21_1 > 45)
  {
    acc_1 = ((acc_1 + (stride_21_1 * 2)) + 5) & 127;
    aux_1 ^= stride_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_21_2 > 45)
  {
    acc_2 = ((acc_2 + (stride_21_2 * 2)) + 5) & 127;
    aux_2 ^= stride_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_44_1) & 63;
  aux_2 = (aux_2 + parity_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_34_1 = 0;
  int damping_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_34_1 = ((damping_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_34_2 = ((damping_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_34_1) & 127;
    acc_2 = (acc_2 + damping_34_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_45_1 = local_arr_1[aux_1 % 3];
  int bound_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_21_1 == stride_21_2);
  assert(parity_44_1 == parity_44_2);
  assert(damping_34_1 == damping_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_45_1 == bound_45_2);
}

int fn_R001098_9813_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int stride_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_21 > 45)
  {
    acc = ((acc + (stride_21 * 2)) + 5) & 127;
    aux ^= stride_21 & 15;
  }
  else
  {
    acc = ((acc - stride_21) + 11) & 127;
    aux += 3;
  }
  int parity_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_44) & 63;
  acc ^= aux;
  int damping_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_34 = ((damping_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_34) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int bound_45 = local_arr[aux % 3];
  acc = (acc + (bound_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001098_9813_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st_1 = {0};
  struct EventLog_R001098_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_74_1 = local_arr_1[aux_1 % 3];
  int pivot_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_74_2 * 2)) & 127;
  int offset_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_91_1 > 38)
  {
    acc_1 = ((acc_1 + (offset_91_1 * 2)) + 5) & 127;
    aux_1 ^= offset_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_91_2 > 38)
  {
    acc_2 = ((acc_2 + (offset_91_2 * 2)) + 5) & 127;
    aux_2 ^= offset_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_91_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_92_1) & 63;
  aux_2 = (aux_2 + quantum_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_74_1 == pivot_74_2);
  assert(offset_91_1 == offset_91_2);
  assert(quantum_92_1 == quantum_92_2);
}

int fn_R001098_9813_3(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int pivot_74 = local_arr[aux % 3];
  acc = (acc + (pivot_74 * 2)) & 127;
  int offset_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_91 > 38)
  {
    acc = ((acc + (offset_91 * 2)) + 5) & 127;
    aux ^= offset_91 & 15;
  }
  else
  {
    acc = ((acc - offset_91) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001098_9813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st_1 = {0};
  struct MatrixBlock_R001098_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int segment_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_96_1 > 45)
  {
    acc_1 = ((acc_1 + (segment_96_1 * 2)) + 5) & 127;
    aux_1 ^= segment_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_96_2 > 45)
  {
    acc_2 = ((acc_2 + (segment_96_2 * 2)) + 5) & 127;
    aux_2 ^= segment_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_24_1) & 63;
  aux_2 = (aux_2 + quotient_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_12_1 = local_arr_1[aux_1 % 3];
  int weight_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_96_1 == segment_96_2);
  assert(quotient_24_1 == quotient_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_12_1 == weight_12_2);
}

int fn_R001098_9813_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int segment_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_96 > 45)
  {
    acc = ((acc + (segment_96 * 2)) + 5) & 127;
    aux ^= segment_96 & 15;
  }
  else
  {
    acc = ((acc - segment_96) + 11) & 127;
    aux += 3;
  }
  int quotient_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_24) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_12 = local_arr[aux % 3];
  acc = (acc + (weight_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001098_9813_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st_1 = {0};
  struct EventLog_R001098_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int index_reg_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_13_1 > 48)
  {
    acc_1 = ((acc_1 + (index_reg_13_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_13_2 > 48)
  {
    acc_2 = ((acc_2 + (index_reg_13_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_68_1 = 0;
  int residue_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_68_1 = ((residue_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_68_2 = ((residue_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_68_1) & 127;
    acc_2 = (acc_2 + residue_68_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_63_1 = local_arr_1[aux_1 % 3];
  int factor_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_63_2 * 2)) & 127;
  int residue_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_45_1)
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

  switch (residue_45_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_13_1 == index_reg_13_2);
  assert(residue_68_1 == residue_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_63_1 == factor_63_2);
  assert(residue_45_1 == residue_45_2);
}

int fn_R001098_9813_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int index_reg_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_13 > 48)
  {
    acc = ((acc + (index_reg_13 * 2)) + 5) & 127;
    aux ^= index_reg_13 & 15;
  }
  else
  {
    acc = ((acc - index_reg_13) + 11) & 127;
    aux += 3;
  }
  int residue_68 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_68 = ((residue_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_68) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int factor_63 = local_arr[aux % 3];
  acc = (acc + (factor_63 * 2)) & 127;
  int residue_45 = (aux + st.buffer[1]) & 3;
  switch (residue_45)
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

void fn_R001098_9813_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001098_9813_2 st_1 = {0};
  struct SensorNode_R001098_9813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_24_1 = 0;
  int metric_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_24_1 = ((metric_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_24_2 = ((metric_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_24_1) & 127;
    acc_2 = (acc_2 + metric_24_2) & 127;
  }

  int pivot_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_40_1)
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

  switch (pivot_40_2)
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

  int coefficient_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_33_1 > 11)
  {
    acc_1 = ((acc_1 + (coefficient_33_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_33_2 > 11)
  {
    acc_2 = ((acc_2 + (coefficient_33_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_24_1 == metric_24_2);
  assert(pivot_40_1 == pivot_40_2);
  assert(coefficient_33_1 == coefficient_33_2);
}

int fn_R001098_9813_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001098_9813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_24 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_24 = ((metric_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_24) & 127;
  }

  int pivot_40 = (aux + st.buffer[1]) & 3;
  switch (pivot_40)
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

  int coefficient_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_33 > 11)
  {
    acc = ((acc + (coefficient_33 * 2)) + 5) & 127;
    aux ^= coefficient_33 & 15;
  }
  else
  {
    acc = ((acc - coefficient_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001098_9813_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001098_9813_2 st_1 = {0};
  struct SensorNode_R001098_9813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int metric_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_31_1) & 63;
  aux_2 = (aux_2 + metric_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_76_1 = 0;
  int sample_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_76_1 = ((sample_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_76_2 = ((sample_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_76_1) & 127;
    acc_2 = (acc_2 + sample_76_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_26_1)
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

  switch (scale_26_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_31_1 == metric_31_2);
  assert(sample_76_1 == sample_76_2);
  assert(scale_26_1 == scale_26_2);
}

int fn_R001098_9813_7(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001098_9813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int metric_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_31) & 63;
  acc ^= aux;
  int sample_76 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_76 = ((sample_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_76) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_26 = (aux + st.buffer[1]) & 3;
  switch (scale_26)
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

void fn_R001098_9813_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st_1 = {0};
  struct EventLog_R001098_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int stride_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_43_1)
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

  switch (stride_43_2)
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
  int sample_32_1 = local_arr_1[aux_1 % 3];
  int sample_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_32_2 * 2)) & 127;
  int residue_32_1 = 0;
  int residue_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_32_1 = ((residue_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_32_2 = ((residue_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_32_1) & 127;
    acc_2 = (acc_2 + residue_32_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_43_1 == stride_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_32_1 == sample_32_2);
  assert(residue_32_1 == residue_32_2);
}

int fn_R001098_9813_8(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int stride_43 = (aux + st.buffer[1]) & 3;
  switch (stride_43)
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
  int sample_32 = local_arr[aux % 3];
  acc = (acc + (sample_32 * 2)) & 127;
  int residue_32 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_32 = ((residue_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_32) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001098_9813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st_1 = {0};
  struct MatrixBlock_R001098_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int index_reg_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_51_1)
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

  switch (index_reg_51_2)
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
  int segment_47_1 = local_arr_1[aux_1 % 3];
  int segment_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_47_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_51_1 == index_reg_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_47_1 == segment_47_2);
}

int fn_R001098_9813_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int index_reg_51 = (aux + st.buffer[1]) & 3;
  switch (index_reg_51)
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
  int segment_47 = local_arr[aux % 3];
  acc = (acc + (segment_47 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001098_9813_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st_1 = {0};
  struct MatrixBlock_R001098_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int parity_25_1 = 0;
  int parity_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_25_1 = ((parity_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_25_2 = ((parity_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_25_1) & 127;
    acc_2 = (acc_2 + parity_25_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_38_1 = local_arr_1[aux_1 % 3];
  int margin_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_38_2 * 2)) & 127;
  int vector_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_43_1 > 32)
  {
    acc_1 = ((acc_1 + (vector_43_1 * 2)) + 5) & 127;
    aux_1 ^= vector_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_43_2 > 32)
  {
    acc_2 = ((acc_2 + (vector_43_2 * 2)) + 5) & 127;
    aux_2 ^= vector_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_43_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_25_1 == parity_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_38_1 == margin_38_2);
  assert(vector_43_1 == vector_43_2);
}

int fn_R001098_9813_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int parity_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_25 = ((parity_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_25) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_38 = local_arr[aux % 3];
  acc = (acc + (margin_38 * 2)) & 127;
  int vector_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_43 > 32)
  {
    acc = ((acc + (vector_43 * 2)) + 5) & 127;
    aux ^= vector_43 & 15;
  }
  else
  {
    acc = ((acc - vector_43) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001098_9813_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001098_9813_2 st_1 = {0};
  struct SensorNode_R001098_9813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_79_1 = local_arr_1[aux_1 % 3];
  int bound_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_79_2 * 2)) & 127;
  int coefficient_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_37_1 > 29)
  {
    acc_1 = ((acc_1 + (coefficient_37_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_37_2 > 29)
  {
    acc_2 = ((acc_2 + (coefficient_37_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_79_1 == bound_79_2);
  assert(coefficient_37_1 == coefficient_37_2);
}

int fn_R001098_9813_11(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001098_9813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int bound_79 = local_arr[aux % 3];
  acc = (acc + (bound_79 * 2)) & 127;
  int coefficient_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_37 > 29)
  {
    acc = ((acc + (coefficient_37 * 2)) + 5) & 127;
    aux ^= coefficient_37 & 15;
  }
  else
  {
    acc = ((acc - coefficient_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001098_9813_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st_1 = {0};
  struct MatrixBlock_R001098_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int metric_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_56_1)
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

  switch (metric_56_2)
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

  int checksum_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_85_1 > 33)
  {
    acc_1 = ((acc_1 + (checksum_85_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_85_2 > 33)
  {
    acc_2 = ((acc_2 + (checksum_85_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_56_1 == metric_56_2);
  assert(checksum_85_1 == checksum_85_2);
}

int fn_R001098_9813_12(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int metric_56 = (aux + st.buffer[1]) & 3;
  switch (metric_56)
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

  int checksum_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_85 > 33)
  {
    acc = ((acc + (checksum_85 * 2)) + 5) & 127;
    aux ^= checksum_85 & 15;
  }
  else
  {
    acc = ((acc - checksum_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001098_9813_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st_1 = {0};
  struct MatrixBlock_R001098_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int index_reg_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_48_1 > 48)
  {
    acc_1 = ((acc_1 + (index_reg_48_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_48_2 > 48)
  {
    acc_2 = ((acc_2 + (index_reg_48_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_53_1) & 63;
  aux_2 = (aux_2 + cursor_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_48_1 == index_reg_48_2);
  assert(cursor_53_1 == cursor_53_2);
}

int fn_R001098_9813_13(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int index_reg_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_48 > 48)
  {
    acc = ((acc + (index_reg_48 * 2)) + 5) & 127;
    aux ^= index_reg_48 & 15;
  }
  else
  {
    acc = ((acc - index_reg_48) + 11) & 127;
    aux += 3;
  }
  int cursor_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_53) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001098_9813_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001098_9813_2 st_1 = {0};
  struct SensorNode_R001098_9813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int damping_39_1 = 0;
  int damping_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_39_1 = ((damping_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_39_2 = ((damping_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_39_1) & 127;
    acc_2 = (acc_2 + damping_39_2) & 127;
  }

  int tally_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_73_1 > 28)
  {
    acc_1 = ((acc_1 + (tally_73_1 * 2)) + 5) & 127;
    aux_1 ^= tally_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_73_2 > 28)
  {
    acc_2 = ((acc_2 + (tally_73_2 * 2)) + 5) & 127;
    aux_2 ^= tally_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_73_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_55_1)
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

  switch (metric_55_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_39_1 == damping_39_2);
  assert(tally_73_1 == tally_73_2);
  assert(metric_55_1 == metric_55_2);
}

int fn_R001098_9813_14(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001098_9813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int damping_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_39 = ((damping_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_39) & 127;
  }

  int tally_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_73 > 28)
  {
    acc = ((acc + (tally_73 * 2)) + 5) & 127;
    aux ^= tally_73 & 15;
  }
  else
  {
    acc = ((acc - tally_73) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_55 = (aux + st.buffer[1]) & 3;
  switch (metric_55)
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

void fn_R001098_9813_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001098_9813_2 st_1 = {0};
  struct SensorNode_R001098_9813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_64_1 = local_arr_1[aux_1 % 3];
  int factor_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_64_2 * 2)) & 127;
  int factor_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_10_1) & 63;
  aux_2 = (aux_2 + factor_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_63_1 = 0;
  int segment_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_63_1 = ((segment_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_63_2 = ((segment_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_63_1) & 127;
    acc_2 = (acc_2 + segment_63_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_64_1 == factor_64_2);
  assert(factor_10_1 == factor_10_2);
  assert(segment_63_1 == segment_63_2);
}

int fn_R001098_9813_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001098_9813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int factor_64 = local_arr[aux % 3];
  acc = (acc + (factor_64 * 2)) & 127;
  int factor_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_10) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_63 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_63 = ((segment_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_63) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001098_9813_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st_1 = {0};
  struct EventLog_R001098_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int stride_56_1 = 0;
  int stride_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_56_1 = ((stride_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_56_2 = ((stride_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_56_1) & 127;
    acc_2 = (acc_2 + stride_56_2) & 127;
  }

  int delta_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_34_1 > 37)
  {
    acc_1 = ((acc_1 + (delta_34_1 * 2)) + 5) & 127;
    aux_1 ^= delta_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_34_2 > 37)
  {
    acc_2 = ((acc_2 + (delta_34_2 * 2)) + 5) & 127;
    aux_2 ^= delta_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_56_1 == stride_56_2);
  assert(delta_34_1 == delta_34_2);
}

int fn_R001098_9813_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int stride_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_56 = ((stride_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_56) & 127;
  }

  int delta_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_34 > 37)
  {
    acc = ((acc + (delta_34 * 2)) + 5) & 127;
    aux ^= delta_34 & 15;
  }
  else
  {
    acc = ((acc - delta_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001098_9813_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st_1 = {0};
  struct EventLog_R001098_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tally_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_35_1) & 63;
  aux_2 = (aux_2 + tally_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_33_1 = local_arr_1[aux_1 % 3];
  int vector_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_33_2 * 2)) & 127;
  int stride_55_1 = 0;
  int stride_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_55_1 = ((stride_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_55_2 = ((stride_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_55_1) & 127;
    acc_2 = (acc_2 + stride_55_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_35_1 == tally_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_33_1 == vector_33_2);
  assert(stride_55_1 == stride_55_2);
}

int fn_R001098_9813_17(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tally_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_33 = local_arr[aux % 3];
  acc = (acc + (vector_33 * 2)) & 127;
  int stride_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_55 = ((stride_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_55) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001098_9813_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st_1 = {0};
  struct EventLog_R001098_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int mask_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_42_1 > 45)
  {
    acc_1 = ((acc_1 + (mask_42_1 * 2)) + 5) & 127;
    aux_1 ^= mask_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_42_2 > 45)
  {
    acc_2 = ((acc_2 + (mask_42_2 * 2)) + 5) & 127;
    aux_2 ^= mask_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_93_1 = 0;
  int tally_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_93_1 = ((tally_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_93_2 = ((tally_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_93_1) & 127;
    acc_2 = (acc_2 + tally_93_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_42_1 == mask_42_2);
  assert(tally_93_1 == tally_93_2);
}

int fn_R001098_9813_18(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001098_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int mask_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_42 > 45)
  {
    acc = ((acc + (mask_42 * 2)) + 5) & 127;
    aux ^= mask_42 & 15;
  }
  else
  {
    acc = ((acc - mask_42) + 11) & 127;
    aux += 3;
  }
  int tally_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_93 = ((tally_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_93) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001098_9813_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st_1 = {0};
  struct MatrixBlock_R001098_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int coefficient_94_1 = 0;
  int coefficient_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_94_1 = ((coefficient_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_94_2 = ((coefficient_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_94_1) & 127;
    acc_2 = (acc_2 + coefficient_94_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_86_1 = local_arr_1[aux_1 % 3];
  int parity_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_94_1 == coefficient_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_86_1 == parity_86_2);
}

int fn_R001098_9813_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int coefficient_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_94 = ((coefficient_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_94) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int parity_86 = local_arr[aux % 3];
  acc = (acc + (parity_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001098_9813_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st_1 = {0};
  struct MatrixBlock_R001098_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_54_1 = local_arr_1[aux_1 % 3];
  int offset_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_54_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_17_1 > 16)
  {
    acc_1 = ((acc_1 + (damping_17_1 * 2)) + 5) & 127;
    aux_1 ^= damping_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_17_2 > 16)
  {
    acc_2 = ((acc_2 + (damping_17_2 * 2)) + 5) & 127;
    aux_2 ^= damping_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_17_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_54_1 == offset_54_2);
  assert(damping_17_1 == damping_17_2);
}

int fn_R001098_9813_20(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001098_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int offset_54 = local_arr[aux % 3];
  acc = (acc + (offset_54 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_17 > 16)
  {
    acc = ((acc + (damping_17 * 2)) + 5) & 127;
    aux ^= damping_17 & 15;
  }
  else
  {
    acc = ((acc - damping_17) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001098_0_1;
  int sec_r001098_0_2;
  int sec_r001098_1_1;
  int sec_r001098_1_2;
  int sec_r001098_2_1;
  int sec_r001098_2_2;
  int sec_r001098_3_1;
  int sec_r001098_3_2;
  int sec_r001098_4_1;
  int sec_r001098_4_2;
  int sec_r001098_5_1;
  int sec_r001098_5_2;
  int sec_r001098_6_1;
  int sec_r001098_6_2;
  int sec_r001098_7_1;
  int sec_r001098_7_2;
  int sec_r001098_8_1;
  int sec_r001098_8_2;
  int sec_r001098_9_1;
  int sec_r001098_9_2;
  int sec_r001098_10_1;
  int sec_r001098_10_2;
  int sec_r001098_11_1;
  int sec_r001098_11_2;
  int sec_r001098_12_1;
  int sec_r001098_12_2;
  int sec_r001098_13_1;
  int sec_r001098_13_2;
  int sec_r001098_14_1;
  int sec_r001098_14_2;
  int sec_r001098_15_1;
  int sec_r001098_15_2;
  int sec_r001098_16_1;
  int sec_r001098_16_2;
  int sec_r001098_17_1;
  int sec_r001098_17_2;
  int sec_r001098_18_1;
  int sec_r001098_18_2;
  int sec_r001098_19_1;
  int sec_r001098_19_2;
  int sec_r001098_20_1;
  int sec_r001098_20_2;
  int sec_r001098_21_1;
  int sec_r001098_21_2;
  int sec_r001098_22_1;
  int sec_r001098_22_2;
  int sec_r001098_23_1;
  int sec_r001098_23_2;
  int pub_r001098_0_1;
  int pub_r001098_0_2;
  int pub_r001098_1_1;
  int pub_r001098_1_2;
  int pub_r001098_2_1;
  int pub_r001098_2_2;
  int pub_r001098_3_1;
  int pub_r001098_3_2;
  int pub_r001098_4_1;
  int pub_r001098_4_2;
  int pub_r001098_5_1;
  int pub_r001098_5_2;
  int pub_r001098_6_1;
  int pub_r001098_6_2;
  int pub_r001098_7_1;
  int pub_r001098_7_2;
  int pub_r001098_8_1;
  int pub_r001098_8_2;
  int pub_r001098_9_1;
  int pub_r001098_9_2;
  int pub_r001098_10_1;
  int pub_r001098_10_2;
  int pub_r001098_11_1;
  int pub_r001098_11_2;
  int pub_r001098_12_1;
  int pub_r001098_12_2;
  int pub_r001098_13_1;
  int pub_r001098_13_2;
  int pub_r001098_14_1;
  int pub_r001098_14_2;
  int pub_r001098_15_1;
  int pub_r001098_15_2;
  int pub_r001098_16_1;
  int pub_r001098_16_2;
  int pub_r001098_17_1;
  int pub_r001098_17_2;
  int pub_r001098_18_1;
  int pub_r001098_18_2;
  int pub_r001098_19_1;
  int pub_r001098_19_2;
  int pub_r001098_20_1;
  int pub_r001098_20_2;
  int pub_r001098_21_1;
  int pub_r001098_21_2;
  int pub_r001098_22_1;
  int pub_r001098_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001098_0_1 >= (-100)) && (pub_r001098_0_1 <= 100));
  __CPROVER_assume((pub_r001098_0_2 >= (-100)) && (pub_r001098_0_2 <= 100));
  __CPROVER_assume((pub_r001098_1_1 >= (-100)) && (pub_r001098_1_1 <= 100));
  __CPROVER_assume((pub_r001098_1_2 >= (-100)) && (pub_r001098_1_2 <= 100));
  __CPROVER_assume((pub_r001098_2_1 >= (-100)) && (pub_r001098_2_1 <= 100));
  __CPROVER_assume((pub_r001098_2_2 >= (-100)) && (pub_r001098_2_2 <= 100));
  __CPROVER_assume((pub_r001098_3_1 >= (-100)) && (pub_r001098_3_1 <= 100));
  __CPROVER_assume((pub_r001098_3_2 >= (-100)) && (pub_r001098_3_2 <= 100));
  __CPROVER_assume((pub_r001098_4_1 >= (-100)) && (pub_r001098_4_1 <= 100));
  __CPROVER_assume((pub_r001098_4_2 >= (-100)) && (pub_r001098_4_2 <= 100));
  __CPROVER_assume((pub_r001098_5_1 >= (-100)) && (pub_r001098_5_1 <= 100));
  __CPROVER_assume((pub_r001098_5_2 >= (-100)) && (pub_r001098_5_2 <= 100));
  __CPROVER_assume((pub_r001098_6_1 >= (-100)) && (pub_r001098_6_1 <= 100));
  __CPROVER_assume((pub_r001098_6_2 >= (-100)) && (pub_r001098_6_2 <= 100));
  __CPROVER_assume((pub_r001098_7_1 >= (-100)) && (pub_r001098_7_1 <= 100));
  __CPROVER_assume((pub_r001098_7_2 >= (-100)) && (pub_r001098_7_2 <= 100));
  __CPROVER_assume((pub_r001098_8_1 >= (-100)) && (pub_r001098_8_1 <= 100));
  __CPROVER_assume((pub_r001098_8_2 >= (-100)) && (pub_r001098_8_2 <= 100));
  __CPROVER_assume((pub_r001098_9_1 >= (-100)) && (pub_r001098_9_1 <= 100));
  __CPROVER_assume((pub_r001098_9_2 >= (-100)) && (pub_r001098_9_2 <= 100));
  __CPROVER_assume((pub_r001098_10_1 >= (-100)) && (pub_r001098_10_1 <= 100));
  __CPROVER_assume((pub_r001098_10_2 >= (-100)) && (pub_r001098_10_2 <= 100));
  __CPROVER_assume((pub_r001098_11_1 >= (-100)) && (pub_r001098_11_1 <= 100));
  __CPROVER_assume((pub_r001098_11_2 >= (-100)) && (pub_r001098_11_2 <= 100));
  __CPROVER_assume((pub_r001098_12_1 >= (-100)) && (pub_r001098_12_1 <= 100));
  __CPROVER_assume((pub_r001098_12_2 >= (-100)) && (pub_r001098_12_2 <= 100));
  __CPROVER_assume((pub_r001098_13_1 >= (-100)) && (pub_r001098_13_1 <= 100));
  __CPROVER_assume((pub_r001098_13_2 >= (-100)) && (pub_r001098_13_2 <= 100));
  __CPROVER_assume((pub_r001098_14_1 >= (-100)) && (pub_r001098_14_1 <= 100));
  __CPROVER_assume((pub_r001098_14_2 >= (-100)) && (pub_r001098_14_2 <= 100));
  __CPROVER_assume((pub_r001098_15_1 >= (-100)) && (pub_r001098_15_1 <= 100));
  __CPROVER_assume((pub_r001098_15_2 >= (-100)) && (pub_r001098_15_2 <= 100));
  __CPROVER_assume((pub_r001098_16_1 >= (-100)) && (pub_r001098_16_1 <= 100));
  __CPROVER_assume((pub_r001098_16_2 >= (-100)) && (pub_r001098_16_2 <= 100));
  __CPROVER_assume((pub_r001098_17_1 >= (-100)) && (pub_r001098_17_1 <= 100));
  __CPROVER_assume((pub_r001098_17_2 >= (-100)) && (pub_r001098_17_2 <= 100));
  __CPROVER_assume((pub_r001098_18_1 >= (-100)) && (pub_r001098_18_1 <= 100));
  __CPROVER_assume((pub_r001098_18_2 >= (-100)) && (pub_r001098_18_2 <= 100));
  __CPROVER_assume((pub_r001098_19_1 >= (-100)) && (pub_r001098_19_1 <= 100));
  __CPROVER_assume((pub_r001098_19_2 >= (-100)) && (pub_r001098_19_2 <= 100));
  __CPROVER_assume((pub_r001098_20_1 >= (-100)) && (pub_r001098_20_1 <= 100));
  __CPROVER_assume((pub_r001098_20_2 >= (-100)) && (pub_r001098_20_2 <= 100));
  __CPROVER_assume((pub_r001098_21_1 >= (-100)) && (pub_r001098_21_1 <= 100));
  __CPROVER_assume((pub_r001098_21_2 >= (-100)) && (pub_r001098_21_2 <= 100));
  __CPROVER_assume((pub_r001098_22_1 >= (-100)) && (pub_r001098_22_1 <= 100));
  __CPROVER_assume((pub_r001098_22_2 >= (-100)) && (pub_r001098_22_2 <= 100));
  __CPROVER_assume((sec_r001098_0_1 >= 0) && (sec_r001098_0_1 <= 255));
  __CPROVER_assume((sec_r001098_0_2 >= 0) && (sec_r001098_0_2 <= 255));
  __CPROVER_assume((sec_r001098_1_1 >= 0) && (sec_r001098_1_1 <= 255));
  __CPROVER_assume((sec_r001098_1_2 >= 0) && (sec_r001098_1_2 <= 255));
  __CPROVER_assume((sec_r001098_2_1 >= 0) && (sec_r001098_2_1 <= 255));
  __CPROVER_assume((sec_r001098_2_2 >= 0) && (sec_r001098_2_2 <= 255));
  __CPROVER_assume((sec_r001098_3_1 >= 0) && (sec_r001098_3_1 <= 255));
  __CPROVER_assume((sec_r001098_3_2 >= 0) && (sec_r001098_3_2 <= 255));
  __CPROVER_assume((sec_r001098_4_1 >= 0) && (sec_r001098_4_1 <= 255));
  __CPROVER_assume((sec_r001098_4_2 >= 0) && (sec_r001098_4_2 <= 255));
  __CPROVER_assume((sec_r001098_5_1 >= 0) && (sec_r001098_5_1 <= 255));
  __CPROVER_assume((sec_r001098_5_2 >= 0) && (sec_r001098_5_2 <= 255));
  __CPROVER_assume((sec_r001098_6_1 >= 0) && (sec_r001098_6_1 <= 255));
  __CPROVER_assume((sec_r001098_6_2 >= 0) && (sec_r001098_6_2 <= 255));
  __CPROVER_assume((sec_r001098_7_1 >= 0) && (sec_r001098_7_1 <= 255));
  __CPROVER_assume((sec_r001098_7_2 >= 0) && (sec_r001098_7_2 <= 255));
  __CPROVER_assume((sec_r001098_8_1 >= 0) && (sec_r001098_8_1 <= 255));
  __CPROVER_assume((sec_r001098_8_2 >= 0) && (sec_r001098_8_2 <= 255));
  __CPROVER_assume((sec_r001098_9_1 >= 0) && (sec_r001098_9_1 <= 255));
  __CPROVER_assume((sec_r001098_9_2 >= 0) && (sec_r001098_9_2 <= 255));
  __CPROVER_assume((sec_r001098_10_1 >= 0) && (sec_r001098_10_1 <= 255));
  __CPROVER_assume((sec_r001098_10_2 >= 0) && (sec_r001098_10_2 <= 255));
  __CPROVER_assume((sec_r001098_11_1 >= 0) && (sec_r001098_11_1 <= 255));
  __CPROVER_assume((sec_r001098_11_2 >= 0) && (sec_r001098_11_2 <= 255));
  __CPROVER_assume((sec_r001098_12_1 >= 0) && (sec_r001098_12_1 <= 255));
  __CPROVER_assume((sec_r001098_12_2 >= 0) && (sec_r001098_12_2 <= 255));
  __CPROVER_assume((sec_r001098_13_1 >= 0) && (sec_r001098_13_1 <= 255));
  __CPROVER_assume((sec_r001098_13_2 >= 0) && (sec_r001098_13_2 <= 255));
  __CPROVER_assume((sec_r001098_14_1 >= 0) && (sec_r001098_14_1 <= 255));
  __CPROVER_assume((sec_r001098_14_2 >= 0) && (sec_r001098_14_2 <= 255));
  __CPROVER_assume((sec_r001098_15_1 >= 0) && (sec_r001098_15_1 <= 255));
  __CPROVER_assume((sec_r001098_15_2 >= 0) && (sec_r001098_15_2 <= 255));
  __CPROVER_assume((sec_r001098_16_1 >= 0) && (sec_r001098_16_1 <= 255));
  __CPROVER_assume((sec_r001098_16_2 >= 0) && (sec_r001098_16_2 <= 255));
  __CPROVER_assume((sec_r001098_17_1 >= 0) && (sec_r001098_17_1 <= 255));
  __CPROVER_assume((sec_r001098_17_2 >= 0) && (sec_r001098_17_2 <= 255));
  __CPROVER_assume((sec_r001098_18_1 >= 0) && (sec_r001098_18_1 <= 255));
  __CPROVER_assume((sec_r001098_18_2 >= 0) && (sec_r001098_18_2 <= 255));
  __CPROVER_assume((sec_r001098_19_1 >= 0) && (sec_r001098_19_1 <= 255));
  __CPROVER_assume((sec_r001098_19_2 >= 0) && (sec_r001098_19_2 <= 255));
  __CPROVER_assume((sec_r001098_20_1 >= 0) && (sec_r001098_20_1 <= 255));
  __CPROVER_assume((sec_r001098_20_2 >= 0) && (sec_r001098_20_2 <= 255));
  __CPROVER_assume((sec_r001098_21_1 >= 0) && (sec_r001098_21_1 <= 255));
  __CPROVER_assume((sec_r001098_21_2 >= 0) && (sec_r001098_21_2 <= 255));
  __CPROVER_assume((sec_r001098_22_1 >= 0) && (sec_r001098_22_1 <= 255));
  __CPROVER_assume((sec_r001098_22_2 >= 0) && (sec_r001098_22_2 <= 255));
  __CPROVER_assume((sec_r001098_23_1 >= 0) && (sec_r001098_23_1 <= 255));
  __CPROVER_assume((sec_r001098_23_2 >= 0) && (sec_r001098_23_2 <= 255));
  struct MatrixBlock_R001098_9813_0 st_var_0_1 = {0};
  struct MatrixBlock_R001098_9813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001098_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001098_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001098_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001098_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001098_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001098_0_2 + 7) & 15;
  struct EventLog_R001098_9813_1 st_var_1_1 = {0};
  struct EventLog_R001098_9813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001098_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001098_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001098_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001098_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001098_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001098_0_2 + 9) & 15;
  struct SensorNode_R001098_9813_2 st_var_2_1 = {0};
  struct SensorNode_R001098_9813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001098_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001098_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001098_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001098_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001098_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001098_0_2 + 11) & 15;
  union ColorPixel_R001098_9813_0 u_var_1;
  union ColorPixel_R001098_9813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001098_9813_0(sec_r001098_0_1, pub_r001098_1_1);
  int helper_flow_0_2 = fn_R001098_9813_0(sec_r001098_0_2, pub_r001098_1_2);
  fn_R001098_9813_0_2(sec_r001098_0_1, pub_r001098_1_1, sec_r001098_0_2, pub_r001098_1_2);
  int helper_flow_1_1 = fn_R001098_9813_1(sec_r001098_1_1, pub_r001098_2_1);
  int helper_flow_1_2 = fn_R001098_9813_1(sec_r001098_1_2, pub_r001098_2_2);
  fn_R001098_9813_1_2(sec_r001098_1_1, pub_r001098_2_1, sec_r001098_1_2, pub_r001098_2_2);
  int helper_flow_2_1 = fn_R001098_9813_2(sec_r001098_2_1, sec_r001098_3_1, pub_r001098_4_1, pub_r001098_5_1, pub_r001098_6_1);
  int helper_flow_2_2 = fn_R001098_9813_2(sec_r001098_2_2, sec_r001098_3_2, pub_r001098_4_2, pub_r001098_5_2, pub_r001098_6_2);
  fn_R001098_9813_2_2(sec_r001098_2_1, sec_r001098_3_1, pub_r001098_4_1, pub_r001098_5_1, pub_r001098_6_1, sec_r001098_2_2, sec_r001098_3_2, pub_r001098_4_2, pub_r001098_5_2, pub_r001098_6_2);
  int helper_flow_3_1 = fn_R001098_9813_3(sec_r001098_3_1, sec_r001098_4_1, pub_r001098_5_1);
  int helper_flow_3_2 = fn_R001098_9813_3(sec_r001098_3_2, sec_r001098_4_2, pub_r001098_5_2);
  fn_R001098_9813_3_2(sec_r001098_3_1, sec_r001098_4_1, pub_r001098_5_1, sec_r001098_3_2, sec_r001098_4_2, pub_r001098_5_2);
  int helper_flow_4_1 = fn_R001098_9813_4(sec_r001098_4_1, sec_r001098_5_1, pub_r001098_6_1, pub_r001098_7_1, pub_r001098_8_1);
  int helper_flow_4_2 = fn_R001098_9813_4(sec_r001098_4_2, sec_r001098_5_2, pub_r001098_6_2, pub_r001098_7_2, pub_r001098_8_2);
  fn_R001098_9813_4_2(sec_r001098_4_1, sec_r001098_5_1, pub_r001098_6_1, pub_r001098_7_1, pub_r001098_8_1, sec_r001098_4_2, sec_r001098_5_2, pub_r001098_6_2, pub_r001098_7_2, pub_r001098_8_2);
  int helper_flow_5_1 = fn_R001098_9813_5(sec_r001098_5_1, sec_r001098_6_1, pub_r001098_7_1, pub_r001098_8_1);
  int helper_flow_5_2 = fn_R001098_9813_5(sec_r001098_5_2, sec_r001098_6_2, pub_r001098_7_2, pub_r001098_8_2);
  fn_R001098_9813_5_2(sec_r001098_5_1, sec_r001098_6_1, pub_r001098_7_1, pub_r001098_8_1, sec_r001098_5_2, sec_r001098_6_2, pub_r001098_7_2, pub_r001098_8_2);
  int helper_flow_6_1 = fn_R001098_9813_6(sec_r001098_6_1, pub_r001098_7_1, pub_r001098_8_1, pub_r001098_9_1, pub_r001098_10_1);
  int helper_flow_6_2 = fn_R001098_9813_6(sec_r001098_6_2, pub_r001098_7_2, pub_r001098_8_2, pub_r001098_9_2, pub_r001098_10_2);
  fn_R001098_9813_6_2(sec_r001098_6_1, pub_r001098_7_1, pub_r001098_8_1, pub_r001098_9_1, pub_r001098_10_1, sec_r001098_6_2, pub_r001098_7_2, pub_r001098_8_2, pub_r001098_9_2, pub_r001098_10_2);
  int helper_flow_7_1 = fn_R001098_9813_7(sec_r001098_7_1, pub_r001098_8_1, pub_r001098_9_1);
  int helper_flow_7_2 = fn_R001098_9813_7(sec_r001098_7_2, pub_r001098_8_2, pub_r001098_9_2);
  fn_R001098_9813_7_2(sec_r001098_7_1, pub_r001098_8_1, pub_r001098_9_1, sec_r001098_7_2, pub_r001098_8_2, pub_r001098_9_2);
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_0_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_0_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_0_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_0_2) + 7) & 255;
    }
  }

  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (it_1 * 3)) + (sec_r001098_12_1 & 15)) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (it_2 * 3)) + (sec_r001098_12_2 & 15)) & 63;
    if ((sec_r001098_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_1_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_1_1) + 7) & 255;
    }
    if ((sec_r001098_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_1_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_1_2) + 7) & 255;
    }
  }

  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (it_1 * 3)) + (sec_r001098_5_1 & 15)) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (it_2 * 3)) + (sec_r001098_5_2 & 15)) & 63;
    if ((sec_r001098_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_2_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_2_1) + 7) & 255;
    }
    if ((sec_r001098_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_2_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_2_2) + 7) & 255;
    }
  }

  int stage_v_3_1 = ((pub_r001098_2_1 * 2) + 11) & 63;
  int stage_v_3_2 = ((pub_r001098_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001098_20_1 * 2) + 26) & 63;
  int stage_v_4_2 = ((pub_r001098_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_5_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_5_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_5_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_5_2) + 7) & 255;
    }
  }

  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (it_1 * 3)) + (sec_r001098_18_1 & 15)) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (it_2 * 3)) + (sec_r001098_18_2 & 15)) & 63;
    if ((sec_r001098_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_6_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_6_1) + 7) & 255;
    }
    if ((sec_r001098_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_6_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_6_2) + 7) & 255;
    }
  }

  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (it_1 * 3)) + (sec_r001098_3_1 & 15)) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (it_2 * 3)) + (sec_r001098_3_2 & 15)) & 63;
    if ((sec_r001098_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_7_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_7_1) + 7) & 255;
    }
    if ((sec_r001098_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_7_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_7_2) + 7) & 255;
    }
  }

  int stage_v_8_1 = ((pub_r001098_2_1 * 2) + 49) & 63;
  int stage_v_8_2 = ((pub_r001098_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_9_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_9_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_9_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_9_2) + 7) & 255;
    }
  }

  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (it_1 * 3)) + (sec_r001098_1_1 & 15)) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (it_2 * 3)) + (sec_r001098_1_2 & 15)) & 63;
    if ((sec_r001098_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_10_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_10_1) + 7) & 255;
    }
    if ((sec_r001098_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_10_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_10_2) + 7) & 255;
    }
  }

  int stage_v_11_1 = ((pub_r001098_11_1 * 2) + 30) & 63;
  int stage_v_11_2 = ((pub_r001098_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001098_11_1 * 2) + 12) & 63;
  int stage_v_12_2 = ((pub_r001098_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_13_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_13_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_13_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_13_2) + 7) & 255;
    }
  }

  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (it_1 * 3)) + (sec_r001098_22_1 & 15)) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (it_2 * 3)) + (sec_r001098_22_2 & 15)) & 63;
    if ((sec_r001098_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_14_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_14_1) + 7) & 255;
    }
    if ((sec_r001098_22_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_14_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_14_2) + 7) & 255;
    }
  }

  int stage_v_15_1 = ((pub_r001098_5_1 * 2) + 23) & 63;
  int stage_v_15_2 = ((pub_r001098_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_16_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_16_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_16_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_16_2) + 7) & 255;
    }
  }

  int stage_v_17_1 = ((pub_r001098_5_1 * 2) + 16) & 63;
  int stage_v_17_2 = ((pub_r001098_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_18_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_18_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_18_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_18_2) + 7) & 255;
    }
  }

  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_19_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_19_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_19_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_19_2) + 7) & 255;
    }
  }

  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (it_1 * 3)) + (stage_v_14_1 & 15)) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (it_2 * 3)) + (stage_v_14_2 & 15)) & 63;
    if ((stage_v_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_20_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_20_1) + 7) & 255;
    }
    if ((stage_v_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_20_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_20_2) + 7) & 255;
    }
  }

  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (it_1 * 3)) + (stage_v_16_1 & 15)) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (it_2 * 3)) + (stage_v_16_2 & 15)) & 63;
    if ((stage_v_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_21_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_21_1) + 7) & 255;
    }
    if ((stage_v_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_21_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_21_2) + 7) & 255;
    }
  }

  int stage_v_22_1 = ((pub_r001098_4_1 * 2) + 22) & 63;
  int stage_v_22_2 = ((pub_r001098_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001098_11_1 * 2) + 24) & 63;
  int stage_v_23_2 = ((pub_r001098_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_24_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_24_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_24_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_24_2) + 7) & 255;
    }
  }

  int stage_v_25_1 = ((pub_r001098_2_1 * 2) + 48) & 63;
  int stage_v_25_2 = ((pub_r001098_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001098_16_1 * 2) + 34) & 63;
  int stage_v_26_2 = ((pub_r001098_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (it_1 * 3)) + (sec_r001098_17_1 & 15)) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (it_2 * 3)) + (sec_r001098_17_2 & 15)) & 63;
    if ((sec_r001098_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_27_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_27_1) + 7) & 255;
    }
    if ((sec_r001098_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_27_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_27_2) + 7) & 255;
    }
  }

  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (it_1 * 3)) + (stage_v_1_1 & 15)) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (it_2 * 3)) + (stage_v_1_2 & 15)) & 63;
    if ((stage_v_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_28_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_28_1) + 7) & 255;
    }
    if ((stage_v_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_28_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_28_2) + 7) & 255;
    }
  }

  int stage_v_29_1 = ((pub_r001098_10_1 * 2) + 31) & 63;
  int stage_v_29_2 = ((pub_r001098_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_30_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_30_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_30_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_30_2) + 7) & 255;
    }
  }

  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (it_1 * 3)) + (stage_v_30_1 & 15)) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (it_2 * 3)) + (stage_v_30_2 & 15)) & 63;
    if ((stage_v_30_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_31_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_31_1) + 7) & 255;
    }
    if ((stage_v_30_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_31_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_31_2) + 7) & 255;
    }
  }

  int stage_v_32_1 = ((pub_r001098_14_1 * 2) + 42) & 63;
  int stage_v_32_2 = ((pub_r001098_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001098_6_1 * 2) + 20) & 63;
  int stage_v_33_2 = ((pub_r001098_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001098_13_1 * 2) + 35) & 63;
  int stage_v_34_2 = ((pub_r001098_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001098_12_1 * 2) + 26) & 63;
  int stage_v_35_2 = ((pub_r001098_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001098_0_1 * 2) + 31) & 63;
  int stage_v_36_2 = ((pub_r001098_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001098_4_1 * 2) + 35) & 63;
  int stage_v_37_2 = ((pub_r001098_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (it_1 * 3)) + (stage_v_31_1 & 15)) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (it_2 * 3)) + (stage_v_31_2 & 15)) & 63;
    if ((stage_v_31_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_38_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_38_1) + 7) & 255;
    }
    if ((stage_v_31_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_38_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_38_2) + 7) & 255;
    }
  }

  int stage_v_39_1 = ((pub_r001098_4_1 * 2) + 34) & 63;
  int stage_v_39_2 = ((pub_r001098_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_40_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_40_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_40_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_40_2) + 7) & 255;
    }
  }

  int stage_v_41_1 = ((pub_r001098_19_1 * 2) + 28) & 63;
  int stage_v_41_2 = ((pub_r001098_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_42_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_42_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_42_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_42_2) + 7) & 255;
    }
  }

  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (it_1 * 3)) + (stage_v_7_1 & 15)) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (it_2 * 3)) + (stage_v_7_2 & 15)) & 63;
    if ((stage_v_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_43_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_43_1) + 7) & 255;
    }
    if ((stage_v_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_43_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_43_2) + 7) & 255;
    }
  }

  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (it_1 * 3)) + (stage_v_31_1 & 15)) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (it_2 * 3)) + (stage_v_31_2 & 15)) & 63;
    if ((stage_v_31_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_44_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_44_1) + 7) & 255;
    }
    if ((stage_v_31_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_44_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_44_2) + 7) & 255;
    }
  }

  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_45_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_45_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_45_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_45_2) + 7) & 255;
    }
  }

  int stage_v_46_1 = ((pub_r001098_1_1 * 2) + 41) & 63;
  int stage_v_46_2 = ((pub_r001098_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (it_1 * 3)) + (helper_flow_7_1 & 15)) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (it_2 * 3)) + (helper_flow_7_2 & 15)) & 63;
    if ((helper_flow_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_47_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_47_1) + 7) & 255;
    }
    if ((helper_flow_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_47_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_47_2) + 7) & 255;
    }
  }

  int stage_v_48_1 = ((pub_r001098_6_1 * 2) + 8) & 63;
  int stage_v_48_2 = ((pub_r001098_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001098_18_1 * 2) + 39) & 63;
  int stage_v_49_2 = ((pub_r001098_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (it_1 * 3)) + (sec_r001098_1_1 & 15)) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (it_2 * 3)) + (sec_r001098_1_2 & 15)) & 63;
    if ((sec_r001098_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_50_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_50_1) + 7) & 255;
    }
    if ((sec_r001098_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_50_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_50_2) + 7) & 255;
    }
  }

  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_51_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_51_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_51_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_51_2) + 7) & 255;
    }
  }

  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (it_1 * 3)) + (sec_r001098_3_1 & 15)) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (it_2 * 3)) + (sec_r001098_3_2 & 15)) & 63;
    if ((sec_r001098_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_52_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_52_1) + 7) & 255;
    }
    if ((sec_r001098_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_52_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_52_2) + 7) & 255;
    }
  }

  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (it_1 * 3)) + (stage_v_42_1 & 15)) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (it_2 * 3)) + (stage_v_42_2 & 15)) & 63;
    if ((stage_v_42_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_53_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_53_1) + 7) & 255;
    }
    if ((stage_v_42_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_53_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_53_2) + 7) & 255;
    }
  }

  int stage_v_54_1 = ((pub_r001098_16_1 * 2) + 38) & 63;
  int stage_v_54_2 = ((pub_r001098_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (it_1 * 3)) + (stage_v_30_1 & 15)) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (it_2 * 3)) + (stage_v_30_2 & 15)) & 63;
    if ((stage_v_30_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_55_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_55_1) + 7) & 255;
    }
    if ((stage_v_30_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_55_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_55_2) + 7) & 255;
    }
  }

  int stage_v_56_1 = ((pub_r001098_5_1 * 2) + 14) & 63;
  int stage_v_56_2 = ((pub_r001098_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (it_1 * 3)) + (sec_r001098_16_1 & 15)) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (it_2 * 3)) + (sec_r001098_16_2 & 15)) & 63;
    if ((sec_r001098_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_57_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_57_1) + 7) & 255;
    }
    if ((sec_r001098_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_57_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_57_2) + 7) & 255;
    }
  }

  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (it_1 * 3)) + (stage_v_5_1 & 15)) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (it_2 * 3)) + (stage_v_5_2 & 15)) & 63;
    if ((stage_v_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_58_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_58_1) + 7) & 255;
    }
    if ((stage_v_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_58_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_58_2) + 7) & 255;
    }
  }

  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (it_1 * 3)) + (stage_v_0_1 & 15)) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (it_2 * 3)) + (stage_v_0_2 & 15)) & 63;
    if ((stage_v_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_59_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_59_1) + 7) & 255;
    }
    if ((stage_v_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_59_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_59_2) + 7) & 255;
    }
  }

  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (it_1 * 3)) + (stage_v_38_1 & 15)) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (it_2 * 3)) + (stage_v_38_2 & 15)) & 63;
    if ((stage_v_38_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_60_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_60_1) + 7) & 255;
    }
    if ((stage_v_38_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_60_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_60_2) + 7) & 255;
    }
  }

  int stage_v_61_1 = ((pub_r001098_1_1 * 2) + 41) & 63;
  int stage_v_61_2 = ((pub_r001098_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001098_22_1 * 2) + 21) & 63;
  int stage_v_62_2 = ((pub_r001098_22_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (it_1 * 3)) + (sec_r001098_15_1 & 15)) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (it_2 * 3)) + (sec_r001098_15_2 & 15)) & 63;
    if ((sec_r001098_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_63_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_63_1) + 7) & 255;
    }
    if ((sec_r001098_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_63_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_63_2) + 7) & 255;
    }
  }

  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (it_1 * 3)) + (sec_r001098_9_1 & 15)) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (it_2 * 3)) + (sec_r001098_9_2 & 15)) & 63;
    if ((sec_r001098_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_64_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_64_1) + 7) & 255;
    }
    if ((sec_r001098_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_64_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_64_2) + 7) & 255;
    }
  }

  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (it_1 * 3)) + (stage_v_16_1 & 15)) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (it_2 * 3)) + (stage_v_16_2 & 15)) & 63;
    if ((stage_v_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_65_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_65_1) + 7) & 255;
    }
    if ((stage_v_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_65_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_65_2) + 7) & 255;
    }
  }

  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (it_1 * 3)) + (stage_v_16_1 & 15)) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (it_2 * 3)) + (stage_v_16_2 & 15)) & 63;
    if ((stage_v_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_66_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_66_1) + 7) & 255;
    }
    if ((stage_v_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_66_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_66_2) + 7) & 255;
    }
  }

  int stage_v_67_1 = ((pub_r001098_17_1 * 2) + 33) & 63;
  int stage_v_67_2 = ((pub_r001098_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_68_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_68_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_68_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_68_2) + 7) & 255;
    }
  }

  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (it_1 * 3)) + (stage_v_44_1 & 15)) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (it_2 * 3)) + (stage_v_44_2 & 15)) & 63;
    if ((stage_v_44_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_69_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_69_1) + 7) & 255;
    }
    if ((stage_v_44_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_69_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_69_2) + 7) & 255;
    }
  }

  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (it_1 * 3)) + (stage_v_43_1 & 15)) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (it_2 * 3)) + (stage_v_43_2 & 15)) & 63;
    if ((stage_v_43_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_70_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_70_1) + 7) & 255;
    }
    if ((stage_v_43_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_70_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_70_2) + 7) & 255;
    }
  }

  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (it_1 * 3)) + (stage_v_53_1 & 15)) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (it_2 * 3)) + (stage_v_53_2 & 15)) & 63;
    if ((stage_v_53_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_71_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_71_1) + 7) & 255;
    }
    if ((stage_v_53_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_71_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_71_2) + 7) & 255;
    }
  }

  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (it_1 * 3)) + (stage_v_28_1 & 15)) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (it_2 * 3)) + (stage_v_28_2 & 15)) & 63;
    if ((stage_v_28_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_72_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_72_1) + 7) & 255;
    }
    if ((stage_v_28_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_72_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_72_2) + 7) & 255;
    }
  }

  int stage_v_73_1 = ((pub_r001098_22_1 * 2) + 37) & 63;
  int stage_v_73_2 = ((pub_r001098_22_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001098_8_1 * 2) + 42) & 63;
  int stage_v_74_2 = ((pub_r001098_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (it_1 * 3)) + (stage_v_5_1 & 15)) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (it_2 * 3)) + (stage_v_5_2 & 15)) & 63;
    if ((stage_v_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_75_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_75_1) + 7) & 255;
    }
    if ((stage_v_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_75_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_75_2) + 7) & 255;
    }
  }

  int stage_v_76_1 = ((pub_r001098_2_1 * 2) + 47) & 63;
  int stage_v_76_2 = ((pub_r001098_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001098_2_1 * 2) + 23) & 63;
  int stage_v_77_2 = ((pub_r001098_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (it_1 * 3)) + (sec_r001098_18_1 & 15)) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (it_2 * 3)) + (sec_r001098_18_2 & 15)) & 63;
    if ((sec_r001098_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_78_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_78_1) + 7) & 255;
    }
    if ((sec_r001098_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_78_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_78_2) + 7) & 255;
    }
  }

  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (it_1 * 3)) + (sec_r001098_16_1 & 15)) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (it_2 * 3)) + (sec_r001098_16_2 & 15)) & 63;
    if ((sec_r001098_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_79_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_79_1) + 7) & 255;
    }
    if ((sec_r001098_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_79_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_79_2) + 7) & 255;
    }
  }

  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_80_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_80_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_80_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_80_2) + 7) & 255;
    }
  }

  int stage_v_81_1 = ((pub_r001098_16_1 * 2) + 21) & 63;
  int stage_v_81_2 = ((pub_r001098_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (it_1 * 3)) + (stage_v_10_1 & 15)) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (it_2 * 3)) + (stage_v_10_2 & 15)) & 63;
    if ((stage_v_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_82_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_82_1) + 7) & 255;
    }
    if ((stage_v_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_82_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_82_2) + 7) & 255;
    }
  }

  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_83_1 = ((stage_v_83_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_83_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_83_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_83_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_83_2) + 7) & 255;
    }
  }

  int stage_v_84_1 = ((pub_r001098_17_1 * 2) + 5) & 63;
  int stage_v_84_2 = ((pub_r001098_17_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (it_1 * 3)) + (stage_v_14_1 & 15)) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (it_2 * 3)) + (stage_v_14_2 & 15)) & 63;
    if ((stage_v_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_85_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_85_1) + 7) & 255;
    }
    if ((stage_v_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_85_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_85_2) + 7) & 255;
    }
  }

  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_86_1 = ((stage_v_86_1 + (it_1 * 3)) + (stage_v_66_1 & 15)) & 63;
    stage_v_86_2 = ((stage_v_86_2 + (it_2 * 3)) + (stage_v_66_2 & 15)) & 63;
    if ((stage_v_66_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_86_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_86_1) + 7) & 255;
    }
    if ((stage_v_66_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_86_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_86_2) + 7) & 255;
    }
  }

  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (it_1 * 3)) + (sec_r001098_9_1 & 15)) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (it_2 * 3)) + (sec_r001098_9_2 & 15)) & 63;
    if ((sec_r001098_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_87_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_87_1) + 7) & 255;
    }
    if ((sec_r001098_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_87_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_87_2) + 7) & 255;
    }
  }

  int stage_v_88_1 = ((pub_r001098_8_1 * 2) + 31) & 63;
  int stage_v_88_2 = ((pub_r001098_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (it_1 * 3)) + (sec_r001098_0_1 & 15)) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (it_2 * 3)) + (sec_r001098_0_2 & 15)) & 63;
    if ((sec_r001098_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_89_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_89_1) + 7) & 255;
    }
    if ((sec_r001098_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_89_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_89_2) + 7) & 255;
    }
  }

  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_90_1 = ((stage_v_90_1 + (it_1 * 3)) + (sec_r001098_3_1 & 15)) & 63;
    stage_v_90_2 = ((stage_v_90_2 + (it_2 * 3)) + (sec_r001098_3_2 & 15)) & 63;
    if ((sec_r001098_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_90_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_90_1) + 7) & 255;
    }
    if ((sec_r001098_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_90_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_90_2) + 7) & 255;
    }
  }

  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (it_1 * 3)) + (sec_r001098_2_1 & 15)) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (it_2 * 3)) + (sec_r001098_2_2 & 15)) & 63;
    if ((sec_r001098_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_91_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_91_1) + 7) & 255;
    }
    if ((sec_r001098_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_91_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_91_2) + 7) & 255;
    }
  }

  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (it_1 * 3)) + (stage_v_66_1 & 15)) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (it_2 * 3)) + (stage_v_66_2 & 15)) & 63;
    if ((stage_v_66_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_92_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_92_1) + 7) & 255;
    }
    if ((stage_v_66_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_92_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_92_2) + 7) & 255;
    }
  }

  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_93_1 = ((stage_v_93_1 + (it_1 * 3)) + (stage_v_5_1 & 15)) & 63;
    stage_v_93_2 = ((stage_v_93_2 + (it_2 * 3)) + (stage_v_5_2 & 15)) & 63;
    if ((stage_v_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_93_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_93_1) + 7) & 255;
    }
    if ((stage_v_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_93_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_93_2) + 7) & 255;
    }
  }

  int stage_v_94_1 = ((pub_r001098_21_1 * 2) + 31) & 63;
  int stage_v_94_2 = ((pub_r001098_21_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (it_1 * 3)) + (stage_v_58_1 & 15)) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (it_2 * 3)) + (stage_v_58_2 & 15)) & 63;
    if ((stage_v_58_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_95_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_95_1) + 7) & 255;
    }
    if ((stage_v_58_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_95_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_95_2) + 7) & 255;
    }
  }

  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_96_1 = ((stage_v_96_1 + (it_1 * 3)) + (stage_v_69_1 & 15)) & 63;
    stage_v_96_2 = ((stage_v_96_2 + (it_2 * 3)) + (stage_v_69_2 & 15)) & 63;
    if ((stage_v_69_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_96_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_96_1) + 7) & 255;
    }
    if ((stage_v_69_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_96_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_96_2) + 7) & 255;
    }
  }

  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (it_1 * 3)) + (stage_v_16_1 & 15)) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (it_2 * 3)) + (stage_v_16_2 & 15)) & 63;
    if ((stage_v_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_97_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_97_1) + 7) & 255;
    }
    if ((stage_v_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_97_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_97_2) + 7) & 255;
    }
  }

  int stage_v_98_1 = ((pub_r001098_5_1 * 2) + 45) & 63;
  int stage_v_98_2 = ((pub_r001098_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (it_1 * 3)) + (stage_v_83_1 & 15)) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (it_2 * 3)) + (stage_v_83_2 & 15)) & 63;
    if ((stage_v_83_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_99_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_99_1) + 7) & 255;
    }
    if ((stage_v_83_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_99_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_99_2) + 7) & 255;
    }
  }

  int stage_v_100_1 = ((pub_r001098_12_1 * 2) + 47) & 63;
  int stage_v_100_2 = ((pub_r001098_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_101_1 = ((stage_v_101_1 + (it_1 * 3)) + (stage_v_47_1 & 15)) & 63;
    stage_v_101_2 = ((stage_v_101_2 + (it_2 * 3)) + (stage_v_47_2 & 15)) & 63;
    if ((stage_v_47_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_101_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_101_1) + 7) & 255;
    }
    if ((stage_v_47_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_101_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_101_2) + 7) & 255;
    }
  }

  int stage_v_102_1 = ((pub_r001098_15_1 * 2) + 15) & 63;
  int stage_v_102_2 = ((pub_r001098_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (it_1 * 3)) + (stage_v_93_1 & 15)) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (it_2 * 3)) + (stage_v_93_2 & 15)) & 63;
    if ((stage_v_93_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_103_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_103_1) + 7) & 255;
    }
    if ((stage_v_93_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_103_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_103_2) + 7) & 255;
    }
  }

  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_104_1 = ((stage_v_104_1 + (it_1 * 3)) + (stage_v_10_1 & 15)) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (it_2 * 3)) + (stage_v_10_2 & 15)) & 63;
    if ((stage_v_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_104_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_104_1) + 7) & 255;
    }
    if ((stage_v_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_104_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_104_2) + 7) & 255;
    }
  }

  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_105_1 = ((stage_v_105_1 + (it_1 * 3)) + (stage_v_52_1 & 15)) & 63;
    stage_v_105_2 = ((stage_v_105_2 + (it_2 * 3)) + (stage_v_52_2 & 15)) & 63;
    if ((stage_v_52_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_105_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_105_1) + 7) & 255;
    }
    if ((stage_v_52_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_105_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_105_2) + 7) & 255;
    }
  }

  int stage_v_106_1 = ((pub_r001098_8_1 * 2) + 11) & 63;
  int stage_v_106_2 = ((pub_r001098_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001098_2_1 * 2) + 50) & 63;
  int stage_v_107_2 = ((pub_r001098_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_108_1 = ((stage_v_108_1 + (it_1 * 3)) + (sec_r001098_11_1 & 15)) & 63;
    stage_v_108_2 = ((stage_v_108_2 + (it_2 * 3)) + (sec_r001098_11_2 & 15)) & 63;
    if ((sec_r001098_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_108_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_108_1) + 7) & 255;
    }
    if ((sec_r001098_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_108_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_108_2) + 7) & 255;
    }
  }

  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_109_1 = ((stage_v_109_1 + (it_1 * 3)) + (sec_r001098_16_1 & 15)) & 63;
    stage_v_109_2 = ((stage_v_109_2 + (it_2 * 3)) + (sec_r001098_16_2 & 15)) & 63;
    if ((sec_r001098_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_109_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_109_1) + 7) & 255;
    }
    if ((sec_r001098_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_109_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_109_2) + 7) & 255;
    }
  }

  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_110_1 = ((stage_v_110_1 + (it_1 * 3)) + (helper_flow_7_1 & 15)) & 63;
    stage_v_110_2 = ((stage_v_110_2 + (it_2 * 3)) + (helper_flow_7_2 & 15)) & 63;
    if ((helper_flow_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_110_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_110_1) + 7) & 255;
    }
    if ((helper_flow_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_110_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_110_2) + 7) & 255;
    }
  }

  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (it_1 * 3)) + (sec_r001098_8_1 & 15)) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (it_2 * 3)) + (sec_r001098_8_2 & 15)) & 63;
    if ((sec_r001098_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_111_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_111_1) + 7) & 255;
    }
    if ((sec_r001098_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_111_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_111_2) + 7) & 255;
    }
  }

  int stage_v_112_1 = ((pub_r001098_4_1 * 2) + 39) & 63;
  int stage_v_112_2 = ((pub_r001098_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_113_1 = ((stage_v_113_1 + (it_1 * 3)) + (stage_v_68_1 & 15)) & 63;
    stage_v_113_2 = ((stage_v_113_2 + (it_2 * 3)) + (stage_v_68_2 & 15)) & 63;
    if ((stage_v_68_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_113_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_113_1) + 7) & 255;
    }
    if ((stage_v_68_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_113_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_113_2) + 7) & 255;
    }
  }

  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (it_1 * 3)) + (stage_v_109_1 & 15)) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (it_2 * 3)) + (stage_v_109_2 & 15)) & 63;
    if ((stage_v_109_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_114_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_114_1) + 7) & 255;
    }
    if ((stage_v_109_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_114_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_114_2) + 7) & 255;
    }
  }

  int stage_v_115_1 = ((pub_r001098_6_1 * 2) + 7) & 63;
  int stage_v_115_2 = ((pub_r001098_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_116_1 = ((stage_v_116_1 + (it_1 * 3)) + (sec_r001098_12_1 & 15)) & 63;
    stage_v_116_2 = ((stage_v_116_2 + (it_2 * 3)) + (sec_r001098_12_2 & 15)) & 63;
    if ((sec_r001098_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_116_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_116_1) + 7) & 255;
    }
    if ((sec_r001098_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_116_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_116_2) + 7) & 255;
    }
  }

  int stage_v_117_1 = ((pub_r001098_13_1 * 2) + 31) & 63;
  int stage_v_117_2 = ((pub_r001098_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (it_1 * 3)) + (stage_v_96_1 & 15)) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (it_2 * 3)) + (stage_v_96_2 & 15)) & 63;
    if ((stage_v_96_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_118_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_118_1) + 7) & 255;
    }
    if ((stage_v_96_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_118_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_118_2) + 7) & 255;
    }
  }

  int stage_v_119_1 = ((pub_r001098_20_1 * 2) + 26) & 63;
  int stage_v_119_2 = ((pub_r001098_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_120_1 = ((stage_v_120_1 + (it_1 * 3)) + (stage_v_109_1 & 15)) & 63;
    stage_v_120_2 = ((stage_v_120_2 + (it_2 * 3)) + (stage_v_109_2 & 15)) & 63;
    if ((stage_v_109_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_120_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_120_1) + 7) & 255;
    }
    if ((stage_v_109_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_120_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_120_2) + 7) & 255;
    }
  }

  int stage_v_121_1 = ((pub_r001098_21_1 * 2) + 46) & 63;
  int stage_v_121_2 = ((pub_r001098_21_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001098_16_1 * 2) + 8) & 63;
  int stage_v_122_2 = ((pub_r001098_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001098_8_1 * 2) + 10) & 63;
  int stage_v_123_2 = ((pub_r001098_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_124_1 = ((stage_v_124_1 + (it_1 * 3)) + (stage_v_55_1 & 15)) & 63;
    stage_v_124_2 = ((stage_v_124_2 + (it_2 * 3)) + (stage_v_55_2 & 15)) & 63;
    if ((stage_v_55_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_124_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_124_1) + 7) & 255;
    }
    if ((stage_v_55_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_124_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_124_2) + 7) & 255;
    }
  }

  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (it_1 * 3)) + (sec_r001098_23_1 & 15)) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (it_2 * 3)) + (sec_r001098_23_2 & 15)) & 63;
    if ((sec_r001098_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_125_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_125_1) + 7) & 255;
    }
    if ((sec_r001098_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_125_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_125_2) + 7) & 255;
    }
  }

  int stage_v_126_1 = ((pub_r001098_4_1 * 2) + 44) & 63;
  int stage_v_126_2 = ((pub_r001098_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (it_1 * 3)) + (stage_v_79_1 & 15)) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (it_2 * 3)) + (stage_v_79_2 & 15)) & 63;
    if ((stage_v_79_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_127_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_127_1) + 7) & 255;
    }
    if ((stage_v_79_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_127_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_127_2) + 7) & 255;
    }
  }

  int stage_v_128_1 = ((pub_r001098_3_1 * 2) + 22) & 63;
  int stage_v_128_2 = ((pub_r001098_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (it_1 * 3)) + (sec_r001098_5_1 & 15)) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (it_2 * 3)) + (sec_r001098_5_2 & 15)) & 63;
    if ((sec_r001098_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_129_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_129_1) + 7) & 255;
    }
    if ((sec_r001098_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_129_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_129_2) + 7) & 255;
    }
  }

  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_130_1 = ((stage_v_130_1 + (it_1 * 3)) + (sec_r001098_2_1 & 15)) & 63;
    stage_v_130_2 = ((stage_v_130_2 + (it_2 * 3)) + (sec_r001098_2_2 & 15)) & 63;
    if ((sec_r001098_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_130_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_130_1) + 7) & 255;
    }
    if ((sec_r001098_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_130_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_130_2) + 7) & 255;
    }
  }

  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (it_1 * 3)) + (sec_r001098_8_1 & 15)) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (it_2 * 3)) + (sec_r001098_8_2 & 15)) & 63;
    if ((sec_r001098_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_131_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_131_1) + 7) & 255;
    }
    if ((sec_r001098_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_131_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_131_2) + 7) & 255;
    }
  }

  int stage_v_132_1 = ((pub_r001098_16_1 * 2) + 14) & 63;
  int stage_v_132_2 = ((pub_r001098_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (it_1 * 3)) + (stage_v_89_1 & 15)) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (it_2 * 3)) + (stage_v_89_2 & 15)) & 63;
    if ((stage_v_89_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_133_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_133_1) + 7) & 255;
    }
    if ((stage_v_89_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_133_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_133_2) + 7) & 255;
    }
  }

  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_134_1 = ((stage_v_134_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_134_2 = ((stage_v_134_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_134_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_134_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_134_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_134_2) + 7) & 255;
    }
  }

  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_135_1 = ((stage_v_135_1 + (it_1 * 3)) + (stage_v_75_1 & 15)) & 63;
    stage_v_135_2 = ((stage_v_135_2 + (it_2 * 3)) + (stage_v_75_2 & 15)) & 63;
    if ((stage_v_75_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_135_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_135_1) + 7) & 255;
    }
    if ((stage_v_75_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_135_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_135_2) + 7) & 255;
    }
  }

  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_136_1 = ((stage_v_136_1 + (it_1 * 3)) + (sec_r001098_14_1 & 15)) & 63;
    stage_v_136_2 = ((stage_v_136_2 + (it_2 * 3)) + (sec_r001098_14_2 & 15)) & 63;
    if ((sec_r001098_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_136_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_136_1) + 7) & 255;
    }
    if ((sec_r001098_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_136_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_136_2) + 7) & 255;
    }
  }

  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_137_1 = ((stage_v_137_1 + (it_1 * 3)) + (stage_v_79_1 & 15)) & 63;
    stage_v_137_2 = ((stage_v_137_2 + (it_2 * 3)) + (stage_v_79_2 & 15)) & 63;
    if ((stage_v_79_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_137_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_137_1) + 7) & 255;
    }
    if ((stage_v_79_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_137_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_137_2) + 7) & 255;
    }
  }

  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (it_1 * 3)) + (stage_v_24_1 & 15)) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (it_2 * 3)) + (stage_v_24_2 & 15)) & 63;
    if ((stage_v_24_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_138_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_138_1) + 7) & 255;
    }
    if ((stage_v_24_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_138_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_138_2) + 7) & 255;
    }
  }

  int stage_v_139_1 = ((pub_r001098_12_1 * 2) + 33) & 63;
  int stage_v_139_2 = ((pub_r001098_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (it_1 * 3)) + (stage_v_95_1 & 15)) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (it_2 * 3)) + (stage_v_95_2 & 15)) & 63;
    if ((stage_v_95_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_140_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_140_1) + 7) & 255;
    }
    if ((stage_v_95_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_140_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_140_2) + 7) & 255;
    }
  }

  int stage_v_141_1 = ((pub_r001098_7_1 * 2) + 21) & 63;
  int stage_v_141_2 = ((pub_r001098_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001098_12_1 * 2) + 28) & 63;
  int stage_v_142_2 = ((pub_r001098_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (it_1 * 3)) + (stage_v_97_1 & 15)) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (it_2 * 3)) + (stage_v_97_2 & 15)) & 63;
    if ((stage_v_97_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_143_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_143_1) + 7) & 255;
    }
    if ((stage_v_97_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_143_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_143_2) + 7) & 255;
    }
  }

  int stage_v_144_1 = ((pub_r001098_3_1 * 2) + 32) & 63;
  int stage_v_144_2 = ((pub_r001098_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001098_7_1 * 2) + 42) & 63;
  int stage_v_145_2 = ((pub_r001098_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001098_19_1 * 2) + 24) & 63;
  int stage_v_146_2 = ((pub_r001098_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001098_2_1 * 2) + 31) & 63;
  int stage_v_147_2 = ((pub_r001098_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_148_1 = ((stage_v_148_1 + (it_1 * 3)) + (stage_v_45_1 & 15)) & 63;
    stage_v_148_2 = ((stage_v_148_2 + (it_2 * 3)) + (stage_v_45_2 & 15)) & 63;
    if ((stage_v_45_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_148_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_148_1) + 7) & 255;
    }
    if ((stage_v_45_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_148_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_148_2) + 7) & 255;
    }
  }

  int stage_v_149_1 = ((pub_r001098_21_1 * 2) + 41) & 63;
  int stage_v_149_2 = ((pub_r001098_21_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_150_1 = ((stage_v_150_1 + (it_1 * 3)) + (sec_r001098_13_1 & 15)) & 63;
    stage_v_150_2 = ((stage_v_150_2 + (it_2 * 3)) + (sec_r001098_13_2 & 15)) & 63;
    if ((sec_r001098_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_150_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_150_1) + 7) & 255;
    }
    if ((sec_r001098_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_150_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_150_2) + 7) & 255;
    }
  }

  int stage_v_151_1 = ((pub_r001098_17_1 * 2) + 5) & 63;
  int stage_v_151_2 = ((pub_r001098_17_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001098_22_1 * 2) + 7) & 63;
  int stage_v_152_2 = ((pub_r001098_22_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001098_0_1 * 2) + 12) & 63;
  int stage_v_153_2 = ((pub_r001098_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001098_2_1 * 2) + 31) & 63;
  int stage_v_154_2 = ((pub_r001098_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (it_1 * 3)) + (stage_v_116_1 & 15)) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (it_2 * 3)) + (stage_v_116_2 & 15)) & 63;
    if ((stage_v_116_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_155_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_155_1) + 7) & 255;
    }
    if ((stage_v_116_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_155_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_155_2) + 7) & 255;
    }
  }

  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_156_1 = ((stage_v_156_1 + (it_1 * 3)) + (stage_v_68_1 & 15)) & 63;
    stage_v_156_2 = ((stage_v_156_2 + (it_2 * 3)) + (stage_v_68_2 & 15)) & 63;
    if ((stage_v_68_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_156_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_156_1) + 7) & 255;
    }
    if ((stage_v_68_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_156_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_156_2) + 7) & 255;
    }
  }

  int stage_v_157_1 = ((pub_r001098_21_1 * 2) + 8) & 63;
  int stage_v_157_2 = ((pub_r001098_21_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001098_13_1 * 2) + 36) & 63;
  int stage_v_158_2 = ((pub_r001098_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001098_1_1 * 2) + 10) & 63;
  int stage_v_159_2 = ((pub_r001098_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (it_1 * 3)) + (stage_v_71_1 & 15)) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (it_2 * 3)) + (stage_v_71_2 & 15)) & 63;
    if ((stage_v_71_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_160_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_160_1) + 7) & 255;
    }
    if ((stage_v_71_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_160_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_160_2) + 7) & 255;
    }
  }

  int stage_v_161_1 = ((pub_r001098_13_1 * 2) + 16) & 63;
  int stage_v_161_2 = ((pub_r001098_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001098_9_1 * 2) + 34) & 63;
  int stage_v_162_2 = ((pub_r001098_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001098_12_1 * 2) + 30) & 63;
  int stage_v_163_2 = ((pub_r001098_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_164_1 = ((stage_v_164_1 + (it_1 * 3)) + (stage_v_63_1 & 15)) & 63;
    stage_v_164_2 = ((stage_v_164_2 + (it_2 * 3)) + (stage_v_63_2 & 15)) & 63;
    if ((stage_v_63_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_164_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_164_1) + 7) & 255;
    }
    if ((stage_v_63_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_164_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_164_2) + 7) & 255;
    }
  }

  int stage_v_165_1 = ((pub_r001098_18_1 * 2) + 23) & 63;
  int stage_v_165_2 = ((pub_r001098_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001098_1_1 * 2) + 17) & 63;
  int stage_v_166_2 = ((pub_r001098_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_167_1 = ((stage_v_167_1 + (it_1 * 3)) + (sec_r001098_21_1 & 15)) & 63;
    stage_v_167_2 = ((stage_v_167_2 + (it_2 * 3)) + (sec_r001098_21_2 & 15)) & 63;
    if ((sec_r001098_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_167_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_167_1) + 7) & 255;
    }
    if ((sec_r001098_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_167_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_167_2) + 7) & 255;
    }
  }

  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_168_1 = ((stage_v_168_1 + (it_1 * 3)) + (sec_r001098_9_1 & 15)) & 63;
    stage_v_168_2 = ((stage_v_168_2 + (it_2 * 3)) + (sec_r001098_9_2 & 15)) & 63;
    if ((sec_r001098_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_168_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_168_1) + 7) & 255;
    }
    if ((sec_r001098_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_168_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_168_2) + 7) & 255;
    }
  }

  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_169_1 = ((stage_v_169_1 + (it_1 * 3)) + (sec_r001098_4_1 & 15)) & 63;
    stage_v_169_2 = ((stage_v_169_2 + (it_2 * 3)) + (sec_r001098_4_2 & 15)) & 63;
    if ((sec_r001098_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_169_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_169_1) + 7) & 255;
    }
    if ((sec_r001098_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_169_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_169_2) + 7) & 255;
    }
  }

  int stage_v_170_1 = ((pub_r001098_7_1 * 2) + 25) & 63;
  int stage_v_170_2 = ((pub_r001098_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001098_10_1 * 2) + 42) & 63;
  int stage_v_171_2 = ((pub_r001098_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_172_1 = ((stage_v_172_1 + (it_1 * 3)) + (stage_v_156_1 & 15)) & 63;
    stage_v_172_2 = ((stage_v_172_2 + (it_2 * 3)) + (stage_v_156_2 & 15)) & 63;
    if ((stage_v_156_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_172_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_172_1) + 7) & 255;
    }
    if ((stage_v_156_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_172_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_172_2) + 7) & 255;
    }
  }

  int stage_v_173_1 = ((pub_r001098_11_1 * 2) + 18) & 63;
  int stage_v_173_2 = ((pub_r001098_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001098_6_1 * 2) + 12) & 63;
  int stage_v_174_2 = ((pub_r001098_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_175_1 = ((stage_v_175_1 + (it_1 * 3)) + (stage_v_78_1 & 15)) & 63;
    stage_v_175_2 = ((stage_v_175_2 + (it_2 * 3)) + (stage_v_78_2 & 15)) & 63;
    if ((stage_v_78_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_175_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_175_1) + 7) & 255;
    }
    if ((stage_v_78_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_175_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_175_2) + 7) & 255;
    }
  }

  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_176_1 = ((stage_v_176_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_176_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_176_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_176_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_176_2) + 7) & 255;
    }
  }

  int stage_v_177_1 = 0;
  int stage_v_177_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_177_1 = ((stage_v_177_1 + (it_1 * 3)) + (stage_v_78_1 & 15)) & 63;
    stage_v_177_2 = ((stage_v_177_2 + (it_2 * 3)) + (stage_v_78_2 & 15)) & 63;
    if ((stage_v_78_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_177_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_177_1) + 7) & 255;
    }
    if ((stage_v_78_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_177_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_177_2) + 7) & 255;
    }
  }

  int stage_v_178_1 = ((pub_r001098_5_1 * 2) + 13) & 63;
  int stage_v_178_2 = ((pub_r001098_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001098_1_1 * 2) + 30) & 63;
  int stage_v_179_2 = ((pub_r001098_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = 0;
  int stage_v_180_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_180_1 = ((stage_v_180_1 + (it_1 * 3)) + (stage_v_108_1 & 15)) & 63;
    stage_v_180_2 = ((stage_v_180_2 + (it_2 * 3)) + (stage_v_108_2 & 15)) & 63;
    if ((stage_v_108_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_180_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_180_1) + 7) & 255;
    }
    if ((stage_v_108_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_180_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_180_2) + 7) & 255;
    }
  }

  int stage_v_181_1 = 0;
  int stage_v_181_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_181_1 = ((stage_v_181_1 + (it_1 * 3)) + (stage_v_60_1 & 15)) & 63;
    stage_v_181_2 = ((stage_v_181_2 + (it_2 * 3)) + (stage_v_60_2 & 15)) & 63;
    if ((stage_v_60_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_181_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_181_1) + 7) & 255;
    }
    if ((stage_v_60_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_181_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_181_2) + 7) & 255;
    }
  }

  int stage_v_182_1 = 0;
  int stage_v_182_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_182_1 = ((stage_v_182_1 + (it_1 * 3)) + (sec_r001098_19_1 & 15)) & 63;
    stage_v_182_2 = ((stage_v_182_2 + (it_2 * 3)) + (sec_r001098_19_2 & 15)) & 63;
    if ((sec_r001098_19_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_182_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_182_1) + 7) & 255;
    }
    if ((sec_r001098_19_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_182_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_182_2) + 7) & 255;
    }
  }

  int stage_v_183_1 = 0;
  int stage_v_183_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_183_1 = ((stage_v_183_1 + (it_1 * 3)) + (stage_v_99_1 & 15)) & 63;
    stage_v_183_2 = ((stage_v_183_2 + (it_2 * 3)) + (stage_v_99_2 & 15)) & 63;
    if ((stage_v_99_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_183_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_183_1) + 7) & 255;
    }
    if ((stage_v_99_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_183_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_183_2) + 7) & 255;
    }
  }

  int stage_v_184_1 = 0;
  int stage_v_184_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_184_1 = ((stage_v_184_1 + (it_1 * 3)) + (stage_v_148_1 & 15)) & 63;
    stage_v_184_2 = ((stage_v_184_2 + (it_2 * 3)) + (stage_v_148_2 & 15)) & 63;
    if ((stage_v_148_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_184_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_184_1) + 7) & 255;
    }
    if ((stage_v_148_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_184_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_184_2) + 7) & 255;
    }
  }

  int stage_v_185_1 = 0;
  int stage_v_185_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_185_1 = ((stage_v_185_1 + (it_1 * 3)) + (stage_v_109_1 & 15)) & 63;
    stage_v_185_2 = ((stage_v_185_2 + (it_2 * 3)) + (stage_v_109_2 & 15)) & 63;
    if ((stage_v_109_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_185_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_185_1) + 7) & 255;
    }
    if ((stage_v_109_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_185_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_185_2) + 7) & 255;
    }
  }

  int stage_v_186_1 = 0;
  int stage_v_186_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_186_1 = ((stage_v_186_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_186_2 = ((stage_v_186_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_186_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_186_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_186_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_186_2) + 7) & 255;
    }
  }

  int stage_v_187_1 = ((pub_r001098_2_1 * 2) + 31) & 63;
  int stage_v_187_2 = ((pub_r001098_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = 0;
  int stage_v_188_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_188_1 = ((stage_v_188_1 + (it_1 * 3)) + (stage_v_20_1 & 15)) & 63;
    stage_v_188_2 = ((stage_v_188_2 + (it_2 * 3)) + (stage_v_20_2 & 15)) & 63;
    if ((stage_v_20_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_188_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_188_1) + 7) & 255;
    }
    if ((stage_v_20_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_188_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_188_2) + 7) & 255;
    }
  }

  int stage_v_189_1 = 0;
  int stage_v_189_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_189_1 = ((stage_v_189_1 + (it_1 * 3)) + (stage_v_65_1 & 15)) & 63;
    stage_v_189_2 = ((stage_v_189_2 + (it_2 * 3)) + (stage_v_65_2 & 15)) & 63;
    if ((stage_v_65_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_189_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_189_1) + 7) & 255;
    }
    if ((stage_v_65_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_189_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_189_2) + 7) & 255;
    }
  }

  int stage_v_190_1 = 0;
  int stage_v_190_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_190_1 = ((stage_v_190_1 + (it_1 * 3)) + (sec_r001098_9_1 & 15)) & 63;
    stage_v_190_2 = ((stage_v_190_2 + (it_2 * 3)) + (sec_r001098_9_2 & 15)) & 63;
    if ((sec_r001098_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_190_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_190_1) + 7) & 255;
    }
    if ((sec_r001098_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_190_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_190_2) + 7) & 255;
    }
  }

  int stage_v_191_1 = ((pub_r001098_0_1 * 2) + 26) & 63;
  int stage_v_191_2 = ((pub_r001098_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = 0;
  int stage_v_192_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_192_1 = ((stage_v_192_1 + (it_1 * 3)) + (sec_r001098_18_1 & 15)) & 63;
    stage_v_192_2 = ((stage_v_192_2 + (it_2 * 3)) + (sec_r001098_18_2 & 15)) & 63;
    if ((sec_r001098_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_192_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_192_1) + 7) & 255;
    }
    if ((sec_r001098_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_192_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_192_2) + 7) & 255;
    }
  }

  int stage_v_193_1 = 0;
  int stage_v_193_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_193_1 = ((stage_v_193_1 + (it_1 * 3)) + (stage_v_71_1 & 15)) & 63;
    stage_v_193_2 = ((stage_v_193_2 + (it_2 * 3)) + (stage_v_71_2 & 15)) & 63;
    if ((stage_v_71_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_193_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_193_1) + 7) & 255;
    }
    if ((stage_v_71_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_193_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_193_2) + 7) & 255;
    }
  }

  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001098_5_1 != sec_r001098_5_2);
  __CPROVER_assume(sec_r001098_17_1 != sec_r001098_17_2);
  __CPROVER_assume(sec_r001098_3_1 != sec_r001098_3_2);
  __CPROVER_assume(pub_r001098_5_1 == pub_r001098_5_2);
  __CPROVER_assume(pub_r001098_20_1 == pub_r001098_20_2);
  __CPROVER_assume(pub_r001098_9_1 == pub_r001098_9_2);
  __CPROVER_assume(pub_r001098_11_1 == pub_r001098_11_2);
  __CPROVER_assume(sec_r001098_19_1 != sec_r001098_19_2);
  __CPROVER_assume(pub_r001098_2_1 == pub_r001098_2_2);
  __CPROVER_assume(pub_r001098_10_1 == pub_r001098_10_2);
  __CPROVER_assume(pub_r001098_19_1 == pub_r001098_19_2);
  __CPROVER_assume(sec_r001098_22_1 != sec_r001098_22_2);
  __CPROVER_assume(pub_r001098_18_1 == pub_r001098_18_2);
  __CPROVER_assume(pub_r001098_6_1 == pub_r001098_6_2);
  __CPROVER_assume(pub_r001098_17_1 == pub_r001098_17_2);
  __CPROVER_assume(pub_r001098_21_1 == pub_r001098_21_2);
  __CPROVER_assume(sec_r001098_20_1 != sec_r001098_20_2);
  __CPROVER_assume(sec_r001098_18_1 != sec_r001098_18_2);
  __CPROVER_assume(sec_r001098_9_1 != sec_r001098_9_2);
  __CPROVER_assume(sec_r001098_21_1 != sec_r001098_21_2);
  __CPROVER_assume(sec_r001098_13_1 != sec_r001098_13_2);
  __CPROVER_assume(sec_r001098_16_1 != sec_r001098_16_2);
  __CPROVER_assume(pub_r001098_15_1 == pub_r001098_15_2);
  __CPROVER_assume(sec_r001098_6_1 != sec_r001098_6_2);
  __CPROVER_assume(sec_r001098_23_1 != sec_r001098_23_2);
  __CPROVER_assume(sec_r001098_11_1 != sec_r001098_11_2);
  __CPROVER_assume(pub_r001098_13_1 == pub_r001098_13_2);
  __CPROVER_assume(sec_r001098_15_1 != sec_r001098_15_2);
  __CPROVER_assume(pub_r001098_7_1 == pub_r001098_7_2);
  __CPROVER_assume(sec_r001098_4_1 != sec_r001098_4_2);
  __CPROVER_assume(sec_r001098_7_1 != sec_r001098_7_2);
  __CPROVER_assume(sec_r001098_10_1 != sec_r001098_10_2);
  __CPROVER_assume(pub_r001098_1_1 == pub_r001098_1_2);
  __CPROVER_assume(sec_r001098_8_1 != sec_r001098_8_2);
  __CPROVER_assume(sec_r001098_14_1 != sec_r001098_14_2);
  __CPROVER_assume(sec_r001098_0_1 != sec_r001098_0_2);
  __CPROVER_assume(pub_r001098_12_1 == pub_r001098_12_2);
  __CPROVER_assume(pub_r001098_14_1 == pub_r001098_14_2);
  __CPROVER_assume(pub_r001098_0_1 == pub_r001098_0_2);
  __CPROVER_assume(pub_r001098_3_1 == pub_r001098_3_2);
  __CPROVER_assume(pub_r001098_8_1 == pub_r001098_8_2);
  __CPROVER_assume(sec_r001098_1_1 != sec_r001098_1_2);
  __CPROVER_assume(pub_r001098_22_1 == pub_r001098_22_2);
  __CPROVER_assume(pub_r001098_16_1 == pub_r001098_16_2);
  __CPROVER_assume(pub_r001098_4_1 == pub_r001098_4_2);
  __CPROVER_assume(sec_r001098_2_1 != sec_r001098_2_2);
  __CPROVER_assume(sec_r001098_12_1 != sec_r001098_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.offset == st_var_2_2.offset);
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
  assert(helper_flow_7_1 == helper_flow_7_2);
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
}


