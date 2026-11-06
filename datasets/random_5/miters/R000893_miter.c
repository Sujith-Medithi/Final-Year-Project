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
struct EventLog_R000893_9313_0
{
  int timestamp;
  unsigned char severity;
  int code;
  int seq;
  int buffer[3];
};
struct Transaction_R000893_9313_1
{
  short auth_code;
  short status;
  unsigned char balance;
  unsigned char fee;
  int buffer[3];
};
struct SensorNode_R000893_9313_2
{
  int reading;
  int threshold;
  int offset;
  int status;
  int gain;
  int buffer[3];
};
struct MatrixBlock_R000893_9313_3
{
  unsigned char trace;
  int scale;
  short stride;
  short determinant;
  int buffer[3];
};
union TelemetryField_R000893_9313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000893_9313_1
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
void fn_R000893_9313_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000893_9313_0 st_1 = {0};
  struct EventLog_R000893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_73_1 = local_arr_1[aux_1 % 3];
  int mask_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_73_2 * 2)) & 127;
  int factor_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_66_1 > 10)
  {
    acc_1 = ((acc_1 + (factor_66_1 * 2)) + 5) & 127;
    aux_1 ^= factor_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_66_2 > 10)
  {
    acc_2 = ((acc_2 + (factor_66_2 * 2)) + 5) & 127;
    aux_2 ^= factor_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_73_1 == mask_73_2);
  assert(factor_66_1 == factor_66_2);
}

int fn_R000893_9313_0(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int mask_73 = local_arr[aux % 3];
  acc = (acc + (mask_73 * 2)) & 127;
  int factor_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_66 > 10)
  {
    acc = ((acc + (factor_66 * 2)) + 5) & 127;
    aux ^= factor_66 & 15;
  }
  else
  {
    acc = ((acc - factor_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000893_9313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st_1 = {0};
  struct MatrixBlock_R000893_9313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int window_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_14_1) & 63;
  aux_2 = (aux_2 + window_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_14_1 == window_14_2);
}

int fn_R000893_9313_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int window_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_14) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000893_9313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st_1 = {0};
  struct SensorNode_R000893_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int stride_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_34_1) & 63;
  aux_2 = (aux_2 + stride_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_95_1 > 11)
  {
    acc_1 = ((acc_1 + (coefficient_95_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_95_2 > 11)
  {
    acc_2 = ((acc_2 + (coefficient_95_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_95_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_34_1 == stride_34_2);
  assert(coefficient_95_1 == coefficient_95_2);
}

int fn_R000893_9313_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int stride_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_34) & 63;
  acc ^= aux;
  int coefficient_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_95 > 11)
  {
    acc = ((acc + (coefficient_95 * 2)) + 5) & 127;
    aux ^= coefficient_95 & 15;
  }
  else
  {
    acc = ((acc - coefficient_95) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000893_9313_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st_1 = {0};
  struct SensorNode_R000893_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int checksum_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_75_1 > 50)
  {
    acc_1 = ((acc_1 + (checksum_75_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_75_2 > 50)
  {
    acc_2 = ((acc_2 + (checksum_75_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_75_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_82_1) & 63;
  aux_2 = (aux_2 + damping_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_75_1 == checksum_75_2);
  assert(damping_82_1 == damping_82_2);
}

int fn_R000893_9313_3(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int checksum_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_75 > 50)
  {
    acc = ((acc + (checksum_75 * 2)) + 5) & 127;
    aux ^= checksum_75 & 15;
  }
  else
  {
    acc = ((acc - checksum_75) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000893_9313_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000893_9313_0 st_1 = {0};
  struct EventLog_R000893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int stride_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_96_1) & 63;
  aux_2 = (aux_2 + stride_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_97_1)
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

  switch (index_reg_97_2)
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

  int checksum_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_11_1 > 42)
  {
    acc_1 = ((acc_1 + (checksum_11_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_11_2 > 42)
  {
    acc_2 = ((acc_2 + (checksum_11_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_96_1 == stride_96_2);
  assert(index_reg_97_1 == index_reg_97_2);
  assert(checksum_11_1 == checksum_11_2);
}

int fn_R000893_9313_4(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int stride_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_96) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_97 = (aux + st.buffer[1]) & 3;
  switch (index_reg_97)
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

  int checksum_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_11 > 42)
  {
    acc = ((acc + (checksum_11 * 2)) + 5) & 127;
    aux ^= checksum_11 & 15;
  }
  else
  {
    acc = ((acc - checksum_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000893_9313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st_1 = {0};
  struct SensorNode_R000893_9313_2 st_2 = {0};
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
  int tracker_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_88_1 > 33)
  {
    acc_1 = ((acc_1 + (tracker_88_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_88_2 > 33)
  {
    acc_2 = ((acc_2 + (tracker_88_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_70_1) & 63;
  aux_2 = (aux_2 + pivot_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_60_1)
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

  switch (quantum_60_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_88_1 == tracker_88_2);
  assert(pivot_70_1 == pivot_70_2);
  assert(quantum_60_1 == quantum_60_2);
}

int fn_R000893_9313_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_88 > 33)
  {
    acc = ((acc + (tracker_88 * 2)) + 5) & 127;
    aux ^= tracker_88 & 15;
  }
  else
  {
    acc = ((acc - tracker_88) + 11) & 127;
    aux += 3;
  }
  int pivot_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_70) & 63;
  acc ^= aux;
  int quantum_60 = (aux + st.buffer[1]) & 3;
  switch (quantum_60)
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

void fn_R000893_9313_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st_1 = {0};
  struct MatrixBlock_R000893_9313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_86_1 = local_arr_1[aux_1 % 3];
  int phase_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_86_2 * 2)) & 127;
  int quotient_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_12_1)
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

  switch (quotient_12_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_48_1) & 63;
  aux_2 = (aux_2 + vector_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
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

  assert(phase_86_1 == phase_86_2);
  assert(quotient_12_1 == quotient_12_2);
  assert(vector_48_1 == vector_48_2);
}

int fn_R000893_9313_6(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int phase_86 = local_arr[aux % 3];
  acc = (acc + (phase_86 * 2)) & 127;
  int quotient_12 = (aux + st.buffer[1]) & 3;
  switch (quotient_12)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000893_9313_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000893_9313_1 st_1 = {0};
  struct Transaction_R000893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_48_1 = local_arr_1[aux_1 % 3];
  int residue_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_48_2 * 2)) & 127;
  int delta_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_28_1) & 63;
  aux_2 = (aux_2 + delta_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_13_1 > 26)
  {
    acc_1 = ((acc_1 + (accumulator_13_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_13_2 > 26)
  {
    acc_2 = ((acc_2 + (accumulator_13_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_13_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_48_1 == residue_48_2);
  assert(delta_28_1 == delta_28_2);
  assert(accumulator_13_1 == accumulator_13_2);
}

int fn_R000893_9313_7(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int residue_48 = local_arr[aux % 3];
  acc = (acc + (residue_48 * 2)) & 127;
  int delta_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_28) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_13 > 26)
  {
    acc = ((acc + (accumulator_13 * 2)) + 5) & 127;
    aux ^= accumulator_13 & 15;
  }
  else
  {
    acc = ((acc - accumulator_13) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000893_9313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st_1 = {0};
  struct SensorNode_R000893_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_37_1 > 12)
  {
    acc_1 = ((acc_1 + (sample_37_1 * 2)) + 5) & 127;
    aux_1 ^= sample_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_37_2 > 12)
  {
    acc_2 = ((acc_2 + (sample_37_2 * 2)) + 5) & 127;
    aux_2 ^= sample_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_19_1) & 63;
  aux_2 = (aux_2 + segment_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_14_1)
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

  switch (tracker_14_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_37_1 == sample_37_2);
  assert(segment_19_1 == segment_19_2);
  assert(tracker_14_1 == tracker_14_2);
}

int fn_R000893_9313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_37 > 12)
  {
    acc = ((acc + (sample_37 * 2)) + 5) & 127;
    aux ^= sample_37 & 15;
  }
  else
  {
    acc = ((acc - sample_37) + 11) & 127;
    aux += 3;
  }
  int segment_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_19) & 63;
  acc ^= aux;
  int tracker_14 = (aux + st.buffer[1]) & 3;
  switch (tracker_14)
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

void fn_R000893_9313_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st_1 = {0};
  struct MatrixBlock_R000893_9313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_92_1 = local_arr_1[aux_1 % 3];
  int threshold_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_92_2 * 2)) & 127;
  int factor_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_46_1 > 28)
  {
    acc_1 = ((acc_1 + (factor_46_1 * 2)) + 5) & 127;
    aux_1 ^= factor_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_46_2 > 28)
  {
    acc_2 = ((acc_2 + (factor_46_2 * 2)) + 5) & 127;
    aux_2 ^= factor_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
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

  assert(threshold_92_1 == threshold_92_2);
  assert(factor_46_1 == factor_46_2);
}

int fn_R000893_9313_9(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_92 = local_arr[aux % 3];
  acc = (acc + (threshold_92 * 2)) & 127;
  int factor_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_46 > 28)
  {
    acc = ((acc + (factor_46 * 2)) + 5) & 127;
    aux ^= factor_46 & 15;
  }
  else
  {
    acc = ((acc - factor_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000893_9313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000893_9313_1 st_1 = {0};
  struct Transaction_R000893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int residue_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_65_1)
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

  switch (residue_65_2)
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

  int delta_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_40_1 > 45)
  {
    acc_1 = ((acc_1 + (delta_40_1 * 2)) + 5) & 127;
    aux_1 ^= delta_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_40_2 > 45)
  {
    acc_2 = ((acc_2 + (delta_40_2 * 2)) + 5) & 127;
    aux_2 ^= delta_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_65_1 == residue_65_2);
  assert(delta_40_1 == delta_40_2);
}

int fn_R000893_9313_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int residue_65 = (aux + st.buffer[1]) & 3;
  switch (residue_65)
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

  int delta_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_40 > 45)
  {
    acc = ((acc + (delta_40 * 2)) + 5) & 127;
    aux ^= delta_40 & 15;
  }
  else
  {
    acc = ((acc - delta_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000893_9313_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st_1 = {0};
  struct MatrixBlock_R000893_9313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int threshold_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_97_1 > 42)
  {
    acc_1 = ((acc_1 + (threshold_97_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_97_2 > 42)
  {
    acc_2 = ((acc_2 + (threshold_97_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_90_1 = local_arr_1[aux_1 % 3];
  int tally_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_90_2 * 2)) & 127;
  int pivot_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_67_1) & 63;
  aux_2 = (aux_2 + pivot_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_97_1 == threshold_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_90_1 == tally_90_2);
  assert(pivot_67_1 == pivot_67_2);
}

int fn_R000893_9313_11(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int threshold_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_97 > 42)
  {
    acc = ((acc + (threshold_97 * 2)) + 5) & 127;
    aux ^= threshold_97 & 15;
  }
  else
  {
    acc = ((acc - threshold_97) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_90 = local_arr[aux % 3];
  acc = (acc + (tally_90 * 2)) & 127;
  int pivot_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_67) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000893_9313_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st_1 = {0};
  struct SensorNode_R000893_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_87_1 == tally_87_2);
}

int fn_R000893_9313_12(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000893_9313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000893_9313_1 st_1 = {0};
  struct Transaction_R000893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int scale_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_26_1)
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

  switch (scale_26_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_21_1) & 63;
  aux_2 = (aux_2 + checksum_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_26_1 == scale_26_2);
  assert(checksum_21_1 == checksum_21_2);
}

int fn_R000893_9313_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int scale_26 = (aux + st.buffer[1]) & 3;
  switch (scale_26)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000893_9313_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000893_9313_1 st_1 = {0};
  struct Transaction_R000893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int anchor_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_69_1 > 40)
  {
    acc_1 = ((acc_1 + (anchor_69_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_69_2 > 40)
  {
    acc_2 = ((acc_2 + (anchor_69_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_73_1) & 63;
  aux_2 = (aux_2 + accumulator_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_69_1 == anchor_69_2);
  assert(accumulator_73_1 == accumulator_73_2);
}

int fn_R000893_9313_14(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int anchor_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_69 > 40)
  {
    acc = ((acc + (anchor_69 * 2)) + 5) & 127;
    aux ^= anchor_69 & 15;
  }
  else
  {
    acc = ((acc - anchor_69) + 11) & 127;
    aux += 3;
  }
  int accumulator_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000893_9313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st_1 = {0};
  struct SensorNode_R000893_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int weight_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_16_1)
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

  switch (weight_16_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_73_1) & 63;
  aux_2 = (aux_2 + pivot_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_55_1 = local_arr_1[aux_1 % 3];
  int segment_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_16_1 == weight_16_2);
  assert(pivot_73_1 == pivot_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_55_1 == segment_55_2);
}

int fn_R000893_9313_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int weight_16 = (aux + st.buffer[1]) & 3;
  switch (weight_16)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_73) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_55 = local_arr[aux % 3];
  acc = (acc + (segment_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000893_9313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st_1 = {0};
  struct MatrixBlock_R000893_9313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tally_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_51_1)
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

  switch (tally_51_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_51_1 == tally_51_2);
}

int fn_R000893_9313_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tally_51 = (aux + st.buffer[1]) & 3;
  switch (tally_51)
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
  return (acc + aux) & 255;
}

void fn_R000893_9313_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000893_9313_0 st_1 = {0};
  struct EventLog_R000893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int phase_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_97_1)
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

  switch (phase_97_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_82_1 = local_arr_1[aux_1 % 3];
  int residue_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_82_2 * 2)) & 127;
  int factor_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_13_1) & 63;
  aux_2 = (aux_2 + factor_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_97_1 == phase_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_82_1 == residue_82_2);
  assert(factor_13_1 == factor_13_2);
}

int fn_R000893_9313_17(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int phase_97 = (aux + st.buffer[1]) & 3;
  switch (phase_97)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_82 = local_arr[aux % 3];
  acc = (acc + (residue_82 * 2)) & 127;
  int factor_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000893_9313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st_1 = {0};
  struct MatrixBlock_R000893_9313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int window_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_88_1 > 28)
  {
    acc_1 = ((acc_1 + (window_88_1 * 2)) + 5) & 127;
    aux_1 ^= window_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_88_2 > 28)
  {
    acc_2 = ((acc_2 + (window_88_2 * 2)) + 5) & 127;
    aux_2 ^= window_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_35_1) & 63;
  aux_2 = (aux_2 + metric_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_88_1 == window_88_2);
  assert(metric_35_1 == metric_35_2);
}

int fn_R000893_9313_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int window_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_88 > 28)
  {
    acc = ((acc + (window_88 * 2)) + 5) & 127;
    aux ^= window_88 & 15;
  }
  else
  {
    acc = ((acc - window_88) + 11) & 127;
    aux += 3;
  }
  int metric_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000893_9313_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st_1 = {0};
  struct MatrixBlock_R000893_9313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int metric_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_15_1)
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

  switch (metric_15_2)
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
  int scale_50_1 = local_arr_1[aux_1 % 3];
  int scale_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_50_2 * 2)) & 127;
  int offset_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_89_1 > 50)
  {
    acc_1 = ((acc_1 + (offset_89_1 * 2)) + 5) & 127;
    aux_1 ^= offset_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_89_2 > 50)
  {
    acc_2 = ((acc_2 + (offset_89_2 * 2)) + 5) & 127;
    aux_2 ^= offset_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_15_1 == metric_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_50_1 == scale_50_2);
  assert(offset_89_1 == offset_89_2);
}

int fn_R000893_9313_19(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000893_9313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int metric_15 = (aux + st.buffer[1]) & 3;
  switch (metric_15)
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
  int scale_50 = local_arr[aux % 3];
  acc = (acc + (scale_50 * 2)) & 127;
  int offset_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_89 > 50)
  {
    acc = ((acc + (offset_89 * 2)) + 5) & 127;
    aux ^= offset_89 & 15;
  }
  else
  {
    acc = ((acc - offset_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000893_9313_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000893_9313_1 st_1 = {0};
  struct Transaction_R000893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_28_1 = local_arr_1[aux_1 % 3];
  int scale_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_28_2 * 2)) & 127;
  int mask_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_54_1 > 21)
  {
    acc_1 = ((acc_1 + (mask_54_1 * 2)) + 5) & 127;
    aux_1 ^= mask_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_54_2 > 21)
  {
    acc_2 = ((acc_2 + (mask_54_2 * 2)) + 5) & 127;
    aux_2 ^= mask_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_55_1) & 63;
  aux_2 = (aux_2 + tally_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_59_1)
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

  switch (parity_59_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_28_1 == scale_28_2);
  assert(mask_54_1 == mask_54_2);
  assert(tally_55_1 == tally_55_2);
  assert(parity_59_1 == parity_59_2);
}

int fn_R000893_9313_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int scale_28 = local_arr[aux % 3];
  acc = (acc + (scale_28 * 2)) & 127;
  int mask_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_54 > 21)
  {
    acc = ((acc + (mask_54 * 2)) + 5) & 127;
    aux ^= mask_54 & 15;
  }
  else
  {
    acc = ((acc - mask_54) + 11) & 127;
    aux += 3;
  }
  int tally_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_55) & 63;
  acc ^= aux;
  int parity_59 = (aux + st.buffer[1]) & 3;
  switch (parity_59)
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

