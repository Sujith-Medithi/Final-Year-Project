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
struct MatrixBlock_R001012_1213_0
{
  unsigned char determinant;
  int dim;
  short trace;
  int buffer[3];
};
struct StreamBuffer_R001012_1213_1
{
  short tail;
  int watermark;
  short capacity;
  unsigned char state;
  short head;
  int buffer[3];
};
union RegisterBank_R001012_1213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001012_1213_1
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
void fn_R001012_1213_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_27_1 > 37)
  {
    acc_1 = ((acc_1 + (residue_27_1 * 2)) + 5) & 127;
    aux_1 ^= residue_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_27_2 > 37)
  {
    acc_2 = ((acc_2 + (residue_27_2 * 2)) + 5) & 127;
    aux_2 ^= residue_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_27_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_27_1 == residue_27_2);
}

int fn_R001012_1213_0(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_27 > 37)
  {
    acc = ((acc + (residue_27 * 2)) + 5) & 127;
    aux ^= residue_27 & 15;
  }
  else
  {
    acc = ((acc - residue_27) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001012_1213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_61_1 = local_arr_1[aux_1 % 3];
  int checksum_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_61_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_65_1 > 29)
  {
    acc_1 = ((acc_1 + (factor_65_1 * 2)) + 5) & 127;
    aux_1 ^= factor_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_65_2 > 29)
  {
    acc_2 = ((acc_2 + (factor_65_2 * 2)) + 5) & 127;
    aux_2 ^= factor_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_61_1 == checksum_61_2);
  assert(factor_65_1 == factor_65_2);
}

