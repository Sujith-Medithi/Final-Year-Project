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
struct EventLog_R000767_6713_0
{
  unsigned char signature;
  unsigned char facility;
  unsigned char severity;
  int buffer[3];
};
struct StreamBuffer_R000767_6713_1
{
  short capacity;
  unsigned char watermark;
  unsigned char state;
  int buffer[3];
};
struct FilterState_R000767_6713_2
{
  short prev_in;
  int damping;
  int mode;
  int cutoff;
  int buffer[3];
};
struct CipherContext_R000767_6713_3
{
  int flags;
  unsigned char tag;
  int iv;
  short round_key;
  int buffer[3];
};
union RegisterBank_R000767_6713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000767_6713_1
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
void fn_R000767_6713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000767_6713_3 st_1 = {0};
  struct CipherContext_R000767_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int margin_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_60_1)
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

  switch (margin_60_2)
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

  int scale_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_37_1) & 63;
  aux_2 = (aux_2 + scale_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_48_1 = local_arr_1[aux_1 % 3];
  int offset_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_48_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_60_1 == margin_60_2);
  assert(scale_37_1 == scale_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_48_1 == offset_48_2);
}

int fn_R000767_6713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000767_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int margin_60 = (aux + st.buffer[1]) & 3;
  switch (margin_60)
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

  int scale_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_37) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_48 = local_arr[aux % 3];
  acc = (acc + (offset_48 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000767_6713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000767_6713_3 st_1 = {0};
  struct CipherContext_R000767_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int quantum_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_12_1) & 63;
  aux_2 = (aux_2 + quantum_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_25_1 = local_arr_1[aux_1 % 3];
  int coefficient_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_25_2 * 2)) & 127;
  int parity_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_58_1 > 34)
  {
    acc_1 = ((acc_1 + (parity_58_1 * 2)) + 5) & 127;
    aux_1 ^= parity_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_58_2 > 34)
  {
    acc_2 = ((acc_2 + (parity_58_2 * 2)) + 5) & 127;
    aux_2 ^= parity_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_12_1 == quantum_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_25_1 == coefficient_25_2);
  assert(parity_58_1 == parity_58_2);
}

int fn_R000767_6713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000767_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int quantum_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_12) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_25 = local_arr[aux % 3];
  acc = (acc + (coefficient_25 * 2)) & 127;
  int parity_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_58 > 34)
  {
    acc = ((acc + (parity_58 * 2)) + 5) & 127;
    aux ^= parity_58 & 15;
  }
  else
  {
    acc = ((acc - parity_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000767_6713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000767_6713_1 st_1 = {0};
  struct StreamBuffer_R000767_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_13_1 > 38)
  {
    acc_1 = ((acc_1 + (accumulator_13_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_13_2 > 38)
  {
    acc_2 = ((acc_2 + (accumulator_13_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_17_1)
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

  switch (coefficient_17_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_13_1 == accumulator_13_2);
  assert(coefficient_17_1 == coefficient_17_2);
}

int fn_R000767_6713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000767_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_13 > 38)
  {
    acc = ((acc + (accumulator_13 * 2)) + 5) & 127;
    aux ^= accumulator_13 & 15;
  }
  else
  {
    acc = ((acc - accumulator_13) + 11) & 127;
    aux += 3;
  }
  int coefficient_17 = (aux + st.buffer[1]) & 3;
  switch (coefficient_17)
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

void fn_R000767_6713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st_1 = {0};
  struct EventLog_R000767_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_69_1) & 63;
  aux_2 = (aux_2 + threshold_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_59_1)
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

  switch (window_59_2)
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

  int segment_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_61_1 > 19)
  {
    acc_1 = ((acc_1 + (segment_61_1 * 2)) + 5) & 127;
    aux_1 ^= segment_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_61_2 > 19)
  {
    acc_2 = ((acc_2 + (segment_61_2 * 2)) + 5) & 127;
    aux_2 ^= segment_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_61_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_69_1 == threshold_69_2);
  assert(window_59_1 == window_59_2);
  assert(segment_61_1 == segment_61_2);
}

int fn_R000767_6713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_69) & 63;
  acc ^= aux;
  int window_59 = (aux + st.buffer[1]) & 3;
  switch (window_59)
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

  int segment_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_61 > 19)
  {
    acc = ((acc + (segment_61 * 2)) + 5) & 127;
    aux ^= segment_61 & 15;
  }
  else
  {
    acc = ((acc - segment_61) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000767_6713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st_1 = {0};
  struct EventLog_R000767_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int segment_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_60_1)
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

  switch (segment_60_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_33_1 = local_arr_1[aux_1 % 3];
  int sample_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_33_2 * 2)) & 127;
  int window_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_76_1) & 63;
  aux_2 = (aux_2 + window_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_60_1 == segment_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_33_1 == sample_33_2);
  assert(window_76_1 == window_76_2);
}

