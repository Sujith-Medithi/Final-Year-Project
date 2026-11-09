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
struct AudioFrame_R001928_2813_0
{
  short envelope;
  unsigned char sample_rate;
  int peak;
  unsigned char channels;
  int buffer[3];
};
struct CipherContext_R001928_2813_1
{
  unsigned char nonce;
  int counter;
  int tag;
  short iv;
  unsigned char round_key;
  int flags;
  int buffer[3];
};
union ColorPixel_R001928_2813_0
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
void fn_R001928_2813_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int bound_59_1 = 0;
  int bound_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_59_1 = ((bound_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_59_2 = ((bound_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_59_1) & 127;
    acc_2 = (acc_2 + bound_59_2) & 127;
  }

  int pivot_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_56_1 > 10)
  {
    acc_1 = ((acc_1 + (pivot_56_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_56_2 > 10)
  {
    acc_2 = ((acc_2 + (pivot_56_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_56_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_81_1 = local_arr_1[aux_1 % 3];
  int bound_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_59_1 == bound_59_2);
  assert(pivot_56_1 == pivot_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_81_1 == bound_81_2);
}

int fn_R001928_2813_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int bound_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_59 = ((bound_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_59) & 127;
  }

  int pivot_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_56 > 10)
  {
    acc = ((acc + (pivot_56 * 2)) + 5) & 127;
    aux ^= pivot_56 & 15;
  }
  else
  {
    acc = ((acc - pivot_56) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_81 = local_arr[aux % 3];
  acc = (acc + (bound_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001928_2813_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int threshold_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_85_1)
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

  switch (threshold_85_2)
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

  int cursor_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_50_1) & 63;
  aux_2 = (aux_2 + cursor_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_96_1 > 17)
  {
    acc_1 = ((acc_1 + (delta_96_1 * 2)) + 5) & 127;
    aux_1 ^= delta_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_96_2 > 17)
  {
    acc_2 = ((acc_2 + (delta_96_2 * 2)) + 5) & 127;
    aux_2 ^= delta_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_85_1 == threshold_85_2);
  assert(cursor_50_1 == cursor_50_2);
  assert(delta_96_1 == delta_96_2);
}

int fn_R001928_2813_1(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int threshold_85 = (aux + st.buffer[1]) & 3;
  switch (threshold_85)
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

  int cursor_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_50) & 63;
  acc ^= aux;
  int delta_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_96 > 17)
  {
    acc = ((acc + (delta_96 * 2)) + 5) & 127;
    aux ^= delta_96 & 15;
  }
  else
  {
    acc = ((acc - delta_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001928_2813_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st_1 = {0};
  struct AudioFrame_R001928_2813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_87_1 = local_arr_1[aux_1 % 3];
  int offset_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_87_2 * 2)) & 127;
  int offset_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_20_1) & 63;
  aux_2 = (aux_2 + offset_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_71_1)
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

  switch (damping_71_2)
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

  int sample_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_41_1 > 39)
  {
    acc_1 = ((acc_1 + (sample_41_1 * 2)) + 5) & 127;
    aux_1 ^= sample_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_41_2 > 39)
  {
    acc_2 = ((acc_2 + (sample_41_2 * 2)) + 5) & 127;
    aux_2 ^= sample_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_87_1 == offset_87_2);
  assert(offset_20_1 == offset_20_2);
  assert(damping_71_1 == damping_71_2);
  assert(sample_41_1 == sample_41_2);
}

int fn_R001928_2813_2(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int offset_87 = local_arr[aux % 3];
  acc = (acc + (offset_87 * 2)) & 127;
  int offset_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_20) & 63;
  acc ^= aux;
  int damping_71 = (aux + st.buffer[1]) & 3;
  switch (damping_71)
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

  int sample_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_41 > 39)
  {
    acc = ((acc + (sample_41 * 2)) + 5) & 127;
    aux ^= sample_41 & 15;
  }
  else
  {
    acc = ((acc - sample_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001928_2813_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_71_1)
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

  switch (anchor_71_2)
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
  int tally_91_1 = local_arr_1[aux_1 % 3];
  int tally_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_91_2 * 2)) & 127;
  int damping_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_43_1) & 63;
  aux_2 = (aux_2 + damping_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_71_1 == anchor_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_91_1 == tally_91_2);
  assert(damping_43_1 == damping_43_2);
}

int fn_R001928_2813_3(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_71 = (aux + st.buffer[1]) & 3;
  switch (anchor_71)
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
  int tally_91 = local_arr[aux % 3];
  acc = (acc + (tally_91 * 2)) & 127;
  int damping_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001928_2813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
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
  int scale_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_97_1) & 63;
  aux_2 = (aux_2 + scale_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_66_1 = 0;
  int anchor_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_66_1 = ((anchor_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_66_2 = ((anchor_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_66_1) & 127;
    acc_2 = (acc_2 + anchor_66_2) & 127;
  }

  int mask_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_24_1 > 46)
  {
    acc_1 = ((acc_1 + (mask_24_1 * 2)) + 5) & 127;
    aux_1 ^= mask_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_24_2 > 46)
  {
    acc_2 = ((acc_2 + (mask_24_2 * 2)) + 5) & 127;
    aux_2 ^= mask_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_97_1 == scale_97_2);
  assert(anchor_66_1 == anchor_66_2);
  assert(mask_24_1 == mask_24_2);
}

int fn_R001928_2813_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_97) & 63;
  acc ^= aux;
  int anchor_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_66 = ((anchor_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_66) & 127;
  }

  int mask_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_24 > 46)
  {
    acc = ((acc + (mask_24 * 2)) + 5) & 127;
    aux ^= mask_24 & 15;
  }
  else
  {
    acc = ((acc - mask_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001928_2813_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int bound_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_49_1) & 63;
  aux_2 = (aux_2 + bound_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_15_1)
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

  switch (phase_15_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_49_1 == bound_49_2);
  assert(phase_15_1 == phase_15_2);
}

int fn_R001928_2813_5(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int bound_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_49) & 63;
  acc ^= aux;
  int phase_15 = (aux + st.buffer[1]) & 3;
  switch (phase_15)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001928_2813_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int factor_95_1 = 0;
  int factor_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_95_1 = ((factor_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_95_2 = ((factor_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_95_1) & 127;
    acc_2 = (acc_2 + factor_95_2) & 127;
  }

  int stride_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_61_1)
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

  switch (stride_61_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_95_1 == factor_95_2);
  assert(stride_61_1 == stride_61_2);
}

int fn_R001928_2813_6(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int factor_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_95 = ((factor_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_95) & 127;
  }

  int stride_61 = (aux + st.buffer[1]) & 3;
  switch (stride_61)
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

void fn_R001928_2813_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_28_1 = local_arr_1[aux_1 % 3];
  int tally_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_28_2 * 2)) & 127;
  int weight_56_1 = 0;
  int weight_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_56_1 = ((weight_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_56_2 = ((weight_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_56_1) & 127;
    acc_2 = (acc_2 + weight_56_2) & 127;
  }

  int delta_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_68_1) & 63;
  aux_2 = (aux_2 + delta_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
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

  assert(tally_28_1 == tally_28_2);
  assert(weight_56_1 == weight_56_2);
  assert(delta_68_1 == delta_68_2);
}

int fn_R001928_2813_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_28 = local_arr[aux % 3];
  acc = (acc + (tally_28 * 2)) & 127;
  int weight_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_56 = ((weight_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_56) & 127;
  }

  int delta_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001928_2813_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int weight_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_69_1) & 63;
  aux_2 = (aux_2 + weight_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_39_1 > 46)
  {
    acc_1 = ((acc_1 + (delta_39_1 * 2)) + 5) & 127;
    aux_1 ^= delta_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_39_2 > 46)
  {
    acc_2 = ((acc_2 + (delta_39_2 * 2)) + 5) & 127;
    aux_2 ^= delta_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_31_1 = 0;
  int residue_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_31_1 = ((residue_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_31_2 = ((residue_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_31_1) & 127;
    acc_2 = (acc_2 + residue_31_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_69_1 == weight_69_2);
  assert(delta_39_1 == delta_39_2);
  assert(residue_31_1 == residue_31_2);
}

int fn_R001928_2813_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int weight_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_69) & 63;
  acc ^= aux;
  int delta_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_39 > 46)
  {
    acc = ((acc + (delta_39 * 2)) + 5) & 127;
    aux ^= delta_39 & 15;
  }
  else
  {
    acc = ((acc - delta_39) + 11) & 127;
    aux += 3;
  }
  int residue_31 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_31 = ((residue_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_31) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001928_2813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int margin_98_1 = 0;
  int margin_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_98_1 = ((margin_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_98_2 = ((margin_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_98_1) & 127;
    acc_2 = (acc_2 + margin_98_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_49_1)
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

  switch (parity_49_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_98_1 == margin_98_2);
  assert(parity_49_1 == parity_49_2);
}

int fn_R001928_2813_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int margin_98 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_98 = ((margin_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_98) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_49 = (aux + st.buffer[1]) & 3;
  switch (parity_49)
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

void fn_R001928_2813_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int index_reg_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_45_1)
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

  switch (index_reg_45_2)
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

  int sample_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_50_1) & 63;
  aux_2 = (aux_2 + sample_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_45_1 == index_reg_45_2);
  assert(sample_50_1 == sample_50_2);
}

int fn_R001928_2813_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int index_reg_45 = (aux + st.buffer[1]) & 3;
  switch (index_reg_45)
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

  int sample_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_50) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001928_2813_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_76_1 > 35)
  {
    acc_1 = ((acc_1 + (segment_76_1 * 2)) + 5) & 127;
    aux_1 ^= segment_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_76_2 > 35)
  {
    acc_2 = ((acc_2 + (segment_76_2 * 2)) + 5) & 127;
    aux_2 ^= segment_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_76_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_76_1 == segment_76_2);
}

int fn_R001928_2813_11(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_76 > 35)
  {
    acc = ((acc + (segment_76 * 2)) + 5) & 127;
    aux ^= segment_76 & 15;
  }
  else
  {
    acc = ((acc - segment_76) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001928_2813_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st_1 = {0};
  struct AudioFrame_R001928_2813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int scale_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_93_1) & 63;
  aux_2 = (aux_2 + scale_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_93_1 == scale_93_2);
}

