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
struct CipherContext_R000107_713_0
{
  short counter;
  unsigned char tag;
  unsigned char flags;
  int round_key;
  int iv;
  int nonce;
  int buffer[3];
};
struct FilterState_R000107_713_1
{
  unsigned char cutoff;
  int mode;
  int prev_out;
  int damping;
  int buffer[3];
};
struct AudioFrame_R000107_713_2
{
  short gain;
  int envelope;
  short peak;
  int buffer[3];
};
union TelemetryField_R000107_713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000107_713_1
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
void fn_R000107_713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000107_713_0 st_1 = {0};
  struct CipherContext_R000107_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_38_1 = local_arr_1[aux_1 % 3];
  int weight_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_38_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_38_1) & 63;
  aux_2 = (aux_2 + cursor_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_11_1 > 43)
  {
    acc_1 = ((acc_1 + (window_11_1 * 2)) + 5) & 127;
    aux_1 ^= window_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_11_2 > 43)
  {
    acc_2 = ((acc_2 + (window_11_2 * 2)) + 5) & 127;
    aux_2 ^= window_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_38_1 == weight_38_2);
  assert(cursor_38_1 == cursor_38_2);
  assert(window_11_1 == window_11_2);
}

int fn_R000107_713_0(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000107_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int weight_38 = local_arr[aux % 3];
  acc = (acc + (weight_38 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_38) & 63;
  acc ^= aux;
  int window_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_11 > 43)
  {
    acc = ((acc + (window_11 * 2)) + 5) & 127;
    aux ^= window_11 & 15;
  }
  else
  {
    acc = ((acc - window_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000107_713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000107_713_1 st_1 = {0};
  struct FilterState_R000107_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_61_1 = local_arr_1[aux_1 % 3];
  int coefficient_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_61_2 * 2)) & 127;
  int threshold_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_42_1 > 42)
  {
    acc_1 = ((acc_1 + (threshold_42_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_42_2 > 42)
  {
    acc_2 = ((acc_2 + (threshold_42_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_61_1 == coefficient_61_2);
  assert(threshold_42_1 == threshold_42_2);
}

int fn_R000107_713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000107_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_61 = local_arr[aux % 3];
  acc = (acc + (coefficient_61 * 2)) & 127;
  int threshold_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_42 > 42)
  {
    acc = ((acc + (threshold_42 * 2)) + 5) & 127;
    aux ^= threshold_42 & 15;
  }
  else
  {
    acc = ((acc - threshold_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000107_713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st_1 = {0};
  struct AudioFrame_R000107_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_54_1 = local_arr_1[aux_1 % 3];
  int accumulator_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_54_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_49_1 > 36)
  {
    acc_1 = ((acc_1 + (pivot_49_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_49_2 > 36)
  {
    acc_2 = ((acc_2 + (pivot_49_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_54_1 == accumulator_54_2);
  assert(pivot_49_1 == pivot_49_2);
}

int fn_R000107_713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int accumulator_54 = local_arr[aux % 3];
  acc = (acc + (accumulator_54 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_49 > 36)
  {
    acc = ((acc + (pivot_49 * 2)) + 5) & 127;
    aux ^= pivot_49 & 15;
  }
  else
  {
    acc = ((acc - pivot_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000107_713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st_1 = {0};
  struct AudioFrame_R000107_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int anchor_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_70_1)
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

  switch (anchor_70_2)
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

  int segment_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_90_1 > 36)
  {
    acc_1 = ((acc_1 + (segment_90_1 * 2)) + 5) & 127;
    aux_1 ^= segment_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_90_2 > 36)
  {
    acc_2 = ((acc_2 + (segment_90_2 * 2)) + 5) & 127;
    aux_2 ^= segment_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_90_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_70_1 == anchor_70_2);
  assert(segment_90_1 == segment_90_2);
}

int fn_R000107_713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int anchor_70 = (aux + st.buffer[1]) & 3;
  switch (anchor_70)
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

  int segment_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_90 > 36)
  {
    acc = ((acc + (segment_90 * 2)) + 5) & 127;
    aux ^= segment_90 & 15;
  }
  else
  {
    acc = ((acc - segment_90) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000107_713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000107_713_0 st_1 = {0};
  struct CipherContext_R000107_713_0 st_2 = {0};
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
  int anchor_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_21_1)
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

  switch (anchor_21_2)
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

  int parity_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_50_1) & 63;
  aux_2 = (aux_2 + parity_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_21_1 == anchor_21_2);
  assert(parity_50_1 == parity_50_2);
}

int fn_R000107_713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000107_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_21 = (aux + st.buffer[1]) & 3;
  switch (anchor_21)
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

  int parity_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_50) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000107_713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000107_713_0 st_1 = {0};
  struct CipherContext_R000107_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int stride_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_72_1 > 16)
  {
    acc_1 = ((acc_1 + (stride_72_1 * 2)) + 5) & 127;
    aux_1 ^= stride_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_72_2 > 16)
  {
    acc_2 = ((acc_2 + (stride_72_2 * 2)) + 5) & 127;
    aux_2 ^= stride_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_87_1)
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

  switch (scale_87_2)
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
  int parity_39_1 = local_arr_1[aux_1 % 3];
  int parity_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_39_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_72_1 == stride_72_2);
  assert(scale_87_1 == scale_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_39_1 == parity_39_2);
}

int fn_R000107_713_5(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000107_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int stride_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_72 > 16)
  {
    acc = ((acc + (stride_72 * 2)) + 5) & 127;
    aux ^= stride_72 & 15;
  }
  else
  {
    acc = ((acc - stride_72) + 11) & 127;
    aux += 3;
  }
  int scale_87 = (aux + st.buffer[1]) & 3;
  switch (scale_87)
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
  int parity_39 = local_arr[aux % 3];
  acc = (acc + (parity_39 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000107_713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st_1 = {0};
  struct AudioFrame_R000107_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_54_1 = local_arr_1[aux_1 % 3];
  int metric_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_54_2 * 2)) & 127;
  int offset_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_58_1)
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

  switch (offset_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_41_1) & 63;
  aux_2 = (aux_2 + stride_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_54_1 == metric_54_2);
  assert(offset_58_1 == offset_58_2);
  assert(stride_41_1 == stride_41_2);
}

int fn_R000107_713_6(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int metric_54 = local_arr[aux % 3];
  acc = (acc + (metric_54 * 2)) & 127;
  int offset_58 = (aux + st.buffer[1]) & 3;
  switch (offset_58)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_41) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000107_713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st_1 = {0};
  struct AudioFrame_R000107_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_31_1 = local_arr_1[aux_1 % 3];
  int delta_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_31_2 * 2)) & 127;
  int quantum_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_84_1 > 18)
  {
    acc_1 = ((acc_1 + (quantum_84_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_84_2 > 18)
  {
    acc_2 = ((acc_2 + (quantum_84_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_31_1 == delta_31_2);
  assert(quantum_84_1 == quantum_84_2);
}

int fn_R000107_713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int delta_31 = local_arr[aux % 3];
  acc = (acc + (delta_31 * 2)) & 127;
  int quantum_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_84 > 18)
  {
    acc = ((acc + (quantum_84 * 2)) + 5) & 127;
    aux ^= quantum_84 & 15;
  }
  else
  {
    acc = ((acc - quantum_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000107_713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000107_713_1 st_1 = {0};
  struct FilterState_R000107_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int weight_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_70_1) & 63;
  aux_2 = (aux_2 + weight_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_13_1)
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

  switch (cursor_13_2)
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

  int checksum_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_28_1 > 28)
  {
    acc_1 = ((acc_1 + (checksum_28_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_28_2 > 28)
  {
    acc_2 = ((acc_2 + (checksum_28_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_28_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_70_1 == weight_70_2);
  assert(cursor_13_1 == cursor_13_2);
  assert(checksum_28_1 == checksum_28_2);
}

int fn_R000107_713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000107_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int weight_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_13 = (aux + st.buffer[1]) & 3;
  switch (cursor_13)
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

  int checksum_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_28 > 28)
  {
    acc = ((acc + (checksum_28 * 2)) + 5) & 127;
    aux ^= checksum_28 & 15;
  }
  else
  {
    acc = ((acc - checksum_28) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000107_713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st_1 = {0};
  struct AudioFrame_R000107_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_78_1 = local_arr_1[aux_1 % 3];
  int quantum_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_78_2 * 2)) & 127;
  int quantum_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_65_1)
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

  switch (quantum_65_2)
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

  int index_reg_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_81_1) & 63;
  aux_2 = (aux_2 + index_reg_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_78_1 == quantum_78_2);
  assert(quantum_65_1 == quantum_65_2);
  assert(index_reg_81_1 == index_reg_81_2);
}

int fn_R000107_713_9(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int quantum_78 = local_arr[aux % 3];
  acc = (acc + (quantum_78 * 2)) & 127;
  int quantum_65 = (aux + st.buffer[1]) & 3;
  switch (quantum_65)
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

  int index_reg_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000107_713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000107_713_1 st_1 = {0};
  struct FilterState_R000107_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int bound_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_55_1)
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

  switch (bound_55_2)
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
  int anchor_19_1 = local_arr_1[aux_1 % 3];
  int anchor_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_55_1 == bound_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_19_1 == anchor_19_2);
}

int fn_R000107_713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000107_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int bound_55 = (aux + st.buffer[1]) & 3;
  switch (bound_55)
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
  int anchor_19 = local_arr[aux % 3];
  acc = (acc + (anchor_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000107_713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000107_713_0 st_1 = {0};
  struct CipherContext_R000107_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int residue_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_99_1) & 63;
  aux_2 = (aux_2 + residue_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_63_1)
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

  switch (phase_63_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_99_1 == residue_99_2);
  assert(phase_63_1 == phase_63_2);
}

int fn_R000107_713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000107_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int residue_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_99) & 63;
  acc ^= aux;
  int phase_63 = (aux + st.buffer[1]) & 3;
  switch (phase_63)
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

void fn_R000107_713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st_1 = {0};
  struct AudioFrame_R000107_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_31_1)
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

  switch (tally_31_2)
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
  int sample_22_1 = local_arr_1[aux_1 % 3];
  int sample_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_22_2 * 2)) & 127;
  int sample_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_72_1 > 19)
  {
    acc_1 = ((acc_1 + (sample_72_1 * 2)) + 5) & 127;
    aux_1 ^= sample_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_72_2 > 19)
  {
    acc_2 = ((acc_2 + (sample_72_2 * 2)) + 5) & 127;
    aux_2 ^= sample_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_31_1 == tally_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_22_1 == sample_22_2);
  assert(sample_72_1 == sample_72_2);
}

