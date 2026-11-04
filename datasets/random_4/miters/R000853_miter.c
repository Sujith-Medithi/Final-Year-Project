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
struct StreamBuffer_R000853_5313_0
{
  short checksum;
  unsigned char watermark;
  unsigned char head;
  int buffer[3];
};
struct FilterState_R000853_5313_1
{
  int cutoff;
  unsigned char prev_in;
  int gain_db;
  int mode;
  unsigned char prev_out;
  int buffer[3];
};
union ColorPixel_R000853_5313_0
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
void fn_R000853_5313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int index_reg_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_11_1) & 63;
  aux_2 = (aux_2 + index_reg_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_71_1)
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

  switch (mask_71_2)
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
  int index_reg_14_1 = local_arr_1[aux_1 % 3];
  int index_reg_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_14_2 * 2)) & 127;
  int coefficient_22_1 = 0;
  int coefficient_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_22_1 = ((coefficient_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_22_2 = ((coefficient_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_22_1) & 127;
    acc_2 = (acc_2 + coefficient_22_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_11_1 == index_reg_11_2);
  assert(mask_71_1 == mask_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_14_1 == index_reg_14_2);
  assert(coefficient_22_1 == coefficient_22_2);
}

int fn_R000853_5313_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int index_reg_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_11) & 63;
  acc ^= aux;
  int mask_71 = (aux + st.buffer[1]) & 3;
  switch (mask_71)
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
  int index_reg_14 = local_arr[aux % 3];
  acc = (acc + (index_reg_14 * 2)) & 127;
  int coefficient_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_22 = ((coefficient_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_22) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000853_5313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st_1 = {0};
  struct FilterState_R000853_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int coefficient_17_1 = 0;
  int coefficient_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_17_1 = ((coefficient_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_17_2 = ((coefficient_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_17_1) & 127;
    acc_2 = (acc_2 + coefficient_17_2) & 127;
  }

  int scale_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_14_1 > 41)
  {
    acc_1 = ((acc_1 + (scale_14_1 * 2)) + 5) & 127;
    aux_1 ^= scale_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_14_2 > 41)
  {
    acc_2 = ((acc_2 + (scale_14_2 * 2)) + 5) & 127;
    aux_2 ^= scale_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_17_1 == coefficient_17_2);
  assert(scale_14_1 == scale_14_2);
}

int fn_R000853_5313_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int coefficient_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_17 = ((coefficient_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_17) & 127;
  }

  int scale_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_14 > 41)
  {
    acc = ((acc + (scale_14 * 2)) + 5) & 127;
    aux ^= scale_14 & 15;
  }
  else
  {
    acc = ((acc - scale_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000853_5313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st_1 = {0};
  struct FilterState_R000853_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_41_1) & 63;
  aux_2 = (aux_2 + anchor_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_92_1 = local_arr_1[aux_1 % 3];
  int sample_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_41_1 == anchor_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_92_1 == sample_92_2);
}

int fn_R000853_5313_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_92 = local_arr[aux % 3];
  acc = (acc + (sample_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000853_5313_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st_1 = {0};
  struct FilterState_R000853_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_23_1 = local_arr_1[aux_1 % 3];
  int coefficient_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_23_2 * 2)) & 127;
  int margin_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_70_1 > 26)
  {
    acc_1 = ((acc_1 + (margin_70_1 * 2)) + 5) & 127;
    aux_1 ^= margin_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_70_2 > 26)
  {
    acc_2 = ((acc_2 + (margin_70_2 * 2)) + 5) & 127;
    aux_2 ^= margin_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_23_1 == coefficient_23_2);
  assert(margin_70_1 == margin_70_2);
}