void fn_R000893_9313_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000893_9313_0 st_1 = {0};
  struct EventLog_R000893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int index_reg_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_23_1 > 50)
  {
    acc_1 = ((acc_1 + (index_reg_23_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_23_2 > 50)
  {
    acc_2 = ((acc_2 + (index_reg_23_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_17_1) & 63;
  aux_2 = (aux_2 + bound_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_23_1 == index_reg_23_2);
  assert(bound_17_1 == bound_17_2);
}

int fn_R000893_9313_21(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int index_reg_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_23 > 50)
  {
    acc = ((acc + (index_reg_23 * 2)) + 5) & 127;
    aux ^= index_reg_23 & 15;
  }
  else
  {
    acc = ((acc - index_reg_23) + 11) & 127;
    aux += 3;
  }
  int bound_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_17) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000893_9313_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st_1 = {0};
  struct SensorNode_R000893_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int segment_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_87_1) & 63;
  aux_2 = (aux_2 + segment_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_73_1)
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

  switch (offset_73_2)
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

  int margin_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_24_1 > 18)
  {
    acc_1 = ((acc_1 + (margin_24_1 * 2)) + 5) & 127;
    aux_1 ^= margin_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_24_2 > 18)
  {
    acc_2 = ((acc_2 + (margin_24_2 * 2)) + 5) & 127;
    aux_2 ^= margin_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_87_1 == segment_87_2);
  assert(offset_73_1 == offset_73_2);
  assert(margin_24_1 == margin_24_2);
}

int fn_R000893_9313_22(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000893_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int segment_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_87) & 63;
  acc ^= aux;
  int offset_73 = (aux + st.buffer[1]) & 3;
  switch (offset_73)
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

  int margin_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_24 > 18)
  {
    acc = ((acc + (margin_24 * 2)) + 5) & 127;
    aux ^= margin_24 & 15;
  }
  else
  {
    acc = ((acc - margin_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000893_0_1;
  int sec_r000893_0_2;
  int sec_r000893_1_1;
  int sec_r000893_1_2;
  int sec_r000893_2_1;
  int sec_r000893_2_2;
  int sec_r000893_3_1;
  int sec_r000893_3_2;
  int sec_r000893_4_1;
  int sec_r000893_4_2;
  int sec_r000893_5_1;
  int sec_r000893_5_2;
  int sec_r000893_6_1;
  int sec_r000893_6_2;
  int sec_r000893_7_1;
  int sec_r000893_7_2;
  int sec_r000893_8_1;
  int sec_r000893_8_2;
  int sec_r000893_9_1;
  int sec_r000893_9_2;
  int sec_r000893_10_1;
  int sec_r000893_10_2;
  int sec_r000893_11_1;
  int sec_r000893_11_2;
  int sec_r000893_12_1;
  int sec_r000893_12_2;
  int sec_r000893_13_1;
  int sec_r000893_13_2;
  int sec_r000893_14_1;
  int sec_r000893_14_2;
  int sec_r000893_15_1;
  int sec_r000893_15_2;
  int pub_r000893_0_1;
  int pub_r000893_0_2;
  int pub_r000893_1_1;
  int pub_r000893_1_2;
  int pub_r000893_2_1;
  int pub_r000893_2_2;
  int pub_r000893_3_1;
  int pub_r000893_3_2;
  int pub_r000893_4_1;
  int pub_r000893_4_2;
  int pub_r000893_5_1;
  int pub_r000893_5_2;
  int pub_r000893_6_1;
  int pub_r000893_6_2;
  int pub_r000893_7_1;
  int pub_r000893_7_2;
  int pub_r000893_8_1;
  int pub_r000893_8_2;
  int pub_r000893_9_1;
  int pub_r000893_9_2;
  int pub_r000893_10_1;
  int pub_r000893_10_2;
  int pub_r000893_11_1;
  int pub_r000893_11_2;
  int pub_r000893_12_1;
  int pub_r000893_12_2;
  int pub_r000893_13_1;
  int pub_r000893_13_2;
  int pub_r000893_14_1;
  int pub_r000893_14_2;
  int pub_r000893_15_1;
  int pub_r000893_15_2;
  int pub_r000893_16_1;
  int pub_r000893_16_2;
  int pub_r000893_17_1;
  int pub_r000893_17_2;
  int pub_r000893_18_1;
  int pub_r000893_18_2;
  int pub_r000893_19_1;
  int pub_r000893_19_2;
  int pub_r000893_20_1;
  int pub_r000893_20_2;
  int pub_r000893_21_1;
  int pub_r000893_21_2;
  int pub_r000893_22_1;
  int pub_r000893_22_2;
  int pub_r000893_23_1;
  int pub_r000893_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000893_0_1 >= (-100)) && (pub_r000893_0_1 <= 100));
  __CPROVER_assume((pub_r000893_0_2 >= (-100)) && (pub_r000893_0_2 <= 100));
  __CPROVER_assume((pub_r000893_1_1 >= (-100)) && (pub_r000893_1_1 <= 100));
  __CPROVER_assume((pub_r000893_1_2 >= (-100)) && (pub_r000893_1_2 <= 100));
  __CPROVER_assume((pub_r000893_2_1 >= (-100)) && (pub_r000893_2_1 <= 100));
  __CPROVER_assume((pub_r000893_2_2 >= (-100)) && (pub_r000893_2_2 <= 100));
  __CPROVER_assume((pub_r000893_3_1 >= (-100)) && (pub_r000893_3_1 <= 100));
  __CPROVER_assume((pub_r000893_3_2 >= (-100)) && (pub_r000893_3_2 <= 100));
  __CPROVER_assume((pub_r000893_4_1 >= (-100)) && (pub_r000893_4_1 <= 100));
  __CPROVER_assume((pub_r000893_4_2 >= (-100)) && (pub_r000893_4_2 <= 100));
  __CPROVER_assume((pub_r000893_5_1 >= (-100)) && (pub_r000893_5_1 <= 100));
  __CPROVER_assume((pub_r000893_5_2 >= (-100)) && (pub_r000893_5_2 <= 100));
  __CPROVER_assume((pub_r000893_6_1 >= (-100)) && (pub_r000893_6_1 <= 100));
  __CPROVER_assume((pub_r000893_6_2 >= (-100)) && (pub_r000893_6_2 <= 100));
  __CPROVER_assume((pub_r000893_7_1 >= (-100)) && (pub_r000893_7_1 <= 100));
  __CPROVER_assume((pub_r000893_7_2 >= (-100)) && (pub_r000893_7_2 <= 100));
  __CPROVER_assume((pub_r000893_8_1 >= (-100)) && (pub_r000893_8_1 <= 100));
  __CPROVER_assume((pub_r000893_8_2 >= (-100)) && (pub_r000893_8_2 <= 100));
  __CPROVER_assume((pub_r000893_9_1 >= (-100)) && (pub_r000893_9_1 <= 100));
  __CPROVER_assume((pub_r000893_9_2 >= (-100)) && (pub_r000893_9_2 <= 100));
  __CPROVER_assume((pub_r000893_10_1 >= (-100)) && (pub_r000893_10_1 <= 100));
  __CPROVER_assume((pub_r000893_10_2 >= (-100)) && (pub_r000893_10_2 <= 100));
  __CPROVER_assume((pub_r000893_11_1 >= (-100)) && (pub_r000893_11_1 <= 100));
  __CPROVER_assume((pub_r000893_11_2 >= (-100)) && (pub_r000893_11_2 <= 100));
  __CPROVER_assume((pub_r000893_12_1 >= (-100)) && (pub_r000893_12_1 <= 100));
  __CPROVER_assume((pub_r000893_12_2 >= (-100)) && (pub_r000893_12_2 <= 100));
  __CPROVER_assume((pub_r000893_13_1 >= (-100)) && (pub_r000893_13_1 <= 100));
  __CPROVER_assume((pub_r000893_13_2 >= (-100)) && (pub_r000893_13_2 <= 100));
  __CPROVER_assume((pub_r000893_14_1 >= (-100)) && (pub_r000893_14_1 <= 100));
  __CPROVER_assume((pub_r000893_14_2 >= (-100)) && (pub_r000893_14_2 <= 100));
  __CPROVER_assume((pub_r000893_15_1 >= (-100)) && (pub_r000893_15_1 <= 100));
  __CPROVER_assume((pub_r000893_15_2 >= (-100)) && (pub_r000893_15_2 <= 100));
  __CPROVER_assume((pub_r000893_16_1 >= (-100)) && (pub_r000893_16_1 <= 100));
  __CPROVER_assume((pub_r000893_16_2 >= (-100)) && (pub_r000893_16_2 <= 100));
  __CPROVER_assume((pub_r000893_17_1 >= (-100)) && (pub_r000893_17_1 <= 100));
  __CPROVER_assume((pub_r000893_17_2 >= (-100)) && (pub_r000893_17_2 <= 100));
  __CPROVER_assume((pub_r000893_18_1 >= (-100)) && (pub_r000893_18_1 <= 100));
  __CPROVER_assume((pub_r000893_18_2 >= (-100)) && (pub_r000893_18_2 <= 100));
  __CPROVER_assume((pub_r000893_19_1 >= (-100)) && (pub_r000893_19_1 <= 100));
  __CPROVER_assume((pub_r000893_19_2 >= (-100)) && (pub_r000893_19_2 <= 100));
  __CPROVER_assume((pub_r000893_20_1 >= (-100)) && (pub_r000893_20_1 <= 100));
  __CPROVER_assume((pub_r000893_20_2 >= (-100)) && (pub_r000893_20_2 <= 100));
  __CPROVER_assume((pub_r000893_21_1 >= (-100)) && (pub_r000893_21_1 <= 100));
  __CPROVER_assume((pub_r000893_21_2 >= (-100)) && (pub_r000893_21_2 <= 100));
  __CPROVER_assume((pub_r000893_22_1 >= (-100)) && (pub_r000893_22_1 <= 100));
  __CPROVER_assume((pub_r000893_22_2 >= (-100)) && (pub_r000893_22_2 <= 100));
  __CPROVER_assume((pub_r000893_23_1 >= (-100)) && (pub_r000893_23_1 <= 100));
  __CPROVER_assume((pub_r000893_23_2 >= (-100)) && (pub_r000893_23_2 <= 100));
  __CPROVER_assume((sec_r000893_0_1 >= 0) && (sec_r000893_0_1 <= 255));
  __CPROVER_assume((sec_r000893_0_2 >= 0) && (sec_r000893_0_2 <= 255));
  __CPROVER_assume((sec_r000893_1_1 >= 0) && (sec_r000893_1_1 <= 255));
  __CPROVER_assume((sec_r000893_1_2 >= 0) && (sec_r000893_1_2 <= 255));
  __CPROVER_assume((sec_r000893_2_1 >= 0) && (sec_r000893_2_1 <= 255));
  __CPROVER_assume((sec_r000893_2_2 >= 0) && (sec_r000893_2_2 <= 255));
  __CPROVER_assume((sec_r000893_3_1 >= 0) && (sec_r000893_3_1 <= 255));
  __CPROVER_assume((sec_r000893_3_2 >= 0) && (sec_r000893_3_2 <= 255));
  __CPROVER_assume((sec_r000893_4_1 >= 0) && (sec_r000893_4_1 <= 255));
  __CPROVER_assume((sec_r000893_4_2 >= 0) && (sec_r000893_4_2 <= 255));
  __CPROVER_assume((sec_r000893_5_1 >= 0) && (sec_r000893_5_1 <= 255));
  __CPROVER_assume((sec_r000893_5_2 >= 0) && (sec_r000893_5_2 <= 255));
  __CPROVER_assume((sec_r000893_6_1 >= 0) && (sec_r000893_6_1 <= 255));
  __CPROVER_assume((sec_r000893_6_2 >= 0) && (sec_r000893_6_2 <= 255));
  __CPROVER_assume((sec_r000893_7_1 >= 0) && (sec_r000893_7_1 <= 255));
  __CPROVER_assume((sec_r000893_7_2 >= 0) && (sec_r000893_7_2 <= 255));
  __CPROVER_assume((sec_r000893_8_1 >= 0) && (sec_r000893_8_1 <= 255));
  __CPROVER_assume((sec_r000893_8_2 >= 0) && (sec_r000893_8_2 <= 255));
  __CPROVER_assume((sec_r000893_9_1 >= 0) && (sec_r000893_9_1 <= 255));
  __CPROVER_assume((sec_r000893_9_2 >= 0) && (sec_r000893_9_2 <= 255));
  __CPROVER_assume((sec_r000893_10_1 >= 0) && (sec_r000893_10_1 <= 255));
  __CPROVER_assume((sec_r000893_10_2 >= 0) && (sec_r000893_10_2 <= 255));
  __CPROVER_assume((sec_r000893_11_1 >= 0) && (sec_r000893_11_1 <= 255));
  __CPROVER_assume((sec_r000893_11_2 >= 0) && (sec_r000893_11_2 <= 255));
  __CPROVER_assume((sec_r000893_12_1 >= 0) && (sec_r000893_12_1 <= 255));
  __CPROVER_assume((sec_r000893_12_2 >= 0) && (sec_r000893_12_2 <= 255));
  __CPROVER_assume((sec_r000893_13_1 >= 0) && (sec_r000893_13_1 <= 255));
  __CPROVER_assume((sec_r000893_13_2 >= 0) && (sec_r000893_13_2 <= 255));
  __CPROVER_assume((sec_r000893_14_1 >= 0) && (sec_r000893_14_1 <= 255));
  __CPROVER_assume((sec_r000893_14_2 >= 0) && (sec_r000893_14_2 <= 255));
  __CPROVER_assume((sec_r000893_15_1 >= 0) && (sec_r000893_15_1 <= 255));
  __CPROVER_assume((sec_r000893_15_2 >= 0) && (sec_r000893_15_2 <= 255));
  struct EventLog_R000893_9313_0 st_var_0_1 = {0};
  struct EventLog_R000893_9313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000893_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000893_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000893_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000893_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000893_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000893_0_2 + 7) & 15;
  struct Transaction_R000893_9313_1 st_var_1_1 = {0};
  struct Transaction_R000893_9313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000893_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000893_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000893_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000893_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000893_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000893_0_2 + 9) & 15;
  struct SensorNode_R000893_9313_2 st_var_2_1 = {0};
  struct SensorNode_R000893_9313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000893_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000893_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000893_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000893_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000893_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000893_0_2 + 11) & 15;
  struct MatrixBlock_R000893_9313_3 st_var_3_1 = {0};
  struct MatrixBlock_R000893_9313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000893_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000893_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000893_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000893_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000893_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000893_0_2 + 13) & 15;
  union TelemetryField_R000893_9313_0 u_var_1;
  union TelemetryField_R000893_9313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 1) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 1) & 15;
  int stage_v_0_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_0_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= stage_v_0_1;
  chk_sum_2 ^= stage_v_0_2;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 36)
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
  if (stage_v_3_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 36)
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
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
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
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 15) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = (st_var_3_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_3_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 21) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((st_var_3_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_3_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 45)
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
  if (stage_v_23_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 45)
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
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 47)
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
  if (stage_v_29_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 47)
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
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((st_var_2_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_2_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 43)
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
  if (stage_v_34_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 43)
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
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 41)
    {
      chk_sum_1 ^= stage_v_36_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_36_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 41)
    {
      chk_sum_2 ^= stage_v_36_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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

  switch (stage_v_38_2)
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

  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  int stage_v_40_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_40_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((st_var_2_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_2_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 55)
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
  if (stage_v_42_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 55)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = table_1[0];
  int stage_v_44_2 = table_2[0];
  table_1[0] = (table_1[1] + 89) & 63;
  table_2[0] = (table_2[1] + 89) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (st_var_1_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_1_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = ((st_var_3_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_3_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 35)
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
  if (stage_v_47_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 35)
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
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 51) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
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
  int sub_step_52_1 = ((sec_r000893_6_1 + pub_r000893_18_1) + 17) & 127;
  int sub_step_52_2 = ((sec_r000893_6_2 + pub_r000893_18_2) + 17) & 127;
  int stage_v_52_1 = ((sub_step_52_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_52_2 = ((sub_step_52_2 * 2) + pub_r000893_20_2) & 127;
  st_var_0_1.buffer[1] = stage_v_52_1 & 15;
  st_var_0_2.buffer[1] = stage_v_52_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int sub_step_53_1 = ((stage_v_52_1 + pub_r000893_0_1) + 18) & 127;
  int sub_step_53_2 = ((stage_v_52_2 + pub_r000893_0_2) + 18) & 127;
  int stage_v_53_1 = ((sub_step_53_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_53_2 = ((sub_step_53_2 * 2) + pub_r000893_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_53_1 & 15;
  st_var_1_2.buffer[2] = stage_v_53_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int sub_step_54_1 = ((sub_step_53_1 + pub_r000893_1_1) + 20) & 127;
  int sub_step_54_2 = ((sub_step_53_2 + pub_r000893_1_2) + 20) & 127;
  int stage_v_54_1 = ((sub_step_54_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_54_2 = ((sub_step_54_2 * 2) + pub_r000893_15_2) & 127;
  st_var_2_1.buffer[0] = stage_v_54_1 & 15;
  st_var_2_2.buffer[0] = stage_v_54_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int sub_step_55_1 = ((sub_step_52_1 + pub_r000893_4_1) + 5) & 127;
  int sub_step_55_2 = ((sub_step_52_2 + pub_r000893_4_2) + 5) & 127;
  int stage_v_55_1 = ((sub_step_55_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_55_2 = ((sub_step_55_2 * 2) + pub_r000893_2_2) & 127;
  st_var_3_1.buffer[1] = stage_v_55_1 & 15;
  st_var_3_2.buffer[1] = stage_v_55_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int sub_step_56_1 = ((sec_r000893_13_1 + pub_r000893_4_1) + 11) & 127;
  int sub_step_56_2 = ((sec_r000893_13_2 + pub_r000893_4_2) + 11) & 127;
  int stage_v_56_1 = ((sub_step_56_1 * 2) + pub_r000893_5_1) & 127;
  int stage_v_56_2 = ((sub_step_56_2 * 2) + pub_r000893_5_2) & 127;
  st_var_0_1.buffer[2] = stage_v_56_1 & 15;
  st_var_0_2.buffer[2] = stage_v_56_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int sub_step_57_1 = ((sub_step_53_1 + pub_r000893_18_1) + 32) & 127;
  int sub_step_57_2 = ((sub_step_53_2 + pub_r000893_18_2) + 32) & 127;
  int stage_v_57_1 = ((sub_step_57_1 * 2) + pub_r000893_18_1) & 127;
  int stage_v_57_2 = ((sub_step_57_2 * 2) + pub_r000893_18_2) & 127;
  st_var_1_1.buffer[0] = stage_v_57_1 & 15;
  st_var_1_2.buffer[0] = stage_v_57_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int sub_step_58_1 = ((sub_step_54_1 + pub_r000893_11_1) + 28) & 127;
  int sub_step_58_2 = ((sub_step_54_2 + pub_r000893_11_2) + 28) & 127;
  int stage_v_58_1 = ((sub_step_58_1 * 2) + pub_r000893_7_1) & 127;
  int stage_v_58_2 = ((sub_step_58_2 * 2) + pub_r000893_7_2) & 127;
  st_var_2_1.buffer[1] = stage_v_58_1 & 15;
  st_var_2_2.buffer[1] = stage_v_58_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int sub_step_59_1 = ((sub_step_53_1 + pub_r000893_21_1) + 32) & 127;
  int sub_step_59_2 = ((sub_step_53_2 + pub_r000893_21_2) + 32) & 127;
  int stage_v_59_1 = ((sub_step_59_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_59_2 = ((sub_step_59_2 * 2) + pub_r000893_2_2) & 127;
  st_var_3_1.buffer[2] = stage_v_59_1 & 15;
  st_var_3_2.buffer[2] = stage_v_59_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int sub_step_60_1 = ((sec_r000893_13_1 + pub_r000893_12_1) + 13) & 127;
  int sub_step_60_2 = ((sec_r000893_13_2 + pub_r000893_12_2) + 13) & 127;
  int stage_v_60_1 = ((sub_step_60_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_60_2 = ((sub_step_60_2 * 2) + pub_r000893_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_60_1 & 15;
  st_var_0_2.buffer[0] = stage_v_60_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int sub_step_61_1 = ((sub_step_52_1 + pub_r000893_22_1) + 26) & 127;
  int sub_step_61_2 = ((sub_step_52_2 + pub_r000893_22_2) + 26) & 127;
  int stage_v_61_1 = ((sub_step_61_1 * 2) + pub_r000893_21_1) & 127;
  int stage_v_61_2 = ((sub_step_61_2 * 2) + pub_r000893_21_2) & 127;
  st_var_1_1.buffer[1] = stage_v_61_1 & 15;
  st_var_1_2.buffer[1] = stage_v_61_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int sub_step_62_1 = ((sub_step_52_1 + pub_r000893_8_1) + 22) & 127;
  int sub_step_62_2 = ((sub_step_52_2 + pub_r000893_8_2) + 22) & 127;
  int stage_v_62_1 = ((sub_step_62_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_62_2 = ((sub_step_62_2 * 2) + pub_r000893_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_62_1 & 15;
  st_var_2_2.buffer[2] = stage_v_62_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int sub_step_63_1 = ((sec_r000893_11_1 + pub_r000893_0_1) + 23) & 127;
  int sub_step_63_2 = ((sec_r000893_11_2 + pub_r000893_0_2) + 23) & 127;
  int stage_v_63_1 = ((sub_step_63_1 * 2) + pub_r000893_9_1) & 127;
  int stage_v_63_2 = ((sub_step_63_2 * 2) + pub_r000893_9_2) & 127;
  st_var_3_1.buffer[0] = stage_v_63_1 & 15;
  st_var_3_2.buffer[0] = stage_v_63_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int sub_step_64_1 = ((stage_v_61_1 + pub_r000893_7_1) + 11) & 127;
  int sub_step_64_2 = ((stage_v_61_2 + pub_r000893_7_2) + 11) & 127;
  int stage_v_64_1 = ((sub_step_64_1 * 2) + pub_r000893_19_1) & 127;
  int stage_v_64_2 = ((sub_step_64_2 * 2) + pub_r000893_19_2) & 127;
  st_var_0_1.buffer[1] = stage_v_64_1 & 15;
  st_var_0_2.buffer[1] = stage_v_64_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int sub_step_65_1 = ((stage_v_57_1 + pub_r000893_2_1) + 33) & 127;
  int sub_step_65_2 = ((stage_v_57_2 + pub_r000893_2_2) + 33) & 127;
  int stage_v_65_1 = ((sub_step_65_1 * 2) + pub_r000893_16_1) & 127;
  int stage_v_65_2 = ((sub_step_65_2 * 2) + pub_r000893_16_2) & 127;
  st_var_1_1.buffer[2] = stage_v_65_1 & 15;
  st_var_1_2.buffer[2] = stage_v_65_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int sub_step_66_1 = ((sec_r000893_10_1 + pub_r000893_8_1) + 10) & 127;
  int sub_step_66_2 = ((sec_r000893_10_2 + pub_r000893_8_2) + 10) & 127;
  int stage_v_66_1 = ((sub_step_66_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_66_2 = ((sub_step_66_2 * 2) + pub_r000893_17_2) & 127;
  st_var_2_1.buffer[0] = stage_v_66_1 & 15;
  st_var_2_2.buffer[0] = stage_v_66_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int sub_step_67_1 = ((sub_step_66_1 + pub_r000893_2_1) + 32) & 127;
  int sub_step_67_2 = ((sub_step_66_2 + pub_r000893_2_2) + 32) & 127;
  int stage_v_67_1 = ((sub_step_67_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_67_2 = ((sub_step_67_2 * 2) + pub_r000893_22_2) & 127;
  st_var_3_1.buffer[1] = stage_v_67_1 & 15;
  st_var_3_2.buffer[1] = stage_v_67_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int sub_step_68_1 = ((stage_v_66_1 + pub_r000893_3_1) + 29) & 127;
  int sub_step_68_2 = ((stage_v_66_2 + pub_r000893_3_2) + 29) & 127;
  int stage_v_68_1 = ((sub_step_68_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_68_2 = ((sub_step_68_2 * 2) + pub_r000893_8_2) & 127;
  st_var_0_1.buffer[2] = stage_v_68_1 & 15;
  st_var_0_2.buffer[2] = stage_v_68_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int sub_step_69_1 = ((sub_step_66_1 + pub_r000893_5_1) + 30) & 127;
  int sub_step_69_2 = ((sub_step_66_2 + pub_r000893_5_2) + 30) & 127;
  int stage_v_69_1 = ((sub_step_69_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_69_2 = ((sub_step_69_2 * 2) + pub_r000893_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_69_1 & 15;
  st_var_1_2.buffer[0] = stage_v_69_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int sub_step_70_1 = ((stage_v_57_1 + pub_r000893_4_1) + 14) & 127;
  int sub_step_70_2 = ((stage_v_57_2 + pub_r000893_4_2) + 14) & 127;
  int stage_v_70_1 = ((sub_step_70_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_70_2 = ((sub_step_70_2 * 2) + pub_r000893_15_2) & 127;
  st_var_2_1.buffer[1] = stage_v_70_1 & 15;
  st_var_2_2.buffer[1] = stage_v_70_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int sub_step_71_1 = ((sub_step_55_1 + pub_r000893_22_1) + 25) & 127;
  int sub_step_71_2 = ((sub_step_55_2 + pub_r000893_22_2) + 25) & 127;
  int stage_v_71_1 = ((sub_step_71_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_71_2 = ((sub_step_71_2 * 2) + pub_r000893_23_2) & 127;
  st_var_3_1.buffer[2] = stage_v_71_1 & 15;
  st_var_3_2.buffer[2] = stage_v_71_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int sub_step_72_1 = ((sub_step_53_1 + pub_r000893_3_1) + 31) & 127;
  int sub_step_72_2 = ((sub_step_53_2 + pub_r000893_3_2) + 31) & 127;
  int stage_v_72_1 = ((sub_step_72_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_72_2 = ((sub_step_72_2 * 2) + pub_r000893_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_72_1 & 15;
  st_var_0_2.buffer[0] = stage_v_72_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int sub_step_73_1 = ((sub_step_58_1 + pub_r000893_17_1) + 7) & 127;
  int sub_step_73_2 = ((sub_step_58_2 + pub_r000893_17_2) + 7) & 127;
  int stage_v_73_1 = ((sub_step_73_1 * 2) + pub_r000893_4_1) & 127;
  int stage_v_73_2 = ((sub_step_73_2 * 2) + pub_r000893_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_73_1 & 15;
  st_var_1_2.buffer[1] = stage_v_73_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int sub_step_74_1 = ((sub_step_59_1 + pub_r000893_1_1) + 7) & 127;
  int sub_step_74_2 = ((sub_step_59_2 + pub_r000893_1_2) + 7) & 127;
  int stage_v_74_1 = ((sub_step_74_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_74_2 = ((sub_step_74_2 * 2) + pub_r000893_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_74_1 & 15;
  st_var_2_2.buffer[2] = stage_v_74_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int sub_step_75_1 = ((sub_step_66_1 + pub_r000893_6_1) + 8) & 127;
  int sub_step_75_2 = ((sub_step_66_2 + pub_r000893_6_2) + 8) & 127;
  int stage_v_75_1 = ((sub_step_75_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_75_2 = ((sub_step_75_2 * 2) + pub_r000893_15_2) & 127;
  st_var_3_1.buffer[0] = stage_v_75_1 & 15;
  st_var_3_2.buffer[0] = stage_v_75_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int sub_step_76_1 = ((sec_r000893_4_1 + pub_r000893_7_1) + 9) & 127;
  int sub_step_76_2 = ((sec_r000893_4_2 + pub_r000893_7_2) + 9) & 127;
  int stage_v_76_1 = ((sub_step_76_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_76_2 = ((sub_step_76_2 * 2) + pub_r000893_23_2) & 127;
  st_var_0_1.buffer[1] = stage_v_76_1 & 15;
  st_var_0_2.buffer[1] = stage_v_76_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int sub_step_77_1 = ((sub_step_61_1 + pub_r000893_6_1) + 23) & 127;
  int sub_step_77_2 = ((sub_step_61_2 + pub_r000893_6_2) + 23) & 127;
  int stage_v_77_1 = ((sub_step_77_1 * 2) + pub_r000893_12_1) & 127;
  int stage_v_77_2 = ((sub_step_77_2 * 2) + pub_r000893_12_2) & 127;
  st_var_1_1.buffer[2] = stage_v_77_1 & 15;
  st_var_1_2.buffer[2] = stage_v_77_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int sub_step_78_1 = ((stage_v_76_1 + pub_r000893_15_1) + 19) & 127;
  int sub_step_78_2 = ((stage_v_76_2 + pub_r000893_15_2) + 19) & 127;
  int stage_v_78_1 = ((sub_step_78_1 * 2) + pub_r000893_7_1) & 127;
  int stage_v_78_2 = ((sub_step_78_2 * 2) + pub_r000893_7_2) & 127;
  st_var_2_1.buffer[0] = stage_v_78_1 & 15;
  st_var_2_2.buffer[0] = stage_v_78_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int sub_step_79_1 = ((sub_step_75_1 + pub_r000893_8_1) + 7) & 127;
  int sub_step_79_2 = ((sub_step_75_2 + pub_r000893_8_2) + 7) & 127;
  int stage_v_79_1 = ((sub_step_79_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_79_2 = ((sub_step_79_2 * 2) + pub_r000893_20_2) & 127;
  st_var_3_1.buffer[1] = stage_v_79_1 & 15;
  st_var_3_2.buffer[1] = stage_v_79_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int sub_step_80_1 = ((sub_step_53_1 + pub_r000893_4_1) + 34) & 127;
  int sub_step_80_2 = ((sub_step_53_2 + pub_r000893_4_2) + 34) & 127;
  int stage_v_80_1 = ((sub_step_80_1 * 2) + pub_r000893_4_1) & 127;
  int stage_v_80_2 = ((sub_step_80_2 * 2) + pub_r000893_4_2) & 127;
  st_var_0_1.buffer[2] = stage_v_80_1 & 15;
  st_var_0_2.buffer[2] = stage_v_80_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int sub_step_81_1 = ((stage_v_76_1 + pub_r000893_21_1) + 13) & 127;
  int sub_step_81_2 = ((stage_v_76_2 + pub_r000893_21_2) + 13) & 127;
  int stage_v_81_1 = ((sub_step_81_1 * 2) + pub_r000893_21_1) & 127;
  int stage_v_81_2 = ((sub_step_81_2 * 2) + pub_r000893_21_2) & 127;
  st_var_1_1.buffer[0] = stage_v_81_1 & 15;
  st_var_1_2.buffer[0] = stage_v_81_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int sub_step_82_1 = ((stage_v_53_1 + pub_r000893_12_1) + 19) & 127;
  int sub_step_82_2 = ((stage_v_53_2 + pub_r000893_12_2) + 19) & 127;
  int stage_v_82_1 = ((sub_step_82_1 * 2) + pub_r000893_9_1) & 127;
  int stage_v_82_2 = ((sub_step_82_2 * 2) + pub_r000893_9_2) & 127;
  st_var_2_1.buffer[1] = stage_v_82_1 & 15;
  st_var_2_2.buffer[1] = stage_v_82_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int sub_step_83_1 = ((sec_r000893_8_1 + pub_r000893_17_1) + 26) & 127;
  int sub_step_83_2 = ((sec_r000893_8_2 + pub_r000893_17_2) + 26) & 127;
  int stage_v_83_1 = ((sub_step_83_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_83_2 = ((sub_step_83_2 * 2) + pub_r000893_17_2) & 127;
  st_var_3_1.buffer[2] = stage_v_83_1 & 15;
  st_var_3_2.buffer[2] = stage_v_83_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int sub_step_84_1 = ((stage_v_80_1 + pub_r000893_4_1) + 16) & 127;
  int sub_step_84_2 = ((stage_v_80_2 + pub_r000893_4_2) + 16) & 127;
  int stage_v_84_1 = ((sub_step_84_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_84_2 = ((sub_step_84_2 * 2) + pub_r000893_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_84_1 & 15;
  st_var_0_2.buffer[0] = stage_v_84_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int sub_step_85_1 = ((sec_r000893_8_1 + pub_r000893_0_1) + 18) & 127;
  int sub_step_85_2 = ((sec_r000893_8_2 + pub_r000893_0_2) + 18) & 127;
  int stage_v_85_1 = ((sub_step_85_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_85_2 = ((sub_step_85_2 * 2) + pub_r000893_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_85_1 & 15;
  st_var_1_2.buffer[1] = stage_v_85_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int sub_step_86_1 = ((sub_step_70_1 + pub_r000893_2_1) + 22) & 127;
  int sub_step_86_2 = ((sub_step_70_2 + pub_r000893_2_2) + 22) & 127;
  int stage_v_86_1 = ((sub_step_86_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_86_2 = ((sub_step_86_2 * 2) + pub_r000893_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_86_1 & 15;
  st_var_2_2.buffer[2] = stage_v_86_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int sub_step_87_1 = ((stage_v_84_1 + pub_r000893_6_1) + 23) & 127;
  int sub_step_87_2 = ((stage_v_84_2 + pub_r000893_6_2) + 23) & 127;
  int stage_v_87_1 = ((sub_step_87_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_87_2 = ((sub_step_87_2 * 2) + pub_r000893_2_2) & 127;
  st_var_3_1.buffer[0] = stage_v_87_1 & 15;
  st_var_3_2.buffer[0] = stage_v_87_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int sub_step_88_1 = ((sub_step_86_1 + pub_r000893_19_1) + 35) & 127;
  int sub_step_88_2 = ((sub_step_86_2 + pub_r000893_19_2) + 35) & 127;
  int stage_v_88_1 = ((sub_step_88_1 * 2) + pub_r000893_5_1) & 127;
  int stage_v_88_2 = ((sub_step_88_2 * 2) + pub_r000893_5_2) & 127;
  st_var_0_1.buffer[1] = stage_v_88_1 & 15;
  st_var_0_2.buffer[1] = stage_v_88_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int sub_step_89_1 = ((stage_v_57_1 + pub_r000893_1_1) + 22) & 127;
  int sub_step_89_2 = ((stage_v_57_2 + pub_r000893_1_2) + 22) & 127;
  int stage_v_89_1 = ((sub_step_89_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_89_2 = ((sub_step_89_2 * 2) + pub_r000893_10_2) & 127;
  st_var_1_1.buffer[2] = stage_v_89_1 & 15;
  st_var_1_2.buffer[2] = stage_v_89_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int sub_step_90_1 = ((sub_step_71_1 + pub_r000893_6_1) + 14) & 127;
  int sub_step_90_2 = ((sub_step_71_2 + pub_r000893_6_2) + 14) & 127;
  int stage_v_90_1 = ((sub_step_90_1 * 2) + pub_r000893_5_1) & 127;
  int stage_v_90_2 = ((sub_step_90_2 * 2) + pub_r000893_5_2) & 127;
  st_var_2_1.buffer[0] = stage_v_90_1 & 15;
  st_var_2_2.buffer[0] = stage_v_90_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int sub_step_91_1 = ((stage_v_64_1 + pub_r000893_16_1) + 10) & 127;
  int sub_step_91_2 = ((stage_v_64_2 + pub_r000893_16_2) + 10) & 127;
  int stage_v_91_1 = ((sub_step_91_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_91_2 = ((sub_step_91_2 * 2) + pub_r000893_11_2) & 127;
  st_var_3_1.buffer[1] = stage_v_91_1 & 15;
  st_var_3_2.buffer[1] = stage_v_91_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int sub_step_92_1 = ((sub_step_69_1 + pub_r000893_0_1) + 21) & 127;
  int sub_step_92_2 = ((sub_step_69_2 + pub_r000893_0_2) + 21) & 127;
  int stage_v_92_1 = ((sub_step_92_1 * 2) + pub_r000893_14_1) & 127;
  int stage_v_92_2 = ((sub_step_92_2 * 2) + pub_r000893_14_2) & 127;
  st_var_0_1.buffer[2] = stage_v_92_1 & 15;
  st_var_0_2.buffer[2] = stage_v_92_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int sub_step_93_1 = ((sub_step_82_1 + pub_r000893_0_1) + 18) & 127;
  int sub_step_93_2 = ((sub_step_82_2 + pub_r000893_0_2) + 18) & 127;
  int stage_v_93_1 = ((sub_step_93_1 * 2) + pub_r000893_16_1) & 127;
  int stage_v_93_2 = ((sub_step_93_2 * 2) + pub_r000893_16_2) & 127;
  st_var_1_1.buffer[0] = stage_v_93_1 & 15;
  st_var_1_2.buffer[0] = stage_v_93_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int sub_step_94_1 = ((sub_step_68_1 + pub_r000893_8_1) + 14) & 127;
  int sub_step_94_2 = ((sub_step_68_2 + pub_r000893_8_2) + 14) & 127;
  int stage_v_94_1 = ((sub_step_94_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_94_2 = ((sub_step_94_2 * 2) + pub_r000893_17_2) & 127;
  st_var_2_1.buffer[1] = stage_v_94_1 & 15;
  st_var_2_2.buffer[1] = stage_v_94_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int sub_step_95_1 = ((sub_step_58_1 + pub_r000893_13_1) + 16) & 127;
  int sub_step_95_2 = ((sub_step_58_2 + pub_r000893_13_2) + 16) & 127;
  int stage_v_95_1 = ((sub_step_95_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_95_2 = ((sub_step_95_2 * 2) + pub_r000893_10_2) & 127;
  st_var_3_1.buffer[2] = stage_v_95_1 & 15;
  st_var_3_2.buffer[2] = stage_v_95_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int sub_step_96_1 = ((sub_step_79_1 + pub_r000893_20_1) + 31) & 127;
  int sub_step_96_2 = ((sub_step_79_2 + pub_r000893_20_2) + 31) & 127;
  int stage_v_96_1 = ((sub_step_96_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_96_2 = ((sub_step_96_2 * 2) + pub_r000893_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_96_1 & 15;
  st_var_0_2.buffer[0] = stage_v_96_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int sub_step_97_1 = ((sec_r000893_9_1 + pub_r000893_6_1) + 18) & 127;
  int sub_step_97_2 = ((sec_r000893_9_2 + pub_r000893_6_2) + 18) & 127;
  int stage_v_97_1 = ((sub_step_97_1 * 2) + pub_r000893_18_1) & 127;
  int stage_v_97_2 = ((sub_step_97_2 * 2) + pub_r000893_18_2) & 127;
  st_var_1_1.buffer[1] = stage_v_97_1 & 15;
  st_var_1_2.buffer[1] = stage_v_97_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int sub_step_98_1 = ((sub_step_82_1 + pub_r000893_3_1) + 10) & 127;
  int sub_step_98_2 = ((sub_step_82_2 + pub_r000893_3_2) + 10) & 127;
  int stage_v_98_1 = ((sub_step_98_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_98_2 = ((sub_step_98_2 * 2) + pub_r000893_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_98_1 & 15;
  st_var_2_2.buffer[2] = stage_v_98_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int sub_step_99_1 = ((sub_step_76_1 + pub_r000893_10_1) + 34) & 127;
  int sub_step_99_2 = ((sub_step_76_2 + pub_r000893_10_2) + 34) & 127;
  int stage_v_99_1 = ((sub_step_99_1 * 2) + pub_r000893_14_1) & 127;
  int stage_v_99_2 = ((sub_step_99_2 * 2) + pub_r000893_14_2) & 127;
  st_var_3_1.buffer[0] = stage_v_99_1 & 15;
  st_var_3_2.buffer[0] = stage_v_99_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int sub_step_100_1 = ((stage_v_99_1 + pub_r000893_17_1) + 32) & 127;
  int sub_step_100_2 = ((stage_v_99_2 + pub_r000893_17_2) + 32) & 127;
  int stage_v_100_1 = ((sub_step_100_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_100_2 = ((sub_step_100_2 * 2) + pub_r000893_23_2) & 127;
  st_var_0_1.buffer[1] = stage_v_100_1 & 15;
  st_var_0_2.buffer[1] = stage_v_100_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int sub_step_101_1 = ((sec_r000893_9_1 + pub_r000893_5_1) + 21) & 127;
  int sub_step_101_2 = ((sec_r000893_9_2 + pub_r000893_5_2) + 21) & 127;
  int stage_v_101_1 = ((sub_step_101_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_101_2 = ((sub_step_101_2 * 2) + pub_r000893_22_2) & 127;
  st_var_1_1.buffer[2] = stage_v_101_1 & 15;
  st_var_1_2.buffer[2] = stage_v_101_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int sub_step_102_1 = ((sec_r000893_12_1 + pub_r000893_12_1) + 29) & 127;
  int sub_step_102_2 = ((sec_r000893_12_2 + pub_r000893_12_2) + 29) & 127;
  int stage_v_102_1 = ((sub_step_102_1 * 2) + pub_r000893_18_1) & 127;
  int stage_v_102_2 = ((sub_step_102_2 * 2) + pub_r000893_18_2) & 127;
  st_var_2_1.buffer[0] = stage_v_102_1 & 15;
  st_var_2_2.buffer[0] = stage_v_102_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int sub_step_103_1 = ((sec_r000893_1_1 + pub_r000893_9_1) + 12) & 127;
  int sub_step_103_2 = ((sec_r000893_1_2 + pub_r000893_9_2) + 12) & 127;
  int stage_v_103_1 = ((sub_step_103_1 * 2) + pub_r000893_4_1) & 127;
  int stage_v_103_2 = ((sub_step_103_2 * 2) + pub_r000893_4_2) & 127;
  st_var_3_1.buffer[1] = stage_v_103_1 & 15;
  st_var_3_2.buffer[1] = stage_v_103_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int sub_step_104_1 = ((stage_v_98_1 + pub_r000893_5_1) + 11) & 127;
  int sub_step_104_2 = ((stage_v_98_2 + pub_r000893_5_2) + 11) & 127;
  int stage_v_104_1 = ((sub_step_104_1 * 2) + pub_r000893_21_1) & 127;
  int stage_v_104_2 = ((sub_step_104_2 * 2) + pub_r000893_21_2) & 127;
  st_var_0_1.buffer[2] = stage_v_104_1 & 15;
  st_var_0_2.buffer[2] = stage_v_104_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int sub_step_105_1 = ((sub_step_96_1 + pub_r000893_8_1) + 20) & 127;
  int sub_step_105_2 = ((sub_step_96_2 + pub_r000893_8_2) + 20) & 127;
  int stage_v_105_1 = ((sub_step_105_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_105_2 = ((sub_step_105_2 * 2) + pub_r000893_15_2) & 127;
  st_var_1_1.buffer[0] = stage_v_105_1 & 15;
  st_var_1_2.buffer[0] = stage_v_105_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int sub_step_106_1 = ((stage_v_63_1 + pub_r000893_0_1) + 30) & 127;
  int sub_step_106_2 = ((stage_v_63_2 + pub_r000893_0_2) + 30) & 127;
  int stage_v_106_1 = ((sub_step_106_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_106_2 = ((sub_step_106_2 * 2) + pub_r000893_2_2) & 127;
  st_var_2_1.buffer[1] = stage_v_106_1 & 15;
  st_var_2_2.buffer[1] = stage_v_106_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int sub_step_107_1 = ((sec_r000893_15_1 + pub_r000893_11_1) + 8) & 127;
  int sub_step_107_2 = ((sec_r000893_15_2 + pub_r000893_11_2) + 8) & 127;
  int stage_v_107_1 = ((sub_step_107_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_107_2 = ((sub_step_107_2 * 2) + pub_r000893_2_2) & 127;
  st_var_3_1.buffer[2] = stage_v_107_1 & 15;
  st_var_3_2.buffer[2] = stage_v_107_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int sub_step_108_1 = ((stage_v_86_1 + pub_r000893_1_1) + 29) & 127;
  int sub_step_108_2 = ((stage_v_86_2 + pub_r000893_1_2) + 29) & 127;
  int stage_v_108_1 = ((sub_step_108_1 * 2) + pub_r000893_7_1) & 127;
  int stage_v_108_2 = ((sub_step_108_2 * 2) + pub_r000893_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_108_1 & 15;
  st_var_0_2.buffer[0] = stage_v_108_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int sub_step_109_1 = ((sub_step_93_1 + pub_r000893_10_1) + 13) & 127;
  int sub_step_109_2 = ((sub_step_93_2 + pub_r000893_10_2) + 13) & 127;
  int stage_v_109_1 = ((sub_step_109_1 * 2) + pub_r000893_4_1) & 127;
  int stage_v_109_2 = ((sub_step_109_2 * 2) + pub_r000893_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_109_1 & 15;
  st_var_1_2.buffer[1] = stage_v_109_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int sub_step_110_1 = ((stage_v_65_1 + pub_r000893_1_1) + 8) & 127;
  int sub_step_110_2 = ((stage_v_65_2 + pub_r000893_1_2) + 8) & 127;
  int stage_v_110_1 = ((sub_step_110_1 * 2) + pub_r000893_9_1) & 127;
  int stage_v_110_2 = ((sub_step_110_2 * 2) + pub_r000893_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_110_1 & 15;
  st_var_2_2.buffer[2] = stage_v_110_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int sub_step_111_1 = ((stage_v_52_1 + pub_r000893_10_1) + 17) & 127;
  int sub_step_111_2 = ((stage_v_52_2 + pub_r000893_10_2) + 17) & 127;
  int stage_v_111_1 = ((sub_step_111_1 * 2) + pub_r000893_19_1) & 127;
  int stage_v_111_2 = ((sub_step_111_2 * 2) + pub_r000893_19_2) & 127;
  st_var_3_1.buffer[0] = stage_v_111_1 & 15;
  st_var_3_2.buffer[0] = stage_v_111_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int sub_step_112_1 = ((sec_r000893_13_1 + pub_r000893_21_1) + 25) & 127;
  int sub_step_112_2 = ((sec_r000893_13_2 + pub_r000893_21_2) + 25) & 127;
  int stage_v_112_1 = ((sub_step_112_1 * 2) + pub_r000893_21_1) & 127;
  int stage_v_112_2 = ((sub_step_112_2 * 2) + pub_r000893_21_2) & 127;
  st_var_0_1.buffer[1] = stage_v_112_1 & 15;
  st_var_0_2.buffer[1] = stage_v_112_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int sub_step_113_1 = ((sub_step_84_1 + pub_r000893_4_1) + 28) & 127;
  int sub_step_113_2 = ((sub_step_84_2 + pub_r000893_4_2) + 28) & 127;
  int stage_v_113_1 = ((sub_step_113_1 * 2) + pub_r000893_16_1) & 127;
  int stage_v_113_2 = ((sub_step_113_2 * 2) + pub_r000893_16_2) & 127;
  st_var_1_1.buffer[2] = stage_v_113_1 & 15;
  st_var_1_2.buffer[2] = stage_v_113_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int sub_step_114_1 = ((stage_v_102_1 + pub_r000893_11_1) + 13) & 127;
  int sub_step_114_2 = ((stage_v_102_2 + pub_r000893_11_2) + 13) & 127;
  int stage_v_114_1 = ((sub_step_114_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_114_2 = ((sub_step_114_2 * 2) + pub_r000893_2_2) & 127;
  st_var_2_1.buffer[0] = stage_v_114_1 & 15;
  st_var_2_2.buffer[0] = stage_v_114_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int sub_step_115_1 = ((sub_step_52_1 + pub_r000893_10_1) + 13) & 127;
  int sub_step_115_2 = ((sub_step_52_2 + pub_r000893_10_2) + 13) & 127;
  int stage_v_115_1 = ((sub_step_115_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_115_2 = ((sub_step_115_2 * 2) + pub_r000893_11_2) & 127;
  st_var_3_1.buffer[1] = stage_v_115_1 & 15;
  st_var_3_2.buffer[1] = stage_v_115_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int sub_step_116_1 = ((sub_step_102_1 + pub_r000893_9_1) + 14) & 127;
  int sub_step_116_2 = ((sub_step_102_2 + pub_r000893_9_2) + 14) & 127;
  int stage_v_116_1 = ((sub_step_116_1 * 2) + pub_r000893_21_1) & 127;
  int stage_v_116_2 = ((sub_step_116_2 * 2) + pub_r000893_21_2) & 127;
  st_var_0_1.buffer[2] = stage_v_116_1 & 15;
  st_var_0_2.buffer[2] = stage_v_116_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int sub_step_117_1 = ((sec_r000893_2_1 + pub_r000893_17_1) + 30) & 127;
  int sub_step_117_2 = ((sec_r000893_2_2 + pub_r000893_17_2) + 30) & 127;
  int stage_v_117_1 = ((sub_step_117_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_117_2 = ((sub_step_117_2 * 2) + pub_r000893_3_2) & 127;
  st_var_1_1.buffer[0] = stage_v_117_1 & 15;
  st_var_1_2.buffer[0] = stage_v_117_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int sub_step_118_1 = ((sub_step_77_1 + pub_r000893_7_1) + 32) & 127;
  int sub_step_118_2 = ((sub_step_77_2 + pub_r000893_7_2) + 32) & 127;
  int stage_v_118_1 = ((sub_step_118_1 * 2) + pub_r000893_13_1) & 127;
  int stage_v_118_2 = ((sub_step_118_2 * 2) + pub_r000893_13_2) & 127;
  st_var_2_1.buffer[1] = stage_v_118_1 & 15;
  st_var_2_2.buffer[1] = stage_v_118_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int sub_step_119_1 = ((stage_v_117_1 + pub_r000893_11_1) + 10) & 127;
  int sub_step_119_2 = ((stage_v_117_2 + pub_r000893_11_2) + 10) & 127;
  int stage_v_119_1 = ((sub_step_119_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_119_2 = ((sub_step_119_2 * 2) + pub_r000893_20_2) & 127;
  st_var_3_1.buffer[2] = stage_v_119_1 & 15;
  st_var_3_2.buffer[2] = stage_v_119_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int sub_step_120_1 = ((sec_r000893_6_1 + pub_r000893_13_1) + 9) & 127;
  int sub_step_120_2 = ((sec_r000893_6_2 + pub_r000893_13_2) + 9) & 127;
  int stage_v_120_1 = ((sub_step_120_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_120_2 = ((sub_step_120_2 * 2) + pub_r000893_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_120_1 & 15;
  st_var_0_2.buffer[0] = stage_v_120_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int sub_step_121_1 = ((sub_step_98_1 + pub_r000893_9_1) + 10) & 127;
  int sub_step_121_2 = ((sub_step_98_2 + pub_r000893_9_2) + 10) & 127;
  int stage_v_121_1 = ((sub_step_121_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_121_2 = ((sub_step_121_2 * 2) + pub_r000893_23_2) & 127;
  st_var_1_1.buffer[1] = stage_v_121_1 & 15;
  st_var_1_2.buffer[1] = stage_v_121_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int sub_step_122_1 = ((sec_r000893_9_1 + pub_r000893_7_1) + 6) & 127;
  int sub_step_122_2 = ((sec_r000893_9_2 + pub_r000893_7_2) + 6) & 127;
  int stage_v_122_1 = ((sub_step_122_1 * 2) + pub_r000893_4_1) & 127;
  int stage_v_122_2 = ((sub_step_122_2 * 2) + pub_r000893_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_122_1 & 15;
  st_var_2_2.buffer[2] = stage_v_122_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int sub_step_123_1 = ((stage_v_54_1 + pub_r000893_17_1) + 21) & 127;
  int sub_step_123_2 = ((stage_v_54_2 + pub_r000893_17_2) + 21) & 127;
  int stage_v_123_1 = ((sub_step_123_1 * 2) + pub_r000893_12_1) & 127;
  int stage_v_123_2 = ((sub_step_123_2 * 2) + pub_r000893_12_2) & 127;
  st_var_3_1.buffer[0] = stage_v_123_1 & 15;
  st_var_3_2.buffer[0] = stage_v_123_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int sub_step_124_1 = ((sub_step_85_1 + pub_r000893_14_1) + 17) & 127;
  int sub_step_124_2 = ((sub_step_85_2 + pub_r000893_14_2) + 17) & 127;
  int stage_v_124_1 = ((sub_step_124_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_124_2 = ((sub_step_124_2 * 2) + pub_r000893_2_2) & 127;
  st_var_0_1.buffer[1] = stage_v_124_1 & 15;
  st_var_0_2.buffer[1] = stage_v_124_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int sub_step_125_1 = ((stage_v_120_1 + pub_r000893_5_1) + 5) & 127;
  int sub_step_125_2 = ((stage_v_120_2 + pub_r000893_5_2) + 5) & 127;
  int stage_v_125_1 = ((sub_step_125_1 * 2) + pub_r000893_5_1) & 127;
  int stage_v_125_2 = ((sub_step_125_2 * 2) + pub_r000893_5_2) & 127;
  st_var_1_1.buffer[2] = stage_v_125_1 & 15;
  st_var_1_2.buffer[2] = stage_v_125_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int sub_step_126_1 = ((stage_v_70_1 + pub_r000893_14_1) + 30) & 127;
  int sub_step_126_2 = ((stage_v_70_2 + pub_r000893_14_2) + 30) & 127;
  int stage_v_126_1 = ((sub_step_126_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_126_2 = ((sub_step_126_2 * 2) + pub_r000893_22_2) & 127;
  st_var_2_1.buffer[0] = stage_v_126_1 & 15;
  st_var_2_2.buffer[0] = stage_v_126_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int sub_step_127_1 = ((sec_r000893_0_1 + pub_r000893_4_1) + 29) & 127;
  int sub_step_127_2 = ((sec_r000893_0_2 + pub_r000893_4_2) + 29) & 127;
  int stage_v_127_1 = ((sub_step_127_1 * 2) + pub_r000893_21_1) & 127;
  int stage_v_127_2 = ((sub_step_127_2 * 2) + pub_r000893_21_2) & 127;
  st_var_3_1.buffer[1] = stage_v_127_1 & 15;
  st_var_3_2.buffer[1] = stage_v_127_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int sub_step_128_1 = ((stage_v_108_1 + pub_r000893_7_1) + 19) & 127;
  int sub_step_128_2 = ((stage_v_108_2 + pub_r000893_7_2) + 19) & 127;
  int stage_v_128_1 = ((sub_step_128_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_128_2 = ((sub_step_128_2 * 2) + pub_r000893_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_128_1 & 15;
  st_var_0_2.buffer[2] = stage_v_128_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int sub_step_129_1 = ((sub_step_89_1 + pub_r000893_2_1) + 7) & 127;
  int sub_step_129_2 = ((sub_step_89_2 + pub_r000893_2_2) + 7) & 127;
  int stage_v_129_1 = ((sub_step_129_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_129_2 = ((sub_step_129_2 * 2) + pub_r000893_11_2) & 127;
  st_var_1_1.buffer[0] = stage_v_129_1 & 15;
  st_var_1_2.buffer[0] = stage_v_129_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int sub_step_130_1 = ((sub_step_68_1 + pub_r000893_7_1) + 25) & 127;
  int sub_step_130_2 = ((sub_step_68_2 + pub_r000893_7_2) + 25) & 127;
  int stage_v_130_1 = ((sub_step_130_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_130_2 = ((sub_step_130_2 * 2) + pub_r000893_8_2) & 127;
  st_var_2_1.buffer[1] = stage_v_130_1 & 15;
  st_var_2_2.buffer[1] = stage_v_130_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int sub_step_131_1 = ((sub_step_120_1 + pub_r000893_8_1) + 27) & 127;
  int sub_step_131_2 = ((sub_step_120_2 + pub_r000893_8_2) + 27) & 127;
  int stage_v_131_1 = ((sub_step_131_1 * 2) + pub_r000893_19_1) & 127;
  int stage_v_131_2 = ((sub_step_131_2 * 2) + pub_r000893_19_2) & 127;
  st_var_3_1.buffer[2] = stage_v_131_1 & 15;
  st_var_3_2.buffer[2] = stage_v_131_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int sub_step_132_1 = ((sec_r000893_0_1 + pub_r000893_12_1) + 28) & 127;
  int sub_step_132_2 = ((sec_r000893_0_2 + pub_r000893_12_2) + 28) & 127;
  int stage_v_132_1 = ((sub_step_132_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_132_2 = ((sub_step_132_2 * 2) + pub_r000893_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_132_1 & 15;
  st_var_0_2.buffer[0] = stage_v_132_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int sub_step_133_1 = ((sec_r000893_4_1 + pub_r000893_12_1) + 5) & 127;
  int sub_step_133_2 = ((sec_r000893_4_2 + pub_r000893_12_2) + 5) & 127;
  int stage_v_133_1 = ((sub_step_133_1 * 2) + pub_r000893_12_1) & 127;
  int stage_v_133_2 = ((sub_step_133_2 * 2) + pub_r000893_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_133_1 & 15;
  st_var_1_2.buffer[1] = stage_v_133_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int sub_step_134_1 = ((sec_r000893_12_1 + pub_r000893_2_1) + 15) & 127;
  int sub_step_134_2 = ((sec_r000893_12_2 + pub_r000893_2_2) + 15) & 127;
  int stage_v_134_1 = ((sub_step_134_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_134_2 = ((sub_step_134_2 * 2) + pub_r000893_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_134_1 & 15;
  st_var_2_2.buffer[2] = stage_v_134_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int sub_step_135_1 = ((sub_step_55_1 + pub_r000893_14_1) + 19) & 127;
  int sub_step_135_2 = ((sub_step_55_2 + pub_r000893_14_2) + 19) & 127;
  int stage_v_135_1 = ((sub_step_135_1 * 2) + pub_r000893_4_1) & 127;
  int stage_v_135_2 = ((sub_step_135_2 * 2) + pub_r000893_4_2) & 127;
  st_var_3_1.buffer[0] = stage_v_135_1 & 15;
  st_var_3_2.buffer[0] = stage_v_135_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int sub_step_136_1 = ((stage_v_101_1 + pub_r000893_11_1) + 34) & 127;
  int sub_step_136_2 = ((stage_v_101_2 + pub_r000893_11_2) + 34) & 127;
  int stage_v_136_1 = ((sub_step_136_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_136_2 = ((sub_step_136_2 * 2) + pub_r000893_3_2) & 127;
  st_var_0_1.buffer[1] = stage_v_136_1 & 15;
  st_var_0_2.buffer[1] = stage_v_136_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int sub_step_137_1 = ((sub_step_96_1 + pub_r000893_9_1) + 19) & 127;
  int sub_step_137_2 = ((sub_step_96_2 + pub_r000893_9_2) + 19) & 127;
  int stage_v_137_1 = ((sub_step_137_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_137_2 = ((sub_step_137_2 * 2) + pub_r000893_6_2) & 127;
  st_var_1_1.buffer[2] = stage_v_137_1 & 15;
  st_var_1_2.buffer[2] = stage_v_137_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int sub_step_138_1 = ((stage_v_121_1 + pub_r000893_2_1) + 14) & 127;
  int sub_step_138_2 = ((stage_v_121_2 + pub_r000893_2_2) + 14) & 127;
  int stage_v_138_1 = ((sub_step_138_1 * 2) + pub_r000893_1_1) & 127;
  int stage_v_138_2 = ((sub_step_138_2 * 2) + pub_r000893_1_2) & 127;
  st_var_2_1.buffer[0] = stage_v_138_1 & 15;
  st_var_2_2.buffer[0] = stage_v_138_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int sub_step_139_1 = ((sub_step_118_1 + pub_r000893_20_1) + 7) & 127;
  int sub_step_139_2 = ((sub_step_118_2 + pub_r000893_20_2) + 7) & 127;
  int stage_v_139_1 = ((sub_step_139_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_139_2 = ((sub_step_139_2 * 2) + pub_r000893_11_2) & 127;
  st_var_3_1.buffer[1] = stage_v_139_1 & 15;
  st_var_3_2.buffer[1] = stage_v_139_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int sub_step_140_1 = ((sub_step_134_1 + pub_r000893_9_1) + 33) & 127;
  int sub_step_140_2 = ((sub_step_134_2 + pub_r000893_9_2) + 33) & 127;
  int stage_v_140_1 = ((sub_step_140_1 * 2) + pub_r000893_1_1) & 127;
  int stage_v_140_2 = ((sub_step_140_2 * 2) + pub_r000893_1_2) & 127;
  st_var_0_1.buffer[2] = stage_v_140_1 & 15;
  st_var_0_2.buffer[2] = stage_v_140_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int sub_step_141_1 = ((sub_step_85_1 + pub_r000893_6_1) + 18) & 127;
  int sub_step_141_2 = ((sub_step_85_2 + pub_r000893_6_2) + 18) & 127;
  int stage_v_141_1 = ((sub_step_141_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_141_2 = ((sub_step_141_2 * 2) + pub_r000893_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_141_1 & 15;
  st_var_1_2.buffer[0] = stage_v_141_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int sub_step_142_1 = ((stage_v_121_1 + pub_r000893_5_1) + 11) & 127;
  int sub_step_142_2 = ((stage_v_121_2 + pub_r000893_5_2) + 11) & 127;
  int stage_v_142_1 = ((sub_step_142_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_142_2 = ((sub_step_142_2 * 2) + pub_r000893_0_2) & 127;
  st_var_2_1.buffer[1] = stage_v_142_1 & 15;
  st_var_2_2.buffer[1] = stage_v_142_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int sub_step_143_1 = ((sec_r000893_14_1 + pub_r000893_4_1) + 8) & 127;
  int sub_step_143_2 = ((sec_r000893_14_2 + pub_r000893_4_2) + 8) & 127;
  int stage_v_143_1 = ((sub_step_143_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_143_2 = ((sub_step_143_2 * 2) + pub_r000893_22_2) & 127;
  st_var_3_1.buffer[2] = stage_v_143_1 & 15;
  st_var_3_2.buffer[2] = stage_v_143_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int sub_step_144_1 = ((sec_r000893_13_1 + pub_r000893_21_1) + 18) & 127;
  int sub_step_144_2 = ((sec_r000893_13_2 + pub_r000893_21_2) + 18) & 127;
  int stage_v_144_1 = ((sub_step_144_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_144_2 = ((sub_step_144_2 * 2) + pub_r000893_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_144_1 & 15;
  st_var_0_2.buffer[0] = stage_v_144_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int sub_step_145_1 = ((sub_step_98_1 + pub_r000893_10_1) + 8) & 127;
  int sub_step_145_2 = ((sub_step_98_2 + pub_r000893_10_2) + 8) & 127;
  int stage_v_145_1 = ((sub_step_145_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_145_2 = ((sub_step_145_2 * 2) + pub_r000893_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_145_1 & 15;
  st_var_1_2.buffer[1] = stage_v_145_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int sub_step_146_1 = ((sub_step_135_1 + pub_r000893_9_1) + 35) & 127;
  int sub_step_146_2 = ((sub_step_135_2 + pub_r000893_9_2) + 35) & 127;
  int stage_v_146_1 = ((sub_step_146_1 * 2) + pub_r000893_19_1) & 127;
  int stage_v_146_2 = ((sub_step_146_2 * 2) + pub_r000893_19_2) & 127;
  st_var_2_1.buffer[2] = stage_v_146_1 & 15;
  st_var_2_2.buffer[2] = stage_v_146_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int sub_step_147_1 = ((sub_step_73_1 + pub_r000893_19_1) + 30) & 127;
  int sub_step_147_2 = ((sub_step_73_2 + pub_r000893_19_2) + 30) & 127;
  int stage_v_147_1 = ((sub_step_147_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_147_2 = ((sub_step_147_2 * 2) + pub_r000893_20_2) & 127;
  st_var_3_1.buffer[0] = stage_v_147_1 & 15;
  st_var_3_2.buffer[0] = stage_v_147_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int sub_step_148_1 = ((stage_v_134_1 + pub_r000893_14_1) + 20) & 127;
  int sub_step_148_2 = ((stage_v_134_2 + pub_r000893_14_2) + 20) & 127;
  int stage_v_148_1 = ((sub_step_148_1 * 2) + pub_r000893_18_1) & 127;
  int stage_v_148_2 = ((sub_step_148_2 * 2) + pub_r000893_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_148_1 & 15;
  st_var_0_2.buffer[1] = stage_v_148_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int sub_step_149_1 = ((stage_v_84_1 + pub_r000893_0_1) + 14) & 127;
  int sub_step_149_2 = ((stage_v_84_2 + pub_r000893_0_2) + 14) & 127;
  int stage_v_149_1 = ((sub_step_149_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_149_2 = ((sub_step_149_2 * 2) + pub_r000893_6_2) & 127;
  st_var_1_1.buffer[2] = stage_v_149_1 & 15;
  st_var_1_2.buffer[2] = stage_v_149_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int sub_step_150_1 = ((sub_step_89_1 + pub_r000893_11_1) + 8) & 127;
  int sub_step_150_2 = ((sub_step_89_2 + pub_r000893_11_2) + 8) & 127;
  int stage_v_150_1 = ((sub_step_150_1 * 2) + pub_r000893_18_1) & 127;
  int stage_v_150_2 = ((sub_step_150_2 * 2) + pub_r000893_18_2) & 127;
  st_var_2_1.buffer[0] = stage_v_150_1 & 15;
  st_var_2_2.buffer[0] = stage_v_150_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int sub_step_151_1 = ((sub_step_122_1 + pub_r000893_19_1) + 12) & 127;
  int sub_step_151_2 = ((sub_step_122_2 + pub_r000893_19_2) + 12) & 127;
  int stage_v_151_1 = ((sub_step_151_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_151_2 = ((sub_step_151_2 * 2) + pub_r000893_22_2) & 127;
  st_var_3_1.buffer[1] = stage_v_151_1 & 15;
  st_var_3_2.buffer[1] = stage_v_151_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int sub_step_152_1 = ((sub_step_94_1 + pub_r000893_14_1) + 32) & 127;
  int sub_step_152_2 = ((sub_step_94_2 + pub_r000893_14_2) + 32) & 127;
  int stage_v_152_1 = ((sub_step_152_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_152_2 = ((sub_step_152_2 * 2) + pub_r000893_20_2) & 127;
  st_var_0_1.buffer[2] = stage_v_152_1 & 15;
  st_var_0_2.buffer[2] = stage_v_152_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int sub_step_153_1 = ((sec_r000893_7_1 + pub_r000893_1_1) + 20) & 127;
  int sub_step_153_2 = ((sec_r000893_7_2 + pub_r000893_1_2) + 20) & 127;
  int stage_v_153_1 = ((sub_step_153_1 * 2) + pub_r000893_13_1) & 127;
  int stage_v_153_2 = ((sub_step_153_2 * 2) + pub_r000893_13_2) & 127;
  st_var_1_1.buffer[0] = stage_v_153_1 & 15;
  st_var_1_2.buffer[0] = stage_v_153_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int sub_step_154_1 = ((sec_r000893_7_1 + pub_r000893_22_1) + 26) & 127;
  int sub_step_154_2 = ((sec_r000893_7_2 + pub_r000893_22_2) + 26) & 127;
  int stage_v_154_1 = ((sub_step_154_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_154_2 = ((sub_step_154_2 * 2) + pub_r000893_22_2) & 127;
  st_var_2_1.buffer[1] = stage_v_154_1 & 15;
  st_var_2_2.buffer[1] = stage_v_154_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int sub_step_155_1 = ((stage_v_142_1 + pub_r000893_5_1) + 28) & 127;
  int sub_step_155_2 = ((stage_v_142_2 + pub_r000893_5_2) + 28) & 127;
  int stage_v_155_1 = ((sub_step_155_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_155_2 = ((sub_step_155_2 * 2) + pub_r000893_3_2) & 127;
  st_var_3_1.buffer[2] = stage_v_155_1 & 15;
  st_var_3_2.buffer[2] = stage_v_155_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int sub_step_156_1 = ((sub_step_133_1 + pub_r000893_21_1) + 27) & 127;
  int sub_step_156_2 = ((sub_step_133_2 + pub_r000893_21_2) + 27) & 127;
  int stage_v_156_1 = ((sub_step_156_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_156_2 = ((sub_step_156_2 * 2) + pub_r000893_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_156_1 & 15;
  st_var_0_2.buffer[0] = stage_v_156_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int sub_step_157_1 = ((stage_v_107_1 + pub_r000893_15_1) + 21) & 127;
  int sub_step_157_2 = ((stage_v_107_2 + pub_r000893_15_2) + 21) & 127;
  int stage_v_157_1 = ((sub_step_157_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_157_2 = ((sub_step_157_2 * 2) + pub_r000893_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_157_1 & 15;
  st_var_1_2.buffer[1] = stage_v_157_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int sub_step_158_1 = ((sec_r000893_0_1 + pub_r000893_14_1) + 33) & 127;
  int sub_step_158_2 = ((sec_r000893_0_2 + pub_r000893_14_2) + 33) & 127;
  int stage_v_158_1 = ((sub_step_158_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_158_2 = ((sub_step_158_2 * 2) + pub_r000893_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_158_1 & 15;
  st_var_2_2.buffer[2] = stage_v_158_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int sub_step_159_1 = ((stage_v_150_1 + pub_r000893_13_1) + 30) & 127;
  int sub_step_159_2 = ((stage_v_150_2 + pub_r000893_13_2) + 30) & 127;
  int stage_v_159_1 = ((sub_step_159_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_159_2 = ((sub_step_159_2 * 2) + pub_r000893_8_2) & 127;
  st_var_3_1.buffer[0] = stage_v_159_1 & 15;
  st_var_3_2.buffer[0] = stage_v_159_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int sub_step_160_1 = ((sec_r000893_12_1 + pub_r000893_11_1) + 18) & 127;
  int sub_step_160_2 = ((sec_r000893_12_2 + pub_r000893_11_2) + 18) & 127;
  int stage_v_160_1 = ((sub_step_160_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_160_2 = ((sub_step_160_2 * 2) + pub_r000893_20_2) & 127;
  st_var_0_1.buffer[1] = stage_v_160_1 & 15;
  st_var_0_2.buffer[1] = stage_v_160_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int sub_step_161_1 = ((stage_v_129_1 + pub_r000893_17_1) + 33) & 127;
  int sub_step_161_2 = ((stage_v_129_2 + pub_r000893_17_2) + 33) & 127;
  int stage_v_161_1 = ((sub_step_161_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_161_2 = ((sub_step_161_2 * 2) + pub_r000893_23_2) & 127;
  st_var_1_1.buffer[2] = stage_v_161_1 & 15;
  st_var_1_2.buffer[2] = stage_v_161_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int sub_step_162_1 = ((sec_r000893_15_1 + pub_r000893_23_1) + 15) & 127;
  int sub_step_162_2 = ((sec_r000893_15_2 + pub_r000893_23_2) + 15) & 127;
  int stage_v_162_1 = ((sub_step_162_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_162_2 = ((sub_step_162_2 * 2) + pub_r000893_22_2) & 127;
  st_var_2_1.buffer[0] = stage_v_162_1 & 15;
  st_var_2_2.buffer[0] = stage_v_162_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int sub_step_163_1 = ((stage_v_99_1 + pub_r000893_20_1) + 5) & 127;
  int sub_step_163_2 = ((stage_v_99_2 + pub_r000893_20_2) + 5) & 127;
  int stage_v_163_1 = ((sub_step_163_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_163_2 = ((sub_step_163_2 * 2) + pub_r000893_3_2) & 127;
  st_var_3_1.buffer[1] = stage_v_163_1 & 15;
  st_var_3_2.buffer[1] = stage_v_163_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int sub_step_164_1 = ((sub_step_76_1 + pub_r000893_1_1) + 11) & 127;
  int sub_step_164_2 = ((sub_step_76_2 + pub_r000893_1_2) + 11) & 127;
  int stage_v_164_1 = ((sub_step_164_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_164_2 = ((sub_step_164_2 * 2) + pub_r000893_23_2) & 127;
  st_var_0_1.buffer[2] = stage_v_164_1 & 15;
  st_var_0_2.buffer[2] = stage_v_164_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int sub_step_165_1 = ((stage_v_128_1 + pub_r000893_17_1) + 26) & 127;
  int sub_step_165_2 = ((stage_v_128_2 + pub_r000893_17_2) + 26) & 127;
  int stage_v_165_1 = ((sub_step_165_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_165_2 = ((sub_step_165_2 * 2) + pub_r000893_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_165_1 & 15;
  st_var_1_2.buffer[0] = stage_v_165_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int sub_step_166_1 = ((sec_r000893_13_1 + pub_r000893_12_1) + 22) & 127;
  int sub_step_166_2 = ((sec_r000893_13_2 + pub_r000893_12_2) + 22) & 127;
  int stage_v_166_1 = ((sub_step_166_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_166_2 = ((sub_step_166_2 * 2) + pub_r000893_6_2) & 127;
  st_var_2_1.buffer[1] = stage_v_166_1 & 15;
  st_var_2_2.buffer[1] = stage_v_166_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int sub_step_167_1 = ((sub_step_145_1 + pub_r000893_10_1) + 25) & 127;
  int sub_step_167_2 = ((sub_step_145_2 + pub_r000893_10_2) + 25) & 127;
  int stage_v_167_1 = ((sub_step_167_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_167_2 = ((sub_step_167_2 * 2) + pub_r000893_23_2) & 127;
  st_var_3_1.buffer[2] = stage_v_167_1 & 15;
  st_var_3_2.buffer[2] = stage_v_167_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int sub_step_168_1 = ((sec_r000893_13_1 + pub_r000893_15_1) + 13) & 127;
  int sub_step_168_2 = ((sec_r000893_13_2 + pub_r000893_15_2) + 13) & 127;
  int stage_v_168_1 = ((sub_step_168_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_168_2 = ((sub_step_168_2 * 2) + pub_r000893_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_168_1 & 15;
  st_var_0_2.buffer[0] = stage_v_168_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int sub_step_169_1 = ((sec_r000893_12_1 + pub_r000893_23_1) + 25) & 127;
  int sub_step_169_2 = ((sec_r000893_12_2 + pub_r000893_23_2) + 25) & 127;
  int stage_v_169_1 = ((sub_step_169_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_169_2 = ((sub_step_169_2 * 2) + pub_r000893_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_169_1 & 15;
  st_var_1_2.buffer[1] = stage_v_169_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int sub_step_170_1 = ((sub_step_61_1 + pub_r000893_9_1) + 33) & 127;
  int sub_step_170_2 = ((sub_step_61_2 + pub_r000893_9_2) + 33) & 127;
  int stage_v_170_1 = ((sub_step_170_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_170_2 = ((sub_step_170_2 * 2) + pub_r000893_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_170_1 & 15;
  st_var_2_2.buffer[2] = stage_v_170_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int sub_step_171_1 = ((sec_r000893_10_1 + pub_r000893_9_1) + 33) & 127;
  int sub_step_171_2 = ((sec_r000893_10_2 + pub_r000893_9_2) + 33) & 127;
  int stage_v_171_1 = ((sub_step_171_1 * 2) + pub_r000893_9_1) & 127;
  int stage_v_171_2 = ((sub_step_171_2 * 2) + pub_r000893_9_2) & 127;
  st_var_3_1.buffer[0] = stage_v_171_1 & 15;
  st_var_3_2.buffer[0] = stage_v_171_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int sub_step_172_1 = ((stage_v_138_1 + pub_r000893_11_1) + 13) & 127;
  int sub_step_172_2 = ((stage_v_138_2 + pub_r000893_11_2) + 13) & 127;
  int stage_v_172_1 = ((sub_step_172_1 * 2) + pub_r000893_1_1) & 127;
  int stage_v_172_2 = ((sub_step_172_2 * 2) + pub_r000893_1_2) & 127;
  st_var_0_1.buffer[1] = stage_v_172_1 & 15;
  st_var_0_2.buffer[1] = stage_v_172_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int sub_step_173_1 = ((sec_r000893_12_1 + pub_r000893_7_1) + 10) & 127;
  int sub_step_173_2 = ((sec_r000893_12_2 + pub_r000893_7_2) + 10) & 127;
  int stage_v_173_1 = ((sub_step_173_1 * 2) + pub_r000893_4_1) & 127;
  int stage_v_173_2 = ((sub_step_173_2 * 2) + pub_r000893_4_2) & 127;
  st_var_1_1.buffer[2] = stage_v_173_1 & 15;
  st_var_1_2.buffer[2] = stage_v_173_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int sub_step_174_1 = ((stage_v_86_1 + pub_r000893_16_1) + 23) & 127;
  int sub_step_174_2 = ((stage_v_86_2 + pub_r000893_16_2) + 23) & 127;
  int stage_v_174_1 = ((sub_step_174_1 * 2) + pub_r000893_18_1) & 127;
  int stage_v_174_2 = ((sub_step_174_2 * 2) + pub_r000893_18_2) & 127;
  st_var_2_1.buffer[0] = stage_v_174_1 & 15;
  st_var_2_2.buffer[0] = stage_v_174_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int sub_step_175_1 = ((sub_step_121_1 + pub_r000893_6_1) + 25) & 127;
  int sub_step_175_2 = ((sub_step_121_2 + pub_r000893_6_2) + 25) & 127;
  int stage_v_175_1 = ((sub_step_175_1 * 2) + pub_r000893_19_1) & 127;
  int stage_v_175_2 = ((sub_step_175_2 * 2) + pub_r000893_19_2) & 127;
  st_var_3_1.buffer[1] = stage_v_175_1 & 15;
  st_var_3_2.buffer[1] = stage_v_175_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int sub_step_176_1 = ((sec_r000893_14_1 + pub_r000893_7_1) + 32) & 127;
  int sub_step_176_2 = ((sec_r000893_14_2 + pub_r000893_7_2) + 32) & 127;
  int stage_v_176_1 = ((sub_step_176_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_176_2 = ((sub_step_176_2 * 2) + pub_r000893_8_2) & 127;
  st_var_0_1.buffer[2] = stage_v_176_1 & 15;
  st_var_0_2.buffer[2] = stage_v_176_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int sub_step_177_1 = ((stage_v_57_1 + pub_r000893_1_1) + 23) & 127;
  int sub_step_177_2 = ((stage_v_57_2 + pub_r000893_1_2) + 23) & 127;
  int stage_v_177_1 = ((sub_step_177_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_177_2 = ((sub_step_177_2 * 2) + pub_r000893_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_177_1 & 15;
  st_var_1_2.buffer[0] = stage_v_177_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int sub_step_178_1 = ((stage_v_159_1 + pub_r000893_17_1) + 24) & 127;
  int sub_step_178_2 = ((stage_v_159_2 + pub_r000893_17_2) + 24) & 127;
  int stage_v_178_1 = ((sub_step_178_1 * 2) + pub_r000893_9_1) & 127;
  int stage_v_178_2 = ((sub_step_178_2 * 2) + pub_r000893_9_2) & 127;
  st_var_2_1.buffer[1] = stage_v_178_1 & 15;
  st_var_2_2.buffer[1] = stage_v_178_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int sub_step_179_1 = ((stage_v_124_1 + pub_r000893_18_1) + 18) & 127;
  int sub_step_179_2 = ((stage_v_124_2 + pub_r000893_18_2) + 18) & 127;
  int stage_v_179_1 = ((sub_step_179_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_179_2 = ((sub_step_179_2 * 2) + pub_r000893_8_2) & 127;
  st_var_3_1.buffer[2] = stage_v_179_1 & 15;
  st_var_3_2.buffer[2] = stage_v_179_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int sub_step_180_1 = ((sub_step_145_1 + pub_r000893_2_1) + 10) & 127;
  int sub_step_180_2 = ((sub_step_145_2 + pub_r000893_2_2) + 10) & 127;
  int stage_v_180_1 = ((sub_step_180_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_180_2 = ((sub_step_180_2 * 2) + pub_r000893_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_180_1 & 15;
  st_var_0_2.buffer[0] = stage_v_180_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int sub_step_181_1 = ((sub_step_126_1 + pub_r000893_23_1) + 15) & 127;
  int sub_step_181_2 = ((sub_step_126_2 + pub_r000893_23_2) + 15) & 127;
  int stage_v_181_1 = ((sub_step_181_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_181_2 = ((sub_step_181_2 * 2) + pub_r000893_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_181_1 & 15;
  st_var_1_2.buffer[1] = stage_v_181_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int sub_step_182_1 = ((sec_r000893_11_1 + pub_r000893_11_1) + 15) & 127;
  int sub_step_182_2 = ((sec_r000893_11_2 + pub_r000893_11_2) + 15) & 127;
  int stage_v_182_1 = ((sub_step_182_1 * 2) + pub_r000893_13_1) & 127;
  int stage_v_182_2 = ((sub_step_182_2 * 2) + pub_r000893_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_182_1 & 15;
  st_var_2_2.buffer[2] = stage_v_182_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int sub_step_183_1 = ((sub_step_78_1 + pub_r000893_5_1) + 25) & 127;
  int sub_step_183_2 = ((sub_step_78_2 + pub_r000893_5_2) + 25) & 127;
  int stage_v_183_1 = ((sub_step_183_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_183_2 = ((sub_step_183_2 * 2) + pub_r000893_17_2) & 127;
  st_var_3_1.buffer[0] = stage_v_183_1 & 15;
  st_var_3_2.buffer[0] = stage_v_183_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int sub_step_184_1 = ((sub_step_130_1 + pub_r000893_9_1) + 14) & 127;
  int sub_step_184_2 = ((sub_step_130_2 + pub_r000893_9_2) + 14) & 127;
  int stage_v_184_1 = ((sub_step_184_1 * 2) + pub_r000893_18_1) & 127;
  int stage_v_184_2 = ((sub_step_184_2 * 2) + pub_r000893_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_184_1 & 15;
  st_var_0_2.buffer[1] = stage_v_184_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int sub_step_185_1 = ((sub_step_130_1 + pub_r000893_0_1) + 6) & 127;
  int sub_step_185_2 = ((sub_step_130_2 + pub_r000893_0_2) + 6) & 127;
  int stage_v_185_1 = ((sub_step_185_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_185_2 = ((sub_step_185_2 * 2) + pub_r000893_22_2) & 127;
  st_var_1_1.buffer[2] = stage_v_185_1 & 15;
  st_var_1_2.buffer[2] = stage_v_185_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int sub_step_186_1 = ((sub_step_139_1 + pub_r000893_19_1) + 35) & 127;
  int sub_step_186_2 = ((sub_step_139_2 + pub_r000893_19_2) + 35) & 127;
  int stage_v_186_1 = ((sub_step_186_1 * 2) + pub_r000893_5_1) & 127;
  int stage_v_186_2 = ((sub_step_186_2 * 2) + pub_r000893_5_2) & 127;
  st_var_2_1.buffer[0] = stage_v_186_1 & 15;
  st_var_2_2.buffer[0] = stage_v_186_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int sub_step_187_1 = ((stage_v_82_1 + pub_r000893_11_1) + 30) & 127;
  int sub_step_187_2 = ((stage_v_82_2 + pub_r000893_11_2) + 30) & 127;
  int stage_v_187_1 = ((sub_step_187_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_187_2 = ((sub_step_187_2 * 2) + pub_r000893_10_2) & 127;
  st_var_3_1.buffer[1] = stage_v_187_1 & 15;
  st_var_3_2.buffer[1] = stage_v_187_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int sub_step_188_1 = ((sub_step_132_1 + pub_r000893_5_1) + 10) & 127;
  int sub_step_188_2 = ((sub_step_132_2 + pub_r000893_5_2) + 10) & 127;
  int stage_v_188_1 = ((sub_step_188_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_188_2 = ((sub_step_188_2 * 2) + pub_r000893_6_2) & 127;
  st_var_0_1.buffer[2] = stage_v_188_1 & 15;
  st_var_0_2.buffer[2] = stage_v_188_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int sub_step_189_1 = ((stage_v_163_1 + pub_r000893_11_1) + 14) & 127;
  int sub_step_189_2 = ((stage_v_163_2 + pub_r000893_11_2) + 14) & 127;
  int stage_v_189_1 = ((sub_step_189_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_189_2 = ((sub_step_189_2 * 2) + pub_r000893_15_2) & 127;
  st_var_1_1.buffer[0] = stage_v_189_1 & 15;
  st_var_1_2.buffer[0] = stage_v_189_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int sub_step_190_1 = ((sub_step_121_1 + pub_r000893_14_1) + 5) & 127;
  int sub_step_190_2 = ((sub_step_121_2 + pub_r000893_14_2) + 5) & 127;
  int stage_v_190_1 = ((sub_step_190_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_190_2 = ((sub_step_190_2 * 2) + pub_r000893_10_2) & 127;
  st_var_2_1.buffer[1] = stage_v_190_1 & 15;
  st_var_2_2.buffer[1] = stage_v_190_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int sub_step_191_1 = ((stage_v_142_1 + pub_r000893_15_1) + 15) & 127;
  int sub_step_191_2 = ((stage_v_142_2 + pub_r000893_15_2) + 15) & 127;
  int stage_v_191_1 = ((sub_step_191_1 * 2) + pub_r000893_18_1) & 127;
  int stage_v_191_2 = ((sub_step_191_2 * 2) + pub_r000893_18_2) & 127;
  st_var_3_1.buffer[2] = stage_v_191_1 & 15;
  st_var_3_2.buffer[2] = stage_v_191_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int sub_step_192_1 = ((sec_r000893_13_1 + pub_r000893_9_1) + 12) & 127;
  int sub_step_192_2 = ((sec_r000893_13_2 + pub_r000893_9_2) + 12) & 127;
  int stage_v_192_1 = ((sub_step_192_1 * 2) + pub_r000893_7_1) & 127;
  int stage_v_192_2 = ((sub_step_192_2 * 2) + pub_r000893_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_192_1 & 15;
  st_var_0_2.buffer[0] = stage_v_192_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int sub_step_193_1 = ((sec_r000893_4_1 + pub_r000893_19_1) + 20) & 127;
  int sub_step_193_2 = ((sec_r000893_4_2 + pub_r000893_19_2) + 20) & 127;
  int stage_v_193_1 = ((sub_step_193_1 * 2) + pub_r000893_1_1) & 127;
  int stage_v_193_2 = ((sub_step_193_2 * 2) + pub_r000893_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_193_1 & 15;
  st_var_1_2.buffer[1] = stage_v_193_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int sub_step_194_1 = ((sec_r000893_12_1 + pub_r000893_10_1) + 7) & 127;
  int sub_step_194_2 = ((sec_r000893_12_2 + pub_r000893_10_2) + 7) & 127;
  int stage_v_194_1 = ((sub_step_194_1 * 2) + pub_r000893_13_1) & 127;
  int stage_v_194_2 = ((sub_step_194_2 * 2) + pub_r000893_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_194_1 & 15;
  st_var_2_2.buffer[2] = stage_v_194_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int sub_step_195_1 = ((stage_v_149_1 + pub_r000893_18_1) + 16) & 127;
  int sub_step_195_2 = ((stage_v_149_2 + pub_r000893_18_2) + 16) & 127;
  int stage_v_195_1 = ((sub_step_195_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_195_2 = ((sub_step_195_2 * 2) + pub_r000893_20_2) & 127;
  st_var_3_1.buffer[0] = stage_v_195_1 & 15;
  st_var_3_2.buffer[0] = stage_v_195_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int sub_step_196_1 = ((sec_r000893_0_1 + pub_r000893_8_1) + 31) & 127;
  int sub_step_196_2 = ((sec_r000893_0_2 + pub_r000893_8_2) + 31) & 127;
  int stage_v_196_1 = ((sub_step_196_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_196_2 = ((sub_step_196_2 * 2) + pub_r000893_23_2) & 127;
  st_var_0_1.buffer[1] = stage_v_196_1 & 15;
  st_var_0_2.buffer[1] = stage_v_196_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int sub_step_197_1 = ((stage_v_164_1 + pub_r000893_21_1) + 14) & 127;
  int sub_step_197_2 = ((stage_v_164_2 + pub_r000893_21_2) + 14) & 127;
  int stage_v_197_1 = ((sub_step_197_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_197_2 = ((sub_step_197_2 * 2) + pub_r000893_3_2) & 127;
  st_var_1_1.buffer[2] = stage_v_197_1 & 15;
  st_var_1_2.buffer[2] = stage_v_197_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int sub_step_198_1 = ((sec_r000893_3_1 + pub_r000893_14_1) + 15) & 127;
  int sub_step_198_2 = ((sec_r000893_3_2 + pub_r000893_14_2) + 15) & 127;
  int stage_v_198_1 = ((sub_step_198_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_198_2 = ((sub_step_198_2 * 2) + pub_r000893_2_2) & 127;
  st_var_2_1.buffer[0] = stage_v_198_1 & 15;
  st_var_2_2.buffer[0] = stage_v_198_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int sub_step_199_1 = ((stage_v_176_1 + pub_r000893_3_1) + 10) & 127;
  int sub_step_199_2 = ((stage_v_176_2 + pub_r000893_3_2) + 10) & 127;
  int stage_v_199_1 = ((sub_step_199_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_199_2 = ((sub_step_199_2 * 2) + pub_r000893_17_2) & 127;
  st_var_3_1.buffer[1] = stage_v_199_1 & 15;
  st_var_3_2.buffer[1] = stage_v_199_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int sub_step_200_1 = ((sec_r000893_3_1 + pub_r000893_8_1) + 20) & 127;
  int sub_step_200_2 = ((sec_r000893_3_2 + pub_r000893_8_2) + 20) & 127;
  int stage_v_200_1 = ((sub_step_200_1 * 2) + pub_r000893_21_1) & 127;
  int stage_v_200_2 = ((sub_step_200_2 * 2) + pub_r000893_21_2) & 127;
  st_var_0_1.buffer[2] = stage_v_200_1 & 15;
  st_var_0_2.buffer[2] = stage_v_200_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int sub_step_201_1 = ((sec_r000893_1_1 + pub_r000893_22_1) + 13) & 127;
  int sub_step_201_2 = ((sec_r000893_1_2 + pub_r000893_22_2) + 13) & 127;
  int stage_v_201_1 = ((sub_step_201_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_201_2 = ((sub_step_201_2 * 2) + pub_r000893_6_2) & 127;
  st_var_1_1.buffer[0] = stage_v_201_1 & 15;
  st_var_1_2.buffer[0] = stage_v_201_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int sub_step_202_1 = ((stage_v_137_1 + pub_r000893_16_1) + 34) & 127;
  int sub_step_202_2 = ((stage_v_137_2 + pub_r000893_16_2) + 34) & 127;
  int stage_v_202_1 = ((sub_step_202_1 * 2) + pub_r000893_14_1) & 127;
  int stage_v_202_2 = ((sub_step_202_2 * 2) + pub_r000893_14_2) & 127;
  st_var_2_1.buffer[1] = stage_v_202_1 & 15;
  st_var_2_2.buffer[1] = stage_v_202_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int sub_step_203_1 = ((sub_step_151_1 + pub_r000893_22_1) + 33) & 127;
  int sub_step_203_2 = ((sub_step_151_2 + pub_r000893_22_2) + 33) & 127;
  int stage_v_203_1 = ((sub_step_203_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_203_2 = ((sub_step_203_2 * 2) + pub_r000893_2_2) & 127;
  st_var_3_1.buffer[2] = stage_v_203_1 & 15;
  st_var_3_2.buffer[2] = stage_v_203_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int sub_step_204_1 = ((stage_v_82_1 + pub_r000893_10_1) + 11) & 127;
  int sub_step_204_2 = ((stage_v_82_2 + pub_r000893_10_2) + 11) & 127;
  int stage_v_204_1 = ((sub_step_204_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_204_2 = ((sub_step_204_2 * 2) + pub_r000893_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_204_1 & 15;
  st_var_0_2.buffer[0] = stage_v_204_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int sub_step_205_1 = ((sec_r000893_6_1 + pub_r000893_4_1) + 30) & 127;
  int sub_step_205_2 = ((sec_r000893_6_2 + pub_r000893_4_2) + 30) & 127;
  int stage_v_205_1 = ((sub_step_205_1 * 2) + pub_r000893_5_1) & 127;
  int stage_v_205_2 = ((sub_step_205_2 * 2) + pub_r000893_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_205_1 & 15;
  st_var_1_2.buffer[1] = stage_v_205_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int sub_step_206_1 = ((stage_v_195_1 + pub_r000893_18_1) + 28) & 127;
  int sub_step_206_2 = ((stage_v_195_2 + pub_r000893_18_2) + 28) & 127;
  int stage_v_206_1 = ((sub_step_206_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_206_2 = ((sub_step_206_2 * 2) + pub_r000893_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_206_1 & 15;
  st_var_2_2.buffer[2] = stage_v_206_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int sub_step_207_1 = ((stage_v_119_1 + pub_r000893_0_1) + 27) & 127;
  int sub_step_207_2 = ((stage_v_119_2 + pub_r000893_0_2) + 27) & 127;
  int stage_v_207_1 = ((sub_step_207_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_207_2 = ((sub_step_207_2 * 2) + pub_r000893_8_2) & 127;
  st_var_3_1.buffer[0] = stage_v_207_1 & 15;
  st_var_3_2.buffer[0] = stage_v_207_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int sub_step_208_1 = ((sec_r000893_2_1 + pub_r000893_4_1) + 23) & 127;
  int sub_step_208_2 = ((sec_r000893_2_2 + pub_r000893_4_2) + 23) & 127;
  int stage_v_208_1 = ((sub_step_208_1 * 2) + pub_r000893_18_1) & 127;
  int stage_v_208_2 = ((sub_step_208_2 * 2) + pub_r000893_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_208_1 & 15;
  st_var_0_2.buffer[1] = stage_v_208_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int sub_step_209_1 = ((stage_v_92_1 + pub_r000893_14_1) + 14) & 127;
  int sub_step_209_2 = ((stage_v_92_2 + pub_r000893_14_2) + 14) & 127;
  int stage_v_209_1 = ((sub_step_209_1 * 2) + pub_r000893_21_1) & 127;
  int stage_v_209_2 = ((sub_step_209_2 * 2) + pub_r000893_21_2) & 127;
  st_var_1_1.buffer[2] = stage_v_209_1 & 15;
  st_var_1_2.buffer[2] = stage_v_209_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int sub_step_210_1 = ((sub_step_168_1 + pub_r000893_4_1) + 30) & 127;
  int sub_step_210_2 = ((sub_step_168_2 + pub_r000893_4_2) + 30) & 127;
  int stage_v_210_1 = ((sub_step_210_1 * 2) + pub_r000893_21_1) & 127;
  int stage_v_210_2 = ((sub_step_210_2 * 2) + pub_r000893_21_2) & 127;
  st_var_2_1.buffer[0] = stage_v_210_1 & 15;
  st_var_2_2.buffer[0] = stage_v_210_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int sub_step_211_1 = ((sec_r000893_2_1 + pub_r000893_4_1) + 9) & 127;
  int sub_step_211_2 = ((sec_r000893_2_2 + pub_r000893_4_2) + 9) & 127;
  int stage_v_211_1 = ((sub_step_211_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_211_2 = ((sub_step_211_2 * 2) + pub_r000893_11_2) & 127;
  st_var_3_1.buffer[1] = stage_v_211_1 & 15;
  st_var_3_2.buffer[1] = stage_v_211_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int sub_step_212_1 = ((sec_r000893_15_1 + pub_r000893_18_1) + 32) & 127;
  int sub_step_212_2 = ((sec_r000893_15_2 + pub_r000893_18_2) + 32) & 127;
  int stage_v_212_1 = ((sub_step_212_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_212_2 = ((sub_step_212_2 * 2) + pub_r000893_11_2) & 127;
  st_var_0_1.buffer[2] = stage_v_212_1 & 15;
  st_var_0_2.buffer[2] = stage_v_212_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int sub_step_213_1 = ((stage_v_81_1 + pub_r000893_4_1) + 8) & 127;
  int sub_step_213_2 = ((stage_v_81_2 + pub_r000893_4_2) + 8) & 127;
  int stage_v_213_1 = ((sub_step_213_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_213_2 = ((sub_step_213_2 * 2) + pub_r000893_22_2) & 127;
  st_var_1_1.buffer[0] = stage_v_213_1 & 15;
  st_var_1_2.buffer[0] = stage_v_213_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int sub_step_214_1 = ((sec_r000893_8_1 + pub_r000893_23_1) + 5) & 127;
  int sub_step_214_2 = ((sec_r000893_8_2 + pub_r000893_23_2) + 5) & 127;
  int stage_v_214_1 = ((sub_step_214_1 * 2) + pub_r000893_19_1) & 127;
  int stage_v_214_2 = ((sub_step_214_2 * 2) + pub_r000893_19_2) & 127;
  st_var_2_1.buffer[1] = stage_v_214_1 & 15;
  st_var_2_2.buffer[1] = stage_v_214_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int sub_step_215_1 = ((stage_v_73_1 + pub_r000893_23_1) + 35) & 127;
  int sub_step_215_2 = ((stage_v_73_2 + pub_r000893_23_2) + 35) & 127;
  int stage_v_215_1 = ((sub_step_215_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_215_2 = ((sub_step_215_2 * 2) + pub_r000893_6_2) & 127;
  st_var_3_1.buffer[2] = stage_v_215_1 & 15;
  st_var_3_2.buffer[2] = stage_v_215_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int sub_step_216_1 = ((sub_step_188_1 + pub_r000893_18_1) + 28) & 127;
  int sub_step_216_2 = ((sub_step_188_2 + pub_r000893_18_2) + 28) & 127;
  int stage_v_216_1 = ((sub_step_216_1 * 2) + pub_r000893_4_1) & 127;
  int stage_v_216_2 = ((sub_step_216_2 * 2) + pub_r000893_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_216_1 & 15;
  st_var_0_2.buffer[0] = stage_v_216_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int sub_step_217_1 = ((sec_r000893_5_1 + pub_r000893_2_1) + 28) & 127;
  int sub_step_217_2 = ((sec_r000893_5_2 + pub_r000893_2_2) + 28) & 127;
  int stage_v_217_1 = ((sub_step_217_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_217_2 = ((sub_step_217_2 * 2) + pub_r000893_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_217_1 & 15;
  st_var_1_2.buffer[1] = stage_v_217_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int sub_step_218_1 = ((stage_v_182_1 + pub_r000893_21_1) + 26) & 127;
  int sub_step_218_2 = ((stage_v_182_2 + pub_r000893_21_2) + 26) & 127;
  int stage_v_218_1 = ((sub_step_218_1 * 2) + pub_r000893_18_1) & 127;
  int stage_v_218_2 = ((sub_step_218_2 * 2) + pub_r000893_18_2) & 127;
  st_var_2_1.buffer[2] = stage_v_218_1 & 15;
  st_var_2_2.buffer[2] = stage_v_218_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int sub_step_219_1 = ((sec_r000893_9_1 + pub_r000893_3_1) + 24) & 127;
  int sub_step_219_2 = ((sec_r000893_9_2 + pub_r000893_3_2) + 24) & 127;
  int stage_v_219_1 = ((sub_step_219_1 * 2) + pub_r000893_12_1) & 127;
  int stage_v_219_2 = ((sub_step_219_2 * 2) + pub_r000893_12_2) & 127;
  st_var_3_1.buffer[0] = stage_v_219_1 & 15;
  st_var_3_2.buffer[0] = stage_v_219_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int sub_step_220_1 = ((stage_v_120_1 + pub_r000893_20_1) + 34) & 127;
  int sub_step_220_2 = ((stage_v_120_2 + pub_r000893_20_2) + 34) & 127;
  int stage_v_220_1 = ((sub_step_220_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_220_2 = ((sub_step_220_2 * 2) + pub_r000893_23_2) & 127;
  st_var_0_1.buffer[1] = stage_v_220_1 & 15;
  st_var_0_2.buffer[1] = stage_v_220_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int sub_step_221_1 = ((sec_r000893_12_1 + pub_r000893_11_1) + 28) & 127;
  int sub_step_221_2 = ((sec_r000893_12_2 + pub_r000893_11_2) + 28) & 127;
  int stage_v_221_1 = ((sub_step_221_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_221_2 = ((sub_step_221_2 * 2) + pub_r000893_2_2) & 127;
  st_var_1_1.buffer[2] = stage_v_221_1 & 15;
  st_var_1_2.buffer[2] = stage_v_221_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int sub_step_222_1 = ((stage_v_89_1 + pub_r000893_17_1) + 31) & 127;
  int sub_step_222_2 = ((stage_v_89_2 + pub_r000893_17_2) + 31) & 127;
  int stage_v_222_1 = ((sub_step_222_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_222_2 = ((sub_step_222_2 * 2) + pub_r000893_10_2) & 127;
  st_var_2_1.buffer[0] = stage_v_222_1 & 15;
  st_var_2_2.buffer[0] = stage_v_222_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int sub_step_223_1 = ((sec_r000893_0_1 + pub_r000893_9_1) + 24) & 127;
  int sub_step_223_2 = ((sec_r000893_0_2 + pub_r000893_9_2) + 24) & 127;
  int stage_v_223_1 = ((sub_step_223_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_223_2 = ((sub_step_223_2 * 2) + pub_r000893_0_2) & 127;
  st_var_3_1.buffer[1] = stage_v_223_1 & 15;
  st_var_3_2.buffer[1] = stage_v_223_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int sub_step_224_1 = ((stage_v_88_1 + pub_r000893_23_1) + 33) & 127;
  int sub_step_224_2 = ((stage_v_88_2 + pub_r000893_23_2) + 33) & 127;
  int stage_v_224_1 = ((sub_step_224_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_224_2 = ((sub_step_224_2 * 2) + pub_r000893_23_2) & 127;
  st_var_0_1.buffer[2] = stage_v_224_1 & 15;
  st_var_0_2.buffer[2] = stage_v_224_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int sub_step_225_1 = ((sub_step_108_1 + pub_r000893_6_1) + 29) & 127;
  int sub_step_225_2 = ((sub_step_108_2 + pub_r000893_6_2) + 29) & 127;
  int stage_v_225_1 = ((sub_step_225_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_225_2 = ((sub_step_225_2 * 2) + pub_r000893_17_2) & 127;
  st_var_1_1.buffer[0] = stage_v_225_1 & 15;
  st_var_1_2.buffer[0] = stage_v_225_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int sub_step_226_1 = ((sub_step_202_1 + pub_r000893_20_1) + 23) & 127;
  int sub_step_226_2 = ((sub_step_202_2 + pub_r000893_20_2) + 23) & 127;
  int stage_v_226_1 = ((sub_step_226_1 * 2) + pub_r000893_13_1) & 127;
  int stage_v_226_2 = ((sub_step_226_2 * 2) + pub_r000893_13_2) & 127;
  st_var_2_1.buffer[1] = stage_v_226_1 & 15;
  st_var_2_2.buffer[1] = stage_v_226_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int sub_step_227_1 = ((sub_step_173_1 + pub_r000893_1_1) + 22) & 127;
  int sub_step_227_2 = ((sub_step_173_2 + pub_r000893_1_2) + 22) & 127;
  int stage_v_227_1 = ((sub_step_227_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_227_2 = ((sub_step_227_2 * 2) + pub_r000893_0_2) & 127;
  st_var_3_1.buffer[2] = stage_v_227_1 & 15;
  st_var_3_2.buffer[2] = stage_v_227_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int sub_step_228_1 = ((stage_v_218_1 + pub_r000893_2_1) + 32) & 127;
  int sub_step_228_2 = ((stage_v_218_2 + pub_r000893_2_2) + 32) & 127;
  int stage_v_228_1 = ((sub_step_228_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_228_2 = ((sub_step_228_2 * 2) + pub_r000893_22_2) & 127;
  st_var_0_1.buffer[0] = stage_v_228_1 & 15;
  st_var_0_2.buffer[0] = stage_v_228_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int sub_step_229_1 = ((stage_v_129_1 + pub_r000893_3_1) + 11) & 127;
  int sub_step_229_2 = ((stage_v_129_2 + pub_r000893_3_2) + 11) & 127;
  int stage_v_229_1 = ((sub_step_229_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_229_2 = ((sub_step_229_2 * 2) + pub_r000893_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_229_1 & 15;
  st_var_1_2.buffer[1] = stage_v_229_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int sub_step_230_1 = ((sub_step_193_1 + pub_r000893_9_1) + 5) & 127;
  int sub_step_230_2 = ((sub_step_193_2 + pub_r000893_9_2) + 5) & 127;
  int stage_v_230_1 = ((sub_step_230_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_230_2 = ((sub_step_230_2 * 2) + pub_r000893_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_230_1 & 15;
  st_var_2_2.buffer[2] = stage_v_230_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int sub_step_231_1 = ((sub_step_60_1 + pub_r000893_3_1) + 6) & 127;
  int sub_step_231_2 = ((sub_step_60_2 + pub_r000893_3_2) + 6) & 127;
  int stage_v_231_1 = ((sub_step_231_1 * 2) + pub_r000893_1_1) & 127;
  int stage_v_231_2 = ((sub_step_231_2 * 2) + pub_r000893_1_2) & 127;
  st_var_3_1.buffer[0] = stage_v_231_1 & 15;
  st_var_3_2.buffer[0] = stage_v_231_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int sub_step_232_1 = ((sec_r000893_8_1 + pub_r000893_18_1) + 9) & 127;
  int sub_step_232_2 = ((sec_r000893_8_2 + pub_r000893_18_2) + 9) & 127;
  int stage_v_232_1 = ((sub_step_232_1 * 2) + pub_r000893_5_1) & 127;
  int stage_v_232_2 = ((sub_step_232_2 * 2) + pub_r000893_5_2) & 127;
  st_var_0_1.buffer[1] = stage_v_232_1 & 15;
  st_var_0_2.buffer[1] = stage_v_232_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int sub_step_233_1 = ((stage_v_203_1 + pub_r000893_14_1) + 19) & 127;
  int sub_step_233_2 = ((stage_v_203_2 + pub_r000893_14_2) + 19) & 127;
  int stage_v_233_1 = ((sub_step_233_1 * 2) + pub_r000893_7_1) & 127;
  int stage_v_233_2 = ((sub_step_233_2 * 2) + pub_r000893_7_2) & 127;
  st_var_1_1.buffer[2] = stage_v_233_1 & 15;
  st_var_1_2.buffer[2] = stage_v_233_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int sub_step_234_1 = ((sec_r000893_2_1 + pub_r000893_4_1) + 20) & 127;
  int sub_step_234_2 = ((sec_r000893_2_2 + pub_r000893_4_2) + 20) & 127;
  int stage_v_234_1 = ((sub_step_234_1 * 2) + pub_r000893_7_1) & 127;
  int stage_v_234_2 = ((sub_step_234_2 * 2) + pub_r000893_7_2) & 127;
  st_var_2_1.buffer[0] = stage_v_234_1 & 15;
  st_var_2_2.buffer[0] = stage_v_234_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int sub_step_235_1 = ((stage_v_69_1 + pub_r000893_11_1) + 32) & 127;
  int sub_step_235_2 = ((stage_v_69_2 + pub_r000893_11_2) + 32) & 127;
  int stage_v_235_1 = ((sub_step_235_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_235_2 = ((sub_step_235_2 * 2) + pub_r000893_3_2) & 127;
  st_var_3_1.buffer[1] = stage_v_235_1 & 15;
  st_var_3_2.buffer[1] = stage_v_235_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int sub_step_236_1 = ((stage_v_170_1 + pub_r000893_1_1) + 20) & 127;
  int sub_step_236_2 = ((stage_v_170_2 + pub_r000893_1_2) + 20) & 127;
  int stage_v_236_1 = ((sub_step_236_1 * 2) + pub_r000893_16_1) & 127;
  int stage_v_236_2 = ((sub_step_236_2 * 2) + pub_r000893_16_2) & 127;
  st_var_0_1.buffer[2] = stage_v_236_1 & 15;
  st_var_0_2.buffer[2] = stage_v_236_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int sub_step_237_1 = ((stage_v_74_1 + pub_r000893_1_1) + 21) & 127;
  int sub_step_237_2 = ((stage_v_74_2 + pub_r000893_1_2) + 21) & 127;
  int stage_v_237_1 = ((sub_step_237_1 * 2) + pub_r000893_7_1) & 127;
  int stage_v_237_2 = ((sub_step_237_2 * 2) + pub_r000893_7_2) & 127;
  st_var_1_1.buffer[0] = stage_v_237_1 & 15;
  st_var_1_2.buffer[0] = stage_v_237_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int sub_step_238_1 = ((sub_step_94_1 + pub_r000893_23_1) + 27) & 127;
  int sub_step_238_2 = ((sub_step_94_2 + pub_r000893_23_2) + 27) & 127;
  int stage_v_238_1 = ((sub_step_238_1 * 2) + pub_r000893_1_1) & 127;
  int stage_v_238_2 = ((sub_step_238_2 * 2) + pub_r000893_1_2) & 127;
  st_var_2_1.buffer[1] = stage_v_238_1 & 15;
  st_var_2_2.buffer[1] = stage_v_238_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int sub_step_239_1 = ((stage_v_230_1 + pub_r000893_13_1) + 9) & 127;
  int sub_step_239_2 = ((stage_v_230_2 + pub_r000893_13_2) + 9) & 127;
  int stage_v_239_1 = ((sub_step_239_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_239_2 = ((sub_step_239_2 * 2) + pub_r000893_3_2) & 127;
  st_var_3_1.buffer[2] = stage_v_239_1 & 15;
  st_var_3_2.buffer[2] = stage_v_239_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int sub_step_240_1 = ((sec_r000893_14_1 + pub_r000893_2_1) + 18) & 127;
  int sub_step_240_2 = ((sec_r000893_14_2 + pub_r000893_2_2) + 18) & 127;
  int stage_v_240_1 = ((sub_step_240_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_240_2 = ((sub_step_240_2 * 2) + pub_r000893_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_240_1 & 15;
  st_var_0_2.buffer[0] = stage_v_240_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int sub_step_241_1 = ((sub_step_229_1 + pub_r000893_10_1) + 10) & 127;
  int sub_step_241_2 = ((sub_step_229_2 + pub_r000893_10_2) + 10) & 127;
  int stage_v_241_1 = ((sub_step_241_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_241_2 = ((sub_step_241_2 * 2) + pub_r000893_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_241_1 & 15;
  st_var_1_2.buffer[1] = stage_v_241_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int sub_step_242_1 = ((sub_step_56_1 + pub_r000893_21_1) + 7) & 127;
  int sub_step_242_2 = ((sub_step_56_2 + pub_r000893_21_2) + 7) & 127;
  int stage_v_242_1 = ((sub_step_242_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_242_2 = ((sub_step_242_2 * 2) + pub_r000893_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_242_1 & 15;
  st_var_2_2.buffer[2] = stage_v_242_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int sub_step_243_1 = ((sec_r000893_11_1 + pub_r000893_5_1) + 21) & 127;
  int sub_step_243_2 = ((sec_r000893_11_2 + pub_r000893_5_2) + 21) & 127;
  int stage_v_243_1 = ((sub_step_243_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_243_2 = ((sub_step_243_2 * 2) + pub_r000893_20_2) & 127;
  st_var_3_1.buffer[0] = stage_v_243_1 & 15;
  st_var_3_2.buffer[0] = stage_v_243_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int sub_step_244_1 = ((sec_r000893_2_1 + pub_r000893_14_1) + 17) & 127;
  int sub_step_244_2 = ((sec_r000893_2_2 + pub_r000893_14_2) + 17) & 127;
  int stage_v_244_1 = ((sub_step_244_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_244_2 = ((sub_step_244_2 * 2) + pub_r000893_11_2) & 127;
  st_var_0_1.buffer[1] = stage_v_244_1 & 15;
  st_var_0_2.buffer[1] = stage_v_244_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int sub_step_245_1 = ((stage_v_232_1 + pub_r000893_11_1) + 23) & 127;
  int sub_step_245_2 = ((stage_v_232_2 + pub_r000893_11_2) + 23) & 127;
  int stage_v_245_1 = ((sub_step_245_1 * 2) + pub_r000893_12_1) & 127;
  int stage_v_245_2 = ((sub_step_245_2 * 2) + pub_r000893_12_2) & 127;
  st_var_1_1.buffer[2] = stage_v_245_1 & 15;
  st_var_1_2.buffer[2] = stage_v_245_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int sub_step_246_1 = ((sub_step_223_1 + pub_r000893_11_1) + 14) & 127;
  int sub_step_246_2 = ((sub_step_223_2 + pub_r000893_11_2) + 14) & 127;
  int stage_v_246_1 = ((sub_step_246_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_246_2 = ((sub_step_246_2 * 2) + pub_r000893_22_2) & 127;
  st_var_2_1.buffer[0] = stage_v_246_1 & 15;
  st_var_2_2.buffer[0] = stage_v_246_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int sub_step_247_1 = ((sec_r000893_1_1 + pub_r000893_0_1) + 19) & 127;
  int sub_step_247_2 = ((sec_r000893_1_2 + pub_r000893_0_2) + 19) & 127;
  int stage_v_247_1 = ((sub_step_247_1 * 2) + pub_r000893_4_1) & 127;
  int stage_v_247_2 = ((sub_step_247_2 * 2) + pub_r000893_4_2) & 127;
  st_var_3_1.buffer[1] = stage_v_247_1 & 15;
  st_var_3_2.buffer[1] = stage_v_247_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int sub_step_248_1 = ((sub_step_208_1 + pub_r000893_15_1) + 6) & 127;
  int sub_step_248_2 = ((sub_step_208_2 + pub_r000893_15_2) + 6) & 127;
  int stage_v_248_1 = ((sub_step_248_1 * 2) + pub_r000893_9_1) & 127;
  int stage_v_248_2 = ((sub_step_248_2 * 2) + pub_r000893_9_2) & 127;
  st_var_0_1.buffer[2] = stage_v_248_1 & 15;
  st_var_0_2.buffer[2] = stage_v_248_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int sub_step_249_1 = ((sec_r000893_0_1 + pub_r000893_1_1) + 10) & 127;
  int sub_step_249_2 = ((sec_r000893_0_2 + pub_r000893_1_2) + 10) & 127;
  int stage_v_249_1 = ((sub_step_249_1 * 2) + pub_r000893_19_1) & 127;
  int stage_v_249_2 = ((sub_step_249_2 * 2) + pub_r000893_19_2) & 127;
  st_var_1_1.buffer[0] = stage_v_249_1 & 15;
  st_var_1_2.buffer[0] = stage_v_249_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int sub_step_250_1 = ((stage_v_98_1 + pub_r000893_21_1) + 15) & 127;
  int sub_step_250_2 = ((stage_v_98_2 + pub_r000893_21_2) + 15) & 127;
  int stage_v_250_1 = ((sub_step_250_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_250_2 = ((sub_step_250_2 * 2) + pub_r000893_15_2) & 127;
  st_var_2_1.buffer[1] = stage_v_250_1 & 15;
  st_var_2_2.buffer[1] = stage_v_250_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int sub_step_251_1 = ((sub_step_111_1 + pub_r000893_11_1) + 15) & 127;
  int sub_step_251_2 = ((sub_step_111_2 + pub_r000893_11_2) + 15) & 127;
  int stage_v_251_1 = ((sub_step_251_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_251_2 = ((sub_step_251_2 * 2) + pub_r000893_23_2) & 127;
  st_var_3_1.buffer[2] = stage_v_251_1 & 15;
  st_var_3_2.buffer[2] = stage_v_251_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int sub_step_252_1 = ((sub_step_157_1 + pub_r000893_14_1) + 19) & 127;
  int sub_step_252_2 = ((sub_step_157_2 + pub_r000893_14_2) + 19) & 127;
  int stage_v_252_1 = ((sub_step_252_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_252_2 = ((sub_step_252_2 * 2) + pub_r000893_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_252_1 & 15;
  st_var_0_2.buffer[0] = stage_v_252_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int sub_step_253_1 = ((sub_step_131_1 + pub_r000893_16_1) + 33) & 127;
  int sub_step_253_2 = ((sub_step_131_2 + pub_r000893_16_2) + 33) & 127;
  int stage_v_253_1 = ((sub_step_253_1 * 2) + pub_r000893_7_1) & 127;
  int stage_v_253_2 = ((sub_step_253_2 * 2) + pub_r000893_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_253_1 & 15;
  st_var_1_2.buffer[1] = stage_v_253_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int sub_step_254_1 = ((stage_v_61_1 + pub_r000893_9_1) + 6) & 127;
  int sub_step_254_2 = ((stage_v_61_2 + pub_r000893_9_2) + 6) & 127;
  int stage_v_254_1 = ((sub_step_254_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_254_2 = ((sub_step_254_2 * 2) + pub_r000893_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_254_1 & 15;
  st_var_2_2.buffer[2] = stage_v_254_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int sub_step_255_1 = ((sec_r000893_9_1 + pub_r000893_5_1) + 21) & 127;
  int sub_step_255_2 = ((sec_r000893_9_2 + pub_r000893_5_2) + 21) & 127;
  int stage_v_255_1 = ((sub_step_255_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_255_2 = ((sub_step_255_2 * 2) + pub_r000893_15_2) & 127;
  st_var_3_1.buffer[0] = stage_v_255_1 & 15;
  st_var_3_2.buffer[0] = stage_v_255_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int sub_step_256_1 = ((sub_step_240_1 + pub_r000893_19_1) + 5) & 127;
  int sub_step_256_2 = ((sub_step_240_2 + pub_r000893_19_2) + 5) & 127;
  int stage_v_256_1 = ((sub_step_256_1 * 2) + pub_r000893_21_1) & 127;
  int stage_v_256_2 = ((sub_step_256_2 * 2) + pub_r000893_21_2) & 127;
  st_var_0_1.buffer[1] = stage_v_256_1 & 15;
  st_var_0_2.buffer[1] = stage_v_256_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int sub_step_257_1 = ((stage_v_173_1 + pub_r000893_17_1) + 24) & 127;
  int sub_step_257_2 = ((stage_v_173_2 + pub_r000893_17_2) + 24) & 127;
  int stage_v_257_1 = ((sub_step_257_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_257_2 = ((sub_step_257_2 * 2) + pub_r000893_10_2) & 127;
  st_var_1_1.buffer[2] = stage_v_257_1 & 15;
  st_var_1_2.buffer[2] = stage_v_257_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int sub_step_258_1 = ((sub_step_253_1 + pub_r000893_13_1) + 11) & 127;
  int sub_step_258_2 = ((sub_step_253_2 + pub_r000893_13_2) + 11) & 127;
  int stage_v_258_1 = ((sub_step_258_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_258_2 = ((sub_step_258_2 * 2) + pub_r000893_8_2) & 127;
  st_var_2_1.buffer[0] = stage_v_258_1 & 15;
  st_var_2_2.buffer[0] = stage_v_258_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int sub_step_259_1 = ((sec_r000893_11_1 + pub_r000893_15_1) + 8) & 127;
  int sub_step_259_2 = ((sec_r000893_11_2 + pub_r000893_15_2) + 8) & 127;
  int stage_v_259_1 = ((sub_step_259_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_259_2 = ((sub_step_259_2 * 2) + pub_r000893_0_2) & 127;
  st_var_3_1.buffer[1] = stage_v_259_1 & 15;
  st_var_3_2.buffer[1] = stage_v_259_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int sub_step_260_1 = ((sub_step_133_1 + pub_r000893_10_1) + 27) & 127;
  int sub_step_260_2 = ((sub_step_133_2 + pub_r000893_10_2) + 27) & 127;
  int stage_v_260_1 = ((sub_step_260_1 * 2) + pub_r000893_4_1) & 127;
  int stage_v_260_2 = ((sub_step_260_2 * 2) + pub_r000893_4_2) & 127;
  st_var_0_1.buffer[2] = stage_v_260_1 & 15;
  st_var_0_2.buffer[2] = stage_v_260_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int sub_step_261_1 = ((sec_r000893_0_1 + pub_r000893_0_1) + 6) & 127;
  int sub_step_261_2 = ((sec_r000893_0_2 + pub_r000893_0_2) + 6) & 127;
  int stage_v_261_1 = ((sub_step_261_1 * 2) + pub_r000893_12_1) & 127;
  int stage_v_261_2 = ((sub_step_261_2 * 2) + pub_r000893_12_2) & 127;
  st_var_1_1.buffer[0] = stage_v_261_1 & 15;
  st_var_1_2.buffer[0] = stage_v_261_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int sub_step_262_1 = ((sub_step_76_1 + pub_r000893_17_1) + 26) & 127;
  int sub_step_262_2 = ((sub_step_76_2 + pub_r000893_17_2) + 26) & 127;
  int stage_v_262_1 = ((sub_step_262_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_262_2 = ((sub_step_262_2 * 2) + pub_r000893_8_2) & 127;
  st_var_2_1.buffer[1] = stage_v_262_1 & 15;
  st_var_2_2.buffer[1] = stage_v_262_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int sub_step_263_1 = ((sub_step_150_1 + pub_r000893_17_1) + 22) & 127;
  int sub_step_263_2 = ((sub_step_150_2 + pub_r000893_17_2) + 22) & 127;
  int stage_v_263_1 = ((sub_step_263_1 * 2) + pub_r000893_9_1) & 127;
  int stage_v_263_2 = ((sub_step_263_2 * 2) + pub_r000893_9_2) & 127;
  st_var_3_1.buffer[2] = stage_v_263_1 & 15;
  st_var_3_2.buffer[2] = stage_v_263_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int sub_step_264_1 = ((sec_r000893_5_1 + pub_r000893_8_1) + 10) & 127;
  int sub_step_264_2 = ((sec_r000893_5_2 + pub_r000893_8_2) + 10) & 127;
  int stage_v_264_1 = ((sub_step_264_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_264_2 = ((sub_step_264_2 * 2) + pub_r000893_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_264_1 & 15;
  st_var_0_2.buffer[0] = stage_v_264_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int sub_step_265_1 = ((stage_v_70_1 + pub_r000893_12_1) + 21) & 127;
  int sub_step_265_2 = ((stage_v_70_2 + pub_r000893_12_2) + 21) & 127;
  int stage_v_265_1 = ((sub_step_265_1 * 2) + pub_r000893_13_1) & 127;
  int stage_v_265_2 = ((sub_step_265_2 * 2) + pub_r000893_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_265_1 & 15;
  st_var_1_2.buffer[1] = stage_v_265_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int sub_step_266_1 = ((sub_step_259_1 + pub_r000893_11_1) + 30) & 127;
  int sub_step_266_2 = ((sub_step_259_2 + pub_r000893_11_2) + 30) & 127;
  int stage_v_266_1 = ((sub_step_266_1 * 2) + pub_r000893_17_1) & 127;
  int stage_v_266_2 = ((sub_step_266_2 * 2) + pub_r000893_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_266_1 & 15;
  st_var_2_2.buffer[2] = stage_v_266_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int sub_step_267_1 = ((sec_r000893_15_1 + pub_r000893_12_1) + 13) & 127;
  int sub_step_267_2 = ((sec_r000893_15_2 + pub_r000893_12_2) + 13) & 127;
  int stage_v_267_1 = ((sub_step_267_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_267_2 = ((sub_step_267_2 * 2) + pub_r000893_20_2) & 127;
  st_var_3_1.buffer[0] = stage_v_267_1 & 15;
  st_var_3_2.buffer[0] = stage_v_267_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int sub_step_268_1 = ((stage_v_262_1 + pub_r000893_22_1) + 34) & 127;
  int sub_step_268_2 = ((stage_v_262_2 + pub_r000893_22_2) + 34) & 127;
  int stage_v_268_1 = ((sub_step_268_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_268_2 = ((sub_step_268_2 * 2) + pub_r000893_6_2) & 127;
  st_var_0_1.buffer[1] = stage_v_268_1 & 15;
  st_var_0_2.buffer[1] = stage_v_268_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int sub_step_269_1 = ((sec_r000893_13_1 + pub_r000893_22_1) + 24) & 127;
  int sub_step_269_2 = ((sec_r000893_13_2 + pub_r000893_22_2) + 24) & 127;
  int stage_v_269_1 = ((sub_step_269_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_269_2 = ((sub_step_269_2 * 2) + pub_r000893_8_2) & 127;
  st_var_1_1.buffer[2] = stage_v_269_1 & 15;
  st_var_1_2.buffer[2] = stage_v_269_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int sub_step_270_1 = ((sec_r000893_11_1 + pub_r000893_12_1) + 8) & 127;
  int sub_step_270_2 = ((sec_r000893_11_2 + pub_r000893_12_2) + 8) & 127;
  int stage_v_270_1 = ((sub_step_270_1 * 2) + pub_r000893_7_1) & 127;
  int stage_v_270_2 = ((sub_step_270_2 * 2) + pub_r000893_7_2) & 127;
  st_var_2_1.buffer[0] = stage_v_270_1 & 15;
  st_var_2_2.buffer[0] = stage_v_270_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int sub_step_271_1 = ((sub_step_225_1 + pub_r000893_1_1) + 12) & 127;
  int sub_step_271_2 = ((sub_step_225_2 + pub_r000893_1_2) + 12) & 127;
  int stage_v_271_1 = ((sub_step_271_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_271_2 = ((sub_step_271_2 * 2) + pub_r000893_3_2) & 127;
  st_var_3_1.buffer[1] = stage_v_271_1 & 15;
  st_var_3_2.buffer[1] = stage_v_271_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int sub_step_272_1 = ((sec_r000893_11_1 + pub_r000893_18_1) + 33) & 127;
  int sub_step_272_2 = ((sec_r000893_11_2 + pub_r000893_18_2) + 33) & 127;
  int stage_v_272_1 = ((sub_step_272_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_272_2 = ((sub_step_272_2 * 2) + pub_r000893_8_2) & 127;
  st_var_0_1.buffer[2] = stage_v_272_1 & 15;
  st_var_0_2.buffer[2] = stage_v_272_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int sub_step_273_1 = ((sec_r000893_1_1 + pub_r000893_1_1) + 5) & 127;
  int sub_step_273_2 = ((sec_r000893_1_2 + pub_r000893_1_2) + 5) & 127;
  int stage_v_273_1 = ((sub_step_273_1 * 2) + pub_r000893_13_1) & 127;
  int stage_v_273_2 = ((sub_step_273_2 * 2) + pub_r000893_13_2) & 127;
  st_var_1_1.buffer[0] = stage_v_273_1 & 15;
  st_var_1_2.buffer[0] = stage_v_273_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int sub_step_274_1 = ((stage_v_130_1 + pub_r000893_2_1) + 17) & 127;
  int sub_step_274_2 = ((stage_v_130_2 + pub_r000893_2_2) + 17) & 127;
  int stage_v_274_1 = ((sub_step_274_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_274_2 = ((sub_step_274_2 * 2) + pub_r000893_11_2) & 127;
  st_var_2_1.buffer[1] = stage_v_274_1 & 15;
  st_var_2_2.buffer[1] = stage_v_274_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int sub_step_275_1 = ((sub_step_72_1 + pub_r000893_18_1) + 22) & 127;
  int sub_step_275_2 = ((sub_step_72_2 + pub_r000893_18_2) + 22) & 127;
  int stage_v_275_1 = ((sub_step_275_1 * 2) + pub_r000893_22_1) & 127;
  int stage_v_275_2 = ((sub_step_275_2 * 2) + pub_r000893_22_2) & 127;
  st_var_3_1.buffer[2] = stage_v_275_1 & 15;
  st_var_3_2.buffer[2] = stage_v_275_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int sub_step_276_1 = ((sub_step_144_1 + pub_r000893_23_1) + 31) & 127;
  int sub_step_276_2 = ((sub_step_144_2 + pub_r000893_23_2) + 31) & 127;
  int stage_v_276_1 = ((sub_step_276_1 * 2) + pub_r000893_1_1) & 127;
  int stage_v_276_2 = ((sub_step_276_2 * 2) + pub_r000893_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_276_1 & 15;
  st_var_0_2.buffer[0] = stage_v_276_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int sub_step_277_1 = ((sub_step_205_1 + pub_r000893_16_1) + 22) & 127;
  int sub_step_277_2 = ((sub_step_205_2 + pub_r000893_16_2) + 22) & 127;
  int stage_v_277_1 = ((sub_step_277_1 * 2) + pub_r000893_23_1) & 127;
  int stage_v_277_2 = ((sub_step_277_2 * 2) + pub_r000893_23_2) & 127;
  st_var_1_1.buffer[1] = stage_v_277_1 & 15;
  st_var_1_2.buffer[1] = stage_v_277_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int sub_step_278_1 = ((stage_v_261_1 + pub_r000893_8_1) + 13) & 127;
  int sub_step_278_2 = ((stage_v_261_2 + pub_r000893_8_2) + 13) & 127;
  int stage_v_278_1 = ((sub_step_278_1 * 2) + pub_r000893_0_1) & 127;
  int stage_v_278_2 = ((sub_step_278_2 * 2) + pub_r000893_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_278_1 & 15;
  st_var_2_2.buffer[2] = stage_v_278_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int sub_step_279_1 = ((sub_step_230_1 + pub_r000893_22_1) + 23) & 127;
  int sub_step_279_2 = ((sub_step_230_2 + pub_r000893_22_2) + 23) & 127;
  int stage_v_279_1 = ((sub_step_279_1 * 2) + pub_r000893_19_1) & 127;
  int stage_v_279_2 = ((sub_step_279_2 * 2) + pub_r000893_19_2) & 127;
  st_var_3_1.buffer[0] = stage_v_279_1 & 15;
  st_var_3_2.buffer[0] = stage_v_279_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int sub_step_280_1 = ((sec_r000893_5_1 + pub_r000893_11_1) + 22) & 127;
  int sub_step_280_2 = ((sec_r000893_5_2 + pub_r000893_11_2) + 22) & 127;
  int stage_v_280_1 = ((sub_step_280_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_280_2 = ((sub_step_280_2 * 2) + pub_r000893_20_2) & 127;
  st_var_0_1.buffer[1] = stage_v_280_1 & 15;
  st_var_0_2.buffer[1] = stage_v_280_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int sub_step_281_1 = ((stage_v_140_1 + pub_r000893_9_1) + 29) & 127;
  int sub_step_281_2 = ((stage_v_140_2 + pub_r000893_9_2) + 29) & 127;
  int stage_v_281_1 = ((sub_step_281_1 * 2) + pub_r000893_18_1) & 127;
  int stage_v_281_2 = ((sub_step_281_2 * 2) + pub_r000893_18_2) & 127;
  st_var_1_1.buffer[2] = stage_v_281_1 & 15;
  st_var_1_2.buffer[2] = stage_v_281_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int sub_step_282_1 = ((stage_v_114_1 + pub_r000893_13_1) + 7) & 127;
  int sub_step_282_2 = ((stage_v_114_2 + pub_r000893_13_2) + 7) & 127;
  int stage_v_282_1 = ((sub_step_282_1 * 2) + pub_r000893_5_1) & 127;
  int stage_v_282_2 = ((sub_step_282_2 * 2) + pub_r000893_5_2) & 127;
  st_var_2_1.buffer[0] = stage_v_282_1 & 15;
  st_var_2_2.buffer[0] = stage_v_282_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int sub_step_283_1 = ((sec_r000893_4_1 + pub_r000893_3_1) + 25) & 127;
  int sub_step_283_2 = ((sec_r000893_4_2 + pub_r000893_3_2) + 25) & 127;
  int stage_v_283_1 = ((sub_step_283_1 * 2) + pub_r000893_21_1) & 127;
  int stage_v_283_2 = ((sub_step_283_2 * 2) + pub_r000893_21_2) & 127;
  st_var_3_1.buffer[1] = stage_v_283_1 & 15;
  st_var_3_2.buffer[1] = stage_v_283_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int sub_step_284_1 = ((sec_r000893_14_1 + pub_r000893_2_1) + 18) & 127;
  int sub_step_284_2 = ((sec_r000893_14_2 + pub_r000893_2_2) + 18) & 127;
  int stage_v_284_1 = ((sub_step_284_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_284_2 = ((sub_step_284_2 * 2) + pub_r000893_11_2) & 127;
  st_var_0_1.buffer[2] = stage_v_284_1 & 15;
  st_var_0_2.buffer[2] = stage_v_284_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int sub_step_285_1 = ((stage_v_113_1 + pub_r000893_4_1) + 10) & 127;
  int sub_step_285_2 = ((stage_v_113_2 + pub_r000893_4_2) + 10) & 127;
  int stage_v_285_1 = ((sub_step_285_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_285_2 = ((sub_step_285_2 * 2) + pub_r000893_3_2) & 127;
  st_var_1_1.buffer[0] = stage_v_285_1 & 15;
  st_var_1_2.buffer[0] = stage_v_285_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int sub_step_286_1 = ((sub_step_281_1 + pub_r000893_7_1) + 32) & 127;
  int sub_step_286_2 = ((sub_step_281_2 + pub_r000893_7_2) + 32) & 127;
  int stage_v_286_1 = ((sub_step_286_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_286_2 = ((sub_step_286_2 * 2) + pub_r000893_8_2) & 127;
  st_var_2_1.buffer[1] = stage_v_286_1 & 15;
  st_var_2_2.buffer[1] = stage_v_286_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int sub_step_287_1 = ((stage_v_65_1 + pub_r000893_23_1) + 28) & 127;
  int sub_step_287_2 = ((stage_v_65_2 + pub_r000893_23_2) + 28) & 127;
  int stage_v_287_1 = ((sub_step_287_1 * 2) + pub_r000893_13_1) & 127;
  int stage_v_287_2 = ((sub_step_287_2 * 2) + pub_r000893_13_2) & 127;
  st_var_3_1.buffer[2] = stage_v_287_1 & 15;
  st_var_3_2.buffer[2] = stage_v_287_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int sub_step_288_1 = ((sub_step_165_1 + pub_r000893_6_1) + 27) & 127;
  int sub_step_288_2 = ((sub_step_165_2 + pub_r000893_6_2) + 27) & 127;
  int stage_v_288_1 = ((sub_step_288_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_288_2 = ((sub_step_288_2 * 2) + pub_r000893_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_288_1 & 15;
  st_var_0_2.buffer[0] = stage_v_288_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int sub_step_289_1 = ((stage_v_109_1 + pub_r000893_20_1) + 7) & 127;
  int sub_step_289_2 = ((stage_v_109_2 + pub_r000893_20_2) + 7) & 127;
  int stage_v_289_1 = ((sub_step_289_1 * 2) + pub_r000893_10_1) & 127;
  int stage_v_289_2 = ((sub_step_289_2 * 2) + pub_r000893_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_289_1 & 15;
  st_var_1_2.buffer[1] = stage_v_289_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int sub_step_290_1 = ((sub_step_62_1 + pub_r000893_17_1) + 34) & 127;
  int sub_step_290_2 = ((sub_step_62_2 + pub_r000893_17_2) + 34) & 127;
  int stage_v_290_1 = ((sub_step_290_1 * 2) + pub_r000893_5_1) & 127;
  int stage_v_290_2 = ((sub_step_290_2 * 2) + pub_r000893_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_290_1 & 15;
  st_var_2_2.buffer[2] = stage_v_290_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int sub_step_291_1 = ((stage_v_180_1 + pub_r000893_16_1) + 23) & 127;
  int sub_step_291_2 = ((stage_v_180_2 + pub_r000893_16_2) + 23) & 127;
  int stage_v_291_1 = ((sub_step_291_1 * 2) + pub_r000893_2_1) & 127;
  int stage_v_291_2 = ((sub_step_291_2 * 2) + pub_r000893_2_2) & 127;
  st_var_3_1.buffer[0] = stage_v_291_1 & 15;
  st_var_3_2.buffer[0] = stage_v_291_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int sub_step_292_1 = ((stage_v_264_1 + pub_r000893_15_1) + 22) & 127;
  int sub_step_292_2 = ((stage_v_264_2 + pub_r000893_15_2) + 22) & 127;
  int stage_v_292_1 = ((sub_step_292_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_292_2 = ((sub_step_292_2 * 2) + pub_r000893_20_2) & 127;
  st_var_0_1.buffer[1] = stage_v_292_1 & 15;
  st_var_0_2.buffer[1] = stage_v_292_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int sub_step_293_1 = ((sub_step_98_1 + pub_r000893_6_1) + 14) & 127;
  int sub_step_293_2 = ((sub_step_98_2 + pub_r000893_6_2) + 14) & 127;
  int stage_v_293_1 = ((sub_step_293_1 * 2) + pub_r000893_6_1) & 127;
  int stage_v_293_2 = ((sub_step_293_2 * 2) + pub_r000893_6_2) & 127;
  st_var_1_1.buffer[2] = stage_v_293_1 & 15;
  st_var_1_2.buffer[2] = stage_v_293_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int sub_step_294_1 = ((sec_r000893_4_1 + pub_r000893_15_1) + 24) & 127;
  int sub_step_294_2 = ((sec_r000893_4_2 + pub_r000893_15_2) + 24) & 127;
  int stage_v_294_1 = ((sub_step_294_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_294_2 = ((sub_step_294_2 * 2) + pub_r000893_11_2) & 127;
  st_var_2_1.buffer[0] = stage_v_294_1 & 15;
  st_var_2_2.buffer[0] = stage_v_294_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int sub_step_295_1 = ((sub_step_97_1 + pub_r000893_16_1) + 19) & 127;
  int sub_step_295_2 = ((sub_step_97_2 + pub_r000893_16_2) + 19) & 127;
  int stage_v_295_1 = ((sub_step_295_1 * 2) + pub_r000893_12_1) & 127;
  int stage_v_295_2 = ((sub_step_295_2 * 2) + pub_r000893_12_2) & 127;
  st_var_3_1.buffer[1] = stage_v_295_1 & 15;
  st_var_3_2.buffer[1] = stage_v_295_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int sub_step_296_1 = ((sub_step_184_1 + pub_r000893_4_1) + 30) & 127;
  int sub_step_296_2 = ((sub_step_184_2 + pub_r000893_4_2) + 30) & 127;
  int stage_v_296_1 = ((sub_step_296_1 * 2) + pub_r000893_20_1) & 127;
  int stage_v_296_2 = ((sub_step_296_2 * 2) + pub_r000893_20_2) & 127;
  st_var_0_1.buffer[2] = stage_v_296_1 & 15;
  st_var_0_2.buffer[2] = stage_v_296_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int sub_step_297_1 = ((stage_v_270_1 + pub_r000893_23_1) + 14) & 127;
  int sub_step_297_2 = ((stage_v_270_2 + pub_r000893_23_2) + 14) & 127;
  int stage_v_297_1 = ((sub_step_297_1 * 2) + pub_r000893_11_1) & 127;
  int stage_v_297_2 = ((sub_step_297_2 * 2) + pub_r000893_11_2) & 127;
  st_var_1_1.buffer[0] = stage_v_297_1 & 15;
  st_var_1_2.buffer[0] = stage_v_297_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int sub_step_298_1 = ((sec_r000893_7_1 + pub_r000893_20_1) + 10) & 127;
  int sub_step_298_2 = ((sec_r000893_7_2 + pub_r000893_20_2) + 10) & 127;
  int stage_v_298_1 = ((sub_step_298_1 * 2) + pub_r000893_5_1) & 127;
  int stage_v_298_2 = ((sub_step_298_2 * 2) + pub_r000893_5_2) & 127;
  st_var_2_1.buffer[1] = stage_v_298_1 & 15;
  st_var_2_2.buffer[1] = stage_v_298_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int sub_step_299_1 = ((sec_r000893_8_1 + pub_r000893_11_1) + 16) & 127;
  int sub_step_299_2 = ((sec_r000893_8_2 + pub_r000893_11_2) + 16) & 127;
  int stage_v_299_1 = ((sub_step_299_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_299_2 = ((sub_step_299_2 * 2) + pub_r000893_15_2) & 127;
  st_var_3_1.buffer[2] = stage_v_299_1 & 15;
  st_var_3_2.buffer[2] = stage_v_299_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int sub_step_300_1 = ((stage_v_152_1 + pub_r000893_21_1) + 8) & 127;
  int sub_step_300_2 = ((stage_v_152_2 + pub_r000893_21_2) + 8) & 127;
  int stage_v_300_1 = ((sub_step_300_1 * 2) + pub_r000893_15_1) & 127;
  int stage_v_300_2 = ((sub_step_300_2 * 2) + pub_r000893_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_300_1 & 15;
  st_var_0_2.buffer[0] = stage_v_300_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int sub_step_301_1 = ((stage_v_187_1 + pub_r000893_1_1) + 11) & 127;
  int sub_step_301_2 = ((stage_v_187_2 + pub_r000893_1_2) + 11) & 127;
  int stage_v_301_1 = ((sub_step_301_1 * 2) + pub_r000893_8_1) & 127;
  int stage_v_301_2 = ((sub_step_301_2 * 2) + pub_r000893_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_301_1 & 15;
  st_var_1_2.buffer[1] = stage_v_301_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int sub_step_302_1 = ((sub_step_205_1 + pub_r000893_2_1) + 9) & 127;
  int sub_step_302_2 = ((sub_step_205_2 + pub_r000893_2_2) + 9) & 127;
  int stage_v_302_1 = ((sub_step_302_1 * 2) + pub_r000893_16_1) & 127;
  int stage_v_302_2 = ((sub_step_302_2 * 2) + pub_r000893_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_302_1 & 15;
  st_var_2_2.buffer[2] = stage_v_302_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int sub_step_303_1 = ((sub_step_297_1 + pub_r000893_21_1) + 13) & 127;
  int sub_step_303_2 = ((sub_step_297_2 + pub_r000893_21_2) + 13) & 127;
  int stage_v_303_1 = ((sub_step_303_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_303_2 = ((sub_step_303_2 * 2) + pub_r000893_3_2) & 127;
  st_var_3_1.buffer[0] = stage_v_303_1 & 15;
  st_var_3_2.buffer[0] = stage_v_303_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int sub_step_304_1 = ((stage_v_150_1 + pub_r000893_14_1) + 23) & 127;
  int sub_step_304_2 = ((stage_v_150_2 + pub_r000893_14_2) + 23) & 127;
  int stage_v_304_1 = ((sub_step_304_1 * 2) + pub_r000893_3_1) & 127;
  int stage_v_304_2 = ((sub_step_304_2 * 2) + pub_r000893_3_2) & 127;
  st_var_0_1.buffer[1] = stage_v_304_1 & 15;
  st_var_0_2.buffer[1] = stage_v_304_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int sub_step_305_1 = ((sec_r000893_5_1 + pub_r000893_5_1) + 26) & 127;
  int sub_step_305_2 = ((sec_r000893_5_2 + pub_r000893_5_2) + 26) & 127;
  int stage_v_305_1 = ((sub_step_305_1 * 2) + pub_r000893_19_1) & 127;
  int stage_v_305_2 = ((sub_step_305_2 * 2) + pub_r000893_19_2) & 127;
  st_var_1_1.buffer[2] = stage_v_305_1 & 15;
  st_var_1_2.buffer[2] = stage_v_305_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000893_5_1 == pub_r000893_5_2);
  __CPROVER_assume(pub_r000893_9_1 == pub_r000893_9_2);
  __CPROVER_assume(pub_r000893_21_1 == pub_r000893_21_2);
  __CPROVER_assume(sec_r000893_15_1 != sec_r000893_15_2);
  __CPROVER_assume(sec_r000893_2_1 != sec_r000893_2_2);
  __CPROVER_assume(sec_r000893_9_1 != sec_r000893_9_2);
  __CPROVER_assume(pub_r000893_7_1 == pub_r000893_7_2);
  __CPROVER_assume(pub_r000893_1_1 == pub_r000893_1_2);
  __CPROVER_assume(sec_r000893_4_1 != sec_r000893_4_2);
  __CPROVER_assume(pub_r000893_17_1 == pub_r000893_17_2);
  __CPROVER_assume(pub_r000893_13_1 == pub_r000893_13_2);
  __CPROVER_assume(pub_r000893_12_1 == pub_r000893_12_2);
  __CPROVER_assume(pub_r000893_0_1 == pub_r000893_0_2);
  __CPROVER_assume(sec_r000893_11_1 != sec_r000893_11_2);
  __CPROVER_assume(pub_r000893_14_1 == pub_r000893_14_2);
  __CPROVER_assume(pub_r000893_4_1 == pub_r000893_4_2);
  __CPROVER_assume(pub_r000893_20_1 == pub_r000893_20_2);
  __CPROVER_assume(pub_r000893_16_1 == pub_r000893_16_2);
  __CPROVER_assume(pub_r000893_2_1 == pub_r000893_2_2);
  __CPROVER_assume(sec_r000893_7_1 != sec_r000893_7_2);
  __CPROVER_assume(sec_r000893_10_1 != sec_r000893_10_2);
  __CPROVER_assume(sec_r000893_6_1 != sec_r000893_6_2);
  __CPROVER_assume(pub_r000893_8_1 == pub_r000893_8_2);
  __CPROVER_assume(pub_r000893_6_1 == pub_r000893_6_2);
  __CPROVER_assume(pub_r000893_23_1 == pub_r000893_23_2);
  __CPROVER_assume(pub_r000893_19_1 == pub_r000893_19_2);
  __CPROVER_assume(sec_r000893_14_1 != sec_r000893_14_2);
  __CPROVER_assume(pub_r000893_10_1 == pub_r000893_10_2);
  __CPROVER_assume(pub_r000893_18_1 == pub_r000893_18_2);
  __CPROVER_assume(pub_r000893_11_1 == pub_r000893_11_2);
  __CPROVER_assume(sec_r000893_0_1 != sec_r000893_0_2);
  __CPROVER_assume(pub_r000893_15_1 == pub_r000893_15_2);
  __CPROVER_assume(pub_r000893_3_1 == pub_r000893_3_2);
  __CPROVER_assume(pub_r000893_22_1 == pub_r000893_22_2);
  __CPROVER_assume(sec_r000893_1_1 != sec_r000893_1_2);
  __CPROVER_assume(sec_r000893_12_1 != sec_r000893_12_2);
  __CPROVER_assume(sec_r000893_13_1 != sec_r000893_13_2);
  __CPROVER_assume(sec_r000893_3_1 != sec_r000893_3_2);
  __CPROVER_assume(sec_r000893_5_1 != sec_r000893_5_2);
  __CPROVER_assume(sec_r000893_8_1 != sec_r000893_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.trace == st_var_3_2.trace);
  assert(st_var_3_1.scale == st_var_3_2.scale);
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
  assert(sub_step_52_1 == sub_step_52_2);
  assert(stage_v_52_1 == stage_v_52_2);
  assert(sub_step_53_1 == sub_step_53_2);
  assert(stage_v_53_1 == stage_v_53_2);
  assert(sub_step_54_1 == sub_step_54_2);
  assert(stage_v_54_1 == stage_v_54_2);
  assert(sub_step_55_1 == sub_step_55_2);
  assert(stage_v_55_1 == stage_v_55_2);
  assert(sub_step_56_1 == sub_step_56_2);
  assert(stage_v_56_1 == stage_v_56_2);
  assert(sub_step_57_1 == sub_step_57_2);
  assert(stage_v_57_1 == stage_v_57_2);
  assert(sub_step_58_1 == sub_step_58_2);
  assert(stage_v_58_1 == stage_v_58_2);
  assert(sub_step_59_1 == sub_step_59_2);
  assert(stage_v_59_1 == stage_v_59_2);
  assert(sub_step_60_1 == sub_step_60_2);
  assert(stage_v_60_1 == stage_v_60_2);
  assert(sub_step_61_1 == sub_step_61_2);
  assert(stage_v_61_1 == stage_v_61_2);
  assert(sub_step_62_1 == sub_step_62_2);
  assert(stage_v_62_1 == stage_v_62_2);
  assert(sub_step_63_1 == sub_step_63_2);
  assert(stage_v_63_1 == stage_v_63_2);
  assert(sub_step_64_1 == sub_step_64_2);
  assert(stage_v_64_1 == stage_v_64_2);
  assert(sub_step_65_1 == sub_step_65_2);
  assert(stage_v_65_1 == stage_v_65_2);
  assert(sub_step_66_1 == sub_step_66_2);
  assert(stage_v_66_1 == stage_v_66_2);
  assert(sub_step_67_1 == sub_step_67_2);
  assert(stage_v_67_1 == stage_v_67_2);
  assert(sub_step_68_1 == sub_step_68_2);
  assert(stage_v_68_1 == stage_v_68_2);
  assert(sub_step_69_1 == sub_step_69_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(sub_step_70_1 == sub_step_70_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(sub_step_71_1 == sub_step_71_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(sub_step_72_1 == sub_step_72_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(sub_step_73_1 == sub_step_73_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(sub_step_74_1 == sub_step_74_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(sub_step_75_1 == sub_step_75_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(sub_step_76_1 == sub_step_76_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(sub_step_77_1 == sub_step_77_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(sub_step_78_1 == sub_step_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(sub_step_79_1 == sub_step_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(sub_step_80_1 == sub_step_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(sub_step_81_1 == sub_step_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(sub_step_82_1 == sub_step_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(sub_step_83_1 == sub_step_83_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(sub_step_84_1 == sub_step_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(sub_step_85_1 == sub_step_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(sub_step_86_1 == sub_step_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(sub_step_87_1 == sub_step_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(sub_step_88_1 == sub_step_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(sub_step_89_1 == sub_step_89_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(sub_step_90_1 == sub_step_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(sub_step_91_1 == sub_step_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(sub_step_92_1 == sub_step_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(sub_step_93_1 == sub_step_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(sub_step_94_1 == sub_step_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(sub_step_95_1 == sub_step_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(sub_step_96_1 == sub_step_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(sub_step_97_1 == sub_step_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(sub_step_98_1 == sub_step_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(sub_step_99_1 == sub_step_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(sub_step_100_1 == sub_step_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(sub_step_101_1 == sub_step_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(sub_step_102_1 == sub_step_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(sub_step_103_1 == sub_step_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(sub_step_104_1 == sub_step_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(sub_step_105_1 == sub_step_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(sub_step_106_1 == sub_step_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(sub_step_107_1 == sub_step_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(sub_step_108_1 == sub_step_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(sub_step_109_1 == sub_step_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(sub_step_110_1 == sub_step_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(sub_step_111_1 == sub_step_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(sub_step_112_1 == sub_step_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(sub_step_113_1 == sub_step_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(sub_step_114_1 == sub_step_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(sub_step_115_1 == sub_step_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(sub_step_116_1 == sub_step_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(sub_step_117_1 == sub_step_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(sub_step_118_1 == sub_step_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(sub_step_119_1 == sub_step_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(sub_step_120_1 == sub_step_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(sub_step_121_1 == sub_step_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(sub_step_122_1 == sub_step_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(sub_step_123_1 == sub_step_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(sub_step_124_1 == sub_step_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(sub_step_125_1 == sub_step_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(sub_step_126_1 == sub_step_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(sub_step_127_1 == sub_step_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(sub_step_128_1 == sub_step_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(sub_step_129_1 == sub_step_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(sub_step_130_1 == sub_step_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(sub_step_131_1 == sub_step_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(sub_step_132_1 == sub_step_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(sub_step_133_1 == sub_step_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(sub_step_134_1 == sub_step_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(sub_step_135_1 == sub_step_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(sub_step_136_1 == sub_step_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(sub_step_137_1 == sub_step_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(sub_step_138_1 == sub_step_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(sub_step_139_1 == sub_step_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(sub_step_140_1 == sub_step_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(sub_step_141_1 == sub_step_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(sub_step_142_1 == sub_step_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(sub_step_143_1 == sub_step_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(sub_step_144_1 == sub_step_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(sub_step_145_1 == sub_step_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(sub_step_146_1 == sub_step_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(sub_step_147_1 == sub_step_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(sub_step_148_1 == sub_step_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(sub_step_149_1 == sub_step_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(sub_step_150_1 == sub_step_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(sub_step_151_1 == sub_step_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(sub_step_152_1 == sub_step_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(sub_step_153_1 == sub_step_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(sub_step_154_1 == sub_step_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(sub_step_155_1 == sub_step_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(sub_step_156_1 == sub_step_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(sub_step_157_1 == sub_step_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(sub_step_158_1 == sub_step_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(sub_step_159_1 == sub_step_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(sub_step_160_1 == sub_step_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(sub_step_161_1 == sub_step_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(sub_step_162_1 == sub_step_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(sub_step_163_1 == sub_step_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(sub_step_164_1 == sub_step_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(sub_step_165_1 == sub_step_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(sub_step_166_1 == sub_step_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(sub_step_167_1 == sub_step_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(sub_step_168_1 == sub_step_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(sub_step_169_1 == sub_step_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(sub_step_170_1 == sub_step_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(sub_step_171_1 == sub_step_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(sub_step_172_1 == sub_step_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(sub_step_173_1 == sub_step_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(sub_step_174_1 == sub_step_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(sub_step_175_1 == sub_step_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(sub_step_176_1 == sub_step_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(sub_step_177_1 == sub_step_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(sub_step_178_1 == sub_step_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(sub_step_179_1 == sub_step_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(sub_step_180_1 == sub_step_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(sub_step_181_1 == sub_step_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(sub_step_182_1 == sub_step_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(sub_step_183_1 == sub_step_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(sub_step_184_1 == sub_step_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(sub_step_185_1 == sub_step_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(sub_step_186_1 == sub_step_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(sub_step_187_1 == sub_step_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(sub_step_188_1 == sub_step_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(sub_step_189_1 == sub_step_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(sub_step_190_1 == sub_step_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(sub_step_191_1 == sub_step_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(sub_step_192_1 == sub_step_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(sub_step_193_1 == sub_step_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(sub_step_194_1 == sub_step_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(sub_step_195_1 == sub_step_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(sub_step_196_1 == sub_step_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(sub_step_197_1 == sub_step_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(sub_step_198_1 == sub_step_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(sub_step_199_1 == sub_step_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(sub_step_200_1 == sub_step_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(sub_step_201_1 == sub_step_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(sub_step_202_1 == sub_step_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(sub_step_203_1 == sub_step_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(sub_step_204_1 == sub_step_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(sub_step_205_1 == sub_step_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(sub_step_206_1 == sub_step_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(sub_step_207_1 == sub_step_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(sub_step_208_1 == sub_step_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(sub_step_209_1 == sub_step_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(sub_step_210_1 == sub_step_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(sub_step_211_1 == sub_step_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(sub_step_212_1 == sub_step_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(sub_step_213_1 == sub_step_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(sub_step_214_1 == sub_step_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(sub_step_215_1 == sub_step_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(sub_step_216_1 == sub_step_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(sub_step_217_1 == sub_step_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(sub_step_218_1 == sub_step_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(sub_step_219_1 == sub_step_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(sub_step_220_1 == sub_step_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(sub_step_221_1 == sub_step_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(sub_step_222_1 == sub_step_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(sub_step_223_1 == sub_step_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(sub_step_224_1 == sub_step_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(sub_step_225_1 == sub_step_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(sub_step_226_1 == sub_step_226_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(sub_step_227_1 == sub_step_227_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(sub_step_228_1 == sub_step_228_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(sub_step_229_1 == sub_step_229_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(sub_step_230_1 == sub_step_230_2);
  assert(stage_v_230_1 == stage_v_230_2);
  assert(sub_step_231_1 == sub_step_231_2);
  assert(stage_v_231_1 == stage_v_231_2);
  assert(sub_step_232_1 == sub_step_232_2);
  assert(stage_v_232_1 == stage_v_232_2);
  assert(sub_step_233_1 == sub_step_233_2);
  assert(stage_v_233_1 == stage_v_233_2);
  assert(sub_step_234_1 == sub_step_234_2);
  assert(stage_v_234_1 == stage_v_234_2);
  assert(sub_step_235_1 == sub_step_235_2);
  assert(stage_v_235_1 == stage_v_235_2);
  assert(sub_step_236_1 == sub_step_236_2);
  assert(stage_v_236_1 == stage_v_236_2);
  assert(sub_step_237_1 == sub_step_237_2);
  assert(stage_v_237_1 == stage_v_237_2);
  assert(sub_step_238_1 == sub_step_238_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(sub_step_239_1 == sub_step_239_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(sub_step_240_1 == sub_step_240_2);
  assert(stage_v_240_1 == stage_v_240_2);
  assert(sub_step_241_1 == sub_step_241_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(sub_step_242_1 == sub_step_242_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(sub_step_243_1 == sub_step_243_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(sub_step_244_1 == sub_step_244_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(sub_step_245_1 == sub_step_245_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(sub_step_246_1 == sub_step_246_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(sub_step_247_1 == sub_step_247_2);
  assert(stage_v_247_1 == stage_v_247_2);
  assert(sub_step_248_1 == sub_step_248_2);
  assert(stage_v_248_1 == stage_v_248_2);
  assert(sub_step_249_1 == sub_step_249_2);
  assert(stage_v_249_1 == stage_v_249_2);
  assert(sub_step_250_1 == sub_step_250_2);
  assert(stage_v_250_1 == stage_v_250_2);
  assert(sub_step_251_1 == sub_step_251_2);
  assert(stage_v_251_1 == stage_v_251_2);
  assert(sub_step_252_1 == sub_step_252_2);
  assert(stage_v_252_1 == stage_v_252_2);
  assert(sub_step_253_1 == sub_step_253_2);
  assert(stage_v_253_1 == stage_v_253_2);
  assert(sub_step_254_1 == sub_step_254_2);
  assert(stage_v_254_1 == stage_v_254_2);
  assert(sub_step_255_1 == sub_step_255_2);
  assert(stage_v_255_1 == stage_v_255_2);
  assert(sub_step_256_1 == sub_step_256_2);
  assert(stage_v_256_1 == stage_v_256_2);
  assert(sub_step_257_1 == sub_step_257_2);
  assert(stage_v_257_1 == stage_v_257_2);
  assert(sub_step_258_1 == sub_step_258_2);
  assert(stage_v_258_1 == stage_v_258_2);
  assert(sub_step_259_1 == sub_step_259_2);
  assert(stage_v_259_1 == stage_v_259_2);
  assert(sub_step_260_1 == sub_step_260_2);
  assert(stage_v_260_1 == stage_v_260_2);
  assert(sub_step_261_1 == sub_step_261_2);
  assert(stage_v_261_1 == stage_v_261_2);
  assert(sub_step_262_1 == sub_step_262_2);
  assert(stage_v_262_1 == stage_v_262_2);
  assert(sub_step_263_1 == sub_step_263_2);
  assert(stage_v_263_1 == stage_v_263_2);
  assert(sub_step_264_1 == sub_step_264_2);
  assert(stage_v_264_1 == stage_v_264_2);
  assert(sub_step_265_1 == sub_step_265_2);
  assert(stage_v_265_1 == stage_v_265_2);
  assert(sub_step_266_1 == sub_step_266_2);
  assert(stage_v_266_1 == stage_v_266_2);
  assert(sub_step_267_1 == sub_step_267_2);
  assert(stage_v_267_1 == stage_v_267_2);
  assert(sub_step_268_1 == sub_step_268_2);
  assert(stage_v_268_1 == stage_v_268_2);
  assert(sub_step_269_1 == sub_step_269_2);
  assert(stage_v_269_1 == stage_v_269_2);
  assert(sub_step_270_1 == sub_step_270_2);
  assert(stage_v_270_1 == stage_v_270_2);
  assert(sub_step_271_1 == sub_step_271_2);
  assert(stage_v_271_1 == stage_v_271_2);
  assert(sub_step_272_1 == sub_step_272_2);
  assert(stage_v_272_1 == stage_v_272_2);
  assert(sub_step_273_1 == sub_step_273_2);
  assert(stage_v_273_1 == stage_v_273_2);
  assert(sub_step_274_1 == sub_step_274_2);
  assert(stage_v_274_1 == stage_v_274_2);
  assert(sub_step_275_1 == sub_step_275_2);
  assert(stage_v_275_1 == stage_v_275_2);
  assert(sub_step_276_1 == sub_step_276_2);
  assert(stage_v_276_1 == stage_v_276_2);
  assert(sub_step_277_1 == sub_step_277_2);
  assert(stage_v_277_1 == stage_v_277_2);
  assert(sub_step_278_1 == sub_step_278_2);
  assert(stage_v_278_1 == stage_v_278_2);
  assert(sub_step_279_1 == sub_step_279_2);
  assert(stage_v_279_1 == stage_v_279_2);
  assert(sub_step_280_1 == sub_step_280_2);
  assert(stage_v_280_1 == stage_v_280_2);
  assert(sub_step_281_1 == sub_step_281_2);
  assert(stage_v_281_1 == stage_v_281_2);
  assert(sub_step_282_1 == sub_step_282_2);
  assert(stage_v_282_1 == stage_v_282_2);
  assert(sub_step_283_1 == sub_step_283_2);
  assert(stage_v_283_1 == stage_v_283_2);
  assert(sub_step_284_1 == sub_step_284_2);
  assert(stage_v_284_1 == stage_v_284_2);
  assert(sub_step_285_1 == sub_step_285_2);
  assert(stage_v_285_1 == stage_v_285_2);
  assert(sub_step_286_1 == sub_step_286_2);
  assert(stage_v_286_1 == stage_v_286_2);
  assert(sub_step_287_1 == sub_step_287_2);
  assert(stage_v_287_1 == stage_v_287_2);
  assert(sub_step_288_1 == sub_step_288_2);
  assert(stage_v_288_1 == stage_v_288_2);
  assert(sub_step_289_1 == sub_step_289_2);
  assert(stage_v_289_1 == stage_v_289_2);
  assert(sub_step_290_1 == sub_step_290_2);
  assert(stage_v_290_1 == stage_v_290_2);
  assert(sub_step_291_1 == sub_step_291_2);
  assert(stage_v_291_1 == stage_v_291_2);
  assert(sub_step_292_1 == sub_step_292_2);
  assert(stage_v_292_1 == stage_v_292_2);
  assert(sub_step_293_1 == sub_step_293_2);
  assert(stage_v_293_1 == stage_v_293_2);
  assert(sub_step_294_1 == sub_step_294_2);
  assert(stage_v_294_1 == stage_v_294_2);
  assert(sub_step_295_1 == sub_step_295_2);
  assert(stage_v_295_1 == stage_v_295_2);
  assert(sub_step_296_1 == sub_step_296_2);
  assert(stage_v_296_1 == stage_v_296_2);
  assert(sub_step_297_1 == sub_step_297_2);
  assert(stage_v_297_1 == stage_v_297_2);
  assert(sub_step_298_1 == sub_step_298_2);
  assert(stage_v_298_1 == stage_v_298_2);
  assert(sub_step_299_1 == sub_step_299_2);
  assert(stage_v_299_1 == stage_v_299_2);
  assert(sub_step_300_1 == sub_step_300_2);
  assert(stage_v_300_1 == stage_v_300_2);
  assert(sub_step_301_1 == sub_step_301_2);
  assert(stage_v_301_1 == stage_v_301_2);
  assert(sub_step_302_1 == sub_step_302_2);
  assert(stage_v_302_1 == stage_v_302_2);
  assert(sub_step_303_1 == sub_step_303_2);
  assert(stage_v_303_1 == stage_v_303_2);
  assert(sub_step_304_1 == sub_step_304_2);
  assert(stage_v_304_1 == stage_v_304_2);
  assert(sub_step_305_1 == sub_step_305_2);
  assert(stage_v_305_1 == stage_v_305_2);
}


