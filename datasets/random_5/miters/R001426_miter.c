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
struct Transaction_R001426_2613_0
{
  short status;
  unsigned char balance;
  unsigned char auth_code;
  short fee;
  int account_id;
  unsigned char rate;
  int buffer[3];
};
struct Vector3D_R001426_2613_1
{
  int coord_x;
  unsigned char norm_sq;
  int pitch;
  unsigned char coord_y;
  int buffer[3];
};
struct StreamBuffer_R001426_2613_2
{
  int state;
  int watermark;
  unsigned char tail;
  unsigned char head;
  short checksum;
  int buffer[3];
};
union TelemetryField_R001426_2613_0
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
void fn_R001426_2613_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st_1 = {0};
  struct Transaction_R001426_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int sample_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_93_1)
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

  switch (sample_93_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_76_1 = 0;
  int segment_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_76_1 = ((segment_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_76_2 = ((segment_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_76_1) & 127;
    acc_2 = (acc_2 + segment_76_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_93_1 == sample_93_2);
  assert(segment_76_1 == segment_76_2);
}

int fn_R001426_2613_0(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int sample_93 = (aux + st.buffer[1]) & 3;
  switch (sample_93)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_76 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_76 = ((segment_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_76) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001426_2613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st_1 = {0};
  struct StreamBuffer_R001426_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_14_1 = local_arr_1[aux_1 % 3];
  int bound_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_14_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_14_1 == bound_14_2);
}

int fn_R001426_2613_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int bound_14 = local_arr[aux % 3];
  acc = (acc + (bound_14 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001426_2613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st_1 = {0};
  struct Transaction_R001426_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int scale_95_1 = 0;
  int scale_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_95_1 = ((scale_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_95_2 = ((scale_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_95_1) & 127;
    acc_2 = (acc_2 + scale_95_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_60_1 = local_arr_1[aux_1 % 3];
  int vector_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_60_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_76_1) & 63;
  aux_2 = (aux_2 + sample_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_95_1 == scale_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_60_1 == vector_60_2);
  assert(sample_76_1 == sample_76_2);
}

int fn_R001426_2613_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int scale_95 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_95 = ((scale_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_95) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int vector_60 = local_arr[aux % 3];
  acc = (acc + (vector_60 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_76) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001426_2613_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st_1 = {0};
  struct StreamBuffer_R001426_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int coefficient_29_1 = 0;
  int coefficient_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_29_1 = ((coefficient_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_29_2 = ((coefficient_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_29_1) & 127;
    acc_2 = (acc_2 + coefficient_29_2) & 127;
  }

  int quotient_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_81_1 > 14)
  {
    acc_1 = ((acc_1 + (quotient_81_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_81_2 > 14)
  {
    acc_2 = ((acc_2 + (quotient_81_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_29_1 == coefficient_29_2);
  assert(quotient_81_1 == quotient_81_2);
}

int fn_R001426_2613_3(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int coefficient_29 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_29 = ((coefficient_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_29) & 127;
  }

  int quotient_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_81 > 14)
  {
    acc = ((acc + (quotient_81 * 2)) + 5) & 127;
    aux ^= quotient_81 & 15;
  }
  else
  {
    acc = ((acc - quotient_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001426_2613_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st_1 = {0};
  struct Transaction_R001426_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_62_1 = local_arr_1[aux_1 % 3];
  int vector_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_62_2 * 2)) & 127;
  int scale_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_12_1 > 45)
  {
    acc_1 = ((acc_1 + (scale_12_1 * 2)) + 5) & 127;
    aux_1 ^= scale_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_12_2 > 45)
  {
    acc_2 = ((acc_2 + (scale_12_2 * 2)) + 5) & 127;
    aux_2 ^= scale_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_12_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_62_1 == vector_62_2);
  assert(scale_12_1 == scale_12_2);
}

int fn_R001426_2613_4(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int vector_62 = local_arr[aux % 3];
  acc = (acc + (vector_62 * 2)) & 127;
  int scale_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_12 > 45)
  {
    acc = ((acc + (scale_12 * 2)) + 5) & 127;
    aux ^= scale_12 & 15;
  }
  else
  {
    acc = ((acc - scale_12) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001426_2613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st_1 = {0};
  struct Vector3D_R001426_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int damping_33_1 = 0;
  int damping_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_33_1 = ((damping_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_33_2 = ((damping_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_33_1) & 127;
    acc_2 = (acc_2 + damping_33_2) & 127;
  }

  int quantum_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_42_1)
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

  switch (quantum_42_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_44_1) & 63;
  aux_2 = (aux_2 + threshold_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_33_1 == damping_33_2);
  assert(quantum_42_1 == quantum_42_2);
  assert(threshold_44_1 == threshold_44_2);
}

int fn_R001426_2613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int damping_33 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_33 = ((damping_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_33) & 127;
  }

  int quantum_42 = (aux + st.buffer[1]) & 3;
  switch (quantum_42)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001426_2613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st_1 = {0};
  struct StreamBuffer_R001426_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_82_1 = local_arr_1[aux_1 % 3];
  int segment_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_82_2 * 2)) & 127;
  int tally_34_1 = 0;
  int tally_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_34_1 = ((tally_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_34_2 = ((tally_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_34_1) & 127;
    acc_2 = (acc_2 + tally_34_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_82_1 == segment_82_2);
  assert(tally_34_1 == tally_34_2);
}

int fn_R001426_2613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int segment_82 = local_arr[aux % 3];
  acc = (acc + (segment_82 * 2)) & 127;
  int tally_34 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_34 = ((tally_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_34) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001426_2613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st_1 = {0};
  struct StreamBuffer_R001426_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int checksum_40_1 = 0;
  int checksum_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_40_1 = ((checksum_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_40_2 = ((checksum_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_40_1) & 127;
    acc_2 = (acc_2 + checksum_40_2) & 127;
  }

  int weight_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_93_1)
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

  switch (weight_93_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_40_1 == checksum_40_2);
  assert(weight_93_1 == weight_93_2);
}

int fn_R001426_2613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int checksum_40 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_40 = ((checksum_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_40) & 127;
  }

  int weight_93 = (aux + st.buffer[1]) & 3;
  switch (weight_93)
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

void fn_R001426_2613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st_1 = {0};
  struct Vector3D_R001426_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int pivot_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_85_1 > 26)
  {
    acc_1 = ((acc_1 + (pivot_85_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_85_2 > 26)
  {
    acc_2 = ((acc_2 + (pivot_85_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_58_1)
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

  switch (phase_58_2)
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

  int threshold_74_1 = 0;
  int threshold_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_74_1 = ((threshold_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_74_2 = ((threshold_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_74_1) & 127;
    acc_2 = (acc_2 + threshold_74_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_38_1 = local_arr_1[aux_1 % 3];
  int tally_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_38_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_85_1 == pivot_85_2);
  assert(phase_58_1 == phase_58_2);
  assert(threshold_74_1 == threshold_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_38_1 == tally_38_2);
}

int fn_R001426_2613_8(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int pivot_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_85 > 26)
  {
    acc = ((acc + (pivot_85 * 2)) + 5) & 127;
    aux ^= pivot_85 & 15;
  }
  else
  {
    acc = ((acc - pivot_85) + 11) & 127;
    aux += 3;
  }
  int phase_58 = (aux + st.buffer[1]) & 3;
  switch (phase_58)
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

  int threshold_74 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_74 = ((threshold_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_74) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tally_38 = local_arr[aux % 3];
  acc = (acc + (tally_38 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001426_2613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st_1 = {0};
  struct StreamBuffer_R001426_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_63_1 = local_arr_1[aux_1 % 3];
  int threshold_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_63_2 * 2)) & 127;
  int index_reg_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_51_1 > 21)
  {
    acc_1 = ((acc_1 + (index_reg_51_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_51_2 > 21)
  {
    acc_2 = ((acc_2 + (index_reg_51_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_63_1 == threshold_63_2);
  assert(index_reg_51_1 == index_reg_51_2);
}

int fn_R001426_2613_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int threshold_63 = local_arr[aux % 3];
  acc = (acc + (threshold_63 * 2)) & 127;
  int index_reg_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_51 > 21)
  {
    acc = ((acc + (index_reg_51 * 2)) + 5) & 127;
    aux ^= index_reg_51 & 15;
  }
  else
  {
    acc = ((acc - index_reg_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001426_2613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st_1 = {0};
  struct StreamBuffer_R001426_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int parity_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_52_1)
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

  switch (parity_52_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_36_1 = 0;
  int metric_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_36_1 = ((metric_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_36_2 = ((metric_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_36_1) & 127;
    acc_2 = (acc_2 + metric_36_2) & 127;
  }

  int tally_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_16_1 > 36)
  {
    acc_1 = ((acc_1 + (tally_16_1 * 2)) + 5) & 127;
    aux_1 ^= tally_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_16_2 > 36)
  {
    acc_2 = ((acc_2 + (tally_16_2 * 2)) + 5) & 127;
    aux_2 ^= tally_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_52_1 == parity_52_2);
  assert(metric_36_1 == metric_36_2);
  assert(tally_16_1 == tally_16_2);
}

int fn_R001426_2613_10(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int parity_52 = (aux + st.buffer[1]) & 3;
  switch (parity_52)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_36 = ((metric_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_36) & 127;
  }

  int tally_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_16 > 36)
  {
    acc = ((acc + (tally_16 * 2)) + 5) & 127;
    aux ^= tally_16 & 15;
  }
  else
  {
    acc = ((acc - tally_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001426_2613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st_1 = {0};
  struct Transaction_R001426_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quotient_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_92_1)
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

  switch (quotient_92_2)
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

  int tally_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_97_1) & 63;
  aux_2 = (aux_2 + tally_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_22_1 = local_arr_1[aux_1 % 3];
  int scale_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_22_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_92_1 == quotient_92_2);
  assert(tally_97_1 == tally_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_22_1 == scale_22_2);
}

int fn_R001426_2613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quotient_92 = (aux + st.buffer[1]) & 3;
  switch (quotient_92)
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

  int tally_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_97) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_22 = local_arr[aux % 3];
  acc = (acc + (scale_22 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001426_2613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st_1 = {0};
  struct Vector3D_R001426_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int margin_21_1 = 0;
  int margin_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_21_1 = ((margin_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_21_2 = ((margin_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_21_1) & 127;
    acc_2 = (acc_2 + margin_21_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_86_1 > 24)
  {
    acc_1 = ((acc_1 + (tally_86_1 * 2)) + 5) & 127;
    aux_1 ^= tally_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_86_2 > 24)
  {
    acc_2 = ((acc_2 + (tally_86_2 * 2)) + 5) & 127;
    aux_2 ^= tally_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_13_1) & 63;
  aux_2 = (aux_2 + sample_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_21_1 == margin_21_2);
  assert(tally_86_1 == tally_86_2);
  assert(sample_13_1 == sample_13_2);
}

int fn_R001426_2613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int margin_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_21 = ((margin_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_21) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_86 > 24)
  {
    acc = ((acc + (tally_86 * 2)) + 5) & 127;
    aux ^= tally_86 & 15;
  }
  else
  {
    acc = ((acc - tally_86) + 11) & 127;
    aux += 3;
  }
  int sample_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001426_2613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st_1 = {0};
  struct Vector3D_R001426_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int quotient_79_1 = 0;
  int quotient_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_79_1 = ((quotient_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_79_2 = ((quotient_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_79_1) & 127;
    acc_2 = (acc_2 + quotient_79_2) & 127;
  }

  int bound_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_98_1)
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

  switch (bound_98_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_79_1 == quotient_79_2);
  assert(bound_98_1 == bound_98_2);
}

int fn_R001426_2613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int quotient_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_79 = ((quotient_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_79) & 127;
  }

  int bound_98 = (aux + st.buffer[1]) & 3;
  switch (bound_98)
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

void fn_R001426_2613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st_1 = {0};
  struct StreamBuffer_R001426_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int quotient_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_21_1)
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

  switch (quotient_21_2)
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

  int offset_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_13_1) & 63;
  aux_2 = (aux_2 + offset_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_60_1 = local_arr_1[aux_1 % 3];
  int tracker_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_60_2 * 2)) & 127;
  int vector_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_70_1 > 14)
  {
    acc_1 = ((acc_1 + (vector_70_1 * 2)) + 5) & 127;
    aux_1 ^= vector_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_70_2 > 14)
  {
    acc_2 = ((acc_2 + (vector_70_2 * 2)) + 5) & 127;
    aux_2 ^= vector_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_21_1 == quotient_21_2);
  assert(offset_13_1 == offset_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_60_1 == tracker_60_2);
  assert(vector_70_1 == vector_70_2);
}

int fn_R001426_2613_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int quotient_21 = (aux + st.buffer[1]) & 3;
  switch (quotient_21)
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

  int offset_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_13) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_60 = local_arr[aux % 3];
  acc = (acc + (tracker_60 * 2)) & 127;
  int vector_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_70 > 14)
  {
    acc = ((acc + (vector_70 * 2)) + 5) & 127;
    aux ^= vector_70 & 15;
  }
  else
  {
    acc = ((acc - vector_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001426_2613_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st_1 = {0};
  struct StreamBuffer_R001426_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int checksum_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_20_1)
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

  switch (checksum_20_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_52_1 > 36)
  {
    acc_1 = ((acc_1 + (threshold_52_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_52_2 > 36)
  {
    acc_2 = ((acc_2 + (threshold_52_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_54_1 = local_arr_1[aux_1 % 3];
  int threshold_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_20_1 == checksum_20_2);
  assert(threshold_52_1 == threshold_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_54_1 == threshold_54_2);
}

int fn_R001426_2613_15(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int checksum_20 = (aux + st.buffer[1]) & 3;
  switch (checksum_20)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_52 > 36)
  {
    acc = ((acc + (threshold_52 * 2)) + 5) & 127;
    aux ^= threshold_52 & 15;
  }
  else
  {
    acc = ((acc - threshold_52) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_54 = local_arr[aux % 3];
  acc = (acc + (threshold_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001426_2613_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st_1 = {0};
  struct Transaction_R001426_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int stride_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_95_1 > 12)
  {
    acc_1 = ((acc_1 + (stride_95_1 * 2)) + 5) & 127;
    aux_1 ^= stride_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_95_2 > 12)
  {
    acc_2 = ((acc_2 + (stride_95_2 * 2)) + 5) & 127;
    aux_2 ^= stride_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_95_1 = local_arr_1[aux_1 % 3];
  int quantum_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_95_2 * 2)) & 127;
  int factor_25_1 = 0;
  int factor_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_25_1 = ((factor_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_25_2 = ((factor_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_25_1) & 127;
    acc_2 = (acc_2 + factor_25_2) & 127;
  }

  int threshold_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_27_1)
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

  switch (threshold_27_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_95_1 == stride_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_95_1 == quantum_95_2);
  assert(factor_25_1 == factor_25_2);
  assert(threshold_27_1 == threshold_27_2);
}

int fn_R001426_2613_16(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int stride_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_95 > 12)
  {
    acc = ((acc + (stride_95 * 2)) + 5) & 127;
    aux ^= stride_95 & 15;
  }
  else
  {
    acc = ((acc - stride_95) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_95 = local_arr[aux % 3];
  acc = (acc + (quantum_95 * 2)) & 127;
  int factor_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_25 = ((factor_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_25) & 127;
  }

  int threshold_27 = (aux + st.buffer[1]) & 3;
  switch (threshold_27)
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

void fn_R001426_2613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st_1 = {0};
  struct StreamBuffer_R001426_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_33_1 = local_arr_1[aux_1 % 3];
  int checksum_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_33_2 * 2)) & 127;
  int accumulator_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_22_1) & 63;
  aux_2 = (aux_2 + accumulator_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_45_1)
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

  switch (stride_45_2)
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

  int tracker_81_1 = 0;
  int tracker_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_81_1 = ((tracker_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_81_2 = ((tracker_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_81_1) & 127;
    acc_2 = (acc_2 + tracker_81_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_33_1 == checksum_33_2);
  assert(accumulator_22_1 == accumulator_22_2);
  assert(stride_45_1 == stride_45_2);
  assert(tracker_81_1 == tracker_81_2);
}

int fn_R001426_2613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int checksum_33 = local_arr[aux % 3];
  acc = (acc + (checksum_33 * 2)) & 127;
  int accumulator_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_22) & 63;
  acc ^= aux;
  int stride_45 = (aux + st.buffer[1]) & 3;
  switch (stride_45)
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

  int tracker_81 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_81 = ((tracker_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_81) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001426_2613_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st_1 = {0};
  struct Vector3D_R001426_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int residue_47_1 = 0;
  int residue_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_47_1 = ((residue_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_47_2 = ((residue_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_47_1) & 127;
    acc_2 = (acc_2 + residue_47_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_92_1 = local_arr_1[aux_1 % 3];
  int segment_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_92_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_94_1)
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

  switch (bound_94_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_47_1 == residue_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_92_1 == segment_92_2);
  assert(bound_94_1 == bound_94_2);
}

int fn_R001426_2613_18(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int residue_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_47 = ((residue_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_47) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_92 = local_arr[aux % 3];
  acc = (acc + (segment_92 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_94 = (aux + st.buffer[1]) & 3;
  switch (bound_94)
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

void fn_R001426_2613_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st_1 = {0};
  struct Vector3D_R001426_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int weight_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_91_1) & 63;
  aux_2 = (aux_2 + weight_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_61_1)
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

  switch (residue_61_2)
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

  int coefficient_16_1 = 0;
  int coefficient_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_16_1 = ((coefficient_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_16_2 = ((coefficient_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_16_1) & 127;
    acc_2 = (acc_2 + coefficient_16_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_91_1 == weight_91_2);
  assert(residue_61_1 == residue_61_2);
  assert(coefficient_16_1 == coefficient_16_2);
}

int fn_R001426_2613_19(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001426_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int weight_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_91) & 63;
  acc ^= aux;
  int residue_61 = (aux + st.buffer[1]) & 3;
  switch (residue_61)
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

  int coefficient_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_16 = ((coefficient_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_16) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001426_2613_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st_1 = {0};
  struct StreamBuffer_R001426_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_35_1 = local_arr_1[aux_1 % 3];
  int mask_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_35_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_35_1 == mask_35_2);
}

int fn_R001426_2613_20(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001426_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int mask_35 = local_arr[aux % 3];
  acc = (acc + (mask_35 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001426_2613_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st_1 = {0};
  struct Transaction_R001426_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int delta_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_97_1)
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

  switch (delta_97_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_96_1 = local_arr_1[aux_1 % 3];
  int margin_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_97_1 == delta_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_96_1 == margin_96_2);
}

int fn_R001426_2613_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int delta_97 = (aux + st.buffer[1]) & 3;
  switch (delta_97)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_96 = local_arr[aux % 3];
  acc = (acc + (margin_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001426_2613_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st_1 = {0};
  struct Transaction_R001426_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_33_1 = local_arr_1[aux_1 % 3];
  int quotient_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_33_2 * 2)) & 127;
  int segment_79_1 = 0;
  int segment_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_79_1 = ((segment_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_79_2 = ((segment_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_79_1) & 127;
    acc_2 = (acc_2 + segment_79_2) & 127;
  }

  int parity_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_16_1) & 63;
  aux_2 = (aux_2 + parity_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_51_1)
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

  switch (pivot_51_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_33_1 == quotient_33_2);
  assert(segment_79_1 == segment_79_2);
  assert(parity_16_1 == parity_16_2);
  assert(pivot_51_1 == pivot_51_2);
}

int fn_R001426_2613_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001426_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int quotient_33 = local_arr[aux % 3];
  acc = (acc + (quotient_33 * 2)) & 127;
  int segment_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_79 = ((segment_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_79) & 127;
  }

  int parity_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_16) & 63;
  acc ^= aux;
  int pivot_51 = (aux + st.buffer[1]) & 3;
  switch (pivot_51)
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

void main()
{
  int sec_r001426_0_1;
  int sec_r001426_0_2;
  int sec_r001426_1_1;
  int sec_r001426_1_2;
  int sec_r001426_2_1;
  int sec_r001426_2_2;
  int sec_r001426_3_1;
  int sec_r001426_3_2;
  int sec_r001426_4_1;
  int sec_r001426_4_2;
  int sec_r001426_5_1;
  int sec_r001426_5_2;
  int sec_r001426_6_1;
  int sec_r001426_6_2;
  int sec_r001426_7_1;
  int sec_r001426_7_2;
  int sec_r001426_8_1;
  int sec_r001426_8_2;
  int sec_r001426_9_1;
  int sec_r001426_9_2;
  int sec_r001426_10_1;
  int sec_r001426_10_2;
  int sec_r001426_11_1;
  int sec_r001426_11_2;
  int sec_r001426_12_1;
  int sec_r001426_12_2;
  int sec_r001426_13_1;
  int sec_r001426_13_2;
  int sec_r001426_14_1;
  int sec_r001426_14_2;
  int sec_r001426_15_1;
  int sec_r001426_15_2;
  int sec_r001426_16_1;
  int sec_r001426_16_2;
  int pub_r001426_0_1;
  int pub_r001426_0_2;
  int pub_r001426_1_1;
  int pub_r001426_1_2;
  int pub_r001426_2_1;
  int pub_r001426_2_2;
  int pub_r001426_3_1;
  int pub_r001426_3_2;
  int pub_r001426_4_1;
  int pub_r001426_4_2;
  int pub_r001426_5_1;
  int pub_r001426_5_2;
  int pub_r001426_6_1;
  int pub_r001426_6_2;
  int pub_r001426_7_1;
  int pub_r001426_7_2;
  int pub_r001426_8_1;
  int pub_r001426_8_2;
  int pub_r001426_9_1;
  int pub_r001426_9_2;
  int pub_r001426_10_1;
  int pub_r001426_10_2;
  int pub_r001426_11_1;
  int pub_r001426_11_2;
  int pub_r001426_12_1;
  int pub_r001426_12_2;
  int pub_r001426_13_1;
  int pub_r001426_13_2;
  int pub_r001426_14_1;
  int pub_r001426_14_2;
  int pub_r001426_15_1;
  int pub_r001426_15_2;
  int pub_r001426_16_1;
  int pub_r001426_16_2;
  int pub_r001426_17_1;
  int pub_r001426_17_2;
  int pub_r001426_18_1;
  int pub_r001426_18_2;
  int pub_r001426_19_1;
  int pub_r001426_19_2;
  int pub_r001426_20_1;
  int pub_r001426_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001426_0_1 >= (-100)) && (pub_r001426_0_1 <= 100));
  __CPROVER_assume((pub_r001426_0_2 >= (-100)) && (pub_r001426_0_2 <= 100));
  __CPROVER_assume((pub_r001426_1_1 >= (-100)) && (pub_r001426_1_1 <= 100));
  __CPROVER_assume((pub_r001426_1_2 >= (-100)) && (pub_r001426_1_2 <= 100));
  __CPROVER_assume((pub_r001426_2_1 >= (-100)) && (pub_r001426_2_1 <= 100));
  __CPROVER_assume((pub_r001426_2_2 >= (-100)) && (pub_r001426_2_2 <= 100));
  __CPROVER_assume((pub_r001426_3_1 >= (-100)) && (pub_r001426_3_1 <= 100));
  __CPROVER_assume((pub_r001426_3_2 >= (-100)) && (pub_r001426_3_2 <= 100));
  __CPROVER_assume((pub_r001426_4_1 >= (-100)) && (pub_r001426_4_1 <= 100));
  __CPROVER_assume((pub_r001426_4_2 >= (-100)) && (pub_r001426_4_2 <= 100));
  __CPROVER_assume((pub_r001426_5_1 >= (-100)) && (pub_r001426_5_1 <= 100));
  __CPROVER_assume((pub_r001426_5_2 >= (-100)) && (pub_r001426_5_2 <= 100));
  __CPROVER_assume((pub_r001426_6_1 >= (-100)) && (pub_r001426_6_1 <= 100));
  __CPROVER_assume((pub_r001426_6_2 >= (-100)) && (pub_r001426_6_2 <= 100));
  __CPROVER_assume((pub_r001426_7_1 >= (-100)) && (pub_r001426_7_1 <= 100));
  __CPROVER_assume((pub_r001426_7_2 >= (-100)) && (pub_r001426_7_2 <= 100));
  __CPROVER_assume((pub_r001426_8_1 >= (-100)) && (pub_r001426_8_1 <= 100));
  __CPROVER_assume((pub_r001426_8_2 >= (-100)) && (pub_r001426_8_2 <= 100));
  __CPROVER_assume((pub_r001426_9_1 >= (-100)) && (pub_r001426_9_1 <= 100));
  __CPROVER_assume((pub_r001426_9_2 >= (-100)) && (pub_r001426_9_2 <= 100));
  __CPROVER_assume((pub_r001426_10_1 >= (-100)) && (pub_r001426_10_1 <= 100));
  __CPROVER_assume((pub_r001426_10_2 >= (-100)) && (pub_r001426_10_2 <= 100));
  __CPROVER_assume((pub_r001426_11_1 >= (-100)) && (pub_r001426_11_1 <= 100));
  __CPROVER_assume((pub_r001426_11_2 >= (-100)) && (pub_r001426_11_2 <= 100));
  __CPROVER_assume((pub_r001426_12_1 >= (-100)) && (pub_r001426_12_1 <= 100));
  __CPROVER_assume((pub_r001426_12_2 >= (-100)) && (pub_r001426_12_2 <= 100));
  __CPROVER_assume((pub_r001426_13_1 >= (-100)) && (pub_r001426_13_1 <= 100));
  __CPROVER_assume((pub_r001426_13_2 >= (-100)) && (pub_r001426_13_2 <= 100));
  __CPROVER_assume((pub_r001426_14_1 >= (-100)) && (pub_r001426_14_1 <= 100));
  __CPROVER_assume((pub_r001426_14_2 >= (-100)) && (pub_r001426_14_2 <= 100));
  __CPROVER_assume((pub_r001426_15_1 >= (-100)) && (pub_r001426_15_1 <= 100));
  __CPROVER_assume((pub_r001426_15_2 >= (-100)) && (pub_r001426_15_2 <= 100));
  __CPROVER_assume((pub_r001426_16_1 >= (-100)) && (pub_r001426_16_1 <= 100));
  __CPROVER_assume((pub_r001426_16_2 >= (-100)) && (pub_r001426_16_2 <= 100));
  __CPROVER_assume((pub_r001426_17_1 >= (-100)) && (pub_r001426_17_1 <= 100));
  __CPROVER_assume((pub_r001426_17_2 >= (-100)) && (pub_r001426_17_2 <= 100));
  __CPROVER_assume((pub_r001426_18_1 >= (-100)) && (pub_r001426_18_1 <= 100));
  __CPROVER_assume((pub_r001426_18_2 >= (-100)) && (pub_r001426_18_2 <= 100));
  __CPROVER_assume((pub_r001426_19_1 >= (-100)) && (pub_r001426_19_1 <= 100));
  __CPROVER_assume((pub_r001426_19_2 >= (-100)) && (pub_r001426_19_2 <= 100));
  __CPROVER_assume((pub_r001426_20_1 >= (-100)) && (pub_r001426_20_1 <= 100));
  __CPROVER_assume((pub_r001426_20_2 >= (-100)) && (pub_r001426_20_2 <= 100));
  __CPROVER_assume((sec_r001426_0_1 >= 0) && (sec_r001426_0_1 <= 255));
  __CPROVER_assume((sec_r001426_0_2 >= 0) && (sec_r001426_0_2 <= 255));
  __CPROVER_assume((sec_r001426_1_1 >= 0) && (sec_r001426_1_1 <= 255));
  __CPROVER_assume((sec_r001426_1_2 >= 0) && (sec_r001426_1_2 <= 255));
  __CPROVER_assume((sec_r001426_2_1 >= 0) && (sec_r001426_2_1 <= 255));
  __CPROVER_assume((sec_r001426_2_2 >= 0) && (sec_r001426_2_2 <= 255));
  __CPROVER_assume((sec_r001426_3_1 >= 0) && (sec_r001426_3_1 <= 255));
  __CPROVER_assume((sec_r001426_3_2 >= 0) && (sec_r001426_3_2 <= 255));
  __CPROVER_assume((sec_r001426_4_1 >= 0) && (sec_r001426_4_1 <= 255));
  __CPROVER_assume((sec_r001426_4_2 >= 0) && (sec_r001426_4_2 <= 255));
  __CPROVER_assume((sec_r001426_5_1 >= 0) && (sec_r001426_5_1 <= 255));
  __CPROVER_assume((sec_r001426_5_2 >= 0) && (sec_r001426_5_2 <= 255));
  __CPROVER_assume((sec_r001426_6_1 >= 0) && (sec_r001426_6_1 <= 255));
  __CPROVER_assume((sec_r001426_6_2 >= 0) && (sec_r001426_6_2 <= 255));
  __CPROVER_assume((sec_r001426_7_1 >= 0) && (sec_r001426_7_1 <= 255));
  __CPROVER_assume((sec_r001426_7_2 >= 0) && (sec_r001426_7_2 <= 255));
  __CPROVER_assume((sec_r001426_8_1 >= 0) && (sec_r001426_8_1 <= 255));
  __CPROVER_assume((sec_r001426_8_2 >= 0) && (sec_r001426_8_2 <= 255));
  __CPROVER_assume((sec_r001426_9_1 >= 0) && (sec_r001426_9_1 <= 255));
  __CPROVER_assume((sec_r001426_9_2 >= 0) && (sec_r001426_9_2 <= 255));
  __CPROVER_assume((sec_r001426_10_1 >= 0) && (sec_r001426_10_1 <= 255));
  __CPROVER_assume((sec_r001426_10_2 >= 0) && (sec_r001426_10_2 <= 255));
  __CPROVER_assume((sec_r001426_11_1 >= 0) && (sec_r001426_11_1 <= 255));
  __CPROVER_assume((sec_r001426_11_2 >= 0) && (sec_r001426_11_2 <= 255));
  __CPROVER_assume((sec_r001426_12_1 >= 0) && (sec_r001426_12_1 <= 255));
  __CPROVER_assume((sec_r001426_12_2 >= 0) && (sec_r001426_12_2 <= 255));
  __CPROVER_assume((sec_r001426_13_1 >= 0) && (sec_r001426_13_1 <= 255));
  __CPROVER_assume((sec_r001426_13_2 >= 0) && (sec_r001426_13_2 <= 255));
  __CPROVER_assume((sec_r001426_14_1 >= 0) && (sec_r001426_14_1 <= 255));
  __CPROVER_assume((sec_r001426_14_2 >= 0) && (sec_r001426_14_2 <= 255));
  __CPROVER_assume((sec_r001426_15_1 >= 0) && (sec_r001426_15_1 <= 255));
  __CPROVER_assume((sec_r001426_15_2 >= 0) && (sec_r001426_15_2 <= 255));
  __CPROVER_assume((sec_r001426_16_1 >= 0) && (sec_r001426_16_1 <= 255));
  __CPROVER_assume((sec_r001426_16_2 >= 0) && (sec_r001426_16_2 <= 255));
  struct Transaction_R001426_2613_0 st_var_0_1 = {0};
  struct Transaction_R001426_2613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001426_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001426_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001426_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001426_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001426_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001426_0_2 + 7) & 15;
  struct Vector3D_R001426_2613_1 st_var_1_1 = {0};
  struct Vector3D_R001426_2613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001426_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001426_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001426_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001426_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001426_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001426_0_2 + 9) & 15;
  struct StreamBuffer_R001426_2613_2 st_var_2_1 = {0};
  struct StreamBuffer_R001426_2613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001426_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001426_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001426_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001426_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001426_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001426_0_2 + 11) & 15;
  union TelemetryField_R001426_2613_0 u_var_1;
  union TelemetryField_R001426_2613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001426_2613_0(sec_r001426_0_1, sec_r001426_1_1);
  int helper_flow_0_2 = fn_R001426_2613_0(sec_r001426_0_2, sec_r001426_1_2);
  fn_R001426_2613_0_2(sec_r001426_0_1, sec_r001426_1_1, sec_r001426_0_2, sec_r001426_1_2);
  int helper_flow_1_1 = fn_R001426_2613_1(sec_r001426_1_1, sec_r001426_2_1, pub_r001426_3_1, pub_r001426_4_1, pub_r001426_5_1);
  int helper_flow_1_2 = fn_R001426_2613_1(sec_r001426_1_2, sec_r001426_2_2, pub_r001426_3_2, pub_r001426_4_2, pub_r001426_5_2);
  fn_R001426_2613_1_2(sec_r001426_1_1, sec_r001426_2_1, pub_r001426_3_1, pub_r001426_4_1, pub_r001426_5_1, sec_r001426_1_2, sec_r001426_2_2, pub_r001426_3_2, pub_r001426_4_2, pub_r001426_5_2);
  int helper_flow_2_1 = fn_R001426_2613_2(sec_r001426_2_1, sec_r001426_3_1, pub_r001426_4_1, pub_r001426_5_1);
  int helper_flow_2_2 = fn_R001426_2613_2(sec_r001426_2_2, sec_r001426_3_2, pub_r001426_4_2, pub_r001426_5_2);
  fn_R001426_2613_2_2(sec_r001426_2_1, sec_r001426_3_1, pub_r001426_4_1, pub_r001426_5_1, sec_r001426_2_2, sec_r001426_3_2, pub_r001426_4_2, pub_r001426_5_2);
  int helper_flow_3_1 = fn_R001426_2613_3(sec_r001426_3_1, pub_r001426_4_1);
  int helper_flow_3_2 = fn_R001426_2613_3(sec_r001426_3_2, pub_r001426_4_2);
  fn_R001426_2613_3_2(sec_r001426_3_1, pub_r001426_4_1, sec_r001426_3_2, pub_r001426_4_2);
  int helper_flow_4_1 = fn_R001426_2613_4(sec_r001426_4_1, sec_r001426_5_1, pub_r001426_6_1);
  int helper_flow_4_2 = fn_R001426_2613_4(sec_r001426_4_2, sec_r001426_5_2, pub_r001426_6_2);
  fn_R001426_2613_4_2(sec_r001426_4_1, sec_r001426_5_1, pub_r001426_6_1, sec_r001426_4_2, sec_r001426_5_2, pub_r001426_6_2);
  int helper_flow_5_1 = fn_R001426_2613_5(sec_r001426_5_1, sec_r001426_6_1, pub_r001426_7_1, pub_r001426_8_1, pub_r001426_9_1);
  int helper_flow_5_2 = fn_R001426_2613_5(sec_r001426_5_2, sec_r001426_6_2, pub_r001426_7_2, pub_r001426_8_2, pub_r001426_9_2);
  fn_R001426_2613_5_2(sec_r001426_5_1, sec_r001426_6_1, pub_r001426_7_1, pub_r001426_8_1, pub_r001426_9_1, sec_r001426_5_2, sec_r001426_6_2, pub_r001426_7_2, pub_r001426_8_2, pub_r001426_9_2);
  int helper_flow_6_1 = fn_R001426_2613_6(sec_r001426_6_1, pub_r001426_7_1, pub_r001426_8_1);
  int helper_flow_6_2 = fn_R001426_2613_6(sec_r001426_6_2, pub_r001426_7_2, pub_r001426_8_2);
  fn_R001426_2613_6_2(sec_r001426_6_1, pub_r001426_7_1, pub_r001426_8_1, sec_r001426_6_2, pub_r001426_7_2, pub_r001426_8_2);
  int helper_flow_7_1 = fn_R001426_2613_7(sec_r001426_7_1, sec_r001426_8_1, pub_r001426_9_1);
  int helper_flow_7_2 = fn_R001426_2613_7(sec_r001426_7_2, sec_r001426_8_2, pub_r001426_9_2);
  fn_R001426_2613_7_2(sec_r001426_7_1, sec_r001426_8_1, pub_r001426_9_1, sec_r001426_7_2, sec_r001426_8_2, pub_r001426_9_2);
  int helper_flow_8_1 = fn_R001426_2613_8(sec_r001426_8_1, pub_r001426_9_1);
  int helper_flow_8_2 = fn_R001426_2613_8(sec_r001426_8_2, pub_r001426_9_2);
  fn_R001426_2613_8_2(sec_r001426_8_1, pub_r001426_9_1, sec_r001426_8_2, pub_r001426_9_2);
  int stage_v_0_1 = ((pub_r001426_2_1 * 2) + 45) & 63;
  int stage_v_0_2 = ((pub_r001426_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((sec_r001426_1_1 + (pub_r001426_10_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001426_1_2 + (pub_r001426_10_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((sec_r001426_11_1 + (pub_r001426_8_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001426_11_2 + (pub_r001426_8_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((pub_r001426_4_1 * 2) + 42) & 63;
  int stage_v_3_2 = ((pub_r001426_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001426_14_1 * 2) + 11) & 63;
  int stage_v_4_2 = ((pub_r001426_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001426_12_1 * 2) + 32) & 63;
  int stage_v_5_2 = ((pub_r001426_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((sec_r001426_3_1 + (pub_r001426_12_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001426_3_2 + (pub_r001426_12_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((helper_flow_3_1 + (pub_r001426_10_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((helper_flow_3_2 + (pub_r001426_10_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((sec_r001426_3_1 + (pub_r001426_0_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001426_3_2 + (pub_r001426_0_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((sec_r001426_8_1 + (pub_r001426_9_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((sec_r001426_8_2 + (pub_r001426_9_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((pub_r001426_12_1 * 2) + 35) & 63;
  int stage_v_10_2 = ((pub_r001426_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((sec_r001426_6_1 + (pub_r001426_9_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((sec_r001426_6_2 + (pub_r001426_9_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((pub_r001426_4_1 * 2) + 8) & 63;
  int stage_v_12_2 = ((pub_r001426_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001426_13_1 * 2) + 28) & 63;
  int stage_v_13_2 = ((pub_r001426_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((sec_r001426_13_1 + (pub_r001426_20_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001426_13_2 + (pub_r001426_20_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((sec_r001426_8_1 + (pub_r001426_17_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((sec_r001426_8_2 + (pub_r001426_17_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001426_17_1 * 2) + 46) & 63;
  int stage_v_16_2 = ((pub_r001426_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((sec_r001426_8_1 + (pub_r001426_20_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001426_8_2 + (pub_r001426_20_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((stage_v_14_1 + (pub_r001426_6_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((stage_v_14_2 + (pub_r001426_6_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((stage_v_9_1 + (pub_r001426_2_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((stage_v_9_2 + (pub_r001426_2_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((stage_v_1_1 + (pub_r001426_14_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((stage_v_1_2 + (pub_r001426_14_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((stage_v_17_1 + (pub_r001426_0_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_17_2 + (pub_r001426_0_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((pub_r001426_6_1 * 2) + 33) & 63;
  int stage_v_22_2 = ((pub_r001426_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001426_11_1 * 2) + 27) & 63;
  int stage_v_23_2 = ((pub_r001426_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((helper_flow_3_1 + (pub_r001426_3_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((helper_flow_3_2 + (pub_r001426_3_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((stage_v_7_1 + (pub_r001426_7_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((stage_v_7_2 + (pub_r001426_7_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((helper_flow_4_1 + (pub_r001426_12_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((helper_flow_4_2 + (pub_r001426_12_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((stage_v_7_1 + (pub_r001426_1_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((stage_v_7_2 + (pub_r001426_1_2 * 2)) + 86) & 127;
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
  int stage_v_28_1 = ((stage_v_6_1 + (pub_r001426_11_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_6_2 + (pub_r001426_11_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((stage_v_1_1 + (pub_r001426_14_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((stage_v_1_2 + (pub_r001426_14_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((pub_r001426_9_1 * 2) + 48) & 63;
  int stage_v_30_2 = ((pub_r001426_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((sec_r001426_5_1 + (pub_r001426_7_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((sec_r001426_5_2 + (pub_r001426_7_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((stage_v_31_1 + (pub_r001426_18_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_31_2 + (pub_r001426_18_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((helper_flow_4_1 + (pub_r001426_13_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((helper_flow_4_2 + (pub_r001426_13_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((pub_r001426_12_1 * 2) + 17) & 63;
  int stage_v_34_2 = ((pub_r001426_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001426_17_1 * 2) + 33) & 63;
  int stage_v_35_2 = ((pub_r001426_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001426_1_1 * 2) + 49) & 63;
  int stage_v_36_2 = ((pub_r001426_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((stage_v_6_1 + (pub_r001426_16_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((stage_v_6_2 + (pub_r001426_16_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((helper_flow_8_1 + (pub_r001426_0_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((helper_flow_8_2 + (pub_r001426_0_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001426_8_1 * 2) + 11) & 63;
  int stage_v_39_2 = ((pub_r001426_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((stage_v_21_1 + (pub_r001426_15_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_21_2 + (pub_r001426_15_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((stage_v_24_1 + (pub_r001426_18_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_24_2 + (pub_r001426_18_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((stage_v_19_1 + (pub_r001426_5_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((stage_v_19_2 + (pub_r001426_5_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((helper_flow_6_1 + (pub_r001426_7_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((helper_flow_6_2 + (pub_r001426_7_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((sec_r001426_10_1 + (pub_r001426_14_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((sec_r001426_10_2 + (pub_r001426_14_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((helper_flow_5_1 + (pub_r001426_12_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((helper_flow_5_2 + (pub_r001426_12_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((stage_v_11_1 + (pub_r001426_3_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_11_2 + (pub_r001426_3_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((sec_r001426_7_1 + (pub_r001426_6_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((sec_r001426_7_2 + (pub_r001426_6_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((helper_flow_3_1 + (pub_r001426_4_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((helper_flow_3_2 + (pub_r001426_4_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_28_1 + (pub_r001426_2_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_28_2 + (pub_r001426_2_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((pub_r001426_14_1 * 2) + 33) & 63;
  int stage_v_50_2 = ((pub_r001426_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((helper_flow_0_1 + (pub_r001426_13_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((helper_flow_0_2 + (pub_r001426_13_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((sec_r001426_11_1 + (pub_r001426_16_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((sec_r001426_11_2 + (pub_r001426_16_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((sec_r001426_5_1 + (pub_r001426_8_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((sec_r001426_5_2 + (pub_r001426_8_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((sec_r001426_0_1 + (pub_r001426_7_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((sec_r001426_0_2 + (pub_r001426_7_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((stage_v_47_1 + (pub_r001426_4_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_47_2 + (pub_r001426_4_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((helper_flow_4_1 + (pub_r001426_19_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((helper_flow_4_2 + (pub_r001426_19_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((stage_v_18_1 + (pub_r001426_14_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_18_2 + (pub_r001426_14_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((pub_r001426_8_1 * 2) + 20) & 63;
  int stage_v_58_2 = ((pub_r001426_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((stage_v_37_1 + (pub_r001426_4_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_37_2 + (pub_r001426_4_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((sec_r001426_0_1 + (pub_r001426_2_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((sec_r001426_0_2 + (pub_r001426_2_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_11_1 + (pub_r001426_20_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_11_2 + (pub_r001426_20_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((stage_v_37_1 + (pub_r001426_12_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_37_2 + (pub_r001426_12_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((pub_r001426_17_1 * 2) + 34) & 63;
  int stage_v_63_2 = ((pub_r001426_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((stage_v_8_1 + (pub_r001426_20_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_8_2 + (pub_r001426_20_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((pub_r001426_20_1 * 2) + 15) & 63;
  int stage_v_65_2 = ((pub_r001426_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001426_1_1 * 2) + 30) & 63;
  int stage_v_66_2 = ((pub_r001426_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((helper_flow_3_1 + (pub_r001426_14_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((helper_flow_3_2 + (pub_r001426_14_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001426_11_1 * 2) + 10) & 63;
  int stage_v_68_2 = ((pub_r001426_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((stage_v_42_1 + (pub_r001426_5_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((stage_v_42_2 + (pub_r001426_5_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((pub_r001426_10_1 * 2) + 37) & 63;
  int stage_v_70_2 = ((pub_r001426_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((stage_v_37_1 + (pub_r001426_8_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_37_2 + (pub_r001426_8_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((pub_r001426_13_1 * 2) + 35) & 63;
  int stage_v_72_2 = ((pub_r001426_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001426_8_1 * 2) + 42) & 63;
  int stage_v_73_2 = ((pub_r001426_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((stage_v_29_1 + (pub_r001426_6_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_29_2 + (pub_r001426_6_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((sec_r001426_5_1 + (pub_r001426_13_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((sec_r001426_5_2 + (pub_r001426_13_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((stage_v_44_1 + (pub_r001426_2_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_44_2 + (pub_r001426_2_2 * 2)) + 233) & 127;
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
  int stage_v_77_1 = ((helper_flow_7_1 + (pub_r001426_8_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((helper_flow_7_2 + (pub_r001426_8_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((pub_r001426_6_1 * 2) + 15) & 63;
  int stage_v_78_2 = ((pub_r001426_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((helper_flow_8_1 + (pub_r001426_5_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((helper_flow_8_2 + (pub_r001426_5_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((stage_v_24_1 + (pub_r001426_13_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_24_2 + (pub_r001426_13_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((stage_v_33_1 + (pub_r001426_6_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_33_2 + (pub_r001426_6_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001426_9_1 * 2) + 8) & 63;
  int stage_v_82_2 = ((pub_r001426_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001426_19_1 * 2) + 46) & 63;
  int stage_v_83_2 = ((pub_r001426_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_19_1 + (pub_r001426_7_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_19_2 + (pub_r001426_7_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((stage_v_74_1 + (pub_r001426_9_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_74_2 + (pub_r001426_9_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_19_1 + (pub_r001426_12_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_19_2 + (pub_r001426_12_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_32_1 + (pub_r001426_20_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_32_2 + (pub_r001426_20_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_76_1 + (pub_r001426_15_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_76_2 + (pub_r001426_15_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((helper_flow_0_1 + (pub_r001426_2_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((helper_flow_0_2 + (pub_r001426_2_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((sec_r001426_16_1 + (pub_r001426_20_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((sec_r001426_16_2 + (pub_r001426_20_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((pub_r001426_4_1 * 2) + 46) & 63;
  int stage_v_91_2 = ((pub_r001426_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001426_17_1 * 2) + 38) & 63;
  int stage_v_92_2 = ((pub_r001426_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001426_3_1 * 2) + 27) & 63;
  int stage_v_93_2 = ((pub_r001426_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((stage_v_51_1 + (pub_r001426_0_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_51_2 + (pub_r001426_0_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_79_1 + (pub_r001426_7_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_79_2 + (pub_r001426_7_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((sec_r001426_2_1 + (pub_r001426_16_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((sec_r001426_2_2 + (pub_r001426_16_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_76_1 + (pub_r001426_7_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_76_2 + (pub_r001426_7_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((pub_r001426_12_1 * 2) + 30) & 63;
  int stage_v_98_2 = ((pub_r001426_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_7_1 + (pub_r001426_1_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_7_2 + (pub_r001426_1_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_18_1 + (pub_r001426_1_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_18_2 + (pub_r001426_1_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((pub_r001426_9_1 * 2) + 25) & 63;
  int stage_v_101_2 = ((pub_r001426_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_29_1 + (pub_r001426_9_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_29_2 + (pub_r001426_9_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_61_1 + (pub_r001426_0_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_61_2 + (pub_r001426_0_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001426_17_1 * 2) + 50) & 63;
  int stage_v_104_2 = ((pub_r001426_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((stage_v_71_1 + (pub_r001426_16_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_71_2 + (pub_r001426_16_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_52_1 + (pub_r001426_5_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_52_2 + (pub_r001426_5_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_40_1 + (pub_r001426_15_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_40_2 + (pub_r001426_15_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((stage_v_77_1 + (pub_r001426_8_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_77_2 + (pub_r001426_8_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((pub_r001426_12_1 * 2) + 36) & 63;
  int stage_v_109_2 = ((pub_r001426_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((stage_v_18_1 + (pub_r001426_11_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_18_2 + (pub_r001426_11_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_106_1 + (pub_r001426_18_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_106_2 + (pub_r001426_18_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((pub_r001426_15_1 * 2) + 6) & 63;
  int stage_v_112_2 = ((pub_r001426_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((stage_v_69_1 + (pub_r001426_4_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_69_2 + (pub_r001426_4_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((stage_v_17_1 + (pub_r001426_2_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_17_2 + (pub_r001426_2_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((pub_r001426_2_1 * 2) + 22) & 63;
  int stage_v_115_2 = ((pub_r001426_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((stage_v_52_1 + (pub_r001426_15_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_52_2 + (pub_r001426_15_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001426_11_1 * 2) + 38) & 63;
  int stage_v_117_2 = ((pub_r001426_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001426_3_1 * 2) + 6) & 63;
  int stage_v_118_2 = ((pub_r001426_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001426_12_1 * 2) + 48) & 63;
  int stage_v_119_2 = ((pub_r001426_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((stage_v_85_1 + (pub_r001426_12_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_85_2 + (pub_r001426_12_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_97_1 + (pub_r001426_14_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_97_2 + (pub_r001426_14_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((sec_r001426_11_1 + (pub_r001426_11_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((sec_r001426_11_2 + (pub_r001426_11_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((pub_r001426_0_1 * 2) + 29) & 63;
  int stage_v_123_2 = ((pub_r001426_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001426_1_1 * 2) + 48) & 63;
  int stage_v_124_2 = ((pub_r001426_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001426_7_1 * 2) + 7) & 63;
  int stage_v_125_2 = ((pub_r001426_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_121_1 + (pub_r001426_0_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_121_2 + (pub_r001426_0_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((sec_r001426_8_1 + (pub_r001426_13_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((sec_r001426_8_2 + (pub_r001426_13_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((stage_v_48_1 + (pub_r001426_5_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_48_2 + (pub_r001426_5_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((stage_v_45_1 + (pub_r001426_7_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_45_2 + (pub_r001426_7_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((pub_r001426_11_1 * 2) + 32) & 63;
  int stage_v_130_2 = ((pub_r001426_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((helper_flow_6_1 + (pub_r001426_6_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((helper_flow_6_2 + (pub_r001426_6_2 * 2)) + 398) & 127;
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
  int stage_v_132_1 = ((stage_v_81_1 + (pub_r001426_15_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_81_2 + (pub_r001426_15_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_80_1 + (pub_r001426_9_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_80_2 + (pub_r001426_9_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001426_2_1 * 2) + 25) & 63;
  int stage_v_134_2 = ((pub_r001426_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001426_20_1 * 2) + 28) & 63;
  int stage_v_135_2 = ((pub_r001426_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((helper_flow_7_1 + (pub_r001426_10_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((helper_flow_7_2 + (pub_r001426_10_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001426_12_1 * 2) + 39) & 63;
  int stage_v_137_2 = ((pub_r001426_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((stage_v_43_1 + (pub_r001426_4_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_43_2 + (pub_r001426_4_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((stage_v_126_1 + (pub_r001426_0_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((stage_v_126_2 + (pub_r001426_0_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_71_1 + (pub_r001426_12_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_71_2 + (pub_r001426_12_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001426_0_1 * 2) + 5) & 63;
  int stage_v_141_2 = ((pub_r001426_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001426_8_1 * 2) + 21) & 63;
  int stage_v_142_2 = ((pub_r001426_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_136_1 + (pub_r001426_9_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_136_2 + (pub_r001426_9_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_64_1 + (pub_r001426_1_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_64_2 + (pub_r001426_1_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_15_1 + (pub_r001426_9_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_15_2 + (pub_r001426_9_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_113_1 + (pub_r001426_15_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_113_2 + (pub_r001426_15_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((pub_r001426_0_1 * 2) + 45) & 63;
  int stage_v_147_2 = ((pub_r001426_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001426_3_1 * 2) + 10) & 63;
  int stage_v_148_2 = ((pub_r001426_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((stage_v_96_1 + (pub_r001426_15_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_96_2 + (pub_r001426_15_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_9_1 + (pub_r001426_0_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_9_2 + (pub_r001426_0_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_64_1 + (pub_r001426_12_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_64_2 + (pub_r001426_12_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_56_1 + (pub_r001426_19_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_56_2 + (pub_r001426_19_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((sec_r001426_5_1 + (pub_r001426_9_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((sec_r001426_5_2 + (pub_r001426_9_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((pub_r001426_10_1 * 2) + 14) & 63;
  int stage_v_154_2 = ((pub_r001426_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_26_1 + (pub_r001426_12_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_26_2 + (pub_r001426_12_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((sec_r001426_11_1 + (pub_r001426_16_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((sec_r001426_11_2 + (pub_r001426_16_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((helper_flow_2_1 + (pub_r001426_1_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((helper_flow_2_2 + (pub_r001426_1_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_139_1 + (pub_r001426_14_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_139_2 + (pub_r001426_14_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((pub_r001426_4_1 * 2) + 27) & 63;
  int stage_v_159_2 = ((pub_r001426_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001426_14_1 * 2) + 49) & 63;
  int stage_v_160_2 = ((pub_r001426_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_85_1 + (pub_r001426_17_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_85_2 + (pub_r001426_17_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((stage_v_81_1 + (pub_r001426_1_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_81_2 + (pub_r001426_1_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((pub_r001426_13_1 * 2) + 10) & 63;
  int stage_v_163_2 = ((pub_r001426_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_54_1 + (pub_r001426_4_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_54_2 + (pub_r001426_4_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_60_1 + (pub_r001426_0_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_60_2 + (pub_r001426_0_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_143_1 + (pub_r001426_0_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_143_2 + (pub_r001426_0_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((sec_r001426_8_1 + (pub_r001426_6_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((sec_r001426_8_2 + (pub_r001426_6_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_108_1 + (pub_r001426_15_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_108_2 + (pub_r001426_15_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((sec_r001426_13_1 + (pub_r001426_7_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((sec_r001426_13_2 + (pub_r001426_7_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((stage_v_116_1 + (pub_r001426_20_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_116_2 + (pub_r001426_20_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((stage_v_51_1 + (pub_r001426_18_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_51_2 + (pub_r001426_18_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((pub_r001426_6_1 * 2) + 31) & 63;
  int stage_v_172_2 = ((pub_r001426_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((stage_v_54_1 + (pub_r001426_17_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_54_2 + (pub_r001426_17_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_85_1 + (pub_r001426_3_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_85_2 + (pub_r001426_3_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_1_1 + (pub_r001426_8_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_1_2 + (pub_r001426_8_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_156_1 + (pub_r001426_16_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_156_2 + (pub_r001426_16_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((pub_r001426_10_1 * 2) + 45) & 63;
  int stage_v_177_2 = ((pub_r001426_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_88_1 + (pub_r001426_2_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_88_2 + (pub_r001426_2_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((pub_r001426_7_1 * 2) + 16) & 63;
  int stage_v_179_2 = ((pub_r001426_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((stage_v_42_1 + (pub_r001426_3_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_42_2 + (pub_r001426_3_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((pub_r001426_18_1 * 2) + 45) & 63;
  int stage_v_181_2 = ((pub_r001426_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001426_2_1 * 2) + 20) & 63;
  int stage_v_182_2 = ((pub_r001426_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001426_3_1 * 2) + 10) & 63;
  int stage_v_183_2 = ((pub_r001426_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((stage_v_28_1 + (pub_r001426_17_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_28_2 + (pub_r001426_17_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_173_1 + (pub_r001426_1_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_173_2 + (pub_r001426_1_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((pub_r001426_16_1 * 2) + 46) & 63;
  int stage_v_186_2 = ((pub_r001426_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_26_1 + (pub_r001426_10_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_26_2 + (pub_r001426_10_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((helper_flow_2_1 + (pub_r001426_8_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((helper_flow_2_2 + (pub_r001426_8_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((stage_v_140_1 + (pub_r001426_0_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_140_2 + (pub_r001426_0_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_44_1 + (pub_r001426_13_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_44_2 + (pub_r001426_13_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((stage_v_173_1 + (pub_r001426_16_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_173_2 + (pub_r001426_16_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((pub_r001426_2_1 * 2) + 15) & 63;
  int stage_v_192_2 = ((pub_r001426_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_45_1 + (pub_r001426_2_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_45_2 + (pub_r001426_2_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((pub_r001426_9_1 * 2) + 19) & 63;
  int stage_v_194_2 = ((pub_r001426_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((stage_v_121_1 + (pub_r001426_14_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_121_2 + (pub_r001426_14_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((pub_r001426_16_1 * 2) + 37) & 63;
  int stage_v_196_2 = ((pub_r001426_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_90_1 + (pub_r001426_3_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_90_2 + (pub_r001426_3_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((pub_r001426_6_1 * 2) + 32) & 63;
  int stage_v_198_2 = ((pub_r001426_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((stage_v_29_1 + (pub_r001426_0_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_29_2 + (pub_r001426_0_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_71_1 + (pub_r001426_3_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_71_2 + (pub_r001426_3_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((pub_r001426_8_1 * 2) + 11) & 63;
  int stage_v_201_2 = ((pub_r001426_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001426_17_1 * 2) + 26) & 63;
  int stage_v_202_2 = ((pub_r001426_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001426_16_1 * 2) + 11) & 63;
  int stage_v_203_2 = ((pub_r001426_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001426_14_1 * 2) + 33) & 63;
  int stage_v_204_2 = ((pub_r001426_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((sec_r001426_1_1 + (pub_r001426_4_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((sec_r001426_1_2 + (pub_r001426_4_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001426_9_1 * 2) + 11) & 63;
  int stage_v_206_2 = ((pub_r001426_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001426_6_1 * 2) + 22) & 63;
  int stage_v_207_2 = ((pub_r001426_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_161_1 + (pub_r001426_5_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_161_2 + (pub_r001426_5_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_140_1 + (pub_r001426_19_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_140_2 + (pub_r001426_19_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((stage_v_191_1 + (pub_r001426_18_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_191_2 + (pub_r001426_18_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((stage_v_195_1 + (pub_r001426_6_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_195_2 + (pub_r001426_6_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((stage_v_11_1 + (pub_r001426_20_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_11_2 + (pub_r001426_20_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((pub_r001426_1_1 * 2) + 49) & 63;
  int stage_v_213_2 = ((pub_r001426_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((sec_r001426_15_1 + (pub_r001426_3_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((sec_r001426_15_2 + (pub_r001426_3_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((helper_flow_0_1 + (pub_r001426_9_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((helper_flow_0_2 + (pub_r001426_9_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((pub_r001426_9_1 * 2) + 39) & 63;
  int stage_v_216_2 = ((pub_r001426_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((stage_v_31_1 + (pub_r001426_16_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_31_2 + (pub_r001426_16_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_105_1 + (pub_r001426_1_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_105_2 + (pub_r001426_1_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_7_1 + (pub_r001426_16_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_7_2 + (pub_r001426_16_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((pub_r001426_19_1 * 2) + 21) & 63;
  int stage_v_220_2 = ((pub_r001426_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((stage_v_143_1 + (pub_r001426_17_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_143_2 + (pub_r001426_17_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_197_1 + (pub_r001426_16_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_197_2 + (pub_r001426_16_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((pub_r001426_10_1 * 2) + 8) & 63;
  int stage_v_223_2 = ((pub_r001426_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((stage_v_164_1 + (pub_r001426_10_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_164_2 + (pub_r001426_10_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((pub_r001426_3_1 * 2) + 45) & 63;
  int stage_v_225_2 = ((pub_r001426_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001426_10_1 * 2) + 13) & 63;
  int stage_v_226_2 = ((pub_r001426_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_146_1 + (pub_r001426_3_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_146_2 + (pub_r001426_3_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((pub_r001426_15_1 * 2) + 49) & 63;
  int stage_v_228_2 = ((pub_r001426_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001426_3_1 * 2) + 16) & 63;
  int stage_v_229_2 = ((pub_r001426_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_86_1 + (pub_r001426_14_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_86_2 + (pub_r001426_14_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((stage_v_2_1 + (pub_r001426_0_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_2_2 + (pub_r001426_0_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((stage_v_94_1 + (pub_r001426_6_1 * 2)) + 701) & 127;
  int stage_v_232_2 = ((stage_v_94_2 + (pub_r001426_6_2 * 2)) + 701) & 127;
  if (stage_v_232_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_232_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_232_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_232_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_233_1 = ((stage_v_24_1 + (pub_r001426_10_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_24_2 + (pub_r001426_10_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((stage_v_146_1 + (pub_r001426_13_1 * 2)) + 707) & 127;
  int stage_v_234_2 = ((stage_v_146_2 + (pub_r001426_13_2 * 2)) + 707) & 127;
  if (stage_v_234_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_234_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_234_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_234_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001426_12_1 == pub_r001426_12_2);
  __CPROVER_assume(pub_r001426_13_1 == pub_r001426_13_2);
  __CPROVER_assume(pub_r001426_17_1 == pub_r001426_17_2);
  __CPROVER_assume(sec_r001426_15_1 != sec_r001426_15_2);
  __CPROVER_assume(pub_r001426_7_1 == pub_r001426_7_2);
  __CPROVER_assume(pub_r001426_6_1 == pub_r001426_6_2);
  __CPROVER_assume(pub_r001426_4_1 == pub_r001426_4_2);
  __CPROVER_assume(sec_r001426_2_1 != sec_r001426_2_2);
  __CPROVER_assume(sec_r001426_13_1 != sec_r001426_13_2);
  __CPROVER_assume(pub_r001426_14_1 == pub_r001426_14_2);
  __CPROVER_assume(pub_r001426_8_1 == pub_r001426_8_2);
  __CPROVER_assume(pub_r001426_1_1 == pub_r001426_1_2);
  __CPROVER_assume(pub_r001426_15_1 == pub_r001426_15_2);
  __CPROVER_assume(pub_r001426_0_1 == pub_r001426_0_2);
  __CPROVER_assume(sec_r001426_1_1 != sec_r001426_1_2);
  __CPROVER_assume(sec_r001426_6_1 != sec_r001426_6_2);
  __CPROVER_assume(sec_r001426_9_1 != sec_r001426_9_2);
  __CPROVER_assume(sec_r001426_4_1 != sec_r001426_4_2);
  __CPROVER_assume(pub_r001426_5_1 == pub_r001426_5_2);
  __CPROVER_assume(sec_r001426_11_1 != sec_r001426_11_2);
  __CPROVER_assume(pub_r001426_11_1 == pub_r001426_11_2);
  __CPROVER_assume(sec_r001426_10_1 != sec_r001426_10_2);
  __CPROVER_assume(pub_r001426_3_1 == pub_r001426_3_2);
  __CPROVER_assume(pub_r001426_19_1 == pub_r001426_19_2);
  __CPROVER_assume(pub_r001426_20_1 == pub_r001426_20_2);
  __CPROVER_assume(sec_r001426_3_1 != sec_r001426_3_2);
  __CPROVER_assume(pub_r001426_18_1 == pub_r001426_18_2);
  __CPROVER_assume(sec_r001426_8_1 != sec_r001426_8_2);
  __CPROVER_assume(sec_r001426_12_1 != sec_r001426_12_2);
  __CPROVER_assume(sec_r001426_7_1 != sec_r001426_7_2);
  __CPROVER_assume(pub_r001426_10_1 == pub_r001426_10_2);
  __CPROVER_assume(pub_r001426_9_1 == pub_r001426_9_2);
  __CPROVER_assume(sec_r001426_16_1 != sec_r001426_16_2);
  __CPROVER_assume(sec_r001426_5_1 != sec_r001426_5_2);
  __CPROVER_assume(pub_r001426_16_1 == pub_r001426_16_2);
  __CPROVER_assume(sec_r001426_0_1 != sec_r001426_0_2);
  __CPROVER_assume(sec_r001426_14_1 != sec_r001426_14_2);
  __CPROVER_assume(pub_r001426_2_1 == pub_r001426_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
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
}