int fn_R001928_2813_12(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int scale_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_93) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001928_2813_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st_1 = {0};
  struct AudioFrame_R001928_2813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_10_1 = local_arr_1[aux_1 % 3];
  int metric_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_10_2 * 2)) & 127;
  int threshold_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_11_1 > 29)
  {
    acc_1 = ((acc_1 + (threshold_11_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_11_2 > 29)
  {
    acc_2 = ((acc_2 + (threshold_11_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_39_1 = 0;
  int residue_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_39_1 = ((residue_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_39_2 = ((residue_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_39_1) & 127;
    acc_2 = (acc_2 + residue_39_2) & 127;
  }

  int factor_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_56_1) & 63;
  aux_2 = (aux_2 + factor_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_10_1 == metric_10_2);
  assert(threshold_11_1 == threshold_11_2);
  assert(residue_39_1 == residue_39_2);
  assert(factor_56_1 == factor_56_2);
}

int fn_R001928_2813_13(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int metric_10 = local_arr[aux % 3];
  acc = (acc + (metric_10 * 2)) & 127;
  int threshold_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_11 > 29)
  {
    acc = ((acc + (threshold_11 * 2)) + 5) & 127;
    aux ^= threshold_11 & 15;
  }
  else
  {
    acc = ((acc - threshold_11) + 11) & 127;
    aux += 3;
  }
  int residue_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_39 = ((residue_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_39) & 127;
  }

  int factor_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001928_2813_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int offset_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_23_1 > 26)
  {
    acc_1 = ((acc_1 + (offset_23_1 * 2)) + 5) & 127;
    aux_1 ^= offset_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_23_2 > 26)
  {
    acc_2 = ((acc_2 + (offset_23_2 * 2)) + 5) & 127;
    aux_2 ^= offset_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_85_1 = local_arr_1[aux_1 % 3];
  int anchor_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_23_1 == offset_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_85_1 == anchor_85_2);
}

int fn_R001928_2813_14(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int offset_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_23 > 26)
  {
    acc = ((acc + (offset_23 * 2)) + 5) & 127;
    aux ^= offset_23 & 15;
  }
  else
  {
    acc = ((acc - offset_23) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int anchor_85 = local_arr[aux % 3];
  acc = (acc + (anchor_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001928_2813_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quantum_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_75_1)
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

  switch (quantum_75_2)
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

  int margin_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_94_1 > 35)
  {
    acc_1 = ((acc_1 + (margin_94_1 * 2)) + 5) & 127;
    aux_1 ^= margin_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_94_2 > 35)
  {
    acc_2 = ((acc_2 + (margin_94_2 * 2)) + 5) & 127;
    aux_2 ^= margin_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_75_1 == quantum_75_2);
  assert(margin_94_1 == margin_94_2);
}

int fn_R001928_2813_15(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quantum_75 = (aux + st.buffer[1]) & 3;
  switch (quantum_75)
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

  int margin_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_94 > 35)
  {
    acc = ((acc + (margin_94 * 2)) + 5) & 127;
    aux ^= margin_94 & 15;
  }
  else
  {
    acc = ((acc - margin_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001928_2813_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_44_1 = local_arr_1[aux_1 % 3];
  int mask_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_44_2 * 2)) & 127;
  int scale_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_86_1)
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

  switch (scale_86_2)
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

  int index_reg_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_83_1) & 63;
  aux_2 = (aux_2 + index_reg_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
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

  assert(mask_44_1 == mask_44_2);
  assert(scale_86_1 == scale_86_2);
  assert(index_reg_83_1 == index_reg_83_2);
}

int fn_R001928_2813_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_44 = local_arr[aux % 3];
  acc = (acc + (mask_44 * 2)) & 127;
  int scale_86 = (aux + st.buffer[1]) & 3;
  switch (scale_86)
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

  int index_reg_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001928_2813_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int offset_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_95_1) & 63;
  aux_2 = (aux_2 + offset_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_66_1 > 47)
  {
    acc_1 = ((acc_1 + (damping_66_1 * 2)) + 5) & 127;
    aux_1 ^= damping_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_66_2 > 47)
  {
    acc_2 = ((acc_2 + (damping_66_2 * 2)) + 5) & 127;
    aux_2 ^= damping_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_55_1 = 0;
  int stride_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_55_1 = ((stride_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_55_2 = ((stride_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_55_1) & 127;
    acc_2 = (acc_2 + stride_55_2) & 127;
  }

  int window_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_44_1)
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

  switch (window_44_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_95_1 == offset_95_2);
  assert(damping_66_1 == damping_66_2);
  assert(stride_55_1 == stride_55_2);
  assert(window_44_1 == window_44_2);
}

int fn_R001928_2813_17(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int offset_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_95) & 63;
  acc ^= aux;
  int damping_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_66 > 47)
  {
    acc = ((acc + (damping_66 * 2)) + 5) & 127;
    aux ^= damping_66 & 15;
  }
  else
  {
    acc = ((acc - damping_66) + 11) & 127;
    aux += 3;
  }
  int stride_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_55 = ((stride_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_55) & 127;
  }

  int window_44 = (aux + st.buffer[1]) & 3;
  switch (window_44)
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

void fn_R001928_2813_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st_1 = {0};
  struct AudioFrame_R001928_2813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_69_1 = local_arr_1[aux_1 % 3];
  int anchor_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_69_2 * 2)) & 127;
  int anchor_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_11_1) & 63;
  aux_2 = (aux_2 + anchor_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_69_1 == anchor_69_2);
  assert(anchor_11_1 == anchor_11_2);
}

int fn_R001928_2813_18(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int anchor_69 = local_arr[aux % 3];
  acc = (acc + (anchor_69 * 2)) & 127;
  int anchor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_11) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001928_2813_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st_1 = {0};
  struct AudioFrame_R001928_2813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_50_1 = local_arr_1[aux_1 % 3];
  int scale_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_50_2 * 2)) & 127;
  int quantum_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_46_1 > 19)
  {
    acc_1 = ((acc_1 + (quantum_46_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_46_2 > 19)
  {
    acc_2 = ((acc_2 + (quantum_46_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_84_1)
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

  switch (damping_84_2)
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

  int checksum_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_20_1) & 63;
  aux_2 = (aux_2 + checksum_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_50_1 == scale_50_2);
  assert(quantum_46_1 == quantum_46_2);
  assert(damping_84_1 == damping_84_2);
  assert(checksum_20_1 == checksum_20_2);
}

int fn_R001928_2813_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int scale_50 = local_arr[aux % 3];
  acc = (acc + (scale_50 * 2)) & 127;
  int quantum_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_46 > 19)
  {
    acc = ((acc + (quantum_46 * 2)) + 5) & 127;
    aux ^= quantum_46 & 15;
  }
  else
  {
    acc = ((acc - quantum_46) + 11) & 127;
    aux += 3;
  }
  int damping_84 = (aux + st.buffer[1]) & 3;
  switch (damping_84)
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

  int checksum_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_20) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001928_2813_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st_1 = {0};
  struct AudioFrame_R001928_2813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int margin_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_90_1 > 35)
  {
    acc_1 = ((acc_1 + (margin_90_1 * 2)) + 5) & 127;
    aux_1 ^= margin_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_90_2 > 35)
  {
    acc_2 = ((acc_2 + (margin_90_2 * 2)) + 5) & 127;
    aux_2 ^= margin_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_86_1)
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

  switch (tally_86_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_90_1 == margin_90_2);
  assert(tally_86_1 == tally_86_2);
}

int fn_R001928_2813_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int margin_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_90 > 35)
  {
    acc = ((acc + (margin_90 * 2)) + 5) & 127;
    aux ^= margin_90 & 15;
  }
  else
  {
    acc = ((acc - margin_90) + 11) & 127;
    aux += 3;
  }
  int tally_86 = (aux + st.buffer[1]) & 3;
  switch (tally_86)
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

void fn_R001928_2813_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st_1 = {0};
  struct AudioFrame_R001928_2813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int weight_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_84_1 > 42)
  {
    acc_1 = ((acc_1 + (weight_84_1 * 2)) + 5) & 127;
    aux_1 ^= weight_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_84_2 > 42)
  {
    acc_2 = ((acc_2 + (weight_84_2 * 2)) + 5) & 127;
    aux_2 ^= weight_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_84_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_29_1 = local_arr_1[aux_1 % 3];
  int window_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_84_1 == weight_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_29_1 == window_29_2);
}

