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
struct Transaction_R000447_4713_0
{
  short auth_code;
  unsigned char fee;
  short status;
  int rate;
  int buffer[3];
};
struct StreamBuffer_R000447_4713_1
{
  int capacity;
  short head;
  unsigned char tail;
  int state;
  unsigned char checksum;
  int buffer[3];
};
union PacketPayload_R000447_4713_0
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
void fn_R000447_4713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st_1 = {0};
  struct Transaction_R000447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int metric_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_30_1 > 12)
  {
    acc_1 = ((acc_1 + (metric_30_1 * 2)) + 5) & 127;
    aux_1 ^= metric_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_30_2 > 12)
  {
    acc_2 = ((acc_2 + (metric_30_2 * 2)) + 5) & 127;
    aux_2 ^= metric_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_30_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_77_1 = local_arr_1[aux_1 % 3];
  int parity_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_30_1 == metric_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_77_1 == parity_77_2);
}

int fn_R000447_4713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int metric_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_30 > 12)
  {
    acc = ((acc + (metric_30 * 2)) + 5) & 127;
    aux ^= metric_30 & 15;
  }
  else
  {
    acc = ((acc - metric_30) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_77 = local_arr[aux % 3];
  acc = (acc + (parity_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st_1 = {0};
  struct Transaction_R000447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int segment_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_26_1)
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

  switch (segment_26_2)
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

  int stride_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_59_1) & 63;
  aux_2 = (aux_2 + stride_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_26_1 == segment_26_2);
  assert(stride_59_1 == stride_59_2);
}

int fn_R000447_4713_1(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int segment_26 = (aux + st.buffer[1]) & 3;
  switch (segment_26)
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

  int stride_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000447_4713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int factor_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_39_1)
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

  switch (factor_39_2)
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
  int residue_59_1 = local_arr_1[aux_1 % 3];
  int residue_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_59_2 * 2)) & 127;
  int bound_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_26_1) & 63;
  aux_2 = (aux_2 + bound_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_39_1 == factor_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_59_1 == residue_59_2);
  assert(bound_26_1 == bound_26_2);
}

int fn_R000447_4713_2(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int factor_39 = (aux + st.buffer[1]) & 3;
  switch (factor_39)
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
  int residue_59 = local_arr[aux % 3];
  acc = (acc + (residue_59 * 2)) & 127;
  int bound_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_26) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_75_1) & 63;
  aux_2 = (aux_2 + cursor_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_20_1 = local_arr_1[aux_1 % 3];
  int checksum_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_75_1 == cursor_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_20_1 == checksum_20_2);
}

int fn_R000447_4713_3(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_75) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_20 = local_arr[aux % 3];
  acc = (acc + (checksum_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st_1 = {0};
  struct Transaction_R000447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int anchor_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_81_1)
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

  switch (anchor_81_2)
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

  int stride_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_87_1) & 63;
  aux_2 = (aux_2 + stride_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_81_1 == anchor_81_2);
  assert(stride_87_1 == stride_87_2);
}

int fn_R000447_4713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int anchor_81 = (aux + st.buffer[1]) & 3;
  switch (anchor_81)
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

  int stride_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_87) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000447_4713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st_1 = {0};
  struct Transaction_R000447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int sample_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_90_1)
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

  switch (sample_90_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_55_1 > 42)
  {
    acc_1 = ((acc_1 + (phase_55_1 * 2)) + 5) & 127;
    aux_1 ^= phase_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_55_2 > 42)
  {
    acc_2 = ((acc_2 + (phase_55_2 * 2)) + 5) & 127;
    aux_2 ^= phase_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_55_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_90_1 == sample_90_2);
  assert(phase_55_1 == phase_55_2);
}

int fn_R000447_4713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int sample_90 = (aux + st.buffer[1]) & 3;
  switch (sample_90)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_55 > 42)
  {
    acc = ((acc + (phase_55 * 2)) + 5) & 127;
    aux ^= phase_55 & 15;
  }
  else
  {
    acc = ((acc - phase_55) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000447_4713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int phase_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_91_1)
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

  switch (phase_91_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_91_1 == phase_91_2);
}

