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
struct MatrixBlock_R000257_5713_0
{
  short scale;
  short stride;
  short trace;
  int buffer[3];
};
struct EventLog_R000257_5713_1
{
  unsigned char timestamp;
  int seq;
  int code;
  int buffer[3];
};
struct Transaction_R000257_5713_2
{
  int status;
  short account_id;
  short balance;
  int fee;
  unsigned char auth_code;
  int buffer[3];
};
struct StreamBuffer_R000257_5713_3
{
  int state;
  int tail;
  int head;
  unsigned char checksum;
  unsigned char capacity;
  int buffer[3];
};
union PacketPayload_R000257_5713_0
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
void fn_R000257_5713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int stride_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_14_1)
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

  switch (stride_14_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_83_1 = local_arr_1[aux_1 % 3];
  int pivot_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_83_2 * 2)) & 127;
  int phase_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_16_1 > 40)
  {
    acc_1 = ((acc_1 + (phase_16_1 * 2)) + 5) & 127;
    aux_1 ^= phase_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_16_2 > 40)
  {
    acc_2 = ((acc_2 + (phase_16_2 * 2)) + 5) & 127;
    aux_2 ^= phase_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_14_1 == stride_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_83_1 == pivot_83_2);
  assert(phase_16_1 == phase_16_2);
}

int fn_R000257_5713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int stride_14 = (aux + st.buffer[1]) & 3;
  switch (stride_14)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_83 = local_arr[aux % 3];
  acc = (acc + (pivot_83 * 2)) & 127;
  int phase_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_16 > 40)
  {
    acc = ((acc + (phase_16 * 2)) + 5) & 127;
    aux ^= phase_16 & 15;
  }
  else
  {
    acc = ((acc - phase_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000257_5713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st_1 = {0};
  struct StreamBuffer_R000257_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int index_reg_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_77_1)
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

  switch (index_reg_77_2)
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

  int stride_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_60_1) & 63;
  aux_2 = (aux_2 + stride_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_78_1 > 38)
  {
    acc_1 = ((acc_1 + (quotient_78_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_78_2 > 38)
  {
    acc_2 = ((acc_2 + (quotient_78_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_33_1 = local_arr_1[aux_1 % 3];
  int index_reg_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_33_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_77_1 == index_reg_77_2);
  assert(stride_60_1 == stride_60_2);
  assert(quotient_78_1 == quotient_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_33_1 == index_reg_33_2);
}

int fn_R000257_5713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int index_reg_77 = (aux + st.buffer[1]) & 3;
  switch (index_reg_77)
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

  int stride_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_60) & 63;
  acc ^= aux;
  int quotient_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_78 > 38)
  {
    acc = ((acc + (quotient_78 * 2)) + 5) & 127;
    aux ^= quotient_78 & 15;
  }
  else
  {
    acc = ((acc - quotient_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_33 = local_arr[aux % 3];
  acc = (acc + (index_reg_33 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000257_5713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int phase_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_51_1)
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

  switch (phase_51_2)
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

  int tally_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_14_1 > 10)
  {
    acc_1 = ((acc_1 + (tally_14_1 * 2)) + 5) & 127;
    aux_1 ^= tally_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_14_2 > 10)
  {
    acc_2 = ((acc_2 + (tally_14_2 * 2)) + 5) & 127;
    aux_2 ^= tally_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_64_1) & 63;
  aux_2 = (aux_2 + quotient_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_63_1 = local_arr_1[aux_1 % 3];
  int parity_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_51_1 == phase_51_2);
  assert(tally_14_1 == tally_14_2);
  assert(quotient_64_1 == quotient_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_63_1 == parity_63_2);
}

int fn_R000257_5713_2(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int phase_51 = (aux + st.buffer[1]) & 3;
  switch (phase_51)
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

  int tally_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_14 > 10)
  {
    acc = ((acc + (tally_14 * 2)) + 5) & 127;
    aux ^= tally_14 & 15;
  }
  else
  {
    acc = ((acc - tally_14) + 11) & 127;
    aux += 3;
  }
  int quotient_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_64) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_63 = local_arr[aux % 3];
  acc = (acc + (parity_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000257_5713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int weight_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_63_1) & 63;
  aux_2 = (aux_2 + weight_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_69_1)
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

  switch (cursor_69_2)
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

  int phase_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_52_1 > 17)
  {
    acc_1 = ((acc_1 + (phase_52_1 * 2)) + 5) & 127;
    aux_1 ^= phase_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_52_2 > 17)
  {
    acc_2 = ((acc_2 + (phase_52_2 * 2)) + 5) & 127;
    aux_2 ^= phase_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_45_1 = local_arr_1[aux_1 % 3];
  int index_reg_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_63_1 == weight_63_2);
  assert(cursor_69_1 == cursor_69_2);
  assert(phase_52_1 == phase_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_45_1 == index_reg_45_2);
}

int fn_R000257_5713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int weight_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_63) & 63;
  acc ^= aux;
  int cursor_69 = (aux + st.buffer[1]) & 3;
  switch (cursor_69)
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

  int phase_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_52 > 17)
  {
    acc = ((acc + (phase_52 * 2)) + 5) & 127;
    aux ^= phase_52 & 15;
  }
  else
  {
    acc = ((acc - phase_52) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_45 = local_arr[aux % 3];
  acc = (acc + (index_reg_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000257_5713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int pivot_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_87_1) & 63;
  aux_2 = (aux_2 + pivot_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_31_1)
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

  switch (quantum_31_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_87_1 == pivot_87_2);
  assert(quantum_31_1 == quantum_31_2);
}

int fn_R000257_5713_4(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int pivot_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_87) & 63;
  acc ^= aux;
  int quantum_31 = (aux + st.buffer[1]) & 3;
  switch (quantum_31)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000257_5713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st_1 = {0};
  struct StreamBuffer_R000257_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_48_1 = local_arr_1[aux_1 % 3];
  int window_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_48_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_45_1)
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

  switch (delta_45_2)
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

  int delta_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_95_1) & 63;
  aux_2 = (aux_2 + delta_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_48_1 == window_48_2);
  assert(delta_45_1 == delta_45_2);
  assert(delta_95_1 == delta_95_2);
}

int fn_R000257_5713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int window_48 = local_arr[aux % 3];
  acc = (acc + (window_48 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_45 = (aux + st.buffer[1]) & 3;
  switch (delta_45)
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

  int delta_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_95) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000257_5713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_79_1 = local_arr_1[aux_1 % 3];
  int quotient_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_79_2 * 2)) & 127;
  int tracker_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_90_1 > 45)
  {
    acc_1 = ((acc_1 + (tracker_90_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_90_2 > 45)
  {
    acc_2 = ((acc_2 + (tracker_90_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_33_1)
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

  switch (bound_33_2)
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

  int threshold_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_22_1) & 63;
  aux_2 = (aux_2 + threshold_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_79_1 == quotient_79_2);
  assert(tracker_90_1 == tracker_90_2);
  assert(bound_33_1 == bound_33_2);
  assert(threshold_22_1 == threshold_22_2);
}

int fn_R000257_5713_6(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int quotient_79 = local_arr[aux % 3];
  acc = (acc + (quotient_79 * 2)) & 127;
  int tracker_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_90 > 45)
  {
    acc = ((acc + (tracker_90 * 2)) + 5) & 127;
    aux ^= tracker_90 & 15;
  }
  else
  {
    acc = ((acc - tracker_90) + 11) & 127;
    aux += 3;
  }
  int bound_33 = (aux + st.buffer[1]) & 3;
  switch (bound_33)
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

  int threshold_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_22) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000257_5713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st_1 = {0};
  struct StreamBuffer_R000257_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_33_1 = local_arr_1[aux_1 % 3];
  int mask_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_33_2 * 2)) & 127;
  int segment_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_43_1 > 14)
  {
    acc_1 = ((acc_1 + (segment_43_1 * 2)) + 5) & 127;
    aux_1 ^= segment_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_43_2 > 14)
  {
    acc_2 = ((acc_2 + (segment_43_2 * 2)) + 5) & 127;
    aux_2 ^= segment_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_43_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_33_1 == mask_33_2);
  assert(segment_43_1 == segment_43_2);
}