int fn_R001928_2813_21(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001928_2813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int weight_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_84 > 42)
  {
    acc = ((acc + (weight_84 * 2)) + 5) & 127;
    aux ^= weight_84 & 15;
  }
  else
  {
    acc = ((acc - weight_84) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int window_29 = local_arr[aux % 3];
  acc = (acc + (window_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001928_2813_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st_1 = {0};
  struct CipherContext_R001928_2813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int segment_26_1 = 0;
  int segment_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_26_1 = ((segment_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_26_2 = ((segment_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_26_1) & 127;
    acc_2 = (acc_2 + segment_26_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_64_1) & 63;
  aux_2 = (aux_2 + delta_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_26_1 == segment_26_2);
  assert(delta_64_1 == delta_64_2);
}

int fn_R001928_2813_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001928_2813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int segment_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_26 = ((segment_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_26) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001928_0_1;
  int sec_r001928_0_2;
  int sec_r001928_1_1;
  int sec_r001928_1_2;
  int sec_r001928_2_1;
  int sec_r001928_2_2;
  int sec_r001928_3_1;
  int sec_r001928_3_2;
  int sec_r001928_4_1;
  int sec_r001928_4_2;
  int sec_r001928_5_1;
  int sec_r001928_5_2;
  int sec_r001928_6_1;
  int sec_r001928_6_2;
  int sec_r001928_7_1;
  int sec_r001928_7_2;
  int sec_r001928_8_1;
  int sec_r001928_8_2;
  int sec_r001928_9_1;
  int sec_r001928_9_2;
  int sec_r001928_10_1;
  int sec_r001928_10_2;
  int sec_r001928_11_1;
  int sec_r001928_11_2;
  int sec_r001928_12_1;
  int sec_r001928_12_2;
  int sec_r001928_13_1;
  int sec_r001928_13_2;
  int sec_r001928_14_1;
  int sec_r001928_14_2;
  int sec_r001928_15_1;
  int sec_r001928_15_2;
  int sec_r001928_16_1;
  int sec_r001928_16_2;
  int sec_r001928_17_1;
  int sec_r001928_17_2;
  int sec_r001928_18_1;
  int sec_r001928_18_2;
  int sec_r001928_19_1;
  int sec_r001928_19_2;
  int sec_r001928_20_1;
  int sec_r001928_20_2;
  int sec_r001928_21_1;
  int sec_r001928_21_2;
  int sec_r001928_22_1;
  int sec_r001928_22_2;
  int sec_r001928_23_1;
  int sec_r001928_23_2;
  int pub_r001928_0_1;
  int pub_r001928_0_2;
  int pub_r001928_1_1;
  int pub_r001928_1_2;
  int pub_r001928_2_1;
  int pub_r001928_2_2;
  int pub_r001928_3_1;
  int pub_r001928_3_2;
  int pub_r001928_4_1;
  int pub_r001928_4_2;
  int pub_r001928_5_1;
  int pub_r001928_5_2;
  int pub_r001928_6_1;
  int pub_r001928_6_2;
  int pub_r001928_7_1;
  int pub_r001928_7_2;
  int pub_r001928_8_1;
  int pub_r001928_8_2;
  int pub_r001928_9_1;
  int pub_r001928_9_2;
  int pub_r001928_10_1;
  int pub_r001928_10_2;
  int pub_r001928_11_1;
  int pub_r001928_11_2;
  int pub_r001928_12_1;
  int pub_r001928_12_2;
  int pub_r001928_13_1;
  int pub_r001928_13_2;
  int pub_r001928_14_1;
  int pub_r001928_14_2;
  int pub_r001928_15_1;
  int pub_r001928_15_2;
  int pub_r001928_16_1;
  int pub_r001928_16_2;
  int pub_r001928_17_1;
  int pub_r001928_17_2;
  int pub_r001928_18_1;
  int pub_r001928_18_2;
  int pub_r001928_19_1;
  int pub_r001928_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001928_0_1 >= (-100)) && (pub_r001928_0_1 <= 100));
  __CPROVER_assume((pub_r001928_0_2 >= (-100)) && (pub_r001928_0_2 <= 100));
  __CPROVER_assume((pub_r001928_1_1 >= (-100)) && (pub_r001928_1_1 <= 100));
  __CPROVER_assume((pub_r001928_1_2 >= (-100)) && (pub_r001928_1_2 <= 100));
  __CPROVER_assume((pub_r001928_2_1 >= (-100)) && (pub_r001928_2_1 <= 100));
  __CPROVER_assume((pub_r001928_2_2 >= (-100)) && (pub_r001928_2_2 <= 100));
  __CPROVER_assume((pub_r001928_3_1 >= (-100)) && (pub_r001928_3_1 <= 100));
  __CPROVER_assume((pub_r001928_3_2 >= (-100)) && (pub_r001928_3_2 <= 100));
  __CPROVER_assume((pub_r001928_4_1 >= (-100)) && (pub_r001928_4_1 <= 100));
  __CPROVER_assume((pub_r001928_4_2 >= (-100)) && (pub_r001928_4_2 <= 100));
  __CPROVER_assume((pub_r001928_5_1 >= (-100)) && (pub_r001928_5_1 <= 100));
  __CPROVER_assume((pub_r001928_5_2 >= (-100)) && (pub_r001928_5_2 <= 100));
  __CPROVER_assume((pub_r001928_6_1 >= (-100)) && (pub_r001928_6_1 <= 100));
  __CPROVER_assume((pub_r001928_6_2 >= (-100)) && (pub_r001928_6_2 <= 100));
  __CPROVER_assume((pub_r001928_7_1 >= (-100)) && (pub_r001928_7_1 <= 100));
  __CPROVER_assume((pub_r001928_7_2 >= (-100)) && (pub_r001928_7_2 <= 100));
  __CPROVER_assume((pub_r001928_8_1 >= (-100)) && (pub_r001928_8_1 <= 100));
  __CPROVER_assume((pub_r001928_8_2 >= (-100)) && (pub_r001928_8_2 <= 100));
  __CPROVER_assume((pub_r001928_9_1 >= (-100)) && (pub_r001928_9_1 <= 100));
  __CPROVER_assume((pub_r001928_9_2 >= (-100)) && (pub_r001928_9_2 <= 100));
  __CPROVER_assume((pub_r001928_10_1 >= (-100)) && (pub_r001928_10_1 <= 100));
  __CPROVER_assume((pub_r001928_10_2 >= (-100)) && (pub_r001928_10_2 <= 100));
  __CPROVER_assume((pub_r001928_11_1 >= (-100)) && (pub_r001928_11_1 <= 100));
  __CPROVER_assume((pub_r001928_11_2 >= (-100)) && (pub_r001928_11_2 <= 100));
  __CPROVER_assume((pub_r001928_12_1 >= (-100)) && (pub_r001928_12_1 <= 100));
  __CPROVER_assume((pub_r001928_12_2 >= (-100)) && (pub_r001928_12_2 <= 100));
  __CPROVER_assume((pub_r001928_13_1 >= (-100)) && (pub_r001928_13_1 <= 100));
  __CPROVER_assume((pub_r001928_13_2 >= (-100)) && (pub_r001928_13_2 <= 100));
  __CPROVER_assume((pub_r001928_14_1 >= (-100)) && (pub_r001928_14_1 <= 100));
  __CPROVER_assume((pub_r001928_14_2 >= (-100)) && (pub_r001928_14_2 <= 100));
  __CPROVER_assume((pub_r001928_15_1 >= (-100)) && (pub_r001928_15_1 <= 100));
  __CPROVER_assume((pub_r001928_15_2 >= (-100)) && (pub_r001928_15_2 <= 100));
  __CPROVER_assume((pub_r001928_16_1 >= (-100)) && (pub_r001928_16_1 <= 100));
  __CPROVER_assume((pub_r001928_16_2 >= (-100)) && (pub_r001928_16_2 <= 100));
  __CPROVER_assume((pub_r001928_17_1 >= (-100)) && (pub_r001928_17_1 <= 100));
  __CPROVER_assume((pub_r001928_17_2 >= (-100)) && (pub_r001928_17_2 <= 100));
  __CPROVER_assume((pub_r001928_18_1 >= (-100)) && (pub_r001928_18_1 <= 100));
  __CPROVER_assume((pub_r001928_18_2 >= (-100)) && (pub_r001928_18_2 <= 100));
  __CPROVER_assume((pub_r001928_19_1 >= (-100)) && (pub_r001928_19_1 <= 100));
  __CPROVER_assume((pub_r001928_19_2 >= (-100)) && (pub_r001928_19_2 <= 100));
  __CPROVER_assume((sec_r001928_0_1 >= 0) && (sec_r001928_0_1 <= 255));
  __CPROVER_assume((sec_r001928_0_2 >= 0) && (sec_r001928_0_2 <= 255));
  __CPROVER_assume((sec_r001928_1_1 >= 0) && (sec_r001928_1_1 <= 255));
  __CPROVER_assume((sec_r001928_1_2 >= 0) && (sec_r001928_1_2 <= 255));
  __CPROVER_assume((sec_r001928_2_1 >= 0) && (sec_r001928_2_1 <= 255));
  __CPROVER_assume((sec_r001928_2_2 >= 0) && (sec_r001928_2_2 <= 255));
  __CPROVER_assume((sec_r001928_3_1 >= 0) && (sec_r001928_3_1 <= 255));
  __CPROVER_assume((sec_r001928_3_2 >= 0) && (sec_r001928_3_2 <= 255));
  __CPROVER_assume((sec_r001928_4_1 >= 0) && (sec_r001928_4_1 <= 255));
  __CPROVER_assume((sec_r001928_4_2 >= 0) && (sec_r001928_4_2 <= 255));
  __CPROVER_assume((sec_r001928_5_1 >= 0) && (sec_r001928_5_1 <= 255));
  __CPROVER_assume((sec_r001928_5_2 >= 0) && (sec_r001928_5_2 <= 255));
  __CPROVER_assume((sec_r001928_6_1 >= 0) && (sec_r001928_6_1 <= 255));
  __CPROVER_assume((sec_r001928_6_2 >= 0) && (sec_r001928_6_2 <= 255));
  __CPROVER_assume((sec_r001928_7_1 >= 0) && (sec_r001928_7_1 <= 255));
  __CPROVER_assume((sec_r001928_7_2 >= 0) && (sec_r001928_7_2 <= 255));
  __CPROVER_assume((sec_r001928_8_1 >= 0) && (sec_r001928_8_1 <= 255));
  __CPROVER_assume((sec_r001928_8_2 >= 0) && (sec_r001928_8_2 <= 255));
  __CPROVER_assume((sec_r001928_9_1 >= 0) && (sec_r001928_9_1 <= 255));
  __CPROVER_assume((sec_r001928_9_2 >= 0) && (sec_r001928_9_2 <= 255));
  __CPROVER_assume((sec_r001928_10_1 >= 0) && (sec_r001928_10_1 <= 255));
  __CPROVER_assume((sec_r001928_10_2 >= 0) && (sec_r001928_10_2 <= 255));
  __CPROVER_assume((sec_r001928_11_1 >= 0) && (sec_r001928_11_1 <= 255));
  __CPROVER_assume((sec_r001928_11_2 >= 0) && (sec_r001928_11_2 <= 255));
  __CPROVER_assume((sec_r001928_12_1 >= 0) && (sec_r001928_12_1 <= 255));
  __CPROVER_assume((sec_r001928_12_2 >= 0) && (sec_r001928_12_2 <= 255));
  __CPROVER_assume((sec_r001928_13_1 >= 0) && (sec_r001928_13_1 <= 255));
  __CPROVER_assume((sec_r001928_13_2 >= 0) && (sec_r001928_13_2 <= 255));
  __CPROVER_assume((sec_r001928_14_1 >= 0) && (sec_r001928_14_1 <= 255));
  __CPROVER_assume((sec_r001928_14_2 >= 0) && (sec_r001928_14_2 <= 255));
  __CPROVER_assume((sec_r001928_15_1 >= 0) && (sec_r001928_15_1 <= 255));
  __CPROVER_assume((sec_r001928_15_2 >= 0) && (sec_r001928_15_2 <= 255));
  __CPROVER_assume((sec_r001928_16_1 >= 0) && (sec_r001928_16_1 <= 255));
  __CPROVER_assume((sec_r001928_16_2 >= 0) && (sec_r001928_16_2 <= 255));
  __CPROVER_assume((sec_r001928_17_1 >= 0) && (sec_r001928_17_1 <= 255));
  __CPROVER_assume((sec_r001928_17_2 >= 0) && (sec_r001928_17_2 <= 255));
  __CPROVER_assume((sec_r001928_18_1 >= 0) && (sec_r001928_18_1 <= 255));
  __CPROVER_assume((sec_r001928_18_2 >= 0) && (sec_r001928_18_2 <= 255));
  __CPROVER_assume((sec_r001928_19_1 >= 0) && (sec_r001928_19_1 <= 255));
  __CPROVER_assume((sec_r001928_19_2 >= 0) && (sec_r001928_19_2 <= 255));
  __CPROVER_assume((sec_r001928_20_1 >= 0) && (sec_r001928_20_1 <= 255));
  __CPROVER_assume((sec_r001928_20_2 >= 0) && (sec_r001928_20_2 <= 255));
  __CPROVER_assume((sec_r001928_21_1 >= 0) && (sec_r001928_21_1 <= 255));
  __CPROVER_assume((sec_r001928_21_2 >= 0) && (sec_r001928_21_2 <= 255));
  __CPROVER_assume((sec_r001928_22_1 >= 0) && (sec_r001928_22_1 <= 255));
  __CPROVER_assume((sec_r001928_22_2 >= 0) && (sec_r001928_22_2 <= 255));
  __CPROVER_assume((sec_r001928_23_1 >= 0) && (sec_r001928_23_1 <= 255));
  __CPROVER_assume((sec_r001928_23_2 >= 0) && (sec_r001928_23_2 <= 255));
  struct AudioFrame_R001928_2813_0 st_var_0_1 = {0};
  struct AudioFrame_R001928_2813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001928_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001928_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001928_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001928_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001928_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001928_0_2 + 7) & 15;
  struct CipherContext_R001928_2813_1 st_var_1_1 = {0};
  struct CipherContext_R001928_2813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001928_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001928_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001928_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001928_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001928_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001928_0_2 + 9) & 15;
  union ColorPixel_R001928_2813_0 u_var_1;
  union ColorPixel_R001928_2813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001928_2813_0(sec_r001928_0_1, sec_r001928_1_1, pub_r001928_2_1, pub_r001928_3_1, pub_r001928_4_1);
  int helper_flow_0_2 = fn_R001928_2813_0(sec_r001928_0_2, sec_r001928_1_2, pub_r001928_2_2, pub_r001928_3_2, pub_r001928_4_2);
  fn_R001928_2813_0_2(sec_r001928_0_1, sec_r001928_1_1, pub_r001928_2_1, pub_r001928_3_1, pub_r001928_4_1, sec_r001928_0_2, sec_r001928_1_2, pub_r001928_2_2, pub_r001928_3_2, pub_r001928_4_2);
  int helper_flow_1_1 = fn_R001928_2813_1(sec_r001928_1_1, sec_r001928_2_1);
  int helper_flow_1_2 = fn_R001928_2813_1(sec_r001928_1_2, sec_r001928_2_2);
  fn_R001928_2813_1_2(sec_r001928_1_1, sec_r001928_2_1, sec_r001928_1_2, sec_r001928_2_2);
  int helper_flow_2_1 = fn_R001928_2813_2(sec_r001928_2_1, pub_r001928_3_1);
  int helper_flow_2_2 = fn_R001928_2813_2(sec_r001928_2_2, pub_r001928_3_2);
  fn_R001928_2813_2_2(sec_r001928_2_1, pub_r001928_3_1, sec_r001928_2_2, pub_r001928_3_2);
  int helper_flow_3_1 = fn_R001928_2813_3(sec_r001928_3_1, pub_r001928_4_1);
  int helper_flow_3_2 = fn_R001928_2813_3(sec_r001928_3_2, pub_r001928_4_2);
  fn_R001928_2813_3_2(sec_r001928_3_1, pub_r001928_4_1, sec_r001928_3_2, pub_r001928_4_2);
  int helper_flow_4_1 = fn_R001928_2813_4(sec_r001928_4_1, pub_r001928_5_1, pub_r001928_6_1, pub_r001928_7_1, pub_r001928_8_1);
  int helper_flow_4_2 = fn_R001928_2813_4(sec_r001928_4_2, pub_r001928_5_2, pub_r001928_6_2, pub_r001928_7_2, pub_r001928_8_2);
  fn_R001928_2813_4_2(sec_r001928_4_1, pub_r001928_5_1, pub_r001928_6_1, pub_r001928_7_1, pub_r001928_8_1, sec_r001928_4_2, pub_r001928_5_2, pub_r001928_6_2, pub_r001928_7_2, pub_r001928_8_2);
  int helper_flow_5_1 = fn_R001928_2813_5(sec_r001928_5_1, pub_r001928_6_1, pub_r001928_7_1);
  int helper_flow_5_2 = fn_R001928_2813_5(sec_r001928_5_2, pub_r001928_6_2, pub_r001928_7_2);
  fn_R001928_2813_5_2(sec_r001928_5_1, pub_r001928_6_1, pub_r001928_7_1, sec_r001928_5_2, pub_r001928_6_2, pub_r001928_7_2);
  int helper_flow_6_1 = fn_R001928_2813_6(sec_r001928_6_1, pub_r001928_7_1);
  int helper_flow_6_2 = fn_R001928_2813_6(sec_r001928_6_2, pub_r001928_7_2);
  fn_R001928_2813_6_2(sec_r001928_6_1, pub_r001928_7_1, sec_r001928_6_2, pub_r001928_7_2);
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (it_1 * 3)) + (sec_r001928_23_1 & 15)) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (it_2 * 3)) + (sec_r001928_23_2 & 15)) & 63;
    if ((sec_r001928_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_0_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_0_1) + 7) & 255;
    }
    if ((sec_r001928_23_2 & 1) != 0)
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
    stage_v_1_1 = ((stage_v_1_1 + (it_1 * 3)) + (sec_r001928_18_1 & 15)) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (it_2 * 3)) + (sec_r001928_18_2 & 15)) & 63;
    if ((sec_r001928_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_1_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_1_1) + 7) & 255;
    }
    if ((sec_r001928_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_1_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_1_2) + 7) & 255;
    }
  }

  int stage_v_2_1 = ((pub_r001928_6_1 * 2) + 43) & 63;
  int stage_v_2_2 = ((pub_r001928_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_3_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_3_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_3_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_3_2) + 7) & 255;
    }
  }

  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_4_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_4_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_4_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_4_2) + 7) & 255;
    }
  }

  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_5_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_5_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_5_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_5_2) + 7) & 255;
    }
  }

  int stage_v_6_1 = ((pub_r001928_5_1 * 2) + 50) & 63;
  int stage_v_6_2 = ((pub_r001928_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (it_1 * 3)) + (sec_r001928_22_1 & 15)) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (it_2 * 3)) + (sec_r001928_22_2 & 15)) & 63;
    if ((sec_r001928_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_7_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_7_1) + 7) & 255;
    }
    if ((sec_r001928_22_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_7_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_7_2) + 7) & 255;
    }
  }

  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (it_1 * 3)) + (stage_v_0_1 & 15)) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (it_2 * 3)) + (stage_v_0_2 & 15)) & 63;
    if ((stage_v_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_8_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_8_1) + 7) & 255;
    }
    if ((stage_v_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_8_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_8_2) + 7) & 255;
    }
  }

  int stage_v_9_1 = ((pub_r001928_18_1 * 2) + 39) & 63;
  int stage_v_9_2 = ((pub_r001928_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (it_1 * 3)) + (stage_v_7_1 & 15)) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (it_2 * 3)) + (stage_v_7_2 & 15)) & 63;
    if ((stage_v_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_10_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_10_1) + 7) & 255;
    }
    if ((stage_v_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_10_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_10_2) + 7) & 255;
    }
  }

  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (it_1 * 3)) + (sec_r001928_10_1 & 15)) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (it_2 * 3)) + (sec_r001928_10_2 & 15)) & 63;
    if ((sec_r001928_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_11_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_11_1) + 7) & 255;
    }
    if ((sec_r001928_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_11_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_11_2) + 7) & 255;
    }
  }

  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (it_1 * 3)) + (sec_r001928_19_1 & 15)) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (it_2 * 3)) + (sec_r001928_19_2 & 15)) & 63;
    if ((sec_r001928_19_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_12_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_12_1) + 7) & 255;
    }
    if ((sec_r001928_19_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_12_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_12_2) + 7) & 255;
    }
  }

  int stage_v_13_1 = ((pub_r001928_3_1 * 2) + 42) & 63;
  int stage_v_13_2 = ((pub_r001928_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001928_4_1 * 2) + 17) & 63;
  int stage_v_14_2 = ((pub_r001928_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (it_1 * 3)) + (sec_r001928_12_1 & 15)) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (it_2 * 3)) + (sec_r001928_12_2 & 15)) & 63;
    if ((sec_r001928_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_15_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_15_1) + 7) & 255;
    }
    if ((sec_r001928_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_15_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_15_2) + 7) & 255;
    }
  }

  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_16_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_16_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_16_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_16_2) + 7) & 255;
    }
  }

  int stage_v_17_1 = ((pub_r001928_6_1 * 2) + 19) & 63;
  int stage_v_17_2 = ((pub_r001928_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (it_1 * 3)) + (sec_r001928_14_1 & 15)) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (it_2 * 3)) + (sec_r001928_14_2 & 15)) & 63;
    if ((sec_r001928_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_18_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_18_1) + 7) & 255;
    }
    if ((sec_r001928_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_18_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_18_2) + 7) & 255;
    }
  }

  int stage_v_19_1 = ((pub_r001928_10_1 * 2) + 46) & 63;
  int stage_v_19_2 = ((pub_r001928_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_20_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_20_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
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
    stage_v_21_1 = ((stage_v_21_1 + (it_1 * 3)) + (sec_r001928_23_1 & 15)) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (it_2 * 3)) + (sec_r001928_23_2 & 15)) & 63;
    if ((sec_r001928_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_21_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_21_1) + 7) & 255;
    }
    if ((sec_r001928_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_21_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_21_2) + 7) & 255;
    }
  }

  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (it_1 * 3)) + (stage_v_3_1 & 15)) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (it_2 * 3)) + (stage_v_3_2 & 15)) & 63;
    if ((stage_v_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_22_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_22_1) + 7) & 255;
    }
    if ((stage_v_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_22_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_22_2) + 7) & 255;
    }
  }

  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (it_1 * 3)) + (sec_r001928_17_1 & 15)) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (it_2 * 3)) + (sec_r001928_17_2 & 15)) & 63;
    if ((sec_r001928_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_23_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_23_1) + 7) & 255;
    }
    if ((sec_r001928_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_23_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_23_2) + 7) & 255;
    }
  }

  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_24_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_24_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_24_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_24_2) + 7) & 255;
    }
  }

  int stage_v_25_1 = ((pub_r001928_4_1 * 2) + 19) & 63;
  int stage_v_25_2 = ((pub_r001928_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (it_1 * 3)) + (sec_r001928_9_1 & 15)) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (it_2 * 3)) + (sec_r001928_9_2 & 15)) & 63;
    if ((sec_r001928_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_26_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_26_1) + 7) & 255;
    }
    if ((sec_r001928_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_26_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_26_2) + 7) & 255;
    }
  }

  int stage_v_27_1 = ((pub_r001928_8_1 * 2) + 39) & 63;
  int stage_v_27_2 = ((pub_r001928_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001928_9_1 * 2) + 21) & 63;
  int stage_v_28_2 = ((pub_r001928_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (it_1 * 3)) + (stage_v_1_1 & 15)) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (it_2 * 3)) + (stage_v_1_2 & 15)) & 63;
    if ((stage_v_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_29_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_29_1) + 7) & 255;
    }
    if ((stage_v_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_29_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_29_2) + 7) & 255;
    }
  }

  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (it_1 * 3)) + (stage_v_11_1 & 15)) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (it_2 * 3)) + (stage_v_11_2 & 15)) & 63;
    if ((stage_v_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_30_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_30_1) + 7) & 255;
    }
    if ((stage_v_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_30_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_30_2) + 7) & 255;
    }
  }

  int stage_v_31_1 = ((pub_r001928_19_1 * 2) + 24) & 63;
  int stage_v_31_2 = ((pub_r001928_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (it_1 * 3)) + (helper_flow_3_1 & 15)) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (it_2 * 3)) + (helper_flow_3_2 & 15)) & 63;
    if ((helper_flow_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_32_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_32_1) + 7) & 255;
    }
    if ((helper_flow_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_32_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_32_2) + 7) & 255;
    }
  }

  int stage_v_33_1 = ((pub_r001928_6_1 * 2) + 15) & 63;
  int stage_v_33_2 = ((pub_r001928_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001928_19_1 * 2) + 6) & 63;
  int stage_v_34_2 = ((pub_r001928_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (it_1 * 3)) + (stage_v_29_1 & 15)) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (it_2 * 3)) + (stage_v_29_2 & 15)) & 63;
    if ((stage_v_29_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_35_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_35_1) + 7) & 255;
    }
    if ((stage_v_29_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_35_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_35_2) + 7) & 255;
    }
  }

  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (it_1 * 3)) + (stage_v_5_1 & 15)) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (it_2 * 3)) + (stage_v_5_2 & 15)) & 63;
    if ((stage_v_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_36_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_36_1) + 7) & 255;
    }
    if ((stage_v_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_36_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_36_2) + 7) & 255;
    }
  }

  int stage_v_37_1 = ((pub_r001928_3_1 * 2) + 29) & 63;
  int stage_v_37_2 = ((pub_r001928_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (it_1 * 3)) + (stage_v_12_1 & 15)) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (it_2 * 3)) + (stage_v_12_2 & 15)) & 63;
    if ((stage_v_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_38_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_38_1) + 7) & 255;
    }
    if ((stage_v_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_38_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_38_2) + 7) & 255;
    }
  }

  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (it_1 * 3)) + (stage_v_7_1 & 15)) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (it_2 * 3)) + (stage_v_7_2 & 15)) & 63;
    if ((stage_v_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_39_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_39_1) + 7) & 255;
    }
    if ((stage_v_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_39_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_39_2) + 7) & 255;
    }
  }

  int stage_v_40_1 = ((pub_r001928_12_1 * 2) + 48) & 63;
  int stage_v_40_2 = ((pub_r001928_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001928_5_1 * 2) + 49) & 63;
  int stage_v_41_2 = ((pub_r001928_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_42_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_42_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
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
    stage_v_43_1 = ((stage_v_43_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_43_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_43_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
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
    stage_v_44_1 = ((stage_v_44_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_44_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_44_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_44_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_44_2) + 7) & 255;
    }
  }

  int stage_v_45_1 = ((pub_r001928_1_1 * 2) + 8) & 63;
  int stage_v_45_2 = ((pub_r001928_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_46_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_46_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_46_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_46_2) + 7) & 255;
    }
  }

  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (it_1 * 3)) + (stage_v_29_1 & 15)) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (it_2 * 3)) + (stage_v_29_2 & 15)) & 63;
    if ((stage_v_29_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_47_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_47_1) + 7) & 255;
    }
    if ((stage_v_29_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_47_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_47_2) + 7) & 255;
    }
  }

  int stage_v_48_1 = ((pub_r001928_11_1 * 2) + 31) & 63;
  int stage_v_48_2 = ((pub_r001928_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_49_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_49_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_49_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_49_2) + 7) & 255;
    }
  }

  int stage_v_50_1 = ((pub_r001928_17_1 * 2) + 13) & 63;
  int stage_v_50_2 = ((pub_r001928_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001928_12_1 * 2) + 15) & 63;
  int stage_v_51_2 = ((pub_r001928_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (it_1 * 3)) + (stage_v_49_1 & 15)) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (it_2 * 3)) + (stage_v_49_2 & 15)) & 63;
    if ((stage_v_49_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_52_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_52_1) + 7) & 255;
    }
    if ((stage_v_49_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_52_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_52_2) + 7) & 255;
    }
  }

  int stage_v_53_1 = ((pub_r001928_5_1 * 2) + 20) & 63;
  int stage_v_53_2 = ((pub_r001928_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001928_7_1 * 2) + 10) & 63;
  int stage_v_54_2 = ((pub_r001928_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001928_19_1 * 2) + 9) & 63;
  int stage_v_55_2 = ((pub_r001928_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_56_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_56_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_56_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_56_2) + 7) & 255;
    }
  }

  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (it_1 * 3)) + (sec_r001928_4_1 & 15)) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (it_2 * 3)) + (sec_r001928_4_2 & 15)) & 63;
    if ((sec_r001928_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_57_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_57_1) + 7) & 255;
    }
    if ((sec_r001928_4_2 & 1) != 0)
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
    stage_v_58_1 = ((stage_v_58_1 + (it_1 * 3)) + (stage_v_26_1 & 15)) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (it_2 * 3)) + (stage_v_26_2 & 15)) & 63;
    if ((stage_v_26_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_58_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_58_1) + 7) & 255;
    }
    if ((stage_v_26_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_58_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_58_2) + 7) & 255;
    }
  }

  int stage_v_59_1 = ((pub_r001928_6_1 * 2) + 23) & 63;
  int stage_v_59_2 = ((pub_r001928_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001928_0_1 * 2) + 15) & 63;
  int stage_v_60_2 = ((pub_r001928_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (it_1 * 3)) + (stage_v_35_1 & 15)) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (it_2 * 3)) + (stage_v_35_2 & 15)) & 63;
    if ((stage_v_35_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_61_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_61_1) + 7) & 255;
    }
    if ((stage_v_35_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_61_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_61_2) + 7) & 255;
    }
  }

  int stage_v_62_1 = ((pub_r001928_17_1 * 2) + 38) & 63;
  int stage_v_62_2 = ((pub_r001928_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (it_1 * 3)) + (sec_r001928_6_1 & 15)) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (it_2 * 3)) + (sec_r001928_6_2 & 15)) & 63;
    if ((sec_r001928_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_63_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_63_1) + 7) & 255;
    }
    if ((sec_r001928_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_63_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_63_2) + 7) & 255;
    }
  }

  int stage_v_64_1 = ((pub_r001928_12_1 * 2) + 42) & 63;
  int stage_v_64_2 = ((pub_r001928_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (it_1 * 3)) + (sec_r001928_21_1 & 15)) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (it_2 * 3)) + (sec_r001928_21_2 & 15)) & 63;
    if ((sec_r001928_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_65_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_65_1) + 7) & 255;
    }
    if ((sec_r001928_21_2 & 1) != 0)
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
    stage_v_66_1 = ((stage_v_66_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_66_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_66_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_66_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_66_2) + 7) & 255;
    }
  }

  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (it_1 * 3)) + (sec_r001928_12_1 & 15)) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (it_2 * 3)) + (sec_r001928_12_2 & 15)) & 63;
    if ((sec_r001928_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_67_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_67_1) + 7) & 255;
    }
    if ((sec_r001928_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_67_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_67_2) + 7) & 255;
    }
  }

  int stage_v_68_1 = ((pub_r001928_16_1 * 2) + 39) & 63;
  int stage_v_68_2 = ((pub_r001928_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001928_12_1 * 2) + 7) & 63;
  int stage_v_69_2 = ((pub_r001928_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001928_8_1 * 2) + 41) & 63;
  int stage_v_70_2 = ((pub_r001928_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_71_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_71_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_71_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_71_2) + 7) & 255;
    }
  }

  int stage_v_72_1 = ((pub_r001928_19_1 * 2) + 42) & 63;
  int stage_v_72_2 = ((pub_r001928_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001928_4_1 * 2) + 41) & 63;
  int stage_v_73_2 = ((pub_r001928_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (it_1 * 3)) + (stage_v_22_1 & 15)) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (it_2 * 3)) + (stage_v_22_2 & 15)) & 63;
    if ((stage_v_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_74_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_74_1) + 7) & 255;
    }
    if ((stage_v_22_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_74_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_74_2) + 7) & 255;
    }
  }

  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (it_1 * 3)) + (stage_v_0_1 & 15)) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (it_2 * 3)) + (stage_v_0_2 & 15)) & 63;
    if ((stage_v_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_75_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_75_1) + 7) & 255;
    }
    if ((stage_v_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_75_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_75_2) + 7) & 255;
    }
  }

  int stage_v_76_1 = ((pub_r001928_17_1 * 2) + 17) & 63;
  int stage_v_76_2 = ((pub_r001928_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001928_16_1 * 2) + 9) & 63;
  int stage_v_77_2 = ((pub_r001928_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (it_1 * 3)) + (stage_v_44_1 & 15)) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (it_2 * 3)) + (stage_v_44_2 & 15)) & 63;
    if ((stage_v_44_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_78_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_78_1) + 7) & 255;
    }
    if ((stage_v_44_2 & 1) != 0)
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
    stage_v_79_1 = ((stage_v_79_1 + (it_1 * 3)) + (sec_r001928_15_1 & 15)) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (it_2 * 3)) + (sec_r001928_15_2 & 15)) & 63;
    if ((sec_r001928_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_79_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_79_1) + 7) & 255;
    }
    if ((sec_r001928_15_2 & 1) != 0)
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
    stage_v_80_1 = ((stage_v_80_1 + (it_1 * 3)) + (sec_r001928_22_1 & 15)) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (it_2 * 3)) + (sec_r001928_22_2 & 15)) & 63;
    if ((sec_r001928_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_80_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_80_1) + 7) & 255;
    }
    if ((sec_r001928_22_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_80_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_80_2) + 7) & 255;
    }
  }

  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (it_1 * 3)) + (stage_v_10_1 & 15)) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (it_2 * 3)) + (stage_v_10_2 & 15)) & 63;
    if ((stage_v_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_81_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_81_1) + 7) & 255;
    }
    if ((stage_v_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_81_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_81_2) + 7) & 255;
    }
  }

  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (it_1 * 3)) + (sec_r001928_11_1 & 15)) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (it_2 * 3)) + (sec_r001928_11_2 & 15)) & 63;
    if ((sec_r001928_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_82_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_82_1) + 7) & 255;
    }
    if ((sec_r001928_11_2 & 1) != 0)
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
    stage_v_83_1 = ((stage_v_83_1 + (it_1 * 3)) + (stage_v_39_1 & 15)) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (it_2 * 3)) + (stage_v_39_2 & 15)) & 63;
    if ((stage_v_39_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_83_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_83_1) + 7) & 255;
    }
    if ((stage_v_39_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_83_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_83_2) + 7) & 255;
    }
  }

  int stage_v_84_1 = ((pub_r001928_18_1 * 2) + 25) & 63;
  int stage_v_84_2 = ((pub_r001928_18_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001928_9_1 * 2) + 19) & 63;
  int stage_v_85_2 = ((pub_r001928_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_86_1 = ((stage_v_86_1 + (it_1 * 3)) + (stage_v_82_1 & 15)) & 63;
    stage_v_86_2 = ((stage_v_86_2 + (it_2 * 3)) + (stage_v_82_2 & 15)) & 63;
    if ((stage_v_82_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_86_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_86_1) + 7) & 255;
    }
    if ((stage_v_82_2 & 1) != 0)
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
    stage_v_87_1 = ((stage_v_87_1 + (it_1 * 3)) + (stage_v_61_1 & 15)) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (it_2 * 3)) + (stage_v_61_2 & 15)) & 63;
    if ((stage_v_61_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_87_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_87_1) + 7) & 255;
    }
    if ((stage_v_61_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_87_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_87_2) + 7) & 255;
    }
  }

  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (it_1 * 3)) + (stage_v_24_1 & 15)) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (it_2 * 3)) + (stage_v_24_2 & 15)) & 63;
    if ((stage_v_24_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_88_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_88_1) + 7) & 255;
    }
    if ((stage_v_24_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_88_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_88_2) + 7) & 255;
    }
  }

  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_89_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_89_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_89_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_89_2) + 7) & 255;
    }
  }

  int stage_v_90_1 = ((pub_r001928_6_1 * 2) + 37) & 63;
  int stage_v_90_2 = ((pub_r001928_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001928_9_1 * 2) + 50) & 63;
  int stage_v_91_2 = ((pub_r001928_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (it_1 * 3)) + (sec_r001928_15_1 & 15)) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (it_2 * 3)) + (sec_r001928_15_2 & 15)) & 63;
    if ((sec_r001928_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_92_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_92_1) + 7) & 255;
    }
    if ((sec_r001928_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_92_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_92_2) + 7) & 255;
    }
  }

  int stage_v_93_1 = ((pub_r001928_8_1 * 2) + 10) & 63;
  int stage_v_93_2 = ((pub_r001928_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001928_12_1 * 2) + 9) & 63;
  int stage_v_94_2 = ((pub_r001928_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (it_1 * 3)) + (stage_v_87_1 & 15)) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (it_2 * 3)) + (stage_v_87_2 & 15)) & 63;
    if ((stage_v_87_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_95_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_95_1) + 7) & 255;
    }
    if ((stage_v_87_2 & 1) != 0)
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
    stage_v_96_1 = ((stage_v_96_1 + (it_1 * 3)) + (stage_v_86_1 & 15)) & 63;
    stage_v_96_2 = ((stage_v_96_2 + (it_2 * 3)) + (stage_v_86_2 & 15)) & 63;
    if ((stage_v_86_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_96_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_96_1) + 7) & 255;
    }
    if ((stage_v_86_2 & 1) != 0)
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
    stage_v_97_1 = ((stage_v_97_1 + (it_1 * 3)) + (stage_v_39_1 & 15)) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (it_2 * 3)) + (stage_v_39_2 & 15)) & 63;
    if ((stage_v_39_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_97_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_97_1) + 7) & 255;
    }
    if ((stage_v_39_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_97_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_97_2) + 7) & 255;
    }
  }

  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (it_1 * 3)) + (sec_r001928_16_1 & 15)) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (it_2 * 3)) + (sec_r001928_16_2 & 15)) & 63;
    if ((sec_r001928_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_98_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_98_1) + 7) & 255;
    }
    if ((sec_r001928_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_98_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_98_2) + 7) & 255;
    }
  }

  int stage_v_99_1 = ((pub_r001928_11_1 * 2) + 21) & 63;
  int stage_v_99_2 = ((pub_r001928_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_100_1 = ((stage_v_100_1 + (it_1 * 3)) + (stage_v_3_1 & 15)) & 63;
    stage_v_100_2 = ((stage_v_100_2 + (it_2 * 3)) + (stage_v_3_2 & 15)) & 63;
    if ((stage_v_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_100_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_100_1) + 7) & 255;
    }
    if ((stage_v_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_100_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_100_2) + 7) & 255;
    }
  }

  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_101_1 = ((stage_v_101_1 + (it_1 * 3)) + (sec_r001928_2_1 & 15)) & 63;
    stage_v_101_2 = ((stage_v_101_2 + (it_2 * 3)) + (sec_r001928_2_2 & 15)) & 63;
    if ((sec_r001928_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_101_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_101_1) + 7) & 255;
    }
    if ((sec_r001928_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_101_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_101_2) + 7) & 255;
    }
  }

  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_102_1 = ((stage_v_102_1 + (it_1 * 3)) + (stage_v_24_1 & 15)) & 63;
    stage_v_102_2 = ((stage_v_102_2 + (it_2 * 3)) + (stage_v_24_2 & 15)) & 63;
    if ((stage_v_24_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_102_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_102_1) + 7) & 255;
    }
    if ((stage_v_24_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_102_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_102_2) + 7) & 255;
    }
  }

  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (it_1 * 3)) + (stage_v_29_1 & 15)) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (it_2 * 3)) + (stage_v_29_2 & 15)) & 63;
    if ((stage_v_29_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_103_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_103_1) + 7) & 255;
    }
    if ((stage_v_29_2 & 1) != 0)
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
    stage_v_104_1 = ((stage_v_104_1 + (it_1 * 3)) + (sec_r001928_2_1 & 15)) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (it_2 * 3)) + (sec_r001928_2_2 & 15)) & 63;
    if ((sec_r001928_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_104_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_104_1) + 7) & 255;
    }
    if ((sec_r001928_2_2 & 1) != 0)
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
    stage_v_105_1 = ((stage_v_105_1 + (it_1 * 3)) + (stage_v_44_1 & 15)) & 63;
    stage_v_105_2 = ((stage_v_105_2 + (it_2 * 3)) + (stage_v_44_2 & 15)) & 63;
    if ((stage_v_44_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_105_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_105_1) + 7) & 255;
    }
    if ((stage_v_44_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_105_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_105_2) + 7) & 255;
    }
  }

  int stage_v_106_1 = ((pub_r001928_11_1 * 2) + 16) & 63;
  int stage_v_106_2 = ((pub_r001928_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (it_1 * 3)) + (stage_v_98_1 & 15)) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (it_2 * 3)) + (stage_v_98_2 & 15)) & 63;
    if ((stage_v_98_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_107_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_107_1) + 7) & 255;
    }
    if ((stage_v_98_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_107_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_107_2) + 7) & 255;
    }
  }

  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_108_1 = ((stage_v_108_1 + (it_1 * 3)) + (stage_v_61_1 & 15)) & 63;
    stage_v_108_2 = ((stage_v_108_2 + (it_2 * 3)) + (stage_v_61_2 & 15)) & 63;
    if ((stage_v_61_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_108_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_108_1) + 7) & 255;
    }
    if ((stage_v_61_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_108_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_108_2) + 7) & 255;
    }
  }

  int stage_v_109_1 = ((pub_r001928_13_1 * 2) + 48) & 63;
  int stage_v_109_2 = ((pub_r001928_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_110_1 = ((stage_v_110_1 + (it_1 * 3)) + (stage_v_46_1 & 15)) & 63;
    stage_v_110_2 = ((stage_v_110_2 + (it_2 * 3)) + (stage_v_46_2 & 15)) & 63;
    if ((stage_v_46_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_110_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_110_1) + 7) & 255;
    }
    if ((stage_v_46_2 & 1) != 0)
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
    stage_v_111_1 = ((stage_v_111_1 + (it_1 * 3)) + (sec_r001928_23_1 & 15)) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (it_2 * 3)) + (sec_r001928_23_2 & 15)) & 63;
    if ((sec_r001928_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_111_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_111_1) + 7) & 255;
    }
    if ((sec_r001928_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_111_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_111_2) + 7) & 255;
    }
  }

  int stage_v_112_1 = ((pub_r001928_14_1 * 2) + 22) & 63;
  int stage_v_112_2 = ((pub_r001928_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_113_1 = ((stage_v_113_1 + (it_1 * 3)) + (stage_v_10_1 & 15)) & 63;
    stage_v_113_2 = ((stage_v_113_2 + (it_2 * 3)) + (stage_v_10_2 & 15)) & 63;
    if ((stage_v_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_113_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_113_1) + 7) & 255;
    }
    if ((stage_v_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_113_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_113_2) + 7) & 255;
    }
  }

  int stage_v_114_1 = ((pub_r001928_5_1 * 2) + 28) & 63;
  int stage_v_114_2 = ((pub_r001928_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (it_1 * 3)) + (stage_v_65_1 & 15)) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (it_2 * 3)) + (stage_v_65_2 & 15)) & 63;
    if ((stage_v_65_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_115_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_115_1) + 7) & 255;
    }
    if ((stage_v_65_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_115_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_115_2) + 7) & 255;
    }
  }

  int stage_v_116_1 = ((pub_r001928_6_1 * 2) + 24) & 63;
  int stage_v_116_2 = ((pub_r001928_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001928_18_1 * 2) + 48) & 63;
  int stage_v_117_2 = ((pub_r001928_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001928_0_1 * 2) + 5) & 63;
  int stage_v_118_2 = ((pub_r001928_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_119_1 = ((stage_v_119_1 + (it_1 * 3)) + (sec_r001928_1_1 & 15)) & 63;
    stage_v_119_2 = ((stage_v_119_2 + (it_2 * 3)) + (sec_r001928_1_2 & 15)) & 63;
    if ((sec_r001928_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_119_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_119_1) + 7) & 255;
    }
    if ((sec_r001928_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_119_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_119_2) + 7) & 255;
    }
  }

  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_120_1 = ((stage_v_120_1 + (it_1 * 3)) + (stage_v_83_1 & 15)) & 63;
    stage_v_120_2 = ((stage_v_120_2 + (it_2 * 3)) + (stage_v_83_2 & 15)) & 63;
    if ((stage_v_83_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_120_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_120_1) + 7) & 255;
    }
    if ((stage_v_83_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_120_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_120_2) + 7) & 255;
    }
  }

  int stage_v_121_1 = ((pub_r001928_1_1 * 2) + 29) & 63;
  int stage_v_121_2 = ((pub_r001928_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_122_1 = ((stage_v_122_1 + (it_1 * 3)) + (sec_r001928_10_1 & 15)) & 63;
    stage_v_122_2 = ((stage_v_122_2 + (it_2 * 3)) + (sec_r001928_10_2 & 15)) & 63;
    if ((sec_r001928_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_122_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_122_1) + 7) & 255;
    }
    if ((sec_r001928_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_122_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_122_2) + 7) & 255;
    }
  }

  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (it_1 * 3)) + (stage_v_42_1 & 15)) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (it_2 * 3)) + (stage_v_42_2 & 15)) & 63;
    if ((stage_v_42_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_123_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_123_1) + 7) & 255;
    }
    if ((stage_v_42_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_123_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_123_2) + 7) & 255;
    }
  }

  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_124_1 = ((stage_v_124_1 + (it_1 * 3)) + (sec_r001928_2_1 & 15)) & 63;
    stage_v_124_2 = ((stage_v_124_2 + (it_2 * 3)) + (sec_r001928_2_2 & 15)) & 63;
    if ((sec_r001928_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_124_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_124_1) + 7) & 255;
    }
    if ((sec_r001928_2_2 & 1) != 0)
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
    stage_v_125_1 = ((stage_v_125_1 + (it_1 * 3)) + (stage_v_101_1 & 15)) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (it_2 * 3)) + (stage_v_101_2 & 15)) & 63;
    if ((stage_v_101_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_125_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_125_1) + 7) & 255;
    }
    if ((stage_v_101_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_125_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_125_2) + 7) & 255;
    }
  }

  int stage_v_126_1 = ((pub_r001928_11_1 * 2) + 45) & 63;
  int stage_v_126_2 = ((pub_r001928_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (it_1 * 3)) + (stage_v_103_1 & 15)) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (it_2 * 3)) + (stage_v_103_2 & 15)) & 63;
    if ((stage_v_103_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_127_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_127_1) + 7) & 255;
    }
    if ((stage_v_103_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_127_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_127_2) + 7) & 255;
    }
  }

  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_128_1 = ((stage_v_128_1 + (it_1 * 3)) + (helper_flow_3_1 & 15)) & 63;
    stage_v_128_2 = ((stage_v_128_2 + (it_2 * 3)) + (helper_flow_3_2 & 15)) & 63;
    if ((helper_flow_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_128_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_128_1) + 7) & 255;
    }
    if ((helper_flow_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_128_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_128_2) + 7) & 255;
    }
  }

  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (it_1 * 3)) + (stage_v_3_1 & 15)) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (it_2 * 3)) + (stage_v_3_2 & 15)) & 63;
    if ((stage_v_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_129_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_129_1) + 7) & 255;
    }
    if ((stage_v_3_2 & 1) != 0)
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
    stage_v_130_1 = ((stage_v_130_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_130_2 = ((stage_v_130_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_130_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_130_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_130_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_130_2) + 7) & 255;
    }
  }

  int stage_v_131_1 = ((pub_r001928_5_1 * 2) + 11) & 63;
  int stage_v_131_2 = ((pub_r001928_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001928_19_1 * 2) + 41) & 63;
  int stage_v_132_2 = ((pub_r001928_19_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (it_1 * 3)) + (stage_v_129_1 & 15)) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (it_2 * 3)) + (stage_v_129_2 & 15)) & 63;
    if ((stage_v_129_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_133_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_133_1) + 7) & 255;
    }
    if ((stage_v_129_2 & 1) != 0)
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
    stage_v_134_1 = ((stage_v_134_1 + (it_1 * 3)) + (stage_v_120_1 & 15)) & 63;
    stage_v_134_2 = ((stage_v_134_2 + (it_2 * 3)) + (stage_v_120_2 & 15)) & 63;
    if ((stage_v_120_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_134_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_134_1) + 7) & 255;
    }
    if ((stage_v_120_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_134_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_134_2) + 7) & 255;
    }
  }

  int stage_v_135_1 = ((pub_r001928_4_1 * 2) + 44) & 63;
  int stage_v_135_2 = ((pub_r001928_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_136_1 = ((stage_v_136_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_136_2 = ((stage_v_136_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_136_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_136_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_136_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_136_2) + 7) & 255;
    }
  }

  int stage_v_137_1 = ((pub_r001928_6_1 * 2) + 29) & 63;
  int stage_v_137_2 = ((pub_r001928_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (it_1 * 3)) + (stage_v_102_1 & 15)) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (it_2 * 3)) + (stage_v_102_2 & 15)) & 63;
    if ((stage_v_102_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_138_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_138_1) + 7) & 255;
    }
    if ((stage_v_102_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_138_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_138_2) + 7) & 255;
    }
  }

  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_139_1 = ((stage_v_139_1 + (it_1 * 3)) + (stage_v_136_1 & 15)) & 63;
    stage_v_139_2 = ((stage_v_139_2 + (it_2 * 3)) + (stage_v_136_2 & 15)) & 63;
    if ((stage_v_136_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_139_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_139_1) + 7) & 255;
    }
    if ((stage_v_136_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_139_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_139_2) + 7) & 255;
    }
  }

  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (it_1 * 3)) + (stage_v_78_1 & 15)) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (it_2 * 3)) + (stage_v_78_2 & 15)) & 63;
    if ((stage_v_78_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_140_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_140_1) + 7) & 255;
    }
    if ((stage_v_78_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_140_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_140_2) + 7) & 255;
    }
  }

  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_141_1 = ((stage_v_141_1 + (it_1 * 3)) + (stage_v_128_1 & 15)) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (it_2 * 3)) + (stage_v_128_2 & 15)) & 63;
    if ((stage_v_128_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_141_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_141_1) + 7) & 255;
    }
    if ((stage_v_128_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_141_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_141_2) + 7) & 255;
    }
  }

  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_142_1 = ((stage_v_142_1 + (it_1 * 3)) + (stage_v_88_1 & 15)) & 63;
    stage_v_142_2 = ((stage_v_142_2 + (it_2 * 3)) + (stage_v_88_2 & 15)) & 63;
    if ((stage_v_88_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_142_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_142_1) + 7) & 255;
    }
    if ((stage_v_88_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_142_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_142_2) + 7) & 255;
    }
  }

  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (it_1 * 3)) + (stage_v_47_1 & 15)) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (it_2 * 3)) + (stage_v_47_2 & 15)) & 63;
    if ((stage_v_47_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_143_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_143_1) + 7) & 255;
    }
    if ((stage_v_47_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_143_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_143_2) + 7) & 255;
    }
  }

  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (it_1 * 3)) + (stage_v_24_1 & 15)) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (it_2 * 3)) + (stage_v_24_2 & 15)) & 63;
    if ((stage_v_24_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_144_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_144_1) + 7) & 255;
    }
    if ((stage_v_24_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_144_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_144_2) + 7) & 255;
    }
  }

  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (it_1 * 3)) + (sec_r001928_13_1 & 15)) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (it_2 * 3)) + (sec_r001928_13_2 & 15)) & 63;
    if ((sec_r001928_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_145_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_145_1) + 7) & 255;
    }
    if ((sec_r001928_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_145_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_145_2) + 7) & 255;
    }
  }

  int stage_v_146_1 = ((pub_r001928_4_1 * 2) + 50) & 63;
  int stage_v_146_2 = ((pub_r001928_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_147_1 = ((stage_v_147_1 + (it_1 * 3)) + (stage_v_136_1 & 15)) & 63;
    stage_v_147_2 = ((stage_v_147_2 + (it_2 * 3)) + (stage_v_136_2 & 15)) & 63;
    if ((stage_v_136_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_147_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_147_1) + 7) & 255;
    }
    if ((stage_v_136_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_147_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_147_2) + 7) & 255;
    }
  }

  int stage_v_148_1 = ((pub_r001928_2_1 * 2) + 49) & 63;
  int stage_v_148_2 = ((pub_r001928_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001928_4_1 * 2) + 5) & 63;
  int stage_v_149_2 = ((pub_r001928_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_150_1 = ((stage_v_150_1 + (it_1 * 3)) + (stage_v_49_1 & 15)) & 63;
    stage_v_150_2 = ((stage_v_150_2 + (it_2 * 3)) + (stage_v_49_2 & 15)) & 63;
    if ((stage_v_49_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_150_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_150_1) + 7) & 255;
    }
    if ((stage_v_49_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_150_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_150_2) + 7) & 255;
    }
  }

  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_151_1 = ((stage_v_151_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_151_2 = ((stage_v_151_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_151_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_151_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_151_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_151_2) + 7) & 255;
    }
  }

  int stage_v_152_1 = ((pub_r001928_11_1 * 2) + 39) & 63;
  int stage_v_152_2 = ((pub_r001928_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001928_9_1 * 2) + 30) & 63;
  int stage_v_153_2 = ((pub_r001928_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_154_1 = ((stage_v_154_1 + (it_1 * 3)) + (sec_r001928_10_1 & 15)) & 63;
    stage_v_154_2 = ((stage_v_154_2 + (it_2 * 3)) + (sec_r001928_10_2 & 15)) & 63;
    if ((sec_r001928_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_154_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_154_1) + 7) & 255;
    }
    if ((sec_r001928_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_154_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_154_2) + 7) & 255;
    }
  }

  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (it_1 * 3)) + (sec_r001928_18_1 & 15)) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (it_2 * 3)) + (sec_r001928_18_2 & 15)) & 63;
    if ((sec_r001928_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_155_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_155_1) + 7) & 255;
    }
    if ((sec_r001928_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_155_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_155_2) + 7) & 255;
    }
  }

  int stage_v_156_1 = ((pub_r001928_18_1 * 2) + 31) & 63;
  int stage_v_156_2 = ((pub_r001928_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001928_13_1 * 2) + 22) & 63;
  int stage_v_157_2 = ((pub_r001928_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_158_1 = ((stage_v_158_1 + (it_1 * 3)) + (stage_v_43_1 & 15)) & 63;
    stage_v_158_2 = ((stage_v_158_2 + (it_2 * 3)) + (stage_v_43_2 & 15)) & 63;
    if ((stage_v_43_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_158_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_158_1) + 7) & 255;
    }
    if ((stage_v_43_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_158_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_158_2) + 7) & 255;
    }
  }

  int stage_v_159_1 = ((pub_r001928_3_1 * 2) + 17) & 63;
  int stage_v_159_2 = ((pub_r001928_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (it_1 * 3)) + (stage_v_138_1 & 15)) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (it_2 * 3)) + (stage_v_138_2 & 15)) & 63;
    if ((stage_v_138_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_160_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_160_1) + 7) & 255;
    }
    if ((stage_v_138_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_160_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_160_2) + 7) & 255;
    }
  }

  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_161_1 = ((stage_v_161_1 + (it_1 * 3)) + (stage_v_49_1 & 15)) & 63;
    stage_v_161_2 = ((stage_v_161_2 + (it_2 * 3)) + (stage_v_49_2 & 15)) & 63;
    if ((stage_v_49_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_161_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_161_1) + 7) & 255;
    }
    if ((stage_v_49_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_161_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_161_2) + 7) & 255;
    }
  }

  int stage_v_162_1 = ((pub_r001928_17_1 * 2) + 45) & 63;
  int stage_v_162_2 = ((pub_r001928_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_163_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_163_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_163_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_163_2) + 7) & 255;
    }
  }

  int stage_v_164_1 = ((pub_r001928_12_1 * 2) + 20) & 63;
  int stage_v_164_2 = ((pub_r001928_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001928_18_1 * 2) + 23) & 63;
  int stage_v_165_2 = ((pub_r001928_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (it_1 * 3)) + (stage_v_134_1 & 15)) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (it_2 * 3)) + (stage_v_134_2 & 15)) & 63;
    if ((stage_v_134_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_166_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_166_1) + 7) & 255;
    }
    if ((stage_v_134_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_166_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_166_2) + 7) & 255;
    }
  }

  int stage_v_167_1 = ((pub_r001928_9_1 * 2) + 47) & 63;
  int stage_v_167_2 = ((pub_r001928_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_168_1 = ((stage_v_168_1 + (it_1 * 3)) + (sec_r001928_3_1 & 15)) & 63;
    stage_v_168_2 = ((stage_v_168_2 + (it_2 * 3)) + (sec_r001928_3_2 & 15)) & 63;
    if ((sec_r001928_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_168_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_168_1) + 7) & 255;
    }
    if ((sec_r001928_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_168_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_168_2) + 7) & 255;
    }
  }

  int stage_v_169_1 = ((pub_r001928_1_1 * 2) + 15) & 63;
  int stage_v_169_2 = ((pub_r001928_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001928_2_1 * 2) + 10) & 63;
  int stage_v_170_2 = ((pub_r001928_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001928_0_1 * 2) + 34) & 63;
  int stage_v_171_2 = ((pub_r001928_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_172_1 = ((stage_v_172_1 + (it_1 * 3)) + (stage_v_16_1 & 15)) & 63;
    stage_v_172_2 = ((stage_v_172_2 + (it_2 * 3)) + (stage_v_16_2 & 15)) & 63;
    if ((stage_v_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_172_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_172_1) + 7) & 255;
    }
    if ((stage_v_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_172_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_172_2) + 7) & 255;
    }
  }

  int stage_v_173_1 = ((pub_r001928_2_1 * 2) + 35) & 63;
  int stage_v_173_2 = ((pub_r001928_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001928_1_1 * 2) + 13) & 63;
  int stage_v_174_2 = ((pub_r001928_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_175_1 = ((stage_v_175_1 + (it_1 * 3)) + (stage_v_134_1 & 15)) & 63;
    stage_v_175_2 = ((stage_v_175_2 + (it_2 * 3)) + (stage_v_134_2 & 15)) & 63;
    if ((stage_v_134_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_175_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_175_1) + 7) & 255;
    }
    if ((stage_v_134_2 & 1) != 0)
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
    stage_v_176_1 = ((stage_v_176_1 + (it_1 * 3)) + (stage_v_102_1 & 15)) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (it_2 * 3)) + (stage_v_102_2 & 15)) & 63;
    if ((stage_v_102_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_176_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_176_1) + 7) & 255;
    }
    if ((stage_v_102_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_176_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_176_2) + 7) & 255;
    }
  }

  int stage_v_177_1 = ((pub_r001928_14_1 * 2) + 30) & 63;
  int stage_v_177_2 = ((pub_r001928_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001928_14_1 * 2) + 29) & 63;
  int stage_v_178_2 = ((pub_r001928_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = 0;
  int stage_v_179_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_179_1 = ((stage_v_179_1 + (it_1 * 3)) + (stage_v_115_1 & 15)) & 63;
    stage_v_179_2 = ((stage_v_179_2 + (it_2 * 3)) + (stage_v_115_2 & 15)) & 63;
    if ((stage_v_115_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_179_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_179_1) + 7) & 255;
    }
    if ((stage_v_115_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_179_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_179_2) + 7) & 255;
    }
  }

  int stage_v_180_1 = 0;
  int stage_v_180_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_180_1 = ((stage_v_180_1 + (it_1 * 3)) + (stage_v_125_1 & 15)) & 63;
    stage_v_180_2 = ((stage_v_180_2 + (it_2 * 3)) + (stage_v_125_2 & 15)) & 63;
    if ((stage_v_125_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_180_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_180_1) + 7) & 255;
    }
    if ((stage_v_125_2 & 1) != 0)
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
    stage_v_181_1 = ((stage_v_181_1 + (it_1 * 3)) + (stage_v_127_1 & 15)) & 63;
    stage_v_181_2 = ((stage_v_181_2 + (it_2 * 3)) + (stage_v_127_2 & 15)) & 63;
    if ((stage_v_127_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_181_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_181_1) + 7) & 255;
    }
    if ((stage_v_127_2 & 1) != 0)
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
    stage_v_182_1 = ((stage_v_182_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_182_2 = ((stage_v_182_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_182_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_182_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
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
    stage_v_183_1 = ((stage_v_183_1 + (it_1 * 3)) + (sec_r001928_13_1 & 15)) & 63;
    stage_v_183_2 = ((stage_v_183_2 + (it_2 * 3)) + (sec_r001928_13_2 & 15)) & 63;
    if ((sec_r001928_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_183_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_183_1) + 7) & 255;
    }
    if ((sec_r001928_13_2 & 1) != 0)
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
    stage_v_184_1 = ((stage_v_184_1 + (it_1 * 3)) + (stage_v_161_1 & 15)) & 63;
    stage_v_184_2 = ((stage_v_184_2 + (it_2 * 3)) + (stage_v_161_2 & 15)) & 63;
    if ((stage_v_161_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_184_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_184_1) + 7) & 255;
    }
    if ((stage_v_161_2 & 1) != 0)
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
    stage_v_185_1 = ((stage_v_185_1 + (it_1 * 3)) + (stage_v_101_1 & 15)) & 63;
    stage_v_185_2 = ((stage_v_185_2 + (it_2 * 3)) + (stage_v_101_2 & 15)) & 63;
    if ((stage_v_101_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_185_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_185_1) + 7) & 255;
    }
    if ((stage_v_101_2 & 1) != 0)
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
    stage_v_186_1 = ((stage_v_186_1 + (it_1 * 3)) + (stage_v_161_1 & 15)) & 63;
    stage_v_186_2 = ((stage_v_186_2 + (it_2 * 3)) + (stage_v_161_2 & 15)) & 63;
    if ((stage_v_161_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_186_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_186_1) + 7) & 255;
    }
    if ((stage_v_161_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_186_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_186_2) + 7) & 255;
    }
  }

  int stage_v_187_1 = ((pub_r001928_13_1 * 2) + 49) & 63;
  int stage_v_187_2 = ((pub_r001928_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = 0;
  int stage_v_188_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_188_1 = ((stage_v_188_1 + (it_1 * 3)) + (stage_v_96_1 & 15)) & 63;
    stage_v_188_2 = ((stage_v_188_2 + (it_2 * 3)) + (stage_v_96_2 & 15)) & 63;
    if ((stage_v_96_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_188_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_188_1) + 7) & 255;
    }
    if ((stage_v_96_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_188_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_188_2) + 7) & 255;
    }
  }

  int stage_v_189_1 = ((pub_r001928_15_1 * 2) + 44) & 63;
  int stage_v_189_2 = ((pub_r001928_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = 0;
  int stage_v_190_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_190_1 = ((stage_v_190_1 + (it_1 * 3)) + (stage_v_42_1 & 15)) & 63;
    stage_v_190_2 = ((stage_v_190_2 + (it_2 * 3)) + (stage_v_42_2 & 15)) & 63;
    if ((stage_v_42_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_190_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_190_1) + 7) & 255;
    }
    if ((stage_v_42_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_190_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_190_2) + 7) & 255;
    }
  }

  int stage_v_191_1 = ((pub_r001928_5_1 * 2) + 18) & 63;
  int stage_v_191_2 = ((pub_r001928_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001928_18_1 * 2) + 28) & 63;
  int stage_v_192_2 = ((pub_r001928_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = 0;
  int stage_v_193_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_193_1 = ((stage_v_193_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_193_2 = ((stage_v_193_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_193_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_193_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_193_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_193_2) + 7) & 255;
    }
  }

  int stage_v_194_1 = 0;
  int stage_v_194_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_194_1 = ((stage_v_194_1 + (it_1 * 3)) + (stage_v_5_1 & 15)) & 63;
    stage_v_194_2 = ((stage_v_194_2 + (it_2 * 3)) + (stage_v_5_2 & 15)) & 63;
    if ((stage_v_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_194_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_194_1) + 7) & 255;
    }
    if ((stage_v_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_194_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_194_2) + 7) & 255;
    }
  }

  int stage_v_195_1 = 0;
  int stage_v_195_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_195_1 = ((stage_v_195_1 + (it_1 * 3)) + (stage_v_133_1 & 15)) & 63;
    stage_v_195_2 = ((stage_v_195_2 + (it_2 * 3)) + (stage_v_133_2 & 15)) & 63;
    if ((stage_v_133_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_195_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_195_1) + 7) & 255;
    }
    if ((stage_v_133_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_195_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_195_2) + 7) & 255;
    }
  }

  int stage_v_196_1 = ((pub_r001928_7_1 * 2) + 13) & 63;
  int stage_v_196_2 = ((pub_r001928_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001928_1_1 * 2) + 5) & 63;
  int stage_v_197_2 = ((pub_r001928_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = 0;
  int stage_v_198_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_198_1 = ((stage_v_198_1 + (it_1 * 3)) + (stage_v_3_1 & 15)) & 63;
    stage_v_198_2 = ((stage_v_198_2 + (it_2 * 3)) + (stage_v_3_2 & 15)) & 63;
    if ((stage_v_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_198_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_198_1) + 7) & 255;
    }
    if ((stage_v_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_198_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_198_2) + 7) & 255;
    }
  }

  int stage_v_199_1 = 0;
  int stage_v_199_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_199_1 = ((stage_v_199_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_199_2 = ((stage_v_199_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_199_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_199_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_199_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_199_2) + 7) & 255;
    }
  }

  int stage_v_200_1 = ((pub_r001928_11_1 * 2) + 28) & 63;
  int stage_v_200_2 = ((pub_r001928_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001928_16_1 * 2) + 16) & 63;
  int stage_v_201_2 = ((pub_r001928_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = 0;
  int stage_v_202_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_202_1 = ((stage_v_202_1 + (it_1 * 3)) + (stage_v_61_1 & 15)) & 63;
    stage_v_202_2 = ((stage_v_202_2 + (it_2 * 3)) + (stage_v_61_2 & 15)) & 63;
    if ((stage_v_61_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_202_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_202_1) + 7) & 255;
    }
    if ((stage_v_61_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_202_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_202_2) + 7) & 255;
    }
  }

  int stage_v_203_1 = 0;
  int stage_v_203_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_203_1 = ((stage_v_203_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_203_2 = ((stage_v_203_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_203_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_203_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_203_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_203_2) + 7) & 255;
    }
  }

  int stage_v_204_1 = 0;
  int stage_v_204_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_204_1 = ((stage_v_204_1 + (it_1 * 3)) + (stage_v_7_1 & 15)) & 63;
    stage_v_204_2 = ((stage_v_204_2 + (it_2 * 3)) + (stage_v_7_2 & 15)) & 63;
    if ((stage_v_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_204_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_204_1) + 7) & 255;
    }
    if ((stage_v_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_204_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_204_2) + 7) & 255;
    }
  }

  int stage_v_205_1 = ((pub_r001928_3_1 * 2) + 11) & 63;
  int stage_v_205_2 = ((pub_r001928_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001928_9_1 * 2) + 27) & 63;
  int stage_v_206_2 = ((pub_r001928_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = 0;
  int stage_v_207_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_207_1 = ((stage_v_207_1 + (it_1 * 3)) + (stage_v_104_1 & 15)) & 63;
    stage_v_207_2 = ((stage_v_207_2 + (it_2 * 3)) + (stage_v_104_2 & 15)) & 63;
    if ((stage_v_104_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_207_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_207_1) + 7) & 255;
    }
    if ((stage_v_104_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_207_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_207_2) + 7) & 255;
    }
  }

  int stage_v_208_1 = 0;
  int stage_v_208_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_208_1 = ((stage_v_208_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_208_2 = ((stage_v_208_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_208_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_208_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_208_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_208_2) + 7) & 255;
    }
  }

  int stage_v_209_1 = ((pub_r001928_0_1 * 2) + 9) & 63;
  int stage_v_209_2 = ((pub_r001928_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = 0;
  int stage_v_210_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_210_1 = ((stage_v_210_1 + (it_1 * 3)) + (sec_r001928_10_1 & 15)) & 63;
    stage_v_210_2 = ((stage_v_210_2 + (it_2 * 3)) + (sec_r001928_10_2 & 15)) & 63;
    if ((sec_r001928_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_210_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_210_1) + 7) & 255;
    }
    if ((sec_r001928_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_210_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_210_2) + 7) & 255;
    }
  }

  int stage_v_211_1 = 0;
  int stage_v_211_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_211_1 = ((stage_v_211_1 + (it_1 * 3)) + (sec_r001928_9_1 & 15)) & 63;
    stage_v_211_2 = ((stage_v_211_2 + (it_2 * 3)) + (sec_r001928_9_2 & 15)) & 63;
    if ((sec_r001928_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_211_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_211_1) + 7) & 255;
    }
    if ((sec_r001928_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_211_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_211_2) + 7) & 255;
    }
  }

  int stage_v_212_1 = ((pub_r001928_0_1 * 2) + 41) & 63;
  int stage_v_212_2 = ((pub_r001928_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = 0;
  int stage_v_213_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_213_1 = ((stage_v_213_1 + (it_1 * 3)) + (stage_v_49_1 & 15)) & 63;
    stage_v_213_2 = ((stage_v_213_2 + (it_2 * 3)) + (stage_v_49_2 & 15)) & 63;
    if ((stage_v_49_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_213_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_213_1) + 7) & 255;
    }
    if ((stage_v_49_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_213_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_213_2) + 7) & 255;
    }
  }

  int stage_v_214_1 = 0;
  int stage_v_214_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_214_1 = ((stage_v_214_1 + (it_1 * 3)) + (stage_v_95_1 & 15)) & 63;
    stage_v_214_2 = ((stage_v_214_2 + (it_2 * 3)) + (stage_v_95_2 & 15)) & 63;
    if ((stage_v_95_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_214_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_214_1) + 7) & 255;
    }
    if ((stage_v_95_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_214_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_214_2) + 7) & 255;
    }
  }

  int stage_v_215_1 = 0;
  int stage_v_215_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_215_1 = ((stage_v_215_1 + (it_1 * 3)) + (stage_v_11_1 & 15)) & 63;
    stage_v_215_2 = ((stage_v_215_2 + (it_2 * 3)) + (stage_v_11_2 & 15)) & 63;
    if ((stage_v_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_215_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_215_1) + 7) & 255;
    }
    if ((stage_v_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_215_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_215_2) + 7) & 255;
    }
  }

  int stage_v_216_1 = 0;
  int stage_v_216_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_216_1 = ((stage_v_216_1 + (it_1 * 3)) + (stage_v_20_1 & 15)) & 63;
    stage_v_216_2 = ((stage_v_216_2 + (it_2 * 3)) + (stage_v_20_2 & 15)) & 63;
    if ((stage_v_20_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_216_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_216_1) + 7) & 255;
    }
    if ((stage_v_20_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_216_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_216_2) + 7) & 255;
    }
  }

  int stage_v_217_1 = 0;
  int stage_v_217_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_217_1 = ((stage_v_217_1 + (it_1 * 3)) + (sec_r001928_21_1 & 15)) & 63;
    stage_v_217_2 = ((stage_v_217_2 + (it_2 * 3)) + (sec_r001928_21_2 & 15)) & 63;
    if ((sec_r001928_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_217_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_217_1) + 7) & 255;
    }
    if ((sec_r001928_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_217_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_217_2) + 7) & 255;
    }
  }

  int stage_v_218_1 = 0;
  int stage_v_218_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_218_1 = ((stage_v_218_1 + (it_1 * 3)) + (sec_r001928_18_1 & 15)) & 63;
    stage_v_218_2 = ((stage_v_218_2 + (it_2 * 3)) + (sec_r001928_18_2 & 15)) & 63;
    if ((sec_r001928_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_218_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_218_1) + 7) & 255;
    }
    if ((sec_r001928_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_218_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_218_2) + 7) & 255;
    }
  }

  int stage_v_219_1 = ((pub_r001928_4_1 * 2) + 35) & 63;
  int stage_v_219_2 = ((pub_r001928_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = 0;
  int stage_v_220_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_220_1 = ((stage_v_220_1 + (it_1 * 3)) + (stage_v_88_1 & 15)) & 63;
    stage_v_220_2 = ((stage_v_220_2 + (it_2 * 3)) + (stage_v_88_2 & 15)) & 63;
    if ((stage_v_88_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_220_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_220_1) + 7) & 255;
    }
    if ((stage_v_88_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_220_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_220_2) + 7) & 255;
    }
  }

  int stage_v_221_1 = ((pub_r001928_4_1 * 2) + 37) & 63;
  int stage_v_221_2 = ((pub_r001928_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = 0;
  int stage_v_222_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_222_1 = ((stage_v_222_1 + (it_1 * 3)) + (stage_v_133_1 & 15)) & 63;
    stage_v_222_2 = ((stage_v_222_2 + (it_2 * 3)) + (stage_v_133_2 & 15)) & 63;
    if ((stage_v_133_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_222_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_222_1) + 7) & 255;
    }
    if ((stage_v_133_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_222_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_222_2) + 7) & 255;
    }
  }

  int stage_v_223_1 = 0;
  int stage_v_223_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_223_1 = ((stage_v_223_1 + (it_1 * 3)) + (stage_v_122_1 & 15)) & 63;
    stage_v_223_2 = ((stage_v_223_2 + (it_2 * 3)) + (stage_v_122_2 & 15)) & 63;
    if ((stage_v_122_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_223_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_223_1) + 7) & 255;
    }
    if ((stage_v_122_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_223_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_223_2) + 7) & 255;
    }
  }

  int stage_v_224_1 = 0;
  int stage_v_224_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_224_1 = ((stage_v_224_1 + (it_1 * 3)) + (stage_v_160_1 & 15)) & 63;
    stage_v_224_2 = ((stage_v_224_2 + (it_2 * 3)) + (stage_v_160_2 & 15)) & 63;
    if ((stage_v_160_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_224_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_224_1) + 7) & 255;
    }
    if ((stage_v_160_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_224_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_224_2) + 7) & 255;
    }
  }

  int stage_v_225_1 = 0;
  int stage_v_225_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_225_1 = ((stage_v_225_1 + (it_1 * 3)) + (stage_v_216_1 & 15)) & 63;
    stage_v_225_2 = ((stage_v_225_2 + (it_2 * 3)) + (stage_v_216_2 & 15)) & 63;
    if ((stage_v_216_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_225_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_225_1) + 7) & 255;
    }
    if ((stage_v_216_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_225_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_225_2) + 7) & 255;
    }
  }

  int stage_v_226_1 = 0;
  int stage_v_226_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_226_1 = ((stage_v_226_1 + (it_1 * 3)) + (stage_v_168_1 & 15)) & 63;
    stage_v_226_2 = ((stage_v_226_2 + (it_2 * 3)) + (stage_v_168_2 & 15)) & 63;
    if ((stage_v_168_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_226_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_226_1) + 7) & 255;
    }
    if ((stage_v_168_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_226_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_226_2) + 7) & 255;
    }
  }

  int stage_v_227_1 = 0;
  int stage_v_227_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_227_1 = ((stage_v_227_1 + (it_1 * 3)) + (stage_v_213_1 & 15)) & 63;
    stage_v_227_2 = ((stage_v_227_2 + (it_2 * 3)) + (stage_v_213_2 & 15)) & 63;
    if ((stage_v_213_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_227_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_227_1) + 7) & 255;
    }
    if ((stage_v_213_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_227_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_227_2) + 7) & 255;
    }
  }

  int stage_v_228_1 = 0;
  int stage_v_228_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_228_1 = ((stage_v_228_1 + (it_1 * 3)) + (stage_v_180_1 & 15)) & 63;
    stage_v_228_2 = ((stage_v_228_2 + (it_2 * 3)) + (stage_v_180_2 & 15)) & 63;
    if ((stage_v_180_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_228_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_228_1) + 7) & 255;
    }
    if ((stage_v_180_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_228_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_228_2) + 7) & 255;
    }
  }

  int stage_v_229_1 = ((pub_r001928_13_1 * 2) + 23) & 63;
  int stage_v_229_2 = ((pub_r001928_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = 0;
  int stage_v_230_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_230_1 = ((stage_v_230_1 + (it_1 * 3)) + (sec_r001928_21_1 & 15)) & 63;
    stage_v_230_2 = ((stage_v_230_2 + (it_2 * 3)) + (sec_r001928_21_2 & 15)) & 63;
    if ((sec_r001928_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_230_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_230_1) + 7) & 255;
    }
    if ((sec_r001928_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_230_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_230_2) + 7) & 255;
    }
  }

  int stage_v_231_1 = 0;
  int stage_v_231_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_231_1 = ((stage_v_231_1 + (it_1 * 3)) + (stage_v_193_1 & 15)) & 63;
    stage_v_231_2 = ((stage_v_231_2 + (it_2 * 3)) + (stage_v_193_2 & 15)) & 63;
    if ((stage_v_193_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_231_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_231_1) + 7) & 255;
    }
    if ((stage_v_193_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_231_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_231_2) + 7) & 255;
    }
  }

  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001928_11_1 != sec_r001928_11_2);
  __CPROVER_assume(sec_r001928_17_1 != sec_r001928_17_2);
  __CPROVER_assume(sec_r001928_3_1 != sec_r001928_3_2);
  __CPROVER_assume(pub_r001928_9_1 == pub_r001928_9_2);
  __CPROVER_assume(sec_r001928_13_1 != sec_r001928_13_2);
  __CPROVER_assume(pub_r001928_6_1 == pub_r001928_6_2);
  __CPROVER_assume(sec_r001928_9_1 != sec_r001928_9_2);
  __CPROVER_assume(pub_r001928_3_1 == pub_r001928_3_2);
  __CPROVER_assume(pub_r001928_13_1 == pub_r001928_13_2);
  __CPROVER_assume(sec_r001928_12_1 != sec_r001928_12_2);
  __CPROVER_assume(sec_r001928_19_1 != sec_r001928_19_2);
  __CPROVER_assume(sec_r001928_8_1 != sec_r001928_8_2);
  __CPROVER_assume(pub_r001928_8_1 == pub_r001928_8_2);
  __CPROVER_assume(pub_r001928_15_1 == pub_r001928_15_2);
  __CPROVER_assume(pub_r001928_7_1 == pub_r001928_7_2);
  __CPROVER_assume(sec_r001928_16_1 != sec_r001928_16_2);
  __CPROVER_assume(sec_r001928_20_1 != sec_r001928_20_2);
  __CPROVER_assume(sec_r001928_14_1 != sec_r001928_14_2);
  __CPROVER_assume(sec_r001928_22_1 != sec_r001928_22_2);
  __CPROVER_assume(sec_r001928_21_1 != sec_r001928_21_2);
  __CPROVER_assume(sec_r001928_18_1 != sec_r001928_18_2);
  __CPROVER_assume(sec_r001928_5_1 != sec_r001928_5_2);
  __CPROVER_assume(pub_r001928_5_1 == pub_r001928_5_2);
  __CPROVER_assume(sec_r001928_7_1 != sec_r001928_7_2);
  __CPROVER_assume(sec_r001928_0_1 != sec_r001928_0_2);
  __CPROVER_assume(pub_r001928_11_1 == pub_r001928_11_2);
  __CPROVER_assume(sec_r001928_15_1 != sec_r001928_15_2);
  __CPROVER_assume(sec_r001928_6_1 != sec_r001928_6_2);
  __CPROVER_assume(sec_r001928_23_1 != sec_r001928_23_2);
  __CPROVER_assume(pub_r001928_16_1 == pub_r001928_16_2);
  __CPROVER_assume(pub_r001928_14_1 == pub_r001928_14_2);
  __CPROVER_assume(sec_r001928_2_1 != sec_r001928_2_2);
  __CPROVER_assume(pub_r001928_1_1 == pub_r001928_1_2);
  __CPROVER_assume(pub_r001928_19_1 == pub_r001928_19_2);
  __CPROVER_assume(pub_r001928_0_1 == pub_r001928_0_2);
  __CPROVER_assume(sec_r001928_1_1 != sec_r001928_1_2);
  __CPROVER_assume(pub_r001928_2_1 == pub_r001928_2_2);
  __CPROVER_assume(pub_r001928_18_1 == pub_r001928_18_2);
  __CPROVER_assume(sec_r001928_4_1 != sec_r001928_4_2);
  __CPROVER_assume(pub_r001928_4_1 == pub_r001928_4_2);
  __CPROVER_assume(pub_r001928_10_1 == pub_r001928_10_2);
  __CPROVER_assume(pub_r001928_17_1 == pub_r001928_17_2);
  __CPROVER_assume(sec_r001928_10_1 != sec_r001928_10_2);
  __CPROVER_assume(pub_r001928_12_1 == pub_r001928_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.flags == st_var_1_2.flags);
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
}


