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
struct FilterState_R001040_4013_0
{
  short gain_db;
  int prev_in;
  unsigned char mode;
  int damping;
  int cutoff;
  unsigned char prev_out;
  int buffer[3];
};
struct CipherContext_R001040_4013_1
{
  int tag;
  int counter;
  int round_key;
  int nonce;
  int buffer[3];
};
union RegisterBank_R001040_4013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001040_4013_1
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
void fn_R001040_4013_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st_1 = {0};
  struct CipherContext_R001040_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int bound_84_1 = 0;
  int bound_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_84_1 = ((bound_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_84_2 = ((bound_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_84_1) & 127;
    acc_2 = (acc_2 + bound_84_2) & 127;
  }

  int offset_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_20_1)
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

  switch (offset_20_2)
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

  int anchor_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_21_1 > 35)
  {
    acc_1 = ((acc_1 + (anchor_21_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_21_2 > 35)
  {
    acc_2 = ((acc_2 + (anchor_21_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_21_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_84_1 == bound_84_2);
  assert(offset_20_1 == offset_20_2);
  assert(anchor_21_1 == anchor_21_2);
}

int fn_R001040_4013_0(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int bound_84 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_84 = ((bound_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_84) & 127;
  }

  int offset_20 = (aux + st.buffer[1]) & 3;
  switch (offset_20)
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

  int anchor_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_21 > 35)
  {
    acc = ((acc + (anchor_21 * 2)) + 5) & 127;
    aux ^= anchor_21 & 15;
  }
  else
  {
    acc = ((acc - anchor_21) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001040_4013_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st_1 = {0};
  struct CipherContext_R001040_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_48_1)
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

  switch (stride_48_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_48_1 == stride_48_2);
}

int fn_R001040_4013_1(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_48 = (aux + st.buffer[1]) & 3;
  switch (stride_48)
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

void fn_R001040_4013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st_1 = {0};
  struct FilterState_R001040_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_54_1 = local_arr_1[aux_1 % 3];
  int segment_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_54_2 * 2)) & 127;
  int anchor_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_10_1)
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

  switch (anchor_10_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_54_1 == segment_54_2);
  assert(anchor_10_1 == anchor_10_2);
}

int fn_R001040_4013_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int segment_54 = local_arr[aux % 3];
  acc = (acc + (segment_54 * 2)) & 127;
  int anchor_10 = (aux + st.buffer[1]) & 3;
  switch (anchor_10)
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

void fn_R001040_4013_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st_1 = {0};
  struct CipherContext_R001040_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int phase_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_31_1)
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

  switch (phase_31_2)
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

  int sample_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_79_1 > 23)
  {
    acc_1 = ((acc_1 + (sample_79_1 * 2)) + 5) & 127;
    aux_1 ^= sample_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_79_2 > 23)
  {
    acc_2 = ((acc_2 + (sample_79_2 * 2)) + 5) & 127;
    aux_2 ^= sample_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_36_1 = local_arr_1[aux_1 % 3];
  int segment_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_31_1 == phase_31_2);
  assert(sample_79_1 == sample_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_36_1 == segment_36_2);
}

int fn_R001040_4013_3(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int phase_31 = (aux + st.buffer[1]) & 3;
  switch (phase_31)
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

  int sample_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_79 > 23)
  {
    acc = ((acc + (sample_79 * 2)) + 5) & 127;
    aux ^= sample_79 & 15;
  }
  else
  {
    acc = ((acc - sample_79) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_36 = local_arr[aux % 3];
  acc = (acc + (segment_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001040_4013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st_1 = {0};
  struct FilterState_R001040_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_28_1)
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

  switch (accumulator_28_2)
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

  int bound_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_85_1 > 20)
  {
    acc_1 = ((acc_1 + (bound_85_1 * 2)) + 5) & 127;
    aux_1 ^= bound_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_85_2 > 20)
  {
    acc_2 = ((acc_2 + (bound_85_2 * 2)) + 5) & 127;
    aux_2 ^= bound_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_96_1 = local_arr_1[aux_1 % 3];
  int tally_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_28_1 == accumulator_28_2);
  assert(bound_85_1 == bound_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_96_1 == tally_96_2);
}

int fn_R001040_4013_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_28 = (aux + st.buffer[1]) & 3;
  switch (accumulator_28)
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

  int bound_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_85 > 20)
  {
    acc = ((acc + (bound_85 * 2)) + 5) & 127;
    aux ^= bound_85 & 15;
  }
  else
  {
    acc = ((acc - bound_85) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_96 = local_arr[aux % 3];
  acc = (acc + (tally_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001040_4013_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st_1 = {0};
  struct CipherContext_R001040_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int vector_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_91_1)
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

  switch (vector_91_2)
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

  int delta_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_48_1 > 30)
  {
    acc_1 = ((acc_1 + (delta_48_1 * 2)) + 5) & 127;
    aux_1 ^= delta_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_48_2 > 30)
  {
    acc_2 = ((acc_2 + (delta_48_2 * 2)) + 5) & 127;
    aux_2 ^= delta_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_48_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_91_1 == vector_91_2);
  assert(delta_48_1 == delta_48_2);
}

int fn_R001040_4013_5(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int vector_91 = (aux + st.buffer[1]) & 3;
  switch (vector_91)
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

  int delta_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_48 > 30)
  {
    acc = ((acc + (delta_48 * 2)) + 5) & 127;
    aux ^= delta_48 & 15;
  }
  else
  {
    acc = ((acc - delta_48) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001040_4013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st_1 = {0};
  struct CipherContext_R001040_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int factor_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_16_1)
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

  switch (factor_16_2)
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

  int cursor_81_1 = 0;
  int cursor_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_81_1 = ((cursor_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_81_2 = ((cursor_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_81_1) & 127;
    acc_2 = (acc_2 + cursor_81_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_16_1 == factor_16_2);
  assert(cursor_81_1 == cursor_81_2);
}

int fn_R001040_4013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int factor_16 = (aux + st.buffer[1]) & 3;
  switch (factor_16)
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

  int cursor_81 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_81 = ((cursor_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_81) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001040_4013_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st_1 = {0};
  struct CipherContext_R001040_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_19_1) & 63;
  aux_2 = (aux_2 + coefficient_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_19_1 == coefficient_19_2);
}

int fn_R001040_4013_7(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_19) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001040_4013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st_1 = {0};
  struct CipherContext_R001040_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int coefficient_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_47_1) & 63;
  aux_2 = (aux_2 + coefficient_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_26_1 = local_arr_1[aux_1 % 3];
  int quantum_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_26_2 * 2)) & 127;
  int tally_41_1 = 0;
  int tally_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_41_1 = ((tally_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_41_2 = ((tally_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_41_1) & 127;
    acc_2 = (acc_2 + tally_41_2) & 127;
  }

  int sample_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_72_1 > 30)
  {
    acc_1 = ((acc_1 + (sample_72_1 * 2)) + 5) & 127;
    aux_1 ^= sample_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_72_2 > 30)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_47_1 == coefficient_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_26_1 == quantum_26_2);
  assert(tally_41_1 == tally_41_2);
  assert(sample_72_1 == sample_72_2);
}

int fn_R001040_4013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int coefficient_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_47) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_26 = local_arr[aux % 3];
  acc = (acc + (quantum_26 * 2)) & 127;
  int tally_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_41 = ((tally_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_41) & 127;
  }

  int sample_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_72 > 30)
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

void fn_R001040_4013_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st_1 = {0};
  struct FilterState_R001040_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int pivot_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_47_1)
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

  switch (pivot_47_2)
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

  int margin_94_1 = 0;
  int margin_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_94_1 = ((margin_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_94_2 = ((margin_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_94_1) & 127;
    acc_2 = (acc_2 + margin_94_2) & 127;
  }

  int scale_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_84_1 > 24)
  {
    acc_1 = ((acc_1 + (scale_84_1 * 2)) + 5) & 127;
    aux_1 ^= scale_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_84_2 > 24)
  {
    acc_2 = ((acc_2 + (scale_84_2 * 2)) + 5) & 127;
    aux_2 ^= scale_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_47_1 == pivot_47_2);
  assert(margin_94_1 == margin_94_2);
  assert(scale_84_1 == scale_84_2);
}

