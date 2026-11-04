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
struct Vector3D_R000102_2213_0
{
  int pitch;
  short norm_sq;
  int coord_y;
  int buffer[3];
};
struct StreamBuffer_R000102_2213_1
{
  unsigned char checksum;
  int state;
  unsigned char watermark;
  int capacity;
  short tail;
  int head;
  int buffer[3];
};
union PacketPayload_R000102_2213_0
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
void fn_R000102_2213_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st_1 = {0};
  struct Vector3D_R000102_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int window_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_70_1) & 63;
  aux_2 = (aux_2 + window_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_54_1 > 49)
  {
    acc_1 = ((acc_1 + (factor_54_1 * 2)) + 5) & 127;
    aux_1 ^= factor_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_54_2 > 49)
  {
    acc_2 = ((acc_2 + (factor_54_2 * 2)) + 5) & 127;
    aux_2 ^= factor_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_54_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_70_1 == window_70_2);
  assert(factor_54_1 == factor_54_2);
}

int fn_R000102_2213_0(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int window_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_70) & 63;
  acc ^= aux;
  int factor_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_54 > 49)
  {
    acc = ((acc + (factor_54 * 2)) + 5) & 127;
    aux ^= factor_54 & 15;
  }
  else
  {
    acc = ((acc - factor_54) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000102_2213_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st_1 = {0};
  struct Vector3D_R000102_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int segment_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_33_1 > 31)
  {
    acc_1 = ((acc_1 + (segment_33_1 * 2)) + 5) & 127;
    aux_1 ^= segment_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_33_2 > 31)
  {
    acc_2 = ((acc_2 + (segment_33_2 * 2)) + 5) & 127;
    aux_2 ^= segment_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_33_1) & 63;
  aux_2 = (aux_2 + index_reg_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_99_1 = 0;
  int coefficient_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_99_1 = ((coefficient_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_99_2 = ((coefficient_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_99_1) & 127;
    acc_2 = (acc_2 + coefficient_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_33_1 == segment_33_2);
  assert(index_reg_33_1 == index_reg_33_2);
  assert(coefficient_99_1 == coefficient_99_2);
}

int fn_R000102_2213_1(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int segment_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_33 > 31)
  {
    acc = ((acc + (segment_33 * 2)) + 5) & 127;
    aux ^= segment_33 & 15;
  }
  else
  {
    acc = ((acc - segment_33) + 11) & 127;
    aux += 3;
  }
  int index_reg_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_33) & 63;
  acc ^= aux;
  int coefficient_99 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_99 = ((coefficient_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_99) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000102_2213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_90_1 = local_arr_1[aux_1 % 3];
  int sample_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_90_2 * 2)) & 127;
  int metric_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_45_1 > 44)
  {
    acc_1 = ((acc_1 + (metric_45_1 * 2)) + 5) & 127;
    aux_1 ^= metric_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_45_2 > 44)
  {
    acc_2 = ((acc_2 + (metric_45_2 * 2)) + 5) & 127;
    aux_2 ^= metric_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_90_1 == sample_90_2);
  assert(metric_45_1 == metric_45_2);
}