int fn_R000853_5313_3(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int coefficient_23 = local_arr[aux % 3];
  acc = (acc + (coefficient_23 * 2)) & 127;
  int margin_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_70 > 26)
  {
    acc = ((acc + (margin_70 * 2)) + 5) & 127;
    aux ^= margin_70 & 15;
  }
  else
  {
    acc = ((acc - margin_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000853_5313_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st_1 = {0};
  struct FilterState_R000853_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int segment_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_17_1) & 63;
  aux_2 = (aux_2 + segment_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_29_1)
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

  switch (cursor_29_2)
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

  int cursor_40_1 = 0;
  int cursor_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_40_1 = ((cursor_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_40_2 = ((cursor_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_40_1) & 127;
    acc_2 = (acc_2 + cursor_40_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_12_1 = local_arr_1[aux_1 % 3];
  int phase_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_17_1 == segment_17_2);
  assert(cursor_29_1 == cursor_29_2);
  assert(cursor_40_1 == cursor_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_12_1 == phase_12_2);
}

int fn_R000853_5313_4(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int segment_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_17) & 63;
  acc ^= aux;
  int cursor_29 = (aux + st.buffer[1]) & 3;
  switch (cursor_29)
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

  int cursor_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_40 = ((cursor_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_40) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_12 = local_arr[aux % 3];
  acc = (acc + (phase_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000853_5313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quotient_53_1 = 0;
  int quotient_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_53_1 = ((quotient_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_53_2 = ((quotient_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_53_1) & 127;
    acc_2 = (acc_2 + quotient_53_2) & 127;
  }

  int quotient_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_42_1)
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

  switch (quotient_42_2)
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

  int weight_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_42_1 > 20)
  {
    acc_1 = ((acc_1 + (weight_42_1 * 2)) + 5) & 127;
    aux_1 ^= weight_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_42_2 > 20)
  {
    acc_2 = ((acc_2 + (weight_42_2 * 2)) + 5) & 127;
    aux_2 ^= weight_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_53_1 == quotient_53_2);
  assert(quotient_42_1 == quotient_42_2);
  assert(weight_42_1 == weight_42_2);
}

int fn_R000853_5313_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quotient_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_53 = ((quotient_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_53) & 127;
  }

  int quotient_42 = (aux + st.buffer[1]) & 3;
  switch (quotient_42)
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

  int weight_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_42 > 20)
  {
    acc = ((acc + (weight_42 * 2)) + 5) & 127;
    aux ^= weight_42 & 15;
  }
  else
  {
    acc = ((acc - weight_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000853_5313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st_1 = {0};
  struct FilterState_R000853_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int threshold_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_45_1)
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

  switch (threshold_45_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_92_1 > 42)
  {
    acc_1 = ((acc_1 + (scale_92_1 * 2)) + 5) & 127;
    aux_1 ^= scale_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_92_2 > 42)
  {
    acc_2 = ((acc_2 + (scale_92_2 * 2)) + 5) & 127;
    aux_2 ^= scale_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_45_1 == threshold_45_2);
  assert(scale_92_1 == scale_92_2);
}

int fn_R000853_5313_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int threshold_45 = (aux + st.buffer[1]) & 3;
  switch (threshold_45)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_92 > 42)
  {
    acc = ((acc + (scale_92 * 2)) + 5) & 127;
    aux ^= scale_92 & 15;
  }
  else
  {
    acc = ((acc - scale_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000853_5313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st_1 = {0};
  struct FilterState_R000853_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int residue_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_48_1 > 36)
  {
    acc_1 = ((acc_1 + (residue_48_1 * 2)) + 5) & 127;
    aux_1 ^= residue_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_48_2 > 36)
  {
    acc_2 = ((acc_2 + (residue_48_2 * 2)) + 5) & 127;
    aux_2 ^= residue_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_66_1 = 0;
  int damping_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_66_1 = ((damping_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_66_2 = ((damping_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_66_1) & 127;
    acc_2 = (acc_2 + damping_66_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_48_1 == residue_48_2);
  assert(damping_66_1 == damping_66_2);
}

int fn_R000853_5313_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int residue_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_48 > 36)
  {
    acc = ((acc + (residue_48 * 2)) + 5) & 127;
    aux ^= residue_48 & 15;
  }
  else
  {
    acc = ((acc - residue_48) + 11) & 127;
    aux += 3;
  }
  int damping_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_66 = ((damping_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_66) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000853_5313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st_1 = {0};
  struct FilterState_R000853_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int checksum_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_53_1) & 63;
  aux_2 = (aux_2 + checksum_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_64_1)
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

  switch (parity_64_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_53_1 == checksum_53_2);
  assert(parity_64_1 == parity_64_2);
}

int fn_R000853_5313_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int checksum_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_53) & 63;
  acc ^= aux;
  int parity_64 = (aux + st.buffer[1]) & 3;
  switch (parity_64)
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

void fn_R000853_5313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int anchor_76_1 = 0;
  int anchor_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_76_1 = ((anchor_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_76_2 = ((anchor_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_76_1) & 127;
    acc_2 = (acc_2 + anchor_76_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_24_1 = local_arr_1[aux_1 % 3];
  int damping_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_24_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_76_1 == anchor_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_24_1 == damping_24_2);
}

int fn_R000853_5313_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int anchor_76 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_76 = ((anchor_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_76) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_24 = local_arr[aux % 3];
  acc = (acc + (damping_24 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000853_5313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_45_1 = local_arr_1[aux_1 % 3];
  int stride_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_45_2 * 2)) & 127;
  int sample_15_1 = 0;
  int sample_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_15_1 = ((sample_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_15_2 = ((sample_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_15_1) & 127;
    acc_2 = (acc_2 + sample_15_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_45_1 == stride_45_2);
  assert(sample_15_1 == sample_15_2);
}

int fn_R000853_5313_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int stride_45 = local_arr[aux % 3];
  acc = (acc + (stride_45 * 2)) & 127;
  int sample_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_15 = ((sample_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_15) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000853_5313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_73_1 = local_arr_1[aux_1 % 3];
  int pivot_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_73_1 == pivot_73_2);
}

int fn_R000853_5313_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_73 = local_arr[aux % 3];
  acc = (acc + (pivot_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000853_5313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
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
  int bound_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_92_1 > 48)
  {
    acc_1 = ((acc_1 + (bound_92_1 * 2)) + 5) & 127;
    aux_1 ^= bound_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_92_2 > 48)
  {
    acc_2 = ((acc_2 + (bound_92_2 * 2)) + 5) & 127;
    aux_2 ^= bound_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_20_1)
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

  switch (margin_20_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_92_1 == bound_92_2);
  assert(margin_20_1 == margin_20_2);
}

int fn_R000853_5313_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_92 > 48)
  {
    acc = ((acc + (bound_92 * 2)) + 5) & 127;
    aux ^= bound_92 & 15;
  }
  else
  {
    acc = ((acc - bound_92) + 11) & 127;
    aux += 3;
  }
  int margin_20 = (aux + st.buffer[1]) & 3;
  switch (margin_20)
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

void fn_R000853_5313_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_32_1) & 63;
  aux_2 = (aux_2 + phase_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_11_1)
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

  switch (pivot_11_2)
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
  int tracker_58_1 = local_arr_1[aux_1 % 3];
  int tracker_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_32_1 == phase_32_2);
  assert(pivot_11_1 == pivot_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_58_1 == tracker_58_2);
}

int fn_R000853_5313_13(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_32) & 63;
  acc ^= aux;
  int pivot_11 = (aux + st.buffer[1]) & 3;
  switch (pivot_11)
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
  int tracker_58 = local_arr[aux % 3];
  acc = (acc + (tracker_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000853_5313_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int tally_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_95_1 > 33)
  {
    acc_1 = ((acc_1 + (tally_95_1 * 2)) + 5) & 127;
    aux_1 ^= tally_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_95_2 > 33)
  {
    acc_2 = ((acc_2 + (tally_95_2 * 2)) + 5) & 127;
    aux_2 ^= tally_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_95_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_35_1 = local_arr_1[aux_1 % 3];
  int scale_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_95_1 == tally_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_35_1 == scale_35_2);
}

int fn_R000853_5313_14(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int tally_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_95 > 33)
  {
    acc = ((acc + (tally_95 * 2)) + 5) & 127;
    aux ^= tally_95 & 15;
  }
  else
  {
    acc = ((acc - tally_95) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_35 = local_arr[aux % 3];
  acc = (acc + (scale_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000853_5313_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quotient_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_52_1)
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

  switch (quotient_52_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_66_1 > 45)
  {
    acc_1 = ((acc_1 + (accumulator_66_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_66_2 > 45)
  {
    acc_2 = ((acc_2 + (accumulator_66_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_52_1 == quotient_52_2);
  assert(accumulator_66_1 == accumulator_66_2);
}

int fn_R000853_5313_15(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quotient_52 = (aux + st.buffer[1]) & 3;
  switch (quotient_52)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_66 > 45)
  {
    acc = ((acc + (accumulator_66 * 2)) + 5) & 127;
    aux ^= accumulator_66 & 15;
  }
  else
  {
    acc = ((acc - accumulator_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000853_5313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int window_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_68_1 > 19)
  {
    acc_1 = ((acc_1 + (window_68_1 * 2)) + 5) & 127;
    aux_1 ^= window_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_68_2 > 19)
  {
    acc_2 = ((acc_2 + (window_68_2 * 2)) + 5) & 127;
    aux_2 ^= window_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_63_1)
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

  switch (anchor_63_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_68_1 == window_68_2);
  assert(anchor_63_1 == anchor_63_2);
}

int fn_R000853_5313_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int window_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_68 > 19)
  {
    acc = ((acc + (window_68 * 2)) + 5) & 127;
    aux ^= window_68 & 15;
  }
  else
  {
    acc = ((acc - window_68) + 11) & 127;
    aux += 3;
  }
  int anchor_63 = (aux + st.buffer[1]) & 3;
  switch (anchor_63)
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

void fn_R000853_5313_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int vector_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_24_1 > 17)
  {
    acc_1 = ((acc_1 + (vector_24_1 * 2)) + 5) & 127;
    aux_1 ^= vector_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_24_2 > 17)
  {
    acc_2 = ((acc_2 + (vector_24_2 * 2)) + 5) & 127;
    aux_2 ^= vector_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_57_1)
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

  switch (phase_57_2)
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

  int coefficient_80_1 = 0;
  int coefficient_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_80_1 = ((coefficient_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_80_2 = ((coefficient_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_80_1) & 127;
    acc_2 = (acc_2 + coefficient_80_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_24_1 == vector_24_2);
  assert(phase_57_1 == phase_57_2);
  assert(coefficient_80_1 == coefficient_80_2);
}

int fn_R000853_5313_17(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int vector_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_24 > 17)
  {
    acc = ((acc + (vector_24 * 2)) + 5) & 127;
    aux ^= vector_24 & 15;
  }
  else
  {
    acc = ((acc - vector_24) + 11) & 127;
    aux += 3;
  }
  int phase_57 = (aux + st.buffer[1]) & 3;
  switch (phase_57)
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

  int coefficient_80 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_80 = ((coefficient_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_80) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000853_5313_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int metric_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_96_1 > 21)
  {
    acc_1 = ((acc_1 + (metric_96_1 * 2)) + 5) & 127;
    aux_1 ^= metric_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_96_2 > 21)
  {
    acc_2 = ((acc_2 + (metric_96_2 * 2)) + 5) & 127;
    aux_2 ^= metric_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_68_1 = local_arr_1[aux_1 % 3];
  int window_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_68_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_52_1)
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

  switch (threshold_52_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_96_1 == metric_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_68_1 == window_68_2);
  assert(threshold_52_1 == threshold_52_2);
}

int fn_R000853_5313_18(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int metric_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_96 > 21)
  {
    acc = ((acc + (metric_96 * 2)) + 5) & 127;
    aux ^= metric_96 & 15;
  }
  else
  {
    acc = ((acc - metric_96) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_68 = local_arr[aux % 3];
  acc = (acc + (window_68 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_52 = (aux + st.buffer[1]) & 3;
  switch (threshold_52)
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

void fn_R000853_5313_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st_1 = {0};
  struct FilterState_R000853_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_17_1 = local_arr_1[aux_1 % 3];
  int quotient_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_17_2 * 2)) & 127;
  int scale_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_45_1) & 63;
  aux_2 = (aux_2 + scale_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_17_1 == quotient_17_2);
  assert(scale_45_1 == scale_45_2);
}

int fn_R000853_5313_19(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_17 = local_arr[aux % 3];
  acc = (acc + (quotient_17 * 2)) & 127;
  int scale_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000853_5313_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st_1 = {0};
  struct FilterState_R000853_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_57_1 = local_arr_1[aux_1 % 3];
  int mask_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_57_2 * 2)) & 127;
  int metric_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_50_1 > 37)
  {
    acc_1 = ((acc_1 + (metric_50_1 * 2)) + 5) & 127;
    aux_1 ^= metric_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_50_2 > 37)
  {
    acc_2 = ((acc_2 + (metric_50_2 * 2)) + 5) & 127;
    aux_2 ^= metric_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_45_1 = 0;
  int factor_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_45_1 = ((factor_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_45_2 = ((factor_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_45_1) & 127;
    acc_2 = (acc_2 + factor_45_2) & 127;
  }

  int damping_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_52_1) & 63;
  aux_2 = (aux_2 + damping_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_57_1 == mask_57_2);
  assert(metric_50_1 == metric_50_2);
  assert(factor_45_1 == factor_45_2);
  assert(damping_52_1 == damping_52_2);
}

int fn_R000853_5313_20(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int mask_57 = local_arr[aux % 3];
  acc = (acc + (mask_57 * 2)) & 127;
  int metric_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_50 > 37)
  {
    acc = ((acc + (metric_50 * 2)) + 5) & 127;
    aux ^= metric_50 & 15;
  }
  else
  {
    acc = ((acc - metric_50) + 11) & 127;
    aux += 3;
  }
  int factor_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_45 = ((factor_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_45) & 127;
  }

  int damping_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000853_5313_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_65_1) & 63;
  aux_2 = (aux_2 + stride_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_65_1 == stride_65_2);
}

int fn_R000853_5313_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000853_5313_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st_1 = {0};
  struct FilterState_R000853_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_51_1)
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

  switch (parity_51_2)
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

  int sample_74_1 = 0;
  int sample_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_74_1 = ((sample_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_74_2 = ((sample_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_74_1) & 127;
    acc_2 = (acc_2 + sample_74_2) & 127;
  }

  int residue_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_93_1 > 48)
  {
    acc_1 = ((acc_1 + (residue_93_1 * 2)) + 5) & 127;
    aux_1 ^= residue_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_93_2 > 48)
  {
    acc_2 = ((acc_2 + (residue_93_2 * 2)) + 5) & 127;
    aux_2 ^= residue_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_51_1 == parity_51_2);
  assert(sample_74_1 == sample_74_2);
  assert(residue_93_1 == residue_93_2);
}

int fn_R000853_5313_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000853_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_51 = (aux + st.buffer[1]) & 3;
  switch (parity_51)
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

  int sample_74 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_74 = ((sample_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_74) & 127;
  }

  int residue_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_93 > 48)
  {
    acc = ((acc + (residue_93 * 2)) + 5) & 127;
    aux ^= residue_93 & 15;
  }
  else
  {
    acc = ((acc - residue_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000853_5313_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_86_1 = 0;
  int margin_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_86_1 = ((margin_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_86_2 = ((margin_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_86_1) & 127;
    acc_2 = (acc_2 + margin_86_2) & 127;
  }

  int damping_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_15_1 > 37)
  {
    acc_1 = ((acc_1 + (damping_15_1 * 2)) + 5) & 127;
    aux_1 ^= damping_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_15_2 > 37)
  {
    acc_2 = ((acc_2 + (damping_15_2 * 2)) + 5) & 127;
    aux_2 ^= damping_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_32_1 = local_arr_1[aux_1 % 3];
  int cursor_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_86_1 == margin_86_2);
  assert(damping_15_1 == damping_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_32_1 == cursor_32_2);
}

int fn_R000853_5313_23(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_86 = ((margin_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_86) & 127;
  }

  int damping_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_15 > 37)
  {
    acc = ((acc + (damping_15 * 2)) + 5) & 127;
    aux ^= damping_15 & 15;
  }
  else
  {
    acc = ((acc - damping_15) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_32 = local_arr[aux % 3];
  acc = (acc + (cursor_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000853_5313_24_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_46_1 = local_arr_1[aux_1 % 3];
  int damping_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_46_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_46_1 == damping_46_2);
}

int fn_R000853_5313_24(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000853_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int damping_46 = local_arr[aux % 3];
  acc = (acc + (damping_46 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000853_0_1;
  int sec_r000853_0_2;
  int sec_r000853_1_1;
  int sec_r000853_1_2;
  int sec_r000853_2_1;
  int sec_r000853_2_2;
  int sec_r000853_3_1;
  int sec_r000853_3_2;
  int sec_r000853_4_1;
  int sec_r000853_4_2;
  int sec_r000853_5_1;
  int sec_r000853_5_2;
  int sec_r000853_6_1;
  int sec_r000853_6_2;
  int sec_r000853_7_1;
  int sec_r000853_7_2;
  int sec_r000853_8_1;
  int sec_r000853_8_2;
  int sec_r000853_9_1;
  int sec_r000853_9_2;
  int sec_r000853_10_1;
  int sec_r000853_10_2;
  int sec_r000853_11_1;
  int sec_r000853_11_2;
  int sec_r000853_12_1;
  int sec_r000853_12_2;
  int sec_r000853_13_1;
  int sec_r000853_13_2;
  int sec_r000853_14_1;
  int sec_r000853_14_2;
  int sec_r000853_15_1;
  int sec_r000853_15_2;
  int sec_r000853_16_1;
  int sec_r000853_16_2;
  int sec_r000853_17_1;
  int sec_r000853_17_2;
  int sec_r000853_18_1;
  int sec_r000853_18_2;
  int sec_r000853_19_1;
  int sec_r000853_19_2;
  int sec_r000853_20_1;
  int sec_r000853_20_2;
  int sec_r000853_21_1;
  int sec_r000853_21_2;
  int pub_r000853_0_1;
  int pub_r000853_0_2;
  int pub_r000853_1_1;
  int pub_r000853_1_2;
  int pub_r000853_2_1;
  int pub_r000853_2_2;
  int pub_r000853_3_1;
  int pub_r000853_3_2;
  int pub_r000853_4_1;
  int pub_r000853_4_2;
  int pub_r000853_5_1;
  int pub_r000853_5_2;
  int pub_r000853_6_1;
  int pub_r000853_6_2;
  int pub_r000853_7_1;
  int pub_r000853_7_2;
  int pub_r000853_8_1;
  int pub_r000853_8_2;
  int pub_r000853_9_1;
  int pub_r000853_9_2;
  int pub_r000853_10_1;
  int pub_r000853_10_2;
  int pub_r000853_11_1;
  int pub_r000853_11_2;
  int pub_r000853_12_1;
  int pub_r000853_12_2;
  int pub_r000853_13_1;
  int pub_r000853_13_2;
  int pub_r000853_14_1;
  int pub_r000853_14_2;
  int pub_r000853_15_1;
  int pub_r000853_15_2;
  int pub_r000853_16_1;
  int pub_r000853_16_2;
  int pub_r000853_17_1;
  int pub_r000853_17_2;
  int pub_r000853_18_1;
  int pub_r000853_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000853_0_1 >= (-100)) && (pub_r000853_0_1 <= 100));
  __CPROVER_assume((pub_r000853_0_2 >= (-100)) && (pub_r000853_0_2 <= 100));
  __CPROVER_assume((pub_r000853_1_1 >= (-100)) && (pub_r000853_1_1 <= 100));
  __CPROVER_assume((pub_r000853_1_2 >= (-100)) && (pub_r000853_1_2 <= 100));
  __CPROVER_assume((pub_r000853_2_1 >= (-100)) && (pub_r000853_2_1 <= 100));
  __CPROVER_assume((pub_r000853_2_2 >= (-100)) && (pub_r000853_2_2 <= 100));
  __CPROVER_assume((pub_r000853_3_1 >= (-100)) && (pub_r000853_3_1 <= 100));
  __CPROVER_assume((pub_r000853_3_2 >= (-100)) && (pub_r000853_3_2 <= 100));
  __CPROVER_assume((pub_r000853_4_1 >= (-100)) && (pub_r000853_4_1 <= 100));
  __CPROVER_assume((pub_r000853_4_2 >= (-100)) && (pub_r000853_4_2 <= 100));
  __CPROVER_assume((pub_r000853_5_1 >= (-100)) && (pub_r000853_5_1 <= 100));
  __CPROVER_assume((pub_r000853_5_2 >= (-100)) && (pub_r000853_5_2 <= 100));
  __CPROVER_assume((pub_r000853_6_1 >= (-100)) && (pub_r000853_6_1 <= 100));
  __CPROVER_assume((pub_r000853_6_2 >= (-100)) && (pub_r000853_6_2 <= 100));
  __CPROVER_assume((pub_r000853_7_1 >= (-100)) && (pub_r000853_7_1 <= 100));
  __CPROVER_assume((pub_r000853_7_2 >= (-100)) && (pub_r000853_7_2 <= 100));
  __CPROVER_assume((pub_r000853_8_1 >= (-100)) && (pub_r000853_8_1 <= 100));
  __CPROVER_assume((pub_r000853_8_2 >= (-100)) && (pub_r000853_8_2 <= 100));
  __CPROVER_assume((pub_r000853_9_1 >= (-100)) && (pub_r000853_9_1 <= 100));
  __CPROVER_assume((pub_r000853_9_2 >= (-100)) && (pub_r000853_9_2 <= 100));
  __CPROVER_assume((pub_r000853_10_1 >= (-100)) && (pub_r000853_10_1 <= 100));
  __CPROVER_assume((pub_r000853_10_2 >= (-100)) && (pub_r000853_10_2 <= 100));
  __CPROVER_assume((pub_r000853_11_1 >= (-100)) && (pub_r000853_11_1 <= 100));
  __CPROVER_assume((pub_r000853_11_2 >= (-100)) && (pub_r000853_11_2 <= 100));
  __CPROVER_assume((pub_r000853_12_1 >= (-100)) && (pub_r000853_12_1 <= 100));
  __CPROVER_assume((pub_r000853_12_2 >= (-100)) && (pub_r000853_12_2 <= 100));
  __CPROVER_assume((pub_r000853_13_1 >= (-100)) && (pub_r000853_13_1 <= 100));
  __CPROVER_assume((pub_r000853_13_2 >= (-100)) && (pub_r000853_13_2 <= 100));
  __CPROVER_assume((pub_r000853_14_1 >= (-100)) && (pub_r000853_14_1 <= 100));
  __CPROVER_assume((pub_r000853_14_2 >= (-100)) && (pub_r000853_14_2 <= 100));
  __CPROVER_assume((pub_r000853_15_1 >= (-100)) && (pub_r000853_15_1 <= 100));
  __CPROVER_assume((pub_r000853_15_2 >= (-100)) && (pub_r000853_15_2 <= 100));
  __CPROVER_assume((pub_r000853_16_1 >= (-100)) && (pub_r000853_16_1 <= 100));
  __CPROVER_assume((pub_r000853_16_2 >= (-100)) && (pub_r000853_16_2 <= 100));
  __CPROVER_assume((pub_r000853_17_1 >= (-100)) && (pub_r000853_17_1 <= 100));
  __CPROVER_assume((pub_r000853_17_2 >= (-100)) && (pub_r000853_17_2 <= 100));
  __CPROVER_assume((pub_r000853_18_1 >= (-100)) && (pub_r000853_18_1 <= 100));
  __CPROVER_assume((pub_r000853_18_2 >= (-100)) && (pub_r000853_18_2 <= 100));
  __CPROVER_assume((sec_r000853_0_1 >= 0) && (sec_r000853_0_1 <= 255));
  __CPROVER_assume((sec_r000853_0_2 >= 0) && (sec_r000853_0_2 <= 255));
  __CPROVER_assume((sec_r000853_1_1 >= 0) && (sec_r000853_1_1 <= 255));
  __CPROVER_assume((sec_r000853_1_2 >= 0) && (sec_r000853_1_2 <= 255));
  __CPROVER_assume((sec_r000853_2_1 >= 0) && (sec_r000853_2_1 <= 255));
  __CPROVER_assume((sec_r000853_2_2 >= 0) && (sec_r000853_2_2 <= 255));
  __CPROVER_assume((sec_r000853_3_1 >= 0) && (sec_r000853_3_1 <= 255));
  __CPROVER_assume((sec_r000853_3_2 >= 0) && (sec_r000853_3_2 <= 255));
  __CPROVER_assume((sec_r000853_4_1 >= 0) && (sec_r000853_4_1 <= 255));
  __CPROVER_assume((sec_r000853_4_2 >= 0) && (sec_r000853_4_2 <= 255));
  __CPROVER_assume((sec_r000853_5_1 >= 0) && (sec_r000853_5_1 <= 255));
  __CPROVER_assume((sec_r000853_5_2 >= 0) && (sec_r000853_5_2 <= 255));
  __CPROVER_assume((sec_r000853_6_1 >= 0) && (sec_r000853_6_1 <= 255));
  __CPROVER_assume((sec_r000853_6_2 >= 0) && (sec_r000853_6_2 <= 255));
  __CPROVER_assume((sec_r000853_7_1 >= 0) && (sec_r000853_7_1 <= 255));
  __CPROVER_assume((sec_r000853_7_2 >= 0) && (sec_r000853_7_2 <= 255));
  __CPROVER_assume((sec_r000853_8_1 >= 0) && (sec_r000853_8_1 <= 255));
  __CPROVER_assume((sec_r000853_8_2 >= 0) && (sec_r000853_8_2 <= 255));
  __CPROVER_assume((sec_r000853_9_1 >= 0) && (sec_r000853_9_1 <= 255));
  __CPROVER_assume((sec_r000853_9_2 >= 0) && (sec_r000853_9_2 <= 255));
  __CPROVER_assume((sec_r000853_10_1 >= 0) && (sec_r000853_10_1 <= 255));
  __CPROVER_assume((sec_r000853_10_2 >= 0) && (sec_r000853_10_2 <= 255));
  __CPROVER_assume((sec_r000853_11_1 >= 0) && (sec_r000853_11_1 <= 255));
  __CPROVER_assume((sec_r000853_11_2 >= 0) && (sec_r000853_11_2 <= 255));
  __CPROVER_assume((sec_r000853_12_1 >= 0) && (sec_r000853_12_1 <= 255));
  __CPROVER_assume((sec_r000853_12_2 >= 0) && (sec_r000853_12_2 <= 255));
  __CPROVER_assume((sec_r000853_13_1 >= 0) && (sec_r000853_13_1 <= 255));
  __CPROVER_assume((sec_r000853_13_2 >= 0) && (sec_r000853_13_2 <= 255));
  __CPROVER_assume((sec_r000853_14_1 >= 0) && (sec_r000853_14_1 <= 255));
  __CPROVER_assume((sec_r000853_14_2 >= 0) && (sec_r000853_14_2 <= 255));
  __CPROVER_assume((sec_r000853_15_1 >= 0) && (sec_r000853_15_1 <= 255));
  __CPROVER_assume((sec_r000853_15_2 >= 0) && (sec_r000853_15_2 <= 255));
  __CPROVER_assume((sec_r000853_16_1 >= 0) && (sec_r000853_16_1 <= 255));
  __CPROVER_assume((sec_r000853_16_2 >= 0) && (sec_r000853_16_2 <= 255));
  __CPROVER_assume((sec_r000853_17_1 >= 0) && (sec_r000853_17_1 <= 255));
  __CPROVER_assume((sec_r000853_17_2 >= 0) && (sec_r000853_17_2 <= 255));
  __CPROVER_assume((sec_r000853_18_1 >= 0) && (sec_r000853_18_1 <= 255));
  __CPROVER_assume((sec_r000853_18_2 >= 0) && (sec_r000853_18_2 <= 255));
  __CPROVER_assume((sec_r000853_19_1 >= 0) && (sec_r000853_19_1 <= 255));
  __CPROVER_assume((sec_r000853_19_2 >= 0) && (sec_r000853_19_2 <= 255));
  __CPROVER_assume((sec_r000853_20_1 >= 0) && (sec_r000853_20_1 <= 255));
  __CPROVER_assume((sec_r000853_20_2 >= 0) && (sec_r000853_20_2 <= 255));
  __CPROVER_assume((sec_r000853_21_1 >= 0) && (sec_r000853_21_1 <= 255));
  __CPROVER_assume((sec_r000853_21_2 >= 0) && (sec_r000853_21_2 <= 255));
  struct StreamBuffer_R000853_5313_0 st_var_0_1 = {0};
  struct StreamBuffer_R000853_5313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000853_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000853_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000853_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000853_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000853_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000853_0_2 + 7) & 15;
  struct FilterState_R000853_5313_1 st_var_1_1 = {0};
  struct FilterState_R000853_5313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000853_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000853_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000853_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000853_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000853_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000853_0_2 + 9) & 15;
  union ColorPixel_R000853_5313_0 u_var_1;
  union ColorPixel_R000853_5313_0 u_var_2;
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
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 44)
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
  if (stage_v_1_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 44)
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
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
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
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = ((st_var_0_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_0_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 41)
    {
      chk_sum_1 ^= stage_v_10_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_10_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 41)
    {
      chk_sum_2 ^= stage_v_10_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 16) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_1_2.buffer[0] * 3) & 63;
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
  int stage_v_17_1 = (st_var_1_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_1_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 24) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 34) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = ((st_var_0_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_0_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 26)
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
  if (stage_v_34_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 26)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 49)
    {
      chk_sum_1 ^= stage_v_40_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_40_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 49)
    {
      chk_sum_2 ^= stage_v_40_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 44)
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
  if (stage_v_42_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 44)
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
  int stage_v_44_1 = table_1[0];
  int stage_v_44_2 = table_2[0];
  table_1[0] = (table_1[1] + 89) & 63;
  table_2[0] = (table_2[1] + 89) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = (st_var_1_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_1_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 40)
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
  if (stage_v_49_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 40)
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
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (st_var_1_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_1_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_55_1 = (st_var_1_1.buffer[0] ^ 58) & 3;
  int stage_v_55_2 = (st_var_1_2.buffer[0] ^ 58) & 3;
  switch (stage_v_55_1)
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

  switch (stage_v_55_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 57) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  int stage_v_57_1 = ((st_var_1_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_1_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 33)
    {
      chk_sum_1 ^= stage_v_57_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_57_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 33)
    {
      chk_sum_2 ^= stage_v_57_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_58_1 = (st_var_0_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_0_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 28)
    {
      chk_sum_1 ^= stage_v_61_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_61_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 28)
    {
      chk_sum_2 ^= stage_v_61_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_62_1 = ((stage_v_62_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_62_2 = ((stage_v_62_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((st_var_1_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_1_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 28)
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
  if (stage_v_63_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 28)
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
  int stage_v_64_1 = ((st_var_0_1.buffer[1] * 2) + 199) & 63;
  int stage_v_64_2 = ((st_var_0_2.buffer[1] * 2) + 199) & 63;
  if (stage_v_64_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_64_1) - 5) & 255;
    if (stage_v_64_1 > 46)
    {
      chk_sum_1 ^= stage_v_64_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_64_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_64_2) - 5) & 255;
    if (stage_v_64_2 > 46)
    {
      chk_sum_2 ^= stage_v_64_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_65_1 = (st_var_1_1.buffer[0] ^ 68) & 3;
  int stage_v_65_2 = (st_var_1_2.buffer[0] ^ 68) & 3;
  switch (stage_v_65_1)
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

  switch (stage_v_65_2)
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

  int stage_v_66_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_66_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_67_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (72 & 31);
  int stage_v_67_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (72 & 31);
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= (stage_v_67_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_67_2 << 1) & 127;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (st_var_1_1.buffer[0] ^ 72) & 3;
  int stage_v_69_2 = (st_var_1_2.buffer[0] ^ 72) & 3;
  switch (stage_v_69_1)
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

  switch (stage_v_69_2)
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

  int stage_v_70_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_70_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 73) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 73) & 15;
  int stage_v_72_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_72_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= stage_v_72_1;
  chk_sum_2 ^= stage_v_72_2;
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (79 & 31);
  int stage_v_74_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (79 & 31);
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= (stage_v_74_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_74_2 << 1) & 127;
  int stage_v_75_1 = ((st_var_1_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_1_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 27)
    {
      chk_sum_1 ^= stage_v_75_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_75_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 27)
    {
      chk_sum_2 ^= stage_v_75_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_76_1 = (st_var_0_1.buffer[0] ^ 79) & 3;
  int stage_v_76_2 = (st_var_0_2.buffer[0] ^ 79) & 3;
  switch (stage_v_76_1)
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

  switch (stage_v_76_2)
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

  int stage_v_77_1 = table_1[1];
  int stage_v_77_2 = table_2[1];
  table_1[1] = (table_1[2] + 155) & 63;
  table_2[1] = (table_2[2] + 155) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_78_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_79_1 = (st_var_1_1.buffer[0] ^ 82) & 3;
  int stage_v_79_2 = (st_var_1_2.buffer[0] ^ 82) & 3;
  switch (stage_v_79_1)
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

  switch (stage_v_79_2)
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

  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
  int stage_v_81_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_81_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((st_var_1_1.buffer[2] * 2) + 256) & 63;
  int stage_v_83_2 = ((st_var_1_2.buffer[2] * 2) + 256) & 63;
  if (stage_v_83_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_83_1) - 5) & 255;
    if (stage_v_83_1 > 43)
    {
      chk_sum_1 ^= stage_v_83_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_83_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_83_2) - 5) & 255;
    if (stage_v_83_2 > 43)
    {
      chk_sum_2 ^= stage_v_83_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_84_1 = table_1[0];
  int stage_v_84_2 = table_2[0];
  table_1[0] = (table_1[1] + 169) & 63;
  table_2[0] = (table_2[1] + 169) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (90 & 31);
  int stage_v_85_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (90 & 31);
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= (stage_v_85_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_85_2 << 1) & 127;
  int stage_v_86_1 = ((st_var_0_1.buffer[2] * 2) + 265) & 63;
  int stage_v_86_2 = ((st_var_0_2.buffer[2] * 2) + 265) & 63;
  if (stage_v_86_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_86_1) - 5) & 255;
    if (stage_v_86_1 > 26)
    {
      chk_sum_1 ^= stage_v_86_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_86_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_86_2) - 5) & 255;
    if (stage_v_86_2 > 26)
    {
      chk_sum_2 ^= stage_v_86_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 89) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 89) & 15;
  int stage_v_88_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_88_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= stage_v_88_1;
  chk_sum_2 ^= stage_v_88_2;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (95 & 31);
  int stage_v_90_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (95 & 31);
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= (stage_v_90_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_90_2 << 1) & 127;
  int stage_v_91_1 = ((st_var_1_1.buffer[1] * 2) + 280) & 63;
  int stage_v_91_2 = ((st_var_1_2.buffer[1] * 2) + 280) & 63;
  if (stage_v_91_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_91_1) - 5) & 255;
    if (stage_v_91_1 > 26)
    {
      chk_sum_1 ^= stage_v_91_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_91_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_91_2) - 5) & 255;
    if (stage_v_91_2 > 26)
    {
      chk_sum_2 ^= stage_v_91_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_93_1 = ((stage_v_93_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_93_2 = ((stage_v_93_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (100 & 31);
  int stage_v_95_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (100 & 31);
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= (stage_v_95_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_95_2 << 1) & 127;
  int stage_v_96_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (101 & 31);
  int stage_v_96_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (101 & 31);
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= (stage_v_96_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_96_2 << 1) & 127;
  int stage_v_97_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (102 & 31);
  int stage_v_97_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (102 & 31);
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= (stage_v_97_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_97_2 << 1) & 127;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = table_1[3];
  int stage_v_99_2 = table_2[3];
  table_1[3] = (table_1[0] + 199) & 63;
  table_2[3] = (table_2[0] + 199) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (105 & 31);
  int stage_v_100_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (105 & 31);
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= (stage_v_100_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_100_2 << 1) & 127;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_101_1 = ((stage_v_101_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_101_2 = ((stage_v_101_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (107 & 31);
  int stage_v_102_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (107 & 31);
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= (stage_v_102_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_102_2 << 1) & 127;
  int stage_v_103_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (108 & 31);
  int stage_v_103_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (108 & 31);
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= (stage_v_103_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_103_2 << 1) & 127;
  int stage_v_104_1 = (st_var_0_1.buffer[0] ^ 107) & 3;
  int stage_v_104_2 = (st_var_0_2.buffer[0] ^ 107) & 3;
  switch (stage_v_104_1)
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

  switch (stage_v_104_2)
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

  int stage_v_105_1 = table_1[1];
  int stage_v_105_2 = table_2[1];
  table_1[1] = (table_1[2] + 211) & 63;
  table_2[1] = (table_2[2] + 211) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = table_1[2];
  int stage_v_106_2 = table_2[2];
  table_1[2] = (table_1[3] + 213) & 63;
  table_2[2] = (table_2[3] + 213) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((st_var_1_1.buffer[2] * 2) + 328) & 63;
  int stage_v_107_2 = ((st_var_1_2.buffer[2] * 2) + 328) & 63;
  if (stage_v_107_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_107_1) - 5) & 255;
    if (stage_v_107_1 > 55)
    {
      chk_sum_1 ^= stage_v_107_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_107_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_107_2) - 5) & 255;
    if (stage_v_107_2 > 55)
    {
      chk_sum_2 ^= stage_v_107_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_110_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_110_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_110_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_110_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_111_1 = (st_var_1_1.buffer[0] ^ 114) & 3;
  int stage_v_111_2 = (st_var_1_2.buffer[0] ^ 114) & 3;
  switch (stage_v_111_1)
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

  switch (stage_v_111_2)
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

  int stage_v_112_1 = ((st_var_0_1.buffer[1] * 2) + 343) & 63;
  int stage_v_112_2 = ((st_var_0_2.buffer[1] * 2) + 343) & 63;
  if (stage_v_112_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_112_1) - 5) & 255;
    if (stage_v_112_1 > 30)
    {
      chk_sum_1 ^= stage_v_112_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_112_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_112_2) - 5) & 255;
    if (stage_v_112_2 > 30)
    {
      chk_sum_2 ^= stage_v_112_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_113_1 = ((st_var_1_1.buffer[2] * 2) + 346) & 63;
  int stage_v_113_2 = ((st_var_1_2.buffer[2] * 2) + 346) & 63;
  if (stage_v_113_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_113_1) - 5) & 255;
    if (stage_v_113_1 > 36)
    {
      chk_sum_1 ^= stage_v_113_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_113_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_113_2) - 5) & 255;
    if (stage_v_113_2 > 36)
    {
      chk_sum_2 ^= stage_v_113_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_114_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_114_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_114_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_114_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_116_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_117_1 = (st_var_1_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_1_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_119_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_119_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_119_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_120_1 = table_1[0];
  int stage_v_120_2 = table_2[0];
  table_1[0] = (table_1[1] + 241) & 63;
  table_2[0] = (table_2[1] + 241) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (126 & 31);
  int stage_v_121_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (126 & 31);
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  chk_sum_1 ^= (stage_v_121_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_121_2 << 1) & 127;
  int stage_v_122_1 = table_1[2];
  int stage_v_122_2 = table_2[2];
  table_1[2] = (table_1[3] + 245) & 63;
  table_2[2] = (table_2[3] + 245) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (st_var_1_1.buffer[0] ^ 126) & 3;
  int stage_v_123_2 = (st_var_1_2.buffer[0] ^ 126) & 3;
  switch (stage_v_123_1)
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

  switch (stage_v_123_2)
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

  int stage_v_124_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (129 & 31);
  int stage_v_124_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (129 & 31);
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= (stage_v_124_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_124_2 << 1) & 127;
  int stage_v_125_1 = (st_var_1_1.buffer[0] ^ 128) & 3;
  int stage_v_125_2 = (st_var_1_2.buffer[0] ^ 128) & 3;
  switch (stage_v_125_1)
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

  switch (stage_v_125_2)
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

  int stage_v_126_1 = table_1[2];
  int stage_v_126_2 = table_2[2];
  table_1[2] = (table_1[3] + 253) & 63;
  table_2[2] = (table_2[3] + 253) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 129) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 129) & 15;
  int stage_v_128_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_128_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  chk_sum_1 ^= stage_v_128_1;
  chk_sum_2 ^= stage_v_128_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 130) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 130) & 15;
  int stage_v_129_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_129_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  chk_sum_1 ^= stage_v_129_1;
  chk_sum_2 ^= stage_v_129_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 131) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 131) & 15;
  int stage_v_130_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_130_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= stage_v_130_1;
  chk_sum_2 ^= stage_v_130_2;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_132_1 = ((stage_v_132_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_132_2 = ((stage_v_132_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (138 & 31);
  int stage_v_133_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (138 & 31);
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= (stage_v_133_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_133_2 << 1) & 127;
  int stage_v_134_1 = table_1[2];
  int stage_v_134_2 = table_2[2];
  table_1[2] = (table_1[3] + 269) & 63;
  table_2[2] = (table_2[3] + 269) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((st_var_1_1.buffer[0] * 2) + 412) & 63;
  int stage_v_135_2 = ((st_var_1_2.buffer[0] * 2) + 412) & 63;
  if (stage_v_135_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_135_1) - 5) & 255;
    if (stage_v_135_1 > 54)
    {
      chk_sum_1 ^= stage_v_135_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_135_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_135_2) - 5) & 255;
    if (stage_v_135_2 > 54)
    {
      chk_sum_2 ^= stage_v_135_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_136_1 = table_1[0];
  int stage_v_136_2 = table_2[0];
  table_1[0] = (table_1[1] + 273) & 63;
  table_2[0] = (table_2[1] + 273) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_137_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_138_1 = (st_var_0_1.buffer[0] ^ 141) & 3;
  int stage_v_138_2 = (st_var_0_2.buffer[0] ^ 141) & 3;
  switch (stage_v_138_1)
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

  switch (stage_v_138_2)
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

  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_139_1 = ((stage_v_139_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_139_2 = ((stage_v_139_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (st_var_0_1.buffer[0] ^ 143) & 3;
  int stage_v_140_2 = (st_var_0_2.buffer[0] ^ 143) & 3;
  switch (stage_v_140_1)
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

  switch (stage_v_140_2)
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

  int stage_v_141_1 = table_1[1];
  int stage_v_141_2 = table_2[1];
  table_1[1] = (table_1[2] + 283) & 63;
  table_2[1] = (table_2[2] + 283) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_142_1 = ((stage_v_142_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_142_2 = ((stage_v_142_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (st_var_1_1.buffer[0] ^ 146) & 3;
  int stage_v_143_2 = (st_var_1_2.buffer[0] ^ 146) & 3;
  switch (stage_v_143_1)
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

  switch (stage_v_143_2)
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

  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (st_var_1_1.buffer[0] ^ 148) & 3;
  int stage_v_145_2 = (st_var_1_2.buffer[0] ^ 148) & 3;
  switch (stage_v_145_1)
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

  switch (stage_v_145_2)
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

  int stage_v_146_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (151 & 31);
  int stage_v_146_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (151 & 31);
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= (stage_v_146_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_146_2 << 1) & 127;
  int stage_v_147_1 = ((st_var_1_1.buffer[0] * 2) + 448) & 63;
  int stage_v_147_2 = ((st_var_1_2.buffer[0] * 2) + 448) & 63;
  if (stage_v_147_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_147_1) - 5) & 255;
    if (stage_v_147_1 > 39)
    {
      chk_sum_1 ^= stage_v_147_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_147_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_147_2) - 5) & 255;
    if (stage_v_147_2 > 39)
    {
      chk_sum_2 ^= stage_v_147_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_148_1 = (st_var_0_1.buffer[0] ^ 151) & 3;
  int stage_v_148_2 = (st_var_0_2.buffer[0] ^ 151) & 3;
  switch (stage_v_148_1)
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

  switch (stage_v_148_2)
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

  int stage_v_149_1 = (st_var_1_1.buffer[0] ^ 152) & 3;
  int stage_v_149_2 = (st_var_1_2.buffer[0] ^ 152) & 3;
  switch (stage_v_149_1)
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

  switch (stage_v_149_2)
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

  int stage_v_150_1 = ((st_var_0_1.buffer[0] * 2) + 457) & 63;
  int stage_v_150_2 = ((st_var_0_2.buffer[0] * 2) + 457) & 63;
  if (stage_v_150_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_150_1) - 5) & 255;
    if (stage_v_150_1 > 29)
    {
      chk_sum_1 ^= stage_v_150_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_150_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_150_2) - 5) & 255;
    if (stage_v_150_2 > 29)
    {
      chk_sum_2 ^= stage_v_150_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_151_1 = (st_var_1_1.buffer[0] ^ 154) & 3;
  int stage_v_151_2 = (st_var_1_2.buffer[0] ^ 154) & 3;
  switch (stage_v_151_1)
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

  switch (stage_v_151_2)
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

  int s_lut_1[4] = {93, 85, 41, 75};
  int s_lut_2[4] = {93, 85, 41, 75};
  int s_idx_1 = sec_r000853_19_1 & 3;
  int s_idx_2 = sec_r000853_19_2 & 3;
  out_sink_1 += s_lut_1[s_idx_1];
  out_sink_2 += s_lut_2[s_idx_2];
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000853_7_1 != sec_r000853_7_2);
  __CPROVER_assume(pub_r000853_8_1 == pub_r000853_8_2);
  __CPROVER_assume(pub_r000853_14_1 == pub_r000853_14_2);
  __CPROVER_assume(pub_r000853_18_1 == pub_r000853_18_2);
  __CPROVER_assume(pub_r000853_1_1 == pub_r000853_1_2);
  __CPROVER_assume(sec_r000853_18_1 != sec_r000853_18_2);
  __CPROVER_assume(pub_r000853_0_1 == pub_r000853_0_2);
  __CPROVER_assume(pub_r000853_13_1 == pub_r000853_13_2);
  __CPROVER_assume(sec_r000853_8_1 != sec_r000853_8_2);
  __CPROVER_assume(pub_r000853_6_1 == pub_r000853_6_2);
  __CPROVER_assume(sec_r000853_4_1 != sec_r000853_4_2);
  __CPROVER_assume(sec_r000853_20_1 != sec_r000853_20_2);
  __CPROVER_assume(sec_r000853_21_1 != sec_r000853_21_2);
  __CPROVER_assume(pub_r000853_4_1 == pub_r000853_4_2);
  __CPROVER_assume(pub_r000853_7_1 == pub_r000853_7_2);
  __CPROVER_assume(pub_r000853_9_1 == pub_r000853_9_2);
  __CPROVER_assume(sec_r000853_16_1 != sec_r000853_16_2);
  __CPROVER_assume(pub_r000853_17_1 == pub_r000853_17_2);
  __CPROVER_assume(sec_r000853_17_1 != sec_r000853_17_2);
  __CPROVER_assume(pub_r000853_2_1 == pub_r000853_2_2);
  __CPROVER_assume(sec_r000853_9_1 != sec_r000853_9_2);
  __CPROVER_assume(pub_r000853_5_1 == pub_r000853_5_2);
  __CPROVER_assume(pub_r000853_12_1 == pub_r000853_12_2);
  __CPROVER_assume(sec_r000853_3_1 != sec_r000853_3_2);
  __CPROVER_assume(sec_r000853_10_1 != sec_r000853_10_2);
  __CPROVER_assume(sec_r000853_12_1 != sec_r000853_12_2);
  __CPROVER_assume(pub_r000853_11_1 == pub_r000853_11_2);
  __CPROVER_assume(sec_r000853_15_1 != sec_r000853_15_2);
  __CPROVER_assume(sec_r000853_6_1 != sec_r000853_6_2);
  __CPROVER_assume(sec_r000853_1_1 != sec_r000853_1_2);
  __CPROVER_assume(sec_r000853_13_1 != sec_r000853_13_2);
  __CPROVER_assume(sec_r000853_5_1 != sec_r000853_5_2);
  __CPROVER_assume(pub_r000853_15_1 == pub_r000853_15_2);
  __CPROVER_assume(sec_r000853_0_1 != sec_r000853_0_2);
  __CPROVER_assume(sec_r000853_19_1 != sec_r000853_19_2);
  __CPROVER_assume(sec_r000853_2_1 != sec_r000853_2_2);
  __CPROVER_assume(sec_r000853_11_1 != sec_r000853_11_2);
  __CPROVER_assume(pub_r000853_10_1 == pub_r000853_10_2);
  __CPROVER_assume(pub_r000853_16_1 == pub_r000853_16_2);
  __CPROVER_assume(sec_r000853_14_1 != sec_r000853_14_2);
  __CPROVER_assume(pub_r000853_3_1 == pub_r000853_3_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.head == st_var_0_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
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
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(s_lut_1[i_0] == s_lut_2[i_0]);
  }

  assert(s_idx_1 == s_idx_2);
}