int fn_R001040_4013_9(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int pivot_47 = (aux + st.buffer[1]) & 3;
  switch (pivot_47)
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

  int margin_94 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_94 = ((margin_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_94) & 127;
  }

  int scale_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_84 > 24)
  {
    acc = ((acc + (scale_84 * 2)) + 5) & 127;
    aux ^= scale_84 & 15;
  }
  else
  {
    acc = ((acc - scale_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001040_4013_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st_1 = {0};
  struct CipherContext_R001040_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int bound_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_28_1 > 26)
  {
    acc_1 = ((acc_1 + (bound_28_1 * 2)) + 5) & 127;
    aux_1 ^= bound_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_28_2 > 26)
  {
    acc_2 = ((acc_2 + (bound_28_2 * 2)) + 5) & 127;
    aux_2 ^= bound_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_97_1 = local_arr_1[aux_1 % 3];
  int weight_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_28_1 == bound_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_97_1 == weight_97_2);
}

int fn_R001040_4013_10(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int bound_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_28 > 26)
  {
    acc = ((acc + (bound_28 * 2)) + 5) & 127;
    aux ^= bound_28 & 15;
  }
  else
  {
    acc = ((acc - bound_28) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int weight_97 = local_arr[aux % 3];
  acc = (acc + (weight_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001040_4013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st_1 = {0};
  struct FilterState_R001040_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int anchor_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_61_1)
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

  switch (anchor_61_2)
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

  int quantum_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_90_1) & 63;
  aux_2 = (aux_2 + quantum_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_99_1 = local_arr_1[aux_1 % 3];
  int mask_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_61_1 == anchor_61_2);
  assert(quantum_90_1 == quantum_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_99_1 == mask_99_2);
}

int fn_R001040_4013_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int anchor_61 = (aux + st.buffer[1]) & 3;
  switch (anchor_61)
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

  int quantum_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_90) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_99 = local_arr[aux % 3];
  acc = (acc + (mask_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001040_4013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st_1 = {0};
  struct FilterState_R001040_4013_0 st_2 = {0};
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
  int margin_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_51_1)
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

  switch (margin_51_2)
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
  int sample_51_1 = local_arr_1[aux_1 % 3];
  int sample_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_51_1 == margin_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_51_1 == sample_51_2);
}