int fn_R000767_6713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int segment_60 = (aux + st.buffer[1]) & 3;
  switch (segment_60)
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

  int local_arr[3] = {4, 9, 15};
  int sample_33 = local_arr[aux % 3];
  acc = (acc + (sample_33 * 2)) & 127;
  int window_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_76) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000767_6713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st_1 = {0};
  struct FilterState_R000767_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_20_1) & 63;
  aux_2 = (aux_2 + anchor_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_36_1)
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

  switch (window_36_2)
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

  int index_reg_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_59_1 > 20)
  {
    acc_1 = ((acc_1 + (index_reg_59_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_59_2 > 20)
  {
    acc_2 = ((acc_2 + (index_reg_59_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_20_1 == anchor_20_2);
  assert(window_36_1 == window_36_2);
  assert(index_reg_59_1 == index_reg_59_2);
}

int fn_R000767_6713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_20) & 63;
  acc ^= aux;
  int window_36 = (aux + st.buffer[1]) & 3;
  switch (window_36)
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

  int index_reg_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_59 > 20)
  {
    acc = ((acc + (index_reg_59 * 2)) + 5) & 127;
    aux ^= index_reg_59 & 15;
  }
  else
  {
    acc = ((acc - index_reg_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000767_6713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st_1 = {0};
  struct EventLog_R000767_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int anchor_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_21_1) & 63;
  aux_2 = (aux_2 + anchor_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_21_1 == anchor_21_2);
}

int fn_R000767_6713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int anchor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_21) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000767_6713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st_1 = {0};
  struct EventLog_R000767_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_58_1 > 27)
  {
    acc_1 = ((acc_1 + (residue_58_1 * 2)) + 5) & 127;
    aux_1 ^= residue_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_58_2 > 27)
  {
    acc_2 = ((acc_2 + (residue_58_2 * 2)) + 5) & 127;
    aux_2 ^= residue_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_93_1) & 63;
  aux_2 = (aux_2 + index_reg_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_58_1 == residue_58_2);
  assert(index_reg_93_1 == index_reg_93_2);
}

int fn_R000767_6713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_58 > 27)
  {
    acc = ((acc + (residue_58 * 2)) + 5) & 127;
    aux ^= residue_58 & 15;
  }
  else
  {
    acc = ((acc - residue_58) + 11) & 127;
    aux += 3;
  }
  int index_reg_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_93) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000767_6713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st_1 = {0};
  struct FilterState_R000767_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int stride_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_47_1)
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

  switch (stride_47_2)
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

  int weight_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_53_1) & 63;
  aux_2 = (aux_2 + weight_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_17_1 = local_arr_1[aux_1 % 3];
  int weight_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_17_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_47_1 == stride_47_2);
  assert(weight_53_1 == weight_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_17_1 == weight_17_2);
}

int fn_R000767_6713_8(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int stride_47 = (aux + st.buffer[1]) & 3;
  switch (stride_47)
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

  int weight_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_53) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_17 = local_arr[aux % 3];
  acc = (acc + (weight_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000767_6713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st_1 = {0};
  struct FilterState_R000767_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int delta_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_97_1 > 16)
  {
    acc_1 = ((acc_1 + (delta_97_1 * 2)) + 5) & 127;
    aux_1 ^= delta_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_97_2 > 16)
  {
    acc_2 = ((acc_2 + (delta_97_2 * 2)) + 5) & 127;
    aux_2 ^= delta_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_97_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_41_1) & 63;
  aux_2 = (aux_2 + mask_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_97_1 == delta_97_2);
  assert(mask_41_1 == mask_41_2);
}

int fn_R000767_6713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int delta_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_97 > 16)
  {
    acc = ((acc + (delta_97 * 2)) + 5) & 127;
    aux ^= delta_97 & 15;
  }
  else
  {
    acc = ((acc - delta_97) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_41) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000767_6713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000767_6713_1 st_1 = {0};
  struct StreamBuffer_R000767_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int weight_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_44_1)
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

  switch (weight_44_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_42_1 > 39)
  {
    acc_1 = ((acc_1 + (checksum_42_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_42_2 > 39)
  {
    acc_2 = ((acc_2 + (checksum_42_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_57_1) & 63;
  aux_2 = (aux_2 + factor_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_44_1 == weight_44_2);
  assert(checksum_42_1 == checksum_42_2);
  assert(factor_57_1 == factor_57_2);
}

int fn_R000767_6713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000767_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int weight_44 = (aux + st.buffer[1]) & 3;
  switch (weight_44)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_42 > 39)
  {
    acc = ((acc + (checksum_42 * 2)) + 5) & 127;
    aux ^= checksum_42 & 15;
  }
  else
  {
    acc = ((acc - checksum_42) + 11) & 127;
    aux += 3;
  }
  int factor_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000767_6713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st_1 = {0};
  struct EventLog_R000767_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int margin_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_45_1 > 33)
  {
    acc_1 = ((acc_1 + (margin_45_1 * 2)) + 5) & 127;
    aux_1 ^= margin_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_45_2 > 33)
  {
    acc_2 = ((acc_2 + (margin_45_2 * 2)) + 5) & 127;
    aux_2 ^= margin_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_50_1 = local_arr_1[aux_1 % 3];
  int mask_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_50_2 * 2)) & 127;
  int sample_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_59_1)
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

  switch (sample_59_2)
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

  int tally_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_82_1) & 63;
  aux_2 = (aux_2 + tally_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_45_1 == margin_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_50_1 == mask_50_2);
  assert(sample_59_1 == sample_59_2);
  assert(tally_82_1 == tally_82_2);
}

int fn_R000767_6713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int margin_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_45 > 33)
  {
    acc = ((acc + (margin_45 * 2)) + 5) & 127;
    aux ^= margin_45 & 15;
  }
  else
  {
    acc = ((acc - margin_45) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_50 = local_arr[aux % 3];
  acc = (acc + (mask_50 * 2)) & 127;
  int sample_59 = (aux + st.buffer[1]) & 3;
  switch (sample_59)
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

  int tally_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000767_6713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000767_6713_1 st_1 = {0};
  struct StreamBuffer_R000767_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_23_1) & 63;
  aux_2 = (aux_2 + delta_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_85_1)
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

  switch (threshold_85_2)
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
  int mask_10_1 = local_arr_1[aux_1 % 3];
  int mask_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_23_1 == delta_23_2);
  assert(threshold_85_1 == threshold_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_10_1 == mask_10_2);
}

int fn_R000767_6713_12(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000767_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_23) & 63;
  acc ^= aux;
  int threshold_85 = (aux + st.buffer[1]) & 3;
  switch (threshold_85)
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
  int mask_10 = local_arr[aux % 3];
  acc = (acc + (mask_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000767_6713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st_1 = {0};
  struct EventLog_R000767_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int window_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_86_1) & 63;
  aux_2 = (aux_2 + window_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_87_1 > 46)
  {
    acc_1 = ((acc_1 + (damping_87_1 * 2)) + 5) & 127;
    aux_1 ^= damping_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_87_2 > 46)
  {
    acc_2 = ((acc_2 + (damping_87_2 * 2)) + 5) & 127;
    aux_2 ^= damping_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_87_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_70_1 = local_arr_1[aux_1 % 3];
  int checksum_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_86_1 == window_86_2);
  assert(damping_87_1 == damping_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_70_1 == checksum_70_2);
}

