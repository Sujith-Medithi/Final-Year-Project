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
struct Transaction_R001606_613_0
{
  short rate;
  int account_id;
  int fee;
  short auth_code;
  int buffer[3];
};
struct StreamBuffer_R001606_613_1
{
  int checksum;
  short head;
  short watermark;
  unsigned char capacity;
  int tail;
  int buffer[3];
};
struct EventLog_R001606_613_2
{
  short facility;
  int seq;
  int code;
  int severity;
  short signature;
  short timestamp;
  int buffer[3];
};
struct Vector3D_R001606_613_3
{
  unsigned char coord_z;
  int norm_sq;
  int coord_x;
  short heading;
  int coord_y;
  int buffer[3];
};
union PacketPayload_R001606_613_0
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
void fn_R001606_613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st_1 = {0};
  struct StreamBuffer_R001606_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int margin_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_32_1 > 34)
  {
    acc_1 = ((acc_1 + (margin_32_1 * 2)) + 5) & 127;
    aux_1 ^= margin_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_32_2 > 34)
  {
    acc_2 = ((acc_2 + (margin_32_2 * 2)) + 5) & 127;
    aux_2 ^= margin_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_84_1) & 63;
  aux_2 = (aux_2 + anchor_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_55_1 = 0;
  int sample_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_55_1 = ((sample_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_55_2 = ((sample_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_55_1) & 127;
    acc_2 = (acc_2 + sample_55_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_32_1 == margin_32_2);
  assert(anchor_84_1 == anchor_84_2);
  assert(sample_55_1 == sample_55_2);
}

int fn_R001606_613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int margin_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_32 > 34)
  {
    acc = ((acc + (margin_32 * 2)) + 5) & 127;
    aux ^= margin_32 & 15;
  }
  else
  {
    acc = ((acc - margin_32) + 11) & 127;
    aux += 3;
  }
  int anchor_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_84) & 63;
  acc ^= aux;
  int sample_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_55 = ((sample_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_55) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001606_613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001606_613_3 st_1 = {0};
  struct Vector3D_R001606_613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int coefficient_35_1 = 0;
  int coefficient_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_35_1 = ((coefficient_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_35_2 = ((coefficient_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_35_1) & 127;
    acc_2 = (acc_2 + coefficient_35_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_41_1) & 63;
  aux_2 = (aux_2 + scale_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_35_1 == coefficient_35_2);
  assert(scale_41_1 == scale_41_2);
}

int fn_R001606_613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001606_613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int coefficient_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_35 = ((coefficient_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_35) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_41) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001606_613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001606_613_0 st_1 = {0};
  struct Transaction_R001606_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int vector_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_34_1 > 33)
  {
    acc_1 = ((acc_1 + (vector_34_1 * 2)) + 5) & 127;
    aux_1 ^= vector_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_34_2 > 33)
  {
    acc_2 = ((acc_2 + (vector_34_2 * 2)) + 5) & 127;
    aux_2 ^= vector_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_40_1)
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

  switch (checksum_40_2)
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
  int mask_41_1 = local_arr_1[aux_1 % 3];
  int mask_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_41_2 * 2)) & 127;
  int cursor_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_37_1) & 63;
  aux_2 = (aux_2 + cursor_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_34_1 == vector_34_2);
  assert(checksum_40_1 == checksum_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_41_1 == mask_41_2);
  assert(cursor_37_1 == cursor_37_2);
}

int fn_R001606_613_2(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001606_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int vector_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_34 > 33)
  {
    acc = ((acc + (vector_34 * 2)) + 5) & 127;
    aux ^= vector_34 & 15;
  }
  else
  {
    acc = ((acc - vector_34) + 11) & 127;
    aux += 3;
  }
  int checksum_40 = (aux + st.buffer[1]) & 3;
  switch (checksum_40)
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
  int mask_41 = local_arr[aux % 3];
  acc = (acc + (mask_41 * 2)) & 127;
  int cursor_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001606_613_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st_1 = {0};
  struct StreamBuffer_R001606_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int accumulator_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_47_1)
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

  switch (accumulator_47_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_47_1 == accumulator_47_2);
}