int fn_R001040_4013_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_51 = (aux + st.buffer[1]) & 3;
  switch (margin_51)
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
  int sample_51 = local_arr[aux % 3];
  acc = (acc + (sample_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001040_4013_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st_1 = {0};
  struct CipherContext_R001040_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int factor_90_1 = 0;
  int factor_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_90_1 = ((factor_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_90_2 = ((factor_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_90_1) & 127;
    acc_2 = (acc_2 + factor_90_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_24_1 = local_arr_1[aux_1 % 3];
  int vector_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_24_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_90_1 == factor_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_24_1 == vector_24_2);
}

int fn_R001040_4013_13(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int factor_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_90 = ((factor_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_90) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int vector_24 = local_arr[aux % 3];
  acc = (acc + (vector_24 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001040_4013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st_1 = {0};
  struct CipherContext_R001040_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int residue_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_99_1 > 19)
  {
    acc_1 = ((acc_1 + (residue_99_1 * 2)) + 5) & 127;
    aux_1 ^= residue_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_99_2 > 19)
  {
    acc_2 = ((acc_2 + (residue_99_2 * 2)) + 5) & 127;
    aux_2 ^= residue_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_91_1) & 63;
  aux_2 = (aux_2 + checksum_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_27_1)
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

  switch (tracker_27_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_99_1 == residue_99_2);
  assert(checksum_91_1 == checksum_91_2);
  assert(tracker_27_1 == tracker_27_2);
}

int fn_R001040_4013_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int residue_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_99 > 19)
  {
    acc = ((acc + (residue_99 * 2)) + 5) & 127;
    aux ^= residue_99 & 15;
  }
  else
  {
    acc = ((acc - residue_99) + 11) & 127;
    aux += 3;
  }
  int checksum_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_91) & 63;
  acc ^= aux;
  int tracker_27 = (aux + st.buffer[1]) & 3;
  switch (tracker_27)
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

void fn_R001040_4013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st_1 = {0};
  struct CipherContext_R001040_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_63_1 = 0;
  int metric_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_63_1 = ((metric_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_63_2 = ((metric_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_63_1) & 127;
    acc_2 = (acc_2 + metric_63_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_53_1)
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

  switch (stride_53_2)
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

  int margin_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_77_1) & 63;
  aux_2 = (aux_2 + margin_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_63_1 == metric_63_2);
  assert(stride_53_1 == stride_53_2);
  assert(margin_77_1 == margin_77_2);
}

int fn_R001040_4013_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001040_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_63 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_63 = ((metric_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_63) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_53 = (aux + st.buffer[1]) & 3;
  switch (stride_53)
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

  int margin_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_77) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001040_4013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st_1 = {0};
  struct FilterState_R001040_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int delta_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_36_1) & 63;
  aux_2 = (aux_2 + delta_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_33_1 = local_arr_1[aux_1 % 3];
  int metric_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_33_2 * 2)) & 127;
  int vector_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_29_1)
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

  switch (vector_29_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_36_1 == delta_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_33_1 == metric_33_2);
  assert(vector_29_1 == vector_29_2);
}

int fn_R001040_4013_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001040_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int delta_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_36) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_33 = local_arr[aux % 3];
  acc = (acc + (metric_33 * 2)) & 127;
  int vector_29 = (aux + st.buffer[1]) & 3;
  switch (vector_29)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001040_0_1;
  int sec_r001040_0_2;
  int sec_r001040_1_1;
  int sec_r001040_1_2;
  int sec_r001040_2_1;
  int sec_r001040_2_2;
  int sec_r001040_3_1;
  int sec_r001040_3_2;
  int sec_r001040_4_1;
  int sec_r001040_4_2;
  int sec_r001040_5_1;
  int sec_r001040_5_2;
  int sec_r001040_6_1;
  int sec_r001040_6_2;
  int sec_r001040_7_1;
  int sec_r001040_7_2;
  int sec_r001040_8_1;
  int sec_r001040_8_2;
  int sec_r001040_9_1;
  int sec_r001040_9_2;
  int sec_r001040_10_1;
  int sec_r001040_10_2;
  int sec_r001040_11_1;
  int sec_r001040_11_2;
  int sec_r001040_12_1;
  int sec_r001040_12_2;
  int sec_r001040_13_1;
  int sec_r001040_13_2;
  int sec_r001040_14_1;
  int sec_r001040_14_2;
  int sec_r001040_15_1;
  int sec_r001040_15_2;
  int sec_r001040_16_1;
  int sec_r001040_16_2;
  int sec_r001040_17_1;
  int sec_r001040_17_2;
  int sec_r001040_18_1;
  int sec_r001040_18_2;
  int pub_r001040_0_1;
  int pub_r001040_0_2;
  int pub_r001040_1_1;
  int pub_r001040_1_2;
  int pub_r001040_2_1;
  int pub_r001040_2_2;
  int pub_r001040_3_1;
  int pub_r001040_3_2;
  int pub_r001040_4_1;
  int pub_r001040_4_2;
  int pub_r001040_5_1;
  int pub_r001040_5_2;
  int pub_r001040_6_1;
  int pub_r001040_6_2;
  int pub_r001040_7_1;
  int pub_r001040_7_2;
  int pub_r001040_8_1;
  int pub_r001040_8_2;
  int pub_r001040_9_1;
  int pub_r001040_9_2;
  int pub_r001040_10_1;
  int pub_r001040_10_2;
  int pub_r001040_11_1;
  int pub_r001040_11_2;
  int pub_r001040_12_1;
  int pub_r001040_12_2;
  int pub_r001040_13_1;
  int pub_r001040_13_2;
  int pub_r001040_14_1;
  int pub_r001040_14_2;
  int pub_r001040_15_1;
  int pub_r001040_15_2;
  int pub_r001040_16_1;
  int pub_r001040_16_2;
  int pub_r001040_17_1;
  int pub_r001040_17_2;
  int pub_r001040_18_1;
  int pub_r001040_18_2;
  int pub_r001040_19_1;
  int pub_r001040_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001040_0_1 >= (-100)) && (pub_r001040_0_1 <= 100));
  __CPROVER_assume((pub_r001040_0_2 >= (-100)) && (pub_r001040_0_2 <= 100));
  __CPROVER_assume((pub_r001040_1_1 >= (-100)) && (pub_r001040_1_1 <= 100));
  __CPROVER_assume((pub_r001040_1_2 >= (-100)) && (pub_r001040_1_2 <= 100));
  __CPROVER_assume((pub_r001040_2_1 >= (-100)) && (pub_r001040_2_1 <= 100));
  __CPROVER_assume((pub_r001040_2_2 >= (-100)) && (pub_r001040_2_2 <= 100));
  __CPROVER_assume((pub_r001040_3_1 >= (-100)) && (pub_r001040_3_1 <= 100));
  __CPROVER_assume((pub_r001040_3_2 >= (-100)) && (pub_r001040_3_2 <= 100));
  __CPROVER_assume((pub_r001040_4_1 >= (-100)) && (pub_r001040_4_1 <= 100));
  __CPROVER_assume((pub_r001040_4_2 >= (-100)) && (pub_r001040_4_2 <= 100));
  __CPROVER_assume((pub_r001040_5_1 >= (-100)) && (pub_r001040_5_1 <= 100));
  __CPROVER_assume((pub_r001040_5_2 >= (-100)) && (pub_r001040_5_2 <= 100));
  __CPROVER_assume((pub_r001040_6_1 >= (-100)) && (pub_r001040_6_1 <= 100));
  __CPROVER_assume((pub_r001040_6_2 >= (-100)) && (pub_r001040_6_2 <= 100));
  __CPROVER_assume((pub_r001040_7_1 >= (-100)) && (pub_r001040_7_1 <= 100));
  __CPROVER_assume((pub_r001040_7_2 >= (-100)) && (pub_r001040_7_2 <= 100));
  __CPROVER_assume((pub_r001040_8_1 >= (-100)) && (pub_r001040_8_1 <= 100));
  __CPROVER_assume((pub_r001040_8_2 >= (-100)) && (pub_r001040_8_2 <= 100));
  __CPROVER_assume((pub_r001040_9_1 >= (-100)) && (pub_r001040_9_1 <= 100));
  __CPROVER_assume((pub_r001040_9_2 >= (-100)) && (pub_r001040_9_2 <= 100));
  __CPROVER_assume((pub_r001040_10_1 >= (-100)) && (pub_r001040_10_1 <= 100));
  __CPROVER_assume((pub_r001040_10_2 >= (-100)) && (pub_r001040_10_2 <= 100));
  __CPROVER_assume((pub_r001040_11_1 >= (-100)) && (pub_r001040_11_1 <= 100));
  __CPROVER_assume((pub_r001040_11_2 >= (-100)) && (pub_r001040_11_2 <= 100));
  __CPROVER_assume((pub_r001040_12_1 >= (-100)) && (pub_r001040_12_1 <= 100));
  __CPROVER_assume((pub_r001040_12_2 >= (-100)) && (pub_r001040_12_2 <= 100));
  __CPROVER_assume((pub_r001040_13_1 >= (-100)) && (pub_r001040_13_1 <= 100));
  __CPROVER_assume((pub_r001040_13_2 >= (-100)) && (pub_r001040_13_2 <= 100));
  __CPROVER_assume((pub_r001040_14_1 >= (-100)) && (pub_r001040_14_1 <= 100));
  __CPROVER_assume((pub_r001040_14_2 >= (-100)) && (pub_r001040_14_2 <= 100));
  __CPROVER_assume((pub_r001040_15_1 >= (-100)) && (pub_r001040_15_1 <= 100));
  __CPROVER_assume((pub_r001040_15_2 >= (-100)) && (pub_r001040_15_2 <= 100));
  __CPROVER_assume((pub_r001040_16_1 >= (-100)) && (pub_r001040_16_1 <= 100));
  __CPROVER_assume((pub_r001040_16_2 >= (-100)) && (pub_r001040_16_2 <= 100));
  __CPROVER_assume((pub_r001040_17_1 >= (-100)) && (pub_r001040_17_1 <= 100));
  __CPROVER_assume((pub_r001040_17_2 >= (-100)) && (pub_r001040_17_2 <= 100));
  __CPROVER_assume((pub_r001040_18_1 >= (-100)) && (pub_r001040_18_1 <= 100));
  __CPROVER_assume((pub_r001040_18_2 >= (-100)) && (pub_r001040_18_2 <= 100));
  __CPROVER_assume((pub_r001040_19_1 >= (-100)) && (pub_r001040_19_1 <= 100));
  __CPROVER_assume((pub_r001040_19_2 >= (-100)) && (pub_r001040_19_2 <= 100));
  __CPROVER_assume((sec_r001040_0_1 >= 0) && (sec_r001040_0_1 <= 255));
  __CPROVER_assume((sec_r001040_0_2 >= 0) && (sec_r001040_0_2 <= 255));
  __CPROVER_assume((sec_r001040_1_1 >= 0) && (sec_r001040_1_1 <= 255));
  __CPROVER_assume((sec_r001040_1_2 >= 0) && (sec_r001040_1_2 <= 255));
  __CPROVER_assume((sec_r001040_2_1 >= 0) && (sec_r001040_2_1 <= 255));
  __CPROVER_assume((sec_r001040_2_2 >= 0) && (sec_r001040_2_2 <= 255));
  __CPROVER_assume((sec_r001040_3_1 >= 0) && (sec_r001040_3_1 <= 255));
  __CPROVER_assume((sec_r001040_3_2 >= 0) && (sec_r001040_3_2 <= 255));
  __CPROVER_assume((sec_r001040_4_1 >= 0) && (sec_r001040_4_1 <= 255));
  __CPROVER_assume((sec_r001040_4_2 >= 0) && (sec_r001040_4_2 <= 255));
  __CPROVER_assume((sec_r001040_5_1 >= 0) && (sec_r001040_5_1 <= 255));
  __CPROVER_assume((sec_r001040_5_2 >= 0) && (sec_r001040_5_2 <= 255));
  __CPROVER_assume((sec_r001040_6_1 >= 0) && (sec_r001040_6_1 <= 255));
  __CPROVER_assume((sec_r001040_6_2 >= 0) && (sec_r001040_6_2 <= 255));
  __CPROVER_assume((sec_r001040_7_1 >= 0) && (sec_r001040_7_1 <= 255));
  __CPROVER_assume((sec_r001040_7_2 >= 0) && (sec_r001040_7_2 <= 255));
  __CPROVER_assume((sec_r001040_8_1 >= 0) && (sec_r001040_8_1 <= 255));
  __CPROVER_assume((sec_r001040_8_2 >= 0) && (sec_r001040_8_2 <= 255));
  __CPROVER_assume((sec_r001040_9_1 >= 0) && (sec_r001040_9_1 <= 255));
  __CPROVER_assume((sec_r001040_9_2 >= 0) && (sec_r001040_9_2 <= 255));
  __CPROVER_assume((sec_r001040_10_1 >= 0) && (sec_r001040_10_1 <= 255));
  __CPROVER_assume((sec_r001040_10_2 >= 0) && (sec_r001040_10_2 <= 255));
  __CPROVER_assume((sec_r001040_11_1 >= 0) && (sec_r001040_11_1 <= 255));
  __CPROVER_assume((sec_r001040_11_2 >= 0) && (sec_r001040_11_2 <= 255));
  __CPROVER_assume((sec_r001040_12_1 >= 0) && (sec_r001040_12_1 <= 255));
  __CPROVER_assume((sec_r001040_12_2 >= 0) && (sec_r001040_12_2 <= 255));
  __CPROVER_assume((sec_r001040_13_1 >= 0) && (sec_r001040_13_1 <= 255));
  __CPROVER_assume((sec_r001040_13_2 >= 0) && (sec_r001040_13_2 <= 255));
  __CPROVER_assume((sec_r001040_14_1 >= 0) && (sec_r001040_14_1 <= 255));
  __CPROVER_assume((sec_r001040_14_2 >= 0) && (sec_r001040_14_2 <= 255));
  __CPROVER_assume((sec_r001040_15_1 >= 0) && (sec_r001040_15_1 <= 255));
  __CPROVER_assume((sec_r001040_15_2 >= 0) && (sec_r001040_15_2 <= 255));
  __CPROVER_assume((sec_r001040_16_1 >= 0) && (sec_r001040_16_1 <= 255));
  __CPROVER_assume((sec_r001040_16_2 >= 0) && (sec_r001040_16_2 <= 255));
  __CPROVER_assume((sec_r001040_17_1 >= 0) && (sec_r001040_17_1 <= 255));
  __CPROVER_assume((sec_r001040_17_2 >= 0) && (sec_r001040_17_2 <= 255));
  __CPROVER_assume((sec_r001040_18_1 >= 0) && (sec_r001040_18_1 <= 255));
  __CPROVER_assume((sec_r001040_18_2 >= 0) && (sec_r001040_18_2 <= 255));
  struct FilterState_R001040_4013_0 st_var_0_1 = {0};
  struct FilterState_R001040_4013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001040_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001040_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001040_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001040_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001040_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001040_0_2 + 7) & 15;
  struct CipherContext_R001040_4013_1 st_var_1_1 = {0};
  struct CipherContext_R001040_4013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001040_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001040_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001040_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001040_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001040_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001040_0_2 + 9) & 15;
  union RegisterBank_R001040_4013_0 u_var_1;
  union RegisterBank_R001040_4013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001040_4013_0(sec_r001040_0_1, sec_r001040_1_1, pub_r001040_2_1);
  int helper_flow_0_2 = fn_R001040_4013_0(sec_r001040_0_2, sec_r001040_1_2, pub_r001040_2_2);
  fn_R001040_4013_0_2(sec_r001040_0_1, sec_r001040_1_1, pub_r001040_2_1, sec_r001040_0_2, sec_r001040_1_2, pub_r001040_2_2);
  int helper_flow_1_1 = fn_R001040_4013_1(sec_r001040_1_1, sec_r001040_2_1);
  int helper_flow_1_2 = fn_R001040_4013_1(sec_r001040_1_2, sec_r001040_2_2);
  fn_R001040_4013_1_2(sec_r001040_1_1, sec_r001040_2_1, sec_r001040_1_2, sec_r001040_2_2);
  int helper_flow_2_1 = fn_R001040_4013_2(sec_r001040_2_1, pub_r001040_3_1, pub_r001040_4_1, pub_r001040_5_1);
  int helper_flow_2_2 = fn_R001040_4013_2(sec_r001040_2_2, pub_r001040_3_2, pub_r001040_4_2, pub_r001040_5_2);
  fn_R001040_4013_2_2(sec_r001040_2_1, pub_r001040_3_1, pub_r001040_4_1, pub_r001040_5_1, sec_r001040_2_2, pub_r001040_3_2, pub_r001040_4_2, pub_r001040_5_2);
  int helper_flow_3_1 = fn_R001040_4013_3(sec_r001040_3_1, pub_r001040_4_1, pub_r001040_5_1);
  int helper_flow_3_2 = fn_R001040_4013_3(sec_r001040_3_2, pub_r001040_4_2, pub_r001040_5_2);
  fn_R001040_4013_3_2(sec_r001040_3_1, pub_r001040_4_1, pub_r001040_5_1, sec_r001040_3_2, pub_r001040_4_2, pub_r001040_5_2);
  int helper_flow_4_1 = fn_R001040_4013_4(sec_r001040_4_1, sec_r001040_5_1, pub_r001040_6_1, pub_r001040_7_1);
  int helper_flow_4_2 = fn_R001040_4013_4(sec_r001040_4_2, sec_r001040_5_2, pub_r001040_6_2, pub_r001040_7_2);
  fn_R001040_4013_4_2(sec_r001040_4_1, sec_r001040_5_1, pub_r001040_6_1, pub_r001040_7_1, sec_r001040_4_2, sec_r001040_5_2, pub_r001040_6_2, pub_r001040_7_2);
  int helper_flow_5_1 = fn_R001040_4013_5(sec_r001040_5_1, pub_r001040_6_1, pub_r001040_7_1);
  int helper_flow_5_2 = fn_R001040_4013_5(sec_r001040_5_2, pub_r001040_6_2, pub_r001040_7_2);
  fn_R001040_4013_5_2(sec_r001040_5_1, pub_r001040_6_1, pub_r001040_7_1, sec_r001040_5_2, pub_r001040_6_2, pub_r001040_7_2);
  int helper_flow_6_1 = fn_R001040_4013_6(sec_r001040_6_1, pub_r001040_7_1, pub_r001040_8_1);
  int helper_flow_6_2 = fn_R001040_4013_6(sec_r001040_6_2, pub_r001040_7_2, pub_r001040_8_2);
  fn_R001040_4013_6_2(sec_r001040_6_1, pub_r001040_7_1, pub_r001040_8_1, sec_r001040_6_2, pub_r001040_7_2, pub_r001040_8_2);
  int helper_flow_7_1 = fn_R001040_4013_7(sec_r001040_7_1, sec_r001040_8_1, pub_r001040_9_1);
  int helper_flow_7_2 = fn_R001040_4013_7(sec_r001040_7_2, sec_r001040_8_2, pub_r001040_9_2);
  fn_R001040_4013_7_2(sec_r001040_7_1, sec_r001040_8_1, pub_r001040_9_1, sec_r001040_7_2, sec_r001040_8_2, pub_r001040_9_2);
  int helper_flow_8_1 = fn_R001040_4013_8(sec_r001040_8_1, pub_r001040_9_1, pub_r001040_10_1, pub_r001040_11_1);
  int helper_flow_8_2 = fn_R001040_4013_8(sec_r001040_8_2, pub_r001040_9_2, pub_r001040_10_2, pub_r001040_11_2);
  fn_R001040_4013_8_2(sec_r001040_8_1, pub_r001040_9_1, pub_r001040_10_1, pub_r001040_11_1, sec_r001040_8_2, pub_r001040_9_2, pub_r001040_10_2, pub_r001040_11_2);
  int stage_v_0_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_0_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_0_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001040_0_1) & 127;
  int stage_v_1_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001040_0_2) & 127;
  if (stage_v_1_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((pub_r001040_15_1 * 2) + 32) & 63;
  int stage_v_2_2 = ((pub_r001040_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001040_16_1) & 127;
  int stage_v_3_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001040_16_2) & 127;
  if (stage_v_3_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001040_15_1) & 127;
  int stage_v_4_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001040_15_2) & 127;
  if (stage_v_4_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((pub_r001040_14_1 * 2) + 42) & 63;
  int stage_v_5_2 = ((pub_r001040_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001040_6_1) & 127;
  int stage_v_6_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001040_6_2) & 127;
  if (stage_v_6_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((sec_r001040_2_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_7_2 = (((sec_r001040_2_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_7_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001040_12_1) & 127;
  int stage_v_8_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001040_12_2) & 127;
  if (stage_v_8_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001040_8_1) & 127;
  int stage_v_9_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001040_8_2) & 127;
  if (stage_v_9_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((pub_r001040_19_1 * 2) + 5) & 63;
  int stage_v_10_2 = ((pub_r001040_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((sec_r001040_7_1 ^ 0x2A) * 2) + pub_r001040_17_1) & 127;
  int stage_v_11_2 = (((sec_r001040_7_2 ^ 0x2A) * 2) + pub_r001040_17_2) & 127;
  if (stage_v_11_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((pub_r001040_12_1 * 2) + 13) & 63;
  int stage_v_12_2 = ((pub_r001040_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001040_16_1) & 127;
  int stage_v_13_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001040_16_2) & 127;
  if (stage_v_13_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_14_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_14_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_15_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_15_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001040_3_1) & 127;
  int stage_v_16_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001040_3_2) & 127;
  if (stage_v_16_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((sec_r001040_2_1 ^ 0x2A) * 2) + pub_r001040_0_1) & 127;
  int stage_v_17_2 = (((sec_r001040_2_2 ^ 0x2A) * 2) + pub_r001040_0_2) & 127;
  if (stage_v_17_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((pub_r001040_16_1 * 2) + 22) & 63;
  int stage_v_18_2 = ((pub_r001040_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001040_12_1 * 2) + 42) & 63;
  int stage_v_19_2 = ((pub_r001040_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001040_8_1) & 127;
  int stage_v_20_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001040_8_2) & 127;
  if (stage_v_20_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_21_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_21_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((sec_r001040_1_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_22_2 = (((sec_r001040_1_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_22_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_23_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_23_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((sec_r001040_14_1 ^ 0x2A) * 2) + pub_r001040_11_1) & 127;
  int stage_v_24_2 = (((sec_r001040_14_2 ^ 0x2A) * 2) + pub_r001040_11_2) & 127;
  if (stage_v_24_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((pub_r001040_11_1 * 2) + 26) & 63;
  int stage_v_25_2 = ((pub_r001040_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_26_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_26_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001040_15_1) & 127;
  int stage_v_27_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001040_15_2) & 127;
  if (stage_v_27_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_28_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_28_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((pub_r001040_19_1 * 2) + 42) & 63;
  int stage_v_29_2 = ((pub_r001040_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001040_10_1 * 2) + 43) & 63;
  int stage_v_30_2 = ((pub_r001040_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001040_8_1 * 2) + 32) & 63;
  int stage_v_31_2 = ((pub_r001040_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001040_10_1 * 2) + 15) & 63;
  int stage_v_32_2 = ((pub_r001040_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001040_14_1) & 127;
  int stage_v_33_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001040_14_2) & 127;
  if (stage_v_33_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((sec_r001040_11_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_34_2 = (((sec_r001040_11_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_34_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001040_11_1) & 127;
  int stage_v_35_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001040_11_2) & 127;
  if (stage_v_35_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((pub_r001040_12_1 * 2) + 39) & 63;
  int stage_v_36_2 = ((pub_r001040_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((sec_r001040_1_1 ^ 0x2A) * 2) + pub_r001040_8_1) & 127;
  int stage_v_37_2 = (((sec_r001040_1_2 ^ 0x2A) * 2) + pub_r001040_8_2) & 127;
  if (stage_v_37_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_38_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_38_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001040_0_1) & 127;
  int stage_v_39_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001040_0_2) & 127;
  if (stage_v_39_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((pub_r001040_0_1 * 2) + 20) & 63;
  int stage_v_40_2 = ((pub_r001040_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001040_7_1) & 127;
  int stage_v_41_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001040_7_2) & 127;
  if (stage_v_41_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_42_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_42_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((sec_r001040_14_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_43_2 = (((sec_r001040_14_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_43_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_44_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_44_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((pub_r001040_19_1 * 2) + 50) & 63;
  int stage_v_45_2 = ((pub_r001040_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((sec_r001040_6_1 ^ 0x2A) * 2) + pub_r001040_3_1) & 127;
  int stage_v_46_2 = (((sec_r001040_6_2 ^ 0x2A) * 2) + pub_r001040_3_2) & 127;
  if (stage_v_46_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001040_8_1) & 127;
  int stage_v_47_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001040_8_2) & 127;
  if (stage_v_47_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_48_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_48_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001040_7_1) & 127;
  int stage_v_49_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001040_7_2) & 127;
  if (stage_v_49_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((pub_r001040_6_1 * 2) + 40) & 63;
  int stage_v_50_2 = ((pub_r001040_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((sec_r001040_6_1 ^ 0x2A) * 2) + pub_r001040_2_1) & 127;
  int stage_v_51_2 = (((sec_r001040_6_2 ^ 0x2A) * 2) + pub_r001040_2_2) & 127;
  if (stage_v_51_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001040_7_1) & 127;
  int stage_v_52_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001040_7_2) & 127;
  if (stage_v_52_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((sec_r001040_6_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_53_2 = (((sec_r001040_6_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_53_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001040_11_1) & 127;
  int stage_v_54_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001040_11_2) & 127;
  if (stage_v_54_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001040_7_1) & 127;
  int stage_v_55_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001040_7_2) & 127;
  if (stage_v_55_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((sec_r001040_2_1 ^ 0x2A) * 2) + pub_r001040_14_1) & 127;
  int stage_v_56_2 = (((sec_r001040_2_2 ^ 0x2A) * 2) + pub_r001040_14_2) & 127;
  if (stage_v_56_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((sec_r001040_18_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_57_2 = (((sec_r001040_18_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_57_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((sec_r001040_17_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_58_2 = (((sec_r001040_17_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_58_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((pub_r001040_9_1 * 2) + 23) & 63;
  int stage_v_59_2 = ((pub_r001040_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_60_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_60_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001040_2_1) & 127;
  int stage_v_61_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001040_2_2) & 127;
  if (stage_v_61_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_62_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_62_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_63_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_63_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((pub_r001040_1_1 * 2) + 22) & 63;
  int stage_v_64_2 = ((pub_r001040_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001040_8_1) & 127;
  int stage_v_65_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001040_8_2) & 127;
  if (stage_v_65_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((sec_r001040_1_1 ^ 0x2A) * 2) + pub_r001040_0_1) & 127;
  int stage_v_66_2 = (((sec_r001040_1_2 ^ 0x2A) * 2) + pub_r001040_0_2) & 127;
  if (stage_v_66_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001040_17_1) & 127;
  int stage_v_67_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001040_17_2) & 127;
  if (stage_v_67_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001040_19_1) & 127;
  int stage_v_68_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001040_19_2) & 127;
  if (stage_v_68_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((pub_r001040_3_1 * 2) + 28) & 63;
  int stage_v_69_2 = ((pub_r001040_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001040_7_1 * 2) + 7) & 63;
  int stage_v_70_2 = ((pub_r001040_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001040_1_1 * 2) + 47) & 63;
  int stage_v_71_2 = ((pub_r001040_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_72_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_72_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((pub_r001040_19_1 * 2) + 45) & 63;
  int stage_v_73_2 = ((pub_r001040_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((sec_r001040_15_1 ^ 0x2A) * 2) + pub_r001040_8_1) & 127;
  int stage_v_74_2 = (((sec_r001040_15_2 ^ 0x2A) * 2) + pub_r001040_8_2) & 127;
  if (stage_v_74_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((pub_r001040_2_1 * 2) + 18) & 63;
  int stage_v_75_2 = ((pub_r001040_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (((sec_r001040_5_1 ^ 0x2A) * 2) + pub_r001040_15_1) & 127;
  int stage_v_76_2 = (((sec_r001040_5_2 ^ 0x2A) * 2) + pub_r001040_15_2) & 127;
  if (stage_v_76_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_77_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_77_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001040_7_1) & 127;
  int stage_v_78_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001040_7_2) & 127;
  if (stage_v_78_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001040_7_1) & 127;
  int stage_v_79_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001040_7_2) & 127;
  if (stage_v_79_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((sec_r001040_2_1 ^ 0x2A) * 2) + pub_r001040_11_1) & 127;
  int stage_v_80_2 = (((sec_r001040_2_2 ^ 0x2A) * 2) + pub_r001040_11_2) & 127;
  if (stage_v_80_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((pub_r001040_11_1 * 2) + 25) & 63;
  int stage_v_81_2 = ((pub_r001040_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001040_11_1) & 127;
  int stage_v_82_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001040_11_2) & 127;
  if (stage_v_82_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_83_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_83_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_84_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_84_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001040_6_1) & 127;
  int stage_v_85_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001040_6_2) & 127;
  if (stage_v_85_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((pub_r001040_8_1 * 2) + 5) & 63;
  int stage_v_86_2 = ((pub_r001040_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001040_10_1 * 2) + 21) & 63;
  int stage_v_87_2 = ((pub_r001040_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001040_11_1) & 127;
  int stage_v_88_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001040_11_2) & 127;
  if (stage_v_88_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((pub_r001040_0_1 * 2) + 9) & 63;
  int stage_v_89_2 = ((pub_r001040_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((sec_r001040_17_1 ^ 0x2A) * 2) + pub_r001040_9_1) & 127;
  int stage_v_90_2 = (((sec_r001040_17_2 ^ 0x2A) * 2) + pub_r001040_9_2) & 127;
  if (stage_v_90_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001040_8_1) & 127;
  int stage_v_91_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001040_8_2) & 127;
  if (stage_v_91_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001040_16_1) & 127;
  int stage_v_92_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001040_16_2) & 127;
  if (stage_v_92_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_93_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_93_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((sec_r001040_13_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_94_2 = (((sec_r001040_13_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_94_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((pub_r001040_0_1 * 2) + 48) & 63;
  int stage_v_95_2 = ((pub_r001040_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001040_15_1) & 127;
  int stage_v_96_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001040_15_2) & 127;
  if (stage_v_96_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001040_9_1) & 127;
  int stage_v_97_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001040_9_2) & 127;
  if (stage_v_97_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001040_15_1) & 127;
  int stage_v_98_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001040_15_2) & 127;
  if (stage_v_98_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((pub_r001040_2_1 * 2) + 45) & 63;
  int stage_v_99_2 = ((pub_r001040_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001040_11_1) & 127;
  int stage_v_100_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001040_11_2) & 127;
  if (stage_v_100_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((pub_r001040_4_1 * 2) + 30) & 63;
  int stage_v_101_2 = ((pub_r001040_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001040_16_1) & 127;
  int stage_v_102_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001040_16_2) & 127;
  if (stage_v_102_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_103_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_103_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001040_19_1) & 127;
  int stage_v_104_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001040_19_2) & 127;
  if (stage_v_104_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_105_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_105_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001040_16_1) & 127;
  int stage_v_106_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001040_16_2) & 127;
  if (stage_v_106_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_107_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_107_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001040_19_1) & 127;
  int stage_v_108_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001040_19_2) & 127;
  if (stage_v_108_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_109_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_109_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_110_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_110_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((sec_r001040_5_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_111_2 = (((sec_r001040_5_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_111_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001040_2_1) & 127;
  int stage_v_112_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001040_2_2) & 127;
  if (stage_v_112_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001040_11_1) & 127;
  int stage_v_113_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001040_11_2) & 127;
  if (stage_v_113_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((sec_r001040_15_1 ^ 0x2A) * 2) + pub_r001040_17_1) & 127;
  int stage_v_114_2 = (((sec_r001040_15_2 ^ 0x2A) * 2) + pub_r001040_17_2) & 127;
  if (stage_v_114_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((pub_r001040_1_1 * 2) + 40) & 63;
  int stage_v_115_2 = ((pub_r001040_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001040_3_1 * 2) + 35) & 63;
  int stage_v_116_2 = ((pub_r001040_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_117_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_117_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_118_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_118_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((pub_r001040_14_1 * 2) + 46) & 63;
  int stage_v_119_2 = ((pub_r001040_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((sec_r001040_7_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_120_2 = (((sec_r001040_7_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_120_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001040_14_1) & 127;
  int stage_v_121_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001040_14_2) & 127;
  if (stage_v_121_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_122_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_122_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((sec_r001040_7_1 ^ 0x2A) * 2) + pub_r001040_16_1) & 127;
  int stage_v_123_2 = (((sec_r001040_7_2 ^ 0x2A) * 2) + pub_r001040_16_2) & 127;
  if (stage_v_123_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_124_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_124_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((sec_r001040_7_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_125_2 = (((sec_r001040_7_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_125_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_126_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_126_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_127_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_127_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((pub_r001040_19_1 * 2) + 47) & 63;
  int stage_v_128_2 = ((pub_r001040_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001040_6_1) & 127;
  int stage_v_129_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001040_6_2) & 127;
  if (stage_v_129_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((sec_r001040_14_1 ^ 0x2A) * 2) + pub_r001040_0_1) & 127;
  int stage_v_130_2 = (((sec_r001040_14_2 ^ 0x2A) * 2) + pub_r001040_0_2) & 127;
  if (stage_v_130_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((pub_r001040_2_1 * 2) + 19) & 63;
  int stage_v_131_2 = ((pub_r001040_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((sec_r001040_18_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_132_2 = (((sec_r001040_18_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_132_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001040_15_1) & 127;
  int stage_v_133_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001040_15_2) & 127;
  if (stage_v_133_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001040_14_1) & 127;
  int stage_v_134_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001040_14_2) & 127;
  if (stage_v_134_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((pub_r001040_1_1 * 2) + 5) & 63;
  int stage_v_135_2 = ((pub_r001040_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001040_6_1) & 127;
  int stage_v_136_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001040_6_2) & 127;
  if (stage_v_136_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_137_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_137_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001040_6_1) & 127;
  int stage_v_138_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001040_6_2) & 127;
  if (stage_v_138_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((sec_r001040_11_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_139_2 = (((sec_r001040_11_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_139_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_140_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_140_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_141_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_141_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001040_15_1) & 127;
  int stage_v_142_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001040_15_2) & 127;
  if (stage_v_142_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_143_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_143_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_144_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_144_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_145_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_145_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((sec_r001040_6_1 ^ 0x2A) * 2) + pub_r001040_17_1) & 127;
  int stage_v_146_2 = (((sec_r001040_6_2 ^ 0x2A) * 2) + pub_r001040_17_2) & 127;
  if (stage_v_146_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((pub_r001040_16_1 * 2) + 39) & 63;
  int stage_v_147_2 = ((pub_r001040_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_148_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_148_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_146_1 ^ 0x2A) * 2) + pub_r001040_12_1) & 127;
  int stage_v_149_2 = (((stage_v_146_2 ^ 0x2A) * 2) + pub_r001040_12_2) & 127;
  if (stage_v_149_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((pub_r001040_12_1 * 2) + 21) & 63;
  int stage_v_150_2 = ((pub_r001040_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001040_17_1 * 2) + 17) & 63;
  int stage_v_151_2 = ((pub_r001040_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001040_1_1 * 2) + 43) & 63;
  int stage_v_152_2 = ((pub_r001040_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001040_4_1 * 2) + 16) & 63;
  int stage_v_153_2 = ((pub_r001040_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001040_8_1) & 127;
  int stage_v_154_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001040_8_2) & 127;
  if (stage_v_154_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001040_14_1) & 127;
  int stage_v_155_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001040_14_2) & 127;
  if (stage_v_155_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_156_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_156_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001040_7_1) & 127;
  int stage_v_157_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001040_7_2) & 127;
  if (stage_v_157_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001040_2_1) & 127;
  int stage_v_158_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001040_2_2) & 127;
  if (stage_v_158_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001040_6_1) & 127;
  int stage_v_159_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001040_6_2) & 127;
  if (stage_v_159_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_160_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_160_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((stage_v_125_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_161_2 = (((stage_v_125_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_161_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001040_11_1) & 127;
  int stage_v_162_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001040_11_2) & 127;
  if (stage_v_162_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_144_1 ^ 0x2A) * 2) + pub_r001040_3_1) & 127;
  int stage_v_163_2 = (((stage_v_144_2 ^ 0x2A) * 2) + pub_r001040_3_2) & 127;
  if (stage_v_163_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001040_9_1) & 127;
  int stage_v_164_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001040_9_2) & 127;
  if (stage_v_164_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((stage_v_158_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_165_2 = (((stage_v_158_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_165_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_166_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_166_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((pub_r001040_14_1 * 2) + 37) & 63;
  int stage_v_167_2 = ((pub_r001040_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001040_8_1) & 127;
  int stage_v_168_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001040_8_2) & 127;
  if (stage_v_168_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((pub_r001040_4_1 * 2) + 37) & 63;
  int stage_v_169_2 = ((pub_r001040_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((sec_r001040_1_1 ^ 0x2A) * 2) + pub_r001040_17_1) & 127;
  int stage_v_170_2 = (((sec_r001040_1_2 ^ 0x2A) * 2) + pub_r001040_17_2) & 127;
  if (stage_v_170_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((pub_r001040_10_1 * 2) + 41) & 63;
  int stage_v_171_2 = ((pub_r001040_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_141_1 ^ 0x2A) * 2) + pub_r001040_11_1) & 127;
  int stage_v_172_2 = (((stage_v_141_2 ^ 0x2A) * 2) + pub_r001040_11_2) & 127;
  if (stage_v_172_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001040_6_1) & 127;
  int stage_v_173_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001040_6_2) & 127;
  if (stage_v_173_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001040_3_1) & 127;
  int stage_v_174_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001040_3_2) & 127;
  if (stage_v_174_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((pub_r001040_10_1 * 2) + 43) & 63;
  int stage_v_175_2 = ((pub_r001040_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001040_9_1) & 127;
  int stage_v_176_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001040_9_2) & 127;
  if (stage_v_176_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((sec_r001040_11_1 ^ 0x2A) * 2) + pub_r001040_16_1) & 127;
  int stage_v_177_2 = (((sec_r001040_11_2 ^ 0x2A) * 2) + pub_r001040_16_2) & 127;
  if (stage_v_177_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001040_9_1) & 127;
  int stage_v_178_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001040_9_2) & 127;
  if (stage_v_178_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_179_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_179_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001040_9_1) & 127;
  int stage_v_180_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001040_9_2) & 127;
  if (stage_v_180_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_176_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_181_2 = (((stage_v_176_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_181_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_182_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_182_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_183_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_183_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001040_14_1) & 127;
  int stage_v_184_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001040_14_2) & 127;
  if (stage_v_184_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((pub_r001040_15_1 * 2) + 21) & 63;
  int stage_v_185_2 = ((pub_r001040_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_178_1 ^ 0x2A) * 2) + pub_r001040_15_1) & 127;
  int stage_v_186_2 = (((stage_v_178_2 ^ 0x2A) * 2) + pub_r001040_15_2) & 127;
  if (stage_v_186_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((sec_r001040_7_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_187_2 = (((sec_r001040_7_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_187_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001040_7_1) & 127;
  int stage_v_188_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001040_7_2) & 127;
  if (stage_v_188_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001040_11_1) & 127;
  int stage_v_189_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001040_11_2) & 127;
  if (stage_v_189_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001040_16_1) & 127;
  int stage_v_190_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001040_16_2) & 127;
  if (stage_v_190_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_174_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_191_2 = (((stage_v_174_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_191_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_184_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_192_2 = (((stage_v_184_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_192_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((pub_r001040_11_1 * 2) + 10) & 63;
  int stage_v_193_2 = ((pub_r001040_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001040_12_1 * 2) + 27) & 63;
  int stage_v_194_2 = ((pub_r001040_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001040_10_1 * 2) + 40) & 63;
  int stage_v_195_2 = ((pub_r001040_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001040_16_1 * 2) + 12) & 63;
  int stage_v_196_2 = ((pub_r001040_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001040_6_1) & 127;
  int stage_v_197_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001040_6_2) & 127;
  if (stage_v_197_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((pub_r001040_13_1 * 2) + 27) & 63;
  int stage_v_198_2 = ((pub_r001040_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001040_14_1) & 127;
  int stage_v_199_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001040_14_2) & 127;
  if (stage_v_199_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001040_0_1) & 127;
  int stage_v_200_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001040_0_2) & 127;
  if (stage_v_200_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_192_1 ^ 0x2A) * 2) + pub_r001040_6_1) & 127;
  int stage_v_201_2 = (((stage_v_192_2 ^ 0x2A) * 2) + pub_r001040_6_2) & 127;
  if (stage_v_201_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_202_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_202_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((pub_r001040_16_1 * 2) + 6) & 63;
  int stage_v_203_2 = ((pub_r001040_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_204_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_204_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((pub_r001040_4_1 * 2) + 37) & 63;
  int stage_v_205_2 = ((pub_r001040_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((stage_v_176_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_206_2 = (((stage_v_176_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_206_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_207_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_207_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((pub_r001040_7_1 * 2) + 24) & 63;
  int stage_v_208_2 = ((pub_r001040_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001040_7_1 * 2) + 12) & 63;
  int stage_v_209_2 = ((pub_r001040_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001040_7_1 * 2) + 9) & 63;
  int stage_v_210_2 = ((pub_r001040_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001040_2_1) & 127;
  int stage_v_211_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001040_2_2) & 127;
  if (stage_v_211_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001040_7_1) & 127;
  int stage_v_212_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001040_7_2) & 127;
  if (stage_v_212_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001040_6_1) & 127;
  int stage_v_213_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001040_6_2) & 127;
  if (stage_v_213_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001040_15_1) & 127;
  int stage_v_214_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001040_15_2) & 127;
  if (stage_v_214_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = (((stage_v_186_1 ^ 0x2A) * 2) + pub_r001040_8_1) & 127;
  int stage_v_215_2 = (((stage_v_186_2 ^ 0x2A) * 2) + pub_r001040_8_2) & 127;
  if (stage_v_215_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_216_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_216_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_217_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_217_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_149_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_218_2 = (((stage_v_149_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_218_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_219_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_219_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((pub_r001040_19_1 * 2) + 39) & 63;
  int stage_v_220_2 = ((pub_r001040_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001040_17_1) & 127;
  int stage_v_221_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001040_17_2) & 127;
  if (stage_v_221_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001040_17_1) & 127;
  int stage_v_222_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001040_17_2) & 127;
  if (stage_v_222_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001040_16_1) & 127;
  int stage_v_223_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001040_16_2) & 127;
  if (stage_v_223_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((stage_v_173_1 ^ 0x2A) * 2) + pub_r001040_19_1) & 127;
  int stage_v_224_2 = (((stage_v_173_2 ^ 0x2A) * 2) + pub_r001040_19_2) & 127;
  if (stage_v_224_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((pub_r001040_14_1 * 2) + 42) & 63;
  int stage_v_225_2 = ((pub_r001040_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001040_7_1 * 2) + 41) & 63;
  int stage_v_226_2 = ((pub_r001040_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001040_6_1 * 2) + 29) & 63;
  int stage_v_227_2 = ((pub_r001040_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = (((stage_v_162_1 ^ 0x2A) * 2) + pub_r001040_17_1) & 127;
  int stage_v_228_2 = (((stage_v_162_2 ^ 0x2A) * 2) + pub_r001040_17_2) & 127;
  if (stage_v_228_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = (((stage_v_228_1 ^ 0x2A) * 2) + pub_r001040_12_1) & 127;
  int stage_v_229_2 = (((stage_v_228_2 ^ 0x2A) * 2) + pub_r001040_12_2) & 127;
  if (stage_v_229_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001040_3_1) & 127;
  int stage_v_230_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001040_3_2) & 127;
  if (stage_v_230_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_231_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_231_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
  }
  if (stage_v_231_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001040_14_1) & 127;
  int stage_v_232_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001040_14_2) & 127;
  if (stage_v_232_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
  }
  if (stage_v_232_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((pub_r001040_0_1 * 2) + 14) & 63;
  int stage_v_233_2 = ((pub_r001040_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_234_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_234_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
  }
  if (stage_v_234_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = (((stage_v_177_1 ^ 0x2A) * 2) + pub_r001040_10_1) & 127;
  int stage_v_235_2 = (((stage_v_177_2 ^ 0x2A) * 2) + pub_r001040_10_2) & 127;
  if (stage_v_235_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
  }
  if (stage_v_235_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001040_19_1) & 127;
  int stage_v_236_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001040_19_2) & 127;
  if (stage_v_236_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
  }
  if (stage_v_236_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = (((stage_v_149_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_237_2 = (((stage_v_149_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_237_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((pub_r001040_14_1 * 2) + 33) & 63;
  int stage_v_238_2 = ((pub_r001040_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001040_18_1 * 2) + 40) & 63;
  int stage_v_239_2 = ((pub_r001040_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001040_0_1) & 127;
  int stage_v_240_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001040_0_2) & 127;
  if (stage_v_240_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
  }
  if (stage_v_240_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = (((stage_v_105_1 ^ 0x2A) * 2) + pub_r001040_8_1) & 127;
  int stage_v_241_2 = (((stage_v_105_2 ^ 0x2A) * 2) + pub_r001040_8_2) & 127;
  if (stage_v_241_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
  }
  if (stage_v_241_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = (((stage_v_218_1 ^ 0x2A) * 2) + pub_r001040_17_1) & 127;
  int stage_v_242_2 = (((stage_v_218_2 ^ 0x2A) * 2) + pub_r001040_17_2) & 127;
  if (stage_v_242_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
  }
  if (stage_v_242_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_243_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_243_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_243_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_243_1) + 13) & 255;
  }
  if (stage_v_243_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_243_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_243_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = (((stage_v_145_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_244_2 = (((stage_v_145_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_244_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
  }
  if (stage_v_244_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001040_1_1) & 127;
  int stage_v_245_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001040_1_2) & 127;
  if (stage_v_245_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_245_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_245_1) + 13) & 255;
  }
  if (stage_v_245_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_245_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_245_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001040_13_1) & 127;
  int stage_v_246_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001040_13_2) & 127;
  if (stage_v_246_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
  }
  if (stage_v_246_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_247_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_247_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
  }
  if (stage_v_247_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001040_18_1) & 127;
  int stage_v_248_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001040_18_2) & 127;
  if (stage_v_248_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_248_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_248_1) + 13) & 255;
  }
  if (stage_v_248_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_248_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_248_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001040_4_1) & 127;
  int stage_v_249_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001040_4_2) & 127;
  if (stage_v_249_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_249_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_249_1) + 13) & 255;
  }
  if (stage_v_249_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_249_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_249_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = (((stage_v_164_1 ^ 0x2A) * 2) + pub_r001040_12_1) & 127;
  int stage_v_250_2 = (((stage_v_164_2 ^ 0x2A) * 2) + pub_r001040_12_2) & 127;
  if (stage_v_250_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_250_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_250_1) + 13) & 255;
  }
  if (stage_v_250_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_250_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_250_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = (((stage_v_134_1 ^ 0x2A) * 2) + pub_r001040_12_1) & 127;
  int stage_v_251_2 = (((stage_v_134_2 ^ 0x2A) * 2) + pub_r001040_12_2) & 127;
  if (stage_v_251_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_251_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_251_1) + 13) & 255;
  }
  if (stage_v_251_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_251_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_251_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001040_5_1) & 127;
  int stage_v_252_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001040_5_2) & 127;
  if (stage_v_252_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_252_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_252_1) + 13) & 255;
  }
  if (stage_v_252_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_252_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_252_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = (((stage_v_245_1 ^ 0x2A) * 2) + pub_r001040_9_1) & 127;
  int stage_v_253_2 = (((stage_v_245_2 ^ 0x2A) * 2) + pub_r001040_9_2) & 127;
  if (stage_v_253_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_253_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_253_1) + 13) & 255;
  }
  if (stage_v_253_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_253_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_253_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((pub_r001040_1_1 * 2) + 24) & 63;
  int stage_v_254_2 = ((pub_r001040_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001040_18_1 * 2) + 35) & 63;
  int stage_v_255_2 = ((pub_r001040_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001040_14_1 != sec_r001040_14_2);
  __CPROVER_assume(pub_r001040_11_1 == pub_r001040_11_2);
  __CPROVER_assume(sec_r001040_2_1 != sec_r001040_2_2);
  __CPROVER_assume(sec_r001040_7_1 != sec_r001040_7_2);
  __CPROVER_assume(pub_r001040_14_1 == pub_r001040_14_2);
  __CPROVER_assume(sec_r001040_3_1 != sec_r001040_3_2);
  __CPROVER_assume(pub_r001040_4_1 == pub_r001040_4_2);
  __CPROVER_assume(pub_r001040_0_1 == pub_r001040_0_2);
  __CPROVER_assume(pub_r001040_15_1 == pub_r001040_15_2);
  __CPROVER_assume(sec_r001040_9_1 != sec_r001040_9_2);
  __CPROVER_assume(sec_r001040_16_1 != sec_r001040_16_2);
  __CPROVER_assume(sec_r001040_6_1 != sec_r001040_6_2);
  __CPROVER_assume(sec_r001040_17_1 != sec_r001040_17_2);
  __CPROVER_assume(pub_r001040_12_1 == pub_r001040_12_2);
  __CPROVER_assume(sec_r001040_5_1 != sec_r001040_5_2);
  __CPROVER_assume(pub_r001040_19_1 == pub_r001040_19_2);
  __CPROVER_assume(pub_r001040_2_1 == pub_r001040_2_2);
  __CPROVER_assume(sec_r001040_15_1 != sec_r001040_15_2);
  __CPROVER_assume(sec_r001040_10_1 != sec_r001040_10_2);
  __CPROVER_assume(pub_r001040_3_1 == pub_r001040_3_2);
  __CPROVER_assume(pub_r001040_10_1 == pub_r001040_10_2);
  __CPROVER_assume(pub_r001040_9_1 == pub_r001040_9_2);
  __CPROVER_assume(pub_r001040_16_1 == pub_r001040_16_2);
  __CPROVER_assume(pub_r001040_6_1 == pub_r001040_6_2);
  __CPROVER_assume(sec_r001040_13_1 != sec_r001040_13_2);
  __CPROVER_assume(sec_r001040_1_1 != sec_r001040_1_2);
  __CPROVER_assume(pub_r001040_17_1 == pub_r001040_17_2);
  __CPROVER_assume(sec_r001040_0_1 != sec_r001040_0_2);
  __CPROVER_assume(pub_r001040_5_1 == pub_r001040_5_2);
  __CPROVER_assume(pub_r001040_13_1 == pub_r001040_13_2);
  __CPROVER_assume(pub_r001040_7_1 == pub_r001040_7_2);
  __CPROVER_assume(pub_r001040_18_1 == pub_r001040_18_2);
  __CPROVER_assume(sec_r001040_18_1 != sec_r001040_18_2);
  __CPROVER_assume(sec_r001040_12_1 != sec_r001040_12_2);
  __CPROVER_assume(pub_r001040_8_1 == pub_r001040_8_2);
  __CPROVER_assume(pub_r001040_1_1 == pub_r001040_1_2);
  __CPROVER_assume(sec_r001040_11_1 != sec_r001040_11_2);
  __CPROVER_assume(sec_r001040_4_1 != sec_r001040_4_2);
  __CPROVER_assume(sec_r001040_8_1 != sec_r001040_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
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
}