int fn_R000257_5713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int mask_33 = local_arr[aux % 3];
  acc = (acc + (mask_33 * 2)) & 127;
  int segment_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_43 > 14)
  {
    acc = ((acc + (segment_43 * 2)) + 5) & 127;
    aux ^= segment_43 & 15;
  }
  else
  {
    acc = ((acc - segment_43) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000257_5713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000257_5713_1 st_1 = {0};
  struct EventLog_R000257_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int phase_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_74_1)
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

  switch (phase_74_2)
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

  int quantum_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_11_1) & 63;
  aux_2 = (aux_2 + quantum_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_50_1 = local_arr_1[aux_1 % 3];
  int parity_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_50_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_74_1 == phase_74_2);
  assert(quantum_11_1 == quantum_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_50_1 == parity_50_2);
}

int fn_R000257_5713_8(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000257_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int phase_74 = (aux + st.buffer[1]) & 3;
  switch (phase_74)
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

  int quantum_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_11) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_50 = local_arr[aux % 3];
  acc = (acc + (parity_50 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000257_5713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000257_5713_1 st_1 = {0};
  struct EventLog_R000257_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int sample_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_91_1 > 24)
  {
    acc_1 = ((acc_1 + (sample_91_1 * 2)) + 5) & 127;
    aux_1 ^= sample_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_91_2 > 24)
  {
    acc_2 = ((acc_2 + (sample_91_2 * 2)) + 5) & 127;
    aux_2 ^= sample_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_91_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_43_1)
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

  switch (sample_43_2)
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

  int residue_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_62_1) & 63;
  aux_2 = (aux_2 + residue_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_91_1 == sample_91_2);
  assert(sample_43_1 == sample_43_2);
  assert(residue_62_1 == residue_62_2);
}

int fn_R000257_5713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000257_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int sample_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_91 > 24)
  {
    acc = ((acc + (sample_91 * 2)) + 5) & 127;
    aux ^= sample_91 & 15;
  }
  else
  {
    acc = ((acc - sample_91) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_43 = (aux + st.buffer[1]) & 3;
  switch (sample_43)
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

  int residue_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000257_5713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_31_1 = local_arr_1[aux_1 % 3];
  int stride_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_31_2 * 2)) & 127;
  int mask_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_30_1) & 63;
  aux_2 = (aux_2 + mask_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_32_1)
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

  switch (metric_32_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_31_1 == stride_31_2);
  assert(mask_30_1 == mask_30_2);
  assert(metric_32_1 == metric_32_2);
}

int fn_R000257_5713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int stride_31 = local_arr[aux % 3];
  acc = (acc + (stride_31 * 2)) & 127;
  int mask_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_30) & 63;
  acc ^= aux;
  int metric_32 = (aux + st.buffer[1]) & 3;
  switch (metric_32)
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

void fn_R000257_5713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_77_1 = local_arr_1[aux_1 % 3];
  int metric_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_77_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_75_1) & 63;
  aux_2 = (aux_2 + threshold_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_77_1 == metric_77_2);
  assert(threshold_75_1 == threshold_75_2);
}

int fn_R000257_5713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int metric_77 = local_arr[aux % 3];
  acc = (acc + (metric_77 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000257_5713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st_1 = {0};
  struct StreamBuffer_R000257_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int pivot_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_28_1)
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

  switch (pivot_28_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_46_1 = local_arr_1[aux_1 % 3];
  int accumulator_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_28_1 == pivot_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_46_1 == accumulator_46_2);
}

