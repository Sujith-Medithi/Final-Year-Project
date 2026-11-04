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
struct MatrixBlock_R000940_4013_0
{
  unsigned char trace;
  unsigned char determinant;
  short stride;
  unsigned char dim;
  int buffer[3];
};
struct StreamBuffer_R000940_4013_1
{
  int watermark;
  int state;
  unsigned char head;
  short capacity;
  short tail;
  int buffer[3];
};
union ColorPixel_R000940_4013_0
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
void fn_R000940_4013_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int index_reg_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_71_1 > 12)
  {
    acc_1 = ((acc_1 + (index_reg_71_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_71_2 > 12)
  {
    acc_2 = ((acc_2 + (index_reg_71_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_71_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_42_1)
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

  switch (phase_42_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_71_1 == index_reg_71_2);
  assert(phase_42_1 == phase_42_2);
}

int fn_R000940_4013_0(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int index_reg_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_71 > 12)
  {
    acc = ((acc + (index_reg_71 * 2)) + 5) & 127;
    aux ^= index_reg_71 & 15;
  }
  else
  {
    acc = ((acc - index_reg_71) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_42 = (aux + st.buffer[1]) & 3;
  switch (phase_42)
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

void fn_R000940_4013_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st_1 = {0};
  struct StreamBuffer_R000940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int parity_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_92_1)
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

  switch (parity_92_2)
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
  int weight_36_1 = local_arr_1[aux_1 % 3];
  int weight_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_92_1 == parity_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_36_1 == weight_36_2);
}

int fn_R000940_4013_1(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int parity_92 = (aux + st.buffer[1]) & 3;
  switch (parity_92)
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
  int weight_36 = local_arr[aux % 3];
  acc = (acc + (weight_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000940_4013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_29_1 = local_arr_1[aux_1 % 3];
  int phase_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_29_2 * 2)) & 127;
  int sample_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_42_1) & 63;
  aux_2 = (aux_2 + sample_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_45_1 = 0;
  int weight_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_45_1 = ((weight_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_45_2 = ((weight_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_45_1) & 127;
    acc_2 = (acc_2 + weight_45_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_29_1 == phase_29_2);
  assert(sample_42_1 == sample_42_2);
  assert(weight_45_1 == weight_45_2);
}

int fn_R000940_4013_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int phase_29 = local_arr[aux % 3];
  acc = (acc + (phase_29 * 2)) & 127;
  int sample_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_42) & 63;
  acc ^= aux;
  int weight_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_45 = ((weight_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_45) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000940_4013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st_1 = {0};
  struct StreamBuffer_R000940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int offset_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_66_1)
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

  switch (offset_66_2)
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

  int mask_97_1 = 0;
  int mask_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_97_1 = ((mask_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_97_2 = ((mask_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_97_1) & 127;
    acc_2 = (acc_2 + mask_97_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_70_1 = local_arr_1[aux_1 % 3];
  int mask_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_66_1 == offset_66_2);
  assert(mask_97_1 == mask_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_70_1 == mask_70_2);
}

int fn_R000940_4013_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int offset_66 = (aux + st.buffer[1]) & 3;
  switch (offset_66)
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

  int mask_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_97 = ((mask_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_97) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_70 = local_arr[aux % 3];
  acc = (acc + (mask_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000940_4013_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int weight_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_14_1 > 42)
  {
    acc_1 = ((acc_1 + (weight_14_1 * 2)) + 5) & 127;
    aux_1 ^= weight_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_14_2 > 42)
  {
    acc_2 = ((acc_2 + (weight_14_2 * 2)) + 5) & 127;
    aux_2 ^= weight_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_61_1 = local_arr_1[aux_1 % 3];
  int stride_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_61_2 * 2)) & 127;
  int segment_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_18_1)
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

  switch (segment_18_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_14_1 == weight_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_61_1 == stride_61_2);
  assert(segment_18_1 == segment_18_2);
}

int fn_R000940_4013_4(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int weight_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_14 > 42)
  {
    acc = ((acc + (weight_14 * 2)) + 5) & 127;
    aux ^= weight_14 & 15;
  }
  else
  {
    acc = ((acc - weight_14) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_61 = local_arr[aux % 3];
  acc = (acc + (stride_61 * 2)) & 127;
  int segment_18 = (aux + st.buffer[1]) & 3;
  switch (segment_18)
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

void fn_R000940_4013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int factor_35_1 = 0;
  int factor_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_35_1 = ((factor_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_35_2 = ((factor_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_35_1) & 127;
    acc_2 = (acc_2 + factor_35_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_24_1 = local_arr_1[aux_1 % 3];
  int stride_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_24_2 * 2)) & 127;
  int quotient_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_22_1)
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

  switch (quotient_22_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_35_1 == factor_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_24_1 == stride_24_2);
  assert(quotient_22_1 == quotient_22_2);
}

int fn_R000940_4013_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int factor_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_35 = ((factor_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_35) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int stride_24 = local_arr[aux % 3];
  acc = (acc + (stride_24 * 2)) & 127;
  int quotient_22 = (aux + st.buffer[1]) & 3;
  switch (quotient_22)
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

void fn_R000940_4013_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_89_1 = local_arr_1[aux_1 % 3];
  int sample_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_89_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_11_1)
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

  switch (accumulator_11_2)
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

  int phase_50_1 = 0;
  int phase_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_50_1 = ((phase_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_50_2 = ((phase_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_50_1) & 127;
    acc_2 = (acc_2 + phase_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_89_1 == sample_89_2);
  assert(accumulator_11_1 == accumulator_11_2);
  assert(phase_50_1 == phase_50_2);
}

int fn_R000940_4013_6(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int sample_89 = local_arr[aux % 3];
  acc = (acc + (sample_89 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_11 = (aux + st.buffer[1]) & 3;
  switch (accumulator_11)
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

  int phase_50 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_50 = ((phase_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000940_4013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int vector_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_59_1)
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

  switch (vector_59_2)
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

  int tally_19_1 = 0;
  int tally_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_19_1 = ((tally_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_19_2 = ((tally_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_19_1) & 127;
    acc_2 = (acc_2 + tally_19_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_19_1 > 23)
  {
    acc_1 = ((acc_1 + (cursor_19_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_19_2 > 23)
  {
    acc_2 = ((acc_2 + (cursor_19_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_19_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_59_1 == vector_59_2);
  assert(tally_19_1 == tally_19_2);
  assert(cursor_19_1 == cursor_19_2);
}

int fn_R000940_4013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int vector_59 = (aux + st.buffer[1]) & 3;
  switch (vector_59)
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

  int tally_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_19 = ((tally_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_19) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_19 > 23)
  {
    acc = ((acc + (cursor_19 * 2)) + 5) & 127;
    aux ^= cursor_19 & 15;
  }
  else
  {
    acc = ((acc - cursor_19) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000940_4013_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int phase_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_47_1)
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

  switch (phase_47_2)
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

  int vector_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_29_1 > 22)
  {
    acc_1 = ((acc_1 + (vector_29_1 * 2)) + 5) & 127;
    aux_1 ^= vector_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_29_2 > 22)
  {
    acc_2 = ((acc_2 + (vector_29_2 * 2)) + 5) & 127;
    aux_2 ^= vector_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_18_1 = 0;
  int cursor_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_18_1 = ((cursor_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_18_2 = ((cursor_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_18_1) & 127;
    acc_2 = (acc_2 + cursor_18_2) & 127;
  }

  int margin_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_34_1) & 63;
  aux_2 = (aux_2 + margin_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_47_1 == phase_47_2);
  assert(vector_29_1 == vector_29_2);
  assert(cursor_18_1 == cursor_18_2);
  assert(margin_34_1 == margin_34_2);
}

int fn_R000940_4013_8(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int phase_47 = (aux + st.buffer[1]) & 3;
  switch (phase_47)
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

  int vector_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_29 > 22)
  {
    acc = ((acc + (vector_29 * 2)) + 5) & 127;
    aux ^= vector_29 & 15;
  }
  else
  {
    acc = ((acc - vector_29) + 11) & 127;
    aux += 3;
  }
  int cursor_18 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_18 = ((cursor_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_18) & 127;
  }

  int margin_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000940_4013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int vector_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_76_1) & 63;
  aux_2 = (aux_2 + vector_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_81_1 > 31)
  {
    acc_1 = ((acc_1 + (threshold_81_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_81_2 > 31)
  {
    acc_2 = ((acc_2 + (threshold_81_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_76_1 == vector_76_2);
  assert(threshold_81_1 == threshold_81_2);
}

int fn_R000940_4013_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int vector_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_76) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_81 > 31)
  {
    acc = ((acc + (threshold_81 * 2)) + 5) & 127;
    aux ^= threshold_81 & 15;
  }
  else
  {
    acc = ((acc - threshold_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000940_4013_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_35_1 = local_arr_1[aux_1 % 3];
  int cursor_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_35_2 * 2)) & 127;
  int pivot_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_73_1) & 63;
  aux_2 = (aux_2 + pivot_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_12_1)
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

  switch (stride_12_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_35_1 == cursor_35_2);
  assert(pivot_73_1 == pivot_73_2);
  assert(stride_12_1 == stride_12_2);
}

int fn_R000940_4013_10(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int cursor_35 = local_arr[aux % 3];
  acc = (acc + (cursor_35 * 2)) & 127;
  int pivot_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_73) & 63;
  acc ^= aux;
  int stride_12 = (aux + st.buffer[1]) & 3;
  switch (stride_12)
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

void fn_R000940_4013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int vector_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_95_1)
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

  switch (vector_95_2)
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

  int margin_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_92_1 > 34)
  {
    acc_1 = ((acc_1 + (margin_92_1 * 2)) + 5) & 127;
    aux_1 ^= margin_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_92_2 > 34)
  {
    acc_2 = ((acc_2 + (margin_92_2 * 2)) + 5) & 127;
    aux_2 ^= margin_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_32_1 = 0;
  int tracker_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_32_1 = ((tracker_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_32_2 = ((tracker_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_32_1) & 127;
    acc_2 = (acc_2 + tracker_32_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_95_1 == vector_95_2);
  assert(margin_92_1 == margin_92_2);
  assert(tracker_32_1 == tracker_32_2);
}

int fn_R000940_4013_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int vector_95 = (aux + st.buffer[1]) & 3;
  switch (vector_95)
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

  int margin_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_92 > 34)
  {
    acc = ((acc + (margin_92 * 2)) + 5) & 127;
    aux ^= margin_92 & 15;
  }
  else
  {
    acc = ((acc - margin_92) + 11) & 127;
    aux += 3;
  }
  int tracker_32 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_32 = ((tracker_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_32) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000940_4013_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_88_1 = local_arr_1[aux_1 % 3];
  int window_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_88_2 * 2)) & 127;
  int offset_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_94_1) & 63;
  aux_2 = (aux_2 + offset_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_40_1 = 0;
  int factor_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_40_1 = ((factor_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_40_2 = ((factor_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_40_1) & 127;
    acc_2 = (acc_2 + factor_40_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_88_1 == window_88_2);
  assert(offset_94_1 == offset_94_2);
  assert(factor_40_1 == factor_40_2);
}

int fn_R000940_4013_12(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int window_88 = local_arr[aux % 3];
  acc = (acc + (window_88 * 2)) & 127;
  int offset_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_94) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_40 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_40 = ((factor_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_40) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000940_4013_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st_1 = {0};
  struct StreamBuffer_R000940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_87_1 = local_arr_1[aux_1 % 3];
  int threshold_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_87_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_75_1 = 0;
  int vector_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_75_1 = ((vector_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_75_2 = ((vector_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_75_1) & 127;
    acc_2 = (acc_2 + vector_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_87_1 == threshold_87_2);
  assert(vector_75_1 == vector_75_2);
}

int fn_R000940_4013_13(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int threshold_87 = local_arr[aux % 3];
  acc = (acc + (threshold_87 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_75 = ((vector_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000940_4013_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int segment_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_43_1) & 63;
  aux_2 = (aux_2 + segment_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_98_1 > 10)
  {
    acc_1 = ((acc_1 + (residue_98_1 * 2)) + 5) & 127;
    aux_1 ^= residue_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_98_2 > 10)
  {
    acc_2 = ((acc_2 + (residue_98_2 * 2)) + 5) & 127;
    aux_2 ^= residue_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_94_1 = 0;
  int metric_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_94_1 = ((metric_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_94_2 = ((metric_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_94_1) & 127;
    acc_2 = (acc_2 + metric_94_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_43_1 == segment_43_2);
  assert(residue_98_1 == residue_98_2);
  assert(metric_94_1 == metric_94_2);
}

int fn_R000940_4013_14(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int segment_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_43) & 63;
  acc ^= aux;
  int residue_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_98 > 10)
  {
    acc = ((acc + (residue_98 * 2)) + 5) & 127;
    aux ^= residue_98 & 15;
  }
  else
  {
    acc = ((acc - residue_98) + 11) & 127;
    aux += 3;
  }
  int metric_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_94 = ((metric_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_94) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000940_4013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st_1 = {0};
  struct StreamBuffer_R000940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int factor_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_94_1)
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

  switch (factor_94_2)
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

  int tally_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_99_1 > 12)
  {
    acc_1 = ((acc_1 + (tally_99_1 * 2)) + 5) & 127;
    aux_1 ^= tally_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_99_2 > 12)
  {
    acc_2 = ((acc_2 + (tally_99_2 * 2)) + 5) & 127;
    aux_2 ^= tally_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_67_1) & 63;
  aux_2 = (aux_2 + residue_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_58_1 = local_arr_1[aux_1 % 3];
  int margin_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_94_1 == factor_94_2);
  assert(tally_99_1 == tally_99_2);
  assert(residue_67_1 == residue_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_58_1 == margin_58_2);
}

int fn_R000940_4013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int factor_94 = (aux + st.buffer[1]) & 3;
  switch (factor_94)
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

  int tally_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_99 > 12)
  {
    acc = ((acc + (tally_99 * 2)) + 5) & 127;
    aux ^= tally_99 & 15;
  }
  else
  {
    acc = ((acc - tally_99) + 11) & 127;
    aux += 3;
  }
  int residue_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_58 = local_arr[aux % 3];
  acc = (acc + (margin_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000940_4013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st_1 = {0};
  struct StreamBuffer_R000940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int segment_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_99_1) & 63;
  aux_2 = (aux_2 + segment_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_51_1 > 32)
  {
    acc_1 = ((acc_1 + (tracker_51_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_51_2 > 32)
  {
    acc_2 = ((acc_2 + (tracker_51_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_99_1 == segment_99_2);
  assert(tracker_51_1 == tracker_51_2);
}

int fn_R000940_4013_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int segment_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_99) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_51 > 32)
  {
    acc = ((acc + (tracker_51 * 2)) + 5) & 127;
    aux ^= tracker_51 & 15;
  }
  else
  {
    acc = ((acc - tracker_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000940_4013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st_1 = {0};
  struct StreamBuffer_R000940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_59_1 > 42)
  {
    acc_1 = ((acc_1 + (margin_59_1 * 2)) + 5) & 127;
    aux_1 ^= margin_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_59_2 > 42)
  {
    acc_2 = ((acc_2 + (margin_59_2 * 2)) + 5) & 127;
    aux_2 ^= margin_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_51_1 = 0;
  int quantum_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_51_1 = ((quantum_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_51_2 = ((quantum_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_51_1) & 127;
    acc_2 = (acc_2 + quantum_51_2) & 127;
  }

  int vector_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_60_1) & 63;
  aux_2 = (aux_2 + vector_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_59_1 == margin_59_2);
  assert(quantum_51_1 == quantum_51_2);
  assert(vector_60_1 == vector_60_2);
}

int fn_R000940_4013_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_59 > 42)
  {
    acc = ((acc + (margin_59 * 2)) + 5) & 127;
    aux ^= margin_59 & 15;
  }
  else
  {
    acc = ((acc - margin_59) + 11) & 127;
    aux += 3;
  }
  int quantum_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_51 = ((quantum_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_51) & 127;
  }

  int vector_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000940_4013_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_85_1) & 63;
  aux_2 = (aux_2 + margin_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_74_1 > 26)
  {
    acc_1 = ((acc_1 + (coefficient_74_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_74_2 > 26)
  {
    acc_2 = ((acc_2 + (coefficient_74_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_85_1 == margin_85_2);
  assert(coefficient_74_1 == coefficient_74_2);
}

int fn_R000940_4013_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_85) & 63;
  acc ^= aux;
  int coefficient_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_74 > 26)
  {
    acc = ((acc + (coefficient_74 * 2)) + 5) & 127;
    aux ^= coefficient_74 & 15;
  }
  else
  {
    acc = ((acc - coefficient_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000940_4013_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int factor_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_48_1) & 63;
  aux_2 = (aux_2 + factor_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_38_1)
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

  switch (sample_38_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_48_1 == factor_48_2);
  assert(sample_38_1 == sample_38_2);
}

int fn_R000940_4013_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int factor_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_48) & 63;
  acc ^= aux;
  int sample_38 = (aux + st.buffer[1]) & 3;
  switch (sample_38)
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

void fn_R000940_4013_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_53_1 = local_arr_1[aux_1 % 3];
  int weight_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_53_2 * 2)) & 127;
  int coefficient_97_1 = 0;
  int coefficient_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_97_1 = ((coefficient_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_97_2 = ((coefficient_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_97_1) & 127;
    acc_2 = (acc_2 + coefficient_97_2) & 127;
  }

  int offset_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_27_1)
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

  switch (offset_27_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_53_1 == weight_53_2);
  assert(coefficient_97_1 == coefficient_97_2);
  assert(offset_27_1 == offset_27_2);
}

int fn_R000940_4013_20(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_53 = local_arr[aux % 3];
  acc = (acc + (weight_53 * 2)) & 127;
  int coefficient_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_97 = ((coefficient_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_97) & 127;
  }

  int offset_27 = (aux + st.buffer[1]) & 3;
  switch (offset_27)
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

void fn_R000940_4013_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st_1 = {0};
  struct StreamBuffer_R000940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int pivot_53_1 = 0;
  int pivot_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_53_1 = ((pivot_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_53_2 = ((pivot_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_53_1) & 127;
    acc_2 = (acc_2 + pivot_53_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_66_1)
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

  switch (coefficient_66_2)
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

  int stride_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_53_1) & 63;
  aux_2 = (aux_2 + stride_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_53_1 == pivot_53_2);
  assert(coefficient_66_1 == coefficient_66_2);
  assert(stride_53_1 == stride_53_2);
}

int fn_R000940_4013_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int pivot_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_53 = ((pivot_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_53) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_66 = (aux + st.buffer[1]) & 3;
  switch (coefficient_66)
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

  int stride_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_53) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000940_4013_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st_1 = {0};
  struct StreamBuffer_R000940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_28_1 = local_arr_1[aux_1 % 3];
  int factor_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_28_2 * 2)) & 127;
  int pivot_97_1 = 0;
  int pivot_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_97_1 = ((pivot_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_97_2 = ((pivot_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_97_1) & 127;
    acc_2 = (acc_2 + pivot_97_2) & 127;
  }

  int window_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_65_1 > 39)
  {
    acc_1 = ((acc_1 + (window_65_1 * 2)) + 5) & 127;
    aux_1 ^= window_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_65_2 > 39)
  {
    acc_2 = ((acc_2 + (window_65_2 * 2)) + 5) & 127;
    aux_2 ^= window_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_28_1 == factor_28_2);
  assert(pivot_97_1 == pivot_97_2);
  assert(window_65_1 == window_65_2);
}

int fn_R000940_4013_22(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int factor_28 = local_arr[aux % 3];
  acc = (acc + (factor_28 * 2)) & 127;
  int pivot_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_97 = ((pivot_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_97) & 127;
  }

  int window_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_65 > 39)
  {
    acc = ((acc + (window_65 * 2)) + 5) & 127;
    aux ^= window_65 & 15;
  }
  else
  {
    acc = ((acc - window_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000940_4013_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st_1 = {0};
  struct StreamBuffer_R000940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int index_reg_43_1 = 0;
  int index_reg_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_43_1 = ((index_reg_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_43_2 = ((index_reg_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_43_1) & 127;
    acc_2 = (acc_2 + index_reg_43_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_43_1 == index_reg_43_2);
}

int fn_R000940_4013_23(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int index_reg_43 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_43 = ((index_reg_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_43) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000940_4013_24_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st_1 = {0};
  struct StreamBuffer_R000940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int stride_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_44_1 > 36)
  {
    acc_1 = ((acc_1 + (stride_44_1 * 2)) + 5) & 127;
    aux_1 ^= stride_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_44_2 > 36)
  {
    acc_2 = ((acc_2 + (stride_44_2 * 2)) + 5) & 127;
    aux_2 ^= stride_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_44_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_59_1 = 0;
  int segment_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_59_1 = ((segment_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_59_2 = ((segment_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_59_1) & 127;
    acc_2 = (acc_2 + segment_59_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_44_1 == stride_44_2);
  assert(segment_59_1 == segment_59_2);
}

int fn_R000940_4013_24(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int stride_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_44 > 36)
  {
    acc = ((acc + (stride_44 * 2)) + 5) & 127;
    aux ^= stride_44 & 15;
  }
  else
  {
    acc = ((acc - stride_44) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_59 = ((segment_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_59) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r000940_0_1;
  int sec_r000940_0_2;
  int sec_r000940_1_1;
  int sec_r000940_1_2;
  int sec_r000940_2_1;
  int sec_r000940_2_2;
  int sec_r000940_3_1;
  int sec_r000940_3_2;
  int sec_r000940_4_1;
  int sec_r000940_4_2;
  int sec_r000940_5_1;
  int sec_r000940_5_2;
  int sec_r000940_6_1;
  int sec_r000940_6_2;
  int sec_r000940_7_1;
  int sec_r000940_7_2;
  int sec_r000940_8_1;
  int sec_r000940_8_2;
  int sec_r000940_9_1;
  int sec_r000940_9_2;
  int sec_r000940_10_1;
  int sec_r000940_10_2;
  int sec_r000940_11_1;
  int sec_r000940_11_2;
  int sec_r000940_12_1;
  int sec_r000940_12_2;
  int sec_r000940_13_1;
  int sec_r000940_13_2;
  int sec_r000940_14_1;
  int sec_r000940_14_2;
  int sec_r000940_15_1;
  int sec_r000940_15_2;
  int sec_r000940_16_1;
  int sec_r000940_16_2;
  int sec_r000940_17_1;
  int sec_r000940_17_2;
  int sec_r000940_18_1;
  int sec_r000940_18_2;
  int sec_r000940_19_1;
  int sec_r000940_19_2;
  int sec_r000940_20_1;
  int sec_r000940_20_2;
  int pub_r000940_0_1;
  int pub_r000940_0_2;
  int pub_r000940_1_1;
  int pub_r000940_1_2;
  int pub_r000940_2_1;
  int pub_r000940_2_2;
  int pub_r000940_3_1;
  int pub_r000940_3_2;
  int pub_r000940_4_1;
  int pub_r000940_4_2;
  int pub_r000940_5_1;
  int pub_r000940_5_2;
  int pub_r000940_6_1;
  int pub_r000940_6_2;
  int pub_r000940_7_1;
  int pub_r000940_7_2;
  int pub_r000940_8_1;
  int pub_r000940_8_2;
  int pub_r000940_9_1;
  int pub_r000940_9_2;
  int pub_r000940_10_1;
  int pub_r000940_10_2;
  int pub_r000940_11_1;
  int pub_r000940_11_2;
  int pub_r000940_12_1;
  int pub_r000940_12_2;
  int pub_r000940_13_1;
  int pub_r000940_13_2;
  int pub_r000940_14_1;
  int pub_r000940_14_2;
  int pub_r000940_15_1;
  int pub_r000940_15_2;
  int pub_r000940_16_1;
  int pub_r000940_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000940_0_1 >= (-100)) && (pub_r000940_0_1 <= 100));
  __CPROVER_assume((pub_r000940_0_2 >= (-100)) && (pub_r000940_0_2 <= 100));
  __CPROVER_assume((pub_r000940_1_1 >= (-100)) && (pub_r000940_1_1 <= 100));
  __CPROVER_assume((pub_r000940_1_2 >= (-100)) && (pub_r000940_1_2 <= 100));
  __CPROVER_assume((pub_r000940_2_1 >= (-100)) && (pub_r000940_2_1 <= 100));
  __CPROVER_assume((pub_r000940_2_2 >= (-100)) && (pub_r000940_2_2 <= 100));
  __CPROVER_assume((pub_r000940_3_1 >= (-100)) && (pub_r000940_3_1 <= 100));
  __CPROVER_assume((pub_r000940_3_2 >= (-100)) && (pub_r000940_3_2 <= 100));
  __CPROVER_assume((pub_r000940_4_1 >= (-100)) && (pub_r000940_4_1 <= 100));
  __CPROVER_assume((pub_r000940_4_2 >= (-100)) && (pub_r000940_4_2 <= 100));
  __CPROVER_assume((pub_r000940_5_1 >= (-100)) && (pub_r000940_5_1 <= 100));
  __CPROVER_assume((pub_r000940_5_2 >= (-100)) && (pub_r000940_5_2 <= 100));
  __CPROVER_assume((pub_r000940_6_1 >= (-100)) && (pub_r000940_6_1 <= 100));
  __CPROVER_assume((pub_r000940_6_2 >= (-100)) && (pub_r000940_6_2 <= 100));
  __CPROVER_assume((pub_r000940_7_1 >= (-100)) && (pub_r000940_7_1 <= 100));
  __CPROVER_assume((pub_r000940_7_2 >= (-100)) && (pub_r000940_7_2 <= 100));
  __CPROVER_assume((pub_r000940_8_1 >= (-100)) && (pub_r000940_8_1 <= 100));
  __CPROVER_assume((pub_r000940_8_2 >= (-100)) && (pub_r000940_8_2 <= 100));
  __CPROVER_assume((pub_r000940_9_1 >= (-100)) && (pub_r000940_9_1 <= 100));
  __CPROVER_assume((pub_r000940_9_2 >= (-100)) && (pub_r000940_9_2 <= 100));
  __CPROVER_assume((pub_r000940_10_1 >= (-100)) && (pub_r000940_10_1 <= 100));
  __CPROVER_assume((pub_r000940_10_2 >= (-100)) && (pub_r000940_10_2 <= 100));
  __CPROVER_assume((pub_r000940_11_1 >= (-100)) && (pub_r000940_11_1 <= 100));
  __CPROVER_assume((pub_r000940_11_2 >= (-100)) && (pub_r000940_11_2 <= 100));
  __CPROVER_assume((pub_r000940_12_1 >= (-100)) && (pub_r000940_12_1 <= 100));
  __CPROVER_assume((pub_r000940_12_2 >= (-100)) && (pub_r000940_12_2 <= 100));
  __CPROVER_assume((pub_r000940_13_1 >= (-100)) && (pub_r000940_13_1 <= 100));
  __CPROVER_assume((pub_r000940_13_2 >= (-100)) && (pub_r000940_13_2 <= 100));
  __CPROVER_assume((pub_r000940_14_1 >= (-100)) && (pub_r000940_14_1 <= 100));
  __CPROVER_assume((pub_r000940_14_2 >= (-100)) && (pub_r000940_14_2 <= 100));
  __CPROVER_assume((pub_r000940_15_1 >= (-100)) && (pub_r000940_15_1 <= 100));
  __CPROVER_assume((pub_r000940_15_2 >= (-100)) && (pub_r000940_15_2 <= 100));
  __CPROVER_assume((pub_r000940_16_1 >= (-100)) && (pub_r000940_16_1 <= 100));
  __CPROVER_assume((pub_r000940_16_2 >= (-100)) && (pub_r000940_16_2 <= 100));
  __CPROVER_assume((sec_r000940_0_1 >= 0) && (sec_r000940_0_1 <= 255));
  __CPROVER_assume((sec_r000940_0_2 >= 0) && (sec_r000940_0_2 <= 255));
  __CPROVER_assume((sec_r000940_1_1 >= 0) && (sec_r000940_1_1 <= 255));
  __CPROVER_assume((sec_r000940_1_2 >= 0) && (sec_r000940_1_2 <= 255));
  __CPROVER_assume((sec_r000940_2_1 >= 0) && (sec_r000940_2_1 <= 255));
  __CPROVER_assume((sec_r000940_2_2 >= 0) && (sec_r000940_2_2 <= 255));
  __CPROVER_assume((sec_r000940_3_1 >= 0) && (sec_r000940_3_1 <= 255));
  __CPROVER_assume((sec_r000940_3_2 >= 0) && (sec_r000940_3_2 <= 255));
  __CPROVER_assume((sec_r000940_4_1 >= 0) && (sec_r000940_4_1 <= 255));
  __CPROVER_assume((sec_r000940_4_2 >= 0) && (sec_r000940_4_2 <= 255));
  __CPROVER_assume((sec_r000940_5_1 >= 0) && (sec_r000940_5_1 <= 255));
  __CPROVER_assume((sec_r000940_5_2 >= 0) && (sec_r000940_5_2 <= 255));
  __CPROVER_assume((sec_r000940_6_1 >= 0) && (sec_r000940_6_1 <= 255));
  __CPROVER_assume((sec_r000940_6_2 >= 0) && (sec_r000940_6_2 <= 255));
  __CPROVER_assume((sec_r000940_7_1 >= 0) && (sec_r000940_7_1 <= 255));
  __CPROVER_assume((sec_r000940_7_2 >= 0) && (sec_r000940_7_2 <= 255));
  __CPROVER_assume((sec_r000940_8_1 >= 0) && (sec_r000940_8_1 <= 255));
  __CPROVER_assume((sec_r000940_8_2 >= 0) && (sec_r000940_8_2 <= 255));
  __CPROVER_assume((sec_r000940_9_1 >= 0) && (sec_r000940_9_1 <= 255));
  __CPROVER_assume((sec_r000940_9_2 >= 0) && (sec_r000940_9_2 <= 255));
  __CPROVER_assume((sec_r000940_10_1 >= 0) && (sec_r000940_10_1 <= 255));
  __CPROVER_assume((sec_r000940_10_2 >= 0) && (sec_r000940_10_2 <= 255));
  __CPROVER_assume((sec_r000940_11_1 >= 0) && (sec_r000940_11_1 <= 255));
  __CPROVER_assume((sec_r000940_11_2 >= 0) && (sec_r000940_11_2 <= 255));
  __CPROVER_assume((sec_r000940_12_1 >= 0) && (sec_r000940_12_1 <= 255));
  __CPROVER_assume((sec_r000940_12_2 >= 0) && (sec_r000940_12_2 <= 255));
  __CPROVER_assume((sec_r000940_13_1 >= 0) && (sec_r000940_13_1 <= 255));
  __CPROVER_assume((sec_r000940_13_2 >= 0) && (sec_r000940_13_2 <= 255));
  __CPROVER_assume((sec_r000940_14_1 >= 0) && (sec_r000940_14_1 <= 255));
  __CPROVER_assume((sec_r000940_14_2 >= 0) && (sec_r000940_14_2 <= 255));
  __CPROVER_assume((sec_r000940_15_1 >= 0) && (sec_r000940_15_1 <= 255));
  __CPROVER_assume((sec_r000940_15_2 >= 0) && (sec_r000940_15_2 <= 255));
  __CPROVER_assume((sec_r000940_16_1 >= 0) && (sec_r000940_16_1 <= 255));
  __CPROVER_assume((sec_r000940_16_2 >= 0) && (sec_r000940_16_2 <= 255));
  __CPROVER_assume((sec_r000940_17_1 >= 0) && (sec_r000940_17_1 <= 255));
  __CPROVER_assume((sec_r000940_17_2 >= 0) && (sec_r000940_17_2 <= 255));
  __CPROVER_assume((sec_r000940_18_1 >= 0) && (sec_r000940_18_1 <= 255));
  __CPROVER_assume((sec_r000940_18_2 >= 0) && (sec_r000940_18_2 <= 255));
  __CPROVER_assume((sec_r000940_19_1 >= 0) && (sec_r000940_19_1 <= 255));
  __CPROVER_assume((sec_r000940_19_2 >= 0) && (sec_r000940_19_2 <= 255));
  __CPROVER_assume((sec_r000940_20_1 >= 0) && (sec_r000940_20_1 <= 255));
  __CPROVER_assume((sec_r000940_20_2 >= 0) && (sec_r000940_20_2 <= 255));
  struct MatrixBlock_R000940_4013_0 st_var_0_1 = {0};
  struct MatrixBlock_R000940_4013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000940_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000940_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000940_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000940_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000940_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000940_0_2 + 7) & 15;
  struct StreamBuffer_R000940_4013_1 st_var_1_1 = {0};
  struct StreamBuffer_R000940_4013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000940_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000940_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000940_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000940_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000940_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000940_0_2 + 9) & 15;
  union ColorPixel_R000940_4013_0 u_var_1;
  union ColorPixel_R000940_4013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 47)
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
  if (stage_v_0_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 47)
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
  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = ((st_var_1_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_1_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 55)
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
  if (stage_v_3_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 55)
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
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((st_var_1_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_1_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 36)
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
  if (stage_v_5_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 36)
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
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 27)
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
  if (stage_v_9_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 27)
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
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 15) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = ((st_var_1_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_1_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 36)
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
  if (stage_v_15_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 36)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 49)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 49)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = (st_var_0_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_0_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
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
  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 30) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 30) & 15;
  int stage_v_29_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_29_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= stage_v_29_1;
  chk_sum_2 ^= stage_v_29_2;
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
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
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
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 40) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 42)
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
  if (stage_v_40_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 42)
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
  if (stage_v_42_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 52)
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
  if (stage_v_42_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 52)
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
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = (st_var_0_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_0_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = table_1[3];
  int stage_v_47_2 = table_2[3];
  table_1[3] = (table_1[0] + 95) & 63;
  table_2[3] = (table_2[0] + 95) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
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

  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
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

  switch (stage_v_52_2)
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

  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 57) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = (st_var_1_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_1_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
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

  switch (stage_v_59_2)
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

  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (st_var_0_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_0_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
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
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_67_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_68_1 = ((st_var_0_1.buffer[2] * 2) + 211) & 63;
  int stage_v_68_2 = ((st_var_0_2.buffer[2] * 2) + 211) & 63;
  if (stage_v_68_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_68_1) - 5) & 255;
    if (stage_v_68_1 > 51)
    {
      chk_sum_1 ^= stage_v_68_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_68_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_68_2) - 5) & 255;
    if (stage_v_68_2 > 51)
    {
      chk_sum_2 ^= stage_v_68_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_69_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_69_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_70_1 = (st_var_0_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_0_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 72) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 74) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 74) & 15;
  int stage_v_73_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_73_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= stage_v_73_1;
  chk_sum_2 ^= stage_v_73_2;
  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 76) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 76) & 15;
  int stage_v_75_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_75_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= stage_v_75_1;
  chk_sum_2 ^= stage_v_75_2;
  int stage_v_76_1 = table_1[0];
  int stage_v_76_2 = table_2[0];
  table_1[0] = (table_1[1] + 153) & 63;
  table_2[0] = (table_2[1] + 153) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((st_var_1_1.buffer[2] * 2) + 238) & 63;
  int stage_v_77_2 = ((st_var_1_2.buffer[2] * 2) + 238) & 63;
  if (stage_v_77_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_77_1) - 5) & 255;
    if (stage_v_77_1 > 28)
    {
      chk_sum_1 ^= stage_v_77_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_77_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_77_2) - 5) & 255;
    if (stage_v_77_2 > 28)
    {
      chk_sum_2 ^= stage_v_77_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_78_1 = (st_var_0_1.buffer[0] ^ 81) & 3;
  int stage_v_78_2 = (st_var_0_2.buffer[0] ^ 81) & 3;
  switch (stage_v_78_1)
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

  switch (stage_v_78_2)
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

  int stage_v_79_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (84 & 31);
  int stage_v_79_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (84 & 31);
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= (stage_v_79_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_79_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 81) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 81) & 15;
  int stage_v_80_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_80_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= stage_v_80_1;
  chk_sum_2 ^= stage_v_80_2;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
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
  int stage_v_86_1 = table_1[2];
  int stage_v_86_2 = table_2[2];
  table_1[2] = (table_1[3] + 173) & 63;
  table_2[2] = (table_2[3] + 173) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = table_1[3];
  int stage_v_87_2 = table_2[3];
  table_1[3] = (table_1[0] + 175) & 63;
  table_2[3] = (table_2[0] + 175) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (93 & 31);
  int stage_v_88_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (93 & 31);
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= (stage_v_88_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_88_2 << 1) & 127;
  int stage_v_89_1 = (st_var_1_1.buffer[0] ^ 92) & 3;
  int stage_v_89_2 = (st_var_1_2.buffer[0] ^ 92) & 3;
  switch (stage_v_89_1)
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

  switch (stage_v_89_2)
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

  int stage_v_90_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (95 & 31);
  int stage_v_90_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (95 & 31);
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= (stage_v_90_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_90_2 << 1) & 127;
  int stage_v_91_1 = table_1[3];
  int stage_v_91_2 = table_2[3];
  table_1[3] = (table_1[0] + 183) & 63;
  table_2[3] = (table_2[0] + 183) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 93) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 93) & 15;
  int stage_v_92_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_92_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  chk_sum_1 ^= stage_v_92_1;
  chk_sum_2 ^= stage_v_92_2;
  int stage_v_93_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (98 & 31);
  int stage_v_93_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (98 & 31);
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  chk_sum_1 ^= (stage_v_93_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_93_2 << 1) & 127;
  int stage_v_94_1 = (st_var_0_1.buffer[0] ^ 97) & 3;
  int stage_v_94_2 = (st_var_0_2.buffer[0] ^ 97) & 3;
  switch (stage_v_94_1)
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

  switch (stage_v_94_2)
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

  int stage_v_95_1 = table_1[3];
  int stage_v_95_2 = table_2[3];
  table_1[3] = (table_1[0] + 191) & 63;
  table_2[3] = (table_2[0] + 191) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
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
  int stage_v_98_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (103 & 31);
  int stage_v_98_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (103 & 31);
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  chk_sum_1 ^= (stage_v_98_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_98_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 100) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 100) & 15;
  int stage_v_99_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_99_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  chk_sum_1 ^= stage_v_99_1;
  chk_sum_2 ^= stage_v_99_2;
  int stage_v_100_1 = ((st_var_0_1.buffer[1] * 2) + 307) & 63;
  int stage_v_100_2 = ((st_var_0_2.buffer[1] * 2) + 307) & 63;
  if (stage_v_100_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_100_1) - 5) & 255;
    if (stage_v_100_1 > 53)
    {
      chk_sum_1 ^= stage_v_100_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_100_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_100_2) - 5) & 255;
    if (stage_v_100_2 > 53)
    {
      chk_sum_2 ^= stage_v_100_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 102) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 102) & 15;
  int stage_v_101_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_101_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= stage_v_101_1;
  chk_sum_2 ^= stage_v_101_2;
  int stage_v_102_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (107 & 31);
  int stage_v_102_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (107 & 31);
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= (stage_v_102_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_102_2 << 1) & 127;
  int stage_v_103_1 = table_1[3];
  int stage_v_103_2 = table_2[3];
  table_1[3] = (table_1[0] + 207) & 63;
  table_2[3] = (table_2[0] + 207) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((st_var_0_1.buffer[2] * 2) + 319) & 63;
  int stage_v_104_2 = ((st_var_0_2.buffer[2] * 2) + 319) & 63;
  if (stage_v_104_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_104_1) - 5) & 255;
    if (stage_v_104_1 > 51)
    {
      chk_sum_1 ^= stage_v_104_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_104_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_104_2) - 5) & 255;
    if (stage_v_104_2 > 51)
    {
      chk_sum_2 ^= stage_v_104_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_105_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (110 & 31);
  int stage_v_105_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (110 & 31);
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= (stage_v_105_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_105_2 << 1) & 127;
  int stage_v_106_1 = (st_var_0_1.buffer[0] ^ 109) & 3;
  int stage_v_106_2 = (st_var_0_2.buffer[0] ^ 109) & 3;
  switch (stage_v_106_1)
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

  switch (stage_v_106_2)
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

  int stage_v_107_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_107_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_108_1 = table_1[0];
  int stage_v_108_2 = table_2[0];
  table_1[0] = (table_1[1] + 217) & 63;
  table_2[0] = (table_2[1] + 217) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (st_var_1_1.buffer[0] ^ 112) & 3;
  int stage_v_109_2 = (st_var_1_2.buffer[0] ^ 112) & 3;
  switch (stage_v_109_1)
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

  switch (stage_v_109_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 111) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 111) & 15;
  int stage_v_110_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_110_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  chk_sum_1 ^= stage_v_110_1;
  chk_sum_2 ^= stage_v_110_2;
  int stage_v_111_1 = (st_var_1_1.buffer[0] ^ 114) & 3;
  int stage_v_111_2 = (st_var_1_2.buffer[0] ^ 114) & 3;
  switch (stage_v_111_1)
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

  switch (stage_v_111_2)
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

  int stage_v_112_1 = (st_var_0_1.buffer[0] ^ 115) & 3;
  int stage_v_112_2 = (st_var_0_2.buffer[0] ^ 115) & 3;
  switch (stage_v_112_1)
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

  switch (stage_v_112_2)
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

  int stage_v_113_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (118 & 31);
  int stage_v_113_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (118 & 31);
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  chk_sum_1 ^= (stage_v_113_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_113_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 115) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 115) & 15;
  int stage_v_114_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_114_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= stage_v_114_1;
  chk_sum_2 ^= stage_v_114_2;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (121 & 31);
  int stage_v_116_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (121 & 31);
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= (stage_v_116_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_116_2 << 1) & 127;
  int stage_v_117_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_117_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_117_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_117_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_118_1 = (st_var_0_1.buffer[0] ^ 121) & 3;
  int stage_v_118_2 = (st_var_0_2.buffer[0] ^ 121) & 3;
  switch (stage_v_118_1)
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

  switch (stage_v_118_2)
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

  int stage_v_119_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (124 & 31);
  int stage_v_119_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (124 & 31);
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= (stage_v_119_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_119_2 << 1) & 127;
  int stage_v_120_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_120_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_121_1 = table_1[1];
  int stage_v_121_2 = table_2[1];
  table_1[1] = (table_1[2] + 243) & 63;
  table_2[1] = (table_2[2] + 243) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (127 & 31);
  int stage_v_122_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (127 & 31);
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= (stage_v_122_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_122_2 << 1) & 127;
  int stage_v_123_1 = (st_var_1_1.buffer[0] ^ 126) & 3;
  int stage_v_123_2 = (st_var_1_2.buffer[0] ^ 126) & 3;
  switch (stage_v_123_1)
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

  switch (stage_v_123_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 125) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 125) & 15;
  int stage_v_124_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_124_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= stage_v_124_1;
  chk_sum_2 ^= stage_v_124_2;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = table_1[2];
  int stage_v_126_2 = table_2[2];
  table_1[2] = (table_1[3] + 253) & 63;
  table_2[2] = (table_2[3] + 253) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = table_1[3];
  int stage_v_127_2 = table_2[3];
  table_1[3] = (table_1[0] + 255) & 63;
  table_2[3] = (table_2[0] + 255) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
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
  int stage_v_130_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (135 & 31);
  int stage_v_130_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (135 & 31);
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= (stage_v_130_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_130_2 << 1) & 127;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_132_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_133_1 = ((st_var_1_1.buffer[1] * 2) + 406) & 63;
  int stage_v_133_2 = ((st_var_1_2.buffer[1] * 2) + 406) & 63;
  if (stage_v_133_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_133_1) - 5) & 255;
    if (stage_v_133_1 > 48)
    {
      chk_sum_1 ^= stage_v_133_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_133_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_133_2) - 5) & 255;
    if (stage_v_133_2 > 48)
    {
      chk_sum_2 ^= stage_v_133_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_134_1 = (st_var_0_1.buffer[0] ^ 137) & 3;
  int stage_v_134_2 = (st_var_0_2.buffer[0] ^ 137) & 3;
  switch (stage_v_134_1)
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

  switch (stage_v_134_2)
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

  int stage_v_135_1 = ((st_var_1_1.buffer[0] * 2) + 412) & 63;
  int stage_v_135_2 = ((st_var_1_2.buffer[0] * 2) + 412) & 63;
  if (stage_v_135_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_135_1) - 5) & 255;
    if (stage_v_135_1 > 42)
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
  if (stage_v_135_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_135_2) - 5) & 255;
    if (stage_v_135_2 > 42)
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
  int stage_v_136_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_136_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_136_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_136_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_137_1 = ((stage_v_137_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_137_2 = ((stage_v_137_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_139_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_140_1 = table_1[0];
  int stage_v_140_2 = table_2[0];
  table_1[0] = (table_1[1] + 281) & 63;
  table_2[0] = (table_2[1] + 281) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_141_1 = ((stage_v_141_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 143) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 143) & 15;
  int stage_v_142_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_142_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= stage_v_142_1;
  chk_sum_2 ^= stage_v_142_2;
  int stage_v_143_1 = ((st_var_1_1.buffer[2] * 2) + 436) & 63;
  int stage_v_143_2 = ((st_var_1_2.buffer[2] * 2) + 436) & 63;
  if (stage_v_143_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_143_1) - 5) & 255;
    if (stage_v_143_1 > 27)
    {
      chk_sum_1 ^= stage_v_143_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_143_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_143_2) - 5) & 255;
    if (stage_v_143_2 > 27)
    {
      chk_sum_2 ^= stage_v_143_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_144_1 = (st_var_0_1.buffer[0] ^ 147) & 3;
  int stage_v_144_2 = (st_var_0_2.buffer[0] ^ 147) & 3;
  switch (stage_v_144_1)
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

  switch (stage_v_144_2)
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

  int stage_v_145_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (150 & 31);
  int stage_v_145_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (150 & 31);
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  chk_sum_1 ^= (stage_v_145_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_145_2 << 1) & 127;
  int stage_v_146_1 = table_1[2];
  int stage_v_146_2 = table_2[2];
  table_1[2] = (table_1[3] + 293) & 63;
  table_2[2] = (table_2[3] + 293) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_147_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_148_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (153 & 31);
  int stage_v_148_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (153 & 31);
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  chk_sum_1 ^= (stage_v_148_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_148_2 << 1) & 127;
  int stage_v_149_1 = table_1[1];
  int stage_v_149_2 = table_2[1];
  table_1[1] = (table_1[2] + 299) & 63;
  table_2[1] = (table_2[2] + 299) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (st_var_0_1.buffer[0] ^ 153) & 3;
  int stage_v_150_2 = (st_var_0_2.buffer[0] ^ 153) & 3;
  switch (stage_v_150_1)
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

  switch (stage_v_150_2)
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

  int stage_v_151_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (156 & 31);
  int stage_v_151_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (156 & 31);
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= (stage_v_151_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_151_2 << 1) & 127;
  int stage_v_152_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_152_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_153_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (158 & 31);
  int stage_v_153_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (158 & 31);
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  chk_sum_1 ^= (stage_v_153_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_153_2 << 1) & 127;
  int stage_v_154_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (159 & 31);
  int stage_v_154_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (159 & 31);
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= (stage_v_154_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_154_2 << 1) & 127;
  int stage_v_155_1 = ((st_var_1_1.buffer[2] * 2) + 472) & 63;
  int stage_v_155_2 = ((st_var_1_2.buffer[2] * 2) + 472) & 63;
  if (stage_v_155_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_155_1) - 5) & 255;
    if (stage_v_155_1 > 36)
    {
      chk_sum_1 ^= stage_v_155_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_155_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_155_2) - 5) & 255;
    if (stage_v_155_2 > 36)
    {
      chk_sum_2 ^= stage_v_155_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 157) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 157) & 15;
  int stage_v_156_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_156_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= stage_v_156_1;
  chk_sum_2 ^= stage_v_156_2;
  int stage_v_157_1 = (st_var_1_1.buffer[0] ^ 160) & 3;
  int stage_v_157_2 = (st_var_1_2.buffer[0] ^ 160) & 3;
  switch (stage_v_157_1)
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

  switch (stage_v_157_2)
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

  int stage_v_158_1 = (st_var_0_1.buffer[0] ^ 161) & 3;
  int stage_v_158_2 = (st_var_0_2.buffer[0] ^ 161) & 3;
  switch (stage_v_158_1)
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

  switch (stage_v_158_2)
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
  int stage_v_160_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_160_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_161_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (166 & 31);
  int stage_v_161_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (166 & 31);
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  chk_sum_1 ^= (stage_v_161_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_161_2 << 1) & 127;
  int stage_v_162_1 = table_1[2];
  int stage_v_162_2 = table_2[2];
  table_1[2] = (table_1[3] + 325) & 63;
  table_2[2] = (table_2[3] + 325) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 165) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 165) & 15;
  int stage_v_164_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_164_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  chk_sum_1 ^= stage_v_164_1;
  chk_sum_2 ^= stage_v_164_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 166) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 166) & 15;
  int stage_v_165_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_165_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  chk_sum_1 ^= stage_v_165_1;
  chk_sum_2 ^= stage_v_165_2;
  int stage_v_166_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (171 & 31);
  int stage_v_166_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (171 & 31);
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  chk_sum_1 ^= (stage_v_166_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_166_2 << 1) & 127;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_167_1 = ((stage_v_167_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_167_2 = ((stage_v_167_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (173 & 31);
  int stage_v_168_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (173 & 31);
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  chk_sum_1 ^= (stage_v_168_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_168_2 << 1) & 127;
  int stage_v_169_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_169_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_170_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (175 & 31);
  int stage_v_170_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (175 & 31);
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  chk_sum_1 ^= (stage_v_170_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_170_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 172) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 172) & 15;
  int stage_v_171_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_171_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  chk_sum_1 ^= stage_v_171_1;
  chk_sum_2 ^= stage_v_171_2;
  int stage_v_172_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_172_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_172_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_172_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_173_1 = (st_var_1_1.buffer[0] ^ 176) & 3;
  int stage_v_173_2 = (st_var_1_2.buffer[0] ^ 176) & 3;
  switch (stage_v_173_1)
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

  switch (stage_v_173_2)
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

  int stage_v_174_1 = ((st_var_0_1.buffer[0] * 2) + 529) & 63;
  int stage_v_174_2 = ((st_var_0_2.buffer[0] * 2) + 529) & 63;
  if (stage_v_174_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_174_1) - 5) & 255;
    if (stage_v_174_1 > 45)
    {
      chk_sum_1 ^= stage_v_174_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_174_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_174_2) - 5) & 255;
    if (stage_v_174_2 > 45)
    {
      chk_sum_2 ^= stage_v_174_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_175_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (180 & 31);
  int stage_v_175_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (180 & 31);
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  chk_sum_1 ^= (stage_v_175_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_175_2 << 1) & 127;
  int stage_v_176_1 = ((st_var_0_1.buffer[2] * 2) + 535) & 63;
  int stage_v_176_2 = ((st_var_0_2.buffer[2] * 2) + 535) & 63;
  if (stage_v_176_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_176_1) - 5) & 255;
    if (stage_v_176_1 > 31)
    {
      chk_sum_1 ^= stage_v_176_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_176_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_176_2) - 5) & 255;
    if (stage_v_176_2 > 31)
    {
      chk_sum_2 ^= stage_v_176_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_177_1 = ((st_var_1_1.buffer[0] * 2) + 538) & 63;
  int stage_v_177_2 = ((st_var_1_2.buffer[0] * 2) + 538) & 63;
  if (stage_v_177_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_177_1) - 5) & 255;
    if (stage_v_177_1 > 40)
    {
      chk_sum_1 ^= stage_v_177_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_177_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_177_2) - 5) & 255;
    if (stage_v_177_2 > 40)
    {
      chk_sum_2 ^= stage_v_177_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int m_var_1 = (sec_r000940_17_1 ^ 0x55) & 63;
  int m_var_2 = (sec_r000940_17_2 ^ 0x55) & 63;
  if (m_var_1 > 18)
  {
    out_sink_1 += ((m_var_1 * 2) + pub_r000940_8_1) & 127;
  }
  else
  {
    out_sink_1 -= (m_var_1 + 11) & 31;
  }
  if (m_var_2 > 18)
  {
    out_sink_2 += ((m_var_2 * 2) + pub_r000940_8_2) & 127;
  }
  else
  {
    out_sink_2 -= (m_var_2 + 11) & 31;
  }
  out_sink_1 ^= sec_r000940_16_1 & 15;
  out_sink_2 ^= sec_r000940_16_2 & 15;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000940_7_1 == pub_r000940_7_2);
  __CPROVER_assume(sec_r000940_6_1 != sec_r000940_6_2);
  __CPROVER_assume(sec_r000940_19_1 != sec_r000940_19_2);
  __CPROVER_assume(sec_r000940_1_1 != sec_r000940_1_2);
  __CPROVER_assume(sec_r000940_3_1 != sec_r000940_3_2);
  __CPROVER_assume(sec_r000940_20_1 != sec_r000940_20_2);
  __CPROVER_assume(pub_r000940_9_1 == pub_r000940_9_2);
  __CPROVER_assume(sec_r000940_5_1 != sec_r000940_5_2);
  __CPROVER_assume(sec_r000940_17_1 != sec_r000940_17_2);
  __CPROVER_assume(sec_r000940_12_1 != sec_r000940_12_2);
  __CPROVER_assume(pub_r000940_10_1 == pub_r000940_10_2);
  __CPROVER_assume(pub_r000940_8_1 == pub_r000940_8_2);
  __CPROVER_assume(pub_r000940_11_1 == pub_r000940_11_2);
  __CPROVER_assume(pub_r000940_16_1 == pub_r000940_16_2);
  __CPROVER_assume(sec_r000940_2_1 != sec_r000940_2_2);
  __CPROVER_assume(pub_r000940_14_1 == pub_r000940_14_2);
  __CPROVER_assume(pub_r000940_3_1 == pub_r000940_3_2);
  __CPROVER_assume(pub_r000940_2_1 == pub_r000940_2_2);
  __CPROVER_assume(pub_r000940_1_1 == pub_r000940_1_2);
  __CPROVER_assume(pub_r000940_12_1 == pub_r000940_12_2);
  __CPROVER_assume(sec_r000940_16_1 != sec_r000940_16_2);
  __CPROVER_assume(sec_r000940_4_1 != sec_r000940_4_2);
  __CPROVER_assume(sec_r000940_13_1 != sec_r000940_13_2);
  __CPROVER_assume(pub_r000940_5_1 == pub_r000940_5_2);
  __CPROVER_assume(sec_r000940_0_1 != sec_r000940_0_2);
  __CPROVER_assume(pub_r000940_0_1 == pub_r000940_0_2);
  __CPROVER_assume(pub_r000940_4_1 == pub_r000940_4_2);
  __CPROVER_assume(sec_r000940_14_1 != sec_r000940_14_2);
  __CPROVER_assume(sec_r000940_9_1 != sec_r000940_9_2);
  __CPROVER_assume(sec_r000940_10_1 != sec_r000940_10_2);
  __CPROVER_assume(sec_r000940_15_1 != sec_r000940_15_2);
  __CPROVER_assume(pub_r000940_15_1 == pub_r000940_15_2);
  __CPROVER_assume(pub_r000940_13_1 == pub_r000940_13_2);
  __CPROVER_assume(pub_r000940_6_1 == pub_r000940_6_2);
  __CPROVER_assume(sec_r000940_11_1 != sec_r000940_11_2);
  __CPROVER_assume(sec_r000940_8_1 != sec_r000940_8_2);
  __CPROVER_assume(sec_r000940_18_1 != sec_r000940_18_2);
  __CPROVER_assume(sec_r000940_7_1 != sec_r000940_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.tail == st_var_1_2.tail);
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
  assert(m_var_1 == m_var_2);
}