int fn_R001606_613_3(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int accumulator_47 = (aux + st.buffer[1]) & 3;
  switch (accumulator_47)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001606_613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001606_613_0 st_1 = {0};
  struct Transaction_R001606_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int bound_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_74_1)
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

  switch (bound_74_2)
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

  int quotient_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_81_1 > 43)
  {
    acc_1 = ((acc_1 + (quotient_81_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_81_2 > 43)
  {
    acc_2 = ((acc_2 + (quotient_81_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_34_1 = 0;
  int segment_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_34_1 = ((segment_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_34_2 = ((segment_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_34_1) & 127;
    acc_2 = (acc_2 + segment_34_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_34_1 = local_arr_1[aux_1 % 3];
  int coefficient_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_34_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_74_1 == bound_74_2);
  assert(quotient_81_1 == quotient_81_2);
  assert(segment_34_1 == segment_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_34_1 == coefficient_34_2);
}

int fn_R001606_613_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001606_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int bound_74 = (aux + st.buffer[1]) & 3;
  switch (bound_74)
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

  int quotient_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_81 > 43)
  {
    acc = ((acc + (quotient_81 * 2)) + 5) & 127;
    aux ^= quotient_81 & 15;
  }
  else
  {
    acc = ((acc - quotient_81) + 11) & 127;
    aux += 3;
  }
  int segment_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_34 = ((segment_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_34) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int coefficient_34 = local_arr[aux % 3];
  acc = (acc + (coefficient_34 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001606_613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st_1 = {0};
  struct EventLog_R001606_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int sample_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_61_1) & 63;
  aux_2 = (aux_2 + sample_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_42_1 = local_arr_1[aux_1 % 3];
  int margin_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_42_2 * 2)) & 127;
  int margin_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_85_1)
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

  switch (margin_85_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_61_1 == sample_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_42_1 == margin_42_2);
  assert(margin_85_1 == margin_85_2);
}

int fn_R001606_613_5(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int sample_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_61) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_42 = local_arr[aux % 3];
  acc = (acc + (margin_42 * 2)) & 127;
  int margin_85 = (aux + st.buffer[1]) & 3;
  switch (margin_85)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001606_613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001606_613_3 st_1 = {0};
  struct Vector3D_R001606_613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_42_1 = local_arr_1[aux_1 % 3];
  int accumulator_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_42_2 * 2)) & 127;
  int factor_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_17_1) & 63;
  aux_2 = (aux_2 + factor_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_42_1 == accumulator_42_2);
  assert(factor_17_1 == factor_17_2);
}

int fn_R001606_613_6(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001606_613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int accumulator_42 = local_arr[aux % 3];
  acc = (acc + (accumulator_42 * 2)) & 127;
  int factor_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_17) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001606_613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st_1 = {0};
  struct EventLog_R001606_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_11_1 = local_arr_1[aux_1 % 3];
  int damping_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_11_2 * 2)) & 127;
  int anchor_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_71_1 > 46)
  {
    acc_1 = ((acc_1 + (anchor_71_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_71_2 > 46)
  {
    acc_2 = ((acc_2 + (anchor_71_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_11_1 == damping_11_2);
  assert(anchor_71_1 == anchor_71_2);
}

int fn_R001606_613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int damping_11 = local_arr[aux % 3];
  acc = (acc + (damping_11 * 2)) & 127;
  int anchor_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_71 > 46)
  {
    acc = ((acc + (anchor_71 * 2)) + 5) & 127;
    aux ^= anchor_71 & 15;
  }
  else
  {
    acc = ((acc - anchor_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001606_613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st_1 = {0};
  struct StreamBuffer_R001606_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int weight_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_64_1) & 63;
  aux_2 = (aux_2 + weight_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_22_1 = local_arr_1[aux_1 % 3];
  int segment_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_22_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_64_1 == weight_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_22_1 == segment_22_2);
}

int fn_R001606_613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int weight_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_64) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_22 = local_arr[aux % 3];
  acc = (acc + (segment_22 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001606_613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st_1 = {0};
  struct StreamBuffer_R001606_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_98_1 = local_arr_1[aux_1 % 3];
  int accumulator_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_98_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_39_1 > 25)
  {
    acc_1 = ((acc_1 + (phase_39_1 * 2)) + 5) & 127;
    aux_1 ^= phase_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_39_2 > 25)
  {
    acc_2 = ((acc_2 + (phase_39_2 * 2)) + 5) & 127;
    aux_2 ^= phase_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_24_1 = 0;
  int phase_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_24_1 = ((phase_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_24_2 = ((phase_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_24_1) & 127;
    acc_2 = (acc_2 + phase_24_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
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

  assert(accumulator_98_1 == accumulator_98_2);
  assert(phase_39_1 == phase_39_2);
  assert(phase_24_1 == phase_24_2);
}

int fn_R001606_613_9(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int accumulator_98 = local_arr[aux % 3];
  acc = (acc + (accumulator_98 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_39 > 25)
  {
    acc = ((acc + (phase_39 * 2)) + 5) & 127;
    aux ^= phase_39 & 15;
  }
  else
  {
    acc = ((acc - phase_39) + 11) & 127;
    aux += 3;
  }
  int phase_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_24 = ((phase_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_24) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001606_613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st_1 = {0};
  struct StreamBuffer_R001606_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int accumulator_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_73_1 > 49)
  {
    acc_1 = ((acc_1 + (accumulator_73_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_73_2 > 49)
  {
    acc_2 = ((acc_2 + (accumulator_73_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_73_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_25_1)
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

  switch (quotient_25_2)
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
  int factor_59_1 = local_arr_1[aux_1 % 3];
  int factor_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_73_1 == accumulator_73_2);
  assert(quotient_25_1 == quotient_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_59_1 == factor_59_2);
}

int fn_R001606_613_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int accumulator_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_73 > 49)
  {
    acc = ((acc + (accumulator_73 * 2)) + 5) & 127;
    aux ^= accumulator_73 & 15;
  }
  else
  {
    acc = ((acc - accumulator_73) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_25 = (aux + st.buffer[1]) & 3;
  switch (quotient_25)
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
  int factor_59 = local_arr[aux % 3];
  acc = (acc + (factor_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001606_613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st_1 = {0};
  struct EventLog_R001606_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int checksum_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_92_1) & 63;
  aux_2 = (aux_2 + checksum_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_46_1 > 11)
  {
    acc_1 = ((acc_1 + (quotient_46_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_46_2 > 11)
  {
    acc_2 = ((acc_2 + (quotient_46_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_92_1 == checksum_92_2);
  assert(quotient_46_1 == quotient_46_2);
}

int fn_R001606_613_11(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int checksum_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_92) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_46 > 11)
  {
    acc = ((acc + (quotient_46 * 2)) + 5) & 127;
    aux ^= quotient_46 & 15;
  }
  else
  {
    acc = ((acc - quotient_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001606_613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001606_613_3 st_1 = {0};
  struct Vector3D_R001606_613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int stride_24_1 = 0;
  int stride_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_24_1 = ((stride_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_24_2 = ((stride_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_24_1) & 127;
    acc_2 = (acc_2 + stride_24_2) & 127;
  }

  int accumulator_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_59_1 > 48)
  {
    acc_1 = ((acc_1 + (accumulator_59_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_59_2 > 48)
  {
    acc_2 = ((acc_2 + (accumulator_59_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_24_1 == stride_24_2);
  assert(accumulator_59_1 == accumulator_59_2);
}

int fn_R001606_613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001606_613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int stride_24 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_24 = ((stride_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_24) & 127;
  }

  int accumulator_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_59 > 48)
  {
    acc = ((acc + (accumulator_59 * 2)) + 5) & 127;
    aux ^= accumulator_59 & 15;
  }
  else
  {
    acc = ((acc - accumulator_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001606_613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st_1 = {0};
  struct EventLog_R001606_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int delta_69_1 = 0;
  int delta_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_69_1 = ((delta_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_69_2 = ((delta_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_69_1) & 127;
    acc_2 = (acc_2 + delta_69_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_69_1 == delta_69_2);
}

int fn_R001606_613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int delta_69 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_69 = ((delta_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_69) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001606_613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001606_613_0 st_1 = {0};
  struct Transaction_R001606_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int threshold_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_25_1) & 63;
  aux_2 = (aux_2 + threshold_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_24_1 = local_arr_1[aux_1 % 3];
  int quotient_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_24_2 * 2)) & 127;
  int stride_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_46_1)
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

  switch (stride_46_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_25_1 == threshold_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_24_1 == quotient_24_2);
  assert(stride_46_1 == stride_46_2);
}

int fn_R001606_613_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001606_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int threshold_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_25) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_24 = local_arr[aux % 3];
  acc = (acc + (quotient_24 * 2)) & 127;
  int stride_46 = (aux + st.buffer[1]) & 3;
  switch (stride_46)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001606_613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st_1 = {0};
  struct StreamBuffer_R001606_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int vector_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_19_1)
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

  switch (vector_19_2)
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

  int weight_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_64_1) & 63;
  aux_2 = (aux_2 + weight_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_19_1 == vector_19_2);
  assert(weight_64_1 == weight_64_2);
}

int fn_R001606_613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int vector_19 = (aux + st.buffer[1]) & 3;
  switch (vector_19)
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

  int weight_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001606_613_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st_1 = {0};
  struct StreamBuffer_R001606_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int cursor_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_68_1 > 35)
  {
    acc_1 = ((acc_1 + (cursor_68_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_68_2 > 35)
  {
    acc_2 = ((acc_2 + (cursor_68_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_41_1)
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

  switch (cursor_41_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_68_1 == cursor_68_2);
  assert(cursor_41_1 == cursor_41_2);
}

int fn_R001606_613_16(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int cursor_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_68 > 35)
  {
    acc = ((acc + (cursor_68 * 2)) + 5) & 127;
    aux ^= cursor_68 & 15;
  }
  else
  {
    acc = ((acc - cursor_68) + 11) & 127;
    aux += 3;
  }
  int cursor_41 = (aux + st.buffer[1]) & 3;
  switch (cursor_41)
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

  return (acc + aux) & 255;
}

void fn_R001606_613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001606_613_0 st_1 = {0};
  struct Transaction_R001606_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int window_63_1 = 0;
  int window_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_63_1 = ((window_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_63_2 = ((window_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_63_1) & 127;
    acc_2 = (acc_2 + window_63_2) & 127;
  }

  int quantum_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_91_1 > 38)
  {
    acc_1 = ((acc_1 + (quantum_91_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_91_2 > 38)
  {
    acc_2 = ((acc_2 + (quantum_91_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_93_1 = local_arr_1[aux_1 % 3];
  int vector_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_93_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_63_1 == window_63_2);
  assert(quantum_91_1 == quantum_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_93_1 == vector_93_2);
}

int fn_R001606_613_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001606_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int window_63 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_63 = ((window_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_63) & 127;
  }

  int quantum_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_91 > 38)
  {
    acc = ((acc + (quantum_91 * 2)) + 5) & 127;
    aux ^= quantum_91 & 15;
  }
  else
  {
    acc = ((acc - quantum_91) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_93 = local_arr[aux % 3];
  acc = (acc + (vector_93 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001606_613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st_1 = {0};
  struct StreamBuffer_R001606_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int factor_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_70_1) & 63;
  aux_2 = (aux_2 + factor_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_45_1)
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

  switch (index_reg_45_2)
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

  int vector_66_1 = 0;
  int vector_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_66_1 = ((vector_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_66_2 = ((vector_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_66_1) & 127;
    acc_2 = (acc_2 + vector_66_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_70_1 == factor_70_2);
  assert(index_reg_45_1 == index_reg_45_2);
  assert(vector_66_1 == vector_66_2);
}

int fn_R001606_613_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int factor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_45 = (aux + st.buffer[1]) & 3;
  switch (index_reg_45)
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

  int vector_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_66 = ((vector_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_66) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001606_613_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001606_613_0 st_1 = {0};
  struct Transaction_R001606_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int offset_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_61_1) & 63;
  aux_2 = (aux_2 + offset_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_61_1 == offset_61_2);
}

int fn_R001606_613_19(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001606_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int offset_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_61) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001606_613_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st_1 = {0};
  struct StreamBuffer_R001606_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int metric_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_93_1 > 34)
  {
    acc_1 = ((acc_1 + (metric_93_1 * 2)) + 5) & 127;
    aux_1 ^= metric_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_93_2 > 34)
  {
    acc_2 = ((acc_2 + (metric_93_2 * 2)) + 5) & 127;
    aux_2 ^= metric_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_92_1) & 63;
  aux_2 = (aux_2 + delta_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_93_1 == metric_93_2);
  assert(delta_92_1 == delta_92_2);
}

int fn_R001606_613_20(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001606_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int metric_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_93 > 34)
  {
    acc = ((acc + (metric_93 * 2)) + 5) & 127;
    aux ^= metric_93 & 15;
  }
  else
  {
    acc = ((acc - metric_93) + 11) & 127;
    aux += 3;
  }
  int delta_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001606_613_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st_1 = {0};
  struct EventLog_R001606_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int damping_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_84_1 > 19)
  {
    acc_1 = ((acc_1 + (damping_84_1 * 2)) + 5) & 127;
    aux_1 ^= damping_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_84_2 > 19)
  {
    acc_2 = ((acc_2 + (damping_84_2 * 2)) + 5) & 127;
    aux_2 ^= damping_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_84_1 = 0;
  int quotient_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_84_1 = ((quotient_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_84_2 = ((quotient_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_84_1) & 127;
    acc_2 = (acc_2 + quotient_84_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_84_1 == damping_84_2);
  assert(quotient_84_1 == quotient_84_2);
}

int fn_R001606_613_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int damping_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_84 > 19)
  {
    acc = ((acc + (damping_84 * 2)) + 5) & 127;
    aux ^= damping_84 & 15;
  }
  else
  {
    acc = ((acc - damping_84) + 11) & 127;
    aux += 3;
  }
  int quotient_84 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_84 = ((quotient_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_84) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001606_613_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st_1 = {0};
  struct EventLog_R001606_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int window_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_43_1 > 22)
  {
    acc_1 = ((acc_1 + (window_43_1 * 2)) + 5) & 127;
    aux_1 ^= window_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_43_2 > 22)
  {
    acc_2 = ((acc_2 + (window_43_2 * 2)) + 5) & 127;
    aux_2 ^= window_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_38_1 = 0;
  int accumulator_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_38_1 = ((accumulator_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_38_2 = ((accumulator_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_38_1) & 127;
    acc_2 = (acc_2 + accumulator_38_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_43_1 == window_43_2);
  assert(accumulator_38_1 == accumulator_38_2);
}

int fn_R001606_613_22(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001606_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int window_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_43 > 22)
  {
    acc = ((acc + (window_43 * 2)) + 5) & 127;
    aux ^= window_43 & 15;
  }
  else
  {
    acc = ((acc - window_43) + 11) & 127;
    aux += 3;
  }
  int accumulator_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_38 = ((accumulator_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_38) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001606_613_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001606_613_3 st_1 = {0};
  struct Vector3D_R001606_613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int metric_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_53_1)
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

  switch (metric_53_2)
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

  int damping_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_80_1) & 63;
  aux_2 = (aux_2 + damping_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_54_1 = local_arr_1[aux_1 % 3];
  int metric_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_54_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_53_1 == metric_53_2);
  assert(damping_80_1 == damping_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_54_1 == metric_54_2);
}

int fn_R001606_613_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001606_613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int metric_53 = (aux + st.buffer[1]) & 3;
  switch (metric_53)
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

  int damping_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_80) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_54 = local_arr[aux % 3];
  acc = (acc + (metric_54 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001606_0_1;
  int sec_r001606_0_2;
  int sec_r001606_1_1;
  int sec_r001606_1_2;
  int sec_r001606_2_1;
  int sec_r001606_2_2;
  int sec_r001606_3_1;
  int sec_r001606_3_2;
  int sec_r001606_4_1;
  int sec_r001606_4_2;
  int sec_r001606_5_1;
  int sec_r001606_5_2;
  int sec_r001606_6_1;
  int sec_r001606_6_2;
  int sec_r001606_7_1;
  int sec_r001606_7_2;
  int sec_r001606_8_1;
  int sec_r001606_8_2;
  int sec_r001606_9_1;
  int sec_r001606_9_2;
  int sec_r001606_10_1;
  int sec_r001606_10_2;
  int sec_r001606_11_1;
  int sec_r001606_11_2;
  int sec_r001606_12_1;
  int sec_r001606_12_2;
  int sec_r001606_13_1;
  int sec_r001606_13_2;
  int sec_r001606_14_1;
  int sec_r001606_14_2;
  int sec_r001606_15_1;
  int sec_r001606_15_2;
  int sec_r001606_16_1;
  int sec_r001606_16_2;
  int sec_r001606_17_1;
  int sec_r001606_17_2;
  int pub_r001606_0_1;
  int pub_r001606_0_2;
  int pub_r001606_1_1;
  int pub_r001606_1_2;
  int pub_r001606_2_1;
  int pub_r001606_2_2;
  int pub_r001606_3_1;
  int pub_r001606_3_2;
  int pub_r001606_4_1;
  int pub_r001606_4_2;
  int pub_r001606_5_1;
  int pub_r001606_5_2;
  int pub_r001606_6_1;
  int pub_r001606_6_2;
  int pub_r001606_7_1;
  int pub_r001606_7_2;
  int pub_r001606_8_1;
  int pub_r001606_8_2;
  int pub_r001606_9_1;
  int pub_r001606_9_2;
  int pub_r001606_10_1;
  int pub_r001606_10_2;
  int pub_r001606_11_1;
  int pub_r001606_11_2;
  int pub_r001606_12_1;
  int pub_r001606_12_2;
  int pub_r001606_13_1;
  int pub_r001606_13_2;
  int pub_r001606_14_1;
  int pub_r001606_14_2;
  int pub_r001606_15_1;
  int pub_r001606_15_2;
  int pub_r001606_16_1;
  int pub_r001606_16_2;
  int pub_r001606_17_1;
  int pub_r001606_17_2;
  int pub_r001606_18_1;
  int pub_r001606_18_2;
  int pub_r001606_19_1;
  int pub_r001606_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001606_0_1 >= (-100)) && (pub_r001606_0_1 <= 100));
  __CPROVER_assume((pub_r001606_0_2 >= (-100)) && (pub_r001606_0_2 <= 100));
  __CPROVER_assume((pub_r001606_1_1 >= (-100)) && (pub_r001606_1_1 <= 100));
  __CPROVER_assume((pub_r001606_1_2 >= (-100)) && (pub_r001606_1_2 <= 100));
  __CPROVER_assume((pub_r001606_2_1 >= (-100)) && (pub_r001606_2_1 <= 100));
  __CPROVER_assume((pub_r001606_2_2 >= (-100)) && (pub_r001606_2_2 <= 100));
  __CPROVER_assume((pub_r001606_3_1 >= (-100)) && (pub_r001606_3_1 <= 100));
  __CPROVER_assume((pub_r001606_3_2 >= (-100)) && (pub_r001606_3_2 <= 100));
  __CPROVER_assume((pub_r001606_4_1 >= (-100)) && (pub_r001606_4_1 <= 100));
  __CPROVER_assume((pub_r001606_4_2 >= (-100)) && (pub_r001606_4_2 <= 100));
  __CPROVER_assume((pub_r001606_5_1 >= (-100)) && (pub_r001606_5_1 <= 100));
  __CPROVER_assume((pub_r001606_5_2 >= (-100)) && (pub_r001606_5_2 <= 100));
  __CPROVER_assume((pub_r001606_6_1 >= (-100)) && (pub_r001606_6_1 <= 100));
  __CPROVER_assume((pub_r001606_6_2 >= (-100)) && (pub_r001606_6_2 <= 100));
  __CPROVER_assume((pub_r001606_7_1 >= (-100)) && (pub_r001606_7_1 <= 100));
  __CPROVER_assume((pub_r001606_7_2 >= (-100)) && (pub_r001606_7_2 <= 100));
  __CPROVER_assume((pub_r001606_8_1 >= (-100)) && (pub_r001606_8_1 <= 100));
  __CPROVER_assume((pub_r001606_8_2 >= (-100)) && (pub_r001606_8_2 <= 100));
  __CPROVER_assume((pub_r001606_9_1 >= (-100)) && (pub_r001606_9_1 <= 100));
  __CPROVER_assume((pub_r001606_9_2 >= (-100)) && (pub_r001606_9_2 <= 100));
  __CPROVER_assume((pub_r001606_10_1 >= (-100)) && (pub_r001606_10_1 <= 100));
  __CPROVER_assume((pub_r001606_10_2 >= (-100)) && (pub_r001606_10_2 <= 100));
  __CPROVER_assume((pub_r001606_11_1 >= (-100)) && (pub_r001606_11_1 <= 100));
  __CPROVER_assume((pub_r001606_11_2 >= (-100)) && (pub_r001606_11_2 <= 100));
  __CPROVER_assume((pub_r001606_12_1 >= (-100)) && (pub_r001606_12_1 <= 100));
  __CPROVER_assume((pub_r001606_12_2 >= (-100)) && (pub_r001606_12_2 <= 100));
  __CPROVER_assume((pub_r001606_13_1 >= (-100)) && (pub_r001606_13_1 <= 100));
  __CPROVER_assume((pub_r001606_13_2 >= (-100)) && (pub_r001606_13_2 <= 100));
  __CPROVER_assume((pub_r001606_14_1 >= (-100)) && (pub_r001606_14_1 <= 100));
  __CPROVER_assume((pub_r001606_14_2 >= (-100)) && (pub_r001606_14_2 <= 100));
  __CPROVER_assume((pub_r001606_15_1 >= (-100)) && (pub_r001606_15_1 <= 100));
  __CPROVER_assume((pub_r001606_15_2 >= (-100)) && (pub_r001606_15_2 <= 100));
  __CPROVER_assume((pub_r001606_16_1 >= (-100)) && (pub_r001606_16_1 <= 100));
  __CPROVER_assume((pub_r001606_16_2 >= (-100)) && (pub_r001606_16_2 <= 100));
  __CPROVER_assume((pub_r001606_17_1 >= (-100)) && (pub_r001606_17_1 <= 100));
  __CPROVER_assume((pub_r001606_17_2 >= (-100)) && (pub_r001606_17_2 <= 100));
  __CPROVER_assume((pub_r001606_18_1 >= (-100)) && (pub_r001606_18_1 <= 100));
  __CPROVER_assume((pub_r001606_18_2 >= (-100)) && (pub_r001606_18_2 <= 100));
  __CPROVER_assume((pub_r001606_19_1 >= (-100)) && (pub_r001606_19_1 <= 100));
  __CPROVER_assume((pub_r001606_19_2 >= (-100)) && (pub_r001606_19_2 <= 100));
  __CPROVER_assume((sec_r001606_0_1 >= 0) && (sec_r001606_0_1 <= 255));
  __CPROVER_assume((sec_r001606_0_2 >= 0) && (sec_r001606_0_2 <= 255));
  __CPROVER_assume((sec_r001606_1_1 >= 0) && (sec_r001606_1_1 <= 255));
  __CPROVER_assume((sec_r001606_1_2 >= 0) && (sec_r001606_1_2 <= 255));
  __CPROVER_assume((sec_r001606_2_1 >= 0) && (sec_r001606_2_1 <= 255));
  __CPROVER_assume((sec_r001606_2_2 >= 0) && (sec_r001606_2_2 <= 255));
  __CPROVER_assume((sec_r001606_3_1 >= 0) && (sec_r001606_3_1 <= 255));
  __CPROVER_assume((sec_r001606_3_2 >= 0) && (sec_r001606_3_2 <= 255));
  __CPROVER_assume((sec_r001606_4_1 >= 0) && (sec_r001606_4_1 <= 255));
  __CPROVER_assume((sec_r001606_4_2 >= 0) && (sec_r001606_4_2 <= 255));
  __CPROVER_assume((sec_r001606_5_1 >= 0) && (sec_r001606_5_1 <= 255));
  __CPROVER_assume((sec_r001606_5_2 >= 0) && (sec_r001606_5_2 <= 255));
  __CPROVER_assume((sec_r001606_6_1 >= 0) && (sec_r001606_6_1 <= 255));
  __CPROVER_assume((sec_r001606_6_2 >= 0) && (sec_r001606_6_2 <= 255));
  __CPROVER_assume((sec_r001606_7_1 >= 0) && (sec_r001606_7_1 <= 255));
  __CPROVER_assume((sec_r001606_7_2 >= 0) && (sec_r001606_7_2 <= 255));
  __CPROVER_assume((sec_r001606_8_1 >= 0) && (sec_r001606_8_1 <= 255));
  __CPROVER_assume((sec_r001606_8_2 >= 0) && (sec_r001606_8_2 <= 255));
  __CPROVER_assume((sec_r001606_9_1 >= 0) && (sec_r001606_9_1 <= 255));
  __CPROVER_assume((sec_r001606_9_2 >= 0) && (sec_r001606_9_2 <= 255));
  __CPROVER_assume((sec_r001606_10_1 >= 0) && (sec_r001606_10_1 <= 255));
  __CPROVER_assume((sec_r001606_10_2 >= 0) && (sec_r001606_10_2 <= 255));
  __CPROVER_assume((sec_r001606_11_1 >= 0) && (sec_r001606_11_1 <= 255));
  __CPROVER_assume((sec_r001606_11_2 >= 0) && (sec_r001606_11_2 <= 255));
  __CPROVER_assume((sec_r001606_12_1 >= 0) && (sec_r001606_12_1 <= 255));
  __CPROVER_assume((sec_r001606_12_2 >= 0) && (sec_r001606_12_2 <= 255));
  __CPROVER_assume((sec_r001606_13_1 >= 0) && (sec_r001606_13_1 <= 255));
  __CPROVER_assume((sec_r001606_13_2 >= 0) && (sec_r001606_13_2 <= 255));
  __CPROVER_assume((sec_r001606_14_1 >= 0) && (sec_r001606_14_1 <= 255));
  __CPROVER_assume((sec_r001606_14_2 >= 0) && (sec_r001606_14_2 <= 255));
  __CPROVER_assume((sec_r001606_15_1 >= 0) && (sec_r001606_15_1 <= 255));
  __CPROVER_assume((sec_r001606_15_2 >= 0) && (sec_r001606_15_2 <= 255));
  __CPROVER_assume((sec_r001606_16_1 >= 0) && (sec_r001606_16_1 <= 255));
  __CPROVER_assume((sec_r001606_16_2 >= 0) && (sec_r001606_16_2 <= 255));
  __CPROVER_assume((sec_r001606_17_1 >= 0) && (sec_r001606_17_1 <= 255));
  __CPROVER_assume((sec_r001606_17_2 >= 0) && (sec_r001606_17_2 <= 255));
  struct Transaction_R001606_613_0 st_var_0_1 = {0};
  struct Transaction_R001606_613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001606_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001606_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001606_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001606_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001606_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001606_0_2 + 7) & 15;
  struct StreamBuffer_R001606_613_1 st_var_1_1 = {0};
  struct StreamBuffer_R001606_613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001606_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001606_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001606_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001606_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001606_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001606_0_2 + 9) & 15;
  struct EventLog_R001606_613_2 st_var_2_1 = {0};
  struct EventLog_R001606_613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001606_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001606_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001606_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001606_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001606_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001606_0_2 + 11) & 15;
  struct Vector3D_R001606_613_3 st_var_3_1 = {0};
  struct Vector3D_R001606_613_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001606_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001606_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001606_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001606_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001606_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001606_0_2 + 13) & 15;
  union PacketPayload_R001606_613_0 u_var_1;
  union PacketPayload_R001606_613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001606_613_0(sec_r001606_0_1, pub_r001606_1_1, pub_r001606_2_1, pub_r001606_3_1, pub_r001606_4_1);
  int helper_flow_0_2 = fn_R001606_613_0(sec_r001606_0_2, pub_r001606_1_2, pub_r001606_2_2, pub_r001606_3_2, pub_r001606_4_2);
  fn_R001606_613_0_2(sec_r001606_0_1, pub_r001606_1_1, pub_r001606_2_1, pub_r001606_3_1, pub_r001606_4_1, sec_r001606_0_2, pub_r001606_1_2, pub_r001606_2_2, pub_r001606_3_2, pub_r001606_4_2);
  int helper_flow_1_1 = fn_R001606_613_1(sec_r001606_1_1, sec_r001606_2_1, pub_r001606_3_1, pub_r001606_4_1);
  int helper_flow_1_2 = fn_R001606_613_1(sec_r001606_1_2, sec_r001606_2_2, pub_r001606_3_2, pub_r001606_4_2);
  fn_R001606_613_1_2(sec_r001606_1_1, sec_r001606_2_1, pub_r001606_3_1, pub_r001606_4_1, sec_r001606_1_2, sec_r001606_2_2, pub_r001606_3_2, pub_r001606_4_2);
  int helper_flow_2_1 = fn_R001606_613_2(sec_r001606_2_1, pub_r001606_3_1);
  int helper_flow_2_2 = fn_R001606_613_2(sec_r001606_2_2, pub_r001606_3_2);
  fn_R001606_613_2_2(sec_r001606_2_1, pub_r001606_3_1, sec_r001606_2_2, pub_r001606_3_2);
  int helper_flow_3_1 = fn_R001606_613_3(sec_r001606_3_1, sec_r001606_4_1);
  int helper_flow_3_2 = fn_R001606_613_3(sec_r001606_3_2, sec_r001606_4_2);
  fn_R001606_613_3_2(sec_r001606_3_1, sec_r001606_4_1, sec_r001606_3_2, sec_r001606_4_2);
  int helper_flow_4_1 = fn_R001606_613_4(sec_r001606_4_1, pub_r001606_5_1, pub_r001606_6_1, pub_r001606_7_1);
  int helper_flow_4_2 = fn_R001606_613_4(sec_r001606_4_2, pub_r001606_5_2, pub_r001606_6_2, pub_r001606_7_2);
  fn_R001606_613_4_2(sec_r001606_4_1, pub_r001606_5_1, pub_r001606_6_1, pub_r001606_7_1, sec_r001606_4_2, pub_r001606_5_2, pub_r001606_6_2, pub_r001606_7_2);
  int helper_flow_5_1 = fn_R001606_613_5(sec_r001606_5_1, pub_r001606_6_1);
  int helper_flow_5_2 = fn_R001606_613_5(sec_r001606_5_2, pub_r001606_6_2);
  fn_R001606_613_5_2(sec_r001606_5_1, pub_r001606_6_1, sec_r001606_5_2, pub_r001606_6_2);
  int helper_flow_6_1 = fn_R001606_613_6(sec_r001606_6_1, sec_r001606_7_1);
  int helper_flow_6_2 = fn_R001606_613_6(sec_r001606_6_2, sec_r001606_7_2);
  fn_R001606_613_6_2(sec_r001606_6_1, sec_r001606_7_1, sec_r001606_6_2, sec_r001606_7_2);
  int helper_flow_7_1 = fn_R001606_613_7(sec_r001606_7_1, pub_r001606_8_1, pub_r001606_9_1, pub_r001606_10_1, pub_r001606_11_1);
  int helper_flow_7_2 = fn_R001606_613_7(sec_r001606_7_2, pub_r001606_8_2, pub_r001606_9_2, pub_r001606_10_2, pub_r001606_11_2);
  fn_R001606_613_7_2(sec_r001606_7_1, pub_r001606_8_1, pub_r001606_9_1, pub_r001606_10_1, pub_r001606_11_1, sec_r001606_7_2, pub_r001606_8_2, pub_r001606_9_2, pub_r001606_10_2, pub_r001606_11_2);
  int helper_flow_8_1 = fn_R001606_613_8(sec_r001606_8_1, sec_r001606_9_1, pub_r001606_10_1, pub_r001606_11_1);
  int helper_flow_8_2 = fn_R001606_613_8(sec_r001606_8_2, sec_r001606_9_2, pub_r001606_10_2, pub_r001606_11_2);
  fn_R001606_613_8_2(sec_r001606_8_1, sec_r001606_9_1, pub_r001606_10_1, pub_r001606_11_1, sec_r001606_8_2, sec_r001606_9_2, pub_r001606_10_2, pub_r001606_11_2);
  int stage_v_0_1 = ((pub_r001606_10_1 * 2) + 5) & 63;
  int stage_v_0_2 = ((pub_r001606_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((sec_r001606_7_1 + (pub_r001606_3_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001606_7_2 + (pub_r001606_3_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((helper_flow_5_1 + (pub_r001606_4_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((helper_flow_5_2 + (pub_r001606_4_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((sec_r001606_5_1 + (pub_r001606_18_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001606_5_2 + (pub_r001606_18_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((sec_r001606_2_1 + (pub_r001606_19_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((sec_r001606_2_2 + (pub_r001606_19_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((pub_r001606_5_1 * 2) + 20) & 63;
  int stage_v_5_2 = ((pub_r001606_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((helper_flow_0_1 + (pub_r001606_13_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((helper_flow_0_2 + (pub_r001606_13_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((pub_r001606_6_1 * 2) + 33) & 63;
  int stage_v_7_2 = ((pub_r001606_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((sec_r001606_0_1 + (pub_r001606_18_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001606_0_2 + (pub_r001606_18_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001606_3_1 * 2) + 28) & 63;
  int stage_v_9_2 = ((pub_r001606_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((helper_flow_0_1 + (pub_r001606_18_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((helper_flow_0_2 + (pub_r001606_18_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((sec_r001606_3_1 + (pub_r001606_10_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((sec_r001606_3_2 + (pub_r001606_10_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((helper_flow_3_1 + (pub_r001606_15_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((helper_flow_3_2 + (pub_r001606_15_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001606_10_1 + (pub_r001606_12_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001606_10_2 + (pub_r001606_12_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((sec_r001606_3_1 + (pub_r001606_4_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001606_3_2 + (pub_r001606_4_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((pub_r001606_8_1 * 2) + 49) & 63;
  int stage_v_15_2 = ((pub_r001606_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((sec_r001606_6_1 + (pub_r001606_7_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((sec_r001606_6_2 + (pub_r001606_7_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001606_12_1 + (pub_r001606_19_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001606_12_2 + (pub_r001606_19_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((sec_r001606_4_1 + (pub_r001606_1_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001606_4_2 + (pub_r001606_1_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((pub_r001606_9_1 * 2) + 26) & 63;
  int stage_v_19_2 = ((pub_r001606_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001606_12_1 * 2) + 46) & 63;
  int stage_v_20_2 = ((pub_r001606_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001606_5_1 * 2) + 32) & 63;
  int stage_v_21_2 = ((pub_r001606_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001606_7_1 * 2) + 38) & 63;
  int stage_v_22_2 = ((pub_r001606_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001606_9_1 * 2) + 43) & 63;
  int stage_v_23_2 = ((pub_r001606_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001606_0_1 * 2) + 43) & 63;
  int stage_v_24_2 = ((pub_r001606_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((sec_r001606_13_1 + (pub_r001606_6_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((sec_r001606_13_2 + (pub_r001606_6_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((pub_r001606_4_1 * 2) + 22) & 63;
  int stage_v_26_2 = ((pub_r001606_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((stage_v_4_1 + (pub_r001606_16_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((stage_v_4_2 + (pub_r001606_16_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((sec_r001606_1_1 + (pub_r001606_14_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((sec_r001606_1_2 + (pub_r001606_14_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((sec_r001606_17_1 + (pub_r001606_7_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001606_17_2 + (pub_r001606_7_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((pub_r001606_1_1 * 2) + 17) & 63;
  int stage_v_30_2 = ((pub_r001606_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001606_6_1 * 2) + 17) & 63;
  int stage_v_31_2 = ((pub_r001606_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((helper_flow_4_1 + (pub_r001606_19_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((helper_flow_4_2 + (pub_r001606_19_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((stage_v_12_1 + (pub_r001606_13_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((stage_v_12_2 + (pub_r001606_13_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((helper_flow_7_1 + (pub_r001606_1_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((helper_flow_7_2 + (pub_r001606_1_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((sec_r001606_6_1 + (pub_r001606_11_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001606_6_2 + (pub_r001606_11_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001606_2_1 * 2) + 25) & 63;
  int stage_v_36_2 = ((pub_r001606_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((stage_v_2_1 + (pub_r001606_13_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((stage_v_2_2 + (pub_r001606_13_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((pub_r001606_12_1 * 2) + 26) & 63;
  int stage_v_38_2 = ((pub_r001606_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((sec_r001606_5_1 + (pub_r001606_18_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001606_5_2 + (pub_r001606_18_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((pub_r001606_10_1 * 2) + 49) & 63;
  int stage_v_40_2 = ((pub_r001606_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((sec_r001606_12_1 + (pub_r001606_0_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((sec_r001606_12_2 + (pub_r001606_0_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((stage_v_13_1 + (pub_r001606_2_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((stage_v_13_2 + (pub_r001606_2_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((pub_r001606_12_1 * 2) + 28) & 63;
  int stage_v_43_2 = ((pub_r001606_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((sec_r001606_3_1 + (pub_r001606_6_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((sec_r001606_3_2 + (pub_r001606_6_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((pub_r001606_12_1 * 2) + 9) & 63;
  int stage_v_45_2 = ((pub_r001606_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((stage_v_33_1 + (pub_r001606_13_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_33_2 + (pub_r001606_13_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((pub_r001606_10_1 * 2) + 48) & 63;
  int stage_v_47_2 = ((pub_r001606_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((sec_r001606_3_1 + (pub_r001606_0_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((sec_r001606_3_2 + (pub_r001606_0_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((sec_r001606_17_1 + (pub_r001606_17_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((sec_r001606_17_2 + (pub_r001606_17_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((sec_r001606_0_1 + (pub_r001606_8_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((sec_r001606_0_2 + (pub_r001606_8_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((pub_r001606_17_1 * 2) + 5) & 63;
  int stage_v_51_2 = ((pub_r001606_17_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((stage_v_8_1 + (pub_r001606_19_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((stage_v_8_2 + (pub_r001606_19_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((stage_v_14_1 + (pub_r001606_18_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_14_2 + (pub_r001606_18_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((helper_flow_7_1 + (pub_r001606_16_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((helper_flow_7_2 + (pub_r001606_16_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((pub_r001606_17_1 * 2) + 29) & 63;
  int stage_v_55_2 = ((pub_r001606_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001606_4_1 * 2) + 26) & 63;
  int stage_v_56_2 = ((pub_r001606_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001606_16_1 * 2) + 18) & 63;
  int stage_v_57_2 = ((pub_r001606_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((stage_v_32_1 + (pub_r001606_15_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_32_2 + (pub_r001606_15_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((stage_v_54_1 + (pub_r001606_18_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_54_2 + (pub_r001606_18_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((pub_r001606_10_1 * 2) + 48) & 63;
  int stage_v_60_2 = ((pub_r001606_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001606_3_1 * 2) + 38) & 63;
  int stage_v_61_2 = ((pub_r001606_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001606_12_1 * 2) + 41) & 63;
  int stage_v_62_2 = ((pub_r001606_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((sec_r001606_4_1 + (pub_r001606_7_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((sec_r001606_4_2 + (pub_r001606_7_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((stage_v_59_1 + (pub_r001606_16_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_59_2 + (pub_r001606_16_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_34_1 + (pub_r001606_19_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_34_2 + (pub_r001606_19_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((pub_r001606_0_1 * 2) + 26) & 63;
  int stage_v_66_2 = ((pub_r001606_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001606_1_1 * 2) + 34) & 63;
  int stage_v_67_2 = ((pub_r001606_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((stage_v_16_1 + (pub_r001606_2_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_16_2 + (pub_r001606_2_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((pub_r001606_13_1 * 2) + 10) & 63;
  int stage_v_69_2 = ((pub_r001606_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((sec_r001606_14_1 + (pub_r001606_0_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((sec_r001606_14_2 + (pub_r001606_0_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((sec_r001606_6_1 + (pub_r001606_14_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((sec_r001606_6_2 + (pub_r001606_14_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((pub_r001606_11_1 * 2) + 30) & 63;
  int stage_v_72_2 = ((pub_r001606_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((helper_flow_7_1 + (pub_r001606_6_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((helper_flow_7_2 + (pub_r001606_6_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((pub_r001606_7_1 * 2) + 11) & 63;
  int stage_v_74_2 = ((pub_r001606_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((sec_r001606_0_1 + (pub_r001606_18_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((sec_r001606_0_2 + (pub_r001606_18_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((stage_v_17_1 + (pub_r001606_6_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_17_2 + (pub_r001606_6_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((stage_v_13_1 + (pub_r001606_16_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_13_2 + (pub_r001606_16_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((pub_r001606_16_1 * 2) + 9) & 63;
  int stage_v_78_2 = ((pub_r001606_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001606_10_1 * 2) + 25) & 63;
  int stage_v_79_2 = ((pub_r001606_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((helper_flow_3_1 + (pub_r001606_5_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((helper_flow_3_2 + (pub_r001606_5_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((helper_flow_8_1 + (pub_r001606_12_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((helper_flow_8_2 + (pub_r001606_12_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((stage_v_73_1 + (pub_r001606_16_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_73_2 + (pub_r001606_16_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((stage_v_73_1 + (pub_r001606_15_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_73_2 + (pub_r001606_15_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((pub_r001606_6_1 * 2) + 36) & 63;
  int stage_v_84_2 = ((pub_r001606_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001606_0_1 * 2) + 5) & 63;
  int stage_v_85_2 = ((pub_r001606_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((sec_r001606_8_1 + (pub_r001606_3_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((sec_r001606_8_2 + (pub_r001606_3_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((sec_r001606_4_1 + (pub_r001606_15_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((sec_r001606_4_2 + (pub_r001606_15_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((pub_r001606_8_1 * 2) + 19) & 63;
  int stage_v_88_2 = ((pub_r001606_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((stage_v_81_1 + (pub_r001606_7_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_81_2 + (pub_r001606_7_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((stage_v_17_1 + (pub_r001606_9_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_17_2 + (pub_r001606_9_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((pub_r001606_0_1 * 2) + 40) & 63;
  int stage_v_91_2 = ((pub_r001606_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((sec_r001606_11_1 + (pub_r001606_18_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((sec_r001606_11_2 + (pub_r001606_18_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((pub_r001606_17_1 * 2) + 15) & 63;
  int stage_v_93_2 = ((pub_r001606_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((stage_v_35_1 + (pub_r001606_18_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_35_2 + (pub_r001606_18_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_82_1 + (pub_r001606_0_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_82_2 + (pub_r001606_0_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_83_1 + (pub_r001606_4_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_83_2 + (pub_r001606_4_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_52_1 + (pub_r001606_12_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_52_2 + (pub_r001606_12_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_37_1 + (pub_r001606_4_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_37_2 + (pub_r001606_4_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((stage_v_13_1 + (pub_r001606_1_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_13_2 + (pub_r001606_1_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((pub_r001606_14_1 * 2) + 19) & 63;
  int stage_v_100_2 = ((pub_r001606_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_52_1 + (pub_r001606_10_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_52_2 + (pub_r001606_10_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001606_12_1 * 2) + 13) & 63;
  int stage_v_102_2 = ((pub_r001606_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((sec_r001606_7_1 + (pub_r001606_3_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((sec_r001606_7_2 + (pub_r001606_3_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001606_8_1 * 2) + 37) & 63;
  int stage_v_104_2 = ((pub_r001606_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((helper_flow_5_1 + (pub_r001606_19_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((helper_flow_5_2 + (pub_r001606_19_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((pub_r001606_3_1 * 2) + 11) & 63;
  int stage_v_106_2 = ((pub_r001606_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001606_2_1 * 2) + 31) & 63;
  int stage_v_107_2 = ((pub_r001606_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((stage_v_13_1 + (pub_r001606_15_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_13_2 + (pub_r001606_15_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_2_1 + (pub_r001606_4_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_2_2 + (pub_r001606_4_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((pub_r001606_0_1 * 2) + 18) & 63;
  int stage_v_110_2 = ((pub_r001606_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_98_1 + (pub_r001606_8_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_98_2 + (pub_r001606_8_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((pub_r001606_18_1 * 2) + 5) & 63;
  int stage_v_112_2 = ((pub_r001606_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001606_12_1 * 2) + 8) & 63;
  int stage_v_113_2 = ((pub_r001606_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((stage_v_99_1 + (pub_r001606_6_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_99_2 + (pub_r001606_6_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_4_1 + (pub_r001606_19_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_4_2 + (pub_r001606_19_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_83_1 + (pub_r001606_16_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_83_2 + (pub_r001606_16_2 * 2)) + 353) & 127;
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
  int stage_v_117_1 = ((helper_flow_5_1 + (pub_r001606_9_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((helper_flow_5_2 + (pub_r001606_9_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((sec_r001606_9_1 + (pub_r001606_13_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((sec_r001606_9_2 + (pub_r001606_13_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_86_1 + (pub_r001606_14_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_86_2 + (pub_r001606_14_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((pub_r001606_18_1 * 2) + 43) & 63;
  int stage_v_120_2 = ((pub_r001606_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((helper_flow_4_1 + (pub_r001606_15_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((helper_flow_4_2 + (pub_r001606_15_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((sec_r001606_5_1 + (pub_r001606_11_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((sec_r001606_5_2 + (pub_r001606_11_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_46_1 + (pub_r001606_14_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_46_2 + (pub_r001606_14_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((stage_v_95_1 + (pub_r001606_16_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_95_2 + (pub_r001606_16_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((pub_r001606_11_1 * 2) + 43) & 63;
  int stage_v_125_2 = ((pub_r001606_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_92_1 + (pub_r001606_10_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_92_2 + (pub_r001606_10_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_126_1 + (pub_r001606_12_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_126_2 + (pub_r001606_12_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((helper_flow_7_1 + (pub_r001606_10_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((helper_flow_7_2 + (pub_r001606_10_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((sec_r001606_4_1 + (pub_r001606_6_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((sec_r001606_4_2 + (pub_r001606_6_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_27_1 + (pub_r001606_8_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_27_2 + (pub_r001606_8_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_127_1 + (pub_r001606_9_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_127_2 + (pub_r001606_9_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((stage_v_108_1 + (pub_r001606_16_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_108_2 + (pub_r001606_16_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_54_1 + (pub_r001606_1_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_54_2 + (pub_r001606_1_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((sec_r001606_16_1 + (pub_r001606_12_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((sec_r001606_16_2 + (pub_r001606_12_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((pub_r001606_7_1 * 2) + 33) & 63;
  int stage_v_135_2 = ((pub_r001606_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_44_1 + (pub_r001606_4_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_44_2 + (pub_r001606_4_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((sec_r001606_16_1 + (pub_r001606_3_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((sec_r001606_16_2 + (pub_r001606_3_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((stage_v_10_1 + (pub_r001606_12_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_10_2 + (pub_r001606_12_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((pub_r001606_0_1 * 2) + 11) & 63;
  int stage_v_139_2 = ((pub_r001606_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001606_1_1 * 2) + 41) & 63;
  int stage_v_140_2 = ((pub_r001606_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_128_1 + (pub_r001606_18_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_128_2 + (pub_r001606_18_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((pub_r001606_15_1 * 2) + 5) & 63;
  int stage_v_142_2 = ((pub_r001606_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_111_1 + (pub_r001606_14_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_111_2 + (pub_r001606_14_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((pub_r001606_18_1 * 2) + 12) & 63;
  int stage_v_144_2 = ((pub_r001606_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001606_3_1 * 2) + 18) & 63;
  int stage_v_145_2 = ((pub_r001606_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((stage_v_96_1 + (pub_r001606_10_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_96_2 + (pub_r001606_10_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((pub_r001606_4_1 * 2) + 15) & 63;
  int stage_v_147_2 = ((pub_r001606_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((stage_v_92_1 + (pub_r001606_9_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_92_2 + (pub_r001606_9_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001606_0_1 * 2) + 46) & 63;
  int stage_v_149_2 = ((pub_r001606_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001606_16_1 * 2) + 21) & 63;
  int stage_v_150_2 = ((pub_r001606_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_64_1 + (pub_r001606_2_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_64_2 + (pub_r001606_2_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((sec_r001606_6_1 + (pub_r001606_13_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((sec_r001606_6_2 + (pub_r001606_13_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((pub_r001606_9_1 * 2) + 25) & 63;
  int stage_v_153_2 = ((pub_r001606_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((stage_v_81_1 + (pub_r001606_7_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_81_2 + (pub_r001606_7_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((pub_r001606_9_1 * 2) + 46) & 63;
  int stage_v_155_2 = ((pub_r001606_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((stage_v_116_1 + (pub_r001606_8_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_116_2 + (pub_r001606_8_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((stage_v_90_1 + (pub_r001606_12_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_90_2 + (pub_r001606_12_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((pub_r001606_8_1 * 2) + 45) & 63;
  int stage_v_158_2 = ((pub_r001606_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((stage_v_18_1 + (pub_r001606_19_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_18_2 + (pub_r001606_19_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_115_1 + (pub_r001606_3_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_115_2 + (pub_r001606_3_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001606_17_1 * 2) + 36) & 63;
  int stage_v_161_2 = ((pub_r001606_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_70_1 + (pub_r001606_3_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_70_2 + (pub_r001606_3_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((pub_r001606_4_1 * 2) + 50) & 63;
  int stage_v_163_2 = ((pub_r001606_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001606_6_1 * 2) + 26) & 63;
  int stage_v_164_2 = ((pub_r001606_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((stage_v_159_1 + (pub_r001606_8_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_159_2 + (pub_r001606_8_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_101_1 + (pub_r001606_1_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_101_2 + (pub_r001606_1_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((pub_r001606_2_1 * 2) + 11) & 63;
  int stage_v_167_2 = ((pub_r001606_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001606_14_1 * 2) + 43) & 63;
  int stage_v_168_2 = ((pub_r001606_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((stage_v_6_1 + (pub_r001606_3_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_6_2 + (pub_r001606_3_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001606_7_1 * 2) + 27) & 63;
  int stage_v_170_2 = ((pub_r001606_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((sec_r001606_8_1 + (pub_r001606_5_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((sec_r001606_8_2 + (pub_r001606_5_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((stage_v_34_1 + (pub_r001606_18_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_34_2 + (pub_r001606_18_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((pub_r001606_18_1 * 2) + 49) & 63;
  int stage_v_173_2 = ((pub_r001606_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001606_16_1 * 2) + 45) & 63;
  int stage_v_174_2 = ((pub_r001606_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((stage_v_128_1 + (pub_r001606_10_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_128_2 + (pub_r001606_10_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((helper_flow_4_1 + (pub_r001606_1_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((helper_flow_4_2 + (pub_r001606_1_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((stage_v_32_1 + (pub_r001606_7_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_32_2 + (pub_r001606_7_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((pub_r001606_18_1 * 2) + 39) & 63;
  int stage_v_178_2 = ((pub_r001606_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001606_4_1 * 2) + 40) & 63;
  int stage_v_179_2 = ((pub_r001606_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((stage_v_109_1 + (pub_r001606_5_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_109_2 + (pub_r001606_5_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_165_1 + (pub_r001606_3_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_165_2 + (pub_r001606_3_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((pub_r001606_11_1 * 2) + 46) & 63;
  int stage_v_182_2 = ((pub_r001606_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001606_13_1 * 2) + 41) & 63;
  int stage_v_183_2 = ((pub_r001606_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((stage_v_118_1 + (pub_r001606_15_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_118_2 + (pub_r001606_15_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_4_1 + (pub_r001606_16_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_4_2 + (pub_r001606_16_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((pub_r001606_19_1 * 2) + 9) & 63;
  int stage_v_186_2 = ((pub_r001606_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_95_1 + (pub_r001606_17_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_95_2 + (pub_r001606_17_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((stage_v_68_1 + (pub_r001606_8_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_68_2 + (pub_r001606_8_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((pub_r001606_2_1 * 2) + 45) & 63;
  int stage_v_189_2 = ((pub_r001606_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((stage_v_34_1 + (pub_r001606_13_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_34_2 + (pub_r001606_13_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((pub_r001606_18_1 * 2) + 8) & 63;
  int stage_v_191_2 = ((pub_r001606_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((stage_v_27_1 + (pub_r001606_16_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_27_2 + (pub_r001606_16_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((pub_r001606_15_1 * 2) + 21) & 63;
  int stage_v_193_2 = ((pub_r001606_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001606_7_1 * 2) + 6) & 63;
  int stage_v_194_2 = ((pub_r001606_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001606_9_1 * 2) + 39) & 63;
  int stage_v_195_2 = ((pub_r001606_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((stage_v_138_1 + (pub_r001606_17_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_138_2 + (pub_r001606_17_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((pub_r001606_9_1 * 2) + 39) & 63;
  int stage_v_197_2 = ((pub_r001606_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001606_6_1 * 2) + 30) & 63;
  int stage_v_198_2 = ((pub_r001606_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((stage_v_171_1 + (pub_r001606_14_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_171_2 + (pub_r001606_14_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_99_1 + (pub_r001606_9_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_99_2 + (pub_r001606_9_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((pub_r001606_18_1 * 2) + 12) & 63;
  int stage_v_201_2 = ((pub_r001606_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((stage_v_80_1 + (pub_r001606_4_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_80_2 + (pub_r001606_4_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((pub_r001606_9_1 * 2) + 49) & 63;
  int stage_v_203_2 = ((pub_r001606_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_83_1 + (pub_r001606_7_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_83_2 + (pub_r001606_7_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((sec_r001606_3_1 + (pub_r001606_17_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((sec_r001606_3_2 + (pub_r001606_17_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((sec_r001606_14_1 + (pub_r001606_19_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((sec_r001606_14_2 + (pub_r001606_19_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((pub_r001606_10_1 * 2) + 33) & 63;
  int stage_v_207_2 = ((pub_r001606_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_117_1 + (pub_r001606_17_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_117_2 + (pub_r001606_17_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_16_1 + (pub_r001606_14_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_16_2 + (pub_r001606_14_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((pub_r001606_9_1 * 2) + 26) & 63;
  int stage_v_210_2 = ((pub_r001606_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001606_2_1 * 2) + 13) & 63;
  int stage_v_211_2 = ((pub_r001606_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((sec_r001606_5_1 + (pub_r001606_4_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((sec_r001606_5_2 + (pub_r001606_4_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((pub_r001606_4_1 * 2) + 40) & 63;
  int stage_v_213_2 = ((pub_r001606_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((stage_v_48_1 + (pub_r001606_13_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_48_2 + (pub_r001606_13_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((pub_r001606_5_1 * 2) + 6) & 63;
  int stage_v_215_2 = ((pub_r001606_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001606_3_1 * 2) + 28) & 63;
  int stage_v_216_2 = ((pub_r001606_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((stage_v_206_1 + (pub_r001606_8_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_206_2 + (pub_r001606_8_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_71_1 + (pub_r001606_11_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_71_2 + (pub_r001606_11_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_202_1 + (pub_r001606_11_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_202_2 + (pub_r001606_11_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((pub_r001606_5_1 * 2) + 28) & 63;
  int stage_v_220_2 = ((pub_r001606_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((stage_v_99_1 + (pub_r001606_2_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_99_2 + (pub_r001606_2_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_65_1 + (pub_r001606_10_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_65_2 + (pub_r001606_10_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_190_1 + (pub_r001606_1_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_190_2 + (pub_r001606_1_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((sec_r001606_11_1 + (pub_r001606_12_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((sec_r001606_11_2 + (pub_r001606_12_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((stage_v_71_1 + (pub_r001606_18_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_71_2 + (pub_r001606_18_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((stage_v_86_1 + (pub_r001606_1_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((stage_v_86_2 + (pub_r001606_1_2 * 2)) + 683) & 127;
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
  int stage_v_227_1 = ((stage_v_83_1 + (pub_r001606_12_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_83_2 + (pub_r001606_12_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((sec_r001606_17_1 + (pub_r001606_2_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((sec_r001606_17_2 + (pub_r001606_2_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((stage_v_86_1 + (pub_r001606_17_1 * 2)) + 692) & 127;
  int stage_v_229_2 = ((stage_v_86_2 + (pub_r001606_17_2 * 2)) + 692) & 127;
  if (stage_v_229_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_229_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_229_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_229_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_230_1 = ((stage_v_228_1 + (pub_r001606_11_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_228_2 + (pub_r001606_11_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((stage_v_214_1 + (pub_r001606_15_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_214_2 + (pub_r001606_15_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((stage_v_80_1 + (pub_r001606_5_1 * 2)) + 701) & 127;
  int stage_v_232_2 = ((stage_v_80_2 + (pub_r001606_5_2 * 2)) + 701) & 127;
  if (stage_v_232_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_232_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_232_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_232_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_233_1 = ((stage_v_63_1 + (pub_r001606_7_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_63_2 + (pub_r001606_7_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((pub_r001606_9_1 * 2) + 44) & 63;
  int stage_v_234_2 = ((pub_r001606_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001606_12_1 * 2) + 43) & 63;
  int stage_v_235_2 = ((pub_r001606_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((sec_r001606_15_1 + (pub_r001606_1_1 * 2)) + 713) & 127;
  int stage_v_236_2 = ((sec_r001606_15_2 + (pub_r001606_1_2 * 2)) + 713) & 127;
  if (stage_v_236_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_236_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_236_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_236_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_237_1 = ((pub_r001606_8_1 * 2) + 48) & 63;
  int stage_v_237_2 = ((pub_r001606_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001606_8_1 * 2) + 14) & 63;
  int stage_v_238_2 = ((pub_r001606_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((stage_v_46_1 + (pub_r001606_3_1 * 2)) + 722) & 127;
  int stage_v_239_2 = ((stage_v_46_2 + (pub_r001606_3_2 * 2)) + 722) & 127;
  if (stage_v_239_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_239_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_239_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_239_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_240_1 = ((stage_v_34_1 + (pub_r001606_0_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((stage_v_34_2 + (pub_r001606_0_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((stage_v_81_1 + (pub_r001606_15_1 * 2)) + 728) & 127;
  int stage_v_241_2 = ((stage_v_81_2 + (pub_r001606_15_2 * 2)) + 728) & 127;
  if (stage_v_241_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_241_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_241_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_241_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_242_1 = ((stage_v_32_1 + (pub_r001606_15_1 * 2)) + 731) & 127;
  int stage_v_242_2 = ((stage_v_32_2 + (pub_r001606_15_2 * 2)) + 731) & 127;
  if (stage_v_242_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_242_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_242_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_242_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_243_1 = ((stage_v_116_1 + (pub_r001606_16_1 * 2)) + 734) & 127;
  int stage_v_243_2 = ((stage_v_116_2 + (pub_r001606_16_2 * 2)) + 734) & 127;
  if (stage_v_243_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_243_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_243_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_243_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_243_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_243_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_243_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_243_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_244_1 = ((stage_v_48_1 + (pub_r001606_2_1 * 2)) + 737) & 127;
  int stage_v_244_2 = ((stage_v_48_2 + (pub_r001606_2_2 * 2)) + 737) & 127;
  if (stage_v_244_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_244_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_244_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_244_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_245_1 = ((pub_r001606_12_1 * 2) + 44) & 63;
  int stage_v_245_2 = ((pub_r001606_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((stage_v_196_1 + (pub_r001606_5_1 * 2)) + 743) & 127;
  int stage_v_246_2 = ((stage_v_196_2 + (pub_r001606_5_2 * 2)) + 743) & 127;
  if (stage_v_246_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_246_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_246_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_246_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_247_1 = ((stage_v_73_1 + (pub_r001606_16_1 * 2)) + 746) & 127;
  int stage_v_247_2 = ((stage_v_73_2 + (pub_r001606_16_2 * 2)) + 746) & 127;
  if (stage_v_247_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_247_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_247_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_247_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_248_1 = ((stage_v_222_1 + (pub_r001606_15_1 * 2)) + 749) & 127;
  int stage_v_248_2 = ((stage_v_222_2 + (pub_r001606_15_2 * 2)) + 749) & 127;
  if (stage_v_248_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_248_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_248_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_248_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_248_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_248_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_248_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_248_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_249_1 = ((stage_v_185_1 + (pub_r001606_2_1 * 2)) + 752) & 127;
  int stage_v_249_2 = ((stage_v_185_2 + (pub_r001606_2_2 * 2)) + 752) & 127;
  if (stage_v_249_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_249_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_249_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_249_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_249_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_249_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_249_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_249_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001606_10_1 == pub_r001606_10_2);
  __CPROVER_assume(sec_r001606_4_1 != sec_r001606_4_2);
  __CPROVER_assume(pub_r001606_17_1 == pub_r001606_17_2);
  __CPROVER_assume(pub_r001606_6_1 == pub_r001606_6_2);
  __CPROVER_assume(pub_r001606_11_1 == pub_r001606_11_2);
  __CPROVER_assume(pub_r001606_14_1 == pub_r001606_14_2);
  __CPROVER_assume(pub_r001606_5_1 == pub_r001606_5_2);
  __CPROVER_assume(pub_r001606_9_1 == pub_r001606_9_2);
  __CPROVER_assume(pub_r001606_19_1 == pub_r001606_19_2);
  __CPROVER_assume(sec_r001606_2_1 != sec_r001606_2_2);
  __CPROVER_assume(sec_r001606_12_1 != sec_r001606_12_2);
  __CPROVER_assume(sec_r001606_3_1 != sec_r001606_3_2);
  __CPROVER_assume(pub_r001606_3_1 == pub_r001606_3_2);
  __CPROVER_assume(sec_r001606_9_1 != sec_r001606_9_2);
  __CPROVER_assume(sec_r001606_10_1 != sec_r001606_10_2);
  __CPROVER_assume(sec_r001606_1_1 != sec_r001606_1_2);
  __CPROVER_assume(sec_r001606_8_1 != sec_r001606_8_2);
  __CPROVER_assume(pub_r001606_2_1 == pub_r001606_2_2);
  __CPROVER_assume(sec_r001606_13_1 != sec_r001606_13_2);
  __CPROVER_assume(pub_r001606_7_1 == pub_r001606_7_2);
  __CPROVER_assume(sec_r001606_5_1 != sec_r001606_5_2);
  __CPROVER_assume(pub_r001606_12_1 == pub_r001606_12_2);
  __CPROVER_assume(sec_r001606_17_1 != sec_r001606_17_2);
  __CPROVER_assume(sec_r001606_7_1 != sec_r001606_7_2);
  __CPROVER_assume(pub_r001606_4_1 == pub_r001606_4_2);
  __CPROVER_assume(pub_r001606_16_1 == pub_r001606_16_2);
  __CPROVER_assume(sec_r001606_14_1 != sec_r001606_14_2);
  __CPROVER_assume(sec_r001606_15_1 != sec_r001606_15_2);
  __CPROVER_assume(pub_r001606_8_1 == pub_r001606_8_2);
  __CPROVER_assume(pub_r001606_18_1 == pub_r001606_18_2);
  __CPROVER_assume(sec_r001606_0_1 != sec_r001606_0_2);
  __CPROVER_assume(sec_r001606_6_1 != sec_r001606_6_2);
  __CPROVER_assume(sec_r001606_11_1 != sec_r001606_11_2);
  __CPROVER_assume(pub_r001606_1_1 == pub_r001606_1_2);
  __CPROVER_assume(pub_r001606_15_1 == pub_r001606_15_2);
  __CPROVER_assume(sec_r001606_16_1 != sec_r001606_16_2);
  __CPROVER_assume(pub_r001606_13_1 == pub_r001606_13_2);
  __CPROVER_assume(pub_r001606_0_1 == pub_r001606_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.facility == st_var_2_2.facility);
  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.signature == st_var_2_2.signature);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.coord_z == st_var_3_2.coord_z);
  assert(st_var_3_1.norm_sq == st_var_3_2.norm_sq);
  assert(st_var_3_1.coord_x == st_var_3_2.coord_x);
  assert(st_var_3_1.heading == st_var_3_2.heading);
  assert(st_var_3_1.coord_y == st_var_3_2.coord_y);
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
}


