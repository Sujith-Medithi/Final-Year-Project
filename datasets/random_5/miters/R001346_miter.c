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
struct CipherContext_R001346_4613_0
{
  unsigned char round_key;
  int nonce;
  unsigned char counter;
  int buffer[3];
};
struct AudioFrame_R001346_4613_1
{
  unsigned char envelope;
  short channels;
  short sample_rate;
  unsigned char peak;
  short rms;
  int buffer[3];
};
union RegisterBank_R001346_4613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001346_4613_1
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
void fn_R001346_4613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int phase_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_94_1)
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

  switch (phase_94_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_39_1) & 63;
  aux_2 = (aux_2 + sample_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_94_1 == phase_94_2);
  assert(sample_39_1 == sample_39_2);
}

int fn_R001346_4613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int phase_94 = (aux + st.buffer[1]) & 3;
  switch (phase_94)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001346_4613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st_1 = {0};
  struct CipherContext_R001346_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_74_1 = local_arr_1[aux_1 % 3];
  int residue_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_74_2 * 2)) & 127;
  int mask_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_26_1 > 37)
  {
    acc_1 = ((acc_1 + (mask_26_1 * 2)) + 5) & 127;
    aux_1 ^= mask_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_26_2 > 37)
  {
    acc_2 = ((acc_2 + (mask_26_2 * 2)) + 5) & 127;
    aux_2 ^= mask_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_71_1)
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

  switch (cursor_71_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_74_1 == residue_74_2);
  assert(mask_26_1 == mask_26_2);
  assert(cursor_71_1 == cursor_71_2);
}

int fn_R001346_4613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int residue_74 = local_arr[aux % 3];
  acc = (acc + (residue_74 * 2)) & 127;
  int mask_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_26 > 37)
  {
    acc = ((acc + (mask_26 * 2)) + 5) & 127;
    aux ^= mask_26 & 15;
  }
  else
  {
    acc = ((acc - mask_26) + 11) & 127;
    aux += 3;
  }
  int cursor_71 = (aux + st.buffer[1]) & 3;
  switch (cursor_71)
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
  return (acc + aux) & 255;
}