int fn_R000447_4713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int phase_91 = (aux + st.buffer[1]) & 3;
  switch (phase_91)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int anchor_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_80_1) & 63;
  aux_2 = (aux_2 + anchor_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_77_1 = local_arr_1[aux_1 % 3];
  int cursor_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_77_2 * 2)) & 127;
  int cursor_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_41_1)
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

  switch (cursor_41_2)
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

  int cursor_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_64_1 > 28)
  {
    acc_1 = ((acc_1 + (cursor_64_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_64_2 > 28)
  {
    acc_2 = ((acc_2 + (cursor_64_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_80_1 == anchor_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_77_1 == cursor_77_2);
  assert(cursor_41_1 == cursor_41_2);
  assert(cursor_64_1 == cursor_64_2);
}

int fn_R000447_4713_7(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int anchor_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_80) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_77 = local_arr[aux % 3];
  acc = (acc + (cursor_77 * 2)) & 127;
  int cursor_41 = (aux + st.buffer[1]) & 3;
  switch (cursor_41)
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

  int cursor_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_64 > 28)
  {
    acc = ((acc + (cursor_64 * 2)) + 5) & 127;
    aux ^= cursor_64 & 15;
  }
  else
  {
    acc = ((acc - cursor_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000447_4713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int accumulator_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_80_1 > 44)
  {
    acc_1 = ((acc_1 + (accumulator_80_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_80_2 > 44)
  {
    acc_2 = ((acc_2 + (accumulator_80_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_87_1 = local_arr_1[aux_1 % 3];
  int coefficient_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_87_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_80_1 == accumulator_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_87_1 == coefficient_87_2);
}

int fn_R000447_4713_8(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int accumulator_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_80 > 44)
  {
    acc = ((acc + (accumulator_80 * 2)) + 5) & 127;
    aux ^= accumulator_80 & 15;
  }
  else
  {
    acc = ((acc - accumulator_80) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_87 = local_arr[aux % 3];
  acc = (acc + (coefficient_87 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_83_1) & 63;
  aux_2 = (aux_2 + parity_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_28_1 = local_arr_1[aux_1 % 3];
  int pivot_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_83_1 == parity_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_28_1 == pivot_28_2);
}

int fn_R000447_4713_9(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_83) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_28 = local_arr[aux % 3];
  acc = (acc + (pivot_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_52_1)
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

  switch (bound_52_2)
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

  int index_reg_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_90_1) & 63;
  aux_2 = (aux_2 + index_reg_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_10_1 = local_arr_1[aux_1 % 3];
  int pivot_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_52_1 == bound_52_2);
  assert(index_reg_90_1 == index_reg_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_10_1 == pivot_10_2);
}

int fn_R000447_4713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_52 = (aux + st.buffer[1]) & 3;
  switch (bound_52)
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

  int index_reg_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_90) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_10 = local_arr[aux % 3];
  acc = (acc + (pivot_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int margin_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_51_1 > 25)
  {
    acc_1 = ((acc_1 + (margin_51_1 * 2)) + 5) & 127;
    aux_1 ^= margin_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_51_2 > 25)
  {
    acc_2 = ((acc_2 + (margin_51_2 * 2)) + 5) & 127;
    aux_2 ^= margin_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_85_1) & 63;
  aux_2 = (aux_2 + quantum_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_63_1 = local_arr_1[aux_1 % 3];
  int quotient_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_51_1 == margin_51_2);
  assert(quantum_85_1 == quantum_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_63_1 == quotient_63_2);
}

int fn_R000447_4713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int margin_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_51 > 25)
  {
    acc = ((acc + (margin_51 * 2)) + 5) & 127;
    aux ^= margin_51 & 15;
  }
  else
  {
    acc = ((acc - margin_51) + 11) & 127;
    aux += 3;
  }
  int quantum_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_85) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_63 = local_arr[aux % 3];
  acc = (acc + (quotient_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st_1 = {0};
  struct Transaction_R000447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int vector_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_33_1 > 16)
  {
    acc_1 = ((acc_1 + (vector_33_1 * 2)) + 5) & 127;
    aux_1 ^= vector_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_33_2 > 16)
  {
    acc_2 = ((acc_2 + (vector_33_2 * 2)) + 5) & 127;
    aux_2 ^= vector_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_88_1 = local_arr_1[aux_1 % 3];
  int anchor_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_33_1 == vector_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_88_1 == anchor_88_2);
}

int fn_R000447_4713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int vector_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_33 > 16)
  {
    acc = ((acc + (vector_33 * 2)) + 5) & 127;
    aux ^= vector_33 & 15;
  }
  else
  {
    acc = ((acc - vector_33) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int anchor_88 = local_arr[aux % 3];
  acc = (acc + (anchor_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int residue_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_23_1 > 17)
  {
    acc_1 = ((acc_1 + (residue_23_1 * 2)) + 5) & 127;
    aux_1 ^= residue_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_23_2 > 17)
  {
    acc_2 = ((acc_2 + (residue_23_2 * 2)) + 5) & 127;
    aux_2 ^= residue_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_28_1 = local_arr_1[aux_1 % 3];
  int stride_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_23_1 == residue_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_28_1 == stride_28_2);
}

int fn_R000447_4713_13(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int residue_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_23 > 17)
  {
    acc = ((acc + (residue_23 * 2)) + 5) & 127;
    aux ^= residue_23 & 15;
  }
  else
  {
    acc = ((acc - residue_23) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_28 = local_arr[aux % 3];
  acc = (acc + (stride_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st_1 = {0};
  struct Transaction_R000447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tracker_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_17_1) & 63;
  aux_2 = (aux_2 + tracker_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_74_1 = local_arr_1[aux_1 % 3];
  int window_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_74_2 * 2)) & 127;
  int sample_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_38_1 > 34)
  {
    acc_1 = ((acc_1 + (sample_38_1 * 2)) + 5) & 127;
    aux_1 ^= sample_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_38_2 > 34)
  {
    acc_2 = ((acc_2 + (sample_38_2 * 2)) + 5) & 127;
    aux_2 ^= sample_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_17_1 == tracker_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_74_1 == window_74_2);
  assert(sample_38_1 == sample_38_2);
}

int fn_R000447_4713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tracker_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_17) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int window_74 = local_arr[aux % 3];
  acc = (acc + (window_74 * 2)) & 127;
  int sample_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_38 > 34)
  {
    acc = ((acc + (sample_38 * 2)) + 5) & 127;
    aux ^= sample_38 & 15;
  }
  else
  {
    acc = ((acc - sample_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000447_4713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st_1 = {0};
  struct Transaction_R000447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int checksum_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_60_1)
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

  switch (checksum_60_2)
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

  int bound_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_45_1) & 63;
  aux_2 = (aux_2 + bound_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_82_1 > 19)
  {
    acc_1 = ((acc_1 + (stride_82_1 * 2)) + 5) & 127;
    aux_1 ^= stride_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_82_2 > 19)
  {
    acc_2 = ((acc_2 + (stride_82_2 * 2)) + 5) & 127;
    aux_2 ^= stride_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_60_1 == checksum_60_2);
  assert(bound_45_1 == bound_45_2);
  assert(stride_82_1 == stride_82_2);
}

int fn_R000447_4713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int checksum_60 = (aux + st.buffer[1]) & 3;
  switch (checksum_60)
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

  int bound_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_45) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_82 > 19)
  {
    acc = ((acc + (stride_82 * 2)) + 5) & 127;
    aux ^= stride_82 & 15;
  }
  else
  {
    acc = ((acc - stride_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000447_4713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int threshold_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_26_1 > 46)
  {
    acc_1 = ((acc_1 + (threshold_26_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_26_2 > 46)
  {
    acc_2 = ((acc_2 + (threshold_26_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_51_1)
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

  switch (stride_51_2)
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
  int parity_99_1 = local_arr_1[aux_1 % 3];
  int parity_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_26_1 == threshold_26_2);
  assert(stride_51_1 == stride_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_99_1 == parity_99_2);
}

int fn_R000447_4713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int threshold_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_26 > 46)
  {
    acc = ((acc + (threshold_26 * 2)) + 5) & 127;
    aux ^= threshold_26 & 15;
  }
  else
  {
    acc = ((acc - threshold_26) + 11) & 127;
    aux += 3;
  }
  int stride_51 = (aux + st.buffer[1]) & 3;
  switch (stride_51)
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
  int parity_99 = local_arr[aux % 3];
  acc = (acc + (parity_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_57_1 = local_arr_1[aux_1 % 3];
  int residue_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_57_2 * 2)) & 127;
  int coefficient_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_63_1 > 36)
  {
    acc_1 = ((acc_1 + (coefficient_63_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_63_2 > 36)
  {
    acc_2 = ((acc_2 + (coefficient_63_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_57_1 == residue_57_2);
  assert(coefficient_63_1 == coefficient_63_2);
}

int fn_R000447_4713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int residue_57 = local_arr[aux % 3];
  acc = (acc + (residue_57 * 2)) & 127;
  int coefficient_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_63 > 36)
  {
    acc = ((acc + (coefficient_63 * 2)) + 5) & 127;
    aux ^= coefficient_63 & 15;
  }
  else
  {
    acc = ((acc - coefficient_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000447_4713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_93_1 = local_arr_1[aux_1 % 3];
  int coefficient_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_93_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_70_1) & 63;
  aux_2 = (aux_2 + metric_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_93_1 == coefficient_93_2);
  assert(metric_70_1 == metric_70_2);
}

int fn_R000447_4713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int coefficient_93 = local_arr[aux % 3];
  acc = (acc + (coefficient_93 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000447_4713_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st_1 = {0};
  struct Transaction_R000447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int anchor_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_38_1) & 63;
  aux_2 = (aux_2 + anchor_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_81_1 > 29)
  {
    acc_1 = ((acc_1 + (weight_81_1 * 2)) + 5) & 127;
    aux_1 ^= weight_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_81_2 > 29)
  {
    acc_2 = ((acc_2 + (weight_81_2 * 2)) + 5) & 127;
    aux_2 ^= weight_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_38_1 == anchor_38_2);
  assert(weight_81_1 == weight_81_2);
}

int fn_R000447_4713_19(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int anchor_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_38) & 63;
  acc ^= aux;
  int weight_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_81 > 29)
  {
    acc = ((acc + (weight_81 * 2)) + 5) & 127;
    aux ^= weight_81 & 15;
  }
  else
  {
    acc = ((acc - weight_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000447_4713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int metric_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_25_1) & 63;
  aux_2 = (aux_2 + metric_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_74_1 > 35)
  {
    acc_1 = ((acc_1 + (window_74_1 * 2)) + 5) & 127;
    aux_1 ^= window_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_74_2 > 35)
  {
    acc_2 = ((acc_2 + (window_74_2 * 2)) + 5) & 127;
    aux_2 ^= window_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_74_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_25_1 == metric_25_2);
  assert(window_74_1 == window_74_2);
}

int fn_R000447_4713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000447_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int metric_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_25) & 63;
  acc ^= aux;
  int window_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_74 > 35)
  {
    acc = ((acc + (window_74 * 2)) + 5) & 127;
    aux ^= window_74 & 15;
  }
  else
  {
    acc = ((acc - window_74) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000447_4713_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st_1 = {0};
  struct Transaction_R000447_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quotient_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_18_1) & 63;
  aux_2 = (aux_2 + quotient_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_71_1)
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

  switch (index_reg_71_2)
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
  int offset_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_10_1 > 39)
  {
    acc_1 = ((acc_1 + (offset_10_1 * 2)) + 5) & 127;
    aux_1 ^= offset_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_10_2 > 39)
  {
    acc_2 = ((acc_2 + (offset_10_2 * 2)) + 5) & 127;
    aux_2 ^= offset_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_18_1 == quotient_18_2);
  assert(index_reg_71_1 == index_reg_71_2);
  assert(offset_10_1 == offset_10_2);
}

int fn_R000447_4713_21(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000447_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quotient_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_18) & 63;
  acc ^= aux;
  int index_reg_71 = (aux + st.buffer[1]) & 3;
  switch (index_reg_71)
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
  int offset_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_10 > 39)
  {
    acc = ((acc + (offset_10 * 2)) + 5) & 127;
    aux ^= offset_10 & 15;
  }
  else
  {
    acc = ((acc - offset_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000447_0_1;
  int sec_r000447_0_2;
  int sec_r000447_1_1;
  int sec_r000447_1_2;
  int sec_r000447_2_1;
  int sec_r000447_2_2;
  int sec_r000447_3_1;
  int sec_r000447_3_2;
  int sec_r000447_4_1;
  int sec_r000447_4_2;
  int sec_r000447_5_1;
  int sec_r000447_5_2;
  int sec_r000447_6_1;
  int sec_r000447_6_2;
  int sec_r000447_7_1;
  int sec_r000447_7_2;
  int sec_r000447_8_1;
  int sec_r000447_8_2;
  int sec_r000447_9_1;
  int sec_r000447_9_2;
  int sec_r000447_10_1;
  int sec_r000447_10_2;
  int sec_r000447_11_1;
  int sec_r000447_11_2;
  int sec_r000447_12_1;
  int sec_r000447_12_2;
  int sec_r000447_13_1;
  int sec_r000447_13_2;
  int sec_r000447_14_1;
  int sec_r000447_14_2;
  int sec_r000447_15_1;
  int sec_r000447_15_2;
  int sec_r000447_16_1;
  int sec_r000447_16_2;
  int sec_r000447_17_1;
  int sec_r000447_17_2;
  int sec_r000447_18_1;
  int sec_r000447_18_2;
  int sec_r000447_19_1;
  int sec_r000447_19_2;
  int sec_r000447_20_1;
  int sec_r000447_20_2;
  int pub_r000447_0_1;
  int pub_r000447_0_2;
  int pub_r000447_1_1;
  int pub_r000447_1_2;
  int pub_r000447_2_1;
  int pub_r000447_2_2;
  int pub_r000447_3_1;
  int pub_r000447_3_2;
  int pub_r000447_4_1;
  int pub_r000447_4_2;
  int pub_r000447_5_1;
  int pub_r000447_5_2;
  int pub_r000447_6_1;
  int pub_r000447_6_2;
  int pub_r000447_7_1;
  int pub_r000447_7_2;
  int pub_r000447_8_1;
  int pub_r000447_8_2;
  int pub_r000447_9_1;
  int pub_r000447_9_2;
  int pub_r000447_10_1;
  int pub_r000447_10_2;
  int pub_r000447_11_1;
  int pub_r000447_11_2;
  int pub_r000447_12_1;
  int pub_r000447_12_2;
  int pub_r000447_13_1;
  int pub_r000447_13_2;
  int pub_r000447_14_1;
  int pub_r000447_14_2;
  int pub_r000447_15_1;
  int pub_r000447_15_2;
  int pub_r000447_16_1;
  int pub_r000447_16_2;
  int pub_r000447_17_1;
  int pub_r000447_17_2;
  int pub_r000447_18_1;
  int pub_r000447_18_2;
  int pub_r000447_19_1;
  int pub_r000447_19_2;
  int pub_r000447_20_1;
  int pub_r000447_20_2;
  int pub_r000447_21_1;
  int pub_r000447_21_2;
  int pub_r000447_22_1;
  int pub_r000447_22_2;
  int pub_r000447_23_1;
  int pub_r000447_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000447_0_1 >= (-100)) && (pub_r000447_0_1 <= 100));
  __CPROVER_assume((pub_r000447_0_2 >= (-100)) && (pub_r000447_0_2 <= 100));
  __CPROVER_assume((pub_r000447_1_1 >= (-100)) && (pub_r000447_1_1 <= 100));
  __CPROVER_assume((pub_r000447_1_2 >= (-100)) && (pub_r000447_1_2 <= 100));
  __CPROVER_assume((pub_r000447_2_1 >= (-100)) && (pub_r000447_2_1 <= 100));
  __CPROVER_assume((pub_r000447_2_2 >= (-100)) && (pub_r000447_2_2 <= 100));
  __CPROVER_assume((pub_r000447_3_1 >= (-100)) && (pub_r000447_3_1 <= 100));
  __CPROVER_assume((pub_r000447_3_2 >= (-100)) && (pub_r000447_3_2 <= 100));
  __CPROVER_assume((pub_r000447_4_1 >= (-100)) && (pub_r000447_4_1 <= 100));
  __CPROVER_assume((pub_r000447_4_2 >= (-100)) && (pub_r000447_4_2 <= 100));
  __CPROVER_assume((pub_r000447_5_1 >= (-100)) && (pub_r000447_5_1 <= 100));
  __CPROVER_assume((pub_r000447_5_2 >= (-100)) && (pub_r000447_5_2 <= 100));
  __CPROVER_assume((pub_r000447_6_1 >= (-100)) && (pub_r000447_6_1 <= 100));
  __CPROVER_assume((pub_r000447_6_2 >= (-100)) && (pub_r000447_6_2 <= 100));
  __CPROVER_assume((pub_r000447_7_1 >= (-100)) && (pub_r000447_7_1 <= 100));
  __CPROVER_assume((pub_r000447_7_2 >= (-100)) && (pub_r000447_7_2 <= 100));
  __CPROVER_assume((pub_r000447_8_1 >= (-100)) && (pub_r000447_8_1 <= 100));
  __CPROVER_assume((pub_r000447_8_2 >= (-100)) && (pub_r000447_8_2 <= 100));
  __CPROVER_assume((pub_r000447_9_1 >= (-100)) && (pub_r000447_9_1 <= 100));
  __CPROVER_assume((pub_r000447_9_2 >= (-100)) && (pub_r000447_9_2 <= 100));
  __CPROVER_assume((pub_r000447_10_1 >= (-100)) && (pub_r000447_10_1 <= 100));
  __CPROVER_assume((pub_r000447_10_2 >= (-100)) && (pub_r000447_10_2 <= 100));
  __CPROVER_assume((pub_r000447_11_1 >= (-100)) && (pub_r000447_11_1 <= 100));
  __CPROVER_assume((pub_r000447_11_2 >= (-100)) && (pub_r000447_11_2 <= 100));
  __CPROVER_assume((pub_r000447_12_1 >= (-100)) && (pub_r000447_12_1 <= 100));
  __CPROVER_assume((pub_r000447_12_2 >= (-100)) && (pub_r000447_12_2 <= 100));
  __CPROVER_assume((pub_r000447_13_1 >= (-100)) && (pub_r000447_13_1 <= 100));
  __CPROVER_assume((pub_r000447_13_2 >= (-100)) && (pub_r000447_13_2 <= 100));
  __CPROVER_assume((pub_r000447_14_1 >= (-100)) && (pub_r000447_14_1 <= 100));
  __CPROVER_assume((pub_r000447_14_2 >= (-100)) && (pub_r000447_14_2 <= 100));
  __CPROVER_assume((pub_r000447_15_1 >= (-100)) && (pub_r000447_15_1 <= 100));
  __CPROVER_assume((pub_r000447_15_2 >= (-100)) && (pub_r000447_15_2 <= 100));
  __CPROVER_assume((pub_r000447_16_1 >= (-100)) && (pub_r000447_16_1 <= 100));
  __CPROVER_assume((pub_r000447_16_2 >= (-100)) && (pub_r000447_16_2 <= 100));
  __CPROVER_assume((pub_r000447_17_1 >= (-100)) && (pub_r000447_17_1 <= 100));
  __CPROVER_assume((pub_r000447_17_2 >= (-100)) && (pub_r000447_17_2 <= 100));
  __CPROVER_assume((pub_r000447_18_1 >= (-100)) && (pub_r000447_18_1 <= 100));
  __CPROVER_assume((pub_r000447_18_2 >= (-100)) && (pub_r000447_18_2 <= 100));
  __CPROVER_assume((pub_r000447_19_1 >= (-100)) && (pub_r000447_19_1 <= 100));
  __CPROVER_assume((pub_r000447_19_2 >= (-100)) && (pub_r000447_19_2 <= 100));
  __CPROVER_assume((pub_r000447_20_1 >= (-100)) && (pub_r000447_20_1 <= 100));
  __CPROVER_assume((pub_r000447_20_2 >= (-100)) && (pub_r000447_20_2 <= 100));
  __CPROVER_assume((pub_r000447_21_1 >= (-100)) && (pub_r000447_21_1 <= 100));
  __CPROVER_assume((pub_r000447_21_2 >= (-100)) && (pub_r000447_21_2 <= 100));
  __CPROVER_assume((pub_r000447_22_1 >= (-100)) && (pub_r000447_22_1 <= 100));
  __CPROVER_assume((pub_r000447_22_2 >= (-100)) && (pub_r000447_22_2 <= 100));
  __CPROVER_assume((pub_r000447_23_1 >= (-100)) && (pub_r000447_23_1 <= 100));
  __CPROVER_assume((pub_r000447_23_2 >= (-100)) && (pub_r000447_23_2 <= 100));
  __CPROVER_assume((sec_r000447_0_1 >= 0) && (sec_r000447_0_1 <= 255));
  __CPROVER_assume((sec_r000447_0_2 >= 0) && (sec_r000447_0_2 <= 255));
  __CPROVER_assume((sec_r000447_1_1 >= 0) && (sec_r000447_1_1 <= 255));
  __CPROVER_assume((sec_r000447_1_2 >= 0) && (sec_r000447_1_2 <= 255));
  __CPROVER_assume((sec_r000447_2_1 >= 0) && (sec_r000447_2_1 <= 255));
  __CPROVER_assume((sec_r000447_2_2 >= 0) && (sec_r000447_2_2 <= 255));
  __CPROVER_assume((sec_r000447_3_1 >= 0) && (sec_r000447_3_1 <= 255));
  __CPROVER_assume((sec_r000447_3_2 >= 0) && (sec_r000447_3_2 <= 255));
  __CPROVER_assume((sec_r000447_4_1 >= 0) && (sec_r000447_4_1 <= 255));
  __CPROVER_assume((sec_r000447_4_2 >= 0) && (sec_r000447_4_2 <= 255));
  __CPROVER_assume((sec_r000447_5_1 >= 0) && (sec_r000447_5_1 <= 255));
  __CPROVER_assume((sec_r000447_5_2 >= 0) && (sec_r000447_5_2 <= 255));
  __CPROVER_assume((sec_r000447_6_1 >= 0) && (sec_r000447_6_1 <= 255));
  __CPROVER_assume((sec_r000447_6_2 >= 0) && (sec_r000447_6_2 <= 255));
  __CPROVER_assume((sec_r000447_7_1 >= 0) && (sec_r000447_7_1 <= 255));
  __CPROVER_assume((sec_r000447_7_2 >= 0) && (sec_r000447_7_2 <= 255));
  __CPROVER_assume((sec_r000447_8_1 >= 0) && (sec_r000447_8_1 <= 255));
  __CPROVER_assume((sec_r000447_8_2 >= 0) && (sec_r000447_8_2 <= 255));
  __CPROVER_assume((sec_r000447_9_1 >= 0) && (sec_r000447_9_1 <= 255));
  __CPROVER_assume((sec_r000447_9_2 >= 0) && (sec_r000447_9_2 <= 255));
  __CPROVER_assume((sec_r000447_10_1 >= 0) && (sec_r000447_10_1 <= 255));
  __CPROVER_assume((sec_r000447_10_2 >= 0) && (sec_r000447_10_2 <= 255));
  __CPROVER_assume((sec_r000447_11_1 >= 0) && (sec_r000447_11_1 <= 255));
  __CPROVER_assume((sec_r000447_11_2 >= 0) && (sec_r000447_11_2 <= 255));
  __CPROVER_assume((sec_r000447_12_1 >= 0) && (sec_r000447_12_1 <= 255));
  __CPROVER_assume((sec_r000447_12_2 >= 0) && (sec_r000447_12_2 <= 255));
  __CPROVER_assume((sec_r000447_13_1 >= 0) && (sec_r000447_13_1 <= 255));
  __CPROVER_assume((sec_r000447_13_2 >= 0) && (sec_r000447_13_2 <= 255));
  __CPROVER_assume((sec_r000447_14_1 >= 0) && (sec_r000447_14_1 <= 255));
  __CPROVER_assume((sec_r000447_14_2 >= 0) && (sec_r000447_14_2 <= 255));
  __CPROVER_assume((sec_r000447_15_1 >= 0) && (sec_r000447_15_1 <= 255));
  __CPROVER_assume((sec_r000447_15_2 >= 0) && (sec_r000447_15_2 <= 255));
  __CPROVER_assume((sec_r000447_16_1 >= 0) && (sec_r000447_16_1 <= 255));
  __CPROVER_assume((sec_r000447_16_2 >= 0) && (sec_r000447_16_2 <= 255));
  __CPROVER_assume((sec_r000447_17_1 >= 0) && (sec_r000447_17_1 <= 255));
  __CPROVER_assume((sec_r000447_17_2 >= 0) && (sec_r000447_17_2 <= 255));
  __CPROVER_assume((sec_r000447_18_1 >= 0) && (sec_r000447_18_1 <= 255));
  __CPROVER_assume((sec_r000447_18_2 >= 0) && (sec_r000447_18_2 <= 255));
  __CPROVER_assume((sec_r000447_19_1 >= 0) && (sec_r000447_19_1 <= 255));
  __CPROVER_assume((sec_r000447_19_2 >= 0) && (sec_r000447_19_2 <= 255));
  __CPROVER_assume((sec_r000447_20_1 >= 0) && (sec_r000447_20_1 <= 255));
  __CPROVER_assume((sec_r000447_20_2 >= 0) && (sec_r000447_20_2 <= 255));
  struct Transaction_R000447_4713_0 st_var_0_1 = {0};
  struct Transaction_R000447_4713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000447_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000447_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000447_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000447_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000447_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000447_0_2 + 7) & 15;
  struct StreamBuffer_R000447_4713_1 st_var_1_1 = {0};
  struct StreamBuffer_R000447_4713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000447_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000447_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000447_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000447_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000447_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000447_0_2 + 9) & 15;
  union PacketPayload_R000447_4713_0 u_var_1;
  union PacketPayload_R000447_4713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (st_var_1_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_1_2.buffer[0] ^ 6) & 3;
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

  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = ((st_var_0_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_0_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 42)
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
  if (stage_v_10_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 42)
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
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 15) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
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
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  if ((sec_r000447_1_1 & 1) != 0)
  {
    if ((sec_r000447_19_1 & 2) != 0)
    {
      stage_v_19_1 = (pub_r000447_6_1 + 31) & 127;
    }
    else
    {
      stage_v_19_1 = (pub_r000447_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_1 = (pub_r000447_6_1 + 7) & 127;
  }
  if ((sec_r000447_1_2 & 1) != 0)
  {
    if ((sec_r000447_19_2 & 2) != 0)
    {
      stage_v_19_2 = (pub_r000447_6_2 + 31) & 127;
    }
    else
    {
      stage_v_19_2 = (pub_r000447_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_2 = (pub_r000447_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  if ((sec_r000447_12_1 & 1) != 0)
  {
    if ((sec_r000447_12_1 & 2) != 0)
    {
      stage_v_20_1 = (pub_r000447_13_1 + 31) & 127;
    }
    else
    {
      stage_v_20_1 = (pub_r000447_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_1 = (pub_r000447_13_1 + 7) & 127;
  }
  if ((sec_r000447_12_2 & 1) != 0)
  {
    if ((sec_r000447_12_2 & 2) != 0)
    {
      stage_v_20_2 = (pub_r000447_13_2 + 31) & 127;
    }
    else
    {
      stage_v_20_2 = (pub_r000447_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_2 = (pub_r000447_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000447_3_1 & 2) != 0)
    {
      stage_v_21_1 = (pub_r000447_3_1 + 31) & 127;
    }
    else
    {
      stage_v_21_1 = (pub_r000447_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_1 = (pub_r000447_3_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000447_3_2 & 2) != 0)
    {
      stage_v_21_2 = (pub_r000447_3_2 + 31) & 127;
    }
    else
    {
      stage_v_21_2 = (pub_r000447_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_2 = (pub_r000447_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  if ((sec_r000447_7_1 & 1) != 0)
  {
    if ((sec_r000447_19_1 & 2) != 0)
    {
      stage_v_22_1 = (pub_r000447_19_1 + 31) & 127;
    }
    else
    {
      stage_v_22_1 = (pub_r000447_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_1 = (pub_r000447_19_1 + 7) & 127;
  }
  if ((sec_r000447_7_2 & 1) != 0)
  {
    if ((sec_r000447_19_2 & 2) != 0)
    {
      stage_v_22_2 = (pub_r000447_19_2 + 31) & 127;
    }
    else
    {
      stage_v_22_2 = (pub_r000447_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_2 = (pub_r000447_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  if ((sec_r000447_14_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_23_1 = (pub_r000447_22_1 + 31) & 127;
    }
    else
    {
      stage_v_23_1 = (pub_r000447_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_1 = (pub_r000447_22_1 + 7) & 127;
  }
  if ((sec_r000447_14_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_23_2 = (pub_r000447_22_2 + 31) & 127;
    }
    else
    {
      stage_v_23_2 = (pub_r000447_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_2 = (pub_r000447_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((sec_r000447_0_1 & 1) != 0)
  {
    if ((sec_r000447_1_1 & 2) != 0)
    {
      stage_v_24_1 = (pub_r000447_9_1 + 31) & 127;
    }
    else
    {
      stage_v_24_1 = (pub_r000447_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_1 = (pub_r000447_9_1 + 7) & 127;
  }
  if ((sec_r000447_0_2 & 1) != 0)
  {
    if ((sec_r000447_1_2 & 2) != 0)
    {
      stage_v_24_2 = (pub_r000447_9_2 + 31) & 127;
    }
    else
    {
      stage_v_24_2 = (pub_r000447_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_2 = (pub_r000447_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000447_15_1 & 2) != 0)
    {
      stage_v_25_1 = (pub_r000447_19_1 + 31) & 127;
    }
    else
    {
      stage_v_25_1 = (pub_r000447_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_1 = (pub_r000447_19_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000447_15_2 & 2) != 0)
    {
      stage_v_25_2 = (pub_r000447_19_2 + 31) & 127;
    }
    else
    {
      stage_v_25_2 = (pub_r000447_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_2 = (pub_r000447_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_26_1 = (pub_r000447_14_1 + 31) & 127;
    }
    else
    {
      stage_v_26_1 = (pub_r000447_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_1 = (pub_r000447_14_1 + 7) & 127;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_26_2 = (pub_r000447_14_2 + 31) & 127;
    }
    else
    {
      stage_v_26_2 = (pub_r000447_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_2 = (pub_r000447_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000447_12_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000447_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000447_12_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000447_12_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000447_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000447_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r000447_15_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000447_12_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000447_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000447_12_1 + 7) & 127;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r000447_15_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000447_12_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000447_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000447_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000447_9_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000447_22_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000447_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000447_22_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000447_9_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000447_22_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000447_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000447_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((sec_r000447_6_1 & 1) != 0)
  {
    if ((sec_r000447_12_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000447_6_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000447_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000447_6_1 + 7) & 127;
  }
  if ((sec_r000447_6_2 & 1) != 0)
  {
    if ((sec_r000447_12_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000447_6_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000447_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000447_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000447_6_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000447_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000447_6_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000447_6_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000447_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000447_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000447_22_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000447_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000447_22_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000447_22_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000447_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000447_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000447_13_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000447_7_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000447_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000447_7_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000447_13_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000447_7_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000447_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000447_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((sec_r000447_1_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000447_2_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000447_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000447_2_1 + 7) & 127;
  }
  if ((sec_r000447_1_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000447_2_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000447_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000447_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((sec_r000447_7_1 & 1) != 0)
  {
    if ((sec_r000447_6_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000447_6_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000447_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000447_6_1 + 7) & 127;
  }
  if ((sec_r000447_7_2 & 1) != 0)
  {
    if ((sec_r000447_6_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000447_6_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000447_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000447_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((sec_r000447_11_1 & 1) != 0)
  {
    if ((sec_r000447_2_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000447_17_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000447_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000447_17_1 + 7) & 127;
  }
  if ((sec_r000447_11_2 & 1) != 0)
  {
    if ((sec_r000447_2_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000447_17_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000447_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000447_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000447_20_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000447_13_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000447_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000447_13_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000447_20_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000447_13_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000447_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000447_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000447_11_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000447_23_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000447_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000447_23_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000447_11_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000447_23_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000447_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000447_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000447_5_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000447_21_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000447_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000447_21_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000447_5_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000447_21_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000447_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000447_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((sec_r000447_9_1 & 1) != 0)
  {
    if ((sec_r000447_6_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000447_6_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000447_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000447_6_1 + 7) & 127;
  }
  if ((sec_r000447_9_2 & 1) != 0)
  {
    if ((sec_r000447_6_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000447_6_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000447_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000447_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000447_11_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000447_14_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000447_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000447_14_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000447_11_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000447_14_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000447_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000447_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000447_14_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000447_10_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000447_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000447_10_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000447_14_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000447_10_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000447_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000447_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000447_1_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000447_5_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000447_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000447_5_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000447_1_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000447_5_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000447_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000447_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((sec_r000447_4_1 & 1) != 0)
  {
    if ((sec_r000447_15_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000447_17_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000447_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000447_17_1 + 7) & 127;
  }
  if ((sec_r000447_4_2 & 1) != 0)
  {
    if ((sec_r000447_15_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000447_17_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000447_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000447_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000447_23_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000447_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000447_23_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000447_23_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000447_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000447_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000447_17_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000447_3_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000447_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000447_3_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000447_17_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000447_3_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000447_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000447_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((sec_r000447_5_1 & 1) != 0)
  {
    if ((sec_r000447_5_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000447_12_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000447_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000447_12_1 + 7) & 127;
  }
  if ((sec_r000447_5_2 & 1) != 0)
  {
    if ((sec_r000447_5_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000447_12_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000447_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000447_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((sec_r000447_6_1 & 1) != 0)
  {
    if ((sec_r000447_10_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000447_11_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000447_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000447_11_1 + 7) & 127;
  }
  if ((sec_r000447_6_2 & 1) != 0)
  {
    if ((sec_r000447_10_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000447_11_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000447_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000447_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000447_1_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000447_9_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000447_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000447_9_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000447_1_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000447_9_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000447_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000447_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000447_16_1 & 1) != 0)
  {
    if ((sec_r000447_9_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000447_14_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000447_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000447_14_1 + 7) & 127;
  }
  if ((sec_r000447_16_2 & 1) != 0)
  {
    if ((sec_r000447_9_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000447_14_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000447_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000447_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000447_4_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000447_3_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000447_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000447_3_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000447_4_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000447_3_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000447_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000447_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000447_6_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000447_22_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000447_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000447_22_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000447_6_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000447_22_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000447_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000447_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((sec_r000447_17_1 & 1) != 0)
  {
    if ((sec_r000447_17_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000447_9_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000447_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000447_9_1 + 7) & 127;
  }
  if ((sec_r000447_17_2 & 1) != 0)
  {
    if ((sec_r000447_17_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000447_9_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000447_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000447_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000447_19_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000447_6_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000447_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000447_6_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000447_19_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000447_6_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000447_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000447_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000447_18_1 & 1) != 0)
  {
    if ((sec_r000447_17_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000447_0_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000447_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000447_0_1 + 7) & 127;
  }
  if ((sec_r000447_18_2 & 1) != 0)
  {
    if ((sec_r000447_17_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000447_0_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000447_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000447_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000447_13_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000447_14_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000447_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000447_14_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000447_13_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000447_14_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000447_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000447_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000447_0_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000447_21_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000447_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000447_21_1 + 7) & 127;
  }
  if ((sec_r000447_0_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000447_21_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000447_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000447_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000447_14_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000447_19_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000447_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000447_19_1 + 7) & 127;
  }
  if ((sec_r000447_14_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000447_19_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000447_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000447_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000447_0_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000447_7_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000447_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000447_7_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000447_0_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000447_7_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000447_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000447_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000447_7_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000447_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000447_7_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000447_7_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000447_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000447_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000447_20_1 & 1) != 0)
  {
    if ((sec_r000447_4_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000447_23_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000447_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000447_23_1 + 7) & 127;
  }
  if ((sec_r000447_20_2 & 1) != 0)
  {
    if ((sec_r000447_4_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000447_23_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000447_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000447_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000447_11_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000447_17_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000447_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000447_17_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000447_11_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000447_17_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000447_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000447_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000447_19_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000447_10_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000447_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000447_10_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000447_19_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000447_10_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000447_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000447_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000447_7_1 & 1) != 0)
  {
    if ((sec_r000447_2_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000447_18_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000447_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000447_18_1 + 7) & 127;
  }
  if ((sec_r000447_7_2 & 1) != 0)
  {
    if ((sec_r000447_2_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000447_18_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000447_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000447_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000447_6_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000447_3_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000447_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000447_3_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000447_6_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000447_3_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000447_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000447_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000447_2_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000447_12_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000447_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000447_12_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000447_2_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000447_12_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000447_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000447_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000447_5_1 & 1) != 0)
  {
    if ((sec_r000447_7_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000447_3_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000447_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000447_3_1 + 7) & 127;
  }
  if ((sec_r000447_5_2 & 1) != 0)
  {
    if ((sec_r000447_7_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000447_3_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000447_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000447_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000447_0_1 & 1) != 0)
  {
    if ((sec_r000447_12_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000447_14_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000447_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000447_14_1 + 7) & 127;
  }
  if ((sec_r000447_0_2 & 1) != 0)
  {
    if ((sec_r000447_12_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000447_14_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000447_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000447_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000447_10_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000447_23_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000447_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000447_23_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000447_10_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000447_23_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000447_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000447_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000447_10_1 & 1) != 0)
  {
    if ((sec_r000447_16_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000447_19_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000447_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000447_19_1 + 7) & 127;
  }
  if ((sec_r000447_10_2 & 1) != 0)
  {
    if ((sec_r000447_16_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000447_19_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000447_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000447_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000447_8_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000447_8_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000447_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000447_8_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000447_8_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000447_8_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000447_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000447_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000447_6_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000447_11_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000447_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000447_11_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000447_6_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000447_11_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000447_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000447_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000447_11_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000447_9_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000447_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000447_9_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000447_11_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000447_9_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000447_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000447_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000447_20_1 & 1) != 0)
  {
    if ((sec_r000447_15_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000447_7_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000447_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000447_7_1 + 7) & 127;
  }
  if ((sec_r000447_20_2 & 1) != 0)
  {
    if ((sec_r000447_15_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000447_7_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000447_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000447_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000447_13_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000447_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000447_13_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000447_13_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000447_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000447_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000447_8_1 & 1) != 0)
  {
    if ((sec_r000447_9_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000447_1_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000447_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000447_1_1 + 7) & 127;
  }
  if ((sec_r000447_8_2 & 1) != 0)
  {
    if ((sec_r000447_9_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000447_1_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000447_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000447_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000447_12_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000447_16_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000447_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000447_16_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000447_12_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000447_16_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000447_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000447_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000447_5_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000447_11_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000447_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000447_11_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000447_5_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000447_11_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000447_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000447_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000447_16_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000447_17_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000447_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000447_17_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000447_16_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000447_17_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000447_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000447_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000447_8_1 & 1) != 0)
  {
    if ((sec_r000447_8_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000447_11_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000447_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000447_11_1 + 7) & 127;
  }
  if ((sec_r000447_8_2 & 1) != 0)
  {
    if ((sec_r000447_8_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000447_11_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000447_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000447_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000447_15_1 & 1) != 0)
  {
    if ((sec_r000447_19_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000447_9_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000447_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000447_9_1 + 7) & 127;
  }
  if ((sec_r000447_15_2 & 1) != 0)
  {
    if ((sec_r000447_19_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000447_9_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000447_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000447_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000447_0_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000447_20_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000447_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000447_20_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000447_0_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000447_20_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000447_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000447_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000447_2_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000447_14_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000447_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000447_14_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000447_2_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000447_14_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000447_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000447_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000447_20_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000447_12_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000447_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000447_12_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000447_20_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000447_12_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000447_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000447_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000447_19_1 & 1) != 0)
  {
    if ((sec_r000447_20_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000447_15_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000447_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000447_15_1 + 7) & 127;
  }
  if ((sec_r000447_19_2 & 1) != 0)
  {
    if ((sec_r000447_20_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000447_15_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000447_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000447_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000447_0_1 & 1) != 0)
  {
    if ((sec_r000447_6_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000447_5_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000447_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000447_5_1 + 7) & 127;
  }
  if ((sec_r000447_0_2 & 1) != 0)
  {
    if ((sec_r000447_6_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000447_5_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000447_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000447_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000447_3_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000447_4_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000447_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000447_4_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000447_3_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000447_4_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000447_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000447_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000447_16_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000447_15_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000447_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000447_15_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000447_16_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000447_15_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000447_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000447_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000447_6_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000447_12_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000447_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000447_12_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000447_6_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000447_12_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000447_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000447_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000447_17_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000447_5_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000447_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000447_5_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000447_17_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000447_5_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000447_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000447_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000447_7_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000447_9_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000447_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000447_9_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000447_7_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000447_9_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000447_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000447_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000447_1_1 & 1) != 0)
  {
    if ((sec_r000447_14_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000447_16_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000447_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000447_16_1 + 7) & 127;
  }
  if ((sec_r000447_1_2 & 1) != 0)
  {
    if ((sec_r000447_14_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000447_16_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000447_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000447_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000447_0_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000447_18_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000447_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000447_18_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000447_0_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000447_18_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000447_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000447_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000447_3_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000447_18_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000447_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000447_18_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000447_3_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000447_18_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000447_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000447_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000447_1_1 & 1) != 0)
  {
    if ((sec_r000447_17_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000447_15_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000447_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000447_15_1 + 7) & 127;
  }
  if ((sec_r000447_1_2 & 1) != 0)
  {
    if ((sec_r000447_17_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000447_15_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000447_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000447_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000447_16_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000447_0_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000447_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000447_0_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000447_16_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000447_0_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000447_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000447_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000447_5_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000447_23_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000447_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000447_23_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000447_5_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000447_23_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000447_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000447_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r000447_7_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000447_14_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000447_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000447_14_1 + 7) & 127;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r000447_7_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000447_14_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000447_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000447_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000447_2_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000447_7_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000447_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000447_7_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000447_2_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000447_7_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000447_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000447_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000447_3_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000447_0_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000447_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000447_0_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000447_3_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000447_0_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000447_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000447_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000447_9_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000447_7_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000447_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000447_7_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000447_9_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000447_7_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000447_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000447_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000447_19_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000447_16_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000447_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000447_16_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000447_19_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000447_16_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000447_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000447_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000447_2_1 & 1) != 0)
  {
    if ((sec_r000447_5_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000447_5_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000447_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000447_5_1 + 7) & 127;
  }
  if ((sec_r000447_2_2 & 1) != 0)
  {
    if ((sec_r000447_5_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000447_5_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000447_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000447_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000447_5_1 & 1) != 0)
  {
    if ((sec_r000447_16_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000447_6_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000447_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000447_6_1 + 7) & 127;
  }
  if ((sec_r000447_5_2 & 1) != 0)
  {
    if ((sec_r000447_16_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000447_6_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000447_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000447_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000447_3_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000447_4_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000447_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000447_4_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000447_3_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000447_4_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000447_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000447_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000447_18_1 & 1) != 0)
  {
    if ((sec_r000447_16_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000447_15_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000447_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000447_15_1 + 7) & 127;
  }
  if ((sec_r000447_18_2 & 1) != 0)
  {
    if ((sec_r000447_16_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000447_15_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000447_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000447_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000447_5_1 & 1) != 0)
  {
    if ((sec_r000447_16_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000447_18_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000447_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000447_18_1 + 7) & 127;
  }
  if ((sec_r000447_5_2 & 1) != 0)
  {
    if ((sec_r000447_16_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000447_18_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000447_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000447_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000447_8_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000447_21_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000447_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000447_21_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000447_8_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000447_21_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000447_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000447_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000447_5_1 & 1) != 0)
  {
    if ((sec_r000447_11_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000447_13_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000447_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000447_13_1 + 7) & 127;
  }
  if ((sec_r000447_5_2 & 1) != 0)
  {
    if ((sec_r000447_11_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000447_13_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000447_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000447_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000447_16_1 & 1) != 0)
  {
    if ((sec_r000447_13_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000447_0_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000447_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000447_0_1 + 7) & 127;
  }
  if ((sec_r000447_16_2 & 1) != 0)
  {
    if ((sec_r000447_13_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000447_0_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000447_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000447_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000447_19_1 & 1) != 0)
  {
    if ((sec_r000447_15_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000447_4_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000447_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000447_4_1 + 7) & 127;
  }
  if ((sec_r000447_19_2 & 1) != 0)
  {
    if ((sec_r000447_15_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000447_4_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000447_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000447_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000447_19_1 & 1) != 0)
  {
    if ((sec_r000447_18_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000447_10_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000447_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000447_10_1 + 7) & 127;
  }
  if ((sec_r000447_19_2 & 1) != 0)
  {
    if ((sec_r000447_18_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000447_10_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000447_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000447_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000447_13_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000447_13_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000447_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000447_13_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000447_13_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000447_13_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000447_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000447_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000447_16_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000447_22_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000447_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000447_22_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000447_16_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000447_22_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000447_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000447_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000447_7_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000447_6_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000447_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000447_6_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000447_7_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000447_6_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000447_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000447_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000447_0_1 & 1) != 0)
  {
    if ((sec_r000447_20_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000447_5_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000447_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000447_5_1 + 7) & 127;
  }
  if ((sec_r000447_0_2 & 1) != 0)
  {
    if ((sec_r000447_20_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000447_5_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000447_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000447_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000447_20_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000447_9_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000447_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000447_9_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000447_20_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000447_9_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000447_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000447_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000447_10_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000447_8_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000447_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000447_8_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000447_10_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000447_8_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000447_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000447_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000447_15_1 == pub_r000447_15_2);
  __CPROVER_assume(pub_r000447_23_1 == pub_r000447_23_2);
  __CPROVER_assume(sec_r000447_9_1 != sec_r000447_9_2);
  __CPROVER_assume(pub_r000447_1_1 == pub_r000447_1_2);
  __CPROVER_assume(pub_r000447_8_1 == pub_r000447_8_2);
  __CPROVER_assume(pub_r000447_5_1 == pub_r000447_5_2);
  __CPROVER_assume(sec_r000447_2_1 != sec_r000447_2_2);
  __CPROVER_assume(sec_r000447_12_1 != sec_r000447_12_2);
  __CPROVER_assume(pub_r000447_3_1 == pub_r000447_3_2);
  __CPROVER_assume(pub_r000447_10_1 == pub_r000447_10_2);
  __CPROVER_assume(sec_r000447_1_1 != sec_r000447_1_2);
  __CPROVER_assume(sec_r000447_8_1 != sec_r000447_8_2);
  __CPROVER_assume(pub_r000447_9_1 == pub_r000447_9_2);
  __CPROVER_assume(pub_r000447_18_1 == pub_r000447_18_2);
  __CPROVER_assume(sec_r000447_3_1 != sec_r000447_3_2);
  __CPROVER_assume(sec_r000447_13_1 != sec_r000447_13_2);
  __CPROVER_assume(sec_r000447_14_1 != sec_r000447_14_2);
  __CPROVER_assume(sec_r000447_17_1 != sec_r000447_17_2);
  __CPROVER_assume(pub_r000447_11_1 == pub_r000447_11_2);
  __CPROVER_assume(sec_r000447_16_1 != sec_r000447_16_2);
  __CPROVER_assume(pub_r000447_4_1 == pub_r000447_4_2);
  __CPROVER_assume(pub_r000447_2_1 == pub_r000447_2_2);
  __CPROVER_assume(pub_r000447_19_1 == pub_r000447_19_2);
  __CPROVER_assume(pub_r000447_21_1 == pub_r000447_21_2);
  __CPROVER_assume(pub_r000447_14_1 == pub_r000447_14_2);
  __CPROVER_assume(pub_r000447_20_1 == pub_r000447_20_2);
  __CPROVER_assume(pub_r000447_0_1 == pub_r000447_0_2);
  __CPROVER_assume(sec_r000447_15_1 != sec_r000447_15_2);
  __CPROVER_assume(pub_r000447_7_1 == pub_r000447_7_2);
  __CPROVER_assume(sec_r000447_5_1 != sec_r000447_5_2);
  __CPROVER_assume(pub_r000447_13_1 == pub_r000447_13_2);
  __CPROVER_assume(sec_r000447_18_1 != sec_r000447_18_2);
  __CPROVER_assume(pub_r000447_17_1 == pub_r000447_17_2);
  __CPROVER_assume(sec_r000447_10_1 != sec_r000447_10_2);
  __CPROVER_assume(sec_r000447_19_1 != sec_r000447_19_2);
  __CPROVER_assume(sec_r000447_4_1 != sec_r000447_4_2);
  __CPROVER_assume(sec_r000447_7_1 != sec_r000447_7_2);
  __CPROVER_assume(sec_r000447_20_1 != sec_r000447_20_2);
  __CPROVER_assume(sec_r000447_6_1 != sec_r000447_6_2);
  __CPROVER_assume(pub_r000447_16_1 == pub_r000447_16_2);
  __CPROVER_assume(pub_r000447_12_1 == pub_r000447_12_2);
  __CPROVER_assume(sec_r000447_11_1 != sec_r000447_11_2);
  __CPROVER_assume(sec_r000447_0_1 != sec_r000447_0_2);
  __CPROVER_assume(pub_r000447_6_1 == pub_r000447_6_2);
  __CPROVER_assume(pub_r000447_22_1 == pub_r000447_22_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
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
}