int fn_R000257_5713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int pivot_28 = (aux + st.buffer[1]) & 3;
  switch (pivot_28)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_46 = local_arr[aux % 3];
  acc = (acc + (accumulator_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000257_5713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int segment_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_18_1 > 39)
  {
    acc_1 = ((acc_1 + (segment_18_1 * 2)) + 5) & 127;
    aux_1 ^= segment_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_18_2 > 39)
  {
    acc_2 = ((acc_2 + (segment_18_2 * 2)) + 5) & 127;
    aux_2 ^= segment_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_70_1)
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

  switch (mask_70_2)
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
  int threshold_76_1 = local_arr_1[aux_1 % 3];
  int threshold_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_76_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_18_1 == segment_18_2);
  assert(mask_70_1 == mask_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_76_1 == threshold_76_2);
}

int fn_R000257_5713_13(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int segment_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_18 > 39)
  {
    acc = ((acc + (segment_18 * 2)) + 5) & 127;
    aux ^= segment_18 & 15;
  }
  else
  {
    acc = ((acc - segment_18) + 11) & 127;
    aux += 3;
  }
  int mask_70 = (aux + st.buffer[1]) & 3;
  switch (mask_70)
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
  int threshold_76 = local_arr[aux % 3];
  acc = (acc + (threshold_76 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000257_5713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int metric_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_32_1)
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

  switch (metric_32_2)
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

  int metric_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_47_1 > 25)
  {
    acc_1 = ((acc_1 + (metric_47_1 * 2)) + 5) & 127;
    aux_1 ^= metric_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_47_2 > 25)
  {
    acc_2 = ((acc_2 + (metric_47_2 * 2)) + 5) & 127;
    aux_2 ^= metric_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_53_1 = local_arr_1[aux_1 % 3];
  int mask_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_53_2 * 2)) & 127;
  int accumulator_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_28_1) & 63;
  aux_2 = (aux_2 + accumulator_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_32_1 == metric_32_2);
  assert(metric_47_1 == metric_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_53_1 == mask_53_2);
  assert(accumulator_28_1 == accumulator_28_2);
}

int fn_R000257_5713_14(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int metric_32 = (aux + st.buffer[1]) & 3;
  switch (metric_32)
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

  int metric_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_47 > 25)
  {
    acc = ((acc + (metric_47 * 2)) + 5) & 127;
    aux ^= metric_47 & 15;
  }
  else
  {
    acc = ((acc - metric_47) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_53 = local_arr[aux % 3];
  acc = (acc + (mask_53 * 2)) & 127;
  int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_28) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000257_5713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int margin_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_43_1 > 31)
  {
    acc_1 = ((acc_1 + (margin_43_1 * 2)) + 5) & 127;
    aux_1 ^= margin_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_43_2 > 31)
  {
    acc_2 = ((acc_2 + (margin_43_2 * 2)) + 5) & 127;
    aux_2 ^= margin_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_43_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_43_1 == margin_43_2);
}

int fn_R000257_5713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int margin_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_43 > 31)
  {
    acc = ((acc + (margin_43 * 2)) + 5) & 127;
    aux ^= margin_43 & 15;
  }
  else
  {
    acc = ((acc - margin_43) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000257_5713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st_1 = {0};
  struct StreamBuffer_R000257_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quantum_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_53_1) & 63;
  aux_2 = (aux_2 + quantum_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_40_1 = local_arr_1[aux_1 % 3];
  int residue_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_40_2 * 2)) & 127;
  int parity_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_87_1 > 30)
  {
    acc_1 = ((acc_1 + (parity_87_1 * 2)) + 5) & 127;
    aux_1 ^= parity_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_87_2 > 30)
  {
    acc_2 = ((acc_2 + (parity_87_2 * 2)) + 5) & 127;
    aux_2 ^= parity_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_87_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_53_1 == quantum_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_40_1 == residue_40_2);
  assert(parity_87_1 == parity_87_2);
}

int fn_R000257_5713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quantum_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_53) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_40 = local_arr[aux % 3];
  acc = (acc + (residue_40 * 2)) & 127;
  int parity_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_87 > 30)
  {
    acc = ((acc + (parity_87 * 2)) + 5) & 127;
    aux ^= parity_87 & 15;
  }
  else
  {
    acc = ((acc - parity_87) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000257_5713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000257_5713_1 st_1 = {0};
  struct EventLog_R000257_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int scale_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_38_1 > 43)
  {
    acc_1 = ((acc_1 + (scale_38_1 * 2)) + 5) & 127;
    aux_1 ^= scale_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_38_2 > 43)
  {
    acc_2 = ((acc_2 + (scale_38_2 * 2)) + 5) & 127;
    aux_2 ^= scale_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_38_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_27_1 = local_arr_1[aux_1 % 3];
  int segment_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_27_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_38_1 == scale_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_27_1 == segment_27_2);
}

int fn_R000257_5713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000257_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int scale_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_38 > 43)
  {
    acc = ((acc + (scale_38 * 2)) + 5) & 127;
    aux ^= scale_38 & 15;
  }
  else
  {
    acc = ((acc - scale_38) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_27 = local_arr[aux % 3];
  acc = (acc + (segment_27 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000257_5713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000257_5713_2 st_1 = {0};
  struct Transaction_R000257_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_29_1 = local_arr_1[aux_1 % 3];
  int metric_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_29_2 * 2)) & 127;
  int pivot_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_52_1)
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

  switch (pivot_52_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_29_1 == metric_29_2);
  assert(pivot_52_1 == pivot_52_2);
}

int fn_R000257_5713_18(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000257_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_29 = local_arr[aux % 3];
  acc = (acc + (metric_29 * 2)) & 127;
  int pivot_52 = (aux + st.buffer[1]) & 3;
  switch (pivot_52)
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

void fn_R000257_5713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st_1 = {0};
  struct StreamBuffer_R000257_5713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_32_1)
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

  switch (damping_32_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_79_1 = local_arr_1[aux_1 % 3];
  int anchor_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_79_2 * 2)) & 127;
  int tracker_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_89_1) & 63;
  aux_2 = (aux_2 + tracker_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_32_1 == damping_32_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_79_1 == anchor_79_2);
  assert(tracker_89_1 == tracker_89_2);
}