int fn_R001012_1213_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int checksum_61 = local_arr[aux % 3];
  acc = (acc + (checksum_61 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_65 > 29)
  {
    acc = ((acc + (factor_65 * 2)) + 5) & 127;
    aux ^= factor_65 & 15;
  }
  else
  {
    acc = ((acc - factor_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001012_1213_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int segment_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_43_1) & 63;
  aux_2 = (aux_2 + segment_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_88_1 = 0;
  int accumulator_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_88_1 = ((accumulator_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_88_2 = ((accumulator_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_88_1) & 127;
    acc_2 = (acc_2 + accumulator_88_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_43_1 == segment_43_2);
  assert(accumulator_88_1 == accumulator_88_2);
}

int fn_R001012_1213_2(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int segment_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_43) & 63;
  acc ^= aux;
  int accumulator_88 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_88 = ((accumulator_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_88) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001012_1213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int scale_77_1 = 0;
  int scale_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_77_1 = ((scale_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_77_2 = ((scale_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_77_1) & 127;
    acc_2 = (acc_2 + scale_77_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_27_1) & 63;
  aux_2 = (aux_2 + accumulator_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_81_1)
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

  switch (coefficient_81_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_77_1 == scale_77_2);
  assert(accumulator_27_1 == accumulator_27_2);
  assert(coefficient_81_1 == coefficient_81_2);
}

int fn_R001012_1213_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int scale_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_77 = ((scale_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_77) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_27) & 63;
  acc ^= aux;
  int coefficient_81 = (aux + st.buffer[1]) & 3;
  switch (coefficient_81)
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

void fn_R001012_1213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int offset_68_1 = 0;
  int offset_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_68_1 = ((offset_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_68_2 = ((offset_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_68_1) & 127;
    acc_2 = (acc_2 + offset_68_2) & 127;
  }

  int coefficient_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_32_1)
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

  switch (coefficient_32_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_68_1 == offset_68_2);
  assert(coefficient_32_1 == coefficient_32_2);
}

int fn_R001012_1213_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int offset_68 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_68 = ((offset_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_68) & 127;
  }

  int coefficient_32 = (aux + st.buffer[1]) & 3;
  switch (coefficient_32)
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

void fn_R001012_1213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st_1 = {0};
  struct MatrixBlock_R001012_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int factor_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_29_1 > 43)
  {
    acc_1 = ((acc_1 + (factor_29_1 * 2)) + 5) & 127;
    aux_1 ^= factor_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_29_2 > 43)
  {
    acc_2 = ((acc_2 + (factor_29_2 * 2)) + 5) & 127;
    aux_2 ^= factor_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_16_1 = 0;
  int tracker_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_16_1 = ((tracker_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_16_2 = ((tracker_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_16_1) & 127;
    acc_2 = (acc_2 + tracker_16_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_29_1 == factor_29_2);
  assert(tracker_16_1 == tracker_16_2);
}

int fn_R001012_1213_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int factor_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_29 > 43)
  {
    acc = ((acc + (factor_29 * 2)) + 5) & 127;
    aux ^= factor_29 & 15;
  }
  else
  {
    acc = ((acc - factor_29) + 11) & 127;
    aux += 3;
  }
  int tracker_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_16 = ((tracker_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_16) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001012_1213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st_1 = {0};
  struct MatrixBlock_R001012_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int metric_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_40_1)
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

  switch (metric_40_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_57_1 = local_arr_1[aux_1 % 3];
  int delta_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_57_2 * 2)) & 127;
  int margin_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_80_1 > 35)
  {
    acc_1 = ((acc_1 + (margin_80_1 * 2)) + 5) & 127;
    aux_1 ^= margin_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_80_2 > 35)
  {
    acc_2 = ((acc_2 + (margin_80_2 * 2)) + 5) & 127;
    aux_2 ^= margin_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_40_1 == metric_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_57_1 == delta_57_2);
  assert(margin_80_1 == margin_80_2);
}

int fn_R001012_1213_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int metric_40 = (aux + st.buffer[1]) & 3;
  switch (metric_40)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_57 = local_arr[aux % 3];
  acc = (acc + (delta_57 * 2)) & 127;
  int margin_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_80 > 35)
  {
    acc = ((acc + (margin_80 * 2)) + 5) & 127;
    aux ^= margin_80 & 15;
  }
  else
  {
    acc = ((acc - margin_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001012_1213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st_1 = {0};
  struct MatrixBlock_R001012_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_30_1 = local_arr_1[aux_1 % 3];
  int offset_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_30_2 * 2)) & 127;
  int scale_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_80_1)
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

  switch (scale_80_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_30_1 == offset_30_2);
  assert(scale_80_1 == scale_80_2);
}

int fn_R001012_1213_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int offset_30 = local_arr[aux % 3];
  acc = (acc + (offset_30 * 2)) & 127;
  int scale_80 = (aux + st.buffer[1]) & 3;
  switch (scale_80)
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

void fn_R001012_1213_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_19_1 = local_arr_1[aux_1 % 3];
  int metric_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_19_2 * 2)) & 127;
  int quantum_60_1 = 0;
  int quantum_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_60_1 = ((quantum_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_60_2 = ((quantum_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_60_1) & 127;
    acc_2 = (acc_2 + quantum_60_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_19_1 == metric_19_2);
  assert(quantum_60_1 == quantum_60_2);
}

int fn_R001012_1213_8(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int metric_19 = local_arr[aux % 3];
  acc = (acc + (metric_19 * 2)) & 127;
  int quantum_60 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_60 = ((quantum_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_60) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001012_1213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st_1 = {0};
  struct MatrixBlock_R001012_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int factor_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_51_1 > 48)
  {
    acc_1 = ((acc_1 + (factor_51_1 * 2)) + 5) & 127;
    aux_1 ^= factor_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_51_2 > 48)
  {
    acc_2 = ((acc_2 + (factor_51_2 * 2)) + 5) & 127;
    aux_2 ^= factor_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_79_1) & 63;
  aux_2 = (aux_2 + residue_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_62_1 = local_arr_1[aux_1 % 3];
  int tracker_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_62_2 * 2)) & 127;
  int anchor_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_86_1)
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

  switch (anchor_86_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_51_1 == factor_51_2);
  assert(residue_79_1 == residue_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_62_1 == tracker_62_2);
  assert(anchor_86_1 == anchor_86_2);
}

int fn_R001012_1213_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int factor_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_51 > 48)
  {
    acc = ((acc + (factor_51 * 2)) + 5) & 127;
    aux ^= factor_51 & 15;
  }
  else
  {
    acc = ((acc - factor_51) + 11) & 127;
    aux += 3;
  }
  int residue_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_79) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_62 = local_arr[aux % 3];
  acc = (acc + (tracker_62 * 2)) & 127;
  int anchor_86 = (aux + st.buffer[1]) & 3;
  switch (anchor_86)
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

void fn_R001012_1213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st_1 = {0};
  struct MatrixBlock_R001012_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int coefficient_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_21_1) & 63;
  aux_2 = (aux_2 + coefficient_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_15_1 = local_arr_1[aux_1 % 3];
  int vector_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_15_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_37_1 > 35)
  {
    acc_1 = ((acc_1 + (checksum_37_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_37_2 > 35)
  {
    acc_2 = ((acc_2 + (checksum_37_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_21_1 == coefficient_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_15_1 == vector_15_2);
  assert(checksum_37_1 == checksum_37_2);
}

int fn_R001012_1213_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int coefficient_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_21) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_15 = local_arr[aux % 3];
  acc = (acc + (vector_15 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_37 > 35)
  {
    acc = ((acc + (checksum_37 * 2)) + 5) & 127;
    aux ^= checksum_37 & 15;
  }
  else
  {
    acc = ((acc - checksum_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001012_1213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int pivot_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_77_1 > 41)
  {
    acc_1 = ((acc_1 + (pivot_77_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_77_2 > 41)
  {
    acc_2 = ((acc_2 + (pivot_77_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_40_1)
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

  switch (checksum_40_2)
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
  int delta_23_1 = local_arr_1[aux_1 % 3];
  int delta_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_23_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_77_1 == pivot_77_2);
  assert(checksum_40_1 == checksum_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_23_1 == delta_23_2);
}

int fn_R001012_1213_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int pivot_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_77 > 41)
  {
    acc = ((acc + (pivot_77 * 2)) + 5) & 127;
    aux ^= pivot_77 & 15;
  }
  else
  {
    acc = ((acc - pivot_77) + 11) & 127;
    aux += 3;
  }
  int checksum_40 = (aux + st.buffer[1]) & 3;
  switch (checksum_40)
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
  int delta_23 = local_arr[aux % 3];
  acc = (acc + (delta_23 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001012_1213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int pivot_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_27_1) & 63;
  aux_2 = (aux_2 + pivot_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_45_1 = 0;
  int tracker_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_45_1 = ((tracker_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_45_2 = ((tracker_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_45_1) & 127;
    acc_2 = (acc_2 + tracker_45_2) & 127;
  }

  int scale_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_62_1 > 48)
  {
    acc_1 = ((acc_1 + (scale_62_1 * 2)) + 5) & 127;
    aux_1 ^= scale_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_62_2 > 48)
  {
    acc_2 = ((acc_2 + (scale_62_2 * 2)) + 5) & 127;
    aux_2 ^= scale_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_65_1)
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

  switch (parity_65_2)
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
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_27_1 == pivot_27_2);
  assert(tracker_45_1 == tracker_45_2);
  assert(scale_62_1 == scale_62_2);
  assert(parity_65_1 == parity_65_2);
}

int fn_R001012_1213_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int pivot_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_27) & 63;
  acc ^= aux;
  int tracker_45 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_45 = ((tracker_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_45) & 127;
  }

  int scale_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_62 > 48)
  {
    acc = ((acc + (scale_62 * 2)) + 5) & 127;
    aux ^= scale_62 & 15;
  }
  else
  {
    acc = ((acc - scale_62) + 11) & 127;
    aux += 3;
  }
  int parity_65 = (aux + st.buffer[1]) & 3;
  switch (parity_65)
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

void fn_R001012_1213_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int tally_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_13_1 > 49)
  {
    acc_1 = ((acc_1 + (tally_13_1 * 2)) + 5) & 127;
    aux_1 ^= tally_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_13_2 > 49)
  {
    acc_2 = ((acc_2 + (tally_13_2 * 2)) + 5) & 127;
    aux_2 ^= tally_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_99_1 = 0;
  int accumulator_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_99_1 = ((accumulator_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_99_2 = ((accumulator_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_99_1) & 127;
    acc_2 = (acc_2 + accumulator_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_13_1 == tally_13_2);
  assert(accumulator_99_1 == accumulator_99_2);
}

int fn_R001012_1213_13(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int tally_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_13 > 49)
  {
    acc = ((acc + (tally_13 * 2)) + 5) & 127;
    aux ^= tally_13 & 15;
  }
  else
  {
    acc = ((acc - tally_13) + 11) & 127;
    aux += 3;
  }
  int accumulator_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_99 = ((accumulator_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_99) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001012_1213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st_1 = {0};
  struct MatrixBlock_R001012_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int tracker_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_73_1 > 50)
  {
    acc_1 = ((acc_1 + (tracker_73_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_73_2 > 50)
  {
    acc_2 = ((acc_2 + (tracker_73_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_85_1 = local_arr_1[aux_1 % 3];
  int coefficient_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_85_2 * 2)) & 127;
  int margin_65_1 = 0;
  int margin_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_65_1 = ((margin_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_65_2 = ((margin_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_65_1) & 127;
    acc_2 = (acc_2 + margin_65_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_73_1 == tracker_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_85_1 == coefficient_85_2);
  assert(margin_65_1 == margin_65_2);
}

int fn_R001012_1213_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int tracker_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_73 > 50)
  {
    acc = ((acc + (tracker_73 * 2)) + 5) & 127;
    aux ^= tracker_73 & 15;
  }
  else
  {
    acc = ((acc - tracker_73) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_85 = local_arr[aux % 3];
  acc = (acc + (coefficient_85 * 2)) & 127;
  int margin_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_65 = ((margin_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_65) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001012_1213_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_44_1)
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

  switch (bound_44_2)
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
  int damping_62_1 = local_arr_1[aux_1 % 3];
  int damping_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_62_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_44_1 == bound_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_62_1 == damping_62_2);
}

int fn_R001012_1213_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_44 = (aux + st.buffer[1]) & 3;
  switch (bound_44)
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
  int damping_62 = local_arr[aux % 3];
  acc = (acc + (damping_62 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001012_1213_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int parity_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_94_1)
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

  switch (parity_94_2)
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

  int window_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_33_1 > 43)
  {
    acc_1 = ((acc_1 + (window_33_1 * 2)) + 5) & 127;
    aux_1 ^= window_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_33_2 > 43)
  {
    acc_2 = ((acc_2 + (window_33_2 * 2)) + 5) & 127;
    aux_2 ^= window_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_48_1 = 0;
  int window_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_48_1 = ((window_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_48_2 = ((window_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_48_1) & 127;
    acc_2 = (acc_2 + window_48_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_94_1 == parity_94_2);
  assert(window_33_1 == window_33_2);
  assert(window_48_1 == window_48_2);
}

int fn_R001012_1213_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int parity_94 = (aux + st.buffer[1]) & 3;
  switch (parity_94)
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

  int window_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_33 > 43)
  {
    acc = ((acc + (window_33 * 2)) + 5) & 127;
    aux ^= window_33 & 15;
  }
  else
  {
    acc = ((acc - window_33) + 11) & 127;
    aux += 3;
  }
  int window_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_48 = ((window_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_48) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001012_1213_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int window_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_23_1) & 63;
  aux_2 = (aux_2 + window_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_59_1 = 0;
  int stride_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_59_1 = ((stride_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_59_2 = ((stride_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_59_1) & 127;
    acc_2 = (acc_2 + stride_59_2) & 127;
  }

  int pivot_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_77_1)
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

  switch (pivot_77_2)
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
  int bound_67_1 = local_arr_1[aux_1 % 3];
  int bound_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_23_1 == window_23_2);
  assert(stride_59_1 == stride_59_2);
  assert(pivot_77_1 == pivot_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_67_1 == bound_67_2);
}

int fn_R001012_1213_17(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int window_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_23) & 63;
  acc ^= aux;
  int stride_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_59 = ((stride_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_59) & 127;
  }

  int pivot_77 = (aux + st.buffer[1]) & 3;
  switch (pivot_77)
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
  int bound_67 = local_arr[aux % 3];
  acc = (acc + (bound_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001012_1213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st_1 = {0};
  struct MatrixBlock_R001012_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int weight_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_57_1) & 63;
  aux_2 = (aux_2 + weight_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_17_1 > 12)
  {
    acc_1 = ((acc_1 + (residue_17_1 * 2)) + 5) & 127;
    aux_1 ^= residue_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_17_2 > 12)
  {
    acc_2 = ((acc_2 + (residue_17_2 * 2)) + 5) & 127;
    aux_2 ^= residue_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_15_1 = local_arr_1[aux_1 % 3];
  int quantum_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_15_2 * 2)) & 127;
  int offset_14_1 = 0;
  int offset_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_14_1 = ((offset_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_14_2 = ((offset_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_14_1) & 127;
    acc_2 = (acc_2 + offset_14_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_57_1 == weight_57_2);
  assert(residue_17_1 == residue_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_15_1 == quantum_15_2);
  assert(offset_14_1 == offset_14_2);
}

int fn_R001012_1213_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int weight_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_57) & 63;
  acc ^= aux;
  int residue_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_17 > 12)
  {
    acc = ((acc + (residue_17 * 2)) + 5) & 127;
    aux ^= residue_17 & 15;
  }
  else
  {
    acc = ((acc - residue_17) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_15 = local_arr[aux % 3];
  acc = (acc + (quantum_15 * 2)) & 127;
  int offset_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_14 = ((offset_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_14) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001012_1213_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_19_1 = local_arr_1[aux_1 % 3];
  int coefficient_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_19_2 * 2)) & 127;
  int mask_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_17_1) & 63;
  aux_2 = (aux_2 + mask_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_56_1 > 48)
  {
    acc_1 = ((acc_1 + (factor_56_1 * 2)) + 5) & 127;
    aux_1 ^= factor_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_56_2 > 48)
  {
    acc_2 = ((acc_2 + (factor_56_2 * 2)) + 5) & 127;
    aux_2 ^= factor_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_19_1 == coefficient_19_2);
  assert(mask_17_1 == mask_17_2);
  assert(factor_56_1 == factor_56_2);
}

int fn_R001012_1213_19(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int coefficient_19 = local_arr[aux % 3];
  acc = (acc + (coefficient_19 * 2)) & 127;
  int mask_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_17) & 63;
  acc ^= aux;
  int factor_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_56 > 48)
  {
    acc = ((acc + (factor_56 * 2)) + 5) & 127;
    aux ^= factor_56 & 15;
  }
  else
  {
    acc = ((acc - factor_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001012_1213_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st_1 = {0};
  struct MatrixBlock_R001012_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int margin_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_19_1)
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

  switch (margin_19_2)
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

  int threshold_35_1 = 0;
  int threshold_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_35_1 = ((threshold_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_35_2 = ((threshold_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_35_1) & 127;
    acc_2 = (acc_2 + threshold_35_2) & 127;
  }

  int offset_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_17_1) & 63;
  aux_2 = (aux_2 + offset_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_90_1 = local_arr_1[aux_1 % 3];
  int pivot_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_19_1 == margin_19_2);
  assert(threshold_35_1 == threshold_35_2);
  assert(offset_17_1 == offset_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_90_1 == pivot_90_2);
}

int fn_R001012_1213_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int margin_19 = (aux + st.buffer[1]) & 3;
  switch (margin_19)
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

  int threshold_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_35 = ((threshold_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_35) & 127;
  }

  int offset_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_17) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_90 = local_arr[aux % 3];
  acc = (acc + (pivot_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001012_1213_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int cursor_18_1 = 0;
  int cursor_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_18_1 = ((cursor_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_18_2 = ((cursor_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_18_1) & 127;
    acc_2 = (acc_2 + cursor_18_2) & 127;
  }

  int offset_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_75_1) & 63;
  aux_2 = (aux_2 + offset_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_72_1 = local_arr_1[aux_1 % 3];
  int damping_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_72_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_18_1 == cursor_18_2);
  assert(offset_75_1 == offset_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_72_1 == damping_72_2);
}

int fn_R001012_1213_21(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001012_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int cursor_18 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_18 = ((cursor_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_18) & 127;
  }

  int offset_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_75) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int damping_72 = local_arr[aux % 3];
  acc = (acc + (damping_72 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001012_1213_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st_1 = {0};
  struct MatrixBlock_R001012_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int phase_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_36_1 > 23)
  {
    acc_1 = ((acc_1 + (phase_36_1 * 2)) + 5) & 127;
    aux_1 ^= phase_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_36_2 > 23)
  {
    acc_2 = ((acc_2 + (phase_36_2 * 2)) + 5) & 127;
    aux_2 ^= phase_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_12_1 = local_arr_1[aux_1 % 3];
  int parity_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_12_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_28_1 = 0;
  int window_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_28_1 = ((window_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_28_2 = ((window_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_28_1) & 127;
    acc_2 = (acc_2 + window_28_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_36_1 == phase_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_12_1 == parity_12_2);
  assert(window_28_1 == window_28_2);
}

int fn_R001012_1213_22(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int phase_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_36 > 23)
  {
    acc = ((acc + (phase_36 * 2)) + 5) & 127;
    aux ^= phase_36 & 15;
  }
  else
  {
    acc = ((acc - phase_36) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_12 = local_arr[aux % 3];
  acc = (acc + (parity_12 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_28 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_28 = ((window_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_28) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001012_1213_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st_1 = {0};
  struct MatrixBlock_R001012_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int damping_13_1 = 0;
  int damping_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_13_1 = ((damping_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_13_2 = ((damping_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_13_1) & 127;
    acc_2 = (acc_2 + damping_13_2) & 127;
  }

  int cursor_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_54_1) & 63;
  aux_2 = (aux_2 + cursor_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_25_1 > 12)
  {
    acc_1 = ((acc_1 + (scale_25_1 * 2)) + 5) & 127;
    aux_1 ^= scale_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_25_2 > 12)
  {
    acc_2 = ((acc_2 + (scale_25_2 * 2)) + 5) & 127;
    aux_2 ^= scale_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_47_1 = local_arr_1[aux_1 % 3];
  int threshold_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_47_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_13_1 == damping_13_2);
  assert(cursor_54_1 == cursor_54_2);
  assert(scale_25_1 == scale_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_47_1 == threshold_47_2);
}

int fn_R001012_1213_23(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001012_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int damping_13 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_13 = ((damping_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_13) & 127;
  }

  int cursor_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_54) & 63;
  acc ^= aux;
  int scale_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_25 > 12)
  {
    acc = ((acc + (scale_25 * 2)) + 5) & 127;
    aux ^= scale_25 & 15;
  }
  else
  {
    acc = ((acc - scale_25) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_47 = local_arr[aux % 3];
  acc = (acc + (threshold_47 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001012_0_1;
  int sec_r001012_0_2;
  int sec_r001012_1_1;
  int sec_r001012_1_2;
  int sec_r001012_2_1;
  int sec_r001012_2_2;
  int sec_r001012_3_1;
  int sec_r001012_3_2;
  int sec_r001012_4_1;
  int sec_r001012_4_2;
  int sec_r001012_5_1;
  int sec_r001012_5_2;
  int sec_r001012_6_1;
  int sec_r001012_6_2;
  int sec_r001012_7_1;
  int sec_r001012_7_2;
  int sec_r001012_8_1;
  int sec_r001012_8_2;
  int sec_r001012_9_1;
  int sec_r001012_9_2;
  int sec_r001012_10_1;
  int sec_r001012_10_2;
  int sec_r001012_11_1;
  int sec_r001012_11_2;
  int sec_r001012_12_1;
  int sec_r001012_12_2;
  int sec_r001012_13_1;
  int sec_r001012_13_2;
  int sec_r001012_14_1;
  int sec_r001012_14_2;
  int sec_r001012_15_1;
  int sec_r001012_15_2;
  int sec_r001012_16_1;
  int sec_r001012_16_2;
  int pub_r001012_0_1;
  int pub_r001012_0_2;
  int pub_r001012_1_1;
  int pub_r001012_1_2;
  int pub_r001012_2_1;
  int pub_r001012_2_2;
  int pub_r001012_3_1;
  int pub_r001012_3_2;
  int pub_r001012_4_1;
  int pub_r001012_4_2;
  int pub_r001012_5_1;
  int pub_r001012_5_2;
  int pub_r001012_6_1;
  int pub_r001012_6_2;
  int pub_r001012_7_1;
  int pub_r001012_7_2;
  int pub_r001012_8_1;
  int pub_r001012_8_2;
  int pub_r001012_9_1;
  int pub_r001012_9_2;
  int pub_r001012_10_1;
  int pub_r001012_10_2;
  int pub_r001012_11_1;
  int pub_r001012_11_2;
  int pub_r001012_12_1;
  int pub_r001012_12_2;
  int pub_r001012_13_1;
  int pub_r001012_13_2;
  int pub_r001012_14_1;
  int pub_r001012_14_2;
  int pub_r001012_15_1;
  int pub_r001012_15_2;
  int pub_r001012_16_1;
  int pub_r001012_16_2;
  int pub_r001012_17_1;
  int pub_r001012_17_2;
  int pub_r001012_18_1;
  int pub_r001012_18_2;
  int pub_r001012_19_1;
  int pub_r001012_19_2;
  int pub_r001012_20_1;
  int pub_r001012_20_2;
  int pub_r001012_21_1;
  int pub_r001012_21_2;
  int pub_r001012_22_1;
  int pub_r001012_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001012_0_1 >= (-100)) && (pub_r001012_0_1 <= 100));
  __CPROVER_assume((pub_r001012_0_2 >= (-100)) && (pub_r001012_0_2 <= 100));
  __CPROVER_assume((pub_r001012_1_1 >= (-100)) && (pub_r001012_1_1 <= 100));
  __CPROVER_assume((pub_r001012_1_2 >= (-100)) && (pub_r001012_1_2 <= 100));
  __CPROVER_assume((pub_r001012_2_1 >= (-100)) && (pub_r001012_2_1 <= 100));
  __CPROVER_assume((pub_r001012_2_2 >= (-100)) && (pub_r001012_2_2 <= 100));
  __CPROVER_assume((pub_r001012_3_1 >= (-100)) && (pub_r001012_3_1 <= 100));
  __CPROVER_assume((pub_r001012_3_2 >= (-100)) && (pub_r001012_3_2 <= 100));
  __CPROVER_assume((pub_r001012_4_1 >= (-100)) && (pub_r001012_4_1 <= 100));
  __CPROVER_assume((pub_r001012_4_2 >= (-100)) && (pub_r001012_4_2 <= 100));
  __CPROVER_assume((pub_r001012_5_1 >= (-100)) && (pub_r001012_5_1 <= 100));
  __CPROVER_assume((pub_r001012_5_2 >= (-100)) && (pub_r001012_5_2 <= 100));
  __CPROVER_assume((pub_r001012_6_1 >= (-100)) && (pub_r001012_6_1 <= 100));
  __CPROVER_assume((pub_r001012_6_2 >= (-100)) && (pub_r001012_6_2 <= 100));
  __CPROVER_assume((pub_r001012_7_1 >= (-100)) && (pub_r001012_7_1 <= 100));
  __CPROVER_assume((pub_r001012_7_2 >= (-100)) && (pub_r001012_7_2 <= 100));
  __CPROVER_assume((pub_r001012_8_1 >= (-100)) && (pub_r001012_8_1 <= 100));
  __CPROVER_assume((pub_r001012_8_2 >= (-100)) && (pub_r001012_8_2 <= 100));
  __CPROVER_assume((pub_r001012_9_1 >= (-100)) && (pub_r001012_9_1 <= 100));
  __CPROVER_assume((pub_r001012_9_2 >= (-100)) && (pub_r001012_9_2 <= 100));
  __CPROVER_assume((pub_r001012_10_1 >= (-100)) && (pub_r001012_10_1 <= 100));
  __CPROVER_assume((pub_r001012_10_2 >= (-100)) && (pub_r001012_10_2 <= 100));
  __CPROVER_assume((pub_r001012_11_1 >= (-100)) && (pub_r001012_11_1 <= 100));
  __CPROVER_assume((pub_r001012_11_2 >= (-100)) && (pub_r001012_11_2 <= 100));
  __CPROVER_assume((pub_r001012_12_1 >= (-100)) && (pub_r001012_12_1 <= 100));
  __CPROVER_assume((pub_r001012_12_2 >= (-100)) && (pub_r001012_12_2 <= 100));
  __CPROVER_assume((pub_r001012_13_1 >= (-100)) && (pub_r001012_13_1 <= 100));
  __CPROVER_assume((pub_r001012_13_2 >= (-100)) && (pub_r001012_13_2 <= 100));
  __CPROVER_assume((pub_r001012_14_1 >= (-100)) && (pub_r001012_14_1 <= 100));
  __CPROVER_assume((pub_r001012_14_2 >= (-100)) && (pub_r001012_14_2 <= 100));
  __CPROVER_assume((pub_r001012_15_1 >= (-100)) && (pub_r001012_15_1 <= 100));
  __CPROVER_assume((pub_r001012_15_2 >= (-100)) && (pub_r001012_15_2 <= 100));
  __CPROVER_assume((pub_r001012_16_1 >= (-100)) && (pub_r001012_16_1 <= 100));
  __CPROVER_assume((pub_r001012_16_2 >= (-100)) && (pub_r001012_16_2 <= 100));
  __CPROVER_assume((pub_r001012_17_1 >= (-100)) && (pub_r001012_17_1 <= 100));
  __CPROVER_assume((pub_r001012_17_2 >= (-100)) && (pub_r001012_17_2 <= 100));
  __CPROVER_assume((pub_r001012_18_1 >= (-100)) && (pub_r001012_18_1 <= 100));
  __CPROVER_assume((pub_r001012_18_2 >= (-100)) && (pub_r001012_18_2 <= 100));
  __CPROVER_assume((pub_r001012_19_1 >= (-100)) && (pub_r001012_19_1 <= 100));
  __CPROVER_assume((pub_r001012_19_2 >= (-100)) && (pub_r001012_19_2 <= 100));
  __CPROVER_assume((pub_r001012_20_1 >= (-100)) && (pub_r001012_20_1 <= 100));
  __CPROVER_assume((pub_r001012_20_2 >= (-100)) && (pub_r001012_20_2 <= 100));
  __CPROVER_assume((pub_r001012_21_1 >= (-100)) && (pub_r001012_21_1 <= 100));
  __CPROVER_assume((pub_r001012_21_2 >= (-100)) && (pub_r001012_21_2 <= 100));
  __CPROVER_assume((pub_r001012_22_1 >= (-100)) && (pub_r001012_22_1 <= 100));
  __CPROVER_assume((pub_r001012_22_2 >= (-100)) && (pub_r001012_22_2 <= 100));
  __CPROVER_assume((sec_r001012_0_1 >= 0) && (sec_r001012_0_1 <= 255));
  __CPROVER_assume((sec_r001012_0_2 >= 0) && (sec_r001012_0_2 <= 255));
  __CPROVER_assume((sec_r001012_1_1 >= 0) && (sec_r001012_1_1 <= 255));
  __CPROVER_assume((sec_r001012_1_2 >= 0) && (sec_r001012_1_2 <= 255));
  __CPROVER_assume((sec_r001012_2_1 >= 0) && (sec_r001012_2_1 <= 255));
  __CPROVER_assume((sec_r001012_2_2 >= 0) && (sec_r001012_2_2 <= 255));
  __CPROVER_assume((sec_r001012_3_1 >= 0) && (sec_r001012_3_1 <= 255));
  __CPROVER_assume((sec_r001012_3_2 >= 0) && (sec_r001012_3_2 <= 255));
  __CPROVER_assume((sec_r001012_4_1 >= 0) && (sec_r001012_4_1 <= 255));
  __CPROVER_assume((sec_r001012_4_2 >= 0) && (sec_r001012_4_2 <= 255));
  __CPROVER_assume((sec_r001012_5_1 >= 0) && (sec_r001012_5_1 <= 255));
  __CPROVER_assume((sec_r001012_5_2 >= 0) && (sec_r001012_5_2 <= 255));
  __CPROVER_assume((sec_r001012_6_1 >= 0) && (sec_r001012_6_1 <= 255));
  __CPROVER_assume((sec_r001012_6_2 >= 0) && (sec_r001012_6_2 <= 255));
  __CPROVER_assume((sec_r001012_7_1 >= 0) && (sec_r001012_7_1 <= 255));
  __CPROVER_assume((sec_r001012_7_2 >= 0) && (sec_r001012_7_2 <= 255));
  __CPROVER_assume((sec_r001012_8_1 >= 0) && (sec_r001012_8_1 <= 255));
  __CPROVER_assume((sec_r001012_8_2 >= 0) && (sec_r001012_8_2 <= 255));
  __CPROVER_assume((sec_r001012_9_1 >= 0) && (sec_r001012_9_1 <= 255));
  __CPROVER_assume((sec_r001012_9_2 >= 0) && (sec_r001012_9_2 <= 255));
  __CPROVER_assume((sec_r001012_10_1 >= 0) && (sec_r001012_10_1 <= 255));
  __CPROVER_assume((sec_r001012_10_2 >= 0) && (sec_r001012_10_2 <= 255));
  __CPROVER_assume((sec_r001012_11_1 >= 0) && (sec_r001012_11_1 <= 255));
  __CPROVER_assume((sec_r001012_11_2 >= 0) && (sec_r001012_11_2 <= 255));
  __CPROVER_assume((sec_r001012_12_1 >= 0) && (sec_r001012_12_1 <= 255));
  __CPROVER_assume((sec_r001012_12_2 >= 0) && (sec_r001012_12_2 <= 255));
  __CPROVER_assume((sec_r001012_13_1 >= 0) && (sec_r001012_13_1 <= 255));
  __CPROVER_assume((sec_r001012_13_2 >= 0) && (sec_r001012_13_2 <= 255));
  __CPROVER_assume((sec_r001012_14_1 >= 0) && (sec_r001012_14_1 <= 255));
  __CPROVER_assume((sec_r001012_14_2 >= 0) && (sec_r001012_14_2 <= 255));
  __CPROVER_assume((sec_r001012_15_1 >= 0) && (sec_r001012_15_1 <= 255));
  __CPROVER_assume((sec_r001012_15_2 >= 0) && (sec_r001012_15_2 <= 255));
  __CPROVER_assume((sec_r001012_16_1 >= 0) && (sec_r001012_16_1 <= 255));
  __CPROVER_assume((sec_r001012_16_2 >= 0) && (sec_r001012_16_2 <= 255));
  struct MatrixBlock_R001012_1213_0 st_var_0_1 = {0};
  struct MatrixBlock_R001012_1213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001012_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001012_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001012_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001012_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001012_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001012_0_2 + 7) & 15;
  struct StreamBuffer_R001012_1213_1 st_var_1_1 = {0};
  struct StreamBuffer_R001012_1213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001012_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001012_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001012_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001012_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001012_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001012_0_2 + 9) & 15;
  union RegisterBank_R001012_1213_0 u_var_1;
  union RegisterBank_R001012_1213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001012_1213_0(sec_r001012_0_1, sec_r001012_1_1);
  int helper_flow_0_2 = fn_R001012_1213_0(sec_r001012_0_2, sec_r001012_1_2);
  fn_R001012_1213_0_2(sec_r001012_0_1, sec_r001012_1_1, sec_r001012_0_2, sec_r001012_1_2);
  int helper_flow_1_1 = fn_R001012_1213_1(sec_r001012_1_1, sec_r001012_2_1, pub_r001012_3_1, pub_r001012_4_1);
  int helper_flow_1_2 = fn_R001012_1213_1(sec_r001012_1_2, sec_r001012_2_2, pub_r001012_3_2, pub_r001012_4_2);
  fn_R001012_1213_1_2(sec_r001012_1_1, sec_r001012_2_1, pub_r001012_3_1, pub_r001012_4_1, sec_r001012_1_2, sec_r001012_2_2, pub_r001012_3_2, pub_r001012_4_2);
  int helper_flow_2_1 = fn_R001012_1213_2(sec_r001012_2_1, sec_r001012_3_1);
  int helper_flow_2_2 = fn_R001012_1213_2(sec_r001012_2_2, sec_r001012_3_2);
  fn_R001012_1213_2_2(sec_r001012_2_1, sec_r001012_3_1, sec_r001012_2_2, sec_r001012_3_2);
  int helper_flow_3_1 = fn_R001012_1213_3(sec_r001012_3_1, sec_r001012_4_1, pub_r001012_5_1, pub_r001012_6_1);
  int helper_flow_3_2 = fn_R001012_1213_3(sec_r001012_3_2, sec_r001012_4_2, pub_r001012_5_2, pub_r001012_6_2);
  fn_R001012_1213_3_2(sec_r001012_3_1, sec_r001012_4_1, pub_r001012_5_1, pub_r001012_6_1, sec_r001012_3_2, sec_r001012_4_2, pub_r001012_5_2, pub_r001012_6_2);
  int helper_flow_4_1 = fn_R001012_1213_4(sec_r001012_4_1, sec_r001012_5_1, pub_r001012_6_1, pub_r001012_7_1);
  int helper_flow_4_2 = fn_R001012_1213_4(sec_r001012_4_2, sec_r001012_5_2, pub_r001012_6_2, pub_r001012_7_2);
  fn_R001012_1213_4_2(sec_r001012_4_1, sec_r001012_5_1, pub_r001012_6_1, pub_r001012_7_1, sec_r001012_4_2, sec_r001012_5_2, pub_r001012_6_2, pub_r001012_7_2);
  int helper_flow_5_1 = fn_R001012_1213_5(sec_r001012_5_1, pub_r001012_6_1, pub_r001012_7_1, pub_r001012_8_1, pub_r001012_9_1);
  int helper_flow_5_2 = fn_R001012_1213_5(sec_r001012_5_2, pub_r001012_6_2, pub_r001012_7_2, pub_r001012_8_2, pub_r001012_9_2);
  fn_R001012_1213_5_2(sec_r001012_5_1, pub_r001012_6_1, pub_r001012_7_1, pub_r001012_8_1, pub_r001012_9_1, sec_r001012_5_2, pub_r001012_6_2, pub_r001012_7_2, pub_r001012_8_2, pub_r001012_9_2);
  int stage_v_0_1 = ((pub_r001012_10_1 * 2) + 33) & 63;
  int stage_v_0_2 = ((pub_r001012_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001012_7_1 * 2) + 11) & 63;
  int stage_v_1_2 = ((pub_r001012_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001012_3_1 * 3) + pub_r001012_4_1) + 30) & 127;
  int stage_v_2_2 = (((sec_r001012_3_2 * 3) + pub_r001012_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001012_1_1 * 2) + 31) & 63;
  int stage_v_3_2 = ((pub_r001012_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((helper_flow_2_1 * 3) + pub_r001012_15_1) + 25) & 127;
  int stage_v_4_2 = (((helper_flow_2_2 * 3) + pub_r001012_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = (((helper_flow_5_1 * 3) + pub_r001012_22_1) + 20) & 127;
  int stage_v_5_2 = (((helper_flow_5_2 * 3) + pub_r001012_22_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((sec_r001012_5_1 * 3) + pub_r001012_20_1) + 10) & 127;
  int stage_v_6_2 = (((sec_r001012_5_2 * 3) + pub_r001012_20_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = ((pub_r001012_15_1 * 2) + 13) & 63;
  int stage_v_7_2 = ((pub_r001012_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001012_18_1 * 2) + 41) & 63;
  int stage_v_8_2 = ((pub_r001012_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001012_22_1 * 2) + 20) & 63;
  int stage_v_9_2 = ((pub_r001012_22_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((helper_flow_4_1 * 3) + pub_r001012_21_1) + 36) & 127;
  int stage_v_10_2 = (((helper_flow_4_2 * 3) + pub_r001012_21_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001012_14_1 * 2) + 36) & 63;
  int stage_v_11_2 = ((pub_r001012_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001012_4_1 * 2) + 44) & 63;
  int stage_v_12_2 = ((pub_r001012_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001012_20_1 * 2) + 34) & 63;
  int stage_v_13_2 = ((pub_r001012_20_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((helper_flow_0_1 * 3) + pub_r001012_1_1) + 5) & 127;
  int stage_v_14_2 = (((helper_flow_0_2 * 3) + pub_r001012_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = ((pub_r001012_16_1 * 2) + 15) & 63;
  int stage_v_15_2 = ((pub_r001012_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001012_9_1 * 2) + 28) & 63;
  int stage_v_16_2 = ((pub_r001012_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((helper_flow_2_1 * 3) + pub_r001012_3_1) + 26) & 127;
  int stage_v_17_2 = (((helper_flow_2_2 * 3) + pub_r001012_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001012_0_1 * 2) + 50) & 63;
  int stage_v_18_2 = ((pub_r001012_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001012_1_1 * 2) + 7) & 63;
  int stage_v_19_2 = ((pub_r001012_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001012_6_1 * 2) + 24) & 63;
  int stage_v_20_2 = ((pub_r001012_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001012_8_1 * 2) + 40) & 63;
  int stage_v_21_2 = ((pub_r001012_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001012_15_1 * 2) + 19) & 63;
  int stage_v_22_2 = ((pub_r001012_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001012_9_1 * 2) + 35) & 63;
  int stage_v_23_2 = ((pub_r001012_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((sec_r001012_14_1 * 3) + pub_r001012_17_1) + 20) & 127;
  int stage_v_24_2 = (((sec_r001012_14_2 * 3) + pub_r001012_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((sec_r001012_11_1 * 3) + pub_r001012_13_1) + 38) & 127;
  int stage_v_25_2 = (((sec_r001012_11_2 * 3) + pub_r001012_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((sec_r001012_1_1 * 3) + pub_r001012_9_1) + 12) & 127;
  int stage_v_26_2 = (((sec_r001012_1_2 * 3) + pub_r001012_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = (((helper_flow_1_1 * 3) + pub_r001012_17_1) + 43) & 127;
  int stage_v_27_2 = (((helper_flow_1_2 * 3) + pub_r001012_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = ((pub_r001012_17_1 * 2) + 50) & 63;
  int stage_v_28_2 = ((pub_r001012_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((stage_v_24_1 * 3) + pub_r001012_6_1) + 18) & 127;
  int stage_v_29_2 = (((stage_v_24_2 * 3) + pub_r001012_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = ((pub_r001012_1_1 * 2) + 35) & 63;
  int stage_v_30_2 = ((pub_r001012_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((sec_r001012_4_1 * 3) + pub_r001012_22_1) + 19) & 127;
  int stage_v_31_2 = (((sec_r001012_4_2 * 3) + pub_r001012_22_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001012_4_1 * 2) + 47) & 63;
  int stage_v_32_2 = ((pub_r001012_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((stage_v_14_1 * 3) + pub_r001012_12_1) + 11) & 127;
  int stage_v_33_2 = (((stage_v_14_2 * 3) + pub_r001012_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((stage_v_27_1 * 3) + pub_r001012_13_1) + 12) & 127;
  int stage_v_34_2 = (((stage_v_27_2 * 3) + pub_r001012_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001012_5_1 * 2) + 47) & 63;
  int stage_v_35_2 = ((pub_r001012_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((sec_r001012_14_1 * 3) + pub_r001012_18_1) + 31) & 127;
  int stage_v_36_2 = (((sec_r001012_14_2 * 3) + pub_r001012_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001012_11_1 * 2) + 5) & 63;
  int stage_v_37_2 = ((pub_r001012_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((sec_r001012_3_1 * 3) + pub_r001012_3_1) + 11) & 127;
  int stage_v_38_2 = (((sec_r001012_3_2 * 3) + pub_r001012_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001012_8_1 * 2) + 38) & 63;
  int stage_v_39_2 = ((pub_r001012_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001012_18_1 * 2) + 41) & 63;
  int stage_v_40_2 = ((pub_r001012_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001012_14_1 * 2) + 19) & 63;
  int stage_v_41_2 = ((pub_r001012_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001012_10_1 * 2) + 25) & 63;
  int stage_v_42_2 = ((pub_r001012_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001012_13_1 * 2) + 35) & 63;
  int stage_v_43_2 = ((pub_r001012_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001012_20_1 * 2) + 5) & 63;
  int stage_v_44_2 = ((pub_r001012_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001012_21_1 * 2) + 25) & 63;
  int stage_v_45_2 = ((pub_r001012_21_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((sec_r001012_9_1 * 3) + pub_r001012_5_1) + 16) & 127;
  int stage_v_46_2 = (((sec_r001012_9_2 * 3) + pub_r001012_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001012_2_1 * 2) + 37) & 63;
  int stage_v_47_2 = ((pub_r001012_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001012_5_1 * 2) + 7) & 63;
  int stage_v_48_2 = ((pub_r001012_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001012_12_1 * 2) + 6) & 63;
  int stage_v_49_2 = ((pub_r001012_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001012_11_1 * 2) + 20) & 63;
  int stage_v_50_2 = ((pub_r001012_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001012_1_1 * 2) + 27) & 63;
  int stage_v_51_2 = ((pub_r001012_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001012_6_1 * 2) + 5) & 63;
  int stage_v_52_2 = ((pub_r001012_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001012_1_1 * 2) + 49) & 63;
  int stage_v_53_2 = ((pub_r001012_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001012_13_1 * 2) + 18) & 63;
  int stage_v_54_2 = ((pub_r001012_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001012_9_1 * 2) + 35) & 63;
  int stage_v_55_2 = ((pub_r001012_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001012_12_1 * 2) + 24) & 63;
  int stage_v_56_2 = ((pub_r001012_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001012_1_1 * 2) + 37) & 63;
  int stage_v_57_2 = ((pub_r001012_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((stage_v_24_1 * 3) + pub_r001012_20_1) + 34) & 127;
  int stage_v_58_2 = (((stage_v_24_2 * 3) + pub_r001012_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = ((pub_r001012_7_1 * 2) + 38) & 63;
  int stage_v_59_2 = ((pub_r001012_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001012_19_1 * 2) + 11) & 63;
  int stage_v_60_2 = ((pub_r001012_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001012_11_1 * 2) + 19) & 63;
  int stage_v_61_2 = ((pub_r001012_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001012_1_1 * 2) + 41) & 63;
  int stage_v_62_2 = ((pub_r001012_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001012_0_1 * 2) + 5) & 63;
  int stage_v_63_2 = ((pub_r001012_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001012_16_1 * 2) + 10) & 63;
  int stage_v_64_2 = ((pub_r001012_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001012_18_1 * 2) + 48) & 63;
  int stage_v_65_2 = ((pub_r001012_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((stage_v_34_1 * 3) + pub_r001012_21_1) + 35) & 127;
  int stage_v_66_2 = (((stage_v_34_2 * 3) + pub_r001012_21_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((sec_r001012_14_1 * 3) + pub_r001012_5_1) + 24) & 127;
  int stage_v_67_2 = (((sec_r001012_14_2 * 3) + pub_r001012_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = ((pub_r001012_13_1 * 2) + 36) & 63;
  int stage_v_68_2 = ((pub_r001012_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001012_14_1 * 2) + 14) & 63;
  int stage_v_69_2 = ((pub_r001012_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001012_6_1 * 2) + 28) & 63;
  int stage_v_70_2 = ((pub_r001012_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001012_8_1 * 2) + 32) & 63;
  int stage_v_71_2 = ((pub_r001012_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((helper_flow_4_1 * 3) + pub_r001012_0_1) + 10) & 127;
  int stage_v_72_2 = (((helper_flow_4_2 * 3) + pub_r001012_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001012_19_1 * 2) + 26) & 63;
  int stage_v_73_2 = ((pub_r001012_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001012_0_1 * 2) + 5) & 63;
  int stage_v_74_2 = ((pub_r001012_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001012_0_1 * 2) + 13) & 63;
  int stage_v_75_2 = ((pub_r001012_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001012_6_1 * 2) + 44) & 63;
  int stage_v_76_2 = ((pub_r001012_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001012_0_1 * 2) + 50) & 63;
  int stage_v_77_2 = ((pub_r001012_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001012_10_1 * 2) + 42) & 63;
  int stage_v_78_2 = ((pub_r001012_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001012_0_1 * 2) + 36) & 63;
  int stage_v_79_2 = ((pub_r001012_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((stage_v_4_1 * 3) + pub_r001012_5_1) + 32) & 127;
  int stage_v_80_2 = (((stage_v_4_2 * 3) + pub_r001012_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = ((pub_r001012_10_1 * 2) + 46) & 63;
  int stage_v_81_2 = ((pub_r001012_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001012_20_1 * 2) + 20) & 63;
  int stage_v_82_2 = ((pub_r001012_20_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001012_22_1 * 2) + 12) & 63;
  int stage_v_83_2 = ((pub_r001012_22_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001012_15_1 * 2) + 49) & 63;
  int stage_v_84_2 = ((pub_r001012_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((stage_v_25_1 * 3) + pub_r001012_22_1) + 20) & 127;
  int stage_v_85_2 = (((stage_v_25_2 * 3) + pub_r001012_22_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = (((helper_flow_0_1 * 3) + pub_r001012_9_1) + 11) & 127;
  int stage_v_86_2 = (((helper_flow_0_2 * 3) + pub_r001012_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001012_5_1 * 2) + 12) & 63;
  int stage_v_87_2 = ((pub_r001012_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001012_15_1 * 2) + 24) & 63;
  int stage_v_88_2 = ((pub_r001012_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((sec_r001012_4_1 * 3) + pub_r001012_8_1) + 7) & 127;
  int stage_v_89_2 = (((sec_r001012_4_2 * 3) + pub_r001012_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((sec_r001012_7_1 * 3) + pub_r001012_2_1) + 18) & 127;
  int stage_v_90_2 = (((sec_r001012_7_2 * 3) + pub_r001012_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001012_10_1 * 2) + 18) & 63;
  int stage_v_91_2 = ((pub_r001012_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_14_1 * 3) + pub_r001012_5_1) + 42) & 127;
  int stage_v_92_2 = (((stage_v_14_2 * 3) + pub_r001012_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001012_6_1 * 2) + 48) & 63;
  int stage_v_93_2 = ((pub_r001012_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001012_13_1 * 2) + 14) & 63;
  int stage_v_94_2 = ((pub_r001012_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001012_0_1 * 2) + 7) & 63;
  int stage_v_95_2 = ((pub_r001012_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001012_3_1 * 2) + 41) & 63;
  int stage_v_96_2 = ((pub_r001012_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001012_16_1 * 2) + 13) & 63;
  int stage_v_97_2 = ((pub_r001012_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((sec_r001012_10_1 * 3) + pub_r001012_13_1) + 8) & 127;
  int stage_v_98_2 = (((sec_r001012_10_2 * 3) + pub_r001012_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = ((pub_r001012_5_1 * 2) + 19) & 63;
  int stage_v_99_2 = ((pub_r001012_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001012_14_1 * 2) + 48) & 63;
  int stage_v_100_2 = ((pub_r001012_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001012_15_1 * 2) + 38) & 63;
  int stage_v_101_2 = ((pub_r001012_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001012_13_1 * 2) + 12) & 63;
  int stage_v_102_2 = ((pub_r001012_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001012_18_1 * 2) + 48) & 63;
  int stage_v_103_2 = ((pub_r001012_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001012_12_1 * 2) + 24) & 63;
  int stage_v_104_2 = ((pub_r001012_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001012_12_1 * 2) + 23) & 63;
  int stage_v_105_2 = ((pub_r001012_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001012_10_1 * 2) + 32) & 63;
  int stage_v_106_2 = ((pub_r001012_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001012_15_1 * 2) + 39) & 63;
  int stage_v_107_2 = ((pub_r001012_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001012_16_1 * 2) + 27) & 63;
  int stage_v_108_2 = ((pub_r001012_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_46_1 * 3) + pub_r001012_13_1) + 19) & 127;
  int stage_v_109_2 = (((stage_v_46_2 * 3) + pub_r001012_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001012_2_1 * 2) + 14) & 63;
  int stage_v_110_2 = ((pub_r001012_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001012_17_1 * 2) + 18) & 63;
  int stage_v_111_2 = ((pub_r001012_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001012_21_1 * 2) + 8) & 63;
  int stage_v_112_2 = ((pub_r001012_21_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_98_1 * 3) + pub_r001012_17_1) + 7) & 127;
  int stage_v_113_2 = (((stage_v_98_2 * 3) + pub_r001012_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001012_8_1 * 2) + 28) & 63;
  int stage_v_114_2 = ((pub_r001012_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001012_5_1 * 2) + 49) & 63;
  int stage_v_115_2 = ((pub_r001012_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((sec_r001012_11_1 * 3) + pub_r001012_14_1) + 6) & 127;
  int stage_v_116_2 = (((sec_r001012_11_2 * 3) + pub_r001012_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = ((pub_r001012_9_1 * 2) + 7) & 63;
  int stage_v_117_2 = ((pub_r001012_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001012_14_1 * 2) + 25) & 63;
  int stage_v_118_2 = ((pub_r001012_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((helper_flow_4_1 * 3) + pub_r001012_14_1) + 15) & 127;
  int stage_v_119_2 = (((helper_flow_4_2 * 3) + pub_r001012_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = ((pub_r001012_5_1 * 2) + 33) & 63;
  int stage_v_120_2 = ((pub_r001012_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001012_0_1 * 2) + 20) & 63;
  int stage_v_121_2 = ((pub_r001012_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001012_7_1 * 2) + 15) & 63;
  int stage_v_122_2 = ((pub_r001012_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_80_1 * 3) + pub_r001012_3_1) + 9) & 127;
  int stage_v_123_2 = (((stage_v_80_2 * 3) + pub_r001012_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = ((pub_r001012_1_1 * 2) + 19) & 63;
  int stage_v_124_2 = ((pub_r001012_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001012_9_1 * 2) + 21) & 63;
  int stage_v_125_2 = ((pub_r001012_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001012_18_1 * 2) + 5) & 63;
  int stage_v_126_2 = ((pub_r001012_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((sec_r001012_8_1 * 3) + pub_r001012_20_1) + 8) & 127;
  int stage_v_127_2 = (((sec_r001012_8_2 * 3) + pub_r001012_20_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = ((pub_r001012_14_1 * 2) + 46) & 63;
  int stage_v_128_2 = ((pub_r001012_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((helper_flow_2_1 * 3) + pub_r001012_2_1) + 44) & 127;
  int stage_v_129_2 = (((helper_flow_2_2 * 3) + pub_r001012_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001012_14_1 * 2) + 21) & 63;
  int stage_v_130_2 = ((pub_r001012_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((sec_r001012_8_1 * 3) + pub_r001012_8_1) + 35) & 127;
  int stage_v_131_2 = (((sec_r001012_8_2 * 3) + pub_r001012_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = ((pub_r001012_16_1 * 2) + 31) & 63;
  int stage_v_132_2 = ((pub_r001012_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_85_1 * 3) + pub_r001012_18_1) + 17) & 127;
  int stage_v_133_2 = (((stage_v_85_2 * 3) + pub_r001012_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_67_1 * 3) + pub_r001012_10_1) + 5) & 127;
  int stage_v_134_2 = (((stage_v_67_2 * 3) + pub_r001012_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = ((pub_r001012_19_1 * 2) + 31) & 63;
  int stage_v_135_2 = ((pub_r001012_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001012_21_1 * 2) + 28) & 63;
  int stage_v_136_2 = ((pub_r001012_21_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001012_6_1 * 2) + 27) & 63;
  int stage_v_137_2 = ((pub_r001012_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_26_1 * 3) + pub_r001012_18_1) + 9) & 127;
  int stage_v_138_2 = (((stage_v_26_2 * 3) + pub_r001012_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001012_21_1 * 2) + 26) & 63;
  int stage_v_139_2 = ((pub_r001012_21_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((stage_v_2_1 * 3) + pub_r001012_9_1) + 24) & 127;
  int stage_v_140_2 = (((stage_v_2_2 * 3) + pub_r001012_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((stage_v_24_1 * 3) + pub_r001012_3_1) + 12) & 127;
  int stage_v_141_2 = (((stage_v_24_2 * 3) + pub_r001012_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = ((pub_r001012_5_1 * 2) + 19) & 63;
  int stage_v_142_2 = ((pub_r001012_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((stage_v_86_1 * 3) + pub_r001012_6_1) + 9) & 127;
  int stage_v_143_2 = (((stage_v_86_2 * 3) + pub_r001012_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((stage_v_119_1 * 3) + pub_r001012_3_1) + 40) & 127;
  int stage_v_144_2 = (((stage_v_119_2 * 3) + pub_r001012_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = ((pub_r001012_10_1 * 2) + 45) & 63;
  int stage_v_145_2 = ((pub_r001012_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001012_6_1 * 2) + 9) & 63;
  int stage_v_146_2 = ((pub_r001012_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001012_16_1 * 2) + 26) & 63;
  int stage_v_147_2 = ((pub_r001012_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_67_1 * 3) + pub_r001012_4_1) + 42) & 127;
  int stage_v_148_2 = (((stage_v_67_2 * 3) + pub_r001012_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((sec_r001012_2_1 * 3) + pub_r001012_20_1) + 22) & 127;
  int stage_v_149_2 = (((sec_r001012_2_2 * 3) + pub_r001012_20_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = ((pub_r001012_15_1 * 2) + 11) & 63;
  int stage_v_150_2 = ((pub_r001012_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((stage_v_2_1 * 3) + pub_r001012_9_1) + 7) & 127;
  int stage_v_151_2 = (((stage_v_2_2 * 3) + pub_r001012_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = ((pub_r001012_13_1 * 2) + 17) & 63;
  int stage_v_152_2 = ((pub_r001012_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((sec_r001012_8_1 * 3) + pub_r001012_0_1) + 10) & 127;
  int stage_v_153_2 = (((sec_r001012_8_2 * 3) + pub_r001012_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = ((pub_r001012_8_1 * 2) + 48) & 63;
  int stage_v_154_2 = ((pub_r001012_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_58_1 * 3) + pub_r001012_2_1) + 5) & 127;
  int stage_v_155_2 = (((stage_v_58_2 * 3) + pub_r001012_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = ((pub_r001012_5_1 * 2) + 26) & 63;
  int stage_v_156_2 = ((pub_r001012_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (((stage_v_113_1 * 3) + pub_r001012_7_1) + 14) & 127;
  int stage_v_157_2 = (((stage_v_113_2 * 3) + pub_r001012_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001012_18_1 * 2) + 43) & 63;
  int stage_v_158_2 = ((pub_r001012_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((sec_r001012_0_1 * 3) + pub_r001012_19_1) + 13) & 127;
  int stage_v_159_2 = (((sec_r001012_0_2 * 3) + pub_r001012_19_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_127_1 * 3) + pub_r001012_17_1) + 35) & 127;
  int stage_v_160_2 = (((stage_v_127_2 * 3) + pub_r001012_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((stage_v_160_1 * 3) + pub_r001012_10_1) + 21) & 127;
  int stage_v_161_2 = (((stage_v_160_2 * 3) + pub_r001012_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001012_19_1 * 2) + 37) & 63;
  int stage_v_162_2 = ((pub_r001012_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001012_9_1 * 2) + 44) & 63;
  int stage_v_163_2 = ((pub_r001012_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001012_0_1 * 2) + 36) & 63;
  int stage_v_164_2 = ((pub_r001012_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001012_15_1 * 2) + 18) & 63;
  int stage_v_165_2 = ((pub_r001012_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001012_19_1 * 2) + 42) & 63;
  int stage_v_166_2 = ((pub_r001012_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_98_1 * 3) + pub_r001012_5_1) + 30) & 127;
  int stage_v_167_2 = (((stage_v_98_2 * 3) + pub_r001012_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001012_16_1 * 2) + 28) & 63;
  int stage_v_168_2 = ((pub_r001012_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001012_2_1 * 2) + 37) & 63;
  int stage_v_169_2 = ((pub_r001012_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_153_1 * 3) + pub_r001012_20_1) + 45) & 127;
  int stage_v_170_2 = (((stage_v_153_2 * 3) + pub_r001012_20_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001012_17_1 * 2) + 40) & 63;
  int stage_v_171_2 = ((pub_r001012_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001012_22_1 * 2) + 38) & 63;
  int stage_v_172_2 = ((pub_r001012_22_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001012_6_1 * 2) + 10) & 63;
  int stage_v_173_2 = ((pub_r001012_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_17_1 * 3) + pub_r001012_21_1) + 34) & 127;
  int stage_v_174_2 = (((stage_v_17_2 * 3) + pub_r001012_21_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001012_4_1 * 2) + 27) & 63;
  int stage_v_175_2 = ((pub_r001012_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001012_2_1 * 2) + 39) & 63;
  int stage_v_176_2 = ((pub_r001012_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001012_8_1 * 2) + 14) & 63;
  int stage_v_177_2 = ((pub_r001012_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001012_2_1 * 2) + 7) & 63;
  int stage_v_178_2 = ((pub_r001012_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((stage_v_17_1 * 3) + pub_r001012_5_1) + 19) & 127;
  int stage_v_179_2 = (((stage_v_17_2 * 3) + pub_r001012_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = ((pub_r001012_6_1 * 2) + 41) & 63;
  int stage_v_180_2 = ((pub_r001012_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001012_2_1 * 2) + 10) & 63;
  int stage_v_181_2 = ((pub_r001012_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001012_14_1 * 2) + 41) & 63;
  int stage_v_182_2 = ((pub_r001012_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001012_3_1 * 2) + 46) & 63;
  int stage_v_183_2 = ((pub_r001012_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001012_2_1 * 2) + 24) & 63;
  int stage_v_184_2 = ((pub_r001012_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_80_1 * 3) + pub_r001012_9_1) + 15) & 127;
  int stage_v_185_2 = (((stage_v_80_2 * 3) + pub_r001012_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001012_10_1 * 2) + 46) & 63;
  int stage_v_186_2 = ((pub_r001012_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001012_19_1 * 2) + 35) & 63;
  int stage_v_187_2 = ((pub_r001012_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_151_1 * 3) + pub_r001012_8_1) + 9) & 127;
  int stage_v_188_2 = (((stage_v_151_2 * 3) + pub_r001012_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001012_16_1 * 2) + 25) & 63;
  int stage_v_189_2 = ((pub_r001012_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_141_1 * 3) + pub_r001012_12_1) + 9) & 127;
  int stage_v_190_2 = (((stage_v_141_2 * 3) + pub_r001012_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001012_12_1 * 2) + 40) & 63;
  int stage_v_191_2 = ((pub_r001012_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001012_22_1 * 2) + 27) & 63;
  int stage_v_192_2 = ((pub_r001012_22_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((sec_r001012_3_1 * 3) + pub_r001012_20_1) + 45) & 127;
  int stage_v_193_2 = (((sec_r001012_3_2 * 3) + pub_r001012_20_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001012_19_1 * 2) + 46) & 63;
  int stage_v_194_2 = ((pub_r001012_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((stage_v_29_1 * 3) + pub_r001012_20_1) + 19) & 127;
  int stage_v_195_2 = (((stage_v_29_2 * 3) + pub_r001012_20_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001012_12_1 * 2) + 30) & 63;
  int stage_v_196_2 = ((pub_r001012_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001012_19_1 * 2) + 38) & 63;
  int stage_v_197_2 = ((pub_r001012_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001012_9_1 * 2) + 27) & 63;
  int stage_v_198_2 = ((pub_r001012_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_159_1 * 3) + pub_r001012_1_1) + 22) & 127;
  int stage_v_199_2 = (((stage_v_159_2 * 3) + pub_r001012_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001012_22_1 * 2) + 5) & 63;
  int stage_v_200_2 = ((pub_r001012_22_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_33_1 * 3) + pub_r001012_21_1) + 42) & 127;
  int stage_v_201_2 = (((stage_v_33_2 * 3) + pub_r001012_21_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = ((pub_r001012_11_1 * 2) + 50) & 63;
  int stage_v_202_2 = ((pub_r001012_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((stage_v_144_1 * 3) + pub_r001012_5_1) + 21) & 127;
  int stage_v_203_2 = (((stage_v_144_2 * 3) + pub_r001012_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = ((pub_r001012_21_1 * 2) + 32) & 63;
  int stage_v_204_2 = ((pub_r001012_21_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001012_6_1 * 2) + 23) & 63;
  int stage_v_205_2 = ((pub_r001012_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001012_19_1 * 2) + 22) & 63;
  int stage_v_206_2 = ((pub_r001012_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001012_0_1 * 2) + 49) & 63;
  int stage_v_207_2 = ((pub_r001012_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = (((helper_flow_5_1 * 3) + pub_r001012_8_1) + 43) & 127;
  int stage_v_208_2 = (((helper_flow_5_2 * 3) + pub_r001012_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = (((sec_r001012_3_1 * 3) + pub_r001012_13_1) + 7) & 127;
  int stage_v_209_2 = (((sec_r001012_3_2 * 3) + pub_r001012_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = ((pub_r001012_17_1 * 2) + 26) & 63;
  int stage_v_210_2 = ((pub_r001012_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_89_1 * 3) + pub_r001012_16_1) + 7) & 127;
  int stage_v_211_2 = (((stage_v_89_2 * 3) + pub_r001012_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_138_1 * 3) + pub_r001012_19_1) + 41) & 127;
  int stage_v_212_2 = (((stage_v_138_2 * 3) + pub_r001012_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_119_1 * 3) + pub_r001012_9_1) + 32) & 127;
  int stage_v_213_2 = (((stage_v_119_2 * 3) + pub_r001012_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001012_4_1 * 2) + 32) & 63;
  int stage_v_214_2 = ((pub_r001012_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001012_8_1 * 2) + 7) & 63;
  int stage_v_215_2 = ((pub_r001012_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001012_16_1 * 2) + 47) & 63;
  int stage_v_216_2 = ((pub_r001012_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001012_18_1 * 2) + 15) & 63;
  int stage_v_217_2 = ((pub_r001012_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((stage_v_185_1 * 3) + pub_r001012_15_1) + 45) & 127;
  int stage_v_218_2 = (((stage_v_185_2 * 3) + pub_r001012_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = ((pub_r001012_21_1 * 2) + 35) & 63;
  int stage_v_219_2 = ((pub_r001012_21_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_185_1 * 3) + pub_r001012_2_1) + 34) & 127;
  int stage_v_220_2 = (((stage_v_185_2 * 3) + pub_r001012_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_159_1 * 3) + pub_r001012_1_1) + 37) & 127;
  int stage_v_221_2 = (((stage_v_159_2 * 3) + pub_r001012_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = ((pub_r001012_7_1 * 2) + 9) & 63;
  int stage_v_222_2 = ((pub_r001012_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001012_14_1 * 2) + 7) & 63;
  int stage_v_223_2 = ((pub_r001012_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001012_20_1 * 2) + 15) & 63;
  int stage_v_224_2 = ((pub_r001012_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_25_1 * 3) + pub_r001012_1_1) + 38) & 127;
  int stage_v_225_2 = (((stage_v_25_2 * 3) + pub_r001012_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((sec_r001012_3_1 * 3) + pub_r001012_13_1) + 8) & 127;
  int stage_v_226_2 = (((sec_r001012_3_2 * 3) + pub_r001012_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = ((pub_r001012_19_1 * 2) + 8) & 63;
  int stage_v_227_2 = ((pub_r001012_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001012_19_1 * 2) + 8) & 63;
  int stage_v_228_2 = ((pub_r001012_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_10_1 * 3) + pub_r001012_1_1) + 44) & 127;
  int stage_v_229_2 = (((stage_v_10_2 * 3) + pub_r001012_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001012_4_1 * 2) + 47) & 63;
  int stage_v_230_2 = ((pub_r001012_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((sec_r001012_9_1 * 3) + pub_r001012_3_1) + 37) & 127;
  int stage_v_231_2 = (((sec_r001012_9_2 * 3) + pub_r001012_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001012_20_1 * 2) + 8) & 63;
  int stage_v_232_2 = ((pub_r001012_20_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001012_20_1 * 2) + 48) & 63;
  int stage_v_233_2 = ((pub_r001012_20_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001012_22_1 * 2) + 29) & 63;
  int stage_v_234_2 = ((pub_r001012_22_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001012_3_1 * 2) + 27) & 63;
  int stage_v_235_2 = ((pub_r001012_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001012_11_1 * 2) + 19) & 63;
  int stage_v_236_2 = ((pub_r001012_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001012_0_1 * 2) + 14) & 63;
  int stage_v_237_2 = ((pub_r001012_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = (((stage_v_6_1 * 3) + pub_r001012_15_1) + 23) & 127;
  int stage_v_238_2 = (((stage_v_6_2 * 3) + pub_r001012_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = (((stage_v_155_1 * 3) + pub_r001012_10_1) + 10) & 127;
  int stage_v_239_2 = (((stage_v_155_2 * 3) + pub_r001012_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((stage_v_67_1 * 3) + pub_r001012_12_1) + 25) & 127;
  int stage_v_240_2 = (((stage_v_67_2 * 3) + pub_r001012_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = ((pub_r001012_11_1 * 2) + 36) & 63;
  int stage_v_241_2 = ((pub_r001012_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001012_13_1 * 2) + 39) & 63;
  int stage_v_242_2 = ((pub_r001012_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((stage_v_212_1 * 3) + pub_r001012_12_1) + 11) & 127;
  int stage_v_243_2 = (((stage_v_212_2 * 3) + pub_r001012_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001012_16_1 * 2) + 38) & 63;
  int stage_v_244_2 = ((pub_r001012_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = (((stage_v_157_1 * 3) + pub_r001012_18_1) + 11) & 127;
  int stage_v_245_2 = (((stage_v_157_2 * 3) + pub_r001012_18_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001012_10_1 * 2) + 46) & 63;
  int stage_v_246_2 = ((pub_r001012_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001012_12_1 * 2) + 28) & 63;
  int stage_v_247_2 = ((pub_r001012_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001012_11_1 * 2) + 37) & 63;
  int stage_v_248_2 = ((pub_r001012_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001012_16_1 * 2) + 27) & 63;
  int stage_v_249_2 = ((pub_r001012_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001012_1_1 * 2) + 17) & 63;
  int stage_v_250_2 = ((pub_r001012_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001012_10_1 * 2) + 35) & 63;
  int stage_v_251_2 = ((pub_r001012_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((stage_v_6_1 * 3) + pub_r001012_11_1) + 17) & 127;
  int stage_v_252_2 = (((stage_v_6_2 * 3) + pub_r001012_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = ((pub_r001012_18_1 * 2) + 40) & 63;
  int stage_v_253_2 = ((pub_r001012_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001012_11_1 * 2) + 12) & 63;
  int stage_v_254_2 = ((pub_r001012_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = (((sec_r001012_10_1 * 3) + pub_r001012_12_1) + 42) & 127;
  int stage_v_255_2 = (((sec_r001012_10_2 * 3) + pub_r001012_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = (((stage_v_67_1 * 3) + pub_r001012_15_1) + 36) & 127;
  int stage_v_256_2 = (((stage_v_67_2 * 3) + pub_r001012_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001012_21_1 * 2) + 11) & 63;
  int stage_v_257_2 = ((pub_r001012_21_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((sec_r001012_8_1 * 3) + pub_r001012_13_1) + 44) & 127;
  int stage_v_258_2 = (((sec_r001012_8_2 * 3) + pub_r001012_13_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001012_21_1 * 2) + 49) & 63;
  int stage_v_259_2 = ((pub_r001012_21_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001012_1_1 * 2) + 36) & 63;
  int stage_v_260_2 = ((pub_r001012_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_211_1 * 3) + pub_r001012_7_1) + 18) & 127;
  int stage_v_261_2 = (((stage_v_211_2 * 3) + pub_r001012_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = (((stage_v_225_1 * 3) + pub_r001012_3_1) + 37) & 127;
  int stage_v_262_2 = (((stage_v_225_2 * 3) + pub_r001012_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = ((pub_r001012_10_1 * 2) + 27) & 63;
  int stage_v_263_2 = ((pub_r001012_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001012_22_1 * 2) + 43) & 63;
  int stage_v_264_2 = ((pub_r001012_22_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_119_1 * 3) + pub_r001012_0_1) + 22) & 127;
  int stage_v_265_2 = (((stage_v_119_2 * 3) + pub_r001012_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = ((pub_r001012_21_1 * 2) + 44) & 63;
  int stage_v_266_2 = ((pub_r001012_21_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001012_15_1 * 2) + 20) & 63;
  int stage_v_267_2 = ((pub_r001012_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((helper_flow_1_1 * 3) + pub_r001012_0_1) + 24) & 127;
  int stage_v_268_2 = (((helper_flow_1_2 * 3) + pub_r001012_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001012_8_1 * 2) + 23) & 63;
  int stage_v_269_2 = ((pub_r001012_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001012_7_1 * 2) + 34) & 63;
  int stage_v_270_2 = ((pub_r001012_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001012_8_1 * 2) + 28) & 63;
  int stage_v_271_2 = ((pub_r001012_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001012_9_1 * 2) + 37) & 63;
  int stage_v_272_2 = ((pub_r001012_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001012_7_1 * 2) + 5) & 63;
  int stage_v_273_2 = ((pub_r001012_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001012_4_1 * 2) + 28) & 63;
  int stage_v_274_2 = ((pub_r001012_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001012_19_1 * 2) + 21) & 63;
  int stage_v_275_2 = ((pub_r001012_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001012_4_1 * 2) + 9) & 63;
  int stage_v_276_2 = ((pub_r001012_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001012_21_1 * 2) + 6) & 63;
  int stage_v_277_2 = ((pub_r001012_21_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((stage_v_17_1 * 3) + pub_r001012_5_1) + 24) & 127;
  int stage_v_278_2 = (((stage_v_17_2 * 3) + pub_r001012_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001012_11_1 * 2) + 46) & 63;
  int stage_v_279_2 = ((pub_r001012_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((helper_flow_4_1 * 3) + pub_r001012_22_1) + 21) & 127;
  int stage_v_280_2 = (((helper_flow_4_2 * 3) + pub_r001012_22_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((sec_r001012_16_1 * 3) + pub_r001012_4_1) + 22) & 127;
  int stage_v_281_2 = (((sec_r001012_16_2 * 3) + pub_r001012_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001012_13_1 * 2) + 42) & 63;
  int stage_v_282_2 = ((pub_r001012_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001012_7_1 * 2) + 35) & 63;
  int stage_v_283_2 = ((pub_r001012_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001012_14_1 * 2) + 28) & 63;
  int stage_v_284_2 = ((pub_r001012_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001012_17_1 * 2) + 26) & 63;
  int stage_v_285_2 = ((pub_r001012_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001012_1_1 * 2) + 37) & 63;
  int stage_v_286_2 = ((pub_r001012_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001012_17_1 * 2) + 36) & 63;
  int stage_v_287_2 = ((pub_r001012_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001012_20_1 * 2) + 6) & 63;
  int stage_v_288_2 = ((pub_r001012_20_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_24_1 * 3) + pub_r001012_9_1) + 15) & 127;
  int stage_v_289_2 = (((stage_v_24_2 * 3) + pub_r001012_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_2_1 * 3) + pub_r001012_5_1) + 32) & 127;
  int stage_v_290_2 = (((stage_v_2_2 * 3) + pub_r001012_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((stage_v_174_1 * 3) + pub_r001012_1_1) + 3) & 127;
  int stage_v_291_2 = (((stage_v_174_2 * 3) + pub_r001012_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = (((stage_v_85_1 * 3) + pub_r001012_21_1) + 31) & 127;
  int stage_v_292_2 = (((stage_v_85_2 * 3) + pub_r001012_21_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = ((pub_r001012_20_1 * 2) + 27) & 63;
  int stage_v_293_2 = ((pub_r001012_20_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_252_1 * 3) + pub_r001012_14_1) + 29) & 127;
  int stage_v_294_2 = (((stage_v_252_2 * 3) + pub_r001012_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_119_1 * 3) + pub_r001012_21_1) + 14) & 127;
  int stage_v_295_2 = (((stage_v_119_2 * 3) + pub_r001012_21_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001012_18_1 * 2) + 6) & 63;
  int stage_v_296_2 = ((pub_r001012_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001012_18_1 * 2) + 10) & 63;
  int stage_v_297_2 = ((pub_r001012_18_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001012_2_1 * 2) + 34) & 63;
  int stage_v_298_2 = ((pub_r001012_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001012_11_1 * 2) + 36) & 63;
  int stage_v_299_2 = ((pub_r001012_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001012_22_1 * 2) + 21) & 63;
  int stage_v_300_2 = ((pub_r001012_22_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001012_13_1 * 2) + 20) & 63;
  int stage_v_301_2 = ((pub_r001012_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001012_19_1 * 2) + 14) & 63;
  int stage_v_302_2 = ((pub_r001012_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_245_1 * 3) + pub_r001012_20_1) + 38) & 127;
  int stage_v_303_2 = (((stage_v_245_2 * 3) + pub_r001012_20_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001012_14_1 * 2) + 24) & 63;
  int stage_v_304_2 = ((pub_r001012_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001012_11_1 * 2) + 31) & 63;
  int stage_v_305_2 = ((pub_r001012_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001012_11_1 * 2) + 30) & 63;
  int stage_v_306_2 = ((pub_r001012_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001012_10_1 * 2) + 31) & 63;
  int stage_v_307_2 = ((pub_r001012_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001012_13_1 * 2) + 5) & 63;
  int stage_v_308_2 = ((pub_r001012_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001012_15_1 * 2) + 20) & 63;
  int stage_v_309_2 = ((pub_r001012_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001012_15_1 * 2) + 39) & 63;
  int stage_v_310_2 = ((pub_r001012_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((helper_flow_2_1 * 3) + pub_r001012_14_1) + 33) & 127;
  int stage_v_311_2 = (((helper_flow_2_2 * 3) + pub_r001012_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = (((stage_v_127_1 * 3) + pub_r001012_5_1) + 35) & 127;
  int stage_v_312_2 = (((stage_v_127_2 * 3) + pub_r001012_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = (((sec_r001012_0_1 * 3) + pub_r001012_5_1) + 20) & 127;
  int stage_v_313_2 = (((sec_r001012_0_2 * 3) + pub_r001012_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = (((stage_v_193_1 * 3) + pub_r001012_17_1) + 18) & 127;
  int stage_v_314_2 = (((stage_v_193_2 * 3) + pub_r001012_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = ((pub_r001012_17_1 * 2) + 31) & 63;
  int stage_v_315_2 = ((pub_r001012_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001012_20_1 * 2) + 36) & 63;
  int stage_v_316_2 = ((pub_r001012_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = (((sec_r001012_0_1 * 3) + pub_r001012_6_1) + 16) & 127;
  int stage_v_317_2 = (((sec_r001012_0_2 * 3) + pub_r001012_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001012_5_1 * 2) + 41) & 63;
  int stage_v_318_2 = ((pub_r001012_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001012_8_1 * 2) + 31) & 63;
  int stage_v_319_2 = ((pub_r001012_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001012_3_1 * 2) + 31) & 63;
  int stage_v_320_2 = ((pub_r001012_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((stage_v_33_1 * 3) + pub_r001012_12_1) + 5) & 127;
  int stage_v_321_2 = (((stage_v_33_2 * 3) + pub_r001012_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_5_1 * 3) + pub_r001012_11_1) + 27) & 127;
  int stage_v_322_2 = (((stage_v_5_2 * 3) + pub_r001012_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = (((stage_v_161_1 * 3) + pub_r001012_2_1) + 9) & 127;
  int stage_v_323_2 = (((stage_v_161_2 * 3) + pub_r001012_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((stage_v_190_1 * 3) + pub_r001012_12_1) + 21) & 127;
  int stage_v_324_2 = (((stage_v_190_2 * 3) + pub_r001012_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_46_1 * 3) + pub_r001012_7_1) + 12) & 127;
  int stage_v_325_2 = (((stage_v_46_2 * 3) + pub_r001012_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001012_22_1 * 2) + 47) & 63;
  int stage_v_326_2 = ((pub_r001012_22_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001012_21_1 * 2) + 21) & 63;
  int stage_v_327_2 = ((pub_r001012_21_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001012_18_1 * 2) + 47) & 63;
  int stage_v_328_2 = ((pub_r001012_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001012_5_1 * 2) + 50) & 63;
  int stage_v_329_2 = ((pub_r001012_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = (((stage_v_2_1 * 3) + pub_r001012_22_1) + 21) & 127;
  int stage_v_330_2 = (((stage_v_2_2 * 3) + pub_r001012_22_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001012_3_1 * 2) + 8) & 63;
  int stage_v_331_2 = ((pub_r001012_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001012_2_1 * 2) + 10) & 63;
  int stage_v_332_2 = ((pub_r001012_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001012_2_1 * 2) + 7) & 63;
  int stage_v_333_2 = ((pub_r001012_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001012_11_1 * 2) + 31) & 63;
  int stage_v_334_2 = ((pub_r001012_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001012_10_1 * 2) + 7) & 63;
  int stage_v_335_2 = ((pub_r001012_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001012_19_1 * 2) + 17) & 63;
  int stage_v_336_2 = ((pub_r001012_19_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001012_3_1 * 2) + 26) & 63;
  int stage_v_337_2 = ((pub_r001012_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = (((stage_v_67_1 * 3) + pub_r001012_19_1) + 24) & 127;
  int stage_v_338_2 = (((stage_v_67_2 * 3) + pub_r001012_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((stage_v_289_1 * 3) + pub_r001012_9_1) + 31) & 127;
  int stage_v_339_2 = (((stage_v_289_2 * 3) + pub_r001012_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001012_12_1 * 2) + 44) & 63;
  int stage_v_340_2 = ((pub_r001012_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001012_13_1 * 2) + 32) & 63;
  int stage_v_341_2 = ((pub_r001012_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = (((sec_r001012_9_1 * 3) + pub_r001012_21_1) + 18) & 127;
  int stage_v_342_2 = (((sec_r001012_9_2 * 3) + pub_r001012_21_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = ((pub_r001012_8_1 * 2) + 46) & 63;
  int stage_v_343_2 = ((pub_r001012_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001012_3_1 * 2) + 29) & 63;
  int stage_v_344_2 = ((pub_r001012_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((stage_v_14_1 * 3) + pub_r001012_9_1) + 5) & 127;
  int stage_v_345_2 = (((stage_v_14_2 * 3) + pub_r001012_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = ((pub_r001012_2_1 * 2) + 37) & 63;
  int stage_v_346_2 = ((pub_r001012_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001012_14_1 * 2) + 45) & 63;
  int stage_v_347_2 = ((pub_r001012_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001012_19_1 * 2) + 23) & 63;
  int stage_v_348_2 = ((pub_r001012_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = (((stage_v_252_1 * 3) + pub_r001012_21_1) + 20) & 127;
  int stage_v_349_2 = (((stage_v_252_2 * 3) + pub_r001012_21_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_203_1 * 3) + pub_r001012_13_1) + 17) & 127;
  int stage_v_350_2 = (((stage_v_203_2 * 3) + pub_r001012_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_80_1 * 3) + pub_r001012_21_1) + 43) & 127;
  int stage_v_351_2 = (((stage_v_80_2 * 3) + pub_r001012_21_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_24_1 * 3) + pub_r001012_15_1) + 13) & 127;
  int stage_v_352_2 = (((stage_v_24_2 * 3) + pub_r001012_15_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = ((pub_r001012_13_1 * 2) + 44) & 63;
  int stage_v_353_2 = ((pub_r001012_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001012_7_1 * 2) + 42) & 63;
  int stage_v_354_2 = ((pub_r001012_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((stage_v_226_1 * 3) + pub_r001012_4_1) + 21) & 127;
  int stage_v_355_2 = (((stage_v_226_2 * 3) + pub_r001012_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001012_5_1 * 2) + 12) & 63;
  int stage_v_356_2 = ((pub_r001012_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = (((stage_v_268_1 * 3) + pub_r001012_18_1) + 45) & 127;
  int stage_v_357_2 = (((stage_v_268_2 * 3) + pub_r001012_18_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = ((pub_r001012_13_1 * 2) + 17) & 63;
  int stage_v_358_2 = ((pub_r001012_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001012_1_1 * 2) + 43) & 63;
  int stage_v_359_2 = ((pub_r001012_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_140_1 * 3) + pub_r001012_0_1) + 35) & 127;
  int stage_v_360_2 = (((stage_v_140_2 * 3) + pub_r001012_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = ((pub_r001012_3_1 * 2) + 23) & 63;
  int stage_v_361_2 = ((pub_r001012_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = (((stage_v_324_1 * 3) + pub_r001012_22_1) + 27) & 127;
  int stage_v_362_2 = (((stage_v_324_2 * 3) + pub_r001012_22_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = (((stage_v_208_1 * 3) + pub_r001012_6_1) + 7) & 127;
  int stage_v_363_2 = (((stage_v_208_2 * 3) + pub_r001012_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_188_1 * 3) + pub_r001012_10_1) + 28) & 127;
  int stage_v_364_2 = (((stage_v_188_2 * 3) + pub_r001012_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((stage_v_25_1 * 3) + pub_r001012_14_1) + 31) & 127;
  int stage_v_365_2 = (((stage_v_25_2 * 3) + pub_r001012_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = ((pub_r001012_2_1 * 2) + 33) & 63;
  int stage_v_366_2 = ((pub_r001012_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001012_7_1 * 2) + 32) & 63;
  int stage_v_367_2 = ((pub_r001012_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = (((stage_v_238_1 * 3) + pub_r001012_11_1) + 21) & 127;
  int stage_v_368_2 = (((stage_v_238_2 * 3) + pub_r001012_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = ((pub_r001012_10_1 * 2) + 11) & 63;
  int stage_v_369_2 = ((pub_r001012_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001012_11_1 * 2) + 10) & 63;
  int stage_v_370_2 = ((pub_r001012_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001012_8_1 * 2) + 22) & 63;
  int stage_v_371_2 = ((pub_r001012_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001012_20_1 * 2) + 26) & 63;
  int stage_v_372_2 = ((pub_r001012_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_72_1 * 3) + pub_r001012_15_1) + 24) & 127;
  int stage_v_373_2 = (((stage_v_72_2 * 3) + pub_r001012_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((stage_v_149_1 * 3) + pub_r001012_19_1) + 7) & 127;
  int stage_v_374_2 = (((stage_v_149_2 * 3) + pub_r001012_19_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_123_1 * 3) + pub_r001012_9_1) + 37) & 127;
  int stage_v_375_2 = (((stage_v_123_2 * 3) + pub_r001012_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001012_8_1 * 2) + 16) & 63;
  int stage_v_376_2 = ((pub_r001012_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001012_15_1 * 2) + 10) & 63;
  int stage_v_377_2 = ((pub_r001012_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = (((stage_v_360_1 * 3) + pub_r001012_1_1) + 22) & 127;
  int stage_v_378_2 = (((stage_v_360_2 * 3) + pub_r001012_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = ((pub_r001012_6_1 * 2) + 21) & 63;
  int stage_v_379_2 = ((pub_r001012_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = (((stage_v_143_1 * 3) + pub_r001012_13_1) + 38) & 127;
  int stage_v_380_2 = (((stage_v_143_2 * 3) + pub_r001012_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = ((pub_r001012_0_1 * 2) + 15) & 63;
  int stage_v_381_2 = ((pub_r001012_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((sec_r001012_8_1 * 3) + pub_r001012_2_1) + 45) & 127;
  int stage_v_382_2 = (((sec_r001012_8_2 * 3) + pub_r001012_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_159_1 * 3) + pub_r001012_18_1) + 17) & 127;
  int stage_v_383_2 = (((stage_v_159_2 * 3) + pub_r001012_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = ((pub_r001012_21_1 * 2) + 29) & 63;
  int stage_v_384_2 = ((pub_r001012_21_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001012_21_1 * 2) + 19) & 63;
  int stage_v_385_2 = ((pub_r001012_21_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001012_16_1 * 2) + 50) & 63;
  int stage_v_386_2 = ((pub_r001012_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001012_12_1 * 2) + 28) & 63;
  int stage_v_387_2 = ((pub_r001012_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001012_18_1 == pub_r001012_18_2);
  __CPROVER_assume(sec_r001012_2_1 != sec_r001012_2_2);
  __CPROVER_assume(pub_r001012_17_1 == pub_r001012_17_2);
  __CPROVER_assume(pub_r001012_10_1 == pub_r001012_10_2);
  __CPROVER_assume(sec_r001012_7_1 != sec_r001012_7_2);
  __CPROVER_assume(pub_r001012_3_1 == pub_r001012_3_2);
  __CPROVER_assume(sec_r001012_16_1 != sec_r001012_16_2);
  __CPROVER_assume(sec_r001012_10_1 != sec_r001012_10_2);
  __CPROVER_assume(pub_r001012_6_1 == pub_r001012_6_2);
  __CPROVER_assume(pub_r001012_0_1 == pub_r001012_0_2);
  __CPROVER_assume(pub_r001012_1_1 == pub_r001012_1_2);
  __CPROVER_assume(pub_r001012_8_1 == pub_r001012_8_2);
  __CPROVER_assume(pub_r001012_16_1 == pub_r001012_16_2);
  __CPROVER_assume(pub_r001012_14_1 == pub_r001012_14_2);
  __CPROVER_assume(pub_r001012_5_1 == pub_r001012_5_2);
  __CPROVER_assume(pub_r001012_9_1 == pub_r001012_9_2);
  __CPROVER_assume(pub_r001012_7_1 == pub_r001012_7_2);
  __CPROVER_assume(pub_r001012_20_1 == pub_r001012_20_2);
  __CPROVER_assume(pub_r001012_2_1 == pub_r001012_2_2);
  __CPROVER_assume(sec_r001012_12_1 != sec_r001012_12_2);
  __CPROVER_assume(pub_r001012_13_1 == pub_r001012_13_2);
  __CPROVER_assume(pub_r001012_21_1 == pub_r001012_21_2);
  __CPROVER_assume(sec_r001012_9_1 != sec_r001012_9_2);
  __CPROVER_assume(sec_r001012_14_1 != sec_r001012_14_2);
  __CPROVER_assume(sec_r001012_15_1 != sec_r001012_15_2);
  __CPROVER_assume(sec_r001012_3_1 != sec_r001012_3_2);
  __CPROVER_assume(pub_r001012_12_1 == pub_r001012_12_2);
  __CPROVER_assume(sec_r001012_13_1 != sec_r001012_13_2);
  __CPROVER_assume(sec_r001012_4_1 != sec_r001012_4_2);
  __CPROVER_assume(sec_r001012_0_1 != sec_r001012_0_2);
  __CPROVER_assume(sec_r001012_1_1 != sec_r001012_1_2);
  __CPROVER_assume(sec_r001012_11_1 != sec_r001012_11_2);
  __CPROVER_assume(pub_r001012_19_1 == pub_r001012_19_2);
  __CPROVER_assume(pub_r001012_11_1 == pub_r001012_11_2);
  __CPROVER_assume(sec_r001012_6_1 != sec_r001012_6_2);
  __CPROVER_assume(pub_r001012_22_1 == pub_r001012_22_2);
  __CPROVER_assume(pub_r001012_15_1 == pub_r001012_15_2);
  __CPROVER_assume(sec_r001012_8_1 != sec_r001012_8_2);
  __CPROVER_assume(sec_r001012_5_1 != sec_r001012_5_2);
  __CPROVER_assume(pub_r001012_4_1 == pub_r001012_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.head == st_var_1_2.head);
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
  assert(stage_v_366_1 == stage_v_366_2);
  assert(stage_v_367_1 == stage_v_367_2);
  assert(stage_v_368_1 == stage_v_368_2);
  assert(stage_v_369_1 == stage_v_369_2);
  assert(stage_v_370_1 == stage_v_370_2);
  assert(stage_v_371_1 == stage_v_371_2);
  assert(stage_v_372_1 == stage_v_372_2);
  assert(stage_v_373_1 == stage_v_373_2);
  assert(stage_v_374_1 == stage_v_374_2);
  assert(stage_v_375_1 == stage_v_375_2);
  assert(stage_v_376_1 == stage_v_376_2);
  assert(stage_v_377_1 == stage_v_377_2);
  assert(stage_v_378_1 == stage_v_378_2);
  assert(stage_v_379_1 == stage_v_379_2);
  assert(stage_v_380_1 == stage_v_380_2);
  assert(stage_v_381_1 == stage_v_381_2);
  assert(stage_v_382_1 == stage_v_382_2);
  assert(stage_v_383_1 == stage_v_383_2);
  assert(stage_v_384_1 == stage_v_384_2);
  assert(stage_v_385_1 == stage_v_385_2);
  assert(stage_v_386_1 == stage_v_386_2);
  assert(stage_v_387_1 == stage_v_387_2);
}