int fn_R000102_2213_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int sample_90 = local_arr[aux % 3];
  acc = (acc + (sample_90 * 2)) & 127;
  int metric_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_45 > 44)
  {
    acc = ((acc + (metric_45 * 2)) + 5) & 127;
    aux ^= metric_45 & 15;
  }
  else
  {
    acc = ((acc - metric_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000102_2213_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int phase_32_1 = 0;
  int phase_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_32_1 = ((phase_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_32_2 = ((phase_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_32_1) & 127;
    acc_2 = (acc_2 + phase_32_2) & 127;
  }

  int margin_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_59_1 > 26)
  {
    acc_1 = ((acc_1 + (margin_59_1 * 2)) + 5) & 127;
    aux_1 ^= margin_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_59_2 > 26)
  {
    acc_2 = ((acc_2 + (margin_59_2 * 2)) + 5) & 127;
    aux_2 ^= margin_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_32_1 == phase_32_2);
  assert(margin_59_1 == margin_59_2);
}

int fn_R000102_2213_3(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int phase_32 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_32 = ((phase_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_32) & 127;
  }

  int margin_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_59 > 26)
  {
    acc = ((acc + (margin_59 * 2)) + 5) & 127;
    aux ^= margin_59 & 15;
  }
  else
  {
    acc = ((acc - margin_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000102_2213_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st_1 = {0};
  struct Vector3D_R000102_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quantum_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_87_1)
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

  switch (quantum_87_2)
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

  int offset_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_92_1) & 63;
  aux_2 = (aux_2 + offset_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_59_1 = 0;
  int checksum_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_59_1 = ((checksum_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_59_2 = ((checksum_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_59_1) & 127;
    acc_2 = (acc_2 + checksum_59_2) & 127;
  }

  int offset_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_59_1 > 48)
  {
    acc_1 = ((acc_1 + (offset_59_1 * 2)) + 5) & 127;
    aux_1 ^= offset_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_59_2 > 48)
  {
    acc_2 = ((acc_2 + (offset_59_2 * 2)) + 5) & 127;
    aux_2 ^= offset_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_87_1 == quantum_87_2);
  assert(offset_92_1 == offset_92_2);
  assert(checksum_59_1 == checksum_59_2);
  assert(offset_59_1 == offset_59_2);
}

int fn_R000102_2213_4(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quantum_87 = (aux + st.buffer[1]) & 3;
  switch (quantum_87)
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

  int offset_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_92) & 63;
  acc ^= aux;
  int checksum_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_59 = ((checksum_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_59) & 127;
  }

  int offset_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_59 > 48)
  {
    acc = ((acc + (offset_59 * 2)) + 5) & 127;
    aux ^= offset_59 & 15;
  }
  else
  {
    acc = ((acc - offset_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000102_2213_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st_1 = {0};
  struct Vector3D_R000102_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_62_1 = local_arr_1[aux_1 % 3];
  int mask_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_62_2 * 2)) & 127;
  int delta_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_91_1) & 63;
  aux_2 = (aux_2 + delta_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_37_1 > 33)
  {
    acc_1 = ((acc_1 + (tally_37_1 * 2)) + 5) & 127;
    aux_1 ^= tally_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_37_2 > 33)
  {
    acc_2 = ((acc_2 + (tally_37_2 * 2)) + 5) & 127;
    aux_2 ^= tally_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_34_1 = 0;
  int scale_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_34_1 = ((scale_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_34_2 = ((scale_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_34_1) & 127;
    acc_2 = (acc_2 + scale_34_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_62_1 == mask_62_2);
  assert(delta_91_1 == delta_91_2);
  assert(tally_37_1 == tally_37_2);
  assert(scale_34_1 == scale_34_2);
}

int fn_R000102_2213_5(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int mask_62 = local_arr[aux % 3];
  acc = (acc + (mask_62 * 2)) & 127;
  int delta_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_91) & 63;
  acc ^= aux;
  int tally_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_37 > 33)
  {
    acc = ((acc + (tally_37 * 2)) + 5) & 127;
    aux ^= tally_37 & 15;
  }
  else
  {
    acc = ((acc - tally_37) + 11) & 127;
    aux += 3;
  }
  int scale_34 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_34 = ((scale_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_34) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000102_2213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int parity_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_14_1) & 63;
  aux_2 = (aux_2 + parity_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_91_1 = local_arr_1[aux_1 % 3];
  int coefficient_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_91_2 * 2)) & 127;
  int mask_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_51_1 > 16)
  {
    acc_1 = ((acc_1 + (mask_51_1 * 2)) + 5) & 127;
    aux_1 ^= mask_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_51_2 > 16)
  {
    acc_2 = ((acc_2 + (mask_51_2 * 2)) + 5) & 127;
    aux_2 ^= mask_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_14_1 == parity_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_91_1 == coefficient_91_2);
  assert(mask_51_1 == mask_51_2);
}

int fn_R000102_2213_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int parity_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_14) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_91 = local_arr[aux % 3];
  acc = (acc + (coefficient_91 * 2)) & 127;
  int mask_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_51 > 16)
  {
    acc = ((acc + (mask_51 * 2)) + 5) & 127;
    aux ^= mask_51 & 15;
  }
  else
  {
    acc = ((acc - mask_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000102_2213_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int factor_47_1 = 0;
  int factor_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_47_1 = ((factor_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_47_2 = ((factor_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_47_1) & 127;
    acc_2 = (acc_2 + factor_47_2) & 127;
  }

  int quotient_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_80_1 > 25)
  {
    acc_1 = ((acc_1 + (quotient_80_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_80_2 > 25)
  {
    acc_2 = ((acc_2 + (quotient_80_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_47_1 == factor_47_2);
  assert(quotient_80_1 == quotient_80_2);
}

int fn_R000102_2213_7(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int factor_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_47 = ((factor_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_47) & 127;
  }

  int quotient_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_80 > 25)
  {
    acc = ((acc + (quotient_80 * 2)) + 5) & 127;
    aux ^= quotient_80 & 15;
  }
  else
  {
    acc = ((acc - quotient_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000102_2213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int damping_44_1 = 0;
  int damping_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_44_1 = ((damping_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_44_2 = ((damping_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_44_1) & 127;
    acc_2 = (acc_2 + damping_44_2) & 127;
  }

  int threshold_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_75_1) & 63;
  aux_2 = (aux_2 + threshold_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_73_1)
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

  switch (mask_73_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_44_1 == damping_44_2);
  assert(threshold_75_1 == threshold_75_2);
  assert(mask_73_1 == mask_73_2);
}

int fn_R000102_2213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int damping_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_44 = ((damping_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_44) & 127;
  }

  int threshold_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_75) & 63;
  acc ^= aux;
  int mask_73 = (aux + st.buffer[1]) & 3;
  switch (mask_73)
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

void fn_R000102_2213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int factor_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_54_1 > 44)
  {
    acc_1 = ((acc_1 + (factor_54_1 * 2)) + 5) & 127;
    aux_1 ^= factor_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_54_2 > 44)
  {
    acc_2 = ((acc_2 + (factor_54_2 * 2)) + 5) & 127;
    aux_2 ^= factor_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_72_1) & 63;
  aux_2 = (aux_2 + metric_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_84_1 = local_arr_1[aux_1 % 3];
  int cursor_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_84_2 * 2)) & 127;
  int anchor_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_54_1)
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

  switch (anchor_54_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_54_1 == factor_54_2);
  assert(metric_72_1 == metric_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_84_1 == cursor_84_2);
  assert(anchor_54_1 == anchor_54_2);
}

int fn_R000102_2213_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int factor_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_54 > 44)
  {
    acc = ((acc + (factor_54 * 2)) + 5) & 127;
    aux ^= factor_54 & 15;
  }
  else
  {
    acc = ((acc - factor_54) + 11) & 127;
    aux += 3;
  }
  int metric_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_72) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_84 = local_arr[aux % 3];
  acc = (acc + (cursor_84 * 2)) & 127;
  int anchor_54 = (aux + st.buffer[1]) & 3;
  switch (anchor_54)
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

void fn_R000102_2213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_43_1 = local_arr_1[aux_1 % 3];
  int vector_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_43_2 * 2)) & 127;
  int segment_98_1 = 0;
  int segment_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_98_1 = ((segment_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_98_2 = ((segment_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_98_1) & 127;
    acc_2 = (acc_2 + segment_98_2) & 127;
  }

  int phase_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_42_1) & 63;
  aux_2 = (aux_2 + phase_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_43_1 == vector_43_2);
  assert(segment_98_1 == segment_98_2);
  assert(phase_42_1 == phase_42_2);
}

int fn_R000102_2213_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int vector_43 = local_arr[aux % 3];
  acc = (acc + (vector_43 * 2)) & 127;
  int segment_98 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_98 = ((segment_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_98) & 127;
  }

  int phase_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_42) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000102_2213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st_1 = {0};
  struct Vector3D_R000102_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_36_1 = local_arr_1[aux_1 % 3];
  int coefficient_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_36_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_20_1 = 0;
  int tracker_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_20_1 = ((tracker_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_20_2 = ((tracker_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_20_1) & 127;
    acc_2 = (acc_2 + tracker_20_2) & 127;
  }

  int sample_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_73_1 > 46)
  {
    acc_1 = ((acc_1 + (sample_73_1 * 2)) + 5) & 127;
    aux_1 ^= sample_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_73_2 > 46)
  {
    acc_2 = ((acc_2 + (sample_73_2 * 2)) + 5) & 127;
    aux_2 ^= sample_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_36_1 == coefficient_36_2);
  assert(tracker_20_1 == tracker_20_2);
  assert(sample_73_1 == sample_73_2);
}

int fn_R000102_2213_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int coefficient_36 = local_arr[aux % 3];
  acc = (acc + (coefficient_36 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_20 = ((tracker_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_20) & 127;
  }

  int sample_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_73 > 46)
  {
    acc = ((acc + (sample_73 * 2)) + 5) & 127;
    aux ^= sample_73 & 15;
  }
  else
  {
    acc = ((acc - sample_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000102_2213_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st_1 = {0};
  struct Vector3D_R000102_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int stride_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_96_1) & 63;
  aux_2 = (aux_2 + stride_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_25_1 > 47)
  {
    acc_1 = ((acc_1 + (pivot_25_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_25_2 > 47)
  {
    acc_2 = ((acc_2 + (pivot_25_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_96_1 == stride_96_2);
  assert(pivot_25_1 == pivot_25_2);
}

int fn_R000102_2213_12(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int stride_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_96) & 63;
  acc ^= aux;
  int pivot_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_25 > 47)
  {
    acc = ((acc + (pivot_25 * 2)) + 5) & 127;
    aux ^= pivot_25 & 15;
  }
  else
  {
    acc = ((acc - pivot_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000102_2213_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int parity_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_10_1 > 21)
  {
    acc_1 = ((acc_1 + (parity_10_1 * 2)) + 5) & 127;
    aux_1 ^= parity_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_10_2 > 21)
  {
    acc_2 = ((acc_2 + (parity_10_2 * 2)) + 5) & 127;
    aux_2 ^= parity_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_95_1) & 63;
  aux_2 = (aux_2 + weight_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_77_1)
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

  switch (segment_77_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_10_1 == parity_10_2);
  assert(weight_95_1 == weight_95_2);
  assert(segment_77_1 == segment_77_2);
}

int fn_R000102_2213_13(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int parity_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_10 > 21)
  {
    acc = ((acc + (parity_10 * 2)) + 5) & 127;
    aux ^= parity_10 & 15;
  }
  else
  {
    acc = ((acc - parity_10) + 11) & 127;
    aux += 3;
  }
  int weight_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_95) & 63;
  acc ^= aux;
  int segment_77 = (aux + st.buffer[1]) & 3;
  switch (segment_77)
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

void fn_R000102_2213_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st_1 = {0};
  struct Vector3D_R000102_2213_0 st_2 = {0};
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
  int stride_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_99_1 > 41)
  {
    acc_1 = ((acc_1 + (stride_99_1 * 2)) + 5) & 127;
    aux_1 ^= stride_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_99_2 > 41)
  {
    acc_2 = ((acc_2 + (stride_99_2 * 2)) + 5) & 127;
    aux_2 ^= stride_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_99_1 == stride_99_2);
}

int fn_R000102_2213_14(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_99 > 41)
  {
    acc = ((acc + (stride_99 * 2)) + 5) & 127;
    aux ^= stride_99 & 15;
  }
  else
  {
    acc = ((acc - stride_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000102_2213_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int cursor_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_63_1)
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

  switch (cursor_63_2)
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

  int scale_17_1 = 0;
  int scale_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_17_1 = ((scale_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_17_2 = ((scale_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_17_1) & 127;
    acc_2 = (acc_2 + scale_17_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_63_1 == cursor_63_2);
  assert(scale_17_1 == scale_17_2);
}

int fn_R000102_2213_15(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int cursor_63 = (aux + st.buffer[1]) & 3;
  switch (cursor_63)
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

  int scale_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_17 = ((scale_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_17) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000102_2213_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int pivot_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_37_1)
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

  switch (pivot_37_2)
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

  int accumulator_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_50_1 > 47)
  {
    acc_1 = ((acc_1 + (accumulator_50_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_50_2 > 47)
  {
    acc_2 = ((acc_2 + (accumulator_50_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_50_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_13_1) & 63;
  aux_2 = (aux_2 + stride_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_37_1 == pivot_37_2);
  assert(accumulator_50_1 == accumulator_50_2);
  assert(stride_13_1 == stride_13_2);
}

int fn_R000102_2213_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int pivot_37 = (aux + st.buffer[1]) & 3;
  switch (pivot_37)
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

  int accumulator_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_50 > 47)
  {
    acc = ((acc + (accumulator_50 * 2)) + 5) & 127;
    aux ^= accumulator_50 & 15;
  }
  else
  {
    acc = ((acc - accumulator_50) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000102_2213_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st_1 = {0};
  struct Vector3D_R000102_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int factor_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_51_1)
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

  switch (factor_51_2)
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

  int quotient_89_1 = 0;
  int quotient_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_89_1 = ((quotient_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_89_2 = ((quotient_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_89_1) & 127;
    acc_2 = (acc_2 + quotient_89_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_51_1 == factor_51_2);
  assert(quotient_89_1 == quotient_89_2);
}

int fn_R000102_2213_17(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int factor_51 = (aux + st.buffer[1]) & 3;
  switch (factor_51)
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

  int quotient_89 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_89 = ((quotient_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_89) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000102_2213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_35_1 = local_arr_1[aux_1 % 3];
  int weight_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_35_2 * 2)) & 127;
  int accumulator_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_74_1)
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

  switch (accumulator_74_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_35_1 == weight_35_2);
  assert(accumulator_74_1 == accumulator_74_2);
}

int fn_R000102_2213_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int weight_35 = local_arr[aux % 3];
  acc = (acc + (weight_35 * 2)) & 127;
  int accumulator_74 = (aux + st.buffer[1]) & 3;
  switch (accumulator_74)
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

void fn_R000102_2213_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int vector_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_26_1 > 21)
  {
    acc_1 = ((acc_1 + (vector_26_1 * 2)) + 5) & 127;
    aux_1 ^= vector_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_26_2 > 21)
  {
    acc_2 = ((acc_2 + (vector_26_2 * 2)) + 5) & 127;
    aux_2 ^= vector_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_85_1)
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

  switch (mask_85_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_26_1 == vector_26_2);
  assert(mask_85_1 == mask_85_2);
}

int fn_R000102_2213_19(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int vector_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_26 > 21)
  {
    acc = ((acc + (vector_26 * 2)) + 5) & 127;
    aux ^= vector_26 & 15;
  }
  else
  {
    acc = ((acc - vector_26) + 11) & 127;
    aux += 3;
  }
  int mask_85 = (aux + st.buffer[1]) & 3;
  switch (mask_85)
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

void fn_R000102_2213_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st_1 = {0};
  struct Vector3D_R000102_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int weight_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_96_1) & 63;
  aux_2 = (aux_2 + weight_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_95_1)
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

  switch (margin_95_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_89_1 > 29)
  {
    acc_1 = ((acc_1 + (metric_89_1 * 2)) + 5) & 127;
    aux_1 ^= metric_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_89_2 > 29)
  {
    acc_2 = ((acc_2 + (metric_89_2 * 2)) + 5) & 127;
    aux_2 ^= metric_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_96_1 == weight_96_2);
  assert(margin_95_1 == margin_95_2);
  assert(metric_89_1 == metric_89_2);
}

int fn_R000102_2213_20(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int weight_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_96) & 63;
  acc ^= aux;
  int margin_95 = (aux + st.buffer[1]) & 3;
  switch (margin_95)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_89 > 29)
  {
    acc = ((acc + (metric_89 * 2)) + 5) & 127;
    aux ^= metric_89 & 15;
  }
  else
  {
    acc = ((acc - metric_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000102_2213_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_50_1)
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

  switch (margin_50_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_50_1 == margin_50_2);
}

int fn_R000102_2213_21(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_50 = (aux + st.buffer[1]) & 3;
  switch (margin_50)
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

void fn_R000102_2213_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st_1 = {0};
  struct Vector3D_R000102_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_58_1 = local_arr_1[aux_1 % 3];
  int quotient_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_58_2 * 2)) & 127;
  int residue_86_1 = 0;
  int residue_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_86_1 = ((residue_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_86_2 = ((residue_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_86_1) & 127;
    acc_2 = (acc_2 + residue_86_2) & 127;
  }

  int threshold_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_72_1 > 32)
  {
    acc_1 = ((acc_1 + (threshold_72_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_72_2 > 32)
  {
    acc_2 = ((acc_2 + (threshold_72_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_80_1)
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

  switch (quantum_80_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_58_1 == quotient_58_2);
  assert(residue_86_1 == residue_86_2);
  assert(threshold_72_1 == threshold_72_2);
  assert(quantum_80_1 == quantum_80_2);
}

int fn_R000102_2213_22(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int quotient_58 = local_arr[aux % 3];
  acc = (acc + (quotient_58 * 2)) & 127;
  int residue_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_86 = ((residue_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_86) & 127;
  }

  int threshold_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_72 > 32)
  {
    acc = ((acc + (threshold_72 * 2)) + 5) & 127;
    aux ^= threshold_72 & 15;
  }
  else
  {
    acc = ((acc - threshold_72) + 11) & 127;
    aux += 3;
  }
  int quantum_80 = (aux + st.buffer[1]) & 3;
  switch (quantum_80)
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

void fn_R000102_2213_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st_1 = {0};
  struct Vector3D_R000102_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int checksum_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_97_1 > 19)
  {
    acc_1 = ((acc_1 + (checksum_97_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_97_2 > 19)
  {
    acc_2 = ((acc_2 + (checksum_97_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_97_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_97_1 == checksum_97_2);
}

int fn_R000102_2213_23(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000102_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int checksum_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_97 > 19)
  {
    acc = ((acc + (checksum_97 * 2)) + 5) & 127;
    aux ^= checksum_97 & 15;
  }
  else
  {
    acc = ((acc - checksum_97) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000102_2213_24_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_60_1) & 63;
  aux_2 = (aux_2 + offset_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_74_1)
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

  switch (sample_74_2)
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

  int vector_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_33_1 > 14)
  {
    acc_1 = ((acc_1 + (vector_33_1 * 2)) + 5) & 127;
    aux_1 ^= vector_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_33_2 > 14)
  {
    acc_2 = ((acc_2 + (vector_33_2 * 2)) + 5) & 127;
    aux_2 ^= vector_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_60_1 == offset_60_2);
  assert(sample_74_1 == sample_74_2);
  assert(vector_33_1 == vector_33_2);
}

int fn_R000102_2213_24(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000102_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_60) & 63;
  acc ^= aux;
  int sample_74 = (aux + st.buffer[1]) & 3;
  switch (sample_74)
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

  int vector_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_33 > 14)
  {
    acc = ((acc + (vector_33 * 2)) + 5) & 127;
    aux ^= vector_33 & 15;
  }
  else
  {
    acc = ((acc - vector_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000102_0_1;
  int sec_r000102_0_2;
  int sec_r000102_1_1;
  int sec_r000102_1_2;
  int sec_r000102_2_1;
  int sec_r000102_2_2;
  int sec_r000102_3_1;
  int sec_r000102_3_2;
  int sec_r000102_4_1;
  int sec_r000102_4_2;
  int sec_r000102_5_1;
  int sec_r000102_5_2;
  int sec_r000102_6_1;
  int sec_r000102_6_2;
  int sec_r000102_7_1;
  int sec_r000102_7_2;
  int sec_r000102_8_1;
  int sec_r000102_8_2;
  int sec_r000102_9_1;
  int sec_r000102_9_2;
  int sec_r000102_10_1;
  int sec_r000102_10_2;
  int sec_r000102_11_1;
  int sec_r000102_11_2;
  int sec_r000102_12_1;
  int sec_r000102_12_2;
  int sec_r000102_13_1;
  int sec_r000102_13_2;
  int sec_r000102_14_1;
  int sec_r000102_14_2;
  int sec_r000102_15_1;
  int sec_r000102_15_2;
  int sec_r000102_16_1;
  int sec_r000102_16_2;
  int sec_r000102_17_1;
  int sec_r000102_17_2;
  int sec_r000102_18_1;
  int sec_r000102_18_2;
  int pub_r000102_0_1;
  int pub_r000102_0_2;
  int pub_r000102_1_1;
  int pub_r000102_1_2;
  int pub_r000102_2_1;
  int pub_r000102_2_2;
  int pub_r000102_3_1;
  int pub_r000102_3_2;
  int pub_r000102_4_1;
  int pub_r000102_4_2;
  int pub_r000102_5_1;
  int pub_r000102_5_2;
  int pub_r000102_6_1;
  int pub_r000102_6_2;
  int pub_r000102_7_1;
  int pub_r000102_7_2;
  int pub_r000102_8_1;
  int pub_r000102_8_2;
  int pub_r000102_9_1;
  int pub_r000102_9_2;
  int pub_r000102_10_1;
  int pub_r000102_10_2;
  int pub_r000102_11_1;
  int pub_r000102_11_2;
  int pub_r000102_12_1;
  int pub_r000102_12_2;
  int pub_r000102_13_1;
  int pub_r000102_13_2;
  int pub_r000102_14_1;
  int pub_r000102_14_2;
  int pub_r000102_15_1;
  int pub_r000102_15_2;
  int pub_r000102_16_1;
  int pub_r000102_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000102_0_1 >= (-100)) && (pub_r000102_0_1 <= 100));
  __CPROVER_assume((pub_r000102_0_2 >= (-100)) && (pub_r000102_0_2 <= 100));
  __CPROVER_assume((pub_r000102_1_1 >= (-100)) && (pub_r000102_1_1 <= 100));
  __CPROVER_assume((pub_r000102_1_2 >= (-100)) && (pub_r000102_1_2 <= 100));
  __CPROVER_assume((pub_r000102_2_1 >= (-100)) && (pub_r000102_2_1 <= 100));
  __CPROVER_assume((pub_r000102_2_2 >= (-100)) && (pub_r000102_2_2 <= 100));
  __CPROVER_assume((pub_r000102_3_1 >= (-100)) && (pub_r000102_3_1 <= 100));
  __CPROVER_assume((pub_r000102_3_2 >= (-100)) && (pub_r000102_3_2 <= 100));
  __CPROVER_assume((pub_r000102_4_1 >= (-100)) && (pub_r000102_4_1 <= 100));
  __CPROVER_assume((pub_r000102_4_2 >= (-100)) && (pub_r000102_4_2 <= 100));
  __CPROVER_assume((pub_r000102_5_1 >= (-100)) && (pub_r000102_5_1 <= 100));
  __CPROVER_assume((pub_r000102_5_2 >= (-100)) && (pub_r000102_5_2 <= 100));
  __CPROVER_assume((pub_r000102_6_1 >= (-100)) && (pub_r000102_6_1 <= 100));
  __CPROVER_assume((pub_r000102_6_2 >= (-100)) && (pub_r000102_6_2 <= 100));
  __CPROVER_assume((pub_r000102_7_1 >= (-100)) && (pub_r000102_7_1 <= 100));
  __CPROVER_assume((pub_r000102_7_2 >= (-100)) && (pub_r000102_7_2 <= 100));
  __CPROVER_assume((pub_r000102_8_1 >= (-100)) && (pub_r000102_8_1 <= 100));
  __CPROVER_assume((pub_r000102_8_2 >= (-100)) && (pub_r000102_8_2 <= 100));
  __CPROVER_assume((pub_r000102_9_1 >= (-100)) && (pub_r000102_9_1 <= 100));
  __CPROVER_assume((pub_r000102_9_2 >= (-100)) && (pub_r000102_9_2 <= 100));
  __CPROVER_assume((pub_r000102_10_1 >= (-100)) && (pub_r000102_10_1 <= 100));
  __CPROVER_assume((pub_r000102_10_2 >= (-100)) && (pub_r000102_10_2 <= 100));
  __CPROVER_assume((pub_r000102_11_1 >= (-100)) && (pub_r000102_11_1 <= 100));
  __CPROVER_assume((pub_r000102_11_2 >= (-100)) && (pub_r000102_11_2 <= 100));
  __CPROVER_assume((pub_r000102_12_1 >= (-100)) && (pub_r000102_12_1 <= 100));
  __CPROVER_assume((pub_r000102_12_2 >= (-100)) && (pub_r000102_12_2 <= 100));
  __CPROVER_assume((pub_r000102_13_1 >= (-100)) && (pub_r000102_13_1 <= 100));
  __CPROVER_assume((pub_r000102_13_2 >= (-100)) && (pub_r000102_13_2 <= 100));
  __CPROVER_assume((pub_r000102_14_1 >= (-100)) && (pub_r000102_14_1 <= 100));
  __CPROVER_assume((pub_r000102_14_2 >= (-100)) && (pub_r000102_14_2 <= 100));
  __CPROVER_assume((pub_r000102_15_1 >= (-100)) && (pub_r000102_15_1 <= 100));
  __CPROVER_assume((pub_r000102_15_2 >= (-100)) && (pub_r000102_15_2 <= 100));
  __CPROVER_assume((pub_r000102_16_1 >= (-100)) && (pub_r000102_16_1 <= 100));
  __CPROVER_assume((pub_r000102_16_2 >= (-100)) && (pub_r000102_16_2 <= 100));
  __CPROVER_assume((sec_r000102_0_1 >= 0) && (sec_r000102_0_1 <= 255));
  __CPROVER_assume((sec_r000102_0_2 >= 0) && (sec_r000102_0_2 <= 255));
  __CPROVER_assume((sec_r000102_1_1 >= 0) && (sec_r000102_1_1 <= 255));
  __CPROVER_assume((sec_r000102_1_2 >= 0) && (sec_r000102_1_2 <= 255));
  __CPROVER_assume((sec_r000102_2_1 >= 0) && (sec_r000102_2_1 <= 255));
  __CPROVER_assume((sec_r000102_2_2 >= 0) && (sec_r000102_2_2 <= 255));
  __CPROVER_assume((sec_r000102_3_1 >= 0) && (sec_r000102_3_1 <= 255));
  __CPROVER_assume((sec_r000102_3_2 >= 0) && (sec_r000102_3_2 <= 255));
  __CPROVER_assume((sec_r000102_4_1 >= 0) && (sec_r000102_4_1 <= 255));
  __CPROVER_assume((sec_r000102_4_2 >= 0) && (sec_r000102_4_2 <= 255));
  __CPROVER_assume((sec_r000102_5_1 >= 0) && (sec_r000102_5_1 <= 255));
  __CPROVER_assume((sec_r000102_5_2 >= 0) && (sec_r000102_5_2 <= 255));
  __CPROVER_assume((sec_r000102_6_1 >= 0) && (sec_r000102_6_1 <= 255));
  __CPROVER_assume((sec_r000102_6_2 >= 0) && (sec_r000102_6_2 <= 255));
  __CPROVER_assume((sec_r000102_7_1 >= 0) && (sec_r000102_7_1 <= 255));
  __CPROVER_assume((sec_r000102_7_2 >= 0) && (sec_r000102_7_2 <= 255));
  __CPROVER_assume((sec_r000102_8_1 >= 0) && (sec_r000102_8_1 <= 255));
  __CPROVER_assume((sec_r000102_8_2 >= 0) && (sec_r000102_8_2 <= 255));
  __CPROVER_assume((sec_r000102_9_1 >= 0) && (sec_r000102_9_1 <= 255));
  __CPROVER_assume((sec_r000102_9_2 >= 0) && (sec_r000102_9_2 <= 255));
  __CPROVER_assume((sec_r000102_10_1 >= 0) && (sec_r000102_10_1 <= 255));
  __CPROVER_assume((sec_r000102_10_2 >= 0) && (sec_r000102_10_2 <= 255));
  __CPROVER_assume((sec_r000102_11_1 >= 0) && (sec_r000102_11_1 <= 255));
  __CPROVER_assume((sec_r000102_11_2 >= 0) && (sec_r000102_11_2 <= 255));
  __CPROVER_assume((sec_r000102_12_1 >= 0) && (sec_r000102_12_1 <= 255));
  __CPROVER_assume((sec_r000102_12_2 >= 0) && (sec_r000102_12_2 <= 255));
  __CPROVER_assume((sec_r000102_13_1 >= 0) && (sec_r000102_13_1 <= 255));
  __CPROVER_assume((sec_r000102_13_2 >= 0) && (sec_r000102_13_2 <= 255));
  __CPROVER_assume((sec_r000102_14_1 >= 0) && (sec_r000102_14_1 <= 255));
  __CPROVER_assume((sec_r000102_14_2 >= 0) && (sec_r000102_14_2 <= 255));
  __CPROVER_assume((sec_r000102_15_1 >= 0) && (sec_r000102_15_1 <= 255));
  __CPROVER_assume((sec_r000102_15_2 >= 0) && (sec_r000102_15_2 <= 255));
  __CPROVER_assume((sec_r000102_16_1 >= 0) && (sec_r000102_16_1 <= 255));
  __CPROVER_assume((sec_r000102_16_2 >= 0) && (sec_r000102_16_2 <= 255));
  __CPROVER_assume((sec_r000102_17_1 >= 0) && (sec_r000102_17_1 <= 255));
  __CPROVER_assume((sec_r000102_17_2 >= 0) && (sec_r000102_17_2 <= 255));
  __CPROVER_assume((sec_r000102_18_1 >= 0) && (sec_r000102_18_1 <= 255));
  __CPROVER_assume((sec_r000102_18_2 >= 0) && (sec_r000102_18_2 <= 255));
  struct Vector3D_R000102_2213_0 st_var_0_1 = {0};
  struct Vector3D_R000102_2213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000102_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000102_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000102_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000102_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000102_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000102_0_2 + 7) & 15;
  struct StreamBuffer_R000102_2213_1 st_var_1_1 = {0};
  struct StreamBuffer_R000102_2213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000102_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000102_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000102_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000102_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000102_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000102_0_2 + 9) & 15;
  union PacketPayload_R000102_2213_0 u_var_1;
  union PacketPayload_R000102_2213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (st_var_0_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_0_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = (st_var_1_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_1_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

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
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = (st_var_0_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_0_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = (st_var_1_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_1_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = (st_var_1_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_1_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 25)
    {
      chk_sum_1 ^= stage_v_18_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_18_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 25)
    {
      chk_sum_2 ^= stage_v_18_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = ((st_var_1_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_1_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 55)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 55)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 27)
    {
      chk_sum_1 ^= stage_v_25_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_25_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 27)
    {
      chk_sum_2 ^= stage_v_25_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_26_1 = ((st_var_0_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_0_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 37)
    {
      chk_sum_1 ^= stage_v_26_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_26_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 37)
    {
      chk_sum_2 ^= stage_v_26_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_27_1 = ((st_var_1_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_1_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 51)
    {
      chk_sum_1 ^= stage_v_27_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_27_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 51)
    {
      chk_sum_2 ^= stage_v_27_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 45)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 45)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_30_1 = ((st_var_0_1.buffer[0] * 2) + 97) & 63;
  int stage_v_30_2 = ((st_var_0_2.buffer[0] * 2) + 97) & 63;
  if (stage_v_30_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_30_1) - 5) & 255;
    if (stage_v_30_1 > 33)
    {
      chk_sum_1 ^= stage_v_30_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_30_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_30_2) - 5) & 255;
    if (stage_v_30_2 > 33)
    {
      chk_sum_2 ^= stage_v_30_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_32_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = table_1[0];
  int stage_v_36_2 = table_2[0];
  table_1[0] = (table_1[1] + 73) & 63;
  table_2[0] = (table_2[1] + 73) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  int stage_v_39_1 = table_1[3];
  int stage_v_39_2 = table_2[3];
  table_1[3] = (table_1[0] + 79) & 63;
  table_2[3] = (table_2[0] + 79) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
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
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = ((st_var_1_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_1_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 29)
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
  if (stage_v_47_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 29)
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

  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (st_var_0_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_0_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 53) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
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
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_62_1 = ((st_var_0_1.buffer[2] * 2) + 193) & 63;
  int stage_v_62_2 = ((st_var_0_2.buffer[2] * 2) + 193) & 63;
  if (stage_v_62_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_62_1) - 5) & 255;
    if (stage_v_62_1 > 36)
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
  if (stage_v_62_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_62_2) - 5) & 255;
    if (stage_v_62_2 > 36)
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
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = table_1[0];
  int stage_v_64_2 = table_2[0];
  table_1[0] = (table_1[1] + 129) & 63;
  table_2[0] = (table_2[1] + 129) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  int stage_v_66_1 = ((st_var_0_1.buffer[0] * 2) + 205) & 63;
  int stage_v_66_2 = ((st_var_0_2.buffer[0] * 2) + 205) & 63;
  if (stage_v_66_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_66_1) - 5) & 255;
    if (stage_v_66_1 > 33)
    {
      chk_sum_1 ^= stage_v_66_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_66_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_66_2) - 5) & 255;
    if (stage_v_66_2 > 33)
    {
      chk_sum_2 ^= stage_v_66_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  int stage_v_68_1 = table_1[0];
  int stage_v_68_2 = table_2[0];
  table_1[0] = (table_1[1] + 137) & 63;
  table_2[0] = (table_2[1] + 137) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 70) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (75 & 31);
  int stage_v_70_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (75 & 31);
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= (stage_v_70_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_70_2 << 1) & 127;
  int stage_v_71_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (76 & 31);
  int stage_v_71_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (76 & 31);
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= (stage_v_71_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_71_2 << 1) & 127;
  int stage_v_72_1 = (st_var_0_1.buffer[0] ^ 75) & 3;
  int stage_v_72_2 = (st_var_0_2.buffer[0] ^ 75) & 3;
  switch (stage_v_72_1)
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

  switch (stage_v_72_2)
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

  int stage_v_73_1 = ((st_var_1_1.buffer[1] * 2) + 226) & 63;
  int stage_v_73_2 = ((st_var_1_2.buffer[1] * 2) + 226) & 63;
  if (stage_v_73_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_73_1) - 5) & 255;
    if (stage_v_73_1 > 54)
    {
      chk_sum_1 ^= stage_v_73_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_73_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_73_2) - 5) & 255;
    if (stage_v_73_2 > 54)
    {
      chk_sum_2 ^= stage_v_73_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_74_1 = ((st_var_0_1.buffer[2] * 2) + 229) & 63;
  int stage_v_74_2 = ((st_var_0_2.buffer[2] * 2) + 229) & 63;
  if (stage_v_74_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_74_1) - 5) & 255;
    if (stage_v_74_1 > 55)
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
  if (stage_v_74_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_74_2) - 5) & 255;
    if (stage_v_74_2 > 55)
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
  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_76_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (81 & 31);
  int stage_v_76_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (81 & 31);
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= (stage_v_76_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_76_2 << 1) & 127;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (83 & 31);
  int stage_v_78_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (83 & 31);
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= (stage_v_78_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_78_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 80) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 80) & 15;
  int stage_v_79_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_79_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= stage_v_79_1;
  chk_sum_2 ^= stage_v_79_2;
  int stage_v_80_1 = (st_var_0_1.buffer[0] ^ 83) & 3;
  int stage_v_80_2 = (st_var_0_2.buffer[0] ^ 83) & 3;
  switch (stage_v_80_1)
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

  switch (stage_v_80_2)
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

  int stage_v_81_1 = ((st_var_1_1.buffer[0] * 2) + 250) & 63;
  int stage_v_81_2 = ((st_var_1_2.buffer[0] * 2) + 250) & 63;
  if (stage_v_81_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_81_1) - 5) & 255;
    if (stage_v_81_1 > 38)
    {
      chk_sum_1 ^= stage_v_81_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_81_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_81_2) - 5) & 255;
    if (stage_v_81_2 > 38)
    {
      chk_sum_2 ^= stage_v_81_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 83) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 83) & 15;
  int stage_v_82_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_82_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= stage_v_82_1;
  chk_sum_2 ^= stage_v_82_2;
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (89 & 31);
  int stage_v_84_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (89 & 31);
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= (stage_v_84_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_84_2 << 1) & 127;
  int stage_v_85_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (90 & 31);
  int stage_v_85_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (90 & 31);
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= (stage_v_85_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_85_2 << 1) & 127;
  int stage_v_86_1 = ((st_var_0_1.buffer[2] * 2) + 265) & 63;
  int stage_v_86_2 = ((st_var_0_2.buffer[2] * 2) + 265) & 63;
  if (stage_v_86_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_86_1) - 5) & 255;
    if (stage_v_86_1 > 47)
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
  if (stage_v_86_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_86_2) - 5) & 255;
    if (stage_v_86_2 > 47)
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

  int stage_v_90_1 = table_1[2];
  int stage_v_90_2 = table_2[2];
  table_1[2] = (table_1[3] + 181) & 63;
  table_2[2] = (table_2[3] + 181) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  }

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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 94) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 94) & 15;
  int stage_v_93_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_93_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  chk_sum_1 ^= stage_v_93_1;
  chk_sum_2 ^= stage_v_93_2;
  int stage_v_94_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (99 & 31);
  int stage_v_94_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (99 & 31);
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  chk_sum_1 ^= (stage_v_94_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_94_2 << 1) & 127;
  int stage_v_95_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_95_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_96_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_96_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_97_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_97_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_97_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_97_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 99) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 99) & 15;
  int stage_v_98_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_98_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  chk_sum_1 ^= stage_v_98_1;
  chk_sum_2 ^= stage_v_98_2;
  int stage_v_99_1 = ((st_var_1_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_1_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 41)
    {
      chk_sum_1 ^= stage_v_99_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_99_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 41)
    {
      chk_sum_2 ^= stage_v_99_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_100_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_100_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_100_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_100_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_101_1 = ((st_var_1_1.buffer[2] * 2) + 310) & 63;
  int stage_v_101_2 = ((st_var_1_2.buffer[2] * 2) + 310) & 63;
  if (stage_v_101_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_101_1) - 5) & 255;
    if (stage_v_101_1 > 50)
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
  if (stage_v_101_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_101_2) - 5) & 255;
    if (stage_v_101_2 > 50)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 103) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 103) & 15;
  int stage_v_102_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_102_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= stage_v_102_1;
  chk_sum_2 ^= stage_v_102_2;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (st_var_0_1.buffer[0] ^ 107) & 3;
  int stage_v_104_2 = (st_var_0_2.buffer[0] ^ 107) & 3;
  switch (stage_v_104_1)
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

  switch (stage_v_104_2)
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

  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_105_1 = ((stage_v_105_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_105_2 = ((stage_v_105_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_106_1 = ((stage_v_106_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_106_2 = ((stage_v_106_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 108) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 108) & 15;
  int stage_v_107_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_107_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  chk_sum_1 ^= stage_v_107_1;
  chk_sum_2 ^= stage_v_107_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 109) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 109) & 15;
  int stage_v_108_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_108_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  chk_sum_1 ^= stage_v_108_1;
  chk_sum_2 ^= stage_v_108_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 110) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 110) & 15;
  int stage_v_109_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_109_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  chk_sum_1 ^= stage_v_109_1;
  chk_sum_2 ^= stage_v_109_2;
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

  switch (stage_v_111_2)
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

  int stage_v_112_1 = table_1[0];
  int stage_v_112_2 = table_2[0];
  table_1[0] = (table_1[1] + 225) & 63;
  table_2[0] = (table_2[1] + 225) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_113_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_113_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_113_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((st_var_1_1.buffer[1] * 2) + 352) & 63;
  int stage_v_115_2 = ((st_var_1_2.buffer[1] * 2) + 352) & 63;
  if (stage_v_115_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_115_1) - 5) & 255;
    if (stage_v_115_1 > 55)
    {
      chk_sum_1 ^= stage_v_115_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_115_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_115_2) - 5) & 255;
    if (stage_v_115_2 > 55)
    {
      chk_sum_2 ^= stage_v_115_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 117) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 117) & 15;
  int stage_v_116_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_116_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= stage_v_116_1;
  chk_sum_2 ^= stage_v_116_2;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_117_1 = ((stage_v_117_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_117_2 = ((stage_v_117_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (123 & 31);
  int stage_v_118_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (123 & 31);
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  chk_sum_1 ^= (stage_v_118_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_118_2 << 1) & 127;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_119_1 = ((stage_v_119_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_119_2 = ((stage_v_119_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((st_var_0_1.buffer[0] * 2) + 367) & 63;
  int stage_v_120_2 = ((st_var_0_2.buffer[0] * 2) + 367) & 63;
  if (stage_v_120_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_120_1) - 5) & 255;
    if (stage_v_120_1 > 28)
    {
      chk_sum_1 ^= stage_v_120_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_120_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_120_2) - 5) & 255;
    if (stage_v_120_2 > 28)
    {
      chk_sum_2 ^= stage_v_120_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_121_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (126 & 31);
  int stage_v_121_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (126 & 31);
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  chk_sum_1 ^= (stage_v_121_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_121_2 << 1) & 127;
  int stage_v_122_1 = ((st_var_0_1.buffer[2] * 2) + 373) & 63;
  int stage_v_122_2 = ((st_var_0_2.buffer[2] * 2) + 373) & 63;
  if (stage_v_122_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_122_1) - 5) & 255;
    if (stage_v_122_1 > 44)
    {
      chk_sum_1 ^= stage_v_122_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_122_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_122_2) - 5) & 255;
    if (stage_v_122_2 > 44)
    {
      chk_sum_2 ^= stage_v_122_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_123_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_123_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_123_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_123_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 125) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 125) & 15;
  int stage_v_124_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_124_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= stage_v_124_1;
  chk_sum_2 ^= stage_v_124_2;
  int stage_v_125_1 = (st_var_1_1.buffer[0] ^ 128) & 3;
  int stage_v_125_2 = (st_var_1_2.buffer[0] ^ 128) & 3;
  switch (stage_v_125_1)
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

  switch (stage_v_125_2)
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

  int stage_v_126_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (131 & 31);
  int stage_v_126_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (131 & 31);
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  chk_sum_1 ^= (stage_v_126_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_126_2 << 1) & 127;
  int stage_v_127_1 = table_1[3];
  int stage_v_127_2 = table_2[3];
  table_1[3] = (table_1[0] + 255) & 63;
  table_2[3] = (table_2[0] + 255) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (st_var_0_1.buffer[0] ^ 131) & 3;
  int stage_v_128_2 = (st_var_0_2.buffer[0] ^ 131) & 3;
  switch (stage_v_128_1)
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

  switch (stage_v_128_2)
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

  int stage_v_129_1 = table_1[1];
  int stage_v_129_2 = table_2[1];
  table_1[1] = (table_1[2] + 259) & 63;
  table_2[1] = (table_2[2] + 259) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_130_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_131_1 = (st_var_1_1.buffer[0] ^ 134) & 3;
  int stage_v_131_2 = (st_var_1_2.buffer[0] ^ 134) & 3;
  switch (stage_v_131_1)
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

  switch (stage_v_131_2)
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

  int stage_v_132_1 = ((st_var_0_1.buffer[0] * 2) + 403) & 63;
  int stage_v_132_2 = ((st_var_0_2.buffer[0] * 2) + 403) & 63;
  if (stage_v_132_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_132_1) - 5) & 255;
    if (stage_v_132_1 > 47)
    {
      chk_sum_1 ^= stage_v_132_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_132_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_132_2) - 5) & 255;
    if (stage_v_132_2 > 47)
    {
      chk_sum_2 ^= stage_v_132_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_133_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_133_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 135) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 135) & 15;
  int stage_v_134_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_134_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= stage_v_134_1;
  chk_sum_2 ^= stage_v_134_2;
  int stage_v_135_1 = table_1[3];
  int stage_v_135_2 = table_2[3];
  table_1[3] = (table_1[0] + 271) & 63;
  table_2[3] = (table_2[0] + 271) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_136_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_136_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_136_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_137_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_137_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_138_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (143 & 31);
  int stage_v_138_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (143 & 31);
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  chk_sum_1 ^= (stage_v_138_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_138_2 << 1) & 127;
  int stage_v_139_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (144 & 31);
  int stage_v_139_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (144 & 31);
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  chk_sum_1 ^= (stage_v_139_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_139_2 << 1) & 127;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((st_var_1_1.buffer[0] * 2) + 430) & 63;
  int stage_v_141_2 = ((st_var_1_2.buffer[0] * 2) + 430) & 63;
  if (stage_v_141_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_141_1) - 5) & 255;
    if (stage_v_141_1 > 29)
    {
      chk_sum_1 ^= stage_v_141_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_141_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_141_2) - 5) & 255;
    if (stage_v_141_2 > 29)
    {
      chk_sum_2 ^= stage_v_141_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_142_1 = ((st_var_0_1.buffer[1] * 2) + 433) & 63;
  int stage_v_142_2 = ((st_var_0_2.buffer[1] * 2) + 433) & 63;
  if (stage_v_142_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_142_1) - 5) & 255;
    if (stage_v_142_1 > 34)
    {
      chk_sum_1 ^= stage_v_142_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_142_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_142_2) - 5) & 255;
    if (stage_v_142_2 > 34)
    {
      chk_sum_2 ^= stage_v_142_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_144_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_145_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (150 & 31);
  int stage_v_145_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (150 & 31);
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  chk_sum_1 ^= (stage_v_145_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_145_2 << 1) & 127;
  int stage_v_146_1 = (st_var_0_1.buffer[0] ^ 149) & 3;
  int stage_v_146_2 = (st_var_0_2.buffer[0] ^ 149) & 3;
  switch (stage_v_146_1)
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

  switch (stage_v_146_2)
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

  int stage_v_147_1 = table_1[3];
  int stage_v_147_2 = table_2[3];
  table_1[3] = (table_1[0] + 295) & 63;
  table_2[3] = (table_2[0] + 295) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_148_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_149_1 = ((stage_v_149_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((st_var_0_1.buffer[0] * 2) + 457) & 63;
  int stage_v_150_2 = ((st_var_0_2.buffer[0] * 2) + 457) & 63;
  if (stage_v_150_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_150_1) - 5) & 255;
    if (stage_v_150_1 > 39)
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
  if (stage_v_150_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_150_2) - 5) & 255;
    if (stage_v_150_2 > 39)
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
  int stage_v_151_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_151_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_151_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_151_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_152_1 = ((stage_v_152_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_152_2 = ((stage_v_152_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((st_var_1_1.buffer[0] * 2) + 466) & 63;
  int stage_v_153_2 = ((st_var_1_2.buffer[0] * 2) + 466) & 63;
  if (stage_v_153_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_153_1) - 5) & 255;
    if (stage_v_153_1 > 36)
    {
      chk_sum_1 ^= stage_v_153_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_153_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_153_2) - 5) & 255;
    if (stage_v_153_2 > 36)
    {
      chk_sum_2 ^= stage_v_153_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_154_1 = ((stage_v_154_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_154_2 = ((stage_v_154_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (st_var_1_1.buffer[0] ^ 158) & 3;
  int stage_v_155_2 = (st_var_1_2.buffer[0] ^ 158) & 3;
  switch (stage_v_155_1)
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

  switch (stage_v_155_2)
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

  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_156_1 = ((stage_v_156_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_156_2 = ((stage_v_156_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_157_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_157_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_157_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_158_1 = (st_var_0_1.buffer[0] ^ 161) & 3;
  int stage_v_158_2 = (st_var_0_2.buffer[0] ^ 161) & 3;
  switch (stage_v_158_1)
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

  switch (stage_v_158_2)
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

  int stage_v_159_1 = (st_var_1_1.buffer[0] ^ 162) & 3;
  int stage_v_159_2 = (st_var_1_2.buffer[0] ^ 162) & 3;
  switch (stage_v_159_1)
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

  switch (stage_v_159_2)
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

  int stage_v_160_1 = (st_var_0_1.buffer[0] ^ 163) & 3;
  int stage_v_160_2 = (st_var_0_2.buffer[0] ^ 163) & 3;
  switch (stage_v_160_1)
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

  switch (stage_v_160_2)
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
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_164_1 = ((stage_v_164_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_164_2 = ((stage_v_164_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = table_1[1];
  int stage_v_165_2 = table_2[1];
  table_1[1] = (table_1[2] + 331) & 63;
  table_2[1] = (table_2[2] + 331) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (st_var_1_1.buffer[0] ^ 170) & 3;
  int stage_v_167_2 = (st_var_1_2.buffer[0] ^ 170) & 3;
  switch (stage_v_167_1)
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

  switch (stage_v_167_2)
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

  int stage_v_168_1 = table_1[0];
  int stage_v_168_2 = table_2[0];
  table_1[0] = (table_1[1] + 337) & 63;
  table_2[0] = (table_2[1] + 337) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (174 & 31);
  int stage_v_169_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (174 & 31);
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  chk_sum_1 ^= (stage_v_169_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_169_2 << 1) & 127;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_170_1 = ((stage_v_170_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_170_2 = ((stage_v_170_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (176 & 31);
  int stage_v_171_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (176 & 31);
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  chk_sum_1 ^= (stage_v_171_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_171_2 << 1) & 127;
  int stage_v_172_1 = ((st_var_0_1.buffer[1] * 2) + 523) & 63;
  int stage_v_172_2 = ((st_var_0_2.buffer[1] * 2) + 523) & 63;
  if (stage_v_172_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_172_1) - 5) & 255;
    if (stage_v_172_1 > 49)
    {
      chk_sum_1 ^= stage_v_172_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_172_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_172_2) - 5) & 255;
    if (stage_v_172_2 > 49)
    {
      chk_sum_2 ^= stage_v_172_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_173_1 = ((st_var_1_1.buffer[2] * 2) + 526) & 63;
  int stage_v_173_2 = ((st_var_1_2.buffer[2] * 2) + 526) & 63;
  if (stage_v_173_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_173_1) - 5) & 255;
    if (stage_v_173_1 > 48)
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
  if (stage_v_173_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_173_2) - 5) & 255;
    if (stage_v_173_2 > 48)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 175) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 175) & 15;
  int stage_v_174_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_174_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  chk_sum_1 ^= stage_v_174_1;
  chk_sum_2 ^= stage_v_174_2;
  int stage_v_175_1 = ((st_var_1_1.buffer[1] * 2) + 532) & 63;
  int stage_v_175_2 = ((st_var_1_2.buffer[1] * 2) + 532) & 63;
  if (stage_v_175_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_175_1) - 5) & 255;
    if (stage_v_175_1 > 43)
    {
      chk_sum_1 ^= stage_v_175_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_175_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_175_2) - 5) & 255;
    if (stage_v_175_2 > 43)
    {
      chk_sum_2 ^= stage_v_175_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_176_1 = ((st_var_0_1.buffer[2] * 2) + 535) & 63;
  int stage_v_176_2 = ((st_var_0_2.buffer[2] * 2) + 535) & 63;
  if (stage_v_176_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_176_1) - 5) & 255;
    if (stage_v_176_1 > 49)
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
  if (stage_v_176_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_176_2) - 5) & 255;
    if (stage_v_176_2 > 49)
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
  if (stage_v_177_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_177_1) - 5) & 255;
    if (stage_v_177_1 > 51)
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
  if (stage_v_177_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_177_2) - 5) & 255;
    if (stage_v_177_2 > 51)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 179) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 179) & 15;
  int stage_v_178_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_178_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  chk_sum_1 ^= stage_v_178_1;
  chk_sum_2 ^= stage_v_178_2;
  int stage_v_179_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (184 & 31);
  int stage_v_179_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (184 & 31);
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  chk_sum_1 ^= (stage_v_179_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_179_2 << 1) & 127;
  int stage_v_180_1 = table_1[0];
  int stage_v_180_2 = table_2[0];
  table_1[0] = (table_1[1] + 361) & 63;
  table_2[0] = (table_2[1] + 361) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((st_var_1_1.buffer[1] * 2) + 550) & 63;
  int stage_v_181_2 = ((st_var_1_2.buffer[1] * 2) + 550) & 63;
  if (stage_v_181_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_181_1) - 5) & 255;
    if (stage_v_181_1 > 46)
    {
      chk_sum_1 ^= stage_v_181_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_181_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_181_2) - 5) & 255;
    if (stage_v_181_2 > 46)
    {
      chk_sum_2 ^= stage_v_181_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_182_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (187 & 31);
  int stage_v_182_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (187 & 31);
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  chk_sum_1 ^= (stage_v_182_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_182_2 << 1) & 127;
  int stage_v_183_1 = ((st_var_1_1.buffer[0] * 2) + 556) & 63;
  int stage_v_183_2 = ((st_var_1_2.buffer[0] * 2) + 556) & 63;
  if (stage_v_183_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_183_1) - 5) & 255;
    if (stage_v_183_1 > 54)
    {
      chk_sum_1 ^= stage_v_183_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_183_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_183_2) - 5) & 255;
    if (stage_v_183_2 > 54)
    {
      chk_sum_2 ^= stage_v_183_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_184_1 = ((st_var_0_1.buffer[1] * 2) + 559) & 63;
  int stage_v_184_2 = ((st_var_0_2.buffer[1] * 2) + 559) & 63;
  if (stage_v_184_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_184_1) - 5) & 255;
    if (stage_v_184_1 > 34)
    {
      chk_sum_1 ^= stage_v_184_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_184_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_184_2) - 5) & 255;
    if (stage_v_184_2 > 34)
    {
      chk_sum_2 ^= stage_v_184_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  out_sink_1 += ((sec_r000102_13_1 * 1) + (sec_r000102_11_1 * 2)) & 255;
  out_sink_2 += ((sec_r000102_13_2 * 1) + (sec_r000102_11_2 * 2)) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000102_11_1 == pub_r000102_11_2);
  __CPROVER_assume(pub_r000102_9_1 == pub_r000102_9_2);
  __CPROVER_assume(pub_r000102_13_1 == pub_r000102_13_2);
  __CPROVER_assume(sec_r000102_2_1 != sec_r000102_2_2);
  __CPROVER_assume(sec_r000102_0_1 != sec_r000102_0_2);
  __CPROVER_assume(pub_r000102_1_1 == pub_r000102_1_2);
  __CPROVER_assume(sec_r000102_5_1 != sec_r000102_5_2);
  __CPROVER_assume(sec_r000102_12_1 != sec_r000102_12_2);
  __CPROVER_assume(pub_r000102_2_1 == pub_r000102_2_2);
  __CPROVER_assume(pub_r000102_6_1 == pub_r000102_6_2);
  __CPROVER_assume(sec_r000102_17_1 != sec_r000102_17_2);
  __CPROVER_assume(pub_r000102_10_1 == pub_r000102_10_2);
  __CPROVER_assume(pub_r000102_16_1 == pub_r000102_16_2);
  __CPROVER_assume(pub_r000102_4_1 == pub_r000102_4_2);
  __CPROVER_assume(sec_r000102_13_1 != sec_r000102_13_2);
  __CPROVER_assume(pub_r000102_8_1 == pub_r000102_8_2);
  __CPROVER_assume(sec_r000102_18_1 != sec_r000102_18_2);
  __CPROVER_assume(pub_r000102_15_1 == pub_r000102_15_2);
  __CPROVER_assume(pub_r000102_5_1 == pub_r000102_5_2);
  __CPROVER_assume(sec_r000102_7_1 != sec_r000102_7_2);
  __CPROVER_assume(sec_r000102_15_1 != sec_r000102_15_2);
  __CPROVER_assume(sec_r000102_6_1 != sec_r000102_6_2);
  __CPROVER_assume(sec_r000102_9_1 != sec_r000102_9_2);
  __CPROVER_assume(sec_r000102_10_1 != sec_r000102_10_2);
  __CPROVER_assume(pub_r000102_3_1 == pub_r000102_3_2);
  __CPROVER_assume(sec_r000102_11_1 != sec_r000102_11_2);
  __CPROVER_assume(pub_r000102_12_1 == pub_r000102_12_2);
  __CPROVER_assume(sec_r000102_4_1 != sec_r000102_4_2);
  __CPROVER_assume(sec_r000102_14_1 != sec_r000102_14_2);
  __CPROVER_assume(sec_r000102_8_1 != sec_r000102_8_2);
  __CPROVER_assume(pub_r000102_0_1 == pub_r000102_0_2);
  __CPROVER_assume(sec_r000102_1_1 != sec_r000102_1_2);
  __CPROVER_assume(sec_r000102_16_1 != sec_r000102_16_2);
  __CPROVER_assume(pub_r000102_14_1 == pub_r000102_14_2);
  __CPROVER_assume(sec_r000102_3_1 != sec_r000102_3_2);
  __CPROVER_assume(pub_r000102_7_1 == pub_r000102_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.tail == st_var_1_2.tail);
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
}