int fn_R000257_5713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000257_5713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_32 = (aux + st.buffer[1]) & 3;
  switch (damping_32)
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

  int local_arr[3] = {4, 9, 15};
  int anchor_79 = local_arr[aux % 3];
  acc = (acc + (anchor_79 * 2)) & 127;
  int tracker_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000257_5713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_95_1 = local_arr_1[aux_1 % 3];
  int phase_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_95_2 * 2)) & 127;
  int residue_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_89_1) & 63;
  aux_2 = (aux_2 + residue_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_97_1)
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

  switch (checksum_97_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_95_1 == phase_95_2);
  assert(residue_89_1 == residue_89_2);
  assert(checksum_97_1 == checksum_97_2);
}

int fn_R000257_5713_20(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000257_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_95 = local_arr[aux % 3];
  acc = (acc + (phase_95 * 2)) & 127;
  int residue_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_89) & 63;
  acc ^= aux;
  int checksum_97 = (aux + st.buffer[1]) & 3;
  switch (checksum_97)
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

void main()
{
  int sec_r000257_0_1;
  int sec_r000257_0_2;
  int sec_r000257_1_1;
  int sec_r000257_1_2;
  int sec_r000257_2_1;
  int sec_r000257_2_2;
  int sec_r000257_3_1;
  int sec_r000257_3_2;
  int sec_r000257_4_1;
  int sec_r000257_4_2;
  int sec_r000257_5_1;
  int sec_r000257_5_2;
  int sec_r000257_6_1;
  int sec_r000257_6_2;
  int sec_r000257_7_1;
  int sec_r000257_7_2;
  int sec_r000257_8_1;
  int sec_r000257_8_2;
  int sec_r000257_9_1;
  int sec_r000257_9_2;
  int sec_r000257_10_1;
  int sec_r000257_10_2;
  int sec_r000257_11_1;
  int sec_r000257_11_2;
  int sec_r000257_12_1;
  int sec_r000257_12_2;
  int sec_r000257_13_1;
  int sec_r000257_13_2;
  int sec_r000257_14_1;
  int sec_r000257_14_2;
  int sec_r000257_15_1;
  int sec_r000257_15_2;
  int sec_r000257_16_1;
  int sec_r000257_16_2;
  int pub_r000257_0_1;
  int pub_r000257_0_2;
  int pub_r000257_1_1;
  int pub_r000257_1_2;
  int pub_r000257_2_1;
  int pub_r000257_2_2;
  int pub_r000257_3_1;
  int pub_r000257_3_2;
  int pub_r000257_4_1;
  int pub_r000257_4_2;
  int pub_r000257_5_1;
  int pub_r000257_5_2;
  int pub_r000257_6_1;
  int pub_r000257_6_2;
  int pub_r000257_7_1;
  int pub_r000257_7_2;
  int pub_r000257_8_1;
  int pub_r000257_8_2;
  int pub_r000257_9_1;
  int pub_r000257_9_2;
  int pub_r000257_10_1;
  int pub_r000257_10_2;
  int pub_r000257_11_1;
  int pub_r000257_11_2;
  int pub_r000257_12_1;
  int pub_r000257_12_2;
  int pub_r000257_13_1;
  int pub_r000257_13_2;
  int pub_r000257_14_1;
  int pub_r000257_14_2;
  int pub_r000257_15_1;
  int pub_r000257_15_2;
  int pub_r000257_16_1;
  int pub_r000257_16_2;
  int pub_r000257_17_1;
  int pub_r000257_17_2;
  int pub_r000257_18_1;
  int pub_r000257_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000257_0_1 >= (-100)) && (pub_r000257_0_1 <= 100));
  __CPROVER_assume((pub_r000257_0_2 >= (-100)) && (pub_r000257_0_2 <= 100));
  __CPROVER_assume((pub_r000257_1_1 >= (-100)) && (pub_r000257_1_1 <= 100));
  __CPROVER_assume((pub_r000257_1_2 >= (-100)) && (pub_r000257_1_2 <= 100));
  __CPROVER_assume((pub_r000257_2_1 >= (-100)) && (pub_r000257_2_1 <= 100));
  __CPROVER_assume((pub_r000257_2_2 >= (-100)) && (pub_r000257_2_2 <= 100));
  __CPROVER_assume((pub_r000257_3_1 >= (-100)) && (pub_r000257_3_1 <= 100));
  __CPROVER_assume((pub_r000257_3_2 >= (-100)) && (pub_r000257_3_2 <= 100));
  __CPROVER_assume((pub_r000257_4_1 >= (-100)) && (pub_r000257_4_1 <= 100));
  __CPROVER_assume((pub_r000257_4_2 >= (-100)) && (pub_r000257_4_2 <= 100));
  __CPROVER_assume((pub_r000257_5_1 >= (-100)) && (pub_r000257_5_1 <= 100));
  __CPROVER_assume((pub_r000257_5_2 >= (-100)) && (pub_r000257_5_2 <= 100));
  __CPROVER_assume((pub_r000257_6_1 >= (-100)) && (pub_r000257_6_1 <= 100));
  __CPROVER_assume((pub_r000257_6_2 >= (-100)) && (pub_r000257_6_2 <= 100));
  __CPROVER_assume((pub_r000257_7_1 >= (-100)) && (pub_r000257_7_1 <= 100));
  __CPROVER_assume((pub_r000257_7_2 >= (-100)) && (pub_r000257_7_2 <= 100));
  __CPROVER_assume((pub_r000257_8_1 >= (-100)) && (pub_r000257_8_1 <= 100));
  __CPROVER_assume((pub_r000257_8_2 >= (-100)) && (pub_r000257_8_2 <= 100));
  __CPROVER_assume((pub_r000257_9_1 >= (-100)) && (pub_r000257_9_1 <= 100));
  __CPROVER_assume((pub_r000257_9_2 >= (-100)) && (pub_r000257_9_2 <= 100));
  __CPROVER_assume((pub_r000257_10_1 >= (-100)) && (pub_r000257_10_1 <= 100));
  __CPROVER_assume((pub_r000257_10_2 >= (-100)) && (pub_r000257_10_2 <= 100));
  __CPROVER_assume((pub_r000257_11_1 >= (-100)) && (pub_r000257_11_1 <= 100));
  __CPROVER_assume((pub_r000257_11_2 >= (-100)) && (pub_r000257_11_2 <= 100));
  __CPROVER_assume((pub_r000257_12_1 >= (-100)) && (pub_r000257_12_1 <= 100));
  __CPROVER_assume((pub_r000257_12_2 >= (-100)) && (pub_r000257_12_2 <= 100));
  __CPROVER_assume((pub_r000257_13_1 >= (-100)) && (pub_r000257_13_1 <= 100));
  __CPROVER_assume((pub_r000257_13_2 >= (-100)) && (pub_r000257_13_2 <= 100));
  __CPROVER_assume((pub_r000257_14_1 >= (-100)) && (pub_r000257_14_1 <= 100));
  __CPROVER_assume((pub_r000257_14_2 >= (-100)) && (pub_r000257_14_2 <= 100));
  __CPROVER_assume((pub_r000257_15_1 >= (-100)) && (pub_r000257_15_1 <= 100));
  __CPROVER_assume((pub_r000257_15_2 >= (-100)) && (pub_r000257_15_2 <= 100));
  __CPROVER_assume((pub_r000257_16_1 >= (-100)) && (pub_r000257_16_1 <= 100));
  __CPROVER_assume((pub_r000257_16_2 >= (-100)) && (pub_r000257_16_2 <= 100));
  __CPROVER_assume((pub_r000257_17_1 >= (-100)) && (pub_r000257_17_1 <= 100));
  __CPROVER_assume((pub_r000257_17_2 >= (-100)) && (pub_r000257_17_2 <= 100));
  __CPROVER_assume((pub_r000257_18_1 >= (-100)) && (pub_r000257_18_1 <= 100));
  __CPROVER_assume((pub_r000257_18_2 >= (-100)) && (pub_r000257_18_2 <= 100));
  __CPROVER_assume((sec_r000257_0_1 >= 0) && (sec_r000257_0_1 <= 255));
  __CPROVER_assume((sec_r000257_0_2 >= 0) && (sec_r000257_0_2 <= 255));
  __CPROVER_assume((sec_r000257_1_1 >= 0) && (sec_r000257_1_1 <= 255));
  __CPROVER_assume((sec_r000257_1_2 >= 0) && (sec_r000257_1_2 <= 255));
  __CPROVER_assume((sec_r000257_2_1 >= 0) && (sec_r000257_2_1 <= 255));
  __CPROVER_assume((sec_r000257_2_2 >= 0) && (sec_r000257_2_2 <= 255));
  __CPROVER_assume((sec_r000257_3_1 >= 0) && (sec_r000257_3_1 <= 255));
  __CPROVER_assume((sec_r000257_3_2 >= 0) && (sec_r000257_3_2 <= 255));
  __CPROVER_assume((sec_r000257_4_1 >= 0) && (sec_r000257_4_1 <= 255));
  __CPROVER_assume((sec_r000257_4_2 >= 0) && (sec_r000257_4_2 <= 255));
  __CPROVER_assume((sec_r000257_5_1 >= 0) && (sec_r000257_5_1 <= 255));
  __CPROVER_assume((sec_r000257_5_2 >= 0) && (sec_r000257_5_2 <= 255));
  __CPROVER_assume((sec_r000257_6_1 >= 0) && (sec_r000257_6_1 <= 255));
  __CPROVER_assume((sec_r000257_6_2 >= 0) && (sec_r000257_6_2 <= 255));
  __CPROVER_assume((sec_r000257_7_1 >= 0) && (sec_r000257_7_1 <= 255));
  __CPROVER_assume((sec_r000257_7_2 >= 0) && (sec_r000257_7_2 <= 255));
  __CPROVER_assume((sec_r000257_8_1 >= 0) && (sec_r000257_8_1 <= 255));
  __CPROVER_assume((sec_r000257_8_2 >= 0) && (sec_r000257_8_2 <= 255));
  __CPROVER_assume((sec_r000257_9_1 >= 0) && (sec_r000257_9_1 <= 255));
  __CPROVER_assume((sec_r000257_9_2 >= 0) && (sec_r000257_9_2 <= 255));
  __CPROVER_assume((sec_r000257_10_1 >= 0) && (sec_r000257_10_1 <= 255));
  __CPROVER_assume((sec_r000257_10_2 >= 0) && (sec_r000257_10_2 <= 255));
  __CPROVER_assume((sec_r000257_11_1 >= 0) && (sec_r000257_11_1 <= 255));
  __CPROVER_assume((sec_r000257_11_2 >= 0) && (sec_r000257_11_2 <= 255));
  __CPROVER_assume((sec_r000257_12_1 >= 0) && (sec_r000257_12_1 <= 255));
  __CPROVER_assume((sec_r000257_12_2 >= 0) && (sec_r000257_12_2 <= 255));
  __CPROVER_assume((sec_r000257_13_1 >= 0) && (sec_r000257_13_1 <= 255));
  __CPROVER_assume((sec_r000257_13_2 >= 0) && (sec_r000257_13_2 <= 255));
  __CPROVER_assume((sec_r000257_14_1 >= 0) && (sec_r000257_14_1 <= 255));
  __CPROVER_assume((sec_r000257_14_2 >= 0) && (sec_r000257_14_2 <= 255));
  __CPROVER_assume((sec_r000257_15_1 >= 0) && (sec_r000257_15_1 <= 255));
  __CPROVER_assume((sec_r000257_15_2 >= 0) && (sec_r000257_15_2 <= 255));
  __CPROVER_assume((sec_r000257_16_1 >= 0) && (sec_r000257_16_1 <= 255));
  __CPROVER_assume((sec_r000257_16_2 >= 0) && (sec_r000257_16_2 <= 255));
  struct MatrixBlock_R000257_5713_0 st_var_0_1 = {0};
  struct MatrixBlock_R000257_5713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000257_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000257_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000257_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000257_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000257_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000257_0_2 + 7) & 15;
  struct EventLog_R000257_5713_1 st_var_1_1 = {0};
  struct EventLog_R000257_5713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000257_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000257_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000257_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000257_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000257_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000257_0_2 + 9) & 15;
  struct Transaction_R000257_5713_2 st_var_2_1 = {0};
  struct Transaction_R000257_5713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000257_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000257_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000257_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000257_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000257_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000257_0_2 + 11) & 15;
  struct StreamBuffer_R000257_5713_3 st_var_3_1 = {0};
  struct StreamBuffer_R000257_5713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000257_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000257_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000257_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000257_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000257_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000257_0_2 + 13) & 15;
  union PacketPayload_R000257_5713_0 u_var_1;
  union PacketPayload_R000257_5713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 30)
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
  if (stage_v_2_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 30)
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
  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = (st_var_2_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_2_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 37)
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
  if (stage_v_12_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 37)
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
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = (st_var_3_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_3_2.buffer[0] ^ 22) & 3;
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

  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 39)
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
  if (stage_v_25_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 39)
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
  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 29) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_30_1 = (st_var_2_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_2_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (st_var_3_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_3_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  int stage_v_42_1 = ((st_var_2_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_2_2.buffer[0] * 2) + 133) & 63;
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
  int stage_v_43_1 = (st_var_3_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_3_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
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
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 29)
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
  if (stage_v_52_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 29)
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
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (60 & 31);
  int stage_v_55_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (60 & 31);
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= (stage_v_55_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_55_2 << 1) & 127;
  int stage_v_56_1 = (st_var_0_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_0_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = (st_var_1_1.buffer[0] ^ 60) & 3;
  int stage_v_57_2 = (st_var_1_2.buffer[0] ^ 60) & 3;
  switch (stage_v_57_1)
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

  switch (stage_v_57_2)
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

  int stage_v_58_1 = ((st_var_2_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_2_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 47)
    {
      chk_sum_1 ^= stage_v_58_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_58_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 47)
    {
      chk_sum_2 ^= stage_v_58_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_59_1 = (st_var_3_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_3_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
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

  switch (stage_v_59_2)
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

  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = table_1[3];
  int stage_v_63_2 = table_2[3];
  table_1[3] = (table_1[0] + 127) & 63;
  table_2[3] = (table_2[0] + 127) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((st_var_0_1.buffer[1] * 2) + 199) & 63;
  int stage_v_64_2 = ((st_var_0_2.buffer[1] * 2) + 199) & 63;
  if (stage_v_64_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_64_1) - 5) & 255;
    if (stage_v_64_1 > 49)
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
  if (stage_v_64_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_64_2) - 5) & 255;
    if (stage_v_64_2 > 49)
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
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  int stage_v_66_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (71 & 31);
  int stage_v_66_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (71 & 31);
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= (stage_v_66_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_66_2 << 1) & 127;
  int stage_v_67_1 = ((st_var_3_1.buffer[1] * 2) + 208) & 63;
  int stage_v_67_2 = ((st_var_3_2.buffer[1] * 2) + 208) & 63;
  if (stage_v_67_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_67_1) - 5) & 255;
    if (stage_v_67_1 > 36)
    {
      chk_sum_1 ^= stage_v_67_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_67_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_67_2) - 5) & 255;
    if (stage_v_67_2 > 36)
    {
      chk_sum_2 ^= stage_v_67_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_68_1 = (st_var_0_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_0_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (74 & 31);
  int stage_v_69_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (74 & 31);
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= (stage_v_69_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_69_2 << 1) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 71) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 71) & 15;
  int stage_v_70_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_70_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= stage_v_70_1;
  chk_sum_2 ^= stage_v_70_2;
  int stage_v_71_1 = ((st_var_3_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_3_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 32)
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
  if (stage_v_71_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 32)
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
  int stage_v_72_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (77 & 31);
  int stage_v_72_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (77 & 31);
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= (stage_v_72_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_72_2 << 1) & 127;
  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 77) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  int stage_v_77_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_77_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_77_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_77_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_78_1 = ((st_var_2_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_2_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 31)
    {
      chk_sum_1 ^= stage_v_78_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_78_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 31)
    {
      chk_sum_2 ^= stage_v_78_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (st_var_0_1.buffer[0] ^ 83) & 3;
  int stage_v_80_2 = (st_var_0_2.buffer[0] ^ 83) & 3;
  switch (stage_v_80_1)
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

  switch (stage_v_80_2)
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

  int stage_v_81_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (86 & 31);
  int stage_v_81_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (86 & 31);
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= (stage_v_81_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_81_2 << 1) & 127;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  }

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
  int stage_v_85_1 = (st_var_1_1.buffer[0] ^ 88) & 3;
  int stage_v_85_2 = (st_var_1_2.buffer[0] ^ 88) & 3;
  switch (stage_v_85_1)
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

  switch (stage_v_85_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 87) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 87) & 15;
  int stage_v_86_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_86_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= stage_v_86_1;
  chk_sum_2 ^= stage_v_86_2;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 88) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 88) & 15;
  int stage_v_87_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_87_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  chk_sum_1 ^= stage_v_87_1;
  chk_sum_2 ^= stage_v_87_2;
  int stage_v_88_1 = ((st_var_0_1.buffer[1] * 2) + 271) & 63;
  int stage_v_88_2 = ((st_var_0_2.buffer[1] * 2) + 271) & 63;
  if (stage_v_88_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_88_1) - 5) & 255;
    if (stage_v_88_1 > 31)
    {
      chk_sum_1 ^= stage_v_88_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_88_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_88_2) - 5) & 255;
    if (stage_v_88_2 > 31)
    {
      chk_sum_2 ^= stage_v_88_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000257_6_1 & 1) != 0)
  {
    if ((sec_r000257_12_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000257_2_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000257_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000257_2_1 + 7) & 127;
  }
  if ((sec_r000257_6_2 & 1) != 0)
  {
    if ((sec_r000257_12_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000257_2_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000257_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000257_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000257_5_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000257_1_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000257_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000257_1_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000257_5_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000257_1_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000257_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000257_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000257_2_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000257_16_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000257_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000257_16_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000257_2_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000257_16_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000257_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000257_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000257_9_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000257_11_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000257_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000257_11_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000257_9_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000257_11_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000257_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000257_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000257_15_1 & 1) != 0)
  {
    if ((sec_r000257_0_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000257_10_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000257_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000257_10_1 + 7) & 127;
  }
  if ((sec_r000257_15_2 & 1) != 0)
  {
    if ((sec_r000257_0_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000257_10_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000257_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000257_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000257_9_1 & 1) != 0)
  {
    if ((sec_r000257_7_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000257_16_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000257_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000257_16_1 + 7) & 127;
  }
  if ((sec_r000257_9_2 & 1) != 0)
  {
    if ((sec_r000257_7_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000257_16_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000257_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000257_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000257_6_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000257_18_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000257_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000257_18_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000257_6_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000257_18_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000257_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000257_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000257_8_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000257_2_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000257_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000257_2_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000257_8_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000257_2_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000257_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000257_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000257_3_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000257_10_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000257_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000257_10_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000257_3_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000257_10_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000257_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000257_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000257_4_1 & 1) != 0)
  {
    if ((sec_r000257_10_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000257_16_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000257_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000257_16_1 + 7) & 127;
  }
  if ((sec_r000257_4_2 & 1) != 0)
  {
    if ((sec_r000257_10_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000257_16_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000257_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000257_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000257_4_1 & 1) != 0)
  {
    if ((sec_r000257_9_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000257_6_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000257_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000257_6_1 + 7) & 127;
  }
  if ((sec_r000257_4_2 & 1) != 0)
  {
    if ((sec_r000257_9_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000257_6_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000257_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000257_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000257_14_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000257_13_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000257_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000257_13_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000257_14_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000257_13_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000257_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000257_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000257_1_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000257_1_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000257_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000257_1_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000257_1_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000257_1_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000257_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000257_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000257_4_1 & 1) != 0)
  {
    if ((sec_r000257_3_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000257_2_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000257_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000257_2_1 + 7) & 127;
  }
  if ((sec_r000257_4_2 & 1) != 0)
  {
    if ((sec_r000257_3_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000257_2_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000257_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000257_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000257_9_1 & 1) != 0)
  {
    if ((sec_r000257_8_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000257_7_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000257_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000257_7_1 + 7) & 127;
  }
  if ((sec_r000257_9_2 & 1) != 0)
  {
    if ((sec_r000257_8_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000257_7_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000257_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000257_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000257_13_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000257_15_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000257_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000257_15_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000257_13_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000257_15_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000257_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000257_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000257_8_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000257_13_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000257_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000257_13_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000257_8_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000257_13_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000257_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000257_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000257_1_1 & 1) != 0)
  {
    if ((sec_r000257_13_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000257_14_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000257_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000257_14_1 + 7) & 127;
  }
  if ((sec_r000257_1_2 & 1) != 0)
  {
    if ((sec_r000257_13_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000257_14_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000257_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000257_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000257_13_1 & 1) != 0)
  {
    if ((sec_r000257_10_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000257_16_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000257_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000257_16_1 + 7) & 127;
  }
  if ((sec_r000257_13_2 & 1) != 0)
  {
    if ((sec_r000257_10_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000257_16_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000257_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000257_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000257_10_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000257_12_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000257_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000257_12_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000257_10_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000257_12_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000257_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000257_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000257_9_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000257_4_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000257_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000257_4_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000257_9_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000257_4_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000257_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000257_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000257_15_1 & 1) != 0)
  {
    if ((sec_r000257_11_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000257_16_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000257_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000257_16_1 + 7) & 127;
  }
  if ((sec_r000257_15_2 & 1) != 0)
  {
    if ((sec_r000257_11_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000257_16_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000257_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000257_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000257_6_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000257_1_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000257_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000257_1_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000257_6_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000257_1_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000257_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000257_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000257_5_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000257_11_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000257_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000257_11_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000257_5_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000257_11_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000257_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000257_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000257_15_1 & 1) != 0)
  {
    if ((sec_r000257_6_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000257_6_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000257_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000257_6_1 + 7) & 127;
  }
  if ((sec_r000257_15_2 & 1) != 0)
  {
    if ((sec_r000257_6_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000257_6_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000257_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000257_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000257_4_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000257_0_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000257_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000257_0_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000257_4_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000257_0_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000257_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000257_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000257_10_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000257_3_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000257_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000257_3_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000257_10_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000257_3_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000257_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000257_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000257_9_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000257_6_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000257_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000257_6_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000257_9_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000257_6_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000257_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000257_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000257_11_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000257_3_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000257_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000257_3_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000257_11_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000257_3_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000257_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000257_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000257_8_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000257_0_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000257_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000257_0_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000257_8_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000257_0_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000257_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000257_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000257_16_1 & 1) != 0)
  {
    if ((sec_r000257_14_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000257_10_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000257_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000257_10_1 + 7) & 127;
  }
  if ((sec_r000257_16_2 & 1) != 0)
  {
    if ((sec_r000257_14_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000257_10_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000257_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000257_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000257_12_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000257_5_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000257_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000257_5_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000257_12_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000257_5_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000257_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000257_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000257_15_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000257_6_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000257_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000257_6_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000257_15_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000257_6_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000257_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000257_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000257_4_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000257_17_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000257_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000257_17_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000257_4_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000257_17_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000257_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000257_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000257_4_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000257_8_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000257_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000257_8_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000257_4_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000257_8_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000257_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000257_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000257_14_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000257_9_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000257_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000257_9_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000257_14_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000257_9_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000257_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000257_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000257_11_1 & 1) != 0)
  {
    if ((sec_r000257_9_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000257_15_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000257_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000257_15_1 + 7) & 127;
  }
  if ((sec_r000257_11_2 & 1) != 0)
  {
    if ((sec_r000257_9_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000257_15_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000257_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000257_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000257_3_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000257_15_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000257_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000257_15_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000257_3_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000257_15_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000257_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000257_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000257_14_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000257_17_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000257_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000257_17_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000257_14_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000257_17_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000257_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000257_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000257_9_1 & 1) != 0)
  {
    if ((sec_r000257_13_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000257_2_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000257_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000257_2_1 + 7) & 127;
  }
  if ((sec_r000257_9_2 & 1) != 0)
  {
    if ((sec_r000257_13_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000257_2_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000257_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000257_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000257_3_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000257_14_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000257_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000257_14_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000257_3_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000257_14_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000257_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000257_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000257_7_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000257_11_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000257_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000257_11_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000257_7_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000257_11_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000257_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000257_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000257_3_1 & 1) != 0)
  {
    if ((sec_r000257_1_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000257_7_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000257_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000257_7_1 + 7) & 127;
  }
  if ((sec_r000257_3_2 & 1) != 0)
  {
    if ((sec_r000257_1_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000257_7_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000257_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000257_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000257_9_1 & 1) != 0)
  {
    if ((sec_r000257_0_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000257_6_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000257_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000257_6_1 + 7) & 127;
  }
  if ((sec_r000257_9_2 & 1) != 0)
  {
    if ((sec_r000257_0_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000257_6_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000257_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000257_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000257_8_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000257_7_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000257_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000257_7_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000257_8_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000257_7_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000257_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000257_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000257_1_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000257_9_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000257_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000257_9_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000257_1_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000257_9_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000257_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000257_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000257_0_1 & 1) != 0)
  {
    if ((sec_r000257_4_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000257_6_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000257_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000257_6_1 + 7) & 127;
  }
  if ((sec_r000257_0_2 & 1) != 0)
  {
    if ((sec_r000257_4_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000257_6_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000257_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000257_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000257_0_1 & 1) != 0)
  {
    if ((sec_r000257_8_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000257_1_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000257_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000257_1_1 + 7) & 127;
  }
  if ((sec_r000257_0_2 & 1) != 0)
  {
    if ((sec_r000257_8_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000257_1_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000257_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000257_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000257_1_1 == pub_r000257_1_2);
  __CPROVER_assume(sec_r000257_2_1 != sec_r000257_2_2);
  __CPROVER_assume(pub_r000257_13_1 == pub_r000257_13_2);
  __CPROVER_assume(pub_r000257_16_1 == pub_r000257_16_2);
  __CPROVER_assume(pub_r000257_9_1 == pub_r000257_9_2);
  __CPROVER_assume(pub_r000257_8_1 == pub_r000257_8_2);
  __CPROVER_assume(sec_r000257_4_1 != sec_r000257_4_2);
  __CPROVER_assume(sec_r000257_7_1 != sec_r000257_7_2);
  __CPROVER_assume(pub_r000257_17_1 == pub_r000257_17_2);
  __CPROVER_assume(sec_r000257_13_1 != sec_r000257_13_2);
  __CPROVER_assume(sec_r000257_14_1 != sec_r000257_14_2);
  __CPROVER_assume(pub_r000257_5_1 == pub_r000257_5_2);
  __CPROVER_assume(pub_r000257_14_1 == pub_r000257_14_2);
  __CPROVER_assume(pub_r000257_4_1 == pub_r000257_4_2);
  __CPROVER_assume(pub_r000257_11_1 == pub_r000257_11_2);
  __CPROVER_assume(pub_r000257_15_1 == pub_r000257_15_2);
  __CPROVER_assume(pub_r000257_7_1 == pub_r000257_7_2);
  __CPROVER_assume(sec_r000257_0_1 != sec_r000257_0_2);
  __CPROVER_assume(sec_r000257_3_1 != sec_r000257_3_2);
  __CPROVER_assume(sec_r000257_5_1 != sec_r000257_5_2);
  __CPROVER_assume(pub_r000257_2_1 == pub_r000257_2_2);
  __CPROVER_assume(pub_r000257_18_1 == pub_r000257_18_2);
  __CPROVER_assume(pub_r000257_12_1 == pub_r000257_12_2);
  __CPROVER_assume(sec_r000257_8_1 != sec_r000257_8_2);
  __CPROVER_assume(pub_r000257_6_1 == pub_r000257_6_2);
  __CPROVER_assume(sec_r000257_15_1 != sec_r000257_15_2);
  __CPROVER_assume(sec_r000257_16_1 != sec_r000257_16_2);
  __CPROVER_assume(sec_r000257_9_1 != sec_r000257_9_2);
  __CPROVER_assume(sec_r000257_11_1 != sec_r000257_11_2);
  __CPROVER_assume(sec_r000257_12_1 != sec_r000257_12_2);
  __CPROVER_assume(sec_r000257_1_1 != sec_r000257_1_2);
  __CPROVER_assume(pub_r000257_3_1 == pub_r000257_3_2);
  __CPROVER_assume(pub_r000257_10_1 == pub_r000257_10_2);
  __CPROVER_assume(sec_r000257_6_1 != sec_r000257_6_2);
  __CPROVER_assume(sec_r000257_10_1 != sec_r000257_10_2);
  __CPROVER_assume(pub_r000257_0_1 == pub_r000257_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.code == st_var_1_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.state == st_var_3_2.state);
  assert(st_var_3_1.tail == st_var_3_2.tail);
  assert(st_var_3_1.head == st_var_3_2.head);
  assert(st_var_3_1.checksum == st_var_3_2.checksum);
  assert(st_var_3_1.capacity == st_var_3_2.capacity);
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
}


