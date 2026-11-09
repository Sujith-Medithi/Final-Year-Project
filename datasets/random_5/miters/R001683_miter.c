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
struct EventLog_R001683_8313_0
{
  int code;
  int seq;
  int timestamp;
  int severity;
  int signature;
  int facility;
  int buffer[3];
};
struct DeviceConfig_R001683_8313_1
{
  int timeout;
  int stop_bits;
  short port;
  int parity;
  int id;
  int baud_rate;
  int buffer[3];
};
struct Transaction_R001683_8313_2
{
  int fee;
  int balance;
  short status;
  int buffer[3];
};
struct MatrixBlock_R001683_8313_3
{
  short scale;
  unsigned char trace;
  short density;
  int stride;
  int determinant;
  int buffer[3];
};
union ColorPixel_R001683_8313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001683_8313_1
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
void fn_R001683_8313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st_1 = {0};
  struct Transaction_R001683_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int anchor_41_1 = 0;
  int anchor_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_41_1 = ((anchor_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_41_2 = ((anchor_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_41_1) & 127;
    acc_2 = (acc_2 + anchor_41_2) & 127;
  }

  int index_reg_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_60_1 > 42)
  {
    acc_1 = ((acc_1 + (index_reg_60_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_60_2 > 42)
  {
    acc_2 = ((acc_2 + (index_reg_60_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_42_1)
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

  switch (tracker_42_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_41_1 == anchor_41_2);
  assert(index_reg_60_1 == index_reg_60_2);
  assert(tracker_42_1 == tracker_42_2);
}

int fn_R001683_8313_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int anchor_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_41 = ((anchor_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_41) & 127;
  }

  int index_reg_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_60 > 42)
  {
    acc = ((acc + (index_reg_60 * 2)) + 5) & 127;
    aux ^= index_reg_60 & 15;
  }
  else
  {
    acc = ((acc - index_reg_60) + 11) & 127;
    aux += 3;
  }
  int tracker_42 = (aux + st.buffer[1]) & 3;
  switch (tracker_42)
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

void fn_R001683_8313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st_1 = {0};
  struct Transaction_R001683_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int checksum_34_1 = 0;
  int checksum_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_34_1 = ((checksum_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_34_2 = ((checksum_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_34_1) & 127;
    acc_2 = (acc_2 + checksum_34_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_41_1)
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

  switch (delta_41_2)
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

  int segment_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_51_1 > 27)
  {
    acc_1 = ((acc_1 + (segment_51_1 * 2)) + 5) & 127;
    aux_1 ^= segment_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_51_2 > 27)
  {
    acc_2 = ((acc_2 + (segment_51_2 * 2)) + 5) & 127;
    aux_2 ^= segment_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_34_1 == checksum_34_2);
  assert(delta_41_1 == delta_41_2);
  assert(segment_51_1 == segment_51_2);
}

int fn_R001683_8313_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int checksum_34 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_34 = ((checksum_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_34) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_41 = (aux + st.buffer[1]) & 3;
  switch (delta_41)
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

  int segment_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_51 > 27)
  {
    acc = ((acc + (segment_51 * 2)) + 5) & 127;
    aux ^= segment_51 & 15;
  }
  else
  {
    acc = ((acc - segment_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001683_8313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st_1 = {0};
  struct Transaction_R001683_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int accumulator_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_86_1)
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

  switch (accumulator_86_2)
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

  int checksum_90_1 = 0;
  int checksum_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_90_1 = ((checksum_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_90_2 = ((checksum_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_90_1) & 127;
    acc_2 = (acc_2 + checksum_90_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_83_1 > 22)
  {
    acc_1 = ((acc_1 + (index_reg_83_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_83_2 > 22)
  {
    acc_2 = ((acc_2 + (index_reg_83_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_86_1 == accumulator_86_2);
  assert(checksum_90_1 == checksum_90_2);
  assert(index_reg_83_1 == index_reg_83_2);
}

int fn_R001683_8313_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int accumulator_86 = (aux + st.buffer[1]) & 3;
  switch (accumulator_86)
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

  int checksum_90 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_90 = ((checksum_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_90) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_83 > 22)
  {
    acc = ((acc + (index_reg_83 * 2)) + 5) & 127;
    aux ^= index_reg_83 & 15;
  }
  else
  {
    acc = ((acc - index_reg_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001683_8313_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st_1 = {0};
  struct Transaction_R001683_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quantum_18_1 = 0;
  int quantum_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_18_1 = ((quantum_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_18_2 = ((quantum_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_18_1) & 127;
    acc_2 = (acc_2 + quantum_18_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_52_1 = local_arr_1[aux_1 % 3];
  int delta_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_52_2 * 2)) & 127;
  int metric_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_91_1)
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

  switch (metric_91_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_18_1 == quantum_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_52_1 == delta_52_2);
  assert(metric_91_1 == metric_91_2);
}

int fn_R001683_8313_3(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quantum_18 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_18 = ((quantum_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_18) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int delta_52 = local_arr[aux % 3];
  acc = (acc + (delta_52 * 2)) & 127;
  int metric_91 = (aux + st.buffer[1]) & 3;
  switch (metric_91)
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

void fn_R001683_8313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001683_8313_0 st_1 = {0};
  struct EventLog_R001683_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int damping_46_1 = 0;
  int damping_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_46_1 = ((damping_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_46_2 = ((damping_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_46_1) & 127;
    acc_2 = (acc_2 + damping_46_2) & 127;
  }

  int residue_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_17_1)
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

  switch (residue_17_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_56_1 > 19)
  {
    acc_1 = ((acc_1 + (threshold_56_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_56_2 > 19)
  {
    acc_2 = ((acc_2 + (threshold_56_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_46_1 == damping_46_2);
  assert(residue_17_1 == residue_17_2);
  assert(threshold_56_1 == threshold_56_2);
}

int fn_R001683_8313_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001683_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int damping_46 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_46 = ((damping_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_46) & 127;
  }

  int residue_17 = (aux + st.buffer[1]) & 3;
  switch (residue_17)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_56 > 19)
  {
    acc = ((acc + (threshold_56 * 2)) + 5) & 127;
    aux ^= threshold_56 & 15;
  }
  else
  {
    acc = ((acc - threshold_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001683_8313_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st_1 = {0};
  struct Transaction_R001683_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int vector_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_75_1) & 63;
  aux_2 = (aux_2 + vector_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_26_1 = 0;
  int scale_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_26_1 = ((scale_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_26_2 = ((scale_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_26_1) & 127;
    acc_2 = (acc_2 + scale_26_2) & 127;
  }

  int stride_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_99_1)
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

  switch (stride_99_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_75_1 == vector_75_2);
  assert(scale_26_1 == scale_26_2);
  assert(stride_99_1 == stride_99_2);
}

int fn_R001683_8313_5(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int vector_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_75) & 63;
  acc ^= aux;
  int scale_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_26 = ((scale_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_26) & 127;
  }

  int stride_99 = (aux + st.buffer[1]) & 3;
  switch (stride_99)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001683_8313_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001683_8313_3 st_1 = {0};
  struct MatrixBlock_R001683_8313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int stride_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_98_1) & 63;
  aux_2 = (aux_2 + stride_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_41_1 = 0;
  int parity_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_41_1 = ((parity_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_41_2 = ((parity_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_41_1) & 127;
    acc_2 = (acc_2 + parity_41_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_98_1 == stride_98_2);
  assert(parity_41_1 == parity_41_2);
}

int fn_R001683_8313_6(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001683_8313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int stride_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_98) & 63;
  acc ^= aux;
  int parity_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_41 = ((parity_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_41) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001683_8313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001683_8313_3 st_1 = {0};
  struct MatrixBlock_R001683_8313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int phase_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_28_1) & 63;
  aux_2 = (aux_2 + phase_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_69_1 = 0;
  int residue_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_69_1 = ((residue_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_69_2 = ((residue_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_69_1) & 127;
    acc_2 = (acc_2 + residue_69_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_47_1 = local_arr_1[aux_1 % 3];
  int window_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_47_2 * 2)) & 127;
  int index_reg_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_92_1)
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

  switch (index_reg_92_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_28_1 == phase_28_2);
  assert(residue_69_1 == residue_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_47_1 == window_47_2);
  assert(index_reg_92_1 == index_reg_92_2);
}

int fn_R001683_8313_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001683_8313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int phase_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_28) & 63;
  acc ^= aux;
  int residue_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_69 = ((residue_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_69) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int window_47 = local_arr[aux % 3];
  acc = (acc + (window_47 * 2)) & 127;
  int index_reg_92 = (aux + st.buffer[1]) & 3;
  switch (index_reg_92)
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

void fn_R001683_8313_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st_1 = {0};
  struct Transaction_R001683_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int segment_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_17_1 > 27)
  {
    acc_1 = ((acc_1 + (segment_17_1 * 2)) + 5) & 127;
    aux_1 ^= segment_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_17_2 > 27)
  {
    acc_2 = ((acc_2 + (segment_17_2 * 2)) + 5) & 127;
    aux_2 ^= segment_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_36_1 = 0;
  int vector_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_36_1 = ((vector_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_36_2 = ((vector_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_36_1) & 127;
    acc_2 = (acc_2 + vector_36_2) & 127;
  }

  int accumulator_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_34_1)
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

  switch (accumulator_34_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_17_1 == segment_17_2);
  assert(vector_36_1 == vector_36_2);
  assert(accumulator_34_1 == accumulator_34_2);
}

int fn_R001683_8313_8(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int segment_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_17 > 27)
  {
    acc = ((acc + (segment_17 * 2)) + 5) & 127;
    aux ^= segment_17 & 15;
  }
  else
  {
    acc = ((acc - segment_17) + 11) & 127;
    aux += 3;
  }
  int vector_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_36 = ((vector_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_36) & 127;
  }

  int accumulator_34 = (aux + st.buffer[1]) & 3;
  switch (accumulator_34)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001683_8313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001683_8313_1 st_1 = {0};
  struct DeviceConfig_R001683_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int weight_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_79_1)
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

  switch (weight_79_2)
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

  int mask_16_1 = 0;
  int mask_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_16_1 = ((mask_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_16_2 = ((mask_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_16_1) & 127;
    acc_2 = (acc_2 + mask_16_2) & 127;
  }

  int quotient_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_52_1) & 63;
  aux_2 = (aux_2 + quotient_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_80_1 > 21)
  {
    acc_1 = ((acc_1 + (quantum_80_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_80_2 > 21)
  {
    acc_2 = ((acc_2 + (quantum_80_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_79_1 == weight_79_2);
  assert(mask_16_1 == mask_16_2);
  assert(quotient_52_1 == quotient_52_2);
  assert(quantum_80_1 == quantum_80_2);
}

int fn_R001683_8313_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001683_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int weight_79 = (aux + st.buffer[1]) & 3;
  switch (weight_79)
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

  int mask_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_16 = ((mask_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_16) & 127;
  }

  int quotient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_52) & 63;
  acc ^= aux;
  int quantum_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_80 > 21)
  {
    acc = ((acc + (quantum_80 * 2)) + 5) & 127;
    aux ^= quantum_80 & 15;
  }
  else
  {
    acc = ((acc - quantum_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001683_8313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st_1 = {0};
  struct Transaction_R001683_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int stride_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_34_1) & 63;
  aux_2 = (aux_2 + stride_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_14_1)
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

  switch (pivot_14_2)
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

  int stride_48_1 = 0;
  int stride_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_48_1 = ((stride_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_48_2 = ((stride_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_48_1) & 127;
    acc_2 = (acc_2 + stride_48_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_34_1 == stride_34_2);
  assert(pivot_14_1 == pivot_14_2);
  assert(stride_48_1 == stride_48_2);
}

int fn_R001683_8313_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001683_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int stride_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_34) & 63;
  acc ^= aux;
  int pivot_14 = (aux + st.buffer[1]) & 3;
  switch (pivot_14)
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

  int stride_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_48 = ((stride_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_48) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001683_8313_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001683_8313_0 st_1 = {0};
  struct EventLog_R001683_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int index_reg_26_1 = 0;
  int index_reg_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_26_1 = ((index_reg_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_26_2 = ((index_reg_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_26_1) & 127;
    acc_2 = (acc_2 + index_reg_26_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_26_1 == index_reg_26_2);
}

int fn_R001683_8313_11(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001683_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int index_reg_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_26 = ((index_reg_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_26) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001683_8313_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001683_8313_1 st_1 = {0};
  struct DeviceConfig_R001683_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int segment_94_1 = 0;
  int segment_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_94_1 = ((segment_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_94_2 = ((segment_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_94_1) & 127;
    acc_2 = (acc_2 + segment_94_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_54_1 = local_arr_1[aux_1 % 3];
  int checksum_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_94_1 == segment_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_54_1 == checksum_54_2);
}

int fn_R001683_8313_12(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001683_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int segment_94 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_94 = ((segment_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_94) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int checksum_54 = local_arr[aux % 3];
  acc = (acc + (checksum_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001683_8313_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001683_8313_0 st_1 = {0};
  struct EventLog_R001683_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int residue_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_94_1 > 12)
  {
    acc_1 = ((acc_1 + (residue_94_1 * 2)) + 5) & 127;
    aux_1 ^= residue_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_94_2 > 12)
  {
    acc_2 = ((acc_2 + (residue_94_2 * 2)) + 5) & 127;
    aux_2 ^= residue_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_59_1 = local_arr_1[aux_1 % 3];
  int tally_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_94_1 == residue_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_59_1 == tally_59_2);
}

int fn_R001683_8313_13(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001683_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int residue_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_94 > 12)
  {
    acc = ((acc + (residue_94 * 2)) + 5) & 127;
    aux ^= residue_94 & 15;
  }
  else
  {
    acc = ((acc - residue_94) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_59 = local_arr[aux % 3];
  acc = (acc + (tally_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001683_8313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001683_8313_0 st_1 = {0};
  struct EventLog_R001683_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int metric_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_14_1 > 15)
  {
    acc_1 = ((acc_1 + (metric_14_1 * 2)) + 5) & 127;
    aux_1 ^= metric_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_14_2 > 15)
  {
    acc_2 = ((acc_2 + (metric_14_2 * 2)) + 5) & 127;
    aux_2 ^= metric_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_80_1)
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

  switch (tally_80_2)
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

  int margin_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_96_1) & 63;
  aux_2 = (aux_2 + margin_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_14_1 == metric_14_2);
  assert(tally_80_1 == tally_80_2);
  assert(margin_96_1 == margin_96_2);
}

int fn_R001683_8313_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001683_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int metric_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_14 > 15)
  {
    acc = ((acc + (metric_14 * 2)) + 5) & 127;
    aux ^= metric_14 & 15;
  }
  else
  {
    acc = ((acc - metric_14) + 11) & 127;
    aux += 3;
  }
  int tally_80 = (aux + st.buffer[1]) & 3;
  switch (tally_80)
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

  int margin_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001683_8313_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001683_8313_3 st_1 = {0};
  struct MatrixBlock_R001683_8313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_63_1 = local_arr_1[aux_1 % 3];
  int vector_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_63_2 * 2)) & 127;
  int anchor_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_44_1 > 33)
  {
    acc_1 = ((acc_1 + (anchor_44_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_44_2 > 33)
  {
    acc_2 = ((acc_2 + (anchor_44_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_44_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_63_1 == vector_63_2);
  assert(anchor_44_1 == anchor_44_2);
}

int fn_R001683_8313_15(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001683_8313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int vector_63 = local_arr[aux % 3];
  acc = (acc + (vector_63 * 2)) & 127;
  int anchor_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_44 > 33)
  {
    acc = ((acc + (anchor_44 * 2)) + 5) & 127;
    aux ^= anchor_44 & 15;
  }
  else
  {
    acc = ((acc - anchor_44) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001683_0_1;
  int sec_r001683_0_2;
  int sec_r001683_1_1;
  int sec_r001683_1_2;
  int sec_r001683_2_1;
  int sec_r001683_2_2;
  int sec_r001683_3_1;
  int sec_r001683_3_2;
  int sec_r001683_4_1;
  int sec_r001683_4_2;
  int sec_r001683_5_1;
  int sec_r001683_5_2;
  int sec_r001683_6_1;
  int sec_r001683_6_2;
  int sec_r001683_7_1;
  int sec_r001683_7_2;
  int sec_r001683_8_1;
  int sec_r001683_8_2;
  int sec_r001683_9_1;
  int sec_r001683_9_2;
  int sec_r001683_10_1;
  int sec_r001683_10_2;
  int sec_r001683_11_1;
  int sec_r001683_11_2;
  int sec_r001683_12_1;
  int sec_r001683_12_2;
  int sec_r001683_13_1;
  int sec_r001683_13_2;
  int sec_r001683_14_1;
  int sec_r001683_14_2;
  int sec_r001683_15_1;
  int sec_r001683_15_2;
  int sec_r001683_16_1;
  int sec_r001683_16_2;
  int sec_r001683_17_1;
  int sec_r001683_17_2;
  int pub_r001683_0_1;
  int pub_r001683_0_2;
  int pub_r001683_1_1;
  int pub_r001683_1_2;
  int pub_r001683_2_1;
  int pub_r001683_2_2;
  int pub_r001683_3_1;
  int pub_r001683_3_2;
  int pub_r001683_4_1;
  int pub_r001683_4_2;
  int pub_r001683_5_1;
  int pub_r001683_5_2;
  int pub_r001683_6_1;
  int pub_r001683_6_2;
  int pub_r001683_7_1;
  int pub_r001683_7_2;
  int pub_r001683_8_1;
  int pub_r001683_8_2;
  int pub_r001683_9_1;
  int pub_r001683_9_2;
  int pub_r001683_10_1;
  int pub_r001683_10_2;
  int pub_r001683_11_1;
  int pub_r001683_11_2;
  int pub_r001683_12_1;
  int pub_r001683_12_2;
  int pub_r001683_13_1;
  int pub_r001683_13_2;
  int pub_r001683_14_1;
  int pub_r001683_14_2;
  int pub_r001683_15_1;
  int pub_r001683_15_2;
  int pub_r001683_16_1;
  int pub_r001683_16_2;
  int pub_r001683_17_1;
  int pub_r001683_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001683_0_1 >= (-100)) && (pub_r001683_0_1 <= 100));
  __CPROVER_assume((pub_r001683_0_2 >= (-100)) && (pub_r001683_0_2 <= 100));
  __CPROVER_assume((pub_r001683_1_1 >= (-100)) && (pub_r001683_1_1 <= 100));
  __CPROVER_assume((pub_r001683_1_2 >= (-100)) && (pub_r001683_1_2 <= 100));
  __CPROVER_assume((pub_r001683_2_1 >= (-100)) && (pub_r001683_2_1 <= 100));
  __CPROVER_assume((pub_r001683_2_2 >= (-100)) && (pub_r001683_2_2 <= 100));
  __CPROVER_assume((pub_r001683_3_1 >= (-100)) && (pub_r001683_3_1 <= 100));
  __CPROVER_assume((pub_r001683_3_2 >= (-100)) && (pub_r001683_3_2 <= 100));
  __CPROVER_assume((pub_r001683_4_1 >= (-100)) && (pub_r001683_4_1 <= 100));
  __CPROVER_assume((pub_r001683_4_2 >= (-100)) && (pub_r001683_4_2 <= 100));
  __CPROVER_assume((pub_r001683_5_1 >= (-100)) && (pub_r001683_5_1 <= 100));
  __CPROVER_assume((pub_r001683_5_2 >= (-100)) && (pub_r001683_5_2 <= 100));
  __CPROVER_assume((pub_r001683_6_1 >= (-100)) && (pub_r001683_6_1 <= 100));
  __CPROVER_assume((pub_r001683_6_2 >= (-100)) && (pub_r001683_6_2 <= 100));
  __CPROVER_assume((pub_r001683_7_1 >= (-100)) && (pub_r001683_7_1 <= 100));
  __CPROVER_assume((pub_r001683_7_2 >= (-100)) && (pub_r001683_7_2 <= 100));
  __CPROVER_assume((pub_r001683_8_1 >= (-100)) && (pub_r001683_8_1 <= 100));
  __CPROVER_assume((pub_r001683_8_2 >= (-100)) && (pub_r001683_8_2 <= 100));
  __CPROVER_assume((pub_r001683_9_1 >= (-100)) && (pub_r001683_9_1 <= 100));
  __CPROVER_assume((pub_r001683_9_2 >= (-100)) && (pub_r001683_9_2 <= 100));
  __CPROVER_assume((pub_r001683_10_1 >= (-100)) && (pub_r001683_10_1 <= 100));
  __CPROVER_assume((pub_r001683_10_2 >= (-100)) && (pub_r001683_10_2 <= 100));
  __CPROVER_assume((pub_r001683_11_1 >= (-100)) && (pub_r001683_11_1 <= 100));
  __CPROVER_assume((pub_r001683_11_2 >= (-100)) && (pub_r001683_11_2 <= 100));
  __CPROVER_assume((pub_r001683_12_1 >= (-100)) && (pub_r001683_12_1 <= 100));
  __CPROVER_assume((pub_r001683_12_2 >= (-100)) && (pub_r001683_12_2 <= 100));
  __CPROVER_assume((pub_r001683_13_1 >= (-100)) && (pub_r001683_13_1 <= 100));
  __CPROVER_assume((pub_r001683_13_2 >= (-100)) && (pub_r001683_13_2 <= 100));
  __CPROVER_assume((pub_r001683_14_1 >= (-100)) && (pub_r001683_14_1 <= 100));
  __CPROVER_assume((pub_r001683_14_2 >= (-100)) && (pub_r001683_14_2 <= 100));
  __CPROVER_assume((pub_r001683_15_1 >= (-100)) && (pub_r001683_15_1 <= 100));
  __CPROVER_assume((pub_r001683_15_2 >= (-100)) && (pub_r001683_15_2 <= 100));
  __CPROVER_assume((pub_r001683_16_1 >= (-100)) && (pub_r001683_16_1 <= 100));
  __CPROVER_assume((pub_r001683_16_2 >= (-100)) && (pub_r001683_16_2 <= 100));
  __CPROVER_assume((pub_r001683_17_1 >= (-100)) && (pub_r001683_17_1 <= 100));
  __CPROVER_assume((pub_r001683_17_2 >= (-100)) && (pub_r001683_17_2 <= 100));
  __CPROVER_assume((sec_r001683_0_1 >= 0) && (sec_r001683_0_1 <= 255));
  __CPROVER_assume((sec_r001683_0_2 >= 0) && (sec_r001683_0_2 <= 255));
  __CPROVER_assume((sec_r001683_1_1 >= 0) && (sec_r001683_1_1 <= 255));
  __CPROVER_assume((sec_r001683_1_2 >= 0) && (sec_r001683_1_2 <= 255));
  __CPROVER_assume((sec_r001683_2_1 >= 0) && (sec_r001683_2_1 <= 255));
  __CPROVER_assume((sec_r001683_2_2 >= 0) && (sec_r001683_2_2 <= 255));
  __CPROVER_assume((sec_r001683_3_1 >= 0) && (sec_r001683_3_1 <= 255));
  __CPROVER_assume((sec_r001683_3_2 >= 0) && (sec_r001683_3_2 <= 255));
  __CPROVER_assume((sec_r001683_4_1 >= 0) && (sec_r001683_4_1 <= 255));
  __CPROVER_assume((sec_r001683_4_2 >= 0) && (sec_r001683_4_2 <= 255));
  __CPROVER_assume((sec_r001683_5_1 >= 0) && (sec_r001683_5_1 <= 255));
  __CPROVER_assume((sec_r001683_5_2 >= 0) && (sec_r001683_5_2 <= 255));
  __CPROVER_assume((sec_r001683_6_1 >= 0) && (sec_r001683_6_1 <= 255));
  __CPROVER_assume((sec_r001683_6_2 >= 0) && (sec_r001683_6_2 <= 255));
  __CPROVER_assume((sec_r001683_7_1 >= 0) && (sec_r001683_7_1 <= 255));
  __CPROVER_assume((sec_r001683_7_2 >= 0) && (sec_r001683_7_2 <= 255));
  __CPROVER_assume((sec_r001683_8_1 >= 0) && (sec_r001683_8_1 <= 255));
  __CPROVER_assume((sec_r001683_8_2 >= 0) && (sec_r001683_8_2 <= 255));
  __CPROVER_assume((sec_r001683_9_1 >= 0) && (sec_r001683_9_1 <= 255));
  __CPROVER_assume((sec_r001683_9_2 >= 0) && (sec_r001683_9_2 <= 255));
  __CPROVER_assume((sec_r001683_10_1 >= 0) && (sec_r001683_10_1 <= 255));
  __CPROVER_assume((sec_r001683_10_2 >= 0) && (sec_r001683_10_2 <= 255));
  __CPROVER_assume((sec_r001683_11_1 >= 0) && (sec_r001683_11_1 <= 255));
  __CPROVER_assume((sec_r001683_11_2 >= 0) && (sec_r001683_11_2 <= 255));
  __CPROVER_assume((sec_r001683_12_1 >= 0) && (sec_r001683_12_1 <= 255));
  __CPROVER_assume((sec_r001683_12_2 >= 0) && (sec_r001683_12_2 <= 255));
  __CPROVER_assume((sec_r001683_13_1 >= 0) && (sec_r001683_13_1 <= 255));
  __CPROVER_assume((sec_r001683_13_2 >= 0) && (sec_r001683_13_2 <= 255));
  __CPROVER_assume((sec_r001683_14_1 >= 0) && (sec_r001683_14_1 <= 255));
  __CPROVER_assume((sec_r001683_14_2 >= 0) && (sec_r001683_14_2 <= 255));
  __CPROVER_assume((sec_r001683_15_1 >= 0) && (sec_r001683_15_1 <= 255));
  __CPROVER_assume((sec_r001683_15_2 >= 0) && (sec_r001683_15_2 <= 255));
  __CPROVER_assume((sec_r001683_16_1 >= 0) && (sec_r001683_16_1 <= 255));
  __CPROVER_assume((sec_r001683_16_2 >= 0) && (sec_r001683_16_2 <= 255));
  __CPROVER_assume((sec_r001683_17_1 >= 0) && (sec_r001683_17_1 <= 255));
  __CPROVER_assume((sec_r001683_17_2 >= 0) && (sec_r001683_17_2 <= 255));
  struct EventLog_R001683_8313_0 st_var_0_1 = {0};
  struct EventLog_R001683_8313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001683_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001683_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001683_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001683_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001683_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001683_0_2 + 7) & 15;
  struct DeviceConfig_R001683_8313_1 st_var_1_1 = {0};
  struct DeviceConfig_R001683_8313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001683_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001683_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001683_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001683_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001683_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001683_0_2 + 9) & 15;
  struct Transaction_R001683_8313_2 st_var_2_1 = {0};
  struct Transaction_R001683_8313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001683_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001683_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001683_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001683_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001683_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001683_0_2 + 11) & 15;
  struct MatrixBlock_R001683_8313_3 st_var_3_1 = {0};
  struct MatrixBlock_R001683_8313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001683_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001683_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001683_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001683_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001683_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001683_0_2 + 13) & 15;
  union ColorPixel_R001683_8313_0 u_var_1;
  union ColorPixel_R001683_8313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001683_8313_0(sec_r001683_0_1, sec_r001683_1_1, pub_r001683_2_1, pub_r001683_3_1, pub_r001683_4_1);
  int helper_flow_0_2 = fn_R001683_8313_0(sec_r001683_0_2, sec_r001683_1_2, pub_r001683_2_2, pub_r001683_3_2, pub_r001683_4_2);
  fn_R001683_8313_0_2(sec_r001683_0_1, sec_r001683_1_1, pub_r001683_2_1, pub_r001683_3_1, pub_r001683_4_1, sec_r001683_0_2, sec_r001683_1_2, pub_r001683_2_2, pub_r001683_3_2, pub_r001683_4_2);
  int helper_flow_1_1 = fn_R001683_8313_1(sec_r001683_1_1, sec_r001683_2_1, pub_r001683_3_1, pub_r001683_4_1);
  int helper_flow_1_2 = fn_R001683_8313_1(sec_r001683_1_2, sec_r001683_2_2, pub_r001683_3_2, pub_r001683_4_2);
  fn_R001683_8313_1_2(sec_r001683_1_1, sec_r001683_2_1, pub_r001683_3_1, pub_r001683_4_1, sec_r001683_1_2, sec_r001683_2_2, pub_r001683_3_2, pub_r001683_4_2);
  int helper_flow_2_1 = fn_R001683_8313_2(sec_r001683_2_1, sec_r001683_3_1, pub_r001683_4_1, pub_r001683_5_1);
  int helper_flow_2_2 = fn_R001683_8313_2(sec_r001683_2_2, sec_r001683_3_2, pub_r001683_4_2, pub_r001683_5_2);
  fn_R001683_8313_2_2(sec_r001683_2_1, sec_r001683_3_1, pub_r001683_4_1, pub_r001683_5_1, sec_r001683_2_2, sec_r001683_3_2, pub_r001683_4_2, pub_r001683_5_2);
  int helper_flow_3_1 = fn_R001683_8313_3(sec_r001683_3_1, sec_r001683_4_1, pub_r001683_5_1);
  int helper_flow_3_2 = fn_R001683_8313_3(sec_r001683_3_2, sec_r001683_4_2, pub_r001683_5_2);
  fn_R001683_8313_3_2(sec_r001683_3_1, sec_r001683_4_1, pub_r001683_5_1, sec_r001683_3_2, sec_r001683_4_2, pub_r001683_5_2);
  int helper_flow_4_1 = fn_R001683_8313_4(sec_r001683_4_1, sec_r001683_5_1, pub_r001683_6_1, pub_r001683_7_1);
  int helper_flow_4_2 = fn_R001683_8313_4(sec_r001683_4_2, sec_r001683_5_2, pub_r001683_6_2, pub_r001683_7_2);
  fn_R001683_8313_4_2(sec_r001683_4_1, sec_r001683_5_1, pub_r001683_6_1, pub_r001683_7_1, sec_r001683_4_2, sec_r001683_5_2, pub_r001683_6_2, pub_r001683_7_2);
  int helper_flow_5_1 = fn_R001683_8313_5(sec_r001683_5_1, sec_r001683_6_1, pub_r001683_7_1);
  int helper_flow_5_2 = fn_R001683_8313_5(sec_r001683_5_2, sec_r001683_6_2, pub_r001683_7_2);
  fn_R001683_8313_5_2(sec_r001683_5_1, sec_r001683_6_1, pub_r001683_7_1, sec_r001683_5_2, sec_r001683_6_2, pub_r001683_7_2);
  int helper_flow_6_1 = fn_R001683_8313_6(sec_r001683_6_1, sec_r001683_7_1, pub_r001683_8_1);
  int helper_flow_6_2 = fn_R001683_8313_6(sec_r001683_6_2, sec_r001683_7_2, pub_r001683_8_2);
  fn_R001683_8313_6_2(sec_r001683_6_1, sec_r001683_7_1, pub_r001683_8_1, sec_r001683_6_2, sec_r001683_7_2, pub_r001683_8_2);
  int helper_flow_7_1 = fn_R001683_8313_7(sec_r001683_7_1, sec_r001683_8_1, pub_r001683_9_1, pub_r001683_10_1, pub_r001683_11_1);
  int helper_flow_7_2 = fn_R001683_8313_7(sec_r001683_7_2, sec_r001683_8_2, pub_r001683_9_2, pub_r001683_10_2, pub_r001683_11_2);
  fn_R001683_8313_7_2(sec_r001683_7_1, sec_r001683_8_1, pub_r001683_9_1, pub_r001683_10_1, pub_r001683_11_1, sec_r001683_7_2, sec_r001683_8_2, pub_r001683_9_2, pub_r001683_10_2, pub_r001683_11_2);
  int stage_v_0_1 = ((pub_r001683_2_1 * 2) + 42) & 63;
  int stage_v_0_2 = ((pub_r001683_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001683_11_1 * 3) + pub_r001683_12_1) + 4) & 127;
  int stage_v_1_2 = (((sec_r001683_11_2 * 3) + pub_r001683_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001683_14_1 * 2) + 12) & 63;
  int stage_v_2_2 = ((pub_r001683_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001683_14_1 * 2) + 28) & 63;
  int stage_v_3_2 = ((pub_r001683_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001683_17_1 * 2) + 8) & 63;
  int stage_v_4_2 = ((pub_r001683_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((sec_r001683_8_1 * 3) + pub_r001683_13_1) + 3) & 127;
  int stage_v_5_2 = (((sec_r001683_8_2 * 3) + pub_r001683_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = ((pub_r001683_14_1 * 2) + 45) & 63;
  int stage_v_6_2 = ((pub_r001683_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((helper_flow_7_1 * 3) + pub_r001683_3_1) + 45) & 127;
  int stage_v_7_2 = (((helper_flow_7_2 * 3) + pub_r001683_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001683_17_1 * 2) + 48) & 63;
  int stage_v_8_2 = ((pub_r001683_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (((stage_v_1_1 * 3) + pub_r001683_14_1) + 35) & 127;
  int stage_v_9_2 = (((stage_v_1_2 * 3) + pub_r001683_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = ((pub_r001683_9_1 * 2) + 7) & 63;
  int stage_v_10_2 = ((pub_r001683_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((helper_flow_1_1 * 3) + pub_r001683_0_1) + 19) & 127;
  int stage_v_11_2 = (((helper_flow_1_2 * 3) + pub_r001683_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = ((pub_r001683_5_1 * 2) + 11) & 63;
  int stage_v_12_2 = ((pub_r001683_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((sec_r001683_3_1 * 3) + pub_r001683_8_1) + 38) & 127;
  int stage_v_13_2 = (((sec_r001683_3_2 * 3) + pub_r001683_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = ((pub_r001683_16_1 * 2) + 38) & 63;
  int stage_v_14_2 = ((pub_r001683_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((helper_flow_1_1 * 3) + pub_r001683_12_1) + 19) & 127;
  int stage_v_15_2 = (((helper_flow_1_2 * 3) + pub_r001683_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001683_7_1 * 2) + 26) & 63;
  int stage_v_16_2 = ((pub_r001683_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((stage_v_15_1 * 3) + pub_r001683_8_1) + 20) & 127;
  int stage_v_17_2 = (((stage_v_15_2 * 3) + pub_r001683_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001683_17_1 * 2) + 47) & 63;
  int stage_v_18_2 = ((pub_r001683_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001683_5_1 * 2) + 21) & 63;
  int stage_v_19_2 = ((pub_r001683_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((helper_flow_7_1 * 3) + pub_r001683_11_1) + 4) & 127;
  int stage_v_20_2 = (((helper_flow_7_2 * 3) + pub_r001683_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001683_10_1 * 2) + 16) & 63;
  int stage_v_21_2 = ((pub_r001683_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((helper_flow_2_1 * 3) + pub_r001683_14_1) + 45) & 127;
  int stage_v_22_2 = (((helper_flow_2_2 * 3) + pub_r001683_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001683_15_1 * 2) + 33) & 63;
  int stage_v_23_2 = ((pub_r001683_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001683_11_1 * 2) + 12) & 63;
  int stage_v_24_2 = ((pub_r001683_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (((helper_flow_7_1 * 3) + pub_r001683_16_1) + 45) & 127;
  int stage_v_25_2 = (((helper_flow_7_2 * 3) + pub_r001683_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((sec_r001683_13_1 * 3) + pub_r001683_16_1) + 35) & 127;
  int stage_v_26_2 = (((sec_r001683_13_2 * 3) + pub_r001683_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = (((stage_v_5_1 * 3) + pub_r001683_2_1) + 25) & 127;
  int stage_v_27_2 = (((stage_v_5_2 * 3) + pub_r001683_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = ((pub_r001683_6_1 * 2) + 39) & 63;
  int stage_v_28_2 = ((pub_r001683_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((helper_flow_0_1 * 3) + pub_r001683_4_1) + 31) & 127;
  int stage_v_29_2 = (((helper_flow_0_2 * 3) + pub_r001683_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = ((pub_r001683_0_1 * 2) + 43) & 63;
  int stage_v_30_2 = ((pub_r001683_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001683_5_1 * 2) + 37) & 63;
  int stage_v_31_2 = ((pub_r001683_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((sec_r001683_15_1 * 3) + pub_r001683_15_1) + 12) & 127;
  int stage_v_32_2 = (((sec_r001683_15_2 * 3) + pub_r001683_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((sec_r001683_15_1 * 3) + pub_r001683_6_1) + 45) & 127;
  int stage_v_33_2 = (((sec_r001683_15_2 * 3) + pub_r001683_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((sec_r001683_8_1 * 3) + pub_r001683_14_1) + 34) & 127;
  int stage_v_34_2 = (((sec_r001683_8_2 * 3) + pub_r001683_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001683_2_1 * 2) + 9) & 63;
  int stage_v_35_2 = ((pub_r001683_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((helper_flow_6_1 * 3) + pub_r001683_10_1) + 33) & 127;
  int stage_v_36_2 = (((helper_flow_6_2 * 3) + pub_r001683_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = (((stage_v_20_1 * 3) + pub_r001683_12_1) + 10) & 127;
  int stage_v_37_2 = (((stage_v_20_2 * 3) + pub_r001683_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = (((stage_v_9_1 * 3) + pub_r001683_1_1) + 44) & 127;
  int stage_v_38_2 = (((stage_v_9_2 * 3) + pub_r001683_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001683_1_1 * 2) + 9) & 63;
  int stage_v_39_2 = ((pub_r001683_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((stage_v_34_1 * 3) + pub_r001683_9_1) + 3) & 127;
  int stage_v_40_2 = (((stage_v_34_2 * 3) + pub_r001683_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((sec_r001683_5_1 * 3) + pub_r001683_6_1) + 7) & 127;
  int stage_v_41_2 = (((sec_r001683_5_2 * 3) + pub_r001683_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001683_5_1 * 2) + 28) & 63;
  int stage_v_42_2 = ((pub_r001683_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((helper_flow_2_1 * 3) + pub_r001683_7_1) + 17) & 127;
  int stage_v_43_2 = (((helper_flow_2_2 * 3) + pub_r001683_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001683_15_1 * 2) + 20) & 63;
  int stage_v_44_2 = ((pub_r001683_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001683_1_1 * 2) + 36) & 63;
  int stage_v_45_2 = ((pub_r001683_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001683_5_1 * 2) + 48) & 63;
  int stage_v_46_2 = ((pub_r001683_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001683_2_1 * 2) + 23) & 63;
  int stage_v_47_2 = ((pub_r001683_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001683_10_1 * 2) + 21) & 63;
  int stage_v_48_2 = ((pub_r001683_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((sec_r001683_5_1 * 3) + pub_r001683_11_1) + 14) & 127;
  int stage_v_49_2 = (((sec_r001683_5_2 * 3) + pub_r001683_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((stage_v_7_1 * 3) + pub_r001683_14_1) + 40) & 127;
  int stage_v_50_2 = (((stage_v_7_2 * 3) + pub_r001683_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001683_12_1 * 2) + 43) & 63;
  int stage_v_51_2 = ((pub_r001683_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001683_8_1 * 2) + 17) & 63;
  int stage_v_52_2 = ((pub_r001683_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001683_14_1 * 2) + 21) & 63;
  int stage_v_53_2 = ((pub_r001683_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001683_12_1 * 2) + 24) & 63;
  int stage_v_54_2 = ((pub_r001683_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((sec_r001683_8_1 * 3) + pub_r001683_4_1) + 27) & 127;
  int stage_v_55_2 = (((sec_r001683_8_2 * 3) + pub_r001683_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001683_0_1 * 2) + 47) & 63;
  int stage_v_56_2 = ((pub_r001683_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((stage_v_26_1 * 3) + pub_r001683_9_1) + 15) & 127;
  int stage_v_57_2 = (((stage_v_26_2 * 3) + pub_r001683_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = ((pub_r001683_4_1 * 2) + 7) & 63;
  int stage_v_58_2 = ((pub_r001683_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((sec_r001683_1_1 * 3) + pub_r001683_9_1) + 42) & 127;
  int stage_v_59_2 = (((sec_r001683_1_2 * 3) + pub_r001683_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001683_9_1 * 2) + 11) & 63;
  int stage_v_60_2 = ((pub_r001683_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_37_1 * 3) + pub_r001683_3_1) + 12) & 127;
  int stage_v_61_2 = (((stage_v_37_2 * 3) + pub_r001683_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001683_1_1 * 2) + 20) & 63;
  int stage_v_62_2 = ((pub_r001683_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((helper_flow_0_1 * 3) + pub_r001683_2_1) + 21) & 127;
  int stage_v_63_2 = (((helper_flow_0_2 * 3) + pub_r001683_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((helper_flow_0_1 * 3) + pub_r001683_14_1) + 30) & 127;
  int stage_v_64_2 = (((helper_flow_0_2 * 3) + pub_r001683_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((sec_r001683_6_1 * 3) + pub_r001683_10_1) + 40) & 127;
  int stage_v_65_2 = (((sec_r001683_6_2 * 3) + pub_r001683_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001683_5_1 * 2) + 38) & 63;
  int stage_v_66_2 = ((pub_r001683_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001683_13_1 * 2) + 25) & 63;
  int stage_v_67_2 = ((pub_r001683_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((stage_v_63_1 * 3) + pub_r001683_6_1) + 37) & 127;
  int stage_v_68_2 = (((stage_v_63_2 * 3) + pub_r001683_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = (((stage_v_41_1 * 3) + pub_r001683_17_1) + 5) & 127;
  int stage_v_69_2 = (((stage_v_41_2 * 3) + pub_r001683_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((helper_flow_4_1 * 3) + pub_r001683_8_1) + 40) & 127;
  int stage_v_70_2 = (((helper_flow_4_2 * 3) + pub_r001683_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((helper_flow_0_1 * 3) + pub_r001683_9_1) + 27) & 127;
  int stage_v_71_2 = (((helper_flow_0_2 * 3) + pub_r001683_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = (((stage_v_63_1 * 3) + pub_r001683_17_1) + 32) & 127;
  int stage_v_72_2 = (((stage_v_63_2 * 3) + pub_r001683_17_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001683_3_1 * 2) + 11) & 63;
  int stage_v_73_2 = ((pub_r001683_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((stage_v_27_1 * 3) + pub_r001683_0_1) + 3) & 127;
  int stage_v_74_2 = (((stage_v_27_2 * 3) + pub_r001683_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((stage_v_33_1 * 3) + pub_r001683_16_1) + 20) & 127;
  int stage_v_75_2 = (((stage_v_33_2 * 3) + pub_r001683_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((sec_r001683_12_1 * 3) + pub_r001683_9_1) + 19) & 127;
  int stage_v_76_2 = (((sec_r001683_12_2 * 3) + pub_r001683_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = (((sec_r001683_16_1 * 3) + pub_r001683_7_1) + 19) & 127;
  int stage_v_77_2 = (((sec_r001683_16_2 * 3) + pub_r001683_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001683_15_1 * 2) + 50) & 63;
  int stage_v_78_2 = ((pub_r001683_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_71_1 * 3) + pub_r001683_17_1) + 38) & 127;
  int stage_v_79_2 = (((stage_v_71_2 * 3) + pub_r001683_17_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001683_8_1 * 2) + 38) & 63;
  int stage_v_80_2 = ((pub_r001683_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((helper_flow_3_1 * 3) + pub_r001683_12_1) + 29) & 127;
  int stage_v_81_2 = (((helper_flow_3_2 * 3) + pub_r001683_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = ((pub_r001683_5_1 * 2) + 45) & 63;
  int stage_v_82_2 = ((pub_r001683_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001683_17_1 * 2) + 40) & 63;
  int stage_v_83_2 = ((pub_r001683_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((sec_r001683_6_1 * 3) + pub_r001683_7_1) + 20) & 127;
  int stage_v_84_2 = (((sec_r001683_6_2 * 3) + pub_r001683_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001683_16_1 * 2) + 23) & 63;
  int stage_v_85_2 = ((pub_r001683_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((helper_flow_0_1 * 3) + pub_r001683_3_1) + 27) & 127;
  int stage_v_86_2 = (((helper_flow_0_2 * 3) + pub_r001683_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001683_6_1 * 2) + 33) & 63;
  int stage_v_87_2 = ((pub_r001683_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_38_1 * 3) + pub_r001683_12_1) + 13) & 127;
  int stage_v_88_2 = (((stage_v_38_2 * 3) + pub_r001683_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001683_9_1 * 2) + 41) & 63;
  int stage_v_89_2 = ((pub_r001683_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_25_1 * 3) + pub_r001683_8_1) + 42) & 127;
  int stage_v_90_2 = (((stage_v_25_2 * 3) + pub_r001683_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001683_6_1 * 2) + 16) & 63;
  int stage_v_91_2 = ((pub_r001683_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001683_16_1 * 2) + 17) & 63;
  int stage_v_92_2 = ((pub_r001683_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001683_3_1 * 2) + 46) & 63;
  int stage_v_93_2 = ((pub_r001683_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((sec_r001683_2_1 * 3) + pub_r001683_6_1) + 15) & 127;
  int stage_v_94_2 = (((sec_r001683_2_2 * 3) + pub_r001683_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((sec_r001683_0_1 * 3) + pub_r001683_16_1) + 15) & 127;
  int stage_v_95_2 = (((sec_r001683_0_2 * 3) + pub_r001683_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001683_16_1 * 2) + 39) & 63;
  int stage_v_96_2 = ((pub_r001683_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_57_1 * 3) + pub_r001683_10_1) + 29) & 127;
  int stage_v_97_2 = (((stage_v_57_2 * 3) + pub_r001683_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = ((pub_r001683_2_1 * 2) + 13) & 63;
  int stage_v_98_2 = ((pub_r001683_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001683_7_1 * 2) + 44) & 63;
  int stage_v_99_2 = ((pub_r001683_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((stage_v_1_1 * 3) + pub_r001683_7_1) + 12) & 127;
  int stage_v_100_2 = (((stage_v_1_2 * 3) + pub_r001683_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = (((stage_v_70_1 * 3) + pub_r001683_6_1) + 10) & 127;
  int stage_v_101_2 = (((stage_v_70_2 * 3) + pub_r001683_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = (((sec_r001683_1_1 * 3) + pub_r001683_11_1) + 42) & 127;
  int stage_v_102_2 = (((sec_r001683_1_2 * 3) + pub_r001683_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = (((stage_v_32_1 * 3) + pub_r001683_5_1) + 32) & 127;
  int stage_v_103_2 = (((stage_v_32_2 * 3) + pub_r001683_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001683_2_1 * 2) + 34) & 63;
  int stage_v_104_2 = ((pub_r001683_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_29_1 * 3) + pub_r001683_7_1) + 12) & 127;
  int stage_v_105_2 = (((stage_v_29_2 * 3) + pub_r001683_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((helper_flow_7_1 * 3) + pub_r001683_5_1) + 19) & 127;
  int stage_v_106_2 = (((helper_flow_7_2 * 3) + pub_r001683_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001683_4_1 * 2) + 40) & 63;
  int stage_v_107_2 = ((pub_r001683_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001683_4_1 * 2) + 50) & 63;
  int stage_v_108_2 = ((pub_r001683_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_88_1 * 3) + pub_r001683_6_1) + 12) & 127;
  int stage_v_109_2 = (((stage_v_88_2 * 3) + pub_r001683_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((helper_flow_5_1 * 3) + pub_r001683_6_1) + 38) & 127;
  int stage_v_110_2 = (((helper_flow_5_2 * 3) + pub_r001683_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001683_4_1 * 2) + 33) & 63;
  int stage_v_111_2 = ((pub_r001683_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_40_1 * 3) + pub_r001683_3_1) + 9) & 127;
  int stage_v_112_2 = (((stage_v_40_2 * 3) + pub_r001683_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = ((pub_r001683_11_1 * 2) + 48) & 63;
  int stage_v_113_2 = ((pub_r001683_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_59_1 * 3) + pub_r001683_10_1) + 35) & 127;
  int stage_v_114_2 = (((stage_v_59_2 * 3) + pub_r001683_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = ((pub_r001683_1_1 * 2) + 13) & 63;
  int stage_v_115_2 = ((pub_r001683_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001683_4_1 * 2) + 40) & 63;
  int stage_v_116_2 = ((pub_r001683_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((sec_r001683_2_1 * 3) + pub_r001683_7_1) + 7) & 127;
  int stage_v_117_2 = (((sec_r001683_2_2 * 3) + pub_r001683_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = ((pub_r001683_5_1 * 2) + 32) & 63;
  int stage_v_118_2 = ((pub_r001683_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_13_1 * 3) + pub_r001683_3_1) + 6) & 127;
  int stage_v_119_2 = (((stage_v_13_2 * 3) + pub_r001683_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = ((pub_r001683_9_1 * 2) + 41) & 63;
  int stage_v_120_2 = ((pub_r001683_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (((stage_v_76_1 * 3) + pub_r001683_6_1) + 15) & 127;
  int stage_v_121_2 = (((stage_v_76_2 * 3) + pub_r001683_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((sec_r001683_5_1 * 3) + pub_r001683_13_1) + 12) & 127;
  int stage_v_122_2 = (((sec_r001683_5_2 * 3) + pub_r001683_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = ((pub_r001683_9_1 * 2) + 21) & 63;
  int stage_v_123_2 = ((pub_r001683_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((sec_r001683_12_1 * 3) + pub_r001683_0_1) + 42) & 127;
  int stage_v_124_2 = (((sec_r001683_12_2 * 3) + pub_r001683_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001683_0_1 * 2) + 9) & 63;
  int stage_v_125_2 = ((pub_r001683_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((helper_flow_0_1 * 3) + pub_r001683_6_1) + 10) & 127;
  int stage_v_126_2 = (((helper_flow_0_2 * 3) + pub_r001683_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((stage_v_70_1 * 3) + pub_r001683_10_1) + 17) & 127;
  int stage_v_127_2 = (((stage_v_70_2 * 3) + pub_r001683_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_106_1 * 3) + pub_r001683_1_1) + 10) & 127;
  int stage_v_128_2 = (((stage_v_106_2 * 3) + pub_r001683_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_7_1 * 3) + pub_r001683_13_1) + 35) & 127;
  int stage_v_129_2 = (((stage_v_7_2 * 3) + pub_r001683_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001683_9_1 * 2) + 27) & 63;
  int stage_v_130_2 = ((pub_r001683_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001683_3_1 * 2) + 48) & 63;
  int stage_v_131_2 = ((pub_r001683_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((stage_v_103_1 * 3) + pub_r001683_2_1) + 14) & 127;
  int stage_v_132_2 = (((stage_v_103_2 * 3) + pub_r001683_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_97_1 * 3) + pub_r001683_3_1) + 28) & 127;
  int stage_v_133_2 = (((stage_v_97_2 * 3) + pub_r001683_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001683_10_1 * 2) + 36) & 63;
  int stage_v_134_2 = ((pub_r001683_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((stage_v_127_1 * 3) + pub_r001683_3_1) + 39) & 127;
  int stage_v_135_2 = (((stage_v_127_2 * 3) + pub_r001683_3_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((stage_v_17_1 * 3) + pub_r001683_17_1) + 9) & 127;
  int stage_v_136_2 = (((stage_v_17_2 * 3) + pub_r001683_17_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = ((pub_r001683_9_1 * 2) + 25) & 63;
  int stage_v_137_2 = ((pub_r001683_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001683_2_1 * 2) + 30) & 63;
  int stage_v_138_2 = ((pub_r001683_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001683_8_1 * 2) + 11) & 63;
  int stage_v_139_2 = ((pub_r001683_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((sec_r001683_5_1 * 3) + pub_r001683_8_1) + 10) & 127;
  int stage_v_140_2 = (((sec_r001683_5_2 * 3) + pub_r001683_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001683_8_1 * 2) + 45) & 63;
  int stage_v_141_2 = ((pub_r001683_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001683_15_1 * 2) + 42) & 63;
  int stage_v_142_2 = ((pub_r001683_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001683_0_1 * 2) + 33) & 63;
  int stage_v_143_2 = ((pub_r001683_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((stage_v_112_1 * 3) + pub_r001683_3_1) + 6) & 127;
  int stage_v_144_2 = (((stage_v_112_2 * 3) + pub_r001683_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((sec_r001683_5_1 * 3) + pub_r001683_13_1) + 7) & 127;
  int stage_v_145_2 = (((sec_r001683_5_2 * 3) + pub_r001683_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001683_7_1 * 2) + 24) & 63;
  int stage_v_146_2 = ((pub_r001683_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_129_1 * 3) + pub_r001683_16_1) + 14) & 127;
  int stage_v_147_2 = (((stage_v_129_2 * 3) + pub_r001683_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = (((stage_v_128_1 * 3) + pub_r001683_8_1) + 31) & 127;
  int stage_v_148_2 = (((stage_v_128_2 * 3) + pub_r001683_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_86_1 * 3) + pub_r001683_17_1) + 28) & 127;
  int stage_v_149_2 = (((stage_v_86_2 * 3) + pub_r001683_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_84_1 * 3) + pub_r001683_9_1) + 30) & 127;
  int stage_v_150_2 = (((stage_v_84_2 * 3) + pub_r001683_9_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = ((pub_r001683_0_1 * 2) + 32) & 63;
  int stage_v_151_2 = ((pub_r001683_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001683_17_1 * 2) + 13) & 63;
  int stage_v_152_2 = ((pub_r001683_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((helper_flow_5_1 * 3) + pub_r001683_17_1) + 43) & 127;
  int stage_v_153_2 = (((helper_flow_5_2 * 3) + pub_r001683_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((stage_v_121_1 * 3) + pub_r001683_9_1) + 29) & 127;
  int stage_v_154_2 = (((stage_v_121_2 * 3) + pub_r001683_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((sec_r001683_9_1 * 3) + pub_r001683_16_1) + 11) & 127;
  int stage_v_155_2 = (((sec_r001683_9_2 * 3) + pub_r001683_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((stage_v_70_1 * 3) + pub_r001683_6_1) + 18) & 127;
  int stage_v_156_2 = (((stage_v_70_2 * 3) + pub_r001683_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = ((pub_r001683_11_1 * 2) + 38) & 63;
  int stage_v_157_2 = ((pub_r001683_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001683_10_1 * 2) + 39) & 63;
  int stage_v_158_2 = ((pub_r001683_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((stage_v_150_1 * 3) + pub_r001683_11_1) + 36) & 127;
  int stage_v_159_2 = (((stage_v_150_2 * 3) + pub_r001683_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = ((pub_r001683_11_1 * 2) + 37) & 63;
  int stage_v_160_2 = ((pub_r001683_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_114_1 * 3) + pub_r001683_10_1) + 14) & 127;
  int stage_v_161_2 = (((stage_v_114_2 * 3) + pub_r001683_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((stage_v_11_1 * 3) + pub_r001683_12_1) + 26) & 127;
  int stage_v_162_2 = (((stage_v_11_2 * 3) + pub_r001683_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001683_3_1 * 2) + 36) & 63;
  int stage_v_163_2 = ((pub_r001683_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001683_1_1 * 2) + 39) & 63;
  int stage_v_164_2 = ((pub_r001683_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_55_1 * 3) + pub_r001683_16_1) + 34) & 127;
  int stage_v_165_2 = (((stage_v_55_2 * 3) + pub_r001683_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001683_12_1 * 2) + 37) & 63;
  int stage_v_166_2 = ((pub_r001683_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_77_1 * 3) + pub_r001683_15_1) + 44) & 127;
  int stage_v_167_2 = (((stage_v_77_2 * 3) + pub_r001683_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001683_0_1 * 2) + 32) & 63;
  int stage_v_168_2 = ((pub_r001683_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001683_14_1 * 2) + 11) & 63;
  int stage_v_169_2 = ((pub_r001683_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001683_16_1 * 2) + 10) & 63;
  int stage_v_170_2 = ((pub_r001683_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001683_11_1 * 2) + 12) & 63;
  int stage_v_171_2 = ((pub_r001683_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_126_1 * 3) + pub_r001683_2_1) + 14) & 127;
  int stage_v_172_2 = (((stage_v_126_2 * 3) + pub_r001683_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((stage_v_72_1 * 3) + pub_r001683_1_1) + 38) & 127;
  int stage_v_173_2 = (((stage_v_72_2 * 3) + pub_r001683_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = (((stage_v_33_1 * 3) + pub_r001683_15_1) + 35) & 127;
  int stage_v_174_2 = (((stage_v_33_2 * 3) + pub_r001683_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001683_5_1 * 2) + 48) & 63;
  int stage_v_175_2 = ((pub_r001683_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((helper_flow_0_1 * 3) + pub_r001683_12_1) + 4) & 127;
  int stage_v_176_2 = (((helper_flow_0_2 * 3) + pub_r001683_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001683_16_1 * 2) + 8) & 63;
  int stage_v_177_2 = ((pub_r001683_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001683_10_1 * 2) + 15) & 63;
  int stage_v_178_2 = ((pub_r001683_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((stage_v_144_1 * 3) + pub_r001683_17_1) + 44) & 127;
  int stage_v_179_2 = (((stage_v_144_2 * 3) + pub_r001683_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((stage_v_25_1 * 3) + pub_r001683_3_1) + 5) & 127;
  int stage_v_180_2 = (((stage_v_25_2 * 3) + pub_r001683_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001683_8_1 * 2) + 15) & 63;
  int stage_v_181_2 = ((pub_r001683_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001683_3_1 * 2) + 27) & 63;
  int stage_v_182_2 = ((pub_r001683_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_172_1 * 3) + pub_r001683_12_1) + 19) & 127;
  int stage_v_183_2 = (((stage_v_172_2 * 3) + pub_r001683_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((helper_flow_3_1 * 3) + pub_r001683_10_1) + 6) & 127;
  int stage_v_184_2 = (((helper_flow_3_2 * 3) + pub_r001683_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = ((pub_r001683_0_1 * 2) + 30) & 63;
  int stage_v_185_2 = ((pub_r001683_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_94_1 * 3) + pub_r001683_2_1) + 19) & 127;
  int stage_v_186_2 = (((stage_v_94_2 * 3) + pub_r001683_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001683_17_1 * 2) + 16) & 63;
  int stage_v_187_2 = ((pub_r001683_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_186_1 * 3) + pub_r001683_14_1) + 31) & 127;
  int stage_v_188_2 = (((stage_v_186_2 * 3) + pub_r001683_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001683_11_1 * 2) + 37) & 63;
  int stage_v_189_2 = ((pub_r001683_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001683_7_1 * 2) + 50) & 63;
  int stage_v_190_2 = ((pub_r001683_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_86_1 * 3) + pub_r001683_8_1) + 9) & 127;
  int stage_v_191_2 = (((stage_v_86_2 * 3) + pub_r001683_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001683_16_1 * 2) + 13) & 63;
  int stage_v_192_2 = ((pub_r001683_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_97_1 * 3) + pub_r001683_10_1) + 45) & 127;
  int stage_v_193_2 = (((stage_v_97_2 * 3) + pub_r001683_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001683_10_1 * 2) + 13) & 63;
  int stage_v_194_2 = ((pub_r001683_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001683_9_1 * 2) + 46) & 63;
  int stage_v_195_2 = ((pub_r001683_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_13_1 * 3) + pub_r001683_0_1) + 15) & 127;
  int stage_v_196_2 = (((stage_v_13_2 * 3) + pub_r001683_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = (((sec_r001683_7_1 * 3) + pub_r001683_15_1) + 35) & 127;
  int stage_v_197_2 = (((sec_r001683_7_2 * 3) + pub_r001683_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((stage_v_149_1 * 3) + pub_r001683_14_1) + 26) & 127;
  int stage_v_198_2 = (((stage_v_149_2 * 3) + pub_r001683_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((stage_v_184_1 * 3) + pub_r001683_8_1) + 11) & 127;
  int stage_v_199_2 = (((stage_v_184_2 * 3) + pub_r001683_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = (((stage_v_61_1 * 3) + pub_r001683_6_1) + 43) & 127;
  int stage_v_200_2 = (((stage_v_61_2 * 3) + pub_r001683_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = ((pub_r001683_0_1 * 2) + 18) & 63;
  int stage_v_201_2 = ((pub_r001683_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((sec_r001683_5_1 * 3) + pub_r001683_17_1) + 27) & 127;
  int stage_v_202_2 = (((sec_r001683_5_2 * 3) + pub_r001683_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = (((stage_v_40_1 * 3) + pub_r001683_1_1) + 31) & 127;
  int stage_v_203_2 = (((stage_v_40_2 * 3) + pub_r001683_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_26_1 * 3) + pub_r001683_8_1) + 8) & 127;
  int stage_v_204_2 = (((stage_v_26_2 * 3) + pub_r001683_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_34_1 * 3) + pub_r001683_8_1) + 38) & 127;
  int stage_v_205_2 = (((stage_v_34_2 * 3) + pub_r001683_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((helper_flow_6_1 * 3) + pub_r001683_5_1) + 16) & 127;
  int stage_v_206_2 = (((helper_flow_6_2 * 3) + pub_r001683_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = ((pub_r001683_2_1 * 2) + 40) & 63;
  int stage_v_207_2 = ((pub_r001683_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = (((stage_v_144_1 * 3) + pub_r001683_15_1) + 37) & 127;
  int stage_v_208_2 = (((stage_v_144_2 * 3) + pub_r001683_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = (((stage_v_112_1 * 3) + pub_r001683_17_1) + 33) & 127;
  int stage_v_209_2 = (((stage_v_112_2 * 3) + pub_r001683_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = (((stage_v_186_1 * 3) + pub_r001683_8_1) + 6) & 127;
  int stage_v_210_2 = (((stage_v_186_2 * 3) + pub_r001683_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_132_1 * 3) + pub_r001683_6_1) + 9) & 127;
  int stage_v_211_2 = (((stage_v_132_2 * 3) + pub_r001683_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001683_15_1 * 2) + 23) & 63;
  int stage_v_212_2 = ((pub_r001683_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001683_15_1 * 2) + 8) & 63;
  int stage_v_213_2 = ((pub_r001683_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001683_0_1 * 2) + 43) & 63;
  int stage_v_214_2 = ((pub_r001683_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001683_8_1 * 2) + 42) & 63;
  int stage_v_215_2 = ((pub_r001683_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001683_9_1 * 2) + 36) & 63;
  int stage_v_216_2 = ((pub_r001683_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_159_1 * 3) + pub_r001683_3_1) + 34) & 127;
  int stage_v_217_2 = (((stage_v_159_2 * 3) + pub_r001683_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = (((stage_v_119_1 * 3) + pub_r001683_16_1) + 39) & 127;
  int stage_v_218_2 = (((stage_v_119_2 * 3) + pub_r001683_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((stage_v_36_1 * 3) + pub_r001683_10_1) + 35) & 127;
  int stage_v_219_2 = (((stage_v_36_2 * 3) + pub_r001683_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = ((pub_r001683_6_1 * 2) + 43) & 63;
  int stage_v_220_2 = ((pub_r001683_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_161_1 * 3) + pub_r001683_6_1) + 7) & 127;
  int stage_v_221_2 = (((stage_v_161_2 * 3) + pub_r001683_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((helper_flow_6_1 * 3) + pub_r001683_14_1) + 24) & 127;
  int stage_v_222_2 = (((helper_flow_6_2 * 3) + pub_r001683_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = (((sec_r001683_16_1 * 3) + pub_r001683_2_1) + 32) & 127;
  int stage_v_223_2 = (((sec_r001683_16_2 * 3) + pub_r001683_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = ((pub_r001683_2_1 * 2) + 36) & 63;
  int stage_v_224_2 = ((pub_r001683_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_202_1 * 3) + pub_r001683_15_1) + 38) & 127;
  int stage_v_225_2 = (((stage_v_202_2 * 3) + pub_r001683_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((stage_v_209_1 * 3) + pub_r001683_7_1) + 34) & 127;
  int stage_v_226_2 = (((stage_v_209_2 * 3) + pub_r001683_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = ((pub_r001683_14_1 * 2) + 41) & 63;
  int stage_v_227_2 = ((pub_r001683_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001683_10_1 * 2) + 46) & 63;
  int stage_v_228_2 = ((pub_r001683_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_70_1 * 3) + pub_r001683_10_1) + 42) & 127;
  int stage_v_229_2 = (((stage_v_70_2 * 3) + pub_r001683_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001683_1_1 * 2) + 50) & 63;
  int stage_v_230_2 = ((pub_r001683_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((stage_v_202_1 * 3) + pub_r001683_14_1) + 41) & 127;
  int stage_v_231_2 = (((stage_v_202_2 * 3) + pub_r001683_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((stage_v_159_1 * 3) + pub_r001683_12_1) + 16) & 127;
  int stage_v_232_2 = (((stage_v_159_2 * 3) + pub_r001683_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001683_5_1 * 2) + 11) & 63;
  int stage_v_233_2 = ((pub_r001683_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((helper_flow_4_1 * 3) + pub_r001683_14_1) + 17) & 127;
  int stage_v_234_2 = (((helper_flow_4_2 * 3) + pub_r001683_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((sec_r001683_10_1 * 3) + pub_r001683_8_1) + 37) & 127;
  int stage_v_235_2 = (((sec_r001683_10_2 * 3) + pub_r001683_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001683_13_1 * 2) + 23) & 63;
  int stage_v_236_2 = ((pub_r001683_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001683_9_1 * 2) + 24) & 63;
  int stage_v_237_2 = ((pub_r001683_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001683_16_1 * 2) + 33) & 63;
  int stage_v_238_2 = ((pub_r001683_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((helper_flow_7_1 * 3) + pub_r001683_17_1) + 19) & 127;
  int stage_v_239_2 = (((helper_flow_7_2 * 3) + pub_r001683_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = ((pub_r001683_17_1 * 2) + 39) & 63;
  int stage_v_240_2 = ((pub_r001683_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_41_1 * 3) + pub_r001683_9_1) + 25) & 127;
  int stage_v_241_2 = (((stage_v_41_2 * 3) + pub_r001683_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_203_1 * 3) + pub_r001683_3_1) + 8) & 127;
  int stage_v_242_2 = (((stage_v_203_2 * 3) + pub_r001683_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((sec_r001683_9_1 * 3) + pub_r001683_13_1) + 40) & 127;
  int stage_v_243_2 = (((sec_r001683_9_2 * 3) + pub_r001683_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001683_6_1 * 2) + 41) & 63;
  int stage_v_244_2 = ((pub_r001683_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001683_12_1 * 2) + 11) & 63;
  int stage_v_245_2 = ((pub_r001683_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001683_16_1 * 2) + 48) & 63;
  int stage_v_246_2 = ((pub_r001683_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001683_13_1 * 2) + 6) & 63;
  int stage_v_247_2 = ((pub_r001683_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001683_7_1 * 2) + 25) & 63;
  int stage_v_248_2 = ((pub_r001683_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((stage_v_133_1 * 3) + pub_r001683_7_1) + 5) & 127;
  int stage_v_249_2 = (((stage_v_133_2 * 3) + pub_r001683_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_36_1 * 3) + pub_r001683_7_1) + 10) & 127;
  int stage_v_250_2 = (((stage_v_36_2 * 3) + pub_r001683_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_226_1 * 3) + pub_r001683_12_1) + 26) & 127;
  int stage_v_251_2 = (((stage_v_226_2 * 3) + pub_r001683_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((stage_v_249_1 * 3) + pub_r001683_3_1) + 37) & 127;
  int stage_v_252_2 = (((stage_v_249_2 * 3) + pub_r001683_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((sec_r001683_12_1 * 3) + pub_r001683_16_1) + 9) & 127;
  int stage_v_253_2 = (((sec_r001683_12_2 * 3) + pub_r001683_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001683_6_1 * 2) + 40) & 63;
  int stage_v_254_2 = ((pub_r001683_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001683_14_1 * 2) + 35) & 63;
  int stage_v_255_2 = ((pub_r001683_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001683_12_1 * 2) + 42) & 63;
  int stage_v_256_2 = ((pub_r001683_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001683_8_1 * 2) + 14) & 63;
  int stage_v_257_2 = ((pub_r001683_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_155_1 * 3) + pub_r001683_12_1) + 31) & 127;
  int stage_v_258_2 = (((stage_v_155_2 * 3) + pub_r001683_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001683_4_1 * 2) + 35) & 63;
  int stage_v_259_2 = ((pub_r001683_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001683_10_1 * 2) + 40) & 63;
  int stage_v_260_2 = ((pub_r001683_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_197_1 * 3) + pub_r001683_4_1) + 33) & 127;
  int stage_v_261_2 = (((stage_v_197_2 * 3) + pub_r001683_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001683_5_1 * 2) + 32) & 63;
  int stage_v_262_2 = ((pub_r001683_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001683_4_1 * 2) + 47) & 63;
  int stage_v_263_2 = ((pub_r001683_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = (((stage_v_77_1 * 3) + pub_r001683_1_1) + 25) & 127;
  int stage_v_264_2 = (((stage_v_77_2 * 3) + pub_r001683_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = ((pub_r001683_2_1 * 2) + 45) & 63;
  int stage_v_265_2 = ((pub_r001683_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = (((stage_v_34_1 * 3) + pub_r001683_1_1) + 5) & 127;
  int stage_v_266_2 = (((stage_v_34_2 * 3) + pub_r001683_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = ((pub_r001683_0_1 * 2) + 7) & 63;
  int stage_v_267_2 = ((pub_r001683_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((stage_v_209_1 * 3) + pub_r001683_12_1) + 44) & 127;
  int stage_v_268_2 = (((stage_v_209_2 * 3) + pub_r001683_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001683_15_1 * 2) + 11) & 63;
  int stage_v_269_2 = ((pub_r001683_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001683_12_1 * 2) + 41) & 63;
  int stage_v_270_2 = ((pub_r001683_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001683_4_1 * 2) + 45) & 63;
  int stage_v_271_2 = ((pub_r001683_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_135_1 * 3) + pub_r001683_0_1) + 13) & 127;
  int stage_v_272_2 = (((stage_v_135_2 * 3) + pub_r001683_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = ((pub_r001683_3_1 * 2) + 26) & 63;
  int stage_v_273_2 = ((pub_r001683_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = (((stage_v_105_1 * 3) + pub_r001683_14_1) + 28) & 127;
  int stage_v_274_2 = (((stage_v_105_2 * 3) + pub_r001683_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = ((pub_r001683_11_1 * 2) + 7) & 63;
  int stage_v_275_2 = ((pub_r001683_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001683_2_1 * 2) + 50) & 63;
  int stage_v_276_2 = ((pub_r001683_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((sec_r001683_8_1 * 3) + pub_r001683_12_1) + 5) & 127;
  int stage_v_277_2 = (((sec_r001683_8_2 * 3) + pub_r001683_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = ((pub_r001683_17_1 * 2) + 50) & 63;
  int stage_v_278_2 = ((pub_r001683_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = (((stage_v_110_1 * 3) + pub_r001683_11_1) + 33) & 127;
  int stage_v_279_2 = (((stage_v_110_2 * 3) + pub_r001683_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = ((pub_r001683_9_1 * 2) + 40) & 63;
  int stage_v_280_2 = ((pub_r001683_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = (((stage_v_101_1 * 3) + pub_r001683_4_1) + 35) & 127;
  int stage_v_281_2 = (((stage_v_101_2 * 3) + pub_r001683_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = (((stage_v_250_1 * 3) + pub_r001683_15_1) + 23) & 127;
  int stage_v_282_2 = (((stage_v_250_2 * 3) + pub_r001683_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001683_6_1 * 2) + 29) & 63;
  int stage_v_283_2 = ((pub_r001683_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = (((stage_v_129_1 * 3) + pub_r001683_4_1) + 26) & 127;
  int stage_v_284_2 = (((stage_v_129_2 * 3) + pub_r001683_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001683_17_1 * 2) + 47) & 63;
  int stage_v_285_2 = ((pub_r001683_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((stage_v_277_1 * 3) + pub_r001683_15_1) + 25) & 127;
  int stage_v_286_2 = (((stage_v_277_2 * 3) + pub_r001683_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((stage_v_112_1 * 3) + pub_r001683_5_1) + 32) & 127;
  int stage_v_287_2 = (((stage_v_112_2 * 3) + pub_r001683_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001683_1_1 * 2) + 47) & 63;
  int stage_v_288_2 = ((pub_r001683_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_94_1 * 3) + pub_r001683_12_1) + 7) & 127;
  int stage_v_289_2 = (((stage_v_94_2 * 3) + pub_r001683_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = ((pub_r001683_1_1 * 2) + 40) & 63;
  int stage_v_290_2 = ((pub_r001683_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = (((stage_v_258_1 * 3) + pub_r001683_5_1) + 27) & 127;
  int stage_v_291_2 = (((stage_v_258_2 * 3) + pub_r001683_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001683_1_1 * 2) + 48) & 63;
  int stage_v_292_2 = ((pub_r001683_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = (((stage_v_208_1 * 3) + pub_r001683_17_1) + 18) & 127;
  int stage_v_293_2 = (((stage_v_208_2 * 3) + pub_r001683_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = ((pub_r001683_14_1 * 2) + 28) & 63;
  int stage_v_294_2 = ((pub_r001683_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001683_15_1 * 2) + 6) & 63;
  int stage_v_295_2 = ((pub_r001683_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((helper_flow_3_1 * 3) + pub_r001683_16_1) + 22) & 127;
  int stage_v_296_2 = (((helper_flow_3_2 * 3) + pub_r001683_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001683_1_1 * 2) + 18) & 63;
  int stage_v_297_2 = ((pub_r001683_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001683_6_1 * 2) + 36) & 63;
  int stage_v_298_2 = ((pub_r001683_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001683_5_1 * 2) + 7) & 63;
  int stage_v_299_2 = ((pub_r001683_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001683_12_1 * 2) + 17) & 63;
  int stage_v_300_2 = ((pub_r001683_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = (((stage_v_17_1 * 3) + pub_r001683_13_1) + 13) & 127;
  int stage_v_301_2 = (((stage_v_17_2 * 3) + pub_r001683_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001683_4_1 * 2) + 9) & 63;
  int stage_v_302_2 = ((pub_r001683_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001683_15_1 * 2) + 37) & 63;
  int stage_v_303_2 = ((pub_r001683_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = (((helper_flow_7_1 * 3) + pub_r001683_14_1) + 4) & 127;
  int stage_v_304_2 = (((helper_flow_7_2 * 3) + pub_r001683_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001683_9_1 * 2) + 17) & 63;
  int stage_v_305_2 = ((pub_r001683_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_5_1 * 3) + pub_r001683_4_1) + 39) & 127;
  int stage_v_306_2 = (((stage_v_5_2 * 3) + pub_r001683_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = (((stage_v_148_1 * 3) + pub_r001683_7_1) + 24) & 127;
  int stage_v_307_2 = (((stage_v_148_2 * 3) + pub_r001683_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001683_4_1 * 2) + 6) & 63;
  int stage_v_308_2 = ((pub_r001683_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001683_0_1 * 2) + 35) & 63;
  int stage_v_309_2 = ((pub_r001683_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001683_8_1 * 2) + 49) & 63;
  int stage_v_310_2 = ((pub_r001683_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001683_1_1 * 2) + 28) & 63;
  int stage_v_311_2 = ((pub_r001683_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = (((stage_v_22_1 * 3) + pub_r001683_6_1) + 31) & 127;
  int stage_v_312_2 = (((stage_v_22_2 * 3) + pub_r001683_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001683_14_1 * 2) + 11) & 63;
  int stage_v_313_2 = ((pub_r001683_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001683_14_1 * 2) + 10) & 63;
  int stage_v_314_2 = ((pub_r001683_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = (((stage_v_251_1 * 3) + pub_r001683_14_1) + 43) & 127;
  int stage_v_315_2 = (((stage_v_251_2 * 3) + pub_r001683_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_97_1 * 3) + pub_r001683_14_1) + 12) & 127;
  int stage_v_316_2 = (((stage_v_97_2 * 3) + pub_r001683_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_289_1 * 3) + pub_r001683_17_1) + 28) & 127;
  int stage_v_317_2 = (((stage_v_289_2 * 3) + pub_r001683_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001683_6_1 * 2) + 42) & 63;
  int stage_v_318_2 = ((pub_r001683_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001683_8_1 * 2) + 13) & 63;
  int stage_v_319_2 = ((pub_r001683_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001683_10_1 * 2) + 21) & 63;
  int stage_v_320_2 = ((pub_r001683_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((stage_v_217_1 * 3) + pub_r001683_0_1) + 23) & 127;
  int stage_v_321_2 = (((stage_v_217_2 * 3) + pub_r001683_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = ((pub_r001683_12_1 * 2) + 28) & 63;
  int stage_v_322_2 = ((pub_r001683_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001683_9_1 * 2) + 48) & 63;
  int stage_v_323_2 = ((pub_r001683_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((sec_r001683_3_1 * 3) + pub_r001683_14_1) + 21) & 127;
  int stage_v_324_2 = (((sec_r001683_3_2 * 3) + pub_r001683_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_239_1 * 3) + pub_r001683_12_1) + 16) & 127;
  int stage_v_325_2 = (((stage_v_239_2 * 3) + pub_r001683_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_223_1 * 3) + pub_r001683_15_1) + 35) & 127;
  int stage_v_326_2 = (((stage_v_223_2 * 3) + pub_r001683_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = (((stage_v_5_1 * 3) + pub_r001683_17_1) + 38) & 127;
  int stage_v_327_2 = (((stage_v_5_2 * 3) + pub_r001683_17_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = ((pub_r001683_11_1 * 2) + 28) & 63;
  int stage_v_328_2 = ((pub_r001683_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = (((stage_v_205_1 * 3) + pub_r001683_16_1) + 28) & 127;
  int stage_v_329_2 = (((stage_v_205_2 * 3) + pub_r001683_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = (((stage_v_264_1 * 3) + pub_r001683_8_1) + 32) & 127;
  int stage_v_330_2 = (((stage_v_264_2 * 3) + pub_r001683_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001683_11_1 * 2) + 6) & 63;
  int stage_v_331_2 = ((pub_r001683_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001683_7_1 * 2) + 34) & 63;
  int stage_v_332_2 = ((pub_r001683_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001683_12_1 * 2) + 13) & 63;
  int stage_v_333_2 = ((pub_r001683_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_103_1 * 3) + pub_r001683_14_1) + 14) & 127;
  int stage_v_334_2 = (((stage_v_103_2 * 3) + pub_r001683_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((stage_v_174_1 * 3) + pub_r001683_8_1) + 4) & 127;
  int stage_v_335_2 = (((stage_v_174_2 * 3) + pub_r001683_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_315_1 * 3) + pub_r001683_9_1) + 5) & 127;
  int stage_v_336_2 = (((stage_v_315_2 * 3) + pub_r001683_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_65_1 * 3) + pub_r001683_9_1) + 9) & 127;
  int stage_v_337_2 = (((stage_v_65_2 * 3) + pub_r001683_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_274_1 * 3) + pub_r001683_17_1) + 37) & 127;
  int stage_v_338_2 = (((stage_v_274_2 * 3) + pub_r001683_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((stage_v_114_1 * 3) + pub_r001683_3_1) + 6) & 127;
  int stage_v_339_2 = (((stage_v_114_2 * 3) + pub_r001683_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001683_7_1 * 2) + 32) & 63;
  int stage_v_340_2 = ((pub_r001683_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = (((stage_v_188_1 * 3) + pub_r001683_13_1) + 16) & 127;
  int stage_v_341_2 = (((stage_v_188_2 * 3) + pub_r001683_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_304_1 * 3) + pub_r001683_14_1) + 5) & 127;
  int stage_v_342_2 = (((stage_v_304_2 * 3) + pub_r001683_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_106_1 * 3) + pub_r001683_14_1) + 7) & 127;
  int stage_v_343_2 = (((stage_v_106_2 * 3) + pub_r001683_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = ((pub_r001683_14_1 * 2) + 32) & 63;
  int stage_v_344_2 = ((pub_r001683_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((stage_v_57_1 * 3) + pub_r001683_4_1) + 15) & 127;
  int stage_v_345_2 = (((stage_v_57_2 * 3) + pub_r001683_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = (((stage_v_217_1 * 3) + pub_r001683_3_1) + 32) & 127;
  int stage_v_346_2 = (((stage_v_217_2 * 3) + pub_r001683_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001683_15_1 * 2) + 46) & 63;
  int stage_v_347_2 = ((pub_r001683_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((helper_flow_6_1 * 3) + pub_r001683_1_1) + 6) & 127;
  int stage_v_348_2 = (((helper_flow_6_2 * 3) + pub_r001683_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001683_6_1 * 2) + 23) & 63;
  int stage_v_349_2 = ((pub_r001683_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((pub_r001683_13_1 * 2) + 28) & 63;
  int stage_v_350_2 = ((pub_r001683_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = (((stage_v_272_1 * 3) + pub_r001683_13_1) + 36) & 127;
  int stage_v_351_2 = (((stage_v_272_2 * 3) + pub_r001683_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_272_1 * 3) + pub_r001683_15_1) + 3) & 127;
  int stage_v_352_2 = (((stage_v_272_2 * 3) + pub_r001683_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = ((pub_r001683_15_1 * 2) + 14) & 63;
  int stage_v_353_2 = ((pub_r001683_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_205_1 * 3) + pub_r001683_9_1) + 16) & 127;
  int stage_v_354_2 = (((stage_v_205_2 * 3) + pub_r001683_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_136_1 * 3) + pub_r001683_7_1) + 20) & 127;
  int stage_v_355_2 = (((stage_v_136_2 * 3) + pub_r001683_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001683_6_1 * 2) + 17) & 63;
  int stage_v_356_2 = ((pub_r001683_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001683_13_1 * 2) + 29) & 63;
  int stage_v_357_2 = ((pub_r001683_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001683_0_1 * 2) + 25) & 63;
  int stage_v_358_2 = ((pub_r001683_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001683_9_1 * 2) + 23) & 63;
  int stage_v_359_2 = ((pub_r001683_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001683_3_1 * 2) + 21) & 63;
  int stage_v_360_2 = ((pub_r001683_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((stage_v_69_1 * 3) + pub_r001683_6_1) + 45) & 127;
  int stage_v_361_2 = (((stage_v_69_2 * 3) + pub_r001683_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001683_13_1 * 2) + 50) & 63;
  int stage_v_362_2 = ((pub_r001683_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001683_10_1 * 2) + 15) & 63;
  int stage_v_363_2 = ((pub_r001683_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001683_12_1 * 2) + 10) & 63;
  int stage_v_364_2 = ((pub_r001683_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001683_1_1 * 2) + 39) & 63;
  int stage_v_365_2 = ((pub_r001683_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = (((stage_v_149_1 * 3) + pub_r001683_16_1) + 25) & 127;
  int stage_v_366_2 = (((stage_v_149_2 * 3) + pub_r001683_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_15_1 * 3) + pub_r001683_16_1) + 4) & 127;
  int stage_v_367_2 = (((stage_v_15_2 * 3) + pub_r001683_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_126_1 * 3) + pub_r001683_5_1) + 4) & 127;
  int stage_v_368_2 = (((stage_v_126_2 * 3) + pub_r001683_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = ((pub_r001683_7_1 * 2) + 40) & 63;
  int stage_v_369_2 = ((pub_r001683_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = (((stage_v_150_1 * 3) + pub_r001683_16_1) + 19) & 127;
  int stage_v_370_2 = (((stage_v_150_2 * 3) + pub_r001683_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = ((pub_r001683_12_1 * 2) + 22) & 63;
  int stage_v_371_2 = ((pub_r001683_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = (((stage_v_366_1 * 3) + pub_r001683_9_1) + 13) & 127;
  int stage_v_372_2 = (((stage_v_366_2 * 3) + pub_r001683_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = ((pub_r001683_17_1 * 2) + 49) & 63;
  int stage_v_373_2 = ((pub_r001683_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_296_1 * 3) + pub_r001683_9_1) + 37) & 127;
  int stage_v_374_2 = (((stage_v_296_2 * 3) + pub_r001683_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_317_1 * 3) + pub_r001683_15_1) + 38) & 127;
  int stage_v_375_2 = (((stage_v_317_2 * 3) + pub_r001683_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001683_14_1 * 2) + 27) & 63;
  int stage_v_376_2 = ((pub_r001683_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_367_1 * 3) + pub_r001683_9_1) + 24) & 127;
  int stage_v_377_2 = (((stage_v_367_2 * 3) + pub_r001683_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_15_1 * 3) + pub_r001683_4_1) + 11) & 127;
  int stage_v_378_2 = (((stage_v_15_2 * 3) + pub_r001683_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_268_1 * 3) + pub_r001683_11_1) + 26) & 127;
  int stage_v_379_2 = (((stage_v_268_2 * 3) + pub_r001683_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_15_1 * 3) + pub_r001683_7_1) + 10) & 127;
  int stage_v_380_2 = (((stage_v_15_2 * 3) + pub_r001683_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = ((pub_r001683_17_1 * 2) + 48) & 63;
  int stage_v_381_2 = ((pub_r001683_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_335_1 * 3) + pub_r001683_5_1) + 20) & 127;
  int stage_v_382_2 = (((stage_v_335_2 * 3) + pub_r001683_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001683_15_1 * 2) + 28) & 63;
  int stage_v_383_2 = ((pub_r001683_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001683_3_1 * 2) + 45) & 63;
  int stage_v_384_2 = ((pub_r001683_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = (((stage_v_326_1 * 3) + pub_r001683_17_1) + 17) & 127;
  int stage_v_385_2 = (((stage_v_326_2 * 3) + pub_r001683_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = ((pub_r001683_14_1 * 2) + 16) & 63;
  int stage_v_386_2 = ((pub_r001683_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001683_10_1 * 2) + 18) & 63;
  int stage_v_387_2 = ((pub_r001683_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001683_10_1 * 2) + 48) & 63;
  int stage_v_388_2 = ((pub_r001683_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001683_15_1 * 2) + 29) & 63;
  int stage_v_389_2 = ((pub_r001683_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((sec_r001683_6_1 * 3) + pub_r001683_3_1) + 45) & 127;
  int stage_v_390_2 = (((sec_r001683_6_2 * 3) + pub_r001683_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((stage_v_86_1 * 3) + pub_r001683_11_1) + 12) & 127;
  int stage_v_391_2 = (((stage_v_86_2 * 3) + pub_r001683_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_173_1 * 3) + pub_r001683_5_1) + 6) & 127;
  int stage_v_392_2 = (((stage_v_173_2 * 3) + pub_r001683_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = ((pub_r001683_2_1 * 2) + 42) & 63;
  int stage_v_393_2 = ((pub_r001683_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001683_8_1 * 2) + 49) & 63;
  int stage_v_394_2 = ((pub_r001683_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001683_11_1 * 2) + 10) & 63;
  int stage_v_395_2 = ((pub_r001683_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_205_1 * 3) + pub_r001683_4_1) + 4) & 127;
  int stage_v_396_2 = (((stage_v_205_2 * 3) + pub_r001683_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = ((pub_r001683_0_1 * 2) + 48) & 63;
  int stage_v_397_2 = ((pub_r001683_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001683_17_1 * 2) + 25) & 63;
  int stage_v_398_2 = ((pub_r001683_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001683_5_1 * 2) + 23) & 63;
  int stage_v_399_2 = ((pub_r001683_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001683_17_1 * 2) + 49) & 63;
  int stage_v_400_2 = ((pub_r001683_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = (((stage_v_122_1 * 3) + pub_r001683_7_1) + 31) & 127;
  int stage_v_401_2 = (((stage_v_122_2 * 3) + pub_r001683_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = (((stage_v_209_1 * 3) + pub_r001683_15_1) + 13) & 127;
  int stage_v_402_2 = (((stage_v_209_2 * 3) + pub_r001683_15_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = (((stage_v_205_1 * 3) + pub_r001683_10_1) + 20) & 127;
  int stage_v_403_2 = (((stage_v_205_2 * 3) + pub_r001683_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = ((pub_r001683_8_1 * 2) + 46) & 63;
  int stage_v_404_2 = ((pub_r001683_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = (((stage_v_147_1 * 3) + pub_r001683_11_1) + 44) & 127;
  int stage_v_405_2 = (((stage_v_147_2 * 3) + pub_r001683_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = ((pub_r001683_6_1 * 2) + 42) & 63;
  int stage_v_406_2 = ((pub_r001683_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001683_5_1 * 2) + 10) & 63;
  int stage_v_407_2 = ((pub_r001683_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001683_1_1 * 2) + 17) & 63;
  int stage_v_408_2 = ((pub_r001683_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001683_4_1 * 2) + 35) & 63;
  int stage_v_409_2 = ((pub_r001683_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = (((stage_v_122_1 * 3) + pub_r001683_16_1) + 4) & 127;
  int stage_v_410_2 = (((stage_v_122_2 * 3) + pub_r001683_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_410_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_410_2 * 2)) & 255;
  int stage_v_411_1 = (((stage_v_77_1 * 3) + pub_r001683_9_1) + 31) & 127;
  int stage_v_411_2 = (((stage_v_77_2 * 3) + pub_r001683_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = ((pub_r001683_3_1 * 2) + 31) & 63;
  int stage_v_412_2 = ((pub_r001683_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = (((stage_v_249_1 * 3) + pub_r001683_2_1) + 12) & 127;
  int stage_v_413_2 = (((stage_v_249_2 * 3) + pub_r001683_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = ((pub_r001683_1_1 * 2) + 14) & 63;
  int stage_v_414_2 = ((pub_r001683_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_337_1 * 3) + pub_r001683_7_1) + 19) & 127;
  int stage_v_415_2 = (((stage_v_337_2 * 3) + pub_r001683_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = (((stage_v_140_1 * 3) + pub_r001683_9_1) + 12) & 127;
  int stage_v_416_2 = (((stage_v_140_2 * 3) + pub_r001683_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = (((stage_v_63_1 * 3) + pub_r001683_1_1) + 5) & 127;
  int stage_v_417_2 = (((stage_v_63_2 * 3) + pub_r001683_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = (((stage_v_119_1 * 3) + pub_r001683_14_1) + 12) & 127;
  int stage_v_418_2 = (((stage_v_119_2 * 3) + pub_r001683_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_418_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_418_2 * 2)) & 255;
  int stage_v_419_1 = ((pub_r001683_1_1 * 2) + 7) & 63;
  int stage_v_419_2 = ((pub_r001683_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = (((stage_v_79_1 * 3) + pub_r001683_12_1) + 36) & 127;
  int stage_v_420_2 = (((stage_v_79_2 * 3) + pub_r001683_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = (((stage_v_337_1 * 3) + pub_r001683_15_1) + 17) & 127;
  int stage_v_421_2 = (((stage_v_337_2 * 3) + pub_r001683_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = ((pub_r001683_12_1 * 2) + 20) & 63;
  int stage_v_422_2 = ((pub_r001683_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = (((sec_r001683_11_1 * 3) + pub_r001683_10_1) + 41) & 127;
  int stage_v_423_2 = (((sec_r001683_11_2 * 3) + pub_r001683_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_423_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_423_2 * 2)) & 255;
  int stage_v_424_1 = (((stage_v_337_1 * 3) + pub_r001683_2_1) + 13) & 127;
  int stage_v_424_2 = (((stage_v_337_2 * 3) + pub_r001683_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_424_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_424_2 * 2)) & 255;
  int stage_v_425_1 = (((stage_v_147_1 * 3) + pub_r001683_5_1) + 13) & 127;
  int stage_v_425_2 = (((stage_v_147_2 * 3) + pub_r001683_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001683_6_1 * 2) + 11) & 63;
  int stage_v_426_2 = ((pub_r001683_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001683_8_1 * 2) + 35) & 63;
  int stage_v_427_2 = ((pub_r001683_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = (((stage_v_200_1 * 3) + pub_r001683_10_1) + 34) & 127;
  int stage_v_428_2 = (((stage_v_200_2 * 3) + pub_r001683_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = ((pub_r001683_2_1 * 2) + 15) & 63;
  int stage_v_429_2 = ((pub_r001683_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = (((stage_v_417_1 * 3) + pub_r001683_0_1) + 24) & 127;
  int stage_v_430_2 = (((stage_v_417_2 * 3) + pub_r001683_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = (((stage_v_352_1 * 3) + pub_r001683_16_1) + 23) & 127;
  int stage_v_431_2 = (((stage_v_352_2 * 3) + pub_r001683_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = (((stage_v_413_1 * 3) + pub_r001683_11_1) + 19) & 127;
  int stage_v_432_2 = (((stage_v_413_2 * 3) + pub_r001683_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = (((stage_v_413_1 * 3) + pub_r001683_12_1) + 39) & 127;
  int stage_v_433_2 = (((stage_v_413_2 * 3) + pub_r001683_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = (((sec_r001683_17_1 * 3) + pub_r001683_15_1) + 11) & 127;
  int stage_v_434_2 = (((sec_r001683_17_2 * 3) + pub_r001683_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = ((pub_r001683_0_1 * 2) + 29) & 63;
  int stage_v_435_2 = ((pub_r001683_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((stage_v_410_1 * 3) + pub_r001683_1_1) + 41) & 127;
  int stage_v_436_2 = (((stage_v_410_2 * 3) + pub_r001683_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = (((stage_v_431_1 * 3) + pub_r001683_8_1) + 31) & 127;
  int stage_v_437_2 = (((stage_v_431_2 * 3) + pub_r001683_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = (((stage_v_390_1 * 3) + pub_r001683_10_1) + 27) & 127;
  int stage_v_438_2 = (((stage_v_390_2 * 3) + pub_r001683_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_438_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_438_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_438_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_438_2 * 2)) & 255;
  int stage_v_439_1 = (((helper_flow_6_1 * 3) + pub_r001683_15_1) + 23) & 127;
  int stage_v_439_2 = (((helper_flow_6_2 * 3) + pub_r001683_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = (((stage_v_327_1 * 3) + pub_r001683_15_1) + 21) & 127;
  int stage_v_440_2 = (((stage_v_327_2 * 3) + pub_r001683_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = (((stage_v_368_1 * 3) + pub_r001683_10_1) + 36) & 127;
  int stage_v_441_2 = (((stage_v_368_2 * 3) + pub_r001683_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_441_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_441_2 * 2)) & 255;
  int stage_v_442_1 = (((helper_flow_6_1 * 3) + pub_r001683_0_1) + 31) & 127;
  int stage_v_442_2 = (((helper_flow_6_2 * 3) + pub_r001683_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = ((pub_r001683_12_1 * 2) + 25) & 63;
  int stage_v_443_2 = ((pub_r001683_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001683_6_1 * 2) + 9) & 63;
  int stage_v_444_2 = ((pub_r001683_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001683_7_1 * 2) + 14) & 63;
  int stage_v_445_2 = ((pub_r001683_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((pub_r001683_16_1 * 2) + 29) & 63;
  int stage_v_446_2 = ((pub_r001683_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = (((stage_v_204_1 * 3) + pub_r001683_1_1) + 20) & 127;
  int stage_v_447_2 = (((stage_v_204_2 * 3) + pub_r001683_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = ((pub_r001683_16_1 * 2) + 22) & 63;
  int stage_v_448_2 = ((pub_r001683_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = (((stage_v_79_1 * 3) + pub_r001683_17_1) + 8) & 127;
  int stage_v_449_2 = (((stage_v_79_2 * 3) + pub_r001683_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_449_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_449_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_449_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_449_2 * 2)) & 255;
  int stage_v_450_1 = ((pub_r001683_0_1 * 2) + 32) & 63;
  int stage_v_450_2 = ((pub_r001683_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = (((stage_v_439_1 * 3) + pub_r001683_15_1) + 35) & 127;
  int stage_v_451_2 = (((stage_v_439_2 * 3) + pub_r001683_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = (((stage_v_203_1 * 3) + pub_r001683_2_1) + 34) & 127;
  int stage_v_452_2 = (((stage_v_203_2 * 3) + pub_r001683_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_452_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_452_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_452_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_452_2 * 2)) & 255;
  int stage_v_453_1 = (((stage_v_208_1 * 3) + pub_r001683_14_1) + 38) & 127;
  int stage_v_453_2 = (((stage_v_208_2 * 3) + pub_r001683_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_453_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_453_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_453_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_453_2 * 2)) & 255;
  int stage_v_454_1 = ((pub_r001683_2_1 * 2) + 22) & 63;
  int stage_v_454_2 = ((pub_r001683_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = (((stage_v_9_1 * 3) + pub_r001683_13_1) + 34) & 127;
  int stage_v_455_2 = (((stage_v_9_2 * 3) + pub_r001683_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_455_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_455_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_455_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_455_2 * 2)) & 255;
  int stage_v_456_1 = ((pub_r001683_8_1 * 2) + 7) & 63;
  int stage_v_456_2 = ((pub_r001683_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = (((stage_v_367_1 * 3) + pub_r001683_10_1) + 24) & 127;
  int stage_v_457_2 = (((stage_v_367_2 * 3) + pub_r001683_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_457_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_457_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_457_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_457_2 * 2)) & 255;
  int stage_v_458_1 = ((pub_r001683_17_1 * 2) + 34) & 63;
  int stage_v_458_2 = ((pub_r001683_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = (((stage_v_338_1 * 3) + pub_r001683_7_1) + 39) & 127;
  int stage_v_459_2 = (((stage_v_338_2 * 3) + pub_r001683_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = (((stage_v_287_1 * 3) + pub_r001683_14_1) + 34) & 127;
  int stage_v_460_2 = (((stage_v_287_2 * 3) + pub_r001683_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_460_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_460_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_460_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_460_2 * 2)) & 255;
  int stage_v_461_1 = ((pub_r001683_10_1 * 2) + 36) & 63;
  int stage_v_461_2 = ((pub_r001683_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = (((stage_v_321_1 * 3) + pub_r001683_15_1) + 37) & 127;
  int stage_v_462_2 = (((stage_v_321_2 * 3) + pub_r001683_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_462_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_462_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_462_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_462_2 * 2)) & 255;
  int stage_v_463_1 = (((stage_v_317_1 * 3) + pub_r001683_14_1) + 45) & 127;
  int stage_v_463_2 = (((stage_v_317_2 * 3) + pub_r001683_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = ((pub_r001683_16_1 * 2) + 29) & 63;
  int stage_v_464_2 = ((pub_r001683_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = ((pub_r001683_10_1 * 2) + 11) & 63;
  int stage_v_465_2 = ((pub_r001683_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = ((pub_r001683_7_1 * 2) + 24) & 63;
  int stage_v_466_2 = ((pub_r001683_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = (((stage_v_9_1 * 3) + pub_r001683_12_1) + 26) & 127;
  int stage_v_467_2 = (((stage_v_9_2 * 3) + pub_r001683_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_467_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_467_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_467_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_467_2 * 2)) & 255;
  int stage_v_468_1 = ((pub_r001683_8_1 * 2) + 6) & 63;
  int stage_v_468_2 = ((pub_r001683_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = (((stage_v_5_1 * 3) + pub_r001683_4_1) + 4) & 127;
  int stage_v_469_2 = (((stage_v_5_2 * 3) + pub_r001683_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_469_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_469_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_469_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_469_2 * 2)) & 255;
  int stage_v_470_1 = (((stage_v_253_1 * 3) + pub_r001683_4_1) + 42) & 127;
  int stage_v_470_2 = (((stage_v_253_2 * 3) + pub_r001683_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = (((sec_r001683_12_1 * 3) + pub_r001683_14_1) + 19) & 127;
  int stage_v_471_2 = (((sec_r001683_12_2 * 3) + pub_r001683_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_471_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_471_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_471_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_471_2 * 2)) & 255;
  int stage_v_472_1 = (((stage_v_191_1 * 3) + pub_r001683_9_1) + 5) & 127;
  int stage_v_472_2 = (((stage_v_191_2 * 3) + pub_r001683_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_472_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_472_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_472_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_472_2 * 2)) & 255;
  int stage_v_473_1 = ((pub_r001683_12_1 * 2) + 19) & 63;
  int stage_v_473_2 = ((pub_r001683_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = (((stage_v_128_1 * 3) + pub_r001683_2_1) + 43) & 127;
  int stage_v_474_2 = (((stage_v_128_2 * 3) + pub_r001683_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_474_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_474_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_474_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_474_2 * 2)) & 255;
  int stage_v_475_1 = (((sec_r001683_7_1 * 3) + pub_r001683_10_1) + 30) & 127;
  int stage_v_475_2 = (((sec_r001683_7_2 * 3) + pub_r001683_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_475_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_475_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_475_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_475_2 * 2)) & 255;
  int stage_v_476_1 = ((pub_r001683_11_1 * 2) + 44) & 63;
  int stage_v_476_2 = ((pub_r001683_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = (((stage_v_379_1 * 3) + pub_r001683_1_1) + 14) & 127;
  int stage_v_477_2 = (((stage_v_379_2 * 3) + pub_r001683_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  int stage_v_478_1 = ((pub_r001683_7_1 * 2) + 31) & 63;
  int stage_v_478_2 = ((pub_r001683_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = (((stage_v_370_1 * 3) + pub_r001683_8_1) + 37) & 127;
  int stage_v_479_2 = (((stage_v_370_2 * 3) + pub_r001683_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_479_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_479_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_479_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_479_2 * 2)) & 255;
  int stage_v_480_1 = (((stage_v_109_1 * 3) + pub_r001683_2_1) + 38) & 127;
  int stage_v_480_2 = (((stage_v_109_2 * 3) + pub_r001683_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_480_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_480_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_480_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_480_2 * 2)) & 255;
  int stage_v_481_1 = (((stage_v_355_1 * 3) + pub_r001683_2_1) + 45) & 127;
  int stage_v_481_2 = (((stage_v_355_2 * 3) + pub_r001683_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_481_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_481_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_481_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_481_2 * 2)) & 255;
  int stage_v_482_1 = ((pub_r001683_16_1 * 2) + 23) & 63;
  int stage_v_482_2 = ((pub_r001683_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = ((pub_r001683_3_1 * 2) + 30) & 63;
  int stage_v_483_2 = ((pub_r001683_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_483_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_483_2) & 127;
  int stage_v_484_1 = ((pub_r001683_0_1 * 2) + 26) & 63;
  int stage_v_484_2 = ((pub_r001683_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_484_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_484_2) & 127;
  int stage_v_485_1 = (((stage_v_334_1 * 3) + pub_r001683_5_1) + 13) & 127;
  int stage_v_485_2 = (((stage_v_334_2 * 3) + pub_r001683_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_485_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_485_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_485_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_485_2 * 2)) & 255;
  int stage_v_486_1 = ((pub_r001683_2_1 * 2) + 24) & 63;
  int stage_v_486_2 = ((pub_r001683_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_486_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_486_2) & 127;
  int stage_v_487_1 = (((helper_flow_4_1 * 3) + pub_r001683_2_1) + 17) & 127;
  int stage_v_487_2 = (((helper_flow_4_2 * 3) + pub_r001683_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_487_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_487_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_487_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_487_2 * 2)) & 255;
  int stage_v_488_1 = ((pub_r001683_10_1 * 2) + 11) & 63;
  int stage_v_488_2 = ((pub_r001683_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_488_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_488_2) & 127;
  int stage_v_489_1 = ((pub_r001683_8_1 * 2) + 42) & 63;
  int stage_v_489_2 = ((pub_r001683_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_489_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_489_2) & 127;
  int stage_v_490_1 = (((stage_v_449_1 * 3) + pub_r001683_11_1) + 10) & 127;
  int stage_v_490_2 = (((stage_v_449_2 * 3) + pub_r001683_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_490_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_490_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_490_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_490_2 * 2)) & 255;
  int stage_v_491_1 = (((stage_v_304_1 * 3) + pub_r001683_3_1) + 43) & 127;
  int stage_v_491_2 = (((stage_v_304_2 * 3) + pub_r001683_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_491_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_491_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_491_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_491_2 * 2)) & 255;
  int stage_v_492_1 = (((sec_r001683_7_1 * 3) + pub_r001683_17_1) + 6) & 127;
  int stage_v_492_2 = (((sec_r001683_7_2 * 3) + pub_r001683_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_492_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_492_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_492_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_492_2 * 2)) & 255;
  int stage_v_493_1 = (((stage_v_432_1 * 3) + pub_r001683_6_1) + 9) & 127;
  int stage_v_493_2 = (((stage_v_432_2 * 3) + pub_r001683_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_493_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_493_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_493_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_493_2 * 2)) & 255;
  int stage_v_494_1 = (((stage_v_413_1 * 3) + pub_r001683_1_1) + 9) & 127;
  int stage_v_494_2 = (((stage_v_413_2 * 3) + pub_r001683_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_494_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_494_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_494_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_494_2 * 2)) & 255;
  int stage_v_495_1 = ((pub_r001683_0_1 * 2) + 26) & 63;
  int stage_v_495_2 = ((pub_r001683_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_495_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_495_2) & 127;
  int stage_v_496_1 = (((sec_r001683_14_1 * 3) + pub_r001683_2_1) + 32) & 127;
  int stage_v_496_2 = (((sec_r001683_14_2 * 3) + pub_r001683_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_496_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_496_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_496_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_496_2 * 2)) & 255;
  int stage_v_497_1 = ((pub_r001683_13_1 * 2) + 39) & 63;
  int stage_v_497_2 = ((pub_r001683_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_497_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_497_2) & 127;
  int stage_v_498_1 = (((stage_v_343_1 * 3) + pub_r001683_17_1) + 31) & 127;
  int stage_v_498_2 = (((stage_v_343_2 * 3) + pub_r001683_17_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_498_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_498_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_498_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_498_2 * 2)) & 255;
  int stage_v_499_1 = (((stage_v_61_1 * 3) + pub_r001683_17_1) + 41) & 127;
  int stage_v_499_2 = (((stage_v_61_2 * 3) + pub_r001683_17_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_499_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_499_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_499_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_499_2 * 2)) & 255;
  int stage_v_500_1 = ((pub_r001683_6_1 * 2) + 42) & 63;
  int stage_v_500_2 = ((pub_r001683_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_500_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_500_2) & 127;
  int stage_v_501_1 = (((stage_v_200_1 * 3) + pub_r001683_12_1) + 44) & 127;
  int stage_v_501_2 = (((stage_v_200_2 * 3) + pub_r001683_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_501_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_501_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_501_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_501_2 * 2)) & 255;
  int stage_v_502_1 = (((sec_r001683_15_1 * 3) + pub_r001683_16_1) + 25) & 127;
  int stage_v_502_2 = (((sec_r001683_15_2 * 3) + pub_r001683_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_502_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_502_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_502_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_502_2 * 2)) & 255;
  int stage_v_503_1 = ((pub_r001683_17_1 * 2) + 42) & 63;
  int stage_v_503_2 = ((pub_r001683_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_503_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_503_2) & 127;
  int stage_v_504_1 = (((stage_v_38_1 * 3) + pub_r001683_3_1) + 42) & 127;
  int stage_v_504_2 = (((stage_v_38_2 * 3) + pub_r001683_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_504_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_504_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_504_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_504_2 * 2)) & 255;
  int stage_v_505_1 = ((pub_r001683_14_1 * 2) + 27) & 63;
  int stage_v_505_2 = ((pub_r001683_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_505_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_505_2) & 127;
  int stage_v_506_1 = (((stage_v_209_1 * 3) + pub_r001683_7_1) + 38) & 127;
  int stage_v_506_2 = (((stage_v_209_2 * 3) + pub_r001683_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_506_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_506_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_506_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_506_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001683_16_1 != sec_r001683_16_2);
  __CPROVER_assume(pub_r001683_9_1 == pub_r001683_9_2);
  __CPROVER_assume(sec_r001683_17_1 != sec_r001683_17_2);
  __CPROVER_assume(sec_r001683_13_1 != sec_r001683_13_2);
  __CPROVER_assume(pub_r001683_3_1 == pub_r001683_3_2);
  __CPROVER_assume(pub_r001683_14_1 == pub_r001683_14_2);
  __CPROVER_assume(sec_r001683_14_1 != sec_r001683_14_2);
  __CPROVER_assume(sec_r001683_0_1 != sec_r001683_0_2);
  __CPROVER_assume(pub_r001683_1_1 == pub_r001683_1_2);
  __CPROVER_assume(pub_r001683_0_1 == pub_r001683_0_2);
  __CPROVER_assume(sec_r001683_8_1 != sec_r001683_8_2);
  __CPROVER_assume(sec_r001683_10_1 != sec_r001683_10_2);
  __CPROVER_assume(pub_r001683_6_1 == pub_r001683_6_2);
  __CPROVER_assume(sec_r001683_1_1 != sec_r001683_1_2);
  __CPROVER_assume(pub_r001683_4_1 == pub_r001683_4_2);
  __CPROVER_assume(sec_r001683_4_1 != sec_r001683_4_2);
  __CPROVER_assume(sec_r001683_5_1 != sec_r001683_5_2);
  __CPROVER_assume(pub_r001683_15_1 == pub_r001683_15_2);
  __CPROVER_assume(pub_r001683_17_1 == pub_r001683_17_2);
  __CPROVER_assume(pub_r001683_8_1 == pub_r001683_8_2);
  __CPROVER_assume(sec_r001683_2_1 != sec_r001683_2_2);
  __CPROVER_assume(sec_r001683_9_1 != sec_r001683_9_2);
  __CPROVER_assume(sec_r001683_3_1 != sec_r001683_3_2);
  __CPROVER_assume(pub_r001683_7_1 == pub_r001683_7_2);
  __CPROVER_assume(pub_r001683_11_1 == pub_r001683_11_2);
  __CPROVER_assume(pub_r001683_16_1 == pub_r001683_16_2);
  __CPROVER_assume(sec_r001683_12_1 != sec_r001683_12_2);
  __CPROVER_assume(sec_r001683_6_1 != sec_r001683_6_2);
  __CPROVER_assume(sec_r001683_11_1 != sec_r001683_11_2);
  __CPROVER_assume(pub_r001683_2_1 == pub_r001683_2_2);
  __CPROVER_assume(sec_r001683_7_1 != sec_r001683_7_2);
  __CPROVER_assume(sec_r001683_15_1 != sec_r001683_15_2);
  __CPROVER_assume(pub_r001683_10_1 == pub_r001683_10_2);
  __CPROVER_assume(pub_r001683_12_1 == pub_r001683_12_2);
  __CPROVER_assume(pub_r001683_13_1 == pub_r001683_13_2);
  __CPROVER_assume(pub_r001683_5_1 == pub_r001683_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.status == st_var_2_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.trace == st_var_3_2.trace);
  assert(st_var_3_1.density == st_var_3_2.density);
  assert(st_var_3_1.stride == st_var_3_2.stride);
  assert(st_var_3_1.determinant == st_var_3_2.determinant);
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
  assert(stage_v_388_1 == stage_v_388_2);
  assert(stage_v_389_1 == stage_v_389_2);
  assert(stage_v_390_1 == stage_v_390_2);
  assert(stage_v_391_1 == stage_v_391_2);
  assert(stage_v_392_1 == stage_v_392_2);
  assert(stage_v_393_1 == stage_v_393_2);
  assert(stage_v_394_1 == stage_v_394_2);
  assert(stage_v_395_1 == stage_v_395_2);
  assert(stage_v_396_1 == stage_v_396_2);
  assert(stage_v_397_1 == stage_v_397_2);
  assert(stage_v_398_1 == stage_v_398_2);
  assert(stage_v_399_1 == stage_v_399_2);
  assert(stage_v_400_1 == stage_v_400_2);
  assert(stage_v_401_1 == stage_v_401_2);
  assert(stage_v_402_1 == stage_v_402_2);
  assert(stage_v_403_1 == stage_v_403_2);
  assert(stage_v_404_1 == stage_v_404_2);
  assert(stage_v_405_1 == stage_v_405_2);
  assert(stage_v_406_1 == stage_v_406_2);
  assert(stage_v_407_1 == stage_v_407_2);
  assert(stage_v_408_1 == stage_v_408_2);
  assert(stage_v_409_1 == stage_v_409_2);
  assert(stage_v_410_1 == stage_v_410_2);
  assert(stage_v_411_1 == stage_v_411_2);
  assert(stage_v_412_1 == stage_v_412_2);
  assert(stage_v_413_1 == stage_v_413_2);
  assert(stage_v_414_1 == stage_v_414_2);
  assert(stage_v_415_1 == stage_v_415_2);
  assert(stage_v_416_1 == stage_v_416_2);
  assert(stage_v_417_1 == stage_v_417_2);
  assert(stage_v_418_1 == stage_v_418_2);
  assert(stage_v_419_1 == stage_v_419_2);
  assert(stage_v_420_1 == stage_v_420_2);
  assert(stage_v_421_1 == stage_v_421_2);
  assert(stage_v_422_1 == stage_v_422_2);
  assert(stage_v_423_1 == stage_v_423_2);
  assert(stage_v_424_1 == stage_v_424_2);
  assert(stage_v_425_1 == stage_v_425_2);
  assert(stage_v_426_1 == stage_v_426_2);
  assert(stage_v_427_1 == stage_v_427_2);
  assert(stage_v_428_1 == stage_v_428_2);
  assert(stage_v_429_1 == stage_v_429_2);
  assert(stage_v_430_1 == stage_v_430_2);
  assert(stage_v_431_1 == stage_v_431_2);
  assert(stage_v_432_1 == stage_v_432_2);
  assert(stage_v_433_1 == stage_v_433_2);
  assert(stage_v_434_1 == stage_v_434_2);
  assert(stage_v_435_1 == stage_v_435_2);
  assert(stage_v_436_1 == stage_v_436_2);
  assert(stage_v_437_1 == stage_v_437_2);
  assert(stage_v_438_1 == stage_v_438_2);
  assert(stage_v_439_1 == stage_v_439_2);
  assert(stage_v_440_1 == stage_v_440_2);
  assert(stage_v_441_1 == stage_v_441_2);
  assert(stage_v_442_1 == stage_v_442_2);
  assert(stage_v_443_1 == stage_v_443_2);
  assert(stage_v_444_1 == stage_v_444_2);
  assert(stage_v_445_1 == stage_v_445_2);
  assert(stage_v_446_1 == stage_v_446_2);
  assert(stage_v_447_1 == stage_v_447_2);
  assert(stage_v_448_1 == stage_v_448_2);
  assert(stage_v_449_1 == stage_v_449_2);
  assert(stage_v_450_1 == stage_v_450_2);
  assert(stage_v_451_1 == stage_v_451_2);
  assert(stage_v_452_1 == stage_v_452_2);
  assert(stage_v_453_1 == stage_v_453_2);
  assert(stage_v_454_1 == stage_v_454_2);
  assert(stage_v_455_1 == stage_v_455_2);
  assert(stage_v_456_1 == stage_v_456_2);
  assert(stage_v_457_1 == stage_v_457_2);
  assert(stage_v_458_1 == stage_v_458_2);
  assert(stage_v_459_1 == stage_v_459_2);
  assert(stage_v_460_1 == stage_v_460_2);
  assert(stage_v_461_1 == stage_v_461_2);
  assert(stage_v_462_1 == stage_v_462_2);
  assert(stage_v_463_1 == stage_v_463_2);
  assert(stage_v_464_1 == stage_v_464_2);
  assert(stage_v_465_1 == stage_v_465_2);
  assert(stage_v_466_1 == stage_v_466_2);
  assert(stage_v_467_1 == stage_v_467_2);
  assert(stage_v_468_1 == stage_v_468_2);
  assert(stage_v_469_1 == stage_v_469_2);
  assert(stage_v_470_1 == stage_v_470_2);
  assert(stage_v_471_1 == stage_v_471_2);
  assert(stage_v_472_1 == stage_v_472_2);
  assert(stage_v_473_1 == stage_v_473_2);
  assert(stage_v_474_1 == stage_v_474_2);
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
  assert(stage_v_478_1 == stage_v_478_2);
  assert(stage_v_479_1 == stage_v_479_2);
  assert(stage_v_480_1 == stage_v_480_2);
  assert(stage_v_481_1 == stage_v_481_2);
  assert(stage_v_482_1 == stage_v_482_2);
  assert(stage_v_483_1 == stage_v_483_2);
  assert(stage_v_484_1 == stage_v_484_2);
  assert(stage_v_485_1 == stage_v_485_2);
  assert(stage_v_486_1 == stage_v_486_2);
  assert(stage_v_487_1 == stage_v_487_2);
  assert(stage_v_488_1 == stage_v_488_2);
  assert(stage_v_489_1 == stage_v_489_2);
  assert(stage_v_490_1 == stage_v_490_2);
  assert(stage_v_491_1 == stage_v_491_2);
  assert(stage_v_492_1 == stage_v_492_2);
  assert(stage_v_493_1 == stage_v_493_2);
  assert(stage_v_494_1 == stage_v_494_2);
  assert(stage_v_495_1 == stage_v_495_2);
  assert(stage_v_496_1 == stage_v_496_2);
  assert(stage_v_497_1 == stage_v_497_2);
  assert(stage_v_498_1 == stage_v_498_2);
  assert(stage_v_499_1 == stage_v_499_2);
  assert(stage_v_500_1 == stage_v_500_2);
  assert(stage_v_501_1 == stage_v_501_2);
  assert(stage_v_502_1 == stage_v_502_2);
  assert(stage_v_503_1 == stage_v_503_2);
  assert(stage_v_504_1 == stage_v_504_2);
  assert(stage_v_505_1 == stage_v_505_2);
  assert(stage_v_506_1 == stage_v_506_2);
}