int fn_R000767_6713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int window_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_86) & 63;
  acc ^= aux;
  int damping_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_87 > 46)
  {
    acc = ((acc + (damping_87 * 2)) + 5) & 127;
    aux ^= damping_87 & 15;
  }
  else
  {
    acc = ((acc - damping_87) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_70 = local_arr[aux % 3];
  acc = (acc + (checksum_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000767_6713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000767_6713_3 st_1 = {0};
  struct CipherContext_R000767_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int checksum_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_38_1 > 21)
  {
    acc_1 = ((acc_1 + (checksum_38_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_38_2 > 21)
  {
    acc_2 = ((acc_2 + (checksum_38_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_42_1 = local_arr_1[aux_1 % 3];
  int quantum_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_38_1 == checksum_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_42_1 == quantum_42_2);
}

int fn_R000767_6713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000767_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int checksum_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_38 > 21)
  {
    acc = ((acc + (checksum_38 * 2)) + 5) & 127;
    aux ^= checksum_38 & 15;
  }
  else
  {
    acc = ((acc - checksum_38) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_42 = local_arr[aux % 3];
  acc = (acc + (quantum_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000767_6713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st_1 = {0};
  struct FilterState_R000767_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int damping_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_10_1)
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

  switch (damping_10_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_24_1 > 38)
  {
    acc_1 = ((acc_1 + (cursor_24_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_24_2 > 38)
  {
    acc_2 = ((acc_2 + (cursor_24_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_10_1 == damping_10_2);
  assert(cursor_24_1 == cursor_24_2);
}

int fn_R000767_6713_15(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int damping_10 = (aux + st.buffer[1]) & 3;
  switch (damping_10)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_24 > 38)
  {
    acc = ((acc + (cursor_24 * 2)) + 5) & 127;
    aux ^= cursor_24 & 15;
  }
  else
  {
    acc = ((acc - cursor_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000767_6713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st_1 = {0};
  struct FilterState_R000767_6713_2 st_2 = {0};
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
  int sample_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_79_1 > 21)
  {
    acc_1 = ((acc_1 + (sample_79_1 * 2)) + 5) & 127;
    aux_1 ^= sample_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_79_2 > 21)
  {
    acc_2 = ((acc_2 + (sample_79_2 * 2)) + 5) & 127;
    aux_2 ^= sample_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_61_1)
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

  switch (anchor_61_2)
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

  int residue_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_42_1) & 63;
  aux_2 = (aux_2 + residue_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_79_1 == sample_79_2);
  assert(anchor_61_1 == anchor_61_2);
  assert(residue_42_1 == residue_42_2);
}

int fn_R000767_6713_16(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_79 > 21)
  {
    acc = ((acc + (sample_79 * 2)) + 5) & 127;
    aux ^= sample_79 & 15;
  }
  else
  {
    acc = ((acc - sample_79) + 11) & 127;
    aux += 3;
  }
  int anchor_61 = (aux + st.buffer[1]) & 3;
  switch (anchor_61)
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

  int residue_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000767_6713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st_1 = {0};
  struct EventLog_R000767_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_44_1) & 63;
  aux_2 = (aux_2 + offset_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_44_1 == offset_44_2);
}

int fn_R000767_6713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000767_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000767_6713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st_1 = {0};
  struct FilterState_R000767_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_53_1 = local_arr_1[aux_1 % 3];
  int accumulator_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_53_2 * 2)) & 127;
  int segment_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_32_1 > 29)
  {
    acc_1 = ((acc_1 + (segment_32_1 * 2)) + 5) & 127;
    aux_1 ^= segment_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_32_2 > 29)
  {
    acc_2 = ((acc_2 + (segment_32_2 * 2)) + 5) & 127;
    aux_2 ^= segment_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_43_1) & 63;
  aux_2 = (aux_2 + quantum_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_53_1 == accumulator_53_2);
  assert(segment_32_1 == segment_32_2);
  assert(quantum_43_1 == quantum_43_2);
}

int fn_R000767_6713_18(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000767_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_53 = local_arr[aux % 3];
  acc = (acc + (accumulator_53 * 2)) & 127;
  int segment_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_32 > 29)
  {
    acc = ((acc + (segment_32 * 2)) + 5) & 127;
    aux ^= segment_32 & 15;
  }
  else
  {
    acc = ((acc - segment_32) + 11) & 127;
    aux += 3;
  }
  int quantum_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000767_0_1;
  int sec_r000767_0_2;
  int sec_r000767_1_1;
  int sec_r000767_1_2;
  int sec_r000767_2_1;
  int sec_r000767_2_2;
  int sec_r000767_3_1;
  int sec_r000767_3_2;
  int sec_r000767_4_1;
  int sec_r000767_4_2;
  int sec_r000767_5_1;
  int sec_r000767_5_2;
  int sec_r000767_6_1;
  int sec_r000767_6_2;
  int sec_r000767_7_1;
  int sec_r000767_7_2;
  int sec_r000767_8_1;
  int sec_r000767_8_2;
  int sec_r000767_9_1;
  int sec_r000767_9_2;
  int sec_r000767_10_1;
  int sec_r000767_10_2;
  int sec_r000767_11_1;
  int sec_r000767_11_2;
  int sec_r000767_12_1;
  int sec_r000767_12_2;
  int sec_r000767_13_1;
  int sec_r000767_13_2;
  int sec_r000767_14_1;
  int sec_r000767_14_2;
  int sec_r000767_15_1;
  int sec_r000767_15_2;
  int sec_r000767_16_1;
  int sec_r000767_16_2;
  int pub_r000767_0_1;
  int pub_r000767_0_2;
  int pub_r000767_1_1;
  int pub_r000767_1_2;
  int pub_r000767_2_1;
  int pub_r000767_2_2;
  int pub_r000767_3_1;
  int pub_r000767_3_2;
  int pub_r000767_4_1;
  int pub_r000767_4_2;
  int pub_r000767_5_1;
  int pub_r000767_5_2;
  int pub_r000767_6_1;
  int pub_r000767_6_2;
  int pub_r000767_7_1;
  int pub_r000767_7_2;
  int pub_r000767_8_1;
  int pub_r000767_8_2;
  int pub_r000767_9_1;
  int pub_r000767_9_2;
  int pub_r000767_10_1;
  int pub_r000767_10_2;
  int pub_r000767_11_1;
  int pub_r000767_11_2;
  int pub_r000767_12_1;
  int pub_r000767_12_2;
  int pub_r000767_13_1;
  int pub_r000767_13_2;
  int pub_r000767_14_1;
  int pub_r000767_14_2;
  int pub_r000767_15_1;
  int pub_r000767_15_2;
  int pub_r000767_16_1;
  int pub_r000767_16_2;
  int pub_r000767_17_1;
  int pub_r000767_17_2;
  int pub_r000767_18_1;
  int pub_r000767_18_2;
  int pub_r000767_19_1;
  int pub_r000767_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000767_0_1 >= (-100)) && (pub_r000767_0_1 <= 100));
  __CPROVER_assume((pub_r000767_0_2 >= (-100)) && (pub_r000767_0_2 <= 100));
  __CPROVER_assume((pub_r000767_1_1 >= (-100)) && (pub_r000767_1_1 <= 100));
  __CPROVER_assume((pub_r000767_1_2 >= (-100)) && (pub_r000767_1_2 <= 100));
  __CPROVER_assume((pub_r000767_2_1 >= (-100)) && (pub_r000767_2_1 <= 100));
  __CPROVER_assume((pub_r000767_2_2 >= (-100)) && (pub_r000767_2_2 <= 100));
  __CPROVER_assume((pub_r000767_3_1 >= (-100)) && (pub_r000767_3_1 <= 100));
  __CPROVER_assume((pub_r000767_3_2 >= (-100)) && (pub_r000767_3_2 <= 100));
  __CPROVER_assume((pub_r000767_4_1 >= (-100)) && (pub_r000767_4_1 <= 100));
  __CPROVER_assume((pub_r000767_4_2 >= (-100)) && (pub_r000767_4_2 <= 100));
  __CPROVER_assume((pub_r000767_5_1 >= (-100)) && (pub_r000767_5_1 <= 100));
  __CPROVER_assume((pub_r000767_5_2 >= (-100)) && (pub_r000767_5_2 <= 100));
  __CPROVER_assume((pub_r000767_6_1 >= (-100)) && (pub_r000767_6_1 <= 100));
  __CPROVER_assume((pub_r000767_6_2 >= (-100)) && (pub_r000767_6_2 <= 100));
  __CPROVER_assume((pub_r000767_7_1 >= (-100)) && (pub_r000767_7_1 <= 100));
  __CPROVER_assume((pub_r000767_7_2 >= (-100)) && (pub_r000767_7_2 <= 100));
  __CPROVER_assume((pub_r000767_8_1 >= (-100)) && (pub_r000767_8_1 <= 100));
  __CPROVER_assume((pub_r000767_8_2 >= (-100)) && (pub_r000767_8_2 <= 100));
  __CPROVER_assume((pub_r000767_9_1 >= (-100)) && (pub_r000767_9_1 <= 100));
  __CPROVER_assume((pub_r000767_9_2 >= (-100)) && (pub_r000767_9_2 <= 100));
  __CPROVER_assume((pub_r000767_10_1 >= (-100)) && (pub_r000767_10_1 <= 100));
  __CPROVER_assume((pub_r000767_10_2 >= (-100)) && (pub_r000767_10_2 <= 100));
  __CPROVER_assume((pub_r000767_11_1 >= (-100)) && (pub_r000767_11_1 <= 100));
  __CPROVER_assume((pub_r000767_11_2 >= (-100)) && (pub_r000767_11_2 <= 100));
  __CPROVER_assume((pub_r000767_12_1 >= (-100)) && (pub_r000767_12_1 <= 100));
  __CPROVER_assume((pub_r000767_12_2 >= (-100)) && (pub_r000767_12_2 <= 100));
  __CPROVER_assume((pub_r000767_13_1 >= (-100)) && (pub_r000767_13_1 <= 100));
  __CPROVER_assume((pub_r000767_13_2 >= (-100)) && (pub_r000767_13_2 <= 100));
  __CPROVER_assume((pub_r000767_14_1 >= (-100)) && (pub_r000767_14_1 <= 100));
  __CPROVER_assume((pub_r000767_14_2 >= (-100)) && (pub_r000767_14_2 <= 100));
  __CPROVER_assume((pub_r000767_15_1 >= (-100)) && (pub_r000767_15_1 <= 100));
  __CPROVER_assume((pub_r000767_15_2 >= (-100)) && (pub_r000767_15_2 <= 100));
  __CPROVER_assume((pub_r000767_16_1 >= (-100)) && (pub_r000767_16_1 <= 100));
  __CPROVER_assume((pub_r000767_16_2 >= (-100)) && (pub_r000767_16_2 <= 100));
  __CPROVER_assume((pub_r000767_17_1 >= (-100)) && (pub_r000767_17_1 <= 100));
  __CPROVER_assume((pub_r000767_17_2 >= (-100)) && (pub_r000767_17_2 <= 100));
  __CPROVER_assume((pub_r000767_18_1 >= (-100)) && (pub_r000767_18_1 <= 100));
  __CPROVER_assume((pub_r000767_18_2 >= (-100)) && (pub_r000767_18_2 <= 100));
  __CPROVER_assume((pub_r000767_19_1 >= (-100)) && (pub_r000767_19_1 <= 100));
  __CPROVER_assume((pub_r000767_19_2 >= (-100)) && (pub_r000767_19_2 <= 100));
  __CPROVER_assume((sec_r000767_0_1 >= 0) && (sec_r000767_0_1 <= 255));
  __CPROVER_assume((sec_r000767_0_2 >= 0) && (sec_r000767_0_2 <= 255));
  __CPROVER_assume((sec_r000767_1_1 >= 0) && (sec_r000767_1_1 <= 255));
  __CPROVER_assume((sec_r000767_1_2 >= 0) && (sec_r000767_1_2 <= 255));
  __CPROVER_assume((sec_r000767_2_1 >= 0) && (sec_r000767_2_1 <= 255));
  __CPROVER_assume((sec_r000767_2_2 >= 0) && (sec_r000767_2_2 <= 255));
  __CPROVER_assume((sec_r000767_3_1 >= 0) && (sec_r000767_3_1 <= 255));
  __CPROVER_assume((sec_r000767_3_2 >= 0) && (sec_r000767_3_2 <= 255));
  __CPROVER_assume((sec_r000767_4_1 >= 0) && (sec_r000767_4_1 <= 255));
  __CPROVER_assume((sec_r000767_4_2 >= 0) && (sec_r000767_4_2 <= 255));
  __CPROVER_assume((sec_r000767_5_1 >= 0) && (sec_r000767_5_1 <= 255));
  __CPROVER_assume((sec_r000767_5_2 >= 0) && (sec_r000767_5_2 <= 255));
  __CPROVER_assume((sec_r000767_6_1 >= 0) && (sec_r000767_6_1 <= 255));
  __CPROVER_assume((sec_r000767_6_2 >= 0) && (sec_r000767_6_2 <= 255));
  __CPROVER_assume((sec_r000767_7_1 >= 0) && (sec_r000767_7_1 <= 255));
  __CPROVER_assume((sec_r000767_7_2 >= 0) && (sec_r000767_7_2 <= 255));
  __CPROVER_assume((sec_r000767_8_1 >= 0) && (sec_r000767_8_1 <= 255));
  __CPROVER_assume((sec_r000767_8_2 >= 0) && (sec_r000767_8_2 <= 255));
  __CPROVER_assume((sec_r000767_9_1 >= 0) && (sec_r000767_9_1 <= 255));
  __CPROVER_assume((sec_r000767_9_2 >= 0) && (sec_r000767_9_2 <= 255));
  __CPROVER_assume((sec_r000767_10_1 >= 0) && (sec_r000767_10_1 <= 255));
  __CPROVER_assume((sec_r000767_10_2 >= 0) && (sec_r000767_10_2 <= 255));
  __CPROVER_assume((sec_r000767_11_1 >= 0) && (sec_r000767_11_1 <= 255));
  __CPROVER_assume((sec_r000767_11_2 >= 0) && (sec_r000767_11_2 <= 255));
  __CPROVER_assume((sec_r000767_12_1 >= 0) && (sec_r000767_12_1 <= 255));
  __CPROVER_assume((sec_r000767_12_2 >= 0) && (sec_r000767_12_2 <= 255));
  __CPROVER_assume((sec_r000767_13_1 >= 0) && (sec_r000767_13_1 <= 255));
  __CPROVER_assume((sec_r000767_13_2 >= 0) && (sec_r000767_13_2 <= 255));
  __CPROVER_assume((sec_r000767_14_1 >= 0) && (sec_r000767_14_1 <= 255));
  __CPROVER_assume((sec_r000767_14_2 >= 0) && (sec_r000767_14_2 <= 255));
  __CPROVER_assume((sec_r000767_15_1 >= 0) && (sec_r000767_15_1 <= 255));
  __CPROVER_assume((sec_r000767_15_2 >= 0) && (sec_r000767_15_2 <= 255));
  __CPROVER_assume((sec_r000767_16_1 >= 0) && (sec_r000767_16_1 <= 255));
  __CPROVER_assume((sec_r000767_16_2 >= 0) && (sec_r000767_16_2 <= 255));
  struct EventLog_R000767_6713_0 st_var_0_1 = {0};
  struct EventLog_R000767_6713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000767_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000767_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000767_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000767_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000767_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000767_0_2 + 7) & 15;
  struct StreamBuffer_R000767_6713_1 st_var_1_1 = {0};
  struct StreamBuffer_R000767_6713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000767_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000767_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000767_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000767_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000767_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000767_0_2 + 9) & 15;
  struct FilterState_R000767_6713_2 st_var_2_1 = {0};
  struct FilterState_R000767_6713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000767_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000767_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000767_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000767_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000767_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000767_0_2 + 11) & 15;
  struct CipherContext_R000767_6713_3 st_var_3_1 = {0};
  struct CipherContext_R000767_6713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000767_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000767_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000767_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000767_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000767_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000767_0_2 + 13) & 15;
  union RegisterBank_R000767_6713_0 u_var_1;
  union RegisterBank_R000767_6713_0 u_var_2;
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
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 49)
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
  if (stage_v_1_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 49)
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
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = (st_var_3_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_3_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 12) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 32)
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
  if (stage_v_13_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 32)
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
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (st_var_2_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_2_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = (st_var_3_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_3_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 28) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 39)
    {
      chk_sum_1 ^= stage_v_28_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_28_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 39)
    {
      chk_sum_2 ^= stage_v_28_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((st_var_3_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_3_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 43)
    {
      chk_sum_1 ^= stage_v_31_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_31_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 43)
    {
      chk_sum_2 ^= stage_v_31_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((sec_r000767_7_1 & 1) != 0)
  {
    if ((sec_r000767_12_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000767_4_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000767_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000767_4_1 + 7) & 127;
  }
  if ((sec_r000767_7_2 & 1) != 0)
  {
    if ((sec_r000767_12_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000767_4_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000767_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000767_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000767_3_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000767_12_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000767_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000767_12_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000767_3_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000767_12_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000767_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000767_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000767_12_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000767_6_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000767_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000767_6_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000767_12_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000767_6_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000767_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000767_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000767_10_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000767_2_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000767_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000767_2_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000767_10_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000767_2_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000767_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000767_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000767_0_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000767_0_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000767_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000767_0_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000767_0_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000767_0_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000767_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000767_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000767_5_1 & 1) != 0)
  {
    if ((sec_r000767_11_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000767_13_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000767_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000767_13_1 + 7) & 127;
  }
  if ((sec_r000767_5_2 & 1) != 0)
  {
    if ((sec_r000767_11_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000767_13_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000767_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000767_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000767_4_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000767_7_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000767_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000767_7_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000767_4_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000767_7_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000767_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000767_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000767_9_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000767_12_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000767_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000767_12_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000767_9_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000767_12_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000767_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000767_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000767_10_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000767_1_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000767_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000767_1_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000767_10_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000767_1_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000767_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000767_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000767_7_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000767_7_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000767_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000767_7_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000767_7_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000767_7_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000767_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000767_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000767_6_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000767_15_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000767_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000767_15_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000767_6_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000767_15_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000767_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000767_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((sec_r000767_5_1 & 1) != 0)
  {
    if ((sec_r000767_11_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000767_8_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000767_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000767_8_1 + 7) & 127;
  }
  if ((sec_r000767_5_2 & 1) != 0)
  {
    if ((sec_r000767_11_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000767_8_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000767_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000767_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000767_0_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000767_19_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000767_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000767_19_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000767_0_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000767_19_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000767_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000767_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000767_15_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000767_15_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000767_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000767_15_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000767_15_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000767_15_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000767_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000767_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000767_13_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000767_13_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000767_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000767_13_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000767_13_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000767_13_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000767_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000767_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000767_15_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000767_7_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000767_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000767_7_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000767_15_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000767_7_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000767_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000767_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((sec_r000767_13_1 & 1) != 0)
  {
    if ((sec_r000767_11_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000767_1_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000767_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000767_1_1 + 7) & 127;
  }
  if ((sec_r000767_13_2 & 1) != 0)
  {
    if ((sec_r000767_11_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000767_1_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000767_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000767_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000767_0_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000767_9_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000767_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000767_9_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000767_0_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000767_9_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000767_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000767_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000767_11_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000767_1_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000767_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000767_1_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000767_11_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000767_1_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000767_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000767_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000767_9_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000767_9_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000767_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000767_9_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000767_9_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000767_9_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000767_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000767_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((sec_r000767_12_1 & 1) != 0)
  {
    if ((sec_r000767_11_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000767_13_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000767_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000767_13_1 + 7) & 127;
  }
  if ((sec_r000767_12_2 & 1) != 0)
  {
    if ((sec_r000767_11_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000767_13_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000767_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000767_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000767_3_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000767_16_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000767_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000767_16_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000767_3_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000767_16_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000767_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000767_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000767_16_1 & 1) != 0)
  {
    if ((sec_r000767_15_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000767_17_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000767_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000767_17_1 + 7) & 127;
  }
  if ((sec_r000767_16_2 & 1) != 0)
  {
    if ((sec_r000767_15_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000767_17_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000767_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000767_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000767_1_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000767_6_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000767_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000767_6_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000767_1_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000767_6_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000767_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000767_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000767_4_1 & 1) != 0)
  {
    if ((sec_r000767_14_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000767_0_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000767_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000767_0_1 + 7) & 127;
  }
  if ((sec_r000767_4_2 & 1) != 0)
  {
    if ((sec_r000767_14_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000767_0_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000767_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000767_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000767_10_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000767_0_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000767_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000767_0_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000767_10_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000767_0_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000767_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000767_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000767_0_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000767_9_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000767_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000767_9_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000767_0_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000767_9_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000767_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000767_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000767_5_1 & 1) != 0)
  {
    if ((sec_r000767_7_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000767_13_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000767_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000767_13_1 + 7) & 127;
  }
  if ((sec_r000767_5_2 & 1) != 0)
  {
    if ((sec_r000767_7_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000767_13_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000767_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000767_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000767_15_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000767_4_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000767_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000767_4_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000767_15_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000767_4_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000767_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000767_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000767_10_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000767_18_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000767_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000767_18_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000767_10_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000767_18_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000767_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000767_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000767_7_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000767_0_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000767_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000767_0_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000767_7_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000767_0_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000767_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000767_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000767_13_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000767_7_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000767_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000767_7_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000767_13_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000767_7_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000767_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000767_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000767_9_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000767_19_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000767_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000767_19_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000767_9_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000767_19_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000767_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000767_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000767_11_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000767_3_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000767_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000767_3_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000767_11_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000767_3_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000767_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000767_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000767_8_1 & 1) != 0)
  {
    if ((sec_r000767_9_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000767_19_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000767_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000767_19_1 + 7) & 127;
  }
  if ((sec_r000767_8_2 & 1) != 0)
  {
    if ((sec_r000767_9_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000767_19_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000767_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000767_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000767_12_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000767_15_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000767_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000767_15_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000767_12_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000767_15_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000767_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000767_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000767_7_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000767_9_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000767_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000767_9_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000767_7_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000767_9_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000767_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000767_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000767_2_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000767_12_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000767_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000767_12_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000767_2_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000767_12_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000767_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000767_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000767_3_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000767_10_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000767_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000767_10_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000767_3_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000767_10_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000767_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000767_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000767_4_1 & 1) != 0)
  {
    if ((sec_r000767_15_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000767_1_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000767_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000767_1_1 + 7) & 127;
  }
  if ((sec_r000767_4_2 & 1) != 0)
  {
    if ((sec_r000767_15_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000767_1_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000767_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000767_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000767_12_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000767_14_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000767_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000767_14_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000767_12_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000767_14_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000767_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000767_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000767_5_1 & 1) != 0)
  {
    if ((sec_r000767_5_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000767_15_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000767_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000767_15_1 + 7) & 127;
  }
  if ((sec_r000767_5_2 & 1) != 0)
  {
    if ((sec_r000767_5_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000767_15_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000767_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000767_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000767_2_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000767_0_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000767_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000767_0_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000767_2_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000767_0_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000767_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000767_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000767_10_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000767_16_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000767_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000767_16_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000767_10_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000767_16_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000767_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000767_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000767_5_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000767_5_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000767_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000767_5_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000767_5_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000767_5_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000767_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000767_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000767_3_1 & 1) != 0)
  {
    if ((sec_r000767_4_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000767_15_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000767_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000767_15_1 + 7) & 127;
  }
  if ((sec_r000767_3_2 & 1) != 0)
  {
    if ((sec_r000767_4_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000767_15_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000767_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000767_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000767_12_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000767_14_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000767_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000767_14_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000767_12_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000767_14_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000767_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000767_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000767_1_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000767_9_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000767_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000767_9_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000767_1_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000767_9_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000767_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000767_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000767_12_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000767_19_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000767_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000767_19_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000767_12_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000767_19_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000767_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000767_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000767_5_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000767_0_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000767_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000767_0_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000767_5_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000767_0_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000767_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000767_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000767_5_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000767_12_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000767_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000767_12_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000767_5_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000767_12_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000767_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000767_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000767_3_1 & 1) != 0)
  {
    if ((sec_r000767_2_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000767_0_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000767_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000767_0_1 + 7) & 127;
  }
  if ((sec_r000767_3_2 & 1) != 0)
  {
    if ((sec_r000767_2_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000767_0_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000767_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000767_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000767_12_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000767_17_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000767_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000767_17_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000767_12_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000767_17_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000767_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000767_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000767_2_1 & 1) != 0)
  {
    if ((sec_r000767_1_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000767_0_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000767_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000767_0_1 + 7) & 127;
  }
  if ((sec_r000767_2_2 & 1) != 0)
  {
    if ((sec_r000767_1_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000767_0_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000767_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000767_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000767_6_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000767_4_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000767_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000767_4_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000767_6_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000767_4_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000767_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000767_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000767_9_1 & 1) != 0)
  {
    if ((sec_r000767_7_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000767_0_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000767_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000767_0_1 + 7) & 127;
  }
  if ((sec_r000767_9_2 & 1) != 0)
  {
    if ((sec_r000767_7_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000767_0_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000767_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000767_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000767_1_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000767_0_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000767_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000767_0_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000767_1_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000767_0_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000767_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000767_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000767_6_1 & 1) != 0)
  {
    if ((sec_r000767_15_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000767_17_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000767_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000767_17_1 + 7) & 127;
  }
  if ((sec_r000767_6_2 & 1) != 0)
  {
    if ((sec_r000767_15_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000767_17_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000767_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000767_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000767_7_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000767_9_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000767_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000767_9_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000767_7_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000767_9_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000767_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000767_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000767_0_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000767_18_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000767_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000767_18_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000767_0_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000767_18_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000767_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000767_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000767_13_1 & 1) != 0)
  {
    if ((sec_r000767_9_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000767_18_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000767_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000767_18_1 + 7) & 127;
  }
  if ((sec_r000767_13_2 & 1) != 0)
  {
    if ((sec_r000767_9_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000767_18_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000767_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000767_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000767_12_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000767_7_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000767_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000767_7_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000767_12_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000767_7_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000767_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000767_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000767_16_1 & 1) != 0)
  {
    if ((sec_r000767_10_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000767_16_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000767_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000767_16_1 + 7) & 127;
  }
  if ((sec_r000767_16_2 & 1) != 0)
  {
    if ((sec_r000767_10_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000767_16_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000767_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000767_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000767_15_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000767_9_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000767_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000767_9_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000767_15_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000767_9_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000767_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000767_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000767_13_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000767_12_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000767_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000767_12_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000767_13_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000767_12_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000767_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000767_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000767_2_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000767_16_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000767_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000767_16_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000767_2_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000767_16_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000767_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000767_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000767_14_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000767_18_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000767_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000767_18_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000767_14_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000767_18_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000767_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000767_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000767_8_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000767_6_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000767_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000767_6_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000767_8_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000767_6_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000767_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000767_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000767_14_1 & 1) != 0)
  {
    if ((sec_r000767_1_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000767_4_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000767_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000767_4_1 + 7) & 127;
  }
  if ((sec_r000767_14_2 & 1) != 0)
  {
    if ((sec_r000767_1_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000767_4_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000767_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000767_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000767_2_1 & 1) != 0)
  {
    if ((sec_r000767_11_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000767_6_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000767_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000767_6_1 + 7) & 127;
  }
  if ((sec_r000767_2_2 & 1) != 0)
  {
    if ((sec_r000767_11_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000767_6_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000767_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000767_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000767_13_1 & 1) != 0)
  {
    if ((sec_r000767_12_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000767_9_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000767_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000767_9_1 + 7) & 127;
  }
  if ((sec_r000767_13_2 & 1) != 0)
  {
    if ((sec_r000767_12_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000767_9_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000767_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000767_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000767_16_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000767_19_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000767_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000767_19_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000767_16_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000767_19_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000767_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000767_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000767_5_1 & 1) != 0)
  {
    if ((sec_r000767_13_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000767_13_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000767_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000767_13_1 + 7) & 127;
  }
  if ((sec_r000767_5_2 & 1) != 0)
  {
    if ((sec_r000767_13_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000767_13_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000767_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000767_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000767_7_1 & 1) != 0)
  {
    if ((sec_r000767_15_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000767_4_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000767_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000767_4_1 + 7) & 127;
  }
  if ((sec_r000767_7_2 & 1) != 0)
  {
    if ((sec_r000767_15_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000767_4_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000767_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000767_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000767_3_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000767_19_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000767_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000767_19_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000767_3_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000767_19_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000767_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000767_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000767_1_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000767_2_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000767_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000767_2_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000767_1_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000767_2_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000767_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000767_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000767_7_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000767_7_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000767_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000767_7_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000767_7_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000767_7_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000767_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000767_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000767_1_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000767_8_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000767_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000767_8_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000767_1_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000767_8_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000767_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000767_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000767_0_1 & 1) != 0)
  {
    if ((sec_r000767_15_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000767_2_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000767_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000767_2_1 + 7) & 127;
  }
  if ((sec_r000767_0_2 & 1) != 0)
  {
    if ((sec_r000767_15_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000767_2_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000767_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000767_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000767_9_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000767_0_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000767_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000767_0_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000767_9_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000767_0_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000767_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000767_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000767_7_1 & 1) != 0)
  {
    if ((sec_r000767_2_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000767_1_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000767_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000767_1_1 + 7) & 127;
  }
  if ((sec_r000767_7_2 & 1) != 0)
  {
    if ((sec_r000767_2_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000767_1_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000767_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000767_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000767_14_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000767_18_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000767_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000767_18_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000767_14_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000767_18_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000767_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000767_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000767_3_1 & 1) != 0)
  {
    if ((sec_r000767_0_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000767_19_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000767_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000767_19_1 + 7) & 127;
  }
  if ((sec_r000767_3_2 & 1) != 0)
  {
    if ((sec_r000767_0_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000767_19_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000767_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000767_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000767_12_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000767_13_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000767_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000767_13_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000767_12_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000767_13_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000767_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000767_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000767_10_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000767_10_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000767_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000767_10_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000767_10_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000767_10_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000767_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000767_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000767_5_1 & 1) != 0)
  {
    if ((sec_r000767_13_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000767_15_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000767_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000767_15_1 + 7) & 127;
  }
  if ((sec_r000767_5_2 & 1) != 0)
  {
    if ((sec_r000767_13_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000767_15_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000767_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000767_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000767_2_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000767_16_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000767_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000767_16_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000767_2_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000767_16_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000767_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000767_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000767_6_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000767_19_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000767_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000767_19_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000767_6_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000767_19_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000767_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000767_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000767_1_1 & 1) != 0)
  {
    if ((sec_r000767_14_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000767_17_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000767_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000767_17_1 + 7) & 127;
  }
  if ((sec_r000767_1_2 & 1) != 0)
  {
    if ((sec_r000767_14_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000767_17_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000767_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000767_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000767_1_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000767_9_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000767_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000767_9_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000767_1_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000767_9_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000767_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000767_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000767_11_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000767_9_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000767_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000767_9_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000767_11_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000767_9_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000767_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000767_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000767_11_1 & 1) != 0)
  {
    if ((sec_r000767_5_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000767_19_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000767_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000767_19_1 + 7) & 127;
  }
  if ((sec_r000767_11_2 & 1) != 0)
  {
    if ((sec_r000767_5_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000767_19_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000767_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000767_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000767_4_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000767_10_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000767_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000767_10_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000767_4_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000767_10_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000767_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000767_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000767_17_1 == pub_r000767_17_2);
  __CPROVER_assume(sec_r000767_2_1 != sec_r000767_2_2);
  __CPROVER_assume(sec_r000767_10_1 != sec_r000767_10_2);
  __CPROVER_assume(pub_r000767_8_1 == pub_r000767_8_2);
  __CPROVER_assume(sec_r000767_1_1 != sec_r000767_1_2);
  __CPROVER_assume(pub_r000767_1_1 == pub_r000767_1_2);
  __CPROVER_assume(sec_r000767_9_1 != sec_r000767_9_2);
  __CPROVER_assume(sec_r000767_4_1 != sec_r000767_4_2);
  __CPROVER_assume(pub_r000767_7_1 == pub_r000767_7_2);
  __CPROVER_assume(pub_r000767_2_1 == pub_r000767_2_2);
  __CPROVER_assume(pub_r000767_0_1 == pub_r000767_0_2);
  __CPROVER_assume(sec_r000767_12_1 != sec_r000767_12_2);
  __CPROVER_assume(pub_r000767_10_1 == pub_r000767_10_2);
  __CPROVER_assume(sec_r000767_3_1 != sec_r000767_3_2);
  __CPROVER_assume(sec_r000767_11_1 != sec_r000767_11_2);
  __CPROVER_assume(pub_r000767_16_1 == pub_r000767_16_2);
  __CPROVER_assume(pub_r000767_9_1 == pub_r000767_9_2);
  __CPROVER_assume(sec_r000767_5_1 != sec_r000767_5_2);
  __CPROVER_assume(sec_r000767_7_1 != sec_r000767_7_2);
  __CPROVER_assume(pub_r000767_5_1 == pub_r000767_5_2);
  __CPROVER_assume(sec_r000767_6_1 != sec_r000767_6_2);
  __CPROVER_assume(sec_r000767_8_1 != sec_r000767_8_2);
  __CPROVER_assume(pub_r000767_4_1 == pub_r000767_4_2);
  __CPROVER_assume(pub_r000767_15_1 == pub_r000767_15_2);
  __CPROVER_assume(sec_r000767_14_1 != sec_r000767_14_2);
  __CPROVER_assume(pub_r000767_12_1 == pub_r000767_12_2);
  __CPROVER_assume(pub_r000767_19_1 == pub_r000767_19_2);
  __CPROVER_assume(pub_r000767_13_1 == pub_r000767_13_2);
  __CPROVER_assume(pub_r000767_14_1 == pub_r000767_14_2);
  __CPROVER_assume(sec_r000767_15_1 != sec_r000767_15_2);
  __CPROVER_assume(sec_r000767_16_1 != sec_r000767_16_2);
  __CPROVER_assume(sec_r000767_0_1 != sec_r000767_0_2);
  __CPROVER_assume(pub_r000767_3_1 == pub_r000767_3_2);
  __CPROVER_assume(pub_r000767_6_1 == pub_r000767_6_2);
  __CPROVER_assume(pub_r000767_11_1 == pub_r000767_11_2);
  __CPROVER_assume(pub_r000767_18_1 == pub_r000767_18_2);
  __CPROVER_assume(sec_r000767_13_1 != sec_r000767_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.state == st_var_1_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.flags == st_var_3_2.flags);
  assert(st_var_3_1.tag == st_var_3_2.tag);
  assert(st_var_3_1.iv == st_var_3_2.iv);
  assert(st_var_3_1.round_key == st_var_3_2.round_key);
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
}