int fn_R000107_713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_31 = (aux + st.buffer[1]) & 3;
  switch (tally_31)
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
  int sample_22 = local_arr[aux % 3];
  acc = (acc + (sample_22 * 2)) & 127;
  int sample_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_72 > 19)
  {
    acc = ((acc + (sample_72 * 2)) + 5) & 127;
    aux ^= sample_72 & 15;
  }
  else
  {
    acc = ((acc - sample_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000107_713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st_1 = {0};
  struct AudioFrame_R000107_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_67_1 > 50)
  {
    acc_1 = ((acc_1 + (sample_67_1 * 2)) + 5) & 127;
    aux_1 ^= sample_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_67_2 > 50)
  {
    acc_2 = ((acc_2 + (sample_67_2 * 2)) + 5) & 127;
    aux_2 ^= sample_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_67_1 == sample_67_2);
}

int fn_R000107_713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000107_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_67 > 50)
  {
    acc = ((acc + (sample_67 * 2)) + 5) & 127;
    aux ^= sample_67 & 15;
  }
  else
  {
    acc = ((acc - sample_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000107_713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000107_713_1 st_1 = {0};
  struct FilterState_R000107_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_48_1 = local_arr_1[aux_1 % 3];
  int threshold_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_48_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_18_1)
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

  switch (mask_18_2)
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

  int quotient_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_14_1 > 41)
  {
    acc_1 = ((acc_1 + (quotient_14_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_14_2 > 41)
  {
    acc_2 = ((acc_2 + (quotient_14_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_48_1 == threshold_48_2);
  assert(mask_18_1 == mask_18_2);
  assert(quotient_14_1 == quotient_14_2);
}

int fn_R000107_713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000107_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int threshold_48 = local_arr[aux % 3];
  acc = (acc + (threshold_48 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_18 = (aux + st.buffer[1]) & 3;
  switch (mask_18)
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

  int quotient_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_14 > 41)
  {
    acc = ((acc + (quotient_14 * 2)) + 5) & 127;
    aux ^= quotient_14 & 15;
  }
  else
  {
    acc = ((acc - quotient_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000107_0_1;
  int sec_r000107_0_2;
  int sec_r000107_1_1;
  int sec_r000107_1_2;
  int sec_r000107_2_1;
  int sec_r000107_2_2;
  int sec_r000107_3_1;
  int sec_r000107_3_2;
  int sec_r000107_4_1;
  int sec_r000107_4_2;
  int sec_r000107_5_1;
  int sec_r000107_5_2;
  int sec_r000107_6_1;
  int sec_r000107_6_2;
  int sec_r000107_7_1;
  int sec_r000107_7_2;
  int sec_r000107_8_1;
  int sec_r000107_8_2;
  int sec_r000107_9_1;
  int sec_r000107_9_2;
  int sec_r000107_10_1;
  int sec_r000107_10_2;
  int sec_r000107_11_1;
  int sec_r000107_11_2;
  int sec_r000107_12_1;
  int sec_r000107_12_2;
  int sec_r000107_13_1;
  int sec_r000107_13_2;
  int sec_r000107_14_1;
  int sec_r000107_14_2;
  int sec_r000107_15_1;
  int sec_r000107_15_2;
  int sec_r000107_16_1;
  int sec_r000107_16_2;
  int sec_r000107_17_1;
  int sec_r000107_17_2;
  int sec_r000107_18_1;
  int sec_r000107_18_2;
  int sec_r000107_19_1;
  int sec_r000107_19_2;
  int sec_r000107_20_1;
  int sec_r000107_20_2;
  int sec_r000107_21_1;
  int sec_r000107_21_2;
  int sec_r000107_22_1;
  int sec_r000107_22_2;
  int sec_r000107_23_1;
  int sec_r000107_23_2;
  int pub_r000107_0_1;
  int pub_r000107_0_2;
  int pub_r000107_1_1;
  int pub_r000107_1_2;
  int pub_r000107_2_1;
  int pub_r000107_2_2;
  int pub_r000107_3_1;
  int pub_r000107_3_2;
  int pub_r000107_4_1;
  int pub_r000107_4_2;
  int pub_r000107_5_1;
  int pub_r000107_5_2;
  int pub_r000107_6_1;
  int pub_r000107_6_2;
  int pub_r000107_7_1;
  int pub_r000107_7_2;
  int pub_r000107_8_1;
  int pub_r000107_8_2;
  int pub_r000107_9_1;
  int pub_r000107_9_2;
  int pub_r000107_10_1;
  int pub_r000107_10_2;
  int pub_r000107_11_1;
  int pub_r000107_11_2;
  int pub_r000107_12_1;
  int pub_r000107_12_2;
  int pub_r000107_13_1;
  int pub_r000107_13_2;
  int pub_r000107_14_1;
  int pub_r000107_14_2;
  int pub_r000107_15_1;
  int pub_r000107_15_2;
  int pub_r000107_16_1;
  int pub_r000107_16_2;
  int pub_r000107_17_1;
  int pub_r000107_17_2;
  int pub_r000107_18_1;
  int pub_r000107_18_2;
  int pub_r000107_19_1;
  int pub_r000107_19_2;
  int pub_r000107_20_1;
  int pub_r000107_20_2;
  int pub_r000107_21_1;
  int pub_r000107_21_2;
  int pub_r000107_22_1;
  int pub_r000107_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000107_0_1 >= (-100)) && (pub_r000107_0_1 <= 100));
  __CPROVER_assume((pub_r000107_0_2 >= (-100)) && (pub_r000107_0_2 <= 100));
  __CPROVER_assume((pub_r000107_1_1 >= (-100)) && (pub_r000107_1_1 <= 100));
  __CPROVER_assume((pub_r000107_1_2 >= (-100)) && (pub_r000107_1_2 <= 100));
  __CPROVER_assume((pub_r000107_2_1 >= (-100)) && (pub_r000107_2_1 <= 100));
  __CPROVER_assume((pub_r000107_2_2 >= (-100)) && (pub_r000107_2_2 <= 100));
  __CPROVER_assume((pub_r000107_3_1 >= (-100)) && (pub_r000107_3_1 <= 100));
  __CPROVER_assume((pub_r000107_3_2 >= (-100)) && (pub_r000107_3_2 <= 100));
  __CPROVER_assume((pub_r000107_4_1 >= (-100)) && (pub_r000107_4_1 <= 100));
  __CPROVER_assume((pub_r000107_4_2 >= (-100)) && (pub_r000107_4_2 <= 100));
  __CPROVER_assume((pub_r000107_5_1 >= (-100)) && (pub_r000107_5_1 <= 100));
  __CPROVER_assume((pub_r000107_5_2 >= (-100)) && (pub_r000107_5_2 <= 100));
  __CPROVER_assume((pub_r000107_6_1 >= (-100)) && (pub_r000107_6_1 <= 100));
  __CPROVER_assume((pub_r000107_6_2 >= (-100)) && (pub_r000107_6_2 <= 100));
  __CPROVER_assume((pub_r000107_7_1 >= (-100)) && (pub_r000107_7_1 <= 100));
  __CPROVER_assume((pub_r000107_7_2 >= (-100)) && (pub_r000107_7_2 <= 100));
  __CPROVER_assume((pub_r000107_8_1 >= (-100)) && (pub_r000107_8_1 <= 100));
  __CPROVER_assume((pub_r000107_8_2 >= (-100)) && (pub_r000107_8_2 <= 100));
  __CPROVER_assume((pub_r000107_9_1 >= (-100)) && (pub_r000107_9_1 <= 100));
  __CPROVER_assume((pub_r000107_9_2 >= (-100)) && (pub_r000107_9_2 <= 100));
  __CPROVER_assume((pub_r000107_10_1 >= (-100)) && (pub_r000107_10_1 <= 100));
  __CPROVER_assume((pub_r000107_10_2 >= (-100)) && (pub_r000107_10_2 <= 100));
  __CPROVER_assume((pub_r000107_11_1 >= (-100)) && (pub_r000107_11_1 <= 100));
  __CPROVER_assume((pub_r000107_11_2 >= (-100)) && (pub_r000107_11_2 <= 100));
  __CPROVER_assume((pub_r000107_12_1 >= (-100)) && (pub_r000107_12_1 <= 100));
  __CPROVER_assume((pub_r000107_12_2 >= (-100)) && (pub_r000107_12_2 <= 100));
  __CPROVER_assume((pub_r000107_13_1 >= (-100)) && (pub_r000107_13_1 <= 100));
  __CPROVER_assume((pub_r000107_13_2 >= (-100)) && (pub_r000107_13_2 <= 100));
  __CPROVER_assume((pub_r000107_14_1 >= (-100)) && (pub_r000107_14_1 <= 100));
  __CPROVER_assume((pub_r000107_14_2 >= (-100)) && (pub_r000107_14_2 <= 100));
  __CPROVER_assume((pub_r000107_15_1 >= (-100)) && (pub_r000107_15_1 <= 100));
  __CPROVER_assume((pub_r000107_15_2 >= (-100)) && (pub_r000107_15_2 <= 100));
  __CPROVER_assume((pub_r000107_16_1 >= (-100)) && (pub_r000107_16_1 <= 100));
  __CPROVER_assume((pub_r000107_16_2 >= (-100)) && (pub_r000107_16_2 <= 100));
  __CPROVER_assume((pub_r000107_17_1 >= (-100)) && (pub_r000107_17_1 <= 100));
  __CPROVER_assume((pub_r000107_17_2 >= (-100)) && (pub_r000107_17_2 <= 100));
  __CPROVER_assume((pub_r000107_18_1 >= (-100)) && (pub_r000107_18_1 <= 100));
  __CPROVER_assume((pub_r000107_18_2 >= (-100)) && (pub_r000107_18_2 <= 100));
  __CPROVER_assume((pub_r000107_19_1 >= (-100)) && (pub_r000107_19_1 <= 100));
  __CPROVER_assume((pub_r000107_19_2 >= (-100)) && (pub_r000107_19_2 <= 100));
  __CPROVER_assume((pub_r000107_20_1 >= (-100)) && (pub_r000107_20_1 <= 100));
  __CPROVER_assume((pub_r000107_20_2 >= (-100)) && (pub_r000107_20_2 <= 100));
  __CPROVER_assume((pub_r000107_21_1 >= (-100)) && (pub_r000107_21_1 <= 100));
  __CPROVER_assume((pub_r000107_21_2 >= (-100)) && (pub_r000107_21_2 <= 100));
  __CPROVER_assume((pub_r000107_22_1 >= (-100)) && (pub_r000107_22_1 <= 100));
  __CPROVER_assume((pub_r000107_22_2 >= (-100)) && (pub_r000107_22_2 <= 100));
  __CPROVER_assume((sec_r000107_0_1 >= 0) && (sec_r000107_0_1 <= 255));
  __CPROVER_assume((sec_r000107_0_2 >= 0) && (sec_r000107_0_2 <= 255));
  __CPROVER_assume((sec_r000107_1_1 >= 0) && (sec_r000107_1_1 <= 255));
  __CPROVER_assume((sec_r000107_1_2 >= 0) && (sec_r000107_1_2 <= 255));
  __CPROVER_assume((sec_r000107_2_1 >= 0) && (sec_r000107_2_1 <= 255));
  __CPROVER_assume((sec_r000107_2_2 >= 0) && (sec_r000107_2_2 <= 255));
  __CPROVER_assume((sec_r000107_3_1 >= 0) && (sec_r000107_3_1 <= 255));
  __CPROVER_assume((sec_r000107_3_2 >= 0) && (sec_r000107_3_2 <= 255));
  __CPROVER_assume((sec_r000107_4_1 >= 0) && (sec_r000107_4_1 <= 255));
  __CPROVER_assume((sec_r000107_4_2 >= 0) && (sec_r000107_4_2 <= 255));
  __CPROVER_assume((sec_r000107_5_1 >= 0) && (sec_r000107_5_1 <= 255));
  __CPROVER_assume((sec_r000107_5_2 >= 0) && (sec_r000107_5_2 <= 255));
  __CPROVER_assume((sec_r000107_6_1 >= 0) && (sec_r000107_6_1 <= 255));
  __CPROVER_assume((sec_r000107_6_2 >= 0) && (sec_r000107_6_2 <= 255));
  __CPROVER_assume((sec_r000107_7_1 >= 0) && (sec_r000107_7_1 <= 255));
  __CPROVER_assume((sec_r000107_7_2 >= 0) && (sec_r000107_7_2 <= 255));
  __CPROVER_assume((sec_r000107_8_1 >= 0) && (sec_r000107_8_1 <= 255));
  __CPROVER_assume((sec_r000107_8_2 >= 0) && (sec_r000107_8_2 <= 255));
  __CPROVER_assume((sec_r000107_9_1 >= 0) && (sec_r000107_9_1 <= 255));
  __CPROVER_assume((sec_r000107_9_2 >= 0) && (sec_r000107_9_2 <= 255));
  __CPROVER_assume((sec_r000107_10_1 >= 0) && (sec_r000107_10_1 <= 255));
  __CPROVER_assume((sec_r000107_10_2 >= 0) && (sec_r000107_10_2 <= 255));
  __CPROVER_assume((sec_r000107_11_1 >= 0) && (sec_r000107_11_1 <= 255));
  __CPROVER_assume((sec_r000107_11_2 >= 0) && (sec_r000107_11_2 <= 255));
  __CPROVER_assume((sec_r000107_12_1 >= 0) && (sec_r000107_12_1 <= 255));
  __CPROVER_assume((sec_r000107_12_2 >= 0) && (sec_r000107_12_2 <= 255));
  __CPROVER_assume((sec_r000107_13_1 >= 0) && (sec_r000107_13_1 <= 255));
  __CPROVER_assume((sec_r000107_13_2 >= 0) && (sec_r000107_13_2 <= 255));
  __CPROVER_assume((sec_r000107_14_1 >= 0) && (sec_r000107_14_1 <= 255));
  __CPROVER_assume((sec_r000107_14_2 >= 0) && (sec_r000107_14_2 <= 255));
  __CPROVER_assume((sec_r000107_15_1 >= 0) && (sec_r000107_15_1 <= 255));
  __CPROVER_assume((sec_r000107_15_2 >= 0) && (sec_r000107_15_2 <= 255));
  __CPROVER_assume((sec_r000107_16_1 >= 0) && (sec_r000107_16_1 <= 255));
  __CPROVER_assume((sec_r000107_16_2 >= 0) && (sec_r000107_16_2 <= 255));
  __CPROVER_assume((sec_r000107_17_1 >= 0) && (sec_r000107_17_1 <= 255));
  __CPROVER_assume((sec_r000107_17_2 >= 0) && (sec_r000107_17_2 <= 255));
  __CPROVER_assume((sec_r000107_18_1 >= 0) && (sec_r000107_18_1 <= 255));
  __CPROVER_assume((sec_r000107_18_2 >= 0) && (sec_r000107_18_2 <= 255));
  __CPROVER_assume((sec_r000107_19_1 >= 0) && (sec_r000107_19_1 <= 255));
  __CPROVER_assume((sec_r000107_19_2 >= 0) && (sec_r000107_19_2 <= 255));
  __CPROVER_assume((sec_r000107_20_1 >= 0) && (sec_r000107_20_1 <= 255));
  __CPROVER_assume((sec_r000107_20_2 >= 0) && (sec_r000107_20_2 <= 255));
  __CPROVER_assume((sec_r000107_21_1 >= 0) && (sec_r000107_21_1 <= 255));
  __CPROVER_assume((sec_r000107_21_2 >= 0) && (sec_r000107_21_2 <= 255));
  __CPROVER_assume((sec_r000107_22_1 >= 0) && (sec_r000107_22_1 <= 255));
  __CPROVER_assume((sec_r000107_22_2 >= 0) && (sec_r000107_22_2 <= 255));
  __CPROVER_assume((sec_r000107_23_1 >= 0) && (sec_r000107_23_1 <= 255));
  __CPROVER_assume((sec_r000107_23_2 >= 0) && (sec_r000107_23_2 <= 255));
  struct CipherContext_R000107_713_0 st_var_0_1 = {0};
  struct CipherContext_R000107_713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000107_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000107_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000107_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000107_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000107_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000107_0_2 + 7) & 15;
  struct FilterState_R000107_713_1 st_var_1_1 = {0};
  struct FilterState_R000107_713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000107_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000107_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000107_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000107_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000107_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000107_0_2 + 9) & 15;
  struct AudioFrame_R000107_713_2 st_var_2_1 = {0};
  struct AudioFrame_R000107_713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000107_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000107_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000107_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000107_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000107_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000107_0_2 + 11) & 15;
  union TelemetryField_R000107_713_0 u_var_1;
  union TelemetryField_R000107_713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 46)
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
  if (stage_v_2_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 46)
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
  int stage_v_3_1 = ((st_var_0_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_0_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 39)
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
  if (stage_v_3_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 39)
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
  int stage_v_4_1 = ((st_var_1_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_1_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 40)
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
  if (stage_v_4_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 40)
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
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
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
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 55)
    {
      chk_sum_1 ^= stage_v_7_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_7_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 55)
    {
      chk_sum_2 ^= stage_v_7_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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

  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 54)
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
  if (stage_v_11_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 54)
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
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 16) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 21) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = (st_var_1_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_1_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((sec_r000107_4_1 & 1) != 0)
  {
    if ((sec_r000107_19_1 & 2) != 0)
    {
      stage_v_24_1 = (pub_r000107_3_1 + 31) & 127;
    }
    else
    {
      stage_v_24_1 = (pub_r000107_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_1 = (pub_r000107_3_1 + 7) & 127;
  }
  if ((sec_r000107_4_2 & 1) != 0)
  {
    if ((sec_r000107_19_2 & 2) != 0)
    {
      stage_v_24_2 = (pub_r000107_3_2 + 31) & 127;
    }
    else
    {
      stage_v_24_2 = (pub_r000107_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_2 = (pub_r000107_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000107_19_1 & 2) != 0)
    {
      stage_v_25_1 = (pub_r000107_5_1 + 31) & 127;
    }
    else
    {
      stage_v_25_1 = (pub_r000107_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_1 = (pub_r000107_5_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000107_19_2 & 2) != 0)
    {
      stage_v_25_2 = (pub_r000107_5_2 + 31) & 127;
    }
    else
    {
      stage_v_25_2 = (pub_r000107_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_2 = (pub_r000107_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((sec_r000107_16_1 & 1) != 0)
  {
    if ((sec_r000107_0_1 & 2) != 0)
    {
      stage_v_26_1 = (pub_r000107_10_1 + 31) & 127;
    }
    else
    {
      stage_v_26_1 = (pub_r000107_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_1 = (pub_r000107_10_1 + 7) & 127;
  }
  if ((sec_r000107_16_2 & 1) != 0)
  {
    if ((sec_r000107_0_2 & 2) != 0)
    {
      stage_v_26_2 = (pub_r000107_10_2 + 31) & 127;
    }
    else
    {
      stage_v_26_2 = (pub_r000107_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_2 = (pub_r000107_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000107_23_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000107_20_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000107_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000107_20_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000107_23_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000107_20_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000107_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000107_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((sec_r000107_19_1 & 1) != 0)
  {
    if ((sec_r000107_11_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000107_3_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000107_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000107_3_1 + 7) & 127;
  }
  if ((sec_r000107_19_2 & 1) != 0)
  {
    if ((sec_r000107_11_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000107_3_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000107_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000107_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((sec_r000107_2_1 & 1) != 0)
  {
    if ((sec_r000107_0_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000107_12_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000107_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000107_12_1 + 7) & 127;
  }
  if ((sec_r000107_2_2 & 1) != 0)
  {
    if ((sec_r000107_0_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000107_12_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000107_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000107_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000107_17_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000107_9_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000107_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000107_9_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000107_17_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000107_9_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000107_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000107_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((sec_r000107_5_1 & 1) != 0)
  {
    if ((sec_r000107_7_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000107_7_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000107_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000107_7_1 + 7) & 127;
  }
  if ((sec_r000107_5_2 & 1) != 0)
  {
    if ((sec_r000107_7_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000107_7_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000107_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000107_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000107_1_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000107_15_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000107_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000107_15_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000107_1_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000107_15_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000107_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000107_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000107_0_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000107_5_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000107_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000107_5_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000107_0_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000107_5_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000107_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000107_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000107_6_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000107_16_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000107_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000107_16_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000107_6_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000107_16_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000107_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000107_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000107_3_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000107_3_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000107_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000107_3_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000107_3_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000107_3_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000107_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000107_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((sec_r000107_18_1 & 1) != 0)
  {
    if ((sec_r000107_22_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000107_12_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000107_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000107_12_1 + 7) & 127;
  }
  if ((sec_r000107_18_2 & 1) != 0)
  {
    if ((sec_r000107_22_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000107_12_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000107_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000107_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000107_12_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000107_11_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000107_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000107_11_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000107_12_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000107_11_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000107_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000107_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000107_17_1 & 1) != 0)
  {
    if ((sec_r000107_15_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000107_2_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000107_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000107_2_1 + 7) & 127;
  }
  if ((sec_r000107_17_2 & 1) != 0)
  {
    if ((sec_r000107_15_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000107_2_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000107_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000107_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((sec_r000107_16_1 & 1) != 0)
  {
    if ((sec_r000107_15_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000107_0_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000107_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000107_0_1 + 7) & 127;
  }
  if ((sec_r000107_16_2 & 1) != 0)
  {
    if ((sec_r000107_15_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000107_0_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000107_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000107_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000107_5_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000107_11_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000107_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000107_11_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000107_5_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000107_11_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000107_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000107_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((sec_r000107_3_1 & 1) != 0)
  {
    if ((sec_r000107_3_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000107_14_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000107_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000107_14_1 + 7) & 127;
  }
  if ((sec_r000107_3_2 & 1) != 0)
  {
    if ((sec_r000107_3_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000107_14_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000107_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000107_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000107_22_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000107_10_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000107_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000107_10_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000107_22_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000107_10_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000107_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000107_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000107_21_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000107_11_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000107_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000107_11_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000107_21_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000107_11_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000107_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000107_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000107_15_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000107_15_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000107_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000107_15_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000107_15_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000107_15_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000107_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000107_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((sec_r000107_15_1 & 1) != 0)
  {
    if ((sec_r000107_10_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000107_10_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000107_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000107_10_1 + 7) & 127;
  }
  if ((sec_r000107_15_2 & 1) != 0)
  {
    if ((sec_r000107_10_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000107_10_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000107_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000107_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000107_9_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000107_6_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000107_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000107_6_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000107_9_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000107_6_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000107_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000107_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000107_10_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000107_1_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000107_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000107_1_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000107_10_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000107_1_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000107_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000107_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000107_15_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000107_2_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000107_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000107_2_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000107_15_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000107_2_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000107_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000107_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000107_18_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000107_11_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000107_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000107_11_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000107_18_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000107_11_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000107_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000107_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000107_3_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000107_18_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000107_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000107_18_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000107_3_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000107_18_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000107_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000107_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000107_14_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000107_2_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000107_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000107_2_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000107_14_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000107_2_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000107_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000107_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000107_3_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000107_8_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000107_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000107_8_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000107_3_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000107_8_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000107_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000107_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000107_13_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000107_9_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000107_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000107_9_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000107_13_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000107_9_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000107_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000107_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000107_21_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000107_12_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000107_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000107_12_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000107_21_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000107_12_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000107_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000107_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000107_11_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000107_2_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000107_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000107_2_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000107_11_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000107_2_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000107_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000107_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000107_23_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000107_12_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000107_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000107_12_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000107_23_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000107_12_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000107_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000107_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000107_8_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000107_21_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000107_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000107_21_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000107_8_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000107_21_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000107_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000107_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000107_16_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000107_2_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000107_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000107_2_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000107_16_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000107_2_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000107_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000107_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000107_3_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000107_14_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000107_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000107_14_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000107_3_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000107_14_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000107_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000107_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000107_18_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000107_6_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000107_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000107_6_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000107_18_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000107_6_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000107_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000107_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000107_19_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000107_9_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000107_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000107_9_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000107_19_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000107_9_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000107_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000107_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000107_0_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000107_6_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000107_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000107_6_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000107_0_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000107_6_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000107_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000107_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((sec_r000107_20_1 & 1) != 0)
  {
    if ((sec_r000107_12_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000107_19_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000107_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000107_19_1 + 7) & 127;
  }
  if ((sec_r000107_20_2 & 1) != 0)
  {
    if ((sec_r000107_12_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000107_19_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000107_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000107_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000107_2_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000107_3_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000107_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000107_3_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000107_2_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000107_3_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000107_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000107_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((sec_r000107_14_1 & 1) != 0)
  {
    if ((sec_r000107_16_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000107_8_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000107_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000107_8_1 + 7) & 127;
  }
  if ((sec_r000107_14_2 & 1) != 0)
  {
    if ((sec_r000107_16_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000107_8_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000107_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000107_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000107_13_1 & 1) != 0)
  {
    if ((sec_r000107_17_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000107_4_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000107_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000107_4_1 + 7) & 127;
  }
  if ((sec_r000107_13_2 & 1) != 0)
  {
    if ((sec_r000107_17_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000107_4_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000107_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000107_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000107_19_1 & 1) != 0)
  {
    if ((sec_r000107_1_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000107_15_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000107_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000107_15_1 + 7) & 127;
  }
  if ((sec_r000107_19_2 & 1) != 0)
  {
    if ((sec_r000107_1_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000107_15_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000107_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000107_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000107_20_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000107_3_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000107_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000107_3_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000107_20_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000107_3_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000107_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000107_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000107_2_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000107_20_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000107_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000107_20_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000107_2_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000107_20_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000107_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000107_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000107_1_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000107_6_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000107_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000107_6_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000107_1_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000107_6_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000107_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000107_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000107_20_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000107_0_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000107_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000107_0_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000107_20_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000107_0_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000107_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000107_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000107_15_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000107_19_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000107_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000107_19_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000107_15_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000107_19_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000107_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000107_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000107_5_1 & 1) != 0)
  {
    if ((sec_r000107_18_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000107_16_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000107_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000107_16_1 + 7) & 127;
  }
  if ((sec_r000107_5_2 & 1) != 0)
  {
    if ((sec_r000107_18_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000107_16_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000107_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000107_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000107_0_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000107_3_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000107_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000107_3_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000107_0_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000107_3_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000107_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000107_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000107_8_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000107_2_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000107_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000107_2_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000107_8_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000107_2_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000107_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000107_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000107_2_1 & 1) != 0)
  {
    if ((sec_r000107_9_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000107_5_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000107_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000107_5_1 + 7) & 127;
  }
  if ((sec_r000107_2_2 & 1) != 0)
  {
    if ((sec_r000107_9_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000107_5_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000107_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000107_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000107_14_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000107_13_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000107_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000107_13_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000107_14_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000107_13_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000107_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000107_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000107_4_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000107_19_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000107_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000107_19_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000107_4_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000107_19_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000107_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000107_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000107_1_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000107_11_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000107_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000107_11_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000107_1_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000107_11_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000107_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000107_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000107_14_1 & 1) != 0)
  {
    if ((sec_r000107_17_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000107_3_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000107_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000107_3_1 + 7) & 127;
  }
  if ((sec_r000107_14_2 & 1) != 0)
  {
    if ((sec_r000107_17_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000107_3_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000107_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000107_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000107_16_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000107_17_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000107_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000107_17_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000107_16_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000107_17_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000107_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000107_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000107_5_1 & 1) != 0)
  {
    if ((sec_r000107_13_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000107_20_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000107_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000107_20_1 + 7) & 127;
  }
  if ((sec_r000107_5_2 & 1) != 0)
  {
    if ((sec_r000107_13_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000107_20_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000107_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000107_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000107_5_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000107_7_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000107_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000107_7_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000107_5_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000107_7_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000107_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000107_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000107_11_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000107_8_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000107_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000107_8_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000107_11_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000107_8_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000107_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000107_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000107_10_1 & 1) != 0)
  {
    if ((sec_r000107_6_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000107_22_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000107_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000107_22_1 + 7) & 127;
  }
  if ((sec_r000107_10_2 & 1) != 0)
  {
    if ((sec_r000107_6_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000107_22_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000107_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000107_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000107_21_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000107_5_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000107_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000107_5_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000107_21_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000107_5_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000107_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000107_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000107_18_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000107_17_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000107_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000107_17_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000107_18_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000107_17_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000107_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000107_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000107_21_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000107_17_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000107_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000107_17_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000107_21_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000107_17_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000107_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000107_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000107_5_1 & 1) != 0)
  {
    if ((sec_r000107_1_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000107_13_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000107_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000107_13_1 + 7) & 127;
  }
  if ((sec_r000107_5_2 & 1) != 0)
  {
    if ((sec_r000107_1_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000107_13_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000107_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000107_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000107_5_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000107_13_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000107_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000107_13_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000107_5_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000107_13_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000107_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000107_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000107_17_1 & 1) != 0)
  {
    if ((sec_r000107_9_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000107_20_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000107_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000107_20_1 + 7) & 127;
  }
  if ((sec_r000107_17_2 & 1) != 0)
  {
    if ((sec_r000107_9_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000107_20_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000107_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000107_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000107_1_1 & 1) != 0)
  {
    if ((sec_r000107_0_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000107_4_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000107_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000107_4_1 + 7) & 127;
  }
  if ((sec_r000107_1_2 & 1) != 0)
  {
    if ((sec_r000107_0_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000107_4_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000107_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000107_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000107_17_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000107_5_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000107_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000107_5_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000107_17_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000107_5_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000107_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000107_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000107_2_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000107_17_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000107_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000107_17_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000107_2_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000107_17_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000107_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000107_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000107_10_1 & 1) != 0)
  {
    if ((sec_r000107_2_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000107_8_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000107_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000107_8_1 + 7) & 127;
  }
  if ((sec_r000107_10_2 & 1) != 0)
  {
    if ((sec_r000107_2_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000107_8_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000107_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000107_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000107_15_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000107_19_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000107_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000107_19_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000107_15_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000107_19_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000107_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000107_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000107_13_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000107_12_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000107_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000107_12_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000107_13_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000107_12_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000107_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000107_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000107_8_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000107_21_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000107_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000107_21_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000107_8_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000107_21_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000107_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000107_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000107_21_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000107_22_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000107_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000107_22_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000107_21_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000107_22_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000107_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000107_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000107_1_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000107_19_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000107_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000107_19_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000107_1_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000107_19_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000107_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000107_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000107_10_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000107_4_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000107_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000107_4_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000107_10_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000107_4_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000107_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000107_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000107_9_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000107_11_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000107_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000107_11_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000107_9_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000107_11_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000107_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000107_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000107_19_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000107_0_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000107_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000107_0_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000107_19_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000107_0_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000107_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000107_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000107_19_1 & 1) != 0)
  {
    if ((sec_r000107_23_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000107_3_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000107_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000107_3_1 + 7) & 127;
  }
  if ((sec_r000107_19_2 & 1) != 0)
  {
    if ((sec_r000107_23_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000107_3_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000107_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000107_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000107_17_1 & 1) != 0)
  {
    if ((sec_r000107_23_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000107_2_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000107_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000107_2_1 + 7) & 127;
  }
  if ((sec_r000107_17_2 & 1) != 0)
  {
    if ((sec_r000107_23_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000107_2_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000107_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000107_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000107_3_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000107_18_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000107_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000107_18_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000107_3_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000107_18_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000107_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000107_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000107_20_1 & 1) != 0)
  {
    if ((sec_r000107_2_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000107_18_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000107_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000107_18_1 + 7) & 127;
  }
  if ((sec_r000107_20_2 & 1) != 0)
  {
    if ((sec_r000107_2_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000107_18_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000107_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000107_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000107_5_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000107_19_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000107_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000107_19_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000107_5_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000107_19_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000107_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000107_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000107_3_1 & 1) != 0)
  {
    if ((sec_r000107_17_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000107_20_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000107_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000107_20_1 + 7) & 127;
  }
  if ((sec_r000107_3_2 & 1) != 0)
  {
    if ((sec_r000107_17_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000107_20_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000107_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000107_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000107_23_1 & 1) != 0)
  {
    if ((sec_r000107_12_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000107_12_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000107_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000107_12_1 + 7) & 127;
  }
  if ((sec_r000107_23_2 & 1) != 0)
  {
    if ((sec_r000107_12_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000107_12_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000107_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000107_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000107_3_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000107_2_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000107_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000107_2_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000107_3_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000107_2_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000107_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000107_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000107_20_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000107_11_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000107_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000107_11_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000107_20_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000107_11_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000107_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000107_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000107_3_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000107_15_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000107_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000107_15_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000107_3_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000107_15_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000107_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000107_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000107_21_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000107_20_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000107_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000107_20_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000107_21_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000107_20_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000107_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000107_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000107_4_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000107_11_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000107_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000107_11_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000107_4_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000107_11_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000107_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000107_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000107_8_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000107_7_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000107_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000107_7_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000107_8_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000107_7_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000107_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000107_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000107_23_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000107_22_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000107_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000107_22_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000107_23_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000107_22_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000107_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000107_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000107_10_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000107_17_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000107_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000107_17_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000107_10_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000107_17_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000107_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000107_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000107_20_1 & 1) != 0)
  {
    if ((sec_r000107_6_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000107_3_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000107_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000107_3_1 + 7) & 127;
  }
  if ((sec_r000107_20_2 & 1) != 0)
  {
    if ((sec_r000107_6_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000107_3_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000107_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000107_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000107_19_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000107_6_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000107_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000107_6_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000107_19_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000107_6_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000107_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000107_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000107_17_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000107_16_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000107_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000107_16_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000107_17_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000107_16_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000107_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000107_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000107_20_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000107_16_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000107_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000107_16_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000107_20_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000107_16_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000107_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000107_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000107_5_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000107_16_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000107_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000107_16_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000107_5_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000107_16_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000107_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000107_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000107_23_1 & 1) != 0)
  {
    if ((sec_r000107_13_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000107_19_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000107_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000107_19_1 + 7) & 127;
  }
  if ((sec_r000107_23_2 & 1) != 0)
  {
    if ((sec_r000107_13_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000107_19_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000107_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000107_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000107_20_1 & 1) != 0)
  {
    if ((sec_r000107_0_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000107_18_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000107_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000107_18_1 + 7) & 127;
  }
  if ((sec_r000107_20_2 & 1) != 0)
  {
    if ((sec_r000107_0_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000107_18_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000107_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000107_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000107_14_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000107_9_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000107_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000107_9_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000107_14_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000107_9_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000107_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000107_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000107_19_1 & 1) != 0)
  {
    if ((sec_r000107_20_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000107_0_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000107_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000107_0_1 + 7) & 127;
  }
  if ((sec_r000107_19_2 & 1) != 0)
  {
    if ((sec_r000107_20_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000107_0_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000107_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000107_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000107_0_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000107_9_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000107_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000107_9_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000107_0_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000107_9_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000107_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000107_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000107_11_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000107_11_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000107_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000107_11_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000107_11_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000107_11_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000107_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000107_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000107_3_1 & 1) != 0)
  {
    if ((sec_r000107_23_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000107_8_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000107_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000107_8_1 + 7) & 127;
  }
  if ((sec_r000107_3_2 & 1) != 0)
  {
    if ((sec_r000107_23_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000107_8_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000107_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000107_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000107_0_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000107_20_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000107_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000107_20_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000107_0_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000107_20_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000107_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000107_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000107_9_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000107_4_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000107_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000107_4_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000107_9_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000107_4_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000107_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000107_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000107_23_1 & 1) != 0)
  {
    if ((sec_r000107_22_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000107_0_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000107_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000107_0_1 + 7) & 127;
  }
  if ((sec_r000107_23_2 & 1) != 0)
  {
    if ((sec_r000107_22_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000107_0_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000107_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000107_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000107_7_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000107_22_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000107_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000107_22_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000107_7_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000107_22_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000107_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000107_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000107_10_1 & 1) != 0)
  {
    if ((sec_r000107_16_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000107_21_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000107_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000107_21_1 + 7) & 127;
  }
  if ((sec_r000107_10_2 & 1) != 0)
  {
    if ((sec_r000107_16_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000107_21_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000107_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000107_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000107_20_1 & 1) != 0)
  {
    if ((sec_r000107_18_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000107_5_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000107_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000107_5_1 + 7) & 127;
  }
  if ((sec_r000107_20_2 & 1) != 0)
  {
    if ((sec_r000107_18_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000107_5_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000107_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000107_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000107_23_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000107_9_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000107_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000107_9_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000107_23_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000107_9_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000107_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000107_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000107_22_1 & 1) != 0)
  {
    if ((sec_r000107_4_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000107_1_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000107_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000107_1_1 + 7) & 127;
  }
  if ((sec_r000107_22_2 & 1) != 0)
  {
    if ((sec_r000107_4_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000107_1_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000107_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000107_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000107_5_1 & 1) != 0)
  {
    if ((sec_r000107_12_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000107_1_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000107_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000107_1_1 + 7) & 127;
  }
  if ((sec_r000107_5_2 & 1) != 0)
  {
    if ((sec_r000107_12_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000107_1_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000107_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000107_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000107_14_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000107_19_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000107_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000107_19_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000107_14_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000107_19_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000107_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000107_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000107_17_1 & 1) != 0)
  {
    if ((sec_r000107_1_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000107_2_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000107_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000107_2_1 + 7) & 127;
  }
  if ((sec_r000107_17_2 & 1) != 0)
  {
    if ((sec_r000107_1_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000107_2_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000107_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000107_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000107_3_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000107_1_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000107_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000107_1_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000107_3_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000107_1_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000107_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000107_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000107_2_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000107_16_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000107_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000107_16_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000107_2_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000107_16_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000107_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000107_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000107_2_1 & 1) != 0)
  {
    if ((sec_r000107_16_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000107_18_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000107_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000107_18_1 + 7) & 127;
  }
  if ((sec_r000107_2_2 & 1) != 0)
  {
    if ((sec_r000107_16_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000107_18_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000107_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000107_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000107_9_1 & 1) != 0)
  {
    if ((sec_r000107_16_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000107_8_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000107_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000107_8_1 + 7) & 127;
  }
  if ((sec_r000107_9_2 & 1) != 0)
  {
    if ((sec_r000107_16_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000107_8_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000107_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000107_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000107_15_1 != sec_r000107_15_2);
  __CPROVER_assume(pub_r000107_19_1 == pub_r000107_19_2);
  __CPROVER_assume(pub_r000107_9_1 == pub_r000107_9_2);
  __CPROVER_assume(sec_r000107_8_1 != sec_r000107_8_2);
  __CPROVER_assume(sec_r000107_3_1 != sec_r000107_3_2);
  __CPROVER_assume(pub_r000107_4_1 == pub_r000107_4_2);
  __CPROVER_assume(pub_r000107_5_1 == pub_r000107_5_2);
  __CPROVER_assume(pub_r000107_15_1 == pub_r000107_15_2);
  __CPROVER_assume(sec_r000107_13_1 != sec_r000107_13_2);
  __CPROVER_assume(sec_r000107_2_1 != sec_r000107_2_2);
  __CPROVER_assume(pub_r000107_2_1 == pub_r000107_2_2);
  __CPROVER_assume(pub_r000107_6_1 == pub_r000107_6_2);
  __CPROVER_assume(pub_r000107_12_1 == pub_r000107_12_2);
  __CPROVER_assume(pub_r000107_0_1 == pub_r000107_0_2);
  __CPROVER_assume(sec_r000107_4_1 != sec_r000107_4_2);
  __CPROVER_assume(pub_r000107_7_1 == pub_r000107_7_2);
  __CPROVER_assume(sec_r000107_7_1 != sec_r000107_7_2);
  __CPROVER_assume(sec_r000107_6_1 != sec_r000107_6_2);
  __CPROVER_assume(pub_r000107_3_1 == pub_r000107_3_2);
  __CPROVER_assume(sec_r000107_10_1 != sec_r000107_10_2);
  __CPROVER_assume(pub_r000107_17_1 == pub_r000107_17_2);
  __CPROVER_assume(sec_r000107_18_1 != sec_r000107_18_2);
  __CPROVER_assume(sec_r000107_23_1 != sec_r000107_23_2);
  __CPROVER_assume(pub_r000107_13_1 == pub_r000107_13_2);
  __CPROVER_assume(pub_r000107_10_1 == pub_r000107_10_2);
  __CPROVER_assume(pub_r000107_11_1 == pub_r000107_11_2);
  __CPROVER_assume(sec_r000107_16_1 != sec_r000107_16_2);
  __CPROVER_assume(pub_r000107_18_1 == pub_r000107_18_2);
  __CPROVER_assume(pub_r000107_16_1 == pub_r000107_16_2);
  __CPROVER_assume(sec_r000107_22_1 != sec_r000107_22_2);
  __CPROVER_assume(sec_r000107_21_1 != sec_r000107_21_2);
  __CPROVER_assume(sec_r000107_9_1 != sec_r000107_9_2);
  __CPROVER_assume(sec_r000107_1_1 != sec_r000107_1_2);
  __CPROVER_assume(sec_r000107_20_1 != sec_r000107_20_2);
  __CPROVER_assume(pub_r000107_1_1 == pub_r000107_1_2);
  __CPROVER_assume(sec_r000107_12_1 != sec_r000107_12_2);
  __CPROVER_assume(pub_r000107_8_1 == pub_r000107_8_2);
  __CPROVER_assume(sec_r000107_14_1 != sec_r000107_14_2);
  __CPROVER_assume(pub_r000107_20_1 == pub_r000107_20_2);
  __CPROVER_assume(sec_r000107_11_1 != sec_r000107_11_2);
  __CPROVER_assume(pub_r000107_21_1 == pub_r000107_21_2);
  __CPROVER_assume(sec_r000107_0_1 != sec_r000107_0_2);
  __CPROVER_assume(pub_r000107_14_1 == pub_r000107_14_2);
  __CPROVER_assume(sec_r000107_5_1 != sec_r000107_5_2);
  __CPROVER_assume(sec_r000107_17_1 != sec_r000107_17_2);
  __CPROVER_assume(sec_r000107_19_1 != sec_r000107_19_2);
  __CPROVER_assume(pub_r000107_22_1 == pub_r000107_22_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.peak == st_var_2_2.peak);
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
}


