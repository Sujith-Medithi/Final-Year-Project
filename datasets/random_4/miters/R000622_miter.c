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
struct StreamBuffer_R000622_2213_0
{
  unsigned char checksum;
  int capacity;
  short tail;
  int state;
  int watermark;
  int buffer[3];
};
struct AudioFrame_R000622_2213_1
{
  unsigned char gain;
  int sample_rate;
  int channels;
  int rms;
  unsigned char peak;
  unsigned char envelope;
  int buffer[3];
};
struct Transaction_R000622_2213_2
{
  int rate;
  int auth_code;
  int account_id;
  unsigned char fee;
  int buffer[3];
};
union ColorPixel_R000622_2213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000622_2213_1
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
void fn_R000622_2213_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st_1 = {0};
  struct AudioFrame_R000622_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int tally_55_1 = 0;
  int tally_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_55_1 = ((tally_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_55_2 = ((tally_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_55_1) & 127;
    acc_2 = (acc_2 + tally_55_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_16_1 = local_arr_1[aux_1 % 3];
  int segment_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_16_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_55_1 == tally_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_16_1 == segment_16_2);
}

int fn_R000622_2213_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int tally_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_55 = ((tally_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_55) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_16 = local_arr[aux % 3];
  acc = (acc + (segment_16 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000622_2213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st_1 = {0};
  struct AudioFrame_R000622_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_41_1 = local_arr_1[aux_1 % 3];
  int cursor_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_41_2 * 2)) & 127;
  int bound_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_91_1 > 25)
  {
    acc_1 = ((acc_1 + (bound_91_1 * 2)) + 5) & 127;
    aux_1 ^= bound_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_91_2 > 25)
  {
    acc_2 = ((acc_2 + (bound_91_2 * 2)) + 5) & 127;
    aux_2 ^= bound_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_35_1) & 63;
  aux_2 = (aux_2 + mask_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_41_1 == cursor_41_2);
  assert(bound_91_1 == bound_91_2);
  assert(mask_35_1 == mask_35_2);
}

int fn_R000622_2213_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int cursor_41 = local_arr[aux % 3];
  acc = (acc + (cursor_41 * 2)) & 127;
  int bound_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_91 > 25)
  {
    acc = ((acc + (bound_91 * 2)) + 5) & 127;
    aux ^= bound_91 & 15;
  }
  else
  {
    acc = ((acc - bound_91) + 11) & 127;
    aux += 3;
  }
  int mask_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000622_2213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st_1 = {0};
  struct AudioFrame_R000622_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int cursor_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_44_1) & 63;
  aux_2 = (aux_2 + cursor_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_75_1)
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

  switch (window_75_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_44_1 == cursor_44_2);
  assert(window_75_1 == window_75_2);
}

int fn_R000622_2213_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int cursor_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_44) & 63;
  acc ^= aux;
  int window_75 = (aux + st.buffer[1]) & 3;
  switch (window_75)
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