void fn_R001346_4613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quotient_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_89_1)
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

  switch (quotient_89_2)
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

  int factor_50_1 = 0;
  int factor_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_50_1 = ((factor_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_50_2 = ((factor_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_50_1) & 127;
    acc_2 = (acc_2 + factor_50_2) & 127;
  }

  int cursor_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_46_1 > 42)
  {
    acc_1 = ((acc_1 + (cursor_46_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_46_2 > 42)
  {
    acc_2 = ((acc_2 + (cursor_46_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_45_1 = local_arr_1[aux_1 % 3];
  int vector_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_89_1 == quotient_89_2);
  assert(factor_50_1 == factor_50_2);
  assert(cursor_46_1 == cursor_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_45_1 == vector_45_2);
}

int fn_R001346_4613_2(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quotient_89 = (aux + st.buffer[1]) & 3;
  switch (quotient_89)
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

  int factor_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_50 = ((factor_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_50) & 127;
  }

  int cursor_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_46 > 42)
  {
    acc = ((acc + (cursor_46 * 2)) + 5) & 127;
    aux ^= cursor_46 & 15;
  }
  else
  {
    acc = ((acc - cursor_46) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_45 = local_arr[aux % 3];
  acc = (acc + (vector_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001346_4613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_15_1 = 0;
  int anchor_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_15_1 = ((anchor_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_15_2 = ((anchor_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_15_1) & 127;
    acc_2 = (acc_2 + anchor_15_2) & 127;
  }

  int accumulator_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_31_1) & 63;
  aux_2 = (aux_2 + accumulator_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_46_1 > 36)
  {
    acc_1 = ((acc_1 + (residue_46_1 * 2)) + 5) & 127;
    aux_1 ^= residue_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_46_2 > 36)
  {
    acc_2 = ((acc_2 + (residue_46_2 * 2)) + 5) & 127;
    aux_2 ^= residue_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_15_1 == anchor_15_2);
  assert(accumulator_31_1 == accumulator_31_2);
  assert(residue_46_1 == residue_46_2);
}

int fn_R001346_4613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_15 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_15 = ((anchor_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_15) & 127;
  }

  int accumulator_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_31) & 63;
  acc ^= aux;
  int residue_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_46 > 36)
  {
    acc = ((acc + (residue_46 * 2)) + 5) & 127;
    aux ^= residue_46 & 15;
  }
  else
  {
    acc = ((acc - residue_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001346_4613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st_1 = {0};
  struct CipherContext_R001346_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_14_1) & 63;
  aux_2 = (aux_2 + metric_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_53_1 = 0;
  int offset_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_53_1 = ((offset_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_53_2 = ((offset_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_53_1) & 127;
    acc_2 = (acc_2 + offset_53_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_44_1 = local_arr_1[aux_1 % 3];
  int pivot_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_14_1 == metric_14_2);
  assert(offset_53_1 == offset_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_44_1 == pivot_44_2);
}

int fn_R001346_4613_4(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_14) & 63;
  acc ^= aux;
  int offset_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_53 = ((offset_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_53) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_44 = local_arr[aux % 3];
  acc = (acc + (pivot_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001346_4613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st_1 = {0};
  struct CipherContext_R001346_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quantum_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_23_1) & 63;
  aux_2 = (aux_2 + quantum_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_87_1)
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

  switch (tally_87_2)
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

  int tally_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_41_1 > 43)
  {
    acc_1 = ((acc_1 + (tally_41_1 * 2)) + 5) & 127;
    aux_1 ^= tally_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_41_2 > 43)
  {
    acc_2 = ((acc_2 + (tally_41_2 * 2)) + 5) & 127;
    aux_2 ^= tally_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_41_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_23_1 == quantum_23_2);
  assert(tally_87_1 == tally_87_2);
  assert(tally_41_1 == tally_41_2);
}

int fn_R001346_4613_5(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quantum_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_23) & 63;
  acc ^= aux;
  int tally_87 = (aux + st.buffer[1]) & 3;
  switch (tally_87)
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

  int tally_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_41 > 43)
  {
    acc = ((acc + (tally_41 * 2)) + 5) & 127;
    aux ^= tally_41 & 15;
  }
  else
  {
    acc = ((acc - tally_41) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001346_4613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int parity_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_24_1 > 48)
  {
    acc_1 = ((acc_1 + (parity_24_1 * 2)) + 5) & 127;
    aux_1 ^= parity_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_24_2 > 48)
  {
    acc_2 = ((acc_2 + (parity_24_2 * 2)) + 5) & 127;
    aux_2 ^= parity_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_24_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_63_1) & 63;
  aux_2 = (aux_2 + margin_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_24_1 == parity_24_2);
  assert(margin_63_1 == margin_63_2);
}

int fn_R001346_4613_6(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int parity_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_24 > 48)
  {
    acc = ((acc + (parity_24 * 2)) + 5) & 127;
    aux ^= parity_24 & 15;
  }
  else
  {
    acc = ((acc - parity_24) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_63) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001346_4613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st_1 = {0};
  struct CipherContext_R001346_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int checksum_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_79_1 > 37)
  {
    acc_1 = ((acc_1 + (checksum_79_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_79_2 > 37)
  {
    acc_2 = ((acc_2 + (checksum_79_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_24_1 = 0;
  int vector_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_24_1 = ((vector_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_24_2 = ((vector_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_24_1) & 127;
    acc_2 = (acc_2 + vector_24_2) & 127;
  }

  int cursor_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_68_1)
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

  switch (cursor_68_2)
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
  int parity_11_1 = local_arr_1[aux_1 % 3];
  int parity_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_79_1 == checksum_79_2);
  assert(vector_24_1 == vector_24_2);
  assert(cursor_68_1 == cursor_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_11_1 == parity_11_2);
}

int fn_R001346_4613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int checksum_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_79 > 37)
  {
    acc = ((acc + (checksum_79 * 2)) + 5) & 127;
    aux ^= checksum_79 & 15;
  }
  else
  {
    acc = ((acc - checksum_79) + 11) & 127;
    aux += 3;
  }
  int vector_24 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_24 = ((vector_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_24) & 127;
  }

  int cursor_68 = (aux + st.buffer[1]) & 3;
  switch (cursor_68)
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
  int parity_11 = local_arr[aux % 3];
  acc = (acc + (parity_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001346_4613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int metric_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_51_1 > 33)
  {
    acc_1 = ((acc_1 + (metric_51_1 * 2)) + 5) & 127;
    aux_1 ^= metric_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_51_2 > 33)
  {
    acc_2 = ((acc_2 + (metric_51_2 * 2)) + 5) & 127;
    aux_2 ^= metric_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_95_1 = 0;
  int segment_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_95_1 = ((segment_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_95_2 = ((segment_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_95_1) & 127;
    acc_2 = (acc_2 + segment_95_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_48_1 = local_arr_1[aux_1 % 3];
  int scale_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_48_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_51_1 == metric_51_2);
  assert(segment_95_1 == segment_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_48_1 == scale_48_2);
}

int fn_R001346_4613_8(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int metric_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_51 > 33)
  {
    acc = ((acc + (metric_51 * 2)) + 5) & 127;
    aux ^= metric_51 & 15;
  }
  else
  {
    acc = ((acc - metric_51) + 11) & 127;
    aux += 3;
  }
  int segment_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_95 = ((segment_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_95) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int scale_48 = local_arr[aux % 3];
  acc = (acc + (scale_48 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001346_4613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st_1 = {0};
  struct CipherContext_R001346_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int tally_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_11_1) & 63;
  aux_2 = (aux_2 + tally_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_80_1 > 27)
  {
    acc_1 = ((acc_1 + (threshold_80_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_80_2 > 27)
  {
    acc_2 = ((acc_2 + (threshold_80_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_80_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_11_1 == tally_11_2);
  assert(threshold_80_1 == threshold_80_2);
}

int fn_R001346_4613_9(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int tally_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_11) & 63;
  acc ^= aux;
  int threshold_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_80 > 27)
  {
    acc = ((acc + (threshold_80 * 2)) + 5) & 127;
    aux ^= threshold_80 & 15;
  }
  else
  {
    acc = ((acc - threshold_80) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001346_4613_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int weight_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_32_1) & 63;
  aux_2 = (aux_2 + weight_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_82_1)
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

  switch (factor_82_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_32_1 == weight_32_2);
  assert(factor_82_1 == factor_82_2);
}

int fn_R001346_4613_10(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int weight_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_32) & 63;
  acc ^= aux;
  int factor_82 = (aux + st.buffer[1]) & 3;
  switch (factor_82)
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

void fn_R001346_4613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st_1 = {0};
  struct CipherContext_R001346_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int segment_61_1 = 0;
  int segment_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_61_1 = ((segment_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_61_2 = ((segment_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_61_1) & 127;
    acc_2 = (acc_2 + segment_61_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_61_1 == segment_61_2);
}

int fn_R001346_4613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int segment_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_61 = ((segment_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_61) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001346_4613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_42_1) & 63;
  aux_2 = (aux_2 + anchor_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_30_1)
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

  switch (margin_30_2)
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

  int stride_34_1 = 0;
  int stride_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_34_1 = ((stride_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_34_2 = ((stride_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_34_1) & 127;
    acc_2 = (acc_2 + stride_34_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_42_1 == anchor_42_2);
  assert(margin_30_1 == margin_30_2);
  assert(stride_34_1 == stride_34_2);
}

int fn_R001346_4613_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_42) & 63;
  acc ^= aux;
  int margin_30 = (aux + st.buffer[1]) & 3;
  switch (margin_30)
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

  int stride_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_34 = ((stride_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_34) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001346_4613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int quotient_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_45_1)
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

  switch (quotient_45_2)
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

  int tally_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_60_1) & 63;
  aux_2 = (aux_2 + tally_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_50_1 > 47)
  {
    acc_1 = ((acc_1 + (phase_50_1 * 2)) + 5) & 127;
    aux_1 ^= phase_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_50_2 > 47)
  {
    acc_2 = ((acc_2 + (phase_50_2 * 2)) + 5) & 127;
    aux_2 ^= phase_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_50_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_45_1 == quotient_45_2);
  assert(tally_60_1 == tally_60_2);
  assert(phase_50_1 == phase_50_2);
}

int fn_R001346_4613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int quotient_45 = (aux + st.buffer[1]) & 3;
  switch (quotient_45)
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

  int tally_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_60) & 63;
  acc ^= aux;
  int phase_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_50 > 47)
  {
    acc = ((acc + (phase_50 * 2)) + 5) & 127;
    aux ^= phase_50 & 15;
  }
  else
  {
    acc = ((acc - phase_50) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001346_4613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st_1 = {0};
  struct CipherContext_R001346_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int residue_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_37_1)
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

  switch (residue_37_2)
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

  int vector_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_61_1 > 37)
  {
    acc_1 = ((acc_1 + (vector_61_1 * 2)) + 5) & 127;
    aux_1 ^= vector_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_61_2 > 37)
  {
    acc_2 = ((acc_2 + (vector_61_2 * 2)) + 5) & 127;
    aux_2 ^= vector_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_82_1) & 63;
  aux_2 = (aux_2 + index_reg_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_37_1 == residue_37_2);
  assert(vector_61_1 == vector_61_2);
  assert(index_reg_82_1 == index_reg_82_2);
}

int fn_R001346_4613_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int residue_37 = (aux + st.buffer[1]) & 3;
  switch (residue_37)
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

  int vector_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_61 > 37)
  {
    acc = ((acc + (vector_61 * 2)) + 5) & 127;
    aux ^= vector_61 & 15;
  }
  else
  {
    acc = ((acc - vector_61) + 11) & 127;
    aux += 3;
  }
  int index_reg_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001346_4613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st_1 = {0};
  struct CipherContext_R001346_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int vector_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_54_1)
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

  switch (vector_54_2)
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
  int parity_15_1 = local_arr_1[aux_1 % 3];
  int parity_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_15_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_54_1 == vector_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_15_1 == parity_15_2);
}

int fn_R001346_4613_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int vector_54 = (aux + st.buffer[1]) & 3;
  switch (vector_54)
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
  int parity_15 = local_arr[aux % 3];
  acc = (acc + (parity_15 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001346_4613_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int offset_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_95_1) & 63;
  aux_2 = (aux_2 + offset_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_51_1)
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

  switch (tracker_51_2)
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
  int segment_10_1 = local_arr_1[aux_1 % 3];
  int segment_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_10_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_95_1 == offset_95_2);
  assert(tracker_51_1 == tracker_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_10_1 == segment_10_2);
}

int fn_R001346_4613_16(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int offset_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_95) & 63;
  acc ^= aux;
  int tracker_51 = (aux + st.buffer[1]) & 3;
  switch (tracker_51)
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
  int segment_10 = local_arr[aux % 3];
  acc = (acc + (segment_10 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001346_4613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int accumulator_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_56_1)
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

  switch (accumulator_56_2)
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

  int tracker_67_1 = 0;
  int tracker_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_67_1 = ((tracker_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_67_2 = ((tracker_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_67_1) & 127;
    acc_2 = (acc_2 + tracker_67_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_56_1 == accumulator_56_2);
  assert(tracker_67_1 == tracker_67_2);
}

int fn_R001346_4613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int accumulator_56 = (aux + st.buffer[1]) & 3;
  switch (accumulator_56)
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

  int tracker_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_67 = ((tracker_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_67) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001346_4613_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_82_1 = 0;
  int pivot_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_82_1 = ((pivot_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_82_2 = ((pivot_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_82_1) & 127;
    acc_2 = (acc_2 + pivot_82_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_80_1 = local_arr_1[aux_1 % 3];
  int pivot_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_82_1 == pivot_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_80_1 == pivot_80_2);
}

int fn_R001346_4613_18(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_82 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_82 = ((pivot_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_82) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_80 = local_arr[aux % 3];
  acc = (acc + (pivot_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001346_4613_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_13_1 = local_arr_1[aux_1 % 3];
  int phase_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_13_2 * 2)) & 127;
  int stride_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_58_1 > 18)
  {
    acc_1 = ((acc_1 + (stride_58_1 * 2)) + 5) & 127;
    aux_1 ^= stride_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_58_2 > 18)
  {
    acc_2 = ((acc_2 + (stride_58_2 * 2)) + 5) & 127;
    aux_2 ^= stride_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_81_1 = 0;
  int phase_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_81_1 = ((phase_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_81_2 = ((phase_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_81_1) & 127;
    acc_2 = (acc_2 + phase_81_2) & 127;
  }

  int tally_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_33_1)
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

  switch (tally_33_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_13_1 == phase_13_2);
  assert(stride_58_1 == stride_58_2);
  assert(phase_81_1 == phase_81_2);
  assert(tally_33_1 == tally_33_2);
}

int fn_R001346_4613_19(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int phase_13 = local_arr[aux % 3];
  acc = (acc + (phase_13 * 2)) & 127;
  int stride_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_58 > 18)
  {
    acc = ((acc + (stride_58 * 2)) + 5) & 127;
    aux ^= stride_58 & 15;
  }
  else
  {
    acc = ((acc - stride_58) + 11) & 127;
    aux += 3;
  }
  int phase_81 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_81 = ((phase_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_81) & 127;
  }

  int tally_33 = (aux + st.buffer[1]) & 3;
  switch (tally_33)
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

void fn_R001346_4613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int offset_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_38_1) & 63;
  aux_2 = (aux_2 + offset_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_19_1 = 0;
  int tracker_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_19_1 = ((tracker_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_19_2 = ((tracker_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_19_1) & 127;
    acc_2 = (acc_2 + tracker_19_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_38_1 == offset_38_2);
  assert(tracker_19_1 == tracker_19_2);
}

int fn_R001346_4613_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int offset_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_38) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_19 = ((tracker_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_19) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001346_4613_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_46_1 = local_arr_1[aux_1 % 3];
  int sample_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_46_2 * 2)) & 127;
  int factor_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_32_1 > 44)
  {
    acc_1 = ((acc_1 + (factor_32_1 * 2)) + 5) & 127;
    aux_1 ^= factor_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_32_2 > 44)
  {
    acc_2 = ((acc_2 + (factor_32_2 * 2)) + 5) & 127;
    aux_2 ^= factor_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_46_1 == sample_46_2);
  assert(factor_32_1 == factor_32_2);
}

int fn_R001346_4613_21(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_46 = local_arr[aux % 3];
  acc = (acc + (sample_46 * 2)) & 127;
  int factor_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_32 > 44)
  {
    acc = ((acc + (factor_32 * 2)) + 5) & 127;
    aux ^= factor_32 & 15;
  }
  else
  {
    acc = ((acc - factor_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001346_4613_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st_1 = {0};
  struct CipherContext_R001346_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_20_1)
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

  switch (stride_20_2)
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

  int residue_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_57_1 > 46)
  {
    acc_1 = ((acc_1 + (residue_57_1 * 2)) + 5) & 127;
    aux_1 ^= residue_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_57_2 > 46)
  {
    acc_2 = ((acc_2 + (residue_57_2 * 2)) + 5) & 127;
    aux_2 ^= residue_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_20_1 == stride_20_2);
  assert(residue_57_1 == residue_57_2);
}

int fn_R001346_4613_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001346_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_20 = (aux + st.buffer[1]) & 3;
  switch (stride_20)
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

  int residue_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_57 > 46)
  {
    acc = ((acc + (residue_57 * 2)) + 5) & 127;
    aux ^= residue_57 & 15;
  }
  else
  {
    acc = ((acc - residue_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001346_4613_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st_1 = {0};
  struct AudioFrame_R001346_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_33_1) & 63;
  aux_2 = (aux_2 + parity_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_13_1 = local_arr_1[aux_1 % 3];
  int threshold_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_33_1 == parity_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_13_1 == threshold_13_2);
}

int fn_R001346_4613_23(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001346_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_33) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_13 = local_arr[aux % 3];
  acc = (acc + (threshold_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001346_0_1;
  int sec_r001346_0_2;
  int sec_r001346_1_1;
  int sec_r001346_1_2;
  int sec_r001346_2_1;
  int sec_r001346_2_2;
  int sec_r001346_3_1;
  int sec_r001346_3_2;
  int sec_r001346_4_1;
  int sec_r001346_4_2;
  int sec_r001346_5_1;
  int sec_r001346_5_2;
  int sec_r001346_6_1;
  int sec_r001346_6_2;
  int sec_r001346_7_1;
  int sec_r001346_7_2;
  int sec_r001346_8_1;
  int sec_r001346_8_2;
  int sec_r001346_9_1;
  int sec_r001346_9_2;
  int sec_r001346_10_1;
  int sec_r001346_10_2;
  int sec_r001346_11_1;
  int sec_r001346_11_2;
  int sec_r001346_12_1;
  int sec_r001346_12_2;
  int sec_r001346_13_1;
  int sec_r001346_13_2;
  int sec_r001346_14_1;
  int sec_r001346_14_2;
  int sec_r001346_15_1;
  int sec_r001346_15_2;
  int sec_r001346_16_1;
  int sec_r001346_16_2;
  int sec_r001346_17_1;
  int sec_r001346_17_2;
  int sec_r001346_18_1;
  int sec_r001346_18_2;
  int pub_r001346_0_1;
  int pub_r001346_0_2;
  int pub_r001346_1_1;
  int pub_r001346_1_2;
  int pub_r001346_2_1;
  int pub_r001346_2_2;
  int pub_r001346_3_1;
  int pub_r001346_3_2;
  int pub_r001346_4_1;
  int pub_r001346_4_2;
  int pub_r001346_5_1;
  int pub_r001346_5_2;
  int pub_r001346_6_1;
  int pub_r001346_6_2;
  int pub_r001346_7_1;
  int pub_r001346_7_2;
  int pub_r001346_8_1;
  int pub_r001346_8_2;
  int pub_r001346_9_1;
  int pub_r001346_9_2;
  int pub_r001346_10_1;
  int pub_r001346_10_2;
  int pub_r001346_11_1;
  int pub_r001346_11_2;
  int pub_r001346_12_1;
  int pub_r001346_12_2;
  int pub_r001346_13_1;
  int pub_r001346_13_2;
  int pub_r001346_14_1;
  int pub_r001346_14_2;
  int pub_r001346_15_1;
  int pub_r001346_15_2;
  int pub_r001346_16_1;
  int pub_r001346_16_2;
  int pub_r001346_17_1;
  int pub_r001346_17_2;
  int pub_r001346_18_1;
  int pub_r001346_18_2;
  int pub_r001346_19_1;
  int pub_r001346_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001346_0_1 >= (-100)) && (pub_r001346_0_1 <= 100));
  __CPROVER_assume((pub_r001346_0_2 >= (-100)) && (pub_r001346_0_2 <= 100));
  __CPROVER_assume((pub_r001346_1_1 >= (-100)) && (pub_r001346_1_1 <= 100));
  __CPROVER_assume((pub_r001346_1_2 >= (-100)) && (pub_r001346_1_2 <= 100));
  __CPROVER_assume((pub_r001346_2_1 >= (-100)) && (pub_r001346_2_1 <= 100));
  __CPROVER_assume((pub_r001346_2_2 >= (-100)) && (pub_r001346_2_2 <= 100));
  __CPROVER_assume((pub_r001346_3_1 >= (-100)) && (pub_r001346_3_1 <= 100));
  __CPROVER_assume((pub_r001346_3_2 >= (-100)) && (pub_r001346_3_2 <= 100));
  __CPROVER_assume((pub_r001346_4_1 >= (-100)) && (pub_r001346_4_1 <= 100));
  __CPROVER_assume((pub_r001346_4_2 >= (-100)) && (pub_r001346_4_2 <= 100));
  __CPROVER_assume((pub_r001346_5_1 >= (-100)) && (pub_r001346_5_1 <= 100));
  __CPROVER_assume((pub_r001346_5_2 >= (-100)) && (pub_r001346_5_2 <= 100));
  __CPROVER_assume((pub_r001346_6_1 >= (-100)) && (pub_r001346_6_1 <= 100));
  __CPROVER_assume((pub_r001346_6_2 >= (-100)) && (pub_r001346_6_2 <= 100));
  __CPROVER_assume((pub_r001346_7_1 >= (-100)) && (pub_r001346_7_1 <= 100));
  __CPROVER_assume((pub_r001346_7_2 >= (-100)) && (pub_r001346_7_2 <= 100));
  __CPROVER_assume((pub_r001346_8_1 >= (-100)) && (pub_r001346_8_1 <= 100));
  __CPROVER_assume((pub_r001346_8_2 >= (-100)) && (pub_r001346_8_2 <= 100));
  __CPROVER_assume((pub_r001346_9_1 >= (-100)) && (pub_r001346_9_1 <= 100));
  __CPROVER_assume((pub_r001346_9_2 >= (-100)) && (pub_r001346_9_2 <= 100));
  __CPROVER_assume((pub_r001346_10_1 >= (-100)) && (pub_r001346_10_1 <= 100));
  __CPROVER_assume((pub_r001346_10_2 >= (-100)) && (pub_r001346_10_2 <= 100));
  __CPROVER_assume((pub_r001346_11_1 >= (-100)) && (pub_r001346_11_1 <= 100));
  __CPROVER_assume((pub_r001346_11_2 >= (-100)) && (pub_r001346_11_2 <= 100));
  __CPROVER_assume((pub_r001346_12_1 >= (-100)) && (pub_r001346_12_1 <= 100));
  __CPROVER_assume((pub_r001346_12_2 >= (-100)) && (pub_r001346_12_2 <= 100));
  __CPROVER_assume((pub_r001346_13_1 >= (-100)) && (pub_r001346_13_1 <= 100));
  __CPROVER_assume((pub_r001346_13_2 >= (-100)) && (pub_r001346_13_2 <= 100));
  __CPROVER_assume((pub_r001346_14_1 >= (-100)) && (pub_r001346_14_1 <= 100));
  __CPROVER_assume((pub_r001346_14_2 >= (-100)) && (pub_r001346_14_2 <= 100));
  __CPROVER_assume((pub_r001346_15_1 >= (-100)) && (pub_r001346_15_1 <= 100));
  __CPROVER_assume((pub_r001346_15_2 >= (-100)) && (pub_r001346_15_2 <= 100));
  __CPROVER_assume((pub_r001346_16_1 >= (-100)) && (pub_r001346_16_1 <= 100));
  __CPROVER_assume((pub_r001346_16_2 >= (-100)) && (pub_r001346_16_2 <= 100));
  __CPROVER_assume((pub_r001346_17_1 >= (-100)) && (pub_r001346_17_1 <= 100));
  __CPROVER_assume((pub_r001346_17_2 >= (-100)) && (pub_r001346_17_2 <= 100));
  __CPROVER_assume((pub_r001346_18_1 >= (-100)) && (pub_r001346_18_1 <= 100));
  __CPROVER_assume((pub_r001346_18_2 >= (-100)) && (pub_r001346_18_2 <= 100));
  __CPROVER_assume((pub_r001346_19_1 >= (-100)) && (pub_r001346_19_1 <= 100));
  __CPROVER_assume((pub_r001346_19_2 >= (-100)) && (pub_r001346_19_2 <= 100));
  __CPROVER_assume((sec_r001346_0_1 >= 0) && (sec_r001346_0_1 <= 255));
  __CPROVER_assume((sec_r001346_0_2 >= 0) && (sec_r001346_0_2 <= 255));
  __CPROVER_assume((sec_r001346_1_1 >= 0) && (sec_r001346_1_1 <= 255));
  __CPROVER_assume((sec_r001346_1_2 >= 0) && (sec_r001346_1_2 <= 255));
  __CPROVER_assume((sec_r001346_2_1 >= 0) && (sec_r001346_2_1 <= 255));
  __CPROVER_assume((sec_r001346_2_2 >= 0) && (sec_r001346_2_2 <= 255));
  __CPROVER_assume((sec_r001346_3_1 >= 0) && (sec_r001346_3_1 <= 255));
  __CPROVER_assume((sec_r001346_3_2 >= 0) && (sec_r001346_3_2 <= 255));
  __CPROVER_assume((sec_r001346_4_1 >= 0) && (sec_r001346_4_1 <= 255));
  __CPROVER_assume((sec_r001346_4_2 >= 0) && (sec_r001346_4_2 <= 255));
  __CPROVER_assume((sec_r001346_5_1 >= 0) && (sec_r001346_5_1 <= 255));
  __CPROVER_assume((sec_r001346_5_2 >= 0) && (sec_r001346_5_2 <= 255));
  __CPROVER_assume((sec_r001346_6_1 >= 0) && (sec_r001346_6_1 <= 255));
  __CPROVER_assume((sec_r001346_6_2 >= 0) && (sec_r001346_6_2 <= 255));
  __CPROVER_assume((sec_r001346_7_1 >= 0) && (sec_r001346_7_1 <= 255));
  __CPROVER_assume((sec_r001346_7_2 >= 0) && (sec_r001346_7_2 <= 255));
  __CPROVER_assume((sec_r001346_8_1 >= 0) && (sec_r001346_8_1 <= 255));
  __CPROVER_assume((sec_r001346_8_2 >= 0) && (sec_r001346_8_2 <= 255));
  __CPROVER_assume((sec_r001346_9_1 >= 0) && (sec_r001346_9_1 <= 255));
  __CPROVER_assume((sec_r001346_9_2 >= 0) && (sec_r001346_9_2 <= 255));
  __CPROVER_assume((sec_r001346_10_1 >= 0) && (sec_r001346_10_1 <= 255));
  __CPROVER_assume((sec_r001346_10_2 >= 0) && (sec_r001346_10_2 <= 255));
  __CPROVER_assume((sec_r001346_11_1 >= 0) && (sec_r001346_11_1 <= 255));
  __CPROVER_assume((sec_r001346_11_2 >= 0) && (sec_r001346_11_2 <= 255));
  __CPROVER_assume((sec_r001346_12_1 >= 0) && (sec_r001346_12_1 <= 255));
  __CPROVER_assume((sec_r001346_12_2 >= 0) && (sec_r001346_12_2 <= 255));
  __CPROVER_assume((sec_r001346_13_1 >= 0) && (sec_r001346_13_1 <= 255));
  __CPROVER_assume((sec_r001346_13_2 >= 0) && (sec_r001346_13_2 <= 255));
  __CPROVER_assume((sec_r001346_14_1 >= 0) && (sec_r001346_14_1 <= 255));
  __CPROVER_assume((sec_r001346_14_2 >= 0) && (sec_r001346_14_2 <= 255));
  __CPROVER_assume((sec_r001346_15_1 >= 0) && (sec_r001346_15_1 <= 255));
  __CPROVER_assume((sec_r001346_15_2 >= 0) && (sec_r001346_15_2 <= 255));
  __CPROVER_assume((sec_r001346_16_1 >= 0) && (sec_r001346_16_1 <= 255));
  __CPROVER_assume((sec_r001346_16_2 >= 0) && (sec_r001346_16_2 <= 255));
  __CPROVER_assume((sec_r001346_17_1 >= 0) && (sec_r001346_17_1 <= 255));
  __CPROVER_assume((sec_r001346_17_2 >= 0) && (sec_r001346_17_2 <= 255));
  __CPROVER_assume((sec_r001346_18_1 >= 0) && (sec_r001346_18_1 <= 255));
  __CPROVER_assume((sec_r001346_18_2 >= 0) && (sec_r001346_18_2 <= 255));
  struct CipherContext_R001346_4613_0 st_var_0_1 = {0};
  struct CipherContext_R001346_4613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001346_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001346_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001346_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001346_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001346_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001346_0_2 + 7) & 15;
  struct AudioFrame_R001346_4613_1 st_var_1_1 = {0};
  struct AudioFrame_R001346_4613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001346_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001346_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001346_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001346_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001346_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001346_0_2 + 9) & 15;
  union RegisterBank_R001346_4613_0 u_var_1;
  union RegisterBank_R001346_4613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001346_4613_0(sec_r001346_0_1, pub_r001346_1_1, pub_r001346_2_1, pub_r001346_3_1, pub_r001346_4_1);
  int helper_flow_0_2 = fn_R001346_4613_0(sec_r001346_0_2, pub_r001346_1_2, pub_r001346_2_2, pub_r001346_3_2, pub_r001346_4_2);
  fn_R001346_4613_0_2(sec_r001346_0_1, pub_r001346_1_1, pub_r001346_2_1, pub_r001346_3_1, pub_r001346_4_1, sec_r001346_0_2, pub_r001346_1_2, pub_r001346_2_2, pub_r001346_3_2, pub_r001346_4_2);
  int helper_flow_1_1 = fn_R001346_4613_1(sec_r001346_1_1, sec_r001346_2_1, pub_r001346_3_1);
  int helper_flow_1_2 = fn_R001346_4613_1(sec_r001346_1_2, sec_r001346_2_2, pub_r001346_3_2);
  fn_R001346_4613_1_2(sec_r001346_1_1, sec_r001346_2_1, pub_r001346_3_1, sec_r001346_1_2, sec_r001346_2_2, pub_r001346_3_2);
  int helper_flow_2_1 = fn_R001346_4613_2(sec_r001346_2_1, pub_r001346_3_1);
  int helper_flow_2_2 = fn_R001346_4613_2(sec_r001346_2_2, pub_r001346_3_2);
  fn_R001346_4613_2_2(sec_r001346_2_1, pub_r001346_3_1, sec_r001346_2_2, pub_r001346_3_2);
  int helper_flow_3_1 = fn_R001346_4613_3(sec_r001346_3_1, sec_r001346_4_1, pub_r001346_5_1, pub_r001346_6_1, pub_r001346_7_1);
  int helper_flow_3_2 = fn_R001346_4613_3(sec_r001346_3_2, sec_r001346_4_2, pub_r001346_5_2, pub_r001346_6_2, pub_r001346_7_2);
  fn_R001346_4613_3_2(sec_r001346_3_1, sec_r001346_4_1, pub_r001346_5_1, pub_r001346_6_1, pub_r001346_7_1, sec_r001346_3_2, sec_r001346_4_2, pub_r001346_5_2, pub_r001346_6_2, pub_r001346_7_2);
  int helper_flow_4_1 = fn_R001346_4613_4(sec_r001346_4_1, sec_r001346_5_1);
  int helper_flow_4_2 = fn_R001346_4613_4(sec_r001346_4_2, sec_r001346_5_2);
  fn_R001346_4613_4_2(sec_r001346_4_1, sec_r001346_5_1, sec_r001346_4_2, sec_r001346_5_2);
  int helper_flow_5_1 = fn_R001346_4613_5(sec_r001346_5_1, sec_r001346_6_1);
  int helper_flow_5_2 = fn_R001346_4613_5(sec_r001346_5_2, sec_r001346_6_2);
  fn_R001346_4613_5_2(sec_r001346_5_1, sec_r001346_6_1, sec_r001346_5_2, sec_r001346_6_2);
  int helper_flow_6_1 = fn_R001346_4613_6(sec_r001346_6_1, pub_r001346_7_1);
  int helper_flow_6_2 = fn_R001346_4613_6(sec_r001346_6_2, pub_r001346_7_2);
  fn_R001346_4613_6_2(sec_r001346_6_1, pub_r001346_7_1, sec_r001346_6_2, pub_r001346_7_2);
  int helper_flow_7_1 = fn_R001346_4613_7(sec_r001346_7_1, pub_r001346_8_1, pub_r001346_9_1, pub_r001346_10_1);
  int helper_flow_7_2 = fn_R001346_4613_7(sec_r001346_7_2, pub_r001346_8_2, pub_r001346_9_2, pub_r001346_10_2);
  fn_R001346_4613_7_2(sec_r001346_7_1, pub_r001346_8_1, pub_r001346_9_1, pub_r001346_10_1, sec_r001346_7_2, pub_r001346_8_2, pub_r001346_9_2, pub_r001346_10_2);
  int helper_flow_8_1 = fn_R001346_4613_8(sec_r001346_8_1, pub_r001346_9_1);
  int helper_flow_8_2 = fn_R001346_4613_8(sec_r001346_8_2, pub_r001346_9_2);
  fn_R001346_4613_8_2(sec_r001346_8_1, pub_r001346_9_1, sec_r001346_8_2, pub_r001346_9_2);
  int stage_v_0_1 = ((helper_flow_3_1 + (pub_r001346_18_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_3_2 + (pub_r001346_18_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001346_18_1 + (pub_r001346_0_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001346_18_2 + (pub_r001346_0_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((sec_r001346_7_1 + (pub_r001346_0_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001346_7_2 + (pub_r001346_0_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((sec_r001346_1_1 + (pub_r001346_16_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001346_1_2 + (pub_r001346_16_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001346_14_1 * 2) + 28) & 63;
  int stage_v_4_2 = ((pub_r001346_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((sec_r001346_15_1 + (pub_r001346_1_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001346_15_2 + (pub_r001346_1_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001346_1_1 + (pub_r001346_13_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001346_1_2 + (pub_r001346_13_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((stage_v_3_1 + (pub_r001346_7_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((stage_v_3_2 + (pub_r001346_7_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((sec_r001346_8_1 + (pub_r001346_1_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001346_8_2 + (pub_r001346_1_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((helper_flow_8_1 + (pub_r001346_10_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((helper_flow_8_2 + (pub_r001346_10_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((pub_r001346_15_1 * 2) + 15) & 63;
  int stage_v_10_2 = ((pub_r001346_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001346_6_1 * 2) + 26) & 63;
  int stage_v_11_2 = ((pub_r001346_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((stage_v_2_1 + (pub_r001346_6_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((stage_v_2_2 + (pub_r001346_6_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001346_7_1 + (pub_r001346_1_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001346_7_2 + (pub_r001346_1_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((helper_flow_0_1 + (pub_r001346_6_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((helper_flow_0_2 + (pub_r001346_6_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((sec_r001346_7_1 + (pub_r001346_11_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((sec_r001346_7_2 + (pub_r001346_11_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001346_2_1 * 2) + 31) & 63;
  int stage_v_16_2 = ((pub_r001346_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((sec_r001346_5_1 + (pub_r001346_4_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001346_5_2 + (pub_r001346_4_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001346_17_1 * 2) + 22) & 63;
  int stage_v_18_2 = ((pub_r001346_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001346_0_1 * 2) + 14) & 63;
  int stage_v_19_2 = ((pub_r001346_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001346_4_1 * 2) + 33) & 63;
  int stage_v_20_2 = ((pub_r001346_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((helper_flow_8_1 + (pub_r001346_2_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((helper_flow_8_2 + (pub_r001346_2_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((pub_r001346_15_1 * 2) + 20) & 63;
  int stage_v_22_2 = ((pub_r001346_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001346_10_1 * 2) + 48) & 63;
  int stage_v_23_2 = ((pub_r001346_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001346_0_1 * 2) + 13) & 63;
  int stage_v_24_2 = ((pub_r001346_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((stage_v_5_1 + (pub_r001346_19_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((stage_v_5_2 + (pub_r001346_19_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((pub_r001346_9_1 * 2) + 24) & 63;
  int stage_v_26_2 = ((pub_r001346_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((stage_v_1_1 + (pub_r001346_12_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((stage_v_1_2 + (pub_r001346_12_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((stage_v_0_1 + (pub_r001346_19_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_0_2 + (pub_r001346_19_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((helper_flow_3_1 + (pub_r001346_9_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((helper_flow_3_2 + (pub_r001346_9_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((helper_flow_1_1 + (pub_r001346_9_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((helper_flow_1_2 + (pub_r001346_9_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001346_16_1 * 2) + 9) & 63;
  int stage_v_31_2 = ((pub_r001346_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((sec_r001346_9_1 + (pub_r001346_11_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((sec_r001346_9_2 + (pub_r001346_11_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((pub_r001346_13_1 * 2) + 34) & 63;
  int stage_v_33_2 = ((pub_r001346_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((sec_r001346_16_1 + (pub_r001346_12_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((sec_r001346_16_2 + (pub_r001346_12_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((helper_flow_7_1 + (pub_r001346_13_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((helper_flow_7_2 + (pub_r001346_13_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((stage_v_21_1 + (pub_r001346_16_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_21_2 + (pub_r001346_16_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((pub_r001346_7_1 * 2) + 7) & 63;
  int stage_v_37_2 = ((pub_r001346_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001346_16_1 * 2) + 6) & 63;
  int stage_v_38_2 = ((pub_r001346_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((sec_r001346_17_1 + (pub_r001346_11_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001346_17_2 + (pub_r001346_11_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((pub_r001346_18_1 * 2) + 24) & 63;
  int stage_v_40_2 = ((pub_r001346_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001346_1_1 * 2) + 42) & 63;
  int stage_v_41_2 = ((pub_r001346_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((helper_flow_8_1 + (pub_r001346_9_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((helper_flow_8_2 + (pub_r001346_9_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((sec_r001346_5_1 + (pub_r001346_10_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((sec_r001346_5_2 + (pub_r001346_10_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((stage_v_21_1 + (pub_r001346_4_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_21_2 + (pub_r001346_4_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((sec_r001346_2_1 + (pub_r001346_3_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001346_2_2 + (pub_r001346_3_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((stage_v_34_1 + (pub_r001346_3_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_34_2 + (pub_r001346_3_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((pub_r001346_19_1 * 2) + 34) & 63;
  int stage_v_47_2 = ((pub_r001346_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((stage_v_9_1 + (pub_r001346_3_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_9_2 + (pub_r001346_3_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((pub_r001346_6_1 * 2) + 47) & 63;
  int stage_v_49_2 = ((pub_r001346_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((sec_r001346_6_1 + (pub_r001346_4_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((sec_r001346_6_2 + (pub_r001346_4_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((stage_v_14_1 + (pub_r001346_1_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((stage_v_14_2 + (pub_r001346_1_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((pub_r001346_16_1 * 2) + 5) & 63;
  int stage_v_52_2 = ((pub_r001346_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((stage_v_28_1 + (pub_r001346_2_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_28_2 + (pub_r001346_2_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((sec_r001346_2_1 + (pub_r001346_13_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((sec_r001346_2_2 + (pub_r001346_13_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((pub_r001346_11_1 * 2) + 31) & 63;
  int stage_v_55_2 = ((pub_r001346_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001346_3_1 * 2) + 10) & 63;
  int stage_v_56_2 = ((pub_r001346_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001346_2_1 * 2) + 7) & 63;
  int stage_v_57_2 = ((pub_r001346_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001346_14_1 * 2) + 12) & 63;
  int stage_v_58_2 = ((pub_r001346_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((sec_r001346_8_1 + (pub_r001346_8_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((sec_r001346_8_2 + (pub_r001346_8_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((stage_v_15_1 + (pub_r001346_2_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_15_2 + (pub_r001346_2_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((pub_r001346_15_1 * 2) + 21) & 63;
  int stage_v_61_2 = ((pub_r001346_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001346_19_1 * 2) + 32) & 63;
  int stage_v_62_2 = ((pub_r001346_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001346_8_1 * 2) + 34) & 63;
  int stage_v_63_2 = ((pub_r001346_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((sec_r001346_4_1 + (pub_r001346_5_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001346_4_2 + (pub_r001346_5_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((sec_r001346_16_1 + (pub_r001346_5_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((sec_r001346_16_2 + (pub_r001346_5_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((sec_r001346_10_1 + (pub_r001346_12_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((sec_r001346_10_2 + (pub_r001346_12_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((sec_r001346_15_1 + (pub_r001346_19_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((sec_r001346_15_2 + (pub_r001346_19_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((stage_v_28_1 + (pub_r001346_7_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_28_2 + (pub_r001346_7_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((stage_v_51_1 + (pub_r001346_8_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((stage_v_51_2 + (pub_r001346_8_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((pub_r001346_9_1 * 2) + 46) & 63;
  int stage_v_70_2 = ((pub_r001346_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001346_1_1 * 2) + 16) & 63;
  int stage_v_71_2 = ((pub_r001346_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((stage_v_15_1 + (pub_r001346_2_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_15_2 + (pub_r001346_2_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((pub_r001346_0_1 * 2) + 43) & 63;
  int stage_v_73_2 = ((pub_r001346_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001346_13_1 * 2) + 48) & 63;
  int stage_v_74_2 = ((pub_r001346_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((stage_v_28_1 + (pub_r001346_2_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_28_2 + (pub_r001346_2_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((helper_flow_4_1 + (pub_r001346_10_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((helper_flow_4_2 + (pub_r001346_10_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((stage_v_75_1 + (pub_r001346_8_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_75_2 + (pub_r001346_8_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_25_1 + (pub_r001346_18_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_25_2 + (pub_r001346_18_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001346_6_1 * 2) + 31) & 63;
  int stage_v_79_2 = ((pub_r001346_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((sec_r001346_0_1 + (pub_r001346_11_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((sec_r001346_0_2 + (pub_r001346_11_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((stage_v_39_1 + (pub_r001346_0_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_39_2 + (pub_r001346_0_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001346_18_1 * 2) + 10) & 63;
  int stage_v_82_2 = ((pub_r001346_18_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001346_18_1 * 2) + 49) & 63;
  int stage_v_83_2 = ((pub_r001346_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001346_17_1 * 2) + 18) & 63;
  int stage_v_84_2 = ((pub_r001346_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((sec_r001346_5_1 + (pub_r001346_13_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((sec_r001346_5_2 + (pub_r001346_13_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_76_1 + (pub_r001346_13_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_76_2 + (pub_r001346_13_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((sec_r001346_17_1 + (pub_r001346_7_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((sec_r001346_17_2 + (pub_r001346_7_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_48_1 + (pub_r001346_2_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_48_2 + (pub_r001346_2_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_46_1 + (pub_r001346_19_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_46_2 + (pub_r001346_19_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((helper_flow_2_1 + (pub_r001346_7_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((helper_flow_2_2 + (pub_r001346_7_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_6_1 + (pub_r001346_11_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_6_2 + (pub_r001346_11_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((helper_flow_1_1 + (pub_r001346_6_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((helper_flow_1_2 + (pub_r001346_6_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((pub_r001346_18_1 * 2) + 23) & 63;
  int stage_v_93_2 = ((pub_r001346_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((stage_v_44_1 + (pub_r001346_18_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_44_2 + (pub_r001346_18_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((helper_flow_4_1 + (pub_r001346_18_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((helper_flow_4_2 + (pub_r001346_18_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_76_1 + (pub_r001346_5_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_76_2 + (pub_r001346_5_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((pub_r001346_12_1 * 2) + 15) & 63;
  int stage_v_97_2 = ((pub_r001346_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001346_14_1 * 2) + 41) & 63;
  int stage_v_98_2 = ((pub_r001346_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001346_19_1 * 2) + 34) & 63;
  int stage_v_99_2 = ((pub_r001346_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((helper_flow_4_1 + (pub_r001346_5_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((helper_flow_4_2 + (pub_r001346_5_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((pub_r001346_7_1 * 2) + 44) & 63;
  int stage_v_101_2 = ((pub_r001346_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_25_1 + (pub_r001346_5_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_25_2 + (pub_r001346_5_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((sec_r001346_9_1 + (pub_r001346_15_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((sec_r001346_9_2 + (pub_r001346_15_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_5_1 + (pub_r001346_3_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_5_2 + (pub_r001346_3_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_39_1 + (pub_r001346_0_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_39_2 + (pub_r001346_0_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_1_1 + (pub_r001346_6_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_1_2 + (pub_r001346_6_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_59_1 + (pub_r001346_5_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_59_2 + (pub_r001346_5_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((pub_r001346_13_1 * 2) + 36) & 63;
  int stage_v_108_2 = ((pub_r001346_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_46_1 + (pub_r001346_12_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_46_2 + (pub_r001346_12_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((pub_r001346_2_1 * 2) + 8) & 63;
  int stage_v_110_2 = ((pub_r001346_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_28_1 + (pub_r001346_1_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_28_2 + (pub_r001346_1_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((sec_r001346_11_1 + (pub_r001346_3_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((sec_r001346_11_2 + (pub_r001346_3_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((stage_v_25_1 + (pub_r001346_6_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_25_2 + (pub_r001346_6_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((stage_v_102_1 + (pub_r001346_19_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_102_2 + (pub_r001346_19_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((sec_r001346_18_1 + (pub_r001346_8_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((sec_r001346_18_2 + (pub_r001346_8_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((pub_r001346_8_1 * 2) + 19) & 63;
  int stage_v_116_2 = ((pub_r001346_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((helper_flow_4_1 + (pub_r001346_7_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((helper_flow_4_2 + (pub_r001346_7_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((stage_v_54_1 + (pub_r001346_5_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_54_2 + (pub_r001346_5_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((pub_r001346_9_1 * 2) + 23) & 63;
  int stage_v_119_2 = ((pub_r001346_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001346_8_1 * 2) + 22) & 63;
  int stage_v_120_2 = ((pub_r001346_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001346_3_1 * 2) + 18) & 63;
  int stage_v_121_2 = ((pub_r001346_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001346_19_1 * 2) + 14) & 63;
  int stage_v_122_2 = ((pub_r001346_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001346_5_1 * 2) + 10) & 63;
  int stage_v_123_2 = ((pub_r001346_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001346_9_1 * 2) + 39) & 63;
  int stage_v_124_2 = ((pub_r001346_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_8_1 + (pub_r001346_15_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_8_2 + (pub_r001346_15_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((pub_r001346_17_1 * 2) + 48) & 63;
  int stage_v_126_2 = ((pub_r001346_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((sec_r001346_15_1 + (pub_r001346_3_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((sec_r001346_15_2 + (pub_r001346_3_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((pub_r001346_19_1 * 2) + 26) & 63;
  int stage_v_128_2 = ((pub_r001346_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001346_10_1 * 2) + 44) & 63;
  int stage_v_129_2 = ((pub_r001346_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((helper_flow_2_1 + (pub_r001346_5_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((helper_flow_2_2 + (pub_r001346_5_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_95_1 + (pub_r001346_5_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_95_2 + (pub_r001346_5_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((stage_v_9_1 + (pub_r001346_11_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_9_2 + (pub_r001346_11_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((sec_r001346_8_1 + (pub_r001346_13_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((sec_r001346_8_2 + (pub_r001346_13_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_118_1 + (pub_r001346_4_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_118_2 + (pub_r001346_4_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((pub_r001346_2_1 * 2) + 49) & 63;
  int stage_v_135_2 = ((pub_r001346_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001346_14_1 * 2) + 37) & 63;
  int stage_v_136_2 = ((pub_r001346_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((stage_v_2_1 + (pub_r001346_9_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_2_2 + (pub_r001346_9_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((pub_r001346_11_1 * 2) + 46) & 63;
  int stage_v_138_2 = ((pub_r001346_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001346_8_1 * 2) + 30) & 63;
  int stage_v_139_2 = ((pub_r001346_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001346_16_1 * 2) + 7) & 63;
  int stage_v_140_2 = ((pub_r001346_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001346_13_1 * 2) + 16) & 63;
  int stage_v_141_2 = ((pub_r001346_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((stage_v_105_1 + (pub_r001346_17_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_105_2 + (pub_r001346_17_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_102_1 + (pub_r001346_3_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_102_2 + (pub_r001346_3_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((pub_r001346_0_1 * 2) + 37) & 63;
  int stage_v_144_2 = ((pub_r001346_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_89_1 + (pub_r001346_18_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_89_2 + (pub_r001346_18_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_53_1 + (pub_r001346_2_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_53_2 + (pub_r001346_2_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((pub_r001346_1_1 * 2) + 16) & 63;
  int stage_v_147_2 = ((pub_r001346_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001346_2_1 * 2) + 14) & 63;
  int stage_v_148_2 = ((pub_r001346_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((stage_v_76_1 + (pub_r001346_2_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_76_2 + (pub_r001346_2_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_112_1 + (pub_r001346_19_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_112_2 + (pub_r001346_19_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((pub_r001346_16_1 * 2) + 16) & 63;
  int stage_v_151_2 = ((pub_r001346_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_68_1 + (pub_r001346_7_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_68_2 + (pub_r001346_7_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_7_1 + (pub_r001346_11_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_7_2 + (pub_r001346_11_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((stage_v_54_1 + (pub_r001346_1_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_54_2 + (pub_r001346_1_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((sec_r001346_8_1 + (pub_r001346_9_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((sec_r001346_8_2 + (pub_r001346_9_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((pub_r001346_10_1 * 2) + 23) & 63;
  int stage_v_156_2 = ((pub_r001346_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001346_1_1 * 2) + 25) & 63;
  int stage_v_157_2 = ((pub_r001346_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_65_1 + (pub_r001346_12_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_65_2 + (pub_r001346_12_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_42_1 + (pub_r001346_12_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_42_2 + (pub_r001346_12_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((pub_r001346_1_1 * 2) + 6) & 63;
  int stage_v_160_2 = ((pub_r001346_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_142_1 + (pub_r001346_17_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_142_2 + (pub_r001346_17_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((stage_v_0_1 + (pub_r001346_11_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_0_2 + (pub_r001346_11_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_137_1 + (pub_r001346_1_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_137_2 + (pub_r001346_1_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_59_1 + (pub_r001346_19_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_59_2 + (pub_r001346_19_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_137_1 + (pub_r001346_1_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_137_2 + (pub_r001346_1_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((pub_r001346_9_1 * 2) + 45) & 63;
  int stage_v_166_2 = ((pub_r001346_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001346_11_1 * 2) + 36) & 63;
  int stage_v_167_2 = ((pub_r001346_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((helper_flow_0_1 + (pub_r001346_11_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((helper_flow_0_2 + (pub_r001346_11_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_6_1 + (pub_r001346_18_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_6_2 + (pub_r001346_18_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((sec_r001346_18_1 + (pub_r001346_11_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((sec_r001346_18_2 + (pub_r001346_11_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((sec_r001346_3_1 + (pub_r001346_14_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((sec_r001346_3_2 + (pub_r001346_14_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((stage_v_158_1 + (pub_r001346_12_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_158_2 + (pub_r001346_12_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((pub_r001346_11_1 * 2) + 39) & 63;
  int stage_v_173_2 = ((pub_r001346_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((helper_flow_0_1 + (pub_r001346_19_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((helper_flow_0_2 + (pub_r001346_19_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((pub_r001346_1_1 * 2) + 42) & 63;
  int stage_v_175_2 = ((pub_r001346_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((sec_r001346_16_1 + (pub_r001346_7_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((sec_r001346_16_2 + (pub_r001346_7_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((helper_flow_8_1 + (pub_r001346_8_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((helper_flow_8_2 + (pub_r001346_8_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_107_1 + (pub_r001346_1_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_107_2 + (pub_r001346_1_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((pub_r001346_6_1 * 2) + 14) & 63;
  int stage_v_179_2 = ((pub_r001346_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001346_14_1 * 2) + 12) & 63;
  int stage_v_180_2 = ((pub_r001346_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((stage_v_169_1 + (pub_r001346_13_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_169_2 + (pub_r001346_13_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_32_1 + (pub_r001346_8_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_32_2 + (pub_r001346_8_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_8_1 + (pub_r001346_9_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_8_2 + (pub_r001346_9_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_2_1 + (pub_r001346_1_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_2_2 + (pub_r001346_1_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((pub_r001346_12_1 * 2) + 35) & 63;
  int stage_v_185_2 = ((pub_r001346_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((stage_v_146_1 + (pub_r001346_2_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_146_2 + (pub_r001346_2_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_168_1 + (pub_r001346_0_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_168_2 + (pub_r001346_0_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((stage_v_80_1 + (pub_r001346_7_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_80_2 + (pub_r001346_7_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((stage_v_94_1 + (pub_r001346_8_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_94_2 + (pub_r001346_8_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_186_1 + (pub_r001346_16_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_186_2 + (pub_r001346_16_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((stage_v_127_1 + (pub_r001346_2_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_127_2 + (pub_r001346_2_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_2_1 + (pub_r001346_2_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_2_2 + (pub_r001346_2_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((pub_r001346_19_1 * 2) + 27) & 63;
  int stage_v_193_2 = ((pub_r001346_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_6_1 + (pub_r001346_17_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_6_2 + (pub_r001346_17_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_17_1 + (pub_r001346_10_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_17_2 + (pub_r001346_10_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_77_1 + (pub_r001346_0_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_77_2 + (pub_r001346_0_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((sec_r001346_11_1 + (pub_r001346_4_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((sec_r001346_11_2 + (pub_r001346_4_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_111_1 + (pub_r001346_7_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_111_2 + (pub_r001346_7_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_50_1 + (pub_r001346_8_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_50_2 + (pub_r001346_8_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_48_1 + (pub_r001346_18_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_48_2 + (pub_r001346_18_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((sec_r001346_10_1 + (pub_r001346_9_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((sec_r001346_10_2 + (pub_r001346_9_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_186_1 + (pub_r001346_10_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_186_2 + (pub_r001346_10_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((stage_v_132_1 + (pub_r001346_15_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_132_2 + (pub_r001346_15_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_43_1 + (pub_r001346_18_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_43_2 + (pub_r001346_18_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((helper_flow_6_1 + (pub_r001346_3_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((helper_flow_6_2 + (pub_r001346_3_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((stage_v_118_1 + (pub_r001346_17_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((stage_v_118_2 + (pub_r001346_17_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((stage_v_45_1 + (pub_r001346_12_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_45_2 + (pub_r001346_12_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_200_1 + (pub_r001346_15_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_200_2 + (pub_r001346_15_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_43_1 + (pub_r001346_3_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_43_2 + (pub_r001346_3_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((sec_r001346_10_1 + (pub_r001346_6_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((sec_r001346_10_2 + (pub_r001346_6_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((pub_r001346_18_1 * 2) + 37) & 63;
  int stage_v_211_2 = ((pub_r001346_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_81_1 + (pub_r001346_13_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_81_2 + (pub_r001346_13_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((sec_r001346_10_1 + (pub_r001346_1_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((sec_r001346_10_2 + (pub_r001346_1_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_50_1 + (pub_r001346_4_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_50_2 + (pub_r001346_4_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((pub_r001346_15_1 * 2) + 35) & 63;
  int stage_v_215_2 = ((pub_r001346_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((stage_v_168_1 + (pub_r001346_0_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_168_2 + (pub_r001346_0_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_103_1 + (pub_r001346_11_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_103_2 + (pub_r001346_11_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((pub_r001346_11_1 * 2) + 42) & 63;
  int stage_v_218_2 = ((pub_r001346_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001346_14_1 * 2) + 36) & 63;
  int stage_v_219_2 = ((pub_r001346_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((sec_r001346_7_1 + (pub_r001346_4_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((sec_r001346_7_2 + (pub_r001346_4_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((pub_r001346_7_1 * 2) + 23) & 63;
  int stage_v_221_2 = ((pub_r001346_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((stage_v_216_1 + (pub_r001346_14_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_216_2 + (pub_r001346_14_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_132_1 + (pub_r001346_18_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_132_2 + (pub_r001346_18_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((stage_v_29_1 + (pub_r001346_6_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_29_2 + (pub_r001346_6_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((stage_v_111_1 + (pub_r001346_17_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_111_2 + (pub_r001346_17_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((stage_v_94_1 + (pub_r001346_5_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((stage_v_94_2 + (pub_r001346_5_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((pub_r001346_18_1 * 2) + 16) & 63;
  int stage_v_227_2 = ((pub_r001346_18_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((stage_v_59_1 + (pub_r001346_9_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((stage_v_59_2 + (pub_r001346_9_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((stage_v_168_1 + (pub_r001346_15_1 * 2)) + 692) & 127;
  int stage_v_229_2 = ((stage_v_168_2 + (pub_r001346_15_2 * 2)) + 692) & 127;
  if (stage_v_229_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_229_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_229_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_229_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_230_1 = ((stage_v_150_1 + (pub_r001346_1_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_150_2 + (pub_r001346_1_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((stage_v_213_1 + (pub_r001346_10_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_213_2 + (pub_r001346_10_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((pub_r001346_10_1 * 2) + 39) & 63;
  int stage_v_232_2 = ((pub_r001346_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001346_6_1 * 2) + 21) & 63;
  int stage_v_233_2 = ((pub_r001346_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((stage_v_36_1 + (pub_r001346_6_1 * 2)) + 707) & 127;
  int stage_v_234_2 = ((stage_v_36_2 + (pub_r001346_6_2 * 2)) + 707) & 127;
  if (stage_v_234_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_234_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_234_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_234_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_235_1 = ((helper_flow_0_1 + (pub_r001346_7_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((helper_flow_0_2 + (pub_r001346_7_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((stage_v_224_1 + (pub_r001346_4_1 * 2)) + 713) & 127;
  int stage_v_236_2 = ((stage_v_224_2 + (pub_r001346_4_2 * 2)) + 713) & 127;
  if (stage_v_236_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_236_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_236_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_236_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001346_8_1 != sec_r001346_8_2);
  __CPROVER_assume(pub_r001346_14_1 == pub_r001346_14_2);
  __CPROVER_assume(pub_r001346_16_1 == pub_r001346_16_2);
  __CPROVER_assume(pub_r001346_9_1 == pub_r001346_9_2);
  __CPROVER_assume(pub_r001346_1_1 == pub_r001346_1_2);
  __CPROVER_assume(sec_r001346_18_1 != sec_r001346_18_2);
  __CPROVER_assume(pub_r001346_12_1 == pub_r001346_12_2);
  __CPROVER_assume(sec_r001346_15_1 != sec_r001346_15_2);
  __CPROVER_assume(pub_r001346_0_1 == pub_r001346_0_2);
  __CPROVER_assume(pub_r001346_4_1 == pub_r001346_4_2);
  __CPROVER_assume(sec_r001346_4_1 != sec_r001346_4_2);
  __CPROVER_assume(sec_r001346_10_1 != sec_r001346_10_2);
  __CPROVER_assume(sec_r001346_6_1 != sec_r001346_6_2);
  __CPROVER_assume(sec_r001346_16_1 != sec_r001346_16_2);
  __CPROVER_assume(sec_r001346_13_1 != sec_r001346_13_2);
  __CPROVER_assume(pub_r001346_10_1 == pub_r001346_10_2);
  __CPROVER_assume(pub_r001346_6_1 == pub_r001346_6_2);
  __CPROVER_assume(sec_r001346_12_1 != sec_r001346_12_2);
  __CPROVER_assume(pub_r001346_15_1 == pub_r001346_15_2);
  __CPROVER_assume(sec_r001346_2_1 != sec_r001346_2_2);
  __CPROVER_assume(sec_r001346_1_1 != sec_r001346_1_2);
  __CPROVER_assume(sec_r001346_17_1 != sec_r001346_17_2);
  __CPROVER_assume(pub_r001346_7_1 == pub_r001346_7_2);
  __CPROVER_assume(sec_r001346_0_1 != sec_r001346_0_2);
  __CPROVER_assume(pub_r001346_17_1 == pub_r001346_17_2);
  __CPROVER_assume(pub_r001346_19_1 == pub_r001346_19_2);
  __CPROVER_assume(sec_r001346_11_1 != sec_r001346_11_2);
  __CPROVER_assume(pub_r001346_11_1 == pub_r001346_11_2);
  __CPROVER_assume(sec_r001346_3_1 != sec_r001346_3_2);
  __CPROVER_assume(pub_r001346_18_1 == pub_r001346_18_2);
  __CPROVER_assume(pub_r001346_5_1 == pub_r001346_5_2);
  __CPROVER_assume(sec_r001346_9_1 != sec_r001346_9_2);
  __CPROVER_assume(sec_r001346_14_1 != sec_r001346_14_2);
  __CPROVER_assume(sec_r001346_5_1 != sec_r001346_5_2);
  __CPROVER_assume(pub_r001346_2_1 == pub_r001346_2_2);
  __CPROVER_assume(pub_r001346_3_1 == pub_r001346_3_2);
  __CPROVER_assume(pub_r001346_13_1 == pub_r001346_13_2);
  __CPROVER_assume(pub_r001346_8_1 == pub_r001346_8_2);
  __CPROVER_assume(sec_r001346_7_1 != sec_r001346_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.rms == st_var_1_2.rms);
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
}