void fn_R000622_2213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000622_2213_2 st_1 = {0};
  struct Transaction_R000622_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int vector_93_1 = 0;
  int vector_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_93_1 = ((vector_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_93_2 = ((vector_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_93_1) & 127;
    acc_2 = (acc_2 + vector_93_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_78_1)
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

  switch (quantum_78_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_93_1 == vector_93_2);
  assert(quantum_78_1 == quantum_78_2);
}

int fn_R000622_2213_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000622_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int vector_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_93 = ((vector_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_93) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_78 = (aux + st.buffer[1]) & 3;
  switch (quantum_78)
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

void fn_R000622_2213_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st_1 = {0};
  struct AudioFrame_R000622_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_64_1 = local_arr_1[aux_1 % 3];
  int window_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_64_2 * 2)) & 127;
  int factor_57_1 = 0;
  int factor_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_57_1 = ((factor_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_57_2 = ((factor_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_57_1) & 127;
    acc_2 = (acc_2 + factor_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_64_1 == window_64_2);
  assert(factor_57_1 == factor_57_2);
}

int fn_R000622_2213_4(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int window_64 = local_arr[aux % 3];
  acc = (acc + (window_64 * 2)) & 127;
  int factor_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_57 = ((factor_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000622_2213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000622_2213_2 st_1 = {0};
  struct Transaction_R000622_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tally_94_1 = 0;
  int tally_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_94_1 = ((tally_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_94_2 = ((tally_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_94_1) & 127;
    acc_2 = (acc_2 + tally_94_2) & 127;
  }

  int parity_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_27_1)
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

  switch (parity_27_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_94_1 == tally_94_2);
  assert(parity_27_1 == parity_27_2);
}

int fn_R000622_2213_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000622_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tally_94 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_94 = ((tally_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_94) & 127;
  }

  int parity_27 = (aux + st.buffer[1]) & 3;
  switch (parity_27)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000622_2213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st_1 = {0};
  struct StreamBuffer_R000622_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int quantum_66_1 = 0;
  int quantum_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_66_1 = ((quantum_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_66_2 = ((quantum_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_66_1) & 127;
    acc_2 = (acc_2 + quantum_66_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_30_1 = local_arr_1[aux_1 % 3];
  int index_reg_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_30_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_66_1 == quantum_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_30_1 == index_reg_30_2);
}

int fn_R000622_2213_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int quantum_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_66 = ((quantum_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_66) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int index_reg_30 = local_arr[aux % 3];
  acc = (acc + (index_reg_30 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000622_2213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000622_2213_2 st_1 = {0};
  struct Transaction_R000622_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int residue_47_1 = 0;
  int residue_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_47_1 = ((residue_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_47_2 = ((residue_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_47_1) & 127;
    acc_2 = (acc_2 + residue_47_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_43_1 = local_arr_1[aux_1 % 3];
  int quotient_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_43_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_50_1) & 63;
  aux_2 = (aux_2 + metric_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_47_1 == residue_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_43_1 == quotient_43_2);
  assert(metric_50_1 == metric_50_2);
}

int fn_R000622_2213_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000622_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int residue_47 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_47 = ((residue_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_47) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_43 = local_arr[aux % 3];
  acc = (acc + (quotient_43 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_50) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000622_2213_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st_1 = {0};
  struct AudioFrame_R000622_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int metric_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_72_1 > 39)
  {
    acc_1 = ((acc_1 + (metric_72_1 * 2)) + 5) & 127;
    aux_1 ^= metric_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_72_2 > 39)
  {
    acc_2 = ((acc_2 + (metric_72_2 * 2)) + 5) & 127;
    aux_2 ^= metric_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_72_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_76_1) & 63;
  aux_2 = (aux_2 + coefficient_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_72_1 == metric_72_2);
  assert(coefficient_76_1 == coefficient_76_2);
}

int fn_R000622_2213_8(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int metric_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_72 > 39)
  {
    acc = ((acc + (metric_72 * 2)) + 5) & 127;
    aux ^= metric_72 & 15;
  }
  else
  {
    acc = ((acc - metric_72) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_76) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000622_2213_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st_1 = {0};
  struct StreamBuffer_R000622_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_26_1 = local_arr_1[aux_1 % 3];
  int tally_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_26_2 * 2)) & 127;
  int accumulator_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_47_1) & 63;
  aux_2 = (aux_2 + accumulator_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_26_1 == tally_26_2);
  assert(accumulator_47_1 == accumulator_47_2);
}

int fn_R000622_2213_9(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int tally_26 = local_arr[aux % 3];
  acc = (acc + (tally_26 * 2)) & 127;
  int accumulator_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000622_2213_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st_1 = {0};
  struct StreamBuffer_R000622_2213_0 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_57_1 = local_arr_1[aux_1 % 3];
  int mask_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_57_2 * 2)) & 127;
  int sample_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_12_1) & 63;
  aux_2 = (aux_2 + sample_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_45_1 = 0;
  int bound_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_45_1 = ((bound_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_45_2 = ((bound_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_45_1) & 127;
    acc_2 = (acc_2 + bound_45_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_57_1 == mask_57_2);
  assert(sample_12_1 == sample_12_2);
  assert(bound_45_1 == bound_45_2);
}

int fn_R000622_2213_10(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_57 = local_arr[aux % 3];
  acc = (acc + (mask_57 * 2)) & 127;
  int sample_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_12) & 63;
  acc ^= aux;
  int bound_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_45 = ((bound_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_45) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000622_2213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st_1 = {0};
  struct StreamBuffer_R000622_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int coefficient_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_11_1)
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

  switch (coefficient_11_2)
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
  int parity_60_1 = local_arr_1[aux_1 % 3];
  int parity_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_11_1 == coefficient_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_60_1 == parity_60_2);
}

int fn_R000622_2213_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int coefficient_11 = (aux + st.buffer[1]) & 3;
  switch (coefficient_11)
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
  int parity_60 = local_arr[aux % 3];
  acc = (acc + (parity_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000622_2213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st_1 = {0};
  struct AudioFrame_R000622_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_89_1 = local_arr_1[aux_1 % 3];
  int mask_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_89_2 * 2)) & 127;
  int weight_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_38_1 > 27)
  {
    acc_1 = ((acc_1 + (weight_38_1 * 2)) + 5) & 127;
    aux_1 ^= weight_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_38_2 > 27)
  {
    acc_2 = ((acc_2 + (weight_38_2 * 2)) + 5) & 127;
    aux_2 ^= weight_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_89_1 == mask_89_2);
  assert(weight_38_1 == weight_38_2);
}

int fn_R000622_2213_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int mask_89 = local_arr[aux % 3];
  acc = (acc + (mask_89 * 2)) & 127;
  int weight_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_38 > 27)
  {
    acc = ((acc + (weight_38 * 2)) + 5) & 127;
    aux ^= weight_38 & 15;
  }
  else
  {
    acc = ((acc - weight_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000622_2213_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000622_2213_2 st_1 = {0};
  struct Transaction_R000622_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int vector_78_1 = 0;
  int vector_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_78_1 = ((vector_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_78_2 = ((vector_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_78_1) & 127;
    acc_2 = (acc_2 + vector_78_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_78_1 == vector_78_2);
}

int fn_R000622_2213_13(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000622_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int vector_78 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_78 = ((vector_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_78) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000622_2213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st_1 = {0};
  struct StreamBuffer_R000622_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quantum_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_89_1 > 38)
  {
    acc_1 = ((acc_1 + (quantum_89_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_89_2 > 38)
  {
    acc_2 = ((acc_2 + (quantum_89_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_25_1 = 0;
  int anchor_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_25_1 = ((anchor_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_25_2 = ((anchor_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_25_1) & 127;
    acc_2 = (acc_2 + anchor_25_2) & 127;
  }

  int residue_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_57_1) & 63;
  aux_2 = (aux_2 + residue_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_55_1 = local_arr_1[aux_1 % 3];
  int accumulator_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_89_1 == quantum_89_2);
  assert(anchor_25_1 == anchor_25_2);
  assert(residue_57_1 == residue_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_55_1 == accumulator_55_2);
}

int fn_R000622_2213_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quantum_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_89 > 38)
  {
    acc = ((acc + (quantum_89 * 2)) + 5) & 127;
    aux ^= quantum_89 & 15;
  }
  else
  {
    acc = ((acc - quantum_89) + 11) & 127;
    aux += 3;
  }
  int anchor_25 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_25 = ((anchor_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_25) & 127;
  }

  int residue_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_57) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_55 = local_arr[aux % 3];
  acc = (acc + (accumulator_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000622_2213_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st_1 = {0};
  struct AudioFrame_R000622_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int index_reg_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_79_1) & 63;
  aux_2 = (aux_2 + index_reg_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_87_1)
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

  switch (quantum_87_2)
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
  int scale_24_1 = local_arr_1[aux_1 % 3];
  int scale_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_24_2 * 2)) & 127;
  int anchor_51_1 = 0;
  int anchor_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_51_1 = ((anchor_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_51_2 = ((anchor_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_51_1) & 127;
    acc_2 = (acc_2 + anchor_51_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_79_1 == index_reg_79_2);
  assert(quantum_87_1 == quantum_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_24_1 == scale_24_2);
  assert(anchor_51_1 == anchor_51_2);
}

int fn_R000622_2213_15(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int index_reg_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_79) & 63;
  acc ^= aux;
  int quantum_87 = (aux + st.buffer[1]) & 3;
  switch (quantum_87)
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
  int scale_24 = local_arr[aux % 3];
  acc = (acc + (scale_24 * 2)) & 127;
  int anchor_51 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_51 = ((anchor_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_51) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000622_2213_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st_1 = {0};
  struct AudioFrame_R000622_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int weight_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_27_1 > 47)
  {
    acc_1 = ((acc_1 + (weight_27_1 * 2)) + 5) & 127;
    aux_1 ^= weight_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_27_2 > 47)
  {
    acc_2 = ((acc_2 + (weight_27_2 * 2)) + 5) & 127;
    aux_2 ^= weight_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_22_1 = local_arr_1[aux_1 % 3];
  int residue_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_22_2 * 2)) & 127;
  int threshold_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_80_1) & 63;
  aux_2 = (aux_2 + threshold_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_40_1)
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

  switch (anchor_40_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_27_1 == weight_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_22_1 == residue_22_2);
  assert(threshold_80_1 == threshold_80_2);
  assert(anchor_40_1 == anchor_40_2);
}

int fn_R000622_2213_16(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int weight_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_27 > 47)
  {
    acc = ((acc + (weight_27 * 2)) + 5) & 127;
    aux ^= weight_27 & 15;
  }
  else
  {
    acc = ((acc - weight_27) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_22 = local_arr[aux % 3];
  acc = (acc + (residue_22 * 2)) & 127;
  int threshold_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_80) & 63;
  acc ^= aux;
  int anchor_40 = (aux + st.buffer[1]) & 3;
  switch (anchor_40)
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

void fn_R000622_2213_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st_1 = {0};
  struct AudioFrame_R000622_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_23_1 = local_arr_1[aux_1 % 3];
  int tally_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_23_2 * 2)) & 127;
  int damping_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_81_1) & 63;
  aux_2 = (aux_2 + damping_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_85_1)
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

  switch (damping_85_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_23_1 == tally_23_2);
  assert(damping_81_1 == damping_81_2);
  assert(damping_85_1 == damping_85_2);
}

int fn_R000622_2213_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int tally_23 = local_arr[aux % 3];
  acc = (acc + (tally_23 * 2)) & 127;
  int damping_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_81) & 63;
  acc ^= aux;
  int damping_85 = (aux + st.buffer[1]) & 3;
  switch (damping_85)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000622_2213_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st_1 = {0};
  struct StreamBuffer_R000622_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_85_1 = local_arr_1[aux_1 % 3];
  int accumulator_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_85_2 * 2)) & 127;
  int parity_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_55_1)
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

  switch (parity_55_2)
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

  int delta_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_78_1) & 63;
  aux_2 = (aux_2 + delta_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_85_1 == accumulator_85_2);
  assert(parity_55_1 == parity_55_2);
  assert(delta_78_1 == delta_78_2);
}

int fn_R000622_2213_18(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int accumulator_85 = local_arr[aux % 3];
  acc = (acc + (accumulator_85 * 2)) & 127;
  int parity_55 = (aux + st.buffer[1]) & 3;
  switch (parity_55)
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

  int delta_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_78) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000622_2213_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st_1 = {0};
  struct StreamBuffer_R000622_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int damping_53_1 = 0;
  int damping_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_53_1 = ((damping_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_53_2 = ((damping_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_53_1) & 127;
    acc_2 = (acc_2 + damping_53_2) & 127;
  }

  int index_reg_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_34_1)
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

  switch (index_reg_34_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_77_1 = local_arr_1[aux_1 % 3];
  int delta_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_53_1 == damping_53_2);
  assert(index_reg_34_1 == index_reg_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_77_1 == delta_77_2);
}

int fn_R000622_2213_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int damping_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_53 = ((damping_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_53) & 127;
  }

  int index_reg_34 = (aux + st.buffer[1]) & 3;
  switch (index_reg_34)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_77 = local_arr[aux % 3];
  acc = (acc + (delta_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000622_2213_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st_1 = {0};
  struct StreamBuffer_R000622_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tally_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_67_1) & 63;
  aux_2 = (aux_2 + tally_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_70_1 > 45)
  {
    acc_1 = ((acc_1 + (cursor_70_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_70_2 > 45)
  {
    acc_2 = ((acc_2 + (cursor_70_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_28_1)
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

  switch (threshold_28_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_67_1 == tally_67_2);
  assert(cursor_70_1 == cursor_70_2);
  assert(threshold_28_1 == threshold_28_2);
}

int fn_R000622_2213_20(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tally_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_67) & 63;
  acc ^= aux;
  int cursor_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_70 > 45)
  {
    acc = ((acc + (cursor_70 * 2)) + 5) & 127;
    aux ^= cursor_70 & 15;
  }
  else
  {
    acc = ((acc - cursor_70) + 11) & 127;
    aux += 3;
  }
  int threshold_28 = (aux + st.buffer[1]) & 3;
  switch (threshold_28)
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

void fn_R000622_2213_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st_1 = {0};
  struct AudioFrame_R000622_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int quantum_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_31_1) & 63;
  aux_2 = (aux_2 + quantum_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_35_1 = local_arr_1[aux_1 % 3];
  int margin_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_31_1 == quantum_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_35_1 == margin_35_2);
}

int fn_R000622_2213_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000622_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int quantum_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_31) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_35 = local_arr[aux % 3];
  acc = (acc + (margin_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000622_2213_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st_1 = {0};
  struct StreamBuffer_R000622_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int checksum_81_1 = 0;
  int checksum_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_81_1 = ((checksum_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_81_2 = ((checksum_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_81_1) & 127;
    acc_2 = (acc_2 + checksum_81_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_89_1 = local_arr_1[aux_1 % 3];
  int coefficient_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_81_1 == checksum_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_89_1 == coefficient_89_2);
}

int fn_R000622_2213_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int checksum_81 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_81 = ((checksum_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_81) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_89 = local_arr[aux % 3];
  acc = (acc + (coefficient_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000622_2213_23_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st_1 = {0};
  struct StreamBuffer_R000622_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_91_1 > 48)
  {
    acc_1 = ((acc_1 + (tally_91_1 * 2)) + 5) & 127;
    aux_1 ^= tally_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_91_2 > 48)
  {
    acc_2 = ((acc_2 + (tally_91_2 * 2)) + 5) & 127;
    aux_2 ^= tally_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_91_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_91_1 == tally_91_2);
}

int fn_R000622_2213_23(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000622_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_91 > 48)
  {
    acc = ((acc + (tally_91 * 2)) + 5) & 127;
    aux ^= tally_91 & 15;
  }
  else
  {
    acc = ((acc - tally_91) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000622_2213_24_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000622_2213_2 st_1 = {0};
  struct Transaction_R000622_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int vector_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_97_1 > 16)
  {
    acc_1 = ((acc_1 + (vector_97_1 * 2)) + 5) & 127;
    aux_1 ^= vector_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_97_2 > 16)
  {
    acc_2 = ((acc_2 + (vector_97_2 * 2)) + 5) & 127;
    aux_2 ^= vector_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_62_1 = 0;
  int cursor_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_62_1 = ((cursor_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_62_2 = ((cursor_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_62_1) & 127;
    acc_2 = (acc_2 + cursor_62_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_65_1 = local_arr_1[aux_1 % 3];
  int offset_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_65_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_97_1 == vector_97_2);
  assert(cursor_62_1 == cursor_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_65_1 == offset_65_2);
}

int fn_R000622_2213_24(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000622_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int vector_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_97 > 16)
  {
    acc = ((acc + (vector_97 * 2)) + 5) & 127;
    aux ^= vector_97 & 15;
  }
  else
  {
    acc = ((acc - vector_97) + 11) & 127;
    aux += 3;
  }
  int cursor_62 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_62 = ((cursor_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_62) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int offset_65 = local_arr[aux % 3];
  acc = (acc + (offset_65 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000622_0_1;
  int sec_r000622_0_2;
  int sec_r000622_1_1;
  int sec_r000622_1_2;
  int sec_r000622_2_1;
  int sec_r000622_2_2;
  int sec_r000622_3_1;
  int sec_r000622_3_2;
  int sec_r000622_4_1;
  int sec_r000622_4_2;
  int sec_r000622_5_1;
  int sec_r000622_5_2;
  int sec_r000622_6_1;
  int sec_r000622_6_2;
  int sec_r000622_7_1;
  int sec_r000622_7_2;
  int sec_r000622_8_1;
  int sec_r000622_8_2;
  int sec_r000622_9_1;
  int sec_r000622_9_2;
  int sec_r000622_10_1;
  int sec_r000622_10_2;
  int sec_r000622_11_1;
  int sec_r000622_11_2;
  int sec_r000622_12_1;
  int sec_r000622_12_2;
  int sec_r000622_13_1;
  int sec_r000622_13_2;
  int sec_r000622_14_1;
  int sec_r000622_14_2;
  int sec_r000622_15_1;
  int sec_r000622_15_2;
  int pub_r000622_0_1;
  int pub_r000622_0_2;
  int pub_r000622_1_1;
  int pub_r000622_1_2;
  int pub_r000622_2_1;
  int pub_r000622_2_2;
  int pub_r000622_3_1;
  int pub_r000622_3_2;
  int pub_r000622_4_1;
  int pub_r000622_4_2;
  int pub_r000622_5_1;
  int pub_r000622_5_2;
  int pub_r000622_6_1;
  int pub_r000622_6_2;
  int pub_r000622_7_1;
  int pub_r000622_7_2;
  int pub_r000622_8_1;
  int pub_r000622_8_2;
  int pub_r000622_9_1;
  int pub_r000622_9_2;
  int pub_r000622_10_1;
  int pub_r000622_10_2;
  int pub_r000622_11_1;
  int pub_r000622_11_2;
  int pub_r000622_12_1;
  int pub_r000622_12_2;
  int pub_r000622_13_1;
  int pub_r000622_13_2;
  int pub_r000622_14_1;
  int pub_r000622_14_2;
  int pub_r000622_15_1;
  int pub_r000622_15_2;
  int pub_r000622_16_1;
  int pub_r000622_16_2;
  int pub_r000622_17_1;
  int pub_r000622_17_2;
  int pub_r000622_18_1;
  int pub_r000622_18_2;
  int pub_r000622_19_1;
  int pub_r000622_19_2;
  int pub_r000622_20_1;
  int pub_r000622_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000622_0_1 >= (-100)) && (pub_r000622_0_1 <= 100));
  __CPROVER_assume((pub_r000622_0_2 >= (-100)) && (pub_r000622_0_2 <= 100));
  __CPROVER_assume((pub_r000622_1_1 >= (-100)) && (pub_r000622_1_1 <= 100));
  __CPROVER_assume((pub_r000622_1_2 >= (-100)) && (pub_r000622_1_2 <= 100));
  __CPROVER_assume((pub_r000622_2_1 >= (-100)) && (pub_r000622_2_1 <= 100));
  __CPROVER_assume((pub_r000622_2_2 >= (-100)) && (pub_r000622_2_2 <= 100));
  __CPROVER_assume((pub_r000622_3_1 >= (-100)) && (pub_r000622_3_1 <= 100));
  __CPROVER_assume((pub_r000622_3_2 >= (-100)) && (pub_r000622_3_2 <= 100));
  __CPROVER_assume((pub_r000622_4_1 >= (-100)) && (pub_r000622_4_1 <= 100));
  __CPROVER_assume((pub_r000622_4_2 >= (-100)) && (pub_r000622_4_2 <= 100));
  __CPROVER_assume((pub_r000622_5_1 >= (-100)) && (pub_r000622_5_1 <= 100));
  __CPROVER_assume((pub_r000622_5_2 >= (-100)) && (pub_r000622_5_2 <= 100));
  __CPROVER_assume((pub_r000622_6_1 >= (-100)) && (pub_r000622_6_1 <= 100));
  __CPROVER_assume((pub_r000622_6_2 >= (-100)) && (pub_r000622_6_2 <= 100));
  __CPROVER_assume((pub_r000622_7_1 >= (-100)) && (pub_r000622_7_1 <= 100));
  __CPROVER_assume((pub_r000622_7_2 >= (-100)) && (pub_r000622_7_2 <= 100));
  __CPROVER_assume((pub_r000622_8_1 >= (-100)) && (pub_r000622_8_1 <= 100));
  __CPROVER_assume((pub_r000622_8_2 >= (-100)) && (pub_r000622_8_2 <= 100));
  __CPROVER_assume((pub_r000622_9_1 >= (-100)) && (pub_r000622_9_1 <= 100));
  __CPROVER_assume((pub_r000622_9_2 >= (-100)) && (pub_r000622_9_2 <= 100));
  __CPROVER_assume((pub_r000622_10_1 >= (-100)) && (pub_r000622_10_1 <= 100));
  __CPROVER_assume((pub_r000622_10_2 >= (-100)) && (pub_r000622_10_2 <= 100));
  __CPROVER_assume((pub_r000622_11_1 >= (-100)) && (pub_r000622_11_1 <= 100));
  __CPROVER_assume((pub_r000622_11_2 >= (-100)) && (pub_r000622_11_2 <= 100));
  __CPROVER_assume((pub_r000622_12_1 >= (-100)) && (pub_r000622_12_1 <= 100));
  __CPROVER_assume((pub_r000622_12_2 >= (-100)) && (pub_r000622_12_2 <= 100));
  __CPROVER_assume((pub_r000622_13_1 >= (-100)) && (pub_r000622_13_1 <= 100));
  __CPROVER_assume((pub_r000622_13_2 >= (-100)) && (pub_r000622_13_2 <= 100));
  __CPROVER_assume((pub_r000622_14_1 >= (-100)) && (pub_r000622_14_1 <= 100));
  __CPROVER_assume((pub_r000622_14_2 >= (-100)) && (pub_r000622_14_2 <= 100));
  __CPROVER_assume((pub_r000622_15_1 >= (-100)) && (pub_r000622_15_1 <= 100));
  __CPROVER_assume((pub_r000622_15_2 >= (-100)) && (pub_r000622_15_2 <= 100));
  __CPROVER_assume((pub_r000622_16_1 >= (-100)) && (pub_r000622_16_1 <= 100));
  __CPROVER_assume((pub_r000622_16_2 >= (-100)) && (pub_r000622_16_2 <= 100));
  __CPROVER_assume((pub_r000622_17_1 >= (-100)) && (pub_r000622_17_1 <= 100));
  __CPROVER_assume((pub_r000622_17_2 >= (-100)) && (pub_r000622_17_2 <= 100));
  __CPROVER_assume((pub_r000622_18_1 >= (-100)) && (pub_r000622_18_1 <= 100));
  __CPROVER_assume((pub_r000622_18_2 >= (-100)) && (pub_r000622_18_2 <= 100));
  __CPROVER_assume((pub_r000622_19_1 >= (-100)) && (pub_r000622_19_1 <= 100));
  __CPROVER_assume((pub_r000622_19_2 >= (-100)) && (pub_r000622_19_2 <= 100));
  __CPROVER_assume((pub_r000622_20_1 >= (-100)) && (pub_r000622_20_1 <= 100));
  __CPROVER_assume((pub_r000622_20_2 >= (-100)) && (pub_r000622_20_2 <= 100));
  __CPROVER_assume((sec_r000622_0_1 >= 0) && (sec_r000622_0_1 <= 255));
  __CPROVER_assume((sec_r000622_0_2 >= 0) && (sec_r000622_0_2 <= 255));
  __CPROVER_assume((sec_r000622_1_1 >= 0) && (sec_r000622_1_1 <= 255));
  __CPROVER_assume((sec_r000622_1_2 >= 0) && (sec_r000622_1_2 <= 255));
  __CPROVER_assume((sec_r000622_2_1 >= 0) && (sec_r000622_2_1 <= 255));
  __CPROVER_assume((sec_r000622_2_2 >= 0) && (sec_r000622_2_2 <= 255));
  __CPROVER_assume((sec_r000622_3_1 >= 0) && (sec_r000622_3_1 <= 255));
  __CPROVER_assume((sec_r000622_3_2 >= 0) && (sec_r000622_3_2 <= 255));
  __CPROVER_assume((sec_r000622_4_1 >= 0) && (sec_r000622_4_1 <= 255));
  __CPROVER_assume((sec_r000622_4_2 >= 0) && (sec_r000622_4_2 <= 255));
  __CPROVER_assume((sec_r000622_5_1 >= 0) && (sec_r000622_5_1 <= 255));
  __CPROVER_assume((sec_r000622_5_2 >= 0) && (sec_r000622_5_2 <= 255));
  __CPROVER_assume((sec_r000622_6_1 >= 0) && (sec_r000622_6_1 <= 255));
  __CPROVER_assume((sec_r000622_6_2 >= 0) && (sec_r000622_6_2 <= 255));
  __CPROVER_assume((sec_r000622_7_1 >= 0) && (sec_r000622_7_1 <= 255));
  __CPROVER_assume((sec_r000622_7_2 >= 0) && (sec_r000622_7_2 <= 255));
  __CPROVER_assume((sec_r000622_8_1 >= 0) && (sec_r000622_8_1 <= 255));
  __CPROVER_assume((sec_r000622_8_2 >= 0) && (sec_r000622_8_2 <= 255));
  __CPROVER_assume((sec_r000622_9_1 >= 0) && (sec_r000622_9_1 <= 255));
  __CPROVER_assume((sec_r000622_9_2 >= 0) && (sec_r000622_9_2 <= 255));
  __CPROVER_assume((sec_r000622_10_1 >= 0) && (sec_r000622_10_1 <= 255));
  __CPROVER_assume((sec_r000622_10_2 >= 0) && (sec_r000622_10_2 <= 255));
  __CPROVER_assume((sec_r000622_11_1 >= 0) && (sec_r000622_11_1 <= 255));
  __CPROVER_assume((sec_r000622_11_2 >= 0) && (sec_r000622_11_2 <= 255));
  __CPROVER_assume((sec_r000622_12_1 >= 0) && (sec_r000622_12_1 <= 255));
  __CPROVER_assume((sec_r000622_12_2 >= 0) && (sec_r000622_12_2 <= 255));
  __CPROVER_assume((sec_r000622_13_1 >= 0) && (sec_r000622_13_1 <= 255));
  __CPROVER_assume((sec_r000622_13_2 >= 0) && (sec_r000622_13_2 <= 255));
  __CPROVER_assume((sec_r000622_14_1 >= 0) && (sec_r000622_14_1 <= 255));
  __CPROVER_assume((sec_r000622_14_2 >= 0) && (sec_r000622_14_2 <= 255));
  __CPROVER_assume((sec_r000622_15_1 >= 0) && (sec_r000622_15_1 <= 255));
  __CPROVER_assume((sec_r000622_15_2 >= 0) && (sec_r000622_15_2 <= 255));
  struct StreamBuffer_R000622_2213_0 st_var_0_1 = {0};
  struct StreamBuffer_R000622_2213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000622_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000622_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000622_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000622_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000622_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000622_0_2 + 7) & 15;
  struct AudioFrame_R000622_2213_1 st_var_1_1 = {0};
  struct AudioFrame_R000622_2213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000622_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000622_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000622_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000622_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000622_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000622_0_2 + 9) & 15;
  struct Transaction_R000622_2213_2 st_var_2_1 = {0};
  struct Transaction_R000622_2213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000622_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000622_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000622_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000622_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000622_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000622_0_2 + 11) & 15;
  union ColorPixel_R000622_2213_0 u_var_1;
  union ColorPixel_R000622_2213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 50)
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
  if (stage_v_0_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 50)
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
  if (stage_v_1_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 51)
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
  if (stage_v_1_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 51)
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
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 6) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((st_var_0_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_0_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 51)
    {
      chk_sum_1 ^= stage_v_9_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_9_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 51)
    {
      chk_sum_2 ^= stage_v_9_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 11) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 43)
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
  if (stage_v_12_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 43)
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
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 23) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  int stage_v_23_1 = (st_var_2_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_2_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 28) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 33) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = ((st_var_1_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_1_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 47)
    {
      chk_sum_1 ^= stage_v_34_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_34_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 47)
    {
      chk_sum_2 ^= stage_v_34_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_35_1 = ((st_var_2_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_2_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 49)
    {
      chk_sum_1 ^= stage_v_35_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_35_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 49)
    {
      chk_sum_2 ^= stage_v_35_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 34)
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
  if (stage_v_38_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 34)
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
  int stage_v_39_1 = (st_var_0_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_0_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = ((st_var_2_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_2_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 33)
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
  if (stage_v_41_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 33)
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
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 39)
    {
      chk_sum_1 ^= stage_v_42_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_42_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 39)
    {
      chk_sum_2 ^= stage_v_42_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_43_1 = ((st_var_1_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_1_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 28)
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
  if (stage_v_43_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 28)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 45) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 46) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = ((st_var_2_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_2_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 53)
    {
      chk_sum_1 ^= stage_v_47_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_47_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 53)
    {
      chk_sum_2 ^= stage_v_47_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_48_1 = (st_var_0_1.buffer[0] ^ 51) & 3;
  int stage_v_48_2 = (st_var_0_2.buffer[0] ^ 51) & 3;
  switch (stage_v_48_1)
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

  switch (stage_v_48_2)
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

  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
  int stage_v_52_1 = ((st_var_1_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_1_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 26)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 26)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_54_1 = (st_var_0_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_0_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_56_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  if (stage_v_59_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 38)
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
  if (stage_v_59_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 38)
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
  int stage_v_60_1 = ((st_var_0_1.buffer[0] * 2) + 187) & 63;
  int stage_v_60_2 = ((st_var_0_2.buffer[0] * 2) + 187) & 63;
  if (stage_v_60_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 42)
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
  if (stage_v_60_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 42)
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
  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_62_1 = ((st_var_2_1.buffer[2] * 2) + 193) & 63;
  int stage_v_62_2 = ((st_var_2_2.buffer[2] * 2) + 193) & 63;
  if (stage_v_62_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_62_1) - 5) & 255;
    if (stage_v_62_1 > 51)
    {
      chk_sum_1 ^= stage_v_62_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_62_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_62_2) - 5) & 255;
    if (stage_v_62_2 > 51)
    {
      chk_sum_2 ^= stage_v_62_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_63_1 = (st_var_0_1.buffer[0] ^ 66) & 3;
  int stage_v_63_2 = (st_var_0_2.buffer[0] ^ 66) & 3;
  switch (stage_v_63_1)
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

  switch (stage_v_63_2)
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

  int stage_v_64_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (69 & 31);
  int stage_v_64_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (69 & 31);
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= (stage_v_64_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_64_2 << 1) & 127;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
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
  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 69) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  int stage_v_69_1 = ((st_var_0_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_0_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 38)
    {
      chk_sum_1 ^= stage_v_69_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_69_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 38)
    {
      chk_sum_2 ^= stage_v_69_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_70_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (75 & 31);
  int stage_v_70_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (75 & 31);
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= (stage_v_70_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_70_2 << 1) & 127;
  int stage_v_71_1 = ((st_var_2_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_2_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 37)
    {
      chk_sum_1 ^= stage_v_71_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_71_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 37)
    {
      chk_sum_2 ^= stage_v_71_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 40)
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
  if (stage_v_72_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 40)
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
  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = ((st_var_2_1.buffer[2] * 2) + 229) & 63;
  int stage_v_74_2 = ((st_var_2_2.buffer[2] * 2) + 229) & 63;
  if (stage_v_74_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_74_1) - 5) & 255;
    if (stage_v_74_1 > 25)
    {
      chk_sum_1 ^= stage_v_74_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_74_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_74_2) - 5) & 255;
    if (stage_v_74_2 > 25)
    {
      chk_sum_2 ^= stage_v_74_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_75_1 = (st_var_0_1.buffer[0] ^ 78) & 3;
  int stage_v_75_2 = (st_var_0_2.buffer[0] ^ 78) & 3;
  switch (stage_v_75_1)
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

  switch (stage_v_75_2)
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

  int stage_v_76_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_76_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_77_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (82 & 31);
  int stage_v_77_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (82 & 31);
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= (stage_v_77_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_77_2 << 1) & 127;
  int stage_v_78_1 = (st_var_0_1.buffer[0] ^ 81) & 3;
  int stage_v_78_2 = (st_var_0_2.buffer[0] ^ 81) & 3;
  switch (stage_v_78_1)
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

  switch (stage_v_78_2)
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

  int stage_v_79_1 = (st_var_1_1.buffer[0] ^ 82) & 3;
  int stage_v_79_2 = (st_var_1_2.buffer[0] ^ 82) & 3;
  switch (stage_v_79_1)
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

  switch (stage_v_79_2)
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

  int stage_v_80_1 = table_1[0];
  int stage_v_80_2 = table_2[0];
  table_1[0] = (table_1[1] + 161) & 63;
  table_2[0] = (table_2[1] + 161) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 82) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 82) & 15;
  int stage_v_81_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_81_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= stage_v_81_1;
  chk_sum_2 ^= stage_v_81_2;
  int stage_v_82_1 = ((st_var_1_1.buffer[1] * 2) + 253) & 63;
  int stage_v_82_2 = ((st_var_1_2.buffer[1] * 2) + 253) & 63;
  if (stage_v_82_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_82_1) - 5) & 255;
    if (stage_v_82_1 > 42)
    {
      chk_sum_1 ^= stage_v_82_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_82_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_82_2) - 5) & 255;
    if (stage_v_82_2 > 42)
    {
      chk_sum_2 ^= stage_v_82_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_85_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_85_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 87) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 87) & 15;
  int stage_v_86_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_86_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= stage_v_86_1;
  chk_sum_2 ^= stage_v_86_2;
  int stage_v_87_1 = ((st_var_0_1.buffer[0] * 2) + 268) & 63;
  int stage_v_87_2 = ((st_var_0_2.buffer[0] * 2) + 268) & 63;
  if (stage_v_87_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_87_1) - 5) & 255;
    if (stage_v_87_1 > 38)
    {
      chk_sum_1 ^= stage_v_87_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_87_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_87_2) - 5) & 255;
    if (stage_v_87_2 > 38)
    {
      chk_sum_2 ^= stage_v_87_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_88_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_88_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_89_1 = (st_var_2_1.buffer[0] ^ 92) & 3;
  int stage_v_89_2 = (st_var_2_2.buffer[0] ^ 92) & 3;
  switch (stage_v_89_1)
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

  switch (stage_v_89_2)
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

  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_90_1 = ((stage_v_90_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_90_2 = ((stage_v_90_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (97 & 31);
  int stage_v_92_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (97 & 31);
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  chk_sum_1 ^= (stage_v_92_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_92_2 << 1) & 127;
  int stage_v_93_1 = ((st_var_0_1.buffer[0] * 2) + 286) & 63;
  int stage_v_93_2 = ((st_var_0_2.buffer[0] * 2) + 286) & 63;
  if (stage_v_93_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_93_1) - 5) & 255;
    if (stage_v_93_1 > 50)
    {
      chk_sum_1 ^= stage_v_93_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_93_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_93_2) - 5) & 255;
    if (stage_v_93_2 > 50)
    {
      chk_sum_2 ^= stage_v_93_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_94_1 = ((st_var_1_1.buffer[1] * 2) + 289) & 63;
  int stage_v_94_2 = ((st_var_1_2.buffer[1] * 2) + 289) & 63;
  if (stage_v_94_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_94_1) - 5) & 255;
    if (stage_v_94_1 > 27)
    {
      chk_sum_1 ^= stage_v_94_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_94_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_94_2) - 5) & 255;
    if (stage_v_94_2 > 27)
    {
      chk_sum_2 ^= stage_v_94_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_95_1 = table_1[3];
  int stage_v_95_2 = table_2[3];
  table_1[3] = (table_1[0] + 191) & 63;
  table_2[3] = (table_2[0] + 191) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_96_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_98_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_98_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_98_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_99_1 = (st_var_0_1.buffer[0] ^ 102) & 3;
  int stage_v_99_2 = (st_var_0_2.buffer[0] ^ 102) & 3;
  switch (stage_v_99_1)
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

  switch (stage_v_99_2)
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

  int stage_v_100_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_100_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_100_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_100_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_101_1 = ((st_var_2_1.buffer[2] * 2) + 310) & 63;
  int stage_v_101_2 = ((st_var_2_2.buffer[2] * 2) + 310) & 63;
  if (stage_v_101_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_101_1) - 5) & 255;
    if (stage_v_101_1 > 41)
    {
      chk_sum_1 ^= stage_v_101_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_101_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_101_2) - 5) & 255;
    if (stage_v_101_2 > 41)
    {
      chk_sum_2 ^= stage_v_101_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_102_1 = table_1[2];
  int stage_v_102_2 = table_2[2];
  table_1[2] = (table_1[3] + 205) & 63;
  table_2[2] = (table_2[3] + 205) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (st_var_1_1.buffer[0] ^ 106) & 3;
  int stage_v_103_2 = (st_var_1_2.buffer[0] ^ 106) & 3;
  switch (stage_v_103_1)
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

  switch (stage_v_103_2)
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

  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_104_1 = ((stage_v_104_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (110 & 31);
  int stage_v_105_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (110 & 31);
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= (stage_v_105_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_105_2 << 1) & 127;
  int stage_v_106_1 = table_1[2];
  int stage_v_106_2 = table_2[2];
  table_1[2] = (table_1[3] + 213) & 63;
  table_2[2] = (table_2[3] + 213) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = table_1[0];
  int stage_v_108_2 = table_2[0];
  table_1[0] = (table_1[1] + 217) & 63;
  table_2[0] = (table_2[1] + 217) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (114 & 31);
  int stage_v_109_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (114 & 31);
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  chk_sum_1 ^= (stage_v_109_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_109_2 << 1) & 127;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_110_1 = ((stage_v_110_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_110_2 = ((stage_v_110_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = table_1[0];
  int stage_v_112_2 = table_2[0];
  table_1[0] = (table_1[1] + 225) & 63;
  table_2[0] = (table_2[1] + 225) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (st_var_2_1.buffer[0] ^ 116) & 3;
  int stage_v_113_2 = (st_var_2_2.buffer[0] ^ 116) & 3;
  switch (stage_v_113_1)
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

  switch (stage_v_113_2)
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

  int stage_v_114_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (119 & 31);
  int stage_v_114_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (119 & 31);
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= (stage_v_114_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_114_2 << 1) & 127;
  int stage_v_115_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_115_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_115_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_115_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_116_1 = ((stage_v_116_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_116_2 = ((stage_v_116_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (st_var_0_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_0_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  int stage_v_118_1 = table_1[2];
  int stage_v_118_2 = table_2[2];
  table_1[2] = (table_1[3] + 237) & 63;
  table_2[2] = (table_2[3] + 237) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = table_1[3];
  int stage_v_119_2 = table_2[3];
  table_1[3] = (table_1[0] + 239) & 63;
  table_2[3] = (table_2[0] + 239) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (st_var_0_1.buffer[0] ^ 123) & 3;
  int stage_v_120_2 = (st_var_0_2.buffer[0] ^ 123) & 3;
  switch (stage_v_120_1)
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

  switch (stage_v_120_2)
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

  int stage_v_121_1 = ((st_var_1_1.buffer[1] * 2) + 370) & 63;
  int stage_v_121_2 = ((st_var_1_2.buffer[1] * 2) + 370) & 63;
  if (stage_v_121_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_121_1) - 5) & 255;
    if (stage_v_121_1 > 28)
    {
      chk_sum_1 ^= stage_v_121_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_121_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_121_2) - 5) & 255;
    if (stage_v_121_2 > 28)
    {
      chk_sum_2 ^= stage_v_121_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_122_1 = (st_var_2_1.buffer[0] ^ 125) & 3;
  int stage_v_122_2 = (st_var_2_2.buffer[0] ^ 125) & 3;
  switch (stage_v_122_1)
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

  switch (stage_v_122_2)
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

  int stage_v_123_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (128 & 31);
  int stage_v_123_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (128 & 31);
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= (stage_v_123_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_123_2 << 1) & 127;
  int stage_v_124_1 = ((st_var_1_1.buffer[1] * 2) + 379) & 63;
  int stage_v_124_2 = ((st_var_1_2.buffer[1] * 2) + 379) & 63;
  if (stage_v_124_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_124_1) - 5) & 255;
    if (stage_v_124_1 > 38)
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
  if (stage_v_124_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_124_2) - 5) & 255;
    if (stage_v_124_2 > 38)
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
  int stage_v_125_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_125_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_126_1 = ((stage_v_126_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_126_2 = ((stage_v_126_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_127_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_128_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_128_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (st_var_1_1.buffer[0] ^ 133) & 3;
  int stage_v_130_2 = (st_var_1_2.buffer[0] ^ 133) & 3;
  switch (stage_v_130_1)
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

  switch (stage_v_130_2)
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

  int stage_v_131_1 = (st_var_2_1.buffer[0] ^ 134) & 3;
  int stage_v_131_2 = (st_var_2_2.buffer[0] ^ 134) & 3;
  switch (stage_v_131_1)
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

  switch (stage_v_131_2)
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

  int stage_v_132_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_132_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((st_var_2_1.buffer[2] * 2) + 409) & 63;
  int stage_v_134_2 = ((st_var_2_2.buffer[2] * 2) + 409) & 63;
  if (stage_v_134_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_134_1) - 5) & 255;
    if (stage_v_134_1 > 46)
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
  if (stage_v_134_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_134_2) - 5) & 255;
    if (stage_v_134_2 > 46)
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
  int stage_v_135_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (140 & 31);
  int stage_v_135_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (140 & 31);
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= (stage_v_135_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_135_2 << 1) & 127;
  int stage_v_136_1 = (st_var_1_1.buffer[0] ^ 139) & 3;
  int stage_v_136_2 = (st_var_1_2.buffer[0] ^ 139) & 3;
  switch (stage_v_136_1)
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

  switch (stage_v_136_2)
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

  int stage_v_137_1 = (st_var_2_1.buffer[0] ^ 140) & 3;
  int stage_v_137_2 = (st_var_2_2.buffer[0] ^ 140) & 3;
  switch (stage_v_137_1)
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

  switch (stage_v_137_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 139) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 139) & 15;
  int stage_v_138_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_138_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  chk_sum_1 ^= stage_v_138_1;
  chk_sum_2 ^= stage_v_138_2;
  int stage_v_139_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_139_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 141) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 141) & 15;
  int stage_v_140_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_140_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  chk_sum_1 ^= stage_v_140_1;
  chk_sum_2 ^= stage_v_140_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 142) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 142) & 15;
  int stage_v_141_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_141_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= stage_v_141_1;
  chk_sum_2 ^= stage_v_141_2;
  int stage_v_142_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (147 & 31);
  int stage_v_142_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (147 & 31);
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= (stage_v_142_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_142_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 144) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 144) & 15;
  int stage_v_143_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_143_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  chk_sum_1 ^= stage_v_143_1;
  chk_sum_2 ^= stage_v_143_2;
  int stage_v_144_1 = table_1[0];
  int stage_v_144_2 = table_2[0];
  table_1[0] = (table_1[1] + 289) & 63;
  table_2[0] = (table_2[1] + 289) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_145_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_146_1 = (st_var_2_1.buffer[0] ^ 149) & 3;
  int stage_v_146_2 = (st_var_2_2.buffer[0] ^ 149) & 3;
  switch (stage_v_146_1)
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

  switch (stage_v_146_2)
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

  int stage_v_147_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (152 & 31);
  int stage_v_147_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (152 & 31);
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= (stage_v_147_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_147_2 << 1) & 127;
  int stage_v_148_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (153 & 31);
  int stage_v_148_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (153 & 31);
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  chk_sum_1 ^= (stage_v_148_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_148_2 << 1) & 127;
  int stage_v_149_1 = ((st_var_2_1.buffer[2] * 2) + 454) & 63;
  int stage_v_149_2 = ((st_var_2_2.buffer[2] * 2) + 454) & 63;
  if (stage_v_149_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_149_1) - 5) & 255;
    if (stage_v_149_1 > 53)
    {
      chk_sum_1 ^= stage_v_149_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_149_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_149_2) - 5) & 255;
    if (stage_v_149_2 > 53)
    {
      chk_sum_2 ^= stage_v_149_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_150_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_150_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_150_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_150_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_151_1 = (st_var_1_1.buffer[0] ^ 154) & 3;
  int stage_v_151_2 = (st_var_1_2.buffer[0] ^ 154) & 3;
  switch (stage_v_151_1)
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

  switch (stage_v_151_2)
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

  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_152_1 = ((stage_v_152_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_152_2 = ((stage_v_152_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_153_1 = ((stage_v_153_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_153_2 = ((stage_v_153_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_154_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_154_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_154_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = table_1[0];
  int stage_v_156_2 = table_2[0];
  table_1[0] = (table_1[1] + 313) & 63;
  table_2[0] = (table_2[1] + 313) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (162 & 31);
  int stage_v_157_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (162 & 31);
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= (stage_v_157_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_157_2 << 1) & 127;
  int stage_v_158_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (163 & 31);
  int stage_v_158_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (163 & 31);
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= (stage_v_158_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_158_2 << 1) & 127;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_159_1 = ((stage_v_159_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_159_2 = ((stage_v_159_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 161) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 161) & 15;
  int stage_v_160_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_160_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= stage_v_160_1;
  chk_sum_2 ^= stage_v_160_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 162) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 162) & 15;
  int stage_v_161_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_161_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  chk_sum_1 ^= stage_v_161_1;
  chk_sum_2 ^= stage_v_161_2;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_162_1 = ((stage_v_162_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_162_2 = ((stage_v_162_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_163_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_164_1 = table_1[0];
  int stage_v_164_2 = table_2[0];
  table_1[0] = (table_1[1] + 329) & 63;
  table_2[0] = (table_2[1] + 329) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (170 & 31);
  int stage_v_165_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (170 & 31);
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  chk_sum_1 ^= (stage_v_165_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_165_2 << 1) & 127;
  int stage_v_166_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_166_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_167_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_167_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_168_1 = ((stage_v_168_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_168_2 = ((stage_v_168_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_169_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_170_1 = table_1[2];
  int stage_v_170_2 = table_2[2];
  table_1[2] = (table_1[3] + 341) & 63;
  table_2[2] = (table_2[3] + 341) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (176 & 31);
  int stage_v_171_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (176 & 31);
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  chk_sum_1 ^= (stage_v_171_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_171_2 << 1) & 127;
  int stage_v_172_1 = table_1[0];
  int stage_v_172_2 = table_2[0];
  table_1[0] = (table_1[1] + 345) & 63;
  table_2[0] = (table_2[1] + 345) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((st_var_2_1.buffer[2] * 2) + 526) & 63;
  int stage_v_173_2 = ((st_var_2_2.buffer[2] * 2) + 526) & 63;
  if (stage_v_173_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_173_1) - 5) & 255;
    if (stage_v_173_1 > 51)
    {
      chk_sum_1 ^= stage_v_173_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_173_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_173_2) - 5) & 255;
    if (stage_v_173_2 > 51)
    {
      chk_sum_2 ^= stage_v_173_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_174_1 = table_1[2];
  int stage_v_174_2 = table_2[2];
  table_1[2] = (table_1[3] + 349) & 63;
  table_2[2] = (table_2[3] + 349) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_175_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_175_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_175_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_176_1 = (st_var_2_1.buffer[0] ^ 179) & 3;
  int stage_v_176_2 = (st_var_2_2.buffer[0] ^ 179) & 3;
  switch (stage_v_176_1)
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

  switch (stage_v_176_2)
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

  if ((sec_r000622_1_1 & 1) != 0)
  {
    if ((sec_r000622_2_1 & 2) != 0)
    {
      out_sink_1 += 34;
    }
    else
    {
      out_sink_1 += 30;
    }
  }
  else
  {
    if ((sec_r000622_1_1 & 4) != 0)
    {
      out_sink_1 -= 30;
    }
    else
    {
      out_sink_1 -= 67;
    }
  }
  if ((sec_r000622_1_2 & 1) != 0)
  {
    if ((sec_r000622_2_2 & 2) != 0)
    {
      out_sink_2 += 34;
    }
    else
    {
      out_sink_2 += 30;
    }
  }
  else
  {
    if ((sec_r000622_1_2 & 4) != 0)
    {
      out_sink_2 -= 30;
    }
    else
    {
      out_sink_2 -= 67;
    }
  }
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000622_15_1 == pub_r000622_15_2);
  __CPROVER_assume(sec_r000622_14_1 != sec_r000622_14_2);
  __CPROVER_assume(sec_r000622_5_1 != sec_r000622_5_2);
  __CPROVER_assume(pub_r000622_6_1 == pub_r000622_6_2);
  __CPROVER_assume(sec_r000622_10_1 != sec_r000622_10_2);
  __CPROVER_assume(sec_r000622_13_1 != sec_r000622_13_2);
  __CPROVER_assume(sec_r000622_7_1 != sec_r000622_7_2);
  __CPROVER_assume(pub_r000622_7_1 == pub_r000622_7_2);
  __CPROVER_assume(sec_r000622_3_1 != sec_r000622_3_2);
  __CPROVER_assume(pub_r000622_8_1 == pub_r000622_8_2);
  __CPROVER_assume(sec_r000622_8_1 != sec_r000622_8_2);
  __CPROVER_assume(sec_r000622_11_1 != sec_r000622_11_2);
  __CPROVER_assume(pub_r000622_1_1 == pub_r000622_1_2);
  __CPROVER_assume(sec_r000622_4_1 != sec_r000622_4_2);
  __CPROVER_assume(sec_r000622_2_1 != sec_r000622_2_2);
  __CPROVER_assume(pub_r000622_11_1 == pub_r000622_11_2);
  __CPROVER_assume(sec_r000622_9_1 != sec_r000622_9_2);
  __CPROVER_assume(pub_r000622_16_1 == pub_r000622_16_2);
  __CPROVER_assume(pub_r000622_20_1 == pub_r000622_20_2);
  __CPROVER_assume(pub_r000622_2_1 == pub_r000622_2_2);
  __CPROVER_assume(pub_r000622_0_1 == pub_r000622_0_2);
  __CPROVER_assume(pub_r000622_18_1 == pub_r000622_18_2);
  __CPROVER_assume(sec_r000622_0_1 != sec_r000622_0_2);
  __CPROVER_assume(pub_r000622_19_1 == pub_r000622_19_2);
  __CPROVER_assume(sec_r000622_12_1 != sec_r000622_12_2);
  __CPROVER_assume(pub_r000622_10_1 == pub_r000622_10_2);
  __CPROVER_assume(sec_r000622_15_1 != sec_r000622_15_2);
  __CPROVER_assume(sec_r000622_1_1 != sec_r000622_1_2);
  __CPROVER_assume(pub_r000622_3_1 == pub_r000622_3_2);
  __CPROVER_assume(pub_r000622_5_1 == pub_r000622_5_2);
  __CPROVER_assume(sec_r000622_6_1 != sec_r000622_6_2);
  __CPROVER_assume(pub_r000622_13_1 == pub_r000622_13_2);
  __CPROVER_assume(pub_r000622_12_1 == pub_r000622_12_2);
  __CPROVER_assume(pub_r000622_17_1 == pub_r000622_17_2);
  __CPROVER_assume(pub_r000622_14_1 == pub_r000622_14_2);
  __CPROVER_assume(pub_r000622_9_1 == pub_r000622_9_2);
  __CPROVER_assume(pub_r000622_4_1 == pub_r000622_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.fee == st_var_2_2.fee);
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
}


